# Action Sheet


> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


An action sheet is a dialog box that displays actions a user can take.


## Required Permissions

None


## ActionSheet.show

show(options: { paramObject1})

Defines and shows an action sheet.

- paramObject1 parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string \|[Resource](../../ui/ts-types.md) | No | None | Title of the dialog box. |
  | message | string \|[Resource](../../ui/ts-types.md) |  |  | Content of the dialog box. |
  | autoCancel | boolean | No | true | Whether to close the dialog box when the overlay is clicked. |
  | confirm | {<br/>value: string \| [Resource](../../ui/ts-types.md),<br/>action: () =&gt; void<br/>} | No | - | Text content of the confirm button and callback upon button clicking.<br/>**value**: button text.<br/>**action**: callback upon button clicking. |
  | cancel | () =&gt; void | No | - | Callback invoked when the dialog box is closed after the overlay is clicked. |
  | alignment | [DialogAlignment](ts-methods-custom-dialog-box.md) | No | DialogAlignment.Default | Alignment mode of the dialog box in the vertical direction. |
  | offset | {<br/>dx: Length,<br/>dy: Length<br/>} | No | {<br/>dx: 0,<br/>dy: 0<br/>} | Offset of the dialog box relative to the alignment position. |
  | sheets | Array<SheetInfo&gt; | Yes | - | Options in the dialog box. Each option supports the image, text, and callback. |

- SheetInfo parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string \| [Resource](../../ui/ts-types.md) | Yes | - | Sheet text. |
  | icon | string \| [Resource](../../ui/ts-types.md) | No | None | Sheet icon. |
  | action | ()=&gt;void | Yes | - | Callback when the sheet is selected. |


## Example



```ts
// xxx.ets
@Entry
@Component
struct ActionSheetExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button('Click to Show ActionSheet')
        .onClick(() => {
          ActionSheet.show({
            title: 'ActionSheet title',
            message: 'message',
            confirm: {
              value: 'Confirm button',
              action: () => {
                console.log('Get Alert Dialog handled')
              }
            },
            sheets: [
              {
                title: 'apples',
                action: () => {
                  console.error('apples')
                }
              },
              {
                title: 'bananas',
                action: () => {
                  console.error('bananas')
                }
              },
              {
                title: 'pears',
                action: () => {
                  console.error('pears')
                }
              }
            ]
          })
        })
    }.width('100%')
    .height('100%')
  }
}
```


![en-us_image_0000001212058508](figures/en-us_image_0000001212058508.gif)

