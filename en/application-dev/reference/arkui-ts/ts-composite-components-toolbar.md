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

## ToolBar

Toolbar({toolBarList: ToolBarOptions, activateIndex?: number, controller: TabsController})

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Decorator      | Description                 | 
| -------- | -------- | -------- |-------------|---------------------|
| toolBarList | [ToolBarOptions](#toolbaroptions) | Yes| @ObjectLink | Toolbar list.             | 
| activateIndex | number | No| @Prop       | Index of the active option.<br>Default value: **1**| 
| controller | [TabsController](ts-container-tabs.md#tabscontroller) | Yes| -           | Style of the filter.          | 


## ToolBarOptions

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| content | [ResourceStr](ts-types.md#resourcestr) | Yes| Text of the toolbar option.| 
| action | () =&gt; void | No| Click event of the toolbar option.| 
| icon | [Resource](ts-types.md#resource) | No| Icon of the toolbar option.| 
| state | [ItemState](#itemstate) | No| Status of the toolbar option.<br>Default value: **ENABLE**| 


## ItemState

| Name| Value| Description| 
| -------- | -------- | -------- |
| ENABLE | 1 | The toolbar option is enabled.| 
| DISABLE | 2 | The toolbar option is disabled.| 
| ACTIVATE | 3 | The toolbar option is activated.| 

## Events
The [universal events](ts-universal-events-click.md) are supported.

## Example

```ts
import { ToolBar, ToolBarOptions } from '@ohos.arkui.advanced.ToolBar'

enum ItemState {
  ENABLE = 1,
  DISABLE = 2,
  ACTIVATE = 3
}

@Entry
@Component
struct Index {
  @State toolbarList: ToolBarOptions = new ToolBarOptions()
  aboutToAppear() {
    this.toolbarList.push({
      content:'Cut Super Long Text',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
    this.toolbarList.push({
      content: 'Copy',
      icon: $r('sys.media.ohos_ic_public_copy'),
      action: () => {
      },
      state:ItemState.DISABLE
    })
    this.toolbarList.push({
      content: 'Paste',
      icon: $r('sys.media.ohos_ic_public_paste'),
      action: () => {
      },
      state:ItemState.ACTIVATE
    })
    this.toolbarList.push({
      content:'Select All',
      icon: $r('sys.media.ohos_ic_public_select_all'),
      action: () => {
      },
    })
    this.toolbarList.push({
      content: 'Share',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
    this.toolbarList.push({
      content: 'Share',
      icon: $r('sys.media.ohos_ic_public_share'),
      action: () => {
      },
    })
  }
  build() {
    Row() {
      Stack() {
        Column() {
          ToolBar({
            activateIndex: 2,
            toolBarList: this.toolbarList,
          })
        }
      }.align(Alignment.Bottom)
      .width('100%').height('100%')
    }
  }
}
```

![en-us_image_0000001658655445](figures/en-us_image_0000001658655445.png)
