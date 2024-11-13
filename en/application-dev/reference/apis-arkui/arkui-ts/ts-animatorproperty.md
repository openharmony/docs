# Property Animation (animation)

With property animations, you can animate changes to certain component properties, such as [width](ts-universal-attributes-size.md#width), [height](ts-universal-attributes-size.md#height), [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [opacity](ts-universal-attributes-opacity.md#opacity), [scale](ts-universal-attributes-transformation.md#scale), [rotate](ts-universal-attributes-transformation.md#rotate) and [translate](ts-universal-attributes-transformation.md#translate). In a property animation that involves width and height changes, a component's content (such as text, [canvas](ts-components-canvas-canvas.md#canvas) content, and [linear gradient](ts-universal-attributes-gradient-color.md#lineargradient)) is changed straight to the final state. To enable the content to change with the width and height during the animation process, use the [renderFit](ts-universal-attributes-renderfit.md#renderfit) attribute.

> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> **Widget capability**: This API can be used in ArkTS widgets since API version 9.

## APIs

animation(value:AnimateParam)

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**
| Name   | Type                               | Mandatory| Description                                   |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| value | [AnimateParam](ts-explicit-animation.md#animateparam) | Yes   | Animation settings.                          |

## Example
```ts
// xxx.ets
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State rotateAngle: number = 0
  @State flag: boolean = true

  build() {
    Column() {
      Button('change size')
        .onClick(() => {
          if (this.flag) {
            this.widthSize = 150
            this.heightSize = 60
          } else {
            this.widthSize = 250
            this.heightSize = 100
          }
          this.flag = !this.flag
        })
        .margin(30)
        .width(this.widthSize)
        .height(this.heightSize)
        .animation({
          duration: 2000,
          curve: Curve.EaseOut,
          iterations: 3,
          playMode: PlayMode.Normal
        })
      Button('change rotate angle')
        .onClick(() => {
          this.rotateAngle = 90
        })
        .margin(50)
        .rotate({ angle: this.rotateAngle })
        .animation({
          duration: 1200,
          curve: Curve.Friction,
          delay: 500,
          iterations: -1, // The value -1 indicates that the animation is played for an unlimited number of times.
          playMode: PlayMode.Alternate,
          expectedFrameRateRange: {
            min: 20,
            max: 120,
            expected: 90,
          }
        })
    }.width('100%').margin({ top: 20 })
  }
}
```

![animation](figures/animation.gif)
