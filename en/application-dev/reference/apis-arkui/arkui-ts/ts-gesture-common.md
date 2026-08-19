# Gesture Common APIs

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=c937ddf8d353530fb7e476d94a0da051f4d8cafb translatedAt=2026-08-18T03:15:40.191Z pushedAt=2026-08-19T01:34:30.050Z -->

Provides common gesture APIs for developers, including gesture common configuration, gesture recognizers, gesture event information, gesture types, and other capabilities, for recognizing, controlling, and handling tap, long press, pan, pinch, and other gesture interaction scenarios in apps.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## GestureInterface\<T><sup>11+</sup>

The **Gesture** API is used to configure common attributes of gestures, supporting setting gesture flags and input types for gesture responses.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### tag<sup>11+</sup>

tag(tag: string): T

Sets a gesture tag.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

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

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                       |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| types  |  Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | Yes   | Array of input types for gesture responses. |

**Return value**

| Type    | Description       |
| ------ | --------- |
| T | Current component.|

## ScrollableTargetInfo<sup>12+</sup>

Provides the information about the scrollable container component corresponding to the gesture recognizer. It inherits from [EventTargetInfo](#eventtargetinfo12).

### isBegin<sup>12+</sup>

isBegin(): boolean

Checks whether this scrollable container component is scrolled to the top. If it is a **Swiper** component in loop mode, **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current scrollable container component is scrolled to the top. The value **true** means that the component is scrolled to the top, and **false** means the opposite.|

### isEnd<sup>12+</sup>

isEnd(): boolean

Checks whether the current scroll container is scrolled to the bottom. If the container is a **Swiper** component and is in loop mode, **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

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

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | [Component ID](./ts-universal-attributes-component-id.md) of the current component. |

### getUniqueId

getUniqueId(): number

Returns the unique ID of the current component. Different from the component ID returned by getId(), this API returns the unique ID of the component. When an API parameter requires the unique ID of a component (such as the uniqueId of isHostBelongsTo), use this API to obtain it.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Return value**

| Type     | Description        |
| ------ | --------- |
| number | Unique ID of the current component. |

## TouchRecognizer<sup>20+</sup>

Defines the touch gesture recognizer object, which supports obtaining touch target information, canceling the current touch interaction, and determining whether the bound node belongs to a specified component subtree. It is applicable to touch processing and event distribution control scenarios.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getEventTargetInfo<sup>20+</sup>

getEventTargetInfo(): EventTargetInfo

Obtains the information about the component corresponding to this touch gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [EventTargetInfo](#eventtargetinfo12) | Information about the component corresponding to the current touch gesture recognizer.|

### cancelTouch<sup>20+</sup>

cancelTouch(): void

Sends a touch cancellation event to the current touch gesture recognizer. It is applicable to scenarios such as page state changes, dialog box interruptions, or business logic that needs to actively terminate the current touch interaction.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### isHostBelongsTo

isHostBelongsTo(uniqueId: number): boolean

Returns whether the node bound to the current touch gesture recognizer is a descendant node of the passed-in component. It is applicable to scenarios where it is determined whether an event comes from the target component subtree during touch processing or gesture distribution.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name   | Type                      | Mandatory | Description                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| uniqueId | number | Yes   | Unique ID of the component. This ID can be obtained through the [getUniqueId](#getuniqueid) API.<br>If the value does not match any component unique ID, **false** is returned. |

**Return value**

| Type     | Description        |
| ------ | --------- |
| boolean | Whether the node bound to the current touch gesture recognizer is a descendant node of the passed-in component. The value **true** indicates that the current bound node is a descendant node of the passed-in component, and **false** indicates that it is not. |

## GestureRecognizer<sup>12+</sup>

Gesture recognizer object, which supports querying gesture flags, type, state, and target component information, controlling the enabled state of the recognizer, blocking the current recognition process, and determining whether the bound node belongs to a specified component subtree. It is applicable to gesture recognition state management and gesture competition handling scenarios.

### getTag<sup>12+</sup>

getTag(): string

Obtains the tag of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Tag of the current gesture recognizer.|

### getType<sup>12+</sup>

getType(): GestureControl.GestureType

Obtains the type of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureControl.GestureType](#gesturetype11) | Type of the current gesture recognizer.|

### isBuiltIn<sup>12+</sup>

isBuiltIn(): boolean

Obtains whether this gesture recognizer is a built-in gesture.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current gesture recognizer is a built-in gesture. The value **true** means that the gesture recognizer is a built-in gesture, and **false** means the opposite.|

### setEnabled<sup>12+</sup>

setEnabled(isEnabled: boolean): void

Sets the enabled state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                          | Mandatory  | Description |
| ------- | ---------------------------------- | ---- | ----- |
| isEnabled   | boolean         | Yes    | Enable status of the gesture recognizer. The value **true** indicates that the current gesture recognizer can call back app events, and **false** indicates that it does not call back app events.<br>Currently, this takes effect only when set for [PanRecognizer](#panrecognizer12). |

### isEnabled<sup>12+</sup>

isEnabled(): boolean

Obtains the enabled state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Enabled state of the gesture recognizer. The value **true** means that the gesture recognizer is enabled and will trigger events, and **false** means the opposite.|

### getState<sup>12+</sup>

getState(): GestureRecognizerState

Obtains the state of this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [GestureRecognizerState](#gesturerecognizerstate12) | State of the gesture recognizer.|

### getEventTargetInfo<sup>12+</sup>

getEventTargetInfo(): EventTargetInfo

Obtains the information about the component corresponding to this gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [EventTargetInfo](#eventtargetinfo12) | Information about the component corresponding to the current gesture recognizer.|

### isValid<sup>12+</sup>

isValid(): boolean;

Whether the current gesture recognizer is valid.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the current gesture recognizer is valid.<br>The value **false** is returned when the component bound to the recognizer is destroyed or the recognizer is not in the response chain.<br>The value **true** is returned when the component bound to the recognizer is not destroyed and the recognizer is in the response chain. |

### getFingerCount<sup>18+</sup>

getFingerCount(): number

Obtains the number of fingers required to trigger the preset gesture.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Preset threshold for the number of fingers to recognize.<br>Value range: [1, 10], integer. |

### isFingerCountLimit<sup>18+</sup>

isFingerCountLimit(): boolean

Returns whether the preset gesture detects the number of fingers touching the screen.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the preset gesture detects the number of fingers touching the screen. The value **true** is returned when a gesture event is bound and the number of fingers touching the screen is detected. The value **false** is returned when a gesture event is bound and the number of fingers touching the screen is not detected. |

### preventBegin<sup>20+</sup>

preventBegin(): void

Blocks the gesture recognizer from participating in the current gesture recognition before all fingers are lifted. It is applicable to scenarios such as custom gesture competition or temporarily giving up the current gesture recognition based on business conditions. If the system has already determined the result of this gesture recognizer (whether successful or not), calling this API has no effect. This method differs from GestureRecognizer.[setEnabled](#setenabled12)(isEnabled: boolean). [setEnabled](#setenabled12) does not block the gesture recognizer object from participating in the gesture recognition process, but only affects whether the callback function corresponding to the gesture is executed.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### isHostBelongsTo

isHostBelongsTo(uniqueId: number): boolean

Returns whether the node bound to the current gesture recognizer is a descendant node of the passed-in component. It is applicable to scenarios where it is determined whether an event comes from the target component subtree during touch processing or gesture distribution.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

**Parameters**

| Name   | Type                      | Mandatory | Description                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| uniqueId | number | Yes   | Unique ID of the component. This ID can be obtained through the [getUniqueId](#getuniqueid) API.<br>If the value is abnormal, **false** is returned. |

**Return value**

| Type     | Description        |
| ------ | --------- |
| boolean | Whether the node bound to the current gesture recognizer is a descendant node of the passed-in component. The value **true** indicates that the current bound node is a descendant node of the passed-in component, and **false** indicates that it is not. |

## TapRecognizer<sup>18+</sup>

Tap gesture recognizer object, which inherits from [GestureRecognizer](#gesturerecognizer12) and supports obtaining the tap count threshold. It is applicable to querying the recognition configuration of single-tap or multi-tap gestures.

### getTapCount<sup>18+</sup>

getTapCount(): number

Obtains the number of consecutive taps required for the tap gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Threshold for the number of consecutive taps recognized by the preset tap gesture recognizer.<br>Value range: [0, +∞) |

## LongPressRecognizer<sup>18+</sup>

Long press gesture recognizer object, which inherits from [GestureRecognizer](#gesturerecognizer12) and supports querying whether long press is triggered repeatedly, the trigger duration threshold, and the maximum recognizable movement distance. It is applicable to querying the long press gesture recognition configuration.

### isRepeat<sup>18+</sup>

isRepeat(): boolean

Checks whether the long press gesture recognizer is set to trigger repeated callbacks.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| boolean | Whether the long press gesture recognizer is set to trigger repeated callbacks. **false**: Repeated callbacks are not triggered. **true**: Repeated callbacks are triggered.|

### getDuration<sup>18+</sup>

getDuration(): number

Obtains the minimum duration required for the long press gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum time threshold for triggering the preset long press gesture recognizer, in ms.<br>Value range: [0, +∞) |

### getAllowableMovement<sup>22+</sup>

getAllowableMovement(): number

Obtains the maximum movement distance recognizable by the long press gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 22.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Maximum movement distance of the gesture recognized by the long press gesture recognizer, in px.<br>Value range: (0, +∞) |

## SwipeRecognizer<sup>18+</sup>

Swipe gesture recognizer object, which inherits from [GestureRecognizer](#gesturerecognizer12) and supports querying the velocity threshold and swipe direction of the swipe gesture. It is applicable to querying the swipe gesture recognition configuration.

### getVelocityThreshold<sup>18+</sup>

getVelocityThreshold(): number

Returns the minimum velocity threshold for the preset swipe gesture recognizer to recognize a swipe. The default minimum velocity is 100 vp/s.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum speed threshold for the preset swipe gesture recognizer to recognize a swipe, in vp/s. If no speed threshold is configured, the default value 100vp/s is returned.<br>Value range: [0, +∞) |

### getDirection<sup>18+</sup>

getDirection(): SwipeDirection

Obtains the direction for recognizing swipe gestures.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [SwipeDirection](./ts-basic-gestures-swipegesture.md#swipedirection) | Direction for recognizing swipe gestures.|

## PinchRecognizer<sup>18+</sup>

Pinch gesture recognizer object, which inherits from [GestureRecognizer](#gesturerecognizer12) and supports querying the minimum recognition distance threshold of the pinch gesture. It is applicable to querying the recognition configuration of scaling gestures.

### getDistance<sup>18+</sup>

getDistance(): number

Obtains the minimum distance required for the pinch gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum recognition distance threshold of the preset pinch gesture recognizer, in vp.<br>Value range: [0, +∞) |

## RotationRecognizer<sup>18+</sup>

Rotation gesture recognizer object, which inherits from [GestureRecognizer](#gesturerecognizer12) and supports querying the minimum angle threshold for triggering the rotation gesture. It is applicable to querying the gesture recognition configuration of rotation interactions.

### getAngle<sup>18+</sup>

getAngle(): number

Obtains the minimum angle change required for the rotation gesture to be recognized.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum degree change threshold for the preset rotation gesture recognizer to trigger the rotation gesture, in deg.<br>Value range: [0, +∞)<br>**NOTE**<br>If the input degree change value is less than or equal to 0 or greater than 360, it is converted to the default value, which is 1. |

## PanRecognizer<sup>12+</sup>

Pan gesture recognizer object, which inherits from [GestureRecognizer](#gesturerecognizer12) and supports querying pan gesture attributes, recognition direction, minimum pan distance, and pan thresholds for different input sources. It is applicable to querying the pan gesture recognition configuration.

### getPanGestureOptions<sup>12+</sup>

getPanGestureOptions(): PanGestureOptions

Obtains the properties of this pan gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [PanGestureOptions](./ts-basic-gestures-pangesture.md#pangestureoptions) | Properties of the current pan gesture recognizer.|

### getDirection<sup>19+</sup>

getDirection(): PanDirection

Obtains the recognized direction of the current pan gesture recognizer.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [PanDirection](./ts-basic-gestures-pangesture.md#pandirection)| Recognized direction of the current pan gesture recognizer.|

### getDistance<sup>19+</sup>

getDistance(): number

Returns the minimum pan distance that triggers the current pan gesture recognizer. The default pan threshold is 5 vp.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum swipe distance that triggers the current pan gesture recognizer. If the minimum swipe distance is not configured, the default swipe threshold 5vp is returned. Unit: vp |

### getDistanceMap<sup>19+</sup>

getDistanceMap(): Map\<SourceTool, number\>

Returns the minimum pan distance that triggers the pan gesture recognizer for different input sources. The default pan threshold is 5 vp.

>  **NOTE**
>
>  This API only returns thresholds for input sources that have been explicitly configured during pan gesture initialization. The default threshold can be queried using the [SourceTool](ts-gesture-settings.md#sourcetool9).Unknown type. Thresholds for unconfigured device types are not available.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| Map<[SourceTool](ts-gesture-settings.md#sourcetool9), number> | Minimum pan distances required for different input sources to trigger the pan gesture recognizer. Unit: vp.|

## GestureRecognizerState<sup>12+</sup>

Enumerates the gesture recognizer states.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

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

Defines the event information of a gesture. Inherits from [BaseEvent](ts-universal-events-click.md#baseevent8).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type  |   Read-Only  | Optional    |  Description |
| -------- | -------- | ---- | ---- |-------- |
| repeat | boolean | No |  No  |Whether the event is a repeated trigger event, used in the **LongPressGesture** gesture trigger scenario. The value **true** indicates a repeated trigger event, and **false** indicates a non-repeated trigger event.<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| offsetX | number | No | No  |Offset X of the gesture event relative to the position when the finger is pressed, in vp. Used in the **PanGesture** gesture trigger scenario. When swiping from left to right, **offsetX** is positive; otherwise, it is negative.<br>**Atomic service API:** This API can be used in atomic services since API version 11.<br>Value range: (-∞, +∞) |
| offsetY | number | No | No  |Offset Y of the gesture event relative to the position when the finger is pressed, in vp. Used in the **PanGesture** gesture trigger scenario. When swiping from top to bottom, offsetY is positive; otherwise, it is negative.<br>**Atomic service API:** This API can be used in atomic services since API version 11.<br>Value range: (-∞, +∞)  |
| angle | number | No | No  |When used in the **RotationGesture** gesture trigger scenario, indicates the rotation angle, in deg.<br>When used in the **SwipeGesture** gesture trigger scenario, indicates the angle of the swipe gesture, that is, the angle between the instantaneous direction of finger movement and the positive horizontal direction, in deg.<br>**NOTE**<br>The rotation angle is calculated as follows: After the **RotationGesture** gesture is recognized, the line connecting two fingers is identified as the initial line. As the fingers move, the line between the fingers rotates. Based on the coordinates of the two endpoints of the initial line and the two endpoints of the current line, the arctangent function is used to calculate their angles relative to the horizontal direction respectively. Finally, **arctan2(cy2-cy1,cx2-cx1)-arctan2(y2-y1,x2-x1)** is the rotation angle. With the initial line as the coordinate system, clockwise rotation is 0 to 180 degrees, and counterclockwise rotation is 0 to -180 degrees.<br>Value range: [-180, 180]<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| scale | number |No | No  |Scale ratio, used in the **PinchGesture** gesture trigger scenario.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| pinchCenterX | number | No | No  |X-axis coordinate of the pinch gesture center point relative to the upper left corner of the original area of the current component element, in vp. Used in the **PinchGesture** gesture trigger scenario.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| pinchCenterY | number | No | No  |Y-axis coordinate of the pinch gesture center point relative to the upper left corner of the original area of the current component element, in vp. Used in the **PinchGesture** gesture trigger scenario.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| speed<sup>8+</sup> | number | No | No  |Swipe gesture velocity, that is, the average velocity of all fingers swiping relative to the original area of the current component element, in vp/s. Used in the **SwipeGesture** gesture trigger scenario.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| fingerList<sup>8+</sup> | [FingerInfo](#fingerinfo8)[] | No | No | For gestures generated by touchscreen input, **fingerList** contains all touch point information that triggers the event. For gestures initiated by a mouse, **fingerList** contains only one record. The event category of a touchpad is the same as that of a mouse, so for gestures initiated by a touchpad, **fingerList** carries only one record.<br/>**NOTE**<br/>1. The finger index corresponds to the position, that is, the id of **fingerList[index]** is **index**. The position corresponding to a finger that is pressed first but does not participate in the current gesture trigger is empty in **fingerList**.<br/>2. When a gesture is triggered by a keyboard or gamepad, there is no finger information, and **fingerList** is empty.<br/>**Atomic service API:** This API can be used in atomic services since API version 11. |
| fingerInfos<sup>20+</sup> | [FingerInfo](#fingerinfo8)[] | No | Yes | For gestures generated by touchscreen input, **fingerInfos** contains all touch point information that triggers the event. For gestures initiated by a mouse, **fingerInfos** contains only one record. The event category of a touchpad is the same as that of a mouse, so for gestures initiated by a touchpad, **fingerInfos** carries only one record.<br/> **NOTE**<br/>**fingerInfos** records only the valid finger information that participates in the touch. A finger that is pressed first but does not participate in the current gesture trigger is not displayed in **fingerInfos**. The default value is an empty array []. When an empty array is returned, it indicates that there is no valid touch point information.<br/>**Atomic service API:** This API can be used in atomic services since API version 20.<br/>**Model restriction:** This API can be used only in the stage model. |
| velocityX<sup>10+</sup> | number | No | No | Used in the [PanGesture](ts-basic-gestures-pangesture.md) gesture to obtain the velocity of the current gesture in the x-axis direction. The origin of the coordinate axis is the upper left corner of the screen. The velocity has positive and negative directions: from left to right is positive, and the opposite is negative. The unit is vp/s.<br>Value range: (-∞, +∞) <br>**Atomic service API:** This API can be used in atomic services since API version 11.<br>**Model restriction:** This API can be used only in the stage model. |
| velocityY<sup>10+</sup> | number | No | No | Used in the [PanGesture](ts-basic-gestures-pangesture.md) gesture to obtain the velocity of the current gesture in the y-axis direction. The origin of the coordinate axis is the upper left corner of the screen. The velocity has positive and negative directions: from top to bottom is positive, and the opposite is negative. The unit is vp/s.<br>Value range: (-∞, +∞) <br>**Atomic service API:** This API can be used in atomic services since API version 11.<br>**Model restriction:** This API can be used only in the stage model. |
| velocity<sup>10+</sup> | number | No | No | Used in the [PanGesture](ts-basic-gestures-pangesture.md) gesture to obtain the velocity of the current gesture in the main direction. It is the arithmetic square root of the sum of squares of the velocities in the x-axis and y-axis directions. The unit is vp/s.<br>Value range: [0, +∞) <br>**Atomic service API:** This API can be used in atomic services since API version 11.<br>**Model restriction:** This API can be used only in the stage model. |
| tapLocation<sup>20+</sup> | [EventLocationInfo](ts-basic-gestures-tapgesture.md#eventlocationinfo20) | No | Yes  |Used in the tap gesture to obtain the coordinate information of the current gesture. In non-tap gestures, the return value of **tapLocation** is **undefined**.<br> **Atomic service API:** This API can be used in atomic services since API version 20.<br>**Model restriction:** This API can be used only in the stage model.|

## GestureMask

Enumerates masking modes of child component gestures.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name|Value| Description|
| -------- | ---- |-------- |
| Normal | - |The gestures of child components are enabled and recognized based on the default gesture recognition sequence.|
| IgnoreInternal | - | The gestures of child components are disabled, including the built-in gestures, such as the built-in swipe gesture for a **List** component. If the areas of the parent and child components are partly overlapped, only gestures in the overlapped areas are disabled.|

## GestureJudgeResult<sup>11+</sup>

Enumerates gesture competition results.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value| Description                              |
| ----- | -------- | ----------------------- |
| CONTINUE  | 0 | The system gesture recognition process continues.|
| REJECT  | 1 | Gesture recognition fails.|

## GestureType<sup>11+</sup>

Enumerates gesture recognizer types.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Value| Description                                  |
| ----- | -------- | ------------------------------- |
| TAP_GESTURE   | 0 | Tap gesture.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| LONG_PRESS_GESTURE  | 1 | Long press gesture.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| PAN_GESTURE    | 2 | Pan gesture.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| PINCH_GESTURE   | 3 | Pinch gesture.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| SWIPE_GESTURE    | 4 | Swipe gesture.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| ROTATION_GESTURE   | 5 | Rotation gesture.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| DRAG    | 6 | Drag.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| CLICK   | 7 | Click.<br>**Atomic service API:** This API can be used in atomic services since API version 12.|
| BOX_SELECT_GESTURE<sup>23+</sup>   | 8 | Mouse box selection gesture in a scrollable container. It is a special pan gesture used to create a selection area by dragging the mouse in a scrollable container to select multiple elements in batches.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 23.|
| WEB_SCROLL_GESTURE<sup>23+</sup>   | 9 | Web component scroll gesture. It is a special pan gesture used to control the scrolling behavior within the Web component.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 23.|
| TEXT_FIELD_SELECT_GESTURE<sup>23+</sup>   | 10 | Text selection gesture. It is a special pan gesture used to select text content by dragging in an input box component.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 23.|
| CONTEXT_MENU_HOVER_GESTURE<sup>23+</sup>   | 11 | Context menu hover gesture. It is a special long press gesture used to trigger the hoverScale animation effect of the menu during a long press (the **hoverScaleInterruption** attribute of [ContextMenuAnimationOptions](./ts-universal-attributes-menu.md#contextmenuanimationoptions11) must be enabled to support this behavior).<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 23.|

## GestureInfo<sup>11+</sup>

Defines the gesture information type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type                 | Read-Only| Optional| Description        |
| ---------------  | ---------------------|----|------| -----------|
| tag              | string                | No | Yes | Gesture tag.<br>**NOTE**<br>When the event flag tag attribute is not set, tag is not returned or returns undefined.      |
| type             | [GestureControl.GestureType](#gesturetype11) | No | No | Gesture type.<br>**NOTE**<br> When the gesture is a system built-in gesture event of an unexposed type, the value of type is -1. |
| isSystemGesture  | boolean                 | No | No | Whether the current gesture is a system built-in gesture. The value **true** indicates yes, and **false** indicates no.<br/>Default value: **false** |

## FingerInfo<sup>8+</sup>

Defines the finger information type.

### Attributes

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- |  -------- |--------- |-------- |
| id | number | No  | No     |Index of the finger, determined by the number of fingers pressed. The index is 0 when the first finger is pressed, and increments by 1 each time another finger is pressed.<br>**NOTE**<br> The index of the mouse (1001), stylus (102), mouse wheel (0), and two-finger swipe on the touchpad (0) is also converted to the finger index.<br>Value range: [0, 10), 102, 1001.<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| globalX | number | No  |  No     |X coordinate relative to the upper left corner of the app window, in vp.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| globalY | number | No  |  No     |Y coordinate relative to the upper left corner of the app window, in vp.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| localX | number | No  |  No     |X coordinate relative to the upper left corner of the original area of the current component element, in vp.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| localY | number | No  |  No     |Y coordinate relative to the upper left corner of the original area of the current component element, in vp.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 11. |
| displayX<sup>12+</sup> | number | No  | No     | X coordinate relative to the upper left corner of the screen, in vp.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 12.<br>**Model restriction:** This API can be used only in the stage model. |
| displayY<sup>12+</sup> | number | No  |  No     |Y coordinate relative to the upper left corner of the screen, in vp.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 12.<br>**Model restriction:** This API can be used only in the stage model. |
| hand<sup>15+</sup> | [InteractionHand](./ts-appendix-enums.md#interactionhand15) | No  |  Yes     |Whether the event is triggered by a left-hand or right-hand tap. If this parameter is not returned, the current event has no left-hand or right-hand tap information.<br>**Atomic service API:** This API can be used in atomic services since API version 15.<br>**Model restriction:** This API can be used only in the stage model. |
| globalDisplayX<sup>20+</sup> | number | No  |  Yes     |X coordinate relative to the upper left corner of the global screen, in vp. If this parameter is not returned, there is no global screen X coordinate information.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 20.<br>**Model restriction:** This API can be used only in the stage model. |
| globalDisplayY<sup>20+</sup> | number | No  |  Yes     |Y coordinate relative to the upper left corner of the global screen, in vp. If this parameter is not returned, there is no global screen Y coordinate information.<br>Value range: [0, +∞)<br>**Atomic service API:** This API can be used in atomic services since API version 20.<br>**Model restriction:** This API can be used only in the stage model. |

### getCurrentLocalPosition

getCurrentLocalPosition?(): Coordinate2D

Obtains the coordinates of the finger position relative to the upper left corner of the current component's real-time position.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description                                                  |
| ------- | ----------------------------------------------------- |
| [Coordinate2D](ts-types.md#coordinate2d) | Coordinates of the finger position relative to the upper left corner of the current component's real-time position. |

## GestureType

type GestureType = TapGesture | LongPressGesture | PanGesture | PinchGesture | SwipeGesture | RotationGesture | GestureGroup

Enumerates gesture recognizer types. The value type is a union of the types listed in the table below.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type| Description|
| -------- | -------- |
| [TapGesture](ts-basic-gestures-tapgesture.md) | Tap gesture, which can be a single-tap or multi-tap gesture.|
| [LongPressGesture](ts-basic-gestures-longpressgesture.md) | Long press.|
| [PanGesture](ts-basic-gestures-pangesture.md) | Pan gesture (triggered when the movement distance of a finger on the screen reaches the minimum value, which is 5 vp by default).|
| [PinchGesture](ts-basic-gestures-pinchgesture.md) | Pinch gesture.|
| [RotationGesture](ts-basic-gestures-rotationgesture.md) | Rotation gesture.|
| [SwipeGesture](ts-basic-gestures-swipegesture.md) | Swipe gesture (triggered when the swipe speed exceeds the specified threshold, which is 100 vp/s by default).|
| [GestureGroup](ts-combined-gestures.md) | A group of gestures. Continuous recognition, parallel recognition, and exclusive recognition are supported.|

## BaseGestureEvent<sup>11+</sup>

Basic gesture event type. Inherits from [BaseEvent](./ts-universal-events-click.md#baseevent8).

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                 | Read-Only  |    Optional  | Description       |
| ---------  | -------------------------------------|-------| -----------|  -----------|
| fingerList | [FingerInfo](#fingerinfo8)[] | No | No | Information about all fingers that trigger the event. For a gesture generated by the touchscreen, fingerList contains information about all touch points that trigger the event. For a gesture initiated by the mouse, fingerList contains only one record. The event category of the touchpad is the same as that of the mouse, so for a gesture initiated by the touchpad, fingerList carries only one record.<br>**NOTE**<br>1. The finger index corresponds to the position, that is, the id of fingerList[index] is index. The position in fingerList corresponding to a finger that is pressed first but does not participate in triggering the current gesture is empty.<br>2. When a gesture is triggered by the keyboard or gamepad, no finger information exists and fingerList is empty.<br>**Atomic service API:** This API can be used in atomic services since API version 12. |
| fingerInfos<sup>20+</sup> | [FingerInfo](#fingerinfo8)[] | No | Yes | Information about all valid touch points that participate in triggering the event. For a gesture generated by the touchscreen, fingerInfos contains information about all touch points that trigger the event. For a gesture initiated by the mouse, fingerInfos contains only one record. The event category of the touchpad is the same as that of the mouse, so for a gesture initiated by the touchpad, fingerInfos carries only one record.<br>**NOTE**<br>fingerInfos records only the valid finger information that participates in the touch. A finger that is pressed first but does not participate in triggering the current gesture is not displayed in fingerInfos. The default value is an empty array []. When an empty array is returned, it indicates that no valid touch point information is available.<br>**Atomic service API:** This API can be used in atomic services since API version 20. |

## TapGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type  | Read-Only| Optional                               | Description        |
| ---------  | --- | ------|-------------------------------  | -----------|
| tapLocation<sup>20+</sup>  | [EventLocationInfo](ts-basic-gestures-tapgesture.md#eventlocationinfo20)| No | Yes | Obtains the coordinate information of the tap gesture. If no value is returned, there is no coordinate information of the tap gesture. <br/>**Atomic service API:** This API can be used in atomic services since API version 20.|

## LongPressGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                              | Read-Only| Optional      | Description        |
| ---------  | ----------------------------------|-----| ----------|----------|
| repeat     | boolean                           | No | No   | Whether the event is a repeated trigger event. **true**: The event is repeated. **false**: The event is not repeated. |

## PanGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type      | Read-Only   | Optional    | Description        |
| ---------  | ---------|-----  | ----------|--------------|
| offsetX    | number | No | No | Offset of the gesture event on the x-axis relative to the original area of the current component, in vp. A positive value indicates a left-to-right swipe, and a negative value indicates the opposite.<br>Value range: (-∞, +∞)  |
| offsetY    | number | No | No | Offset of the gesture event on the y-axis relative to the original area of the current component, in vp. A positive value indicates a top-to-bottom swipe, and a negative value indicates the opposite.<br>Value range: (-∞, +∞)  |
| velocityX  | number | No | No | Velocity of the current gesture on the x-axis. The origin of the coordinate system is at the upper left corner of the screen. The velocity can be positive or negative: a positive value indicates a left-to-right movement, and a negative value indicates the opposite. The unit is vp/s.<br>Value range: (-∞, +∞)  |
| velocityY  | number | No | No | Velocity of the current gesture on the y-axis. The origin of the coordinate system is at the upper left corner of the screen. The velocity can be positive or negative: a positive value indicates a top-to-bottom movement, and a negative value indicates the opposite. The unit is vp/s.<br>Value range: (-∞, +∞) |
| velocity   | number | No | No | Velocity of the current gesture in the main direction, which is the arithmetic square root of the sum of the squares of the velocities on the x-axis and y-axis. The unit is vp/s.<br>Value range: [0, +∞)  |

## PinchGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type    | Read-Only| Optional| Description        |
| ------------  | --------|-----------|---------------------  | -----------|
| scale         | number | No | No | Scale factor.<br>Value range: [0, +∞)  |
| pinchCenterX  | number | No | No | X-coordinate of the pinch gesture center relative to the upper left corner of the original area of the current component, in vp.<br>Value range: [0, +∞)  |
| pinchCenterY  | number | No | No | Y-coordinate of the pinch gesture center relative to the upper left corner of the original area of the current component, in vp.<br>Value range: [0, +∞)  |

## RotationGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                             |Read-Only| Optional       | Description        |
| ------------  | ---------------------------------|----|--------------| -----------|
| angle | number | No | No | Rotation angle, in degrees.<br>**NOTE**<br>Angle calculation: When a rotation gesture is recognized, the line connecting the two fingers is identified as the initial line. As the fingers move, the line between the fingers rotates. Based on the coordinates of the two endpoints of the initial line and the current line, the arctangent function is used to calculate their respective angles relative to the horizontal direction.<br>The final rotation angle is: arctan2(cy2-cy1, cx2-cx1) - arctan2(y2-y1, x2-x1).<br>With the initial line as the coordinate system, clockwise rotation ranges from 0 to 180 degrees, and counterclockwise rotation ranges from 0 to -180 degrees. |

## SwipeGestureEvent<sup>11+</sup>

Inherits from [BaseGestureEvent](#basegestureevent11). This object can be passed as the **event** parameter of [onGestureJudgeBegin](./ts-gesture-customize-judge.md#ongesturejudgebegin).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                        | Read-Only| Optional            | Description        |
| ------------  | ----------------------------|------|------  | -----------|
| angle         | number | No | No | Angle of the swipe gesture, that is, the angle between the instantaneous direction of finger movement and the positive horizontal direction, in deg.<br>**NOTE**<br>With the positive horizontal direction as the reference, when the swipe direction is on the clockwise side of the positive horizontal direction, the angle ranges from 0 to 180 degrees; when it is on the counterclockwise side, the angle ranges from 0 to -180 degrees.|
| speed         | number | No | No | Speed of the swipe gesture, that is, the average speed at which all fingers move relative to the original area of the current component, in vp/s.<br>Value range: [0, +∞)  |