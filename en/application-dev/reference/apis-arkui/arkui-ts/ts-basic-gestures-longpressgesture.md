# LongPressGesture

**LongPressGesture** is used to trigger a long press gesture, which requires one or more fingers with a minimum 500 ms hold-down time.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

LongPressGesture(value?: { fingers?: number, repeat?: boolean, duration?: number })

Triggers a long press gesture. In components that support drag actions by default, such as **Text**, **TextInput**, **TextArea**, **HyperLink**, **Image**, and **RichEditor**, the long press gesture may conflict with the drag action. If this occurs, they are handled as follows:

If the minimum duration of the long press gesture is less than 500 ms, the long press gesture receives a higher response priority than the drag action.

If the minimum duration of the long press gesture is greater than or equal to 500 ms, the drag action receives a higher response priority than the long press gesture.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10.<br>Default value: **1**<br> **NOTE**<br>If a finger moves more than 15 px after being pressed, the gesture recognition fails.|
| repeat | boolean | No| Whether to continuously trigger the event callback. The value **true** means to continuously trigger the event callback, and **false** means the opposite.<br>Default value: **false**|
| duration | number | No| Minimum hold-down time, in ms.<br>Default value: **500**<br>**NOTE**<br>Value range: [0, +∞). If the value is less than or equal to 0, the default value **500** is used.|
| isFingerCountLimited<sup>15+</sup> | boolean | No| Whether to enforce the exact number of fingers touching the screen. With the value **true**, the gesture recognition fails if the number of fingers touching the screen does not match the configured value of **fingers**.<br>For gestures that have already been successfully recognized, changes in the number of fingers touching the screen will not trigger the repeat event. However, if the number of fingers touching the screen returns to the configured minimum number, the [onAction](ts-basic-gestures-longpressgesture.md#events) event can be triggered. The [onActionEnd](ts-basic-gestures-longpressgesture.md#events) event can also be triggered regardless of the finger count.<br>Default value: **false**|


## Events

| Name| Description|
| -------- | -------- |
| onAction(event:(event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when a long press gesture is recognized.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionEnd(event:(event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Invoked when the last finger is lifted after the long press gesture is recognized.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionCancel(event: () =&gt; void) | Invoked when a tap cancellation event is received after the long press gesture is recognized. No gesture event information is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onActionCancel(event:(event: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void)<sup>18+</sup> | Invoked when a tap cancellation event is received after the long press gesture is recognized. Gesture event information is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## Attributes

| Name| Type   |Description                                       |
| ----  | ------  | ---------------------------------------- |
| tag<sup>11+</sup>   | string  | Tag for the long press gesture. It is used to distinguish the gesture during custom gesture judgment.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| allowedTypes<sup>14+</sup> | Array\<[SourceTool](ts-gesture-settings.md#sourcetool9)> | Allowed event input types for the long press gesture.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|


## Example

This example demonstrates the recognition of a long press gesture using **LongPressGesture**.

```ts
// xxx.ets
@Entry
@Component
struct LongPressGestureExample {
  @State count: number = 0

  build() {
    Column() {
      Text('LongPress onAction:' + this.count).fontSize(28)
        // Touch and hold the text with one finger to trigger the gesture event.
        .gesture(
        LongPressGesture({ repeat: true })
          // When repeat is set to true, the event callback is triggered continuously when the gesture is detected. The triggering interval is specified by duration (500 ms by default).
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
