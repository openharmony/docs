# @ohos.measure (Text Measurement)

The **measure** module provides APIs for measuring text metrics, such as text height and width.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import measure from '@ohos.measure'
```

## measure.measureText

measureText(options: MeasureOptions): number

Measures the width of the given single-line text.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](#measureoptions) | Yes   | Information about the measured text.|

**Return value**

| Type         | Description      |
| ------------  | --------- |
| number        | Text width.<br>The unit is px.|


**Example**

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

Measures the width and height of the given single-line text.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory  | Description       |
| ------- | ------------------------------- | ---- | --------- |
| options | [MeasureOptions](#measureoptions) | Yes   | Information about the measured text.|

**Return value**

| Type         | Description      |
| ------------  | --------- |
| [SizeOption](../arkui-ts/ts-types.md#sizeoptions)   | Layout width and height occupied by the text.<br>The unit is px.|


**Example**

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

Provides attributes of the measured text.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name          | Type                                                                                               | Mandatory| Description                     |
| -------------- | -------------------------------------------------------------------------------------------------- | ---- | ----------------------------------------------- |
| textContent | string                                                                                             | Yes  | Content of the measured text.                                 |
| constraintWidth<sup>10+</sup> | number \| string \| [Resource](../arkui-ts/ts-types.md#resource)   | No  | Layout width of the measured text.<br>**NOTE**<br>The default unit is vp. The value cannot be a percentage. If this parameter is not set, the value of **SizeOption** is the maximum width allowed for the single-line text.                            |
| fontSize       | number \| string \| [Resource](../arkui-ts/ts-types.md#resource)               | No  | Font size of the measured text. If the value is of the number type, the unit fp is used.<br>Default value: **16fp**<br>**NOTE**<br>The value cannot be a percentage.   |
| fontStyle      | number \| [FontStyle](../arkui-ts/ts-appendix-enums.md#fontstyle)                        | No  | Font style of the measured text.<br>Default value: **FontStyle.Normal**           |
| fontWeight     | number \| string \| [FontWeight](../arkui-ts/ts-appendix-enums.md#fontweight)  | No  | Font width of the measured text. For the number type, the value ranges from 100 to 900, at an interval of 100. A larger value indicates a heavier font weight. The default value is **400**. For the string type, only strings of the number type are supported, for example, **400**, **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**, which correspond to the enumerated values in **FontWeight**.<br>Default value: **FontWeight.Normal**|
| fontFamily     | string \| [Resource](../arkui-ts/ts-types.md#resource)                                   | No  | Font family of the measured text. Default value: **'HarmonyOS Sans'**<br>Only the default font is supported.|
| letterSpacing  | number \| string                                                                         | No  | Letter spacing of the measured text.|
| textAlign<sup>10+</sup>  | number \| [TextAlign](../arkui-ts/ts-appendix-enums.md#textalign)              | No  | Horizontal alignment mode of the measured text.<br>Default value: **TextAlign.Start**|
| overflow<sup>10+</sup>  | number \| [TextOverflow](../arkui-ts/ts-appendix-enums.md#textoverflow)         | No  | Display mode when the measured text is too long.|
| maxLines<sup>10+</sup>  | number                                                                                    | No  | Maximum number of lines in the measured text.|
| lineHeight<sup>10+</sup>  | number \| string \| [Resource](../arkui-ts/ts-types.md#resource)    | No  | Line height of the measured text.|
| baselineOffset<sup>10+</sup>  | number \| string                                                          | No  | Baseline offset of the measured text.<br>Default value: **0**|
| textCase<sup>10+</sup>  | number \| [TextCase](../arkui-ts/ts-appendix-enums.md#textcase)                 | No  | Case of the measured text.<br>Default value: **TextCase.Normal**|
| textIndent<sup>11+</sup> | number \| string  | No | Indentation of the first line.<br>Default value: **0**|
| wordBreak<sup>11+</sup> | [WordBreak](../arkui-ts/ts-appendix-enums.md#wordbreak11) | No  | Line break rule.<br>Default value: **WordBreak.BREAK_WORD**<br>**NOTE**<br>Since API version 11, this API is supported in ArkTS widgets.<br>When used with **{overflow: TextOverflow.Ellipsis}** and **maxLines**, **WordBreak.BREAK_ALL** can insert line breaks between letters when overflow occurs and display excess content with an ellipsis (...).|
