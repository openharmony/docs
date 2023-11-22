# tab_content    
仅在Tabs中使用，对应一个切换页签的内容视图。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SelectedMode<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INDICATOR | 0 | 使用下划线模式。 |  
| BOARD | 1 | 使用背板模式。 |  
    
## LayoutMode<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AUTO | 0 | 若页签宽度大于104vp，页签内容为左右排布，否则页签内容为上下排布。仅TabBar为垂直模式或Fixed水平模式时有效。 |  
| VERTICAL | 1 | 页签内容上下排布。 |  
| HORIZONTAL | 2 | 页签内容左右排布。 |  
    
## IndicatorStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| color<sup>(10+)</sup> | ResourceColor | false | false | 下划线的颜色和背板颜色。<br/>默认值:#FF007DFF<br/> |  
| height<sup>(10+)</sup> | Length | false | false | 下划线的高度（不支持百分比设置）。<br/>默认值:2.0<br/>单位：vp<br/> |  
| width<sup>(10+)</sup> | Length | false | false | 下划线的宽度（不支持百分比设置）。<br/>默认值：0.0<br/>单位：vp<br/><strong>说明：</strong><br/>宽度设置为0时，按页签文本宽度显示。<br/> |  
| borderRadius<sup>(10+)</sup> | Length | false | false | 下划线的圆角半径（不支持百分比设置）。<br/>默认值：0.0<br/>单位：vp<br/> |  
| marginTop<sup>(10+)</sup> | Length | false | false | 下划线与文字的间距（不支持百分比设置）。<br/>默认值：8.0<br/>单位：vp。 |  
    
## BoardStyle<sup>(10+)</sup>    
  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| borderRadius<sup>(10+)</sup> | Length | false | false | 背板的圆角半径（不支持百分比设置）。<br/>默认值：8.0<br/>单位：vp<br/> |  
    
## LabelStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| overflow<sup>(10+)</sup> | TextOverflow | false | false | 设置Label文本超长时的显示方式。默认值是省略号截断。 |  
| maxLines<sup>(10+)</sup> | number | false | false | 设置Label文本的最大行数。如果指定此参数，则文本最多不会超过指定的行。如果有多余的文本，可以通过textOverflow来指定截断方式。默认值是1。 |  
| minFontSize<sup>(10+)</sup> | number \| ResourceStr | false | false | 设置Label文本最小显示字号（不支持百分比设置）。需配合maxFontSize以及maxLines或布局大小限制使用。自适应文本大小生效后，font.size不生效。默认值是0.0fp。 |  
| maxFontSize<sup>(10+)</sup> | number \| ResourceStr | false | false | 设置Label文本最大显示字号（不支持百分比设置）。需配合minFontSize以及maxLines或布局大小限制使用。自适应文本大小生效后，font.size不生效。默认值是0.0fp。 |  
| heightAdaptivePolicy<sup>(10+)</sup> | TextHeightAdaptivePolicy | false | false | 设置Label文本自适应高度的方式。默认值是最大行数优先。 |  
| font<sup>(10+)</sup> | Font | false | false | 设置Label文本字体样式。<br/>当页签为子页签时，默认值是字体大小16.0fp、字体类型'HarmonyOS Sans'，字体风格正常，字重正常。<br/>当页签为底部页签时，默认值是字体大小10.0fp、字体类型'HarmonyOS Sans'，字体风格正常，字重中等。 |  
    
## SubTabBarStyle<sup>(9+)</sup>    
子页签样式。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### of<sup>(10+)</sup>  
 **调用形式：**     
- static of(content: ResourceStr): SubTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| content | ResourceStr | true | 页签内的文字内容。从API version 10开始，content类型为ResourceStr。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SubTabBarStyle |  |  
    
### indicator<sup>(10+)</sup>    
设置选中子页签的下划线风格。子页签的下划线风格仅在水平模式下有效。  
 **调用形式：**     
- indicator(value: IndicatorStyle): SubTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | IndicatorStyle | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SubTabBarStyle |  |  
    
### selectedMode<sup>(10+)</sup>    
设置选中子页签的显示方式。  
默认值：SelectedMode.INDICATOR  
  
 **调用形式：**     
- selectedMode(value: SelectedMode): SubTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | SelectedMode | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SubTabBarStyle |  |  
    
### board<sup>(10+)</sup>    
设置选中子页签的背板风格。子页签的背板风格仅在水平模式下有效。  
  
 **调用形式：**     
- board(value: BoardStyle): SubTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | BoardStyle | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SubTabBarStyle |  |  
    
### labelStyle<sup>(10+)</sup>    
设置子页签的label文本和字体的样式。  
  
 **调用形式：**     
- labelStyle(value: LabelStyle): SubTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | LabelStyle | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SubTabBarStyle |  |  
    
### padding<sup>(10+)</sup>    
设置子页签的内边距属性（不支持百分比设置）。使用Dimension时，四个方向内边距同时生效。  
默认值：{left:8.0vp,right:8.0vp,top:17.0vp,bottom:18.0vp}  
  
 **调用形式：**     
- padding(value: Padding | Dimension): SubTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SubTabBarStyle |  |  
    
## BottomTabBarStyle<sup>(9+)</sup>    
底部页签和侧边页签样式。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### of<sup>(10+)</sup>  
 **调用形式：**     
- static of(icon: ResourceStr, text: ResourceStr): BottomTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| icon | ResourceStr | true | 页签内的图片内容。从API version 10开始，icon类型为ResourceStr。<br/> |  
| text | ResourceStr | true | 页签内的文字内容。从API version 10开始，text类型为ResourceStr。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BottomTabBarStyle |  |  
    
### labelStyle<sup>(10+)</sup>    
设置子页签的label文本和字体的样式。  
  
 **调用形式：**     
- labelStyle(value: LabelStyle): BottomTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | LabelStyle | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BottomTabBarStyle |  |  
    
### padding<sup>(10+)</sup>    
设置底部页签的内边距属性（不支持百分比设置）。使用Dimension时，四个方向内边距同时生效。  
默认值：{left:4.0vp,right:4.0vp,top:0.0vp,bottom:0.0vp}  
  
 **调用形式：**     
- padding(value: Padding | Dimension): BottomTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BottomTabBarStyle |  |  
    
### layoutMode<sup>(10+)</sup>    
设置底部页签的图片、文字排布的方式，具体参照LayoutMode枚举。  
默认值：LayoutMode.VERTICAL  
  
 **调用形式：**     
- layoutMode(value: LayoutMode): BottomTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | LayoutMode | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BottomTabBarStyle |  |  
    
### verticalAlign<sup>(10+)</sup>    
设置底部页签的图片、文字在垂直方向上的对齐格式。  
默认值：VerticalAlign.Center  
  
 **调用形式：**     
- verticalAlign(value: VerticalAlign): BottomTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | VerticalAlign | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BottomTabBarStyle |  |  
    
### symmetricExtensible<sup>(10+)</sup>    
设置底部页签的图片、文字是否可以对称借左右底部页签的空余位置中的最小值，仅fixed水平模式下在底部页签之间有效。  
默认值：false  
  
 **调用形式：**     
- symmetricExtensible(value: boolean): BottomTabBarStyle  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | boolean | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BottomTabBarStyle |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- TabContent()    
起始版本： 7    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| tabBar |  string \| Resource \| CustomBuilder \|   { icon?: string \| Resource; text?: string \| Resource } |  |  
    
 **示例代码1：**   
```ts    
@Entry  
@Component  
struct TabContentExample {  
  @State fontColor: string = '#182431'  
  @State selectedFontColor: string = '#007DFF'  
  @State currentIndex: number = 0  
  private controller: TabsController = new TabsController()  
  
  @Builder TabBuilder(index: number) {  
    Column() {  
      Image(this.currentIndex === index ? '/common/public_icon_on.svg' : '/common/public_icon_off.svg')  
        .width(24)  
        .height(24)  
        .margin({ bottom: 4 })  
        .objectFit(ImageFit.Contain)  
      Text(`Tab${index + 1}`)  
        .fontColor(this.currentIndex === index ? this.selectedFontColor : this.fontColor)  
        .fontSize(10)  
        .fontWeight(500)  
        .lineHeight(14)  
    }.width('100%')  
  }  
  
  build() {  
    Column() {  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column() {  
            Text('Tab1')  
              .fontSize(36)  
              .fontColor('#182431')  
              .fontWeight(500)  
              .opacity(0.4)  
              .margin({ top: 30, bottom: 56.5 })  
            Divider()  
              .strokeWidth(0.5)  
              .color('#182431')  
              .opacity(0.05)  
          }.width('100%')  
        }.tabBar(this.TabBuilder(0))  
  
        TabContent() {  
          Column() {  
            Text('Tab2')  
              .fontSize(36)  
              .fontColor('#182431')  
              .fontWeight(500)  
              .opacity(0.4)  
              .margin({ top: 30, bottom: 56.5 })  
            Divider()  
              .strokeWidth(0.5)  
              .color('#182431')  
              .opacity(0.05)  
          }.width('100%')  
        }.tabBar(this.TabBuilder(1))  
  
        TabContent() {  
          Column() {  
            Text('Tab3')  
              .fontSize(36)  
              .fontColor('#182431')  
              .fontWeight(500)  
              .opacity(0.4)  
              .margin({ top: 30, bottom: 56.5 })  
            Divider()  
              .strokeWidth(0.5)  
              .color('#182431')  
              .opacity(0.05)  
          }.width('100%')  
        }.tabBar(this.TabBuilder(2))  
  
        TabContent() {  
          Column() {  
            Text('Tab4')  
              .fontSize(36)  
              .fontColor('#182431')  
              .fontWeight(500)  
              .opacity(0.4)  
              .margin({ top: 30, bottom: 56.5 })  
            Divider()  
              .strokeWidth(0.5)  
              .color('#182431')  
              .opacity(0.05)  
          }.width('100%')  
        }.tabBar(this.TabBuilder(3))  
      }  
      .vertical(false)  
      .barHeight(56)  
      .onChange((index: number) => {  
        this.currentIndex = index  
      })  
      .width(360)  
      .height(190)  
      .backgroundColor('#F1F3F5')  
      .margin({ top: 38 })  
    }.width('100%')  
  }  
}  
    
```    
  
![tabContent](figures/tabContent1.gif)  
  
    
 **示例代码2：**   
```ts    
@Entry  
@Component  
struct TabContentExample {  
  @State fontColor: string = '#182431'  
  @State selectedFontColor: string = '#007DFF'  
  @State currentIndex: number = 0  
  private controller: TabsController = new TabsController()  
  
  @Builder TabBuilder(index: number) {  
    Column() {  
      Image(this.currentIndex === index ? '/common/public_icon_on.svg' : '/common/public_icon_off.svg')  
        .width(24)  
        .height(24)  
        .margin({ bottom: 4 })  
        .objectFit(ImageFit.Contain)  
      Text('Tab')  
        .fontColor(this.currentIndex === index ? this.selectedFontColor : this.fontColor)  
        .fontSize(10)  
        .fontWeight(500)  
        .lineHeight(14)  
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)  
  }  
  
  build() {  
    Column() {  
      Tabs({ barPosition: BarPosition.Start, controller: this.controller }) {  
        TabContent()  
          .tabBar(this.TabBuilder(0))  
        TabContent()  
          .tabBar(this.TabBuilder(1))  
        TabContent()  
          .tabBar(this.TabBuilder(2))  
        TabContent()  
          .tabBar(this.TabBuilder(3))  
      }  
      .vertical(true)  
      .barWidth(96)  
      .barHeight(414)  
      .onChange((index: number) => {  
        this.currentIndex = index  
      })  
      .width(96)  
      .height(414)  
      .backgroundColor('#F1F3F5')  
      .margin({ top: 52 })  
    }.width('100%')  
  }  
}  
    
```    
  
![tabContent](figures/tabContent2.gif)  
    
 **示例代码3：**   
```ts    
@Entry  
@Component  
struct TabBarStyleExample {  
  build() {  
    Column({ space: 5 }) {  
      Text("子页签样式")  
      Column() {  
        Tabs({ barPosition: BarPosition.Start }) {  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Pink)  
          }.tabBar(new SubTabBarStyle('Pink'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Yellow)  
          }.tabBar(new SubTabBarStyle('Yellow'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Blue)  
          }.tabBar(new SubTabBarStyle('Blue'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Green)  
          }.tabBar(new SubTabBarStyle('Green'))  
        }  
        .vertical(false)  
        .scrollable(true)  
        .barMode(BarMode.Fixed)  
        .onChange((index: number) => {  
          console.info(index.toString())  
        })  
        .width('100%')  
        .backgroundColor(0xF1F3F5)  
      }.width('100%').height(200)  
      Text("底部页签样式")  
      Column() {  
        Tabs({ barPosition: BarPosition.End }) {  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Pink)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'pink'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Yellow)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Yellow'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Blue)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Blue'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Green)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Green'))  
        }  
        .vertical(false)  
        .scrollable(true)  
        .barMode(BarMode.Fixed)  
        .onChange((index: number) => {  
          console.info(index.toString())  
        })  
        .width('100%')  
        .backgroundColor(0xF1F3F5)  
      }.width('100%').height(200)  
      Text("侧边页签样式")  
      Column() {  
        Tabs({ barPosition: BarPosition.Start }) {  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Pink)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'pink'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Yellow)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Yellow'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Blue)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Blue'))  
  
          TabContent() {  
            Column().width('100%').height('100%').backgroundColor(Color.Green)  
          }.tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), 'Green'))  
        }  
        .vertical(true).scrollable(true).barMode(BarMode.Fixed)  
        .onChange((index: number) => {  
          console.info(index.toString())  
        })  
        .width('100%')  
        .backgroundColor(0xF1F3F5)  
      }.width('100%').height(400)  
    }  
  }  
}  
    
```    
  
![tabbarStyle](figures/TabBarStyle.jpeg)  
    
 **示例代码4：**   
```ts    
@Entry  
@Component  
struct TabsAttr {  
  private controller: TabsController = new TabsController()  
  @State indicatorColor: Color = Color.Blue;  
  @State indicatorWidth: number = 40;  
  @State indicatorHeight: number = 10;  
  @State indicatorBorderRadius: number = 5;  
  @State indicatorSpace: number = 10;  
  @State subTabBorderRadius: number = 20;  
  @State selectedMode: SelectedMode = SelectedMode.INDICATOR;  
  private colorFlag: boolean = true;  
  private widthFlag: boolean = true;  
  private heightFlag: boolean = true;  
  private borderFlag: boolean = true;  
  private spaceFlag: boolean = true;  
  
  build() {  
    Column() {  
      Button("下划线颜色变化").width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          // 对Button组件的宽高属性进行动画配置  
          if (this.colorFlag) {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorColor = Color.Red  
            })  
          } else {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorColor = Color.Yellow  
            })  
          }  
          this.colorFlag = !this.colorFlag  
        })  
      Button("下划线高度变化").width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          // 对Button组件的宽高属性进行动画配置  
          if (this.heightFlag) {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorHeight = 20  
            })  
          } else {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorHeight = 10  
            })  
          }  
          this.heightFlag = !this.heightFlag  
        })  
      Button("下划线宽度变化").width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          // 对Button组件的宽高属性进行动画配置  
          if (this.widthFlag) {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorWidth = 30  
            })  
          } else {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorWidth = 50  
            })  
          }  
          this.widthFlag = !this.widthFlag  
        })  
      Button("下划线圆角半径变化").width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          // 对Button组件的宽高属性进行动画配置  
          if (this.borderFlag) {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorBorderRadius = 0  
            })  
          } else {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorBorderRadius = 5  
            })  
          }  
          this.borderFlag = !this.borderFlag  
        })  
      Button("下划线间距变化").width('100%').margin({ bottom: '12vp' })  
        .onClick((event?: ClickEvent) => {  
          // 对Button组件的宽高属性进行动画配置  
          if (this.spaceFlag) {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorSpace = 20  
            })  
          } else {  
            animateTo({  
              duration: 1000, // 动画时长  
              curve: Curve.Linear, // 动画曲线  
              delay: 200, // 动画延迟  
              iterations: 1, // 播放次数  
              playMode: PlayMode.Normal, // 动画模式  
              onFinish: () => {  
                console.info('play end')  
              }  
            }, () => {  
              this.indicatorSpace = 10  
            })  
          }  
          this.spaceFlag = !this.spaceFlag  
        })  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink).borderRadius('12vp')  
        }.tabBar(SubTabBarStyle.of('pink')  
          .indicator({  
            color: this.indicatorColor, //下划线颜色  
            height: this.indicatorHeight, //下划线高度  
            width: this.indicatorWidth, //下划线宽度  
            borderRadius: this.indicatorBorderRadius, //下划线圆角半径  
            marginTop: this.indicatorSpace //下划线与文字间距  
          })  
          .selectedMode(this.selectedMode)  
          .board({ borderRadius: this.subTabBorderRadius })  
          .labelStyle({})  
        )  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Yellow).borderRadius('12vp')  
        }.tabBar('yellow')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue).borderRadius('12vp')  
        }.tabBar('blue')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green).borderRadius('12vp')  
        }.tabBar('green')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Gray).borderRadius('12vp')  
        }.tabBar('gray')  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Orange).borderRadius('12vp')  
        }.tabBar('orange')  
      }  
      .vertical(false)  
      .scrollable(true)  
      .barMode(BarMode.Scrollable)  
      .barHeight(140)  
      .animationDuration(400)  
      .onChange((index: number) => {  
        console.info(index.toString())  
      })  
      .backgroundColor(0xF5F5F5)  
      .height(320)  
    }.width('100%').height(250).padding({ top: '24vp', left: '24vp', right: '24vp' })  
  }  
}  
    
```    
  
![tabContent3](figures/tabContent3.gif)  
    
 **示例代码5：**   
```ts    
@Entry  
@Component  
struct TabsTextOverflow {  
  @State message: string = 'Hello World'  
  private controller: TabsController = new TabsController()  
  @State subTabOverflowOpaque: boolean = true;  
  build() {  
    Column() {  
      Tabs({ barPosition: BarPosition.Start, controller: this.controller }) {  
        TabContent() {  
          Column(){  
            Text('单行省略号截断').fontSize(30).fontColor(0xFF000000)  
          }.width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(SubTabBarStyle.of('开始【单行省略号截断单行省略号截断单行省略号截断单行省略号截断单行省略号截断单行省略号截断单行省略号截断单行省略号截断单行省略号截断单行省略号截断】结束')  
          .labelStyle({ overflow: TextOverflow.Ellipsis, maxLines: 1, minFontSize: 10, heightAdaptivePolicy: TextHeightAdaptivePolicy.MAX_LINES_FIRST,  
            font: { size: 20 } }))  
        TabContent() {  
          Column()  
          {  
            Text('先缩小再截断').fontSize(30).fontColor(0xFF000000)  
          }.width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(SubTabBarStyle.of('开始【先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断先缩小再截断】结束')  
          .labelStyle({ overflow: TextOverflow.Clip, maxLines: 1, minFontSize: 15, maxFontSize: 15, heightAdaptivePolicy: TextHeightAdaptivePolicy.MIN_FONT_SIZE_FIRST,  
            font: { size: 20 } }))  
        TabContent() {  
          Column(){  
            Text('先缩小再换行再截断').fontSize(30).fontColor(0xFF000000)  
          }.width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(SubTabBarStyle.of('开始【先缩小再换行再截断先缩小再换行再截断先缩小再换行再截断先缩小再换行再截断先缩小再换行再截断先缩小再换行再截断先缩小再换行再截断先缩小再换行再截断】结束')  
          .labelStyle({ overflow: TextOverflow.Clip, maxLines: 2, minFontSize: 15, maxFontSize: 15, heightAdaptivePolicy: TextHeightAdaptivePolicy.MIN_FONT_SIZE_FIRST,  
            font: { size: 20 } }))  
        TabContent() {  
          Column() {  
            Text('换行').fontSize(30).fontColor(0xFF000000)  
          }  
          .width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(SubTabBarStyle.of('开始【换行换行换行换行换行换行换行换行换行换行换行换行换行换行换行】结束')  
          .labelStyle({ overflow: TextOverflow.Clip, maxLines: 10, minFontSize: 10, heightAdaptivePolicy: TextHeightAdaptivePolicy.MAX_LINES_FIRST,  
            font: { size: 20 } }))  
      }  
      .vertical(true).scrollable(true)  
      .barMode(BarMode.Fixed)  
      .barHeight(720)  
      .barWidth(200).animationDuration(400)  
      .onChange((index: number) => {  
        console.info(index.toString())  
      })  
      .height('100%').width('100%')  
    }  
    .height('100%')  
  }  
}  
```  
  
![tabContent4](figures/tabContent4.png)  
  
### 示例6  
  
```ts  
// xxx.ets  
@Entry  
@Component  
struct TabContentExample6 {  
  private controller: TabsController = new TabsController()  
  @State text: string = "2"  
  @State tabPadding: number = 0;  
  @State symmetricExtensible: boolean = false;  
  @State layoutMode: LayoutMode = LayoutMode.VERTICAL;  
  @State verticalAlign: VerticalAlign = VerticalAlign.Center;  
  
  build() {  
    Column() {  
      Row() {  
        Button("padding+10 " + this.tabPadding)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.tabPadding += 10  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("padding-10 " + this.tabPadding)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.tabPadding -= 10  
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
            this.text = "2"  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("symmetricExtensible改变 " + this.symmetricExtensible)  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.symmetricExtensible = !this.symmetricExtensible  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutMode垂直 ")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.layoutMode = LayoutMode.VERTICAL;  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("layoutMode水平 ")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.layoutMode = LayoutMode.HORIZONTAL;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("verticalAlign朝上")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.verticalAlign = VerticalAlign.Top;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("verticalAlign居中")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.verticalAlign = VerticalAlign.Center;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("verticalAlign朝下")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.verticalAlign = VerticalAlign.Bottom;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), "1"))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), this.text)  
          .padding(this.tabPadding)  
          .verticalAlign(this.verticalAlign)  
          .layoutMode(this.layoutMode)  
          .symmetricExtensible(this.symmetricExtensible))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), "3"))  
      }  
      .animationDuration(300)  
      .height('60%')  
      .backgroundColor(0xf1f3f5)  
      .barMode(BarMode.Fixed)  
    }  
    .width('100%')  
    .height(500)  
    .margin({ top: 5 })  
    .padding('24vp')  
  }  
}  
    
```    
  
![tabContent4](figures/tabContent4.png)  
    
 **示例代码6：**   
```null    
// xxx.ets  
@Entry  
@Component  
struct TabContentExample6 {  
  private controller: TabsController = new TabsController()  
  @State text: string = "2"  
  @State tabPadding: number = 0;  
  @State symmetricExtensible: boolean = false;  
  @State layoutMode: LayoutMode = LayoutMode.VERTICAL;  
  @State verticalAlign: VerticalAlign = VerticalAlign.Center;  
  
  build() {  
    Column() {  
      Row() {  
        Button("padding+10 " + this.tabPadding)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.tabPadding += 10  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("padding-10 " + this.tabPadding)  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.tabPadding -= 10  
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
            this.text = "2"  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("symmetricExtensible改变 " + this.symmetricExtensible)  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.symmetricExtensible = !this.symmetricExtensible  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("layoutMode垂直 ")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.layoutMode = LayoutMode.VERTICAL;  
          })  
          .margin({ right: '6%', bottom: '12vp' })  
        Button("layoutMode水平 ")  
          .width('47%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.layoutMode = LayoutMode.HORIZONTAL;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("verticalAlign朝上")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.verticalAlign = VerticalAlign.Top;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("verticalAlign居中")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.verticalAlign = VerticalAlign.Center;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
      Row() {  
        Button("verticalAlign朝下")  
          .width('100%')  
          .height(50)  
          .margin({ top: 5 })  
          .onClick((event?: ClickEvent) => {  
            this.verticalAlign = VerticalAlign.Bottom;  
          })  
          .margin({ bottom: '12vp' })  
      }  
  
  
      Tabs({ barPosition: BarPosition.End, controller: this.controller }) {  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Pink)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), "1"))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Green)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), this.text)  
          .padding(this.tabPadding)  
          .verticalAlign(this.verticalAlign)  
          .layoutMode(this.layoutMode)  
          .symmetricExtensible(this.symmetricExtensible))  
  
        TabContent() {  
          Column().width('100%').height('100%').backgroundColor(Color.Blue)  
        }.tabBar(BottomTabBarStyle.of($r("sys.media.ohos_app_icon"), "3"))  
      }  
      .animationDuration(300)  
      .height('60%')  
      .backgroundColor(0xf1f3f5)  
      .barMode(BarMode.Fixed)  
    }  
    .width('100%')  
    .height(500)  
    .margin({ top: 5 })  
    .padding('24vp')  
  }  
}  
    
```    
  
![tabContent4](figures/tabContent5.gif)  
