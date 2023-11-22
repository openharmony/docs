# scroll    
可滚动的容器组件，当子组件的布局尺寸超过父组件的尺寸时，内容可以滚动。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ScrollDirection    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Vertical | 0 | 仅支持竖直方向滚动<br/> |  
| Horizontal | 1 | 仅支持水平方向滚动<br/> |  
| Free<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>支持竖直或水平方向滚动<br/>从API version 9开始废弃<br/> |  
| None | 3 | 不可滚动<br/> |  
    
## ScrollAlign<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| START | 0 | 首部对齐。指定item首部与List首部对齐<br/> |  
| CENTER | 1 | 居中对齐。指定item主轴方向居中对齐于List<br/> |  
| END | 2 | 尾部对齐。指定item尾部与List尾部对齐<br/> |  
| AUTO | 3 | 自动对齐。<br/>若指定item完全处于显示区，不做调整。否则依照滑动距离最短的原则，将指定item首部对齐或尾部对齐于List,使指定item完全处于显示区<br/> |  
    
## Scroller    
可滚动容器组件的控制器，可以将此组件绑定至容器组件，然后通过它控制容器组件的滚动，同一个控制器不可以控制多个容器组件，目前支持绑定到List、Scroll、ScrollBar、Grid、WaterFlow上  
    
### scrollTo    
滑动到指定位置。  
  
 **调用形式：**     
- scrollTo(value: {     /**      * The X-axis offset.      *      * @type { number | string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     xOffset: number | string;      /**      * The Y-axis offset.      *      * @type { number | string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     yOffset: number | string;      /**      * Descriptive animation.      *      * @type { ?object } The object type provides custom animation parameters      * and the boolean type enables default spring animation.      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     animation?: { duration?: number; curve?: Curve | ICurve } | boolean;   })  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | {     /**      * The X-axis offset.      *      * @type { number \| string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     xOffset: number \| string;      /**      * The Y-axis offset.      *      * @type { number \| string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     yOffset: number \| string;      /**      * Descriptive animation.      *      * @type { ?object } The object type provides custom animation parameters      * and the boolean type enables default spring animation.      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @crossplatform      * @since 10      */     animation?: { duration?: number; curve?: Curve \| ICurve } \| boolean;   } | true |  |  
    
### scrollEdge    
滚动到容器边缘，不区分滚动轴方向，Edge.Top和Edge.Start表现相同，Edge.Bottom和Edge.End表现相同。  
 **调用形式：**     
- scrollEdge(value: Edge)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | Edge | true | 滚动到的边缘位置<br/> |  
    
### scrollPage<sup>(deprecated)</sup>    
滚动到下一页或者上一页。  
  
 **调用形式：**     
- scrollPage(value: { next: boolean; direction?: Axis })  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| next<sup>(deprecated)</sup> | boolean | true | 是否向下翻页。true表示向下翻页，false表示向上翻页。<br/> |  
| direction<sup>(deprecated)</sup> | Axis | false | 设置滚动方向为水平或竖直方向。<br/>从API version 9开始废弃<br/> |  
    
### currentOffset    
返回当前的滚动偏移量。  
  
 **调用形式：**     
- currentOffset()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### scrollToIndex    
滑动到指定Index。开启smooth动效时，会对经过的所有item进行加载和布局计算，当大量加载item时会导致性能问题。  
 **调用形式：**     
- scrollToIndex(value: number, smooth?: boolean, align?: ScrollAlign)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 要滑动到的目标元素在当前容器中的索引值。<br/><strong>说明：</strong><br/>value值设置成负值或者大于当前容器子组件的最大索引值，视为异常值，本次跳转不生效<br/> |  
| smooth | boolean | false | 设置滑动到列表项在列表中的索引值时是否有动效，true表示有动效，false表示没有动效。<br/>默认值：false。<br/><strong>说明：</strong><br/>当前仅List组件支持该参数<br/> |  
| align | ScrollAlign | false | 指定滑动到的元素与当前容器的对齐方式。<br/>List中的默认值为：ScrollAlign.START。Grid中默认值为：ScrollAlign.AUTO<br/><strong>说明：</strong><br/>当前仅List、Grid组件支持该参数<br/> |  
    
### scrollBy<sup>(9+)</sup>    
滑动指定距离  
  
 **调用形式：**     
- scrollBy(dx: Length, dy: Length)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dx | Length | true | 水平方向滚动距离，不支持百分比形式<br/> |  
| dy | Length | true | 竖直方向滚动距离，不支持百分比形式<br/> |  
    
### isAtEnd<sup>(10+)</sup>    
查询组件是否滚动到底部  
  
 **调用形式：**     
- isAtEnd(): boolean  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true表示组件已经滚动到底部，false表示组件还没滚动到底部 |  
    
## ScrollSnapOptions    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| snapAlign<sup>(10+)</sup> | ScrollSnapAlign | false | true | 设置Scroll组件限位滚动时的对其方式。<br/><strong>说明：</strong><br/>1.该属性默认值为ScrollSnapAlign.NONE。<br/>2.该接口仅当snapPagination属性为Dimension时生效，不支持Array<Dimension>。<br/> |  
| snapPagination<sup>(10+)</sup> | Dimension \| Array<Dimension> | false | false | 设置Scroll组件限位滚动时的限位点，限位点即为Scroll组件能滑动停靠的偏移量。<br/><strong>说明：</strong><br/>1.当属性为Dimension时，表示每页的大小，系统会安装该大小来自动计算每个限位点的位置：如当Dimension为500时，实际的限位点即为[0,500,1000,1500,...]。<br/>2.当属性为Array<Dimension>时，每个Dimension代表限位点的位置。每个Dimension的范围为[0,可滑动距离]，0和可滑动距离的底部自动成为限位点。<br/>3.当该属性不填或者Dimension为小于等于0的输入时，按异常值，无限位滚动处理。当该属性值为Array<Dimension>数组时，数组中的数值必须为单调递增。<br/>4.当输入为百分比时，实际的大小为Scroll组件的视口与百分比数值之积。<br/> |  
| enableSnapToStart<sup>(10+)</sup> | boolean | false | false | 在Scroll组件限位滚动模式下，该属性设置为false后，运行Scroll在开头和第一个限位点间自由滑动。<br/><strong>说明：</strong><br/>1.该属性值默认为true。<br/>2.该属性仅当snapPagination属性为Array<Dimension>时生效，不支持Dimension。<br/> |  
| enableSnapToEnd<sup>(10+)</sup> | boolean | false | false | 在Scroll组件限位滚动模式下，该属性设置为false后，运行Scroll在最后一个限位点和末尾间自由滑动。<br/><strong>说明：</strong><br/>1.该属性值默认为true。<br/>2.该属性仅当snapPagination属性为Array<Dimension>时生效，不支持Dimension。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Scroll(scroller?: Scroller)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| scroller<sup>(7+)</sup> | Scroller | false | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| scrollable |  ScrollDirection |  |  
| scrollBar | null |  |  
| scrollBarColor | null |  |  
| scrollBarWidth |  number \| string |  |  
| edgeEffect | null |  |  
| nestedScroll<sup>10+</sup> |  NestedScrollOptions |  |  
| enableScrollInteraction<sup>10+</sup> |  boolean |  |  
| friction<sup>10+</sup> |  number \| Resource |  |  
| scrollSnap<sup>10+</sup> |  ScrollSnapOptions |  |  
    
### onScroll<sup>(deprecated)</sup>    
onScroll(event: (xOffset: number, yOffset: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | (xOffset: number, yOffset: number) => void | true |  |  
    
### onScrollEdge<sup>(deprecated)</sup>    
onScrollEdge(event: (side: Edge) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | (side: Edge) => void | true |  |  
    
### onScrollStart<sup>(deprecated)</sup>    
onScrollStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(9+)</sup> | () => void | true |  |  
    
### onScrollEnd    
onScrollEnd(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | () => void | true |  |  
    
### onScrollStop<sup>(deprecated)</sup>    
onScrollStop(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(9+)</sup> | () => void | true |  |  
    
### onScrollFrameBegin<sup>(deprecated)</sup>    
onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number })    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(9+)</sup> | (offset: number, state: ScrollState) => { offsetRemain: number } | true |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
import Curves from '@ohos.curves'  
  
@Entry  
@Component  
struct ScrollExample {  
  scroller: Scroller = new Scroller()  
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]  
  
  build() {  
    Stack({ alignContent: Alignment.TopStart }) {  
      Scroll(this.scroller) {  
        Column() {  
          ForEach(this.arr, (item: number) => {  
            Text(item.toString())  
              .width('90%')  
              .height(150)  
              .backgroundColor(0xFFFFFF)  
              .borderRadius(15)  
              .fontSize(16)  
              .textAlign(TextAlign.Center)  
              .margin({ top: 10 })  
          }, (item: string) => item)  
        }.width('100%')  
      }  
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向  
      .scrollBar(BarState.On) // 滚动条常驻显示  
      .scrollBarColor(Color.Gray) // 滚动条颜色  
      .scrollBarWidth(10) // 滚动条宽度  
      .friction(0.6)  
      .edgeEffect(EdgeEffect.None)  
      .onScroll((xOffset: number, yOffset: number) => {  
        console.info(xOffset + ' ' + yOffset)  
      })  
      .onScrollEdge((side: Edge) => {  
        console.info('To the edge')  
      })  
      .onScrollEnd(() => {  
        console.info('Scroll Stop')  
      })  
  
      Button('scroll 150')  
        .height('5%')  
        .onClick(() => { // 点击后下滑指定距离150.0vp  
          this.scroller.scrollBy(0, 150)  
        })  
        .margin({ top: 10, left: 20 })  
      Button('scroll 100')  
        .height('5%')  
        .onClick(() => { // 点击后滑动到指定位置，即下滑100.0vp的距离  
          const yOffset: number = this.scroller.currentOffset().yOffset;  
          this.scroller.scrollTo({ xOffset: 0, yOffset: yOffset + 100 })  
        })  
        .margin({ top: 60, left: 20 })  
      Button('scroll 100')  
        .height('5%')  
        .onClick(() => { // 点击后滑动到指定位置，即下滑100.0vp的距离，滑动过程配置有动画  
          let curve = Curves.interpolatingSpring(100, 1, 228, 30) //创建一个阶梯曲线  
          const yOffset: number = this.scroller.currentOffset().yOffset;  
          this.scroller.scrollTo({ xOffset: 0, yOffset: yOffset + 100, animation: { duration: 1000, curve: curve } })  
        })  
        .margin({ top: 110, left: 20 })  
      Button('back top')  
        .height('5%')  
        .onClick(() => { // 点击后回到顶部  
          this.scroller.scrollEdge(Edge.Top)  
        })  
        .margin({ top: 160, left: 20 })  
      Button('next page')  
        .height('5%')  
        .onClick(() => { // 点击后滑到下一页  
          this.scroller.scrollPage({ next: true })  
        })  
        .margin({ top: 210, left: 20 })  
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)  
  }  
}  
    
```    
  
![zh-cn_image_0000001174104386](figures/zh-cn_image_0000001174104386.gif)  
    
 **示例代码2：**   
```ts    
@Entry  
@Component  
struct NestedScroll {  
  @State listPosition: number = 0; // 0代表滚动到List顶部，1代表中间值，2代表滚动到List底部。  
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  
  private scrollerForScroll: Scroller = new Scroller()  
  private scrollerForList: Scroller = new Scroller()  
  
  build() {  
    Flex() {  
      Scroll(this.scrollerForScroll) {  
        Column() {  
          Text("Scroll Area")  
            .width("100%")  
            .height("40%")  
            .backgroundColor(0X330000FF)  
            .fontSize(16)  
            .textAlign(TextAlign.Center)  
            .onClick(() => {  
              this.scrollerForList.scrollToIndex(5)  
            })  
  
          List({ space: 20, scroller: this.scrollerForList }) {  
            ForEach(this.arr, (item: number) => {  
              ListItem() {  
                Text("ListItem" + item)  
                  .width("100%")  
                  .height("100%")  
                  .borderRadius(15)  
                  .fontSize(16)  
                  .textAlign(TextAlign.Center)  
                  .backgroundColor(Color.White)  
              }.width("100%").height(100)  
            }, (item: string) => item)  
          }  
          .width("100%")  
          .height("50%")  
          .edgeEffect(EdgeEffect.None)  
          .friction(0.6)  
          .onReachStart(() => {  
            this.listPosition = 0  
          })  
          .onReachEnd(() => {  
            this.listPosition = 2  
          })  
          .onScrollFrameBegin((offset: number) => {  
            if ((this.listPosition == 0  offset <= 0) || (this.listPosition == 2  offset >= 0)) {  
              this.scrollerForScroll.scrollBy(0, offset)  
              return { offsetRemain: 0 }  
            }  
            this.listPosition = 1  
            return { offsetRemain: offset };  
          })  
  
          Text("Scroll Area")  
            .width("100%")  
            .height("40%")  
            .backgroundColor(0X330000FF)  
            .fontSize(16)  
            .textAlign(TextAlign.Center)  
        }  
      }  
      .width("100%").height("100%")  
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding(20)  
  }  
}  
    
```    
  
![NestedScroll](figures/NestedScroll.gif)  
    
 **示例代码3：**   
```ts    
@Entry  
@Component  
struct StickyNestedScroll {  
  @State message: string = 'Hello World'  
  @State arr: number[] = []  
  
  @Styles  
  listCard() {  
    .backgroundColor(Color.White)  
    .height(72)  
    .width("100%")  
    .borderRadius(12)  
  }  
  
  build() {  
    Scroll() {  
      Column() {  
        Text("Scroll Area")  
          .width("100%")  
          .height("40%")  
          .backgroundColor('#0080DC')  
          .textAlign(TextAlign.Center)  
        Tabs({ barPosition: BarPosition.Start }) {  
          TabContent() {  
            List({ space: 10 }) {  
              ForEach(this.arr, (item: number) => {  
                ListItem() {  
                  Text("item" + item)  
                    .fontSize(16)  
                }.listCard()  
              }, (item: string) => item)  
            }.width("100%")  
            .edgeEffect(EdgeEffect.Spring)  
            .nestedScroll({  
              scrollForward: NestedScrollMode.PARENT_FIRST,  
              scrollBackward: NestedScrollMode.SELF_FIRST  
            })  
          }.tabBar("Tab1")  
  
          TabContent() {  
          }.tabBar("Tab2")  
        }  
        .vertical(false)  
        .height("100%")  
      }.width("100%")  
    }  
    .edgeEffect(EdgeEffect.Spring)  
    .friction(0.6)  
    .backgroundColor('#DCDCDC')  
    .scrollBar(BarState.Off)  
    .width('100%')  
    .height('100%')  
  }  
  
  aboutToAppear() {  
    for (let i = 0; i < 30; i++) {  
      this.arr.push(i)  
    }  
  }  
}  
    
```    
  
![NestedScroll2](figures/NestedScroll2.gif)  
    
 **示例代码4：**   
```ts    
@Entry  
@Component  
struct Index {  
  scroller: Scroller = new Scroller;  
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]  
  build() {  
    Scroll(this.scroller) {  
      Column() {  
        ForEach(this.arr, (item: number) => {  
          Text(item.toString())  
            .width('90%')  
            .height(200)  
            .backgroundColor(0xFFFFFF)  
            .borderWidth(1)  
            .borderColor(Color.Black)  
            .borderRadius(15)  
            .fontSize(16)  
            .textAlign(TextAlign.Center)  
        }, (item: string) => item)  
      }.width('100%').backgroundColor(0xDCDCDC)  
    }  
    .backgroundColor(Color.Yellow)  
    .height('100%')  
    .edgeEffect(EdgeEffect.Spring)  
    .scrollSnap({snapAlign:ScrollSnapAlign.START, snapPagination:400, enableSnapToStart:true, enableSnapToEnd:true})  
  }  
}  
    
```    
  
![NestedScrollSnap](figures/NestedScrollSnap.gif)  
