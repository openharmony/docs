# Alert Dialog Box


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This method is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


You can set the text content and response callback for an alert dialog box.


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| show | options:&nbsp;{&nbsp;paramObject1\|&nbsp;paramObject2} | - | Defines&nbsp;and&nbsp;displays&nbsp;the&nbsp;**&lt;AlertDialog&gt;**&nbsp;component. | 

- paramObject1 parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string&nbsp;\|[Resource](../../ui/ts-types.md#resource) |  |  | Title&nbsp;of&nbsp;a&nbsp;dialog&nbsp;box. |
  | message | string&nbsp;\|[Resource](../../ui/ts-types.md#resource) |  |  | Content&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box. |
  | autoCancel | boolean | No | true | Whether&nbsp;to&nbsp;close&nbsp;the&nbsp;dialog&nbsp;box&nbsp;when&nbsp;the&nbsp;overlay&nbsp;is&nbsp;clicked. |
  | confirm | {<br/>value:&nbsp;string&nbsp;\|[Resource](../../ui/ts-types.md#resource),<br>fontColor?: Color\|number \|string \|[Resource](../../ui/ts-types.md#resource),<br/>backgroundColor?:Color  \|number\|string\|[Resource](../../ui/ts-types.md#resource),<br>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} <br/> |  |  | Text content, text color, background color, and click callback of the confirm button. |
  | cancel | ()&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;dialog&nbsp;box&nbsp;is&nbsp;closed&nbsp;after&nbsp;the&nbsp;overlay&nbsp;is&nbsp;clicked. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment&nbsp;mode&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;in&nbsp;the&nbsp;vertical&nbsp;direction. |
  | offset | {<br/>dx:&nbsp;Length&nbsp;\|[Resource](../../ui/ts-types.md#resource),<br/>dy:&nbsp;Length&nbsp;&nbsp;\|[Resource](../../ui/ts-types.md#resource)<br/>} |  |  | Offset&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;relative&nbsp;to&nbsp;the&nbsp;alignment&nbsp;position. |
  | gridCount | number | No | - | Number&nbsp;of&nbsp;grid&nbsp;columns&nbsp;occupied&nbsp;by&nbsp;the&nbsp;width&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box. |

- paramObject2 parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string&nbsp;\|[Resource](../../ui/ts-types.md#resource) | No | - | Title&nbsp;of&nbsp;a&nbsp;dialog&nbsp;box. |
  | message | string&nbsp;\|[Resource](../../ui/ts-types.md#resource) | Yes | - | Content&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box. |
  | autoCancel | boolean | No | true | Whether&nbsp;to&nbsp;close&nbsp;the&nbsp;dialog&nbsp;box&nbsp;when&nbsp;the&nbsp;overlay&nbsp;is&nbsp;clicked. |
  | primaryButton | {<br/>value:&nbsp;string&nbsp;\|[Resource](../../ui/ts-types.md#resource),<br>fontColor?: Color\|number \|string \|[Resource](../../ui/ts-types.md#resource),<br/>backgroundColor?:Color  \|number\|string\|[Resource](../../ui/ts-types.md#resource),<br>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} <br/> |  |  | Text&nbsp;content,&nbsp;text&nbsp;color,&nbsp;background&nbsp;color,&nbsp;and&nbsp;click&nbsp;callback&nbsp;of&nbsp;the&nbsp;primary&nbsp;button. |
  | secondaryButton | {<br/>value:&nbsp;string&nbsp;\|[Resource](../../ui/ts-types.md#resource),<br>fontColor?: Color\|number \|string \|[Resource](../../ui/ts-types.md#resource),<br/>backgroundColor?:Color  \|number\|string\|[Resource](../../ui/ts-types.md#resource),<br>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} <br/> |  |  | Text&nbsp;content,&nbsp;text&nbsp;color,&nbsp;background&nbsp;color,&nbsp;and&nbsp;click&nbsp;callback&nbsp;of&nbsp;the&nbsp;secondary&nbsp;button. |
  | cancel | ()&nbsp;=&gt;&nbsp;void | No | - | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;dialog&nbsp;box&nbsp;is&nbsp;closed&nbsp;after&nbsp;the&nbsp;overlay&nbsp;is&nbsp;clicked. |
  | alignment | DialogAlignment | No | DialogAlignment.Default | Alignment&nbsp;mode&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;in&nbsp;the&nbsp;vertical&nbsp;direction. |
  | offset | {<br/>dx:&nbsp;Length&nbsp;\|[Resource](../../ui/ts-types.md#resource),<br/>dy:&nbsp;Length&nbsp;&nbsp;\|[Resource](../../ui/ts-types.md#resource)<br/>} |  |  | Offset&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box&nbsp;relative&nbsp;to&nbsp;the&nbsp;alignment&nbsp;position. |
  | gridCount | number | No | - | Number&nbsp;of&nbsp;grid&nbsp;columns&nbsp;occupied&nbsp;by&nbsp;the&nbsp;width&nbsp;of&nbsp;the&nbsp;dialog&nbsp;box. |


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
