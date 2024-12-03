# ChipGroup

ChipGroup高级组件，提供操作块群组，用于对文件或者资源内容进行分类等场景。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```typescript
import { ChipSize, ChipGroup } from '@kit.ArkUI'
```

## 子组件

无

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

**装饰器类型：**@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型                                            | 必填 | 装饰器类型 | 说明                                                                                     |
| --------------- | ----------------------------------------------- | ---- | ------------------------------------------------------------                             | ------------------------------------------------------------                             |
| items           | [ChipGroupItemOptions[]](#chipgroupitemoptions) | 是   | @Require &nbsp;@Prop | 每个chip特定的属性，参考[ChipGroupItemOptions[]](#chipgroupitemoptions)类型。<br/>为undefined时，ChipGroup默认为空。               |
| itemStyle       | [ChipItemStyle](#chipitemstyle)                 | 否   | @Prop | chip的style属性，比如颜色，大小等，参考[ChipItemStyle](#chipitemstyle)类型。<br/>为undefined时，ChipGroup中的Chip式样为默认值。                 |
| selectedIndexes | Array&lt;number&gt;                             | 否   | @Prop | 被选中chip的索引。<br/>为undefined时，默认第一个Chip被选中。                                            |
| multiple        | boolean                                         | 否   | @Prop | true：支持多个chip被选中；false：只能是单个chip被选中。<br/>默认值：false<br/>为undefined时，multiple走默认值。                     |
| chipGroupSpace  | [ChipGroupSpaceOptions](#chipgroupspaceoptions) | 否   | @Prop | 左右内边距，和chip与chip之间的间距。参考[ChipGroupSpaceOptions](#chipgroupspaceoptions)类型。<br/>为undefined时，chipGroupSpace走默认值。 |
| chipGroupPadding  | [ChipGroupPaddingOptions](#chipgrouppaddingoptions) | 否   | @Prop | chipGroup的上下内边距，以便控制整体高度。参考[ChipGroupPaddingOptions](#chipgrouppaddingoptions)类型。<br/>为undefined时，chipGroupPadding走默认值。 |
| onChange        | Callback\<Array\<number>>  | 否   | -  | chip状态改变时候的回调方法。<br/>为undefined时，表示解绑事件。                                                                |
| suffix          | ()=>void                                        | 否   | @BuilderParam | 最右侧的builder，由使用者自定义，使用时候需引入[IconGroupSuffix](#icongroupsuffix)接口。<br/>默认值：不传入的情况，没有suffix。 |

> **说明：**
>
> 1. 针对selectedIndexes和multiple接口，multiple等于false的时候，当没有传入selectedIndexes时候，默认是第一个chip被选中，当传入的selectedIndexes有一个以上的元素时候，默认第一个索引的chip被选中。
>
> 2. 针对suffix接口，使用时候需要引入IconGroupSuffix接口，不传入的情况，没有suffix。
>
> 3. 关于图标填充色（fillColor以及activedFillColor）的设置，跟随字体颜色（fontColor）保持一致。若想两者颜色不同，则需要在传入[ChipGroupSpaceOptions](#chipgroupspaceoptions)时，使用prefixSymbol。

## ChipGroupItemOptions

ChipGroupItemOptions定义每个chip的非共通属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称         | 类型                           | 必填 | 说明                              |
| ----------   | ----------------------------- | ---- | ----------------------------------- |
| prefixIcon   | [IconOptions](#iconoptions)   | 否   | 前缀Image图标属性。                   |
| prefixSymbol | [ChipSymbolGlyphOptions](ohos-arkui-advanced-Chip.md#chipsymbolglyphoptions12) | 否   | 前缀SymbolGlyph图标属性。             |
| label        | [LabelOptions](#labeloptions) | 是   | 文本属性。                            |
| suffixIcon   | [IconOptions](#iconoptions) | 否   | 后缀Image图标属性。                   |
| suffixSymbol | [ChipSymbolGlyphOptions](ohos-arkui-advanced-Chip.md#chipsymbolglyphoptions12) | 否   | 后缀SymbolGlyph图标属性。             |
| allowClose   | boolean                       | 否   | 删除图标是否显示。<br/>默认值：false。  |

>**说明：**
>
>suffixIcon有传入参数时，allowClose不生效，suffixIcon没有传入参数时，allowClose决定是否显示删除图标。

## ChipItemStyle

ChipItemStyle定义了chip的共通属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                    | 类型                                                         | 必填 | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size                    | [ChipSize](ohos-arkui-advanced-Chip.md#chipsize) \| [SizeOptions](ts-types.md#sizeoptions) | 否   | chip尺寸，使用时需要从chip组件引入ChipSize类型。<br/>默认值：ChipSize：ChipSize.NORMAL。<br/> 为undefined时，ChipSize走默认值。 |
| backgroundColor         | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_button_normal')。<br/>为undefined时，backgroundColor走默认值。 |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary')。<br/>为undefined时，fontColor走默认值。 |
| selectedFontColor       | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip激活时的文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_contrary')。<br/>为undefined时，selectedFontColor走默认值。 |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip激活时的背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_emphasize')。<br/>为undefined时，selectedBackgroundColor走默认值。 |

> **说明：**
>
> 1.操作块的大小可以是两种类型，一种是ChipSize，为方便使用，有两种尺寸可选分别是NORMAL和SMALL；另一种是SizeOptions。
>
> 2.backgroundColor、selectedBackgroundColor赋值undefined时，显示默认背景颜色，赋值非法值时，背景色透明。

## ChipGroupSpaceOptions

ChipGroupSpaceOptions 定义了chipGroup左右内边距，以及chip与chip直接的间距。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型            | 必填 | 说明                                             |
| ---------- | -------------- | ---- | ------------------------------------------------ |
| itemSpace | string \| number  | 否   | chip与chip之间的间距（不支持百分比）。<br/>默认值：8<br/>单位：vp<br/>为undefined时，itemSpace走默认值。      |
| startSpace | [Length](ts-types.md#length)         | 否   | 左侧内边距（不支持百分比）。<br/>默认值：16<br/>单位：vp<br/>为undefined时，startSpace走默认值。                |
| endSpace   | [Length](ts-types.md#length)         | 否   | 右侧内边距（不支持百分比）。<br/>默认值：16<br/>单位：vp<br/>为undefined时，endSpace走默认值。 |

## ChipGroupPaddingOptions

ChipGroupPaddingOptions 定义了chipGroup上下内边距，以便控制chipGroup的整体高度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型            | 必填 | 说明                                                      |
| ------ | -------------- | ---- | ------------------------------------------------            |
| top    | [Length](ts-types.md#length)         | 是   | chipGroup的上方内边距（不支持百分比）。<br/>默认值：14<br/>为undefined时，top走默认值。        |
| bottom | [Length](ts-types.md#length)         | 是   | chipGroup的上方内边距（不支持百分比）。<br/>默认值：14<br/>为undefined时，bottom走默认值。         |

## IconGroupSuffix

**装饰器类型：**@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                    | 必填|装饰器类型 | 说明  |
| -------- | ---------------------- | ---- |-----|----------------------------------------------|
| items    | Array<[IconItemOptions](#iconitemoptions) \| [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md)> | 是  |@Require &nbsp;@Prop | 自定义builder items。|

> **说明：**
>
> 传参SymbolGlyphModifier时，不支持通过symbolEffect修改动效类型和effectStrategy设置动效。
>

## IconItemOptions

尾部builder接口定义，针对背板大小及颜色设置限制。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                            | 必填 | 说明                                    |
| -------- | --------------                 | ---- | ------------------------------           |
| icon     | [IconOptions](#iconoptions)    | 是   | 自定义Builder icon。<br/>chip大小是ChipSize.SMALL时，suffix默认值：{width: 16,height: 16}。<br/>chip大小是ChipSize.NORMAL时，suffix默认值：{width: 24,height: 24}。</br> 如果想动态修改size，那么必须在引入[IconGroupSuffix](#icongroupsuffix)时，使用[SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md)类型。                       |
| action   | Callback\<void>        | 是   | 自定义Builder items 的Callback<br/>为undefined时，表示解绑事件。            |

## IconOptions

IconOptions定义图标的共通属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                                   | 必填 | 说明                                                         |
| ---- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| src  | [ResourceStr](ts-types.md#resourcestr) | 是   | 图标图片或图片地址引用。                                     |
| size | [SizeOptions](ts-types.md#sizeoptions) | 否   | 图标大小，不支持百分比。|

## LabelOptions

Label定义图标的共通属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 必填  | 说明     |
| ---- | ------ | ---- | -------- |
| text | string | 是   | 文本属性  |

## 示例

### 示例1（无最右侧的builder）

该示例实现了无最右侧的builder时效果。

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
            label: { text: "操作块1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "操作块2" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "操作块3" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块4" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "操作块5" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块6" },
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

### 示例2（有最右侧的builder）

该示例通过配置suffix实现最右侧的自定义组件效果。

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
            label: { text: "操作块1" },
            suffixIcon: { src: $r('sys.media.ohos_ic_public_cut') },
            allowClose: false
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_copy') },
            label: { text: "操作块2" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_clock') },
            label: { text: "操作块3" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块4" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_mirror') },
            label: { text: "操作块5" },
            allowClose: true
          },
          {
            prefixIcon: { src: $r('sys.media.ohos_ic_public_cast_stream') },
            label: { text: "操作块6" },
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

### 示例3（设置Symbol类型图标）
该示例实现了IconGroupSuffix及ChipGroup传入SymbolGlyph资源。
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
