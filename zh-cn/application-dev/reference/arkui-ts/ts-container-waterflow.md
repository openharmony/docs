# WaterFlow


瀑布流容器，由“行”和“列”分割的单元格所组成，通过容器自身的排列规则，将不同大小的“项目”自上而下，如瀑布般紧密布局。


> **说明：**
>
> 该组件从API Version 9 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件


包含[FlowItem](ts-container-flowitem.md)子组件。

>  **说明：**
>
>  WaterFlow子组件的visibility属性设置为None时不显示，但该子组件周围的gap还会生效。

## 接口


WaterFlow(options?: {footer?: CustomBuilder, scroller?: Scroller})

**参数：**

| 参数名     | 参数类型                                        | 必填 | 参数描述                                     |
| ---------- | ----------------------------------------------- | ------ | -------------------------------------------- |
| footer |  [CustomBuilder](ts-types.md#custombuilder8) | 否   | 设置WaterFlow尾部组件。  |
| scroller | [Scroller](ts-container-scroll.md#scroller) | 否   | 可滚动组件的控制器，与可滚动组件绑定。<br/>目前瀑布流仅支持Scroller组件的scrollToIndex接口。 |


## 属性


除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| columnsTemplate | string | 设置当前瀑布流组件布局列的数量，不设置时默认1列。<br/>例如, '1fr 1fr 2fr' 是将父组件分3列，将父组件允许的宽分为4等份，第一列占1份，第二列占1份，第三列占2份。<br>可使用columnsTemplate('repeat(auto-fill,track-size)')根据给定的列宽track-size自动计算列数，其中repeat、auto-fill为关键字，track-size为可设置的宽度，支持的单位包括px、vp、%或有效数字，使用方法参见示例2。<br>默认值：'1fr' |
| rowsTemplate | string | 设置当前瀑布流组件布局行的数量，不设置时默认1行。<br/>例如, '1fr 1fr 2fr'是将父组件分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。<br>可使用rowsTemplate('repeat(auto-fill,track-size)')根据给定的行高track-size自动计算行数，其中repeat、auto-fill为关键字，track-size为可设置的高度，支持的单位包括px、vp、%或有效数字。<br/>默认值：'1fr' |
| itemConstraintSize | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | 设置约束尺寸，子组件布局时，进行尺寸范围限制。               |
| columnsGap | Length |设置列与列的间距。 <br>默认值：0|
| rowsGap | Length |设置行与行的间距。<br> 默认值：0|
| layoutDirection | [FlexDirection](ts-appendix-enums.md#flexdirection) |设置布局的主轴方向。<br/>默认值：FlexDirection.Column|
| enableScrollInteraction<sup>10+</sup>  |  boolean  |   设置是否支持滚动手势，当设置为false时，无法通过手指或者鼠标滚动，但不影响控制器的滚动接口。<br/>默认值：true      |
| nestedScroll<sup>10+</sup>                 | [NestedScrollOptions](ts-container-scroll.md#nestedscrolloptions10对象说明)         | 嵌套滚动选项。设置向前向后两个方向上的嵌套滚动模式，实现与父组件的滚动联动。 |
| friction<sup>10+</sup> | number \| [Resource](ts-types.md#resource)    | 设置摩擦系数，手动划动滚动区域时生效，只对惯性滚动过程有影响，对惯性滚动过程中的链式效果有间接影响。<br/>默认值：非可穿戴设备为0.6，可穿戴设备为0.9<br/>**说明：** <br/>设置为小于等于0的值时，按默认值处理 |
| cachedCount<sup>11+</sup> | number | 设置预加载的FlowItem的数量，只在LazyForEach中生效。 <br/> 默认值：1 <br/>**说明：** <br/>设置该属性后会缓存cachedCount个FlowItem。<br/>[LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)超出显示和缓存范围的FlowItem会被释放。<br/>设置为小于0的值时，按默认值显示。|
| scrollBar<sup>11+</sup>            | [BarState](ts-appendix-enums.md#barstate) | 设置滚动条状态。<br/>默认值：BarState.Off<br/>**说明：** <br/>滚动条位置和长度以已布局过的总高度和当前偏移为准，在瀑布流布局全部子节点之前随着滑动持续变化。 |
| scrollBarWidth<sup>11+</sup> | string&nbsp;\|&nbsp;number         | 设置滚动条的宽度，不支持百分比设置。<br/>默认值：4<br/>单位：vp<br/>**说明：** <br/>如果滚动条的宽度超过其高度，则滚动条的宽度会变为默认值。 |
| scrollBarColor<sup>11+</sup> | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;[Color](ts-appendix-enums.md#color)   | 设置滚动条的颜色。 |
| edgeEffect<sup>11+</sup>     | value:[EdgeEffect](ts-appendix-enums.md#edgeeffect), <br/>options?:[EdgeEffectOptions<sup>11+</sup>](ts-container-scroll.md#edgeeffectoptions11对象说明)        | 设置边缘滑动效果。<br/>\- value：设置瀑布流组件的边缘滑动效果，支持弹簧效果和阴影效果。<br/>默认值：EdgeEffect.None <br/>\- options：设置组件内容大小小于组件自身时，是否开启滑动效果。<br/>默认值：false |

layoutDirection优先级高于rowsTemplate和columnsTemplate。根据layoutDirection设置情况，分为以下三种设置模式:

- layoutDirection设置纵向布局（FlexDirection.Column 或 FlexDirection.ColumnReverse）

	此时columnsTemplate有效（如果未设置，取默认值）。例如columnsTemplate设置为"1fr 1fr"、rowsTemplate设置为"1fr 1fr 1fr"时，瀑布流组件纵向布局，辅轴均分成横向2列。

- layoutDirection设置横向布局（FlexDirection.Row 或 FlexDirection.RowReverse）

	此时rowsTemplate有效（如果未设置，取默认值）。例如columnsTemplate设置为"1fr 1fr"、rowsTemplate设置为"1fr 1fr 1fr"时，瀑布流组件横向布局，辅轴均分成纵向3列。

- layoutDirection未设置布局方向

	布局方向为layoutDirection的默认值：FlexDirection.Column，此时columnsTemplate有效。例如columnsTemplate设置为"1fr 1fr"、rowsTemplate设置为"1fr 1fr 1fr"时，瀑布流组件纵向布局，辅轴均分成横向2列。

## 事件


除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：


| 名称 | 功能描述 |
| -------- | -------- |
| onReachStart(event: () => void) | 瀑布流组件到达起始位置时触发。 |
| onReachEnd(event: () => void)   | 瀑布流组件到底末尾位置时触发。 |
| onScrollFrameBegin<sup>10+</sup>(event: (offset: number, state: ScrollState) => { offsetRemain }) | 瀑布流开始滑动时触发，事件参数传入即将发生的滑动量，事件处理函数中可根据应用场景计算实际需要的滑动量并作为事件处理函数的返回值返回，瀑布流将按照返回值的实际滑动量进行滑动。<br/>\- offset：即将发生的滑动量，单位vp。<br/>\- state：当前滑动状态。<br/>- offsetRemain：实际滑动量，单位vp。<br/>触发该事件的条件：手指拖动WaterFlow、WaterFlow惯性划动时每帧开始时触发；List超出边缘回弹、使用滚动控制器的滚动不会触发。|
| onScroll<sup>11+</sup>(event: (scrollOffset: number, scrollState: [ScrollState](ts-container-list.md#scrollstate枚举说明)) => void) | 瀑布流滑动时触发。<br/>- scrollOffset: 每帧滚动的偏移量，瀑布流的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>- scrollState: 当前滑动状态。 |
| onScrollIndex<sup>11+</sup>(event: (first: number, last: number) => void) | 当前瀑布流显示的起始位置/终止位置的子组件发生变化时触发。瀑布流初始化时会触发一次。<br/>- first: 当前显示的WaterFlow起始位置的索引值。<br/>- last: 当前显示的瀑布流终止位置的索引值。<br/>瀑布流显示区域上第一个子组件/最后一个组件的索引值有变化就会触发。 |
| onScrollStart<sup>11+</sup>(event: () => void) | 瀑布流滑动开始时触发。手指拖动瀑布流或瀑布流的滚动条触发的滑动开始时，会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画开始时会触发该事件。 |
| onScrollStop<sup>11+</sup>(event: () => void)          | 瀑布流滑动停止时触发。手指拖动瀑布流或瀑布流的滚动条触发的滑动，手指离开屏幕并且滑动停止时会触发该事件；使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画停止会触发该事件。 |


## 示例

### 示例1
WaterFlow的基本使用。
```ts
// WaterFlowDataSource.ets

// 实现IDataSource接口的对象，用于瀑布流组件加载数据
export class WaterFlowDataSource implements IDataSource {
  private dataArray: number[] = []
  private listeners: DataChangeListener[] = []

  constructor() {
    for (let i = 0; i < 100; i++) {
      this.dataArray.push(i)
    }
  }

  // 获取索引对应的数据
  public getData(index: number): number {
    return this.dataArray[index]
  }

  // 通知控制器数据重新加载
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded()
    })
  }

  // 通知控制器数据增加
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdded(index)
    })
  }

  // 通知控制器数据变化
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChanged(index)
    })
  }

  // 通知控制器数据删除
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDeleted(index)
    })
  }

  // 通知控制器数据位置变化
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMoved(from, to)
    })
  }

  // 获取数据总数
  public totalCount(): number {
    return this.dataArray.length
  }

  // 注册改变数据的控制器
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener)
    }
  }

  // 注销改变数据的控制器
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener)
    if (pos >= 0) {
      this.listeners.splice(pos, 1)
    }
  }

  // 增加数据
  public add1stItem(): void {
    this.dataArray.splice(0, 0, this.dataArray.length)
    this.notifyDataAdd(0)
  }

  // 在数据尾部增加一个元素
  public addLastItem(): void {
    this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length)
    this.notifyDataAdd(this.dataArray.length - 1)
  }

  // 在指定索引位置增加一个元素
  public addItem(index: number): void {
    this.dataArray.splice(index, 0, this.dataArray.length)
    this.notifyDataAdd(index)
  }

  // 删除第一个元素
  public delete1stItem(): void {
    this.dataArray.splice(0, 1)
    this.notifyDataDelete(0)
  }

  // 删除第二个元素
  public delete2ndItem(): void {
    this.dataArray.splice(1, 1)
    this.notifyDataDelete(1)
  }

  // 删除最后一个元素
  public deleteLastItem(): void {
    this.dataArray.splice(-1, 1)
    this.notifyDataDelete(this.dataArray.length)
  }

  // 重新加载数据
  public reload(): void {
    this.dataArray.splice(1, 1)
    this.dataArray.splice(3, 2)
    this.notifyDataReload()
  }
}
```

```ts
// Index.ets
import { WaterFlowDataSource } from './WaterFlowDataSource'

@Entry
@Component
struct WaterFlowDemo {
  @State minSize: number = 80
  @State maxSize: number = 180
  @State fontSize: number = 24
  @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F]
  scroller: Scroller = new Scroller()
  dataSource: WaterFlowDataSource = new WaterFlowDataSource()
  private itemWidthArray: number[] = []
  private itemHeightArray: number[] = []

  // 计算flow item宽/高
  getSize() {
    let ret = Math.floor(Math.random() * this.maxSize)
    return (ret > this.minSize ? ret : this.minSize)
  }

  // 保存flow item宽/高
  getItemSizeArray() {
    for (let i = 0; i < 100; i++) {
      this.itemWidthArray.push(this.getSize())
      this.itemHeightArray.push(this.getSize())
    }
  }

  aboutToAppear() {
    this.getItemSizeArray()
  }

  @Builder
  itemFoot() {
    Column() {
      Text(`Footer`)
        .fontSize(10)
        .backgroundColor(Color.Red)
        .width(50)
        .height(50)
        .align(Alignment.Center)
        .margin({ top: 2 })
    }
  }

  build() {
    Column({ space: 2 }) {
      WaterFlow() {
        LazyForEach(this.dataSource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
              Image('res/waterFlowTest(' + item % 5 + ').jpg')
                .objectFit(ImageFit.Fill)
                .width('100%')
                .layoutWeight(1)
            }
          }
          .onAppear(() => {
            // 即将触底时提前增加数据
            if (item + 20 == this.dataSource.totalCount()) {
              for (let i = 0; i < 100; i++) {
                this.dataSource.addLastItem()
              }
            }
          })
          .width('100%')
          .height(this.itemHeightArray[item % 100])
          .backgroundColor(this.colors[item % 5])
        }, (item: string) => item)
      }
      .columnsTemplate("1fr 1fr")
      .columnsGap(10)
      .rowsGap(5)
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('100%')
    }
  }
}
```

![zh-cn_image_WaterFlow.gif](figures/waterflow-perf-demo.gif)

### 示例2
auto-fill的使用。
```ts
//index.ets
import { WaterFlowDataSource } from './WaterFlowDataSource'

@Entry
@Component
struct WaterFlowDemo {
  @State minSize: number = 80
  @State maxSize: number = 180
  @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F]
  dataSource: WaterFlowDataSource = new WaterFlowDataSource()
  private itemWidthArray: number[] = []
  private itemHeightArray: number[] = []

  // 计算flow item宽/高
  getSize() {
    let ret = Math.floor(Math.random() * this.maxSize)
    return (ret > this.minSize ? ret : this.minSize)
  }

  // 保存flow item宽/高
  getItemSizeArray() {
    for (let i = 0; i < 100; i++) {
      this.itemWidthArray.push(this.getSize())
      this.itemHeightArray.push(this.getSize())
    }
  }

  aboutToAppear() {
    this.getItemSizeArray()
  }

  build() {
    Column({ space: 2 }) {
      WaterFlow() {
        LazyForEach(this.dataSource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
            }
          }
          .width('100%')
          .height(this.itemHeightArray[item % 100])
          .backgroundColor(this.colors[item % 5])
        }, (item: string) => item)
      }
      .columnsTemplate('repeat(auto-fill,80)')
      .columnsGap(10)
      .rowsGap(5)
      .padding({left:5})
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('100%')
    }
  }
}
```

![waterflow_auto-fill.png](figures/waterflow_auto-fill.png)