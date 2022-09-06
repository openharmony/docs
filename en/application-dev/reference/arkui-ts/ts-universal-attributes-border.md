# Border

The border attribute is used to set border styles for components.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The border of a component is displayed above the content of its child components since API version 9.

## Required Permissions

None


## Attributes


| Name        | Type     | Default Value                 | Description                    |
| ------------ | ------------- | ----------------------- | ------------------------ |
| border       | BorderOptions | -                       | Unified border style.  |
| borderStyle  | [BorderStyle](ts-appendix-enums.md#borderstyle)   | BorderStyle.Solid | Border style of an element.|
| borderWidth  | Length        | 0                       | Border width of an element.    |
| borderColor  | [ResourceColor](../../ui/ts-types.md)         | -                       | Border color of an element.    |
| borderRadius | Length \| BorderRadiuses<sup>9+</sup>        | 0                       | Border radius of an element.|

- BorderOptions

  | Name| Type                                                    | Default Value           | Mandatory| Description  |
  | -------- | ------------------------------------------------------------ | ----------------- | ---- | ---------- |
  | width    | [Length](../../ui/ts-types.md#length) \| EdgeWidth<sup>9+</sup> | 0                 | No  | Border width.|
  | color    | [ResourceColor](../../ui/ts-types.md) \| EdgeColor<sup>9+</sup> | 'Black'           | No  | Border color.|
  | radius   | [Length](../../ui/ts-types.md#length) \| BorderRadiuses<sup>9+</sup> | 0                 | No  | Border radius.|
  | style    | [BorderStyle](ts-appendix-enums.md#borderstyle) \| EdgeStyle<sup>9+</sup>                          | BorderStyle.Solid | No  | Border style.|


- EdgeWidth<sup>9+</sup>

  To reference this object, at least one parameter must be passed.

  | Name   | Type   | Mandatory | Default Value | Description                 |
  | ------ | ------ | --------- | ------------- | --------------------------- |
  | left   | length | No        | 0             | Width of the left border.   |
  | right  | length | No        | 0             | Width of the right border.  |
  | top    | length | No        | 0             | Width of the top border.    |
  | bottom | length | No        | 0             | Width of the bottom border. |

- EdgeColor<sup>9+</sup>

  To reference this object, at least one parameter must be passed.

  | Name  | Type                             | Mandatory| Default Value | Description          |
  | ------ | ------------------------------------- | ---- | ------- | -------------- |
  | left   | [ResourceColor](../../ui/ts-types.md) | No  | 'Black' | Color of the left border.|
  | right  | [ResourceColor](../../ui/ts-types.md) | No  | 'Black' | Color of the right border.|
  | top    | [ResourceColor](../../ui/ts-types.md) | No  | 'Black' | Color of the top border.|
  | bottom | [ResourceColor](../../ui/ts-types.md) | No  | 'Black' | Color of the bottom border.|

- BorderRadiuses<sup>9+</sup>

  To reference this object, at least one parameter must be passed.

  | Name       | Type| Mandatory| Default Value| Description            |
  | ----------- | -------- | ---- | ------ | ---------------- |
  | topLeft     | length   | No  | 0      | Radius of the upper-left rounded corner.|
  | topRight    | length   | No  | 0      | Radius of the upper-right rounded corner.|
  | bottomLeft  | length   | No  | 0      | Radius of the lower-left rounded corner.|
  | bottomRight | length   | No  | 0      | Radius of the lower-right rounded corner.|

- EdgeStyle<sup>9+</sup>

  To reference this object, at least one parameter must be passed.

  | Name   | Type        | Mandatory | Default Value     | Description                 |
  | ------ | ----------- | --------- | ----------------- | --------------------------- |
  | left   | [BorderStyle](ts-appendix-enums.md#borderstyle) | No        | BorderStyle.Solid | Style of the left border.   |
  | right  | [BorderStyle](ts-appendix-enums.md#borderstyle) | No        | BorderStyle.Solid | Style of the right border.  |
  | top    | [BorderStyle](ts-appendix-enums.md#borderstyle) | No        | BorderStyle.Solid | Style of the top border.    |
  | bottom | [BorderStyle](ts-appendix-enums.md#borderstyle) | No        | BorderStyle.Solid | Style of the bottom border. |


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
