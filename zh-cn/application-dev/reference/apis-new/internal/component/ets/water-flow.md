# water_flow    
瀑布流容器，由“行”和“列”分割的单元格所组成，通过容器自身的排列规则，将不同大小的“项目”自上而下，如瀑布般紧密布局。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## WaterFlowOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| footer | CustomBuilder | false | false | 设置WaterFlow尾部组件。 |  
| scroller | Scroller | false | false | 可滚动组件的控制器，与可滚动组件绑定。<br/>目前瀑布流仅支持Scroller组件的scrollToIndex接口。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- WaterFlow(options?: WaterFlowOptions)    
起始版本： 9    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | WaterFlowOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| columnsTemplate |  string |  |  
| itemConstraintSize |  ConstraintSizeOptions |  |  
| rowsTemplate |  string |  |  
| columnsGap |  Length |  |  
| rowsGap |  Length |  |  
| layoutDirection |  FlexDirection |  |  
| nestedScroll<sup>10+</sup> |  NestedScrollOptions |  |  
| enableScrollInteraction<sup>10+</sup> |  boolean |  |  
| friction<sup>10+</sup> |  number \| Resource |  |  
    
### onReachStart<sup>(deprecated)</sup>    
onReachStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onReachEnd<sup>(deprecated)</sup>    
onReachEnd(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onScrollFrameBegin<sup>(deprecated)</sup>    
onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number })    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | (offset: number, state: ScrollState) => { offsetRemain: number } | true |  |  
    
 **示例代码1：**   
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
  public Add1stItem(): void {  
    this.dataArray.splice(0, 0, this.dataArray.length)  
    this.notifyDataAdd(0)  
  }  
  
  // 在数据尾部增加一个元素  
  public AddLastItem(): void {  
    this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length)  
    this.notifyDataAdd(this.dataArray.length - 1)  
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
  
    
 **示例代码2：**   
```ts    
// Index.ets  
import { WaterFlowDataSource } from './WaterFlowDataSource'  
  
@Entry  
@Component  
struct WaterflowDemo {  
  @State minSize: number = 80  
  @State maxSize: number = 180  
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
          .onAppear(() => {  
            // 即将触底时提前增加数据  
            if (item + 20 == this.datasource.totalCount()) {  
              for (let i = 0; i < 100; i++) {  
                this.datasource.AddLastItem()  
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
  
