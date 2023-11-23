# units    
ArkUI为开发者提供4种像素单位，框架采用vp为基准数据单位。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## Resource  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## Length  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
    
| 取值范围 | 说明 |  
| --------| --------|  
| string |  |  
| number |  |  
| Resource |  |  
    
## PX<sup>(10+)</sup>    
屏幕物理像素单位。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## VP<sup>(10+)</sup>    
屏幕密度相关像素，根据屏幕像素密度转换为屏幕物理像素，当数值不带单位时，默认单位vp。在实际宽度为1440物理像素的屏幕上，1vp约等于3px。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
    
| 取值范围 | 说明 |  
| --------| --------|  
| `${number}vp` |  |  
| number |  |  
    
## FP<sup>(10+)</sup>    
字体像素，与vp类似适用屏幕密度变化，随系统字体大小设置变化。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## LPX<sup>(10+)</sup>    
视窗逻辑像素单位，lpx单位为实际屏幕宽度与逻辑宽度（通过[designWidth](../../quick-start/module-configuration-file.md#pages标签)配置）的比值，designWidth默认值为720。当designWidth为720时，在实际宽度为1440物理像素的屏幕上，1lpx为2px大小。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## Percentage<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## Degree<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## Dimension<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
    
| 取值范围 | 说明 |  
| --------| --------|  
| PX |  |  
| VP |  |  
| FP |  |  
| LPX |  |  
| Percentage |  |  
| Resource |  |  
    
## ResourceStr  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
    
| 取值范围 | 说明 |  
| --------| --------|  
| string |  |  
| Resource |  |  
    
## Padding  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| top | Length | false | false |  |  
| right | Length | false | false |  |  
| bottom | Length | false | false |  |  
| left | Length | false | false |  |  
    
## EdgeWidths<sup>(9+)</sup>  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| top<sup>(9+)</sup> | Length | false | false |  |  
| right<sup>(9+)</sup> | Length | false | false |  |  
| bottom<sup>(9+)</sup> | Length | false | false |  |  
| left<sup>(9+)</sup> | Length | false | false |  |  
    
## BorderRadiuses<sup>(9+)</sup>  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| topLeft<sup>(9+)</sup> | Length | false | false |  |  
| topRight<sup>(9+)</sup> | Length | false | false |  |  
| bottomLeft<sup>(9+)</sup> | Length | false | false |  |  
| bottomRight<sup>(9+)</sup> | Length | false | false |  |  
    
## EdgeColors<sup>(9+)</sup>  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| top<sup>(9+)</sup> | ResourceColor | false | false |  |  
| right<sup>(9+)</sup> | ResourceColor | false | false |  |  
| bottom<sup>(9+)</sup> | ResourceColor | false | false |  |  
| left<sup>(9+)</sup> | ResourceColor | false | false |  |  
    
## EdgeStyles<sup>(9+)</sup>  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| top<sup>(9+)</sup> | BorderStyle | false | false |  |  
| right<sup>(9+)</sup> | BorderStyle | false | false |  |  
| bottom<sup>(9+)</sup> | BorderStyle | false | false |  |  
| left<sup>(9+)</sup> | BorderStyle | false | false |  |  
    
## Offset  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| dx | Length | false | true |  |  
| dy | Length | false | true |  |  
    
## ResourceColor  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
    
| 取值范围 | 说明 |  
| --------| --------|  
| Color |  |  
| number |  |  
| string |  |  
| Resource |  |  
    
## LengthConstrain<sup>(9+)</sup>  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| minLength<sup>(9+)</sup> | Length | false | true |  |  
| maxLength<sup>(9+)</sup> | Length | false | true |  |  
    
## Font  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| size | Length | false | false |  |  
| weight | FontWeight \| number \| string | false | false |  |  
| family | string \| Resource | false | false |  |  
| style | FontStyle | false | false |  |  
    
## Area<sup>(8+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width<sup>(8+)</sup> | Length | false | true |  |  
| height<sup>(8+)</sup> | Length | false | true |  |  
| position<sup>(8+)</sup> | Position | false | true |  |  
| globalPosition<sup>(8+)</sup> | Position | false | true |  |  
    
## Position  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | Length | false | false |  |  
| y | Length | false | false |  |  
    
## ConstraintSizeOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| minWidth | Length | false | false |  |  
| maxWidth | Length | false | false |  |  
| minHeight | Length | false | false |  |  
| maxHeight | Length | false | false |  |  
    
## SizeOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width | Length | false | false |  |  
| height | Length | false | false |  |  
    
## BorderOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width | EdgeWidths \| Length | false | false |  |  
| color | EdgeColors \| ResourceColor | false | false |  |  
| radius | BorderRadiuses \| Length | false | false |  |  
| style | EdgeStyles \| BorderStyle | false | false |  |  
    
## MarkStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| strokeColor<sup>(10+)</sup> | ResourceColor | false | false |  |  
| size<sup>(10+)</sup> | Length | false | false |  |  
| strokeWidth<sup>(10+)</sup> | Length | false | false |  |  
    
## ColorFilter<sup>(9+)</sup>  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct Example {  
  build() {  
    Column() {  
      Flex({ wrap: FlexWrap.Wrap }) {  
        Column() {  
          Text("width(220)")  
            .width(220)  
            .height(40)  
            .backgroundColor(0xF9CF93)  
            .textAlign(TextAlign.Center)  
            .fontColor(Color.White)  
            .fontSize('12vp')  
        }.margin(5)  
  
        Column() {  
          Text("width('220px')")  
            .width('220px')  
            .height(40)  
            .backgroundColor(0xF9CF93)  
            .textAlign(TextAlign.Center)  
            .fontColor(Color.White)  
        }.margin(5)  
  
        Column() {  
          Text("width('220vp')")  
            .width('220vp')  
            .height(40)  
            .backgroundColor(0xF9CF93)  
            .textAlign(TextAlign.Center)  
            .fontColor(Color.White)  
            .fontSize('12vp')  
        }.margin(5)  
  
        Column() {  
          Text("width('220lpx') designWidth:720")  
            .width('220lpx')  
            .height(40)  
            .backgroundColor(0xF9CF93)  
            .textAlign(TextAlign.Center)  
            .fontColor(Color.White)  
            .fontSize('12vp')  
        }.margin(5)  
  
        Column() {  
          Text("width(vp2px(220) + 'px')")  
            .width(vp2px(220) + 'px')  
            .height(40)  
            .backgroundColor(0xF9CF93)  
            .textAlign(TextAlign.Center)  
            .fontColor(Color.White)  
            .fontSize('12vp')  
        }.margin(5)  
  
        Column() {  
          Text("fontSize('12fp')")  
            .width(220)  
            .height(40)  
            .backgroundColor(0xF9CF93)  
            .textAlign(TextAlign.Center)  
            .fontColor(Color.White)  
            .fontSize('12fp')  
        }.margin(5)  
  
        Column() {  
          Text("width(px2vp(220))")  
            .width(px2vp(220))  
            .height(40)  
            .backgroundColor(0xF9CF93)  
            .textAlign(TextAlign.Center)  
            .fontColor(Color.White)  
            .fontSize('12fp')  
        }.margin(5)  
      }.width('100%')  
    }  
  }  
}  
    
```    
  
