# WaterFlow


瀑布流容器，由“行”和“列”分割的单元格所组成，通过容器自身的排列规则，将不同大小的“项目”自上而下，如瀑布般紧密布局。


> **说明：**
>
> 该组件从API Version 9 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件


包含[FlowItem](ts-container-flowitem.md)子组件。

>  **说明：**
>
>  WaterFlow子组件的visibility属性设置为None时不显示，但依然会占用子组件对应的网格。

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
| columnsTemplate | string | 设置当前瀑布流组件布局列的数量，不设置时默认1列。<br/>例如, '1fr 1fr 2fr' 是将父组件分3列，将父组件允许的宽分为4等份，第一列占1份，第二列占1份，第三列占2份。并支持[auto-fill](#auto-fill说明)。<br>默认值：'1fr' |
| rowsTemplate | string | 设置当前瀑布流组件布局行的数量，不设置时默认1行。<br/>例如, '1fr 1fr 2fr'是将父组件分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。并支持[auto-fill](#auto-fill说明)。<br/>默认值：'1fr' |
| itemConstraintSize | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | 设置约束尺寸，子组件布局时，进行尺寸范围限制。               |
| columnsGap | Length |设置列与列的间距。 <br>默认值：0|
| rowsGap | Length |设置行与行的间距。<br> 默认值：0|
| layoutDirection | [FlexDirection](ts-appendix-enums.md#flexdirection) |设置布局的主轴方向。<br/>默认值：FlexDirection.Column|
| enableScrollInteraction<sup>10+</sup>  |  boolean  |   设置是否支持滚动手势，当设置为false时，无法通过手指或者鼠标滚动，但不影响控制器的滚动接口。<br/>默认值：true      |

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


## auto-fill说明

WaterFlow的columnsTemplate、rowsTemplate属性的auto-fill仅支持以下格式：

```css
repeat(auto-fill, track-size)
```

其中repeat、auto-fill为关键字。track-size为行高或者列宽，支持的单位包括px、vp、%或有效数字，track-size至少包括一个有效行高或者列宽。


## 示例


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
  public getData(index: number): any {
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
  public Add1stItem(): void {
      this.dataArray.splice(0, 0, this.dataArray.length)
      this.notifyDataAdd(0)
  }

  // 在数据尾部增加一个元素
  public AddLastItem(): void {
      this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length)
      this.notifyDataAdd(this.dataArray.length-1)
  }

  // 在指定索引位置增加一个元素
  public AddItem(index: number): void {
      this.dataArray.splice(index, 0, this.dataArray.length)
      this.notifyDataAdd(index)
  }

  // 删除第一个元素
  public Delete1stItem(): void {
      this.dataArray.splice(0, 1)
      this.notifyDataDelete(0)
  }

  // 删除第二个元素
  public Delete2ndItem(): void {
      this.dataArray.splice(1, 1)
      this.notifyDataDelete(1)
  }

  // 删除最后一个元素
  public DeleteLastItem(): void {
      this.dataArray.splice(-1, 1)
      this.notifyDataDelete(this.dataArray.length)
  }

  // 重新加载数据
  public Reload(): void {
      this.dataArray.splice(1, 1)
      this.dataArray.splice(3, 2)
      this.notifyDataReload()
  }
}
```

```ts
// WaterflowDemo.ets
import { WaterFlowDataSource } from './WaterFlowDataSource'

@Entry
@Component
struct WaterflowDemo {
  @State minSize: number = 50
  @State maxSize: number = 100
  @State fontSize: number = 24
  @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F]
  scroller: Scroller = new Scroller()
  datasource: WaterFlowDataSource = new WaterFlowDataSource()
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
    
  @Builder itemFoot() {
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
      WaterFlow({ footer: this.itemFoot.bind(this), scroller: this.scroller }) {
        LazyForEach(this.datasource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
              Image('res/waterFlowTest(' + item % 5 + ').jpg')
                .objectFit(ImageFit.Fill)
                .width('100%')
                .layoutWeight(1)
            }
          }
          .width('100%')
          .height(this.itemHeightArray[item])
          .backgroundColor(this.colors[item % 5])
        }, item => item)
      }
      .columnsTemplate("1fr 1fr 1fr 1fr")
      .itemConstraintSize({
        minWidth: 0,
        maxWidth: '100%',
        minHeight: 0,
        maxHeight: '100%'
      })
      .columnsGap(10)
      .rowsGap(5)
      .onReachStart(() => {
        console.info("onReachStart")
      })
      .onReachEnd(() => {
        console.info("onReachEnd")
      })
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('80%')
      .layoutDirection(FlexDirection.Column)
    }
  }
}
```

![zh-cn_image_WaterFlow.gif](figures/waterflow.gif)
