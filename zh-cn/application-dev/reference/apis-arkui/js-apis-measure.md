# @ohos.measure (文本计算)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供文本宽度、高度等相关计算，支持多种文本属性配置（如字体大小、样式、粗细、行高等），适用于需要在组件构建前获知文本尺寸的场景，例如自适应布局、文本裁剪、动态调整UI尺寸等，帮助开发者实现更精准的布局计算和性能优化。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - 该模块不支持在[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)的文件声明处使用，即不能在UIAbility的生命周期中调用，需要在创建组件实例后使用。
>
> - 如需更多测算文本参数，建议使用图形对应测算接口[Paragraph](../apis-arkgraphics2d/js-apis-graphics-text.md#paragraph)接口。
>
> - 调用文本计算接口时，不建议同时使用[ApplicationContext.setFontSizeScale](../apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetfontsizescale13)设置应用字体大小缩放比例。为了确保时序的一致性，建议开发者自行监听字体缩放变化，以保证测算结果的准确性。
>
> - 在测算裁剪后的文本时，由于某些Unicode字符（如emoji）的码位长度大于1，直接按字符串长度裁剪会导致不准确的结果。建议基于Unicode码点进行迭代处理，避免错误截断字符，确保测算结果准确。

## 导入模块

```ts
import { MeasureText } from '@kit.ArkUI';
```

## MeasureText.measureText<sup>(deprecated)</sup>

static measureText(options: MeasureOptions): number

计算指定文本作为单行文本显示时的宽度。如果文本包含多行（由换行符`\n`分隔），则返回其中最长的行的宽度。

> **说明：**
>
> - 从API version 9开始支持，从API version 18开始废弃，建议使用[measureText](arkts-apis-uicontext-measureutils.md#measuretext12)替代。measureText需要先通过[UIContext](arkts-apis-uicontext-uicontext.md)中的[getMeasureUtils](arkts-apis-uicontext-uicontext.md#getmeasureutils12)方法获取[MeasureUtils](arkts-apis-uicontext-measureutils.md)对象，然后通过该对象进行调用。且直接使用measureText可能导致[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)的问题。
>
> - 从API version 12开始，可以通过使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getMeasureUtils](arkts-apis-uicontext-uicontext.md#getmeasureutils12)方法获取当前UI上下文关联的[MeasureUtils](arkts-apis-uicontext-measureutils.md)对象。
>
> - measureText接口的计算结果始终是单行文本的宽度，入参options中配置的布局约束（如constraintWidth、maxLines）对measureText的结果没有影响。如果需要计算布局约束下的宽度，请使用[measureTextSize](arkts-apis-uicontext-measureutils.md#measuretextsize12)方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](#measureoptions) | 是    | 被计算文本描述信息。 |

**返回值：**

| 类型          | 说明       |
| ------------  | --------- |
| number        | 文本宽度。<br/>单位：px |

> **说明：**
>
> 直接使用MeasureText可能导致[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)的问题，推荐通过[UIContext](arkts-apis-uicontext-uicontext.md)中的[getMeasureUtils](./arkts-apis-uicontext-uicontext.md#getmeasureutils12)方法获取当前UI上下文关联的[MeasureUtils](arkts-apis-uicontext-measureutils.md)实例。

**示例：**

```ts
import { MeasureText } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State textWidth: number = MeasureText.measureText({
    // 建议使用 this.getUIContext().getMeasureUtils().measureText()接口
    textContent: "Hello World",
    fontSize: '50px'
  });

  build() {
    Row() {
      Column() {
        Text(`The width of 'Hello World': ${this.textWidth}`)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## MeasureText.measureTextSize<sup>(deprecated)</sup>

static measureTextSize(options: MeasureOptions): SizeOptions

计算指定文本的宽度和高度。

> **说明：**
>
> - 从API version 10开始支持，从API version 18开始废弃，建议使用[measureTextSize](arkts-apis-uicontext-measureutils.md#measuretextsize12)替代。measureTextSize需要先通过[UIContext](arkts-apis-uicontext-uicontext.md)中的[getMeasureUtils](arkts-apis-uicontext-uicontext.md#getmeasureutils12)方法获取[MeasureUtils](arkts-apis-uicontext-measureutils.md)对象，然后通过该对象进行调用。且直接使用measureTextSize可能导致[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)的问题。
>
> - 从API version 12开始，可以通过使用[UIContext](arkts-apis-uicontext-uicontext.md)中的[getMeasureUtils](arkts-apis-uicontext-uicontext.md#getmeasureutils12)方法获取当前UI上下文关联的[MeasureUtils](arkts-apis-uicontext-measureutils.md)对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](#measureoptions) | 是    | 被计算文本描述信息。 |

**返回值：**

| 类型          | 说明       |
| ------------  | --------- |
| [SizeOptions](arkui-ts/ts-types.md#sizeoptions)  | 返回文本所占布局宽度和高度。<br/>**说明：**  <br/>文本宽度以及高度返回值单位均为px。 |

> **说明：**
>
> 直接使用MeasureText可能导致[UI上下文不明确](../../ui/arkts-global-interface.md#ui上下文不明确)的问题，推荐通过[UIContext](arkts-apis-uicontext-uicontext.md)中的[getMeasureUtils](./arkts-apis-uicontext-uicontext.md#getmeasureutils12)方法获取当前UI上下文关联的[MeasureUtils](arkts-apis-uicontext-measureutils.md)实例。

**示例：**

```ts
import { MeasureText } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  textSize: SizeOptions = MeasureText.measureTextSize({
    // 建议使用 this.getUIContext().getMeasureUtils().measureTextSize()接口
    textContent: "Hello World",
    fontSize: '50px'
  });

  build() {
    Row() {
      Column() {
        Text(`The width of 'Hello World': ${this.textSize.width}`)
        Text(`The height of 'Hello World': ${this.textSize.height}`)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## MeasureOptions

被计算文本属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型             | 只读 | 可选 | 说明                      |
| -------------- | ------------------------- | ---- | ---- | ----------------------------- |
| textContent | string&nbsp;\|&nbsp;[Resource](arkui-ts/ts-types.md#resource)                                                                                             | 否   | 否 | 设置被计算文本内容。                                  |
| constraintWidth<sup>10+</sup> | number \| string \| [Resource](arkui-ts/ts-types.md#resource)   | 否 | 是  | 设置被计算文本布局宽度。取值范围：[0, +∞)。<br>**说明：** <br>默认单位为vp，不支持设置百分比字符串。若不设置，则文本宽度为单行布局的最大宽度。若设置则为设置值，同时会影响文本的换行方式和高度计算结果。<br>**模型约束：** 此接口仅可在Stage模型下使用。                             |
| fontSize       | number \| string \| [Resource](arkui-ts/ts-types.md#resource)               | 否 | 是   | 设置被计算文本字体大小。取值范围：[0, +∞)，超出取值范围会导致计算结果异常。<br>默认值：16<br>**说明：** <br>不支持设置百分比字符串。<br>fontSize为number类型时，从API version 12开始，使用fp单位，在API version 12之前使用vp单位。    |
| fontStyle      | number&nbsp;\|&nbsp;[FontStyle](arkui-ts/ts-appendix-enums.md#fontstyle)                        | 否 | 是   | 设置被计算文本字体样式。<br>默认值：FontStyle.Normal<br>number类型取值范围为[0,1]，取值间隔为1，依次对应FontStyle中的枚举值。超出范围时使用默认值FontStyle.Normal。            |
| fontWeight     | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[FontWeight](arkui-ts/ts-appendix-enums.md#fontweight)  | 否 | 是   | 设置被计算文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。超出范围或不在间隔值上时使用默认值400。string类型仅支持number类型取值的字符串形式，例如"400"，以及"bold"、"bolder"、"lighter"、"regular"、"medium"，分别对应FontWeight中相应的枚举值。<br>默认值：FontWeight.Normal|
| fontFamily     | string&nbsp;\|&nbsp;[Resource](arkui-ts/ts-types.md#resource)                                   | 否 | 是   | 设置被计算文本字体列表。默认字体'HarmonyOS Sans'，且当前只支持这种字体。设置其他字体名称时使用默认字体'HarmonyOS Sans'。|
| letterSpacing  | number \| string   | 否 | 是   | 设置被计算文本字符间距。<br>默认值：0<br>**说明：** <br>默认单位为vp。string类型支持带单位的字符串，如'10px'、'10vp'。 |
| textAlign<sup>10+</sup>  | number&nbsp;\|&nbsp;[TextAlign](arkui-ts/ts-appendix-enums.md#textalign)              | 否 | 是   | 设置被计算文本水平方向的对齐方式。<br>默认值：TextAlign.Start<br>number类型取值范围为[0,3]，取值间隔为1，依次对应TextAlign中的枚举值。超出范围时使用默认值TextAlign.Start。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| overflow<sup>10+</sup>  | number \| [TextOverflow](arkui-ts/ts-appendix-enums.md#textoverflow)         | 否 | 是   | 设置被计算文本超长时的截断方式，需与maxLines配合使用才能生效。<br>默认值：1<br>number类型取值范围为[0,3]，取值间隔为1，依次对应TextOverflow中的枚举值。超出范围时使用默认值1。<br>**说明：** 当设置为TextOverflow.Ellipsis时，可配合wordBreak.BREAK_ALL和maxLines使用，实现英文单词按字母截断，超出部分以省略号显示。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| maxLines<sup>10+</sup>  | number              | 否 | 是   | 设置被计算文本最大行数，当文本实际行数超过此值时，measureTextSize的计算结果将基于最大行数进行测算，超出部分不计入高度计算。<br>取值范围：[0, INT32_MAX]，传入负数或超出范围时使用默认值。<br>默认值：不限制<br>**说明：** 可配合overflow: TextOverflow.Ellipsis和wordBreak.BREAK_ALL使用，实现英文单词按字母截断，超出部分以省略号显示。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| lineHeight<sup>10+</sup>  | number \| string \| [Resource](arkui-ts/ts-types.md#resource)    | 否 | 是   | 设置被计算文本行高，影响多行文本的高度计算结果和行间距，数值越大行间距越大。<br>取值范围：[0, +∞)。string类型支持带单位的字符串，如'10px'、'10vp'。<br>默认值：系统默认行高<br>默认单位为vp<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| baselineOffset<sup>10+</sup>  | number \| string                                                          | 否 | 是   | 设置被计算文本基线的偏移量。<br>默认值：0。单位：vp。string类型支持带单位的字符串，如'10px'、'10vp'。<br>**说明：** 正数表示基线向上偏移，负数表示基线向下偏移。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| textCase<sup>10+</sup>  | number&nbsp;\|&nbsp;[TextCase](arkui-ts/ts-appendix-enums.md#textcase)                 | 否 | 是   | 设置被计算文本大小写。<br>默认值：TextCase.Normal<br>number类型取值范围为[0,2]，取值间隔为1，依次对应TextCase中的枚举值。超出范围时使用默认值TextCase.Normal。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| textIndent<sup>11+</sup> | number \| string  | 否 | 是  | 设置首行文本缩进。取值范围：[0, +∞)，超出范围时使用默认值0。<br>默认值：0。<br>**说明：** <br>默认单位为vp。string类型支持带单位的字符串，如'10px'、'10vp'。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| wordBreak<sup>11+</sup> | [WordBreak](arkui-ts/ts-appendix-enums.md#wordbreak11) | 否 | 是   | 设置断行规则。 <br>默认值：WordBreak.BREAK_WORD <br>**说明：** <br>WordBreak.BREAK_ALL与overflow: TextOverflow.Ellipsis、maxLines组合使用可实现英文单词按字母截断，超出部分以省略号显示。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |