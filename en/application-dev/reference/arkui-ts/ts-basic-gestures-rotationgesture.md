# RotationGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

RotationGesture(options?: { fingers?: number, angle?: number })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 2 | Minimum&nbsp;number&nbsp;of&nbsp;fingers&nbsp;to&nbsp;trigger&nbsp;a&nbsp;rotation.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;2&nbsp;to&nbsp;5. | 
  | angle | number | No | 1.0 | Minimum&nbsp;degree&nbsp;that&nbsp;can&nbsp;trigger&nbsp;the&nbsp;rotation&nbsp;gesture. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onActionStart((event?:&nbsp;RotationGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;rotation&nbsp;gesture&nbsp;is&nbsp;recognized. | 
| onActionUpdate((event?:&nbsp;RotationGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;during&nbsp;the&nbsp;movement&nbsp;of&nbsp;the&nbsp;rotation&nbsp;gesture. | 
| onActionEnd((event?:&nbsp;RotationGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;finger&nbsp;used&nbsp;for&nbsp;the&nbsp;rotation&nbsp;gesture&nbsp;is&nbsp;lift. | 
| onActionCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;tap&nbsp;cancellation&nbsp;event&nbsp;is&nbsp;received&nbsp;after&nbsp;the&nbsp;rotation&nbsp;gesture&nbsp;is&nbsp;recognized. | 

- RotationGestureEvent<sup>8+</sup> attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | angle | number | Rotation&nbsp;angle. | 


## Example


```
@Entry
@Component
struct RotationGestureExample {
  @State angle: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('RotationGesture angle:' + this.angle)
    }
    .height(100).width(200).padding(20).border({ width:1 })
    .margin(80).rotate({ x:1, y:2, z:3, angle: this.angle })
    .gesture(
      RotationGesture()
        .onActionStart((event: RotationGestureEvent) => {
          console.log('Rotation start')
        })
        .onActionUpdate((event: RotationGestureEvent) => {
          this.angle = event.angle
        })
        .onActionEnd(() => {
          console.log('Rotation end')
        })
    )
  }
}
```

![en-us_image_0000001256858403](figures/en-us_image_0000001256858403.gif)
