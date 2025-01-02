# Gesture Binding

Bind different types of gesture events to components and set response methods for them.

>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Binding Gesture Recognition

Use the following attributes to bind gesture recognition to a component. When a gesture is recognized, the event callback is invoked to notify the component.
A region in which a gesture can be recognized may be specified by the [touch target](ts-universal-attributes-touch-target.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| gesture | gesture: [GestureType](#gesturetype),<br>mask?: [GestureMask](#gesturemask) | gesture: -,<br>mask: GestureMask.Normal | Gesture to bind.<br>- **gesture**: type of the gesture to bind. <br>- **mask**: mask for gesture events.|
| priorityGesture | gesture: [GestureType](#gesturetype),<br>mask?: [GestureMask](#gesturemask) | gesture: -,<br>mask: GestureMask.Normal | Gesture to preferentially recognize.<br>- **gesture**: type of the gesture to bind.<br>- **mask**: mask for gesture events.<br>1. By default, the child component preferentially recognizes the gesture specified by **gesture**, and the parent component preferentially recognizes the gesture specified by **priorityGesture** (if set).<br>2. With regard to long press gestures, the component with the shortest minimum hold-down time responds first, ignoring the **priorityGesture** settings.|
| parallelGesture | gesture: [GestureType](#gesturetype),<br>mask?: [GestureMask](#gesturemask) | gesture: -,<br>mask: GestureMask.Normal | Gesture that can be recognized at once by the component and its child component.<br>- **gesture**: type of the gesture to bind. <br>- **mask**: mask for gesture events.<br>The gesture event is not a bubbling event. When **parallelGesture** is set for a component, both it and its child component can respond to the same gesture events, thereby implementing a quasi-bubbling effect.|


## GestureType

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Description|
| -------- | -------- |
| [TapGesture](ts-basic-gestures-tapgesture.md) | Tap gesture, which can be a single-tap or multi-tap gesture.|
| [LongPressGesture](ts-basic-gestures-longpressgesture.md) | Long press gesture.|
| [PanGesture](ts-basic-gestures-pangesture.md) | Pan gesture, which requires a minimum 5 vp movement distance of a finger on the screen.|
| [PinchGesture](ts-basic-gestures-pinchgesture.md) | Pinch gesture.|
| [RotationGesture](ts-basic-gestures-rotationgesture.md) | Rotation gesture.|
| [SwipeGesture](ts-basic-gestures-swipegesture.md) | Swipe gesture, which can be recognized when the swipe speed is 100 vp/s or higher.|
| [GestureGroup](ts-combined-gestures.md) | A group of gestures. Continuous recognition, parallel recognition, and exclusive recognition are supported.|


## GestureMask

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Description|
| -------- | -------- |
| Normal | The gestures of child components are enabled and recognized based on the default gesture recognition sequence.|
| IgnoreInternal | The gestures of child components are disabled, including the built-in gestures, such as the built-in swipe gesture for a **List** component. If the areas of the parent and child components are partly overlapped, only gestures in the overlapped areas are disabled.|

## Gesture Response Event

The component binds gesture objects of different **GestureType** instances through gesture events. Each gesture object provides gesture-related information in the gesture response event. In the following example, the **TapGesture** object provides gesture-related information in the **onAction** event. For details about the event definitions of other gestures, see the corresponding gesture sections. To bind multiple gestures, use [combined gestures](ts-combined-gestures.md).

**TapGesture**

| Name| Description|
| -------- | -------- |
| onAction((event:GestureEvent) =&gt; void) | Callback invoked when a tap gesture is recognized.|

## GestureEvent

Inherits from [BaseEvent](ts-gesture-customize-judge.md#baseevent).

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Type| Description|
| -------- | -------- | -------- |
| repeat | boolean | Whether the event is triggered repeatedly. This attribute is used for the **LongPressGesture** event.|
| offsetX | number | Offset in the X coordinate of the gesture event, in vp. This attribute is used for the **PanGesture** event. A positive value means to pan from left to right, and a negative value means the opposite.|
| offsetY | number | Offset in the Y coordinate of the gesture event, in vp. This attribute is used for the **PanGesture** event. A positive value means to pan from top to bottom, and a negative value means the opposite.|
| angle | number | Rotation angle for the **RotationGesture** event;<br>angle of the swipe gesture for the **SwipeGesture** event, that is, the change in the included angle between the line segment created by the two fingers and the horizontal direction.<br>**NOTE**<br>Angle calculation method: After a swipe gesture is recognized, a line connecting the two fingers is identified as the initial line. As the fingers swipe, the line between the fingers rotates. Based on the coordinates of the initial line's and current line's end points, an arc tangent function is used to calculate the respective included angle of the points relative to the horizontal direction by using the following formula: Rotation angle = arctan2(cy2-cy1,cx2-cx1) - arctan2(y2-y1,x2-x1) The initial line is used as the coordinate system. The clockwise rotation is 0 to 180 degrees, and the counter-clockwise rotation is –180 to 0 degrees.|
| scale | number | Scale ratio. This attribute is used for the **PinchGesture** event.|
| pinchCenterX | number | X coordinate of the pinch center, in vp. This attribute is used for the **PinchGesture** event.|
| pinchCenterY | number | Y coordinate of the pinch center, in vp. This attribute is used for the **PinchGesture** event.|
| speed<sup>8+</sup> | number | Swipe gesture speed, that is, the average swipe speed of all fingers relative to the original area of the current component. The unit is vp/s. This attribute is used for the **SwipeGesture** event.|
| fingerList<sup>8+</sup> | [FingerInfo](#fingerinfo8)[] | List of contact points of the gesture event. If the event input device is touchscreen, the list includes all contact points. If the event input device is mouse or touchpad, the list contains only one contact point.<br>**NOTE**<br>The index of a finger corresponds to its position, that is, the ID of a finger in **fingerList[index]** refers to its index. If a finger is pressed first and does not participate in triggering of the current gesture, its position in **fingerList** is left empty.|
| velocityX<sup>10+</sup> | number | Velocity along the x-axis. This parameter is used in [PanGesture](ts-basic-gestures-pangesture.md). The origin of the coordinate axis is the upper left corner of the screen. The velocity is positive if the movement is from left to right, and it is negative if the movement is from right to left. The unit is vp/s.|
| velocityY<sup>10+</sup> | number | Velocity along the y-axis. This parameter is used in [PanGesture](ts-basic-gestures-pangesture.md). The origin of the coordinate axis is the upper left corner of the screen. The velocity is positive if the movement is from top to bottom, and it is negative if the movement is from bottom to top. The unit is vp/s.|
| velocity<sup>10+</sup> | number | Velocity along the main axis. This parameter is used in [PanGesture](ts-basic-gestures-pangesture.md). The value is the arithmetic square root of the sum of squares of the velocity along the x- and y-axis. The unit is vp/s.|

## SourceType

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Description|
| -------- | -------- |
| Unknown | Unknown device type.|
| Mouse | Mouse.|
| TouchScreen | Touchscreen.|

## FingerInfo<sup>8+</sup>

| Name| Type| Description|
| -------- | -------- | -------- |
| id | number | Index of a finger.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| globalX | number | X-coordinate relative to the upper left corner of the application window, in vp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| globalY | number | Y-coordinate relative to the upper left corner of the application window, in vp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| localX | number | X-coordinate relative to the upper left corner of the current component's original area, in vp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| localY | number | Y-coordinate relative to the upper left corner of the current component's original area, in vp.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| displayX<sup>12+</sup> | number | X-coordinate relative to the upper left corner of the screen, in vp.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| displayY<sup>12+</sup> | number | Y-coordinate relative to the upper left corner of the screen, in vp.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## SourceTool<sup>9+</sup>

| Name| Description|
| -------- | -------- |
| Unknown | Unknown input source.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Finger | Finger.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Pen | Stylus.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Mouse<sup>12+</sup> | Mouse device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| Touchpad<sup>12+</sup> | Touchpad. Single-finger input on the touchpad is treated as a mouse input operation.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| Joystick<sup>12+</sup> | Joystick.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct GestureSettingsExample {
  @State priorityTestValue: string = ''
  @State parallelTestValue: string = ''

  build() {
    Column() {
      Column() {
        Text('TapGesture:' + this.priorityTestValue).fontSize(28)
          .gesture(
            TapGesture()
              .onAction((event: GestureEvent) => {
                this.priorityTestValue += '\nText'
              }))
      }
      .height(200)
      .width(250)
      .padding(20)
      .margin(20)
      .border({ width: 3 })
      // When priorityGesture is set, the tap gesture on the <Column> component is prioritized over the tap gesture on the child <Text> component.
      .priorityGesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            this.priorityTestValue += '\nColumn'
          }), GestureMask.IgnoreInternal)

      Column() {
        Text('TapGesture:' + this.parallelTestValue).fontSize(28)
          .gesture(
            TapGesture()
              .onAction((event: GestureEvent) => {
                this.parallelTestValue += '\nText'
              }))
      }
      .height(200)
      .width(250)
      .padding(20)
      .margin(20)
      .border({ width: 3 })
      // When parallelGesture is set, the tap gestures on the <Column> component and on the child <Text> component are both recognized.
      .parallelGesture(
        TapGesture()
          .onAction((event: GestureEvent) => {
            this.parallelTestValue += '\nColumn'
          }), GestureMask.Normal)
    }
  }
}
```

![en-us_image_0000001257058419](figures/en-us_image_0000001257058419.gif)
