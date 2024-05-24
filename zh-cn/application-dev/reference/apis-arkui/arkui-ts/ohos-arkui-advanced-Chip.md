#  @ohos.arkui.advanced.Chip (操作块组件)

操作块，用于搜索框历史记录或者邮件发送列表等场景。

> **说明：**
>
> 该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## Chip

Chip({options:ChipOptions})

**装饰器类型：**@Builder

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称    | 类型                        | 必填 | 装饰器类型 | 说明                 |
| ------- | --------------------------- | ---- | ---------- | -------------------- |
| options | [ChipOptions](#chipoptions) | 是   | @Builder   | 定义chip组件的参数。 |

## ChipOptions

ChipOptions定义chip的样式及具体式样参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型                                                         | 必填 | 说明                                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size            | [ChipSize](#chipsize) \| [SizeOptions](ts-types.md#sizeoptions) | 否   | 操作块尺寸。<br/>默认值：ChipSize：ChipSize.NORMAL，<br/>   SizeOptions类型参数不支持百分比设置。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| enabled         | boolean                                                      | 否   | 操作块是否可选中。<br>默认值：true<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| activated<sup>12+</sup>       | boolean                                        | 否   | 操作块是否为激活态。<br>默认值：false                      |
| prefixIcon      | [PrefixIconOptions](#prefixiconoptions)                      | 否   | 前缀图标属性。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| prefixSymbol<sup>12+</sup>    | [SymbolOptions](#symboloptions12)              | 否   | 前缀图标属性，symbol类型。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| label           | [LabelOptions](#labeloptions)                                | 是   | 文本属性。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。   |
| suffixIcon      | [SuffixIconOptions](#suffixiconoptions)                      | 否   | 后缀图标属性。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| suffixSymbol<sup>12+</sup>    | [SymbolOptions](#symboloptions12)              | 否   | 后缀图标属性，symbol类型。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| backgroundColor | [ResourceColor](ts-types.md#resourcecolor)                   | 否   | 操作块背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_button_normal')<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| activatedBackgroundColor<sup>12+</sup> | [ResourceColor](ts-types.md#resourcecolor)          | 否   | 操作块激活时的背景颜色。<br/>默认值：$r('sys.color.ohos_id_color_emphasize')。 |
| borderRadius    | [Dimension](ts-types.md#dimension10)                         | 否   | 操作块背景圆角半径大小，不支持百分比。<br/>默认值：$r('sys.float.ohos_id_corner_radius_button')<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| allowClose      | boolean                                                      | 否   | 删除图标是否显示。<br/>默认值：true<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| onClose         | ()=>void                                                     | 否   | 默认删除图标点击事件。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| onClicked<sup>12+</sup>       | ()=>void                                       | 否   | 操作块点击事件。                                       |

> **说明：**
>
> 1.操作块有最小宽度限制，当用户设置宽度小于最小宽度时，按最小宽度显示。
>
> 2.suffixSymbol有传入参数时，suffixIcon和allowClose不生效；suffixSymbol没有传入参数、suffixIcon有传入参数时，allowClose不生效；suffixSymbol和suffixIcon都没有传入参数时，allowClose决定是否显示删除图标。
>
> 3.backgroundColor和activatedBackgroundColor赋值undefined时，显示默认背景颜色，赋值非法值时，背景色透明。
>
> 4.prefixSymbol/suffixSymbol的fontColor默认值，normalFontColor: `[$r('sys.color.ohos_id_color_primary')]`、activatedFontColor: `[$r('sys.color.ohos_id_color_text_primary_contrary')]`。fontColor默认值为16。
>
> 5.prefixIcon的fillColor默认值：`$r('sys.color.ohos_id_color_secondary')`，suffixIcon的fillColor默认值：`$r('sys.color.ohos_id_color_primary')`。fillColor对颜色的解析与Image组件保持一致。
>
> 6.prefixIcon的activatedFillColor默认值：`$r('sys.color.ohos_id_color_text_primary_contrary')`，suffixIcon的activatedFillColor默认值：`$r('sys.color.ohos_id_color_text_primary_contrary')`。activatedFillColor对颜色的解析与Image组件保持一致。

## ChipSize

ChipSize是chip可指定的尺寸类型，如普通型Chip。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称   | 值       | 描述               |
| ------ | -------- | ------------------ |
| NORMAL | "NORMAL" | normal尺寸操作块。 |
| SMALL  | "SMALL"  | small尺寸操作块。  |

## IconCommonOptions

IconCommonOptions定义图标的共通属性。

| 名称      | 类型                                       | 必填 | 说明                                                         |
| --------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| src       | [ResourceStr](ts-types.md#resourcestr)     | 是   | 图标图片或图片地址引用。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| size      | [SizeOptions](ts-types.md#sizeoptions)     | 否   | 图标大小，不支持百分比。<br/>默认值：{width: 16,height: 16}<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| fillColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | 图标填充颜色。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| activatedFillColor<sup>12+</sup> | [ResourceColor](ts-types.md#resourcecolor) | 否   | 操作块激活时图标填充颜色。                            |

> **说明：**
>
> 仅在图片格式为svg时，fillColor和activatedFillColor生效。
>

## PrefixIconOptions

PrefixIconOptions定义前缀图标的属性。

继承于[IconCommonOptions](#iconcommonoptions)。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

## SuffixIconOptions

SuffixIconOptions定义后缀图标的属性。

继承于[IconCommonOptions](#iconcommonoptions)。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称   | 类型       | 必填 | 说明               |
| ------ | ---------- | ---- | ------------------ |
| action | () => void | 否   | 后缀图标设定事件。 |

## SymbolOptions<sup>12+</sup>

SymbolOptions定义前缀图标和后缀图标的属性。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称   | 类型       | 必填 | 说明               |
| ------ | ---------- | ---- | ------------------ |
| normal | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | 图标设定事件。 |
| activated | [SymbolGlyphModifier](ts-universal-attributes-attribute-modifier.md) | 否   | 激活时图标设定事件。 |

## LabelOptions

LabelOptions定义文本的属性。

| 名称        | 类型                                       | 必填 | 说明                                                         |
| ----------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| text        | string                                     | 是   | 文本文字内容。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| fontSize    | [Dimension](ts-types.md#dimension10)       | 否   | 文字字号，不支持百分比。<br/>默认值：$r('sys.float.ohos_id_text_size_button2')<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| fontColor   | [ResourceColor](ts-types.md#resourcecolor) | 否   | 文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary')<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| activatedFontColor<sup>12+</sup>   | [ResourceColor](ts-types.md#resourcecolor) | 否   | 操作块激活时的文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_contrary') |
| fontFamily  | string                                     | 否   | 文字字体。<br/>默认值："HarmonyOS Sans"<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |
| labelMargin | [LabelMarginOptions](#labelmarginoptions)  | 否   | 文本与左右侧图标之间间距。<br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |

## LabelMarginOptions

LabelMarginOptions定义文本与左右侧图标之间间距。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称  | 类型                                 | 必填 | 说明                                                     |
| ----- | ------------------------------------ | ---- | -------------------------------------------------------- |
| left  | [Dimension](ts-types.md#dimension10) | 否   | 文本与左侧图标之间间距，不支持百分比。<br/>默认值：6vp。 |
| right | [Dimension](ts-types.md#dimension10) | 否   | 文本与右侧图标之间间距，不支持百分比。<br/>默认值：6vp。 |


## 示例

### 示例1

```ts
import { Chip, ChipSize } from '@ohos.arkui.advanced.Chip';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 10 }) {
      Chip({
        prefixIcon: {
          src: $r('app.media.chips'),
          size: { width: 16, height: 16 },
          fillColor: Color.Red,
        },
        label: {
          text: "操作块",
          fontSize: 12,
          fontColor: Color.Blue,
          fontFamily: "HarmonyOS Sans",
          labelMargin: { left: 20, right: 30 },
        },
        suffixIcon: {
          src: $r('app.media.close'),
          size: { width: 16, height: 16 },
          fillColor: Color.Red,
        },
        size: ChipSize.NORMAL,
        allowClose: false,
        enabled: true,
        backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
        borderRadius: $r('sys.float.ohos_id_corner_radius_button')
      })
    }
  }
}
```


![](figures/chip1.png)

### 示例2

```ts
import { Chip, ChipSize } from '@ohos.arkui.advanced.Chip';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 10 }) {
      Chip({
        prefixIcon: {
          src: $r('app.media.chips'),
          size: { width: 16, height: 16 },
          fillColor: Color.Blue,
        },
        label: {
          text: "操作块",
          fontSize: 12,
          fontColor: Color.Blue,
          fontFamily: "HarmonyOS Sans",
          labelMargin: { left: 20, right: 30 },
        },
        size: ChipSize.NORMAL,
        allowClose: true,
        enabled: true,
        backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
        borderRadius: $r('sys.float.ohos_id_corner_radius_button')
      })
    }
  }
}
```


![](figures/chip2.png)

### 示例3

```ts
import { Chip, ChipSize } from '@ohos.arkui.advanced.Chip';

@Entry
@Component
struct Index {
  build() {
    Column({ space: 10 }) {
      Chip({
        prefixIcon: {
          src: $r('app.media.chips'),
          size: { width: 16, height: 16 },
          fillColor: Color.Blue,
        },
        label: {
          text: "操作块",
          fontSize: 12,
          fontColor: Color.Blue,
          fontFamily: "HarmonyOS Sans",
          labelMargin: { left: 20, right: 30 },
        },
        size: ChipSize.SMALL,
        allowClose: false,
        enabled: true,
        backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
        borderRadius: $r('sys.float.ohos_id_corner_radius_button'),
        onClose:()=>{
          console.log("chip on close")
      }
      })
    }
  }
}
```


![](figures/chip3.png)

### 示例4

```ts
import { Chip, ChipSize } from '@ohos.arkui.advanced.Chip';

@Entry
@Component
struct Index {
  @State isActivated: boolean = false

  build() {
    Column({ space: 10 }) {
      Chip({
        prefixIcon: {
          src: $r('app.media.chips'),
          size: { width: 16, height: 16 },
          fillColor: Color.Blue,
          activatedFillColor: $r('sys.color.ohos_id_color_text_primary_contrary')
        },
        label: {
          text: "操作块",
          fontSize: 12,
          fontColor: Color.Blue,
          activatedFontColor: $r('sys.color.ohos_id_color_text_primary_contrary'),
          fontFamily: "HarmonyOS Sans",
          labelMargin: { left: 20, right: 30 },
        },
        size: ChipSize.NORMAL,
        allowClose: true,
        enabled: true,
        activated: this.isActivated,
        backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
        activatedBackgroundColor: $r('sys.color.ohos_id_color_emphasize'),
        borderRadius: $r('sys.float.ohos_id_corner_radius_button'),
        onClose:()=>{
          console.log("chip on close")
        },
        onClicked:()=>{
          console.log("chip on clicked")
        }
      })

      Button('改变激活状态').onClick(()=>{
        this.isActivated = !this.isActivated
      })
    }
  }
}
```


![](figures/chip4.gif)

### 示例5

Chip组件的前缀、后缀图标使用symbol类型资源展示。

```ts
import { Chip, ChipSize } from '@ohos.arkui.advanced.Chip';
import { SymbolGlyphModifier } from '@ohos.arkui.modifier';

@Entry
@Component
struct Index {
  @State isActivated: boolean = false

  build() {
    Column({ space: 10 }) {
      Chip({
        prefixIcon: {
          src: $r('app.media.chips'),
          size: { width: 16, height: 16 },
          fillColor: Color.Blue,
          activatedFillColor: $r('sys.color.ohos_id_color_text_primary_contrary')
        },
		prefixSymbol: {
          normal: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontSize(16).fontColor([Color.Green]),
          activated: new SymbolGlyphModifier($r('sys.symbol.ohos_star')).fontSize(16).fontColor([Color.Red]),
		},
        label: {
          text: "操作块",
          fontSize: 12,
          fontColor: Color.Blue,
          activatedFontColor: $r('sys.color.ohos_id_color_text_primary_contrary'),
          fontFamily: "HarmonyOS Sans",
          labelMargin: { left: 20, right: 30 },
        },
        size: ChipSize.NORMAL,
        allowClose: true,
        enabled: true,
        activated: this.isActivated,
        backgroundColor: $r('sys.color.ohos_id_color_button_normal'),
        activatedBackgroundColor: $r('sys.color.ohos_id_color_emphasize'),
        borderRadius: $r('sys.float.ohos_id_corner_radius_button'),
        onClose:()=>{
          console.log("chip on close")
        },
        onClicked:()=>{
          console.log("chip on clicked")
        }
      })

      Button('改变激活状态').onClick(()=>{
        this.isActivated = !this.isActivated
      })
    }
  }
}
```

![](figures/chip5.gif)