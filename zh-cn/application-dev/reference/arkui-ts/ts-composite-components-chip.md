#  @ohos.arkui.advanced.Chip（操作块组件）

操作块，用于搜索框历史记录或者邮件发送列表等场景。

> **说明：**
>
> 该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## Chip

Chip({options:ChipOptions})

**装饰器类型：**@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 名称    | 类型                        | 必填 | 装饰器类型 | 说明                 |
| ------- | --------------------------- | ---- | ---------- | -------------------- |
| options | [ChipOptions](#chipoptions) | 是   | @Builder   | 定义chip组件的参数。 |

## ChipOptions

ChipOptions定义chip的样式及具体式样参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称            | 类型                                    | 必填 | 说明                                                         |
| --------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| size            | [ChipSize](#chipsize) \| SizeOptions    | 否   | 操作块尺寸。<br/>默认值：ChipSize：ChipSize.NORMAL，<br/>   SizeOptions类型参数不支持百分比设置。|
| enabled         | boolean                                 | 否   | 操作块是否可选中。<br>默认值：true。                         |
| prefixIcon      | [PrefixIconOptions](#prefixiconoptions) | 否   | 前缀图标属性。                                               |
| label           | [LabelOptions](#labeloptions)           | 是   | 文本属性。                                                   |
| suffixIcon      | [SuffixIconOptions](#suffixiconoptions) | 否   | 后缀图标属性。                                               |
| backgroundColor | ResourceColor                           | 否   | 操作块背景颜色。<br/>默认值：$r('sys.float.ohos_id_color_button_normal')。 |
| borderRadius    | Dimension                               | 否   | 操作块背景圆角半径大小，不支持百分比。<br/>默认值：$r('sys.float.ohos_id_corner_radius_button')。 |
| allowClose      | boolean                                 | 否   | 删除图标是否显示。<br/>默认值：true。                        |
| onClose         | ()=>void                                | 否   | 默认删除图标点击事件。                                       |

> **说明：**
>
> suffixIcon有传入参数时，allowClose不生效，suffixIcon没有传入参数时，allowClose决定是否显示删除图标。
>
> backgroundColor赋值undefined时，显示默认背景颜色，赋值非法值时，背景色透明。

## ChipSize

ChipSize是chip可指定的尺寸类型，如普通型Chip。

| 名称   | 描述               |
| ------ | ------------------ |
| NORMAL | normal尺寸操作块。 |
| SMALL  | small尺寸操作块。  |

## IconCommonOptions

IconCommonOptions定义图标的共通属性。

| 名称      | 类型          | 必填 | 说明                                                         |
| --------- | ------------- | ---- | ------------------------------------------------------------ |
| src       | ResourceStr   | 是   | 图标图片或图片地址引用。                                     |
| size      | SizeOptions   | 否   | 图标大小，不支持百分比。<br/>默认值: {width: 16,height: 16}。 |
| fillColor | ResourceColor | 否   | 图标填充颜色。                                               |

> **说明：**
>
> 仅在图片格式为svg时，fillColor生效。

## PrefixIconOptions

PrefixIconOptions定义前缀图标的属性。

继承于[IconCommonOptions](#iconcommonoptions)

## SuffixIconOptions

SuffixIconOptions定义后缀图标的属性。

继承于[IconCommonOptions](#iconcommonoptions)

| 名称   | 类型       | 必填 | 说明               |
| ------ | ---------- | ---- | ------------------ |
| action | () => void | 否   | 后缀图标设定事件。 |

## LabelOptions

LabelOptions定义文本的属性。

| 名称        | 类型                                      | 必填 | 说明                                                         |
| ----------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| text        | string                                    | 是   | 文本文字内容。                                               |
| fontSize    | Dimension                                 | 否   | 文字字号，不支持百分比。<br/>默认值：$r('sys.float.ohos_id_text_size_button3')。 |
| fontColor   | ResourceColor                             | 否   | 文字颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary')。 |
| fontFamily  | string                                    | 否   | 文字字体。<br/>默认值："HarmonyOS Sans"。                    |
| labelMargin | [LabelMarginOptions](#labelmarginoptions) | 否   | 文本与左右侧图标之间间距。                                   |

## LabelMarginOptions

LabelMarginOptions定义文本与左右侧图标之间间距。

| 名称  | 类型      | 必填 | 说明                                                     |
| ----- | --------- | ---- | -------------------------------------------------------- |
| left  | Dimension | 否   | 文本与左侧图标之间间距，不支持百分比。<br/>默认值：6vp。 |
| right | Dimension | 否   | 文本与右侧图标之间间距，不支持百分比。<br/>默认值：6vp。 |


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


![](figures/chip1.jpeg)

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


![](figures/chip2.jpeg)

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


![](figures/chip3.jpeg)
