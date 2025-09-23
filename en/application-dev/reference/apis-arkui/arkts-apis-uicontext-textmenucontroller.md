# Class (TextMenuController)

Provides the capability to control text menus.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 16.
>
> - In the following non-static API examples, you must first use [getTextMenuController()](arkts-apis-uicontext-uicontext.md#gettextmenucontroller16) in **UIContext** to obtain a **TextMenuController** instance, and then call the APIs using the obtained instance.

## setMenuOptions<sup>16+</sup>

setMenuOptions(options: TextMenuOptions): void

Sets menu options.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type        | Mandatory  | Description  |
| -------- | ---------- | ---- | ---- |
| options | [TextMenuOptions](../apis-arkui/arkui-ts/ts-text-common.md#textmenuoptions16)| Yes   | Menu options.<br>Default value: **{showMode: TextMenuShowMode.DEFAULT}**|

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Index {
  aboutToAppear(): void {
    // Set the UIContext to preferentially display the context menu on selection in a separate window.
    this.getUIContext()
      .getTextMenuController()
      .setMenuOptions(
        {
          showMode: TextMenuShowMode.PREFER_WINDOW
        }
      );
  }

  build() {
    Row() {
      Column() {
        TextInput({ text: "This is a TextInput. Long press to display the text selection menu." })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
          .caretStyle({ width: '4vp' })

        Text("This is a Text. Long press to display the text selection menu.")
          .height(60)
          .copyOption(CopyOptions.InApp)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
      }.width('100%')
    }
    .height('100%')
  }
}
```
## disableSystemServiceMenuItems<sup>20+</sup>

static disableSystemServiceMenuItems(disable: boolean): void

Disables all system service menu items in the text selection menu.

> **NOTE**
> 
> This API takes effect globally for the entire application process after being called.
>
> This API can be used in [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md).
>
> After this API is called, the [editMenuOptions](./arkui-ts/ts-basic-components-text.md#editmenuoptions12) API of text components will be affected. The parameter list of its [onCreateMenu](./arkui-ts/ts-text-common.md#oncreatemenu12) callback will not include the disabled menu options.
>
> Components involving text selection menus include the following: [Text](./arkui-ts/ts-basic-components-text.md), [TextArea](./arkui-ts/ts-basic-components-textarea.md), [TextInput](./arkui-ts/ts-basic-components-textinput.md), [Search](./arkui-ts/ts-basic-components-search.md), [RichEditor](./arkui-ts/ts-basic-components-richeditor.md), and [Web](../apis-arkweb/arkts-basic-components-web.md).
>
> System service menu items refer to menu items other than copy, cut, select all, and paste in [TextMenuItemId](./arkui-ts/ts-text-common.md#textmenuitemid12).
>
> When both **disableSystemServiceMenuItems** and **disableMenuItems** are set, the earlier-set **disableSystemServiceMenuItems** takes precedence.
>
> This API takes effect globally, and multiple calls are subject to the last call.
>
> Disabled menus can be restored in the following ways:
>
> - If only **disableSystemServiceMenuItems(true)** is used to disable menus, set it to **false** to restore.
> - If only **disableMenuItems** is used to disable menus, set it to an empty array to restore.
> - If both **disableSystemServiceMenuItems** and **disableMenuItems** are used, set the former to **false** and the latter to an empty array to restore.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type        | Mandatory  | Description  |
| -------- | ---------- | ---- | ---- |
| disable | boolean | Yes   | Whether to disable system service menu items. The value **true** means to disable system service menu items, and **false** means the opposite.<br>Default value: **false**.|

**Example**

```ts
import { TextMenuController } from '@kit.ArkUI';

// xxx.ets
@Entry
@Component
struct Index {
  aboutToAppear(): void {
    // Disable all system service menu items.
    TextMenuController.disableSystemServiceMenuItems(true)
  }

  aboutToDisappear(): void {
    // Restore system service menu items when the page disappears.
    TextMenuController.disableSystemServiceMenuItems(false)
  }

  build() {
    Row() {
      Column() {
        TextInput({ text: "This is a TextInput. Long press to display the text selection menu." })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
          .caretStyle({ width: '4vp' })
          .editMenuOptions({
            onCreateMenu: (menuItems: Array<TextMenuItem>) => {
                // menuItems does not contain the disabled system menu items.
                return menuItems
            },
            onMenuItemClick: (menuItem: TextMenuItem, textRange: TextRange) => {
                return false
            }
          })
      }.width('100%')
    }
    .height('100%')
  }
}
```
## disableMenuItems<sup>20+</sup>

static disableMenuItems(items: Array\<TextMenuItemId>): void

Disables specified system service menu items in the text selection menu.

> **NOTE**
> 
> This API takes effect globally for the entire application process after being called.
>
> This API can be used in [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md).
>
> After this API is called, the [editMenuOptions](./arkui-ts/ts-basic-components-text.md#editmenuoptions12) API of text components will be affected. The parameter list of its [onCreateMenu](./arkui-ts/ts-text-common.md#oncreatemenu12) callback will not include the disabled menu options.
>
> Components involving text selection menus include the following: [Text](./arkui-ts/ts-basic-components-text.md), [TextArea](./arkui-ts/ts-basic-components-textarea.md), [TextInput](./arkui-ts/ts-basic-components-textinput.md), [Search](./arkui-ts/ts-basic-components-search.md), [RichEditor](./arkui-ts/ts-basic-components-richeditor.md), and [Web](../apis-arkweb/arkts-basic-components-web.md).
>
> System service menu items refer to menu items other than copy, cut, select all, and paste in [TextMenuItemId](./arkui-ts/ts-text-common.md#textmenuitemid12).
>
> When both **disableSystemServiceMenuItems** and **disableMenuItems** are set, the earlier-set **disableSystemServiceMenuItems** takes precedence.
>
> This API takes effect globally, and multiple calls are subject to the last call.
>
> Disabled menus can be restored in the following ways:
>
> - If only **disableSystemServiceMenuItems(true)** is used to disable menus, set it to **false** to restore.
> - If only **disableMenuItems** is used to disable menus, set it to an empty array to restore.
> - If both **disableSystemServiceMenuItems** and **disableMenuItems** are used, set the former to **false** and the latter to an empty array to restore.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type        | Mandatory  | Description  |
| -------- | ---------- | ---- | ---- |
| items | Array<[TextMenuItemId](./arkui-ts/ts-text-common.md#textmenuitemid12)> | Yes   | List of menu items to disable.<br>Default value: **[]**.<br>By default, no menu item is disabled.|

**Example**

```ts
import { TextMenuController } from '@kit.ArkUI';

// xxx.ets
@Entry
@Component
struct Index {
  aboutToAppear(): void {
    // Disable search and translate menu items.
    TextMenuController.disableMenuItems([TextMenuItemId.SEARCH, TextMenuItemId.TRANSLATE])
  }

  aboutToDisappear(): void {
    // Restore system service menu items.
    TextMenuController.disableMenuItems([])
  }

  build() {
    Row() {
      Column() {
        TextInput({ text: "This is a TextInput. Long press to display the text selection menu." })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
          .caretStyle({ width: '4vp' })
          .editMenuOptions({
            onCreateMenu: (menuItems: Array<TextMenuItem>) => {
                // menuItems does not contain search and translate options.
                return menuItems;
            },
            onMenuItemClick: (menuItem: TextMenuItem, textRange: TextRange) => {
                return false
            }
          })
      }.width('100%')
    }
    .height('100%')
  }
}
```
