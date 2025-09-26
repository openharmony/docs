# Gesture Common APIs
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

Provides common APIs related to gestures.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## GestureInterface\<T><sup>11+</sup>

Defines the gesture API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### tag<sup>11+</sup>

tag(tag: string): T

Sets a gesture tag.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                       |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| tag  |  string | Yes  | Gesture tag.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| T | Current component.|

### allowedTypes<sup>14+</sup>

allowedTypes(types: Array\<SourceTool>): T

Sets the input types that can trigger the gesture response.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                       |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| types  |  Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | Yes  | Input types that can trigger the gesture response.|

**Return value**

| Type    | Description       |
| ------ | --------- |
| T | Current component.|

## ScrollableTargetInfo<sup>12+</sup> 

Contains information about the scrollable container component associated with the gesture recognizer. Inherits from [EventTargetInfo](#eventtargetinfo12).

### isBegin<sup>12+</sup> 

isBegin(): boolean

Checks whether this scrollable container component is scrolled to the top. If it is a **Swiper** component in loop mode, **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current scrollable container component is scrolled to the top. The value **true** means that the component is scrolled to the top, and **false** means the opposite.|

### isEnd<sup>12+</sup> 

isEnd(): boolean

Checks whether the current scroll container is scrolled to the bottom. If the container is a **Swiper** component and is in loop mode, **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current scrollable container component is scrolled to the bottom. The value **true** means that the component is scrolled to the bottom, and **false** means the opposite.|

## EventTargetInfo<sup>12+</sup> 

Provides the information about the component corresponding to the gesture recognizer.

### getId<sup>12+</sup> 

getId(): string

Obtains the ID of this component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | [ID](./ts-universal-attributes-component-id.md#id) of the current component.|

## TouchRecognizer<sup>20+</sup> 

Represents a touch gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getEventTargetInfo<sup>20+</sup>

getEventTargetInfo(): EventTargetInfo

Obtains the information about the component corresponding to this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [EventTargetInfo](#eventtargetinfo12) | Information about the component corresponding to the current gesture recognizer.|

### cancelTouch<sup>20+</sup>

cancelTouch(): void

Sends a touch cancellation event to the current gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## GestureRecognizer<sup>12+</sup> 

Gesture recognizer object.

### getTag<sup>12+</sup> 

getTag(): string

Obtains the tag of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Tag of the current gesture recognizer.|

### getType<sup>12+</sup> 

getType(): GestureControl.GestureType

Obtains the type of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureControl.GestureType](#gesturetype11) | Type of the current gesture recognizer.|

### isBuiltIn<sup>12+</sup> 

isBuiltIn(): boolean

Obtains whether this gesture recognizer is a built-in gesture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current gesture recognizer is a built-in gesture. The value **true** means that the gesture recognizer is a built-in gesture, and **false** means the opposite.|

### setEnabled<sup>12+</sup> 

setEnabled(isEnabled: boolean): void

Sets the enabled state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                          | Mandatory  | Description |
| ------- | ---------------------------------- | ---- | ----- |
| isEnabled   | boolean         | Yes   | Enabled state to set. The value **true** means that the gesture recognizer is enabled and will trigger events, and **false** means the opposite.|

### isEnabled<sup>12+</sup> 

isEnabled(): boolean

Obtains the enabled state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Enabled state of the gesture recognizer. The value **true** means that the gesture recognizer is enabled and will trigger events, and **false** means the opposite.|

### getState<sup>12+</sup> 

getState(): GestureRecognizerState

Obtains the state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureRecognizerState](#gesturerecognizerstate12) | State of the gesture recognizer.|

### getEventTargetInfo<sup>12+</sup> 

getEventTargetInfo(): EventTargetInfo

Obtains the information about the component corresponding to this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [EventTargetInfo](#eventtargetinfo12) | Information about the component corresponding to the current gesture recognizer.|

### isValid<sup>12+</sup> 

isValid(): boolean;

Whether the current gesture recognizer is valid.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current gesture recognizer is valid.<br>Returns **false** if the component bound to this recognizer is destroyed or if the recognizer is not on the response chain.<br>Returns **true** if the bound component exists and the recognizer is in the response chain.|

### getFingerCount<sup>18+</sup>

getFingerCount(): number

Obtains the number of fingers required to trigger the preset gesture.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Number of fingers required to trigger the preset gesture.<br>Value range: an integer from 1 to 10.|

### isFingerCountLimit<sup>18+</sup>

isFingerCountLimit(): boolean

Checks whether the preset gesture detects the number of fingers on the screen.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the preset gesture detects the number of fingers on the screen. Returns **true** if the gesture event is bound and the number of fingers on the touch screen is detected; **false** otherwise.|

### preventBegin<sup>20+</sup>

preventBegin(): void

Prevents a gesture recognizer from participating in the current gesture recognition before all fingers are lifted. If the system has already determined the result of the gesture recognizer (regardless of success or failure), calling this API will be ineffective. Unlike GestureRecognizer.[setEnabled](#setenabled12)(isEnabled: boolean), which only affects callback execution, this API prevents the recognizer from participating in the recognition process entirely.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## TapRecognizer<sup>18+</sup>

Implements a tap gesture recognizer object. Inherits from [GestureRecognizer](#gesturerecognizer12).

### getTapCount<sup>18+</sup>

getTapCount(): number

Obtains the number of consecutive taps required for the tap gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Number of consecutive taps required for the tap gesture to be recognized.<br>Value range: [0, +∞).|

## LongPressRecognizer<sup>18+</sup>

Implements a long press gesture recognizer. Inherits from [GestureRecognizer](#gesturerecognizer12).

### isRepeat<sup>18+</sup>

isRepeat(): boolean

Checks whether the long press gesture recognizer is set to trigger repeated callbacks.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether repeated callbacks are enabled. **true**: enabled. **false**: disabled.|

### getDuration<sup>18+</sup>

getDuration(): number

Obtains the minimum duration required for the long press gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum duration, in ms.<br>Value range: [0, +∞).|

## SwipeRecognizer<sup>18+</sup>

Implements a swipe gesture recognizer. Inherits from [GestureRecognizer](#gesturerecognizer12).

### getVelocityThreshold<sup>18+</sup>

getVelocityThreshold(): number

Obtains the minimum velocity required for the swipe gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum velocity required for the swipe gesture to be recognized, in vp/s.<br>Value range: [0, +∞).|

### getDirection<sup>18+</sup>

getDirection(): SwipeDirection

Obtains the direction for recognizing swipe gestures.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [SwipeDirection](./ts-basic-gestures-swipegesture.md#swipedirection) | Direction for recognizing swipe gestures.|

## PinchRecognizer<sup>18+</sup>

Implements a pinch gesture recognizer. Inherits from [GestureRecognizer](#gesturerecognizer12).

### getDistance<sup>18+</sup>

getDistance(): number

Obtains the minimum distance required for the pinch gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum distance required for the pinch gesture to be recognized, in vp.<br>Value range: [0, +∞).|

## RotationRecognizer<sup>18+</sup>

Implements a rotation gesture recognizer. Inherits from [GestureRecognizer](#gesturerecognizer12).

### getAngle<sup>18+</sup>

getAngle(): number

Obtains the minimum angle change required for the rotation gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum angle change required for the rotation gesture to be recognized, in degrees (deg).<br>Value range: [0, +∞).<br>**NOTE**<br>If the provided angle is less than or equal to 0 or greater than 360, it is converted to the default value **1**.|

## PanRecognizer<sup>12+</sup> 

Implements a pan gesture recognizer. Inherits from [GestureRecognizer](#gesturerecognizer12).

### getPanGestureOptions<sup>12+</sup> 

getPanGestureOptions(): PanGestureOptions

Obtains the properties of this pan gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [PanGestureOptions](./ts-basic-gestures-pangesture.md#pangestureoptions) | Properties of the current pan gesture recognizer.|

### getDirection<sup>19+</sup>

getDirection(): PanDirection

Obtains the recognized direction of this pan gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [PanDirection](./ts-basic-gestures-pangesture.md#pandirection)| Recognized direction of the current pan gesture recognizer.|

### getDistance<sup>19+</sup>

getDistance(): number

Obtains the minimum swipe distance required to trigger this pan gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum swipe distance. Unit: vp.|

### getDistanceMap<sup>19+</sup>

getDistanceMap(): Map\<SourceTool, number\>

Obtains the minimum swipe distances required for different input sources to trigger this pan gesture recognizer.

>  **NOTE**
>
>  This API only returns thresholds for input sources that were explicitly configured during pan gesture initialization. The default swipe threshold can be queried using the [SourceTool](ts-gesture-settings.md#sourcetool9).Unknown type. Unconfigured source types will not be included in the returned map.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| Map<[SourceTool](ts-gesture-settings.md#sourcetool9), number> | Minimum swipe distances per input source. Unit: vp.|

## GestureRecognizerState<sup>12+</sup> 

Enumerates the gesture recognizer states.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Value  | Description                          |
| ------- | ---- | ---------------------------------- |
| READY | 0    | Ready.|
| DETECTING    | 1    | Detecting.|
| PENDING    | 2    | Pending.|
| BLOCKED    | 3    | Blocked.|
| SUCCESSFUL    | 4    | Successful.|
| FAILED    | 5    | Failed.|

## GestureEvent

Defines the gesture event information. Inherits from [BaseEvent](ts-gesture-customize-judge.md#baseevent8).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type |   Read-Only | Optional   |  Description|
| -------- | -------- | ---- | ---- |-------- |
| repeat | boolean | No|  No |Whether the event is a repeated trigger event, used in the **LongPressGesture** scenarios. The value **true** means that the event is a repeated trigger event, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| offsetX | number | No| No |X-axis offset of the gesture event relative to the finger press position, in vp. Used in **PanGesture** scenarios. A positive value means to pan from left to right, and a negative value means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>Value range: (-∞, +∞).|
| offsetY | number | No| No |Y-axis offset of the gesture event relative to the finger press position, in vp. Used in **PanGesture** scenarios. A positive value means to pan from top to bottom, and a negative value means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>Value range: (-∞, +∞). |
| angle | number | No| No |Rotation angle for the **RotationGesture** event;<br>angle of the swipe gesture for the **SwipeGesture** event, that is, the change in the included angle between the line segment created by the two fingers and the horizontal direction.<br>**NOTE**<br>Angle calculation method: After a swipe gesture is recognized, a line connecting the two fingers is identified as the initial line. As the fingers swipe, the line between the fingers rotates. Based on the coordinates of the initial line's and current line's end points, the arc tangent function is used to calculate the respective included angle of the points relative to the horizontal direction by using the following formula: Rotation angle = arctan2(cy2-cy1,cx2-cx1) - arctan2(y2-y1,x2-x1). The initial line is used as the coordinate system. The clockwise rotation is 0 to 180 degrees, and the counter-clockwise rotation is -180 to 0 degrees.<br>Value range: [-180, +180].<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| scale | number |No| No |Scale ratio. This attribute is used for the pinch gesture.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| pinchCenterX | number | No| No |X-coordinate of the pinch center, in vp. Used for the **PinchGesture** event.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| pinchCenterY | number | No| No |Y-coordinate of the pinch center, in vp. Used for the **PinchGesture** event.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| speed<sup>8+</sup> | number | No| No |Swipe gesture speed, that is, the average swipe speed of all fingers relative to the original area of the current component, in vp/s. Used for the **SwipeGesture** event.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fingerList<sup>8+</sup> | [FingerInfo](./ts-gesture-common.md#fingerinfo8)[] | No| No |List of touch points of the gesture event. If the event input device is touchscreen, the list includes all touch points. If the event input device is mouse or touchpad, the list contains only one touch point.<br>**NOTE**<br>The index of a finger corresponds to its position, that is, the ID of a finger in **fingerList[index]** refers to its index. If a finger is pressed first and does not participate in triggering of the current gesture, its position in **fingerList** is left empty.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fingerInfos<sup>20+</sup> | [FingerInfo](./ts-gesture-common.md#fingerinfo8)[] | No| Yes |Information about touch points of the gesture event. For gesture events initiated by a touchscreen, **fingerInfos** includes information about all touch points. For gesture events initiated by a mouse or touchpad, **fingerInfos** contains only one touch point.<br> **NOTE**<br>**fingerInfos** only records information about effective fingers that participate in the touch. Fingers that are pressed first but do not participate in triggering of the current gesture will not be shown in **fingerInfos**. The default value is an empty array **[]**, and an empty array indicates no effective touch point information.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| velocityX<sup>10+</sup> | number | No| No |Velocity along the x-axis. This parameter is used in [PanGesture](ts-basic-gestures-pangesture.md). The origin of the coordinate axis is the upper left corner of the screen. The velocity is positive if the movement is from left to right, and it is negative if the movement is from right to left. The unit is vp/s.<br>Value range: (-∞, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| velocityY<sup>10+</sup> | number | No| No |Velocity along the y-axis. This parameter is used in [PanGesture](ts-basic-gestures-pangesture.md). The origin of the coordinate axis is the upper left corner of the screen. The velocity is positive if the movement is from top to bottom, and it is negative if the movement is from bottom to top. The unit is vp/s.<br>Value range: (-∞, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| velocity<sup>10+</sup> | number | No| No |Velocity along the main axis. This parameter is used in [PanGesture](ts-basic-gestures-pangesture.md). The value is the arithmetic square root of the sum of squares of the velocity along the x- and y-axis. The unit is vp/s.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| tapLocation<sup>20+</sup> | [EventLocationInfo](ts-basic-gestures-tapgesture.md#eventlocationinfo20) | No| Yes |Coordinate information of the current tap gesture.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|

## GestureMask<sup>11+</sup>

Enumerates masking modes of child component gestures.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name|Value| Description|
| -------- | ---- |-------- |
| Normal | - |The gestures of child components are enabled and recognized based on the default gesture recognition sequence.|
| IgnoreInternal | - | The gestures of child components are disabled, including the built-in gestures, such as the built-in swipe gesture for a **List** component. If the areas of the parent and child components are partly overlapped, only gestures in the overlapped areas are disabled.|

## GestureJudgeResult<sup>12+</sup>

Enumerates gesture competition results.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value| Description                              |
| ----- | -------- | ----------------------- |
| CONTINUE  | 0 | The system gesture recognition process continues.|
| REJECT  | 1 | Gesture recognition fails.|

## GestureType<sup>11+</sup>

Enumerates gesture recognizer types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value| Description                                  |
| ----- | -------- | ------------------------------- |
| TAP_GESTURE   | 0 | Tap gesture.|
| LONG_PRESS_GESTURE  | 1 | Long press gesture.|
| PAN_GESTURE    | 2 | Pan.|
| PINCH_GESTURE   | 3 | Pinch gesture.|
| SWIPE_GESTURE    | 4 | Swipe gesture.|
| ROTATION_GESTURE   | 5 | Rotation gesture.|
| DRAG    | 6 | Drag and drop.|
| CLICK   | 7 | Click.|

## GestureInfo<sup>11+</sup>

Defines the gesture information type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type                 | Read-Only| Optional| Description        |
| ---------------  | ---------------------|----|------| -----------|
| tag              | string                | No| Yes| Gesture tag.<br>**NOTE**<br>Returns **undefined** if the gesture's **tag** attribute was not set.     |
| type             | [GestureControl.GestureType](./ts-gesture-common.md#gesturetype11) | No| No| Gesture type.<br>**NOTE**<br> Returns **-1** for built-in gestures of unexposed types.|
| isSystemGesture  | boolean                 | No| No| Whether the gesture is a system (component built-in) gesture. **true**: yes. false: no.<br>Default value: **false**.|

## FingerInfo<sup>8+</sup>

Defines the finger information type.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- |  -------- |--------- |-------- |
| id | number | No | No    |Index of the finger, determined by the number of fingers pressed. The first pressed finger is assigned 0, with the index incrementing by one for each subsequent finger.<br>**NOTE**<br> Indexes for other input sources (mouse: 1001, stylus: 102, mouse wheel: 0, two-finger trackpad slide: 0) are also converted to finger indexes.<br>Value range: [0, 9).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| globalX | number | No |  No    |X-coordinate relative to the upper left corner of the application window, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| globalY | number | No |  No    |Y-coordinate relative to the upper left corner of the application window, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| localX | number | No |  No    |X-coordinate relative to the upper left corner of the current component's original area, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| localY | number | No |  No    |Y-coordinate relative to the upper left corner of the current component's original area, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayX<sup>12+</sup> | number | No | No    | X-coordinate relative to the upper left corner of the screen, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| displayY<sup>12+</sup> | number | No |  No    |Y-coordinate relative to the upper left corner of the screen, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| hand<sup>15+</sup> | [InteractionHand](./ts-appendix-enums.md#interactionhand15) | No |  Yes    |Whether the event is triggered by a left-hand or right-hand tap.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| globalDisplayX<sup>20+</sup> | number | No |  Yes    |X-coordinate relative to the upper left corner of the global display, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| globalDisplayY<sup>20+</sup> | number | No |  Yes    |Y-coordinate relative to the upper left corner of the global display, in vp.<br>Value range: [0, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## GestureType<sup>11+</sup>

declare type GestureType = TapGesture | LongPressGesture | PanGesture | PinchGesture | SwipeGesture | RotationGesture | GestureGroup

Enumerates gesture recognizer types. The value type is a union of the types listed in the table below.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type| Description|
| -------- | -------- |
| [TapGesture](ts-basic-gestures-tapgesture.md) | Tap gesture, which can be a single-tap or multi-tap gesture.|
| [LongPressGesture](ts-basic-gestures-longpressgesture.md) | Long press gesture.|
| [PanGesture](ts-basic-gestures-pangesture.md) | Pan gesture (triggered when the movement distance of a finger on the screen reaches the minimum value, which is 5 vp by default).|
| [PinchGesture](ts-basic-gestures-pinchgesture.md) | Pinch gesture.|
| [RotationGesture](ts-basic-gestures-rotationgesture.md) | Rotation gesture.|
| [SwipeGesture](ts-basic-gestures-swipegesture.md) | Swipe gesture (triggered when the swipe speed exceeds the specified threshold, which is 100 vp/s by default).|
| [GestureGroup](ts-combined-gestures.md) | A group of gestures. Continuous recognition, parallel recognition, and exclusive recognition are supported.|

## BaseGestureEvent<sup>11+</sup>

Defines the basic gesture event type. Inherits from [BaseEvent](./ts-gesture-customize-judge.md#baseevent8).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                 | Read-Only  |    Optional  | Description       |
| ---------  | -------------------------------------|-------| -----------|  -----------|
| fingerList | [FingerInfo[]](./ts-gesture-common.md#fingerinfo8) | No| No| Information about all fingers triggering the event.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| fingerInfos<sup>20+</sup> | [FingerInfo[]](./ts-gesture-common.md#fingerinfo8)  | No| Yes| Information about all valid touch points. The default value is an empty array **[]**, and an empty array indicates no effective touch point information.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## TapGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type  | Read-Only| Optional                               | Description        |
| ---------  | --- | ------|-------------------------------  | -----------|
| tapLocation<sup>20+</sup>  | [EventLocationInfo](ts-basic-gestures-tapgesture.md#eventlocationinfo20)| No| Yes| Coordinates of the tap gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## LongPressGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                              | Read-Only| Optional      | Description        |
| ---------  | ----------------------------------|-----| ----------|----------|
| repeat     | boolean                           | No | No   | Whether the event is a repeated trigger event. **true**: The event is repeated. **false**: The event is not repeated. |

## PanGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type      | Read-Only   | Optional    | Description        |
| ---------  | ---------|-----  | ----------|--------------|
| offsetX    | number | No| No| Offset of the gesture event on the x-axis relative to the original area of the current component, in vp. A positive value means to pan from left to right, and a negative value means the opposite. |
| offsetY    | number | No| No| Offset of the gesture event on the y-axis relative to the original area of the current component, in vp. A positive value means to pan from top to bottom, and a negative value means the opposite. |
| velocityX  | number | No| No| Velocity along the x-axis. The origin of the coordinate axis is the upper left corner of the screen. The velocity is positive if the movement is from left to right, and it is negative if the movement is from right to left. The unit is vp/s. |
| velocityY  | number | No| No| Velocity along the y-axis. The origin of the coordinate axis is the upper left corner of the screen. The velocity is positive if the movement is from top to bottom, and it is negative if the movement is from bottom to top. The unit is vp/s.|
| velocity   | number | No| No| Velocity along the main axis. The value is the arithmetic square root of the sum of squares of the velocity along the x- and y-axis. The unit is vp/s. |

## PinchGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type    | Read-Only| Optional| Description        |
| ------------  | --------|-----------|---------------------  | -----------|
| scale         | number | No| No| Scale factor. |
| pinchCenterX  | number | No| No| X-coordinate of the center of the pinch gesture, in vp, relative to the original area of the current component. |
| pinchCenterY  | number | No| No| Y-coordinate of the center of the pinch gesture, in vp, relative to the original area of the current component. |

## RotationGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                             |Read-Only| Optional       | Description        |
| ------------  | ---------------------------------|----|--------------| -----------|
| angle         | number | No| No|   Rotation angle, in deg.<br>**NOTE**<br>Angle calculation: Once a rotation gesture is detected, the line connecting two fingers is considered the start line. As the fingers move, the line between them rotates. Based on the coordinates of the start line and the current line, the included angle relative to the horizontal axis is computed using the arctangent function.<br>The final angle is calculated as follows: arctan2(cy2 - cy1, cx2 - cx1) - arctan2(y2 - y1, x2 - x1).<br>If the start line is taken as the reference axis, clockwise rotation produces values from 0 to 180 degrees, and counterclockwise rotation produces values from –180 to 0 degrees. |

## SwipeGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                        | Read-Only| Optional            | Description        |
| ------------  | ----------------------------|------|------  | -----------|
| angle         | number | No| No| Angle of the swipe gesture, that is, the change in the included angle between the line segment created by the two fingers and the horizontal direction. The unit is deg.<br>**NOTE**<br>Angle calculation: Once a rotation gesture is detected, the line connecting two fingers is considered the start line. As the fingers move, the line between them rotates. Based on the coordinates of the start line and the current line, the included angle relative to the horizontal axis is computed using the arctangent function.<br>The final angle is calculated as follows: arctan2(cy2 - cy1, cx2 - cx1) - arctan2(y2 - y1, x2 - x1).<br>If the start line is taken as the reference axis, clockwise rotation produces values from 0 to 180 degrees, and counterclockwise rotation produces values from –180 to 0 degrees.|
| speed         | number | No| No| Swipe gesture speed, defined as the average swipe speed of all fingers relative to the original area of the current component. The unit is vp/s. |
