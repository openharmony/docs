# Span

作为[Text](ts-basic-components-text.md)、[ContainerSpan](ts-basic-components-containerspan.md)组件的子组件，用于显示行内文本的组件。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  该组件从API Version 10开始支持继承父组件Text的属性，即如果子组件未设置属性且父组件设置属性，则继承父组件设置的属性。支持继承的属性仅包括：fontColor、fontSize、fontStyle、fontWeight、decoration、letterSpacing、textCase、fontfamily、textShadow。


## 子组件

无


## 接口

Span(value: string | Resource)

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | string \| [Resource](ts-types.md#resource) | 是 | 文本内容。 |


## 属性

通用属性方法仅支持[文本通用](ts-universal-attributes-text-style.md)。

### decoration

decoration(value: DecorationStyleInterface)

设置文本装饰线样式及其颜色。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 描述                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [DecorationStyleInterface<sup>12+</sup>](ts-universal-styled-string.md#decorationstyleinterface对象说明) | 是   | 文本装饰线样式对象。<br/>默认值：<br/>{&nbsp;type:&nbsp;TextDecorationType.None,&nbsp;color:&nbsp;Color.Black,&nbsp;style:&nbsp;TextDecorationStyle.SOLID&nbsp;} |

### letterSpacing

letterSpacing(value: number | string)

设置文本字符间距。取值小于0，字符聚集重叠，取值大于0且随着数值变大，字符间距越来越大，稀疏分布。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                       | 必填 | 描述           |
| ------ | -------------------------- | ---- | -------------- |
| value  | number&nbsp;\|&nbsp;string | 是   | 文本字符间距。 |

### textCase

textCase(value: TextCase)

设置文本大小写。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 描述                                     |
| ------ | ----------------------------------------- | ---- | ---------------------------------------- |
| value  | [TextCase](ts-appendix-enums.md#textcase) | 是   | 文本大小写。<br/>默认值：TextCase.Normal |

### lineHeight<sup>10+</sup>

lineHeight(value: Length)

设置文本行高。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 描述           |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| value  | [Length](ts-types.md#length) | 是   | 文本行高。 |

### font<sup>10+</sup>

font(value: Font)

设置文本样式。包括字体大小、字体粗细、字体族和字体风格。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                     | 必填 | 描述       |
| ------ | ------------------------ | ---- | ---------- |
| value  | [Font](ts-types.md#font) | 是   | 文本样式。 |

### textShadow<sup>11+</sup>

textShadow(value: ShadowOptions | Array&lt;ShadowOptions&gt;)

设置文字阴影效果。该接口支持以数组形式入参，实现多重文字阴影。不支持fill字段, 不支持智能取色模式。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 描述           |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| value  | [ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions对象说明)&nbsp;\|&nbsp;&nbsp;Array&lt;[ShadowOptions](ts-universal-attributes-image-effect.md#shadowoptions对象说明)> | 是   | 文字阴影效果。 |

### textBackgroundStyle<sup>11+</sup>

textBackgroundStyle(style: TextBackgroundStyle)

设置背景样式。作为[ContainerSpan](ts-basic-components-containerspan.md)的子组件时可以继承它的此属性值，优先使用其自身的此属性。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 描述                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [TextBackgroundStyle](ts-basic-components-containerspan.md#textbackgroundstyle对象说明) | 是   | 背景样式。<br />默认值:<br />{<br />  color: Color.Transparent,<br />  radius: 0<br />} |

### baselineOffset<sup>12+</sup>

baselineOffset(value: LengthMetrics)

设置Span基线的偏移量。此属性与父组件的baselineOffset是共存的。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 描述                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 是   | 设置Span基线的偏移量，设置该值为百分比时，按默认值显示。<br/>正数内容向上偏移，负数向下偏移。<br/>默认值：0 |

## 事件

通用事件仅支持[点击事件](ts-universal-events-click.md)。

>  **说明：**
>
>  由于Span组件无尺寸信息，因此点击事件返回的ClickEvent对象的target属性无效。


## 示例
### 示例1

decoration、letterSpacing、textCase属性接口使用示例

```ts
// xxx.ets
@Entry
@Component
struct SpanExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Basic Usage').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('In Line')
        Span(' Component')
        Span(' !')
      }

      Text() {
        Span('This is the Span component').fontSize(12).textCase(TextCase.Normal)
          .decoration({ type: TextDecorationType.None, color: Color.Red })
      }

      // 文本横线添加
      Text('Text Decoration').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Underline-WAVY-span').decoration({ type: TextDecorationType.Underline, color: Color.Red, style: TextDecorationStyle.WAVY }).fontSize(12)
      }

      Text() {
        Span('I am LineThrough-DOTTED-span')
          .decoration({ type: TextDecorationType.LineThrough, color: Color.Red, style: TextDecorationStyle.DOTTED })
          .fontSize(12)
      }

      Text() {
        Span('I am Overline-DASHED-span').decoration({ type: TextDecorationType.Overline, color: Color.Red, style: TextDecorationStyle.DASHED }).fontSize(12)
      }

      // 文本字符间距
      Text('LetterSpacing').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('span letter spacing')
          .letterSpacing(0)
          .fontSize(12)
      }

      Text() {
        Span('span letter spacing')
          .letterSpacing(-2)
          .fontSize(12)
      }

      Text() {
        Span('span letter spacing')
          .letterSpacing(3)
          .fontSize(12)
      }


      // 文本大小写展示设置
      Text('Text Case').fontSize(9).fontColor(0xCCCCCC)
      Text() {
        Span('I am Lower-span').fontSize(12)
          .textCase(TextCase.LowerCase)
          .decoration({ type: TextDecorationType.None })
      }

      Text() {
        Span('I am Upper-span').fontSize(12)
          .textCase(TextCase.UpperCase)
          .decoration({ type: TextDecorationType.None })
      }
    }.width('100%').height(250).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![Span](figures/span.png)

### 示例2
``` ts
@Entry
@Component
struct TextSpanExample {
  @State textShadows : ShadowOptions | Array<ShadowOptions> = [{ radius: 10, color: Color.Red, offsetX: 10, offsetY: 0 },{ radius: 10, color: Color.Black, offsetX: 20, offsetY: 0 },
      { radius: 10, color: Color.Brown, offsetX: 30, offsetY: 0 },{ radius: 10, color: Color.Green, offsetX: 40, offsetY: 0 },
      { radius: 10, color: Color.Yellow, offsetX: 100, offsetY: 0 }]
  build() {
    Column({ space: 8 }) {
      Text() {
        Span('123456789').fontSize(50).textShadow(this.textShadows)
      }
      Text() {
        Span('123456789') // span can inherit text shadow & font size from outer text
      }.fontSize(50).textShadow(this.textShadows)
    }
  }
}
```
![TextshadowExample](figures/text_span_textshadow.png)

### 示例3
``` ts
// xxx.ets
@Component
@Entry
struct Index {
  build() {
    Column() {
      Text() {
        Span('   Hello World !   ')
          .fontSize('20fp')
          .textBackgroundStyle({color: "#7F007DFF", radius: "5vp"})
          .fontColor(Color.White)
      }
    }.width('100%').margin({bottom: '5vp'}).alignItems(HorizontalAlign.Center)
  }
}
```
![TextBackgroundStyleExample](figures/span_textbackgroundstyle.png)

### 示例4

该示例实现了如何设置Span基线的偏移量。

```ts
import { LengthUnit,LengthMetrics } from '@ohos.arkui.node';

@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        Text(){
          Span('word1')
            .baselineOffset(new LengthMetrics(20,LengthUnit.VP))
          Span('word2')
            .baselineOffset(new LengthMetrics(0,LengthUnit.VP))
          ImageSpan($r("app.media.icon"))
            .width('45px')
            .baselineOffset(new LengthMetrics(-20,LengthUnit.VP))
        }
        .backgroundColor(Color.Gray)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![SpanBaselineOffset](figures/SpanBaselineOffset.png)

