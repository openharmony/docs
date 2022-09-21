# Ellipse


The **\<Ellipse>** component is used to draw an ellipse.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

Not supported


## APIs

ellipse(options?: {width?: string | number, height?: string | number})

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | width | string \| number | No| 0 | Width of the ellipse. |
  | height | string \| number | No| 0 | Height of the ellipse. |


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| fill | [ResourceColor](../../ui/ts-types.md) | Color.Black | No| Color of the fill area.|
| fillOpacity | number \| string \| [Resource](../../ui/ts-types.md#resource)| 1 | No| Opacity of the fill area.|
| stroke | [ResourceColor](../../ui/ts-types.md) | Color.Black | No|Stroke color.|
| strokeDashArray | Array&lt;Length&gt; | [] | No| Stroke dash.|
| strokeDashOffset | number \| string | 0 | No| Offset of the start point for drawing the stroke.|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | No| Cap style of the stroke.|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | No| Join style of the stroke.|
| strokeMiterLimit | number \| string | 4 | No| Limit value when the sharp angle is drawn as a miter.|
| strokeOpacity | number \| string \| [Resource](../../ui/ts-types.md#resource)| 1 | No| Stroke opacity.|
| strokeWidth | Length | 1 | No| Stroke width.|
| antiAlias | boolean | true | No| Whether anti-aliasing is enabled.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct EllipseExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // Draw an ellipse in a 150 x 70 rectangle.
      Ellipse({ width: 150, height: 80 })
      // Draw an ellipse in a 150 x 70 rectangle.
      Ellipse().width(150).height(80)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212058488](figures/en-us_image_0000001212058488.png)
