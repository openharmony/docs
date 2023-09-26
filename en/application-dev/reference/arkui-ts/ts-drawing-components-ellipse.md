# Ellipse

The **\<Ellipse>** component is used to draw an ellipse.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Ellipse(options?: {width?: string | number, height?: string | number})

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| width | string \| number | No| Width.<br>Default value: **0**<br>**NOTE**<br>An invalid value is handled as the default value.|
| height | string \| number | No| Height.<br>Default value: **0**<br>**NOTE**<br>An invalid value is handled as the default value.|



## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| fill | [ResourceColor](ts-types.md) | Color.Black | Color of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| fillOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Opacity of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| stroke | [ResourceColor](ts-types.md) | - |Stroke color. If this attribute is not set, the component does not have any stroke.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>If the value is invalid, no stroke will be drawn.|
| strokeDashArray | Array&lt;Length&gt; | [] | Stroke dashes.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| strokeDashOffset | number \| string | 0 | Offset of the start point for drawing the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | Cap style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter | Join style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute does not work for the **\<ellipse>** component, which does not have corners.|
| strokeMiterLimit | number \| string | 4 | Limit on the ratio of the miter length to the value of **strokeWidth** used to draw a miter join.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute does not take effect for the **\<Ellipse>** component, because it does not have a miter join.|
| strokeOpacity | number \| string \| [Resource](ts-types.md#resource)| 1 | Stroke opacity.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>The value range is [0.0, 1.0]. A value less than 0.0 evaluates to the value **0.0**. A value greater than 1.0 evaluates to the value **1.0**. Any other value evaluates to the value **1.0**.|
| strokeWidth | Length | 1 | Stroke width.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>The value cannot be a percentage.<br>An invalid value is handled as the default value.|
| antiAlias | boolean | true | Whether anti-aliasing is enabled.<br>Since API version 9, this API is supported in ArkTS widgets.|



## Example

```ts
// xxx.ets
@Entry
@Component
struct EllipseExample {
  build() {
    Column({ space: 10 }) {
      // Draw a 150 x 80 ellipse.
      Ellipse({ width: 150, height: 80 })
      // Draw a 150 x 100 ellipse with blue strokes.
      Ellipse()
        .width(150)
        .height(100)
        .fillOpacity(0)
        .stroke(Color.Blue)
        .strokeWidth(3)
    }.width('100%')
  }
}
```

![en-us_image_0000001174104394](figures/en-us_image_0000001174104394.png)
