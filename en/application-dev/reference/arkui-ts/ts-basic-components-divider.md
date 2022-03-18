# Divider


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Divider&gt;** component is used to separate content blocks and content elements.


## Required Permissions

None


## Child Components

None


## APIs

Divider()


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| vertical | boolean | false | Whether&nbsp;a&nbsp;vertical&nbsp;divider&nbsp;is&nbsp;used.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;that&nbsp;a&nbsp;vertical&nbsp;divider&nbsp;is&nbsp;used,&nbsp;and&nbsp;**false**&nbsp;means&nbsp;that&nbsp;a&nbsp;horizontal&nbsp;divider&nbsp;is&nbsp;used. |
| color | Color | - | Color&nbsp;of&nbsp;the&nbsp;divider. |
| strokeWidth | Length | 1 | Width&nbsp;of&nbsp;the&nbsp;divider. |
| lineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle-enums) | LineCapStyle.Butt | Cap&nbsp;style&nbsp;of&nbsp;the&nbsp;divider. |


## Events

Universal events are not supported.


## Example


```
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
