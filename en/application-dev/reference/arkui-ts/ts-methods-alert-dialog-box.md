# Alert Dialog Box

You can set the text content and response callback for an alert dialog box.

>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](../apis/js-apis-arkui-UIContext.md#uicontext).
>
> Since API version 10, you can use the[showAlertDialog](../apis/js-apis-arkui-UIContext.md#showalertdialog) API in [UIContext](../apis/js-apis-arkui-UIContext.md#uicontext) to obtain the UI context.

## Attributes

| Name   | Type | Description|
| ---- | --------------- | -------- |
| show | [AlertDialogParamWithConfirm](#alertdialogparamwithconfirm) \| [AlertDialogParamWithButtons](#alertdialogparamwithbuttons)  | Defines and displays the **\<AlertDialog>** component. |

## AlertDialogParamWithConfirm
| Name      | Type    | Mandatory    | Description        |
| ---------- | ---------------- | ---------- | ------------------------------- |
| title      | [ResourceStr](ts-types.md#resourcestr) | No   | Title of the dialog box.|
| message    | [ResourceStr](ts-types.md#resourcestr) | Yes   | Content of the dialog box.|
| autoCancel | boolean | No  | Whether to close the dialog box when the overlay is clicked.<br>Default value: **true**|
| confirm    | {<br>value: [ResourceStr](ts-types.md#resourcestr),<br>fontColor?: [ResourceColor](ts-types.md#resourcecolor),<br>backgroundColor?:  [ResourceColor](ts-types.md#resourcecolor),<br>action: () =&gt; void<br>} | No  | Text content, text color, background color, and click callback of the confirm button.|
| cancel     | () =&gt; void      | No    | Callback invoked when the dialog box is closed after the overlay is clicked.|
| alignment  | [DialogAlignment](#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**|
| offset     | [Offset](ts-types.md#offset) | No    | Offset of the dialog box relative to the alignment position.|
| gridCount  | number                       | No    | Number of grid columns occupied by the width of the dialog box.|

## AlertDialogParamWithButtons
| Name            | Type               | Mandatory    | Description                    |
| --------------- | ---------------------- | ------------ | --------------------- |
| title           | [ResourceStr](ts-types.md#resourcestr) | No    | Title of the dialog box.             |
| message         | [ResourceStr](ts-types.md#resourcestr) | Yes    | Content of the dialog box.             |
| autoCancel      | boolean           | No  | Whether to close the dialog box when the overlay is clicked.<br>Default value: **true**     |
| primaryButton   | {<br>value: [ResourceStr](ts-types.md#resourcestr),<br>fontColor?: [ResourceColor](ts-types.md#resourcecolor),<br>backgroundColor?: [ResourceColor](ts-types.md#resourcecolor),<br>action: () =&gt; void;<br>} | No| Text content, text color, background color, and click callback of the primary button.|
| secondaryButton | {<br>value: [ResourceStr](ts-types.md#resourcestr),<br>fontColor?: [ResourceColor](ts-types.md#resourcecolor),<br>backgroundColor?: [ResourceColor](ts-types.md#resourcecolor),<br>action: () =&gt; void;<br>} | No | Text content, text color, background color, and click callback of the primary button.|
| cancel          | () =&gt; void      | No | Callback invoked when the dialog box is closed after the overlay is clicked.        |
| alignment       | [DialogAlignment](#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**|
| offset          | [Offset](ts-types.md#offset) | No | Offset of the dialog box relative to the alignment position.|
| gridCount       | number                       | No | Number of grid columns occupied by the width of the dialog box.|

## DialogAlignment

| Name                      | Description     |
| ------------------------ | ------- |
| Top                      | Vertical top alignment.|
| Center                   | Vertical center alignment.|
| Bottom                   | Vertical bottom alignment.|
| Default                  | Default alignment.  |
| TopStart<sup>8+</sup>    | Top left alignment.  |
| TopEnd<sup>8+</sup>      | Top right alignment.  |
| CenterStart<sup>8+</sup> | Center left alignment.  |
| CenterEnd<sup>8+</sup>   | Center right alignment.  |
| BottomStart<sup>8+</sup> | Bottom left alignment.  |
| BottomEnd<sup>8+</sup>   | Bottom right alignment.  |

## Example

```ts
// xxx.ets
@Entry
@Component
struct AlertDialogExample {
  build() {
    Column({ space: 5 }) {
      Button('one button dialog')
        .onClick(() => {
          AlertDialog.show(
            {
              title: 'title',
              message: 'text',
              autoCancel: true,
              alignment: DialogAlignment.Bottom,
              offset: { dx: 0, dy: -20 },
              gridCount: 3,
              confirm: {
                value: 'button',
                action: () => {
                  console.info('Button-clicking callback')
                }
              },
              cancel: () => {
                console.info('Closed callbacks')
              }
            }
          )
        })
        .backgroundColor(0x317aff)
      Button('two button dialog')
        .onClick(() => {
          AlertDialog.show(
            {
              title: 'title',
              message: 'text',
              autoCancel: true,
              alignment: DialogAlignment.Bottom,
              gridCount: 4,
              offset: { dx: 0, dy: -20 },
              primaryButton: {
                value: 'cancel',
                action: () => {
                  console.info('Callback when the first button is clicked')
                }
              },
              secondaryButton: {
                value: 'ok',
                action: () => {
                  console.info('Callback when the second button is clicked')
                }
              },
              cancel: () => {
                console.info('Closed callbacks')
              }
            }
          )
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001174582844](figures/en-us_image_0000001174582844.gif)
