# ArkUI_NativeGestureAPI_1
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## Overview

Defines the gesture APIs.

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Header file**: [native_gesture.h](capi-native-gesture-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t version | The struct version is 1.|


### Member Functions

| Name| Description|
| -- | -- |
| [ArkUI_GestureRecognizer* (\*createTapGesture)(int32_t countNum, int32_t fingersNum)](#createtapgesture) | Creates a tap gesture.1. This API is used to trigger a tap gesture with one, two, or more taps.<br>        2. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.<br>        3. If the distance between the last tapped position and the current tapped position exceeds 60 vp, gesture recognition fails.<br>        4. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers touching the screen within 300 ms of the first finger touch is less than the required number,<br>           or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted is less than the required number.<br>        5. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized.<br>|
| [ArkUI_GestureRecognizer* (\*createLongPressGesture)(int32_t fingersNum, bool repeatResult, int32_t durationNum)](#createlongpressgesture) | Creates a long press gesture.1. This API is used to trigger a long press gesture, which requires one or more fingers with a minimum 500 ms hold-down time.<br>        2. In components that support drag actions by default, such as **Text**, **TextInput**, **TextArea**, **HyperLink**, **Image**, and **RichEditor**,<br>           the long press gesture may conflict with the drag action. If this occurs, the event priority is determined as follows:<br>           If the minimum duration of the long press gesture is less than 500 ms, the long press gesture receives a higher response priority than the drag action.<br>           If the minimum duration of the long press gesture is greater than or equal to 500 ms, the drag action receives a higher response priority than the long press gesture.<br>        3. If a finger moves more than 15 px after being pressed, the gesture recognition fails.<br>|
| [ArkUI_GestureRecognizer* (\*createPanGesture)(int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum)](#createpangesture) | Creates a pan gesture.1. This API is used to trigger a pan gesture when the movement distance of a finger on the screen exceeds the minimum value.<br>        2. If a pan gesture and a tab swipe occur at the same time, set <b>distanceNum</b> to <b>1</b> so that the gesture can be more easily recognized.<br>|
| [ArkUI_GestureRecognizer* (\*createPinchGesture)(int32_t fingersNum, double distanceNum)](#createpinchgesture) | Creates a pinch gesture.1. This API is used to trigger a pinch gesture, which requires two to five fingers with a minimum 5 vp distance between the fingers.<br>        2. While more fingers than the minimum number can be pressed to trigger the gesture, only the first fingers of the minimum number participate in gesture calculation.<br>|
| [ArkUI_GestureRecognizer* (\*createRotationGesture)(int32_t fingersNum, double angleNum)](#createrotationgesture) | Creates a rotation gesture.1. This API is used to trigger a rotation gesture, which requires two to five fingers with a minimum 1-degree rotation angle.<br>        2. While more fingers than the minimum number can be pressed to trigger the gesture, only the first two fingers participate in gesture calculation.<br>|
| [ArkUI_GestureRecognizer* (\*createSwipeGesture)(int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum)](#createswipegesture) | Creates a swipe gesture.1. This API is used to implement a swipe gesture, which can be recognized when the swipe speed is 100 vp/s or higher.<br>|
| [ArkUI_GestureRecognizer* (\*createGroupGesture)(ArkUI_GroupGestureMode gestureMode)](#creategroupgesture) | Creates a gesture group.|
| [void (\*dispose)(ArkUI_GestureRecognizer* recognizer)](#dispose) | Disposes of a gesture to release resources.|
| [int32_t (\*addChildGesture)(ArkUI_GestureRecognizer* group, ArkUI_GestureRecognizer* child)](#addchildgesture) | Adds a gesture to a gesture group.|
| [int32_t (\*removeChildGesture)(ArkUI_GestureRecognizer* group, ArkUI_GestureRecognizer* child)](#removechildgesture) | Removes a gesture from a gesture group.|
| [int32_t (\*setGestureEventTarget)(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureEventActionTypeMask actionTypeMask, void* extraParams,void (\*targetReceiver)(ArkUI_GestureEvent* event, void* extraParams))](#setgestureeventtarget) | Registers a callback for gestures.|
| [int32_t (\*addGestureToNode)(ArkUI_NodeHandle node, ArkUI_GestureRecognizer* recognizer, ArkUI_GesturePriority mode, ArkUI_GestureMask mask)](#addgesturetonode) | Adds a gesture to a UI component.|
| [int32_t (\*removeGestureFromNode)(ArkUI_NodeHandle node, ArkUI_GestureRecognizer* recognizer)](#removegesturefromnode) | Removes a gesture from a node.|
| [int32_t (\*setGestureInterrupterToNode)(ArkUI_NodeHandle node, ArkUI_GestureInterruptResult (\*interrupter)(ArkUI_GestureInterruptInfo* info))](#setgestureinterruptertonode) | Sets a gesture interruption callback for a node.|
| [ArkUI_GestureRecognizerType (\*getGestureType)(ArkUI_GestureRecognizer* recognizer)](#getgesturetype) | Obtains the type of a gesture.|
| [int32_t (\*setInnerGestureParallelTo)(ArkUI_NodeHandle node, void* userData, ArkUI_GestureRecognizer* (\*parallelInnerGesture)(ArkUI_ParallelInnerGestureEvent* event))](#setinnergestureparallelto) | Sets the callback function for the parallel internal gesture event.|
| [ArkUI_GestureRecognizer* (\*createTapGestureWithDistanceThreshold)(int32_t countNum, int32_t fingersNum, double distanceThreshold)](#createtapgesturewithdistancethreshold) | Creates a tap gesture that is subject to distance restrictions.1. This API is used to trigger a tap gesture with one, two, or more taps.<br>        2. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.<br>        3. If the distance between the last tapped position and the current tapped position exceeds 60 vp, gesture recognition fails.<br>        4. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers touching the screen within 300 ms of the first finger touch is less than the required number,<br>           or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted is less than the required number.<br>        5. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized.<br>        6. If the finger moves beyond the preset distance limit, gesture recognition fails.<br>|

## Member Function Description

### createTapGesture()

```
ArkUI_GestureRecognizer* (*createTapGesture)(int32_t countNum, int32_t fingersNum)
```

**Description**


Creates a tap gesture.1. This API is used to trigger a tap gesture with one, two, or more taps.<br>        2. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.<br>        3. If the distance between the last tapped position and the current tapped position exceeds 60 vp, gesture recognition fails.<br>        4. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers touching the screen within 300 ms of the first finger touch is less than the required number,<br>           or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted is less than the required number.<br>        5. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized.<br>

**Parameters**

| Name| Description|
| -- | -- |
| int32_t countNum | Number of consecutive taps. If the value is less than 1 or is not set, the default value **1** is used.|
|  int32_t fingersNum | Number of fingers required to trigger the tap gesture. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value **1** is used.|

**Returns**

| Type                          | Description|
|------------------------------| -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture.|

### createLongPressGesture()

```
ArkUI_GestureRecognizer* (*createLongPressGesture)(int32_t fingersNum, bool repeatResult, int32_t durationNum)
```

**Description**


Creates a long press gesture.1. This API is used to trigger a long press gesture, which requires one or more fingers with a minimum 500 ms hold-down time.<br>        2. In components that support drag actions by default, such as **Text**, **TextInput**, **TextArea**, **HyperLink**, **Image**, and **RichEditor**,<br>           the long press gesture may conflict with the drag action. If this occurs, the event priority is determined as follows:<br>           If the minimum duration of the long press gesture is less than 500 ms, the long press gesture receives a higher response priority than the drag action.<br>           If the minimum duration of the long press gesture is greater than or equal to 500 ms, the drag action receives a higher response priority than the long press gesture.<br>        3. If a finger moves more than 15 px after being pressed, the gesture recognition fails.<br>

**Parameters**

| Name| Description|
| -- | -- |
| int32_t fingersNum | Minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10.|
|  bool repeatResult | Whether to continuously trigger the event callback.|
|  int32_t durationNum | Minimum hold-down time, in ms. If the value is less than or equal to 0, the default value **500** is used.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture.|

### createPanGesture()

```
ArkUI_GestureRecognizer* (*createPanGesture)(int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum)
```

**Description**


Creates a pan gesture.1. This API is used to trigger a pan gesture when the movement distance of a finger on the screen exceeds the minimum value.<br>        2. If a pan gesture and a tab swipe occur at the same time, set <b>distanceNum</b> to <b>1</b> so that the gesture can be more easily recognized.<br>

**Parameters**

| Name                                                                 | Description|
|----------------------------------------------------------------------| -- |
| int32_t fingersNum                                                   | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value **1** is used.|
| [ArkUI_GestureDirectionMask](capi-native-gesture-h.md#variables) directions | Pan direction. The value supports the AND (&) and OR (\|) operations.|
| double distanceNum                                                   | Minimum pan distance to trigger the gesture, in vp. If this parameter is set to a value less than or equal to 0, the default value **5** is used.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture.|

### createPinchGesture()

```
ArkUI_GestureRecognizer* (*createPinchGesture)(int32_t fingersNum, double distanceNum)
```

**Description**


Creates a pinch gesture.1. This API is used to trigger a pinch gesture, which requires two to five fingers with a minimum 5 vp distance between the fingers.<br>        2. While more fingers than the minimum number can be pressed to trigger the gesture, only the first fingers of the minimum number participate in gesture calculation.<br>

**Parameters**

| Name| Description|
| -- | -- |
| int32_t fingersNum | Minimum number of fingers required to trigger the pinch gesture. The value ranges from 2 to 5. The default value is **2**.|
|  double distanceNum | Minimum recognition distance, in vp. If this parameter is set to a value less than or equal to 0, the default value **5** is used.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture.|

### createRotationGesture()

```
ArkUI_GestureRecognizer* (*createRotationGesture)(int32_t fingersNum, double angleNum)
```

**Description**


Creates a rotation gesture.1. This API is used to trigger a rotation gesture, which requires two to five fingers with a minimum 1-degree rotation angle.<br>        2. While more fingers than the minimum number can be pressed to trigger the gesture, only the first two fingers participate in gesture calculation.<br>

**Parameters**

| Name| Description|
| -- | -- |
| int32_t fingersNum | Minimum number of fingers required to trigger the rotation gesture. The value ranges from 2 to 5. The default value is **2**.|
|  double angleNum | Minimum angle change required to trigger the rotation gesture, in degrees (deg). The default value is **1**. If this parameter is set to a value less than or equal to 0 or greater than 360, the default value **1** is used.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture.|

### createSwipeGesture()

```
ArkUI_GestureRecognizer* (*createSwipeGesture)(int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum)
```

**Description**


Creates a swipe gesture.1. This API is used to implement a swipe gesture, which can be recognized when the swipe speed is 100 vp/s or higher.<br>

**Parameters**

| Name| Description|
| -- | -- |
| int32_t fingersNum | Minimum number of fingers required to trigger the swipe gesture. The value ranges from 1 to 10.|
|  [ArkUI_GestureDirectionMask](capi-native-gesture-h.md#variables) directions | Directions in which the swipe gesture can be recognized.|
|  double speedNum | Minimum speed required to recognize the swipe gesture, in px/s. If this parameter is set to a value less than or equal to 0, the default value **100** is used.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture.|

### createGroupGesture()

```
ArkUI_GestureRecognizer* (*createGroupGesture)(ArkUI_GroupGestureMode gestureMode)
```

**Description**


Creates a gesture group.

**Parameters**

| Name                                                                                  | Description|
|---------------------------------------------------------------------------------------| -- |
| [ArkUI_GroupGestureMode](capi-native-gesture-h.md#arkui_groupgesturemode) gestureMode | Gesture group mode.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture group.|

### dispose()

```
void (*dispose)(ArkUI_GestureRecognizer* recognizer)
```

**Description**


Disposes of a gesture to release resources.

**Parameters**

| Name                                                                                  | Description|
|---------------------------------------------------------------------------------------| -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer| Pointer to the custom dialog box controller.|

### addChildGesture()

```
int32_t (*addChildGesture)(ArkUI_GestureRecognizer* group, ArkUI_GestureRecognizer* child)
```

**Description**


Adds a gesture to a gesture group.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* group | Pointer to the target gesture group.|
|  [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* child | Pointer to the target gesture.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful.<br>            Returns **401** if a parameter error occurs, for example, attempting to add a gesture to an object that is not a gesture group.|

### removeChildGesture()

```
int32_t (*removeChildGesture)(ArkUI_GestureRecognizer* group, ArkUI_GestureRecognizer* child)
```

**Description**


Removes a gesture from a gesture group.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* group | Pointer to the target gesture group.|
|  [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* child | Pointer to the target gesture.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful.<br>            Returns **401** if a parameter error occurs.|

### setGestureEventTarget()

```
int32_t (*setGestureEventTarget)(ArkUI_GestureRecognizer* recognizer, ArkUI_GestureEventActionTypeMask actionTypeMask, void* extraParams,void (*targetReceiver)(ArkUI_GestureEvent* event, void* extraParams))
```

**Description**


Registers a callback for gestures.

**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | Pointer to a gesture recognizer.|
| [ArkUI_GestureEventActionTypeMask](capi-native-gesture-h.md#variables) actionTypeMask            | Gesture event types. Multiple callbacks can be registered at once, with the callback event types distinguished in the callbacks. Example: **actionTypeMask = GESTURE_EVENT_ACTION_ACCEPT**| GESTURE_EVENT_ACTION_UPDATE; |
| void* extraParams                                                                         | Context passed in the **targetReceiver** callback.|
| targetReceiver                                                                            | Callback to register for processing the gesture event types. **event** indicates the gesture callback data.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful.<br>            Returns **401** if a parameter error occurs.|

### addGestureToNode()

```
int32_t (*addGestureToNode)(ArkUI_NodeHandle node, ArkUI_GestureRecognizer* recognizer, ArkUI_GesturePriority mode, ArkUI_GestureMask mask)
```

**Description**


Adds a gesture to a UI component.

**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node                          | UI component to which you want to add the gesture.|
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | Gesture to be added to the UI component.|
| [ArkUI_GesturePriority](capi-native-gesture-h.md#arkui_gesturepriority) mode              | Gesture event mode. Available options are **NORMAL_GESTURE**, **PARALLEL_GESTURE**, and **PRIORITY_GESTURE**.|
| [ArkUI_GestureMask](capi-native-gesture-h.md#arkui_gesturemask) mask                      | Gesture masking mode.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful.<br>            Returns **401** if a parameter error occurs.|

### removeGestureFromNode()

```
int32_t (*removeGestureFromNode)(ArkUI_NodeHandle node, ArkUI_GestureRecognizer* recognizer)
```

**Description**


Removes a gesture from a node.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Node from which you want to remove the gesture.|
|  [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | Gesture to be removed.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful.<br>            Returns **401** if a parameter error occurs.|

### setGestureInterrupterToNode()

```
int32_t (*setGestureInterrupterToNode)(ArkUI_NodeHandle node, ArkUI_GestureInterruptResult (*interrupter)(ArkUI_GestureInterruptInfo* info))
```

**Description**


Sets a gesture interruption callback for a node.

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Node for which you want to set a gesture interruption callback.|
| interrupter                                                      | Gesture interruption callback to set. **info** indicates the gesture interruption data. If **interrupter** returns **GESTURE_INTERRUPT_RESULT_CONTINUE**, the gesture recognition process proceeds properly; if it returns **GESTURE_INTERRUPT_RESULT_REJECT**, the gesture recognition process is interrupted.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful.<br>            Returns **401** if a parameter error occurs.|

### getGestureType()

```
ArkUI_GestureRecognizerType (*getGestureType)(ArkUI_GestureRecognizer* recognizer)
```

**Description**


Obtains the type of a gesture.

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* recognizer | Pointer to the gesture.|

**Returns**

| Type                                                                                 | Description|
|-------------------------------------------------------------------------------------| -- |
| [ArkUI_GestureRecognizerType](capi-native-gesture-h.md#arkui_gesturerecognizertype) | Returns the gesture type.|

### setInnerGestureParallelTo()

```
int32_t (*setInnerGestureParallelTo)(ArkUI_NodeHandle node, void* userData, ArkUI_GestureRecognizer* (*parallelInnerGesture)(ArkUI_ParallelInnerGestureEvent* event))
```

**Description**


Sets the callback function for the parallel internal gesture event.

**Parameters**

| Name                                                             | Description|
|------------------------------------------------------------------| -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | ArkUI node for which the callback of the parallel internal gesture event is to be set.|
| void* userData                                                         | Custom data.|
| parallelInnerGesture                                             | Parallel internal gesture event. **event** returns the data of the parallel internal gesture event. **parallelInnerGesture** returns the pointer to the gesture recognizer that requires parallel recognition.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>            Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### createTapGestureWithDistanceThreshold()

```
ArkUI_GestureRecognizer* (*createTapGestureWithDistanceThreshold)(int32_t countNum, int32_t fingersNum, double distanceThreshold)
```

**Description**


Creates a tap gesture that is subject to distance restrictions.1. This API is used to trigger a tap gesture with one, two, or more taps.<br>        2. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.<br>        3. If the distance between the last tapped position and the current tapped position exceeds 60 vp, gesture recognition fails.<br>        4. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers touching the screen within 300 ms of the first finger touch is less than the required number,<br>           or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted is less than the required number.<br>        5. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized.<br>        6. If the finger moves beyond the preset distance limit, gesture recognition fails.<br>

**Parameters**

| Name| Description|
| -- | -- |
| int32_t countNum | Number of consecutive taps. If the value is less than 1 or is not set, the default value **1** is used.|
|  int32_t fingersNum | Number of fingers required to trigger the tap gesture. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value **1** is used.|
|  double distanceThreshold | Allowed moving distance of a finger. If the value is less than 0 or is not set, it will be converted to the default value of infinity.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_GestureRecognizer](capi-arkui-nativemodule-arkui-gesturerecognizer.md)* | Returns the pointer to the created gesture.|
