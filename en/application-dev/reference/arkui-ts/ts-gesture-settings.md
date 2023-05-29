# Gesture Binding

Bind different types of gesture events to components and set response methods for them.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Binding Gesture Recognition

Use the following attributes to bind gesture recognition to a component. When a gesture is recognized, the event callback is invoked to notify the component.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| gesture | gesture: [GestureType](#gesturetype),<br>mask?: [GestureMask](#gesturemask) | gesture: -,<br>mask: GestureMask.Normal | Gesture to bind.<br>- **gesture**: type of the gesture to bind.<br>- **mask**: mask for gesture events.|
| priorityGesture | gesture: [GestureType](#gesturetype),<br>mask?: [GestureMask](#gesturemask) | gesture: -,<br>mask: GestureMask.Normal | Gesture to preferentially recognize.<br>- **gesture**: type of the gesture to bind.<br>- **mask**: mask for gesture events.<br>1. By default, the child component preferentially recognizes the gesture specified by **gesture**, and the parent component preferentially recognizes the gesture specified by **priorityGesture** (if set).<br>2. With regard to long press gestures, the component with the shortest minimum hold-down time responds first, ignoring the **priorityGesture** settings.|
| parallelGesture | gesture: [GestureType](#gesturetype),<br>mask?: [GestureMask](#gesturemask) | gesture: -,<br>mask: GestureMask.Normal | Gesture that can be triggered together with the child component gesture.<br>- **gesture**: type of the gesture to bind. <br>- **mask**: mask for gesture events.<br>The gesture event is not a bubbling event. When **parallelGesture** is set for the parent component, gesture events that are the same for the parent and child components can be triggered, thereby implementing a bubbling effect. If both the single-tap gesture event and the double-tap gesture event are bound to the parent and child components, only the single-tap gesture event is responded.|


## GestureType
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
| Name| Description|
| -------- | -------- |
| Normal | The gestures of child components are not ignored and are recognized based on the default gesture recognition sequence.|
| IgnoreInternal | The gestures of child components are ignored, including the built-in gestures. For example, if the child component is **\<List>**, its built-in swipe gesture is also ignored.|

## Gesture Response Event

The component binds gesture objects of different **GestureType**s through gesture events. Each gesture object provides gesture-related information in the gesture response event. In the following example, the **TapGesture** object provides gesture-related information in the **onAction** event. For details about the event definitions of other gestures, see the corresponding gesture sections. To bind multiple gestures, use [combined gestures](ts-combined-gestures.md).

**TapGesture**

| Name| Description|
| -------- | -------- |
| onAction((event?:GestureEvent) =&gt; void) | Callback invoked when a tap gesture is recognized.|

## GestureEvent
| Name| Type| Description|
| -------- | -------- | -------- |
| repeat | boolean | Whether the event is triggered repeatedly. This attribute is used for the **LongPressGesture** event.|
| offsetX | number | Offset of the gesture event on the x-axis, in vp. This attribute is used for the **PanGesture** event. A positive value means to pan from left to right, and a negative value means the opposite.|
| offsetY | number | Offset of the gesture event on the y-axis, in vp. This attribute is used for the **PanGesture** event. A positive value means to pan from top to bottom, and a negative value means the opposite.|
| angle | number | Rotation angle for the **RotationGesture** event;<br>angle of the swipe gesture for the **SwipeGesture** event, that is, the change in the included angle between the line segment created by the two fingers and the horizontal direction.<br>**NOTE**<br>Angle calculation method: After a swipe gesture is recognized, a line connecting the two fingers is identified as the initial line. As the fingers swipe, the line between the fingers rotates. Based on the coordinates of the initial line's and current line's end points, an arc tangent function is used to calculate the respective included angle of the points relative to the horizontal direction by using the following formula: Rotation angle = arctan2(cy2-cy1,cx2-cx1) – arctan2(y2-y1,x2-x1) The initial line is used as the coordinate system. The clockwise rotation is 0 to 180 degrees, and the counter-clockwise rotation is –180 to 0 degrees.|
| scale | number | Scale ratio. This attribute is used for the **PinchGesture** event.|
| pinchCenterX | number | X-coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component. This attribute is used for the **PinchGesture** event.|
| pinchCenterY | number | Y-coordinate of the center of the pinch gesture, in vp, relative to the upper left corner of the current component. This attribute is used for the **PinchGesture** event.|
| speed<sup>8+</sup> | number | Swipe gesture speed, that is, the average swipe speed of all fingers. The unit is vp/s. This attribute is used for the **SwipeGesture** event.|
| fingerList<sup>8+</sup> | [FingerInfo](#fingerinfo)[] | Information about all fingers that trigger the event. This attribute is used for the **LongPressGesture** and **TapGesture** events.|
| timestamp<sup>8+</sup> | number | Timestamp of the event.|
| target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md#eventtarget8) | Display area of the element that triggers the gesture event.|
| source<sup>8+</sup> | [SourceType](#sourcetype) | Event input device.|
| pressure<sup>9+</sup> | number | Press pressure.|
| tiltX<sup>9+</sup> | number | Angle between the projection of the stylus on the device plane and the x-axis.|
| tiltY<sup>9+</sup> | number | Angle between the projection of the stylus on the device plane and the y-axis.|
| sourceTool<sup>9+</sup> | [SourceTool](#sourcetool) | Event input source.|

## SourceType
| Name| Description|
| -------- | -------- |
| Unknown | Unknown device type.|
| Mouse | Mouse.|
| TouchScreen | Touchscreen.|

## FingerInfo
| Name| Type| Description|
| -------- | -------- | -------- |
| id | number | Index of a finger.|
| globalX | number | X-coordinate relative to the upper left corner of the application window.|
| globalY | number | Y-coordinate relative to the upper left corner of the application window.|
| localX | number | X-coordinate relative to the upper left corner of the current component.|
| localY | number | Y-coordinate relative to the upper left corner of the current component.|

## SourceTool
| Name| Description|
| -------- | -------- |
| Unknown | Unknown input source.|
| Finger | Finger input.|
| Pen | Stylus input.|


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
            .onAction(() => {
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
            .onAction(() => {
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
