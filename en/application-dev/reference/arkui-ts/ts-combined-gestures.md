# Combined Gestures

Continuous recognition, parallel recognition, and exclusive recognition are supported for a group of gestures.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## APIs

GestureGroup(mode: GestureMode, ...gesture: GestureType[])

**Parameters**

| Name    | Type                                    | Mandatory  | Description                          |
| ------- | ---------------------------------------- | ---- | ------------------------------ |
| mode    | [GestureMode](#gesturemode)          | Yes   | Recognition mode of combined gestures.                   |
| gesture | [TapGesture](ts-basic-gestures-tapgesture.md)<br>\| [LongPressGesture](ts-basic-gestures-longpressgesture.md)<br>\| [PanGesture](ts-basic-gestures-pangesture.md)<br>\| [PinchGesture](ts-basic-gestures-pinchgesture.md)<br>\| [RotationGesture](ts-basic-gestures-rotationgesture.md) | Yes   | Variable-length parameter, indicating one or more basic gesture types. These gestures are recognized in combination.|

## GestureMode

| Name       | Description                                      |
| --------- | ---------------------------------------- |
| Sequence  | Sequential recognition: Gestures are recognized in the registration sequence until all gestures are recognized successfully. When one gesture fails to be recognized, all gestures fail to be recognized.|
| Parallel  | Parallel recognition. Registered gestures are recognized concurrently until all gestures are recognized. The recognition result of each gesture does not affect each other.    |
| Exclusive | Exclusive recognition. Registered gestures are identified concurrently. If one gesture is successfully recognized, gesture recognition ends.      |


## Events

| Name                                      | Description                                |
| ---------------------------------------- | ------------------------------------ |
| onCancel(event: () =&gt; void) | Callback for the GestureMode.Sequence cancellation event.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct GestureGroupExample {
  @State count: number = 0
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State positionX: number = 0
  @State positionY: number = 0
  @State borderStyles: BorderStyle = BorderStyle.Solid

  build() {
    Column() {
      Text('sequence gesture\n' + 'LongPress onAction:' + this.count + '\nPanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
        .fontSize(15)
    }
    .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
    .height(150)
    .width(200)
    .padding(20)
    .margin(20)
    .border({ width: 3, style: this.borderStyles })
    .gesture(
      // The following combined gestures are recognized in sequential recognition mode. If the long press gesture event is not triggered correctly, the drag gesture event will not be triggered.
    GestureGroup(GestureMode.Sequence,
    LongPressGesture({ repeat: true })
      .onAction((event: GestureEvent) => {
        if (event.repeat) {
          this.count++
        }
        console.info('LongPress onAction')
      })
      .onActionEnd(() => {
        console.info('LongPress end')
      }),
    PanGesture()
      .onActionStart(() => {
        this.borderStyles = BorderStyle.Dashed
        console.info('pan start')
      })
      .onActionUpdate((event: GestureEvent) => {
        this.offsetX = this.positionX + event.offsetX
        this.offsetY = this.positionY + event.offsetY
        console.info('pan update')
      })
      .onActionEnd(() => {
        this.positionX = this.offsetX
        this.positionY = this.offsetY
        this.borderStyles = BorderStyle.Solid
        console.info('pan end')
      })
    )
      .onCancel(() => {
        console.info('sequence gesture canceled')
      })
    )
  }
}
```

Diagram:

In sequence recognition mode the long press gesture event is triggered first.

![en-us_image_0000001174104384](figures/en-us_image_0000001174104384.png)

After the long press gesture is recognized, the drag gesture event is triggered.

 ![en-us_image1_0000001174104384](figures/en-us_image1_0000001174104384.png) 
