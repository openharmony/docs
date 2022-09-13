# Circle

 The **\<Circle>** component is used to draw a circle.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Circle(options?: {width?: string | number, height?: string | number})

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | width | string \| number | No| 0 | Width of the circle. |
  | height | string \| number | No| 0 | Height of the circle. |

| Name| Type| Mandatory| Default Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| width | string \| number | Yes| - | Width.|
| height | string \| number | Yes| - | Height.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| fill | [ResourceColor](../../ui/ts-types.md) | Color.Black | No| Color of the fill area.|
| fillOpacity | number \| string \| [Resource](../../ui/ts-types.md#resource-type)| 1 | No| Opacity of the fill area.|
| stroke | [ResourceColor](../../ui/ts-types.md) | Color.Black | No| Stroke color.|
| strokeDashArray | Array&lt;Length&gt; | [] | No| Stroke dashes.|
| strokeDashOffset | number \| string | 0 | No| Offset of the start point for drawing the stroke.|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | No| Cap style of the stroke.|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | No| Join style of the stroke.|
| strokeMiterLimit | number \| string | 4 | No| Limit value when the sharp angle is drawn as a miter.|
| strokeOpacity | number \| string \| [Resource](../../ui/ts-types.md#resource-type)| 1 | No| Stroke opacity.|
| strokeWidth | Length | 1 | No| Stroke width.|
| antiAlias | boolean | true | No| Whether anti-aliasing is enabled.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct CircleExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // Draw a circle whose diameter is 150.
      Circle({ width: 150, height: 150 })
      // Draw a circle whose diameter is 150.
      Circle().width(150).height(150)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001256978353](figures/en-us_image_0000001256978353.png)
