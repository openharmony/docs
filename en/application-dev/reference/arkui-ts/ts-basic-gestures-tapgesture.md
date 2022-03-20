# TapGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

TapGesture(options?: { count?: number, fingers?: number })

- Parameters
    | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | count | number | No | 1 | Number of consecutive taps. If this parameter is set to a value less than **1**, the default value will be used.<br/>> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>> If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms. | 
  | fingers | number | No | 1 | Minimum number of fingers to trigger a tap. The value ranges from 1 to 10.<br/>> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>> 1. When multi-finger is configured, if the number of fingers used for tap does not reach the specified number within 300 ms after the first finger is tapped, the gesture fails to be recognized.<br/>> <br/>> 2. Gesture recognition fails if the number of fingers used for tap exceeds the configured number. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onAction((event?: GestureEvent) =&gt; void) | Callback invoked when a tap gesture is recognized. | 


## Example


```
@Entry
@Component
struct TapGestureExample {
  @State value: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Click twice')
      Text(this.value)
    }
    .height(200).width(300).padding(60).border({ width: 1 }).margin(30)
    .gesture(
      TapGesture({ count: 2 })
        .onAction(() => {
          this.value = 'TapGesture onAction'
        })
    )
  }
}
```

![en-us_image_0000001256858417](figures/en-us_image_0000001256858417.gif)
