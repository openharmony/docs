# SwipeGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This gesture is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

SwipeGesture(value?: { fingers?: number; direction?: SwipeDirection; speed?: number })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 1 | Minimum&nbsp;number&nbsp;of&nbsp;fingers&nbsp;to&nbsp;trigger&nbsp;a&nbsp;swipe&nbsp;gesture.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;1&nbsp;to&nbsp;10. | 
  | direction | SwipeDirection | No | SwipeDirection.All | Swipe&nbsp;direction. | 
  | speed | number | No | 100 | Minimum&nbsp;speed&nbsp;of&nbsp;the&nbsp;swipe&nbsp;gesture&nbsp;(100&nbsp;vp/s). | 

- SwipeDirection enums
    | Name | Description | 
  | -------- | -------- |
  | All | All&nbsp;directions. | 
  | Horizontal | Horizontal&nbsp;direction. | 
  | Vertical | Vertical&nbsp;direction. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onAction(callback:(event?:&nbsp;SwipeGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;swipe&nbsp;gesture&nbsp;is&nbsp;recognized. | 


- SwipeGestureEvent attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | angle | number | Angle&nbsp;of&nbsp;the&nbsp;swipe&nbsp;gesture. | 
  | speed | number | Speed&nbsp;of&nbsp;the&nbsp;swipe&nbsp;gesture. | 


## Example


```
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle : number = 0
  @State speed : number = 1

  build() {
    Column() {
      Text("SwipGesture speed : " + this.speed)
      Text("SwipGesture angle : " + this.rotateAngle)
    }
    .position({x: 80, y: 200})
    .border({width:2})
    .width(260).height(260)
    .rotate({x: 0, y: 0, z: 1, angle: this.rotateAngle})
    .gesture(
      SwipeGesture({fingers: 1, direction:SwipeDirection.Vertical})
        .onAction((event: SwipeGestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
      })
    )
  }
}
```

![en-us_image_0000001257138365](figures/en-us_image_0000001257138365.gif)
