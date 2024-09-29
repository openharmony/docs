# ArkUI_NativeGestureAPI_1


## Overview

Defines the gesture APIs.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [version](#version) | The struct version is 1. | 
| ArkUI_GestureRecognizer \*(\* [createTapGesture](#createtapgesture) )(int32_t countNum, int32_t fingersNum) | Creates a tap gesture. | 
| ArkUI_GestureRecognizer \*(\* [createTapGestureWithDistance](#createtapgesturewithdistance) )(int32_t countNum, int32_t fingersNum, int32_t distance) | Creates a tap gesture that is subject to distance restrictions. | 
| ArkUI_GestureRecognizer \*(\* [createLongPressGesture](#createlongpressgesture) )(int32_t fingersNum, bool repeatResult, int32_t durationNum) | Creates a long press gesture. | 
| ArkUI_GestureRecognizer \*(\* [createPanGesture](#createpangesture) )(int32_t fingersNum, [ArkUI_GestureDirectionMask](_ark_u_i___native_module.md#arkui_gesturedirectionmask) directions, double distanceNum) | Creates a pan gesture. | 
| ArkUI_GestureRecognizer \*(\* [createPinchGesture](#createpinchgesture) )(int32_t fingersNum, double distanceNum) | Creates a pinch gesture. | 
| ArkUI_GestureRecognizer \*(\* [createRotationGesture](#createrotationgesture) )(int32_t fingersNum, double angleNum) | Creates a rotation gesture. | 
| ArkUI_GestureRecognizer \*(\* [createSwipeGesture](#createswipegesture) )(int32_t fingersNum, [ArkUI_GestureDirectionMask](_ark_u_i___native_module.md#arkui_gesturedirectionmask) directions, double speedNum) | Creates a swipe gesture. | 
| ArkUI_GestureRecognizer \*(\* [createGroupGesture](#creategroupgesture) )([ArkUI_GroupGestureMode](_ark_u_i___native_module.md#arkui_groupgesturemode) gestureMode) | Creates a gesture group. | 
| void(\* [dispose](#dispose) )(ArkUI_GestureRecognizer \*recognizer) | Disposes of a gesture to release resources. | 
| int32_t(\* [addChildGesture](#addchildgesture) )(ArkUI_GestureRecognizer \*group, ArkUI_GestureRecognizer \*child) | Adds a gesture to a gesture group. | 
| int32_t(\* [removeChildGesture](#removechildgesture) )(ArkUI_GestureRecognizer \*group, ArkUI_GestureRecognizer \*child) | Removes a gesture from a gesture group. | 
| int32_t(\* [setGestureEventTarget](#setgestureeventtarget) )(ArkUI_GestureRecognizer \*recognizer, [ArkUI_GestureEventActionTypeMask](_ark_u_i___native_module.md#arkui_gestureeventactiontypemask) actionTypeMask, void \*extraParams, void(\*targetReceiver)(ArkUI_GestureEvent \*event, void \*extraParams)) | Registers a callback for gestures. | 
| int32_t(\* [addGestureToNode](#addgesturetonode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, ArkUI_GestureRecognizer \*recognizer, [ArkUI_GesturePriority](_ark_u_i___native_module.md#arkui_gesturepriority) mode, [ArkUI_GestureMask](_ark_u_i___native_module.md#arkui_gesturemask) mask) | Adds a gesture to a UI component. | 
| int32_t(\* [removeGestureFromNode](#removegesturefromnode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, ArkUI_GestureRecognizer \*recognizer) | Removes a gesture from a node. | 
| int32_t(\* [setGestureInterrupterToNode](#setgestureinterruptertonode) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_GestureInterruptResult](_ark_u_i___native_module.md#arkui_gestureinterruptresult)(\*interrupter)(ArkUI_GestureInterruptInfo \*info)) | Sets a gesture interruption callback for a node. | 
| [ArkUI_GestureRecognizerType](_ark_u_i___native_module.md#arkui_gesturerecognizertype)(\* [getGestureType](#getgesturetype) )(ArkUI_GestureRecognizer \*recognizer) | Obtains the type of a gesture. | 
| int32_t(\* [setInnerGestureParallelTo](#setinnergestureparallelto) )([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData, ArkUI_GestureRecognizer \*(\*parallelInnerGesture)([ArkUI_ParallelInnerGestureEvent](_ark_u_i___native_module.md#arkui_parallelinnergestureevent) \*event)) | Sets the callback function for the parallel internal gesture event. | 


## Member Variable Description


### addChildGesture

```
int32_t(* ArkUI_NativeGestureAPI_1::addChildGesture) (ArkUI_GestureRecognizer *group, ArkUI_GestureRecognizer *child)
```
**Description**

Adds a gesture to a gesture group.

**Parameters**

| Name| Description| 
| -------- | -------- |
| group | Pointer to the target gesture group. | 
| child | Pointer to the target gesture. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs, for example, if a gesture is added to an object that is not a gesture group.


### addGestureToNode

```
int32_t(* ArkUI_NativeGestureAPI_1::addGestureToNode) (ArkUI_NodeHandle node, ArkUI_GestureRecognizer *recognizer, ArkUI_GesturePriority mode, ArkUI_GestureMask mask)
```
**Description**

Adds a gesture to a UI component.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | UI component to which you want to add the gesture. | 
| recognizer | Gesture to be added to the UI component. | 
| mode | Gesture event mode. Available options are **NORMAL_GESTURE**, **PARALLEL_GESTURE**, and **PRIORITY_GESTURE**. | 
| mask | Gesture masking mode. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.


### createGroupGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createGroupGesture) (ArkUI_GroupGestureMode gestureMode)
```
**Description**

Creates a gesture group.

**Parameters**

| Name| Description| 
| -------- | -------- |
| gestureMode | Gesture group mode. | 

**Returns**

Returns the pointer to the created gesture group.


### createLongPressGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createLongPressGesture) (int32_t fingersNum, bool repeatResult, int32_t durationNum)
```
**Description**

Creates a long press gesture.

**Parameters**

| Name| Description| 
| -------- | -------- |
| fingersNum | Minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10. | 
| repeatResult | Whether to continuously trigger the event callback. | 
| durationNum | Minimum hold-down time, in ms. If the value is less than or equal to 0, the default value <b>500</b> is used. | 

**Returns**

Returns the pointer to the created gesture.


### createPanGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createPanGesture) (int32_t fingersNum, ArkUI_GestureDirectionMask directions, double distanceNum)
```
**Description**

Creates a pan gesture.

**Parameters**

| Name| Description| 
| -------- | -------- |
| fingersNum | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value **1** is used. | 
| directions | Pan direction. The value supports the AND (&amp;) and OR (\|) operations. | 
| distanceNum | Minimum pan distance to trigger the gesture, in vp. If this parameter is set to a value less than or equal to 0, the default value **5** is used. | 

**Returns**

Returns the pointer to the created gesture.


### createPinchGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createPinchGesture) (int32_t fingersNum, double distanceNum)
```
**Description**

Creates a pinch gesture.

**Parameters**

| Name| Description| 
| -------- | -------- |
| fingersNum | Minimum number of fingers to trigger a pinch. The value ranges from 2 to 5. The default value is **2**. | 
| distanceNum | Minimum recognition distance, in vp. If this parameter is set to a value less than or equal to 0, the default value **5** is used. | 

**Returns**

Returns the pointer to the created gesture.


### createRotationGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createRotationGesture) (int32_t fingersNum, double angleNum)
```
**Description**

Creates a rotation gesture.

**Parameters**

| Name| Description| 
| -------- | -------- |
| fingersNum | Minimum number of fingers to trigger a rotation. The value ranges from 2 to 5. The default value is **2**. | 
| angleNum | Minimum degree that can trigger the rotation gesture. The default value is **1**. If this parameter is set to a value less than or equal to 0 or greater than 360, the default value **1** is used. | 

**Returns**

Returns the pointer to the created gesture.


### createSwipeGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createSwipeGesture) (int32_t fingersNum, ArkUI_GestureDirectionMask directions, double speedNum)
```
**Description**

Creates a swipe gesture.

**Parameters**

| Name| Description| 
| -------- | -------- |
| fingersNum | Minimum number of fingers to trigger a swipe gesture. The value ranges from 1 to 10. | 
| directions | Swipe direction. | 
| speedNum | Minimum speed of the swipe gesture, in px/s. If this parameter is set to a value less than or equal to 0, the default value **100** is used. | 

**Returns**

Returns the pointer to the created gesture.


### createTapGesture

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createTapGesture) (int32_t countNum, int32_t fingersNum)
```
**Description**

Creates a tap gesture.

**Parameters**

| Name| Description| 
| -------- | -------- |
| countNum | Number of consecutive taps. If the value is less than 1 or is not set, the default value **1** is used. | 
| fingersNum | Number of fingers required to trigger a tap. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value **1** is used. | 

**Returns**

Returns the pointer to the created gesture.


### createTapGestureWithDistance

```
ArkUI_GestureRecognizer*(* ArkUI_NativeGestureAPI_1::createTapGestureWithDistance) (int32_t countNum, int32_t fingersNum, int32_t distance)
```
**Description**

Creates a tap gesture that is subject to distance restrictions.

**Parameters**

| Name| Description| 
| -------- | -------- |
| countNum | Number of consecutive taps. If the value is less than 1 or is not set, the default value **1** is used. | 
| fingersNum | Number of fingers required to trigger a tap. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value **1** is used. | 
| distance | Allowed moving distance of a finger. If the value is less than 0 or is not set, it will be converted to the default value of infinity. | 

**Returns**

Returns the pointer to the created gesture.


### dispose

```
void(* ArkUI_NativeGestureAPI_1::dispose) (ArkUI_GestureRecognizer *recognizer)
```
**Description**

Disposes of a gesture to release resources.

**Parameters**

| Name| Description| 
| -------- | -------- |
| recognizer | Pointer to the gesture to dispose of. | 


### getGestureType

```
ArkUI_GestureRecognizerType(* ArkUI_NativeGestureAPI_1::getGestureType) (ArkUI_GestureRecognizer *recognizer)
```
**Description**

Obtains the type of a gesture.

**Parameters**

| Name| Description| 
| -------- | -------- |
| recognizer | Pointer to the gesture. | 

**Returns**

Returns the gesture type.


### removeChildGesture

```
int32_t(* ArkUI_NativeGestureAPI_1::removeChildGesture) (ArkUI_GestureRecognizer *group, ArkUI_GestureRecognizer *child)
```
**Description**

Removes a gesture from a gesture group.

**Parameters**

| Name| Description| 
| -------- | -------- |
| group | Pointer to the target gesture group. | 
| child | Pointer to the target gesture. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.


### removeGestureFromNode

```
int32_t(* ArkUI_NativeGestureAPI_1::removeGestureFromNode) (ArkUI_NodeHandle node, ArkUI_GestureRecognizer *recognizer)
```
**Description**

Removes a gesture from a node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | Node from which you want to remove the gesture. | 
| recognizer | Gesture to be removed. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.


### setGestureEventTarget

```
int32_t(* ArkUI_NativeGestureAPI_1::setGestureEventTarget) (ArkUI_GestureRecognizer *recognizer, ArkUI_GestureEventActionTypeMask actionTypeMask, void *extraParams, void(*targetReceiver)(ArkUI_GestureEvent *event, void *extraParams))
```
**Description**

Registers a callback for gestures.

**Parameters**

| Name| Description| 
| -------- | -------- |
| recognizer | Pointer to a gesture recognizer. | 
| actionTypeMask | Gesture event types. Multiple callbacks can be registered at once, with the callback event types distinguished in the callbacks. Example: actionTypeMask = GESTURE_EVENT_ACTION_ACCEPT \| GESTURE_EVENT_ACTION_UPDATE;  | 
| extraParams | Context passed in the **targetReceiver** callback. | 
| targetReceiver | Callback to register for processing the gesture event types. **event** indicates the gesture callback data. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.


### setGestureInterrupterToNode

```
int32_t(* ArkUI_NativeGestureAPI_1::setGestureInterrupterToNode) (ArkUI_NodeHandle node, ArkUI_GestureInterruptResult(*interrupter)(ArkUI_GestureInterruptInfo *info))
```
**Description**

Sets a gesture interruption callback for a node.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | ArkUI node for which you want to set a gesture interruption callback. | 
| interrupter | Gesture interruption callback to set. **info** indicates the gesture interruption data. If **interrupter** returns **GESTURE_INTERRUPT_RESULT_CONTINUE**, the gesture recognition process continues. If it returns **GESTURE_INTERRUPT_RESULT_REJECT**, the gesture recognition process is paused. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.


### setInnerGestureParallelTo

```
int32_t(* ArkUI_NativeGestureAPI_1::setInnerGestureParallelTo) (ArkUI_NodeHandle node, void *userData, ArkUI_GestureRecognizer *(*parallelInnerGesture)(ArkUI_ParallelInnerGestureEvent *event))
```
**Description**

Sets the callback function for the parallel internal gesture event.

**Parameters**

| Name| Description| 
| -------- | -------- |
| node | ArkUI node for which the callback of the parallel internal gesture event is to be set. | 
| userData | User-defined data. | 
| parallelInnerGesture | Parallel internal gesture event. **event** returns the data of the parallel internal gesture event. **parallelInnerGesture** returns the pointer to the gesture recognizer that requires parallel recognition. | 

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.


### version

```
int32_t ArkUI_NativeGestureAPI_1::version
```
**Description**

The struct version is 1.
