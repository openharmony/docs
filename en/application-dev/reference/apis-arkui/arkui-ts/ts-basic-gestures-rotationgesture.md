# RotationGesture

**RotationGesture** is used to trigger a rotation gesture, which requires two to five fingers with a minimum 1-degree rotation angle.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

RotationGesture(value?: { fingers?: number, angle?: number })

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a rotation. The value ranges from 2 to 5.<br>Default value: **2**<br>While more fingers than the minimum number can be pressed to trigger the gesture, only the first two fingers participate in gesture calculation.|
| angle | number | No| Minimum degree that can trigger the rotation gesture.<br>Default value: **1**<br>**NOTE**<br>If the value is less than or equal to 0 or greater than 360, it will be converted to the default value.|


## Events

| Name | Description|
| -------- | -------- |
| onActionStart(event:(event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when a rotation gesture is recognized.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionUpdate(event:(event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when the user moves the finger in a rotation gesture on the screen.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionEnd(event:(event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Triggered when the finger used for the rotation gesture is lifted.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionCancel(event: () =&gt; void) | Triggered when a tap cancellation event is received after the rotation gesture is recognized. No gesture event information is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionCancel(event:(event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void)<sup>16+</sup> | Triggered when a tap cancellation event is received after the rotation gesture is recognized. Gesture event information is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 16.|

## Attributes

| Name| Type   |Description                                       |
| ----  | ------  | ---------------------------------------- |
| tag<sup>11+</sup>   | string  | Tag for the rotation gesture. It is used to distinguish the gesture during custom gesture judgment.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | Allowed event input types for the rotation gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## Example

This example demonstrates the recognition of a two-finger rotation gesture using **RotationGesture**.

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
          if (event) {
            this.angle = this.rotateValue + event.angle
          }
        })
        .onActionEnd((event: GestureEvent) => {
          this.rotateValue = this.angle
          console.info('Rotation end')
        })
      )
    }.width('100%')
  }
}
```

 ![en-us_image_0000001174264372](figures/en-us_image_0000001174264372.png)
