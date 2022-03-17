# Badge


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Badge&gt;** component presents event information on a component.


## Required Permissions

None


## Child Components

This component supports only one child component.


## APIs

Badge(value: {count: number, position?: BadgePosition, maxCount?: number, style?: BadgeStyle})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | count | number | Yes | - | Number&nbsp;of&nbsp;prompt&nbsp;messages. |
  | position | BadgePosition | No | BadgePosition.RightTop | Position&nbsp;to&nbsp;display&nbsp;the&nbsp;badge&nbsp;relative&nbsp;to&nbsp;the&nbsp;parent&nbsp;component. |
  | maxCount | number | No | 99 | Maximum&nbsp;number&nbsp;of&nbsp;prompt&nbsp;messages.&nbsp;When&nbsp;the&nbsp;maximum&nbsp;number&nbsp;is&nbsp;reached,&nbsp;only&nbsp;**maxCount+**&nbsp;is&nbsp;displayed. |
  | style | BadgeStyle | No | - | Style&nbsp;of&nbsp;the&nbsp;**&lt;Badge&gt;**&nbsp;component,&nbsp;including&nbsp;the&nbsp;text&nbsp;color,&nbsp;text&nbsp;size,&nbsp;badge&nbsp;color,&nbsp;and&nbsp;badge&nbsp;size. |

Badge(value: {value: string, position?: BadgePosition, style?: BadgeStyle})

Creates a **&lt;Badge&gt;** component based on the string.

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | string | Yes | - | String&nbsp;of&nbsp;the&nbsp;content&nbsp;to&nbsp;prompt. |
  | position | BadgePosition | No | BadgePosition.RightTop | Display&nbsp;position&nbsp;of&nbsp;the&nbsp;badge. |
  | style | BadgeStyle | No | - | Style&nbsp;of&nbsp;the&nbsp;**&lt;Badge&gt;**&nbsp;component,&nbsp;including&nbsp;the&nbsp;text&nbsp;color,&nbsp;text&nbsp;size,&nbsp;badge&nbsp;color,&nbsp;and&nbsp;badge&nbsp;size. |

- BadgeStyle object
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | color | Color | No | Color.White | Text&nbsp;color. | 
  | fontSize | number&nbsp;\|&nbsp;string | No | 10 | Text&nbsp;size. | 
  | badgeSize | number&nbsp;\|&nbsp;string | Yes | - | Size&nbsp;of&nbsp;the&nbsp;badge. | 
  | badgeColor | Color | No | Color.Red | Color&nbsp;of&nbsp;the&nbsp;badge. | 

- BadgePosition enums
    | Name | Description | 
  | -------- | -------- |
  | Right | The&nbsp;badge&nbsp;is&nbsp;vertically&nbsp;centered&nbsp;on&nbsp;the&nbsp;right&nbsp;of&nbsp;the&nbsp;parent&nbsp;component. | 
  | RightTop | The&nbsp;badge&nbsp;is&nbsp;displayed&nbsp;in&nbsp;the&nbsp;upper&nbsp;right&nbsp;corner&nbsp;of&nbsp;the&nbsp;parent&nbsp;component. | 
  | Left | The&nbsp;badge&nbsp;is&nbsp;vertically&nbsp;centered&nbsp;on&nbsp;the&nbsp;left&nbsp;of&nbsp;the&nbsp;parent&nbsp;component. | 


## Example


```
@Entry
@Component
struct BadgeExample {
  @State counts: number = 1
  @State message: string = 'new'

  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      Badge({
        count: this.counts,
        maxCount: 99,
        style: { color: 0xFFFFFF, fontSize: 16, badgeSize: 20, badgeColor: Color.Red }
      }) {
        Button('message')
          .onClick(() => {
            this.counts++
          })
          .width(100).height(50).backgroundColor(0x317aff)
      }.width(100).height(50)

      Badge({
        value: this.message,
        style: { color: 0xFFFFFF, fontSize: 9, badgeSize: 20, badgeColor: Color.Blue }
      }) {
        Text('message')
          .width(80).height(50).fontSize(16).lineHeight(37)
          .borderRadius(10).textAlign(TextAlign.Center).backgroundColor(0xF3F4ED)
      }.width(80).height(50)

      Badge({
        value: '',
        position: 1,
        style: { badgeSize: 6, badgeColor: Color.Red }
      }) {
        Text('message')
          .width(90).height(50).fontSize(16).lineHeight(37)
          .borderRadius(10).textAlign(TextAlign.Center).backgroundColor(0xF3F4ED)
      }.width(90).height(50)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218470](figures/en-us_image_0000001212218470.gif)
