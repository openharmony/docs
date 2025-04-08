# TabTitleBar


The **TabTitleBar** component is a tab title bar used to switch between tabs pages. It is applicable only to level-1 pages.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { TabTitleBar } from '@kit.ArkUI'
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-component-general-attributes.md) are not supported.


## TabTitleBar

TabTitleBar({tabItems: Array&lt;TabTitleBarTabItem&gt;, menuItems?: Array&lt;TabTitleBarMenuItem&gt;, swiperContent: () =&gt; void})

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| tabItems | Array&lt;[TabTitleBarTabItem](#tabtitlebartabitem)&gt; | Yes| - | List of tab items on the left of the title bar.|
| menuItems | Array&lt;[TabTitleBarMenuItem](#tabtitlebarmenuitem)&gt; | No| - | List of menu items on the right of the title bar.|
| swiperContent | () =&gt; void | Yes| \@BuilderParam | Constructor for page content pertaining to the tab list.|

> **NOTE**
> 
> The input parameter cannot be **undefined**, that is, calling **TabTitleBar(undefined)** is not allowed.

## TabTitleBarMenuItem

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | Yes| Icon resource.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| symbolStyle<sup>18+</sup> | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No| Symbol icon resource, which has higher priority than **value**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| label<sup>13+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Icon label.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| isEnabled | boolean | No| Whether to enable the item.<br> Default value: **false**<br> The value **true** means to enable the item, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| action | () =&gt; void | No| Action to perform.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| accessibilityLevel<sup>18+<sup>       | string  | No| Accessibility level. It determines whether the component can be recognized by accessibility services.<br>The options are as follows:<br>**"auto"**: It is treated as "yes" by the system.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the component nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| accessibilityText<sup>18+<sup>        | ResourceStr | No| Accessibility text, that is, accessibility label name. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>Default value: value of the **label** property if it is set and an empty string otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                                    |
| accessibilityDescription<sup>18+<sup> | ResourceStr | No| Accessible description. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the component's attributes and accessibility text alone. If a component contains both text information and the accessible description, the text is announced first and then the accessible description, when the component is selected.<br>Default value: **"Double-tap to activate"**<br>**Atomic service API**: This API can be used in atomic services since API version 18.          |

## TabTitleBarTabItem

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| title | [ResourceStr](ts-types.md#resourcestr) | Yes| Text of the tab.|
| icon | [ResourceStr](ts-types.md#resourcestr) | No| Icon of the tab.|
| symbolStyle<sup>18+</sup> | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | No| Symbol icon of the tab, which has higher priority than **icon**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|


## Events
The [universal events](ts-component-general-events.md) are not supported.

## Example

### Example 1: Implementing a Simple Tab Title Bar
This example demonstrates a tab title bar with tabs on the left and a menu list on the right.
```ts
import { TabTitleBar, promptAction, TabTitleBarTabItem, TabTitleBarMenuItem } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @Builder
  // Define the pages associated with the tab list.
  componentBuilder() {
    Text("#1ABC9C\nTURQUOISE")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#1ABC9C")
    Text("#16A085\nGREEN SEA")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#16A085")
    Text("#2ECC71\nEMERALD")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#2ECC71")
    Text("#27AE60\nNEPHRITIS")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#27AE60")
    Text("#3498DB\nPETER RIVER")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#3498DB")
  }

  // Define several tab items on the left.
  private readonly tabItems: Array<TabTitleBarTabItem> =
    [
      { title: 'Tab 1' },
      { title: 'Tab 2' },
      { title: 'Tab 3' },
      { title: 'icon', icon: $r('sys.media.ohos_app_icon') },
      { title: 'Tab 4' },
    ]
  // Define several menu items on the right.
  private readonly menuItems: Array<TabTitleBarMenuItem> = [
    {
      value: $r('sys.media.ohos_save_button_filled'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 0" })
    },
    {
      value: $r('sys.media.ohos_ic_public_copy'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 1" })
    },
    {
      value: $r('sys.media.ohos_ic_public_edit'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 2" })
    },
  ]

  // Display the tab title bar.
  build() {
    Row() {
      Column() {
        TabTitleBar({
          swiperContent: this.componentBuilder,
          tabItems: this.tabItems,
          menuItems: this.menuItems,
        })
      }.width('100%')
    }.height('100%')
  }
}
```



### Example 2: Implementing Announcement for the Custom Button on the Right Side
This example customizes the screen reader announcement text by setting the **accessibilityText**, **accessibilityDescription**, and **accessibilityLevel** properties of the custom button on the right side of the title bar.
```ts
import { TabTitleBar, promptAction, TabTitleBarTabItem, TabTitleBarMenuItem } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @Builder
  // Define the pages associated with the tab list.
  componentBuilder() {
    Text("#1ABC9C\nTURQUOISE")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#1ABC9C")
    Text("#16A085\nGREEN SEA")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#16A085")
    Text("#2ECC71\nEMERALD")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#2ECC71")
    Text("#27AE60\nNEPHRITIS")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#27AE60")
    Text("#3498DB\nPETER RIVER")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#3498DB")
  }

  // Define several tab items on the left.
  private readonly tabItems: Array<TabTitleBarTabItem> =
    [
      { title: 'Tab 1' },
      { title: 'Tab 2' },
      { title: 'Tab 3' },
      { title: 'icon', icon: $r('sys.media.ohos_app_icon') },
      { title: 'Tab 4' },
    ]
  // Define several menu items on the right.
  private readonly menuItems: Array<TabTitleBarMenuItem> = [
    {
      value: $r('sys.media.ohos_save_button_filled'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 0" }),
      accessibilityText: 'Save',
      // The screen reader will not focus on this item.
      accessibilityLevel: 'no',
      accessibilityDescription: 'Tap to save the icon'
    },
    {
      value: $r('sys.media.ohos_ic_public_copy'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 1" }),
      accessibilityText: 'Copy',
      accessibilityLevel: 'yes',
      accessibilityDescription: 'Tap to copy the icon'
    },
    {
      value: $r('sys.media.ohos_ic_public_edit'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 2" }),
      // The screen reader will prioritize this text over the label.
      accessibilityText: 'Edit',
      // The screen reader can focus on this item.
      accessibilityLevel: 'yes',
      // The screen reader will ultimately announce this text.
      accessibilityDescription: 'Tap to edit the icon'
    },
  ]

  // Display the tab title bar.
  build() {
    Row() {
      Column() {
        TabTitleBar({
          swiperContent: this.componentBuilder,
          tabItems: this.tabItems,
          menuItems: this.menuItems,
        })
      }.width('100%')
    }.height('100%')
  }
}
```


### Example 3: Setting the Symbol Icon
This example demonstrates how to use **symbolStyle** in **TabTitleBarTabItem** and **TabTitleBarMenuItem** to set custom symbol icons.
```ts
import { TabTitleBar, promptAction, TabTitleBarTabItem, TabTitleBarMenuItem, SymbolGlyphModifier } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @Builder
  // Define the pages associated with the tab list.
  componentBuilder() {
    Text("#1ABC9C\nTURQUOISE")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#1ABC9C")
    Text("#16A085\nGREEN SEA")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#16A085")
    Text("#2ECC71\nEMERALD")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#2ECC71")
    Text("#27AE60\nNEPHRITIS")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#27AE60")
    Text("#3498DB\nPETER RIVER")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#3498DB")
  }

  // Define several tab items on the left.
  private readonly tabItems: Array<TabTitleBarTabItem> =
    [
      { title: 'Tab 1' },
      { title: 'Tab 2' },
      { title: 'Tab 3' },
      {
        title: 'icon',
        icon: $r('sys.media.ohos_app_icon'),
        symbolStyle: new SymbolGlyphModifier($r('sys.symbol.car'))
      },
      { title: 'Tab 4' },
    ]
  // Define several menu items on the right.
  private readonly menuItems: Array<TabTitleBarMenuItem> = [
    {
      value: $r('sys.media.ohos_save_button_filled'),
      symbolStyle: new SymbolGlyphModifier($r('sys.symbol.save')),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 0" }),
      accessibilityText: 'Save',
      // The screen reader will not focus on this item.
      accessibilityLevel: 'no',
      accessibilityDescription: 'Tap to save the icon'
    },
    {
      value: $r('sys.media.ohos_ic_public_copy'),
      symbolStyle: new SymbolGlyphModifier($r('sys.symbol.car')),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 1" }),
      accessibilityText: 'Copy',
      accessibilityLevel: 'yes',
      accessibilityDescription: 'Tap to copy the icon'
    },
    {
      value: $r('sys.media.ohos_ic_public_edit'),
      symbolStyle: new SymbolGlyphModifier($r('sys.symbol.ai_edit')),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 2" }),
      // The screen reader will prioritize this text over the label.
      accessibilityText: 'Edit',
      // The screen reader can focus on this item.
      accessibilityLevel: 'yes',
      // The screen reader will ultimately announce this text.
      accessibilityDescription: 'Tap to edit the icon'
    },
  ]

  // Display the tab title bar.
  build() {
    Row() {
      Column() {
        TabTitleBar({
          swiperContent: this.componentBuilder,
          tabItems: this.tabItems,
          menuItems: this.menuItems,
        })
      }.width('100%')
    }.height('100%')
  }
}
```

