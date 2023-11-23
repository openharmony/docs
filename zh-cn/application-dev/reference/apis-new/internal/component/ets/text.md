# text    
显示一段文本的组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Text(content?: string | Resource)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| content | string | false | 文本内容。包含子组件Span时不生效，显示Span内容，并且此时text组件的样式不生效。<br/>默认值：' '<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| font<sup>10+</sup> |  Font |  |  
| fontColor |  ResourceColor |  |  
| fontSize |  number \| string \| Resource |  |  
| minFontSize |  number \| string \| Resource |  |  
| maxFontSize |  number \| string \| Resource |  |  
| fontStyle |  FontStyle |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| textAlign |  TextAlign |  |  
| lineHeight |  number \| string \| Resource |  |  
| textOverflow |  { overflow: TextOverflow } |  |  
| fontFamily |  string \| Resource |  |  
| maxLines |  number |  |  
| decoration |  { type: TextDecorationType; color?: ResourceColor } |  |  
| letterSpacing |  number \| string |  |  
| textCase |  TextCase |  |  
| baselineOffset |  number \| string |  |  
| copyOption<sup>9+</sup> |  CopyOptions |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| draggable<sup>9+</sup> |  boolean |  |  
| textShadow<sup>10+</sup> |  ShadowOptions |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
| heightAdaptivePolicy<sup>10+</sup> |  TextHeightAdaptivePolicy |  |  
| textIndent<sup>10+</sup> |  Length |  |  
    
 **示例代码1：**   
```ts    
@Entry  
@Component  
struct TextExample1 {  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {  
      // 文本水平方向对齐方式设置  
      // 单行文本  
      Text('textAlign').fontSize(9).fontColor(0xCCCCCC)  
      Text('TextAlign set to Center.')  
        .textAlign(TextAlign.Center)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('TextAlign set to Start.')  
        .textAlign(TextAlign.Start)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('TextAlign set to End.')  
        .textAlign(TextAlign.End)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
  
      // 多行文本  
      Text('This is the text content with textAlign set to Center.')  
        .textAlign(TextAlign.Center)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('This is the text content with textAlign set to Start.')  
        .textAlign(TextAlign.Start)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('This is the text content with textAlign set to End.')  
        .textAlign(TextAlign.End)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
  
  
      // 文本超长时显示方式  
      Text('TextOverflow+maxLines').fontSize(9).fontColor(0xCCCCCC)  
      // 超出maxLines截断内容展示  
      Text('This is the setting of textOverflow to Clip text content This is the setting of textOverflow to None text content. This is the setting of textOverflow to Clip text content This is the setting of textOverflow to None text content.')  
        .textOverflow({ overflow: TextOverflow.Clip })  
        .maxLines(1)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
  
      // 超出maxLines展示省略号  
      Text('This is set textOverflow to Ellipsis text content This is set textOverflow to Ellipsis text content.'.split('')  
        .join('\u200B'))  
        .textOverflow({ overflow: TextOverflow.Ellipsis })  
        .maxLines(1)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
  
      Text('lineHeight').fontSize(9).fontColor(0xCCCCCC)  
      Text('This is the text with the line height set. This is the text with the line height set.')  
        .fontSize(12).border({ width: 1 }).padding(10)  
      Text('This is the text with the line height set. This is the text with the line height set.')  
        .fontSize(12).border({ width: 1 }).padding(10)  
        .lineHeight(20)  
    }.height(600).width(350).padding({ left: 35, right: 35, top: 35 })  
  }  
}  
    
```    
  
![textExp1](figures/textExp1.png)  
    
 **示例代码2：**   
```ts    
@Entry  
@Component  
struct TextExample2 {  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {  
      Text('decoration').fontSize(9).fontColor(0xCCCCCC)  
      Text('This is the text content with the decoration set to LineThrough and the color set to Red.')  
        .decoration({  
          type: TextDecorationType.LineThrough,  
          color: Color.Red  
        })  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
  
  
      Text('This is the text content with the decoration set to Overline and the color set to Red.')  
        .decoration({  
          type: TextDecorationType.Overline,  
          color: Color.Red  
        })  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
  
  
      Text('This is the text content with the decoration set to Underline and the color set to Red.')  
        .decoration({  
          type: TextDecorationType.Underline,  
          color: Color.Red  
        })  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
  
      // 文本基线偏移  
      Text('baselineOffset').fontSize(9).fontColor(0xCCCCCC)  
      Text('This is the text content with baselineOffset 0.')  
        .baselineOffset(0)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('This is the text content with baselineOffset 30.')  
        .baselineOffset(30)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('This is the text content with baselineOffset -20.')  
        .baselineOffset(-20)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
  
      // 文本字符间距  
      Text('letterSpacing').fontSize(9).fontColor(0xCCCCCC)  
      Text('This is the text content with letterSpacing 0.')  
        .letterSpacing(0)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('This is the text content with letterSpacing 3.')  
        .letterSpacing(3)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      Text('This is the text content with letterSpacing -1.')  
        .letterSpacing(-1)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
  
      Text('textCase').fontSize(9).fontColor(0xCCCCCC)  
      Text('This is the text content with textCase set to Normal.')  
        .textCase(TextCase.Normal)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      // 文本全小写展示  
      Text('This is the text content with textCase set to LowerCase.')  
        .textCase(TextCase.LowerCase)  
        .fontSize(12)  
        .border({ width: 1 })  
        .padding(10)  
        .width('100%')  
      // 文本全大写展示  
      Text('This is the text content with textCase set to UpperCase.')  
        .textCase(TextCase.UpperCase)  
        .fontSize(12).border({ width: 1 }).padding(10)  
  
    }.height(700).width(350).padding({ left: 35, right: 35, top: 35 })  
  }  
}  
    
```    
  
![textExp1](figures/textExp2.png)  
    
 **示例代码3：**   
```ts    
@Entry  
@Component  
struct TextExample {  
  build() {  
    Column({ space: 8 }) {  
      Text('textShadow').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      // 设置文字阴影效果  
      Text('textShadow')  
        .width('80%')  
        .height(55)  
        .fontSize(40)  
        .lineHeight(55)  
        .textAlign(TextAlign.Center)  
        .textShadow({ radius: 10, color: Color.Black, offsetX: 0, offsetY: 0 })  
        .borderWidth(1)  
      Divider()  
      // 设置文本自适应高度的方式  
      Text('heightAdaptivePolicy').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      Text('This is the text with the height adaptive policy set')  
        .width('80%')  
        .height(90)  
        .borderWidth(1)  
        .minFontSize(10)  
        .maxFontSize(30)  
        .maxLines(3)  
        .textOverflow({ overflow: TextOverflow.Ellipsis })  
        .heightAdaptivePolicy(TextHeightAdaptivePolicy.MAX_LINES_FIRST)  
      Text('This is the text with the height adaptive policy set')  
        .width('80%')  
        .height(90)  
        .borderWidth(1)  
        .minFontSize(10)  
        .maxFontSize(30)  
        .maxLines(3)  
        .textOverflow({ overflow: TextOverflow.Ellipsis })  
        .heightAdaptivePolicy(TextHeightAdaptivePolicy.MIN_FONT_SIZE_FIRST)  
      Text('This is the text with the height adaptive policy set')  
        .width('80%')  
        .height(90)  
        .borderWidth(1)  
        .minFontSize(10)  
        .maxFontSize(30)  
        .maxLines(3)  
        .textOverflow({ overflow: TextOverflow.Ellipsis })  
        .heightAdaptivePolicy(TextHeightAdaptivePolicy.LAYOUT_CONSTRAINT_FIRST)  
      Divider()  
      Text('marquee').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      // 设置文本超长时以跑马灯的方式展示  
      Text('This is the text with the text overflow set marquee')  
        .width(300)  
        .borderWidth(1)  
        .textOverflow({ overflow: TextOverflow.MARQUEE })  
    }  
  }  
}  
    
```    
  
![](figures/text_3.gif)  
