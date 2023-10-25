# GridItem

The **\<GridItem>** component provides a single item in a grid.

>  **NOTE**
>
>  - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>  - This component can be used only as a child of [\<Grid>](ts-container-grid.md).


## Child Components

Supported

## APIs

### GridItem<sup>11+</sup>

GridItem(value?: GridItemOptions)

**Parameters**

| Name| Type                                     | Mandatory| Description                                                    |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [GridItemOptions](#griditemoptions11) | No  | Value of the grid item, containing the **style** parameter of the **GridItemStyle** enum type.|

### GridItem<sup>(deprecated)</sup>

GridItem()

This API is deprecated since API version 11. You are advised to use **GridItem<sup>11+</sup>** instead.


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| rowStart | number | Start row number of the component.|
| rowEnd | number | End row number of the component.|
| columnStart | number | Start column number of the component.|
| columnEnd | number | End column number of the component.|
| forceRebuild<sup>(deprecated)</sup> | boolean | Whether to re-create the component when it is being built.<br>This API is deprecated since API version 9. Whether to re-create the component is automatically determined based on the component attributes and child component changes. No manual configuration is required.<br>Default value: **false**|
| selectable<sup>8+</sup> | boolean | Whether the grid item is selectable by the mouse.<br>**NOTE**<br>This attribute takes effect only when mouse frame selection is enabled for the parent **\<Grid>** container.<br>Default value: **true**|
| selected<sup>10+</sup> | boolean | Whether the grid item is selected. This attribute supports [$$](../../quick-start/arkts-two-way-sync.md) for two-way binding of variables.<br>**NOTE**<br>This attribute must be used before the [style for the selected state](./ts-universal-attributes-polymorphic-style.md) is set. Otherwise, the style settings will not take effect.<br>Default value: **false**|

>  **NOTE**
>
>  Rules for setting **rowStart**, **rowEnd**, **columnStart**, and **columnEnd**:
>
>  The valid value range of **rowStart** and **rowEnd** is 0 to the total number of rows minus 1. The valid value range of **columnStart** and **columnEnd** is 0 to the total number of columns minus 1.
>
>  Settings outside of the valid ranges do not take effect.
>
>  In the grid that has both **columnTemplate** and **rowTemplate** set, grid items that have **rowStart**/**rowEnd** or **columnStart**/**columnEnd** set are laid out in a row-by-row then column-by-column manner.
>
>  In the grid that has only **columnTemplate** set, grid items that have **columnStart**/**columnEnd** set are laid out in the specific columns. If there are already grid items in those columns, the grid items will be laid out in another row.
>
>  In the grid that has only **rowTemplate** set, grid items that have **rowStart**/**rowEnd** set are laid out in the specific rows. If there are already grid items in those rows, the grid items will be laid out in another column.
>
>  In the grid that has only **columnTemplate** set, grid items whose row or column number settings are invalid are laid out in a row-by-row then column-by-column manner.
>
>  In the grid that has neither **columnTemplate** nor **rowTemplate** set, the row and column number attributes do not work.

## GridItemOptions<sup>11+</sup>

| Name | Type                                 | Mandatory| Description                                                        |
| ----- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| style | [GridItemStyle](#griditemstyle11) | No  | Style of the grid item.<br>Default value: **GridItemStyle.NONE**<br>If this parameter is set to **GridItemStyle.NONE**, no style is applied.<br>If this parameter is set to **GridItemStyle.PLAIN**, the grid item is in hover or press style depending on the state.|

## GridItemStyle<sup>11+</sup>

| Name | Description                    |
| ----- | ------------------------ |
| NONE  | No style.                |
| PLAIN | Hover or press style.|

> **NOTE**
>
> To set the focused style for the grid item, the grid container must have paddings of greater than 4 vp for accommodating the focus frame of the grid item.


## Events

| Name| Description|
| -------- | -------- |
| onSelect(event: (isSelected: boolean) =&gt; void)<sup>8+</sup> | Triggered when the selected state of the grid item changes.<br>**isSelected**: returns **true** if the grid item is being selected by the mouse; returns **false** otherwise.|

## Example

### Example 1

```ts
// xxx.ets
@Entry
@Component
struct GridItemExample {
  @State numbers: string[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]

  build() {
    Column() {
      Grid() {
        GridItem() {
          Text('4')
            .fontSize(16)
            .backgroundColor(0xFAEEE0)
            .width('100%')
            .height('100%')
            .textAlign(TextAlign.Center)
        }.rowStart(1).rowEnd(2).columnStart(1).columnEnd(2) // Set valid row and column numbers.

        ForEach(this.numbers, (item: string) => {
          GridItem() {
            Text(item)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height('100%')
              .textAlign(TextAlign.Center)
          }
        }, (item: string) => item)

        GridItem() {
          Text('5')
            .fontSize(16)
            .backgroundColor(0xDBD0C0)
            .width('100%')
            .height('100%')
            .textAlign(TextAlign.Center)
        }.columnStart(1).columnEnd(4) // Set only the column numbers. The layout does not start from the first column.
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .width('90%').height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001174582870](figures/en-us_image_0000001174582870.gif)

### Example 2

This example shows how to use **GridItemOptions**.

```ts
// xxx.ets
@Entry
@Component
struct GridItemExample {
  @State Number: String[] = ['0', '1', '2']

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem({style:GridItemStyle.NONE}) {
              Text(day)
                .fontSize(16)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
                .focusable(true)
            }
            .backgroundColor(0xF9CF93)
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr')
      .columnsGap(4)
      .rowsGap(4)
      .width('60%')
      .backgroundColor(0xFAEEE0)
      .height(150)
      .padding('4vp')

      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem({style:GridItemStyle.PLAIN}) {
              Text(day)
                .fontSize(16)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
                .focusable(true)
            }
            .backgroundColor(0xF9CF93)
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr')
      .columnsGap(4)
      .rowsGap(4)
      .width('60%')
      .backgroundColor(0xFAEEE0)
      .height(150)
      .padding('4vp')
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_griditem_griditemoptions](figures/en-us_image_griditem_griditemoptions.png)
