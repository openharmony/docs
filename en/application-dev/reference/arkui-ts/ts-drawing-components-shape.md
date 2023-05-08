# Shape

The **\<Shape>** component is the parent component of the drawing components. The attributes described in this topic are universal attributes supported by all the drawing components.


1. Drawing components use **\<Shape>** as their parent to implement the effect similar to SVG.

2. The **\<Shape>** component is used independently to draw a specific shape.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

The following child components are supported: **[\<Rect>](ts-drawing-components-rect.md)**, **[\<Path>](ts-drawing-components-path.md)**, **[\<Circle>](ts-drawing-components-circle.md)**, **[\<Ellipse>](ts-drawing-components-ellipse.md)**, **[\<Polyline>](ts-drawing-components-polyline.md)**, **[\<Polygon>](ts-drawing-components-polygon.md)**, **[\<Image>](ts-basic-components-image.md)**, **[\<Text>](ts-basic-components-text.md)**, **[\<Column>](ts-container-column.md)**, and **[\<Row>](ts-container-row.md)**.


## APIs

Shape(value?: PixelMap)

Since API version 9, this API is supported in ArkTS widgets, except that **PixelMap** objects are not supported.

**Parameters**

| Name| Type| Mandatory| Default Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| value | [PixelMap](../apis/js-apis-image.md#pixelmap7) | No| - | Shape to draw. You can draw a shape in the specified **PixelMap** object. If no object is specified, the shape is drawn in the current drawing target.|


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| viewPort | {<br>x?: number \| string,<br>y?: number \| string,<br>width?: number \| string,<br>height?: number \| string<br>} | { x:0, y:0, width:0, height:0 } | View port of the shape.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>If of the string type, the value cannot be a percentage.|
| fill | [ResourceColor](ts-types.md) | Color.Black | Color of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.|
| fillOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Opacity of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.|
| stroke | [ResourceColor](ts-types.md) | - | Stroke color. If this attribute is not set, the component does not have any stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeDashArray | Array&lt;Length&gt; | [] | Stroke dashes.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeDashOffset | number \| string | 0 | Offset of the start point for drawing the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | Cap style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | Join style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeMiterLimit | number \| string | 4 | Limit on the ratio of the miter length to the value of **strokeWidth** used to draw a miter join. The miter length indicates the distance from the outer tip to the inner corner of the miter.<br>**NOTE**<br>This attribute must be set to a value greater than or equal to 1 and takes effect when **strokeLineJoin** is set to **LineJoinStyle.Miter**.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Stroke opacity.<br>**NOTE**<br>The value range is [0.0, 1.0]. If the set value is less than 0.0, **0.0** will be used. If the set value is greater than 1.0, **1.0** will be used.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeWidth | number \| string | 1 | Stroke width.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>If of the string type, the value cannot be a percentage.|
| antiAlias | boolean | true | Whether anti-aliasing is enabled.<br>Since API version 9, this API is supported in ArkTS widgets.|
| mesh<sup>8+</sup> | Array&lt;number&gt;,number,number | [],0,0 | Mesh effect. The first parameter is an array of lengths (column + 1) * (row + 1) * 2, which records the position of each vertex of the distorted bitmap. The second parameter is the number of columns in the mesh matrix. The third parameter is the number of rows in the mesh matrix.<br>Since API version 9, this API is supported in ArkTS widgets.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct ShapeExample {
  build() {
    Column({ space: 10 }) {
      Text('basic').fontSize(11).fontColor(0xCCCCCC).width(320)
      // Draw a 300 x 50 rectangle with strokes at (-2, -2). The fill color is 0x317AF7, the stroke color is black, the stroke width is 4, the stroke dash is 20, the offset is 10 to the left, the cap style is rounded, the join style is rounded, and anti-aliasing is enabled (default).
      // Draw a 300 x 50 ellipse with strokes at (-2, 58). The fill color is 0x317AF7, the stroke color is black, the stroke width is 4, the stroke dash is 20, the offset is 10 to the left, the cap style is rounded, the join style is rounded, and anti-aliasing is enabled (default).
      // Draw a 300 x 10 straight line at (-2, 118). The fill color is 0x317AF7, the stroke color is black, the stroke width is 4, the stroke dash is 20, the offset is 10 to the left, the cap style is rounded, the join style is rounded, and anti-aliasing is enabled (default).
      Shape() {
        Rect().width(300).height(50)
        Ellipse().width(300).height(50).offset({ x: 0, y: 60 })
        Path().width(300).height(10).commands('M0 0 L900 0').offset({ x: 0, y: 120 })
      }
      .width(350)
      .height(140)
      .viewPort({ x: -2, y: -2, width: 304, height: 130 })
      .fill(0x317AF7)
      .stroke(Color.Black)
      .strokeWidth(4)
      .strokeDashArray([20])
      .strokeDashOffset(10)
      .strokeLineCap(LineCapStyle.Round)
      .strokeLineJoin(LineJoinStyle.Round)
      .antiAlias(true)
      // Draw a 300 x 50 rectangle with strokes at (0, 0) and (-5, -5). The drawing start point is the midpoint of the stroke width by default. To fully display the strokes, you must set the coordinates of the start position of the viewport to negative values so that the viewport is offset by half the stroke width.
      Shape() {
        Rect().width(300).height(50)
      }
      .width(350)
      .height(80)
      .viewPort({ x: 0, y: 0, width: 320, height: 70 })
      .fill(0x317AF7)
      .stroke(Color.Black)
      .strokeWidth(10)

      Shape() {
        Rect().width(300).height(50)
      }
      .width(350)
      .height(80)
      .viewPort({ x: -5, y: -5, width: 320, height: 70 })
      .fill(0x317AF7)
      .stroke(Color.Black)
      .strokeWidth(10)

      Text('path').fontSize(11).fontColor(0xCCCCCC).width(320)
      // Draw a straight line at (0, -5). The fill color is 0xEE8443, the stroke width is 10, and the stroke dash is 20.
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }
      .width(350)
      .height(20)
      .viewPort({ x: 0, y: -5, width: 300, height: 20 })
      .stroke(0xEE8443)
      .strokeWidth(10)
      .strokeDashArray([20])
      // Draw a straight line at (0, -5). The fill color is 0xEE8443, the stroke width is 10, the stroke dash is 20, and the offset is 10 to the left.
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }
      .width(350)
      .height(20)
      .viewPort({ x: 0, y: -5, width: 300, height: 20 })
      .stroke(0xEE8443)
      .strokeWidth(10)
      .strokeDashArray([20])
      .strokeDashOffset(10)
      // Draw a straight line at (0, -5). The fill color is 0xEE8443, the stroke width is 10, and the stroke opacity is 0.5.
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }
      .width(350)
      .height(20)
      .viewPort({ x: 0, y: -5, width: 300, height: 20 })
      .stroke(0xEE8443)
      .strokeWidth(10)
      .strokeOpacity(0.5)
      // Draw a straight line at (0, -5). The fill color is 0xEE8443, the stroke width is 10, the stroke dash is 20, and the cap style is rounded.
      Shape() {
        Path().width(300).height(10).commands('M0 0 L900 0')
      }
      .width(350)
      .height(20)
      .viewPort({ x: 0, y: -5, width: 300, height: 20 })
      .stroke(0xEE8443)
      .strokeWidth(10)
      .strokeDashArray([20])
      .strokeLineCap(LineCapStyle.Round)
      // Draw a closed path at (-80, -5). The fill color is 0x317AF7, the stroke width is 10, the stroke color is 0xEE8443, and the join style is miter (default value).
      Shape() {
        Path().width(200).height(60).commands('M0 0 L400 0 L400 150 Z')
      }
      .width(300)
      .height(200)
      .viewPort({ x: -20, y: -5, width: 310, height: 90 })
      .fill(0x317AF7)
      .stroke(0xEE8443)
      .strokeWidth(10)
      .strokeLineJoin(LineJoinStyle.Miter)
      .strokeMiterLimit(5)
    }.width('100%').margin({ top: 15 })
  }
}
```

![en-us_image_0000001184628104](figures/en-us_image_0000001184628104.png)
 
