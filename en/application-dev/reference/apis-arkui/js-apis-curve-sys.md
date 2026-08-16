# @ohos.curves (Interpolation Calculation) (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=f2c83aae5fc4cc185b9f2bf3ef69ad83dc991bfc translatedAt=2026-08-11T09:13:45.374Z pushedAt=2026-08-13T03:49:52.695Z -->

This module provides the system APIs for setting animation interpolation curves, used to construct objects for curves such as spring animation curves, responsive spring animation curves, and interpolating spring curves.

> **NOTE**
>
> This topic contains only the system APIs of this module. For other public APIs, see [@ohos.curves (Interpolation Calculation)](js-apis-curve.md).

**Since:** 26.0.0

## Modules to Import

```ts
import { curves } from '@kit.ArkUI';
```

## TrailOptimization

Implements trailing optimization for a spring animation.

**System API:** This is a system API.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| --- | --- | --- | --- | --- |
| progressThreshold | number | No | Yes | Animation progress threshold.<br/>Value range: [0, 1]<br/>Default value: **1**. |
| responseDecayFactor | number | No | Yes | Natural vibration period decay factor.<br/>Value range: (0, 1]<br/>Default value: **1**. |

## curves.trailOptimizedSpringMotion

trailOptimizedSpringMotion(response?: number, dampingFraction?: number, overlapDuration?: number, trail?: TrailOptimization): ICurve

Constructs a spring animation curve object with trailing optimization by adding trailing optimization parameters based on [springMotion](js-apis-curve.md#curvesspringmotion9). If multiple spring animations are applied to the same attribute of the same object, each animation replaces the previous one and inherits its velocity.

**System API:** This is a system API.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| --- | --- | --- | --- |
| response | number | No | Natural vibration period of the spring, which determines the speed at which the spring returns to rest.<br/>Default value: **0.55**<br/>Unit: second<br/>Value range: (0, +∞)<br/>**NOTE**<br/>If the value is less than or equal to 0, the default value **0.55** is used. |
| dampingFraction | number | No | Damping coefficient.<br/>**0** indicates no damping, resulting in perpetual oscillation.<br/>A value greater than 0 and less than 1 indicates under-damping, where the motion overshoots the target value.<br/>**1** indicates critical damping.<br/>A value greater than 1 indicates over-damping, where the motion gradually approaches the target value.<br/>Default value: **0.825**<br/>Value range: [0, +∞)<br/>**NOTE**<br/>If the value is less than 0, the default value **0.825** is used. |
| overlapDuration | number | No | Duration for spring animation transition. When animation inheritance occurs, if the **response** values of the two spring animations differ, the **response** parameter smoothly transitions over **overlapDuration**.<br/>Default value: **0**<br/>Unit: second<br/>Value range: [0, +∞)<br/>**NOTE**<br/>If the value is less than 0, the default value **0** is used.<br/>The spring animation curve is a physical curve. The **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), and [pageTransition](arkui-ts/ts-page-transition-animation.md) does not take effect. The animation duration depends on the **trailOptimizedSpringMotion** animation curve parameters and the previous velocity. The time cannot be normalized, so interpolation cannot be obtained through the **interpolate** API of this curve. |
| trail | [TrailOptimization](#trailoptimization) | No | Trailing optimization configuration. |

**Return value**

| Type | Description |
| --- | --- |
| [ICurve](js-apis-curve.md#icurve9) | Curve object.<br/>**NOTE**<br/>The spring animation curve is a physical curve. The **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), and [pageTransition](arkui-ts/ts-page-transition-animation.md) does not take effect. The animation duration depends on the **trailOptimizedSpringMotion** animation curve parameters and the previous velocity. The time cannot be normalized, so interpolation cannot be obtained through the [interpolate](js-apis-curve.md#interpolate9) API of this curve. |

## curves.trailOptimizedResponsiveSpringMotion

trailOptimizedResponsiveSpringMotion(response?: number, dampingFraction?: number, overlapDuration?: number, trail?: TrailOptimization): ICurve

Constructs a responsive spring animation curve object with trailing optimization by adding trailing optimization parameters based on [responsiveSpringMotion](js-apis-curve.md#curvesresponsivespringmotion9).

**System API:** This is a system API.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| --- | --- | --- | --- |
| response | number | No | Same as **response** in **springMotion**.<br/>Default value: **0.15**<br/>Unit: second<br/>Value range: (0, +∞)<br/>**NOTE**<br/>If the value is less than or equal to 0, the default value **0.15** is used. |
| dampingFraction | number | No | Same as **dampingFraction** in **springMotion**.<br/>Default value: **0.86**<br/>Value range: [0, +∞)<br/>**NOTE**<br/>If the value is less than 0, the default value **0.86** is used. |
| overlapDuration | number | No | Same as **overlapDuration** in **springMotion**.<br/>Default value: **0.25**<br/>Unit: second<br/>Value range: [0, +∞)<br/>**NOTE**<br/>If the value is less than 0, the default value **0.25** is used.<br/>The responsive spring animation curve is a special case of **springMotion**, differing only in default values. If a spring curve with custom parameters is used, it is recommended to use **springMotion** to construct the curve. If a responsive animation is used, it is recommended to use the responsive spring animation curve with default parameters.<br/>The **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), and [pageTransition](arkui-ts/ts-page-transition-animation.md) does not take effect. The animation duration depends on the **trailOptimizedResponsiveSpringMotion** animation curve parameters and the previous velocity, and the interpolation cannot be obtained through the **interpolate** API of this curve. |
| trail | [TrailOptimization](#trailoptimization) | No | Trailing optimization configuration. |

**Return value**

| Type | Description |
| --- | --- |
| [ICurve](js-apis-curve.md#icurve9) | Curve object.<br/>**NOTE**<br/>1. The responsive spring animation curve is a special case of **springMotion**, differing only in default values. If a spring curve with custom parameters is used, it is recommended to use **springMotion** to construct the curve. If a responsive animation is used, it is recommended to use the responsive spring animation curve with default parameters.<br/>2. The **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), and [pageTransition](arkui-ts/ts-page-transition-animation.md) does not take effect. The animation duration depends on the **trailOptimizedResponsiveSpringMotion** animation curve parameters and the previous velocity, and the interpolation cannot be obtained through the [interpolate](js-apis-curve.md#interpolate9) API of this curve. |

## curves.trailOptimizedInterpolatingSpring

trailOptimizedInterpolatingSpring(velocity: number, mass: number, stiffness: number, damping: number, trail?: TrailOptimization): ICurve

Construct an interpolating spring curve object with trailing optimization by adding trailing optimization parameters based on [interpolatingSpring](js-apis-curve.md#curvesinterpolatingspring10), generating an animation curve from 0 to 1. Actual animation values are calculated through interpolation based on the curve. The animation duration is determined by the curve parameters and is not controlled by the duration parameter in the animation settings.

**System API:** This is a system API.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| --- | --- | --- | --- |
| velocity | number | Yes | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. This is a normalized velocity, and it is calculated as the actual initial velocity divided by the change in the animation property.<br/>Value range: (-∞, +∞) |
| mass | number | Yes | Mass. It describes the inertia of the object in the elastic system, affecting the amplitude of oscillation and the speed of return to equilibrium. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.<br/>Value range: (0, +∞)<br/>**Note:** When the value is set to less than or equal to 0, **1** is used. |
| stiffness | number | Yes | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the capability to resist deformation, and the faster the speed of restoring to the equilibrium position.<br/>Value range: (0, +∞)<br/>**Note:** When the value is set to less than or equal to 0, **1** is used. |
| damping | number | Yes | Damping. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.<br/>Value range: (0, +∞)<br/>**Note:** When the value is set to less than or equal to 0, **1** is used. |
| trail | [TrailOptimization](#trailoptimization) | No | Trailing optimization configuration. |

**Return value**

| Type | Description |
| --- | --- |
| [ICurve](js-apis-curve.md#icurve9) | Curve object.<br/>**Note:** The spring animation curve is a physical curve. The **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), and [pageTransition](arkui-ts/ts-page-transition-animation.md) does not take effect. The animation duration depends on the **trailOptimizedInterpolatingSpring** animation curve parameters. Time cannot be normalized, so the interpolation value cannot be obtained through the [interpolate](js-apis-curve.md#interpolate9) API of this curve. |

## Example

### Example 1: Spring Curve with Trailing Optimization

This example demonstrates the acceleration effect of trailing optimization on the spring animation by comparing the animation execution durations of [interpolatingSpring](js-apis-curve.md#curvesinterpolatingspring10) and [trailOptimizedInterpolatingSpring](#curvestrailoptimizedinterpolatingspring).

```ts
import { curves } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State widthSize: number = 150;
  @State heightSize: number = 50;
  @State myAnimateTimeOrigin: number = 0;
  @State myAnimateTimeOptimized: number = 0;
  @State myAngleOrigin: number = 0;
  @State myAngleOptimized: number = 0;

  build() {
    Column() {
      Row() {
        Column() {
          Column()
            .height(100)
            .width(100)
            .borderRadius(10)
            .backgroundColor(Color.Blue)
            .rotate({
              x: 0,
              y: 0,
              z: 1,
              angle: this.myAngleOrigin
            })
          // The actual animation execution duration may fluctuate.
          Text('Original execution duration:' + this.myAnimateTimeOrigin)
        }
        .width('50%')

        Column() {
          Column()
            .height(100)
            .width(100)
            .borderRadius(10)
            .backgroundColor(Color.Red)
            .rotate({
              x: 0,
              y: 0,
              z: 1,
              angle: this.myAngleOptimized
            })
          // The actual animation execution duration may fluctuate.
          Text('Trailing optimization execution duration:' + this.myAnimateTimeOptimized)
        }
        .width('50%')
      }
      .justifyContent(FlexAlign.Center)

      Button('Play animate')
        .width(this.widthSize)
        .height(this.heightSize)
        .margin(5)
        .onClick(() => {
          const startTime = Date.now();

          this.getUIContext()?.animateTo({
            duration: 2000,
            curve: curves.interpolatingSpring(0.85, 0.1, 7, 1.0),
            iterations: 1,
            playMode: PlayMode.Normal,
            onFinish: () => {
              const endTime = Date.now();
              this.myAnimateTimeOrigin = endTime - startTime;
            }
          }, () => {
            this.myAngleOrigin = 360;
          })

          this.getUIContext()?.animateTo({
            duration: 2000,
            curve: curves.trailOptimizedInterpolatingSpring(0.85, 0.1, 7, 1.0,
              { progressThreshold: 0.98, responseDecayFactor: 0.9 }),
            iterations: 1,
            playMode: PlayMode.Normal,
            onFinish: () => {
              const endTime = Date.now();
              this.myAnimateTimeOptimized = endTime - startTime;
            }
          }, () => {
            this.myAngleOptimized = 360;
          })
        })
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```

