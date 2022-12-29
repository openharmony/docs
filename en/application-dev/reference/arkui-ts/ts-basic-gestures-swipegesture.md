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
| direction | [swipeDirection](#swipedirection)| No| Swipe direction.<br>Default value: **SwipeDirection.All**|
| speed | number | No| Minimum speed of the swipe gesture, in vp/s.<br>Default value: **100**|

## SwipeDirection

| Name| Description|
| -------- | -------- |
| All | All directions.|
| Horizontal | Horizontal direction. The gesture event is triggered when the angle between the finger moving direction and the x-axis is less than 45 degrees.|
| Vertical | Vertical direction. The gesture event is triggered when the angle between the finger moving direction and the y-axis is less than 45 degrees.|
| None | Swiping disabled.|


## Events

| Name| Description|
| -------- | -------- |
| onAction(event:(event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when a swipe gesture is recognized.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle: number = 0
  @State speed: number = 1

  build() {
    Column() {
      Column() {
        Text("SwipeGesture speed\n" + this.speed)
        Text("SwipeGesture angle\n" + this.rotateAngle)
      }
      .border({ width: 3 })
      .width(300)
      .height(200)
      .margin(100)
      .rotate({ angle: this.rotateAngle })
      // The gesture event is triggered by swiping vertically with one finger.
      .gesture(
      SwipeGesture({ direction: SwipeDirection.Vertical })
        .onAction((event: GestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
        })
      )
    }.width('100%')
  }
}
```

 ![en-us_image_0000001231374559.png](figures/en-us_image_0000001231374559.png) 
