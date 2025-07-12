# Class (TextMenuController)

提供控制文本菜单的能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 16开始支持。
>
> - 以下非静态API需先使用UIContext中的[getTextMenuController()](arkts-apis-uicontext-uicontext.md#gettextmenucontroller16)方法获取TextMenuController实例，再通过此实例调用对应方法。

## setMenuOptions<sup>16+</sup>

setMenuOptions(options: TextMenuOptions): void

设置菜单选项。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型         | 必填   | 说明   |
| -------- | ---------- | ---- | ---- |
| options | [TextMenuOptions](../apis-arkui/arkui-ts/ts-text-common.md#textmenuoptions16对象说明)| 是    | 设置菜单选项。<br />默认值:{showMode: TextMenuShowMode.DEFAULT} |

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct Index {
  aboutToAppear(): void {
    // 设置在对应的UIContext下优先使用独立窗口显示文本选择菜单
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
        TextInput({ text: "这是一个TextInput，长按弹出文本选择菜单" })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
          .caretStyle({ width: '4vp' })

        Text("这是一个Text，长按弹出文本选择菜单")
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

屏蔽文本选择菜单内所有系统服务菜单项。

> **说明：**
> 
> 此接口调用后整个应用进程都会生效。
>
> 此接口可在[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)使用。
>
> 此接口调用后将影响文本组件的接口[editMenuOptions](./arkui-ts/ts-basic-components-text.md#editmenuoptions12)，其回调方法[onCreateMenu](./arkui-ts/ts-text-common.md#oncreatemenu12)的入参列表中不包含被屏蔽的菜单选项。
>
> 涉及文本选择菜单的组件有 [Text](./arkui-ts/ts-basic-components-text.md)、[TextArea](./arkui-ts/ts-basic-components-textarea.md)、[TextInput](./arkui-ts/ts-basic-components-textinput.md)、[Search](./arkui-ts/ts-basic-components-search.md)、[RichEditor](./arkui-ts/ts-basic-components-richeditor.md)、[Web](../apis-arkweb/arkts-basic-components-web.md)。
>
> 系统服务菜单项指除[TextMenuItemId](./arkui-ts/ts-text-common.md#textmenuitemid12)中的复制、剪切、全选、粘贴以外的菜单项。
>
> 当disableSystemServiceMenuItems与disableMenuItems同时设置时，优先生效先设置的disableSystemServiceMenuItems。
>
> 使用该接口时，全局生效，多次调用以最后一次为准。
>
> 可以通过以下三种方式恢复禁用菜单：
>
> - 仅设置disableSystemServiceMenuItems(true)禁用菜单时，设置false即可恢复禁用；
> - 仅设置disableMenuItems禁用菜单时，设置为空数组即可恢复禁用；
> - 当disableSystemServiceMenuItems与disableMenuItems同时使用时，则前者设置为false，后者设置为空数组，即可恢复禁用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型         | 必填   | 说明   |
| -------- | ---------- | ---- | ---- |
| disable | boolean | 是    | 是否禁用系统服务菜单。true表示禁用，false表示不禁用。<br />默认值: false |

**示例：**

```ts
import { TextMenuController } from '@kit.ArkUI';

// xxx.ets
@Entry
@Component
struct Index {
  aboutToAppear(): void {
    // 禁用所有系统服务菜单。
    TextMenuController.disableSystemServiceMenuItems(true)
  }

  aboutToDisappear(): void {
    // 页面消失恢复系统服务菜单。
    TextMenuController.disableSystemServiceMenuItems(false)
  }

  build() {
    Row() {
      Column() {
        TextInput({ text: "这是一个TextInput，长按弹出文本选择菜单" })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
          .caretStyle({ width: '4vp' })
          .editMenuOptions({
            onCreateMenu: (menuItems: Array<TextMenuItem>) => {
                // menuItems不包含被屏蔽的系统菜单项。
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

屏蔽文本选择菜单内指定的系统服务菜单项。

> **说明：**
> 
> 此接口调用后整个应用进程都会生效。
>
> 此接口可在[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)使用。
>
> 此接口调用后将影响文本组件的接口[editMenuOptions](./arkui-ts/ts-basic-components-text.md#editmenuoptions12)，其回调方法[onCreateMenu](./arkui-ts/ts-text-common.md#oncreatemenu12)的入参列表中不包含被屏蔽的菜单选项。
>
> 涉及文本选择菜单的组件有 [Text](./arkui-ts/ts-basic-components-text.md)、[TextArea](./arkui-ts/ts-basic-components-textarea.md)、[TextInput](./arkui-ts/ts-basic-components-textinput.md)、[Search](./arkui-ts/ts-basic-components-search.md)、[RichEditor](./arkui-ts/ts-basic-components-richeditor.md)、[Web](../apis-arkweb/arkts-basic-components-web.md)。
>
> 系统服务菜单项指除[TextMenuItemId](./arkui-ts/ts-text-common.md#textmenuitemid12)中的复制、剪切、全选、粘贴以外的菜单项。
>
> 当disableSystemServiceMenuItems与disableMenuItems同时设置时，优先生效先设置的disableSystemServiceMenuItems。
>
> 使用该接口时，全局生效，多次调用以最后一次为准。
>
> 可以通过以下三种方式恢复禁用菜单：
>
> - 仅设置disableSystemServiceMenuItems(true)禁用菜单时，设置false即可恢复禁用；
> - 仅设置disableMenuItems禁用菜单时，设置为空数组即可恢复禁用；
> - 当disableSystemServiceMenuItems与disableMenuItems同时使用时，则前者设置为false，后者设置为空数组，即可恢复禁用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型         | 必填   | 说明   |
| -------- | ---------- | ---- | ---- |
| items | Array<[TextMenuItemId](./arkui-ts/ts-text-common.md#textmenuitemid12)> | 是    | 禁用菜单项的列表。<br />默认值: []<br />默认不禁用任何菜单。 |

**示例：**

```ts
import { TextMenuController } from '@kit.ArkUI';

// xxx.ets
@Entry
@Component
struct Index {
  aboutToAppear(): void {
    // 禁用搜索和翻译菜单。
    TextMenuController.disableMenuItems([TextMenuItemId.SEARCH, TextMenuItemId.TRANSLATE])
  }

  aboutToDisappear(): void {
    // 恢复系统服务菜单。
    TextMenuController.disableMenuItems([])
  }

  build() {
    Row() {
      Column() {
        TextInput({ text: "这是一个TextInput，长按弹出文本选择菜单" })
          .height(60)
          .fontStyle(FontStyle.Italic)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
          .caretStyle({ width: '4vp' })
          .editMenuOptions({
            onCreateMenu: (menuItems: Array<TextMenuItem>) => {
                // menuItems不包含搜索和翻译。
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

