# Click Event


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

  | Name | Bubble&nbsp;Supported | Description | 
| -------- | -------- | -------- |
| onClick(callback:&nbsp;(event?:&nbsp;ClickEvent)&nbsp;=&gt;&nbsp;void) | No | Called&nbsp;when&nbsp;a&nbsp;click&nbsp;event&nbsp;occurs.&nbsp;For&nbsp;details&nbsp;about&nbsp;the&nbsp;event&nbsp;parameters,&nbsp;see&nbsp;[ClickEvent](#clickevent). | 


### ClickEvent

  | Name | Type | Description | 
| -------- | -------- | -------- |
| screenX | number | X&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;click&nbsp;relative&nbsp;to&nbsp;the&nbsp;left&nbsp;edge&nbsp;of&nbsp;the&nbsp;screen. | 
| screenY | number | Y&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;click&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;edge&nbsp;of&nbsp;the&nbsp;screen. | 
| x | number | X&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;click&nbsp;relative&nbsp;to&nbsp;the&nbsp;left&nbsp;edge&nbsp;of&nbsp;the&nbsp;component&nbsp;being&nbsp;clicked. | 
| y | number | Y&nbsp;coordinate&nbsp;of&nbsp;the&nbsp;click&nbsp;relative&nbsp;to&nbsp;the&nbsp;upper&nbsp;edge&nbsp;of&nbsp;the&nbsp;component&nbsp;being&nbsp;clicked. | 
| target<sup>8+</sup> | EventTarget | Target&nbsp;element&nbsp;that&nbsp;is&nbsp;clicked. | 
| timestamp | number | Timestamp&nbsp;of&nbsp;the&nbsp;event. | 


## Example


```
@Entry
@Component
struct ClickExample {
  @State text: string = ''

  build() {
    Column() {
      Button('Click').backgroundColor(0x2788D9).width(100).height(40)
        .onClick((event: ClickEvent) => {
          console.info(this.text = 'Click Point:' + '\n  screenX:' + event.screenX + '\n  screenY:' + event.screenY
          + '\n  x:' + event.x + '\n  y:' + event.y + '\ntarget:' + '\n  component globalPos:('
          + event.target.area.globalPos.x + ',' + event.target.area.globalPos.y + ')\n  width:'
          + event.target.area.width + '\n  height:' + event.target.area.height)
        })
      Text(this.text).padding(15)
    }.height(350).width('100%').padding(10)
  }
}
```


![en-us_image_0000001256858383](figures/en-us_image_0000001256858383.gif)
