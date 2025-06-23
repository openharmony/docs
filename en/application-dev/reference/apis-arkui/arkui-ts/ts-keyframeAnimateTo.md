# Keyframe Animation (keyframeAnimateTo)

The [UIContext](../js-apis-arkui-UIContext.md#uicontext) provides the **keyframeAnimateTo** API that allows you to define several keyframes to implement segment-based animations. In an animation that involves width and height changes, as in a property animation, a component's content (such as text and [canvas](ts-components-canvas-canvas.md) content) is changed straight to the final state. To enable the content to change with the width and height during the animation process, use the [renderFit](ts-universal-attributes-renderfit.md#renderfit) attribute.

>  **NOTE**
>
>  This feature is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.
>
>  This API is a member function of the [UIContext](../js-apis-arkui-UIContext.md#uicontext) class and needs to be called through a **UIContext** instance.

keyframeAnimateTo(param: KeyframeAnimateParam, keyframes: Array&lt;KeyframeState&gt;): void

Sets the keyframe animation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                             | Mandatory| Description                        |
| ------------ | ---------------------------------------------------- | ------- | ---------------------------- |
| param        | [KeyframeAnimateParam](#keyframeanimateparam) | Yes     | Global parameters of the keyframe animation.    |
| keyframes    | Array&lt;[KeyframeState](#keyframestate)&gt;  | Yes     | Array of keyframes.           |

## KeyframeAnimateParam

| Name      | Type   | Mandatory| Description                                   |
| ---------- | ---------- | ------- | ------------------------------------- |
| delay      | number     | No     | Delay of animation playback, in ms.<br>Default value: **0**.<br>**NOTE**<br>A value greater than 0 means to begin the animation after the specified amount of time has elapsed.<br>A value less than 0 means to begin the animation in advance. If the absolute value of **delay** is less than the actual animation duration, the animation starts its first frame from the state at the absolute value. If the absolute value of **delay** is greater than or equal to the actual animation duration, the animation starts its first frame from the end state. The actual animation duration is equal to the duration of a single animation multiplied by the number of animation playback times.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| iterations | number     | No     | Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. The value **0** indicates that there is no animation.<br>Default value: **1**.<br>Value range: [-1, +∞).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| onFinish   | () => void | No     | Callback invoked when the animation playback is complete. This API is called after the keyframe animation has played for the specified number of times. If the UIAbility moves from the foreground to the background, any finite loop keyframe animation that is still in progress will be immediately terminated, triggering the completion callback.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| expectedFrameRateRange<sup>18+</sup>   | [ExpectedFrameRateRange](../arkui-ts/ts-explicit-animation.md#expectedframeraterange11) | No| Expected frame rate range of the animation.<br>Default value: {min:-1, max:-1, expected:-1} (following the application's frame rate)<br>**NOTE**<br>After a valid expected frame rate is set, the system collects the configured frame rate and divides the frequency on the rendering pipeline. The actual frame rate may be different from the expected one configured. It is limited by the system capability and screen refresh rate.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## KeyframeState

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type                             | Mandatory| Description                                      |
| ---------- | ------------------------------------ | ------- | ---------------------------------------- |
| duration   | number                               | Yes     | Duration of the keyframe animation, in ms.<br>Value range: [0, +∞)<br>**NOTE**<br>- If this parameter is set to a value less than 0, the value **0** is used.<br>- Floating-point values will be rounded down to integers. For example, if the value set is 1.2, **1** will be used.|
| curve      | [Curve](ts-appendix-enums.md#curve)\| string \| [ICurve](../js-apis-curve.md#icurve9) | No | Animation curve used by the keyframe.<br>You are advised to specify the curve using the **Curve** or **ICurve** type.<br>For the string type, this parameter indicates an animation interpolation curve. For available values, see the **curve** parameter in [AnimateParam](./ts-explicit-animation.md#animateparam).<br>Default value: **Curve.EaseInOut**<br>**NOTE**<br>Because the[springMotion](../js-apis-curve.md#curvesspringmotion9), [responsiveSpringMotion](../js-apis-curve.md#curvesresponsivespringmotion9), and [interpolatingSpring](../js-apis-curve.md#curvesinterpolatingspring10) curves do not have effective duration settings, they are not supported.|
| event      | () => void                           | Yes     | Closure function of the state at the time of the keyframe, that is, the state to be reached at the time of the keyframe.|

## Example

This example demonstrates how to set the keyframe animation using **keyframeAnimateTo**.

```ts
// xxx.ets
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct KeyframeDemo {
  @State myScale: number = 1.0;
  uiContext: UIContext | undefined = undefined;

  aboutToAppear() {
    this.uiContext = this.getUIContext?.();
  }

  build() {
    Column() {
      Circle()
        .width(100)
        .height(100)
        .fill("#46B1E3")
        .margin(100)
        .scale({ x: this.myScale, y: this.myScale })
        .onClick(() => {
          if (!this.uiContext) {
            console.info("no uiContext, keyframe failed");
            return;
          }
          this.myScale = 1;
          // Set the keyframe animation to play three times.
          this.uiContext.keyframeAnimateTo({
              iterations: 3,
              expectedFrameRateRange: {
                min: 10,
                max: 120,
                expected: 60,
              }
            }, [
            {
              // The first keyframe animation lasts for 800 ms, during which the scale attribute changes from 1 to 1.5.
              duration: 800,
              event: () => {
                this.myScale = 1.5;
              }
            },
            {
              // The second keyframe animation lasts for 500 ms, during which the scale attribute changes from 1.5 to 1.
              duration: 500,
              event: () => {
                this.myScale = 1;
              }
            }
          ]);
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![keyframeAnimateTo](figures/keyframeAnimateTo1.gif)
