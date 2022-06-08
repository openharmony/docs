# RotationGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

RotationGesture(options?: { fingers?: number, angle?: number })

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 2 | Minimum number of fingers to trigger a rotation. The value ranges from 2 to 5. |
  | angle | number | No | 1.0 | Minimum degree that can trigger the rotation gesture. |


## Events

| Name | Description |
| -------- | -------- |
| onActionStart((event?: GestureEvent) =&gt; void) | Callback invoked when a rotation gesture is recognized. |
| onActionUpdate((event?: GestureEvent) =&gt; void) | Callback invoked during the movement of the rotation gesture. |
| onActionEnd((event?: GestureEvent) =&gt; void) | Callback invoked when the finger used for the rotation gesture is lift. |
| onActionCancel(event: () =&gt; void) | Callback invoked when a tap cancellation event is received after the rotation gesture is recognized. |

- GestureEvent attributes related to the rotation gesture  
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | angle | number | Rotation angle. |


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
