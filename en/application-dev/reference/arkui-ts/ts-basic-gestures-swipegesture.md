# SwipeGesture

**\<SwipeGesture>** is used to implement a swipe gesture, which can be recognized when the swipe speed is 100 vp/s or higher.

>  **NOTE**
>
>  This gesture is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

SwipeGesture(value?: { fingers?: number; direction?: SwipeDirection; speed?: number })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a swipe gesture. The value ranges from 1 to 10.<br>Default value: **1**|
| direction | SwipeDirection | No| Swipe direction.<br>Default value: **SwipeDirection.All**|
| speed | number | No| Minimum speed of the swipe gesture, in vp/s.<br>Default value: **100**|

## SwipeDirection

| Name| Description|
| -------- | -------- |
| All | All directions.|
| Horizontal | Horizontal direction.|
| Vertical | Vertical direction.|
| None | Swiping disabled.|


## Events

| Name| Description|
| -------- | -------- |
| onAction(event:(event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Triggered when a swipe gesture is recognized.|

![en-us_image_0000001231374661](figures/en-us_image_0000001231374661.png)
## Example

```ts
// xxx.ets
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
      SwipeGesture({fingers: 1, direction: SwipeDirection.Vertical})
        .onAction((event: GestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
      })
    )
  }
}
```

![en-us_image_0000001231374559](figures/en-us_image_0000001231374559.gif)
