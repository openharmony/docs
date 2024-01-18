# Circle

 The **\<Circle>** component is used to draw a circle.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Circle(options?: {width?: string | number, height?: string | number})

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| width | string \| number | No| Width of the circle.<br>Default value: **0**<br>**NOTE**<br>An invalid value is handled as the default value.|
| height | string \| number | No| Height of the circle.<br>Default value: **0**<br>**NOTE**<br>An invalid value is handled as the default value.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| fill | [ResourceColor](ts-types.md) | Color.Black | Color of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| fillOpacity | [Length](ts-types.md#length) | 1 | Opacity of the fill area.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| stroke | [ResourceColor](ts-types.md) | - | Stroke color. If this attribute is not set, the component does not have any stroke.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>If the value is invalid, no stroke will be drawn.|
| strokeDashArray | Array&lt;[Length](ts-types.md#length)&gt; | [] | Stroke dashes.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| strokeDashOffset | number \| string  | 0 | Offset of the start point for drawing the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>An invalid value is handled as the default value.|
| strokeLineCap | [LineCapStyle](ts-appendix-enums.md#linecapstyle) | LineCapStyle.Butt | Cap style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeLineJoin | [LineJoinStyle](ts-appendix-enums.md#linejoinstyle) | LineJoinStyle.Miter |  Join style of the stroke.<br>Since API version 9, this API is supported in ArkTS widgets.|
| strokeMiterLimit | number \| string | 4 | Limit on the ratio of the miter length to the value of **strokeWidth** used to draw a miter join.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute does not take effect for the **\<Circle>** component, because it does not have a miter join.|
| strokeOpacity | [Length](ts-types.md#length) | 1 | Stroke opacity.<br>Default value: **1**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>The value range is [0.0, 1.0]. A value less than 0.0 evaluates to the value **0.0**. A value greater than 1.0 evaluates to the value **1.0**. Any other value evaluates to the value **1.0**.|
| strokeWidth | [Length](ts-types.md#length) | 1 | Stroke width.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>If of the string type, this parameter cannot be set in percentage. A percentage is processed as 1px.|
| antiAlias | boolean | true | Whether anti-aliasing is enabled.<br>Since API version 9, this API is supported in ArkTS widgets.|



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
