# Grid


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Grid&gt;** component is a two-dimensional layout. The component is divided into rows and columns, to form cells. You can specify the cell where an item is located and combine different grids to form various layouts.


## Required Permissions

None


## Child Components

This component contains the child component [<GridItem>](ts-container-griditem.md).


## APIs

Grid()


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| columnsTemplate | string | '1fr' | Number&nbsp;of&nbsp;columns&nbsp;in&nbsp;the&nbsp;current&nbsp;grid&nbsp;layout.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;one&nbsp;column&nbsp;is&nbsp;used&nbsp;by&nbsp;default.&nbsp;For&nbsp;example,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'&nbsp;divides&nbsp;the&nbsp;component&nbsp;into&nbsp;three&nbsp;columns,&nbsp;with&nbsp;four&nbsp;equal&nbsp;parts.&nbsp;The&nbsp;first&nbsp;column&nbsp;occupies&nbsp;one&nbsp;part,&nbsp;the&nbsp;second&nbsp;column&nbsp;occupies&nbsp;one&nbsp;part,&nbsp;and&nbsp;the&nbsp;third&nbsp;column&nbsp;occupies&nbsp;two&nbsp;parts. |
| rowsTemplate | string | '1fr' | Number&nbsp;of&nbsp;rows&nbsp;in&nbsp;the&nbsp;current&nbsp;grid&nbsp;layout.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;one&nbsp;row&nbsp;is&nbsp;used&nbsp;by&nbsp;default.&nbsp;For&nbsp;example,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'&nbsp;divides&nbsp;the&nbsp;component&nbsp;into&nbsp;three&nbsp;rows.&nbsp;The&nbsp;width&nbsp;allowed&nbsp;by&nbsp;the&nbsp;parent&nbsp;component&nbsp;is&nbsp;divided&nbsp;into&nbsp;four&nbsp;equal&nbsp;parts.&nbsp;The&nbsp;first&nbsp;row&nbsp;occupies&nbsp;one&nbsp;part,&nbsp;the&nbsp;second&nbsp;row&nbsp;occupies&nbsp;one&nbsp;part,&nbsp;and&nbsp;the&nbsp;third&nbsp;row&nbsp;occupies&nbsp;two&nbsp;parts. |
| columnsGap | Length | 0 | Spacing&nbsp;between&nbsp;columns. |
| rowsGap | Length | 0 | Spacing&nbsp;between&nbsp;rows. |
| editMode<sup>8+</sup> | boolean | false | Whether&nbsp;to&nbsp;enter&nbsp;editing&nbsp;mode.&nbsp;In&nbsp;editing&nbsp;mode,&nbsp;you&nbsp;can&nbsp;drag&nbsp;the&nbsp;**&lt;[GridItem](ts-container-griditem.md)&gt;**&nbsp;in&nbsp;the&nbsp;**&lt;Gird&gt;**&nbsp;component. |
| layoutDirection<sup>8+</sup> | [LayoutDirection](ts-appendix-enums.md#layoutdirection-enums) | LayoutDirection.Row | Main axis direction of the layout. The options are as follows:- **LayoutDirection.Row**: Horizontal layout, where the child components are arranged in the same direction as the main axis runs along the rows.- **LayoutDirection.Column**: Vertical layout, where the child components are arranged in the same direction as the main axis runs down the columns. |
| maxCount<sup>8+</sup> | number | 1 | Maximum&nbsp;number&nbsp;of&nbsp;rows&nbsp;that&nbsp;can&nbsp;be&nbsp;displayed. |
| minCount<sup>8+</sup> | number | 1 | Minimum&nbsp;number&nbsp;of&nbsp;rows&nbsp;that&nbsp;can&nbsp;be&nbsp;displayed. |
| cellLength<sup>8+</sup> | number | 0 | Fixed&nbsp;height&nbsp;per&nbsp;row. |
| multiSelectable<sup>8+</sup> | boolean | false | Whether&nbsp;to&nbsp;enable&nbsp;mouse&nbsp;frame&nbsp;selection.<br/>-&nbsp;**false**:&nbsp;The&nbsp;mouse&nbsp;frame&nbsp;selection&nbsp;is&nbsp;disabled.<br/>-&nbsp;**true**:&nbsp;The&nbsp;mouse&nbsp;frame&nbsp;selection&nbsp;is&nbsp;disabled. |
| edgeEffection<sup>8+</sup> | EdgeEffect | EdgeEffect.Spring | Edge effect. For details, see **EdgeEffect**. |

- EdgeEffect enums

  | Name   | Description                                                  |
  | ------ | ------------------------------------------------------------ |
  | Spring | Similar to the physical dynamic effect of a spring. After scrolling to the edge, you can continue to scroll for a distance based on the initial speed or by touching the knob of the scrollbar. After you release your hand, the knob is rebounded. |
  | None   | No effect after the scrollbar is moved to the edge.          |

## Events

  | Name | Description | 
| -------- | -------- |
| onScrollIndex(first:&nbsp;number)&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;start&nbsp;item&nbsp;of&nbsp;the&nbsp;grid&nbsp;changes. | 


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

