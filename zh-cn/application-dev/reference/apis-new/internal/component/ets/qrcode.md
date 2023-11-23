# qrcode    
用于显示单个二维码的组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- QRCode(value: string)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 二维码内容字符串。最大支持256个字符，若超出，则截取前256个字符。<br/>**说明：** <br/>该字符串内容确保有效，不支持null、undefined以及空内容。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| color |  ResourceColor |  |  
| backgroundColor |  ResourceColor |  |  
| contentOpacity<sup>11+</sup> |  number \| Resource |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct QRCodeExample {  
  private value: string = 'hello world'  
  build() {  
    Column({ space: 5 }) {  
      Text('normal').fontSize(9).width('90%').fontColor(0xCCCCCC).fontSize(30)  
      QRCode(this.value).width(140).height(140)  
  
      // 设置二维码颜色  
      Text('color').fontSize(9).width('90%').fontColor(0xCCCCCC).fontSize(30)  
      QRCode(this.value).color(0xF7CE00).width(140).height(140)  
  
      // 设置二维码背景色  
      Text('backgroundColor').fontSize(9).width('90%').fontColor(0xCCCCCC).fontSize(30)  
      QRCode(this.value).width(140).height(140).backgroundColor(Color.Orange)  
  
      // 设置二维码不透明度  
      Text('contentOpacity').fontSize(9).width('90%').fontColor(0xCCCCCC).fontSize(30)  
      QRCode(this.value).width(140).height(140).color(Color.Black).contentOpacity(0.1)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![qrcode](figures/qrcode.png)  
