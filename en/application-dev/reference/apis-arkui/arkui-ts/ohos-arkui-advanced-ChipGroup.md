# ChipGroup

**ChipGroup** is an advanced component that provides a group of chips for scenarios such as categorizing files or resource content.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```typescript
import { ChipSize, ChipGroup } from '@kit.ArkUI'
```

## Child Components

Not supported

## ChipGroup

```
ChipGroup({
  items: ChipGroupItemOptions[],
  itemStyle?: ChipItemStyle,
  selectedIndexes?: Array<number>,
  multiple?: boolean,
  chipGroupSpace?: ChipGroupSpaceOptions,
  chipGroupPadding?: ChipGroupPaddingOptions,
  onChange?: (selectedIndexes: Array<number>) => void,
  suffix?: Callback<void>
})
```

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type                                           | Mandatory| Decorator| Description                                                                                    |
| --------------- | ----------------------------------------------- | ---- | ------------------------------------------------------------                             | ------------------------------------------------------------                             |
| items           | [ChipGroupItemOptions[]](#chipgroupitemoptions) | Yes  | @Require  @Prop | Specific attributes of individual chips. For details, see [ChipGroupItemOptions[]](#chipgroupitemoptions).<br>If this parameter is set to **undefined**, the chip group is empty by default.              |
| itemStyle       | [ChipItemStyle](#chipitemstyle)                 | No  | @Prop | Chip style, including the color and size. For details, see [ChipItemStyle](#chipitemstyle).<br>If this parameter is set to **undefined**, the default chip style is used.                |
| selectedIndexes | Array&lt;number&gt;                             | No  | @Prop | Index of the selected chip.<br>If this parameter is set to **undefined**, the first chip is selected.                                           |
| multiple        | boolean                                         | No  | @Prop | Whether multiple chips can be selected.<br>**true**: Multiple chips can be selected.<br>**false**: Only one chip can be selected.<br>Default value: **false**<br>If this parameter is set to **undefined**, the default value is used.                    |
| chipGroupSpace  | [ChipGroupSpaceOptions](#chipgroupspaceoptions) | No  | @Prop | Left and right padding, and the spacing between chips. For details, see [ChipGroupSpaceOptions](#chipgroupspaceoptions).<br>If this parameter is set to **undefined**, the default value is used.|
| chipGroupPadding  | [ChipGroupPaddingOptions](#chipgrouppaddingoptions) | No  | @Prop | Top and bottom padding, used to control the overall height. For details, see [ChipGroupPaddingOptions](#chipgrouppaddingoptions).<br>If this parameter is set to **undefined**, the default value is used.|
| onChange        | Callback\<Array\<number>>  | No  | -  | Callback invoked when the chip status changes.<br>If the value is **undefined**, the event is unbound.                                                               |
| suffix          | ()=>void                                        | No  | @BuilderParam | Suffix, which is a builder customized by the user and requires importing the [IconGroupSuffix](#icongroupsuffix) API when used.<br>Default value: The suffix is not displayed if not passed.|

> **NOTE**
>
> 1. When **multiple** is set to **false**, if **selectedIndexes** is not passed in, the first chip is automatically selected by default. However, if the provided **selectedIndexes** includes multiple elements, the chip at the first index is selected by default.
>
> 2. For the **suffix** API to work, you must include the **IconGroupSuffix** API when implementing it. If no value is specified for **suffix**, no suffix will be displayed.
>
> 3. The icon fill colors, such as **fillColor** and **activedFillColor**, are set to be consistent with the font color (**fontColor**). To differentiate the icon colors from the font color, include **prefixSymbol** when you pass in [ChipGroupSpaceOptions](#chipgroupspaceoptions).

## ChipGroupItemOptions

Defines the specific attributes of individual chips.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                          | Mandatory| Description                             |
| ----------   | ----------------------------- | ---- | ----------------------------------- |
| prefixIcon   | [IconOptions](#iconoptions)   | No  | Prefix image icon of the chip.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                  |
| prefixSymbol | [ChipSymbolGlyphOptions](ohos-arkui-advanced-Chip.md#chipsymbolglyphoptions12) | No  | Prefix symbol glyph icon of the chip.<br>**Atomic service API**: This API can be used in atomic services since API version 12.            |
| label        | [LabelOptions](#labeloptions) | Yes  | Text of the chip.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                           |
| suffixIcon<sup>(deprecated)</sup>   | [IconOptions](#iconoptions) | No  | Suffix image icon of the chip.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**NOTE**<br>This API is supported since API version 12 and deprecated since API version 14. You are advised to use **suffixImageIcon** instead. |
| suffixSymbol | [ChipSymbolGlyphOptions](ohos-arkui-advanced-Chip.md#chipsymbolglyphoptions12) | No  | Suffix symbol glyph icon of the chip.<br>**Atomic service API**: This API can be used in atomic services since API version 12.            |
| allowClose   | boolean                       | No  | Whether to show the close icon.<br>Default value: **false**<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| suffixImageIcon<sup>14+</sup> | [SuffixImageIconOptions](#suffiximageiconoptions14) | No| Suffix image icon of the chip.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| suffixSymbolOptions<sup>14+</sup> | [ChipSuffixSymbolGlyphOptions](ohos-arkui-advanced-Chip.md#chipsuffixsymbolglyphoptions14) | No| Suffix symbol icon of the chip.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| closeOptions<sup>14+</sup> | [CloseOptions](ohos-arkui-advanced-Chip.md#closeoptions14) | No| Accessibility options of the default close icon.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| accessibilityDescription<sup>14+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Accessible description of the chip. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the chip's attributes and accessibility text alone. If a chip contains both text information and the accessible description, the text is announced first and then the accessible description, when the chip is selected.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| accessibilityLevel<sup>14+</sup> | string | No| Accessibility level of the chip. It determines whether the chip can be recognized by accessibility services.<br>The options are as follows:<br>**"auto"**: It is treated as "yes" by the system.<br>**"yes"**: The chip can be recognized by accessibility services.<br>**"no"**: The chip cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the chip nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**<br>**Atomic service API**: This API can be used in atomic services since API version 14.|


>**NOTE**
>
>If **suffixIcon** is specified, **allowClose** has no effect.

## ChipItemStyle

Defines the common attributes shared by all chips in the chip group.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                   | Type                                                        | Mandatory| Description                                                        |
| ----------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size                    | [ChipSize](ohos-arkui-advanced-Chip.md#chipsize) \| [SizeOptions](ts-types.md#sizeoptions) | No  | Chip size. To use this API, you must import the **ChipSize** type from the **Chip** component.<br>Default value: **ChipSize**: **ChipSize.NORMAL**<br>If this parameter is set to **undefined**, the default value is used.|
| backgroundColor         | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Background color of the chip.<br>Default value: **$r('sys.color.ohos_id_color_button_normal')**<br>If this parameter is set to **undefined**, the default value is used.|
| fontColor               | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Font color of the chip.<br>Default value: **$r('sys.color.ohos_id_color_text_primary')**<br>If this parameter is set to **undefined**, the default value is used.|
| selectedFontColor       | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Font color of the chip when it is activated or selected.<br>Default value: **$r('sys.color.ohos_id_color_text_primary_contrary')**<br>If this parameter is set to **undefined**, the default value is used.|
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Background color of the chip when it is activated or selected.<br>Default value: **$r('sys.color.ohos_id_color_emphasize').**<br>If this parameter is set to **undefined**, the default value is used.|

> **NOTE**
>
> 1. The size settings for chips can be of two types: (1) **ChipSize**, which conveniently offers two size options, **NORMAL** and **SMALL**; (2) **SizeOptions**.
>
> 2. If **undefined** is assigned to **backgroundColor** or **selectedBackgroundColor**, the default background color is used. If an invalid value is assigned, the background color is transparent.

## ChipGroupSpaceOptions

Defines the left and right padding of the chip group, and the spacing between chips.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type           | Mandatory| Description                                            |
| ---------- | -------------- | ---- | ------------------------------------------------ |
| itemSpace | string \| number  | No  | Spacing between chips. Percentage values are not supported.<br>Default value: **8**<br>Unit: vp<br>If this parameter is set to **undefined**, the default value is used.     |
| startSpace | [Length](ts-types.md#length)         | No  | Left padding. Percentage values are not supported.<br>Default value: **16**<br>Unit: vp<br>If this parameter is set to **undefined**, the default value is used.               |
| endSpace   | [Length](ts-types.md#length)         | No  | Right padding. Percentage values are not supported.<br>Default value: **16**<br>Unit: vp<br>If this parameter is set to **undefined**, the default value is used.|

## ChipGroupPaddingOptions

Defines the top and bottom padding of the chip group, used to control the overall height.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type           | Mandatory| Description                                                     |
| ------ | -------------- | ---- | ------------------------------------------------            |
| top    | [Length](ts-types.md#length)         | Yes  | Top padding. Percentage values are not supported.<br>Default value: **14**<br>If this parameter is set to **undefined**, the default value is used.       |
| bottom | [Length](ts-types.md#length)         | Yes  | Top padding. Percentage values are not supported.<br>Default value: **14**<br>If this parameter is set to **undefined**, the default value is used.        |

## SuffixImageIconOptions<sup>14+</sup>

Defines the suffix iconoptions.

Inherits [IconOptions](#iconoptions).

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| ---- | ---- | --- | ---- |
| action | [VoidCallback](ts-types.md#voidcallback12) | No| Action of the suffix icon.|
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No| Accessibility text, that is, accessible label name, of the suffix icon. If an icon does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which icon is selected. To solve this problem, you can set accessibility text for icons without text information. When such an icon is selected, the screen reader announces the specified accessibility text, informing the user which icon is selected.|
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No| Accessible description of the suffix icon. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the chip's attributes and accessibility text alone. If an icon contains both text information and the accessible description, the text is announced first and then the accessible description, when the icon is selected.|
| accessibilityLevel | string | No| Accessibility level of the suffix icon. It determines whether the icon can be recognized by accessibility services.<br>The options are as follows:<br>**"auto"**: It is treated as "yes" when **action** is set for the icon and as "no" otherwise.<br>**"yes"**: The icon can be recognized by accessibility services.<br>**"no"**: The icon cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the icon nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**|

## SymbolItemOptions<sup>14+</sup>

Defines the options for the trailing symbol item in a chip group.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| ---- | ---- | --- | ---- |
| symbol | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | Yes| Settings of the trailing symbol item.|
| action | [VoidCallback](ts-types.md#voidcallback12) | Yes| Action of the trailing symbol item.|
| accessibilityText | [ResourceStr](ts-types.md#resourcestr) | No| Accessibility text of the trailing symbol item. If a trailing symbol item does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which item is selected. To solve this problem, you can set accessibility text for trailing symbol items without text information. When such a trailing symbol item is selected, the screen reader announces the specified accessibility text, informing the user which item is selected.|
| accessibilityDescription | [ResourceStr](ts-types.md#resourcestr) | No| Accessible description of the trailing symbol item. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the chip's attributes and accessibility text alone. If a trailing symbol item contains both text information and the accessible description, the text is announced first and then the accessible description, when the trailing symbol item is selected.|
| accessibilityLevel | string | No| Accessibility level of the trailing symbol item. It determines whether the trailing symbol item can be recognized by accessibility services.<br>The options are as follows:<br>**"auto"**: It is treated as "yes" by the system.<br>**"yes"**: The trailing symbol item can be recognized by accessibility services.<br>**"no"**: The trailing symbol item cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the trailing symbol item nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**|

## IconGroupSuffix

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                   | Mandatory| Decorator| Description                                                             |
| -------- | ---------------------- | ---- | ----------------------------------------------| ----------------------------------------------|
| items    | Array<[IconItemOptions](#iconitemoptions) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) \| [ SymbolItemOptions](#symbolitemoptions14)> | Yes  | @Require  @Prop | Custom builder items.|

> **NOTE**
>
> With **SymbolGlyphModifier**, neither modifying the animation type with **symbolEffect** nor setting the effect strategy with **effectStrategy** is supported.
>

## IconItemOptions

Defines the tail builder, which imposes limitations on the settings for the background size and color.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type                           | Mandatory| Description                                   |
| -------- | --------------                 | ---- | ------------------------------           |
| icon     | [IconOptions](#iconoptions)    | Yes  | Custom builder icon.<br>When the chip size is **ChipSize.SMALL**, the suffix is at {width: 16, height: 16} by default.<br>When the chip size is **ChipSize.NORMAL**, the suffix is at {width: 24, height: 24} by default.<br>To dynamically change the size, you must use the [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) type when importing the [IconGroupSuffix](#icongroupsuffix) API.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                      |
| action   | Callback\<void>        | Yes  | Callback of custom builder items.<br>If the value is **undefined**, the event is unbound.<br>**Atomic service API**: This API can be used in atomic services since API version 12.           |
| accessibilityText<sup>14+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Accessibility text of the trailing symbol item. If a trailing symbol item does not contain text information, it will not be announced by the screen reader when selected. In this case, the screen reader user cannot know which item is selected. To solve this problem, you can set accessibility text for trailing symbol items without text information. When such a component is selected, the screen reader announces the specified accessibility text, informing the user which component is selected.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| accessibilityDescription<sup>14+</sup> | [ResourceStr](ts-types.md#resourcestr) | No| Accessible description of the trailing symbol item. You can provide comprehensive text explanations to help users understand the operation they are about to perform and its potential consequences, especially when these cannot be inferred from the chip's attributes and accessibility text alone. If a trailing symbol item contains both text information and the accessible description, the text is announced first and then the accessible description, when the trailing symbol item is selected.<br> **Atomic service API**: This API can be used in atomic services since API version 14.|
| accessibilityLevel<sup>14+</sup> | string | No| Accessibility level of the trailing symbol item. It determines whether the trailing symbol item can be recognized by accessibility services.<br>The options are as follows:<br>**"auto"**: It is treated as "yes" by the system.<br>**"yes"**: The trailing symbol item can be recognized by accessibility services.<br>**"no"**: The trailing symbol item cannot be recognized by accessibility services.<br>**"no-hide-descendants"**: Neither the trailing symbol item nor its child components can be recognized by accessibility services.<br>Default value: **"auto"**<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## IconOptions

Defines the common attributes of icons.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type                                  | Mandatory| Description                                                        |
| ---- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| src  | [ResourceStr](ts-types.md#resourcestr) | Yes  | Icon source, which can be a specific image path or an image reference.                                    |
| size | [SizeOptions](ts-types.md#sizeoptions) | No  | Icon size. This parameter cannot be set in percentage.|

## LabelOptions

Defines the common attributes of labels.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Mandatory | Description    |
| ---- | ------ | ---- | -------- |
| text | string | Yes  | Text of the chip. |

## Example

### Example 1: Implementing a Chip Group Without a Builder-defined Suffix

This example shows how to implement a chip group without a builder-defined suffix.

```typescript
import { ChipSize, ChipGroup } from '@kit.ArkUI'

@Entry
@Preview
@Component
struct Index {
  @State selected_index: Array<number> = [0, 1, 2, 3, 4, 5, 6]
  build() {
    Column() {
      ChipGroup({
        items: [
          {
            // Replace 'app.media.icon' with your actual icon resource.
            prefixIcon: { src: $r('app.media.icon') },
            label: { text: "Chip 1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "Chip 2" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "Chip 3" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Chip 4" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "Chip 5" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Chip 6" },
            allowClose: true
          },
        ],
        itemStyle: {
          size: ChipSize.SMALL,
          backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
          fontColor: $r('sys.color.ohos_id_color_text_primary'),
          selectedBackgroundColor: $r('sys.color.ohos_id_color_emphasize'),
          selectedFontColor: $r('sys.color.ohos_id_color_text_primary_contrary'),
        },
        selectedIndexes: this.selected_index,
        multiple: false,
        chipGroupSpace: { itemSpace: 8, endSpace: 0 },
        chipGroupPadding: { top: 10, bottom: 10 },
        onChange: (activatedChipsIndex:Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
      })
    }
  }
}
```

![](figures/chipGroupDemo1.jpeg)

### Example 2: Implementing a Chip Group with a Builder-defined Suffix

This example shows how to implement a chip group with a builder-defined suffix.

```typescript
import { ChipSize, ChipGroup, IconGroupSuffix  } from '@kit.ArkUI'

@Entry
@Preview
@Component
struct Index {
  @State selected_index: Array<number> = [0, 1, 2, 3, 4, 5, 6]
  @State selected_state: boolean = true;

  @LocalBuilder
  ChipGroupSuffix(): void {
    IconGroupSuffix({
      items: [{
        icon: { src: $r('sys.media.ohos_ic_public_search_filled'), size: { width: 36, height: 36 } },
        action: () => {
          if (this.selected_state == false) {
            this.selected_index = [0, 1, 2, 3, 4, 5, 6]
            this.selected_state = true
          } else {
            this.selected_index = []
            this.selected_state = false
          }
        }
      }
      ]
    })
  }

  build() {
    Column() {
      ChipGroup({
        items: [
          {
            prefixIcon: { src: $r('app.media.icon') },
            label: { text: "Chip 1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "Chip 2" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "Chip 3" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Chip 4" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "Chip 5" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Chip 6" },
            allowClose: true
          },
        ],
        itemStyle: {
          size: ChipSize.NORMAL,
          backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
          fontColor: $r('sys.color.ohos_id_color_text_primary'),
          selectedBackgroundColor: $r('sys.color.ohos_id_color_emphasize'),
          selectedFontColor: $r('sys.color.ohos_id_color_text_primary_contrary'),
        },
        selectedIndexes: this.selected_index,
        multiple: true,
        chipGroupSpace: { itemSpace: 8, endSpace: 0 },
        chipGroupPadding: { top: 10, bottom: 10 },
        onChange: (activatedChipsIndex: Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
        suffix: this.ChipGroupSuffix
      })
    }
  }
}
```

![](figures/chipGroupDemo2.jpeg)

### Example 3: Setting the Symbol Icon
This example implements **IconGroupSuffix** and **ChipGroup** with **SymbolGlyph** resources.
```typescript
import { ChipSize, ChipGroup, IconGroupSuffix, SymbolGlyphModifier } from '@kit.ArkUI'

@Entry
@Preview
@Component
struct Index {
  @State selected_index: Array<number> = [0, 1, 2, 3, 4, 5, 6];
  @State selected_state: boolean = true;
  @State prefixModifierNormal: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_star'));
  @State prefixModifierActivated: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontColor([Color.Red]);
  @State suffixModifierNormal: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi'));
  @State suffixModifierActivated: SymbolGlyphModifier = new SymbolGlyphModifier($r('sys.symbol.ohos_wifi')).fontColor([Color.Red]);

  @LocalBuilder
  ChipGroupSuffix(): void {
    IconGroupSuffix({
      items: [
        new SymbolGlyphModifier($r('sys.symbol.magnifyingglass'))
          .onClick(() => {
            if (this.selected_state == false) {
              this.selected_index = [0, 1, 2, 3, 4, 5, 6];
              this.selected_state = true;
            } else {
              this.selected_index = [];
              this.selected_state = false;
            }
          })
      ]
    })
  }

  build() {
    Column() {
      ChipGroup({
        items: [
          {
            prefixSymbol: { normal: this.prefixModifierNormal, activated: this.prefixModifierActivated },
            label: { text: "Chip 1" },
            suffixSymbol: { normal: this.suffixModifierNormal, activated: this.suffixModifierActivated },
            allowClose: false,
          },
          {
            prefixSymbol: { normal: this.prefixModifierNormal, activated: this.prefixModifierActivated },
            label: { text: "Chip 2" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "Chip 3" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Chip 4" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "Chip 5" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Chip 6" },
            allowClose: true,
          },
        ],
        itemStyle: {
          size: ChipSize.NORMAL,
          backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
          fontColor: $r('sys.color.ohos_id_color_text_primary'),
          selectedBackgroundColor: $r('sys.color.ohos_id_color_emphasize'),
          selectedFontColor: $r('sys.color.ohos_id_color_text_primary_contrary'),
        },
        selectedIndexes: this.selected_index,
        multiple: true,
        chipGroupSpace: { itemSpace: 8, endSpace: 0 },
        chipGroupPadding: { top: 10, bottom: 10 },
        onChange: (activatedChipsIndex: Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
        suffix: this.ChipGroupSuffix
      })
    }
  }
}

```
![](figures/chipGroupDemo3.jpeg)

### Example 4: Implementing the Screen Reader Feature for the Single-selection Scenario

This example implements the screen reader feature for a chip group with and without a suffix area in a single-selection scenario.

```typescript
import { ChipGroup, IconGroupSuffix, SymbolGlyphModifier } from '@kit.ArkUI';

@Builder function DefaultFunction(): void {}

@Component
struct SectionGroup {
  @Prop
  @Require
  title: ResourceStr;
  @BuilderParam
  @Require
  content: () => void = DefaultFunction;

  build() {
    Column({ space: 4 }) {
      Text(this.title)
        .fontColor('#FF666666')
        .fontSize(12)
      Column({ space: 8 }) {
        this.content()
      }
    }
    .alignItems(HorizontalAlign.Start)
    .width('100%')
  }
}
@Component
struct SectionItem {
  @Prop
  @Require
  title: ResourceStr;
  @BuilderParam
  @Require
  content: () => void = DefaultFunction;

  build() {
    Column({ space: 12 }) {
      Text(this.title)
      this.content()
    }
    .backgroundColor('#FFFFFFFF')
    .borderRadius(12)
    .padding(12)
    .width('100%')
  }
}

@Entry
@Component
export struct ChipGroupExample2 {
  @LocalBuilder
  Suffix() {
    IconGroupSuffix({
      items: [
        {
          icon: { src: $r('sys.media.ohos_ic_public_more'), },
          accessibilityText: 'More',
          accessibilityDescription: 'Speak usage hints',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: 'More icon touched.'
            });
          }
        },
        {
          symbol: new SymbolGlyphModifier($r('sys.symbol.more')),
          accessibilityText: 'More',
          accessibilityDescription: 'Speak usage hints',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: 'More icon touched.'
            });
          }
        },
        {
          icon: { src: $r('sys.media.ohos_ic_public_more'), },
          accessibilityText: 'More',
          accessibilityDescription: 'Speak usage hints',
          accessibilityLevel: 'no',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: 'More icon touched.'
            });
          }
        }
      ]
    })
  }

  build() {
    NavDestination() {
      Scroll() {
        Column({ space: 12 }) {
          SectionGroup({ title: 'Available' }) {
            SectionItem({ title: 'Single selection without suffix area' }) {
              ChipGroup({
                items: [
                  {
                    prefixIcon: {
                      src: $r('app.media.startIcon')
                    },
                    label: { text: "Option 1" },
                    suffixImageIcon: {
                      src: $r('sys.media.save_button_picture'),
                      accessibilityText: 'Save',
                      action: () => {
                        this.getUIContext().getPromptAction().showToast({
                          message: 'Suffix icon touched.'
                        });
                      },
                    }
                  },
                  {
                    label: { text: "Option 2" },
                    suffixSymbol: {
                      normal: new SymbolGlyphModifier($r('sys.symbol.save')),
                      activated: new SymbolGlyphModifier($r('sys.symbol.save'))
                    },
                    suffixSymbolOptions: {
                      normalAccessibility: {
                        accessibilityText: 'Save'
                      },
                      action: () => {
                        this.getUIContext().getPromptAction().showToast({
                          message: 'Suffix icon touched.'
                        });
                      }
                    }
                  },
                  {
                    label: { text: "Option 3" },
                    suffixIcon: { src: $r('sys.media.save_button_picture'), }
                  },
                  { label: { text: "Option 4" } },
                  { label: { text: "Option 5" } },
                  { label: { text: "Option 6" } },
                  { label: { text: "Option 7" } },
                  { label: { text: "Option 8" } },
                  { label: { text: "Option 9" } },
                ]
              })
            }
            SectionItem({ title: 'Single selection with suffix area' }) {
              ChipGroup({
                items: [
                  { label: { text: "Option 1" } },
                  { label: { text: "Option 2" } },
                  { label: { text: "Option 3" } },
                  { label: { text: "Option 4" } },
                  { label: { text: "Option 5" } },
                  { label: { text: "Option 6" } },
                  { label: { text: "Option 7" } },
                  { label: { text: "Option 8" } },
                  { label: { text: "Option 9" } },
                ],
                suffix: this.Suffix.bind(this),
              })
            }
          }
        }
      }
      .padding({
        top: 8,
        bottom: 8,
        left: 16,
        right: 16, })
    }
    .title('Basic usage')
    .backgroundColor('#F1F3F5')
  }
}
```

### Example 5: Implementing the Screen Reader Feature for the Multi-selection Scenario

This example implements the screen reader feature for a chip group with and without a suffix area in a multi-selection scenario.

```typescript
import { ChipGroup, IconGroupSuffix, SymbolGlyphModifier } from '@kit.ArkUI';

@Builder function DefaultFunction(): void {}

@Component
struct SectionGroup {
  @Prop
  @Require
  title: ResourceStr;
  @BuilderParam
  @Require
  content: () => void = DefaultFunction;

  build() {
    Column({ space: 4 }) {
      Text(this.title)
        .fontColor('#FF666666')
        .fontSize(12)
      Column({ space: 8 }) {
        this.content()
      }
    }
    .alignItems(HorizontalAlign.Start)
    .width('100%')
  }
}
@Component
struct SectionItem {
  @Prop
  @Require
  title: ResourceStr;
  @BuilderParam
  @Require
  content: () => void = DefaultFunction;

  build() {
    Column({ space: 12 }) {
      Text(this.title)
      this.content()
    }
    .backgroundColor('#FFFFFFFF')
    .borderRadius(12)
    .padding(12)
    .width('100%')
  }
}

@Entry
@Component
export struct ChipGroupExample2 {
  @LocalBuilder
  Suffix() {
    IconGroupSuffix({
      items: [
        {
          icon: { src: $r('sys.media.ohos_ic_public_more'), },
          accessibilityText: 'More',
          accessibilityDescription: 'Speak usage hints',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: 'More icon touched.'
            });
          }
        },
        {
          symbol: new SymbolGlyphModifier($r('sys.symbol.more')),
          accessibilityText: 'More',
          accessibilityDescription: 'Speak usage hints',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: 'More icon touched.'
            });
          }
        },
        {
          icon: { src: $r('sys.media.ohos_ic_public_more'), },
          accessibilityText: 'More',
          accessibilityDescription: 'Speak usage hints',
          accessibilityLevel: 'no',
          action: () => {
            this.getUIContext().getPromptAction().showToast({
              message: 'More icon touched.'
            });
          }
        }
      ]
    })
  }

  build() {
    NavDestination() {
      Scroll() {
        Column({ space: 12 }) {
          SectionGroup({ title: 'Available' }) {
            SectionItem({ title: 'Multi-selection without suffix area' }) {
              ChipGroup({
                items: [
                  { label: { text: "Option 1" } },
                  { label: { text: "Option 2" } },
                  { label: { text: "Option 3" } },
                  { label: { text: "Option 4" } },
                  { label: { text: "Option 5" } },
                  { label: { text: "Option 6" } },
                  { label: { text: "Option 7" } },
                  { label: { text: "Option 8" } },
                  { label: { text: "Option 9" } },
                ],
                multiple: true
              })
            }
            SectionItem({ title: 'Multi-selection with suffix area' }) {
              ChipGroup({
                items: [
                  { label: { text: "Option 1" } },
                  { label: { text: "Option 2" } },
                  { label: { text: "Option 3" } },
                  { label: { text: "Option 4" } },
                  { label: { text: "Option 5" } },
                  { label: { text: "Option 6" } },
                  { label: { text: "Option 7" } },
                  { label: { text: "Option 8" } },
                  { label: { text: "Option 9" } },
                ],
                suffix: this.Suffix.bind(this),
                multiple: true,
              })
            }
          }
        }
      }
      .padding({
        top: 8,
        bottom: 8,
        left: 16,
        right: 16, })
    }
    .title('Basic usage')
    .backgroundColor('#F1F3F5')
  }
}
```
