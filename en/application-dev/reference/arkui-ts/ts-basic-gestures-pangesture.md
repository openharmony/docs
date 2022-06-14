# PanGesture

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions

None


## APIs

PanGesture(options?: { fingers?: number, direction?: PanDirection, distance?: number } | [PanGestureOption](#pangestureoptions))

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 1 | Minimum number of fingers to trigger a slide gesture. The value ranges from 1 to 10. |
  | direction | PanDirection | No | All | Slide direction. The enumerated value supports the AND (&amp;) and OR (\|) operations. |
  | distance | number | No | 5.0 | Minimum slide recognition distance, in vp. |

- PanDirection enums
  | Name | Description |
  | -------- | -------- |
  | All | All directions. |
  | Horizontal | Horizontal slide. |
  | Vertical | Vertical slide. |
  | Left | Slide to the left. |
  | Right | Slide to the right. |
  | Up | Slide up. |
  | Down | Slide down. |
  | None | Slide disabled. |


### PanGestureOptions

The attributes of the slide gesture recognizer can be dynamically modified using the **PanGestureOptions** AP. This avoids modifying attributes through status variables, which will cause the UI to be refreshed.

PanGestureOptions(options?: { fingers?: number, direction?: PanDirection, distance?: number })

- Parameters
  For details, see **PanGesture**.

- APIs
  | Name | Description |
  | -------- | -------- |
  | setDirection(value: PanDirection) | Sets the direction. |
  | setDistance(value: number) | Sets the distance. |
  | setFingers(value: number) | Sets the number of fingers. |


## Events

| Name | Description |
| -------- | -------- |
| onActionStart(callback: (event?: GestureEvent) =&gt; void) | Callback for the pan gestures reorganization event. |
| onActionUpdate(callback: (event?: GestureEvent) =&gt; void) | Callback invoked when a pan gesture is recognized. |
| onActionEnd(callback: (event?: GestureEvent) =&gt; void) | Callback invoked when the finger used for a pan gesture is lift. |
| onActionCancel(callback: () =&gt; void) | Callback invoked when a tap cancellation event is received after a pan gesture is recognized. |

- GestureEvent attributes related to the pan gesture  
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | offsetX | number | Offset of the gesture event, in vp. |
  | offsetY | number | Offset of the gesture event, in vp. |


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
        .onActionStart((event: GestureEvent) => {
          console.info('Pan start')
        })
        .onActionUpdate((event: GestureEvent) => {
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
