# PinchGesture

**PinchGesture** is used to trigger a pinch gesture, which requires two to five fingers with a minimum 3 vp distance between the fingers.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

PinchGesture(value?: { fingers?: number, distance?: number })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a pinch. The value ranges from 2 to 5.<br>Default value: **2**|
| distance | number | No| Minimum recognition distance, in vp.<br>Default value: **3**<br>**NOTE**<br>If the value is less than or equal to 0, it will be converted to the default value. |


## Events

| Name| Description|
| -------- | -------- |
| onActionStart(event:(event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when a pinch gesture is recognized.|
| onActionUpdate(event:(event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when the user moves the finger in a pinch gesture on the screen.|
| onActionEnd(event:(event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when the finger used for a pinch gesture is lift.|
| onActionCancel(event: () =&gt; void) | Triggered when a tap cancellation event is received after a pinch gesture is recognized.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct PinchGestureExample {
  @State scaleValue: number = 1
  @State pinchValue: number = 1
  @State pinchX: number = 0
  @State pinchY: number = 0

  build() {
    Column() {
      Column() {
        Text('PinchGesture scale:\n' + this.scaleValue)
        Text('PinchGesture center:\n(' + this.pinchX + ',' + this.pinchY + ')')
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin({ top: 100 })
      .scale({ x: this.scaleValue, y: this.scaleValue, z: 1 })
      // The gesture event is triggered by pinching three fingers together.
      .gesture(
      PinchGesture({ fingers: 3 })
        .onActionStart((event?: GestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event?: GestureEvent) => {
          if (event) {
            this.scaleValue = this.pinchValue * event.scale
            this.pinchX = event.pinchCenterX
            this.pinchY = event.pinchCenterY
          }
        })
        .onActionEnd(() => {
          this.pinchValue = this.scaleValue
          console.info('Pinch end')
        })
      )
    }.width('100%')
  }
}
```

 ![en-us_image_0000001174582848](figures/en-us_image_0000001174582848.png)
