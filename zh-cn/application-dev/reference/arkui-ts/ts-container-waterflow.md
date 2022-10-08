# WaterFlow

瀑布流容器，由“行”和“列”分割的单元格所组成，通过容器自身的排列规则，将不同大小的“项目”自上而下，如瀑布般紧密布局。

> **说明：**
> 该组件从API Version 9 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

包含[FlowItem](ts-container-flowitem.md)子组件。


## 接口

WaterFlow(*options*?: {footer?: CustomBuilder, scroller?: Scroller;})

- 参数

  | 参数名     | 参数类型                                        | 必填 | 默认值 | 参数描述                                     |
  | ---------- | ----------------------------------------------- | ---- | ------ | -------------------------------------------- |
  | footer |  [CustomBuilder](ts-types.md#custombuilder8) | 否   | -  | 设置WaterFlow尾部组件。  |
  | scroller | [Scroller](ts-container-scroll.md#Scroller) | 否   | -   | 可滚动组件的控制器。用于与可滚动组件进行绑定。 |

## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| columnsTemplate | string | 设置当前网格布局列的数量，不设置时默认1列。<br/>例如, '1fr 1fr 2fr' 是将父组件分3列，将父组件允许的宽分为4等份，第一列占1份，第二列占1份，第三列占2份。<br>默认值：'1fr' |
| rowsTemplate | string | 设置当前网格布局行的数量，不设置时默认1行。<br/>例如, '1fr 1fr 2fr'是将父组件分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。<br/>默认值：'1fr' |
| itemConstraintSize | [ConstraintSizeOptions](../../ui/ts-types.md#ConstraintSizeOptions) | 设置约束尺寸，子组件布局时，进行尺寸范围限制。               |
| columnsGap | Length |设置列与列的间距。 <br>默认值：0|
| rowsGap | Length |设置行与行的间距。<br> 默认值：0|
| layoutDirection | [FlexDirection](./ts-appendix-enums.md#FlexDirection) |设置布局的主轴方向。|

## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onReachStart(event: () => void) | 瀑布流组件到达起始位置时触发。 |
| onReachEnd(event: () => void)   | 瀑布流组件到底末尾位置时触发。 |

## 示例

```typescript
// WaterFlowDataSource.ets

export class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = []

  public totalCount(): number {
    return 0
  }

  public getData(index: number): any {
    return undefined
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener)
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1)
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded()
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdded(index)
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChanged(index)
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDeleted(index)
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMoved(from, to)
    })
  }
}

export class WaterFlowDataSource extends BasicDataSource {
  constructor() {
    super()
    for (let i = 0; i <= 100; i++) {
      this.dataArray.push(i);
    }
  }

  private dataArray: number[] = []

  public getData(index: number): any {
    return this.dataArray[index]
  }

  public triggerDataSourceUpdated(index): void {
    this.notifyDataChange(index)
  }

  public loadData(index: number): void {
    this.triggerDataSourceUpdated(index)
  }

  public totalCount(): number {
    return this.dataArray.length
  }

  public Delete1stItem(): void {
    this.dataArray.splice(0, 1)
    this.notifyDataDelete(0)
  }

  public Delete2ndItem(): void{
    this.dataArray.splice(1, 1)
    this.notifyDataDelete(1)
  }

  public DeleteLastItem(): void{
    this.dataArray.splice(-1, 1)
    this.notifyDataDelete(this.dataArray.length)
  }

  public AddItem(index: number): void{
    this.dataArray.splice(index, 0, this.dataArray.length)
    this.notifyDataAdd(index)
  }

  public Reload(): void{
    this.dataArray.splice(1, 1);
    this.dataArray.splice(3, 2);
    this.notifyDataReload();
  }
}
```

```typescript
// WaterflowDemo.ets
import { WaterFlowDataSource } from './WaterFlowDataSource'

@Entry
@Component
struct WaterflowDemo {
  @State minSize: number = 50
  @State maxSize: number = 100
  @State fontSize: number = 24
  @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F]
  scroller: Scroller = new Scroller();
  datasource: WaterFlowDataSource = new WaterFlowDataSource();

  getSize() {
    let ret = Math.floor(Math.random() * this.maxSize)
    return (ret > this.minSize ? ret : this.minSize)
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
      WaterFlow({ footer: this.itemFoot, scroller: this.scroller }) {
        LazyForEach(this.datasource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
              Image('res/waterFlowTest(' + item % 5 + ').jpg')
                .objectFit(ImageFit.Fill)
            }
          }
          .width(this.getSize())
          .height(this.getSize())
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

![zh-cn_image_WaterFlow.gif](figures/WaterFlow.gif)