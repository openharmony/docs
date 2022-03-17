# Location


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| align | [Alignment](ts-appendix-enums.md#alignment-enums) | Center | Alignment&nbsp;of&nbsp;the&nbsp;component&nbsp;content.&nbsp;This&nbsp;attribute&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;the&nbsp;values&nbsp;of&nbsp;**width**&nbsp;and&nbsp;**height**&nbsp;are&nbsp;greater&nbsp;than&nbsp;the&nbsp;size&nbsp;of&nbsp;the&nbsp;component&nbsp;content. |
| direction | Direction | Auto | Horizontal&nbsp;layout&nbsp;of&nbsp;the&nbsp;component.&nbsp;For&nbsp;details&nbsp;about&nbsp;the&nbsp;options,&nbsp;see&nbsp;**Direction**&nbsp;enums. |
| position | {<br/>x:&nbsp;Length,<br/>y:&nbsp;Length<br/>} | - | Offset&nbsp;of&nbsp;the&nbsp;component&nbsp;anchor&nbsp;point&nbsp;relative&nbsp;to&nbsp;the&nbsp;top&nbsp;start&nbsp;edge&nbsp;of&nbsp;the&nbsp;parent&nbsp;component.&nbsp;The&nbsp;offset&nbsp;is&nbsp;expressed&nbsp;using&nbsp;absolute&nbsp;values.&nbsp;When&nbsp;laying&nbsp;out&nbsp;components,&nbsp;this&nbsp;attribute&nbsp;does&nbsp;not&nbsp;affect&nbsp;the&nbsp;layout&nbsp;of&nbsp;the&nbsp;parent&nbsp;component.&nbsp;It&nbsp;only&nbsp;adjusts&nbsp;the&nbsp;component&nbsp;position&nbsp;during&nbsp;drawing. |
| markAnchor | {<br/>x:&nbsp;Length,<br/>y:&nbsp;Length<br/>} | {<br/>x:&nbsp;0,<br/>y:&nbsp;0<br/>} | Anchor&nbsp;point&nbsp;of&nbsp;the&nbsp;component&nbsp;for&nbsp;positioning.&nbsp;The&nbsp;top&nbsp;start&nbsp;edge&nbsp;of&nbsp;the&nbsp;component&nbsp;is&nbsp;used&nbsp;as&nbsp;the&nbsp;reference&nbsp;point&nbsp;for&nbsp;offset. |
| offset | {<br/>x:&nbsp;Length,<br/>y:&nbsp;Length<br/>} | {<br/>x:&nbsp;0,<br/>y:&nbsp;0<br/>} | Coordinate&nbsp;offset&nbsp;of&nbsp;the&nbsp;relative&nbsp;layout.&nbsp;This&nbsp;attribute&nbsp;does&nbsp;not&nbsp;affect&nbsp;the&nbsp;layout&nbsp;of&nbsp;the&nbsp;parent&nbsp;component.&nbsp;It&nbsp;only&nbsp;adjusts&nbsp;the&nbsp;component&nbsp;position&nbsp;during&nbsp;drawing. |


- Direction enums
    | Name | Description | 
  | -------- | -------- |
  | Ltr | Components&nbsp;are&nbsp;arranged&nbsp;from&nbsp;left&nbsp;to&nbsp;right. | 
  | Rtl | Components&nbsp;are&nbsp;arranged&nbsp;from&nbsp;right&nbsp;to&nbsp;left. | 
  | Auto | The&nbsp;default&nbsp;layout&nbsp;direction&nbsp;is&nbsp;used. | 


## Example


```
@Entry
@Component
struct PositionExample {
  build() {
    Column() {
      Column({space: 10}) {
        Text('align').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Text('top start')
          .align(Alignment.TopStart)
          .height(50)
          .width('90%')
          .fontSize(16)
          .backgroundColor(0xFFE4C4)

        Text('direction').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Text('1').height(50).width('25%').fontSize(16).backgroundColor(0xF5DEB3)
          Text('2').height(50).width('25%').fontSize(16).backgroundColor(0xD2B48C)
          Text('3').height(50).width('25%').fontSize(16).backgroundColor(0xF5DEB3)
          Text('4').height(50).width('25%').fontSize(16).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .direction(Direction.Rtl)
      }
    }
    .width('100%').margin({ top: 5 }).direction(Direction.Rtl)
  }
}
```

![en-us_image_0000001212218456](figures/en-us_image_0000001212218456.gif)


```
@Entry
@Component
struct PositionExample2 {
  build() {
    Column({ space: 20 }) {
      Text('position').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row({ space: 20 }) {
        Text('1').size({ width: '45%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }) .fontSize(16)
        Text('2 position(25, 15)')
          .size({ width: '60%', height: '30' }).backgroundColor(0xbbb2cb).border({ width: 1 })
          .fontSize(16).align(Alignment.Start)
          .position({ x: 25, y: 15 })
        Text('3').size({ width: '45%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('4 position(50%, 70%)')
          .size({ width: '50%', height: '50' }).backgroundColor(0xbbb2cb).border({ width: 1 }).fontSize(16)
          .position({ x: '50%', y: '70%' })
      }.width('90%').height(100).border({ width: 1, style: BorderStyle.Dashed })

      Text('markAnchor').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Stack({ alignContent: Alignment.TopStart }) {
        Row()
          .size({ width: '100', height: '100' })
          .backgroundColor(0xdeb887)
        Image($r('app.media.ic_health_heart'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 25, y: 25 })
        Image($r('app.media.ic_health_heart'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 25, y: 25 })
          .position({ x: '100%', y: '100%' })
      }.margin({ top: 25 }).border({ width: 1, style: BorderStyle.Dashed })

      Text('offset').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row() {
        Text('1').size({ width: '15%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('2\noffset(15, 15)')
          .size({ width: 120, height: '50' }).backgroundColor(0xbbb2cb).border({ width: 1 })
          .fontSize(16).align(Alignment.Start)
          .offset({ x: 15, y: 15 })
        Text('3').size({ width: '15%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('4\noffset(-10%, 20%)')
          .size({ width: 150, height: '50' }) .backgroundColor(0xbbb2cb).border({ width: 1 }).fontSize(16)
          .offset({ x: '-10%', y: '20%' })
      }.width('90%').height(100).border({ width: 1, style: BorderStyle.Dashed })
    }
    .width('100%').margin({ top: 25 })
  }
}
```

![en-us_image_0000001256858409](figures/en-us_image_0000001256858409.gif)
