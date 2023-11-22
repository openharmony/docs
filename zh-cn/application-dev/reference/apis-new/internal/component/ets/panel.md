# panel    
可滑动面板，提供一种轻量的内容展示窗口，方便在不同尺寸中切换。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## PanelMode    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Mini | 0 | 类型为minibar和foldable时，为最小状态；类型为temporary，则不生效。 |  
| Half | 1 | 类型为foldable和temporary时，为类半屏状态；类型为minibar，则不生效。 |  
| Full | 2 | 类全屏状态。 |  
    
## PanelType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Minibar | 0 | 提供minibar和类全屏展示切换效果。 |  
| Foldable | 1 | 内容永久展示类，提供大（类全屏）、中（类半屏）、小三种尺寸展示切换效果。 |  
| Temporary | 2 | 内容临时展示区，提供大（类全屏）、中（类半屏）两种尺寸展示切换效果。 |  
| CUSTOM<sup>(10+)</sup> | 3 | 配置自适应内容高度，不支持尺寸切换效果。 |  
    
## PanelHeight<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WRAP_CONTENT | wrapContent | 类型为CUSTOM时，自适应内容高度。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Panel(show: boolean)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| show<sup>(7+)</sup> | boolean | true | 控制Panel显示或隐藏。<br/>**说明：** <br/>如果设置为false时，则不占位隐藏。[Visible.None](ts-universal-attributes-visibility.md)或者show之间有一个生效时，都会生效不占位隐藏。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| mode |  PanelMode |  |  
| type |  PanelType |  |  
| dragBar |  boolean |  |  
| customHeight<sup>10+</sup> |  Dimension \| PanelHeight |  |  
| fullHeight |  number \| string |  |  
| halfHeight |  number \| string |  |  
| miniHeight |  number \| string |  |  
| show |  boolean |  |  
| backgroundMask<sup>9+</sup> | null |  |  
| showCloseIcon<sup>10+</sup> |  boolean |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(     event: (       /**        * Width of content area.        *        * @syscap SystemCapability.ArkUI.ArkUI.Full        * @since 7        */       width: number,        /**        * Height of content area.        *        * @syscap SystemCapability.ArkUI.ArkUI.Full        * @since 7        */       height: number,        /**        * Initial state.        *        * @syscap SystemCapability.ArkUI.ArkUI.Full        * @since 7        */       mode: PanelMode,     ) => void,   )    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(7+)</sup> | (       /**        * Width of content area.        *        * @syscap SystemCapability.ArkUI.ArkUI.Full        * @since 7        */       width: number,        /**        * Height of content area.        *        * @syscap SystemCapability.ArkUI.ArkUI.Full        * @since 7        */       height: number,        /**        * Initial state.        *        * @syscap SystemCapability.ArkUI.ArkUI.Full        * @since 7        */       mode: PanelMode,     ) => void | true |  |  
    
### onHeightChange<sup>(deprecated)</sup>    
onHeightChange(callback: (value: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct PanelExample {  
  @State show: boolean = false  
  
  build() {  
    Column() {  
      Text('2021-09-30    Today Calendar: 1.afternoon......Click for details')  
        .width('90%')  
        .height(50)  
        .borderRadius(10)  
        .backgroundColor(0xFFFFFF)  
        .padding({ left: 20 })  
        .onClick(() => {  
          this.show = !this.show  
        })  
      Panel(this.show) { // 展示日程  
        Column() {  
          Text('Today Calendar')  
          Divider()  
          Text('1. afternoon 4:00 The project meeting')  
        }  
      }  
      .type(PanelType.Foldable)  
      .mode(PanelMode.Half)  
      .dragBar(true) // 默认开启  
      .halfHeight(500) // 默认一半  
      .showCloseIcon(true) // 显示关闭图标  
      .onChange((width: number, height: number, mode: PanelMode) => {  
        console.info(`width:${width},height:${height},mode:${mode}`)  
      })  
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001174422896](figures/zh-cn_image_0000001174422896.gif)  
