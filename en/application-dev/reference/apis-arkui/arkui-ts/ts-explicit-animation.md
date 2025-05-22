# Explicit Animation (animateTo)

With **animateTo**, you can build explicit animations for state changes caused by closure code. In an explicit animation that involves width and height changes, as in a property animation, a component's content (such as text, [canvas](ts-components-canvas-canvas.md) content, and [linear gradient](ts-universal-attributes-gradient-color.md)) is changed straight to the final state. To enable the content to change with the width and height during the animation process, you can use the [renderFit](ts-universal-attributes-renderfit.md) attribute.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](../js-apis-arkui-UIContext.md#uicontext).
>
>**Widget capability**: This API can be used in ArkTS widgets since API version 9.
>
>  Since API version 10, you can use the [animateTo](../js-apis-arkui-UIContext.md#animateto) API in [UIContext](../js-apis-arkui-UIContext.md#uicontext), which ensures that your animation is executed in the intended UI instance.
> This API can be used in atomic services since API version 11.

## APIs
animateTo(value: AnimateParam, event: () => void): void

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**
| Name   | Type                               | Mandatory| Description                                   |
| ----- | --------------------------------- | ---- | ------------------------------------- |
| value | [AnimateParam](#animateparam)| Yes   | Animation settings.                          |
| event | () => void                        | Yes   | Closure function for the animation. The system automatically inserts the transition animation if the state changes in the closure function.|

## AnimateParam

| Name        | Type         | Mandatory                | Description                                      |
| ---------- | ---------------|------------------------ | ---------------------------------------- |
| duration   | number         |  No | Animation duration, in ms.<br>Default value: **1000**<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**NOTE**<br>- The maximum animation duration on an ArkTS widget is 1000 ms. If the set value exceeds the limit, the value **1000** will be used.<br>- A value less than 0 evaluates to the value **0**.<br>- Floating-point values will be rounded down to integers. For example, if the value set is 1.2, **1** will be used.|
| tempo      | number         | No| Animation playback speed. A larger value indicates faster animation playback, and a smaller value indicates slower animation playback. The value **0** means that there is no animation.<br>Default value: **1.0**<br><br>**Atomic service API**: This API can be used in atomic services since API version 11. **NOTE**<br>A value less than 0 evaluates to the value **1**.|
| curve      | [Curve](ts-appendix-enums.md#curve) \| [ICurve<sup>9+</sup>](../js-apis-curve.md#icurve9) \| string | No| Animation curve.<br>Default value: **Curve.EaseInOut**<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| delay      | number         | No| Delay of animation playback, in ms. By default, the playback is not delayed.<br>Default value: **0**<br>Value range: (-∞, +∞)<br><br>**Atomic service API**: This API can be used in atomic services since API version 11. **NOTE**<br>- A value greater than 0 means to begin the animation after the specified amount of time has elapsed.<br>A value less than 0 means to begin the animation in advance. If the absolute value of **delay** is less than the actual animation duration, the animation starts its first frame from the state at the absolute value. If the absolute value of **delay** is greater than or equal to the actual animation duration, the animation starts its first frame from the end state. The actual animation duration is equal to the duration of a single animation multiplied by the number of animation playback times.<br>- Floating-point values will be rounded down to integers. For example, if the value set is 1.2, **1** will be used.|
| iterations | number         | No| Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. The value **0** indicates that there is no animation.<br>Default value: **1**<br>Value range: [-1, +∞)<br>**Atomic service API**: This API can be used in atomic services since API version 11.         |
| playMode   | [PlayMode](ts-appendix-enums.md#playmode)|No| Playback mode. By default, the animation is played from the beginning after the playback is complete.<br>Default value: **PlayMode.Normal**<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.<br>For details about the restrictions, see **Notes about PlayMode**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onFinish   | () =&gt; void      | No| Callback invoked when the animation playback is complete.<br>**Widget capability**: This API can be used in ArkTS widgets since API version 9.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| finishCallbackType<sup>11+</sup>   | [FinishCallbackType](#finishcallbacktype11)|No| Type of the **onFinish** callback.<br>Default value: **FinishCallbackType.REMOVED**<br>**Widget capability**: This API can be used in ArkTS widgets since API version 11.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| expectedFrameRateRange<sup>11+</sup>   | [ExpectedFrameRateRange](#expectedframeraterange11) | No| Expected frame rate range of the animation. **Atomic service API**: This API can be used in atomic services since API version 12.|

> **Notes about PlayMode**:
>
> - **PlayMode.Normal** and **PlayMode.Alternate** are recommended. Under these settings, the first round of the animation is played forwards. If **PlayMode.Reverse** or **PlayMode.AlternateReverse** is used, the first round of the animation is played backwards. In this case, the animation jumps to the end state and then starts from there.
> - When using **PlayMode.Alternate** or **PlayMode.AlternateReverse**, make sure the final state of the animation is the same as the value of the state variable. In other words, make sure the last round of the animation is played forwards. When **PlayMode.Alternate** is used, **iterations** must be set to an odd number. When **PlayMode.AlternateReverse** is used, **iterations** must be set to an even number.
> - **PlayMode.Reverse** is not recommended. Under this setting, the animation jumps to the end state at the beginning, and its final state will be different from the value of the state variable.

## FinishCallbackType<sup>11+</sup>

**Widget capability**: This API can be used in ArkTS widgets since API version 11.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Description                                                        |
| --------- | ------------------------------------------------------------ |
| REMOVED   | The callback is invoked when the entire animation is removed once it has finished.                        |
| LOGICALLY | The callback is invoked when the animation logically enters the falling state, though it may still be in its long tail state.|

## ExpectedFrameRateRange<sup>11+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name | Type    | Description     |
|-----|--------|---------|
| min | number | Expected minimum frame rate.|
| max | number | Expected maximum frame rate.|
| expected | number | Expected optimal frame rate.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct AnimateToExample {
  @State widthSize: number = 250
  @State heightSize: number = 100
  @State rotateAngle: number = 0
  private flag: boolean = true

  build() {
    Column() {
      Button('change size')
        .width(this.widthSize)
        .height(this.heightSize)
        .margin(30)
        .onClick(() => {
          if (this.flag) {
            animateTo({
              duration: 2000,
              curve: Curve.EaseOut,
              iterations: 3,
              playMode: PlayMode.Normal,
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 150
              this.heightSize = 60
            })
          } else {
            animateTo({}, () => {
              this.widthSize = 250
              this.heightSize = 100
            })
          }
          this.flag = !this.flag
        })
      Button('change rotate angle')
        .margin(50)
        .rotate({ x: 0, y: 0, z: 1, angle: this.rotateAngle })
        .onClick(() => {
          animateTo({
            duration: 1200,
            curve: Curve.Friction,
            delay: 500,
            iterations: -1, // The value -1 indicates that the animation is played for an unlimited number of times.
            playMode: PlayMode.Alternate,
            onFinish: () => {
              console.info('play end')
            },
            expectedFrameRateRange: {
              min: 10,
              max: 120,
              expected: 60,
            }
          }, () => {
            this.rotateAngle = 90
          })
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![animation1](figures/animation1.gif)
