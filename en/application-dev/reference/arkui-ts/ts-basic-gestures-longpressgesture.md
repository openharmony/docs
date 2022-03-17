# LongPressGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

LongPressGesture(options?: { fingers?: number, repeat?: boolean, duration?: number })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | fingers | number | No | 1 | Minimum&nbsp;number&nbsp;of&nbsp;fingers&nbsp;to&nbsp;trigger&nbsp;a&nbsp;long&nbsp;press&nbsp;gesture.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;1&nbsp;to&nbsp;10. | 
  | repeat | boolean | No | false | Whether&nbsp;to&nbsp;continuously&nbsp;trigger&nbsp;the&nbsp;event&nbsp;callback. | 
  | duration | number | No | 500 | Minimum&nbsp;hold-down&nbsp;time,&nbsp;in&nbsp;ms. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onAction((event?:&nbsp;LongPressGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;long&nbsp;press&nbsp;gesture&nbsp;is&nbsp;recognized. | 
| onActionEnd((event?:&nbsp;LongPressGestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;finger&nbsp;used&nbsp;for&nbsp;a&nbsp;long&nbsp;press&nbsp;gesture&nbsp;is&nbsp;lift. | 
| onActionCancel(event:&nbsp;()&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;tap&nbsp;cancellation&nbsp;event&nbsp;is&nbsp;received&nbsp;after&nbsp;a&nbsp;long&nbsp;press&nbsp;gesture&nbsp;is&nbsp;recognized. | 

- LongPressGestureEvent<sup>8+</sup> attributes
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | repeat | boolean | Whether&nbsp;the&nbsp;event&nbsp;is&nbsp;repeated. | 


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
        .onAction((event: LongPressGestureEvent) => {
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
