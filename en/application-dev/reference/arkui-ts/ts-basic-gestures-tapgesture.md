# TapGesture


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## APIs

TapGesture(options?: { count?: number, fingers?: number })

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | count | number | No | 1 | Number&nbsp;of&nbsp;consecutive&nbsp;taps.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;set&nbsp;to&nbsp;a&nbsp;value&nbsp;less&nbsp;than&nbsp;**1**,&nbsp;the&nbsp;default&nbsp;value&nbsp;will&nbsp;be&nbsp;used.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;If&nbsp;multi-tap&nbsp;is&nbsp;configured,&nbsp;the&nbsp;timeout&nbsp;interval&nbsp;between&nbsp;a&nbsp;lift&nbsp;and&nbsp;the&nbsp;next&nbsp;tap&nbsp;is&nbsp;300&nbsp;ms. | 
  | fingers | number | No | 1 | Minimum&nbsp;number&nbsp;of&nbsp;fingers&nbsp;to&nbsp;trigger&nbsp;a&nbsp;tap.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;1&nbsp;to&nbsp;10.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;1.&nbsp;When&nbsp;multi-finger&nbsp;is&nbsp;configured,&nbsp;if&nbsp;the&nbsp;number&nbsp;of&nbsp;fingers&nbsp;used&nbsp;for&nbsp;tap&nbsp;does&nbsp;not&nbsp;reach&nbsp;the&nbsp;specified&nbsp;number&nbsp;within&nbsp;300&nbsp;ms&nbsp;after&nbsp;the&nbsp;first&nbsp;finger&nbsp;is&nbsp;tapped,&nbsp;the&nbsp;gesture&nbsp;fails&nbsp;to&nbsp;be&nbsp;recognized.<br/>>&nbsp;<br/>>&nbsp;2.&nbsp;Gesture&nbsp;recognition&nbsp;fails&nbsp;if&nbsp;the&nbsp;number&nbsp;of&nbsp;fingers&nbsp;used&nbsp;for&nbsp;tap&nbsp;exceeds&nbsp;the&nbsp;configured&nbsp;number. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onAction((event?:&nbsp;GestureEvent)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;a&nbsp;tap&nbsp;gesture&nbsp;is&nbsp;recognized. | 


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
