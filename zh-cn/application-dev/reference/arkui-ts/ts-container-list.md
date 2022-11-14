# List

列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。

> **说明：**
>
> - 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 该组件回弹的前提是要有滚动。内容小于一屏时，没有回弹效果。


## 子组件

包含[ListItem](ts-container-listitem.md)、[ListItemGroup](ts-container-listitemgroup.md)子组件。


## 接口

List(value?:{space?: number&nbsp;|&nbsp;string, initialIndex?: number, scroller?: Scroller})

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| space | number&nbsp;\|&nbsp;string | 否 | 列表项间距。<br/>默认值：0 |
| initialIndex | number | 否 | 设置当前List初次加载时视口起始位置显示的item的索引值。如果设置的值超过了当前List最后一个item的索引值，则设置不生效。<br/>默认值：0 |
| scroller | [Scroller](ts-container-scroll.md#scroller) | 否 | 可滚动组件的控制器。用于与可滚动组件进行绑定。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| listDirection | [Axis](ts-appendix-enums.md#axis) | 设置List组件排列方向。<br/>默认值：Axis.Vertical |
| divider                      | {<br/>strokeWidth:&nbsp;[Length](ts-types.md#length),<br/>color?:[ResourceColor](ts-types.md),<br/>startMargin?:&nbsp;Length,<br/>endMargin?:&nbsp;Length<br/>}&nbsp;\|&nbsp;null | 设置ListItem分割线样式，默认无分割线。<br/>- strokeWidth:&nbsp;分割线的线宽。<br/>- color:&nbsp;分割线的颜色。<br/>- startMargin:&nbsp;分割线与列表侧边起始端的距离。<br/>- endMargin:&nbsp;分割线与列表侧边结束端的距离。 |
| scrollBar      | [BarState](ts-appendix-enums.md#barstate) | 设置滚动条状态。<br/>默认值：BarState.Off |
| cachedCount | number                                   | 设置预加载的ListItem数量。具体使用可参考[减少应用白块说明](../../ui/ui-ts-performance-improvement-recommendation.md#减少应用滑动白块)。<br/>默认值：1 |
| editMode | boolean | 声明当前List组件是否处于可编辑模式。<br/>默认值：false |
| edgeEffect | [EdgeEffect](ts-appendix-enums.md#edgeeffect) | 设置组件的滑动效果。<br/>默认值：EdgeEffect.Spring |
| chainAnimation | boolean | 设置当前List是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。链式联动效果：List内的list-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。<br/>默认值：false<br/>-&nbsp;false：不启用链式联动。<br/>-&nbsp;true：启用链式联动。 |
| multiSelectable<sup>8+</sup> | boolean | 是否开启鼠标框选。<br/>默认值：false<br/>-&nbsp;false：关闭框选。<br/>-&nbsp;true：开启框选。 |
| lanes<sup>9+</sup> | number \| [LengthConstrain](ts-types.md#lengthconstrain) | 以列模式为例（listDirection为Axis.Vertical）:<br/>lanes用于决定List组件在交叉轴方向按几列布局。<br/>默认值：1<br/>规则如下：<br/>- lanes为指定的数量时，根据指定的数量与List组件的交叉轴宽度来决定每列的宽度；<br/>- lane设置了{minLength，maxLength}时，根据List组件的宽度自适应决定lanes数量（即列数），保证缩放过程中lane的宽度符合{minLength，maxLength}的限制。其中，minLength条件会被优先满足，即优先保证符合ListItem的宽度符合最小宽度限制。例如在列模式下，设置了{minLength: 40vp，maxLength: 60vp}，则当List组件宽度为70vp时，ListItem为一列，并且根据alignListItem属性做靠左、居中或者靠右布局；当List组件宽度变化至80vp时，符合两倍的minLength，则ListItem自适应为两列。 |
| alignListItem<sup>9+</sup> | ListItemAlign | List交叉轴方向宽度大于ListItem交叉轴宽度 * lanes时，ListItem在List交叉轴方向的布局方式，默认为首部对齐。<br/>默认值：ListItemAlign.Start |
| sticky<sup>9+</sup> | StickyStyle | 配合[ListItemGroup](ts-container-listitemgroup.md)组件使用，设置ListItemGroup中header和footer是否要吸顶或吸底。<br/>默认值：StickyStyle.None<br/>**说明：**<br/>sticky属性可以设置为 StickyStyle.Header \| StickyStyle.Footer 以同时支持header吸顶和footer吸底。 |

## ListItemAlign<sup>9+</sup>枚举说明

| 名称   | 描述                                   |
| ------ | -------------------------------------- |
| Start  | ListItem在List中，交叉轴方向首部对齐。 |
| Center | ListItem在List中，交叉轴方向居中对齐。 |
| End    | ListItem在List中，交叉轴方向尾部对齐。 |

## StickyStyle<sup>9+</sup>枚举说明

| 名称   | 描述                                   |
| ------ | -------------------------------------- |
| None  | ListItemGroup的header不吸顶，footer不吸底。 |
| Header | ListItemGroup的header吸顶。 |
| Footer | ListItemGroup的footer吸底。 |



## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onItemDelete(event: (index: number) => boolean) | 当List组件在编辑模式时，点击ListItem右边出现的删除按钮时触发。<br/>- index: 被删除的列表项的索引值。 |
| onScroll(event: (scrollOffset: number, scrollState: ScrollState) => void) | 列表滑动时触发。<br/>- scrollOffset: 滑动偏移量。<br/>- [scrollState](#scrollstate枚举说明): 当前滑动状态。 |
| onScrollIndex(event: (start: number, end: number) => void) | 列表滑动时触发。<br/>计算索引值时，ListItemGroup作为一个整体占一个索引值，不计算ListItemGroup内部ListItem的索引值。<br/>- start: 滑动起始位置索引值。<br/>- end: 滑动结束位置索引值。 |
| onReachStart(event: () => void) | 列表到达起始位置时触发。 |
| onReachEnd(event: () => void) | 列表到底末尾位置时触发。 |
| onScrollBegin<sup>9+</sup>(event: (dx: number, dy: number) => { dxRemain: number, dyRemain: number }) | 列表开始滑动时触发。<br/>\- dx：即将发生的水平方向滚动量。<br/>\- dy：即将发生的竖直方向滚动量。<br/>- dxRemain：水平方向滚动剩余量。<br/>\- dyRemain：竖直方向滚动剩余量。 |
| onScrollStop(event: () => void) | 列表滑动停止时触发。 |
| onItemMove(event: (from: number, to: number) => boolean) | 列表元素发生移动时触发。<br/>- from: 移动前索引值。<br/>- to: 移动后索引值。 |
| onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => ((() => any) \| void) | 开始拖拽列表元素时触发。<br/>- event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 被拖拽列表元素索引值。 |
| onItemDragEnter(event: (event: ItemDragInfo) => void) | 拖拽进入列表元素范围内时触发。<br/>- event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。 |
| onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void) | 拖拽在列表元素范围内移动时触发。<br/>- event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽起始位置。<br/>- insertIndex: 拖拽插入位置。 |
| onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void) | 拖拽离开列表元素时触发。<br/>- event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽离开的列表元素索引值。 |
| onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void) | 绑定该事件的列表元素可作为拖拽释放目标，当在列表元素内停止拖拽时触发。<br/>- event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽起始位置。<br/>- insertIndex: 拖拽插入位置。<br/>- isSuccess: 是否成功释放。 |

## ScrollState枚举说明

| 名称     | 描述                     |
| ------ | ------------------------- |
| Idle    | 未滑动状态。           |
| Scroll   | 惯性滑动状态。          |
| Fling   | 手指拖动状态。           |

>  **说明：**
>
>  要使List处于可编辑模式需配合onItemDelete事件和ListItem的editable属性，即可编辑模式实现删除列表项功能，需满足以下条件：
>
>  - editMode属性设置为true。
>
>  - 绑定onItemDelete事件，且事件回调返回true。
>
>  - ListItem的editable属性设置为true。
>
>  实现ListItem拖拽，需满足以下条件：
>
>  - editMode属性设置为true。
>
>  - 绑定onDragStart事件，且事件回调中返回浮动UI布局。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical) // 排列方向
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线
        .edgeEffect(EdgeEffect.None) // 滑动到边缘无效果
        .chainAnimation(false) // 联动特效关闭
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
        .editMode(this.editFlag)
        .onItemDelete((index: number) => {
          console.info(this.arr[index] + 'Delete')
          this.arr.splice(index, 1)
          console.info(JSON.stringify(this.arr))
          this.editFlag = false
          return true
        }).width('90%')
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001174264378](figures/zh-cn_image_0000001174264378.gif)

```ts
// xxx.ets
@Entry
@Component
struct ListLanesExample {
  @State arr: string[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19"]
  @State alignListItem: ListItemAlign = ListItemAlign.Start

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
          .border({ width: 2, color: Color.Green })
        }, item => item)
      }
      .height(300)
      .width("90%")
      .editMode(true)
      .border({ width: 3, color: Color.Red })
      .lanes({ minLength: 40, maxLength: 40 })
      .alignListItem(this.alignListItem)

      Button("点击更改alignListItem:" + this.alignListItem).onClick(() => {
        if (this.alignListItem == ListItemAlign.Start) {
          this.alignListItem = ListItemAlign.Center
        } else if (this.alignListItem == ListItemAlign.Center) {
          this.alignListItem = ListItemAlign.End
        } else {
          this.alignListItem = ListItemAlign.Start
        }
      })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![list](figures/list1.gif)