# Alert Dialog Box


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **<AlertDialog\>** component is used to display an alert dialog box. You can set the text content and response callback for an alert dialog box as needed.


## Attributes

| Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| show | options: { paramObject1\| paramObject2} | - | Defines and displays the **<AlertDialog\>** component. | 

- paramObject1 parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string \|[Resource](../../ui/ts-types.md#resource) |  |  | Title of a dialog box. |
  | message | string \|[Resource](../../ui/ts-types.md#resource) |  |  | Content of the dialog box. |
  | autoCancel | boolean | No | true | Whether to close the dialog box when the overlay is clicked. |
  | confirm | {<br/>value: string \|[Resource](../../ui/ts-types.md#resource),<br>fontColor?: Color\|number \|string \|[Resource](../../ui/ts-types.md#resource),<br/>backgroundColor?:Color  \|number\|string\|[Resource](../../ui/ts-types.md#resource),<br>action: () =&gt; void<br/>} <br/> |  |  | Text content, text color, background color, and click callback of the confirm button. |
  | cancel | () =&gt; void | No | - | Callback invoked when the dialog box is closed after the overlay is clicked. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment mode of the dialog box in the vertical direction. |
  | offset | {<br/>dx: Length \|[Resource](../../ui/ts-types.md#resource),<br/>dy: Length  \|[Resource](../../ui/ts-types.md#resource)<br/>} |  |  | Offset of the dialog box relative to the alignment position. |
  | gridCount | number | No | - | Number of grid columns occupied by the width of the dialog box. |

- paramObject2 parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string \|[Resource](../../ui/ts-types.md#resource) | No | - | Title of a dialog box. |
  | message | string \|[Resource](../../ui/ts-types.md#resource) | Yes | - | Content of the dialog box. |
  | autoCancel | boolean | No | true | Whether to close the dialog box when the overlay is clicked. |
  | primaryButton | {<br/>value: string \|[Resource](../../ui/ts-types.md#resource),<br>fontColor?: Color\|number \|string \|[Resource](../../ui/ts-types.md#resource),<br/>backgroundColor?:Color  \|number\|string\|[Resource](../../ui/ts-types.md#resource),<br>action: () =&gt; void<br/>} <br/> |  |  | Text content, text color, background color, and click callback of the primary button. |
  | secondaryButton | {<br/>value: string \|[Resource](../../ui/ts-types.md#resource),<br>fontColor?: Color\|number \|string \|[Resource](../../ui/ts-types.md#resource),<br/>backgroundColor?:Color  \|number\|string\|[Resource](../../ui/ts-types.md#resource),<br>action: () =&gt; void<br/>} <br/> |  |  | Text content, text color, background color, and click callback of the secondary button. |
  | cancel | () =&gt; void | No | - | Callback invoked when the dialog box is closed after the overlay is clicked. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment mode of the dialog box in the vertical direction. |
  | offset | {<br/>dx: Length \|[Resource](../../ui/ts-types.md#resource),<br/>dy: Length  \|[Resource](../../ui/ts-types.md#resource)<br/>} |  |  | Offset of the dialog box relative to the alignment position. |
  | gridCount | number | No | - | Number of grid columns occupied by the width of the dialog box. |


## Example


```
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

![en-us_image_0000001256978387](figures/en-us_image_0000001256978387.gif)
