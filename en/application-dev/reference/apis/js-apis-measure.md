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

Provides attributes of the measured text.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name          | Type                                                                                               | Mandatory| Description                     |
| -------------- | -------------------------------------------------------------------------------------------------- | ---- | ----------------------------------------------- |
| textContent    | string                                                                                             | Yes  | Content of the measured text.                                 |
| fontSize       | number \| string \| [Resource](../arkui-ts/ts-types.md#resource)               | No  | Font size of the measured text. If the value is of the number type, the unit fp is used.<br>Default value: **16fp**<br>**NOTE**<br>The value cannot be a percentage.   |
| fontStyle      | number \| [FontStyle](../arkui-ts/ts-appendix-enums.md#fontstyle)                        | No  | Font style of the measured text.<br>Default value: **FontStyle.Normal**           |
| fontWeight     | number \| string \| [FontWeight](../arkui-ts/ts-appendix-enums.md#fontweight)  | No  | Font width of the measured text. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is **400**. A larger value indicates a heavier font weight. The string type supports only the string of the number type, for example, **400**, **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**, which correspond to the enumerated values in **FontWeight**.<br>Default value: **FontWeight.Normal**|
| fontFamily     | string \| [Resource](../arkui-ts/ts-types.md#resource)                                   | No  | Font family of the measured text. Default value: **'HarmonyOS Sans'**<br>Only the default font is supported.|
| letterSpacing  | number \| string                                                                         | No  | Letter spacing of the measured text.|
