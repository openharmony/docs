# Popup Control


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| bindPopup | show:&nbsp;boolean,<br/>popup:&nbsp;PopupOption&nbsp;\|&nbsp;CustomPopupOption | - | Settings&nbsp;of&nbsp;the&nbsp;popup&nbsp;bound&nbsp;to&nbsp;a&nbsp;component.<br/>**show**:&nbsp;whether&nbsp;to&nbsp;display&nbsp;the&nbsp;popup&nbsp;on&nbsp;the&nbsp;creation&nbsp;page&nbsp;by&nbsp;default.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**.<br/>**popup**:&nbsp;parameters&nbsp;of&nbsp;the&nbsp;current&nbsp;popup. | 


- PopupOption attributes
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | message | string | Yes | - | Content&nbsp;of&nbsp;the&nbsp;popup&nbsp;message. | 
  | placementOnTop | boolean | No | false | Whether&nbsp;to&nbsp;display&nbsp;the&nbsp;popup&nbsp;above&nbsp;the&nbsp;component.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. | 
  | primaryButton | {<br/>value:&nbsp;string,<br/>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} | No | - | First&nbsp;button.<br/>**value**:&nbsp;text&nbsp;of&nbsp;the&nbsp;primary&nbsp;button&nbsp;in&nbsp;the&nbsp;popup.<br/>**action**:&nbsp;callback&nbsp;function&nbsp;for&nbsp;clicking&nbsp;the&nbsp;primary&nbsp;button. | 
  | secondaryButton | {<br/>value:&nbsp;string,<br/>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} | No | - | Second&nbsp;button.<br/>**value**:&nbsp;text&nbsp;of&nbsp;the&nbsp;secondary&nbsp;button&nbsp;in&nbsp;the&nbsp;popup.<br/>**action**:&nbsp;callback&nbsp;function&nbsp;for&nbsp;clicking&nbsp;the&nbsp;secondary&nbsp;button. | 
  | onStateChange | (isVisible:&nbsp;boolean)&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;for&nbsp;the&nbsp;popup&nbsp;status&nbsp;change&nbsp;event.&nbsp;The&nbsp;parameter&nbsp;**isVisible**&nbsp;indicates&nbsp;the&nbsp;visibility&nbsp;of&nbsp;the&nbsp;popup. | 

- CustomPopupOption<sup>8+</sup>
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | builder | ()&nbsp;=&gt;&nbsp;any | Yes | - | Builder&nbsp;of&nbsp;the&nbsp;tooltip&nbsp;content. |
  | placement | Placement | No | Placement.Bottom | Preferred&nbsp;position&nbsp;of&nbsp;the&nbsp;tooltip&nbsp;component.&nbsp;If&nbsp;the&nbsp;set&nbsp;position&nbsp;is&nbsp;insufficient&nbsp;for&nbsp;holding&nbsp;the&nbsp;component,&nbsp;it&nbsp;will&nbsp;be&nbsp;automatically&nbsp;adjusted. |
  | maskColor | [Color](../../ui/ts-types.md) | No | - | Color&nbsp;of&nbsp;the&nbsp;tooltip&nbsp;mask. |
  | popupColor | [Color](../../ui/ts-types.md) | No | - | Color&nbsp;of&nbsp;the&nbsp;tooltip. |
  | enableArrow | boolean | No | true | Whether&nbsp;to&nbsp;display&nbsp;arrows.&nbsp;Arrows&nbsp;are&nbsp;displayed&nbsp;only&nbsp;for&nbsp;tooltips&nbsp;in&nbsp;the&nbsp;up&nbsp;and&nbsp;down&nbsp;directions. |
  | autoCancel | boolean | No | true | Whether&nbsp;to&nbsp;automatically&nbsp;close&nbsp;the&nbsp;tooltip&nbsp;when&nbsp;an&nbsp;operation&nbsp;is&nbsp;performed&nbsp;on&nbsp;the&nbsp;page. |
  | onStateChange | (isVisible:&nbsp;boolean)&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;for&nbsp;the&nbsp;popup&nbsp;status&nbsp;change&nbsp;event.&nbsp;The&nbsp;parameter&nbsp;**isVisible**&nbsp;indicates&nbsp;the&nbsp;visibility&nbsp;of&nbsp;the&nbsp;popup. |

- Placement<sup>8+</sup> enums
    | Name | Description | 
  | -------- | -------- |
  | Left | The&nbsp;tooltip&nbsp;is&nbsp;on&nbsp;the&nbsp;left&nbsp;of&nbsp;the&nbsp;component. | 
  | Right | The&nbsp;tooltip&nbsp;is&nbsp;on&nbsp;the&nbsp;right&nbsp;of&nbsp;the&nbsp;component. | 
  | Top | The&nbsp;tooltip&nbsp;is&nbsp;on&nbsp;the&nbsp;top&nbsp;of&nbsp;the&nbsp;component. | 
  | Bottom | The&nbsp;tooltip&nbsp;is&nbsp;at&nbsp;the&nbsp;bottom&nbsp;of&nbsp;the&nbsp;component. | 
  | TopLeft | The&nbsp;tooltip&nbsp;is&nbsp;in&nbsp;the&nbsp;upper&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;component. | 
  | TopRight | The&nbsp;tooltip&nbsp;is&nbsp;in&nbsp;the&nbsp;upper&nbsp;right&nbsp;corner&nbsp;of&nbsp;the&nbsp;component. | 
  | BottomLeft | The&nbsp;tooltip&nbsp;is&nbsp;in&nbsp;the&nbsp;lower&nbsp;left&nbsp;corner&nbsp;of&nbsp;the&nbsp;component. | 
  | BottomRight | The&nbsp;tooltip&nbsp;is&nbsp;in&nbsp;the&nbsp;lower&nbsp;right&nbsp;corner&nbsp;of&nbsp;the&nbsp;component. | 


## Example


```
@Entry
@Component
struct PopupExample {
  @State noHandlePopup: boolean = false
  @State handlePopup: boolean = false
  @State customPopup: boolean = false

  @Builder popupBuilder() {
    Row({ space: 2 }) {
      Image('/resource/ic_public_thumbsup.svg').width(24).height(24).margin({ left: -5 })
      Text('Custom Popup').fontSize(12)
    }.width(100).height(50).backgroundColor(Color.White)
  }

  build() {
    Flex({ direction: FlexDirection.Column }) {
      Button('no handle popup')
        .onClick(() => {
          this.noHandlePopup = !this.noHandlePopup
        })
        .bindPopup(this.noHandlePopup, {
          message: 'content1 content1',
          placementOnTop: false,
          onStateChange: (e) => {
            console.info(e.isVisible.toString())
            if (!e.isVisible) {
              this.noHandlePopup = false
            }
          }
        })
        .position({ x: 100, y: 50 })

      Button('with handle popup')
        .onClick(() => {
          this.handlePopup = !this.handlePopup
        })
        .bindPopup(this.handlePopup, {
          message: 'content2 content2',
          placementOnTop: true,
          primaryButton: {
            value: 'ok',
            action: () => {
              this.handlePopup = !this.handlePopup
              console.info('secondaryButton click')
            }
          },
          onStateChange: (e) => {
            console.info(e.isVisible.toString())
          }
        })
        .position({ x: 100, y: 200 })

      Button('custom popup')
        .onClick(() => {
          this.customPopup = !this.customPopup
        })
        .bindPopup(this.customPopup, {
          builder: this.popupBuilder,
          placement: Placement.Bottom,
          maskColor: 0x33000000,
          popupColor: Color.White,
          enableArrow: true,
          onStateChange: (e) => {
            if (!e.isVisible) {
              this.customPopup = false
            }
          }
        })
        .position({ x: 100, y: 350 })
    }.width('100%').padding({ top: 5 })
  }
}
```

![en-us_image_0000001212058458](figures/en-us_image_0000001212058458.gif)
