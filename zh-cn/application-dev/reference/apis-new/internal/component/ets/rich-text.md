# rich_text    
富文本组件，解析并显示HTML格式文本。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- RichText(content: string)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| content | string | true |  |  
    
### onStart<sup>(deprecated)</sup>    
onStart(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onComplete<sup>(deprecated)</sup>    
onComplete(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
示例效果请以真机运行为准，当前IDE预览器不支持。  
```ts    
// xxx.ets  
@Entry  
@Component  
struct RichTextExample {  
  @State data: string = '<h1 style="text-align: center;">h1标题</h1>' +  
  '<h1 style="text-align: center;"><i>h1斜体</i></h1>' +  
  '<h1 style="text-align: center;"><u>h1下划线</u></h1>' +  
  '<h2 style="text-align: center;">h2标题</h2>' +  
  '<h3 style="text-align: center;">h3标题</h3>' +  
  '<p style="text-align: center;">p常规<hr/>' +  
  '<div style="width: 500px;height: 500px;border: 1px solid;margin: 0 auto;">' +  
  '<p style="font-size: 35px;text-align: center;font-weight: bold; color: rgb(24,78,228)">字体大小35px,行高45px' +  
  '<p style="background-color: #e5e5e5;line-height: 45px;font-size: 35px;text-indent: 2em;">' +  
  '这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字这是一段文字';  
  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center,  
      justifyContent: FlexAlign.Center }) {  
      RichText(this.data)  
        .onStart(() => {  
          console.info('RichText onStart');  
        })  
        .onComplete(() => {  
          console.info('RichText onComplete');  
        })  
        .width(500)  
        .height(500)  
        .backgroundColor(0XBDDB69)  
      RichText('layoutWeight(1)')  
        .onStart(() => {  
          console.info('RichText onStart');  
        })  
        .onComplete(() => {  
          console.info('RichText onComplete');  
        })  
        .size({ width: '100%', height: 110 })  
        .backgroundColor(0X92D6CC)  
        .layoutWeight(1)  
      RichText('layoutWeight(2)')  
        .onStart(() => {  
          console.info('RichText onStart');  
        })  
        .onComplete(() => {  
          console.info('RichText onComplete');  
        })  
        .size({ width: '100%', height: 110 })  
        .backgroundColor(0X92C48D)  
        .layoutWeight(2)  
    }  
  }  
}  
    
```    
  
![richText](figures/richText.png)  
