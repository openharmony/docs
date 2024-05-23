# Property Animation (animation)

With property animations, you can animate changes to certain component properties, such as [width](ts-universal-attributes-size.md#width), [height](ts-universal-attributes-size.md#height), [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), [opacity](ts-universal-attributes-opacity.md#opacity), [scale](ts-universal-attributes-transformation.md#scale), [rotate](ts-universal-attributes-transformation.md#rotate) and [translate](ts-universal-attributes-transformation.md#translate). In a property animation that involves width and height changes, a component's content (such as text, [canvas](ts-components-canvas-canvas.md#canvas) content, and [linear gradient](ts-universal-attributes-gradient-color.md#lineargradient)) is changed straight to the final state. To enable the content to change with the width and height during the animation process, use the [renderFit](ts-universal-attributes-renderfit.md#renderfit) attribute.

> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> This API can be used in ArkTS widgets since API version 9.

## APIs

animation(value:AnimateParam)

**Parameters**
| Name   | Type                               | Mandatory| Description                                   |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| value | [AnimateParam](../arkui-ts/ts-explicit-animation.md#animateparam) | Yes   | Animation settings.                          |

## ExpectedFrameRateRange<sup>11+</sup>
| Name | Type    | Description     |
|-----|--------|---------|
| min | number | Expected minimum frame rate.|
| max | number | Expected maximum frame rate.|
| expected | number | Expected optimal frame rate.|

> **Notes about PlayMode**:
> - **PlayMode.Normal** and **PlayMode.Alternate** are recommended. Under these settings, the first round of the animation is played forwards. If **PlayMode.Reverse** or **PlayMode.AlternateReverse** is used, the first round of the animation is played backwards. In this case, the animation jumps to the end state and then starts from there.
> - When using **PlayMode.Alternate** or **PlayMode.AlternateReverse**, make sure the final state of the animation is the same as the value of the state variable. In other words, make sure the last round of the animation is played forwards. When **PlayMode.Alternate** is used, **iterations** must be set to an odd number. When **PlayMode.AlternateReverse** is used, **iterations** must be set to an even number.
> - **PlayMode.Reverse** is not recommended. Under this setting, the animation jumps to the end state at the beginning, and its final state will be different from the value of the state variable.

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
