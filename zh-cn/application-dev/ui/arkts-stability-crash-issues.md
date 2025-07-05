# UI相关应用崩溃问题案例

本文档收集整改了一些常见的会导致应用崩溃的ArkUI API错误用法，旨在帮助开发者了解一些常见的会导致应用崩溃问题的错误用法，从而避免在实际应用开发过中犯类似错误。

## 1、OH_NativeXComponent注册的回调函数对象被提前释放

### 典型案例

**问题现象**

libace_compatible.z.so栈最后一帧为XComponentPattern的OnSurfaceCreated、OnSurfaceChanged、OnSurfaceDestroyed、DispatchTouchEvent
比较常见的是#00为一个异常的地址，且最后几位和Reason后面的地址内容一致，说明某个函数指针有问题，导致执行它的时候跑到了这个异常地址。

```cpp
Reason:Signal:SIGSEGV(SEGV_ACCERR)@0x0000005c5f09a280 

#00 pc 0000000000ac9280 [anon:native_heap:jemalloc]
#01 pc 0000000002615120 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::NG::XComponentPattern::OnSurfaceDestroyed()+468)
#02 pc 0000000002614b18 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::NG::XComponentPattern::OnDetachFromFrameNode(OHOS::Ace::NG::FrameNode*)+88)
#03 pc 0000000000875294 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::NG::FrameNode::~FrameNode()+264)
```

**问题原因**

应用通过[OH_NativeXComponent_RegisterCallback](../reference/apis-arkui/capi-native-interface-xcomponent-h.md#OH_NativeXComponent_RegisterCallback())接口给OH_NativeXComponent注册的[OH_NativeXComponent_Callback](../reference/apis-arkui/capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-callback.md)回调函数对象是以裸指针形式保存在内部的XComponentPattern对象里面的，这意味着这些回调的生命周期实际是应用控制的。如果应用提前将OH_NativeXComponent_Callback回调函数对象销毁了，就会导致对应的裸指针指向的内存非法，引起Use-After-Free问题。

![OH_NativeXComponent_Callback](figures/OH_NativeXComponent_Callback.png)

### 接口文档

[Native XComponent](../reference/apis-arkui/capi-oh-nativexcomponent-native-xcomponent.md)

### 最佳实践

onSurfaceDestroy回调是XComponentPattern销毁时调用的最后一个回调，该回调执行完表示组件已经销毁。所以需要应用保证onSurfaceDestroy回调执行前需要保证这些回调是有效的。


## 2、OH_NativeXComponent对象被提前释放

### 典型案例

**问题现象**

接近栈顶的位置为libace_ndk.z.so(OH_NativeXComponent::XXX...)，且下一帧为应用的so的堆栈。

```cpp
#00 pc 00000000000c8b3c /system/lib64/libc++.so(std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>>::basic_string(std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>> const&)+16)
#01 pc 0000000000034f64 /system/lib64/libace_ndk.z.so(OH_NativeXComponent::GetXComponentId(char*, unsigned long*)+76)
#02 pc 00000000000867c0 /data/storage/el1/bundle/libs/arm64/librenderer.so
```

**问题原因**

OH_NativeXComponent是使用裸指针管理的，应用侧持有它的裸指针，如果在它的生命周期结束后，仍然调用它相关的接口，会导致uaf问题。

### 接口文档

[Native XComponent](../reference/apis-arkui/capi-oh-nativexcomponent-native-xcomponent.md)

### 最佳实践

系统会通过onSurfaceDestroy回调通知应用OH_NativeXComponent已经销毁，需要应用保证在onSurfaceDestroy回调执行完后不能再调用OH_NativeXComponent相关接口。


## 3、@Consume缺少匹配的@Provide

### 典型案例

**问题现象**

![initializeConsumeMissingCrashLog](figures/initializeConsumeMissingCrashLog.png)

**问题原因**

报错发生在@Consume初始化的阶段，原因是@Consume初始化的时候仅能通过key来匹配对应的@Provide变量进行初始化。当没有找到对应的@Provide的时候就会有这个报错(missing @Provide)：

![initializeConsumeMissingCause](figures/initializeConsumeMissingCause.png)

### 接口文档

[跨组件层级双向同步](state-management/arkts-new-Provider-and-Consumer.md)

### 最佳实践

需要排查组件树，对于@Provide和@Consume来说，@Provide装饰的变量是在祖先组件中，可以理解为被“提供”给后代的状态变量。@Consume装饰的变量是在后代组件中，去“消费（绑定）”祖先组件提供的变量。如果@Consume绑定key的@Provide在其祖先组件中没有被定义就会有上述报错。应该从用法的角度来进行排查。


## 4、@Link数据源类型错误

### 典型案例

**问题现象**

![SynchedPropertyTwoWayPUCrashLog](figures/SynchedPropertyTwoWayPUCrashLog.png)

**问题原因**

报错发生在@Link初始化的阶段，原因是@Link初始化的时候会把自己注册给父组件调用父组件的addSubscriber，如果此时数据源的类型和@Link不是完全一致，或者使用了常量去初始化@Link这个方法就无法调用到，导致这个报错(is not callable)：

![SynchedPropertyTwoWayPUCause](figures/SynchedPropertyTwoWayPUCause.png)

### 接口文档

[父子双向同步](state-management/arkts-link.md)

### 最佳实践

需要排查@Link的数据源是否是状态变量，且类型是否和@Link一致。


## 5、@Provide缺少重写声明

### 典型案例

**问题现象**

![addProvidedVarDuplicateCrashLog](figures/addProvidedVarDuplicateCrashLog.png)

**问题原因**

报错发生在@Provide初始化的阶段，原因是@Provide重写需要声明allowOverride，当声明时别名和属性名都可以被Override。如果没有声明出现了重复的别名或者属性名，就会报错(duplicate @Provide property with name xxxxx)：

![addProvidedVarDuplicateCause](figures/addProvidedVarDuplicateCause.png)

### 接口文档

[跨组件层级双向同步](state-management/arkts-new-Provider-and-Consumer.md)

### 最佳实践

需要排查@Provide是否使用了允许重写的声明（allowOverride），如果没有使用，则这样使用是不合规的，只有声明之后才会允许重写，并且子组件的@Consume会根绝别名或者属性名找到并使用距离他最近的父节点上的@Provide值。
