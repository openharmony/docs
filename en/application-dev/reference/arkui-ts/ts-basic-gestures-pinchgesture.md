# PinchGesture


> **NOTE**<br>
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

PinchGesture(options?: { fingers?: number, distance?: number })

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 2 | Minimum number of fingers to trigger a pinch. The value ranges from 2 to 5. |
  | distance | number | No | 3.0 | Minimum recognition distance, in vp. |


## Events

| Name | Description |
| -------- | -------- |
| onActionStart((event?: GestureEvent) =&gt; void) | Callback invoked when a pinch gesture is recognized. |
| onActionUpdate((event?: GestureEvent) =&gt; void) | Callback invoked during the movement of a pinch gesture. |
| onActionEnd((event?: GestureEvent) =&gt; void) | Callback invoked when the finger used for a pinch gesture is lift. |
| onActionCancel(event: () =&gt; void) | Callback invoked when a tap cancellation event is received after a pinch gesture is recognized. |

- GestureEvent attributes related to the pinch gesture  
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | scale | number | Scale ratio. This attribute is used for the pinch gesture. |
  | pinchCenterX | number | X-coordinate of the center of the pinch gesture, in px. |
  | pinchCenterY | number | Y-coordinate of the center of the pinch gesture, in px. |


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
        .onActionStart((event: GestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: GestureEvent) => {
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
