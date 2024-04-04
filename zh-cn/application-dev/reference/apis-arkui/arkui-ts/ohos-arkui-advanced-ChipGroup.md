## 	@ohos.arkui.advanced.ChipGroup 

ChipGroup，用于对文件或者资源内容进行分类等场景。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## ChipGroup

```
ChipGroup({
            items: ChipGroupItemOptions[],
            itemStyle: ChipItemStyle,
            selectedIndexes: Array<number>,
            multiple: boolean,
            chipGroupSpaceSize: ChipGroupSpaceOptions,
            onChange: (selectedIndexes: Array<number>) => void,
            suffix: Callback<void>
          })
```



**装饰器类型：**@Builder

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| **名称**           | **类型**                                  | 必填 | 描述                                                         |
| ------------------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| items              | [ChipItemOptions](#chipitemoptions)[]     | 是   | 每个chip特定的属性，参考[ChipItemOptions](#chipitemoptions)[]类型。 |
| itemStyle          | [ChipItemStyle](#chipitemstyle)          | 否   | chip的style属性，比如颜色，大小等，参考ChipItemStyle类型。   |
| selectedIndexes    | Array<number>                             | 否   | 被选中chip的索引。<br/>默认值：第一个chip被选中。            |
| multiple           | boolean                                   | 否   | true：支持多个chip被选中；false：只能是单个chip被选中。<br/>默认值：true |
| chipGroupSpaceSize | [ChipGroupSpaceOptions](#chipitemoptions) | 否   | 左右内边距,和chip与chip之间的间距。参考ChipGroupSpaceOptions类型。 |
| onChange           | (selectedIndexes: Array<number>) => void  | 否   | chip状态改变时候的回调方法。                                 |
| suffix             | Callback<void>                            | 是   | 最右侧的builder，由使用者自定义，使用时候需引入IconGroupSuffix接口。<br/>默认值：不传入的情况无，没有suffix。 |

> **说明：**
>
> 1. 针对selectedIndexes和multiple接口，multiple等于false的时候，当没有传入selectedIndexes时候，默认是第一个chip被选中，当传入的selectedIndexes有一个以上的元素时候，默认第一个索引的chip被选中。
> 2. 针对suffix接口，使用时候需要引入IconGroupSuffix接口，不传入的情况，没有suffix。



## ChipItemOptions

ChipItemOptions定义每个chip的非共通属性。

| 名称       | 类型                          | 必填 | 描述                                  |
| ---------- | ----------------------------- | ---- | ------------------------------------- |
| prefixIcon | [IconOptions](#iconoptions) | 否   | 前缀图标属性。                        |
| label      | [LabelOptions](#labeloptions) | 是   | 文本属性。                            |
| suffixIcon | [IconOptions](#iconoptions)   | 否   | 后缀图标属性。                        |
| allowClose | boolean                       | 否   | 删除图标是否显示。<br/>默认值：true。 |



## ChipItemStyle

ChipItemStyle定义了chip的共通属性。

| **名称**                | **类型**                                                     | 必填 | 描述                                                         |
| ----------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size                    | [ChipSize](ohos-arkui-advanced-Chip.md#chipsize) | 否   | chip尺寸，使用时需要从chip组件引入ChipSize类型。<br/>默认值：ChipSize：ChipSize.NORMAL。<br/> |
| backgroundColor         | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_button_normal')。 |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary')。 |
| selectedFontColor       | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip激活时的文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_contrary')。 |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | chip激活时的背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_emphasize')。 |



## ChipGroupSpaceOptions

ChipGroupSpaceOptions 定义了chipGroup左右内边距，以及chip与chip直接的间距。

| 名称       | 类型           | 必填 | 描述                                                |
| ---------- | -------------- | ---- | --------------------------------------------------- |
| space      | string\|number | 否   | chip与chip之间的间距。<br/>默认值：8                |
| startSpace | Length         | 否   | 左侧内边距。<br/>默认值：16                         |
| endSpace   | Length         | 否   | 右侧内边距(没有自定义builder的时候)。<br/>默认值：0 |



## IconGroupSuffix

| **名称** | **类型**               | 必填 | 描述                                           |
| -------- | ---------------------- | ---- | ---------------------------------------------- |
| items    | Array<IconItemOptions> | 是   | 自定义builder items，参考IconItemOptions接口。 |

​	

## IconItemOptions

尾部builder接口定义，针对背板大小及颜色设置限制。

| **名称** | **类型**       | 必填 | 描述                           |
| -------- | -------------- | ---- | ------------------------------ |
| icon     | IconOptions    | 是   | 自定义builder icon             |
| action   | Callback<void> | 是   | 自定义Builder items 的Callback |



## IconOptions

IconOptions定义图标的共通属性。

| 名称 | 类型                                   | 必填 | 说明                                                         |
| ---- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| src  | [ResourceStr](ts-types.md#resourcestr) | 是   | 图标图片或图片地址引用。                                     |
| size | [SizeOptions](ts-types.md#sizeoptions) | 否   | 图标大小，不支持百分比。<br/>chip默认值：{width: 16,height: 16}。<br/>suffix默认值：<br/>chip大小是ChipSize.SMALL时，suffix默认值：{width: 16,height: 16}。 <br/>chip大小是ChipSize.NORMAL时，suffix默认值：{width: 24,height: 24}。 |

## LabelOptions

Label定义图标的共通属性。

| 名称 | 类型   | 必填 | 说明     |
| ---- | ------ | ---- | -------- |
| text | string | 是   | 文本属性 |



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
        chipGroupSpaceSize: { itemSpace: 8, endSpace: 0 },
        onChange: (activatedChipsIndex:Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
        // suffix: this.ChipGroupSuffix
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
        chipGroupSpaceSize: { itemSpace: 8, endSpace: 0 },
        onChange: (activatedChipsIndex: Array<number>) => {
          console.log('chips on clicked, activated index ' + activatedChipsIndex)
        },
        suffix: this.ChipGroupSuffix
      })
    }
  }
}


```

![](figures/chipGroupDemo1.jpeg)
