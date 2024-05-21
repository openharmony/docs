# Universal Text Attributes

Universal text attributes include text style attributes applicable to text containers.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## fontColor

fontColor(value: ResourceColor)

Sets the font color.

**Widget capability**: Since API version 9, this API is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description      |
| ------ | ------------------------------------------ | ---- | ---------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | Yes  | Font color.|

## fontSize

fontSize(value: number | string | Resource)

Sets the font size.

**Widget capability**: Since API version 9, this API is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Resource](ts-types.md#resource) \| number \| string | Yes  | Font size. If **fontSize** is of the number type, the unit fp is used. The default font size is 16 fp. This attribute cannot be set in percentage.|

## fontStyle

fontStyle(value: FontStyle)

Sets the font style.

**Widget capability**: Since API version 9, this API is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                       | Mandatory| Description                                   |
| ------ | ------------------------------------------- | ---- | --------------------------------------- |
| value  | [FontStyle](ts-appendix-enums.md#fontstyle) | Yes  | Font style.<br>Default value: **FontStyle.Normal**|

## fontWeight

fontWeight(value: number | FontWeight | string)

Sets the font weight. If the value is too large, the text may be clipped depending on the font.

**Widget capability**: Since API version 9, this API is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | Yes  | Font weight. For the number type, the value range is [100, 900], at an interval of 100. The default value is **400**. A larger value indicates a heavier font weight. For the string type, only strings that represent a number, for example, **"400"**, and the following enumerated values of **FontWeight** are supported: **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**.<br>Default value: **FontWeight.Normal**|

## fontFamily

fontFamily(value: string | Resource)

Sets the font family.

**Widget capability**: Since API version 9, this API is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [Resource](ts-types.md#resource) \| string | Yes  | Font family. The 'HarmonyOS Sans' font and [registered custom fonts](../js-apis-font.md) are supported.|

## lineHeight

lineHeight(value: number | string | Resource)

Sets the text line height. If the value is less than or equal to **0**, the line height is not limited and the font size is adaptive.

**Widget capability**: Since API version 9, this API is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                              |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------- |
| value  | [Resource](ts-types.md#resource) \| number \| string | Yes  | Text line height. For number values, the unit is fp.|

## decoration

decoration(value: { type: TextDecorationType; color?: ResourceColor })

Sets the style and color for the text decorative line.

**Widget capability**: Since API version 9, this API is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | {<br>type: [TextDecorationType](ts-appendix-enums.md#textdecorationtype),<br>color?: [ResourceColor](ts-types.md#resourcecolor)<br>} | Yes  | Style and color of the text decorative line.<br>Default value: {<br>type: TextDecorationType.None,<br>color: Color.Black<br>} |


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
