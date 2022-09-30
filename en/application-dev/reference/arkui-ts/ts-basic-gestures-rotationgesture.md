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
| angle | number | No| Minimum degree that can trigger the rotation gesture.<br>Default value: **1.0**|


## Events

| Parameter| Description|
| -------- | -------- |
| onActionStart(event:(event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Triggered when a rotation gesture is recognized.|
| onActionUpdate(event:(event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Triggered when the user moves the finger in a rotation gesture on the screen.|
| onActionEnd(event:(event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Triggered when the finger used for the rotation gesture is lift.|
| onActionCancel(event: () =&gt; void) | Triggered when a tap cancellation event is received after the rotation gesture is recognized.|


## Example

```ts
// xxx.ets
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
        .onActionStart((event: GestureEvent) => {
          console.log('Rotation start')
        })
        .onActionUpdate((event: GestureEvent) => {
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
