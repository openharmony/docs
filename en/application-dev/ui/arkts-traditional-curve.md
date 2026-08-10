# Traditional Curve

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=a9629f73ba09e0a02f481334ff066f3a10f1dd06 translatedAt=2026-08-04T06:38:53.724Z pushedAt=2026-08-04T08:32:12.060Z -->

Traditional curves are based on mathematical formulas, creating animation curves whose shapes meet your expectations. Represented by the cubic Bezier curve [curves.cubicBezierCurve](../reference/apis-arkui/js-apis-curve.md#curvescubicbeziercurve9), you can change the curve shape by adjusting control points, thereby producing animation effects such as ease-in and ease-out. For the same traditional curve, since it has no physical meaning, its shape does not change in response to user actions, lacking the natural and vivid feel of physical animations. It is recommended that you prioritize physical curves for creating animations and use traditional curves as a supplement in the few necessary scenarios.

ArkUI provides APIs for traditional curves such as Bezier and step curves. For details, see [Interpolation Calculation](../reference/apis-arkui/js-apis-curve.md).

The following is an example of a traditional curve.

<!-- @[traditional_curve](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Animation/entry/src/main/ets/pages/traditionalCurve/template1/CurveDemo.ets) -->

``` TypeScript
class TraditionalCurve {
  public title: string;
  public curve: Curve;
  public color: Color | string;

  constructor(title: string, curve: Curve, color: Color | string = '') {
    this.title = title;
    this.curve = curve;
    this.color = color;
  }
}

const traditionalCurves: TraditionalCurve[] = [
  new TraditionalCurve(' Linear', Curve.Linear, '#317AF7'),
  new TraditionalCurve(' Ease', Curve.Ease, '#D94838'),
  new TraditionalCurve(' EaseIn', Curve.EaseIn, '#DB6B42'),
  new TraditionalCurve(' EaseOut', Curve.EaseOut, '#5BA854'),
  new TraditionalCurve(' EaseInOut', Curve.EaseInOut, '#317AF7'),
  new TraditionalCurve(' FastOutSlowIn', Curve.FastOutSlowIn, '#D94838')
]

@Entry
@Component
struct CurveDemo {
  @State dRotate: number = 0; // Rotation angle.

  build() {
    Column() {
      // Curve example
      Grid() {
        ForEach(traditionalCurves, (item: TraditionalCurve) => {
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
      .height(300)
      .margin({ top: 50 })

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

        ForEach(traditionalCurves, (item: TraditionalCurve) => {
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
          .animation({
            duration: 2000,
            iterations: -1,
            curve: item.curve,
            delay: 100
          })
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

![en-us_image_0000001641260233](figures/Traditional-Curve.gif)