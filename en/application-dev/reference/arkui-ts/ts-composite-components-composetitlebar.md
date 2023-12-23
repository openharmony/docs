# @ohos.arkui.advanced.ComposeTitleBar (One- or Two-Row Title Bar with Profile Picture)


A one- or two-row title bar with profile picture is a common title bar that contains a title, subtitle (optional), and profile picture (optional). It can come with a Back button for switching between pages of different levels.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { ComposeTitleBar } from "@ohos.arkui.advanced.ComposeTitleBar"
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are not supported.


## ComposeTitleBar

ComposeTitleBar({item?: ComposeTitleBarMenuItem, title: ResourceStr, subtitle?: ResourceStr, menuItems?: Array&lt;ComposeTitleBarMenuItem&gt;})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| item | [ComposeTitleBarMenuItem](#composetitlebarmenuitem) | No| A single menu item for the profile picture on the left.| 
| title | [ResourceStr](ts-types.md#resourcestr) | Yes| Title.| 
| subtitle | [ResourceStr](ts-types.md#resourcestr) | No| Subtitle.| 
| menuItems | Array&lt;[ComposeTitleBarMenuItem](#composetitlebarmenuitem)&gt; | No| List of menu items on the right.| 


## ComposeTitleBarMenuItem

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | Yes| Icon.| 
| isEnabled | boolean | Yes| Whether to enable the item.| 
| action | ()&nbsp;=&gt;&nbsp;void | No| Action to perform.| 

## Events
The [universal events](ts-universal-events-click.md) are not supported.

## Example

```ts
import { ComposeTitleBar } from "@ohos.arkui.advanced.ComposeTitleBar"
import promptAction from '@ohos.promptAction'

class menuItem {
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
  private  menuItems:Array<menuItem> =[
    new menuItem($r('app.media.ic_public_save'),true,() => promptAction.showToast({ message: "show toast index 1" })),
    new menuItem($r('app.media.ic_public_reduce'),true,() => promptAction.showToast({ message: "show toast index 2" })),
    new menuItem($r('app.media.ic_public_edit'),true,() => promptAction.showToast({ message: "show toast index 3" })),
    new menuItem($r('app.media.ic_public_reduce'),true,() => promptAction.showToast({ message: "show toast index 4" }))
  ]

  build() {
    Row() {
      Column() {
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBar({
          title: "Title",
          subtitle: "Subtitle",
          menuItems: this.menuItems.slice(0, 1),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBar({
          title: "Title",
          subtitle: "Subtitle",
          menuItems: this.menuItems.slice(0, 2),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBar({
          title: "Title",
          subtitle: "Subtitle",
          menuItems: this.menuItems,
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBar({
          menuItems: [{ isEnabled: true, value: $r('app.media.ic_public_save'),
            action: () => promptAction.showToast({ message: "show toast index 1" })
          }],
          title: "Title",
          subtitle: "Subtitle",
          item: { isEnabled: true, value: $r('app.media.app_icon') }
        })
        Divider().height(2).color(0xCCCCCC)
      }
    }.height('100%')
  }
}
```

![en-us_image_0000001616913438](figures/en-us_image_0000001616913438.jpg)
