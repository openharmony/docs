# RotationGesture

**RotationGesture** is used to trigger a rotation gesture, which requires two to five fingers with a minimum 1-degree rotation angle.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

RotationGesture(value?: { fingers?: number, angle?: number })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a rotation. The value ranges from 2 to 5.<br>Default value: **2**|
| angle | number | No| Minimum degree that can trigger the rotation gesture.<br>Default value: **1**|


## Events

| Parameter| Description|
| -------- | -------- |
| onActionStart(event:(event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when a rotation gesture is recognized.|
| onActionUpdate(event:(event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when the user moves the finger in a rotation gesture on the screen.|
| onActionEnd(event:(event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when the finger used for the rotation gesture is lift.|
| onActionCancel(event: () =&gt; void) | Triggered when a tap cancellation event is received after the rotation gesture is recognized.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct RotationGestureExample {
  @State angle: number = 0
  @State rotateValue: number = 0

  build() {
    Column() {
      Column() {
        Text('RotationGesture angle:' + this.angle)
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin(80)
      .rotate({ angle: this.angle })
      // The gesture event is triggered by rotating with two fingers.
      .gesture(
      RotationGesture()
        .onActionStart((event: GestureEvent) => {
          console.info('Rotation start')
        })
        .onActionUpdate((event: GestureEvent) => {
          this.angle = this.rotateValue + event.angle
        })
        .onActionEnd(() => {
          this.rotateValue = this.angle
          console.info('Rotation end')
        })
      )
    }.width('100%')
  }
}
```

 ![en-us_image_0000001174264372](figures/en-us_image_0000001174264372.png)
