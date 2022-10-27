# Gradient Color

Create a more gorgeous look for a component by applying a gradient color effect to it.

>  **NOTE**
>
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes


| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| linearGradient | {<br>angle?: number \| string,<br>direction?: [GradientDirection](ts-appendix-enums.md#gradientdirection),<br>colors: Array&lt;[ColorStop](ts-basic-components-gauge.md#colorstop)&gt;,<br>repeating?: boolean<br>} | - | Linear gradient.<br>**angle**: angle of the linear gradient.<br>**direction**: direction of the linear gradient. It does not take effect when **angle** is set.<br>**colors**: description of the gradient colors.<br>**repeating**: whether the colors are repeated.|
| sweepGradient | {<br>center: Point,<br>start?: number \| string,<br>end?: number \| string,<br>rotation?: number\|string,<br>colors: Array&lt;[ColorStop](ts-basic-components-gauge.md#colorstop)&gt;,<br>repeating?: boolean<br>} | - | Angle gradient.<br>**center**: center point of the angle gradient.<br>**start**: start point of the angle gradient.<br>**end**: end point of the angle gradient.<br>**rotation**: rotation angle of the angle gradient.<br>**colors**: description of the gradient colors.<br>**repeating**: whether the colors are repeated.|
| radialGradient | {<br>center: Point,<br>radius: number \| string,<br>colors: Array&lt;[ColorStop](ts-basic-components-gauge.md#colorstop)&gt;,<br>repeating?: boolean<br>} | - | Radial gradient.<br>**center**: center point of the radial gradient.<br>**radius**: radius of the radial gradient.<br>**colors**: description of the gradient colors.<br>**repeating**: whether the colors are repeated.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct ColorGradientExample {
  
  build() {
    Column({ space: 5 }) {
      Text('linearGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width('90%')
        .height(50)
        .linearGradient({
          angle: 90,
          colors: [[0xAEE1E1, 0.0], [0xD3E0DC, 0.3], [0xFCD1D1, 1.0]]
        })
      Text('sweepGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .sweepGradient({
          center: [50, 50],
          start: 0,
          end: 359,
          colors: [[0xAEE1E1, 0.0], [0xD3E0DC, 0.3], [0xFCD1D1, 1.0]]
        })
      Text('radialGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .radialGradient({
          center: [50, 50],
          radius: 60,
          colors:[[0xAEE1E1, 0.0], [0xD3E0DC, 0.3], [0xFCD1D1, 1.0]]
        })
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![en-us_image_0000001212218484](figures/en-us_image_0000001212218484.png)
