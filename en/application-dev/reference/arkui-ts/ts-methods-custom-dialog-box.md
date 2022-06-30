# Custom Dialog Box


> **NOTE**<br>
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **CustomDialogController** class is used to display a custom dialog box.


## APIs

CustomDialogController(value:{builder: CustomDialog, cancel?: () =&gt; void, autoCancel?: boolean, alignment?: DialogAlignment, offset?: Offset, customStyle?: boolean})


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | builder | [CustomDialog](../../ui/ts-component-based-customdialog.md) | Yes | - | Constructor of the custom dialog box content. |
  | cancel | () =&gt; void | No | - | Callback invoked when the dialog box is closed after the overlay exits. |
  | autoCancel | boolean | No | true | Whether to allow users to click the overlay to exit. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment mode of the dialog box in the vertical direction. |
  | offset | {<br/>dx: Length \|[Resource](../../ui/ts-types.md#resource),<br/>dy: Length  \|[Resource](../../ui/ts-types.md#resource)<br/>} | No | - | Offset of the dialog box relative to the alignment position. |
  | customStyle | boolean | No | false | Whether the style of the dialog box is customized. |
  | gridCount<sup>8+</sup> | number                                   | No   | -                       | Count of grid columns occupied by the dialog box. |

- DialogAlignment enums
  | Name | Description |
  | -------- | -------- |
  | Top | Aligns vertically to the top. |
  | Center | Aligns vertically to the middle. |
  | Bottom | Aligns vertically to the bottom. |
  | Default | Default alignment. |
  | TopStart<sup>8+</sup> | Top left alignment. |
  | TopEnd<sup>8+</sup> | Top right alignment. |
  | CenterStart<sup>8+</sup> | Center left alignment. |
  | CenterEnd<sup>8+</sup> | Center right alignment. |
  | BottomStart<sup>8+</sup> | Bottom left alignment. |
  | BottomEnd<sup>8+</sup> | Bottom right alignment. |


## CustomDialogController


### Objects to Import


```
dialogController : CustomDialogController = new CustomDialogController(value:{builder: CustomDialog, cancel?: () => void, autoCancel?: boolean})
```

### open()
open(): void


Opens the content of the custom dialog box. If the content has been displayed, this API does not take effect.


### close
close(): void

Closes the custom dialog box. If the dialog box is closed, the setting does not take effect.


## Example


```ts
// xxx.ets
@CustomDialog
struct CustomDialogExample {
  controller: CustomDialogController
  cancel: () => void
  confirm: () => void

  build() {
    Column() {
      Text('Software uninstall').width('70%').fontSize(20).margin({ top: 10, bottom: 10 })
      Image($r('app.media.icon')).width(80).height(80)
      Text('Whether to uninstall a software?').fontSize(16).margin({ bottom: 10 })
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Button('cancel')
          .onClick(() => {
            this.controller.close()
            this.cancel()
          }).backgroundColor(0xffffff).fontColor(Color.Black)
        Button('confirm')
          .onClick(() => {
            this.controller.close()
            this.confirm()
          }).backgroundColor(0xffffff).fontColor(Color.Red)
      }.margin({ bottom: 10 })
    }
  }
}

@Entry
@Component
struct CustomDialogUser {
  dialogController: CustomDialogController = new CustomDialogController({
    builder: CustomDialogExample({ cancel: this.onCancel, confirm: this.onAccept }),
    cancel: this.existApp,
    autoCancel: true
  })

  onCancel() {
    console.info('Callback when the first button is clicked')
  }
  onAccept() {
    console.info('Callback when the second button is clicked')
  }
  existApp() {
    console.info('Click the callback in the blank area')
  }

  build() {
    Column() {
      Button('click me')
        .onClick(() => {
          this.dialogController.open()
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212058470](figures/en-us_image_0000001212058470.gif)
