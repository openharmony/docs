# Span


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Span&gt;** component is used to display a paragraph of textual information. It can be used only as a child component in the **&lt;Text&gt;** component.


## Required Permissions

None


## Child Components

None


## APIs

Span(content: string)

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | content | string | Yes | - | Text content. |


## Attributes

In addition to the text style attributes, the attributes below are supported.

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| decoration | {<br/>type: [TextDecorationType](ts-appendix-enums.md#textdecorationtype-enums),<br/>color?: Color<br/>} | {<br/>type: TextDecorationType.None<br/>} | Style and color of the text decorative line. |
| textCase | [TextCase](ts-appendix-enums.md#textcase-enums) | Normal | Text case. |


## Events

Among all the universal events, only the click event is supported.

> **NOTE**<br>
> As the **&lt;Span&gt;** component does not have size information, the **target** attribute of the **ClickEvent** object returned by the click event is invalid.


## Example


```
@Entry
@Component
struct SpanExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Basic Usage').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('This is the Span component').fontSize(12).textCase(TextCase.Normal)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }

      Text('Text Decoration').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Underline-span').decoration({ type: TextDecorationType.Underline, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am LineThrough-span').decoration({ type: TextDecorationType.LineThrough, color: Color.Red }).fontSize(12)
      }
      Text() {
        Span('I am Overline-span').decoration({ type: TextDecorationType.Overline, color: Color.Red }).fontSize(12)
      }

      Text('Text Case').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Lower-span').textCase(TextCase.LowerCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
      Text() {
        Span('I am Upper-span').textCase(TextCase.UpperCase).fontSize(12)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }
    }.width('100%').height(250).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![en-us_image_0000001257138363](figures/en-us_image_0000001257138363.gif)
