# data_panel    
数据面板组件，用于将多个数据占比情况使用占比图进行展示。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## DataPanelType<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Line | 0 | 线型数据面板。 |  
| Circle | 1 | 环形数据面板。 |  
    
## ColorStop<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| color<sup>(10+)</sup> | ResourceColor | false | true |  |  
| offset<sup>(10+)</sup> | Length | false | true |  |  
    
## LinearGradient<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## DataPanelShadowOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| colors<sup>(10+)</sup> | Array<ResourceColor \| LinearGradient> | false | false |  |  
    
## DataPanelOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| values | number[] | false | true |  |  
| max | number | false | false |  |  
| type<sup>(8+)</sup> | DataPanelType | false | false |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- DataPanel(options: DataPanelOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(7+)</sup> | DataPanelOptions | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| closeEffect |  boolean |  |  
| valueColors<sup>10+</sup> |  Array<ResourceColor \| LinearGradient> |  |  
| trackBackgroundColor<sup>10+</sup> |  ResourceColor |  |  
| strokeWidth<sup>10+</sup> |  Length |  |  
| trackShadow<sup>10+</sup> |  DataPanelShadowOptions |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct DataPanelExample {  
  public valueArr: number[] = [10, 10, 10, 10, 10, 10, 10, 10, 10]  
  
  build() {  
    Column({ space: 5 }) {  
      Row() {  
        Stack() {  
          DataPanel({ values: [25], max: 100, type: DataPanelType.Circle }).width(168).height(168)  
          Column() {  
            Text('30').fontSize(35).fontColor('#182431')  
            Text('1.0.0').fontSize(9.33).lineHeight(12.83).fontWeight(500).opacity(0.6)  
          }  
  
          Text('%')  
            .fontSize(9.33)  
            .lineHeight(12.83)  
            .fontWeight(500)  
            .opacity(0.6)  
            .position({ x: 104.42, y: 78.17 })  
        }.margin({ right: 44 })  
  
        Stack() {  
          DataPanel({ values: [50, 12, 8, 5], max: 100, type: DataPanelType.Circle }).width(168).height(168)  
          Column() {  
            Text('75').fontSize(35).fontColor('#182431')  
            Text('已使用98GB/128GB').fontSize(8.17).lineHeight(11.08).fontWeight(500).opacity(0.6)  
          }  
  
          Text('%')  
            .fontSize(9.33)  
            .lineHeight(12.83)  
            .fontWeight(500)  
            .opacity(0.6)  
            .position({ x: 104.42, y: 78.17 })  
        }  
      }.margin({ bottom: 59 })  
  
      DataPanel({ values: this.valueArr, max: 100, type: DataPanelType.Line }).width(300).height(10)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![dataPanel](figures/dataPanel.PNG)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct LinearGradientDataPanelExample {  
  public values1: number[] = [20, 20, 20, 20]  
  public color1: LinearGradient = new LinearGradient([{ color: "#65EEC9A3", offset: 0 }, { color: "#FFEF629F", offset: 1 }])  
  public color2: LinearGradient = new LinearGradient([{ color: "#FF67F9D4", offset: 0 }, { color: "#FFFF9554", offset: 1 }])  
  public colorShadow1: LinearGradient = new LinearGradient([{ color: "#65EEC9A3", offset: 0 }, { color: "#65EF629F", offset: 1 }])  
  public colorShadow2: LinearGradient = new LinearGradient([{ color: "#65e26709", offset: 0 }, { color: "#65efbd08", offset: 1 }])  
  public colorShadow3: LinearGradient = new LinearGradient([{ color: "#6572B513", offset: 0 }, { color: "#6508efa6", offset: 1 }])  
  public colorShadow4: LinearGradient = new LinearGradient([{ color: "#65ed08f5", offset: 0 }, { color: "#65ef0849", offset: 1 }])  
  @State color3: string = '#00FF00'  
  @State color4: string = '#20FF0000'  
  @State bgColor: string = '#08182431'  
  @State offsetX: number = 15  
  @State offsetY: number = 15  
  @State radius: number = 5  
  @State colorArray: Array<LinearGradient | ResourceColor> = [this.color1, this.color2, this.color3, this.color4]  
  @State shadowColorArray: Array<LinearGradient | ResourceColor> = [this.colorShadow1, this.colorShadow2, this.colorShadow3, this.colorShadow4]  
  
  build() {  
    Column({ space: 5 }) {  
      Text('LinearGradient').fontSize(9).fontColor(0xCCCCCC).textAlign(TextAlign.Start).width('100%').margin({ top: 20, left: 20})  
      DataPanel({ values: this.values1, max: 100, type: DataPanelType.Circle })  
        .width(300)  
        .height(300)  
        .valueColors(this.colorArray)  
        .trackShadow({  
          radius: this.radius,  
          colors: this.shadowColorArray,  
          offsetX: this.offsetX,  
          offsetY: this.offsetY  
        })  
        .strokeWidth(30)  
        .trackBackgroundColor(this.bgColor)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![LinearGradientDataPanel](figures/LinearGradientDataPanel.PNG)  
