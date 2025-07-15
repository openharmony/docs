# OH_NativeXComponent_MouseEvent_Callback

## 概述

注册鼠标事件的回调。

**起始版本：** 9

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## 汇总

### 成员函数

| 名称 | 描述 |
| -- | -- |
| [void (\*DispatchMouseEvent)(OH_NativeXComponent* component, void* window)](#dispatchmouseevent) | 当鼠标事件被触发时调用。 |
| [void (\*DispatchHoverEvent)(OH_NativeXComponent* component, bool isHover)](#dispatchhoverevent) | 当悬停事件被触发时调用。 |

## 成员函数说明

### DispatchMouseEvent()

```
void (*DispatchMouseEvent)(OH_NativeXComponent* component, void* window)
```

**描述：**


当鼠标事件被触发时调用。

**起始版本：** 8

**参数：**

| 参数项                                | 描述 |
|------------------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | 表示指向[OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)实例的指针。 |
| void* window                       | 表示NativeWindow句柄。 |

### DispatchHoverEvent()

```
void (*DispatchHoverEvent)(OH_NativeXComponent* component, bool isHover)
```

**描述：**


当悬停事件被触发时调用。

**起始版本：** 8

**参数：**

| 参数项                                | 描述 |
|------------------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | 表示指向[OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)实例的指针。 |
| bool isHover                       | 表示鼠标或手写笔是否悬浮在组件上，进入时为true，离开时为false。 |


