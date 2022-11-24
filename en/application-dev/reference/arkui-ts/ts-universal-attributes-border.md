# Border

The border attributes are used to set border styles for components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes

| Name        | Type                                                    | Description                                                        |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| border       | {<br>width?: [Length](ts-types.md#length),<br>color?:  [ResourceColor](ts-types.md#resourcecolor),<br>radius?:  [Length](ts-types.md#length),<br>style?: [BorderStyle](ts-appendix-enums.md#borderstyle)<br>} | Unified border style. |
| borderStyle  | [BorderStyle](ts-appendix-enums.md#borderstyle) | Border style of an element.<br>Default value: **BorderStyle.Solid**          |
| borderWidth  | [Length](ts-types.md#length)     | Border width.                                        |
| borderColor  | [ResourceColor](ts-types.md#resourcecolor) | Border color of an element.                                        |
| borderRadius | [Length](ts-types.md#length) | Border radius.                                    |

## Example

```ts
// xxx.ets
@Entry
@Component
struct BorderExample {
  
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
      // Dashed border
      Text('dashed')
        .borderStyle(BorderStyle.Dashed).borderWidth(5).borderColor(0xAFEEEE).borderRadius(10)
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
      // Dotted border
      Text('dotted')
        .border({ width: 5, color: 0x317AF7, radius: 10, style: BorderStyle.Dotted })
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
    }.width('100%').height(150)
  }
}
```

![en-us_image_0000001211898466](figures/en-us_image_0000001211898466.gif)
