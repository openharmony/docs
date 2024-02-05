# @ohos.measure (文本计算)

本模块提供文本宽度、高度等相关计算。

> **说明**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import measure from '@ohos.measure'
```

## measure.measureText

measureText(options: MeasureOptions): number

计算指定文本单行布局下的宽度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](#measureoptions) | 是    | 被计算文本描述信息。 |

**返回值：**

| 类型          | 说明       |
| ------------  | --------- |
| number        | 文本宽度。<br/>**说明:** 单位px。 |


**示例：**

```ts
import measure from '@ohos.measure'

@Entry
@Component
struct Index {
  @State textWidth: number = measure.measureText({
    textContent: "Hello word",
    fontSize: '50px'
  })

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

## measure.measureTextSize<sup>10+</sup>

measureTextSize(options: MeasureOptions): SizeOptions

计算指定文本单行布局下的宽度和高度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                              | 必填   | 说明        |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](#measureoptions) | 是    | 被计算文本描述信息。 |

**返回值：**

| 类型          | 说明       |
| ------------  | --------- |
| [SizeOption](../arkui-ts/ts-types.md#sizeoptions)   | 返回文本所占布局宽度和高度。<br/>**说明:** 文本宽度以及高度返回值单位均为px。 |


**示例：**

```ts
import measure from '@ohos.measure'
@Entry
@Component
struct Index {
  textSize : SizeOptions = measure.measureTextSize({
    textContent: "Hello word",
    fontSize: '50px'
  })
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

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型                                                                                                | 必填 | 说明                      |
| -------------- | -------------------------------------------------------------------------------------------------- | ---- | ----------------------------------------------- |
| textContent | string&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)                                                                                             | 是   | 设置被计算文本内容。                                  |
| constraintWidth<sup>10+</sup> | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)   | 否   | 设置被计算文本布局宽度。<br/>**说明：** 默认单位为vp，不支持设置百分比字符串。若不设置，则文本SizeOption宽度为单行布局所占最大宽度值，若设置则为设置值。                             |
| fontSize       | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)               | 否   | 设置被计算文本字体大小，fontSize为number类型时，使用fp单位。<br/>默认值：16fp。<br/>**说明：** 不支持设置百分比字符串。    |
| fontStyle      | number&nbsp;\|&nbsp;[FontStyle](../arkui-ts/ts-appendix-enums.md#fontstyle)                        | 否   | 设置被计算文本字体样式。<br>默认值：FontStyle.Normal            |
| fontWeight     | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[FontWeight](../arkui-ts/ts-appendix-enums.md#fontweight)  | 否   | 设置被计算文本的字体粗细，number类型取值[100,&nbsp;900]，取值间隔为100，默认为400，取值越大，字体越粗。string类型仅支持number类型取值的字符串形式，例如"400"，以及"bold"、"bolder"、"lighter"、"regular"、"medium"，分别对应FontWeight中相应的枚举值。<br/>默认值：FontWeight.Normal|
| fontFamily     | string&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)                                   | 否   | 设置被计算文本字体列表。默认字体'HarmonyOS Sans'，且当前只支持这种字体。|
| letterSpacing  | number&nbsp;\|&nbsp;string                                                                         | 否   | 设置被计算文本字符间距。|
| textAlign<sup>10+</sup>  | number&nbsp;\|&nbsp;[TextAlign](../arkui-ts/ts-appendix-enums.md#textalign)              | 否   | 设置被计算文本水平方向的对齐方式。<br/>默认值：TextAlign.Start|
| overflow<sup>10+</sup>  | number&nbsp;\|&nbsp;[TextOverflow](../arkui-ts/ts-appendix-enums.md#textoverflow)         | 否   | 设置被计算文本超长时的截断方式。|
| maxLines<sup>10+</sup>  | number                                                                                    | 否   | 设置被计算文本最大行数。|
| lineHeight<sup>10+</sup>  | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)    | 否   | 设置被计算文本行高。|
| baselineOffset<sup>10+</sup>  | number&nbsp;\|&nbsp;string                                                          | 否   | 设置被计算文本基线的偏移量。<br />默认值：0 |
| textCase<sup>10+</sup>  | number&nbsp;\|&nbsp;[TextCase](../arkui-ts/ts-appendix-enums.md#textcase)                 | 否   | 设置被计算文本大小写。<br />默认值：TextCase.Normal |
| textIndent<sup>11+</sup> | number&nbsp;\|&nbsp;string  | 否  | 设置首行文本缩进，默认值0。 |
| wordBreak<sup>11+</sup> | [WordBreak](../arkui-ts/ts-appendix-enums.md#wordbreak11) | 否   | 设置断行规则。 <br />默认值：WordBreak.BREAK_WORD <br/>**说明：** <br/>从API version 11开始，该接口支持在ArkTS卡片中使用。<br/>WordBreak.BREAK_ALL与{overflow:&nbsp;TextOverflow.Ellipsis}，`maxLines`组合使用可实现英文单词按字母截断，超出部分以省略号显示|