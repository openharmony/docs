# Custom Dialog Box


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **CustomDialogController** class is used to display a custom dialog box.


## APIs

CustomDialogController(value:{builder: CustomDialog, cancel?: () =&gt; void, autoCancel?: boolean})


- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | builder | [CustomDialog](../../ui/ ts-component-based-customdialog.md) | Yes | - | Constructor&nbsp;of&nbsp;the&nbsp;custom&nbsp;dialog&nbsp;box&nbsp;content. |
  | cancel | ()&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;dialog&nbsp;box&nbsp;is&nbsp;closed&nbsp;after&nbsp;the&nbsp;overlay&nbsp;exits. |
  | autoCancel | boolean | No | true | Whether&nbsp;to&nbsp;allow&nbsp;users&nbsp;to&nbsp;click&nbsp;the&nbsp;overlay&nbsp;to&nbsp;exit. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment&nbsp;mode&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;in&nbsp;the&nbsp;vertical&nbsp;direction. |
  | offset | {<br/>dx:&nbsp;Length&nbsp;\|[Resource](../../ui/ts-types.md#resource),<br/>dy:&nbsp;Length&nbsp;&nbsp;\|[Resource](../../ui/ts-types.md#resource)<br/>} |  |  | Offset&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;relative&nbsp;to&nbsp;the&nbsp;alignment&nbsp;position. |
  | customStyle | boolean | No | false | Whether&nbsp;the&nbsp;style&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;is&nbsp;customized. |

- DialogAlignment enums
    | Name | Description | 
  | -------- | -------- |
  | Top | Aligns&nbsp;vertically&nbsp;to&nbsp;the&nbsp;top. | 
  | Center | Aligns&nbsp;vertically&nbsp;to&nbsp;the&nbsp;middle. | 
  | Bottom | Aligns&nbsp;vertically&nbsp;to&nbsp;the&nbsp;bottom. | 
  | Default | Default&nbsp;alignment. | 
  | TopStart<sup>8+</sup> | Top&nbsp;left&nbsp;alignment. | 
  | TopEnd<sup>8+</sup> | Top&nbsp;right&nbsp;alignment. | 
  | CenterStart<sup>8+</sup> | Center&nbsp;left&nbsp;alignment. | 
  | CenterEnd<sup>8+</sup> | Center&nbsp;right&nbsp;alignment. | 
  | BottomStart<sup>8+</sup> | Bottom&nbsp;left&nbsp;alignment. | 
  | BottomEnd<sup>8+</sup> | Bottom&nbsp;right&nbsp;alignment. | 


### CustomDialogController


### Objects to Import


```
dialogController : CustomDialogController = new CustomDialogController(value:{builder: CustomDialog, cancel?: () => void, autoCancel?: boolean})
```


### dialogController.open

open(): void


Opens the content of the custom dialog box. If the content has been displayed, this API does not take effect.


### dialogController.close

close(): void

Closes the custom dialog box. If the dialog box is closed, the setting does not take effect.


## Example


```
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
