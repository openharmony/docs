# Interpolation Calculation

The **Curves** module provides APIs for interpolation calculation to construct step, cubic Bezier, and spring curve objects.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import Curves from '@ohos.curves'
```


## Curves.initCurve<sup>9+</sup>

initCurve(curve?: Curve): ICurve


Implements initialization for the interpolation curve, which is used to create an interpolation curve object based on the input parameter.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Default Value      | Description      |
| ------ | ------------------------------------------------------------ | ---- | ------------ | ---------- |
| curve  | [Curve](../arkui-ts/ts-appendix-enums.md#curve) | No  | Curve.Linear | Curve type.|

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
|  [ICurve](#icurve) | Curve object.|


**Example**

```ts
import Curves from '@ohos.curves'
Curves.initCurve(Curve.EaseIn) // Create a default ease-in curve, where the interpolation starts slowly and then picks up speed.
```


##  Curves.stepsCurve<sup>9+</sup>

stepsCurve(count: number, end: boolean): ICurve


Constructs a step curve object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | Yes  | Number of steps. The value must be a positive integer.                                  |
| end    | boolean | Yes  | Whether jumping occurs when the interpolation ends.<br>- **true**: Jumping occurs when the interpolation ends.<br>- **false**: Jumping occurs when the interpolation starts.|

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
|  [ICurve](#icurve) | Curve object.|


**Example**

```ts
import Curves from '@ohos.curves'
Curves.stepsCurve(9, true) // Create a step curve.
```


## Curves.cubicBezierCurve<sup>9+</sup>

cubicBezierCurve(x1: number, y1: number, x2: number, y2: number): ICurve


Constructs a cubic Bezier curve object. The curve values must be between 0 and 1.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| x1   | number | Yes   | X coordinate of the first point on the Bezier curve.|
| y1   | number | Yes   | Y coordinate of the first point on the Bezier curve.|
| x2   | number | Yes   | X coordinate of the second point on the Bezier curve.|
| y2   | number | Yes   | Y coordinate of the second point on the Bezier curve.|

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
|  [ICurve](#icurve) | Curve object.|


**Example**

```ts
import Curves from '@ohos.curves'
Curves.cubicBezierCurve(0.1, 0.0, 0.1, 1.0) // Create a cubic Bezier curve.
```


##  Curves.springCurve<sup>9+</sup>

springCurve(velocity: number, mass: number, stiffness: number, damping: number): ICurve


Constructs a spring curve object.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| velocity  | number | Yes   | Initial velocity. It is applied by external factors to the elastic animation. It aims to help ensure the smooth transition from the previous motion state to the elastic animation.|
| mass      | number | Yes   | Mass. Force object of the elastic system, which will have inertia effect on the elastic system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.|
| stiffness | number | Yes   | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.|
| damping   | number | Yes   | Damping. It is a pure number and has no real physical meaning. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.|


**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
|  [ICurve](#icurve)| Curve object.|


**Example**

```ts
import Curves from '@ohos.curves'
Curves.springCurve(100, 1, 228, 30) // Create a spring curve.
```


## ICurve


### interpolate

interpolate(fraction: number): number


Implements calculation.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                                        |
| -------- | ------ | ---- | -------------------------------------------- |
| fraction | number | Yes  | Current normalized time. The value ranges from 0 to 1.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | Curve interpolation corresponding to the normalized time point.|

**Example**

```ts
import Curves from '@ohos.curves'
let curve = Curves.initCurve(Curve.EaseIn) // Create an ease-in curve.
let value: number = curve.interpolate(0.5) // Calculate the interpolation for half of the time.
```


## Curves.init<sup>(deprecated)</sup>

init(curve?: Curve): string


Implements initialization to create a curve. This API is deprecated since API version 9. You are advised to use [Curves.initCurve](#curvesinitcurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Default Value      | Description      |
| ------ | ------------------------------------------------------------ | ---- | ------------ | ---------- |
| curve  |[Curve](../arkui-ts/ts-appendix-enums.md#curve) | No  | Curve.Linear | Curve type.|


## Curves.steps<sup>(deprecated)</sup>

steps(count: number, end: boolean): string


Constructs a step curve object. This API is deprecated since API version 9. You are advised to use [Curves.stepsCurve](#curvesstepscurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | Yes  | Number of steps. The value must be a positive integer.                                  |
| end    | boolean | Yes  | Whether jumping occurs when the interpolation ends.<br>- **true**: Jumping occurs when the interpolation ends.<br>- **false**: Jumping occurs when the interpolation starts.|


## Curves.cubicBezier<sup>(deprecated)</sup>

cubicBezier(x1: number, y1: number, x2: number, y2: number): string


Constructs a cubic Bezier curve object. The curve value must range from 0 to 1. This API is deprecated since API version 9. You are advised to use [Curves.cubicBezierCurve](#curvescubicbeziercurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| x1   | number | Yes   | X coordinate of the first point on the Bezier curve.|
| y1   | number | Yes   | Y coordinate of the first point on the Bezier curve.|
| x2   | number | Yes   | X coordinate of the second point on the Bezier curve.|
| y2   | number | Yes   | Y coordinate of the second point on the Bezier curve.|


## Curves.spring<sup>(deprecated)</sup>

spring(velocity: number, mass: number, stiffness: number, damping: number): string


Constructs a spring curve object. This API is deprecated since API version 9. You are advised to use [Curves.springCurve](#curvesspringcurve9) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| velocity  | number | Yes   | Initial velocity. It is applied by external factors to the elastic animation. It aims to help ensure the smooth transition from the previous motion state to the elastic animation.|
| mass      | number | Yes   | Mass. Force object of the elastic system, which will have inertia effect on the elastic system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.|
| stiffness | number | Yes   | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.|
| damping   | number | Yes   | Damping. It is a pure number and has no real physical meaning. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.|

## Example

```ts
// xxx.ets
import Curves from '@ohos.curves'
@Entry
@Component
struct ImageComponent {
  @State widthSize: number = 200
  @State heightSize: number = 200

  build() {
    Column() {
      Text()
        .margin({top:100})
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Red)
        .onClick(()=> {
          let curve = Curves.cubicBezierCurve(0.25, 0.1, 0.25, 1.0);
          this.widthSize = curve.interpolate(0.5) * this.widthSize;
          this.heightSize = curve.interpolate(0.5) * this.heightSize;
        })
        .animation({duration: 2000 , curve: Curves.stepsCurve(9, true)})
    }.width("100%").height("100%")
  }
}
```

![en-us_image_0000001174104410](figures/en-us_image_0000001174104410.gif)
