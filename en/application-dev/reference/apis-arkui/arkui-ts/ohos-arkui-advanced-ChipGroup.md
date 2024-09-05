# ChipGroup

**ChipGroup** is an advanced component that provides a group of chips for scenarios such as categorizing files or resource content.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

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

**Parameters**

| Name           | Type                                           | Mandatory| Description                                                                                      |
| --------------- | ----------------------------------------------- | ---- | ------------------------------------------------------------                             |
| items           | [ChipGroupItemOptions[]](#chipgroupitemoptions) | Yes  | Specific attributes of individual chips. For details, see [ChipGroupItemOptions[]](#chipgroupitemoptions).<br>If this parameter is set to **undefined**, the chip group is empty by default.              |
| itemStyle       | [ChipItemStyle](#chipitemstyle)                 | No  | Chip style, including the color and size. For details, see [ChipItemStyle](#chipitemstyle).<br>If this parameter is set to **undefined**, the default chip style is used.                |
| selectedIndexes | Array&lt;number&gt;                             | No  | Index of the selected chip.<br>If this parameter is set to **undefined**, the first chip is selected.                                           |
| multiple        | boolean                                         | No  | Whether multiple chips can be selected.<br>**true**: Multiple chips can be selected.<br>**false**: Only one chip can be selected.<br>Default value: **false**<br>If this parameter is set to **undefined**, the default value is used.                    |
| chipGroupSpace  | [ChipGroupSpaceOptions](#chipgroupspaceoptions) | No  | Left and right padding, and the spacing between chips. For details, see [ChipGroupSpaceOptions](#chipgroupspaceoptions).<br>If this parameter is set to **undefined**, the default value is used.|
| chipGroupPadding  | [ChipGroupPaddingOptions](#chipgrouppaddingoptions) | No  | Top and bottom padding, used to control the overall height. For details, see [ChipGroupPaddingOptions](#chipgrouppaddingoptions).<br>If this parameter is set to **undefined**, the default value is used.|
| onChange        | (selectedIndexes: Array&lt;number&gt;) => void  | No  | Callback invoked when the chip status changes.<br>If the value is **undefined**, the event is unbound.                                                               |
| suffix          | ()=>void                                        | No  | Suffix, which is a builder customized by the user and requires importing the [IconGroupSuffix](#icongroupsuffix) API when used.<br>Default value: The suffix is not displayed if not passed.|

> **NOTE**
>
> 1. When **multiple** is set to **false**, if **selectedIndexes** is not passed in, the first chip is automatically selected by default. However, if the provided **selectedIndexes** includes multiple elements, the chip at the first index is selected by default.
>
> 2. For the **suffix** API to work, you must include the **IconGroupSuffix** API when implementing it. If no value is specified for **suffix**, no suffix will be displayed.
>
> 3. The icon fill colors, such as **fillColor** and **activedFillColor**, are set to be consistent with the font color (**fontColor**). To differentiate the icon colors from the font color, include **prefixSymbol** when you pass in [ChipGroupSpaceOptions](#chipgroupspaceoptions).

## ChipGroupItemOptions

Defines the specific attributes of individual chips.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name        | Type                          | Mandatory| Description                               |
| ----------   | ----------------------------- | ---- | ----------------------------------- |
| prefixIcon   | [IconOptions](#iconoptions)   | No  | Prefix image icon of the chip.                  |
| prefixSymbol | [ChipSymbolGlyphOptions](ohos-arkui-advanced-Chip.md#chipsymbolglyphoptions12) | No  | Prefix symbol glyph icon of the chip.            |
| label        | [LabelOptions](#labeloptions) | Yes  | Text of the chip.                           |
| suffixIcon   | [IconOptions](#iconoptions) | No  | Suffix image icon of the chip.                  |
| suffixSymbol | [ChipSymbolGlyphOptions](ohos-arkui-advanced-Chip.md#chipsymbolglyphoptions12) | No  | Suffix symbol glyph icon of the chip.            |
| allowClose   | boolean                       | No  | Whether to show the close icon.<br>Default value: **false** |

>**NOTE**
>
>If **suffixIcon** is specified, **allowClose** has no effect.

## ChipItemStyle

Defines the common attributes shared by all chips in the chip group.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                   | Type                                                             | Mandatory| Description                                                 |
| ----------------------- | ----------------------                                           | ---- | -------------------------------                       |
| size                    | [ChipSize](ohos-arkui-advanced-Chip.md#chipsize) \| [SizeOptions](ts-types.md#sizeoptions)  | No  | Chip size. To use this API, you must import the **ChipSize** type from the **Chip** component.<br>Default value: **ChipSize**: **ChipSize.NORMAL**<br> If this parameter is set to **undefined**, the default value is used. |
| backgroundColor         | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Background color of the chip.<br>Default value: **$r('sys.color.ohos_id_color_button_normal')**<br>If this parameter is set to **undefined**, the default value is used.                 |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Font color of the chip.<br>Default value: **$r('sys.color.ohos_id_color_text_primary')**<br>If this parameter is set to **undefined**, the default value is used.                   |
| selectedFontColor       | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Font color of the chip when it is activated or selected.<br>Default value: **$r('sys.color.ohos_id_color_text_primary_contrary')**<br>If this parameter is set to **undefined**, the default value is used.   |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Background color of the chip when it is activated or selected.<br>Default value: **$r('sys.color.ohos_id_color_emphasize')**<br>If this parameter is set to **undefined**, the default value is used.               |

> **NOTE**
>
> 1. The size settings for chips can be of two types: (1) **ChipSize**, which conveniently offers two size options, **NORMAL** and **SMALL**; (2) **SizeOptions**.
>
> 2. If **undefined** is assigned to **backgroundColor** or **selectedBackgroundColor**, the default background color is used. If an invalid value is assigned, the background color is transparent.

## ChipGroupSpaceOptions

Defines the left and right padding of the chip group, and the spacing between chips.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type           | Mandatory| Description                                              |
| ---------- | -------------- | ---- | ------------------------------------------------ |
| itemSpace | string \| number  | No  | Spacing between chips. Percentage values are not supported.<br>Default value: **8**<br>Unit: vp<br>If this parameter is set to **undefined**, the default value is used.     |
| startSpace | [Length](ts-types.md#length)         | No  | Left padding. Percentage values are not supported.<br>Default value: **16**<br>Unit: vp<br>If this parameter is set to **undefined**, the default value is used.               |
| endSpace   | [Length](ts-types.md#length)         | No  | Right padding. Percentage values are not supported.<br>Default value: **16**<br>Unit: vp<br>If this parameter is set to **undefined**, the default value is used.|

## ChipGroupPaddingOptions

Defines the top and bottom padding of the chip group, used to control the overall height.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name  | Type           | Mandatory| Description                                                       |
| ------ | -------------- | ---- | ------------------------------------------------            |
| top    | [Length](ts-types.md#length)         | Yes  | Top padding. Percentage values are not supported.<br>Default value: **14**<br>If this parameter is set to **undefined**, the default value is used.       |
| bottom | [Length](ts-types.md#length)         | Yes  | Bottom padding. Percentage values are not supported.<br>Default value: **14**<br>If this parameter is set to **undefined**, the default value is used.        |

## IconGroupSuffix

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                   | Mandatory| Description                                                               |
| -------- | ---------------------- | ---- | ----------------------------------------------|
| items    | Array<[IconItemOptions](#iconitemoptions) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md)> | Yes  | Custom builder items.|

> **NOTE**
>
> With **SymbolGlyphModifier**, neither modifying the animation type with **symbolEffect** nor setting the effect strategy with **effectStrategy** is supported.
>

## IconItemOptions

Defines the tail builder, which imposes limitations on the settings for the background size and color.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name    | Type                           | Mandatory| Description                                     |
| -------- | --------------                 | ---- | ------------------------------           |
| icon     | [IconOptions](#iconoptions)    | Yes  | Custom builder icon.                       |
| action   | Callback\<void>        | Yes  | Callback of custom builder items.<br>If the value is **undefined**, the event is unbound.           |

## IconOptions

Defines the common attributes of icons.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Type                                  | Mandatory| Description                                                        |
| ---- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| src  | [ResourceStr](ts-types.md#resourcestr) | Yes  | Icon source, which can be a specific image path or an image reference.                                    |
| size | [SizeOptions](ts-types.md#sizeoptions) | No  | Icon size. Percentage values are not supported.<br>When the chip size is **ChipSize.SMALL**, the default suffix is at {width: 16, height: 16}.<br>When the chip size is **ChipSize.NORMAL**, the default suffix is at {width: 24, height: 24}.<br> To dynamically change the size, you must use the [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) type when importing the [IconGroupSuffix](#icongroupsuffix) API.|

## LabelOptions

Defines the common attributes of labels.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Type  | Mandatory | Description    |
| ---- | ------ | ---- | -------- |
| text | string | Yes  | Text of the chip. |

## Example

### Example 1: Suffix Not Included

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

### Example 2: Suffix Included

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

### Example 3
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
