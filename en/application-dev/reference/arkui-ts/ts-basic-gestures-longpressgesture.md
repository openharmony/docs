# LongPressGesture


> **NOTE**<br>
> This API is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The **&lt;LongPressGesture&gt;** component can be used to trigger a long press gesture.

## Required Permissions

None


## APIs

LongPressGesture(options?: { fingers?: number, repeat?: boolean, duration?: number })

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 1 | Minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10. |
  | repeat | boolean | No | false | Whether to continuously trigger the event callback. |
  | duration | number | No | 500 | Minimum hold-down time, in ms. |


## Events

| Name | Description |
| -------- | -------- |
| onAction((event?: GestureEvent) =&gt; void) | Callback invoked when a long press gesture is recognized. |
| onActionEnd((event?: GestureEvent) =&gt; void) | Callback invoked when the finger used for a long press gesture is lift. |
| onActionCancel(event: () =&gt; void) | Callback invoked when a tap cancellation event is received after a long press gesture is recognized. |

- GestureEvent attributes related to the long press gesture
  | Name | Type | Description |
  | -------- | -------- | -------- |
  | repeat | boolean | Whether the event is repeated. |


## Example


```
@Entry
@Component
struct LongPressGestureExample {
  @State count: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('LongPress onAction:' + this.count)
    }
    .height(200).width(300).padding(60).border({ width:1 }).margin(30)
    .gesture(
      LongPressGesture({ repeat: true })
        // Repeatedly triggered when the long press gesture exists.
        .onAction((event: GestureEvent) => {
          if (event.repeat) { this.count++ }
        })
        // Triggered when the long press gesture ends.
        .onActionEnd(() => {
          this.count = 0
        })
    )
  }
}
```

![en-us_image_0000001257058425](figures/en-us_image_0000001257058425.gif)
