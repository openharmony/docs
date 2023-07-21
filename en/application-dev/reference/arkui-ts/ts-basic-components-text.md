# Text

The **\<Text>** component is used to display a piece of textual information.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component can contain the [\<Span>](ts-basic-components-span.md) child component.


## APIs

Text(content?: string | Resource)

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| content | string \| [Resource](ts-types.md#resource) | No| Text content. The content and style set for the **\<Text>** component do not take effect when it contains the **\<Span>** child component.<br>Default value: **' '**|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                      | Type                           | Description                                              |
| ----------------------- | ----------------------------------- | ------------------------------------------- |
| textAlign               | [TextAlign](ts-appendix-enums.md#textalign) | Horizontal alignment mode of the text.<br>Default value: **TextAlign.Start**<br>**NOTE**<br>The text takes up the full width of the **\<Text>** component. To set vertical alignment for the text, use the [align](ts-universal-attributes-location.md) attribute. The **align** attribute alone does not control the horizontal position of the text. In other words, **Alignment.TopStart**, **Alignment.Top**, and **Alignment.TopEnd** produce the same effect, top-aligning the text; **Alignment.Start**, **Alignment.Center**, and **Alignment.End** produce the same effect, centered-aligning the text vertically; **Alignment.BottomStart**, **Alignment.Bottom**, and **Alignment.BottomEnd** produce the same effect, bottom-aligning the text. Yet, it can work with the **textAlign** attribute to jointly determine the horizontal position of the text.<br>Since API version 9, this API is supported in ArkTS widgets.|
| textOverflow            | {overflow: [TextOverflow](ts-appendix-enums.md#textoverflow)} | Display mode when the text is too long.<br>Default value: **{overflow: TextOverflow.Clip}**<br>**NOTE**<br/>Text is clipped at the transition between words. To clip text in the middle of a word, add **\u200B** between characters.<br>This attribute must be used with `maxLines` to take effect.<br>Since API version 9, this API is supported in ArkTS widgets.|
| maxLines                | number | Maximum number of lines in the text.<br>Default value: **Infinity**<br>**NOTE**<br/>By default, text is automatically folded. If this attribute is specified, the text will not exceed the specified number of lines. If there is extra text, you can use **textOverflow** to specify how it is displayed.<br>Since API version 9, this API is supported in ArkTS widgets.|
| lineHeight              | string \| number \| [Resource](ts-types.md#resource)  | Text line height. If the value is less than or equal to **0**, the line height is not limited and the font size is adaptive. If the value of the number type, the unit fp is used.<br>Since API version 9, this API is supported in ArkTS widgets.|
| decoration              | {<br>type: [TextDecorationType](ts-appendix-enums.md#textdecorationtype),<br>color?: [ResourceColor](ts-types.md#resourcecolor)<br>} | Style and color of the text decorative line.<br>Default value: {<br>type: TextDecorationType.None,<br>color: Color.Black<br>} <br>Since API version 9, this API is supported in ArkTS widgets.|
| baselineOffset          | number \| string | Baseline offset of the text. The default value is **0**.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br/><br>If this attribute is set to a percentage, the default value is used.|
| letterSpacing           | number \| string | Letter spacing.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br/><br>If this attribute is set to a percentage, the default value is used.|
| minFontSize             | number \| string \| [Resource](ts-types.md#resource)      | Minimum font size.<br>For the setting to take effect, this attribute must be used together with **maxFontSize**, **maxLines**, or layout constraint settings.<br>Since API version 9, this API is supported in ArkTS widgets.                              |
| maxFontSize             | number \| string \| [Resource](ts-types.md#resource)      | Maximum font size.<br>For the setting to take effect, this attribute must be used together with **minFontSize**, **maxLines**, or layout constraint settings.<br>Since API version 9, this API is supported in ArkTS widgets.                               |
| textCase                | [TextCase](ts-appendix-enums.md#textcase) | Text case.<br>Default value: **TextCase.Normal**<br>Since API version 9, this API is supported in ArkTS widgets.|
| copyOption<sup>9+</sup> | [CopyOptions](ts-appendix-enums.md#copyoptions9) | Whether copy and paste is allowed.<br>Default value: **CopyOptions.None**<br>This API is supported in ArkTS widgets.<br>**NOTE**<br/>When this attribute is set to **CopyOptions.InApp** or **CopyOptions.LocalDevice**, a long press on the text will display a context menu that offers the copy and select-all options.|

>  **NOTE**
>
>  The **\<Text>** component cannot contain both the text and the child component **\<Span>**. If both of them exist, only the content in **\<Span>** is displayed.

## Events

The [universal events](ts-universal-events-click.md) are supported.


## Example

### Example 1
Examples of using **textAlign**, **textOverflow**, **maxLines**, and **lineHeight**
```ts
// xxx.ets
@Entry
@Component
struct TextExample1 {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      // Set the horizontal alignment mode for the text.
      // Single-line text
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

      // Multi-line text
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


      // Set the display mode when the text is too long.
      Text('TextOverflow+maxLines').fontSize(9).fontColor(0xCCCCCC)
      // Clip the text when the value of maxLines is exceeded.
      Text('This is the setting of textOverflow to Clip text content This is the setting of textOverflow to None text content. This is the setting of textOverflow to Clip text content This is the setting of textOverflow to None text content.')
        .textOverflow({ overflow: TextOverflow.Clip })
        .maxLines(1)
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)

      // Show an ellipsis (...) when the value of maxLines is exceeded.
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

### Example 2
Example of using **decoration**, **baselineOffset**, **letterSpacing**, and **textCase**:
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

      // Set the text baseline offset.
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

      // Set the letter spacing.
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
      // Display the text in lowercase.
      Text('This is the text content with textCase set to LowerCase.')
        .textCase(TextCase.LowerCase)
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)
        .width('100%')
      // Display the text in uppercase.
      Text('This is the text content with textCase set to UpperCase.')
        .textCase(TextCase.UpperCase)
        .fontSize(12).border({ width: 1 }).padding(10)

    }.height(700).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```
![textExp1](figures/textExp2.png)
