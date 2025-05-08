# PanGesture

**PanGesture** is used to trigger a pan gesture when the movement distance of a finger on the screen reaches the minimum value.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

PanGesture(value?: { fingers?: number, direction?: PanDirection, distance?: number } | [PanGestureOptions](#pangestureoptions))

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**<br>Value range: 1 to 10<br>**NOTE**<br>If the value is less than 1 or is not set, the default value is used.|
| direction | [PanDirection](#pandirection) | No| Pan direction. The value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**|
| distance | number | No| Minimum pan distance to trigger the gesture, in vp.<br>Value range: [0, +∞)<br>Default value: **5**<br>**NOTE**<br>If a pan gesture and a [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** to make the gesture more easily recognizable.<br>If the value specified is less than **0**, the default value **5** is used.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen. With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**. The gesture can only be successfully recognized if the number of fingers touching the screen equals the configured minimum number and the swipe distance meets the threshold.<br>For gestures that have already been successfully recognized, changing the number of fingers touching the screen will not trigger the [onActionUpdate](ts-basic-gestures-pangesture.md#events) event, but the [onActionEnd](ts-basic-gestures-pangesture.md#events) event can still be triggered.<br>Default value: **false**|

## PanDirection

Enumerates the pan directions. Unlike **SwipeDirection**, **PanDirection** has no angular restrictions.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name| Description|
| -------- | -------- |
| All | All directions.|
| Horizontal | Horizontal direction.|
| Vertical | Vertical direction.|
| Left | Leftward.|
| Right | Rightward.|
| Up | Upward.|
| Down | Downward.|
| None | Panning disabled.|


## PanGestureOptions

The attributes of the pan gesture recognizer can be dynamically modified using the **PanGestureOptions** API. This avoids modifying attributes through state variables, which will cause a UI re-render.

PanGestureOptions(value?: { fingers?: number, direction?: PanDirection, distance?: number })

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type                             | Mandatory| Description                                                    |
| --------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| fingers   | number                                | No  | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**|
| direction | [PanDirection](#pandirection) | No  | Pan direction. The enumerated value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**|
| distance  | number                                | No  | Minimum pan distance to trigger the gesture, in vp.<br>Default value: **5**<br>**NOTE**<br>If a pan gesture and a [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** to make the gesture more easily recognizable.<br>If the value specified is less than **0**, the default value **5** is used.<br>To avoid slow response and lagging during scrolling, set a reasonable pan distance.|

**APIs**

| Name| Description|
| -------- | -------- |
| setDirection(value: [PanDirection](#pandirection)) | Sets the pan direction.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| setDistance(value: number) | Sets the minimum pan distance to trigger the gesture, in vp.<br>Value range: [0, +∞)<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| setFingers(value: number) | Sets the minimum number of fingers to trigger the gesture.<br>Value range: an integer from 1 to 10<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| getDirection()<sup>12+</sup>: [PanDirection](#pandirection)| Obtains the pan direction.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| getDistance()<sup>18+</sup>: (value: number) | Obtains the minimum pan distance to trigger the gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|


## Events

| Name| Description|
| -------- | -------- |
| onActionStart(event: (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when a pan gesture is recognized.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionUpdate(event: (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when the pan gesture status is updated.<br>If **fingerList** contains multiple fingers, this callback updates the location information of only one finger each time.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionEnd(event: (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when the finger used for a pan gesture is lifted.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionCancel(event: () =&gt; void) | Invoked when a tap cancellation event is received after a pan gesture is recognized. No gesture event information is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionCancel(event: (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void)<sup>18+</sup> | Invoked when a tap cancellation event is received after a pan gesture is recognized. Gesture event information is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## Attributes

| Name| Type   |Description                                       |
| ----  | ------  | ---------------------------------------- |
| tag<sup>11+</sup>   | string  | Tag for the pan gesture. It is used to distinguish the gesture during custom gesture judgment.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)>  | Allowed event input types for the pan gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## Example

This example demonstrates the recognition of single-finger and double-finger pan gestures using **PanGesture**.

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
      .translate({ x: this.offsetX, y: this.offsetY, z: 0}) // Move the component with its upper left corner as the coordinate origin.
      // Pan left and right to trigger the gesture event
      .gesture(
      PanGesture(this.panOption)
        .onActionStart((event: GestureEvent) => {
          console.info('Pan start')
        })
        .onActionUpdate((event: GestureEvent) => {
          if (event) {
            this.offsetX = this.positionX + event.offsetX
            this.offsetY = this.positionY + event.offsetY
          }
        })
        .onActionEnd((event: GestureEvent) => {
          this.positionX = this.offsetX
          this.positionY = this.offsetY
          console.info('Pan end')
        })
      )

      Button('Set PanGesture Trigger Condition')
        .onClick(() => {
          // Change the trigger condition to double-finger panning in any direction.
          this.panOption.setDirection(PanDirection.All)
          this.panOption.setFingers(2)
        })
    }
  }
}
```

**Diagrams**

Panning left:

![en-us_image_0000001174264374](figures/en-us_image_0000001174264374.png) 

Click **Set PanGesture Trigger Condition** to set the pan gesture to be triggered by two fingers moving toward the lower left corner.

 ![en-us_image1_0000001174264374](figures/en-us_image1_0000001174264374.png) 
