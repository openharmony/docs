# PinchGesture

**PinchGesture** is used to trigger a pinch gesture, which requires two to five fingers with a minimum 3 vp distance between the fingers.

>  **NOTE**
>
>  This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs

PinchGesture(value?: { fingers?: number, distance?: number })

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fingers | number | No| Minimum number of fingers to trigger a pinch. The value ranges from 2 to 5.<br>Default value: **2**|
| distance | number | No| Minimum recognition distance, in vp.<br>Default value: **3.0**|


## Events

| Name| Description|
| -------- | -------- |
| onActionStart(event:(event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Triggered when a pinch gesture is recognized.|
| onActionUpdate(event:(event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Triggered when the user moves the finger in a pinch gesture on the screen.|
| onActionEnd(event:(event?: [GestureEvent](ts-gesture-settings.md)) =&gt; void) | Triggered when the finger used for a pinch gesture is lift.|
| onActionCancel(event: () =&gt; void) | Triggered when a tap cancellation event is received after a pinch gesture is recognized.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct PinchGestureExample {
  @State scaleValue: number = 1

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PinchGesture scale:' + this.scale)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .scale({ x: this.scaleValue, y: this.scaleValue, z: this.scaleValue })
    .gesture(
      PinchGesture()
        .onActionStart((event: GestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: GestureEvent) => {
          this.scaleValue = event.scale
        })
        .onActionEnd(() => {
          console.info('Pinch end')
        })
    )
  }
}
```

![en-us_image_0000001257058419](figures/en-us_image_0000001257058419.gif)
