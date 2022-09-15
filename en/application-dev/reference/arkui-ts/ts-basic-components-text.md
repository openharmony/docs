# Text

The **\<Text>** component is used to display a piece of textual information.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

This component can contain the [\<Span>](ts-basic-components-span.md) child component.


## APIs

Text(content?: ResourceStr)

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | content | [ResourceStr](../../ui/ts-types.md#resourcestr8) | No| '' | Text content. The content and style set for the **\<Text>** component do not take effect when it contains the **\<Span>** child component.|


## Attributes

In addition to the following attributes, the attributes in [Text Style](ts-universal-attributes-text-style.md) are supported.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| textAlign | [TextAlign](ts-appendix-enums.md#textalign) | TextAlign.Start | Text alignment mode of multiple lines of text.|
| textOverflow | {overflow: [TextOverflow](ts-appendix-enums.md#textoverflow)} | {overflow: TextOverflow.Clip} | Display mode when the text is too long.<br>**NOTE**<br/>Text is truncated at the transition between words. To truncate text in the middle of a word, add **\u200B** between characters.<br>This attribute must be used with `maxLines` to take effect. |
| maxLines | number | Infinity | Maximum number of lines in the text.<br>**NOTE**<br/>By default, text is automatically folded. If this parameter is specified, the text does not exceed the specified number of lines. If there is extra text, you can use `textOverflow` to specify the truncation mode. |
| lineHeight     | string \| number \| [Resource](../../ui/ts-types.md)  | - | Text line height. If the value is less than or equal to **0**, the line height is not limited and the font size is adaptive. If the value of the number type, the unit fp is used.|
| decoration     | {<br>type: TextDecorationType,<br>color?: [ResourceColor](../../ui/ts-types.md)<br>} | {<br>type: TextDecorationType.None,<br>color: Color.Black<br>} | Style and color of the text decorative line.                          |
| baselineOffset | number \| string         | -         | Offset of the text baseline.                             |
| letterSpacing       | [Length](../../ui/ts-types.md)                 | -                          | Letter spacing.                                |
| minFontSize       | number \| string \| [Resource](../../ui/ts-types.md)      | -     | Minimum font size.                                |
| maxFontSize       | number \| string \| [Resource](../../ui/ts-types.md)      | -     | Maximum font size.                                |
| textCase | [TextCase](ts-appendix-enums.md#textcase) | TextCase.Normal | Text case.|
| copyOption<sup>9+</sup> | [CopyOptions](ts-appendix-enums.md#copyoptions9) | CopyOptions.None | Whether copy and paste is allowed.|

>  **NOTE**
>
>  The **\<Text>** component cannot contain both the text and the child component **\<Span>**. If both of them exist, only the content in **\<Span>** is displayed.


## Example

```ts
// xxx.ets
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
      Text('This is set textOverflow to Ellipsis text content This is set textOverflow to Ellipsis text content.'.split('').join('\u200B'))
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

```ts
// xxx.ets
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
