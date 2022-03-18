# PinchGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

PinchGesture(options?: { fingers?: number, distance?: number })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 2 | Minimum&nbsp;number&nbsp;of&nbsp;fingers&nbsp;to&nbsp;trigger&nbsp;a&nbsp;pinch.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;2&nbsp;to&nbsp;5. | 
  | distance | number | No | 3.0 | Minimum&nbsp;recognition&nbsp;distance,&nbsp;in&nbsp;vp. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onActionStart((event?:&nbsp;PinchGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;pinch&nbsp;gesture&nbsp;is&nbsp;recognized. | 
| onActionUpdate((event?:&nbsp;PinchGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;during&nbsp;the&nbsp;movement&nbsp;of&nbsp;a&nbsp;pinch&nbsp;gesture. | 
| onActionEnd((event?:&nbsp;PinchGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;finger&nbsp;used&nbsp;for&nbsp;a&nbsp;pinch&nbsp;gesture&nbsp;is&nbsp;lift. | 
| onActionCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;tap&nbsp;cancellation&nbsp;event&nbsp;is&nbsp;received&nbsp;after&nbsp;a&nbsp;pinch&nbsp;gesture&nbsp;is&nbsp;recognized. | 

- PinchGestureEvent<sup>8+</sup> attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | scale | number | Scale&nbsp;ratio.&nbsp;This&nbsp;attribute&nbsp;is&nbsp;used&nbsp;for&nbsp;the&nbsp;pinch&nbsp;gesture. | 
  | pinchCenterX | number | X-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;of&nbsp;the&nbsp;pinch&nbsp;gesture,&nbsp;in&nbsp;px. | 
  | pinchCenterY | number | Y-coordinate&nbsp;of&nbsp;the&nbsp;center&nbsp;of&nbsp;the&nbsp;pinch&nbsp;gesture,&nbsp;in&nbsp;px. | 


## Example


```
@Entry
@Component
struct PinchGestureExample {
  @State scale: number = 1

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PinchGesture scale:' + this.scale)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .scale({ x: this.scale, y: this.scale, z: this.scale })
    .gesture(
      PinchGesture()
        .onActionStart((event: PinchGestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: PinchGestureEvent) => {
          this.scale = event.scale
        })
        .onActionEnd(() => {
          console.info('Pinch end')
        })
    )
  }
}
```

![en-us_image_0000001257058419](figures/en-us_image_0000001257058419.gif)
