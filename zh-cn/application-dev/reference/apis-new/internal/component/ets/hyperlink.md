# hyperlink    
超链接组件，组件宽高范围内点击实现跳转。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Hyperlink(address: string | Resource, content?: string | Resource)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| address | string | true | Hyperlink组件跳转的网页。 |  
| content | string | false | Hyperlink组件中超链接显示文本。<br/><strong>说明：</strong><br/>组件内有子组件时，不显示超链接文本。<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| color |  Color \| number \| string \| Resource |  |  
    
 **示例代码：**   
```ts    
@Entry  
@Component  
struct HyperlinkExample {  
  build() {  
    Column() {  
      Column() {  
        Hyperlink('https://example.com/') {  
          Image($r('app.media.bg'))  
            .width(200)  
            .height(100)  
        }  
      }  
  
      Column() {  
        Hyperlink('https://example.com/', 'Go to the developer website') {  
        }  
        .color(Color.Blue)  
      }  
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)  
  }  
}  
    
```    
  
![hyperlink](figures/hyperlink.PNG)  
