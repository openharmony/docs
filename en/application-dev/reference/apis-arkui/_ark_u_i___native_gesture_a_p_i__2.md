# ArkUI_NativeGestureAPI_2


## Overview

Defines the gesture APIs.

**Since**: 18

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md)* [gestureApi1](#gestureapi1); | Pointer to the [ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) struct.|
| int32_t(\* [setGestureInterrupterToNode](#setgestureinterruptertonode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void* userData, [ArkUI_GestureInterruptResult](_ark_u_i___native_module.md#arkui_gestureinterruptresult)(\*interrupter)(ArkUI_GestureInterruptInfo \*info)) | Sets the callback for gesture interruption events.|


## Member Variable Description


### setGestureInterrupterToNode

```
int32_t(* ArkUI_NativeGestureAPI_1::setGestureInterrupterToNode) (ArkUI_NodeHandle node, void* userData, ArkUI_GestureInterruptResult(*interrupter)(ArkUI_GestureInterruptInfo *info))
```
**Description**

Sets the callback for gesture interruption events.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Node for which you want to set a gesture interruption callback.|
| userData | Custom data.|
| interrupter | Gesture interruption callback to set.<br>If **GESTURE_INTERRUPT_RESULT_CONTINUE** is returned, the gesture recognition process continues.<br>If **GESTURE_INTERRUPT_RESULT_REJECT** is returned, the gesture recognition process is paused.|

**Returns**

Returns **0** if the operation is successful. Returns **401** if a parameter error occurs.

### gestureApi1

```
ArkUI_NativeGestureAPI_1* gestureApi1
```
**Description**

Pointer to the [ArkUI_NativeGestureAPI_1](_ark_u_i___native_gesture_a_p_i__1.md) struct.

**Since**: 18
