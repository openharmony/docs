# @ohos.arkui.advanced.ChipGroup (操作块组组件)

ChipGroup高级组件，提供操作块群组，用于对文件或者资源内容进行分类等场景。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## ChipGroup

```
ChipGroup({
  items: ChipGroupItemOptions[],
  itemStyle?: ChipItemStyle,
  selectedIndexes?: Array<number>,
  multiple?: boolean,
  chipGroupSpaceSize?: ChipGroupSpaceOptions,
  onChange?: (selectedIndexes: Array<number>) => void,
  suffix?: Callback<void>
})
```

**装饰器类型：**@Builder

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称            | 类型                                            | 必填 | 描述                                                                                       |
| --------------- | ----------------------------------------------- | ---- | ------------------------------------------------------------                             |
| items           | [ChipGroupItemOptions[]](#chipgroupitemoptions) | 是   | 每个chip特定的属性，参考[ChipGroupItemOptions[]](#chipgroupitemoptions)类型。               |
| itemStyle       | [ChipItemStyle](#chipitemstyle)                 | 否   | chip的style属性，比如颜色，大小等，参考[ChipItemStyle](#chipitemstyle)类型。                 |
| selectedIndexes | Array&lt;number&gt;                             | 否   | 被选中chip的索引。<br/>默认值：第一个chip被选中。                                            |
| multiple        | boolean                                         | 否   | true：支持多个chip被选中；false：只能是单个chip被选中。<br/>默认值：false                     |
| chipGroupSpace  | [ChipGroupSpaceOptions](#chipgroupspaceoptions) | 否   | 左右内边距,和chip与chip之间的间距。参考[ChipGroupSpaceOptions](#chipgroupspaceoptions)类型。 |
| onChange        | (selectedIndexes: Array&lt;number&gt;) => void  | 否   | chip状态改变时候的回调方法。                                                                |
| suffix          | ()=>void                                        | 否   | 最右侧的builder，由使用者自定义，使用时候需引入[IconGroupSuffix](#icongroupsuffix)接口。<br/>默认值：不传入的情况，没有suffix。 |

> **说明：**
>
> 1. 针对selectedIndexes和multiple接口，multiple等于false的时候，当没有传入selectedIndexes时候，默认是第一个chip被选中，当传入的selectedIndexes有一个以上的元素时候，默认第一个索引的chip被选中。
>
> 2. 针对suffix接口，使用时候需要引入IconGroupSuffix接口，不传入的情况，没有suffix。

## ChipGroupItemOptions

ChipGroupItemOptions定义每个chip的非共通属性。

| 名称         | 类型                           | 必填 | 描述                                |
| ----------   | ----------------------------- | ---- | ----------------------------------- |
| prefixIcon   | [IconOptions](#iconoptions)   | 否   | 前缀Image图标属性。                   |
| prefixSymbol | [SymbolOptions](ohos-arkui-advanced-Chip.md#symboloptions) | 否   | 前缀SymbolGlyph图标属性。             |
| label        | [LabelOptions](#labeloptions) | 是   | 文本属性。                            |
| suffixIcon   | [IconOptions](#iconoptions) | 否   | 后缀Image图标属性。                   |
| suffixSymbol | [SymbolOptions](ohos-arkui-advanced-Chip.md#symboloptions) | 否   | 后缀SymbolGlyph图标属性。             |
| allowClose   | boolean                       | 否   | 删除图标是否显示。<br/>默认值：true。  |

>**说明：**
>
>suffixIcon有传入参数时，allowClose不生效，suffixIcon没有传入参数时，allowClose决定是否显示删除图标。

## ChipItemStyle

ChipItemStyle定义了chip的共通属性。

| 名称                    | 类型                                                              | 必填 | 描述                                                  |
| ----------------------- | ----------------------                                           | ---- | -------------------------------                       |
| size                    | [ChipSize](ohos-arkui-advanced-Chip.md#chipsize) \| [SizeOptions](ts-types.md#sizeoptions)  | 否   | chip尺寸，使用时需要从chip组件引入ChipSize类型。<br/>默认值：ChipSize：ChipSize.NORMAL。<br/>  |
| backgroundColor         | [ResourceColor](ts-types.md#resourcecolor)                       | 否   | chip背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_button_normal')。                   |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor)                       | 否   | chip文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary')。                    |
| selectedFontColor       | [ResourceColor](ts-types.md#resourcecolor)                       | 否   | chip激活时的文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_contrary')。    |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)                       | 否   | chip激活时的背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_emphasize')。                |

> **说明：**
>
> 1.操作块的大小可以是两种类型，一种是ChipSize，为方便使用，有两种尺寸可选分别是NORMAL和SMALL；另一种是SizeOptions，操作块有最小宽度限制，当用户设置宽度小于最小宽度时，按最小宽度显示。
>
> 2.backgroundColor、selectedBackgroundColor赋值undefined时，显示默认背景颜色，赋值非法值时，背景色透明。

## ChipGroupSpaceOptions

ChipGroupSpaceOptions 定义了chipGroup左右内边距，以及chip与chip直接的间距。

| 名称       | 类型            | 必填 | 描述                                               |
| ---------- | -------------- | ---- | ------------------------------------------------ |
| itemSpace | string\|number  | 否   | chip与chip之间的间距（不支持百分比）。<br/>默认值：8                 |
| startSpace | Length         | 否   | 左侧内边距（不支持百分比）。<br/>默认值：16                          |
| endSpace   | Length         | 否   | 右侧内边距（不支持百分比）。<br/>默认值：16    |

## IconGroupSuffix

| 名称     | 类型                    | 必填 | 描述                                                                |
| -------- | ---------------------- | ---- | ----------------------------------------------|
| items    | Array<[IconItemOptions](#iconitemoptions) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md)> | 是   | 自定义builder items。|

## IconItemOptions

尾部builder接口定义，针对背板大小及颜色设置限制。

| 名称     | 类型                            | 必填 | 描述                                      |
| -------- | --------------                 | ---- | ------------------------------           |
| icon     | [IconOptions](#iconoptions)    | 是   | 自定义Builder icon                        |
| action   | ()=>void                       | 是   | 自定义Builder items 的Callback            |

## IconOptions

IconOptions定义图标的共通属性。

| 名称 | 类型                                   | 必填 | 说明                                                         |
| ---- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| src  | [ResourceStr](ts-types.md#resourcestr) | 是   | 图标图片或图片地址引用。                                     |
| size | [SizeOptions](ts-types.md#sizeoptions) | 否   | 图标大小，不支持百分比。<br/>chip默认值：{width: 16,height: 16}。<br/>suffix默认值：<br/>chip大小是ChipSize.SMALL时，suffix默认值：{width: 16,height: 16}。 <br/>chip大小是ChipSize.NORMAL时，suffix默认值：{width: 24,height: 24}。 |

## LabelOptions

Label定义图标的共通属性。

| 名称 | 类型   | 必填  | 说明     |
| ---- | ------ | ---- | -------- |
| text | string | 是   | 文本属性  |

## 示例

### 示例1-无suffix

```typescript

import { Chip, ChipSize } from '@ohos.arkui.advanced.Chip'
import { ChipGroup,IconGroupSuffix } from '@ohos.arkui.advanced.ChipGroup';

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
            label: { text: "操作块1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "操作块2" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "操作块3" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块4" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "操作块5" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块6" },
            allowClose: true,
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

### 示例2-有suffix

```typescript
import { Chip, ChipSize } from '@ohos.arkui.advanced.Chip'
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
            label: { text: "操作块1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "操作块2" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "操作块3" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块4" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "操作块5" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块6" },
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

### 示例3
该示例实现了IconGroupSuffix及ChipGroup传入SymbolGlyph资源。
```typescript
import { ChipSize } from '@ohos.arkui.advanced.Chip'
import { ChipGroup, IconGroupSuffix } from '@ohos.arkui.advanced.ChipGroup';
import { SymbolGlyphModifier } from '@ohos.arkui.modifier';

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

  @Builder
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
            label: { text: "操作块1" },
            suffixSymbol: { normal: this.suffixModifierNormal, activated: this.suffixModifierActivated },
            allowClose: false,
          },
          {
            prefixSymbol: { normal: this.prefixModifierNormal, activated: this.prefixModifierActivated },
            label: { text: "操作块2" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "操作块3" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块4" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "操作块5" },
            allowClose: true,
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块6" },
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
        onChange: (activatedChipsIndex: Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
        suffix: this.ChipGroupSuffix.bind(this)
      })
    }
  }
}

```
![](figures/chipGroupDemo3.jpeg)