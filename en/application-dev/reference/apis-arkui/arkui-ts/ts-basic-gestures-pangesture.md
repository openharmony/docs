# PanGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

**PanGesture** is used to trigger a pan gesture when the movement distance of a finger on the screen reaches the minimum value.

The table below describes the scenarios that can trigger a pan gesture:

| Trigger Mode             | Input Source Type          | Input Device Type           | Remarks                             | 
|----------------------|---------------------|------------------------|-----------------------------------|
| Swiping with a finger press         | [SourceTool](ts-gesture-settings.md#sourcetool9).Finger   | [SourceType](ts-gesture-settings.md#sourcetype8).TouchScreen | Both **axisVertical** and **axisHorizontal** are 0.|
| Swiping with a left mouse button press     | [SourceTool](ts-gesture-settings.md#sourcetool9).MOUSE    | [SourceType](ts-gesture-settings.md#sourcetype8).Mouse        | Both **axisVertical** and **axisHorizontal** are 0.|
| Scrolling with a mouse wheel         | [SourceTool](ts-gesture-settings.md#sourcetool9).MOUSE    | [SourceType](ts-gesture-settings.md#sourcetype8).Mouse        | Either **axisVertical** or **axisHorizontal** is non-zero.|
| Swiping after pressing the left button on a touchpad | [SourceTool](ts-gesture-settings.md#sourcetool9).MOUSE  | [SourceType](ts-gesture-settings.md#sourcetype8).Mouse     | Both **axisVertical** and **axisHorizontal** are 0.|
| Swiping with two fingers on a touchpad      | [SourceTool](ts-gesture-settings.md#sourcetool9).TOUCHPAD  | [SourceType](ts-gesture-settings.md#sourcetype8).Mouse      | Either **axisVertical** or **axisHorizontal** is non-zero.|
| Swiping with a stylus      | [SourceTool](ts-gesture-settings.md#sourcetool9).Pen  | [SourceType](ts-gesture-settings.md#sourcetype8).TouchScreen      | Both **axisVertical** and **axisHorizontal** are 0.|

>  **NOTE**
>
>  This API is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

### PanGesture

PanGesture(value?: { fingers?: number; direction?: PanDirection; distance?: number } | PanGestureOptions)

Sets the pan gesture event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | { fingers?: number; direction?: PanDirection; distance?: number } \| [PanGestureOptions](#pangestureoptions) | No| Parameters for the pan gesture.<br> - **fingers**: minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**.<br>Value range: [1, 10].<br>**NOTE**<br>If the value is less than 1 or is not set, the default value is used.<br> - **direction**: pan direction. The value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**.<br> - **distance**: minimum pan distance to trigger the gesture, in vp.<br>Value range: [0, +∞).<br>Default value: **8** for the stylus and **5** for other input sources.<br>**NOTE**<br>If a pan gesture and a [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** to make the gesture more easily recognizable.<br>If the value specified is less than **0**, the default value is used.|

### PanGesture<sup>15+</sup>

PanGesture(options?: PanGestureHandlerOptions)

Sets the pan gesture event. Compared with [PanGesture](#pangesture-1), this API adds the **isFingerCountLimited** and **distanceMap** parameters to **options**, which control whether to enforce the exact number of fingers touching the screen and specify the minimum pan distance required to trigger the gesture for different input sources, respectively.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options   | [PanGestureHandlerOptions](./ts-uigestureevent.md#pangesturehandleroptions)   | No  | Parameters of the pan gesture handler.|

## PanDirection

Enumerates the pan directions. Unlike **SwipeDirection**, **PanDirection** has no angular restrictions.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| ---- | -- | ----- |
| All | - | All directions.|
| Horizontal | - | Horizontal direction.|
| Vertical | - | Vertical direction.|
| Left | - | Leftward.|
| Right | - | Rightward.|
| Up | - | Upward.|
| Down | - | Downward.|
| None | - | Panning disabled.|


## PanGestureOptions

### constructor

PanGestureOptions(value?: { fingers?: number, direction?: PanDirection, distance?: number })

The attributes of the pan gesture recognizer can be dynamically modified using the **PanGestureOptions** API. This avoids modifying attributes through state variables, which will cause a UI re-render.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| fingers   | number                                | No  | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**.|
| direction | [PanDirection](#pandirection) | No  | Pan direction. The enumerated value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**.|
| distance  | number                                | No  | Minimum pan distance to trigger the gesture, in vp.<br>Default value: **8** for the stylus and **5** for other input sources.<br>**NOTE**<br>If a pan gesture and a [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** to make the gesture more easily recognizable.<br>If the value specified is less than **0**, the default value is used.<br>To avoid slow response and lagging during scrolling, set a reasonable pan distance.|

### constructor<sup>20+</sup>

constructor(value?: PanGestureHandlerOptions)

The attributes of the pan gesture recognizer can be dynamically modified using the **PanGestureOptions** API. This avoids modifying attributes through state variables, which will cause a UI re-render.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ---------------------- | ---- | -------------------------------- |
| value   | [PanGestureHandlerOptions](./ts-uigestureevent.md#pangesturehandleroptions)   | No  | Parameters of the pan gesture handler.|

### setDirection

setDirection(value: PanDirection)

Sets the pan direction.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                     |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  [PanDirection](#pandirection) | Yes  | Pan direction. The enumerated value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**.|

### setDirection<sup>20+</sup>

setDirection(value: PanDirection): void

Sets the pan direction.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  [PanDirection](#pandirection) | Yes  | Pan direction. The enumerated value supports the AND (&amp;) and OR (\|) operations.<br>Default value: **PanDirection.All**.|

### setDistance

setDistance(value: number)

Sets the minimum pan distance to trigger the gesture, in vp. To avoid performance degradation due to excessive response delays or accidental releases, avoid excessively large values. For best practices, see [Reducing the Pan Distance for Gesture Recognition](https://developer.huawei.com/consumer/en/doc/best-practices-V5/bpta-application-latency-optimization-cases-V5#section1116134115286).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                       |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | Yes  | Minimum pan distance to trigger the gesture, in vp.<br>Default value: **8** for the stylus and **5** for other input sources.<br>**NOTE**<br>If a pan gesture and a [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** to make the gesture more easily recognizable.<br>If the value specified is less than **0**, the default value is used.<br>To avoid slow response and lagging during scrolling, set a reasonable pan distance.|

### setDistance<sup>20+</sup>

setDistance(value: number): void

Sets the minimum pan distance to trigger the gesture, in vp. To avoid performance degradation due to excessive response delays or accidental releases, avoid excessively large values. For best practices, see [Reducing the Pan Distance for Gesture Recognition](https://developer.huawei.com/consumer/en/doc/best-practices-V5/bpta-application-latency-optimization-cases-V5#section1116134115286).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                      |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | Yes  | Minimum pan distance to trigger the gesture, in vp.<br>Default value: **8** for the stylus and **5** for other input sources.<br>**NOTE**<br>If a pan gesture and a [tab](ts-container-tabs.md) swipe occur at the same time, set **distance** to **1** to make the gesture more easily recognizable.<br>If the value specified is less than **0**, the default value is used.<br>To avoid slow response and lagging during scrolling, set a reasonable pan distance.|

### setFingers

setFingers(value: number)

Sets the minimum number of fingers to trigger the gesture.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | Yes  | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**.|

### setFingers<sup>20+</sup>

setFingers(value: number): void

Sets the minimum number of fingers to trigger the gesture.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| value  |  number | Yes  | Minimum number of fingers to trigger a pan gesture. The value ranges from 1 to 10.<br>Default value: **1**.|


### getDirection<sup>12+</sup>

getDirection(): PanDirection

Obtains the pan direction.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| [PanDirection](#pandirection) | Pan direction.|

### getDistance<sup>18+</sup>

getDistance(): number

Obtains the minimum pan distance to trigger the gesture.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description       |
| ------ | --------- |
| number | Minimum pan distance to trigger the gesture.|


## Events

**System capability**: SystemCapability.ArkUI.ArkUI.Full

>  **NOTE**
>
>  In **fingerList** of [GestureEvent](ts-gesture-settings.md#gestureevent), the index of a finger corresponds to its position, that is, the ID of a finger in **fingerList[index]** refers to its index. If a finger is pressed first and does not participate in triggering of the current gesture, its position in **fingerList** is left empty. You are advised to use **fingerInfos** when possible.

### onActionStart

onActionStart(event: (event: GestureEvent) => void)

Invoked when a pan gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the gesture event.|

### onActionUpdate

onActionUpdate(event: (event: GestureEvent) => void)

Invoked when the pan gesture status is updated. If **fingerList** contains multiple fingers, this callback updates the location information of only one finger each time.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the gesture event.|

### onActionEnd

onActionEnd(event: (event: GestureEvent) => void)

Invoked when the finger used for a pan gesture is lifted.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the gesture event.|

### onActionCancel

onActionCancel(event: () => void)

Invoked when a tap cancellation event is received after a pan gesture is recognized. No gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  () => void | Yes  | Callback for the gesture event.|

### onActionCancel<sup>18+</sup>

onActionCancel(event: Callback\<GestureEvent\>)

Invoked when a tap cancellation event is received after a pan gesture is recognized. Gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes  | Callback for the gesture event.|

## Attributes

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type   | Read-Only| Optional| Description                    |
| ----  | ------ | ---- | ---- | ----------------------- |
| tag<sup>11+</sup>   | string  | No| No| Tag for the pan gesture. It is used to distinguish the gesture during custom gesture judgment.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)>  | No| No| Allowed event input types for the pan gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## Example

This example demonstrates the recognition of single-finger and double-finger pan gestures using **PanGesture**.

```ts
// xxx.ets
@Entry
@Component
struct PanGestureExample {
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State positionX: number = 0;
  @State positionY: number = 0;
  private panOption: PanGestureOptions = new PanGestureOptions({ direction: PanDirection.Left | PanDirection.Right });

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
          console.info('Pan start');
          console.info('Pan start timeStamp is: ' + event.timestamp);
        })
        .onActionUpdate((event: GestureEvent) => {
          if (event) {
            this.offsetX = this.positionX + event.offsetX;
            this.offsetY = this.positionY + event.offsetY;
          }
        })
        .onActionEnd((event: GestureEvent) => {
          this.positionX = this.offsetX;
          this.positionY = this.offsetY;
          console.info('Pan end');
          console.info('Pan end timeStamp is: ' + event.timestamp);
        })
      )

      Button('Set PanGesture Trigger Condition')
        .onClick(() => {
          // Change the trigger condition to double-finger panning in any direction.
          this.panOption.setDirection(PanDirection.All);
          this.panOption.setFingers(2);
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
