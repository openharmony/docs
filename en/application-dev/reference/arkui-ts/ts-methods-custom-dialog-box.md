# Custom Dialog Box

A custom dialog box is a dialog box you customize by using APIs of the **CustomDialogController** class. You can set the style and content to your preference for a custom dialog box.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.




## APIs

CustomDialogController(value:{builder: CustomDialog, cancel?: () =&gt; void, autoCancel?: boolean, alignment?: DialogAlignment, offset?: Offset, customStyle?: boolean, gridCount?: number, maskColor?: ResourceColor, openAnimation?: AnimateParam, closeAniamtion?: AnimateParam})


**Parameters**

| Name                          | Type                                    | Mandatory  | Description                                    |
| ----------------------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| builder                       | CustomDialog                             | Yes   | Constructor of the custom dialog box content.                             |
| cancel                        | () =&gt; void                  | No   | Callback invoked when the dialog box is closed after the overlay exits.                            |
| autoCancel                    | boolean                                  | No   | Whether to allow users to click the overlay to exit.<br>Default value: **true**                |
| alignment                     | [DialogAlignment](ts-methods-alert-dialog-box.md#dialogalignment) | No   | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**|
| offset                        | [Offset](ts-types.md#offset)             | No   | Offset of the dialog box relative to the alignment position.                  |
| customStyle                   | boolean                                  | No   | Whether to use a custom style for the dialog box.<br>Default value: **false**, which means that the dialog box automatically adapts its width to the grid system and its height to the child components; the maximum height is 90% of the container height; the rounded corner is 24 vp.|
| gridCount<sup>8+</sup>        | number                                   | No   | Number of [grid columns](../../ui/arkts-layout-development-grid-layout.md) occupied by the dialog box.<br>The default value is subject to the window size, and the maximum value is the maximum number of columns supported by the system. If this parameter is set to an invalid value, the default value is used.|

## CustomDialogController

### Objects to Import

```ts
dialogController : CustomDialogController = new CustomDialogController(value:{builder: CustomDialog, cancel?: () => void, autoCancel?: boolean})
```
> **NOTE**
>
> **CustomDialogController** is valid only when it is a member variable of the **@CustomDialog** and **@Component** decorated struct and is defined in the **@Component** decorated struct. For details, see the following example.

### open()
open(): void


Opens the content of the custom dialog box. This API can be called multiple times. If the dialog box displayed in a subwindow, no new subwindow is allowed.


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
  // You can pass in multiple other controllers in the CustomDialog to open one or more other CustomDialogs in the CustomDialog. In this case, you must place the controller pointing to the self at the end.
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
    // The default value of borderRadius is 24vp. The border attribute must be used together with the borderRadius attribute.
  }
}

@Entry
@Component
struct CustomDialogUser {
  @State textValue: string = ''
  @State inputValue: string = 'click me'
  dialogController: CustomDialogController = new CustomDialogController({
    builder: CustomDialogExample({
      cancel: this.onCancel,
      confirm: this.onAccept,
      textValue: $textValue,
      inputValue: $inputValue
    }),
    cancel: this.existApp,
    autoCancel: true,
    alignment: DialogAlignment.Default,
    offset: { dx: 0, dy: -20 },
    gridCount: 4,
    customStyle: false
  })

  // Delete the dialogController instance and set it to undefined when the custom component is about to be destroyed.
  aboutToDisappear() {
    delete this.dialogController, // Delete the dialogController instance.
    this.dialogController = undefined // Set dialogController to undefined.
  }

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
          if (this.dialogController != undefined) {
            this.dialogController.open()
          }
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212058470](figures/en-us_image_0000001212058470.gif)
