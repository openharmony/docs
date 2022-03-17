# Text


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Text&gt;** component is used to display a paragraph of textual information.


## Required Permissions

None


## Child Components

The **&lt;Text&gt;** component can contain the child component [<Span>](../reference/arkui-ts/ts-basic-components-span.md).


## APIs

Text(content?: string)

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | content | string | No | '' | Text&nbsp;content,&nbsp;which&nbsp;is&nbsp;the&nbsp;content&nbsp;of&nbsp;the&nbsp;child&nbsp;component&nbsp;**&lt;Span&gt;**.&nbsp;This&nbsp;parameter&nbsp;does&nbsp;not&nbsp;take&nbsp;effect&nbsp;when&nbsp;the&nbsp;child&nbsp;component&nbsp;**&lt;Span&gt;**&nbsp;is&nbsp;contained. | 


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| textAlign | TextAlign | TextAlign.Start                                              | Text&nbsp;alignment&nbsp;mode&nbsp;of&nbsp;multiple&nbsp;lines&nbsp;of&nbsp;text. |
| textOverflow | {overflow:&nbsp;TextOverflow} | {overflow:&nbsp;TextOverflow.Clip} | Display&nbsp;mode&nbsp;when&nbsp;the&nbsp;text&nbsp;is&nbsp;too&nbsp;long. |
| maxLines | number | Infinity | Maximum&nbsp;number&nbsp;of&nbsp;lines&nbsp;in&nbsp;the&nbsp;text. |
| lineHeight | Length | - | Text&nbsp;line&nbsp;height.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;**0**,&nbsp;the&nbsp;line&nbsp;height&nbsp;is&nbsp;not&nbsp;limited&nbsp;and&nbsp;the&nbsp;font&nbsp;size&nbsp;is&nbsp;adaptive.&nbsp;If&nbsp;the&nbsp;value&nbsp;of&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;unit&nbsp;fp&nbsp;is&nbsp;used. |
| decoration | {<br/>type:&nbsp;TextDecorationType,<br/>color?:&nbsp;Color<br/>} | {<br/>type:&nbsp;TextDecorationType.None,<br/>color:&nbsp;Color.Black<br/>} | Style&nbsp;and&nbsp;color&nbsp;of&nbsp;the&nbsp;text&nbsp;decorative&nbsp;line. |
| baselineOffset | Length | - | Offset&nbsp;of&nbsp;the&nbsp;text&nbsp;baseline. |
| textCase | TextCase | TextCase.Normal | Text&nbsp;case. |

- TextAlign enums
    | Name | Description | 
  | -------- | -------- |
  | Center | The&nbsp;text&nbsp;is&nbsp;center-aligned. | 
  | Start | The&nbsp;text&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;direction&nbsp;in&nbsp;which&nbsp;the&nbsp;text&nbsp;is&nbsp;written. | 
  | End | The&nbsp;text&nbsp;is&nbsp;aligned&nbsp;with&nbsp;the&nbsp;opposite&nbsp;direction&nbsp;in&nbsp;which&nbsp;the&nbsp;text&nbsp;is&nbsp;written. | 

- TextOverflow enums
    | Name | Description | 
  | -------- | -------- |
  | Clip | Extra&nbsp;text&nbsp;is&nbsp;truncated. | 
  | Ellipsis | The&nbsp;ellipsis&nbsp;(...)&nbsp;is&nbsp;used&nbsp;for&nbsp;extra-long&nbsp;text. | 
  | None | No&nbsp;truncation&nbsp;or&nbsp;ellipsis&nbsp;is&nbsp;used&nbsp;for&nbsp;extra-long&nbsp;text. | 

- TextDecorationType enums
    | Name | Description | 
  | -------- | -------- |
  | Underline | An&nbsp;underline&nbsp;is&nbsp;used. | 
  | LineThrough | A&nbsp;strikethrough&nbsp;is&nbsp;used. | 
  | Overline | An&nbsp;overline&nbsp;is&nbsp;used. | 
  | None | No&nbsp;decorative&nbsp;line&nbsp;is&nbsp;used. | 

- TextCase enums
    | Name | Description | 
  | -------- | -------- |
  | Normal | The&nbsp;original&nbsp;case&nbsp;of&nbsp;the&nbsp;text&nbsp;is&nbsp;retained. | 
  | LowerCase | All&nbsp;letters&nbsp;in&nbsp;the&nbsp;text&nbsp;are&nbsp;in&nbsp;lowercase. | 
  | UpperCase | All&nbsp;letters&nbsp;in&nbsp;the&nbsp;text&nbsp;are&nbsp;in&nbsp;uppercase. | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> The **&lt;Text&gt;** component cannot contain both the text and the child component **&lt;Span&gt;**. If both of them exist, only the content in **&lt;Span&gt;** is displayed.


## Example


```
@Entry
@Component
struct TextExample1 {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('lineHeight').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text with the line height set This is the text with the line height set This is the text with the line height set.')
        .lineHeight(25).fontSize(12).border({ width: 1 }).padding(10)

      Text('TextOverflow').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the setting of textOverflow to none text content This is the setting of textOverflow to none text content.')
        .textOverflow({ overflow: TextOverflow.None })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the setting of textOverflow to Clip text content This is the setting of textOverflow to Clip text content.')
        .textOverflow({ overflow: TextOverflow.Clip })
        .maxLines(1).fontSize(12).border({ width: 1 }).padding(10)
      Text('This is set textOverflow to Ellipsis text content This is set textOverflow to Ellipsis text content.')
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .maxLines(1).fontSize(12).border({ width: 1 }).padding(10)

      Text('decoration').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with the decoration set to Underline and the color set to Red.')
        .decoration({ type: TextDecorationType.Underline, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the text content with the decoration set to LineThrough and the color set to Red.')
        .decoration({ type: TextDecorationType.LineThrough, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
      Text('This is the text content with the decoration set to Overline and the color set to Red.')
        .decoration({ type: TextDecorationType.Overline, color: Color.Red })
        .fontSize(12).border({ width: 1 }).padding(10)
    }.height(600).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![en-us_image_0000001257138337](figures/en-us_image_0000001257138337.gif)


```
@Entry
@Component
struct TextExample2 {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('textCase').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with textCase set to Normal.')
        .textCase(TextCase.Normal)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textCase set to LowerCase.')
        .textCase(TextCase.LowerCase)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textCase set to UpperCase.')
        .textCase(TextCase.UpperCase)
        .fontSize(12).border({ width: 1 }).padding(10)

      Text('textAlign').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with textAlign set to Center.')
        .textAlign(TextAlign.Center)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textAlign set to Start.')
        .textAlign(TextAlign.Start)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with textAlign set to End.')
        .textAlign(TextAlign.End)
        .fontSize(12).border({ width: 1 }).padding(10).width('100%')

      Text('baselineOffset').fontSize(9).fontColor(0xCCCCCC)
      Text('This is the text content with baselineOffset set to 10.')
        .baselineOffset(10).fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with baselineOffset set to 30.')
        .baselineOffset(30).fontSize(12).border({ width: 1 }).padding(10).width('100%')
      Text('This is the text content with baselineOffset set to -10.')
        .baselineOffset(-10).fontSize(12).border({ width: 1 }).padding(10).width('100%')
    }.height(700).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![en-us_image_0000001257058391](figures/en-us_image_0000001257058391.gif)
