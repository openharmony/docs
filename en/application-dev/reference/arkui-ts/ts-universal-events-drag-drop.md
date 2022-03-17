# Drag/Drop Event


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


| Name | Bubble&nbsp;Supported | Description |
| -------- | -------- | -------- |
| onDragStart(callback:&nbsp;(event:&nbsp;[DragEvent](#DragEvent),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;\|[Custom Builder](../../ui/ts-types.md)) | No | Triggered&nbsp;when&nbsp;the&nbsp;component&nbsp;bound&nbsp;to&nbsp;the&nbsp;event&nbsp;is&nbsp;dragged&nbsp;for&nbsp;the&nbsp;first&nbsp;time.<br/>-**event**:&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event,&nbsp;including&nbsp;the&nbsp;coordinates&nbsp;of&nbsp;the&nbsp;item&nbsp;that&nbsp;is&nbsp;being&nbsp;dragged.<br/>-**extraParams**:&nbsp;additional&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event.&nbsp;For&nbsp;details,&nbsp;see&nbsp;extraParam.<br/>Return&nbsp;value:&nbsp;object&nbsp;being&nbsp;dragged,&nbsp;which&nbsp;is&nbsp;used&nbsp;for&nbsp;prompts&nbsp;displayed&nbsp;when&nbsp;the&nbsp;object&nbsp;is&nbsp;dragged.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;-&nbsp;A&nbsp;drag&nbsp;event&nbsp;can&nbsp;be&nbsp;triggered&nbsp;by&nbsp;a&nbsp;150&nbsp;ms&nbsp;long&nbsp;press.<br/>>&nbsp;<br/>>&nbsp;-&nbsp;If&nbsp;the&nbsp;duration&nbsp;of&nbsp;a&nbsp;long-press&nbsp;gesture&nbsp;is&nbsp;set&nbsp;to&nbsp;less&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;150&nbsp;ms,&nbsp;the&nbsp;callback&nbsp;for&nbsp;the&nbsp;long-press&nbsp;gesture&nbsp;takes&nbsp;precedence.&nbsp;Otherwise,&nbsp;the&nbsp;callback&nbsp;for&nbsp;the&nbsp;drag&nbsp;event&nbsp;takes&nbsp;precedence. |
| onDragEnter(callback:&nbsp;(event:&nbsp;[DragEvent](#DragEvent),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | No | Triggered&nbsp;when&nbsp;the&nbsp;dragged&nbsp;item&nbsp;enters&nbsp;a&nbsp;valid&nbsp;drop&nbsp;target.<br/>-**event**:&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event,&nbsp;including&nbsp;the&nbsp;coordinates&nbsp;of&nbsp;the&nbsp;item&nbsp;that&nbsp;is&nbsp;being&nbsp;dragged.<br/>-**extraParams**:&nbsp;additional&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event.&nbsp;For&nbsp;details,&nbsp;see&nbsp;extraParam.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;event&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;the&nbsp;**onDrop**&nbsp;event&nbsp;is&nbsp;listened&nbsp;to. |
| onDragMove(callback:&nbsp;(event:&nbsp;[DragEvent](#DragEvent),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | No | Triggered&nbsp;when&nbsp;the&nbsp;dragged&nbsp;item&nbsp;moves&nbsp;in&nbsp;a&nbsp;valid&nbsp;drop&nbsp;target.<br/>-**event**:&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event,&nbsp;including&nbsp;the&nbsp;coordinates&nbsp;of&nbsp;the&nbsp;item&nbsp;that&nbsp;is&nbsp;being&nbsp;dragged.<br/>-**extraParams**:&nbsp;additional&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event.&nbsp;For&nbsp;details,&nbsp;see&nbsp;extraParam.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;event&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;the&nbsp;**onDrop**&nbsp;event&nbsp;is&nbsp;listened&nbsp;to. |
| onDragLeave(callback:&nbsp;(event:&nbsp;[DragEvent](#DragEvent),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | No | Triggered&nbsp;when&nbsp;the&nbsp;dragged&nbsp;item&nbsp;leaves&nbsp;a&nbsp;valid&nbsp;drop&nbsp;target.<br/>-**event**:&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event,&nbsp;including&nbsp;the&nbsp;coordinates&nbsp;of&nbsp;the&nbsp;item&nbsp;that&nbsp;is&nbsp;being&nbsp;dragged.<br/>-**extraParams**:&nbsp;additional&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event.&nbsp;For&nbsp;details,&nbsp;see&nbsp;extraParam.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;event&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;the&nbsp;**onDrop**&nbsp;event&nbsp;is&nbsp;listened&nbsp;to. |
| onDrop(callback:&nbsp;(event:[DragEvent](#DragEvent),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | No | Triggered&nbsp;when&nbsp;the&nbsp;dragged&nbsp;item&nbsp;is&nbsp;dropped&nbsp;on&nbsp;a&nbsp;valid&nbsp;drop&nbsp;target.<br/>-**event**:&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event,&nbsp;including&nbsp;the&nbsp;coordinates&nbsp;of&nbsp;the&nbsp;item&nbsp;that&nbsp;is&nbsp;being&nbsp;dragged.<br/>-**extraParams**:&nbsp;additional&nbsp;information&nbsp;about&nbsp;the&nbsp;drag&nbsp;event.&nbsp;For&nbsp;details,&nbsp;see&nbsp;extraParam. |


- extraParam
  Returns additional information required for dragging an item.

    **extraParam** is a string converted from a JSON object. You can obtain the following attributes using the JSON object converted from **Json.parse**.
    | Name | Type | Description | 
  | -------- | -------- | -------- |
  | selectedIndex | number | Index&nbsp;of&nbsp;the&nbsp;dragged&nbsp;item&nbsp;in&nbsp;the&nbsp;parent&nbsp;container.&nbsp;The&nbsp;value&nbsp;of&nbsp;**selectedindex**&nbsp;starts&nbsp;from&nbsp;**0**.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;attribute&nbsp;is&nbsp;valid&nbsp;only&nbsp;in&nbsp;the&nbsp;**ListItem**&nbsp;component. | 
  | insertIndex | number | Index&nbsp;of&nbsp;the&nbsp;element&nbsp;into&nbsp;which&nbsp;the&nbsp;dragged&nbsp;item&nbsp;is&nbsp;dropped&nbsp;in&nbsp;the&nbsp;**List**&nbsp;component.&nbsp;The&nbsp;value&nbsp;of&nbsp;**insertIndex**&nbsp;starts&nbsp;from&nbsp;**0**.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;attribute&nbsp;is&nbsp;valid&nbsp;only&nbsp;in&nbsp;the&nbsp;drag&nbsp;event&nbsp;of&nbsp;the&nbsp;**List**&nbsp;component. | 


### DragEvent

- APIs
    | Name | Return&nbsp;Value&nbsp;Type | Description | 
  | -------- | -------- | -------- |
  | getX() | number | X-coordinate&nbsp;of&nbsp;the&nbsp;item&nbsp;that&nbsp;is&nbsp;being&nbsp;dragged,&nbsp;in&nbsp;vp. | 
  | getY() | number | Y-coordinate&nbsp;of&nbsp;the&nbsp;item&nbsp;that&nbsp;is&nbsp;being&nbsp;dragged,&nbsp;in&nbsp;vp. | 


## Example


```
@Entry
@Component
struct DragExample {
  @State numbers: string[] = ['one', 'two', 'three', 'four', 'five', 'six']
  @State text: string = ''
  @State bool: boolean = false
  @State bool1: boolean = false
  @State size: string = ''
  @State appleVisible: Visibility = Visibility.Visible
  @State orangeVisible: Visibility = Visibility.Visible
  @State bananaVisible: Visibility = Visibility.Visible
  @State select: number = 0
  @State currentIndex: number = 0

  @Builder pixelMapBuilder() {
    Column() {
      Text(this.text)
        .width('50%').height(60).fontSize(16).borderRadius(10)
        .textAlign(TextAlign.Center).backgroundColor(Color.Yellow)
    }
  }

  build() {
    Column() {
      Text('There are three Text elements here')
        .fontSize(12).fontColor(0xCCCCCC).width('90%')
        .textAlign(TextAlign.Start).margin(5)
      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceAround }) {
        Text('apple').width('25%').height(35).fontSize(16)
          .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          .visibility(this.appleVisible)
          .onDragStart(() => {
            this.bool = true
            this.text = 'apple'
            this.appleVisible = Visibility.Hidden
            return this.pixelMapBuilder
          })
        Text('orange').width('25%').height(35).fontSize(16)
          .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          .visibility(this.orangeVisible)
          .onDragStart(() => {
            this.bool = true
            this.text = 'orange'
            this.orangeVisible = Visibility.Hidden
            return this.pixelMapBuilder
          })
        Text('banana').width('25%').height(35).fontSize(16)
          .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          .visibility(this.bananaVisible)
          .onDragStart((event: DragEvent, extraParams: string) => {
            console.log('Text onDragStarts, ' + extraParams)
            this.bool = true
            this.text = 'banana'
            this.bananaVisible = Visibility.Hidden
            return this.pixelMapBuilder
          })
      }.border({ width: 1 }).width('90%').padding({ top: 10, bottom: 10 }).margin(10)

      Text('This is a List element').fontSize(12)
        .fontColor(0xCCCCCC).width('90%')
        .textAlign(TextAlign.Start).margin(15)
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.numbers, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(80).fontSize(16).borderRadius(10)
              .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          }
          .onDragStart((event: DragEvent, extraParams: string) => {
            console.log('ListItem onDragStarts, ' + extraParams)
            var jsonString = JSON.parse(extraParams)
            this.bool1 = true
            this.text = this.numbers[jsonString.selectedIndex]
            this.select = jsonString.selectedIndex
            return this.pixelMapBuilder
          })
        }, item => item)
      }
      .editMode(true)
      .height('50%').width('90%').border({ width: 1 })
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onDragEnter((event: DragEvent, extraParams: string) => {
        console.log('List onDragEnter, ' + extraParams)
      })
      .onDragMove((event: DragEvent, extraParams: string) => {
        console.log('List onDragMove, ' + extraParams)
      })
      .onDragLeave((event: DragEvent, extraParams: string) => {
        console.log('List onDragLeave, ' + extraParams)
      })
      .onDrop((event: DragEvent, extraParams: string) => {
        var jsonString = JSON.parse(extraParams)
        if (this.bool) {
          this.numbers.splice(jsonString.insertIndex, 0, this.text)
          this.bool = false
        } else if (this.bool1) {
          this.numbers.splice(jsonString.selectedIndex, 1)
          this.numbers.splice(jsonString.insertIndex, 0, this.text)
          this.bool = false
          this.bool1 = false
        }
      })
    }.width('100%').height('100%').padding({ top: 20 }).margin({ top: 20 })
  }
}
```

![en-us_image_0000001212218450](figures/en-us_image_0000001212218450.gif)
