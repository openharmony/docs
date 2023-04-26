# Polygon

The **\<Polygon>** component is used to draw a polygon.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Polygon(value?: {width?: string | number, height?: string | number})

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type| Mandatory| Default Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| width | string \| number | No| 0 | Width.|
| height | string \| number | No| 0 | Height.|


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| points | Array&lt;Point&gt; | [] | Vertex coordinates of the polygon.<br>Since API version 9, this API is supported in ArkTS widgets.|
| fill | [ResourceColor](ts-types.md) | Color.Black | Color of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.|
| fillOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Opacity of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.|
| stroke | [ResourceColor](ts-types.md) | - | Stroke color. If this attribute is not set, the component does not have any stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeDashArray | Array&lt;Length&gt; | [] | Stroke dashes.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeDashOffset | number \| string | 0 | Offset of the start point for drawing the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | Cap style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | Join style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeMiterLimit | number \| string | 4 | Limit on the ratio of the miter length to the value of **strokeWidth** used to draw a miter join. The miter length indicates the distance from the outer tip to the inner corner of the miter.<br>**NOTE**<br>This attribute must be set to a value greater than or equal to 1 and takes effect when **strokeLineJoin** is set to **LineJoinStyle.Miter**.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Stroke opacity.<br>**NOTE**<br>The value range is [0.0, 1.0]. If the set value is less than 0.0, **0.0** will be used. If the set value is greater than 1.0, **1.0** will be used.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeWidth | Length | 1 | Stroke width.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>The value cannot be a percentage.|
| antiAlias | boolean | true | Whether anti-aliasing is enabled.<br>Since API version 9, this API is supported in ArkTS widgets.|

## Point

Describes the coordinates of a point.

Since API version 9, this API is supported in ArkTS widgets.

| Name     | Type            | Description                                                        |
| --------- | -------------------- | ------------------------------------------------------------ |
| Point | [number, number] | Coordinates of a point. The first parameter is the x-coordinate, and the second parameter is the y-coordinate (relative coordinate).|


## Example

```ts
// xxx.ets
@Entry
@Component
struct PolygonExample {
  build() {
    Column({ space: 10 }) {
      // Draw a triangle in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 0), and the passing point is (50, 100).
      Polygon({ width: 100, height: 100 })
        .points([[0, 0], [50, 100], [100, 0]])
        .fill(Color.Green)
      // Draw a quadrilateral in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 0), and the passing points are (0, 100) and (100, 100).
      Polygon().width(100).height(100)
        .points([[0, 0], [0, 100], [100, 100], [100, 0]])
        .fillOpacity(0)
        .strokeWidth(5)
        .stroke(Color.Blue)
      // Draw a pentagon in a 100 x 100 rectangle. The start point is (50, 0), the end point is (100, 50), and the passing points are (0, 50), (20, 100), and (80, 100).
      Polygon().width(100).height(100)
        .points([[50, 0], [0, 50], [20, 100], [80, 100], [100, 50]])
        .fill(Color.Red)
        .fillOpacity(0.6)
    }.width('100%').margin({ top: 10 })
  }
}
```

![en-us_image_0000001174582856](figures/en-us_image_0000001174582856.png)
