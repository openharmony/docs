# OH_NativeXComponent_MouseEvent_Callback
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_NativeXComponent_MouseEvent_Callback {...} OH_NativeXComponent_MouseEvent_Callback
```

## 概述

提供了鼠标事件和悬停事件的回调注册能力，开发者可通过该回调结构体监听NativeXComponent上的鼠标和手写笔交互行为，适用于需要在Native侧处理指针输入交互的场景。其中，DispatchMouseEvent侧重鼠标按键按下、释放、移动等组件内的操作行为，DispatchHoverEvent侧重鼠标或手写笔进入/离开组件的悬停状态变化，两者监听维度不同，可按需同时注册。

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

```c
void (*DispatchMouseEvent)(OH_NativeXComponent* component, void* window)
```

**描述：**


当鼠标事件（例如鼠标按键按下、释放、移动等操作）被触发时调用。

**起始版本：** 9

**参数：**

| 参数项                                | 描述 |
|------------------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | 表示指向[OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)实例的指针。 |
| void* window | 表示触发鼠标事件时关联的NativeWindow句柄。 |

### DispatchHoverEvent()

```c
void (*DispatchHoverEvent)(OH_NativeXComponent* component, bool isHover)
```

**描述：**


当悬停事件被触发时调用。该函数在鼠标或手写笔进入或离开组件时触发。

**起始版本：** 9

**参数：**

| 参数项                                | 描述 |
|------------------------------------| -- |
| [OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)* component | 表示指向[OH_NativeXComponent](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent.md)实例的指针。 |
| bool isHover                       | 表示鼠标或手写笔是否悬停在组件上，进入时为true，离开时为false。 |


