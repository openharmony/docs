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
  @State message: string = 'Hello World'
  @State textWidth : number = measure.measureText({
    textContent: "Hello word",
    fontSize: '50px'
  })
  build() {
    Row() {
      Column() {
        Text("The width of 'Hello World': " + this.textWidth)
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
| textContent    | string                                                                                             | 是   | 设置被计算文本内容。                                  |
| fontSize       | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)               | 否   | 设置被计算文本字体大小，fontSize为number类型时，使用fp单位。<br/>默认值：16fp。<br/>**说明:**不支持设置百分比字符串。    |
| fontStyle      | number&nbsp;\|&nbsp;[FontStyle](../arkui-ts/ts-appendix-enums.md#fontstyle)                        | 否   | 设置被计算文本字体样式。<br>默认值：FontStyle.Normal            |
| fontWeight     | number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[FontWeight](../arkui-ts/ts-appendix-enums.md#fontweight)  | 否   | 设置被计算文本的字体粗细，number类型取值[100,&nbsp;900]，取值间隔为100，默认为400，取值越大，字体越粗。string类型仅支持number类型取值的字符串形式，例如"400"，以及"bold"、"bolder"、"lighter"、"regular"、"medium"，分别对应FontWeight中相应的枚举值。<br/>默认值：FontWeight.Normal|
| fontFamily     | string&nbsp;\|&nbsp;[Resource](../arkui-ts/ts-types.md#resource)                                   | 否   | 设置被计算文本字体列表。默认字体'HarmonyOS Sans'，且当前只支持这种字体。|
| letterSpacing  | number&nbsp;\|&nbsp;string                                                                         | 否   | 设置被计算文本字符间距。|

