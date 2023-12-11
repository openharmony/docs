# @ohos.arkui.advanced.SelectTitleBar (Drop-down Title Bar)


The drop-down title bar is a title bar that contains a drop-down menu for switching between pages of different levels (configured with the Back button).


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { SelectTitleBar } from "@ohos.arkui.advanced.SelectTitleBar"
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are not supported.

## SelectTitleBar

SelectTitleBar({selected: number, options: Array&lt;SelectOption&gt;, menuItems?: Array&lt;SelectTitleBarMenuItem&gt;, subtitle?: ResourceStr, badgeValue?: number, hidesBackButton?: boolean, onSelected?: (index: number) =&gt; void})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| selected | number | Yes| \@Prop | Index of the currently selected option.|
| options | Array&lt;[SelectOption](ts-basic-components-select.md#selectoption)&gt; | Yes| - | Options in the drop-down menu.|
| menuItems | Array&lt;[SelectTitleBarMenuItem](#selecttitlebarmenuitem)&gt; | No| - | List of menu items on the right of the title bar.|
| subtitle | [ResourceStr](ts-types.md#resourcestr) | No| - | Subtitle.|
| badgeValue | number | No| - | Badge.|
| hidesBackButton | boolean | No| - | Whether to hide the Back button.|
| onSelected | (index:&nbsp;number)&nbsp;=&gt;&nbsp;void | No| - | Callback invoked when an option in the drop-down menu is selected. The index of the selected option is passed in.|


## SelectTitleBarMenuItem

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | Yes| Icon.|
| isEnabled | boolean | Yes| Whether to enable the item. |
| action | ()&nbsp;=&gt;&nbsp;void | No| Action to perform.|

## Events
The [universal events](ts-universal-events-click.md) are not supported.

## Example

```ts
import { SelectTitleBar } from "@ohos.arkui.advanced.SelectTitleBar"
import promptAction from '@ohos.promptAction'

class menuItems {
  value: Resource;
  isEnabled: boolean;
  action: () => void

  constructor(value: Resource,isEnabled: boolean,action: () => void) {
    this.value = value
    this.isEnabled = isEnabled
    this.action = action
  }
}

@Entry
@Component
struct Index {
  private  menuItems:Array<menuItems> =
  [
    new menuItems($r('app.media.ic_public_save'),true,() => promptAction.showToast({ message: "show toast index 1" })),
    new menuItems($r('app.media.ic_public_reduce'),true,() => promptAction.showToast({ message: "show toast index 2" })),
    new menuItems($r('app.media.ic_public_edit'),true,() => promptAction.showToast({ message: "show toast index 3" })),
    new menuItems($r('app.media.ic_public_reduce'),true,() => promptAction.showToast({ message: "show toast index 4" }))
  ]

  build() {
    Row() {
      Column() {
		Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: 'All photos' },
            { value:'Local (device)' },
            {"value":"Local (memory card)"}
          ],
          selected: 0,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          hidesBackButton: true
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: 'All photos' },
            { value:'Local (device)' },
            {"value":"Local (memory card)"}
          ],
          selected: 0,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          hidesBackButton: false
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: 'All photos' },
            { value:'Local (device)' },
            {"value":"Local (memory card)"}
          ],
          selected: 1,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          subtitle: "example@example.com"
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: 'All photos' },
            { value:'Local (device)' },
            {"value":"Local (memory card)"}
          ],
          selected: 1,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          subtitle: "example@example.com",
          menuItems: [{ isEnabled: true, value: $r('app.media.ic_public_save'),
            action: () => promptAction.showToast({ message: "show toast index 1" })
          }]
        })
        Divider().height(2).color(0xCCCCCC)
        SelectTitleBar({
          options: [
            { value: 'All photos' },
            { value:'Local (device)' },
            {"value":"Local (memory card)"}
          ],
          selected: 0,
          onSelected: (index) => promptAction.showToast({ message: 'page index ' + index }),
          subtitle: "example@example.com",
          menuItems: this.menuItems,
          badgeValue: 99,
          hidesBackButton: true
        })
        Divider().height(2).color(0xCCCCCC)
      }.width('100%')
    }.height('100%')
  }
}
```

![en-us_image_0000001616959836](figures/en-us_image_0000001616959836.jpg)
