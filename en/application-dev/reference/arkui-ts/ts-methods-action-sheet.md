# Action Sheet


> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


An action sheet is a dialog box that displays actions a user can take.


## Required Permissions

None


## ActionSheet.show

show(options: { paramObject1})

Defines and shows the action sheet.

- paramObject1 parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string \|[Resource](../../ui/ts-types.md#resource) | No | None | Title of the dialog box. |
  | message | string \|[Resource](../../ui/ts-types.md#resource) |  |  | Content of the dialog box. |
  | autoCancel | boolean | No | true | Whether to close the dialog box when the overlay is clicked. |
  | confirm | {<br/>value: string \|[Resource](../../ui/ts-types.md#resource),<br>action: () =&gt; void<br/>} | number | string | Text content of the confirm button and callback upon button clicking.<br/>**value**: button text.<br/>**action**: callback upon button clicking. |
  | cancel | () =&gt; void | No | - | Callback invoked when the dialog box is closed after the overlay is clicked. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment mode of the dialog box in the vertical direction. |
  | offset | {<br/>dx: Length\|[Resource](../../ui/ts-types.md#resource)<br/>dy: Length\|[Resource](../../ui/ts-types.md#resource)<br/>} | No | - | Offset of the dialog box relative to the alignment position. |
  | sheets | Array&lt;SheetInfo&gt; | Yes | - | Options in the dialog box. Each option supports the image, text, and callback. |

- SheetInfo parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string | Yes | - | Sheet text. |
  | icon | string | No | None | Sheet icon. |
  | action | ()=&gt;void | Yes | - | Callback when the sheet is selected. |


## Example



```
@Entry
@Component
struct ActionSheetExapmle {
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

