# span    
作为Text组件和RichEditor组件的子组件，用于显示行内文本的组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Span(value: string | Resource)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 文本内容。<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| font<sup>10+</sup> |  Font |  |  
| fontColor |  ResourceColor |  |  
| fontSize |  number \| string \| Resource |  |  
| fontStyle |  FontStyle |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| fontFamily |  string \| Resource |  |  
| decoration |  { type: TextDecorationType; color?: ResourceColor } |  |  
| letterSpacing |  number \| string |  |  
| textCase |  TextCase |  |  
| lineHeight<sup>10+</sup> |  Length |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct SpanExample {  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {  
      Text('Basic Usage').fontSize(9).fontColor(0xCCCCCC)  
      Text() {  
        Span('In Line')  
        Span(' Component')  
        Span(' !')  
      }  
  
      Text() {  
        Span('This is the Span component').fontSize(12).textCase(TextCase.Normal)  
          .decoration({ type: TextDecorationType.None, color: Color.Red })  
      }  
  
      // 文本横线添加  
      Text('Text Decoration').fontSize(9).fontColor(0xCCCCCC)  
      Text() {  
        Span('I am Underline-span').decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(12)  
      }  
  
      Text() {  
        Span('I am LineThrough-span')  
          .decoration({ type: TextDecorationType.LineThrough, color: Color.Red })  
          .fontSize(12)  
      }  
  
      Text() {  
        Span('I am Overline-span').decoration({ type: TextDecorationType.Overline, color: Color.Red }).fontSize(12)  
      }  
  
      // 文本字符间距  
      Text('LetterSpacing').fontSize(9).fontColor(0xCCCCCC)  
      Text() {  
        Span('span letter spacing')  
          .letterSpacing(0)  
          .fontSize(12)  
      }  
  
      Text() {  
        Span('span letter spacing')  
          .letterSpacing(-2)  
          .fontSize(12)  
      }  
  
      Text() {  
        Span('span letter spacing')  
          .letterSpacing(3)  
          .fontSize(12)  
      }  
  
  
      // 文本大小写展示设置  
      Text('Text Case').fontSize(9).fontColor(0xCCCCCC)  
      Text() {  
        Span('I am Lower-span').fontSize(12)  
          .textCase(TextCase.LowerCase)  
          .decoration({ type: TextDecorationType.None })  
      }  
  
      Text() {  
        Span('I am Upper-span').fontSize(12)  
          .textCase(TextCase.UpperCase)  
          .decoration({ type: TextDecorationType.None })  
      }  
    }.width('100%').height(250).padding({ left: 35, right: 35, top: 35 })  
  }  
}  
    
```    
  
![Span](figures/span.png)  
