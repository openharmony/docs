# @ohos.arkui.advanced.ChipGroup (ChipGroup)

ChipGroup advanced component, which provides operation block groups for classifying files or resource content.

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

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name           | Type                                           | Mandatory | Description                                                                                      |
| --------------- | ----------------------------------------------- | ---- | ------------------------------------------------------------                             |
| items           | [ChipGroupItemOptions[]](#chipgroupitemoptions) | Yes  | Specific attributes of each chip. For details, see [ChipGroupItemOptions[]](#chipgroupitemoptions).<br>When is set to undefined, ChipGroup is left blank by default.              |
| itemStyle       | [ChipItemStyle](#chipitemstyle)                 | No  | Chip style attributes, such as the color and size. For details, see [ChipItemStyle](#chipitemstyle).<br>If this parameter is set to undefined, the chip pattern in the chip group is the default value.                |
| selectedIndexes | Array&lt;number&gt;                             | No  | Indicates the index of the selected chip.<br>If this parameter is set to undefined, the first chip is selected by default.                                           |
| multiple        | boolean                                         | No  | **true**: Multiple chips can be selected. **false**: Only one chip can be selected.<br>Default value: **false**<br>If this parameter is set to undefined, the default value of multiple is used.                    |
| chipGroupSpace  | [ChipGroupSpaceOptions](#chipgroupspaceoptions) | No  | Left and right inner margins, and spacing between chips. For details, see [ChipGroupSpaceOptions](#chipgroupspaceoptions).<br>If this parameter is set to undefined, the default value of chipGroupSpace is used. |
| onChange        | (selectedIndexes: Array&lt;number&gt;) => void  | No  | Callback method when the chip status changes.<br>If this parameter is set to undefined, the event is unbound.                                                       |
| suffix          | ()=>void                                        | No  | The builder on the right is user-defined. The [IconGroupSuffix](#icongroupsuffix) interface needs to be introduced when the builder is used.<br>Default value: If this parameter is not transferred, there is no suffix. |

> **NOTE**
>
> 1. For the selectedIndexes and multiple interfaces, when multiple is false and selectedIndexes is not transferred, the first chip is selected by default. When selectedIndexes contains more than one element, the chip with the first index is selected by default.
>
> 2. For the suffix interface, the IconGroupSuffix interface needs to be introduced. If the IconGroupSuffix interface is not transferred, there is no suffix.
>
> 3. The settings of the icon fill color (fillColor and activedFillColor) are the same as those of the font color (fontColor). If you want the two colors to be different, use prefixSymbol when transferring [ChipGroupSpaceOptions](#chipgroupspaceoptions).

## ChipGroupItemOptions

ChipGroupItemOptions defines the non-common attributes of each chip.

| Name        | Type                          | Mandatory | Description                               |
| ----------   | ----------------------------- | ---- | ----------------------------------- |
| prefixIcon   | [IconOptions](#iconoptions)   | No  | Prefix icon of the chip.                  |
| label        | [LabelOptions](#labeloptions) | Yes  | Text of the chip.                           |
| suffixIcon   | [IconOptions](#iconoptions) | No  | Suffix icon of the chip.                  |
| allowClose   | boolean                       | No  | Whether to show the deletion icon.<br>Default value: **false** |

>**NOTE**
>
>If **suffixIcon** is specified, **allowClose** has no effect.

## ChipItemStyle

ChipItemStyle defines the common attributes of a chip.

| Name                   | Type                                                             | Mandatory | Description.                                                 |
| ----------------------- | ----------------------                                           | ---- | -------------------------------                       |
| size                    | [ChipSize](ohos-arkui-advanced-Chip.md#chipsize) \| [SizeOptions](ts-types.md#sizeoptions)  | No  | Chip size. The ChipSize type needs to be introduced from the chip component.<br>Default value: ChipSize: ChipSize.NORMAL.<br> If this parameter is set to undefined, the default value of ChipSize is used. |
| backgroundColor         | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Background color of the chip.<br>Default value: **$r('sys.color.ohos_id_color_button_normal').**<br>If this parameter is set to undefined, the default value of backgroundColor is used.                 |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Chip text color.<br>Default value: **$r('sys.color.ohos_id_color_text_primary')**<br>If this parameter is set to undefined, the default value of fontColor is used.                   |
| selectedFontColor       | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Text color when the chip is activated.<br>Default value: **$r('sys.color.ohos_id_color_text_primary_contrary').**<br>If this parameter is set to undefined, the default value of selectedFontColor is used.   |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)                       | No  | Background color when the chip is activated.<br>Default value: **$r('sys.color.ohos_id_color_emphasize').**<br>If this parameter is set to undefined, the default value of selectedBackgroundColor is used.               |

> **NOTE**
>
> 1. The size of the operation block can be **ChipSize** (**NORMAL** or **SMALL**). The other is **SizeOptions**. The operation block has a minimum width limit. When the width set by the user is less than the minimum width, the operation block is displayed based on the minimum width.
>
> 2. If **undefined** is assigned to **backgroundColor**, the default background color is used. If an invalid value is assigned to **backgroundColor**, the background color is transparent.

## ChipGroupSpaceOptions

ChipGroupSpaceOptions defines the left and right inner margins of a chip group and the spacing between chips.

| Name      | Type           | Mandatory | Description                                              |
| ---------- | -------------- | ---- | ------------------------------------------------ |
| itemSpace | string \| number  | No  | Spacing between chips (the percentage is not supported).<br>Default value: **8**<br>Unit: vp<br>If this parameter is set to undefined, the default value of itemSpace is used.     |
| startSpace | [Length](ts-types.md#length)         | No  | Left inner margin (percentage not supported).<br>Default value: **16**<br>Unit: vp<br>If this parameter is set to undefined, the default value of startSpace is used.               |
| endSpace   | [Length](ts-types.md#length)         | No  | Right inner margin (percentage not supported).<br>Default value: **16**<br>Unit: vp<br>If this parameter is set to undefined, the default value of endSpace is used. |

## ChipGroupPaddingOptions

Defines the top and bottom margins of a chip group to control the overall height of the chip group.

| Name  | Type           | Mandatory | Description                                                       |
| ------ | -------------- | ---- | ------------------------------------------------            |
| top    | [Length](ts-types.md#length)         | Yes  | Upper inner margin of the chip group (percentage not supported).<br>Default value: 14<br>If this parameter is set to undefined, the default value of top is used.       |
| bottom | [Length](ts-types.md#length)         | Yes  | Upper inner margin of the chip group (percentage not supported).<br>Default value: 14<br>If this parameter is set to undefined, the default value is used for bottom.        |

## IconGroupSuffix

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                   | Mandatory | Description.                                                               |
| -------- | ---------------------- | ---- | ----------------------------------------------                      |
| items    | Array<[IconItemOptions](#iconitemoptions)> | Yes  | Customize builder items. For details, see the IconItemOptions interface.   |

## IconItemOptions

Defines the tail builder interface and sets restrictions on the backplane size and color.

| Name    | Type                           | Mandatory | Description                                     |
| -------- | --------------                 | ---- | ------------------------------           |
| icon     | [IconOptions](#iconoptions)    | Yes  | Customizing the Builder Icon                       |
| action   | Callback\<void>        | Yes  | Callback of Customized Builder Items<br>If this parameter is set to undefined, the event is unbound.           |

## IconOptions

IconOptions defines the common attributes of icons.

| Name | Type                                  | Mandatory | Note:                                                        |
| ---- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| src  | [ResourceStr](ts-types.md#resourcestr) | Yes  | Icon source, which can be a specific image path or an image reference.                                    |
| size | [SizeOptions](ts-types.md#sizeoptions) | No  | Icon size. The percentage is not supported.<br>When the chip size is ChipSize.SMALL, the default value of suffix is {width: 16,height: 16}.<br>When the chip size is ChipSize.NORMAL, the default value of suffix is {width: 24,height: 24}.<br> If you want to dynamically change the value of size, you must use the [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) type when introducing [IconGroupSuffix](#icongroupsuffix).|

## LabelOptions

Label defines the common attributes of icons.

| Name | Type  | Mandatory | Note:    |
| ---- | ------ | ---- | -------- |
| text | string | Yes  | Text of the chip. |

## Example

### Example 1 - No suffix

```typescript
import { ChipSize } from '@ohos.arkui.advanced.Chip'
import { ChipGroup } from '@ohos.arkui.advanced.ChipGroup';

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
            label: { text: "Operation Block 1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "Operation Block 2" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "Operation Block 3" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Operation Block 4" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "Operation Block 5" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Operation Block 6" },
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
        onChange: (activatedChipsIndex:Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
      })
    }
  }
}
```

![](figures/chipGroupDemo1.jpeg)

### Example 2 - With suffix

```typescript
import { ChipSize } from '@ohos.arkui.advanced.Chip'
import { ChipGroup,IconGroupSuffix } from '@ohos.arkui.advanced.ChipGroup';

@Entry
@Preview
@Component
struct Index {
  @State selected_index: Array<number> = [0, 1, 2, 3, 4, 5, 6]
  @State selected_state: boolean = true;

  @Builder
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
            label: { text: "Operation Block 1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "Operation Block 2" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "Operation Block 3" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Operation Block 4" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "Operation Block 5" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "Operation Block 6" },
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
        onChange: (activatedChipsIndex: Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
        suffix: this.ChipGroupSuffix.bind(this)
      })
    }
  }
}
```

![](figures/chipGroupDemo2.jpeg)
