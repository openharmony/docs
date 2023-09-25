# Alert Dialog Box

You can set the text content and response callback for an alert dialog box.

>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](../apis/js-apis-arkui-UIContext.md#uicontext).
>
> Since API version 10, you can use the [showAlertDialog](../apis/js-apis-arkui-UIContext.md#showalertdialog) API in [UIContext](../apis/js-apis-arkui-UIContext.md#uicontext) to obtain the UI context.

## Attributes

| Name   | Type | Description|
| ---- | --------------- | -------- |
| show | [AlertDialogParamWithConfirm](#alertdialogparamwithconfirm) \| [AlertDialogParamWithButtons](#alertdialogparamwithbuttons) \| [AlertDialogParamWithOptions](#alertdialogparamwithoptions10) | Defines and displays the **\<AlertDialog>** component.|

## AlertDialogParamWithConfirm
| Name      | Type    | Mandatory    | Description        |
| ---------- | ---------------- | ---------- | ------------------------------- |
| title      | [ResourceStr](ts-types.md#resourcestr) | No   | Title of the dialog box.|
| subtitle<sup>10+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Subtitle of the dialog box.|
| message    | [ResourceStr](ts-types.md#resourcestr) | Yes   | Content of the dialog box.|
| autoCancel | boolean | No  | Whether to close the dialog box when the overlay is clicked.<br>Default value: **true**|
| confirm    | {<br>enabled<sup>10+</sup>?: boolean,<br>defaultFocus<sup>10+</sup>?: boolean,<br>style<sup>10+</sup>?: [DialogButtonStyle](#dialogbuttonstyle10),<br>value: [ResourceStr](ts-types.md#resourcestr),<br>fontColor?: [ResourceColor](ts-types.md#resourcecolor),<br>backgroundColor?:  [ResourceColor](ts-types.md#resourcecolor),<br>action: () =&gt; void<br>} | No  | Information about the confirm button.<br>**enabled**: whether to respond when the button is clicked.<br>Default value: **true**<br>**defaultFocus**: whether the button is the default focus.<br>Default value: **false**<br>**style**: button style.<br>Default value: **DialogButtonStyle.DEFAULT**<br>**value**: text of the button.<br>**fontColor**: font color of the button.<br>**backgroundColor**: background color of the button.<br>**action**: callback when the button is selected.|
| cancel     | () =&gt; void      | No    | Callback invoked when the dialog box is closed after the overlay is clicked.|
| alignment  | [DialogAlignment](#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**|
| offset     | [Offset](ts-types.md#offset) | No    | Offset of the dialog box relative to the alignment position.<br>Default value: **{ dx: 0 , dy: 0 }**|
| gridCount  | number                       | No    | Number of grid columns occupied by the width of the dialog box.<br>Default value: **4**|
| maskRect<sup>10+</sup>| [Rectangle](#rectangle10) | No    | Mask area of the dialog box. Events outside the mask area are transparently transmitted, and events within the mask area are not.<br>Default value: **{ x: 0, y: 0, width: '100%', height: '100%' }**|

Priorities of the **confirm** parameters: **fontColor** and **backgroundColor** > **style** > **defaultFocus**

| backgroundColor | fontColor | style                       | defaultFocus | Effect    |
| --------------- | --------- | --------------------------- | ------------ | -------- |
| Green           | Red     | -                           | -            | Red text on green background|
| Green           | -         | DialogButtonStyle.HIGHLIGHT | -            | White text on green background|
| Green           | -         | DialogButtonStyle.DEFAULT   | -            | Blue text on green background|
| Green           | -         | -                           | TRUE         | White text on green background|
| Green           | -         | -                           | FALSE/-      | Blue text on green background|
| -               | Red     | DialogButtonStyle.HIGHLIGHT | -            | Red text on blue background|
| -               | Red     | DialogButtonStyle.DEFAULT   | -            | Red text on white background|
| -               | Red     | -                           | TRUE         | Red text on blue background|
| -               | Red     | -                           | FALSE/-      | Red text on white background|
| -               | -         | DialogButtonStyle.HIGHLIGHT | -            | White text on blue background|
| -               | -         | DialogButtonStyle.DEFAULT   | -            | Blue text on white background|
| -               | -         | -                           | TRUE         | White text on blue background|
| -               | -         | -                           | FALSE/-      | Blue text on white background|

## AlertDialogParamWithButtons
| Name            | Type               | Mandatory    | Description                    |
| --------------- | ---------------------- | ------------ | --------------------- |
| title           | [ResourceStr](ts-types.md#resourcestr) | No    | Title of the dialog box.             |
| subtitle<sup>10+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Subtitle of the dialog box.|
| message         | [ResourceStr](ts-types.md#resourcestr) | Yes    | Content of the dialog box.             |
| autoCancel      | boolean           | No  | Whether to close the dialog box when the overlay is clicked.<br>Default value: **true**     |
| primaryButton   | {<br>enabled<sup>10+</sup>?: boolean,<br>defaultFocus<sup>10+</sup>?: boolean,<br>style<sup>10+</sup>?: [DialogButtonStyle](#dialogbuttonstyle10),<br>value: [ResourceStr](ts-types.md#resourcestr),<br>fontColor?: [ResourceColor](ts-types.md#resourcecolor),<br>backgroundColor?: [ResourceColor](ts-types.md#resourcecolor),<br>action: () =&gt; void;<br>} | No| Information about the confirm button.<br>**enabled**: whether to respond when the button is clicked.<br>Default value: **true**<br>**defaultFocus**: whether the button is the default focus.<br>Default value: **false**<br>**style**: button style.<br>Default value: **DialogButtonStyle.DEFAULT**<br>**value**: text of the button.<br>**fontColor**: font color of the button.<br>**backgroundColor**: background color of the button.<br>**action**: callback when the button is selected.|
| secondaryButton | {<br>enabled<sup>10+</sup>?: boolean,<br>defaultFocus<sup>10+</sup>?: boolean,<br>style<sup>10+</sup>?: [DialogButtonStyle](#dialogbuttonstyle10),<br>value: [ResourceStr](ts-types.md#resourcestr),<br>fontColor?: [ResourceColor](ts-types.md#resourcecolor),<br>backgroundColor?: [ResourceColor](ts-types.md#resourcecolor),<br>action: () =&gt; void;<br>} | No | Information about the confirm button.<br>**enabled**: whether to respond when the button is clicked.<br>Default value: **true**<br>**defaultFocus**: whether the button is the default focus.<br>Default value: **false**<br>**style**: button style.<br>Default value: **DialogButtonStyle.DEFAULT**<br>**value**: text of the button.<br>**fontColor**: font color of the button.<br>**backgroundColor**: background color of the button.<br>**action**: callback when the button is selected.|
| cancel          | () =&gt; void      | No | Callback invoked when the dialog box is closed after the overlay is clicked.        |
| alignment       | [DialogAlignment](#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**|
| offset          | [Offset](ts-types.md#offset) | No | Offset of the dialog box relative to the alignment position.|
| gridCount       | number                       | No | Number of grid columns occupied by the width of the dialog box.|
| maskRect<sup>10+</sup> | [Rectangle](#rectangle10) | No    | Mask area of the dialog box. Events outside the mask area are transparently transmitted, and events within the mask area are not.<br>Default value: **{ x: 0, y: 0, width: '100%', height: '100%' }**|

## AlertDialogParamWithOptions<sup>10+</sup>
| Name            | Type               | Mandatory    | Description                    |
| --------------- | ---------------------- | ------------ | --------------------- |
| title           | [ResourceStr](ts-types.md#resourcestr) | No    | Title of the dialog box.             |
| subtitle<sup>10+</sup>           | [ResourceStr](ts-types.md#resourcestr) | No    | Subtitle of the dialog box.             |
| message         | [ResourceStr](ts-types.md#resourcestr) | Yes    | Content of the dialog box.             |
| autoCancel      | boolean           | No  | Whether to close the dialog box when the overlay is clicked.<br>Default value: **true**     |
| cancel          | () =&gt; void      | No | Callback invoked when the dialog box is closed after the overlay is clicked.        |
| alignment       | [DialogAlignment](#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**|
| offset          | [Offset](ts-types.md#offset) | No | Offset of the dialog box relative to the alignment position.|
| gridCount       | number                       | No | Number of grid columns occupied by the width of the dialog box.|
| maskRect<sup>10+</sup>| [Rectangle](#rectangle10) | No    | Mask area of the dialog box. Events outside the mask area are transparently transmitted, and events within the mask area are not.<br>Default value: **{ x: 0, y: 0, width: '100%', height: '100%' }**|
| buttons<sup>10+</sup>       | Array&lt;[AlertDialogButtonOptions](#alertdialogbuttonoptions10)&gt;                 | No | Buttons in the dialog box.|
|buttonDirection<sup>10+</sup>      | [DialogButtonDirection](#dialogbuttondirection10)| No | Direction in which buttons are laid out.<br>Default value: **DialogButtonDirection.AUTO**<br>When there are more than three buttons, the Auto mode (which automatically switches to the vertical layout when there are more than two buttons) is recommended. In non-Auto mode, buttons that extend beyond the display area are clipped.|

## AlertDialogButtonOptions<sup>10+</sup>
| Name            | Type               | Mandatory    | Description                    |
| ------------------| ---------------------- | ------------ | --------------------- |
| enabled           | boolean | No    | Whether to respond when the button is clicked.<br>Default value: **true**             |
| defaultFocus           | boolean | No    | Whether the button is the default focus.<br>Default value: **false**             |
| style           | [DialogButtonStyle](#dialogbuttonstyle10) | No    | Style of the button.<br>Default value: **DialogButtonStyle.DEFAULT**             |
| value           | [ResourceStr](ts-types.md#resourcestr) | Yes    | Text of the button. If the value is null, the button is not displayed.             |
| fontColor           | [ResourceColor](ts-types.md#resourcecolor) | No    | Font color of the button.             |
| backgroundColor           | [ResourceColor](ts-types.md#resourcecolor) | No    | Background color of the button.             |
| action           | 	() => void | Yes    | Callback when the button is selected.             |

## DialogButtonDirection<sup>10+</sup>
| Name                      | Description     |
| -------------------------- | --------- |
| AUTO                      | Buttons are laid out horizontally when there are two or fewer buttons and vertically otherwise.|
| HORIZONTAL                      | Buttons are laid out horizontally.|
| VERTICAL                      | Buttons are laid out vertically.|

Priorities of the **confirm** parameters: **fontColor** and **backgroundColor** > **style** > **defaultFocus**

| backgroundColor | fontColor | style                       | defaultFocus | Effect    |
| --------------- | --------- | --------------------------- | ------------ | -------- |
| Green           | Red     | -                           | -            | Red text on green background|
| Green           | -         | DialogButtonStyle.HIGHLIGHT | -            | White text on green background|
| Green           | -         | DialogButtonStyle.DEFAULT   | -            | Blue text on green background|
| Green           | -         | -                           | TRUE         | White text on green background|
| Green           | -         | -                           | FALSE/-      | Blue text on green background|
| -               | Red     | DialogButtonStyle.HIGHLIGHT | -            | Red text on blue background|
| -               | Red     | DialogButtonStyle.DEFAULT   | -            | Red text on white background|
| -               | Red     | -                           | TRUE         | Red text on blue background|
| -               | Red     | -                           | FALSE/-      | Red text on white background|
| -               | -         | DialogButtonStyle.HIGHLIGHT | -            | White text on blue background|
| -               | -         | DialogButtonStyle.DEFAULT   | -            | Blue text on white background|
| -               | -         | -                           | TRUE         | White text on blue background|
| -               | -         | -                           | FALSE/-      | Blue text on white background|

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

## Rectangle<sup>10+</sup>

The **Rectangle** type is used to represent a mask area of a dialog box.

| Name    | Type                          | Mandatory| Description                               |
|--------|------------------------------|----|-----------------------------------|
| x      | [Length](ts-types.md#length) | No | X coordinate of the mask area of the dialog box relative to the upper left corner of the window.<br>Default value: **0vp**|
| y      | [Length](ts-types.md#length) | No | Y coordinate of the mask area of the dialog box relative to the upper left corner of the window.<br>Default value: **0vp**|
| width  | [Length](ts-types.md#length) | No | Width of the mask area of the dialog box.<br>Default value: **'100%'**       |
| height | [Length](ts-types.md#length) | No | Height of the mask area of the dialog box.<br>Default value: **'100%'**       |

>  **NOTE**
>
>  **x** and **y** can be set to a positive or negative percentage value. When **x** is set to **'100%'**, the mask area is moved rightward by the window width. When **x** is set to **'-100%'**, the mask area is moved leftward by the window width. When **y** is set to **'100%'**, the mask area is moved downward by the window height. When **y** is set to **'-100%'**, the mask area is moved upward by the window height.
>
>  **width** and **height** can be set in percentage and can only be set to positive values. If they are set to negative values, the default values are used instead.
>
>  The percentage is calculated based on the width and height of the window.

## DialogButtonStyle<sup>10+</sup>

| Name     | Description                             |
| --------- | --------------------------------- |
| DEFAULT   | Blue text on white background (black background under the dark theme).|
| HIGHLIGHT | White text on blue background.                       |

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
              subtitle: 'subtitle',
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
                enabled: true,
                defaultFocus: true,
                style: DialogButtonStyle.HIGHLIGHT,
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
        Button('three button dialog')
        .onClick(() => {
          AlertDialog.show(
            {
              title: 'title',
              subtitle: 'subtitle',
              message: 'text',
              autoCancel: true,
              alignment: DialogAlignment.Bottom,
              gridCount: 4,
              offset: { dx: 0, dy: -20 },
              buttonDirection: DialogButtonDirection.HORIZONTAL,
              buttons: [
                {
                  value: 'Button',
                  action: () => {
                    console.info('Callback when button1 is clicked')
                  }
                },
                {
                  value: 'Button',
                  action: () => {
                    console.info('Callback when button2 is clicked')
                  }
                },
                {
                  value: 'Button',
                  enabled: true,
                  defaultFocus: true,
                  style: DialogButtonStyle.HIGHLIGHT,
                  action: () => {
                    console.info('Callback when button3 is clicked')
                  }
                },
              ],
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

![en-us_image_alert](figures/en-us_image_alert.gif)
