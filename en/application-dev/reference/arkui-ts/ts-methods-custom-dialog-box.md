# Custom Dialog Box

A custom dialog box is a dialog box you customize by using APIs of the **CustomDialogController** class. You can set the style and content to your preference for a custom dialog box.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.




## APIs

CustomDialogController(value:{builder: CustomDialog, cancel?: () =&gt; void, autoCancel?: boolean, alignment?: DialogAlignment, offset?: Offset, customStyle?: boolean, gridCount?: number})


**Parameters**

| Name                   | Type                                     | Mandatory | Description                              |
| ---------------------- | ---------------------------------------- | --------- | ---------------------------------------- |
| builder                | CustomDialog                             | Yes       | Constructor of the custom dialog box content. |
| cancel                 | () =&gt; void                            | No        | Callback invoked when the dialog box is closed after the overlay exits. |
| autoCancel             | boolean                                  | No        | Whether to allow users to click the overlay to exit.<br>Default value: **true** |
| alignment              | [DialogAlignment](#dialogalignment)      | No        | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default** |
| offset                 | {<br>dx: Length \| [Resource](ts-types.md#resource),<br>dy: Length  \| [Resource](ts-types.md#resource)<br>} | No        | Offset of the dialog box relative to the alignment position. |
| customStyle            | boolean                                  | No        | Whether to use a custom style for the dialog box.<br>Default value: **false** |
| gridCount<sup>8+</sup> | number                                   | No        | Number of grid columns occupied by the dialog box. |

## DialogAlignment

| Name                     | Description                |
| ------------------------ | -------------------------- |
| Top                      | Vertical top alignment.    |
| Center                   | Vertical center alignment. |
| Bottom                   | Vertical bottom alignment. |
| Default                  | Default alignment.         |
| TopStart<sup>8+</sup>    | Top left alignment.        |
| TopEnd<sup>8+</sup>      | Top right alignment.       |
| CenterStart<sup>8+</sup> | Center left alignment.     |
| CenterEnd<sup>8+</sup>   | Center right alignment.    |
| BottomStart<sup>8+</sup> | Bottom left alignment.     |
| BottomEnd<sup>8+</sup>   | Bottom right alignment.    |


## CustomDialogController

### Objects to Import

```ts
dialogController : CustomDialogController = new CustomDialogController(value:{builder: CustomDialog, cancel?: () => void, autoCancel?: boolean})
```

### open()
open(): void


Opens the content of the custom dialog box. If the content has been displayed, this API does not take effect.


### close
close(): void


Closes the custom dialog box. If the dialog box is closed, this API does not take effect.


## Example

```ts
// xxx.ets
@CustomDialog
struct CustomDialogExample {
  @Link textValue: string
  @Link inputValue: string
  controller: CustomDialogController
  cancel: () => void
  confirm: () => void

  build() {
    Column() {
      Text('Change text').fontSize(20).margin({ top: 10, bottom: 10 })
      TextInput({ placeholder: '', text: this.textValue }).height(60).width('90%')
        .onChange((value: string) => {
          this.textValue = value
        })
      Text('Whether to change a text?').fontSize(16).margin({ bottom: 10 })
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Button('cancel')
          .onClick(() => {
            this.controller.close()
            this.cancel()
          }).backgroundColor(0xffffff).fontColor(Color.Black)
        Button('confirm')
          .onClick(() => {
            this.inputValue = this.textValue
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
  @State textValue: string = ''
  @State inputValue: string = 'click me'
  dialogController: CustomDialogController = new CustomDialogController({
    builder: CustomDialogExample({ cancel: this.onCancel, confirm: this.onAccept, textValue: $textValue, inputValue: $inputValue }),
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
      Button(this.inputValue)
        .onClick(() => {
          this.dialogController.open()
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212058470](figures/en-us_image_0000001212058470.gif)
