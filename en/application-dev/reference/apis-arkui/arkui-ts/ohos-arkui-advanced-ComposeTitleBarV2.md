# ComposeTitleBarV2

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangrunsen-->
<!--Designer: @YanSanzo-->
<!--Tester: @ybhou1993-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=b4797ff84520f34081469c8824bbfa37af31b0f1 translatedAt=2026-07-17T09:57:48.043Z pushedAt=2026-07-21T01:04:55.126Z -->

The **ComposeTitleBarV2** component is a title bar that supports setting a title, an avatar (optional), and a subtitle (optional). It can be used on primary pages, secondary pages, and higher-level UIs to configure the back button.

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), state management V2 delivers enhanced capabilities for deep observation and management of data objects, and is no longer limited to the component level. With state management V2, you can control the data and state of the common title bar more flexibly, achieving more efficient UI refresh.

> **NOTE**
>
> - This component can only be used in the stage model.
>
> - If [universal attributes](ts-component-general-attributes.md) and [universal events](ts-component-general-events.md) are set for **ComposeTitleBarV2**, the compilation toolchain will generate an additional node **__Common__** and attach the universal attributes or universal events to **__Common__**, rather than directly applying them to **ComposeTitleBarV2** itself. This may cause the configured universal attributes or universal events to fail to take effect or behave unexpectedly. Therefore, it is not recommended to set universal attributes and universal events for **ComposeTitleBarV2**.

**Since:** 26.0.0

## Modules to Import

```ts
import { ComposeTitleBarV2, ComposeTitleBarV2MenuItem } from '@kit.ArkUI';
```

## Child Components

None

## ComposeTitleBarV2

ComposeTitleBarV2({item?: ComposeTitleBarV2MenuItem, title: ResourceStr, subtitle?: ResourceStr, menuItems?: Array&lt;ComposeTitleBarV2MenuItem&gt;})

Defines a title bar that supports setting a title, an avatar (optional), and a subtitle (optional). It can be used on primary pages, secondary pages, and higher-level UIs to configure the back button.

> **NOTE**
> 
> The input parameter cannot be **undefined**, that is, **ComposeTitleBarV2(undefined)** is not allowed.

**Since:** 26.0.0

**Decorator:** @ComponentV2

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Mandatory | Decorator Type | Description |
| -------- | -------- | -------- | -------- | -------- |
| item | [ComposeTitleBarV2MenuItem](#composetitlebarv2menuitem) | No | \@Param | Single menu item for the left avatar. |
| title | [ResourceStr](ts-types.md#resourcestr) | Yes | \@Param | Title. |
| subtitle | [ResourceStr](ts-types.md#resourcestr) | No | \@Param | Subtitle. |
| menuItems | Array&lt;[ComposeTitleBarV2MenuItem](#composetitlebarv2menuitem)&gt; | No | \@Param | List of right-side menu items. |

## ComposeTitleBarV2MenuItem

Defines a menu item class, which is used for the left avatar or right menu items on the title bar.

**Decorator:** @ObservedV2

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | No | No | Icon resource.<br>Decorator: **@Trace** |
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon resource, which takes priority over **value**. This attribute cannot be set for the left-side avatar of an item.<br>Decorator: **@Trace** |
| label | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Icon label description.<br>Decorator: **@Trace** |
| isEnabled | boolean | No | Yes | Whether to enable the item. It is enabled by default.<br>When **isEnabled** is **true**, the item is enabled.<br>When **isEnabled** is **false**, the item is disabled.<br>The item attribute does not support triggering the **isEnabled** attribute.<br/>Default value: **true**. |
| action | [OnActionCallback](#onactioncallback) | No | Yes | Action closure triggered for the event. The item attribute does not support triggering the **action** event.<br>Decorator: **@Trace** |
| accessibilityLevel | string | No | Yes | Accessibility level of the right-side custom button of the title bar. It controls whether the current item can be recognized by the accessibility service.<br/>Supported values:<br/>**"auto"**: The attribute value of the current component is converted to **"yes"** or **"no"** based on the context.<br/>**"yes"**: The current component can be recognized by the accessibility service.<br/>**"no"**: The current component cannot be recognized by the accessibility service.<br/>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by the accessibility service.<br/>Default value: **"auto"**.<br>Decorator: **@Trace** |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the right-side custom button of the title bar. When a component does not contain the text attribute, the screen reader does not announce anything when selecting this component, leaving users unaware of what they have selected. To address this issue, you can set accessibility text for components that do not contain text information. When the screen reader selects this component, it announces the accessibility text, helping users clearly understand what they have selected.<br/>Default value: If **label** is set, the default value is the content of the **label** attribute. If **label** is not set, the default value is **" "**. <br>Decorator: **@Trace**|
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the right-side custom button of the title bar. This description is used to explain the current component in detail to users. You should provide a relatively detailed text description for this attribute to help users understand the action to be performed and its potential consequences, especially when these consequences cannot be directly inferred from the component's attributes and accessibility text. When a component has both the text attribute and the accessibility description attribute and it is selected, the system first announces the component's text attribute, followed by the accessibility description.<br/>Default value: "Double-tap with one finger to execute".<br>Decorator: **@Trace** |

### constructor

constructor(params?: ComposeTitleBarV2MenuItemParams)

A constructor used to create a **ComposeTitleBarV2MenuItem** object.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| params | [ComposeTitleBarV2MenuItemParams](#composetitlebarv2menuitemparams) | No | Menu item parameter object. |

## ComposeTitleBarV2MenuItemParams

Defines the menu item parameters for creating a **ComposeTitleBarV2MenuItem** instance.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | No | No | Icon resource.|
| symbolStyle | [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | No | Yes | Symbol icon resource, which takes priority over **value**. This attribute cannot be set for the left-side avatar of an item.|
| label | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Icon label description. |
| isEnabled | boolean | No | Yes | Whether to enable the item. It is enabled by default.<br>When **isEnabled** is **true**, the item is enabled.<br>When **isEnabled** is **false**, the item is disabled.<br>The item attribute does not support triggering the **isEnabled** attribute.<br/>Default value: **true**.|
| action | [OnActionCallback](#onactioncallback) | No | Yes | Action closure triggered for the event. The item attribute does not support triggering the **action** event. |
| accessibilityLevel | string | No | Yes | Accessibility level of the right-side custom button of the title bar. It controls whether the current item can be recognized by the accessibility service.<br/>Supported values:<br/>**"auto"**: The attribute value of the current component is converted to **"yes"** or **"no"** based on the context.<br/>**"yes"**: The current component can be recognized by the accessibility service.<br/>**"no"**: The current component cannot be recognized by the accessibility service.<br/>**"no-hide-descendants"**: The current component and all its child components cannot be recognized by the accessibility service.<br/>Default value: **"auto"**. |
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility text of the right-side custom button of the title bar. When a component does not contain the text attribute, the screen reader does not announce anything when selecting this component, leaving users unaware of what they have selected. To address this issue, you can set accessibility text for components that do not contain text information. When the screen reader selects this component, it announces the accessibility text, helping users clearly understand what they have selected.<br/>Default value: If **label** is set, the default value is the content of the **label** attribute. If **label** is not set, the default value is **" "**. |
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No | Yes | Accessibility description of the right-side custom button of the title bar. This description is used to explain the current component in detail to users. You should provide a relatively detailed text description for this attribute to help users understand the action to be performed and its potential consequences, especially when these consequences cannot be directly inferred from the component's attributes and accessibility text. When a component has both the text attribute and the accessibility description attribute and it is selected, the system first announces the component's text attribute, followed by the accessibility description.<br/>Default value: "Double-tap with one finger to execute". |

## OnActionCallback

type OnActionCallback = () => void

Defines the callback triggered when a menu item is tapped.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Device behavior differences:** The actual device types supported by this API (phone, PC/2-in-1 device, tablet, and TV) are fewer than those supported by its system capability (phone, PC/2-in-1 device, tablet, TV, and wearable). Due to hardware capability restrictions, calling this API on wearables results in a runtime exception indicating that the API is undefined.

## Events

[Universal events](ts-component-general-events.md) are not supported.

## Example

### Example 1: Setting a Simple Title Bar

Since API version 26.0.0, the **ComposeTitleBarV2** API can be used to implement a simple title bar. This example demonstrates the basic usage of **ComposeTitleBarV2**.

```ts
import { ComposeTitleBarV2, ComposeTitleBarV2MenuItem, Prompt } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  // Define the right-side menu item list.
  @Local menuItems: Array<ComposeTitleBarV2MenuItem> = [
    new ComposeTitleBarV2MenuItem({
      // Menu icon resource.
      value: $r('sys.media.ohos_save_button_filled'),
      // Enable the icon.
      isEnabled: true,
      // Trigger an event when the menu is tapped.
      action: () => Prompt.showToast({ message: 'icon 1' }),
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.media.ohos_ic_public_copy'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'icon 2' }),
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.media.ohos_ic_public_edit'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'icon 3' }),
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.media.ohos_ic_public_remove'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'icon 4' }),
    }),
  ]

  build(): void {
    Row() {
      Column() {
        // Divider.
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title.',
          subtitle: 'Subtitle.',
          menuItems: this.menuItems.slice(0, 1),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title.',
          subtitle: 'Subtitle',
          menuItems: this.menuItems.slice(0, 2),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title',
          subtitle: 'Subtitle',
          menuItems: this.menuItems,
        })
        Divider().height(2).color(0xCCCCCC)
        // Define the title bar with an avatar.
        ComposeTitleBarV2({
          menuItems: [
            new ComposeTitleBarV2MenuItem({
              isEnabled: true,
              value: $r('sys.media.ohos_save_button_filled'),
              action: () => Prompt.showToast({ message: 'icon' }),
            })
          ],
          title: 'Title',
          subtitle: 'Subtitle',
          item: new ComposeTitleBarV2MenuItem({
            isEnabled: true,
            value: $r('sys.media.ohos_app_icon')
          })
        })
        Divider().height(2).color(0xCCCCCC)
      }
    }.height('100%')
  }
}
```

![Example 1](figures/image-composetitlebarv2-example-01.png)

### Example 2: Setting a Right-side Custom Button Announcement

Since API version 26.0.0, you can customize the text announced by the screen reader by configuring the following attribute APIs for the right-side custom buttons of the title bar: **accessibilityText**, **accessibilityDescription**, and **accessibilityLevel**.

```ts
import { ComposeTitleBarV2, ComposeTitleBarV2MenuItem, Prompt } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  // Define the right-side menu item list.
  @Local menuItems: Array<ComposeTitleBarV2MenuItem> = [
    new ComposeTitleBarV2MenuItem({
      // Menu icon resource.
      value: $r('sys.media.ohos_save_button_filled'),
      // Enable the icon.
      isEnabled: true,
      // Trigger an event when the menu is tapped.
      action: () => Prompt.showToast({ message: 'icon 1' }),
      // Text announced by the screen reader, with a higher priority than the label.
      accessibilityText: 'Save',
      // Whether the screen reader can focus on this element.
      accessibilityLevel: 'yes',
      // Description text announced last by the screen reader.
      accessibilityDescription: 'Tap to save the icon.',
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.media.ohos_ic_public_copy'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'icon 2' }),
      accessibilityText: 'Copy',
      // Set to "no" to prevent the screen reader from focusing.
      accessibilityLevel: 'no',
      accessibilityDescription: 'Tap to copy the icon',
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.media.ohos_ic_public_edit'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'icon 3' }),
      accessibilityText: 'Edit',
      accessibilityLevel: 'yes',
      accessibilityDescription: 'Tap to edit the icon',
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.media.ohos_ic_public_remove'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'icon 4' }),
      accessibilityText: 'Remove',
      accessibilityLevel: 'yes',
      accessibilityDescription: 'Tap to remove the icon',
    }),
  ]

  build(): void {
    Row() {
      Column() {
        // Divider line.
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title',
          subtitle: 'Subtitle',
          menuItems: this.menuItems.slice(0, 1),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title',
          subtitle: 'Subtitle',
          menuItems: this.menuItems.slice(0, 2),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title',
          subtitle: 'Subtitle',
          menuItems: this.menuItems,
        })
        Divider().height(2).color(0xCCCCCC)
        // Define a title bar with an avatar.
        ComposeTitleBarV2({
          menuItems: [
            new ComposeTitleBarV2MenuItem({
              isEnabled: true,
              value: $r('sys.media.ohos_save_button_filled'),
              action: () => Prompt.showToast({ message: 'icon' }),
            })
          ],
          title: 'Title',
          subtitle: 'Subtitle',
          item: new ComposeTitleBarV2MenuItem({
            isEnabled: true,
            value: $r('sys.media.ohos_app_icon'),
          }),
        })
        Divider().height(2).color(0xCCCCCC)
      }
    }.height('100%')
  }
}
```

![Example 2](figures/image-composetitlebarv2-example-02.png)

### Example 3: Setting a Symbol Icon

Since API version 26.0.0, a symbol icon can be configured by setting the **symbolStyle** attribute API of **ComposeTitleBarV2MenuItem**.

```ts
import { ComposeTitleBarV2, ComposeTitleBarV2MenuItem, Prompt, SymbolGlyphModifier } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  // Define the right-side menu item list.
  @Local menuItems: Array<ComposeTitleBarV2MenuItem> = [
    new ComposeTitleBarV2MenuItem({
      // Menu image resource.
      value: $r('sys.symbol.house'),
      // Menu symbol icon, which takes priority over value.
      symbolStyle: new SymbolGlyphModifier($r('sys.symbol.bell')).fontColor([Color.Red]),
      // Enable the icon.
      isEnabled: true,
      // Trigger an event when the menu is tapped.
      action: () => Prompt.showToast({ message: 'symbol icon 1' }),
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.symbol.house'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'symbol icon 2' }),
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.symbol.car'),
      symbolStyle: new SymbolGlyphModifier($r('sys.symbol.heart')).fontColor([Color.Pink]),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'symbol icon 3' }),
    }),
    new ComposeTitleBarV2MenuItem({
      value: $r('sys.symbol.car'),
      isEnabled: true,
      action: () => Prompt.showToast({ message: 'symbol icon 4' }),
    }),
  ]

  build(): void {
    Row() {
      Column() {
        // Divider.
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title.',
          subtitle: 'Subtitle.',
          menuItems: this.menuItems.slice(0, 1),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title',
          subtitle: 'Subtitle',
          menuItems: this.menuItems.slice(0, 2),
        })
        Divider().height(2).color(0xCCCCCC)
        ComposeTitleBarV2({
          title: 'Title',
          subtitle: 'Subtitle',
          menuItems: this.menuItems,
        })
        Divider().height(2).color(0xCCCCCC)
        // Define a title bar with an avatar.
        ComposeTitleBarV2({
          menuItems: [
            new ComposeTitleBarV2MenuItem({
              isEnabled: true,
              value: $r('sys.symbol.heart'),
              action: () => Prompt.showToast({ message: 'symbol icon 1' }),
            })
          ],
          title: 'Title',
          subtitle: 'Subtitle',
          item: new ComposeTitleBarV2MenuItem({
            isEnabled: true,
            value: $r('sys.media.ohos_app_icon'),
          }),
        })
        Divider().height(2).color(0xCCCCCC)
      }
    }.height('100%')
  }
}
```

![Example 3](figures/image-composetitlebarv2-example-03.png)
<!--no_check-->