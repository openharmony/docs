# PanGesture

**PanGesture** is used to trigger a pan gesture, which requires a minimum 5 vp movement distance of a finger on the screen.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

PanGesture(value?: { fingers?: number; direction?: PanDirection; distance?: number } | [PanGestureOptions](#pangestureoptions))

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**|
| direction | PanDirection | No| Pan direction. The enumerated value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**|
| distance | number | No| Minimum pan distance to trigger the gesture, in vp.<br>Default value: **5.0**<br>**NOTE**<br>If a pan gesture and tab swipe occur at the same time, set **distance** to **1** so that the gesture can be more easily recognized.|

## PanDirection enums

| Name| Description|
| -------- | -------- |
| All | All directions.|
| Horizontal | Horizontal panning.|
| Vertical | Vertical panning.|
| Left | Panning to the left.|
| Right | Panning to the right.|
| Up | Panning up.|
| Down | Panning down.|
| None | Panning disabled.|


## PanGestureOptions

The attributes of the pan gesture recognizer can be dynamically modified using the **PanGestureOptions** API. This avoids modifying attributes through state variables, which will cause the UI to be refreshed.

PanGestureOptions(value?: { fingers?: number; direction?: PanDirection; distance?: number })

**Parameters**

| Name | Type    | Mandatory| Description                                                    |
| --------- | ------------ | ---- | ------------------------------------------------------------ |
| fingers   | number       | No  | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**|
| direction | PanDirection | No  | Pan direction. The enumerated value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **All**|
| distance  | number       | No  | Minimum pan distance to trigger the gesture, in vp.<br>Default value: **5.0**<br>**NOTE**<br>If a pan gesture and tab swipe occur at the same time, set **distance** to **1** so that the gesture can be more easily recognized.|

**APIs**

| Name| Description|
| -------- | -------- |
| setDirection(value: PanDirection) | Sets the direction.|
| setDistance(value: number) | Sets the distance.|
| setFingers(value: number) | Sets the number of fingers.|


## Events

| Name| Description|
| -------- | -------- |
| onActionStart(event: (event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Callback invoked when a pan gesture is recognized.|
| onActionUpdate(event: (event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Callback invoked when the pan gesture status is updated.|
| onActionEnd(event: (event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Callback invoked when the finger used for a pan gesture is lift.|
| onActionCancel(event: () =&gt; void) | Callback invoked when a tap cancellation event is received after a pan gesture is recognized.|


## Example

```ts
// xxx.ets
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
