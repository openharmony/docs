# PinchGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

**PinchGesture** is used to trigger a pinch gesture, which requires two to five fingers with a minimum 5 vp distance between the fingers.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>  
>  After a pinch gesture is successfully triggered, all fingers must be lifted and pressed again to trigger the pinch gesture again.


## APIs

### PinchGesture

PinchGesture(value?: { fingers?: number, distance?: number })

Sets the parameters for the pinch gesture.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | { fingers?: number, distance?: number } | No| Parameters for the pinch gesture.<br> - **fingers**: minimum number of fingers to trigger a pinch. The value ranges from 2 to 5.<br>Default value: **2**<br>While more fingers than the minimum number can be pressed to trigger the gesture, only the first fingers of the minimum number participate in gesture calculation.<br> - **distance**: minimum recognition distance, in vp.<br>Default value: **5**<br>**NOTE**<br>Value range: [0, +∞). If the value is less than or equal to 0, it will be converted to the default value.|

### PinchGesture<sup>15+</sup>

PinchGesture(options?: PinchGestureHandlerOptions)

Sets the parameters for the pinch gesture. Compared with [PinchGesture](#pinchgesture-1), this API adds the **isFingerCountLimited** parameter to **options**, which determines whether to enforce the exact number of fingers touching the screen.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [PinchGestureHandlerOptions](./ts-uigestureevent.md#pinchgesturehandleroptions) | No| Parameters of the pinch gesture handler.|


## Events

>  **NOTE**
>
>  In **fingerList** of [GestureEvent](ts-gesture-settings.md#gestureevent), the index of a finger corresponds to its position, that is, the ID of a finger in **fingerList[index]** refers to its index. If a finger is pressed first and does not participate in triggering of the current gesture, its position in **fingerList** is left empty. You are advised to use **fingerInfos** when possible.

### onActionStart

onActionStart(event: (event: GestureEvent) => void)

Triggered when a pinch gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  | (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the pinch event.|

### onActionUpdate

onActionUpdate(event: (event: GestureEvent) => void)

Triggered when the user moves the finger in the pinch gesture on the screen.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the pinch event.|

### onActionEnd

onActionEnd(event: (event: GestureEvent) => void)

Triggered when the fingers used for the pinch gesture are lifted.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                     |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the pinch event.|

### onActionCancel

onActionCancel(event: () => void)

Triggered when a tap cancellation event is received after the pinch gesture is recognized. Gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                     |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  () => void | Yes  | Callback for the pinch event.|

### onActionCancel<sup>18+</sup>

onActionCancel(event: Callback\<GestureEvent\>)

Triggered when a tap cancellation event is received after the pinch gesture is recognized. Gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes  | Callback for the pinch event.|

## Attributes

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type   | Read-Only| Optional| Description                                       |
| ----  | ------| -----| -----|----------------------------------- |
| tag<sup>12+</sup>   | string  | No| No| Tag for the pinch gesture. It is used to distinguish the gesture during custom gesture recognition.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| allowedTypes<sup>14+</sup> | No| No| Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | Allowed event input types for the pinch gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## Example

### Example 1: Implementing Simple Scaling

This example demonstrates the recognition of a three-finger pinch gesture using **PinchGesture**.

```ts
// xxx.ets
@Entry
@Component
struct PinchGestureExample {
  @State scaleValue: number = 1;
  @State pinchValue: number = 1;
  @State pinchX: number = 0;
  @State pinchY: number = 0;

  build() {
    Column() {
      Column() {
        Text('PinchGesture scale:\n' + this.scaleValue)
        Text('PinchGesture center:\n(' + this.pinchX + ',' + this.pinchY + ')')
      }
      .height(200)
      .width(300)
      .padding(20)
      .border({ width: 3 })
      .margin({ top: 100 })
      .scale({ x: this.scaleValue, y: this.scaleValue, z: 1 })
      // The gesture event is triggered by pinching three fingers together.
      .gesture(
      PinchGesture({ fingers: 3 })
        .onActionStart((event: GestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: GestureEvent) => {
          if (event) {
            this.scaleValue = this.pinchValue * event.scale
            this.pinchX = event.pinchCenterX
            this.pinchY = event.pinchCenterY
          }
        })
        .onActionEnd((event: GestureEvent) => {
          this.pinchValue = this.scaleValue
          console.info('Pinch end')
        })
      )
    }.width('100%')
  }
}
```

 ![en-us_image_0000001174582848](figures/en-us_image_0000001174582848.png)

### Example 2: Implementing Image Scaling with Finger Tracking

This example demonstrates how to implement image scaling with finger tracking by configuring **PinchGesture**.

```ts
// xxx.ets
import { UIContext, display, matrix4 } from '@kit.ArkUI';

@Entry
@Component
struct PinchGestureExample {
  private uiContext: UIContext = new UIContext();
  private contentWidth: number = 0;
  private contentHeight: number = 0;
  private scaleMin: number = 0.3;
  private scaleMax: number = 30.0;
  private screenWidth: number = 0;
  private screenHeight: number = 0;
  @State pntX: number = 0;
  @State pntY: number = 0;
  @State curScale: number = 1;
  @State preScale: number = 1;
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State matrix: matrix4.Matrix4Transit = matrix4.identity()
    .translate({ x: this.offsetX, y: this.offsetY })
    .scale({ x: this.curScale, y: this.curScale });

  public updateMatrix(): void {
    this.matrix = matrix4.identity()
      .scale({ x: this.curScale, y: this.curScale })
      .translate({ x: this.uiContext.vp2px(this.offsetX), y: this.uiContext.vp2px(this.offsetY) });
  }

  aboutToAppear(): void {
    this.uiContext = this.getUIContext();
    let screenSize = display.getDefaultDisplaySync();
    this.screenWidth = this.uiContext.px2vp(screenSize.width);
    this.screenHeight = this.uiContext.px2vp(screenSize.height);
  }

  build() {
    Column() {
      // Replace $r('app.media.img') with the image resource file you use.
      Image($r('app.media.img'))
        .objectFit(ImageFit.Contain)
        .draggable(false)
        .onComplete((event) => {
          this.contentWidth = this.uiContext.px2vp(event!.contentWidth);
          this.contentHeight = this.uiContext.px2vp(event!.contentHeight);
        })
        .transform(this.matrix)
    }
    // The gesture event is triggered by a two-finger pinch.
    .gesture(
      PinchGesture({ fingers: 2 })
        .onActionStart((event: GestureEvent) => {
          // Displayed size of the image before scaling
          const displayWidth = this.contentWidth * this.curScale;
          const displayHeight = this.contentHeight * this.curScale;
          // Upper left corner coordinates before scaling
          const left = (this.screenWidth - displayWidth) / 2 + this.offsetX;
          const top = (this.screenHeight - displayHeight) / 2 + this.offsetY;
          // Relative position (as a percentage) of the pinch center relative to the upper left corner of the displayed image
          this.pntX = (event.pinchCenterX - left) / displayWidth;
          this.pntY = (event.pinchCenterY - top) / displayHeight;
          // Scale factor before the current operation
          this.preScale = this.curScale;
        })
        .onActionUpdate((event: GestureEvent) => {
          // Target scale factor
          this.curScale = this.preScale * event.scale;
          let targetDisplayWidth = this.contentWidth * this.curScale;
          let targetDisplayHeight = this.contentHeight * this.curScale;
          // Coordinates of the pinch center after scaling
          const pointX = (this.screenWidth - targetDisplayWidth) / 2 + targetDisplayWidth * this.pntX;
          const pointY = (this.screenHeight - targetDisplayHeight) / 2 + targetDisplayHeight * this.pntY;
          // Offset required to align the calculated point (pointX, pointY) with the actual pinch center after scaling
          this.offsetX = event.pinchCenterX - pointX;
          this.offsetY = event.pinchCenterY - pointY;
          this.updateMatrix();
        })
        .onActionEnd((event: GestureEvent) => {
          if (this.curScale < this.scaleMin || this.curScale > this.scaleMax) {
            this.curScale = 1;
            this.offsetX = 0;
            this.offsetY = 0;
            this.updateMatrix();
          }
        })
    )
  }
}
```

 ![image_pinch](figures/image_pinch.gif)
