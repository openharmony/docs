# RotationGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

**RotationGesture** is used to trigger a rotation gesture, which requires two to five fingers with a minimum 1-degree rotation angle. This gesture cannot be triggered using a two-finger rotation operation on a trackpad.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

### RotationGesture

RotationGesture(value?: { fingers?: number, angle?: number })

Sets the parameters for the rotation gesture.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | { fingers?: number, angle?: number } | No| Parameters for the rotation gesture.<br> - **fingers**: minimum number of fingers to trigger a rotation. The value ranges from 2 to 5.<br>Default value: **2**<br>While more fingers than the minimum number can be pressed to trigger the gesture, only the first two fingers participate in gesture calculation.<br> - **angle**: minimum angle change required to trigger the rotation gesture, in degrees (deg).<br>Default value: **1**<br>**NOTE**<br>If the value is less than or equal to 0 or greater than 360, it will be converted to the default value.|

### RotationGesture<sup>15+</sup>

RotationGesture(options?: RotationGestureHandlerOptions)

Sets the parameters for the rotation gesture. Compared with [RotationGesture](#rotationgesture-1), this API adds the **isFingerCountLimited** parameter to **options**, which determines whether to enforce the exact number of fingers touching the screen.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [RotationGestureHandlerOptions](./ts-uigestureevent.md#rotationgesturehandleroptions) | No|Parameters of the rotation gesture handler.|


## Events

>  **NOTE**
>
>  In **fingerList** of [GestureEvent](ts-gesture-settings.md#gestureevent), the index of a finger corresponds to its position, that is, the ID of a finger in **fingerList[index]** refers to its index. If a finger is pressed first and does not participate in triggering of the current gesture, its position in **fingerList** is left empty. You are advised to use **fingerInfos** when possible.

### onActionStart

onActionStart(event: (event: GestureEvent) => void)

Triggered when a rotation gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the gesture event.|

### onActionUpdate

onActionUpdate(event: (event: GestureEvent) => void)

Triggered when the user moves the finger in a rotation gesture on the screen.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                       |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the gesture event.|

### onActionEnd

onActionEnd(event: (event: GestureEvent) => void)

Triggered when the finger used for the rotation gesture is lifted.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the gesture event.|

### onActionCancel

onActionCancel(event: () => void)

Triggered when a tap cancellation event is received after the rotation gesture is recognized. No gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  () => void | Yes  | Callback for the gesture event.|

### onActionCancel<sup>18+</sup>

onActionCancel(event: Callback\<GestureEvent\>)

Triggered when a tap cancellation event is received after the rotation gesture is recognized. Gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes  | Callback for the gesture event.|

## Attributes

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type   | Read-Only| Optional| Description                             |
| ----  | ------  | --- | ----- | -------------------------------- |
| tag<sup>11+</sup>   | string  | No| No| Tag for the rotation gesture. It is used to distinguish the gesture during custom gesture recognition.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | No| No| Allowed event input types for the rotation gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## Example

This example demonstrates the recognition of a two-finger rotation gesture using **RotationGesture**.

```ts
// xxx.ets
@Entry
@Component
struct RotationGestureExample {
  @State angle: number = 0;
  @State rotateValue: number = 0;

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
