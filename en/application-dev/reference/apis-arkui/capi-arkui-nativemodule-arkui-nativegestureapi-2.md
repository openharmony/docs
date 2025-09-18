# ArkUI_NativeGestureAPI_2
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a collection of gesture APIs.

**Since**: 18

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_gesture.h](capi-native-gesture-h.md)

## Summary

### Member Variables

| Name                                       | Description|
|-------------------------------------------| -- |
| [ArkUI_NativeGestureAPI_1](capi-arkui-nativemodule-arkui-nativegestureapi-1.md)* gestureApi1 | Pointer to the **ArkUI_NativeGestureAPI_1** struct.|


### Member Functions

| Name| Description|
| -- | -- |
| [int32_t (\*setGestureInterrupterToNode)(ArkUI_NodeHandle node, void* userData,ArkUI_GestureInterruptResult (\*interrupter)(ArkUI_GestureInterruptInfo* info))](#setgestureinterruptertonode) | Sets the callback for gesture interruption events.|

## Member Function Description

### setGestureInterrupterToNode()

```
int32_t (*setGestureInterrupterToNode)(ArkUI_NodeHandle node, void* userData,ArkUI_GestureInterruptResult (*interrupter)(ArkUI_GestureInterruptInfo* info))
```

**Description**


Sets the callback for gesture interruption events.

**Parameters**

| Name                      | Description|
|---------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Node for which you want to set a gesture interruption callback.|
| void* userData            | Pointer to user-defined data.|
| interrupter               | Gesture interruption callback to set. **info** returns the gesture interruption data. If **interrupter** returns **GESTURE_INTERRUPT_RESULT_CONTINUE**, the gesture recognition process proceeds properly; if it returns **GESTURE_INTERRUPT_RESULT_REJECT**, the gesture recognition process is interrupted.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>            **401**: Parameter error.|
