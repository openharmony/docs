# Rect

The **\<Rect>** component is used to draw a rectangle.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Rect(value?: {width?: string | number,height?: string | number,radius?: string | number | Array&lt;string | number&gt;} |
  {width?: string | number,height?: string | number,radiusWidth?: string | number,radiusHeight?: string | number})

**Parameters**

| Name| Type| Mandatory| Default Value| Description|
| -------- | -------- | -------- | -------- | -------- |
| width | string \| number | No| 0 | Width.|
| height | string \| number | No| 0 | Height.|
| radius | string \| number \| Array&lt;string \| number&gt; | No| 0 | Radius of the rounded corner. You can set separate radiuses for four rounded corners.|
| radiusWidth | string \| number | No| 0 | Width of the rounded corner.|
| radiusHeight | string \| number | No| 0 | Height of the rounded corner.|


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| radiusWidth | string \| number | 0 | No| Width of the rounded corner. The width and height are the same when only the width is set.|
| radiusHeight | string \| number | 0 | No| Height of the rounded corner. The width and height are the same only when the height is set.|
| radius | string \| number \| Array&lt;string \| number&gt; | 0 | No| Radius of the rounded corner. You can set separate radiuses for four rounded corners.|
| fill | [ResourceColor](ts-types.md#resourcecolor) | Color.Black | No| Color of the fill area.|
| fillOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | No| Opacity of the fill area.|
| stroke | [ResourceColor](ts-types.md#resourcecolor) | Color.Black | No| Stroke color.|
| strokeDashArray | Array&lt;Length&gt; | [] | No| Stroke dash.|
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
struct RectExample {
  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Draw a 90% x 50 rectangle.
      Rect({ width: '90%', height: 50 })
      // Draw a 90% x 50 rectangle.
      Rect().width('90%').height(50)

      Text('with rounded corners').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Draw a 90% x 50 rectangle with the width and height of the rounded corner being 20.
      Rect({ width: '90%', height: 50 }).radiusHeight(20).radiusWidth(20)
      // Draw a 90% x 50 rectangle with the width and height of the rounded corner being 20.
      Rect({ width: '90%', height: 50 }).radius(20)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218454](figures/en-us_image_0000001212218454.png)
