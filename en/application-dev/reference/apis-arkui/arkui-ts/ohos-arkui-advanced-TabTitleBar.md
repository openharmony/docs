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
The [universal attributes](ts-universal-attributes-size.md) are not supported.


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
| label<sup>13+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Icon label.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|
| isEnabled | boolean | No| Whether to enable the item.<br> Default value: **false**<br> The value **true** means to enable the item, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| action | () =&gt; void | No| Action to perform.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| accessibilityLevel<sup>16+<sup>       | string  | No| Accessibility level. It determines whether the component can be recognized by accessibility services.<br>The options are as follows:<br>**"auto"**: It is treated as "yes" by the system.<br>**"yes"**: The component can be recognized by accessibility services.<br>**"no"**: The component cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the component nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**<br>**Atomic service API**: This API can be used in atomic services since API version 16.|
| accessibilityText<sup>16+<sup>        | ResourceStr | No| Accessibility text, that is, accessibility label name. If a component does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which component is selected. To solve this problem, you can set accessibility text for components without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>Default value: value of the **label** property if it is set and an empty string otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 16.                                    |
| accessibilityDescription<sup>16+<sup> | ResourceStr | No| Accessible description. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the component's attributes and accessibility text alone. If a component contains both text information and the accessible description, the text is announced first and then the accessible description, when the component is selected.<br>Default value: **"Double-tap to activate"**<br>**Atomic service API**: This API can be used in atomic services since API version 16.          |

## TabTitleBarTabItem

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| title | [ResourceStr](ts-types.md#resourcestr) | Yes| Text of the tab.|
| icon | [ResourceStr](ts-types.md#resourcestr) | No| Icon of the tab.|


## Events
The [universal events](ts-universal-events-click.md) are not supported.

## Example

### Example 1: Implementing a Simple Tab Title Bar
This example demonstrates a tab title bar with tabs on the left and a menu list on the right.
```ts
import { TabTitleBar, promptAction } from '@kit.ArkUI'

// Define the class for tab items on the left side of the title bar.
class tabItem {
  title: ResourceStr;
  icon?: ResourceStr;
  constructor(title: ResourceStr,icon?: ResourceStr) {
    this.title = title
    this.icon = icon
  }
}

// Define the API for menu items on the right side of the title bar.
interface menuItem {
  value: ResourceStr;
  isEnabled?: boolean;
  action?: () => void
}

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
  private readonly tabItems: Array<tabItem> = [new tabItem('Tab 1'),new tabItem('Tab 2'),new tabItem('Tab 3'),new tabItem("Happy",$r('app.media.emoji_happy')),new tabItem('Tab 4')]
  // Define several menu items on the right.
  private  readonly menuItems: Array<menuItem> = [
    {
      value: $r('app.media.ic_public_reduce'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 0" })
    },
    {
      value: $r('app.media.ic_public_edit'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 1" })
    },
    {
      value: $r('app.media.ic_public_save'),
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

![en-us_image_0000001616916278](figures/en-us_image_0000001616916278.png)

### Example 2: Implementing Screen Reader Announcement for the Custom Button on the Right Side
This example customizes the screen reader announcement text by setting the **accessibilityText**, **accessibilityDescription**, and **accessibilityLevel** properties of the custom button on the right side of the title bar.
```ts
import { TabTitleBar, promptAction } from '@kit.ArkUI'

// Define the class for tab items on the left side of the title bar.
class tabItem {
  title: ResourceStr;
  icon?: ResourceStr;
  constructor(title: ResourceStr,icon?: ResourceStr) {
    this.title = title
    this.icon = icon
  }
}

// Define the API for menu items on the right side of the title bar.
interface menuItem {
  value: ResourceStr;
  isEnabled?: boolean;
  action?: () => void;
  accessibilityText?: ResourceStr;
  accessibilityDescription?: ResourceStr;
  accessibilityLevel?: string
}

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
  private readonly tabItems: Array<tabItem> = [new tabItem('Tab 1'),new tabItem('Tab 2'),new tabItem('Tab 3'),new tabItem("Happy",$r('app.media.emoji_happy')),new tabItem('Tab 4')]
  // Define several menu items on the right.
  private  readonly menuItems: Array<menuItem> = [
    {
      value: $r('app.media.ic_public_reduce'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 0" }),
      accessibilityText: 'Shrink',
      // The screen reader will not focus on this item.
      accessibilityLevel: 'no',
      accessibilityDescription: 'Tap to shrink the icon'
    },
    {
      value: $r('app.media.ic_public_edit'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 1" }),
      accessibilityText: 'Edit',
      accessibilityLevel: 'yes',
      accessibilityDescription: 'Tap to edit the icon'
    },
    {
      value: $r('app.media.ic_public_save'),
      isEnabled: true,
      action: () => promptAction.showToast({ message: "on item click! index 2" }),
      // The screen reader will prioritize this text over the label.
      accessibilityText: 'Save',
      // The screen reader can focus on this item.
      accessibilityLevel: 'yes',
      // The screen reader will ultimately announce this text.
      accessibilityDescription: 'Tap to save the icon'
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
![en-us_image_0000001616916278](figures/en-us_image_0000001616916278.png)
