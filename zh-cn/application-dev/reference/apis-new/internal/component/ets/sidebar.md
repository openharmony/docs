# sidebar    
提供侧边栏可以显示和隐藏的侧边栏容器，通过子组件定义侧边栏和内容区，第一个子组件表示侧边栏，第二个子组件表示内容区。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SideBarContainerType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Embed | 0 | 侧边栏嵌入到组件内，和内容区并列显示。<br/>组件尺寸小于minContentWidth + minSideBarWidth,并且未设置showSideBar时，侧边栏自动隐藏。<br/>未设置minSideBarWidth或者minContentWidth采用未设置接口的默认值进行计算。<br/>组件在自动隐藏后，如果通过点击控制按钮唤出侧边栏，则侧边栏悬浮在内容区上显示。 |  
| Overlay | 1 | 侧边栏浮在内容区上面<br/> |  
| AUTO<sup>(10+)</sup> | 2 | 组件尺寸大于等于minSideBarWidth+minContentWidth时，采用Embed模式显示。<br/>组件尺寸小于minSideBarWidth+minContentWidth时，采用Overlay模式显示。<br/>未设置minSideBarWidth或minContentWidth时，会使用未设置接口的默认值进行计算，若计算的值小于600vp，则使用600vp做为模式切换的断点值<br/> |  
    
## SideBarPosition<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Start | 0 | 侧边栏位于容器左侧<br/> |  
| End | 1 | 侧边栏位于容器右侧<br/> |  
    
## ButtonStyle  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left | number | false | false | 设置侧边栏控制按钮距离容器左界限的间距。<br/>默认值：16vp<br/>单位：vp<br/> |  
| top | number | false | false | 设置侧边栏控制按钮距离容器上界限的间距。<br/>默认值：48vp<br/>单位：vp。 |  
| width | number | false | false | 设置侧边栏控制按钮的宽度。<br/>默认值：<br/>API version 9及之前版本：32vp<br/>从API version 10开始：24vp<br/>单位：vp<br/> |  
| height | number | false | false | 设置侧边栏控制按钮的高度。<br/>默认值：<br/>API version 9及之前版本：32vp<br/>从API version 10开始：24vp<br/>单位：vp<br/> |  
| icons | {shown: string \| PixelMap \| Resource;hidden: string \| PixelMap \| Resource;switching?: string \| PixelMap \| Resource;} | false | false | 设置侧边栏控制按钮的图标：<br/>- shown: 设置侧边栏显示时控制按钮的图标。<br/><strong>说明：</strong><br/>资源获取错误时，使用默认图标。<br/>- hidden: 设置侧边栏隐藏时控制按钮的图标。<br/>- switching:设置侧边栏显示和隐藏状态切换时控制按钮的图标<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- SideBarContainer(type?: SideBarContainerType)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(8+)</sup> | SideBarContainerType | false | 设置侧边栏的显示类型。<br/>默认值：SideBarContainerType.Embed<br/> |  
    
## DividerStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| strokeWidth<sup>(10+)</sup> | Length | false | true | 分割线的线宽<br/> |  
| color<sup>(10+)</sup> | ResourceColor | false | false | 分割线的颜色。<br/>默认值：#000000，3%<br/> |  
| startMargin<sup>(10+)</sup> | Length | false | false | 分割线与侧边栏顶端的距离。<br/>默认值：0<br/> |  
| endMargin<sup>(10+)</sup> | Length | false | false | 分割线与侧边栏底端的距离。<br/>默认值：0<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| showSideBar |  boolean |  |  
| controlButton |  ButtonStyle |  |  
| showControlButton |  boolean |  |  
| sideBarWidth |  number |  |  
| minSideBarWidth |  number |  |  
| maxSideBarWidth |  number |  |  
| autoHide<sup>9+</sup> |  boolean |  |  
| sideBarPosition<sup>9+</sup> |  SideBarPosition |  |  
| divider<sup>10+</sup> |  DividerStyle \| null |  |  
| minContentWidth<sup>10+</sup> |  Dimension |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct SideBarContainerExample {  
  normalIcon: Resource = $r("app.media.icon")  
  selectedIcon: Resource = $r("app.media.icon")  
  @State arr: number[] = [1, 2, 3]  
  @State current: number = 1  
  
  build() {  
    SideBarContainer(SideBarContainerType.Embed) {  
      Column() {  
        ForEach(this.arr, (item: number) => {  
          Column({ space: 5 }) {  
            Image(this.current === item ? this.selectedIcon : this.normalIcon).width(64).height(64)  
            Text("Index0" + item)  
              .fontSize(25)  
              .fontColor(this.current === item ? '#0A59F7' : '#999')  
              .fontFamily('source-sans-pro,cursive,sans-serif')  
          }  
          .onClick(() => {  
            this.current = item  
          })  
        }, (item: string) => item)  
      }.width('100%')  
      .justifyContent(FlexAlign.SpaceEvenly)  
      .backgroundColor('#19000000')  
  
      Column() {  
        Text('SideBarContainer content text1').fontSize(25)  
        Text('SideBarContainer content text2').fontSize(25)  
      }  
      .margin({ top: 50, left: 20, right: 30 })  
    }  
    .controlButton({  
      icons: {  
        hidden: $r('app.media.drawer'),  
        shown: $r('app.media.drawer'),  
        switching: $r('app.media.drawer')  
      }  
    })  
    .sideBarWidth(150)  
    .minSideBarWidth(50)  
    .maxSideBarWidth(300)  
    .minContentWidth(0)  
    .onChange((value: boolean) => {  
      console.info('status:' + value)  
    })  
    .divider({ strokeWidth: '1vp', color: Color.Gray, startMargin: '4vp', endMargin: '4vp' })  
  }  
}  
    
```    
  
![](figures/sidebarcontainer.png)  
