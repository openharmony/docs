# Interpolation Calculation

Interpolation calculation can be implemented to set the animation interpolation curve, which is used to construct the step curve, cubic Bezier curve, and spring curve objects.

> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import Curves from '@ohos.curves'
```


## Curves.initCurve<sup>9+</sup>

initCurve(curve?: Curve): ICurve


Implements initialization for the interpolation curve, which is used to create an interpolation curve object based on the input parameter.

**Parameters**

| Name| Type                                                        | Mandatory| Default Value      | Description      |
| ------ | ------------------------------------------------------------ | ---- | ------------ | ---------- |
| curve  | [Curve](#curve-enums)| No  | Curve.Linear | Curve type.|

**Return value**

| Type                          | Description            |
| ---------------------------------- | ---------------- |
|  [ICurve](#icurve) | Interpolation object of the curve.|


**Example**

```ts
import Curves from '@ohos.curves'
Curves.initCurve(Curve.EaseIn) // Create an ease-in curve.
```


##  Curves.stepsCurve<sup>9+</sup>

stepsCurve(count: number, end: boolean): ICurve


Constructs a step curve object.

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | Yes  | Number of steps. Must be a positive integer.                                  |
| end    | boolean | Yes  | Whether the step change occurs at the start or end point of each interval.<br>- **true**: The step change occurs at the end point.<br>- **false**: The step change occurs at the start point.|

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


Constructs a third-order Bezier curve object. The curve value must be between 0 and 1.


**Parameters**
| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| x1   | number | Yes   | Horizontal coordinate of the first point on the Bezier curve.|
| y1   | number | Yes   | Vertical coordinate of the first point on the Bezier curve.|
| x2   | number | Yes   | Horizontal coordinate of the second point on the Bezier curve.|
| y2   | number | Yes   | Vertical coordinate of the second point on the Bezier curve.|

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


**Parameters**
| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| velocity  | number | Yes   | Initial velocity. It is a parameter that affects the elastic dynamic effect by external factors. It aims to ensure the smooth transition from the previous motion state to the elastic dynamic effect.|
| mass      | number | Yes   | Quality. The force object of the elastic system will have inertia effects on the elastic system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.|
| stiffness | number | Yes   | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.|
| damping   | number | Yes   | Damping. It is a pure number and has no real physical meaning. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion and the smaller the oscillation amplitude.|


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


Calculation function of the interpolation curve. Passing a normalized time parameter to this function returns the current interpolation.

**Parameters**

| Name  | Type  | Mandatory| Description                                        |
| -------- | ------ | ---- | -------------------------------------------- |
| fraction | number | Yes  | Current normalized time. The value ranges from 0 to 1.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | The curve interpolation corresponding to the normalized time point is returned.|

**Example**

```ts
import Curves from '@ohos.curves'
let curve = Curves.initCurve(Curve.EaseIn) // Create an ease-in curve.
let value: number = curve.interpolate(0.5) // Calculate the interpolation for half of the time.
```


## Curves.init<sup>(deprecated)</sup>

init(curve?: Curve): string


Implements initialization to create a curve object based on the input parameter. This API is deprecated since API version 9. Use [Curves.initCurve](#curvesinitcurve9) instead.

**Parameters**

| Name| Type                                                        | Mandatory| Default Value      | Description      |
| ------ | ------------------------------------------------------------ | ---- | ------------ | ---------- |
| curve  |[Curve](#curve-enums)| No  | Curve.Linear | Curve type.|


## Curves.steps<sup>(deprecated)</sup>

steps(count: number, end: boolean): string


Constructs a step curve object. This API is deprecated since API version 9. Use [Curves.stepsCurve](# curvesstepscurve9) instead.

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ----| ------------------------------------------------------------ |
| count  | number  | Yes  | Number of steps. Must be a positive integer.                                  |
| end    | boolean | Yes  | Whether the step change occurs at the start or end of each interval.<br>- **true**: The step change occurs at the end point.<br>- **false**: The step change occurs at the start point.|


## Curves.cubicBezier<sup>(deprecated)</sup>

cubicBezier(x1: number, y1: number, x2: number, y2: number): string


Constructs a cubic Bezier curve object. The curve value must range from 0 to 1. This API is deprecated since API version 9. Use [Curves.cubicBezierCurve](#curvescubicbeziercurve9) instead.


**Parameters**
| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| x1   | number | Yes   | Horizontal coordinate of the first point on the Bezier curve.|
| y1   | number | Yes   | Vertical coordinate of the first point on the Bezier curve.|
| x2   | number | Yes   | Horizontal coordinate of the second point on the Bezier curve.|
| y2   | number | Yes   | Vertical coordinate of the second point on the Bezier curve.|


## Curves.spring<sup>(deprecated)</sup>

spring(velocity: number, mass: number, stiffness: number, damping: number): string


Constructs a spring curve object. This API is deprecated since API version 9. Use [Curves.cubicBezierCurve](#curvescubicbeziercurve9) instead.

**Parameters**

| Name      | Type    | Mandatory  | Description   |
| --------- | ------ | ---- | ----- |
| velocity  | number | Yes   | Initial velocity. It is a parameter that affects the elastic dynamic effect by external factors. It aims to ensure the smooth transition from the previous motion state to the elastic dynamic effect.|
| mass      | number | Yes   | Quality. The force object of the elastic system will have inertia effects on the elastic system. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.|
| stiffness | number | Yes   | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.|
| damping   | number | Yes   | Damping. It is a pure number and has no real physical meaning. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion and the smaller the oscillation amplitude.|


## Curve

| Name                 | Description                                      |
| ------------------- | ---------------------------------------- |
| Linear              | The animation speed keeps unchanged.                       |
| Ease                | The animation starts slowly, accelerates, and then slows down towards the end. The cubic-bezier curve (0.25, 0.1, 0.25, 1.0) is used.|
| EaseIn              | The animation starts at a low speed and then picks up speed until the end. The cubic-bezier curve (0.42, 0.0, 1.0, 1.0) is used.|
| EaseOut             | The animation ends at a low speed. The cubic-bezier curve (0.0, 0.0, 0.58, 1.0) is used.|
| EaseInOut           | The animation starts and ends at a low speed. The cubic-bezier curve (0.42, 0.0, 0.58, 1.0) is used.|
| FastOutSlowIn       | The animation uses the standard cubic-bezier curve (0.4, 0.0, 0.2, 1.0).|
| LinearOutSlowIn     | The animation uses the deceleration cubic-bezier curve (0.0, 0.0, 0.2, 1.0).|
| FastOutLinearIn     | The animation uses the acceleration cubic-bezier curve (0.4, 0.0, 1.0, 1.0).|
| ExtremeDeceleration | The animation uses the extreme deceleration cubic-bezier curve (0.0, 0.0, 0.0, 1.0).|
| Sharp               | The animation uses the sharp cubic-bezier curve (0.33, 0.0, 0.67, 1.0).|
| Rhythm              | The animation uses the rhythm cubic-bezier curve (0.7, 0.0, 0.2, 1.0).|
| Smooth              | The animation uses the smooth cubic-bezier curve (0.4, 0.0, 0.4, 1.0).|
| Friction            | The animation uses the friction cubic-bezier curve (0.2, 0.0, 0.2, 1.0).|


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
![en-us_image_0000001212058456](figures/en-us_image_0000001212058456.gif)
