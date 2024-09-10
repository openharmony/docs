# Traditional Curve

Traditional curves are mathematically described curves. A typical representative is the cubic Bezier curve. You define the curve shape with a set of control points, to bring out the expected animation effect, such as ease in and ease out. As aforementioned, a traditional curve is not based on the real-world behavior. This means that it does not change its shape to respond to user behavior, and lacks the natural and engaging feel given by a physics-based curve. When creating animations, prioritize physics-based curves and use traditional curves only in rare cases.


ArkUI provides APIs for traditional curves such as Bezier and step curves. For details, see [Interpolation Calculation](../reference/apis-arkui/js-apis-curve.md).


The following is an example of a traditional curve.



```ts
class MyCurve {
  public title: string;
  public curve: Curve;
  public color: Color | string;

  constructor(title: string, curve: Curve, color: Color | string = '') {
    this.title = title;
    this.curve = curve;
    this.color = color;
  }
}

const myCurves: MyCurve[] = [
  new MyCurve(' Linear', Curve.Linear, '#317AF7'),
  new MyCurve(' Ease', Curve.Ease, '#D94838'),
  new MyCurve(' EaseIn', Curve.EaseIn, '#DB6B42'),
  new MyCurve(' EaseOut', Curve.EaseOut, '#5BA854'),
  new MyCurve(' EaseInOut', Curve.EaseInOut, '#317AF7'),
  new MyCurve(' FastOutSlowIn', Curve.FastOutSlowIn, '#D94838')
]

@Entry
@Component
export struct CurveDemo {
  @State dRotate: number = 0; // Rotation angle.

  build() {
    Column() {
      // Curve example
      Grid() {
        ForEach(myCurves, (item: MyCurve) => {
          GridItem() {
            Column() {
              Row()
                .width(30)
                .height(30)
                .borderRadius(15)
                .backgroundColor(item.color)
              Text(item.title)
                .fontSize(15)
                .fontColor(0x909399)
            }
            .width('100%')
          }
        })
      }
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .padding(10)
      .width('100%')
      .height(300).margin({top:50})

      Stack() {
        // Swing pipe
        Row()
          .width(290)
          .height(290)
          .border({
            width: 15,
            color: 0xE6E8EB,
            radius: 145
          })

        ForEach(myCurves, (item: MyCurve) => {
          // Balls
          Column() {
            Row()
              .width(30)
              .height(30)
              .borderRadius(15)
              .backgroundColor(item.color)
          }
          .width(20)
          .height(300)
          .rotate({ angle: this.dRotate })
          .animation({ duration: 2000, iterations: -1, curve: item.curve, delay: 100 })
        })
      }
      .width('100%')
      .height(200)
      .onClick(() => {
        this.dRotate ? null : this.dRotate = 360;
      })
    }
    .width('100%')
  }
}
```


![en-us_image_0000001641260233](figures/en-us_image_0000001641260233.gif)
