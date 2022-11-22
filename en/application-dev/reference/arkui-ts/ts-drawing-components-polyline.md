# Polyline

The **\<Polyline>** component is used to draw a polyline.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Polyline(value?: {width?: string | number, height?: string | number})

**Parameters**
| Name| Type| Mandatory| Default Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| width | string \| number | No| 0 | Width.|
| height | string \| number | No| 0 | Height.|


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| points | Array&lt;Point&gt; | [] | No| List of coordinates that the polyline passes through.|
| fill | [ResourceColor](ts-types.md#resourcecolor) | Color.Black | No| Color of the fill area.|
| fillOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | No| Opacity of the fill area.|
| stroke | [ResourceColor](ts-types.md#resourcecolor) | Color.Black | No| Stroke color.|
| strokeDashArray | Array&lt;Length&gt; | [] | No| Stroke dashes.|
| strokeDashOffset | number \| string | 0 | No| Offset of the start point for drawing the stroke.|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | No| Cap style of the stroke.|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | No| Join style of the stroke.|
| strokeMiterLimit | number \| string | 4 | No| Limit value when the sharp angle is drawn as a miter.|
| strokeOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | No| Stroke opacity.|
| strokeWidth | Length | 1 | No| Stroke width.|
| antiAlias | boolean | true | No| Whether anti-aliasing is enabled.|

## Point

Describes the coordinates of a point.

| Name     | Type            | Description                                                        |
| --------- | -------------------- | ------------------------------------------------------------ |
| Point | [number, number] | Coordinates of a point. The first parameter is the x-coordinate, and the second parameter is the y-coordinate (relative coordinate).|

## Example

```ts
// xxx.ets
@Entry
@Component
struct PolylineExample {
  build() {
    Column({ space: 5 }) {
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // Draw a polyline in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 100), and the passing point is (20,60).
        Polyline({ width: 100, height: 100 }).points([[0, 0], [20, 60], [100, 100]])
        // Draw a polyline in a 100 x 100 rectangle. The start point is (0, 0), the end point is (100, 100), and the passing point is (0,100).
        Polyline().width(100).height(100).points([[0, 0], [0, 100], [100, 100]])
      }.width('100%')
    }.margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218432](figures/en-us_image_0000001212218432.gif)
