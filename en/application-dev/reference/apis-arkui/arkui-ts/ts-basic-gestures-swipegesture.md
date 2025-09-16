# SwipeGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

**SwipeGesture** is used to trigger a swipe gesture. This gesture is successfully recognized when the swipe speed exceeds the specified threshold, which is 100 vp/s by default.

>  **NOTE**
>
>  This gesture is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

### SwipeGesture

SwipeGesture(value?: { fingers?: number, direction?: SwipeDirection, speed?: number })

Sets the parameters for the swipe gesture.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | { fingers?: number, direction?: SwipeDirection, speed?: number } | No| Parameters for the swipe gesture.<br> - **fingers**: minimum number of fingers to trigger a swipe gesture. The value ranges from 1 to 10.<br>Default value: **1**<br> - **direction**: swipe direction.<br>Default value: **SwipeDirection.All**<br> - **speed**: minimum speed of the swipe gesture.<br>Default value: 100 vp/s<br>**NOTE**<br>If the value is less than or equal to 0, it will be converted to the default value.|

### SwipeGesture<sup>15+</sup>

SwipeGesture(options?: SwipeGestureHandlerOptions)

Sets the parameters for the swipe gesture. Compared with [SwipeGesture](#swipegesture-1), this API adds the **isFingerCountLimited** parameter to **options**, which determines whether to enforce the exact number of fingers touching the screen.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SwipeGestureHandlerOptions](./ts-uigestureevent.md#swipegesturehandleroptions) | No| Parameters of the swipe gesture handler.|

## SwipeDirection

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ---- | -- | ----- |
| All | - | All directions.|
| Horizontal | - | Horizontal direction. The gesture event is triggered when the angle between the finger moving direction and the x-axis is less than 45 degrees.|
| Vertical | - | Vertical direction. The gesture event is triggered when the angle between the finger moving direction and the y-axis is less than 45 degrees.|
| None | - | Swiping disabled.|


## Events

>  **NOTE**
>
>  In **fingerList** of [GestureEvent](ts-gesture-settings.md#gestureevent), the index of a finger corresponds to its position, that is, the ID of a finger in **fingerList[index]** refers to its index. If a finger is pressed first and does not participate in triggering of the current gesture, its position in **fingerList** is left empty. You are advised to use **fingerInfos** when possible.

**Atomic service API**: This API can be used in atomic services since API version 8.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onAction

onAction(event: (event: GestureEvent) => void)

Invoked when the swipe gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the gesture event.|

## Attributes

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type   | Read-Only| Optional| Description                |
| ----  | ------ | ---- | ---- |-------------------- |
| tag<sup>11+</sup>   | string  | No| No| Tag for the swipe gesture. It is used to distinguish the gesture during custom gesture judgment.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | No| No| Allowed event input types for the swipe gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## Example

This example demonstrates the recognition of a swipe gesture using **SwipeGesture**.

```ts
// xxx.ets
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle: number = 0;
  @State speed: number = 1;

  build() {
    Column() {
      Column() {
        Text("SwipeGesture speed\n" + this.speed)
        Text("SwipeGesture angle\n" + this.rotateAngle)
      }
      .border({ width: 3 })
      .width(300)
      .height(200)
      .margin(100)
      .rotate({ angle: this.rotateAngle })
      // The gesture event is triggered by swiping vertically with one finger.
      .gesture(
      SwipeGesture({ direction: SwipeDirection.Vertical })
        .onAction((event: GestureEvent) => {
          if (event) {
            this.speed = event.speed
            this.rotateAngle = event.angle
          }
        })
      )
    }.width('100%')
  }
}
```

 ![en-us_image_0000001231374559.png](figures/en-us_image_0000001231374559.png) 
