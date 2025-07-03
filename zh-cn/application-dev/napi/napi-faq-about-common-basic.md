# 常见基本功能问题汇总

## 模块加载失败，报错信息显示`Error message: is not callable`.

- 问题描述：
通过如下模块注册代码提供的libxxx.so，在部分项目中调用动态库的API，出现`Error message: is not callable` 
```cpp
static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "xxx",
    .nm_priv = nullptr,
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule()
{
    napi_module_register(&demoModule);
}
```
  
- 排查建议：  
1. 可根据以下文档进行排查：     
[ArkTS/JS侧import xxx from libxxx.so后，使用xxx报错显示undefined/not callable或明确的Error message](napi-faq-about-common-basic.md#arkts侧报错显示undefined)  
[模块注册与模块命名](napi-guidelines.md#模块注册与模块命名)   
2. 同时也可参考动态加载能力是否可以满足该场景  
[napi_load_module_with_info支持的场景](use-napi-load-module-with-info.md#napi_load_module_with_info支持的场景)   
[napi_load_module支持的场景](use-napi-load-module.md#napi_load_module支持的场景)   

## 在大量需要调用ArkTS方法进行通信的场景如何保证异步任务的有序性

- 具体问题：在大量需要通过c++调用ArkTS方法进行通信的场景，如何保证异步任务的有序性？
- 参考方案：  
可参考线程安全函数来实现，napi_call_threadsafe_function可保证异步任务执行顺序, 需要注意的是这些异步任务会抛回到ArkTS线程顺序执行，如果是抛回到主线程，异步任务的执行时间过长可能导致应用冻结退出，所以不建议将长耗时的任务通过线程安全函数抛回到主线程执行。   
[使用Node-API接口进行线程安全开发](use-napi-thread-safety.md)

此外，napi中常见的抛任务方法的差异如下：

1. napi_async_work系列接口：只能保证execute_cb执行在complete_cb之前，对于不同的async_work，时序无法保证  
[napi_queue_async_work_with_qos](../../application-dev/reference/native-lib/napi.md#napi_queue_async_work_with_qos)是在普通napi_queue_async_work的基础上，支持自定义qos优先级，而这里只是指定libuv调度任务时使用线程的优先级，不是指任务的优先级，所以也无法保证任务的时序。   
2. napi_threadsafe_function系列接口：接口内部维护了一个队列，是保序的。   
napi_call_threadsafe_function：先入先出    
napi_call_threadsafe_function_with_priority：根据自己指定的任务优先级执行    
[使用Node-API接口从异步线程向ArkTS线程投递指定优先级和入队方式的的任务](use-call-threadsafe-function-with-priority.md)

## 是否存在便捷的回调ArkTS的方式

- 具体描述：  
在进行多线程开发时，ArkTS函数只能在其创建线程上执行，c++线程不能直接通过napi_call_function的形式直接调用ArkTS回调，是否存在便捷的方法？  
可参考文档：   
[Native侧子线程与UI主线程通信](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-native-sub-main-comm)   
[使用Node-API接口进行异步任务开发](use-napi-asynchronous-task.md)   

## 如何在C++代码中回调ArkTS方法

- 参考文档：   
[如何在C++调用从ArkTS传递过来的function](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs/faqs-ndk-26)    

## 由于工作线程 A 长时间持有锁M，而主线程又在等待获取锁M，形成循环等待条件，导致系统进入死锁状态   

- 参考方案：    
可使用napi_threadsafe_function系列接口，具体可参考前文问题二的解决方案    

## 如何确保数据类型的正确映射与内存管理的安全性

- 具体问题：如何在遵循N-API单一返回值约束的前提下，安全、高效地将多个返回值（包括结构化数据和指针信息）传递给ArkTS运行时环境，并确保数据类型的正确映射与内存管理的安全性？
- 参考实现：   
尽管napi_value接口仅支持单一返回值，但开发者可通过该返回值封装所需的全部信息。

比如通过napi_create_object，创建出一个ArkTS对象，用这个对象来承载返回的所有信息，number和string都可以通过napi_set_property/napi_set_named_property等属性设置的接口设置到这个对象上。native对象也可以通过napi_wrap接口和ArkTS对象进行绑定，后续在通过napi_unwrap取出来。   
此外，亦可使用ArkTS数组作为数据载体，其具有良好的灵活性。    
- 参考文档：   
[使用Node-API接口进行object相关开发](use-napi-about-object.md)    
[使用Node-API接口进行array相关开发](use-napi-about-array.md)    

## napi_get_uv_event_loop接口错误码说明

在OpenHarmony中，对使用非法的napi_env作为`napi_get_uv_event_loop`入参的行为加入了额外的参数校验，这一行为将直接反映到该接口的返回值上。该接口返回值详情如下：

1. 当env且（或）loop为nullptr时，返回`napi_invalid_arg`。
2. 当env为有效的napi_env且loop为合法指针，返回`napi_ok`。
3. 当env不是有效的napi_env（如已释放的env），返回`napi_generic_failure`。

- 常见错误场景示例如下：

```c++
napi_value NapiInvalidArg(napi_env env, napi_callback_info)
{
    napi_status status = napi_ok;
    status = napi_get_uv_event_loop(env, nullptr); // loop为nullptr, 状态码napi_invalid_arg
    if (status == napi_ok) {
        // do something
    }

    uv_loop_s* loop = nullptr;
    status = napi_get_uv_event_loop(nullptr, &loop); // env为nullptr, 状态码napi_invalid_arg
    if (status == napi_ok) {
        // do something
    }

    status = napi_get_uv_event_loop(nullptr, nullptr); // env, loop均为nullptr, 状态码napi_invalid_arg
    if (status == napi_ok) {
        // do something
    }

    return nullptr;
}

napi_value NapiGenericFailure(napi_env env, napi_callback_info)
{
    std::thread([]() {
        napi_env env = nullptr;
        napi_create_ark_runtime(&env); // 通常情况下，需要对该接口返回值进行判断
        // napi_destroy_ark_runtime 会将指针置空，拷贝一份用以构造问题场景
        napi_env copiedEnv = env;
        napi_destroy_ark_runtime(&env);
        uv_loop_s* loop = nullptr;
        napi_status status = napi_get_uv_event_loop(copiedEnv, &loop); // env无效, 状态码napi_generic_failure
        if (status == napi_ok) {
            // do something
        }
    }).detach();
}
```

## Native层调用ts层对象方法必须传入一个function给Native层吗

- 具体问题：【NAPI】Native层调用ts层对象方法，必须传入一个function给Native层吗？
- 参考方案：  
如果想要在Native层调用ts层对象方法，则Native层需获取该TS Function对象。  
获取的途径也有很多，比如：  
1. 通过传递的方式，ts层传给Native层，也就是问题描述的方案   
2. 可以把这个ts function通过属性设置方式绑定到Native层可访问的对象上，这样Native层通过这个对象也能拿到function进行调用   
3. napi层也提供了一个创建ts function的能力，即napi_create_function，可以直接在Native层中创建出来，这样，Native层自然就能拿到这个ts function   

## 是否能调用ets的方法并获取到结果

- 具体问题：在c++通过pthread或std::thread创建的线程，是否能调用ets的方法并获取到结果？
问题分析：   
如果是直接创建出来的c++线程，这个线程是没有ArkTS运行环境的，也就是该线程上没有对应的napi env，所以无法直接在刚创建出来的c++线程上直接运行ets方法并获取到结果。  

- 解决方案参考：  
1. 使用napi_threadsafe_function系列的napi接口，这系列接口，相当于在c++线程抛任务回到ArkTS线程执行ets方法  
[使用Node-API接口进行线程安全开发](use-napi-thread-safety.md)  
2. 在c++线程创建出ArkTS运行环境   
[使用Node-API接口创建ArkTS运行时环境](use-napi-ark-runtime.md)   

## 是否有不拷贝的napi_get_value_string_utf8接口或者能力

- 具体问题：当前napi的napi_get_value_string_utf8每次调用的时候都要进行拷贝，是否有不拷贝的napi_get_value_string_utf8接口或者能力？  
- 问题解答：   
当前版本暂不支持该功能，每次napi_get_value_string_utf8都是需要有一个拷贝过程的。

拷贝是必要的，因为会涉及到string生命周期。当触发GC的时候，ArkTS对象可能会在虚拟机里面被搬移，可能搬移到其他地方，也可能直接对象被回收。如果直接返回一个类似char*的地址，对象被移动或回收后，那这个地址的指向就不再是之前的字符串了，此时再用这个地址去解引用很容易崩溃。

## 多线程下napi_env的使用注意事项

- 具体问题：   
多线程下napi_env的使用注意事项是什么？是否存在napi_env切换导致的异常问题？是否必须在主线程？  

- 注意事项：   
1. napi_env和ArkTS线程是绑定的，napi_env不能跨线程使用，否则会导致稳定性问题。
[多线程限制](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/use-napi-process#%E5%A4%9A%E7%BA%BF%E7%A8%8B%E9%99%90%E5%88%B6)
2. 在使用env调用napi接口时，需要注意，大部分的napi接口只能在env所在的ArkTS线程上调用，不然会出现多线程安全问题。
参考该文档的第四点【multi-thread】 [开发者使用napi接口时，跨线程使用napi_env或napi_value引发多线程安全问题](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615)   
3. 最好不要缓存napi env，否则容易出现多线程安全问题和use-after-free问题   
参考该文档的第八点【use-after-free】[开发者使用napi接口时，跨线程使用napi_env或napi_value引发多线程安全问题](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615) 
4. [napi_env禁止缓存的原因是什么](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs/faqs-ndk-73)

## napi_call_threadsafe_function执行顺序不符合预期

- 问题描述：   
napi_call_threadsafe_function执行结果不符合预期  
原本期望的执行顺序是 a -> b -> c
posttask(a);   
posttask(b);   
posttask(c);   
但是实际的执行顺序是 b -> a -> c   

- 排查方向：   
1. 是不是用的同一个napi_threadsafe_function，若使用不同实例，则无法保障与调用顺序一致；   
注：对于同一个napi_threadsafe_function来说，napi_call_threadsafe_function是保序的，接口内维护了一个队列，先调用就会先执行。   
注：不同实例是先创建，先执行，但是若使用不同实例，得保证对应关系。  
2. 是否能保证实际call的顺序是a -> b -> c；   
3. 使用了napi_call_threadsafe_function_with_priority，该接口是向主线程的事件循环中投递任务， 由于主线程存在不同优先级的队列， 不同的优先级的任务是无法保证时序的，同意优先级的任务，由于是在同一事件队列，可以保证时序。   

参考文档：    
[使用Node-API接口从异步线程向ArkTS线程投递指定优先级和入队方式的的任务](use-call-threadsafe-function-with-priority.md)  

## ArkTS侧报错显示undefined
具体问题：
ArkTS/JS侧import xxx from libxxx.so后，使用xxx报错显示undefined/not callable或明确的Error message
1. 排查.cpp文件在注册模块时的模块名称与so的名称匹配一致。
   如模块名为entry，则so的名字为libentry.so，napi_module中nm_modname字段应为entry，大小写与模块名保持一致。

2. 排查so是否加载成功。
   应用启动时过滤模块加载相关日志，重点搜索"dlopen"关键字，确认是否有相关报错信息；常见加载失败原因有权限不足、so文件不存在以及so已拉入黑名单等，可根据以下关键错误日志确认问题。其中，多线程场景(worker、taskpool等)下优先检查模块实现中nm_modname是否与模块名一致，区分大小写。

3. 排查依赖的so是否加载成功。
   确定所依赖的其它so是否打包到应用中以及是否有权限打开。常见加载失败原因有权限不足、so文件不存在等。

4. 排查模块导入方式与so路径是否对应。
   若JS侧导入模块的形式为： import xxx from '\@ohos.yyy.zzz'，则该so将在/system/lib/module/yyy中找libzzz.z.so或libzzz_napi.z.so，若so不存在或名称无法对应，则报错日志中会出现dlopen相关日志。

   注意，32位系统路径为/system/lib，64位系统路径为/system/lib64。

| **已知关键错误日志** | **修改建议** |
| -------- | -------- |
| module $SO is not allowed to load in restricted runtime. | $SO表示模块名。该模块不在受限worker线程的so加载白名单，不允许加载，建议用户删除该模块。 |
| module $SO is in blocklist, loading prohibited. | $SO表示模块名。受卡片或者Extension管控，该模块在黑名单内，不允许加载，建议用户删除该模块。 |
| load module failed. $ERRMSG. | 动态库加载失败。$ERRMSG表示加载失败原因，一般常见原因是so文件不存在、依赖的so文件不存在或者符号未定义，需根据加载失败原因具体分析。 |
| try to load abc file from $FILEPATH failed. | 通常加载动态库和abc文件为二选一：如果是要加载动态库并且加载失败，该告警可以忽略；如果是要加载abc文件，则该错误打印的原因是abc文件不存在，$FILEPATH表示模块路径。 |

5. 如果有明确的Error message，可以通过Error message判断当前问题。

| **Error message** | **修改建议** |
| -------- | -------- |
| First attempt: $ERRMSG. | 首先加载后缀不拼接'_napi'的模块名为'xxx'的so，如果加载失败会有该错误信息，$ERRMSG表示具体加载时的错误信息。 |
| Second attempt: $ERRMSG. | 第二次加载后缀拼接'_napi'的模块名为'xxx_napi'的so，如果加载失败会有该错误信息，$ERRMSG表示具体加载时的错误信息。 |
| try to load abc file from xxx failed. | 第三次加载名字为'xxx'的abc文件，如果加载失败会有该错误信息。 |
| module xxx is not allowed to load in restricted runtime. | 该模块不允许在受限运行时中使用，xxx表示模块名，建议用户删除该模块。 |
| module xxx is in blocklist, loading prohibited. | 该模块不允许在当前extension下使用，xxx表示模块名，建议用户删除该模块。 |

## 接口执行结果非预期

问题描述：接口执行结果非预期，日志显示occur exception need return。

部分Node-API接口在调用结束前会进行检查，检查虚拟机中是否存在ArkTS异常。如果存在异常，则会打印出occur exception need return日志，并打印出检查点所在的行号，以及对应的Node-API接口名称。

解决此类问题有以下两种思路：

- 若该异常开发者不关心，可以选择直接清除。
  可直接使用napi接口napi_get_and_clear_last_exception，清理异常。调用时机：在打印occur exception need return日志的接口之前调用。

- 将该异常继续向上抛到ArkTS层，在ArkTS层进行捕获。
  发生异常时，可以选择走异常分支， 确保不再走多余的Native逻辑 ，直接返回到ArkTS层。

## napi_value和napi_ref的生命周期有何区别

- Native_value由HandleScope管理，一般开发者不需要自己加HandleScope（uv_queue_work的complete callback除外）。

- napi_ref由开发者自己管理，需要手动delete。

## Node-API接口返回值不是napi_ok时如何排查定位

Node-API接口正常执行后，会返回一个napi_ok的状态枚举值，若napi接口返回值不为napi_ok，可从以下几个方面进行排查。

- Node-API接口执行前一般会进行入参校验，首先进行的是判空校验。在代码中体现为：

  ```cpp
  CHECK_ENV：env判空校验
  CHECK_ARG：其它入参判空校验
  ```

- 某些Node-API接口还有入参类型校验。比如napi_get_value_double接口是获取ArkTS number对应的C double值，首先就要保证的是：ArkTS value类型为number，因此可以看到相关校验。

  ```cpp
  RETURN_STATUS_IF_FALSE(env, NativeValue->TypeOf() == Native_NUMBER, napi_number_expected);
  ```

- 还有一些接口会对其执行结果进行校验。比如napi_call_function这个接口，其功能是执行一个ArkTS function，当ArkTS function中出现异常时，Node-API将会返回napi_pending_exception的状态值。

  ```cpp
  // 接口内部实现，经校验可返回状态值
  auto resultValue = engine->CallFunction(NativeRecv, NativeFunc, NativeArgv, argc);
  RETURN_STATUS_IF_FALSE(env, resultValue != nullptr, napi_pending_exception)
  ```

- 还有一些状态值需要根据相应Node-API接口具体分析：确认具体的状态值，分析这个状态值在什么情况下会返回，再排查具体出错原因。

## napi_wrap如何保证被wrap的对象按期望顺序析构
问题：在使用`napi_wrap`把两个 C++ 对象包装成两个 JavaScript 对象的场景中，由于这两个 C++ 对象存在依赖关系，要求其中一个c++对象必须在另一个c++对象之前析构。然而，JavaScript 垃圾回收（GC）的时机不确定，直接在`napi_wrap`的`finalize_cb`回调里销毁 C++ 对象，没办法保证析构顺序符合要求。该如何保证两个c++对象析构的前后顺序？

参考方案：  
先标记可释放状态，当A和B都为可释放状态时同时释放C++对象   
原理：将所有依赖对象的释放逻辑集中在最后一个被销毁的 JS 对象的 finalize_cb 中处理。  
实现步骤：   
在 jsObjA 的 finalize_cb 中标记 cppObjA 为待销毁（不立即释放）。  
在 jsObjB 的 finalize_cb 中标记 cppObjB 为待销毁（不立即释放）。  
jsObjA 和 jsObjB 都为待销毁状态时，按顺序销毁A和B。
示例代码：    
```cpp
struct ObjectPair {
    CppObjA* objA;
    CppObjB* objB;
    bool objADestroyedA = false;
    bool objADestroyedB = false;
};

// jsObjA 的 finalize 回调
void FinalizeA(napi_env env, void* data, void* hint) {
    ObjectPair* pair = static_cast<ObjectPair*>(data);
    pair->objADestroyedA = true;
    if (pair->objADestroyedA && pair->objADestroyedB) {
        delete pair->objA; // 确保先销毁 A
        delete pair->objB; // 再销毁 B
        delete pair;       // 释放包装结构
    }
}

// jsObjB 的 finalize 回调
void FinalizeB(napi_env env, void* data, void* hint) {
    ObjectPair* pair = static_cast<ObjectPair*>(data);
    pair->objADestroyedB = true;
    if (pair->objADestroyedA && pair->objADestroyedB) {
        delete pair->objA; // 确保先销毁 A
        delete pair->objB; // 再销毁 B
        delete pair;       // 释放包装结构
    }
}
```
## napi_call_threadsafe_function回调任务不执行

问题排查：
原因一：`napi_call_threadsafe_function`函数调用返回值不为`napi_ok`。请确认调用`napi_tsfn`相关函数的返回值是否都是`napi_ok`，若不是，请根据[错误码文档](napi_status_introduction.md)排查返回值非`napi_ok`的原因。  
原因二：env所在的ArkTS线程被阻塞。`napi_call_threadsafe_function`函数的回调将执行在env所在的ArkTS线程上，若ArkTS线程被阻塞，则线程安全函数回调不会被执行。  
原因三：线程安全函数被重复初始化的`uv_async_t`句柄影响，导致任务不执行。若某个`uv_async_t`句柄被重新初始化，第一次初始化和重复初始化范围内所创建所有`uv_async_t`句柄将无法被uv访问。线程安全函数是基于`uv_async_t`机制实现，在该特殊场景下创建线程安全函数将失效。  
