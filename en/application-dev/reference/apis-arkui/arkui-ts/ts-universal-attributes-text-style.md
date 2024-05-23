# Universal Text Attributes

Universal text attributes include text style attributes applicable to text containers.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.



## Attributes


| Name        | Type                                    | Description                                      |
| ---------- | ---------------------------------------- | ---------------------------------------- |
| fontColor  | [ResourceColor](ts-types.md#resourcecolor) | Font color.<br>This API can be used in ArkTS widgets since API version 9.|
| fontSize   | number \| string \| [Resource](ts-types.md#resource)             | Font size. If the value is of the number type, the unit fp is used. The default font size is 16. This attribute cannot be set in percentage.<br>This API can be used in ArkTS widgets since API version 9.|
| fontStyle  | [FontStyle](ts-appendix-enums.md#fontstyle) | Font style.<br>Default value: **FontStyle.Normal**<br>This API can be used in ArkTS widgets since API version 9.|
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string | Font weight. If the value is too large, the text may be clipped depending on the font. For the number type, the value range is [100, 900], at an interval of 100. The default value is **400**. A larger value indicates a heavier font weight. For the string type, only strings that represent a number, for example, **"400"**, and the following enumerated values of **FontWeight** are supported: **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**.<br>Default value: **FontWeight.Normal**<br>This API can be used in ArkTS widgets since API version 9.|
| fontFamily | string \| [Resource](ts-types.md#resource) | Font family. Default font: **'HarmonyOS Sans'**<br>The 'HarmonyOS Sans' font and [registered custom fonts](../js-apis-font.md) are supported for applications.<br>Only the 'HarmonyOS Sans' font is supported for widgets.<br>This API can be used in ArkTS widgets since API version 9.|
| lineHeight | string \| number \| [Resource](ts-types.md#resource) | Text line height. If the value is less than or equal to **0**, the line height is not limited and the font size is adaptive. If the value is of the number type, the unit fp is used.<br>This API can be used in ArkTS widgets since API version 9.|
| decoration | {<br>type: [TextDecorationType](ts-appendix-enums.md#textdecorationtype),<br>color?: [ResourceColor](ts-types.md#resourcecolor)<br>} | Style and color of the text decorative line.<br>Default value: {<br>type: TextDecorationType.None,<br>color: Color.Black<br>}<br>This API can be used in ArkTS widgets since API version 9.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct TextStyleExample {
  build() {
    Column({ space: 5 }) {
      Text('default text')
      
      Text('text font color red').fontColor(Color.Red)
      
      Text('text font default')
      Text('text font size 10').fontSize(10)
      Text('text font size 10fp').fontSize('10fp')
      Text('text font size 20').fontSize(20)
      
      Text('text font style Italic').fontStyle(FontStyle.Italic)
      
      Text('text fontWeight bold').fontWeight(700)
      Text('text fontWeight lighter').fontWeight(FontWeight.Lighter)
      
      Text('red 20 Italic bold text')
        .fontColor(Color.Red)
        .fontSize(20)
        .fontStyle(FontStyle.Italic)
        .fontWeight(FontWeight.Bold)
      
      Text('Orange 18 Normal text')
        .fontColor(Color.Orange)
        .fontSize(18)
        .fontStyle(FontStyle.Normal)
    }.width('100%')
  }
}
```

![textstyle](figures/textstyle.png)
