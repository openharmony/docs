# Text Style

The text style attributes set the style for text in a component.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.



## Attributes


| Name        | Type                                     | Description                                   |
| -----------| ---------------------------------------- | ------------------------------------ |
| fontColor  | [ResourceColor](ts-types.md#resourcecolor)  | Font color.<br>Since API version 9, this API is supported in ArkTS widgets.|
| fontSize   | [Length](ts-types.md#length)  | Font size. If the value is of the number type, the unit fp is used. The default font size is 16. This attribute cannot be set in percentage.<br>Since API version 9, this API is supported in ArkTS widgets.|
| fontStyle  | [FontStyle](ts-appendix-enums.md#fontstyle)  | Font style.<br>Default value: **FontStyle.Normal**<br>Since API version 9, this API is supported in ArkTS widgets.|
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight) \| string  | Font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is **400**. A larger value indicates a larger font weight. The string type supports only the string of the number type, for example, **400**, **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**, which correspond to the enumerated values in **FontWeight**.<br>Default value: **FontWeight.Normal**<br>Since API version 9, this API is supported in ArkTS widgets.|
| fontFamily | string \| [Resource](ts-types.md#resource)  | Font family.<br> Default value: **'HarmonyOS Sans'**. Currently, only the default font is supported.<br>Since API version 9, this API is supported in ArkTS widgets.|
| lineHeight | string \| number \| [Resource](ts-types.md#resource) | Text line height. If the value is less than or equal to **0**, the line height is not limited and the font size is adaptive. If the value of the number type, the unit fp is used.<br>Since API version 9, this API is supported in ArkTS widgets.|
| decoration | {<br>type: [TextDecorationType](ts-appendix-enums.md#textdecorationtype),<br>color?: [ResourceColor](ts-types.md#resourcecolor)<br>} | Style and color of the text decorative line.<br>Default value: {<br>type: TextDecorationType.None,<br>color: Color.Black<br>}<br>Since API version 9, this API is supported in ArkTS widgets.|


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
