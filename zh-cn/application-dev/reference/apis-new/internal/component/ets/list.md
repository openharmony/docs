# list    
列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ScrollState    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Idle | 0 | 空闲状态。使用控制器提供的方法控制滚动时触发，拖动滚动条滚动时触发。<br/>**说明：** <br/> 从API version 10开始，调整为滚动状态回归空闲时触发，控制器提供的无动画方法控制滚动时触发。 |  
| Scroll | 1 | 滚动状态。使用手指拖动List滚动时触发。<br/>**说明：** <br/> 从API version 10开始，拖动滚动条滚动和滚动鼠标滚轮时也会触发。 |  
| Fling | 2 | 惯性滚动状态。快速划动松手后进行惯性滚动和划动到边缘回弹时触发。<br/>**说明：** <br/> 从API version 10开始，由动画控制的滚动都触发。包括快速划动松手后的惯性滚动，划动到边缘回弹的滚动，快速拖动内置滚动条松手后的惯性滚动，使用滚动控制器提供的带动画的方法控制的滚动。 |  
    
## ListItemAlign<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Start | 0 | ListItem在List中，交叉轴方向首部对齐。 |  
| Center | 1 | ListItem在List中，交叉轴方向居中对齐。 |  
| End | 2 | ListItem在List中，交叉轴方向尾部对齐。 |  
    
## StickyStyle<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | ListItemGroup的header不吸顶，footer不吸底。 |  
| Header | 1 | ListItemGroup的header吸顶，footer不吸底。 |  
| Footer | 2 | ListItemGroup的footer吸底，header不吸底。 |  
    
## ScrollSnapAlign<sup>(10+)</sup>    
设置列表项滚动结束对齐效果。<span style="letter-spacing: 0px;">左右和上下这种两端对齐的样式：当列表位移至末端，则需要将末端的item完整显示，同时不能露出边界空白区域，此时另一端可以出现不限位对齐的现象。</span>  
只支持item等高场景限位，不等高场景可能存在不准确的情况。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 默认无项目滚动对齐效果。滚动结束列表项何时将无限制地停止。 |  
| START | 1 | 视图中的第一项将在列表的开头对齐。<br/>**说明：**<br/>当列表位移至末端，需要将末端的item完整显示，可能出现开头不对齐的情况。 |  
| CENTER | 2 | 视图中的中间项将在列表中心对齐。<br/>**说明：**<br/>顶端和末尾的item都可以在列表中心对齐，列表显示可能露出空白，第一个或最后一个item会对齐到中间位置。 |  
| END | 3 | 视图中的最后一项将在列表末尾对齐。<br/>**说明：**<br/>当列表位移至顶端，需要将顶端的item完整显示，可能出现末尾不对齐的情况。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- List(value?: { initialIndex?: number; space?: number | string; scroller?: Scroller })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| initialIndex<sup>(7+)</sup> | number | false | 设置当前List初次加载时视口起始位置显示的item的索引值。<br/>默认值：0<br/>**说明：** <br/>设置为负数或超过了当前List最后一个item的索引值时视为无效取值，无效取值按默认值显示。 |  
| space<sup>(7+)</sup> | number \| string | false | 子组件主轴方向的间隔。<br/>默认值：0<br/>**说明：** <br/>设置为负数或者大于等于List内容区长度时，按默认值显示。<br/>space参数值小于List分割线宽度时，子组件主轴方向的间隔取分割线宽度。 |  
| scroller<sup>(7+)</sup> | Scroller | false | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/>**说明：** <br/>不允许和其他滚动类组件绑定同一个滚动控制对象。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| lanes<sup>9+</sup> |  number \| LengthConstrain, gutter?: Dimension |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| alignListItem<sup>9+</sup> |  ListItemAlign |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| listDirection |  Axis |  |  
| scrollBar |  BarState |  |  
| edgeEffect |  EdgeEffect |  |  
| divider | null |  |  
| editMode<sup>(deprecated)</sup> |  boolean |  |  
| multiSelectable<sup>8+</sup> |  boolean |  |  
| cachedCount |  number |  |  
| chainAnimation |  boolean |  |  
| chainAnimationOptions<sup>10+</sup> |  ChainAnimationOptions |  |  
| sticky<sup>9+</sup> |  StickyStyle |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| scrollSnapAlign<sup>10+</sup> |  ScrollSnapAlign |  |  
| nestedScroll<sup>10+</sup> |  NestedScrollOptions |  |  
| enableScrollInteraction<sup>10+</sup> |  boolean |  |  
| friction<sup>10+</sup> |  number \| Resource |  |  
    
### onScroll<sup>(deprecated)</sup>    
onScroll(event: (scrollOffset: number, scrollState: ScrollState) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | (scrollOffset: number, scrollState: ScrollState) => void | true | - scrollOffset: 每帧滚动的偏移量，List的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>- [scrollState](#scrollstate枚举说明): 当前滑动状态。 |  
    
### onScrollIndex<sup>(deprecated)</sup>    
onScrollIndex(event: (start: number, end: number, center: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | (start: number, end: number, center: number) => void | true | - start: List显示区域内第一个子组件的索引值。<br/>- end: List显示区域内最后一个子组件的索引值。<br/>- center: List显示区域内中间位置子组件的索引值。<br/> |  
    
### onReachStart<sup>(deprecated)</sup>    
onReachStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | () => void | true |  |  
    
### onReachEnd<sup>(deprecated)</sup>    
onReachEnd(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | () => void | true |  |  
    
### onScrollStart<sup>(deprecated)</sup>    
onScrollStart(event: () => void)    
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(9+)</sup> | () => void | true |  |  
    
### onScrollStop<sup>(deprecated)</sup>    
onScrollStop(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | () => void | true |  |  
    
### onItemDelete    
onItemDelete(event: (index: number) => boolean)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | (index: number) => boolean | true | - index: 被删除的列表项的索引值。<br/> |  
    
### onItemMove<sup>(deprecated)</sup>    
onItemMove(event: (from: number, to: number) => boolean)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | (from: number, to: number) => boolean | true | - from: 移动前索引值。<br/>- to: 移动后索引值<br/> |  
    
### onItemDragStart<sup>(deprecated)</sup>    
onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => ((() => any) | void))    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(8+)</sup> | (event: ItemDragInfo, itemIndex: number) => ((() => any) \| void) | true | - event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 被拖拽列表元素索引值。 |  
    
### onItemDragEnter<sup>(deprecated)</sup>    
onItemDragEnter(event: (event: ItemDragInfo) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(8+)</sup> | (event: ItemDragInfo) => void | true | <span style="letter-spacing: 0px;">- event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。</span>。 |  
    
### onItemDragMove<sup>(deprecated)</sup>    
onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(8+)</sup> | (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void | true | <span style="letter-spacing: 0px;">- event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽起始位置。<br/>- insertIndex: 拖拽插入位置。</span> |  
    
### onItemDragLeave<sup>(deprecated)</sup>    
onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(8+)</sup> | (event: ItemDragInfo, itemIndex: number) => void | true | - event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽离开的列表元素索引值。 |  
    
### onItemDrop<sup>(deprecated)</sup>    
onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(8+)</sup> | (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void | true | - event: 见[ItemDragInfo对象说明](ts-container-grid.md#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽起始位置。<br/>- insertIndex: 拖拽插入位置。<br/>- isSuccess: 是否成功释放。<br/> |  
    
### onScrollFrameBegin<sup>(deprecated)</sup>    
onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number })    
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(9+)</sup> | (offset: number, state: ScrollState) => { offsetRemain: number } | true | <br/>\- offset：即将发生的滑动量，单位vp。<br/>\- state：当前滑动状态。<br/>- offsetRemain：实际滑动量，单位vp。 |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListExample {  
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]  
  
  build() {  
    Column() {  
      List({ space: 20, initialIndex: 0 }) {  
        ForEach(this.arr, (item: number) => {  
          ListItem() {  
            Text('' + item)  
              .width('100%').height(100).fontSize(16)  
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)  
          }  
        }, (item: string) => item)  
      }  
      .listDirection(Axis.Vertical) // 排列方向  
      .scrollBar(BarState.Off)  
      .friction(0.6)  
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线  
      .edgeEffect(EdgeEffect.Spring) // 边缘效果设置为Spring  
      .onScrollIndex((firstIndex: number, lastIndex: number, centerIndex: number) => {  
        console.info('first' + firstIndex)  
        console.info('last' + lastIndex)  
        console.info('center' + centerIndex)  
      })  
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {  
        console.info(`onScroll scrollState = ScrollState` + scrollState + `, scrollOffset = ` + scrollOffset)  
      })  
      .width('90%')  
    }  
    .width('100%')  
    .height('100%')  
    .backgroundColor(0xDCDCDC)  
    .padding({ top: 5 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001174264378](figures/zh-cn_image_0000001174264378.gif)  
    
 **示例代码2：**   
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
        ForEach(this.arr, (item: string) => {  
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
        }, (item: string) => item)  
      }  
      .height(300)  
      .width("90%")  
      .friction(0.6)  
      .border({ width: 3, color: Color.Red })  
      .lanes({ minLength: 40, maxLength: 40 })  
      .alignListItem(this.alignListItem)  
      .scrollBar(BarState.Off)  
  
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
  
![list](figures/list-alignListItem.gif)  
    
 **示例代码3：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListExample {  
  @State arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]  
  @State editFlag: boolean = false  
  
  build() {  
    Stack({ alignContent: Alignment.TopStart }) {  
      Column() {  
        List({ space: 20, initialIndex: 0 }) {  
          ForEach(this.arr, (item: number, index?: number) => {  
            ListItem() {  
              Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center }) {  
                Text('' + item)  
                  .width('100%')  
                  .height(80)  
                  .fontSize(20)  
                  .textAlign(TextAlign.Center)  
                  .borderRadius(10)  
                  .backgroundColor(0xFFFFFF)  
                  .flexShrink(1)  
                if (this.editFlag) {  
                  Button() {  
                    Text("delete").fontSize(16)  
                  }.width('30%').height(40)  
                  .onClick(() => {  
                    if (index != undefined) {  
                      console.info(this.arr[index] + 'Delete')  
                      this.arr.splice(index, 1)  
                      console.info(JSON.stringify(this.arr))  
                      this.editFlag = false  
                    }  
                  }).stateEffect(true)  
                }  
              }  
            }  
          }, (item: string) => item)  
        }.width('90%')  
        .scrollBar(BarState.Off)  
        .friction(0.6)  
      }.width('100%')  
  
      Button('edit list')  
        .onClick(() => {  
          this.editFlag = !this.editFlag  
        }).margin({ top: 5, left: 20 })  
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })  
  }  
}  
    
```    
  
![list](figures/list3.gif)  
    
 **示例代码4：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ListExample {  
  private arr: number[] = []  
  private scrollerForList: Scroller = new Scroller()  
  
  aboutToAppear() {  
    for (let i = 0; i < 20; i++) {  
      this.arr.push(i)  
    }  
  }  
  build() {  
    Column() {  
      Row() {  
        List({ space: 20, initialIndex: 3, scroller: this.scrollerForList }) {  
          ForEach(this.arr, (item: number) => {  
            ListItem() {  
              Text('' + item)  
                .width('100%').height(100).fontSize(16)  
                .textAlign(TextAlign.Center)  
            }  
            .borderRadius(10).backgroundColor(0xFFFFFF)  
            .width('60%')  
            .height('80%')  
          }, (item: number) => JSON.stringify(item))  
        }  
        .chainAnimationOptions({  
          minSpace: 20,  
          maxSpace: 60,  
          edgeEffect: ChainEdgeEffect.STRETCH  
        })  
        .chainAnimation(true)  
        .edgeEffect(EdgeEffect.Spring)  
        .listDirection(Axis.Horizontal)  
        .height('100%')  
        .width('100%')  
        .scrollSnapAlign(ScrollSnapAlign.CENTER)  
        .borderRadius(10)  
        .backgroundColor(0xDCDCDC)  
      }  
      .width('100%')  
      .height('100%')  
      .backgroundColor(0xDCDCDC)  
      .padding({ top: 10 })  
    }  
  }  
}  
    
```    
  
![list](figures/list4.gif)  
