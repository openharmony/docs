# Action Sheet


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


An action sheet is a dialog box that displays actions a user can take.


## Required Permissions

None


## ActionSheet.show

show(options: { paramObject1})

Defines and shows the action sheet.

- paramObject1 parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string&nbsp;\|[Resource](../../ui/ts-types.md#resource) | No | None | Title&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box. |
  | message | string&nbsp;\|[Resource](../../ui/ts-types.md#resource) |  |  | Content&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box. |
  | autoCancel | boolean | No | true | Whether&nbsp;to&nbsp;close&nbsp;the&nbsp;dialog&nbsp;box&nbsp;when&nbsp;the&nbsp;overlay&nbsp;is&nbsp;clicked. |
  | confirm | {<br/>value:&nbsp;string&nbsp;\|[Resource](../../ui/ts-types.md#resource),<br>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} | number | string | Text&nbsp;content&nbsp;of&nbsp;the&nbsp;confirm&nbsp;button&nbsp;and&nbsp;callback&nbsp;upon&nbsp;button&nbsp;clicking.<br/>**value**:&nbsp;button&nbsp;text.<br/>**action**:&nbsp;callback&nbsp;upon&nbsp;button&nbsp;clicking. |
  | cancel | ()&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;dialog&nbsp;box&nbsp;is&nbsp;closed&nbsp;after&nbsp;the&nbsp;overlay&nbsp;is&nbsp;clicked. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment&nbsp;mode&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;in&nbsp;the&nbsp;vertical&nbsp;direction. |
  | offset | {<br/>dx:&nbsp;Length\|[Resource](../../ui/ts-types.md#resource)<br/>dy:&nbsp;Length\|[Resource](../../ui/ts-types.md#resource)<br/>} | No | - | Offset&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;relative&nbsp;to&nbsp;the&nbsp;alignment&nbsp;position. |
  | sheets | Array&lt;SheetInfo&gt; | Yes | - | Options&nbsp;in&nbsp;the&nbsp;dialog&nbsp;box.&nbsp;Each&nbsp;option&nbsp;supports&nbsp;the&nbsp;image,&nbsp;text,&nbsp;and&nbsp;callback. |

- SheetInfo parameters
    | | | | | |
  | -------- | -------- | -------- | -------- | -------- |
  | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | title | string | Yes | - | Sheet&nbsp;text. |
  | icon | string | No | None | Sheet&nbsp;icon. |
  | action | ()=&gt;void | Yes | - | Callback&nbsp;when&nbsp;the&nbsp;sheet&nbsp;is&nbsp;selected. |


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

