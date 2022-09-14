# Grid

>  **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

网格容器，由“行”和“列”分割的单元格所组成，通过指定“项目”所在的单元格做出各种各样的布局。




## 子组件

包含[GridItem](ts-container-griditem.md)子组件。


## 接口

Grid(scroller?: Scroller)

**参数：**
| 参数名       | 参数类型                                     | 必填   | 默认值            | 参数描述                    |
| --------- | ---------------------------------------- | ---- | --------------------------- | ----------------------- |
| scroller  | [Scroller](ts-container-scroll.md#scroller) | 否    | -          | 可滚动组件的控制器。用于与可滚动组件进行绑定。 |


## 属性

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| columnsTemplate | string | '1fr' | 用于设置当前网格布局列的数量，不设置时默认1列&nbsp;示例,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'&nbsp;分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份。 |
| rowsTemplate | string | '1fr' | 用于设置当前网格布局行的数量，不设置时默认1行&nbsp;示例,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。 |
| columnsGap | Length | 0 | 用于设置列与列的间距。 |
| rowsGap | Length | 0 | 用于设置行与行的间距。 |
| scrollBar      | [BarState](ts-appendix-enums.md#barstate) | BarState.Off     | 设置滚动条状态。  |
| scrollBarColor | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;[Color](ts-appendix-enums.md#color)             | -                        | 设置滚动条的颜色。 |
| scrollBarWidth | number&nbsp;\|&nbsp;string                                | -                        | 设置滚动条的宽度。 |
| cachedCount | number                                   | 1                        | 设置预加载的GridItem的数量。 |
| editMode <sup>8+</sup>                   | boolean | false | 是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部[GridItem](ts-container-griditem.md)。 |
| layoutDirection<sup>8+</sup>             | [GridDirection](#griddirection8枚举说明)  | GridDirection.Row     | 设置布局的主轴方向。 |
| maxCount<sup>8+</sup> | number  | 1     | 当layoutDirection是Row/RowReverse时，表示可显示的最大行数<br/>当layoutDirection是Column/ColumnReverse时，表示可显示的最大列数。 |
| minCount<sup>8+</sup> | number  | 1     | 当layoutDirection是Row/RowReverse时，表示可显示的最小行数。<br/>当layoutDirection是Column/ColumnReverse时，表示可显示的最小列数。 |
| cellLength<sup>8+</sup> | number  | 0     | 当layoutDirection是Row/RowReverse时，表示一行的高度。<br/>当layoutDirection是Column/ColumnReverse时，表示一列的宽度。 |
| multiSelectable<sup>8+</sup> | boolean | false | 是否开启鼠标框选。<br/>-&nbsp;false：关闭框选。<br/>-&nbsp;true：开启框选。 |
| supportAnimation<sup>8+</sup> | boolean | false | 是否支持动画。 |

## GridDirection<sup>8+</sup>枚举说明

| 名称   | 描述                                   |
  | ------ | -------------------------------------- |
| Row  | 网格元素按照行方向排列。 |
| Column | 网格元素按照列方向排列。 |
| RowReverse    | 网格元素按照行逆序方向排列。 |
| ColumnReverse   | 网格元素按照列逆序方向排列。 |

## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onScrollIndex(event: (first: number) => void) | 当前网格显示的起始位置item发生变化时触发，返回值为当前显示的网格起始位置的索引值。 |
| onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => (() => any) \| void) | 开始拖拽网格元素时触发，返回值event见[ItemDragInfo对象说明](#itemdraginfo对象说明)，itemIndex为被拖拽网格元素索引值。 |
| onItemDragEnter(event: (event: ItemDragInfo) => void) | 拖拽进入网格元素范围内时触发，返回值event见[ItemDragInfo对象说明](#itemdraginfo对象说明)。 |
| onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void) | 拖拽在网格元素范围内移动时触发，返回值event见[ItemDragInfo对象说明](#itemdraginfo对象说明)，itemIndex为拖拽起始位置，insertIndex为拖拽插入位置。 |
| onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void) | 拖拽离开网格元素时触发，返回值event见[ItemDragInfo对象说明](#itemdraginfo对象说明)，itemIndex为拖拽离开的网格元素索引值。 |
| onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void) | 绑定该事件的网格元素可作为拖拽释放目标，当在网格元素内停止拖拽时触发，返回值event见[ItemDragInfo对象说明](#itemdraginfo对象说明)，itemIndex为拖拽起始位置，insertIndex为拖拽插入位置，isSuccess为是否成功释放。 |

## ItemDragInfo对象说明

| 名称         | 类型         |   描述         |
| ---------- | ---------- | ---------- |
| x | number |  当前拖拽点的x坐标。    |
| y   | number |  当前拖拽点的y坐标。    |

## 示例

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

![zh-cn_image_0000001219744183](figures/zh-cn_image_0000001219744183.gif)