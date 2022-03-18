# Column


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Column&gt;** component lays out child components vertically.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Column(value:{space?: Length})


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | space | Length | No | 0 | Space&nbsp;between&nbsp;any&nbsp;two&nbsp;adjacent&nbsp;child&nbsp;components&nbsp;in&nbsp;the&nbsp;vertical&nbsp;layout. | 


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| alignItems | HorizontalAlign | HorizontalAlign.Center | Alignment&nbsp;mode&nbsp;of&nbsp;child&nbsp;components&nbsp;in&nbsp;the&nbsp;horizontal&nbsp;direction. |
| justifyContent<sup>8+</sup> | [FlexAlign](ts-container-flex.md) | FlexAlign.Start | Alignment mode of child components in the vertical direction. |

- HorizontalAlign enums
    | Name | Description | 
  | -------- | -------- |
  | Start | Aligned&nbsp;with&nbsp;the&nbsp;start&nbsp;edge&nbsp;in&nbsp;the&nbsp;same&nbsp;direction&nbsp;as&nbsp;the&nbsp;language&nbsp;in&nbsp;use. | 
  | Center | Center&nbsp;alignment.&nbsp;This&nbsp;is&nbsp;the&nbsp;default&nbsp;alignment&nbsp;mode. | 
  | End | Aligned&nbsp;with&nbsp;the&nbsp;end&nbsp;edge&nbsp;in&nbsp;the&nbsp;same&nbsp;direction&nbsp;as&nbsp;the&nbsp;language&nbsp;in&nbsp;use. | 


## Example


```
@Entry
@Component
struct ColumnExample {
  build() {
    Column() {
        Text('space').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Column({ space: 5 }) {
          Column().width('100%').height(30).backgroundColor(0xAFEEEE)
          Column().width('100%').height(30).backgroundColor(0x00FFFF)
        }.width('90%').height(100).border({ width: 1 })

        Text('alignItems(Start)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Column() {
          Column().width('50%').height(30).backgroundColor(0xAFEEEE)
          Column().width('50%').height(30).backgroundColor(0x00FFFF)
        }.alignItems(HorizontalAlign.Start).width('90%').border({ width: 1 })

        Text('alignItems(End)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Column() {
          Column().width('50%').height(30).backgroundColor(0xAFEEEE)
          Column().width('50%').height(30).backgroundColor(0x00FFFF)
        }.alignItems(HorizontalAlign.End).width('90%').border({ width: 1 })

        Text('justifyContent(Center)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Column() {
          Column().width('30%').height(30).backgroundColor(0xAFEEEE)
          Column().width('30%').height(30).backgroundColor(0x00FFFF)
        }.height('15%').border({ width: 1 }).justifyContent(FlexAlign.Center)
        Text('justifyContent(End)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Column() {
          Column().width('30%').height(30).backgroundColor(0xAFEEEE)
          Column().width('30%').height(30).backgroundColor(0x00FFFF)
        }.height('15%').border({ width: 1 }).justifyContent(FlexAlign.End)
    }.width('100%').padding({ top: 5 })
  }
}
```

![](figures/column.png)
