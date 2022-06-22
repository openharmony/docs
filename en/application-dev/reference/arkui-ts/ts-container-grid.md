# Grid


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Grid&gt;** component is a two-dimensional layout. The component is divided into rows and columns to form cells. You can specify the cell where an item is located and combine different grids to form various layouts.


## Required Permissions

None


## Child Components

This component contains the child component [<GridItem>](ts-container-griditem.md).


## APIs

Grid()


## Attributes

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| columnsTemplate | string | '1fr' | Number of columns in the current grid layout. If this parameter is not set, one column is used by default. For example, '1fr 1fr 2fr' divides the component into three columns, with four equal parts. The first column occupies one part, the second column occupies one part, and the third column occupies two parts. |
| rowsTemplate | string | '1fr' | Number of rows in the current grid layout. If this parameter is not set, one row is used by default. For example, '1fr 1fr 2fr' divides the component into three rows. The width allowed by the parent component is divided into four equal parts. The first row occupies one part, the second row occupies one part, and the third row occupies two parts. |
| columnsGap | Length | 0 | Spacing between columns. |
| rowsGap | Length | 0 | Spacing between rows. |
| editMode<sup>8+</sup> | boolean | false | Whether to enter editing mode. In editing mode, you can drag the **&lt;[GridItem](ts-container-griditem.md)&gt;** in the **&lt;Gird&gt;** component. |
| layoutDirection<sup>8+</sup> | [LayoutDirection](ts-appendix-enums.md#layoutdirection-enums) | LayoutDirection.Row | Main axis direction of the layout. The options are as follows:- **LayoutDirection.Row**: Horizontal layout, where the child components are arranged in the same direction as the main axis runs along the rows.- **LayoutDirection.Column**: Vertical layout, where the child components are arranged in the same direction as the main axis runs down the columns. |
| maxCount<sup>8+</sup> | number | 1 | Maximum number of rows that can be displayed. |
| minCount<sup>8+</sup> | number | 1 | Minimum number of rows that can be displayed. |
| cellLength<sup>8+</sup> | number | 0 | Fixed height per row. |
| multiSelectable<sup>8+</sup> | boolean | false | Whether to enable mouse frame selection.<br/>- **false**: The mouse frame selection is disabled.<br/>- **true**: The mouse frame selection is disabled. |
| edgeEffection<sup>8+</sup> | EdgeEffect | EdgeEffect.Spring | Edge effect. For details, see **EdgeEffect**. |

- EdgeEffect enums

  | Name   | Description                                                  |
  | ------ | ------------------------------------------------------------ |
  | Spring | Similar to the physical dynamic effect of a spring. After scrolling to the edge, you can continue to scroll for a distance based on the initial speed or by touching the knob of the scrollbar. After you release your hand, the knob is rebounded. |
  | None   | No effect after the scrollbar is moved to the edge.          |

## Events

| Name | Description | 
| -------- | -------- |
| onScrollIndex(first: number) =&gt; void | Triggered when the start item of the grid changes. | 


## Example


```
@Entry
@Component
struct GridExample {
  @State Number: String[] = ['0', '1', '2', '3', '4']

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
            }
          }, day => day)
        }, day => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)

      Text('scroll').fontColor(0xCCCCCC).fontSize(9).width('90%')
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height(80)
                .textAlign(TextAlign.Center)
            }
          }, day => day)
        }, day => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .onScrollIndex((first: number) => {
        console.info(first.toString())
      })
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218434](figures/en-us_image_0000001212218434.gif)

