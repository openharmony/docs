# tabs    
通过页签进行内容视图切换的容器组件，每个页签对应一个内容视图。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## BarMode    
  
    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Scrollable | 0 | 每一个TabBar均使用实际布局宽度，超过总长度（横向Tabs的barWidth，纵向Tabs的barHeight）后可滑动。<br/> |  
| Fixed | 1 | 所有TabBar平均分配barWidth宽度（纵向时平均分配barHeight高度）。 |  
    
## BarPosition    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Start | 0 | vertical属性方法设置为true时，页签位于容器左侧；vertical属性方法设置为false时，页签位于容器顶部。 |  
| End | 1 | vertical属性方法设置为true时，页签位于容器右侧；vertical属性方法设置为false时，页签位于容器底部。 |  
    
## LayoutStyle<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ALWAYS_CENTER | 0 | 当页签内容超过TabBar宽度时，TabBar可滚动。<br/>当页签内容不超过TabBar宽度时，TabBar不可滚动，页签紧凑居中。<br/> |  
| ALWAYS_AVERAGE_SPLIT | 1 | 当页签内容超过TabBar宽度时，TabBar可滚动。<br/>当页签内容不超过TabBar宽度时，TabBar不可滚动，且所有页签平均分配TabBar宽度。<br/>仅水平模式下有效，否则视为LayoutStyle.ALWAYS_CENTER。<br/> |  
| SPACE_BETWEEN_OR_CENTER | 2 | 当页签内容超过TabBar宽度时，TabBar可滚动。<br/>当页签内容不超过TabBar宽度但超过TabBar宽度一半时，TabBar不可滚动，页签紧凑居中。<br/>当页签内容不超过TabBar宽度一半时，TabBar不可滚动，保证页签居中排列在TabBar宽度一半，且间距相同。<br/> |  
    
## TabsController    
Tabs组件的控制器，用于控制Tabs组件进行页签切换。不支持一个TabsController控制多个Tabs组件。    
### changeIndex    
控制Tabs切换到指定页签。  
 **调用形式：**     
- changeIndex(value: number): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 页签在Tabs里的索引值，索引值从0开始。<br/><strong>说明：</strong><br/>设置小于0或大于最大数量的值时，该事件失效。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Tabs(value?: { barPosition?: BarPosition; index?: number; controller?: TabsController })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| barPosition | BarPosition | false | 设置Tabs的页签位置。<br/>默认值：BarPosition.Start<br/> |  
| index | number | false | 设置当前显示页签的索引。<br/>默认值：0<br/><strong>说明：</strong><br/>设置为小于0的值时按默认值显示。<br/>可选值为[0, TabContent子节点数量-1]。<br/>设置不同值时，默认生效切换动效，可以设置animationDuration为0关闭动画。<br/>从API version 10开始，该参数支持<a href="https://gitee.com/openharmony/docs/blob/weekly_20231010/zh-cn/application-dev/quick-start/arkts-two-way-sync.md">$$</a>双向绑定变量。<br/> |  
| controller | TabsController | false | 设置Tabs控制器。<br/> |  
    
## DividerStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| strokeWidth<sup>(10+)</sup> | Length | false | true | 分割线的线宽（不支持百分比设置）。<br/> |  
| color<sup>(10+)</sup> | ResourceColor | false | false | 分割线的颜色。默认值：#33182431 |  
| startMargin<sup>(10+)</sup> | Length | false | false | 分割线与侧边栏顶端的距离（不支持百分比设置）。<br/>默认值：0.0<br/>单位：vp<br/> |  
| endMargin<sup>(10+)</sup> | Length | false | false | 分割线与侧边栏底端的距离（不支持百分比设置）。<br/>默认值：0.0<br/>单位：vp<br/> |  
    
## BarGridColumnOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sm<sup>(10+)</sup> | number | false | false | 小屏下，页签占用的columns数量，必须是非负偶数。小屏为大于等于320vp但小于600vp。<br/>默认值为-1，代表页签占用TabBar全部宽度。<br/> |  
| md<sup>(10+)</sup> | number | false | false | 中屏下，页签占用的columns数量，必须是非负偶数。中屏为大于等于600vp但小于800vp。<br/>默认值为-1，代表页签占用TabBar全部宽度。<br/> |  
| lg<sup>(10+)</sup> | number | false | false | 大屏下，页签占用的columns数量，必须是非负偶数。大屏为大于等于840vp但小于1024vp。<br/>默认值为-1，代表页签占用TabBar全部宽度。<br/> |  
| margin<sup>(10+)</sup> | Dimension | false | false | 网格模式下的column边距（不支持百分比设置）。<br/>默认值:24.0<br/>单位：vp<br/> |  
| gutter<sup>(10+)</sup> | Dimension | false | false | 网格模式下的column间隔（不支持百分比设置）。<br/>默认值:24.0<br/>单位：vp<br/> |  
    
## ScrollableBarModeOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| margin<sup>(10+)</sup> | Dimension | false | false | Scrollable模式下的TabBar的左右边距（不支持百分比设置）。<br/>默认值：0.0<br/>单位：vp<br/> |  
| nonScrollableLayoutStyle<sup>(10+)</sup> | LayoutStyle | false | false | Scrollable模式下不滚动时的页签排布方式。<br/>默认值：LayoutStyle.ALWAYS_CENTER<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| vertical |  boolean |  |  
| barPosition<sup>9+</sup> |  BarPosition |  |  
| scrollable |  boolean |  |  
| barMode |  BarMode, options?: ScrollableBarModeOptions |  |  
| barWidth<sup>8+</sup> |  Length |  |  
| barHeight<sup>8+</sup> |  Length |  |  
| animationDuration |  number |  |  
| fadingEdge<sup>10+</sup> |  boolean |  |  
| divider<sup>10+</sup> |  DividerStyle \| null |  |  
| barOverlap<sup>10+</sup> |  boolean |  |  
| barBackgroundColor<sup>10+</sup> |  ResourceColor |  |  
| barGridAlign<sup>10+</sup> |  BarGridColumnOptions |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(event: (index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (index: number) => void | true |  |  
    
### onTabBarClick<sup>(deprecated)</sup>    
onTabBarClick(event: (index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | (index: number) => void | true |  |  
    
 **示例代码1：**   
```ts    
@Entry  
@Component  
struct TabsExample {  
  @State fontColor: string = '#182431'  
  @State selectedFontColor: string = '#007DFF'  
  @State currentIndex: number = 0  
  private controller: TabsController = new TabsController()  
  
  @Builder TabBuilder(index: number, name: string) {  
    Column() {  
      Text(name)  
        .fontColor(this.currentIndex === index ? this.selectedFontColor : this.fontColor)  
        .fontSize(16)  
        .fontWeight(this.currentIndex === index ? 500 : 400)  
        .lineHeight(22)  
        .margin({ top: 17, bottom: 7 })  
      Divider()  
        .strokeWidth(2)  
        .color('#007DFF')  
        .opacity(this.currentIndex === index ? 1 : 0)  
    }.width('100%')  
  }  
  
  build() {  
    Column() {  
      Tabs({ barPosition: BarPosition.Start, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor('#00CB87')  
        }.tabBar(this.TabBuilder(0, 'green'))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor('#007DFF')  
        }.tabBar(this.TabBuilder(1, 'blue'))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor('#FFBF00')  
        }.tabBar(this.TabBuilder(2, 'yellow'))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor('#E67C92')  
        }.tabBar(this.TabBuilder(3, 'pink'))  
      }  
      .vertical(false)  
      .barMode(BarMode.Fixed)  
      .barWidth(360)  
      .barHeight(56)  
      .animationDuration(400)  
      .onChange((index: number) => {  
        this.currentIndex = index  
      })  
      .width(360)  
      .height(296)  
      .margin({ top: 52 })  
      .backgroundColor('#F1F3F5')  
    }.width('100%')  
  }  
}  
    
```    
  
![tabs2](figures/tabs2.gif)  
    
 **示例代码2：**   
```ts    
@Entry  
@Component  
struct TabsDivider1 {  
  private controller1: TabsController = new TabsController()  
  @State dividerColor: string = 'red'  
  @State strokeWidth: number = 2  
  @State startMargin: number = 0  
  @State endMargin: number = 0  
  @State nullFlag: boolean = false  
  
  build() {  
    Column() {  
      Tabs({ controller: this.controller1 }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar('pink')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Yellow)  
        }.tabBar('yellow')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar('blue')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Red)  
        }.tabBar('red')  
      }  
      .vertical(true)  
      .scrollable(true)  
      .barMode(BarMode.Fixed)  
      .barWidth(70)  
      .barHeight(200)  
      .animationDuration(400)  
      .onChange((index: number) => {  
        console.info(index.toString())  
      })  
      .height('200vp')  
      .margin({ bottom: '12vp' })  
      .divider(this.nullFlag ? null : {  
        strokeWidth: this.strokeWidth,  
        color: this.dividerColor,  
        startMargin: this.startMargin,  
        endMargin: this.endMargin  
      })  
  
      Button('常规Divider').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          this.nullFlag = false;  
          this.strokeWidth = 2;  
          this.dividerColor = 'red';  
          this.startMargin = 0;  
          this.endMargin = 0;  
        })  
      Button('空Divider').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          this.nullFlag = true  
        })  
      Button('颜色变为蓝色').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          this.dividerColor = 'blue'  
        })  
      Button('宽度增加').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          this.strokeWidth += 2  
        })  
      Button('宽度减小').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          if (this.strokeWidth > 2) {  
            this.strokeWidth -= 2  
          }  
        })  
      Button('上边距增加').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          this.startMargin += 2  
        })  
      Button('上边距减少').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          if (this.startMargin > 2) {  
            this.startMargin -= 2  
          }  
        })  
      Button('下边距增加').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          this.endMargin += 2  
        })  
      Button('下边距减少').width('100%').margin({ bottom: '12vp' })  
        .onClick(() => {  
          if (this.endMargin > 2) {  
            this.endMargin -= 2  
          }  
        })  
    }.padding({ top: '24vp', left: '24vp', right: '24vp' })  
  }  
}  
    
```    
  
![tabs3](figures/tabs3.gif)  
    
 **示例代码3：**   
```ts    
@Entry  
@Component  
struct TabsOpaque {  
  @State message: string = 'Hello World'  
  private controller: TabsController = new TabsController()  
  private controller1: TabsController = new TabsController()  
  @State selfFadingFade: boolean = true;  
  
  build() {  
    Column() {  
      Button('子页签设置渐隐').width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          this.selfFadingFade = true;  
        })  
      Button('子页签设置不渐隐').width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          this.selfFadingFade = false;  
        })  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar('pink')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Yellow)  
        }.tabBar('yellow')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar('blue')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
      }  
      .vertical(false)  
      .scrollable(true)  
      .barMode(BarMode.Scrollable)  
      .barHeight(80)  
      .animationDuration(400)  
      .onChange((index: number) => {  
        console.info(index.toString())  
      })  
      .fadingEdge(this.selfFadingFade)  
      .height('30%')  
      .width('100%')  
  
      Tabs({ barPosition: BarPosition.Start, controller: this.controller1 }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar('pink')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Yellow)  
        }.tabBar('yellow')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar('blue')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar('green')  
      }  
      .vertical(true)  
      .scrollable(true)  
      .barMode(BarMode.Scrollable)  
      .barHeight(200)  
      .barWidth(80)  
      .animationDuration(400)  
      .onChange((index: number) => {  
        console.info(index.toString())  
      })  
      .fadingEdge(this.selfFadingFade)  
      .height('30%')  
      .width('100%')  
    }  
    .padding({ top: '24vp', left: '24vp', right: '24vp' })  
  }  
}  
    
```    
  
![tabs4](figures/tabs4.gif)  
    
 **示例代码4：**   
```ts    
@Entry  
@Component  
struct barBackgroundColorTest {  
  private controller: TabsController = new TabsController()  
  @State barOverlap: boolean = true;  
  @State barBackgroundColor: string = '#88888888';  
  
  build() {  
    Column() {  
      Button("barOverlap变化").width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          if (this.barOverlap) {  
            this.barOverlap = false;  
          } else {  
            this.barOverlap = true;  
          }  
        })  
  
      Tabs({ barPosition: BarPosition.Start, index: 0, controller: this.controller }) {  
        TabContent() {  
          Column() {  
            Text(`barOverlap ${this.barOverlap}`).fontSize(16).margin({ top: this.barOverlap ? '56vp' : 0 })  
            Text(`barBackgroundColor ${this.barBackgroundColor}`).fontSize(16)  
          }.width('100%').width('100%').height('100%')  
          .backgroundColor(Color.Pink)  
        }  
        .tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), "1"))  
  
        TabContent() {  
          Column() {  
            Text(`barOverlap ${this.barOverlap}`).fontSize(16).margin({ top: this.barOverlap ? '56vp' : 0 })  
            Text(`barBackgroundColor ${this.barBackgroundColor}`).fontSize(16)  
          }.width('100%').width('100%').height('100%')  
          .backgroundColor(Color.Yellow)  
        }  
        .tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), "2"))  
  
        TabContent() {  
          Column() {  
            Text(`barOverlap ${this.barOverlap}`).fontSize(16).margin({ top: this.barOverlap ? '56vp' : 0 })  
            Text(`barBackgroundColor ${this.barBackgroundColor}`).fontSize(16)  
          }.width('100%').width('100%').height('100%')  
          .backgroundColor(Color.Green)  
        }  
        .tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), "3"))  
      }  
      .vertical(false)  
      .barMode(BarMode.Fixed)  
      .height('60%')  
      .barOverlap(this.barOverlap)  
      .scrollable(true)  
      .animationDuration(10)  
      .barBackgroundColor(this.barBackgroundColor)  
    }  
    .height(500)  
    .padding({ top: '24vp', left: '24vp', right: '24vp' })  
  }  
}  
```  
  
![tabs5](figures/tabs5.gif)  
  
  
### 示例5  
  
```ts  
// xxx.ets  
@Entry  
@Component  
struct TabsExample5 {  
  private controller: TabsController = new TabsController()  
  @State gridMargin: number = 10  
  @State gridGutter: number = 10  
  @State sm: number = -2  
  @State clickedContent: string = "";  
  
  build() {  
    Column() {  
      Row() {  
        Button("gridMargin+10 " + this.gridMargin)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.gridMargin += 10  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("gridMargin-10 " + this.gridMargin)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.gridMargin -= 10  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("gridGutter+10 " + this.gridGutter)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.gridGutter += 10  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("gridGutter-10 " + this.gridGutter)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.gridGutter -= 10  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("sm+2 " + this.sm)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.sm += 2  
          })  
          .margin({ right: '6%' })  
        Button("sm-2 " + this.sm).width('47%').height(50).margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.sm -= 2  
          })  
      }  
  
      Text("点击内容:" + this.clickedContent).width('100%').height(200).margin({ top: 5 })  
  
  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), "1"))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), "2"))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), "3"))  
      }  
      .width('350vp')  
      .animationDuration(300)  
      .height('60%')  
      .barGridAlign({ sm: this.sm, margin: this.gridMargin, gutter: this.gridGutter })  
      .backgroundColor(0xf1f3f5)  
      .onTabBarClick((index: number) => {  
        this.clickedContent += "now index " + index + " is clicked\n";  
      })  
    }  
    .width('100%')  
    .height(500)  
    .margin({ top: 5 })  
    .padding('10vp')  
  }  
}  
    
```    
  
![tabs5](figures/tabs5.gif)  
    
 **示例代码5：**   
```ts    
@Entry  
@Component  
struct TabsExample6 {  
  private controller: TabsController = new TabsController()  
  @State scrollMargin: number = 0  
  @State layoutStyle: LayoutStyle = LayoutStyle.ALWAYS_CENTER  
  @State text: string = "文本"  
  
  build() {  
    Column() {  
      Row() {  
        Button("scrollMargin+10 " + this.scrollMargin)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.scrollMargin += 10  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("scrollMargin-10 " + this.scrollMargin)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.scrollMargin -= 10  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("文本增加 ")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.text += '文本增加'  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("文本重置")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.text = "文本"  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutStyle.ALWAYS_CENTER")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .fontSize(15)  
          .onClick((event?: ClickEvent) => {  
            this.layoutStyle = LayoutStyle.ALWAYS_CENTER;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutStyle.ALWAYS_AVERAGE_SPLIT")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .fontSize(15)  
          .onClick((event?: ClickEvent) => {  
            this.layoutStyle = LayoutStyle.ALWAYS_AVERAGE_SPLIT;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutStyle.SPACE_BETWEEN_OR_CENTER")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .fontSize(15)  
          .onClick((event?: ClickEvent) => {  
            this.layoutStyle = LayoutStyle.SPACE_BETWEEN_OR_CENTER;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(SubTabBarStyle.of(this.text))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar(SubTabBarStyle.of(this.text))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar(SubTabBarStyle.of(this.text))  
      }  
      .animationDuration(300)  
      .height('60%')  
      .backgroundColor(0xf1f3f5)  
      .barMode(BarMode.Scrollable, { margin: this.scrollMargin, nonScrollableLayoutStyle: this.layoutStyle })  
    }  
    .width('100%')  
    .height(500)  
    .margin({ top: 5 })  
    .padding('24vp')  
  }  
}  
    
```    
  
![tabs5](figures/tabs6.gif)  
    
 **示例代码6：**   
```null    
// xxx.ets  
@Entry  
@Component  
struct TabsExample6 {  
  private controller: TabsController = new TabsController()  
  @State scrollMargin: number = 0  
  @State layoutStyle: LayoutStyle = LayoutStyle.ALWAYS_CENTER  
  @State text: string = "文本"  
  
  build() {  
    Column() {  
      Row() {  
        Button("scrollMargin+10 " + this.scrollMargin)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.scrollMargin += 10  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("scrollMargin-10 " + this.scrollMargin)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.scrollMargin -= 10  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("文本增加 ")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.text += '文本增加'  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("文本重置")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.text = "文本"  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutStyle.ALWAYS_CENTER")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .fontSize(15)  
          .onClick((event?: ClickEvent) => {  
            this.layoutStyle = LayoutStyle.ALWAYS_CENTER;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutStyle.ALWAYS_AVERAGE_SPLIT")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .fontSize(15)  
          .onClick((event?: ClickEvent) => {  
            this.layoutStyle = LayoutStyle.ALWAYS_AVERAGE_SPLIT;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutStyle.SPACE_BETWEEN_OR_CENTER")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .fontSize(15)  
          .onClick((event?: ClickEvent) => {  
            this.layoutStyle = LayoutStyle.SPACE_BETWEEN_OR_CENTER;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(SubTabBarStyle.of(this.text))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar(SubTabBarStyle.of(this.text))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar(SubTabBarStyle.of(this.text))  
      }  
      .animationDuration(300)  
      .height('60%')  
      .backgroundColor(0xf1f3f5)  
      .barMode(BarMode.Scrollable, { margin: this.scrollMargin, nonScrollableLayoutStyle: this.layoutStyle })  
    }  
    .width('100%')  
    .height(500)  
    .margin({ top: 5 })  
    .padding('24vp')  
  }  
}  
    
```    
  
![tabs5](figures/tabs7.gif)  
