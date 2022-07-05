# Row

> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **<Row\>** component lays out child components horizontally.


## Required Permissions

None


## Child Components

Supported


## APIs

Row(value:{space?: Length})

- Parameters
  | Name | Type | Mandatory | Default Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | space | Length | No| 0 | Space between two adjacent child components in the horizontal layout. | 


## Attributes

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| alignItems | VerticalAlign | VerticalAlign.Center | Alignment mode of the child components in the vertical direction. |
| justifyContent8+ | [FlexAlign](ts-container-flex.md) | FlexAlign.Start | Alignment mode of the child components in the horizontal direction. |

- VerticalAlign enums
  | Name | Description | 
  | -------- | -------- |
  | Top | Top aligned. | 
  | Center | Center aligned. This is the default alignment mode. | 
  | Bottom | Bottom aligned. |


## Example

```
@Entry
@Component
struct RowExample {
  build() {
    Column({ space: 5 }) {
      Text('space').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row({ space: 5 }) {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').height(107).border({ width: 1 })

        Text('alignItems(Top)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.alignItems(VerticalAlign.Top).height('15%').border({ width: 1 })

        Text('alignItems(Center)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.alignItems(VerticalAlign.Center).height('15%').border({ width: 1 })

        Text('justifyContent(End)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').border({ width: 1 }).justifyContent(FlexAlign.End)

        Text('justifyContent(Center)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').border({ width: 1 }).justifyContent(FlexAlign.Center)
    }.width('100%')
  }
}
```

![en_image_0000001174422908](figures/row.png)
