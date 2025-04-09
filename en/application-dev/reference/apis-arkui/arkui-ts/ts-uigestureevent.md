# Bound Gesture Configuration

You can set the gestures that are bound to a component. Specifically, you can add or remove gestures by calling the APIs of the **UIGestureEvent** object.

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## UIGestureEvent

Provides APIs for configuring gestures bound to a component.

### addGesture

addGesture(gesture: GestureHandler\<T>, priority?: GesturePriority, mask?: GestureMask): void

Adds a gesture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| gesture  |  [GestureHandler\<T>](#gesturehandlert) | Yes  | Gesture handler object.|
| priority  |  [GesturePriority](#gesturepriority) | No  | Priority of the bound gesture.|
| mask  |  [GestureMask](./ts-gesture-settings.md#gesturemask) | No  | Mask for gesture events.|

### addParallelGesture

addParallelGesture(gesture: GestureHandler\<T>, mask?: GestureMask): void

Adds a gesture that can be recognized at once by the component and its child component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| gesture  |  [GestureHandler\<T>](#gesturehandlert) | Yes  | Gesture handler object.|
| mask  |  [GestureMask](./ts-gesture-settings.md#gesturemask) | No  | Mask for gesture events.|

### removeGestureByTag

removeGestureByTag(tag: string): void

Remove a gesture from a component that has been bound with a specific tag through a modifier.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| tag  |  string | Yes  | Gesture handler flag.|

### clearGestures

clearGestures(): void

Clears all gestures that have been bound to the component through a modifier.

**Atomic service API**: This API can be used in atomic services since API version 12.

## GestureHandler\<T>

Defines the basic type of the gesture handler.

### tag

tag(tag: string): T

Sets the tag for the gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory|Description                                       |
| ----  | ------  | ------|---------------------------------- |
| tag   | string  | Yes|Tag of the gesture handler.|

### allowedTypes<sup>14+</sup>

allowedTypes(types: Array\<SourceTool>): T

Sets the event input sources supported by the gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory|Description                                       |
| ----  | ------  | ------|---------------------------------- |
| types   | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)>  | Yes|Event input sources supported by the gesture handler.|

## TapGestureHandler

Defines a type of gesture handler object for tap gestures.

### constructor

constructor(options?: TapGestureHandlerOptions)

A constructor used to create a **TapGestureHandler** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type                                                        | Mandatory| Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [TapGestureHandlerOptions](#tapgesturehandleroptions) | No  | Parameters of the tap gesture handler.|

### onAction

onAction(event: Callback\<GestureEvent>): TapGestureHandler

Invoked when a tap gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when a tap gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| TapGestureHandler | Tap gesture handler object.|

## TapGestureHandlerOptions

Provides the parameters of the tap gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory| Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| count | number | No| Number of consecutive taps. If the value is less than 1 or is not set, the default value is used.<br>Default value: **1**<br>**NOTE**<br>1. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.<br>2. If the distance between the last tapped position and the current tapped position exceeds 60 vp, gesture recognition fails.|
| fingers | number | No| Number of fingers required to trigger a tap. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value is used.<br>Default value: **1**<br>**NOTE**<br>1. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers pressing the screen within 300 ms of the first finger's being pressed is less than the required number, or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted is less than the required number.<br>2. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen.<br>**true**: Enforce the exact number of fingers touching the screen.<br>**false**: Do not enforce the exact number of fingers touching the screen.<br> With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**.<br>In multi-tap events (where the **count** parameter is greater than 1), each tap must have the same number of fingers as the configured value; otherwise, the gesture recognition fails.<br>Default value: **false**.|

## LongPressGestureHandler

Defines a type of gesture handler object for long press gestures.

### constructor

constructor(options?: LongPressGestureHandlerOptions)

A constructor used to create a **LongPressGestureHandler** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**


| Name | Type                                                        | Mandatory| Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [LongPressGestureHandlerOptions](#longpressgesturehandleroptions) | No  | Parameters of the long press gesture handler.|

### onAction

onAction(event: Callback\<GestureEvent>): LongPressGestureHandler

Invoked when a long press gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when a long press gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| LongPressGestureHandler | Long press gesture handler object.|

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): LongPressGestureHandler

Invoked when the last finger is lifted after the long press gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when the last finger is lifted after the long press gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| LongPressGestureHandler | Long press gesture handler object.|

### onActionCancel

onActionCancel(event: Callback\<void>): LongPressGestureHandler

Invoked when a tap cancellation event is received after a long press gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | Yes| Callback invoked when a tap cancellation event is received after a long press gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| LongPressGestureHandler | Long press gesture handler object.|

## LongPressGestureHandlerOptions

Provides the parameters of the long press gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory| Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No| Minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10.<br>Default value: **1**<br> **NOTE**<br>If a finger moves more than 15 px after being pressed, the gesture recognition fails.|
| repeat | boolean | No| Whether to continuously trigger the event callback. The value **true** means to continuously trigger the event callback, and **false** means the opposite.<br>Default value: **false**.|
| duration | number | No| Minimum hold-down time, in ms.<br>Default value: **500**<br>**NOTE**<br>Value range: [0, +∞). If the value is less than or equal to 0, the default value **500** is used.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen.<br>**true**: Enforce the exact number of fingers touching the screen.<br>**false**: Do not enforce the exact number of fingers touching the screen.<br> With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**.<br>For gestures that have already been successfully recognized, changes in the number of fingers touching the screen will not trigger the repeat event. However, if the number of fingers touching the screen returns to the configured minimum number, the [onAction](ts-basic-gestures-longpressgesture.md#events) event can be triggered. The [onActionEnd](ts-basic-gestures-longpressgesture.md#events) event can also be triggered regardless of the finger count.<br>Default value: **false**.|

## PanGestureHandler

Defines a type of gesture handler object for pan gestures.

### constructor

constructor(options?: PanGestureHandlerOptions)

A constructor used to create a **PanGestureHandler** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**


| Name | Type                                                        | Mandatory| Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [PanGestureHandlerOptions](#pangesturehandleroptions) | No  | Parameters of the pan gesture handler.|

### onActionStart

onActionStart(event: Callback\<GestureEvent>): PanGestureHandler

Invoked when a pan gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when a pan gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| PanGestureHandler | Pan gesture handler object.|

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): PanGestureHandler

Invoked during the movement of a pan gesture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked during the movement of a pan gesture.<br>If **fingerList** contains multiple fingers, this callback updates the location information of only one finger each time.|

**Return value**

| Type| Description|
| -------- | -------- |
| PanGestureHandler | Pan gesture handler object.|

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): PanGestureHandler

Invoked when the finger used for a pan gesture is lifted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when the finger used for a pan gesture is lifted.|

**Return value**

| Type| Description|
| -------- | -------- |
| PanGestureHandler | Pan gesture handler object.|

### onActionCancel

onActionCancel(event: Callback\<void>): PanGestureHandler

Invoked when a tap cancellation event is received after a pan gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | Yes| Callback invoked when a tap cancellation event is received after a pan gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| PanGestureHandler | Pan gesture handler object.|

## PanGestureHandlerOptions

Provides the parameters of the pan gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory| Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No| Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**<br>Value range: [1, 10]<br>**NOTE**<br>If the value is less than 1 or is not set, the default value is used.|
| direction | [PanDirection](./ts-basic-gestures-pangesture.md#pandirection) | No| Pan direction. The value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**|
| distance | number | No| Minimum pan distance to trigger the gesture, in vp.<br>Default value: **5**<br>**NOTE**<br>If a pan gesture and a [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** so that the gesture can be more easily recognized.<br>Value range: [0, +∞). If the value specified is less than 0, the default value **5** is used.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen.<br>**true**: Enforce the exact number of fingers touching the screen.<br>**false**: Do not enforce the exact number of fingers touching the screen.<br> With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**. The gesture can only be successfully recognized if the number of fingers touching the screen equals the configured minimum number and the swipe distance meets the threshold.<br>For gestures that have already been successfully recognized, changing the number of fingers touching the screen will not trigger the [onActionUpdate](ts-basic-gestures-pangesture.md#events) event, but the [onActionEnd](ts-basic-gestures-pangesture.md#events) event can still be triggered.<br>Default value: **false**.|

## SwipeGestureHandler

Defines a type of gesture handler object for swipe gestures.

### constructor

constructor(options?: SwipeGestureHandlerOptions)

A constructor used to create a **SwipeGestureHandler** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type                                                        | Mandatory| Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [SwipeGestureHandlerOptions](#swipegesturehandleroptions) | No  | Parameters of the swipe gesture handler.|

### onAction

onAction(event: Callback\<GestureEvent>): SwipeGestureHandlerOptions

Invoked when a swipe gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when a swipe gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| SwipeGestureHandler | Swipe gesture handler object.|

## SwipeGestureHandlerOptions

Provides the parameters of the swipe gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory| Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No| Minimum number of fingers to trigger a swipe gesture. The value ranges from 1 to 10.<br>Default value: **1**|
| direction | [SwipeDirection](./ts-basic-gestures-swipegesture.md#swipedirection) | No| Swipe direction.<br>Default value: **SwipeDirection.All**|
| speed | number | No| Minimum speed of the swipe gesture.<br>Default value: 100 vp/s<br>**NOTE**<br>If the value is less than or equal to 0, it will be converted to the default value.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen.<br>**true**: Enforce the exact number of fingers touching the screen.<br>**false**: Do not enforce the exact number of fingers touching the screen.<br> With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**.<br>Default value: **false**.|

## PinchGestureHandler

Defines a type of gesture handler object for pinch gestures.

### constructor

constructor(options?: PinchGestureHandlerOptions)

A constructor used to create a **PinchGestureHandler** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**


| Name | Type                                                        | Mandatory| Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [PinchGestureHandlerOptions](#pinchgesturehandleroptions) | No  | Parameters of the pinch gesture handler.|

### onActionStart

onActionStart(event: Callback\<GestureEvent>): PinchGestureHandler

Invoked when a pinch gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when a pinch gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| PinchGestureHandler | Pinch gesture handler object.|

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): PinchGestureHandler

Invoked during the movement of a pinch gesture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked during the movement of a pinch gesture.|

**Return value**

| Type| Description|
| -------- | -------- |
| PinchGestureHandler | Pinch gesture handler object.|

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): PinchGestureHandler

Invoked when the finger used for a pinch gesture is lifted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when the finger used for a pinch gesture is lifted.|

**Return value**

| Type| Description|
| -------- | -------- |
| PinchGestureHandler | Pinch gesture handler object.|

### onActionCancel

onActionCancel(event: Callback\<void>): PinchGestureHandler

Invoked when a tap cancellation event is received after a pinch gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | Yes| Callback invoked when a tap cancellation event is received after a pinch gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| PinchGestureHandler | Pan gesture handler object.|

## PinchGestureHandlerOptions

Provides the parameters of the pinch gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory| Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No| Minimum number of fingers to trigger a pinch. The value ranges from 2 to 5.<br>Default value: **2**<br>While more fingers than the minimum number can be pressed to trigger the gesture, only the first fingers of the minimum number participate in gesture calculation.|
| distance | number | No| Minimum recognition distance, in vp.<br>Default value: **5**<br>**NOTE**<br> If the value is less than or equal to 0, it will be converted to the default value.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen.<br>**true**: Enforce the exact number of fingers touching the screen.<br>**false**: Do not enforce the exact number of fingers touching the screen.<br> With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**. The gesture can only be successfully recognized if the number of fingers equals the configured minimum and the swipe distance meets the threshold. Note that only the first two fingers that touch the screen are considered for the gesture. If one of these fingers is lifted, the gesture recognition fails. For gestures that have already been successfully recognized, changing the number of fingers touching the screen will not trigger the [onActionUpdate](ts-basic-gestures-pinchgesture.md#events) event, but the [onActionEnd](ts-basic-gestures-pinchgesture.md#events) event can still be triggered.<br>Default value: **false**.|

## RotationGestureHandler

Defines a type of gesture handler object for rotation gestures.

### constructor

constructor(options?: RotationGestureHandlerOptions)

A constructor used to create a **RotationGestureHandler** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**


| Name | Type                                                        | Mandatory| Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [RotationGestureHandlerOptions](#rotationgesturehandleroptions) | No  | Parameters of the rotation gesture handler.|

### onActionStart

onActionStart(event: Callback\<GestureEvent>): RotationGestureHandler

Invoked when a rotation gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when a rotation gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| RotationGestureHandler | Pan gesture handler object.|

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): RotationGestureHandler

Invoked during the movement of the rotation gesture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked during the movement of the rotation gesture.|

**Return value**

| Type| Description|
| -------- | -------- |
| RotationGestureHandler | Pan gesture handler object.|

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): RotationGestureHandler

Invoked when the finger used for the rotation gesture is lifted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes| Callback invoked when the finger used for the rotation gesture is lifted.|

**Return value**

| Type| Description|
| -------- | -------- |
| RotationGestureHandler | Rotation gesture handler object.|

### onActionCancel

onActionCancel(event: Callback\<void>): RotationGestureHandler

Invoked when a tap cancellation event is received after the rotation gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | Yes| Callback invoked when a tap cancellation event is received after the rotation gesture is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| RotationGestureHandler | Pan gesture handler object.|

## RotationGestureHandlerOptions

Provides the parameters of the rotation gesture handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory| Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No| Minimum number of fingers to trigger a rotation. The value ranges from 2 to 5.<br>Default value: **2**<br>While more fingers than the minimum number can be pressed to trigger the gesture, only the first two fingers participate in gesture calculation.|
| angle | number | No| Minimum degree that can trigger the rotation gesture.<br>Default value: **1**<br>**NOTE**<br>If the value is less than or equal to 0 or greater than 360, it will be converted to the default value.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen.<br>**true**: Enforce the exact number of fingers touching the screen.<br>**false**: Do not enforce the exact number of fingers touching the screen.<br> With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**. The gesture can only be successfully recognized if the number of fingers equals the configured minimum and the swipe distance meets the threshold. Note that only the first two fingers that touch the screen are considered for the gesture. If one of these fingers is lifted, the gesture recognition fails.<br>For gestures that have already been successfully recognized, changing the number of fingers touching the screen will not trigger the[onActionUpdate](ts-basic-gestures-rotationgesture.md#events) event, but the [onActionEnd](ts-basic-gestures-rotationgesture.md#events) event can still be triggered.<br>Default value: **false**.|

## GestureGroupHandler

Defines a type of gesture handler object for gesture groups.

### constructor

constructor(options?: GestureGroupGestureHandlerOptions)

A constructor used to create a **GestureGroupHandler** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type                                                        | Mandatory| Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [GestureGroupGestureHandlerOptions](#gesturegroupgesturehandleroptions) | No  | Parameters of the gesture group handler.|

### onCancel

onCancel(event: Callback\<void>): GestureGroupHandler

Invoked when a cancellation event is received after the gesture group in sequential gesture recognition (**GestureMode.Sequence**) is recognized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                             | Mandatory| Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | Yes| Callback invoked when a cancellation event is received after the gesture group in sequential gesture recognition **GestureMode.Sequence**) is recognized.|

**Return value**

| Type| Description|
| -------- | -------- |
| GestureGroupHandler | Gesture group handler object.|

## GestureGroupGestureHandlerOptions

Provides the parameters of the gesture group handler.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory| Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| mode    | [GestureMode](./ts-combined-gestures.md#gesturemode)                          | Yes  | Recognition mode of combined gestures.<br>Default value: **GestureMode.Sequence**     |
| gestures | [GestureHandler](#gesturehandlert)\<[TapGestureHandler](#tapgesturehandler) \| [LongPressGestureHandler](#longpressgesturehandler) \| [PanGestureHandler](#pangesturehandler) \| [SwipeGestureHandler](#swipegesturehandler) \| [PinchGestureHandler](#pinchgesturehandler) \| [RotationGestureHandler](#rotationgesturehandler) \| [GestureGroupHandler](#gesturegrouphandler)>[] | Yes  | Gestures that need to be included in the gesture group.<br>**NOTE**<br>To add both tap and double-tap gestures for a component, add two TapGestures, with the tap gesture added after the double-tap gesture.|

## GesturePriority

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Description|
| -------- | -------- |
| NORMAL | Normal priority.|
| PRIORITY | High priority.|

## Example

For details, see [Gesture Modifier](./ts-universal-attributes-gesture-modifier.md).
