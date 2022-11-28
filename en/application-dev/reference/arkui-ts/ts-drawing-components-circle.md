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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| width | string \| number | No| Width of the circle.<br>Default value: **0**|
| height | string \| number | No| Height of the circle.<br>Default value: **0**|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| fill | [ResourceColor](ts-types.md) | Color of the fill area.<br>Default value: **Color.Black**|
| fillOpacity | number \| string \| [Resource](ts-types.md#resource)| Opacity of the fill area.<br>Default value: **1**|
| stroke | [ResourceColor](ts-types.md) | Stroke color. If this attribute is not set, the component does not have any stroke.|
| strokeDashArray | Array&lt;Length&gt; | Stroke dashes.<br>Default value: **[]** |
| strokeDashOffset | number \| string  | Offset of the start point for drawing the stroke.<br>Default value: **0**|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | Cap style of the stroke.<br>Default value: **LineCapStyle.Butt**|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | Join style of the stroke.<br>Default value: **LineJoinStyle.Miter**|
| strokeMiterLimit | number \| string | Limit value when the sharp angle is drawn as a miter.<br>Default value: **4**<br>**NOTE**<br>This attribute does not take effect because the **\<Circle>** component cannot be used to draw a shape with a sharp angle.|
| strokeOpacity | number \| string \| [Resource](ts-types.md#resource)| Stroke opacity.<br>Default value: **1**<br>**NOTE**<br>The value range is [0.0, 1.0]. If the set value is less than 0.0, **0.0** will be used. If the set value is greater than 1.0, **1.0** will be used.|
| strokeWidth | Length | Stroke width.<br>Default value: **1**|
| antiAlias | boolean | Whether anti-aliasing is enabled.<br>Default value: **true**|


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
      // Draw a circle with the diameter of 150 and red dashes. (If the width and height are different, the shorter value is used as the diameter.)
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
