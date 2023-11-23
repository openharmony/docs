# grid    
网格容器，由“行”和“列”分割的单元格所组成，通过指定“项目”所在的单元格做出各种各样的布局。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## GridLayoutOptions<sup>(10+)</sup>    
布局选项，配合rowsTemplate、columnsTemplate仅设置其中一个的Grid使用，可以替代通过columnStart/columnEnd控制GridItem占用多列、rowStart/rowEnd控制GridItem占用多行的场景。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| regularSize<sup>(10+)</sup> | [number, number] | false | true | 大小规则的GridItem在Grid中占的行数和列数，只支持占1行1列即[1, 1]。<br/> |  
| irregularIndexes<sup>(10+)</sup> | number[] | false | false | 大小不规则的GridItem在Grid所有子节点中的索引值。onGetIrregularSizeByIndex不设置时irregularIndexes中的GridItem默认占垂直滚动Grid的一整行或水平滚动Grid的一整列。<br/> |  
| onGetIrregularSizeByIndex<sup>(10+)</sup> | function | false | false |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Grid(scroller?: Scroller, layoutOptions?: GridLayoutOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| scroller | Scroller | false | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/> |  
| layoutOptions | GridLayoutOptions | false | 滚动Grid布局选项。<br/> |  
    
## GridDirection<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Row | 0 | 主轴布局方向沿水平方向布局，即自左往右先填满一行，再去填下一行。 |  
| Column | 1 | 主轴布局方向沿垂直方向布局，即自上往下先填满一列，再去填下一列。 |  
| RowReverse | 2 | <span style="letter-spacing: 0px;">主轴布局方向沿水平方向反向布局，即自右往左先填满一行，再去填下一行。</span> |  
| ColumnReverse | 3 | 主轴布局方向沿垂直方向反向布局，即自下往上先填满一列，再去填下一列。 |  
    
## ComputedBarAttribute<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| totalOffset<sup>(10+)</sup> | number | false | true | Grid内容相对显示区域的总偏移。<br/> |  
| totalLength<sup>(10+)</sup> | number | false | true | Grid内容总长度。<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| columnsTemplate |  string |  |  
| rowsTemplate |  string |  |  
| columnsGap |  Length |  |  
| rowsGap |  Length |  |  
| scrollBarWidth |  number \| string |  |  
| scrollBarColor |  Color \| number \| string |  |  
| scrollBar |  BarState |  |  
| cachedCount |  number |  |  
| editMode<sup>8+</sup> |  boolean |  |  
| multiSelectable<sup>8+</sup> |  boolean |  |  
| maxCount<sup>8+</sup> |  number |  |  
| minCount<sup>8+</sup> |  number |  |  
| cellLength<sup>8+</sup> |  number |  |  
| layoutDirection<sup>8+</sup> |  GridDirection |  |  
| supportAnimation<sup>8+</sup> |  boolean |  |  
| edgeEffect<sup>10+</sup> |  EdgeEffect |  |  
| nestedScroll<sup>10+</sup> |  NestedScrollOptions |  |  
| enableScrollInteraction<sup>10+</sup> |  boolean |  |  
| friction<sup>10+</sup> |  number \| Resource |  |  
    
### onScrollBarUpdate<sup>(deprecated)</sup>    
onScrollBarUpdate(event: (index: number, offset: number) => ComputedBarAttribute)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | (index: number, offset: number) => ComputedBarAttribute | true | <br/> |  
    
### onScrollIndex<sup>(deprecated)</sup>    
onScrollIndex(event: (first: number, last: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | (first: number, last: number) => void | true |  |  
    
### onItemDragStart<sup>(deprecated)</sup>    
onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => (() => any) | void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (event: ItemDragInfo, itemIndex: number) => (() => any) \| void | true |  |  
    
### onItemDragEnter<sup>(deprecated)</sup>    
onItemDragEnter(event: (event: ItemDragInfo) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (event: ItemDragInfo) => void | true |  |  
    
### onItemDragMove<sup>(deprecated)</sup>    
onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void | true |  |  
    
### onItemDragLeave<sup>(deprecated)</sup>    
onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (event: ItemDragInfo, itemIndex: number) => void | true |  |  
    
### onItemDrop<sup>(deprecated)</sup>    
onItemDrop(     event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void,   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void | true |  |  
    
### onScroll<sup>(deprecated)</sup>    
onScroll(event: (scrollOffset: number, scrollState: ScrollState) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | (scrollOffset: number, scrollState: ScrollState) => void | true |  |  
    
### onReachStart<sup>(deprecated)</sup>    
onReachStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | () => void | true |  |  
    
### onReachEnd<sup>(deprecated)</sup>    
onReachEnd(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | () => void | true |  |  
    
### onScrollStart<sup>(deprecated)</sup>    
onScrollStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | () => void | true |  |  
    
### onScrollStop<sup>(deprecated)</sup>    
onScrollStop(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | () => void | true |  |  
    
### onScrollFrameBegin<sup>(deprecated)</sup>    
onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number })    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | (offset: number, state: ScrollState) => { offsetRemain: number } | true |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct GridExample {  
  @State Number: String[] = ['0', '1', '2', '3', '4']  
  scroller: Scroller = new Scroller()  
  
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
          }, (day: string) => day)  
        }, (day: string) => day)  
      }  
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')  
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')  
      .columnsGap(10)  
      .rowsGap(10)  
      .width('90%')  
      .backgroundColor(0xFAEEE0)  
      .height(300)  
  
      Text('scroll').fontColor(0xCCCCCC).fontSize(9).width('90%')  
      Grid(this.scroller) {  
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
          }, (day: string) => day)  
        }, (day: string) => day)  
      }  
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')  
      .columnsGap(10)  
      .rowsGap(10)  
      .friction(0.6)  
      .edgeEffect(EdgeEffect.Spring)  
      .scrollBar(BarState.On)  
      .onScrollIndex((first: number) => {  
        console.info(first.toString())  
      })  
      .onScrollBarUpdate((index: number, offset: number) => {  
        return {totalOffset: (index / 5) * (80 + 10) - offset, totalLength: 80 * 5 + 10 * 4}  
      })  
      .width('90%')  
      .backgroundColor(0xFAEEE0)  
      .height(300)  
      Button('next page')  
        .onClick(() => { // 点击后滑到下一页  
          this.scroller.scrollPage({ next: true })  
        })  
    }.width('100%').margin({ top: 5 })  
  }  
}  
```  
  
![zh-cn_image_0000001219744183](figures/zh-cn_image_0000001219744183.gif)  
  
### 示例2  
  
1.  设置属性editMode\(true\)设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem。  
  
2.  在[onItemDragStart](#事件)回调中设置拖拽过程中显示的图片。  
  
3.  在[onItemDrop](#事件)中获取拖拽起始位置，和拖拽插入位置，在[onDrag](#事件)回调中完成交换数组位置逻辑。  
  
```ts  
@Entry  
@Component  
struct GridExample {  
  @State numbers: string[] = []  
  scroller: Scroller = new Scroller()  
  @State text: string = 'drag'  
  
  @Builder pixelMapBuilder() { //拖拽过程样式  
    Column() {  
      Text(this.text)  
        .fontSize(16)  
        .backgroundColor(0xF9CF93)  
        .width(80)  
        .height(80)  
        .textAlign(TextAlign.Center)  
    }  
  }  
  
  aboutToAppear() {  
    for (let i = 1;i <= 15; i++) {  
      this.numbers.push(i + '')  
    }  
  }  
  
  changeIndex(index1: number, index2: number) { //交换数组位置  
    let temp: string;  
    temp = this.numbers[index1];  
    this.numbers[index1] = this.numbers[index2];  
    this.numbers[index2] = temp;  
  }  
  
  build() {  
    Column({ space: 5 }) {  
      Grid(this.scroller) {  
        ForEach(this.numbers, (day: string) => {  
          GridItem() {  
            Text(day)  
              .fontSize(16)  
              .backgroundColor(0xF9CF93)  
              .width(80)  
              .height(80)  
              .textAlign(TextAlign.Center)  
          }  
        })  
      }  
      .columnsTemplate('1fr 1fr 1fr')  
      .columnsGap(10)  
      .rowsGap(10)  
      .onScrollIndex((first: number) => {  
        console.info(first.toString())  
      })  
      .width('90%')  
      .backgroundColor(0xFAEEE0)  
      .height(300)  
      .editMode(true) //设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem  
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => { //第一次拖拽此事件绑定的组件时，触发回调。  
        this.text = this.numbers[itemIndex]  
        return this.pixelMapBuilder() //设置拖拽过程中显示的图片。  
      })  
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => { //绑定此事件的组件可作为拖拽释放目标，当在本组件范围内停止拖拽行为时，触发回调。  
        // isSuccess=false时，说明drop的位置在grid外部；insertIndex > length时，说明有新增元素的事件发生  
        if (!isSuccess || insertIndex >= this.numbers.length) {  
          return  
        }  
        console.info('beixiang' + itemIndex + '', insertIndex + '') //itemIndex拖拽起始位置，insertIndex拖拽插入位置  
        this.changeIndex(itemIndex, insertIndex)  
      })  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
网格子组件开始拖拽：![gridDrag](figures/gridDrag.png)  
网格子组件拖拽过程中：![gridDrag](figures/gridDrag1.png)  
网格子组件1与子组件6拖拽交换位置后：![gridDrag](figures/gridDrag2.png)  
    
 **示例代码2：**   
1.  设置属性editMode\(true\)设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem。2.  在[onItemDragStart](#事件)回调中设置拖拽过程中显示的图片。3.  在[onItemDrop](#事件)中获取拖拽起始位置，和拖拽插入位置，在[onDrag](#事件)回调中完成交换数组位置逻辑。  
```ts    
@Entry  
@Component  
struct GridExample {  
  @State numbers: string[] = []  
  scroller: Scroller = new Scroller()  
  @State text: string = 'drag'  
  
  @Builder pixelMapBuilder() { //拖拽过程样式  
    Column() {  
      Text(this.text)  
        .fontSize(16)  
        .backgroundColor(0xF9CF93)  
        .width(80)  
        .height(80)  
        .textAlign(TextAlign.Center)  
    }  
  }  
  
  aboutToAppear() {  
    for (let i = 1;i <= 15; i++) {  
      this.numbers.push(i + '')  
    }  
  }  
  
  changeIndex(index1: number, index2: number) { //交换数组位置  
    let temp: string;  
    temp = this.numbers[index1];  
    this.numbers[index1] = this.numbers[index2];  
    this.numbers[index2] = temp;  
  }  
  
  build() {  
    Column({ space: 5 }) {  
      Grid(this.scroller) {  
        ForEach(this.numbers, (day: string) => {  
          GridItem() {  
            Text(day)  
              .fontSize(16)  
              .backgroundColor(0xF9CF93)  
              .width(80)  
              .height(80)  
              .textAlign(TextAlign.Center)  
          }  
        })  
      }  
      .columnsTemplate('1fr 1fr 1fr')  
      .columnsGap(10)  
      .rowsGap(10)  
      .onScrollIndex((first: number) => {  
        console.info(first.toString())  
      })  
      .width('90%')  
      .backgroundColor(0xFAEEE0)  
      .height(300)  
      .editMode(true) //设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem  
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => { //第一次拖拽此事件绑定的组件时，触发回调。  
        this.text = this.numbers[itemIndex]  
        return this.pixelMapBuilder() //设置拖拽过程中显示的图片。  
      })  
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => { //绑定此事件的组件可作为拖拽释放目标，当在本组件范围内停止拖拽行为时，触发回调。  
        // isSuccess=false时，说明drop的位置在grid外部；insertIndex > length时，说明有新增元素的事件发生  
        if (!isSuccess || insertIndex >= this.numbers.length) {  
          return  
        }  
        console.info('beixiang' + itemIndex + '', insertIndex + '') //itemIndex拖拽起始位置，insertIndex拖拽插入位置  
        this.changeIndex(itemIndex, insertIndex)  
      })  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
    
 **示例代码3：**   
使用GridLayoutOptions  
```ts    
// xxx.ets  
@Entry  
@Component  
struct GridExample {  
  @State Number: String[] = ['0', '1', '2', '3', '4']  
  scroller: Scroller = new Scroller()  
  layoutOptions1: GridLayoutOptions = {  
    regularSize: [1, 1],        // 只支持[1, 1]  
    irregularIndexes: [0, 6],   // 索引为0和6的GridItem占用一行  
  }  
  
  layoutOptions2: GridLayoutOptions = {  
    regularSize: [1, 1],  
    irregularIndexes: [0, 7],   // 索引为0和7的GridItem占用的列数由onGetIrregularSizeByIndex指定  
    onGetIrregularSizeByIndex: (index: number) => {  
      if (index === 0) {  
        return [1, 5]  
      }  
      return [1, index % 6 + 1]  
    }  
  }  
  
  build() {  
    Column({ space: 5 }) {  
      Grid(this.scroller, this.layoutOptions1) {  
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
          }, (day: string) => day)  
        }, (day: string) => day)  
      }  
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')  
      .columnsGap(10)  
      .rowsGap(10)  
      .scrollBar(BarState.Off)  
      .width('90%')  
      .backgroundColor(0xFAEEE0)  
      .height(300)  
  
      Text('scroll').fontColor(0xCCCCCC).fontSize(9).width('90%')  
      // 不使用scroll，需要undefined占位  
      Grid(undefined, this.layoutOptions2) {  
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
          }, (day: string) => day)  
        }, (day: string) => day)  
      }  
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')  
      .columnsGap(10)  
      .rowsGap(10)  
      .scrollBar(BarState.Off)  
      .width('90%')  
      .backgroundColor(0xFAEEE0)  
      .height(300)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
