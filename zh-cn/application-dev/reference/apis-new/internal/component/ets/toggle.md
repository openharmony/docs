# toggle    
组件提供勾选框样式、状态按钮样式及开关样式。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ToggleType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Checkbox | 0 | 提供单选框样式。<br>**说明：**<br/>API version 11开始，Checkbox默认样式由圆角方形变为圆形。<br/>[通用属性margin](ts-universal-attributes-size.md)的默认值为：<br>{<br>top: 14 px,<br>right: 14 px,<br>bottom: 14 px,<br>left: 14 px<br> } |  
| Switch | 1 | 提供开关样式。<br>**说明：**<br/>[通用属性margin](ts-universal-attributes-size.md)默认值为：<br>{<br/>top: 6px,<br/>right: 14px,<br/>bottom: 6 px,<br/>left: 14 px<br/> } |  
| Button | 2 | 提供状态按钮样式，如果子组件有文本设置，则相应的文本内容会显示在按钮内部。 |  
    
## 接口  
  
  
<p>从API version 9开始，该接口支持在ArkTS卡片中使用。</p>  
    
 **调用形式**     
    
- Toggle(options: { type: ToggleType; isOn?: boolean })    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | ToggleType | true | 开关的样式。 |  
| isOn | boolean | false | 开关是否打开，true：打开，false：关闭。<br/>默认值：false<br />从API version 10开始，该参数支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| selectedColor |  ResourceColor |  |  
| switchPointColor | null |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (isOn: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ToggleExample {  
  build() {  
    Column({ space: 10 }) {  
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')  
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {  
        Toggle({ type: ToggleType.Switch, isOn: false })  
          .selectedColor('#007DFF')  
          .switchPointColor('#FFFFFF')  
          .onChange((isOn: boolean) => {  
            console.info('Component status:' + isOn)  
          })  
  
        Toggle({ type: ToggleType.Switch, isOn: true })  
          .selectedColor('#007DFF')  
          .switchPointColor('#FFFFFF')  
          .onChange((isOn: boolean) => {  
            console.info('Component status:' + isOn)  
          })  
      }  
  
      Text('type: Checkbox').fontSize(12).fontColor(0xcccccc).width('90%')  
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {  
        Toggle({ type: ToggleType.Checkbox, isOn: false })  
          .size({ width: 20, height: 20 })  
          .selectedColor('#007DFF')  
          .onChange((isOn: boolean) => {  
            console.info('Component status:' + isOn)  
          })  
  
        Toggle({ type: ToggleType.Checkbox, isOn: true })  
          .size({ width: 20, height: 20 })  
          .selectedColor('#007DFF')  
          .onChange((isOn: boolean) => {  
            console.info('Component status:' + isOn)  
          })  
      }  
  
      Text('type: Button').fontSize(12).fontColor(0xcccccc).width('90%')  
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {  
        Toggle({ type: ToggleType.Button, isOn: false }) {  
          Text('status button').fontColor('#182431').fontSize(12)  
        }.width(106)  
        .selectedColor('rgba(0,125,255,0.20)')  
        .onChange((isOn: boolean) => {  
          console.info('Component status:' + isOn)  
        })  
  
        Toggle({ type: ToggleType.Button, isOn: true }) {  
          Text('status button').fontColor('#182431').fontSize(12)  
        }.width(106)  
        .selectedColor('rgba(0,125,255,0.20)')  
        .onChange((isOn: boolean) => {  
          console.info('Component status:' + isOn)  
        })  
      }  
    }.width('100%').padding(24)  
  }  
}  
    
```    
  
![zh-cn_image_0000001643320073](figures/zh-cn_image_0000001643320073.png)  
