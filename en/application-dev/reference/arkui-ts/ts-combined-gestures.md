# Combined Gestures


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> Combined gestures are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

GestureGroup(mode: GestureMode, ...gesture: GestureType[])

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | mode | GestureMode | Yes | - | Recognition&nbsp;mode&nbsp;of&nbsp;combined&nbsp;gestures. |
  | gesture | [TapGesture](ts-basic-gestures-tapgesture.md)<br/>\|&nbsp;[LongPressGesture](ts-basic-gestures-longpressgesture.md)<br/>\|&nbsp;[PanGesture](ts-basic-gestures-pangesture.md)<br/>\|&nbsp;[PinchGesture](ts-basic-gestures-pinchgesture.md)<br/>\|&nbsp;[RotationGesture](ts-basic-gestures-rotationgesture.md) | Yes | - | Variable-length&nbsp;parameter,&nbsp;indicating&nbsp;one&nbsp;or&nbsp;more&nbsp;basic&nbsp;gesture&nbsp;types.&nbsp;These&nbsp;gestures&nbsp;are&nbsp;recognized&nbsp;in&nbsp;combination. |

- GestureMode enums
    | Name | Description | 
  | -------- | -------- |
  | Sequence | Sequential&nbsp;recognition:&nbsp;Gestures&nbsp;are&nbsp;recognized&nbsp;in&nbsp;the&nbsp;registration&nbsp;sequence&nbsp;until&nbsp;all&nbsp;gestures&nbsp;are&nbsp;recognized&nbsp;successfully.&nbsp;When&nbsp;one&nbsp;gesture&nbsp;fails&nbsp;to&nbsp;be&nbsp;recognized,&nbsp;all&nbsp;gestures&nbsp;fail&nbsp;to&nbsp;be&nbsp;recognized. | 
  | Parallel | Parallel&nbsp;recognition.&nbsp;Registered&nbsp;gestures&nbsp;are&nbsp;recognized&nbsp;concurrently&nbsp;until&nbsp;all&nbsp;gestures&nbsp;are&nbsp;recognized.&nbsp;The&nbsp;recognition&nbsp;result&nbsp;of&nbsp;each&nbsp;gesture&nbsp;does&nbsp;not&nbsp;affect&nbsp;each&nbsp;other. | 
  | Exclusive | Exclusive&nbsp;recognition.&nbsp;Registered&nbsp;gestures&nbsp;are&nbsp;identified&nbsp;concurrently.&nbsp;If&nbsp;one&nbsp;gesture&nbsp;is&nbsp;successfully&nbsp;recognized,&nbsp;gesture&nbsp;recognition&nbsp;ends. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Callback&nbsp;for&nbsp;the&nbsp;GestureMode.Sequence&nbsp;cancellation&nbsp;event. | 


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
