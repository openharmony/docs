# Bound Gesture Configuration

Sets the gesture bound to the widget. The UIGestureEvent object can be used to call its interface to add or delete gestures.

>**NOTE**
>
>The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## UIGestureEvent

Sets the gesture bound to the widget.

### addGesture

addGesture(gesture: GestureHandler\<T>, priority?: GesturePriority, mask?: GestureMask): void

Add gestures.

Parameters

| Parameter | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| gesture  |  [GestureHandler\<T>](#gesturehandlert) | Yes  | Gesture processor object. |
| priority  |  [GesturePriority](#gesturepriority) | No  | Priority of the bound gesture. |
| mask  |  [GestureMask](./ts-gesture-settings.md#gesturemask) | No  | Sets the event response. |

### addParallelGesture

addParallelGesture(gesture: GestureHandler\<T>, mask?: GestureMask): void

Gesture that can be recognized at once by the component and its child component.

Parameters

| Parameter | Type  | Mandatory | Description                      |
| ------ | ------ | ---- | -------------------------- |
| gesture  |  [GestureHandler\<T>](#gesturehandlert) | Yes  | Gesture processor object. |
| mask  |  [GestureMask](./ts-gesture-settings.md#gesturemask) | No  | Sets the event response. |

### removeGestureByTag

removeGestureByTag(tag: string): void

Removes gestures that are bound by modifier and set to the specified flag on the component.

Parameters

| Parameter | Type  | Mandatory | Note:                      |
| ------ | ------ | ---- | -------------------------- |
| tag  |  string | Yes  | Gesture processor flag. |

### clearGestures

clearGestures(): void

Clears all gestures bound by modifier on the component.

## GestureHandler\<T>

Basic type of the gesture object.

### tag

tag(tag: string): T

Sets the flag of the gesture processor.

**Parameters**

| Name | Type | Mandatory |Description.                                       |
| ----  | ------  | ------|---------------------------------- |
| tag   | string  | M |Sets the gesture processor flag.|

## TapGestureHandler

Object type of the tap gesture processor.

### constructor

constructor(options?: TapGestureHandlerOptions)

A constructor used to create a **Highlights** album instance.

**Parameters**

| Name | Type                                                        | Mandatory | Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [TapGestureHandlerOptions](#tapgesturehandleroptions) | No  | Tap gesture processor configuration parameter. |

### onAction

onAction(event: Callback\<GestureEvent>): TapGestureHandler

Callback invoked when a tap gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | M | Callback invoked when a tap gesture is recognized. |

**Return value**

| Type | Usage |
| -------- | -------- |
| TapGestureHandler | Returns the current tap gesture processor object. |

## TapGestureHandlerOptions

Tap gesture processor configuration parameter.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory | Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| count | number | No | Number of consecutive taps. If the value is less than 1 or is not set, the default value is used.<br>Default value: **1**<br>**NOTE**<br>1. If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.<br>2. If the distance between the last tapped position and the current tapped position exceeds 60 vp, gesture recognition fails.|
| fingers | number | No | Number of fingers required to trigger a tap. The value ranges from 1 to 10. If the value is less than 1 or is not set, the default value is used.<br>Default value: **1**<br>**NOTE**<br>1. If the value is greater than 1, the tap gesture will fail to be recognized when the number of fingers pressing the screen within 300 ms of the first finger's being pressed is less than the required number, or when the number of fingers lifted from the screen within 300 ms of the first finger's being lifted is less than the required number.<br>2. When the number of fingers touching the screen exceeds the set value, the gesture can be recognized. |

## LongPressGestureHandler

Object type of the touch and hold gesture processor.

### constructor

constructor(options?: LongPressGestureHandlerOptions)

A constructor used to create a **Highlights** album instance.

**Parameters**


| Name | Type                                                        | Mandatory | Note:              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [LongPressGestureHandlerOptions](#longpressgesturehandleroptions) | No  | Touch and hold gesture processor configuration parameter. |

### onAction

onAction(event: Callback\<GestureEvent>): LongPressGestureHandler

Callback invoked when a long press gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note:                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | Supported | Callback invoked when a long press gesture is recognized. |

**Return value**

| Type | Requirement |
| -------- | -------- |
| LongPressGestureHandler | Returns the current touch and hold gesture processor object. |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): LongPressGestureHandler

Invoked when the last finger is lifted after the long press gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note:                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | M | Invoked when the last finger is lifted after the long press gesture is recognized. |

**Return value**

| Type | File |
| -------- | -------- |
| LongPressGestureHandler | Returns the current touch and hold gesture processor object. |

### onActionCancel

onActionCancel(event: Callback\<void>): LongPressGestureHandler

Callback invoked when a tap cancellation event is received after a long press gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | Supported | Callback invoked when a tap cancellation event is received after a long press gesture is recognized.<br>**Note:**<br>This event is triggered when the window loses focus. |

**Return value**

| Type | **Description** |
| -------- | -------- |
| LongPressGestureHandler | Returns the current touch and hold gesture processor object. |

## LongPressGestureHandlerOptions

Touch and hold gesture processor configuration parameter.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                  | Mandatory | Description.                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No | Minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10.<br>Default value: **1**<br> **Note:**<br>If a finger moves more than 15 px after being pressed, the gesture recognition fails.|
| repeat | boolean | No | Whether to continuously trigger the event callback.<br>Default value: **false** |
| duration | number | No | Minimum duration for triggering touch and hold, in milliseconds.<br>Default value: **500**<br>**Note:**<br>If the value is less than or equal to 0, the default value <b>500</b> is used.|

## PanGestureHandler

Object type of the drag gesture processor.

### constructor

constructor(options?: PanGestureHandlerOptions)

A constructor used to create a **Highlights** album instance.

**Parameters**


| Name | Type                                                        | Mandatory | Description              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [PanGestureHandlerOptions](#pangesturehandleroptions) | No  | Drag gesture processor configuration parameter. |

### onActionStart

onActionStart(event: Callback\<GestureEvent>): PanGestureHandler

Callback for the pan gestures reorganization event.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note:                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | M | Callback for the pan gestures reorganization event. |

**Return value**

| Type | Usage |
| -------- | -------- |
| PanGestureHandler | Returns the current drag gesture processor object. |

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): PanGestureHandler

Callback invoked when a pan gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | M | Callback invoked when a pan gesture is recognized.<br>If **fingerList** contains multiple fingers, this callback updates the location information of only one finger each time. |

**Return value**

| Type | **Description** |
| -------- | -------- |
| PanGestureHandler | Returns the current drag gesture processor object. |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): PanGestureHandler

Callback invoked when the finger used for a pan gesture is lift.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | M | Callback invoked when the finger used for a pan gesture is lift. |

**Return value**

| Type | Usage |
| -------- | -------- |
| PanGestureHandler | Returns the current drag gesture processor object. |

### onActionCancel

onActionCancel(event: Callback\<void>): PanGestureHandler

Callback invoked when a tap cancellation event is received after a pan gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note:                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | M | Callback invoked when a tap cancellation event is received after a pan gesture is recognized.<br>**Note:**<br>This event is triggered when the window loses focus. |

**Return value**

| Type | Usage |
| -------- | -------- |
| PanGestureHandler | Returns the current drag gesture processor object. |

## PanGestureHandlerOptions

Drag gesture processor configuration parameter.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory | Description.                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**<br>The value ranges from 1 to 10. <br>**Note:**<br>If the value is less than 1 or is not set, the default value is used. |
| direction | [PanDirection](./ts-basic-gestures-pangesture.md#pandirection) | No | Specifies the direction of the gesture that triggers the drag. The enumerated values support logical AND (&amp;) and logical OR (\).|operations.<br>Default value: PanDirection.All |
| distance | number | No | Minimum pan distance to trigger the gesture, in vp.<br>Default value: **5**<br>**NOTE**<br>[Tabs component] (ts-container-tabs.md) When the sliding event and the drag gesture event coexist, you can set distance to 1 to make the drag more sensitive and avoid event disorder.<br>If the value specified is less than **0**, the default value **5** is used. |

## SwipeGestureHandler

Object type of the slide gesture processor.

### constructor

constructor(options?: SwipeGestureHandlerOptions)

A constructor used to create a **Highlights** album instance.

**Parameters**

| Name | Type                                                        | Mandatory | Note:              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [SwipeGestureHandlerOptions](#swipegesturehandleroptions) | No  | Sliding gesture processor configuration parameter. |

### onAction

onAction(event: Callback\<GestureEvent>): SwipeGestureHandlerOptions

Invoked when the swipe gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note:                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | Supported | Invoked when the swipe gesture is recognized. |

**Return value**

| Type | Description |
| -------- | -------- |
| SwipeGestureHandler | Returns the current sliding gesture processor object. |

## SwipeGestureHandlerOptions

Configuration parameter of the sliding event processor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory | Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No | Minimum number of fingers to trigger a swipe gesture. The value ranges from 1 to 10.<br>Default value: **1** |
| direction | [SwipeDirection](./ts-basic-gestures-swipegesture.md#swipedirection) | No | Swipe direction.<br>Default value: **SwipeDirection.All** |
| speed | number | No | Minimum speed of the swipe gesture.<br>Default value: 100 vp/s<br>**Note:**<br>If the value is less than or equal to 0, it will be converted to the default value. |

## PinchGestureHandler

Object type of the pinch gesture processor.

### constructor

constructor(options?: PinchGestureHandlerOptions)

A constructor used to create a **Highlights** album instance.

**Parameters**


| Name | Type                                                        | Mandatory | Note:              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [PinchGestureHandlerOptions](#pinchgesturehandleroptions) | No  | Configuration parameter of the pinch gesture processor. |

### onActionStart

onActionStart(event: Callback\<GestureEvent>): PinchGestureHandler

Callback invoked when a pinch gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | Supported | Callback invoked when a pinch gesture is recognized. |

**Return value**

| Type | Description |
| -------- | -------- |
| PinchGestureHandler | Returns the current drag gesture processor object. |

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): PinchGestureHandler

Callback invoked during the movement of a pinch gesture.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | M | Callback invoked during the movement of a pinch gesture. |

**Return value**

| Type | Usage |
| -------- | -------- |
| PinchGestureHandler | Returns the current drag gesture processor object. |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): PinchGestureHandler

Callback invoked when the finger used for a pinch gesture is lift.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note:                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent] (ts-gesture-settings.md#gestureevent) > | Supported | Callback invoked when the finger used for a pinch gesture is lift. |

**Return value**

| Type | **Description** |
| -------- | -------- |
| PinchGestureHandler | Returns the current drag gesture processor object. |

### onActionCancel

onActionCancel(event: Callback\<void>): PinchGestureHandler

Callback invoked when a tap cancellation event is received after a pinch gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | M | Callback invoked when a tap cancellation event is received after a pinch gesture is recognized.<br>**Note:**<br>This event is triggered when the window loses focus. |

**Return value**

| Type | Description |
| -------- | -------- |
| PinchGestureHandler | Returns the current drag gesture processor object. |

## PinchGestureHandlerOptions

Configuration parameter of the pinch gesture processor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes        | Type                                  | Mandatory | Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No | Minimum number of fingers to trigger a pinch. The value ranges from 2 to 5.<br>Default value: **2**<br>While more fingers than the minimum number can be pressed to trigger the gesture, only the first fingers of the minimum number participate in gesture calculation. |
| distance | number | No | Minimum recognition distance, in vp.<br>Default value: **5**<br>**Note:**<br> If the value is less than or equal to 0, it will be converted to the default value.|

## RotationGestureHandler

Object type of the rotation gesture processor.

### constructor

constructor(options?: RotationGestureHandlerOptions)

A constructor used to create a **Highlights** album instance.

**Parameters**


| Name | Type                                                        | Mandatory | Note:              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [RotationGestureHandlerOptions](#rotationgesturehandleroptions) | No  | Configuration parameter of the rotation gesture processor. |

### onActionStart

onActionStart(event: Callback\<GestureEvent>): RotationGestureHandler

Callback invoked when a rotation gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description.                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Supported | Callback invoked when a rotation gesture is recognized. |

**Return value**

| Type | Usage |
| -------- | -------- |
| RotationGestureHandler | Returns the current drag gesture processor object. |

### onActionUpdate

onActionUpdate(event: Callback\<GestureEvent>): RotationGestureHandler

Callback invoked during the movement of the rotation gesture.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | M | Callback invoked during the movement of the rotation gesture. |

**Return value**

| Type | **Description** |
| -------- | -------- |
| RotationGestureHandler | Returns the current drag gesture processor object. |

### onActionEnd

onActionEnd(event: Callback\<GestureEvent>): RotationGestureHandler

Callback invoked when the finger used for the rotation gesture is lift.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)<[GestureEvent](ts-gesture-settings.md#gestureevent)> | M | Callback invoked when the finger used for the rotation gesture is lift. |

**Return value**

| Type | Usage |
| -------- | -------- |
| RotationGestureHandler | Returns the current drag gesture processor object. |

### onActionCancel

onActionCancel(event: Callback\<void>): RotationGestureHandler

Callback invoked when a tap cancellation event is received after the rotation gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Note:                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | M | Callback invoked when a tap cancellation event is received after the rotation gesture is recognized.<br>**Note:**<br>This event is triggered when the window loses focus. |

**Return value**

| Type | **Description** |
| -------- | -------- |
| RotationGestureHandler | Returns the current drag gesture processor object. |

## RotationGestureHandlerOptions

Configuration parameter of the rotation gesture processor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                  | Mandatory | Description.                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| fingers | number | No | Minimum number of fingers to trigger a rotation. The value ranges from 2 to 5.<br>Default value: **2**<br>While more fingers than the minimum number can be pressed to trigger the gesture, only the first two fingers participate in gesture calculation.|
| angle | number | No | Minimum degree that can trigger the rotation gesture.<br>Default value: **1**<br>**Note:**<br>If the value is less than or equal to 0 or greater than 360, it will be converted to the default value.|

## GestureGroupHandler

Gesture group processor object type.

### constructor

constructor(options?: GestureGroupGestureHandlerOptions)

A constructor used to create a **Highlights** album instance.

**Parameters**

| Name | Type                                                        | Mandatory | Note:              |
| ------- | ------------------------------------------------------------ | ---- | ------------------ |
| options | [GestureGroupGestureHandlerOptions](#gesturegroupgesturehandleroptions) | No  | Gesture group processor configuration parameter. |

### onCancel

onCancel(event: Callback\<void>): GestureGroupHandler

Callback invoked when a tap cancellation event is received after the rotation gesture is recognized.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Parameters 

| Parameter | Type                             | Mandatory | Description                |
| ------ | --------------------------------- | ---- | -------------------- |
| event  | [Callback](./ts-types.md#callback12)\<void> | M | Callback for the GestureMode.Sequence cancellation event.<br>**Note:**<br>This event is triggered when the window loses focus. |

**Return value**

| Type | **Description** |
| -------- | -------- |
| GestureGroupHandler | Returns the current gesture group processor object. |

## GestureGroupGestureHandlerOptions

Gesture group processor configuration parameter.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                  | Mandatory | Description                |
| ------------ | -------------------------------------- | ---- | -------------------- |
| mode    | [GestureMode](./ts-combined-gestures.md#gesturemode)                          | Yes  | Recognition mode of combined gestures.<br>Default value: **GestureMode.Sequence**     |
| gestures | [GestureHandler](#gesturehandlert)\<[TapGestureHandler](#tapgesturehandler) \| [LongPressGestureHandler](#longpressgesturehandler) \| [PanGestureHandler](#pangesturehandler) \| [SwipeGestureHandler](#swipegesturehandler) \| [PinchGestureHandler](#pinchgesturehandler) \| [RotationGestureHandler](#rotationgesturehandler) \| [GestureGroupHandler](#gesturegrouphandler)>[] | Yes  | Gestures to be included in the gesture group.<br>**NOTE**<br>To add both tap and double-tap gestures for a component, add two TapGestures, with the tap gesture added after the double-tap gesture. |

## GesturePriority
| Name | **Description** |
| -------- | -------- |
| NORMAL | Normal priority gestures. |
| PRIORITY | /** High-priority.|

## Example

See [Gesture Modifier](./ts-universal-attributes-gesture-modifier.md#gesture-modifier)。
