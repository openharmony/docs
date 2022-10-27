# Popup Control

The popup attribute defines the popup displayed when a component is clicked.

>  **NOTE**
>
>  This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## APIs


| Name          | Type                            | Description                                       |
| ---------- | ------------------------------------- | --------------------------------------- |
| bindPopup  | show: boolean,<br>popup: PopupOptions \| CustomPopupOptions<sup>8+</sup> | Settings of the popup bound to the component.<br>**show**: whether to display the popup on the creation page by default. The default value is **false**.<br>**popup**: parameters of the popup.|

## PopupOptions

| Name                     | Type                                               | Mandatory   | Description                                         |
| -------------------------| ------------------------------------------------| -----| ----------------------------------------- |
| message                  | string                                          | Yes   | Content of the popup message.                                    |
| placementOnTop           | boolean                                         | No   | Whether to display the popup above the component. The default value is **false**.                 |
| primaryButton            | {<br>value: string,<br>action: () =&gt; void<br>} | No   | Primary button.<br>**value**: text of the primary button in the popup.<br>**action**: callback for clicking the primary button.|
| secondaryButton          | {<br>value: string,<br>action: () =&gt; void<br>} | No   | Secondary button.<br>**value**: text of the secondary button in the popup.<br>**action**: callback for clicking the secondary button.|
| onStateChange            | (event: { isVisible: boolean }) =&gt; void | No   | Callback for the popup status change event. The parameter **isVisible** indicates whether the popup is visible.     |

## CustomPopupOptions<sup>8+</sup>

| Name                      | Type                      | Mandatory    | Description                                                |
| -------------------------| ------------------------- | ---- | ---------------------------------------------------- |
| builder                  | [CustomBuilder](ts-types.md#custombuilder8)  | Yes  | Builder of the popup content.                                         |
| placement                | [Placement](ts-appendix-enums.md#placement8) | No  | Preferred position of the popup. If the set position is insufficient for holding the popup, it will be automatically adjusted.<br>Default value: **Placement.Bottom**    |
| maskColor                | [ResourceColor](ts-types.md#resourcecolor)  | No  | Color of the popup mask.                                         |
| popupColor               | [ResourceColor](ts-types.md#resourcecolor)  | No  | Color of the popup.                                              |
| enableArrow              | boolean                                      | No  | Whether to display an arrow. Arrows are displayed only for tooltips in the up and down directions.<br>Default value: **true** |
| autoCancel               | boolean                                      | No  | Whether to automatically close the popup when an operation is performed on the page.<br>Default value: **true**                       |
| onStateChange            | (event: { isVisible: boolean }) =&gt; void | No   | Callback for the popup status change event. The parameter **isVisible** indicates whether the popup is visible.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct PopupExample {
  @State noHandlePopup: boolean = false
  @State handlePopup: boolean = false
  @State customPopup: boolean = false

  @Builder popupBuilder() {
    Row({ space: 2 }) {
      Image('/resource/ic_public_thumbsup.svg').width(24).height(24).margin({ left: -5 })
      Text('Custom Popup').fontSize(10)
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
