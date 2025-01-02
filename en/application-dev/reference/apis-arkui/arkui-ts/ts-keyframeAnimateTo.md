# Keyframe Animation (keyframeAnimateTo)

The [UIContext](../js-apis-arkui-UIContext.md#uicontext) provides the **keyframeAnimateTo** API to specify several keyframes to implement segment-based animation. In an animation that involves width and height changes, as in a property animation, a component's content (such as text, [canvas](ts-components-canvas-canvas.md) content, and [linear gradient](ts-universal-attributes-gradient-color.md)) is changed straight to the final state. To enable the content to change with the width and height during the animation process, you can use the [renderFit](ts-universal-attributes-renderfit.md) attribute.

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

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type   | Mandatory| Description                                   |
| ---------- | ---------- | ------- | ------------------------------------- |
| delay      | number     | No     | Delay of animation playback, in ms.<br>Default value: **0**, indicating that the playback is not delayed.<br>**NOTE**<br>A value greater than 0 means to begin the animation after the specified amount of time has elapsed.<br>A value less than 0 means to begin the animation in advance. If the absolute value of **delay** is less than the actual animation duration, the animation starts its first frame from the state at the absolute value. If the absolute value of **delay** is greater than or equal to the actual animation duration, the animation starts its first frame from the end state. The actual animation duration is equal to the duration of a single animation multiplied by the number of animation playback times.|
| iterations | number     | No     | Number of times that the animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. The value **0** indicates that there is no animation.<br>Default value: **1**<br>Value range: [-1, +∞)|
| onFinish   | () => void | No     | Callback invoked when the animation playback is complete. This API is called after the keyframe animation has played for the specified number of times.|

## KeyframeState

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type                             | Mandatory| Description                                      |
| ---------- | ------------------------------------ | ------- | ---------------------------------------- |
| duration   | number                               | Yes     | Duration of the keyframe animation, in ms.<br>Value range: [0, +∞)<br>**NOTE**<br>- If this parameter is set to a value less than 0, the value **0** is used.<br>- Floating-point values will be rounded down to integers. For example, if the value set is 1.2, **1** will be used.|
| curve      | [Curve](ts-appendix-enums.md#curve)\| string \| [ICurve](../js-apis-curve.md#icurve9) | No | Animation curve used by the keyframe.<br>Default value: **Curve.EaseInOut**<br>**NOTE**<br>Because the[springMotion](../js-apis-curve.md#curvesspringmotion9), [responsiveSpringMotion](../js-apis-curve.md#curvesresponsivespringmotion9), and [interpolatingSpring](../js-apis-curve.md#curvesinterpolatingspring10) curves do not have effective duration settings, they are not supported.|
| event      | () => void                           | Yes     | Closure function of the state at the time of the keyframe, that is, the state to be reached at the time of the keyframe.|

## Example

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
          this.uiContext.keyframeAnimateTo({ iterations: 3 }, [
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
