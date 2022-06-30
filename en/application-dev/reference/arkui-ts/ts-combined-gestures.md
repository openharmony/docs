# Combined Gestures


> **NOTE**<br>
> Combined gestures are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

GestureGroup(mode: GestureMode, ...gesture: GestureType[])

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | mode | GestureMode | Yes | - | Recognition mode of combined gestures. |
  | gesture | [TapGesture](ts-basic-gestures-tapgesture.md)<br/>\| [LongPressGesture](ts-basic-gestures-longpressgesture.md)<br/>\| [PanGesture](ts-basic-gestures-pangesture.md)<br/>\| [PinchGesture](ts-basic-gestures-pinchgesture.md)<br/>\| [RotationGesture](ts-basic-gestures-rotationgesture.md) | Yes | - | Variable-length parameter, indicating one or more basic gesture types. These gestures are recognized in combination. |

- GestureMode enums
  | Name | Description | 
  | -------- | -------- |
  | Sequence | Sequential recognition: Gestures are recognized in the registration sequence until all gestures are recognized successfully. When one gesture fails to be recognized, all gestures fail to be recognized. | 
  | Parallel | Parallel recognition. Registered gestures are recognized concurrently until all gestures are recognized. The recognition result of each gesture does not affect each other. | 
  | Exclusive | Exclusive recognition. Registered gestures are identified concurrently. If one gesture is successfully recognized, gesture recognition ends. | 


## Events

| Name | Description | 
| -------- | -------- |
| onCancel(event: () =&gt; void) | Callback for the GestureMode.Sequence cancellation event. | 


## Example


```
@Entry
@Component
struct GestureGroupExample {
  @State count: number = 0
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State borderStyle: BorderStyle = BorderStyle.Solid

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('sequence gesture\n' + 'LongPress onAction:' + this.count + '\nPanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
    }.translate({ x: this.offsetX, y: this.offsetY, z: 5 })
    .height(100).width(200).padding(10).margin(80).border({ width: 1, style: this.borderStyle })
    .gesture(
      GestureGroup(GestureMode.Sequence,
        LongPressGesture({ repeat: true })
          .onAction((event: GestureEvent) => {
            if (event.repeat) {this.count++}
            console.log('LongPress onAction')
          })
          .onActionEnd(() => {
            console.log('LongPress end')
          }),
        PanGesture({})
          .onActionStart(() => {
            this.borderStyle = BorderStyle.Dashed
            console.log('pan start')
          })
          .onActionUpdate((event: GestureEvent) => {
            this.offsetX = event.offsetX
            this.offsetY = event.offsetY
            console.log('pan update')
          })
      )
      .onCancel(() => {
        console.log('sequence gesture canceled')
      })
    )
  }
}
```

![en-us_image_0000001212058490](figures/en-us_image_0000001212058490.gif)
