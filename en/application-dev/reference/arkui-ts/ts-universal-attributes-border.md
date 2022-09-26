# Border

The border attributes are used to set border styles for components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The border of a component is displayed above the content of its child components since API version 9.


## Attributes


| Name        | Type                                                    | Description                                                        |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| border       | {<br>width?: [Length](../../ui/ts-types.md#length) \| EdgeWidth<sup>9+</sup>,<br>color?:  [ResourceColor](../../ui/ts-types.md) \| EdgeColor<sup>9+</sup>,<br>radius?:  [Length](../../ui/ts-types.md#length) \| BorderRadiuses<sup>9+</sup>,<br>style?: [BorderStyle](ts-appendix-enums.md#borderstyle) \| EdgeStyle<sup>9+</sup><br>} | Unified border style.<br>- **width**: border width.<br>- **color**: border color.<br>- **radius**: radius of the rounded corner of the border.<br>- **style**: border style.|
| borderStyle  | [BorderStyle](ts-appendix-enums.md#borderstyle) \| EdgeStyle<sup>9+</sup> | Border style of an element.<br>Default value: **BorderStyle.Solid**          |
| borderWidth  | [Length](../../ui/ts-types.md) \| EdgeWidth<sup>9+</sup>     | Border width of an element.                                        |
| borderColor  | [ResourceColor](../../ui/ts-types.md) \| EdgeColor<sup>9+</sup> | Border color of an element.                                        |
| borderRadius | [Length](../../ui/ts-types.md) \| BorderRadiuses<sup>9+</sup> | Border radius of an element.                                    |

## EdgeWidth<sup>9+</sup>

To reference this object, at least one parameter must be passed.

| Name  | Type                             | Mandatory| Description          |
| ------ | ------------------------------------- | ---- | -------------- |
| left   | [Length](../../ui/ts-types.md#length) | No  | Width of the left border.|
| right  | [Length](../../ui/ts-types.md#length) | No  | Width of the right border.|
| top    | [Length](../../ui/ts-types.md#length) | No  | Width of the top border.|
| bottom | [Length](../../ui/ts-types.md#length) | No  | Width of the bottom border.|

## EdgeColor<sup>9+</sup>

To reference this object, at least one parameter must be passed.

| Name  | Type                             | Mandatory| Description          |
| ------ | ------------------------------------- | ---- | -------------- |
| left   | [ResourceColor](../../ui/ts-types.md) | No  | Color of the left border.|
| right  | [ResourceColor](../../ui/ts-types.md) | No  | Color of the right border.|
| top    | [ResourceColor](../../ui/ts-types.md) | No  | Color of the top border.|
| bottom | [ResourceColor](../../ui/ts-types.md) | No  | Color of the bottom border.|

## BorderRadiuses<sup>9+</sup>

To reference this object, at least one parameter must be passed.

| Name       | Type                             | Mandatory| Description            |
| ----------- | ------------------------------------- | ---- | ---------------- |
| topLeft     | [Length](../../ui/ts-types.md#length) | No  | Radius of the upper-left rounded corner.|
| topRight    | [Length](../../ui/ts-types.md#length) | No  | Radius of the upper-right rounded corner.|
| bottomLeft  | [Length](../../ui/ts-types.md#length) | No  | Radius of the lower-left rounded corner.|
| bottomRight | [Length](../../ui/ts-types.md#length) | No  | Radius of the lower-right rounded corner.|

## EdgeStyle<sup>9+</sup>

To reference this object, at least one parameter must be passed.

| Name  | Type                                       | Mandatory| Description          |
| ------ | ----------------------------------------------- | ---- | -------------- |
| left   | [BorderStyle](ts-appendix-enums.md#borderstyle) | No  | Style of the left border.|
| right  | [BorderStyle](ts-appendix-enums.md#borderstyle) | No  | Style of the right border.|
| top    | [BorderStyle](ts-appendix-enums.md#borderstyle) | No  | Style of the top border.|
| bottom | [BorderStyle](ts-appendix-enums.md#borderstyle) | No  | Style of the bottom border.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct BorderExample {
  
  build() {
    Column() {
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
      Text('.border')
        .fontSize(50)
        .width(300)
        .height(300)
        .border({
          width: { left: '5lpx', right: '10lpx', top: '20lpx', bottom: '30lpx' },
          color: { left: '#e3bbbb', right: Color.Blue, top: Color.Red, bottom: Color.Green },
          radius: { topLeft: 10, topRight: 20, bottomLeft: 40, bottomRight: 80 },
          style: {
              left: BorderStyle.Dotted,
              right: BorderStyle.Dotted,
              top: BorderStyle.Solid,
              bottom: BorderStyle.Dashed
          }
      }).textAlign(TextAlign.Center)
    }
  }
}
```

![en-us_image_0000001211898466](figures/en-us_image_0000001211898466.gif)
