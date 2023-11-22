# paste_button    
安全控件的粘贴按钮，用户通过点击该粘贴按钮，可以临时获取读取剪贴板权限，而不会触发toast提示。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## PasteIconStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LINES | 0 | 粘贴按钮展示线条样式图标。 |  
    
## PasteDescription    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PASTE | 0 | 粘贴按钮的文字描述为“粘贴”。 |  
    
## PasteButtonOptions    
创建包含指定元素的粘贴按钮。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| icon | PasteIconStyle | false | false | 设置粘贴按钮的图标风格。<br/>不传入该参数表示没有图标，icon和text至少存在一个。 |  
| text | PasteDescription | false | false | 设置粘贴按钮的文本描述。<br/>不传入该参数表示没有文字描述，icon和text至少存在一个。<br/> |  
| buttonType | ButtonType | false | false | 设置粘贴按钮的背景样式。<br/>不传入该参数表示没有背景。<br/> |  
    
## PasteButtonOnClickResult    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 0 | 粘贴按钮点击成功。 |  
| TEMPORARY_AUTHORIZATION_FAILED | 1 | 粘贴按钮点击后权限授权失败。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- PasteButton(options: PasteButtonOptions)    
起始版本： 10    
    
- PasteButton()    
起始版本： 10    
### onClick<sup>(deprecated)</sup>    
onClick(event: (event: ClickEvent, result: PasteButtonOnClickResult) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (event: ClickEvent, result: PasteButtonOnClickResult) => void | true | 见ClickEvent对象说明。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct Index {  
  build() {  
    Row() {  
      Column({space:10}) {  
        // 默认参数下，图标、文字、背景都存在  
        PasteButton().onClick((event: ClickEvent, result: PasteButtonOnClickResult)=>{  
          console.info("result " + result)  
        })  
        // 传入参数即表示元素存在，不传入的参数表示元素不存在，例如：只显示图标  
        PasteButton({icon:PasteIconStyle.LINES})  
        // 只显示图标+背景  
        PasteButton({icon:PasteIconStyle.LINES, buttonType:ButtonType.Capsule})  
        // 图标、文字、背景都存在  
        PasteButton({icon:PasteIconStyle.LINES, text:PasteDescription.PASTE, buttonType:ButtonType.Capsule})  
      }.width('100%')  
    }.height('100%')  
  }  
}  
    
```    
  
![zh-cn_image_0000001593677984](figures/zh-cn_image_0000001593677984.png)  
