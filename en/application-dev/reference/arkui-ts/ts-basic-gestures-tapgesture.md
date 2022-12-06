# TapGesture

**TapGesture** is used to trigger a tap gesture with one or more taps.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

TapGesture(value?: { count?: number, fingers?: number })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| count | number | No| Number of consecutive taps. If this parameter is set to a value less than **1**, the default value will be used.<br>Default value: **1**<br>> **NOTE**<br>> If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.|
| fingers | number | No| Number of fingers required to trigger a tap. The value ranges from 1 to 10.<br>Default value: **1**<br>> **NOTE**<br>> 1. When multi-finger is configured, the gesture will fail to be recognized if the number of fingers used for tapping is less than the configured number within 300 ms of tapping by the first finger.<br>> 2. The gesture will fail to be recognized if the number of fingers used for tapping exceeds the configured number.|


## Events

| Name| Description|
| -------- | -------- |
| onAction(event: (event?: [GestureEvent](ts-gesture-settings.md#gestureevent)) =&gt; void) | Callback invoked when a tap gesture is recognized.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct TapGestureExample {
  @State value: string = ''

  build() {
    Column() {
      // The gesture event is triggered by double-tapping.
      Text('Click twice').fontSize(28)
        .gesture(
        TapGesture({ count: 2 })
          .onAction((event: GestureEvent) => {
            this.value = JSON.stringify(event.fingerList[0])
          })
        )
      Text(this.value)
    }
    .height(200)
    .width(300)
    .padding(20)
    .border({ width: 3 })
    .margin(30)
  }
}
```

![en-us_image_0000001256858417](figures/en-us_image_0000001256858417.gif)
