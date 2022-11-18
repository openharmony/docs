# Grid

The **\<Grid>** component consists of cells formed by rows and columns. You can specify the cells where items are located to form various layouts.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component contains the child component **[\<GridItem>](ts-container-griditem.md)**.


## Interface

Grid(scroller?: Scroller)

**Parameters**
| Name     | Type                                     | Mandatory | Description                              |
| -------- | ---------------------------------------- | --------- | ---------------------------------------- |
| scroller | [Scroller](ts-container-scroll.md#scroller) | No        | Scroller, which can be bound to scrollable components. |

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                          | Type                                     | Description                              |
| ----------------------------- | ---------------------------------------- | ---------------------------------------- |
| columnsTemplate               | string                                   | Number of columns in the current grid layout. If this attribute is not set, one column is used by default.<br>For example, **'1fr 1fr 2fr'** indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. This attribute supports [auto-fill] (#auto-fill description).<br>Default value: **'1fr'** |
| rowsTemplate                  | string                                   | Number of rows in the current grid layout. If this attribute is not set, one row is used by default.<br>For example, **'1fr 1fr 2fr'** indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. This attribute supports [auto-fill] (#auto-fill description).<br>Default value: **'1fr'** |
| columnsGap                    | Length                                   | Gap between columns.<br>Default value: **0** |
| rowsGap                       | Length                                   | Gap between rows.<br>Default value: **0** |
| scrollBar                     | [BarState](ts-appendix-enums.md#barstate) | Scrollbar status.<br>Default value: **BarState.Off** |
| scrollBarColor                | string \| number \| Color                | Color of the scrollbar.                  |
| scrollBarWidth                | string \| number                         | Width of the scrollbar.                  |
| cachedCount                   | number                                   | Number of grid items to be preloaded. For details, see [Minimizing White Blocks During Swiping](../../ui/ts-performance-improvement-recommendation.md#minimizing-white-blocks-during-swiping).<br>Default value: **1** |
| editMode <sup>8+</sup>        | boolean                                  | Whether to enter editing mode. In editing mode, the user can drag the **\<[GridItem](ts-container-griditem.md)>** in the **\<Grid>** component.<br>Default value: **false** |
| layoutDirection<sup>8+</sup>  | [GridDirection](#griddirection8)         | Main axis direction of the grid.<br>Default value: **GridDirection.Row** |
| maxCount<sup>8+</sup>         | number                                   | When **layoutDirection** is **Row** or **RowReverse**: maximum number of rows that can be displayed.<br>When **layoutDirection** is **Column** or **ColumnReverse**: maximum number of columns that can be displayed.<br>Default value: **1** |
| minCount<sup>8+</sup>         | number                                   | When **layoutDirection** is **Row** or **RowReverse**: minimum number of rows that can be displayed.<br>When **layoutDirection** is **Column** or **ColumnReverse**: minimum number of columns that can be displayed.<br>Default value: **1** |
| cellLength<sup>8+</sup>       | number                                   | When **layoutDirection** is **Row** or **RowReverse**: fixed height per row.<br>When **layoutDirection** is **Column** or **ColumnReverse**: fixed width per column.<br>Default value: **0** |
| multiSelectable<sup>8+</sup>  | boolean                                  | Whether to enable mouse frame selection.<br>Default value: **false**<br>- **false**: The mouse frame selection is disabled.<br>- **true**: The mouse frame selection is enabled. |
| supportAnimation<sup>8+</sup> | boolean                                  | Whether to enable animation.<br>Default value: **false** |

## GridDirection<sup>8+</sup>

| Name          | Description                              |
| ------------- | ---------------------------------------- |
| Row           | Horizontal layout, where the child components are arranged from left to right as the main axis runs along the rows. |
| Column        | Vertical layout, where the child components are arranged from top to bottom as the main axis runs down the columns. |
| RowReverse    | Reverse horizontal layout, where the child components are arranged from right to left as the main axis runs along the rows. |
| ColumnReverse | Reverse vertical layout, where the child components are arranged from bottom up as the main axis runs down the columns. |

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| onScrollIndex(event: (first: number) => void) | Triggered when the start item of the grid changes.<br>- **first**: index of the start item of the grid. |
| onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => (() => any) \| void) | Triggered when a grid item starts to be dragged.<br>- **event**: See [ItemDragInfo](#itemdraginfo).<br>- **itemIndex**: index of the dragged element. |
| onItemDragEnter(event: (event: ItemDragInfo) => void) | Triggered when the dragged item enters the drop target of the grid.<br>- **event**: See [ItemDragInfo](#itemdraginfo). |
| onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void) | Triggered when the dragged item moves over the drop target of the grid.<br>- **event**: See [ItemDragInfo](#itemdraginfo).<br>- **itemIndex**: initial position of the dragged item.<br>- **insertIndex**: index of the position to which the dragged item will be dropped. |
| onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void) | Triggered when the dragged item exits the drop target of the grid.<br>- **event**: See [ItemDragInfo](#itemdraginfo).<br>- **itemIndex**: index of the dragged item. |
| onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void) | Triggered when the dragged item is dropped on the drop target of the grid.<br>- **event**: See [ItemDragInfo](#itemdraginfo).<br>- **itemIndex**: initial position of the dragged item.<br>- **insertIndex**: index of the position to which the dragged item will be dropped.<br>- **isSuccess**: whether the dragged item is successfully dropped. |

## Notes About auto-fill

In the **columnsTemplate** and **rowsTemplate** attributes of the **\<Grid>** component, **auto-fill** supports only the following formats:

```css
repeat(auto-fill, track-size)
```

The keywords **repeat** and **auto-fill** are used. **track-size** indicates the row height or column width, which can be in the unit of px, vp, %, or valid digits. The value must contain at least one valid row height or column width.

## ItemDragInfo

| Name | Type   | Description                       |
| ---- | ------ | --------------------------------- |
| x    | number | X-coordinate of the dragged item. |
| y    | number | Y-coordinate of the dragged item. |

## Example

```ts
// xxx.ets
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

![en-us_image_0000001219744183](figures/en-us_image_0000001219744183.gif)

**Example of auto-fill**

```ts
// grid-autofill.ets
@Entry
@Component
struct Index {
  @State gridItemWidth: string = "100%"
  @State gridItemHeight: string = "100%"
  @State gridWidth: string = "100%"
  @State gridHeight: string = "100%"
  @State itemList: string[] = []
  build() {
    Column() {
      Grid() {
        ForEach(this.itemList, (item) => {
          GridItem() {
            Text(item.toString())
              .fontSize(16)
              .width('100%')
              .textAlign(TextAlign.Center)
          }
          .width(this.gridItemWidth)
          .height(this.gridItemHeight)
          .backgroundColor(0xF9CF93)
        }, item => item)
      }
      .columnsGap(1)
      .rowsGap(1)
      .border({ width: 4, color: 0xffdb7093, style: BorderStyle.Dashed, radius: 5 })
      .width(this.gridWidth)
      .height(this.gridHeight)
      .columnsTemplate("15% repeat(auto-fill, 10% 50px 20%) 50px")
      .rowsTemplate("150px repeat(auto-fill, 20% 25%)")
    }.margin(5)
  }

  aboutToAppear() {
    for(var i = 1; i < 50; i++) {
      this.itemList.push(i.toString())
    }
  }
}
```

![grid-autofill](figures/grid-autofill.png)
