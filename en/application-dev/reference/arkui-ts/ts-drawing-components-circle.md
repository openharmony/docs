# Circle

 The **\<Circle>** component is used to draw a circle.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Circle(options?: {width?: string | number, height?: string | number})

**Parameters**

| Name| Type| Mandatory| Default Value | Description|
| -------- | -------- | -------- | -------- | -------- |
| width | string \| number | No| 0 | Width of the circle. |
| height | string \| number | No| 0 | Height of the circle. |

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value | Description|
| -------- | -------- | -------- | -------- |
| fill | [ResourceColor](ts-types.md#resourcecolor8) | Color.Black | Color of the fill area. |
| fillOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Opacity of the fill area. |
| stroke | [ResourceColor](ts-types.md#resourcecolor8) | - | Stroke color. If this attribute is not set, the component does not have any stroke.|
| strokeDashArray | Array&lt;Length&gt; | [] | Stroke dashes. |
| strokeDashOffset | number \| string  | 0 | Offset of the start point for drawing the stroke. |
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | Cap style of the stroke. |
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | Join style of the stroke. |
| strokeMiterLimit | number \| string | 4 | Limit on the ratio of the miter length to the value of **strokeWidth** used to draw a miter join.<br>**NOTE**<br>This attribute does not take effect for the **\<Circle>** component, because it does not have a miter join. |
| strokeOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Stroke opacity.<br>**NOTE**<br>The value range is [0.0, 1.0]. If the set value is less than 0.0, **0.0** will be used. If the set value is greater than 1.0, **1.0** will be used. |
| strokeWidth | Length | 1 | Stroke width. |
| antiAlias | boolean | true | Whether anti-aliasing is enabled. |


## Example

```ts
// xxx.ets
@Entry
@Component
struct CircleExample {
  build() {
    Column({ space: 10 }) {
      // Draw a circle whose diameter is 150.
      Circle({ width: 150, height: 150 })
      // Draw a circle whose diameter is 150 and stroke color is red. (If the width and height values are different, the smaller value will be used as the diameter.)
      Circle()
        .width(150)
        .height(200)
        .fillOpacity(0)
        .strokeWidth(3)
        .stroke(Color.Red)
        .strokeDashArray([1, 2])
    }.width('100%')
  }
}
```

![en-us_image_0000001219744191](figures/en-us_image_0000001219744191.png)
