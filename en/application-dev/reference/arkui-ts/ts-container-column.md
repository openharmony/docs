# Column


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Column&gt;** component lays out child components vertically.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Column(value:{space?: Length})


- Parameters
    | Name  | Type   | Mandatory | Default Value | Description                              |
    | ----- | ------ | --------- | ------------- | ---------------------------------------- |
    | space | Length | No        | 0             | Space between any two adjacent child components in the vertical layout. |


## Attributes

| Name                        | Type                              | Default Value          | Description                              |
| --------------------------- | --------------------------------- | ---------------------- | ---------------------------------------- |
| alignItems                  | HorizontalAlign                   | HorizontalAlign.Center | Alignment mode of child components in the horizontal direction. |
| justifyContent<sup>8+</sup> | [FlexAlign](ts-container-flex.md) | FlexAlign.Start        | Alignment mode of child components in the vertical direction. |

- HorizontalAlign enums
    | Name   | Description                              |
    | ------ | ---------------------------------------- |
    | Start  | Aligned with the start edge in the same direction as the language in use. |
    | Center | Aligned to the center. This is the default alignment mode. |
    | End    | Aligned with the end edge in the same direction as the language in use. |


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

![](figures/Column.png)
