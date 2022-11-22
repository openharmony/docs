# Line


The **\<Line>** component is used to draw a straight line.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

Not supported


## APIs

Line(value?: {width?: string | number, height?: string | number})

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | width | string \| number | No| 0 | Width.|
  | height | string \| number | No| 0 | Height.|


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| startPoint | Array&lt;Length&gt; | [0, 0] | No  | Coordinates (relative coordinates) of the start point of the line, in vp.|
| endPoint   | Array&lt;Length&gt; | [0, 0] | No  | Coordinates (relative coordinates) of the end point of the line, in vp.|
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


## Example

```ts
// xxx.ets
@Entry
@Component
struct LineExample {
  build() {
    Column() {
      Line().startPoint([0, 0]).endPoint([50, 100])
      Line({ width: 50, height: 50 }).startPoint([0, 0]).endPoint([100, 100])
      Line().width(200).height(200).startPoint([50, 50]).endPoint([150, 150])
    }.margin({ top: 5 })
  }
}
```

![en-us_image_0000001256858387](figures/en-us_image_0000001256858387.jpg)
