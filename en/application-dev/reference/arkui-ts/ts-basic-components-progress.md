# Progress


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Progress&gt;** component is used to provide a progress bar that displays the progress of content loading or an operation.


## Required Permissions

None


## Child Components

None


## APIs

Progress(value: {value: number, total?: number, style?: ProgressStyle})

Creates a progress bar.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Current&nbsp;progress. | 
  | total | number | No | 100 | Total&nbsp;progress. | 
  | style | ProgressStyle | No | ProgressStyle.Linear | Style&nbsp;of&nbsp;the&nbsp;progress&nbsp;bar. | 


- ProgressStyle enums
    | Name | Description | 
  | -------- | -------- |
  | Linear | Linear&nbsp;style. | 
  | Ring<sup>8+</sup> | Ring&nbsp;style&nbsp;without&nbsp;scale.&nbsp;The&nbsp;ring&nbsp;fills&nbsp;up&nbsp;as&nbsp;the&nbsp;progress&nbsp;increases. | 
  | Eclipse | Eclipse&nbsp;style,&nbsp;which&nbsp;visualizes&nbsp;the&nbsp;progress&nbsp;in&nbsp;a&nbsp;way&nbsp;similar&nbsp;to&nbsp;the&nbsp;moon&nbsp;waxing&nbsp;from&nbsp;new&nbsp;to&nbsp;full. | 
  | ScaleRing<sup>8+</sup> | Ring&nbsp;style&nbsp;with&nbsp;scale,&nbsp;which&nbsp;is&nbsp;similar&nbsp;to&nbsp;the&nbsp;clock&nbsp;scale&nbsp;style. | 
  | Capsule<sup>8+</sup> | Capsule&nbsp;style.&nbsp;At&nbsp;both&nbsp;ends,&nbsp;the&nbsp;progress&nbsp;bar&nbsp;changes&nbsp;from&nbsp;an&nbsp;arc&nbsp;to&nbsp;a&nbsp;straight&nbsp;line&nbsp;and&nbsp;from&nbsp;a&nbsp;straight&nbsp;line&nbsp;to&nbsp;an&nbsp;arc.&nbsp;In&nbsp;the&nbsp;middle&nbsp;part&nbsp;of&nbsp;the&nbsp;capsule,&nbsp;the&nbsp;progress&nbsp;bar&nbsp;moves&nbsp;to&nbsp;the&nbsp;right. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| value | number | - | Current&nbsp;progress. | 
| color | Color | - | Background&nbsp;color&nbsp;of&nbsp;the&nbsp;progress&nbsp;bar. | 
| style8+ | {<br/>strokeWidth?&nbsp;:&nbsp;Length,<br/>scaleCount?&nbsp;:&nbsp;number,<br/>scaleWidth?&nbsp;:&nbsp;Length<br/>} | - | Component&nbsp;style.<br/>-&nbsp;**strokeWidth**:&nbsp;width&nbsp;of&nbsp;the&nbsp;progress&nbsp;bar.<br/>-&nbsp;**scaleCount**:&nbsp;scale&nbsp;count&nbsp;of&nbsp;the&nbsp;circular&nbsp;progress&nbsp;bar.<br/>-&nbsp;**scaleWidth**:&nbsp;scale&nbsp;width&nbsp;of&nbsp;the&nbsp;circular&nbsp;progress&nbsp;bar.<br/>If&nbsp;the&nbsp;scale&nbsp;thickness&nbsp;is&nbsp;greater&nbsp;than&nbsp;the&nbsp;progress&nbsp;bar&nbsp;width,&nbsp;the&nbsp;default&nbsp;scale&nbsp;thickness&nbsp;is&nbsp;used. | 


## Example

  
```
@Entry
@Component
struct ProgressExample {
  build() {
    Column({ space: 15 }) {
      Text('Linear Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 10, style: ProgressStyle.Linear }).width(200)
      Progress({ value: 20, total: 150, style: ProgressStyle.Linear }).color(Color.Grey).value(50).width(200)

      Text('Eclipse Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, style: ProgressStyle.Eclipse }).width(100)
        Progress({ value: 20, total: 150, style: ProgressStyle.Eclipse }).color(Color.Grey).value(50).width(100)
      }

      Text('ScaleRing Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, style: ProgressStyle.ScaleRing }).width(100)
        Progress({ value: 20, total: 150, style: ProgressStyle.ScaleRing })
          .color(Color.Grey).value(50).width(100)
          .style({ strokeWidth: 15, scaleCount: 15, scaleWidth: 5 })
      }

      Text('Ring Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, style: ProgressStyle.Ring }).width(100)
        Progress({ value: 20, total: 150, style: ProgressStyle.Ring })
          .color(Color.Grey).value(50).width(100)
          .style({ strokeWidth: 20, scaleCount: 30, scaleWidth: 20 })
      }

      Text('Capsule Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, style: ProgressStyle.Capsule }).width(100)
        Progress({ value: 20, total: 150, style: ProgressStyle.Capsule }).color(Color.Grey).value(50).width(100)
      }
    }.width('100%').margin({ top: 30 })
  }
}
```

![en-us_image_0000001212378432](figures/en-us_image_0000001212378432.gif)
