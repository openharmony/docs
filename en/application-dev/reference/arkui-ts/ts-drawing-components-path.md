# Path


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **<Path\>** component is used to draw a path.


## Required Permissions

None


## Child Components

None


## Attributes

| Name | Type | Default Value | Mandatory | Description | 
| -------- | -------- | -------- | -------- | -------- |
| width | Length | 0 | No | Width of the rectangle where the path is located. | 
| height | Length | 0 | No | Height of the rectangle where the path is located. | 
| commands | string | '' | Yes | Commands for drawing the path. | 


The supported commands are as follows:


- M = moveto

- L = lineto

- H = horizontal lineto

- V = vertical lineto

- C = curveto

- S = smooth curveto

- Q = quadratic Bezier curve

- T = smooth quadratic Bezier curveto

- A = elliptical Arc

- Z = closepath


For example, the command **M0 20 L50 50 L50 100 Z** defines a path that starts from (0, 20), reaches (50, 50) and then (50, 100), and ends at (0, 20).


## Example

  
```ts
@Entry
@Component
struct PathExample {
  build() {
    Column({ space: 5 }) {
      Text('Straight line').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Path().width(300).height(10).commands('M0 0 L900 0').stroke(Color.Black).strokeWidth(3)

      Text('Straight line graph').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        // Run MoveTo(150, 0), LineTo(300, 300), LineTo(0, 300), and ClosePath() in sequence.
        Path().width(100).height(100).commands('M150 0 L300 300 L0 300 Z')
        // Run MoveTo(0, 0), HorizontalLineto(300), VerticalLineto(300), HorizontalLineto(0), and ClosePath() in sequence.
        Path().width(100).height(100).commands('M0 0 H300 V300 H0 Z')
        // Run MoveTo(150, 0), LineTo(0, 150), LineTo(60, 300), LineTo(240, 300), LineTo(300, 150), and ClosePath() in sequence.
        Path().width(100).height(100).commands('M150 0 L0 150 L60 300 L240 300 L300 150 Z')
      }.width('100%')

      Text('Curve graphics').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        / / Run MoveTo(0, 300), draw a curve between (150, 0) and (300, 300), and then run ClosePath().
        Path().width(100).height(100).commands("M0 300 S150 0 300 300 Z")
        / / Run MoveTo(0, 150), draw a curve among (0, 150), (150, 0), and (300, 150), and then run ClosePath().
        Path().width(100).height(100).commands('M0 150 C0 150 150 0 300 150 L150 300 Z')
      }
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212058492](figures/en-us_image_0000001212058492.png)