# Gradient Color


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| linearGradient | {<br/>angle?:&nbsp;[Angle](../../ui/ts-types.md),<br/>direction?:GradientDirection,<br/>colors:&nbsp;Array<[ColorStop](../../ui/ts-types.md)><br/>repeating?:&nbsp;boolean<br/>} | - | Linear&nbsp;gradient.<br/>**angle**:&nbsp;angle&nbsp;of&nbsp;the&nbsp;linear&nbsp;gradient.<br/>**direction**:&nbsp;direction&nbsp;of&nbsp;the&nbsp;linear&nbsp;gradient.<br/>**colors**:&nbsp;description&nbsp;of&nbsp;the&nbsp;gradient&nbsp;colors.<br/>**repeating**:&nbsp;whether&nbsp;the&nbsp;colors&nbsp;are&nbsp;repeated. |
| sweepGradient | {<br/>center:&nbsp;Point,<br/>start?:&nbsp;angle,<br/>end?:&nbsp;angle,<br/>colors:&nbsp;Array<[ColorStop](../../ui/ts-types.md)><br/>repeating?:&nbsp;boolean<br/>} | - | Angle&nbsp;gradient.<br/>**center**:&nbsp;center&nbsp;point&nbsp;of&nbsp;the&nbsp;angle&nbsp;gradient.<br/>**start**:&nbsp;start&nbsp;point&nbsp;of&nbsp;the&nbsp;angle&nbsp;gradient.<br/>**end**:&nbsp;end&nbsp;point&nbsp;of&nbsp;the&nbsp;angle&nbsp;gradient.<br/>**colors**:&nbsp;description&nbsp;of&nbsp;the&nbsp;gradient&nbsp;colors.<br/>**repeating**:&nbsp;whether&nbsp;the&nbsp;colors&nbsp;are&nbsp;repeated. |
| radialGradient | {<br/>center:&nbsp;Point,<br/>radius:&nbsp;Length,<br/>colors:&nbsp;Array<[ColorStop](../../ui/ts-types.md)><br/>repeating:&nbsp;boolean<br/>} | - | Radial&nbsp;gradient.<br/>**center**:&nbsp;center&nbsp;point&nbsp;of&nbsp;the&nbsp;radial&nbsp;gradient.<br/>**radius**:&nbsp;radius&nbsp;of&nbsp;the&nbsp;radial&nbsp;gradient.<br/>**colors**:&nbsp;description&nbsp;of&nbsp;the&nbsp;gradient&nbsp;colors.<br/>**repeating**:&nbsp;whether&nbsp;the&nbsp;colors&nbsp;are&nbsp;repeated. |


- GradientDirection enums
  **GradientDirection** is used to describe the gradient direction.

    | Name | Description | 
  | -------- | -------- |
  | Left | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;from&nbsp;right&nbsp;to&nbsp;left. | 
  | Top | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;from&nbsp;bottom&nbsp;to&nbsp;top. | 
  | Right | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;from&nbsp;left&nbsp;to&nbsp;right. | 
  | Bottom | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;from&nbsp;top&nbsp;to&nbsp;bottom. | 
  | LeftTop | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;upper&nbsp;left. | 
  | LeftBottom | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;lower&nbsp;left. | 
  | RightTop | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;upper&nbsp;right. | 
  | RightBottom | The&nbsp;gradient&nbsp;direction&nbsp;is&nbsp;lower&nbsp;right. | 
  | None | No&nbsp;gradient. | 


## Example


```
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
          direction: GradientDirection.Left,
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
