# @ohos.arkui.advanced.ToolBar (Toolbar)


The **\<Toolbar>** component is used to host a set of action options related to the current screen, displayed at the bottom of the screen. It can display five child components. When there are six or more child components, the first four are displayed and the others are moved to the **More** option on the toolbar.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { ToolBar, ToolBarOptions } from '@ohos.arkui.advanced.ToolBar'
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are supported.

## APIs

Toolbar({toolBarList: ToolBarOptions, activateIndex?: number, controller: TabsController})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| toolBarList | [ToolBarOptions](#toolbaroptions) | Yes| Toolbar list.| 
| activateIndex | number | No| Index of the active option.<br>Default value: **1**| 
| controller | [TabsController](ts-container-tabs.md#tabscontroller) | Yes| Style of the filter.| 


## ToolBarOptions

Inherited from **Array\<ToolBarOption>**.

**ToolBarOption**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| content | [ResourceStr](ts-types.md#resourcestr) | Yes| Text of the toolbar option.| 
| action | void | No| Click event of the toolbar option.| 
| icon | [Resource](ts-types.md#resource) | No| Icon of the toolbar option.| 
| state | [ItemState](#itemstate) | No| Status of the toolbar option.<br>Default value: **ENABLE**| 


## ItemState

| Name| Description| 
| -------- | -------- |
| ENABLE | The toolbar option is enabled.| 
| DISABLE | The toolbar option is disabled.| 
| ACTIVATE | The toolbar option is activated.| 

## Events
The [universal events](ts-universal-events-click.md) are supported.

## Example

```ts
import { ToolBar, ToolBarOptions } from '@ohos.arkui.advanced.ToolBar'
@Entry
@Component
struct Index {
  @State toolbarList: ToolBarOptions = new ToolBarOptions()
    aboutToAppear() {
    this.toolbarList.push({ text: 'Cut Super Long Text',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
    this.toolbarList.push({ text: 'Copy',
      icon: $r('sys.media.ohos_ic_public_copy'),
      action: () => {
      },
      state:2
    })
    this.toolbarList.push({ text: 'Paste',
      icon: $r('sys.media.ohos_ic_public_paste'),
      action: () => {
      },
      state:3
    })
    this.toolbarList.push({ text: 'Select All',
      icon: $r('sys.media.ohos_ic_public_select_all'),
      action: () => {
      },
    })
    this.toolbarList.push({ text: 'Share',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
    this.toolbarList.push({ text: 'Share',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
  }
  build() {
    Row() {
      Stack() {
        Column(){
          Button ("Delete Item")
            .width(96)
            .height(40)
            .onClick(() => {
              this.toolbarList.pop()
            })
          Button ("Add Item")
            .width(96)
            .height(40)
            .onClick(() => {
              this.toolbarList.push(this.toolbarList[1])
            })
        }.margin({bottom: 300})
        Column() {
          ToolBar({
            currentIndex: 2,
            hwToolBarList: this.toolbarList,
          })
        }
      }.align(Alignment.Bottom)
      .width('100%').height('100%')
    }
  }
}
```

![en-us_image_0000001658655445](figures/en-us_image_0000001658655445.png)
