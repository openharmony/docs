# @ohos.arkui.advanced.EditableTitleBar (Editable Title Bar)


The editable title bar is a title bar that comes with button icons, typically **Cancel** on the left and **Confirm** on the right, on a multi-select or editing page.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { EditableTitleBar } from "@ohos.arkui.advanced.EditableTitleBar"
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are not supported.


## EditableTitleBar

EditableTitleBar({leftIconType: EditableLeftIconType, title: ResourceStr, menuItems?: Array&lt;EditableTitleBarMenuItem&gt;, onSave?: () =&gt; void, onCancel?: () =&gt;void})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| leftIconStyle | [EditableLeftIconType](#editablelefticontype) | Yes| Type of the icon on the left.| 
| title | [ResourceStr](ts-types.md#resourcestr) | Yes| Title.| 
| menuItems | Array&lt;[EditableTitleBarMenuItem](#editabletitlebarmenuitem)&gt; | No| List of menu items on the right.| 
| onSave | ()&nbsp;=&gt;&nbsp;void | No| Callback invoked when the Save icon is clicked.| 
| onCancel | ()&nbsp;=&gt;&nbsp;void | No| Callback invoked when the left icon is clicked to cancel the operation.| 


## EditableLeftIconType

| Name| Description| 
| -------- | -------- |
| Back | Back.| 
| Cancel | Cancel.| 


## EditableTitleBarMenuItem

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | Yes| Icon.| 
| isEnabled | boolean | Yes| Whether to enable the item. The item is enabled by default.| 
| action | ()&nbsp;=&gt;&nbsp;void | No| Action to perform.| 

## Events
The [universal events](ts-universal-events-click.md) are not supported.

## Example

```ts
import { EditableLeftIconType } from "@ohos.arkui.advanced.EditableTitleBar"
import { EditableTitleBar } from "@ohos.arkui.advanced.EditableTitleBar"
import promptAction from '@ohos.promptAction'

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
		Divider().height(2).color(0xCCCCCC)
        EditableTitleBar({
          leftIconStyle: EditableLeftIconType.Cancel,
          title: "Edit",
          menuItems: [],
          onCancel: () => {
            promptAction.showToast({ message: "on cancel" })
          },
          onSave: () => {
            promptAction.showToast({ message: "on save" })
          }
        })
        Divider().height(2).color(0xCCCCCC)
        EditableTitleBar({
          leftIconStyle: EditableLeftIconType.Back,
          title: "Edit",
          menuItems: [
            { value: $r('app.media.ic_public_reduce'),
              isEnabled: false,
              action: () => {
                promptAction.showToast({ message: "show toast index 2" })
              }
            }
          ],
          onCancel: () => {
            promptAction.showToast({ message: "on cancel" })
          },
          onSave: () => {
            promptAction.showToast({ message: "on save" })
          }
        })
		Divider().height(2).color(0xCCCCCC)
      }.width('100%')
    }.height('100%')
  }
}
```

![en-us_image_0000001617073302](figures/en-us_image_0000001617073302.jpg)
