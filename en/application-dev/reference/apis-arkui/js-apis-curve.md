# @ohos.curves (Interpolation Calculation)

The **Curves** module provides APIs for interpolation calculation to create step, cubic Bezier, and spring curves.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { curves } from '@kit.ArkUI';
```


## Curves.initCurve<sup>9+</sup>

initCurve(curve?: Curve): ICurve

Implements initialization for the interpolation curve, which is used to create an interpolation curve based on the input parameter.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type           | Mandatory | Description                               |
| ------ | --------------- | ---- | ----------------------------------- |
| curve  | [Curve](#curve) | No  | Curve type.<br>Default value: **Curve.Linear** |

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | Interpolation curve. |

## Curve

Defines an interpolation curve. For details about the animation, see <!--RP1-->[Bezier Curve](../../../design/ux-design/animation-attributes.md)<!--RP1End-->.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Linear              | The animation speed keeps unchanged.                          |
| Ease                | The animation starts at a low speed and then accelerates. It slows down before the animation ends. **cubic-bezier(0.25, 0.1, 0.25, 1.0)** |
| EaseIn              | The animation starts at a low speed and then picks up speed until the end. The cubic-bezier curve (0.42, 0.0, 1.0, 1.0) is used.      |
| EaseOut             | The animation ends at a low speed. The cubic-bezier curve (0.0, 0.0, 0.58, 1.0) is used.      |
| EaseInOut           | The animation starts and ends at a low speed. The cubic-bezier curve (0.42, 0.0, 0.58, 1.0) is used. |
| FastOutSlowIn       | The animation uses the standard cubic-bezier curve (0.4, 0.0, 0.2, 1.0).                |
| LinearOutSlowIn     | The animation uses the deceleration cubic-bezier curve (0.0, 0.0, 0.2, 1.0).                |
| FastOutLinearIn     | The animation uses the acceleration cubic-bezier curve (0.4, 0.0, 1.0, 1.0).                |
| ExtremeDeceleration | The animation uses the extreme deceleration cubic-bezier curve (0.0, 0.0, 0.0, 1.0).                |
| Sharp               | The animation uses the sharp cubic-bezier curve (0.33, 0.0, 0.67, 1.0).              |
| Rhythm              | The animation uses the rhythm cubic-bezier curve (0.7, 0.0, 0.2, 1.0).                |
| Smooth              | The animation uses the smooth cubic-bezier curve (0.4, 0.0, 0.4, 1.0).                |
| Friction            | The animation uses the damping cubic-bezier curve (0.2, 0.0, 0.2, 1.0).                 |

**Example**

```ts
import { curves } from '@kit.ArkUI';
curves.initCurve(Curve.EaseIn) // Create a default ease-in curve, where the interpolation starts slowly and then picks up speed.
```


##  Curves.stepsCurve<sup>9+</sup>

stepsCurve(count: number, end: boolean): ICurve

Creates a step curve.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory | Description                                                        |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | Yes  | Number of steps. The value must be a positive integer.<br>Value range: [1, +∞)<br>**NOTE**<br>A value less than 1 evaluates to the value **1**. |
| end    | boolean | Yes  | Whether jumping occurs when the interpolation ends.<br>- **true**: Jumping occurs when the interpolation ends.<br>- **false**: Jumping occurs when the interpolation starts. |

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | Interpolation curve. |

**Example**

```ts
import { curves } from '@kit.ArkUI';
curves.stepsCurve(9, true)  // Create a step curve.
```


## Curves.cubicBezierCurve<sup>9+</sup>

cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve

Creates a cubic Bezier curve. The curve values must be between 0 and 1.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| x1     | number | Yes  | X coordinate of the first point on the Bezier curve.<br>Value range: [0, 1]<br>**NOTE**<br>A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**. |
| y1     | number | Yes  | Y coordinate of the first point on the Bezier curve.<br>Value range: (-∞, +∞)         |
| x2     | number | Yes  | X coordinate of the second point on the Bezier curve.<br>Value range: [0, 1]<br>**NOTE**<br>A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**. |
| y2     | number | Yes  | Y coordinate of the second point on the Bezier curve.<br>Value range: (-∞, +∞)         |

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | Interpolation curve. |


**Example**

```ts
import { curves } from '@kit.ArkUI';
curves.cubicBezierCurve(0.1, 0.0, 0.1, 1.0) // Create a cubic Bezier curve.
```


##  Curves.springCurve<sup>9+</sup>

springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve

Creates a spring curve. The curve shape is subject to the spring parameters, and the animation duration is subject to the **duration** parameter in **animation** and **animateTo**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name   | Type  | Mandatory | Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| velocity  | number | Yes  | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. The velocity is the normalized velocity, and its value is equal to the actual velocity at the beginning of the animation divided by the animation attribute change value.<br>Value range: (-∞, +∞) |
| mass      | number | Yes  | Mass, which influences the inertia in the spring system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the value **1** is used. |
| stiffness | number | Yes  | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the value **1** is used. |
| damping   | number | Yes  | Damping. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the value **1** is used. |


**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | Interpolation curve. |


**Example**

```ts
import { curves } from '@kit.ArkUI';
curves.springCurve(10, 1, 228, 30) // Create a spring curve.
```


##  Curves.springMotion<sup>9+</sup>

springMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve

Creates a spring animation curve. If multiple spring animations are applied to the same attribute of an object, each animation replaces their predecessor and inherits the velocity.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| response  | number | No   | Duration of one complete oscillation.<br>Default value: **0.55**<br>Unit: second<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the default value **0.55** is used. |
| dampingFraction      | number | No   | Damping coefficient.<br>**0**: undamped. In this case, the spring oscillates forever.<br>> 0 and < 1: underdamped. In this case, the spring overshoots the equilibrium position.<br>**1**: critically damped.<br>> 1: overdamped. In this case, the spring approaches equilibrium gradually.<br>Default value: **0.825**<br>Unit: second<br>Value range: [0, +∞)<br>**NOTE**<br>A value less than 0 evaluates to the default value **0.825**. |
| overlapDuration | number | No   | Duration for animations to overlap, in seconds. When animations overlap, the **response** values of these animations will transit smoothly over this duration if they are different.<br>Default value: **0**<br>Unit: second<br>Value range: [0, +∞)<br> **NOTE**<br>A value less than 0 evaluates to the default value **0**.<br>The spring animation curve is physics-based. Its duration depends on the **springMotion** parameters and the previous velocity, rather than the **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), or [pageTransition](arkui-ts/ts-page-transition-animation.md). The time cannot be normalized. Therefore, the interpolation cannot be obtained using the **interpolate** function of the curve. |


**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | Curve.<br>**NOTE**<br>The spring animation curve is physics-based. Its duration depends on the **springMotion** parameters and the previous velocity, rather than the **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), or [pageTransition](arkui-ts/ts-page-transition-animation.md). The time cannot be normalized. Therefore, the interpolation cannot be obtained using the [interpolate](#interpolate9) function of the curve. |

**Example**

```ts
import { curves } from '@kit.ArkUI'
curves.springMotion() // Create a spring animation curve with default settings.
curves.springMotion(0.5) // Create a spring animation curve with the specified response value.
curves.springMotion(0.5, 0.6) // Create a spring animation curve with the specified response and dampingFraction values.
curves.springMotion(0.5, 0.6, 0) // Create a spring animation curve with the specified parameter values.
```


##  Curves.responsiveSpringMotion<sup>9+</sup>

responsiveSpringMotion(response?: number, dampingFraction?: number, overlapDuration?: number): ICurve

Creates a responsive spring animation curve. It is a special case of [springMotion](#curvesspringmotion9), with the only difference in the default values. It can be used together with **springMotion**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| response  | number | No   | See **response** in **springMotion**.<br>Default value: **0.15**<br>Unit: second<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the default value **0.15** is used. |
| dampingFraction      | number | No   | See **dampingFraction** in **springMotion**.<br>Default value: **0.86**<br>Unit: second<br>Value range: [0, +∞)<br>**NOTE**<br>A value less than 0 evaluates to the default value **0.86**. |
| overlapDuration | number | No   | See **overlapDuration** in **springMotion**.<br>Default value: **0.25**<br>Unit: second<br>Value range: [0, +∞)<br>**NOTE**<br>A value less than 0 evaluates to the default value **0.25**.<br> To apply custom settings for a spring animation, you are advised to use **springMotion**. When using **responsiveSpringMotion**, you are advised to retain the default settings.<br>The duration of the responsive spring animation depends on the **responsiveSpringMotion** parameters and the previous velocity, rather than the duration parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), or [pageTransition](arkui-ts/ts-page-transition-animation.md). In addition, the interpolation cannot be obtained using the **interpolate** function of the curve. |

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | Curve.<br>**NOTE**<br>1. To apply custom settings for a spring animation, you are advised to use **springMotion**. When using **responsiveSpringMotion**, you are advised to retain the default settings.<br>2. The duration of the responsive spring animation depends on the **responsiveSpringMotion** parameters and the previous velocity, rather than the duration parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), or [pageTransition](arkui-ts/ts-page-transition-animation.md). In addition, the interpolation cannot be obtained using the [interpolate](#interpolate9) function of the curve. |

**Example**

```ts
import { curves } from '@kit.ArkUI'
curves.responsiveSpringMotion() // Create a responsive spring animation curve with default settings.
```


##  Curves.interpolatingSpring<sup>10+</sup>

interpolatingSpring(velocity: number, mass: number, stiffness: number, damping: number): ICurve

Creates an interpolating spring curve animated from 0 to 1. The actual animation value is calculated based on the curve. The animation duration is subject to the curve parameters, rather than the **duration** parameter in **animation** or **animateTo**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| velocity  | number | Yes   | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. The velocity is the normalized velocity, and its value is equal to the actual velocity at the beginning of the animation divided by the animation attribute change value.<br>Value range: (-∞, +∞) |
| mass      | number | Yes   | Mass, which influences the inertia in the spring system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the value **1** is used. |
| stiffness | number | Yes   | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the value **1** is used. |
| damping   | number | Yes   | Damping. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.<br>Value range: (0, +∞)<br>**NOTE**<br>If this parameter is set to a value less than or equal to 0, the value **1** is used. |

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
| [ICurve](#icurve9) | Curve.<br>**NOTE**<br>The spring animation curve is physics-based. Its duration depends on the **interpolatingSpring** parameters, rather than the **duration** parameter in [animation](arkui-ts/ts-animatorproperty.md), [animateTo](arkui-ts/ts-explicit-animation.md), or [pageTransition](arkui-ts/ts-page-transition-animation.md). The time cannot be normalized. Therefore, the interpolation cannot be obtained using the [interpolate](#interpolate9) function of the curve. |

**Example**

```ts
import { curves } from '@kit.ArkUI'
curves.interpolatingSpring(10, 1, 228, 30) // Create an interpolating spring curve whose duration is subject to spring parameters.
```

## Curves.customCurve<sup>10+</sup>

customCurve(interpolate: (fraction: number) => number): ICurve

Creates a custom curve.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                        | Mandatory | Description                                                        |
| ----------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| interpolate | (fraction: number) => number | Yes  | Custom interpolation callback.<br>**fraction**: input x value for interpolation when the animation starts. Value range: [0, 1]<br>The return value is the y value of the curve. Value range: [0, 1]<br>**NOTE**<br>If **fraction** is **0**, the return value **0** corresponds to the animation start point; any other return value means that the animation jumps at the start point.<br>If **fraction** is **1**, the return value **1** corresponds to the animation end point; any other return value means that the end value of the animation is not the value of the state variable, which will result in an effect of transition from that end value to the value of the state variable. |

**Return value**

| Type              | Description            |
| ------------------ | ---------------- |
| [ICurve](#icurve9) | Interpolation curve. |

**Example**

```ts
import { curves } from '@kit.ArkUI'
let interpolate = (fraction:number):number => {
  return Math.sqrt(fraction)
}
let curve = curves.customCurve(interpolate) // Create a custom interpolation curve.
```

## ICurve<sup>9+</sup>

Curve.


### interpolate<sup>9+</sup>

interpolate(fraction: number): number

Implements calculation.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory | Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| fraction | number | Yes  | Current normalized time.<br>Value range: [0, 1]<br>**NOTE**<br>A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**. |

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | Curve interpolation corresponding to the normalized time point. |

**Example**

```ts
import { curves } from '@kit.ArkUI'
let curveValue = curves.initCurve(Curve.EaseIn) // Create an ease-in curve.
let value: number = curveValue.interpolate(0.5) // Calculate the interpolation for half of the time.
```


## Curves.init<sup>(deprecated)</sup>

init(curve?: Curve): string


Implements initialization to create a curve. This API is deprecated since API version 9. You are advised to use [Curves.initCurve](#curvesinitcurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type           | Mandatory | Description                               |
| ------ | --------------- | ---- | ----------------------------------- |
| curve  | [Curve](#curve) | No  | Curve type.<br>Default value: **Curve.Linear** |


## Curves.steps<sup>(deprecated)</sup>

steps(count: number, end: boolean): string


Creates a step curve. This API is deprecated since API version 9. You are advised to use [Curves.stepsCurve](#curvesstepscurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory | Description                                                        |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | Yes  | Number of steps. The value must be a positive integer.                                  |
| end    | boolean | Yes  | Whether jumping occurs when the interpolation ends.<br>- **true**: Jumping occurs when the interpolation ends.<br>- **false**: Jumping occurs when the interpolation starts. |


## Curves.cubicBezier<sup>(deprecated)</sup>

cubicBezier(x1: number, y1: number, x2: number, y2: number): string


Creates a cubic Bezier curve. The curve value must range from 0 to 1. This API is deprecated since API version 9. You are advised to use [Curves.cubicBezierCurve](#curvescubicbeziercurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| x1   | number | Yes   | X coordinate of the first point on the Bezier curve. |
| y1   | number | Yes   | Y coordinate of the first point on the Bezier curve. |
| x2   | number | Yes   | X coordinate of the second point on the Bezier curve. |
| y2   | number | Yes   | Y coordinate of the second point on the Bezier curve. |


## Curves.spring<sup>(deprecated)</sup>

spring(velocity: number, mass: number, stiffness: number, damping: number): string


Creates a spring curve. This API is deprecated since API version 9. You are advised to use [Curves.springCurve](#curvesspringcurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| velocity  | number | Yes   | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. |
| mass      | number | Yes   | Mass, which influences the inertia in the spring system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position. |
| stiffness | number | Yes   | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position. |
| damping   | number | Yes   | Damping. It is a pure number and has no real physical meaning. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude. |

## Example

```ts
// xxx.ets
import { curves } from '@kit.ArkUI'

@Entry
@Component
struct ImageComponent {
  @State widthSize: number = 200
  @State heightSize: number = 200

  build() {
    Column() {
      Text()
        .margin({ top: 100 })
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Red)
        .onClick(() => {
          let curve = curves.cubicBezierCurve(0.25, 0.1, 0.25, 1.0);
          this.widthSize = curve.interpolate(0.5) * this.widthSize;
          this.heightSize = curve.interpolate(0.5) * this.heightSize;
        })
        .animation({ duration: 2000, curve: curves.stepsCurve(9, true) })
    }.width("100%").height("100%")
  }
}
```

![en-us_image_0000001174104410](figures/en-us_image_0000001174104410.gif)
