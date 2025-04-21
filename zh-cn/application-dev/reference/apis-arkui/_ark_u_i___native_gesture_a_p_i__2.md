# ArkUI_NativeGestureAPI_2


## 概述

手势模块接口集合。

**起始版本：** 18

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)

**所在头文件：** [native_gesture.h](native__gesture_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md)* [gestureApi1](#gestureapi1); | 指向 [ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) 结构体的指针。 |
| int32_t(\* [setGestureInterrupterToNode](#setgestureinterruptertonode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void* userData, [ArkUI_GestureInterruptResult](_ark_u_i___native_module.md#arkui_gestureinterruptresult)(\*interrupter)(ArkUI_GestureInterruptInfo \*info)) | 设置手势中断事件的回调函数。 |


## 结构体成员变量说明


### setGestureInterrupterToNode

```
int32_t(* ArkUI_NativeGestureAPI_1::setGestureInterrupterToNode) (ArkUI_NodeHandle node, void* userData, ArkUI_GestureInterruptResult(*interrupter)(ArkUI_GestureInterruptInfo *info))
```
**描述：**

设置手势中断事件的回调函数。

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 需要被设置手势打断回调的ArkUI节点。 |
| userData | 用户自定义数据。 |
| interrupter | 打断回调。<br />返回GESTURE_INTERRUPT_RESULT_CONTINUE时，手势正常进行。<br />返回GESTURE_INTERRUPT_RESULT_REJECT时，手势被打断。 |

**返回：**

0 - 成功。 401 - 参数错误。

### gestureApi1

```
ArkUI_NativeGestureAPI_1* gestureApi1
```
**描述：**

指向 [ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) 结构体的指针。

**起始版本：** 18
