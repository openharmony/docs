# Divider

The **\<Divider>** component is used to separate content blocks and elements.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Divider()

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name     | Type        | Description       |
| ----------- | ---------- | ------------------ |
| vertical    | boolean | Whether a vertical divider is used. **false**: A horizontal divider is used.<br>**true**: A vertical divider is used.<br>Default value: **false**|
| color       | [ResourceColor](ts-types.md#resourcecolor) | Color of the divider.|
| strokeWidth | number \| string | Width of the divider.<br>Default value: **1**|
| lineCap     | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | Cap style of the divider.<br>Default value: **LineCapStyle.Butt**|


## Events

The universal events are not supported.


## Example

```ts
// xxx.ets
@Entry
@Component
struct DividerExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Horizontal divider').fontSize(9).fontColor(0xCCCCCC)
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)
      Divider()
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)

      Text('Vertical divider').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, wrap: FlexWrap.Wrap }) {
        Text('bravery')
        Divider().vertical(true).margin(20).height(15)
        Text('effort')
        Divider().vertical(true).margin(20).height(15)
        Text('upward')
      }.width(250)

      Text('Custom Styles').fontSize(9).fontColor(0xCCCCCC)
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)
      Divider().vertical(false).strokeWidth(5).color(0x2788D9).lineCap(LineCapStyle.Round)
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)
    }.width('100%').height(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![en-us_image_0000001257058407](figures/en-us_image_0000001257058407.png)
