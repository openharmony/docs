# PanGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

PanGesture(options?: { fingers?: number, direction?: PanDirection, distance?: number } | [PanGestureOption](#pangestureoption))

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 1 | Minimum&nbsp;number&nbsp;of&nbsp;fingers&nbsp;to&nbsp;trigger&nbsp;a&nbsp;long&nbsp;press&nbsp;gesture.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;1&nbsp;to&nbsp;10. | 
  | direction | PanDirection | No | All | Slide&nbsp;direction.&nbsp;The&nbsp;enumerated&nbsp;value&nbsp;supports&nbsp;the&nbsp;AND&nbsp;(&amp;)&nbsp;and&nbsp;OR&nbsp;(\|)&nbsp;operations. | 
  | distance | number | No | 5.0 | Minimum&nbsp;slide&nbsp;recognition&nbsp;distance,&nbsp;in&nbsp;vp. | 

- PanDirection enums
    | Name | Description | 
  | -------- | -------- |
  | All | All&nbsp;directions. | 
  | Horizontal | Horizontal&nbsp;slide. | 
  | Vertical | Vertical&nbsp;slide. | 
  | Left | Slide&nbsp;to&nbsp;the&nbsp;left. | 
  | Right | Slide&nbsp;to&nbsp;the&nbsp;right. | 
  | Up | Slide&nbsp;up. | 
  | Down | Slide&nbsp;down. | 
  | None | Slide&nbsp;disabled. | 


### PanGestureOption

The attributes of the slide gesture recognizer can be dynamically modified using the **PanGestureOption** AP. This avoids modifying attributes through status variables, which will cause the UI to be refreshed.

PanGestureOption(options?: { fingers?: number, direction?: PanDirection, distance?: number })

- Parameters
  For details, see **PanGesture**.

- APIs
    | Name | Description | 
  | -------- | -------- |
  | setDirection(value:&nbsp;PanDirection) | Sets&nbsp;the&nbsp;direction. | 
  | setDistance(value:&nbsp;number) | Sets&nbsp;the&nbsp;distance. | 
  | setFingers(value:&nbsp;number) | Sets&nbsp;the&nbsp;number&nbsp;of&nbsp;fingers. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onActionStart(callback:&nbsp;(event?:&nbsp;PanGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;for&nbsp;the&nbsp;pan&nbsp;gestures&nbsp;reorganization&nbsp;event. | 
| onActionUpdate(callback:&nbsp;(event?:&nbsp;PanGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;pan&nbsp;gesture&nbsp;is&nbsp;recognized. | 
| onActionEnd(callback:&nbsp;(event?:&nbsp;PanGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;finger&nbsp;used&nbsp;for&nbsp;a&nbsp;pan&nbsp;gesture&nbsp;is&nbsp;lift. | 
| onActionCancel(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;tap&nbsp;cancellation&nbsp;event&nbsp;is&nbsp;received&nbsp;after&nbsp;a&nbsp;pan&nbsp;gesture&nbsp;is&nbsp;recognized. | 

- PanGestureEvent<sup>8+</sup> attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | offsetX | number | Offset&nbsp;of&nbsp;the&nbsp;gesture&nbsp;event,&nbsp;in&nbsp;vp. | 
  | offsetY | number | Offset&nbsp;of&nbsp;the&nbsp;gesture&nbsp;event,&nbsp;in&nbsp;vp. | 


## Example


```
@Entry
@Component
struct PanGestureExample {
  @State offsetX: number = 0
  @State offsetY: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .translate({ x: this.offsetX, y: this.offsetY, z: 5 })
    .gesture(
      PanGesture({})
        .onActionStart((event: PanGestureEvent) => {
          console.info('Pan start')
        })
        .onActionUpdate((event: PanGestureEvent) => {
          this.offsetX = event.offsetX
          this.offsetY = event.offsetY
        })
        .onActionEnd(() => {
          console.info('Pan end')
        })
    )
  }
}
```

![en-us_image_0000001256978371](figures/en-us_image_0000001256978371.gif)
