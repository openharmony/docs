# Types
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - For the system capability SystemCapability.Window.SessionManager, use [canIUse()](../common/js-apis-syscap.md#caniuse) to check whether the device supports this system capability and the corresponding APIs.

## SpecificSystemBar<sup>11+</sup>

type SpecificSystemBar = 'status' \| 'navigation' \| 'navigationIndicator'

Defines the type of system bar that can be displayed or hidden.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type      | Description    |
|------------|--------|
| 'status'   | Status bar.  |
| 'navigation'   | <!--RP13--><!--RP13End-->Three-button navigation bar.  |
| 'navigationIndicator'   | Bottom navigation bar. <!--RP12-->OpenHarmony devices do not support this capability.<!--RP12End--> |

## WindowAnimationCurveParam<sup>20+</sup>

type WindowAnimationCurveParam = Array&lt;number&gt;

Defines the parameters for the animation curve. The meaning of **WindowAnimationCurveParam** varies depending on the type of [WindowAnimationCurve](arkts-apis-window-e.md#windowanimationcurve20).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Type     | Description                         |
| -----------| ---------------------------- |
| Array&lt;number&gt;    | An array of numbers. The range of values for each element depends on the specific curve type.    |

When the curve type is **LINEAR**, **WindowAnimationCurveParam** is optional and have no effect.

When the curve type is **INTERPOLATION_SPRING**, **WindowAnimationCurveParam** must be set as an array of length 4: [velocity,mass,stiffness,damping].

- **velocity**: initial velocity, which is of the number type. This parameter is mandatory. The value range is (-∞, +∞).

  It describes the impact of external factors to the spring animation, designed to help ensure smooth transition from the previous motion state. This is a normalized velocity, and it is calculated as the actual initial velocity divided by the change in the animation property.

- **mass**: mass, which is of the number type. This parameter is mandatory. The value range is (0, +∞). If the value is less than or equal to 0, the value **1** is used.

  It describes the inertia of the object in the elastic system, affecting the amplitude of oscillation and the speed of return to equilibrium. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.

- **stiffness**: stiffness, which is of the number type. This parameter is mandatory. The value range is (0, +∞). If the value is less than or equal to 0, the value **1** is used.

  It describes the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the capability to resist deformation, and the faster the speed of restoring to the equilibrium position.

- **damping**: damping, which is of the number type. This parameter is mandatory. The value range is (0, +∞). If the value is less than or equal to 0, the value **1** is used.

  It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.

When the curve type is **CUBIC_BEZIER**, **WindowAnimationCurveParam** must be set as an array of length 4: [x1, y1, x2, y2].

- x1: horizontal coordinate of the first point of the Bezier curve. It is of the number type, mandatory, with a range of [0, 1]. Values less than 0 are treated as 0, and values greater than 1 are treated as 1.

- y1: vertical coordinate of the first point of the Bezier curve. It is of the number type, mandatory, with a range of (-∞, +∞).

- x2: horizontal coordinate of the second point of the Bezier curve. It is of the number type, mandatory, with a range of [0, 1]. Values less than 0 are treated as 0, and values greater than 1 are treated as 1.

- y2: vertical coordinate of the second point of the Bezier curve. It is of the number type, mandatory, with a range of (-∞, +∞).

## RotationChangeCallback<sup>19+</sup>

type RotationChangeCallback&lt;T, U&gt; = (info: T) => U

Describes a generic callback function for rotation event notifications.

In this callback function, the parameter type is [RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19), and the return value type is [RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19) \| void.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | -------------------------- |
| info | T    | Yes  | Rotation event information. The system passes a parameter of the [RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19) type to notify you of the window information when a rotation change occurs.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------ |
| U | A value of the [RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19) or void type, which is used to specify the window position after rotation. When void is returned, the system does not change the window position.|

## WindowEventListener

type WindowEventListener = (windowId: number, event: window.WindowEventType) => void

Callback function for window lifecycle event notifications.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | ---- | ------------------ |
| windowId | number  | Yes | ID of the window whose lifecycle changes.|
| event | window.[WindowEventType](arkts-apis-window-e.md#windoweventtype10)  | Yes| Window lifecycle event type.|
