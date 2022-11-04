# Gesture Binding

Bind different types of gesture events to components and set response methods for them.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Binding Gesture Recognition


Use the following attributes to bind gesture recognition to a component. When a gesture is recognized, the event callback is invoked to notify the component.


| Parameter| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| gesture | gesture: GestureType,<br>mask?: GestureMask | gesture: -,<br>mask: GestureMask.Normal | Gesture to recognize.<br>- **gesture**: type of the gesture to bind.<br>- **mask**: event response setting.|
| priorityGesture | gesture: GestureType,<br>mask?: GestureMask | gesture: -,<br>mask: GestureMask.Normal | Gesture to preferentially recognize.<br>- **gesture**: type of the gesture to bind.<br>- **mask**: event response setting.<br>By default, the child component takes precedence over the parent component in gesture recognition. When **priorityGesture** is configured for the parent component, the parent component takes precedence over the child component in gesture recognition.|
| parallelGesture | gesture: GestureType,<br>mask?: GestureMask | gesture: -,<br>mask: GestureMask.Normal | Gesture that can be triggered together with the child component gesture.<br>- **gesture**: type of the gesture to bind. <br>- **mask**: event response setting.<br>The gesture event is not a bubbling event. When **parallelGesture** is set for the parent component, gesture events that are the same for the parent component and child components can be triggered, thereby implementing a bubbling effect.|


- GestureMask
  | Name| Description|
  | -------- | -------- |
  | Normal | The gestures of child components are not masked and are recognized based on the default gesture recognition sequence.|
  | IgnoreInternal | The gestures of child components are masked. Only the gestures of the current component are recognized.<br>However, the built-in gestures of the child components are not masked. For example, when the child component is a **\<List>** component, the built-in sliding gestures can still be triggered.|


- GestureType
  | Name| Description|
  | -------- | -------- |
  | TapGesture | Tap gesture, which can be a single-tap or multi-tap gesture.|
  | LongPressGesture | Long press gesture.|
  | PanGesture | Pan gesture, which requires a minimum 5 vp movement distance of a finger on the screen.|
  | PinchGesture | Pinch gesture.|
  | RotationGesture | Rotation gesture.|
  | SwipeGesture | Swipe gesture, which can be recognized when the swipe speed is 100 vp/s or higher.|
  | GestureGroup | A group of gestures. Continuous recognition, parallel recognition, and exclusive recognition are supported.|


## Gesture Response Event

The component uses the **gesture** method to bind the gesture object and uses the events provided in this object to respond to the gesture operation. For example, the **onAction** event of the **TapGesture** object can be used to respond to a click event. For details about the event definitions of other gestures, see the corresponding gesture sections.

- TapGesture
  | Name| Description|
  | -------- | -------- |
  | onAction((event?:GestureEvent) =&gt; void) | Callback invoked when a tap gesture is recognized.|

- GestureEvent attributes
  | Name| Type| Description|
  | -------- | -------- | -------- |
  | timestamp<sup>8+</sup> | number | Timestamp of the event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.|
  | target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md) | Display area of the element that triggers the gesture event.|
  | source<sup>8+</sup> | SourceType | Event input device.|
  | repeat | boolean | Whether the event is triggered repeatedly. This parameter is used for the **LongPressGesture** event.|
  | fingerList<sup>8+</sup> | FingerInfo[] | Information about all fingers that trigger the event, which is used for the **LongPressGesture** and **TapGesture** events.|
  | offsetX | number | Offset of the gesture event on the x-axis, in vp. This parameter is used for the **PanGesture** event.|
  | offsetY | number | Offset of the gesture event on the y-axis, in vp. This parameter is used for the **PanGesture** event.|
  | angle | number | Rotation angle for the **RotationGesture** event; angle of the swipe gesture for the **SwipeGesture** event, that is, the change in the included angle between the line segment created by the two fingers and the horizontal direction.<br>**NOTE**<br>Angle calculation method: After a swipe gesture is recognized, a line connecting the two fingers is identified as the initial line. As the fingers swipe, the line between the fingers rotates. Based on the coordinates of the initial line's and current line's end points, an arc tangent function is used to calculate the respective included angle of the points relative to the horizontal direction by using the following formula: Rotation angle = arctan2(cy2-cy1,cx2-cx1) - arctan2(y2-y1,x2-x1) The initial line is used as the coordinate system. The clockwise rotation is 0 to 180 degrees, and the counter-clockwise rotation is –180 to 0 degrees. |
  | speed<sup>8+</sup> | number | Swipe gesture speed, that is, the average swipe speed of all fingers. The unit is vp/s. This attribute is used for the **SwipeGesture** event.|
  | scale | number | Scale ratio. This attribute is used for the **PinchGesture** event.|
  | pinchCenterX | number | X-coordinate of the center of the pinch gesture, in px. This attribute is used for the **PinchGesture** event.|
  | pinchCenterY | number | Y-coordinate of the center of the pinch gesture, in px. This attribute is used for the **PinchGesture** event.|
  
- SourceType
  | Name| Description|
  | -------- | -------- |
  | Unknown | Unknown device type.|
  | Mouse | Mouse.|
  | TouchScreen | Touchscreen.|

- FingerInfo
  | Name| Type| Description|
  | -------- | -------- | -------- |
  | id | number | Index of a finger.|
  | globalX | number | X-coordinate relative to the upper left corner of the application window.|
  | globalY | number | Y-coordinate relative to the upper left corner of the application window.|
  | localX | number | X-coordinate relative to the upper left corner of the current component.|
  | localY | number | Y-coordinate relative to the upper left corner of the current component.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct GestureSettingsExample {
  @State value: string = ''

  build() {
    Column(){
      Column() {
        Text('Click\n' + this.value)
          .gesture(
          TapGesture()
            .onAction(() => {
              this.value = 'gesture onAction'
            }))
      }.height(200).width(300).padding(60).border({ width: 1 })
      // When priorityGesture is specified, the bound gesture is preferentially recognized and the child component gesture is ignored.
      .priorityGesture(
      TapGesture()
        .onAction((event: GestureEvent) => {
          this.value = 'priorityGesture onAction' + '\ncomponent globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
          + event.target.area.width + '\nheight:' + event.target.area.height
        }), GestureMask.IgnoreInternal
      )
    }.padding(60)
  }
}
```

![en-us_image_0000001257058419](figures/en-us_image_0000001257058419.gif)
