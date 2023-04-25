

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
| fingers | number | No| Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**<br>Value range: 1 to 10<br>**NOTE**<br>If the value is less than 1 or is not set, the default value is used.|
| direction | PanDirection | No| Pan direction. The enumerated value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**|
| distance | number | No| Minimum pan distance to trigger the gesture, in vp.<br>Default value: **5**<br>**NOTE**<br>If a pan gesture and [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** so that the gesture can be more easily recognized.|

## PanDirection

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
| distance  | number       | No  | Minimum pan distance to trigger the gesture, in vp.<br>Default value: **5.0**<br>**NOTE**<br>If a pan gesture and [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** so that the gesture can be more easily recognized.|

**APIs**

| Name| Description|
| -------- | -------- |
| setDirection(value: PanDirection) | Sets the direction.|
| setDistance(value: number) | Sets the distance.|
| setFingers(value: number) | Sets the number of fingers.|


## Events

| Name| Description|
| -------- | -------- |
| onActionStart(event: (event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when a pan gesture is recognized.|
| onActionUpdate(event: (event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when the pan gesture status is updated.|
| onActionEnd(event: (event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when the finger used for a pan gesture is lift.|
| onActionCancel(event: () =&gt; void) | Invoked when a tap cancellation event is received after a pan gesture is recognized.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct PanGestureExample {
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State positionX: number = 0
  @State positionY: number = 0
  private panOption: PanGestureOptions = new PanGestureOptions({ direction: PanDirection.Left | PanDirection.Right })

  build() {
    Column() {
      Column() {
        Text('PanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin(50)
      .translate({ x: this.offsetX, y: this.offsetY, z: 0 })
      // Pan left or right to trigger the gesture event.
      .gesture(
      PanGesture(this.panOption)
        .onActionStart((event: GestureEvent) => {
          console.info('Pan start')
        })
        .onActionUpdate((event: GestureEvent) => {
          this.offsetX = this.positionX + event.offsetX
          this.offsetY = this.positionY + event.offsetY
        })
        .onActionEnd(() => {
          this.positionX = this.offsetX
          this.positionY = this.offsetY
          console.info('Pan end')
        })
      )

      Button ('Set PanGesture Trigger Condition')
        .onClick(() => {
          // Set the pan gesture to be triggered by two fingers moving in any direction.
          this.panOption.setDirection(PanDirection.All)
          this.panOption.setFingers(2)
        })
    }
  }
}
```

**Diagrams**

Pannig to the left:

![en-us_image_0000001174264374](figures/en-us_image_0000001174264374.png) 

Click **Set PanGesture Trigger Condition** to two fingers moving toward the lower left corner.

 ![en-us_image1_0000001174264374](figures/en-us_image1_0000001174264374.png) 
