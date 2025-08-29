# LongPressGesture
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

**LongPressGesture** is used to trigger a long press gesture. This gesture requires one or more fingers to be held down for a specified duration, which is 500 ms by default and can be adjusted using the **duration** parameter.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  On some devices, the system's two-finger long press gesture may take precedence, causing the application's two-finger long press gesture to be ineffective.


## APIs

### LongPressGesture

LongPressGesture(value?: { fingers?: number, repeat?: boolean, duration?: number })

Sets the parameters for the long press gesture.

In components that support drag actions by default, such as **Text**, **TextInput**, **TextArea**, **HyperLink**, **Image**, and **RichEditor**, the long press gesture may conflict with the drag action. If this occurs, the event priority is determined as follows:

If the long press duration is less than 500 milliseconds, the system prioritizes the long press event over the drag event.

If the long press duration reaches or exceeds 500 milliseconds, the system prioritizes the drag event over the long press event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | { fingers?: number, repeat?: boolean, duration?: number } | No| Parameters for the long press gesture.<br> - **fingers**: minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10.<br>Default value: **1**.<br> - **repeat**: whether to continuously trigger the event callback. The value **true** means to continuously trigger the event callback, and **false** means the opposite.<br>Default value: **false**.<br> - **duration**: minimum hold-down time, in ms.<br>Default value: **500**.|

### LongPressGesture<sup>15+</sup>

LongPressGesture(options?: LongPressGestureHandlerOptions)

Sets the parameters for the long press gesture. Compared with [LongPressGesture](#longpressgesture-1), this API adds the **isFingerCountLimited** parameter to **options**, which determines whether to enforce the exact number of fingers touching the screen.

In components that support drag actions by default, such as **Text**, **TextInput**, **TextArea**, **HyperLink**, **Image**, and **RichEditor**, the long press gesture may conflict with the drag action. If this occurs, the event priority is determined as follows:

If the long press duration is less than 500 milliseconds, the system prioritizes the long press event over the drag event.

If the long press duration reaches or exceeds 500 milliseconds, the system prioritizes the drag event over the long press event.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [LongPressGestureHandlerOptions](./ts-uigestureevent.md#longpressgesturehandleroptions) | No| Parameters of the long press gesture handler.|


## Events

>  **NOTE**
>
>  In **fingerList** of [GestureEvent](ts-gesture-settings.md#gestureevent), the index of a finger corresponds to its position, that is, the ID of a finger in **fingerList[index]** refers to its index. If a finger is pressed first and does not participate in triggering of the current gesture, its position in **fingerList** is left empty. You are advised to use **fingerInfos** when possible.
>
>  Once a long press gesture is triggered, the information in **fingerList** and **fingerInfo** within the [GestureEvent](ts-gesture-settings.md#gestureevent) object is only updated when fingers are pressed down and not updated when fingers are lifted.

### onAction

onAction(event: (event: GestureEvent) => void)

Invoked when a long press gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the long press event.|

### onActionEnd

onActionEnd(event: (event: GestureEvent) => void)

Invoked when the last finger is lifted after the long press gesture is recognized.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  (event: [GestureEvent](ts-gesture-settings.md#gestureevent)) => void | Yes  | Callback for the long press event.|

### onActionCancel

onActionCancel(event: () => void)

Invoked when a tap cancellation event is received after the long press gesture is recognized. No gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  () => void | Yes  | Callback for the long press event.|

### onActionCancel<sup>18+</sup>

onActionCancel(event: Callback\<GestureEvent\>)

Invoked when a tap cancellation event is received after the long press gesture is recognized. Gesture event information is returned.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| event  |  Callback\<[GestureEvent](ts-gesture-settings.md#gestureevent)> | Yes  | Callback for the long press event.|

## Attributes

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type   | Read-Only| Optional| Description                                       |
| ----  | ------  | ----------- | ------------ | ----------------- |
| tag<sup>11+</sup>   | string  | No| No| Tag for the long press gesture. It is used to distinguish the gesture during custom gesture judgment.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | No| No| Allowed event input types for the long press gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|


## Example

This example demonstrates the recognition of a long press gesture using **LongPressGesture**.

```ts
// xxx.ets
@Entry
@Component
struct LongPressGestureExample {
  @State count: number = 0;

  build() {
    Column() {
      Text('LongPress onAction:' + this.count).fontSize(28)
        // This gesture event is triggered when the text is long-pressed with a single finger.
        .gesture(
        LongPressGesture({ repeat: true })
          // Since repeat is set to true, the event callback is continuously triggered during the long press, with the triggering interval specified by duration (500 ms by default).
          .onAction((event: GestureEvent) => {
            if (event && event.repeat) {
              this.count++
            }
          })
            // Triggered when the long press gesture ends.
          .onActionEnd((event: GestureEvent) => {
            this.count = 0
          })
        )
    }
    .height(200)
    .width(300)
    .padding(20)
    .border({ width: 3 })
    .margin(30)
  }
}
```

![en-us_image_0000001174264380](figures/en-us_image_0000001174264380.gif)
