# native_animate.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a set of animation APIs of ArkUI on the native side.

**File to include**: <arkui/native_animate.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md) | ArkUI_ExpectedFrameRateRange | Defines a struct for the expected frame rate range of the animation.|
| [ArkUI_AnimateCompleteCallback](capi-arkui-nativemodule-arkui-animatecompletecallback.md) | ArkUI_AnimateCompleteCallback | Defines a struct for the callback type for when the animation playback is complete.|
| [ArkUI_NativeAnimateAPI_1](capi-arkui-nativemodule-arkui-nativeanimateapi-1.md) | ArkUI_NativeAnimateAPI_1 | Defines a struct for the animation APIs of ArkUI on the native side.|
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md) | ArkUI_AnimateOption | Animation settings.|
| [ArkUI_Curve](capi-arkui-nativemodule-arkui-curve.md) | ArkUI_Curve | Defines an interpolation curve.|
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | ArkUI_Curve* | Defines a struct for the pointer to an interpolation curve.|
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md) | ArkUI_KeyframeAnimateOption | Defines the keyframe animation parameter object.|
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md) | ArkUI_AnimatorOption | Defines the animator parameter object.|
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) | ArkUI_Animator* | Defines the pointer to an animator object.|
| [ArkUI_AnimatorEvent](capi-arkui-nativemodule-arkui-animatorevent.md) | ArkUI_AnimatorEvent | Defines the animator callback event object.|
| [ArkUI_AnimatorOnFrameEvent](capi-arkui-nativemodule-arkui-animatoronframeevent.md) | ArkUI_AnimatorOnFrameEvent | Defines the callback object when the animator receives a frame.|
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md) | ArkUI_TransitionEffect | Defines the transition effect.|

### Callback

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create()](#oh_arkui_animateoption_create) | Creates an animation configuration.|
| [void OH_ArkUI_AnimateOption_Dispose(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_dispose) | Disposes of an animation configuration.|
| [uint32_t OH_ArkUI_AnimateOption_GetDuration(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getduration) | Obtains the animation duration, in milliseconds.|
| [float OH_ArkUI_AnimateOption_GetTempo(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_gettempo) | Obtains the playback speed of an animation.|
| [ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getcurve) | Obtains an animation curve.|
| [int32_t OH_ArkUI_AnimateOption_GetDelay(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getdelay) | Obtains the animation delay, in milliseconds.|
| [int32_t OH_ArkUI_AnimateOption_GetIterations(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getiterations) | Obtains the number of times that an animation is played.|
| [ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getplaymode) | Obtains the playback mode of an animation.|
| [ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimateOption_GetExpectedFrameRateRange(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getexpectedframeraterange) | Obtains the expected frame rate range of an animation.|
| [void OH_ArkUI_AnimateOption_SetDuration(ArkUI_AnimateOption* option, int32_t value)](#oh_arkui_animateoption_setduration) | Sets the animation duration.|
| [void OH_ArkUI_AnimateOption_SetTempo(ArkUI_AnimateOption* option, float value)](#oh_arkui_animateoption_settempo) | Sets the playback speed of an animation.|
| [void OH_ArkUI_AnimateOption_SetCurve(ArkUI_AnimateOption* option, ArkUI_AnimationCurve value)](#oh_arkui_animateoption_setcurve) | Animation curve.|
| [void OH_ArkUI_AnimateOption_SetDelay(ArkUI_AnimateOption* option, int32_t value)](#oh_arkui_animateoption_setdelay) | Sets the animation delay.|
| [void OH_ArkUI_AnimateOption_SetIterations(ArkUI_AnimateOption* option, int32_t value)](#oh_arkui_animateoption_setiterations) | Sets the number of times that an animation is played.|
| [void OH_ArkUI_AnimateOption_SetPlayMode(ArkUI_AnimateOption* option, ArkUI_AnimationPlayMode value)](#oh_arkui_animateoption_setplaymode) | Sets the playback mode for an animation.|
| [void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange(ArkUI_AnimateOption* option, ArkUI_ExpectedFrameRateRange* value)](#oh_arkui_animateoption_setexpectedframeraterange) | Defines a struct for the expected frame rate range of the animation.|
| [void OH_ArkUI_AnimateOption_SetICurve(ArkUI_AnimateOption* option, ArkUI_CurveHandle value)](#oh_arkui_animateoption_seticurve) | Sets the animation curve for an animation.|
| [ArkUI_CurveHandle OH_ArkUI_AnimateOption_GetICurve(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_geticurve) | Obtains the animation curve of an animation.|
| [ArkUI_KeyframeAnimateOption* OH_ArkUI_KeyframeAnimateOption_Create(int32_t size)](#oh_arkui_keyframeanimateoption_create) | Obtains the keyframe animation parameters.|
| [void OH_ArkUI_KeyframeAnimateOption_Dispose(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_dispose) | Disposes of a keyframe animation parameter object.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetDelay(ArkUI_KeyframeAnimateOption* option, int32_t value)](#oh_arkui_keyframeanimateoption_setdelay) | Sets the overall delay of a keyframe animation, in milliseconds. By default, the keyframe animation is played without delay.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetIterations(ArkUI_KeyframeAnimateOption* option, int32_t value)](#oh_arkui_keyframeanimateoption_setiterations) | Sets the number of times that the keyframe animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. The value **0** indicates that there is no animation.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (\*onFinish)(void* userData))](#oh_arkui_keyframeanimateoption_registeronfinishcallback) | Sets the callback invoked when the keyframe animation playback is complete. This API is called after the keyframe animation has played for the specified number of times.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option, ArkUI_ExpectedFrameRateRange* frameRate)](#oh_arkui_keyframeanimateoption_setexpectedframerate) | Sets the expected frame rate for a keyframe animation.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetDuration(ArkUI_KeyframeAnimateOption* option, int32_t value, int32_t index)](#oh_arkui_keyframeanimateoption_setduration) | Sets the duration of a keyframe animation, in milliseconds.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetCurve(ArkUI_KeyframeAnimateOption* option, ArkUI_CurveHandle value, int32_t index)](#oh_arkui_keyframeanimateoption_setcurve) | Sets the animation curve for a specific keyframe in a keyframe animation.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (\*event)(void* userData), int32_t index)](#oh_arkui_keyframeanimateoption_registeroneventcallback) | Sets the closure function of the state at the time of the keyframe, that is, the state to be reached at the time of the keyframe.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_GetDelay(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_getdelay) | Obtains the overall delay of a keyframe animation|
| [int32_t OH_ArkUI_KeyframeAnimateOption_GetIterations(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_getiterations) | Obtains the number of times that a keyframe animation is played.|
| [ArkUI_ExpectedFrameRateRange* OH_ArkUI_KeyframeAnimateOption_GetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_getexpectedframerate) | Obtains the expected frame rate from keyframe animation parameters.|
| [int32_t OH_ArkUI_KeyframeAnimateOption_GetDuration(ArkUI_KeyframeAnimateOption* option, int32_t index)](#oh_arkui_keyframeanimateoption_getduration) | Obtains the duration of a specific state in a keyframe animation.|
| [ArkUI_CurveHandle OH_ArkUI_KeyframeAnimateOption_GetCurve(ArkUI_KeyframeAnimateOption* option, int32_t index)](#oh_arkui_keyframeanimateoption_getcurve) | Obtains the animation curve of a specific state in a keyframe animation.|
| [ArkUI_AnimatorOption* OH_ArkUI_AnimatorOption_Create(int32_t keyframeSize)](#oh_arkui_animatoroption_create) | Creates an **AnimatorOption** object.|
| [void OH_ArkUI_AnimatorOption_Dispose(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_dispose) | Disposes of an **AnimatorOption** object.|
| [int32_t OH_ArkUI_AnimatorOption_SetDuration(ArkUI_AnimatorOption* option, int32_t value)](#oh_arkui_animatoroption_setduration) | Sets the duration of an animation, in milliseconds.|
| [int32_t OH_ArkUI_AnimatorOption_SetDelay(ArkUI_AnimatorOption* option, int32_t value)](#oh_arkui_animatoroption_setdelay) | Sets the delay of animation playback, in milliseconds.|
| [int32_t OH_ArkUI_AnimatorOption_SetIterations(ArkUI_AnimatorOption* option, int32_t value)](#oh_arkui_animatoroption_setiterations) | Sets the number of times that an animation is played. The value **0** means not to play the animation, and **-1** means to play the animation for an unlimited number of times.|
| [int32_t OH_ArkUI_AnimatorOption_SetFill(ArkUI_AnimatorOption* option, ArkUI_AnimationFillMode value)](#oh_arkui_animatoroption_setfill) | Sets whether the animator animation is restored to the initial state after being executed.|
| [int32_t OH_ArkUI_AnimatorOption_SetDirection(ArkUI_AnimatorOption* option, ArkUI_AnimationDirection value)](#oh_arkui_animatoroption_setdirection) | Set the playback direction.|
| [int32_t OH_ArkUI_AnimatorOption_SetCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value)](#oh_arkui_animatoroption_setcurve) | Sets the interpolation curve for the animation of an animator.|
| [int32_t OH_ArkUI_AnimatorOption_SetBegin(ArkUI_AnimatorOption* option, float value)](#oh_arkui_animatoroption_setbegin) | Sets the interpolation start point of an animation.|
| [int32_t OH_ArkUI_AnimatorOption_SetEnd(ArkUI_AnimatorOption* option, float value)](#oh_arkui_animatoroption_setend) | Sets the interpolation end point for the animation of an animator.|
| [int32_t OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange(ArkUI_AnimatorOption* option, ArkUI_ExpectedFrameRateRange* value)](#oh_arkui_animatoroption_setexpectedframeraterange) | Sets the expected frame rate range of an animation.|
| [int32_t OH_ArkUI_AnimatorOption_SetKeyframe(ArkUI_AnimatorOption* option, float time, float value, int32_t index)](#oh_arkui_animatoroption_setkeyframe) | Sets the keyframe parameters of an animation.|
| [int32_t OH_ArkUI_AnimatorOption_SetKeyframeCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value, int32_t index)](#oh_arkui_animatoroption_setkeyframecurve) | Sets the keyframe curve type for the animation of an animator.|
| [int32_t OH_ArkUI_AnimatorOption_GetDuration(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getduration) | Obtains the duration for playing an animation.|
| [int32_t OH_ArkUI_AnimatorOption_GetDelay(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getdelay) | Obtains the delay for playing an animation.|
| [int32_t OH_ArkUI_AnimatorOption_GetIterations(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getiterations) | Obtains the number of times that an animation is played.|
| [ArkUI_AnimationFillMode OH_ArkUI_AnimatorOption_GetFill(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getfill) | Obtains whether the animator animation is restored to the initial state after being executed.|
| [ArkUI_AnimationDirection OH_ArkUI_AnimatorOption_GetDirection(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getdirection) | Obtains the playback direction of an animation.|
| [ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetCurve(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getcurve) | Obtains the interpolation curve of the animation of an animator.|
| [float OH_ArkUI_AnimatorOption_GetBegin(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getbegin) | Obtains the interpolation start point of an animation.|
| [float OH_ArkUI_AnimatorOption_GetEnd(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getend) | Obtains the interpolation end point of an animation.|
| [ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getexpectedframeraterange) | Obtains the expected frame rate range of an animation.|
| [float OH_ArkUI_AnimatorOption_GetKeyframeTime(ArkUI_AnimatorOption* option, int32_t index)](#oh_arkui_animatoroption_getkeyframetime) | Obtains the keyframe time of an animation.|
| [float OH_ArkUI_AnimatorOption_GetKeyframeValue(ArkUI_AnimatorOption* option, int32_t index)](#oh_arkui_animatoroption_getkeyframevalue) | Obtains the keyframe value of an animation.|
| [ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetKeyframeCurve(ArkUI_AnimatorOption* option, int32_t index)](#oh_arkui_animatoroption_getkeyframecurve) | Obtains the interpolation curve for a keyframe in the animation of an animator.|
| [void* OH_ArkUI_AnimatorEvent_GetUserData(ArkUI_AnimatorEvent* event)](#oh_arkui_animatorevent_getuserdata) | Obtains the custom object in an animation event object.|
| [void* OH_ArkUI_AnimatorOnFrameEvent_GetUserData(ArkUI_AnimatorOnFrameEvent* event)](#oh_arkui_animatoronframeevent_getuserdata) | Obtains the custom object in an animation event object.|
| [float OH_ArkUI_AnimatorOnFrameEvent_GetValue(ArkUI_AnimatorOnFrameEvent* event)](#oh_arkui_animatoronframeevent_getvalue) | Obtains the current progress in an animation event object.|
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnFrameCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorOnFrameEvent* event))](#oh_arkui_animatoroption_registeronframecallback) | Sets the callback invoked when the animator receives a frame.|
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnFinishCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorEvent* event))](#oh_arkui_animatoroption_registeronfinishcallback) | Sets the callback invoked when the animation playback is complete.|
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnCancelCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorEvent* event))](#oh_arkui_animatoroption_registeroncancelcallback) | Sets the callback invoked when the animation playback is canceled.|
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorEvent* event))](#oh_arkui_animatoroption_registeronrepeatcallback) | Sets the callback invoked when the animation playback is repeated.|
| [int32_t OH_ArkUI_Animator_ResetAnimatorOption(ArkUI_AnimatorHandle animatorHandle, ArkUI_AnimatorOption* option)](#oh_arkui_animator_resetanimatoroption) | Resets an animator configuration.|
| [int32_t OH_ArkUI_Animator_Play(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_play) | Starts the animation of an animator.|
| [int32_t OH_ArkUI_Animator_Finish(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_finish) | Ends the animation of an animator.|
| [int32_t OH_ArkUI_Animator_Pause(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_pause) | Pauses the animation of an animator.|
| [int32_t OH_ArkUI_Animator_Cancel(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_cancel) | Cancels the animation of an animator.|
| [int32_t OH_ArkUI_Animator_Reverse(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_reverse) | Plays this animation in reverse order.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateCurveByType(ArkUI_AnimationCurve curve)](#oh_arkui_curve_createcurvebytype) | Implements initialization for the interpolation curve, which is used to create an interpolation curve based on the input parameter.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateStepsCurve(int32_t count, bool end)](#oh_arkui_curve_createstepscurve) | Creates a step curve.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateCubicBezierCurve(float x1, float y1, float x2, float y2)](#oh_arkui_curve_createcubicbeziercurve) | Creates a cubic Bezier curve.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringCurve(float velocity, float mass, float stiffness, float damping)](#oh_arkui_curve_createspringcurve) | Creates a spring curve. The curve shape is subject to the spring parameters, and the animation duration is subject to the **duration** parameter in **animation** and **animateTo**.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringMotion(float response, float dampingFraction, float overlapDuration)](#oh_arkui_curve_createspringmotion) | Creates a spring animation curve. If multiple spring animations are applied to the same attribute of an object, each animation replaces their predecessor and inherits the velocity.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateResponsiveSpringMotion(float response, float dampingFraction, float overlapDuration)](#oh_arkui_curve_createresponsivespringmotion) | Creates a responsive spring animation curve. It is a special case of **springMotion**, with the only difference in the default values. It can be used together with **springMotion**.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateInterpolatingSpring(float velocity, float mass, float stiffness, float damping)](#oh_arkui_curve_createinterpolatingspring) | Creates an interpolating spring curve animated from 0 to 1. The actual animation value is calculated based on the curve.|
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateCustomCurve(void* userData, float (\*interpolate)(float fraction, void* userdata))](#oh_arkui_curve_createcustomcurve) | Creates a custom curve.|
| [void OH_ArkUI_Curve_DisposeCurve(ArkUI_CurveHandle curveHandle)](#oh_arkui_curve_disposecurve) | Disposes of a custom curve.|
| [ArkUI_TransitionEffect* OH_ArkUI_CreateOpacityTransitionEffect(float opacity)](#oh_arkui_createopacitytransitioneffect) | Creates an opacity object for component transition.|
| [ArkUI_TransitionEffect* OH_ArkUI_CreateTranslationTransitionEffect(ArkUI_TranslationOptions* translate)](#oh_arkui_createtranslationtransitioneffect) | Creates a translation object for component transition.|
| [ArkUI_TransitionEffect* OH_ArkUI_CreateScaleTransitionEffect(ArkUI_ScaleOptions* scale)](#oh_arkui_createscaletransitioneffect) | Creates a scaling object for component transition.|
| [ArkUI_TransitionEffect* OH_ArkUI_CreateRotationTransitionEffect(ArkUI_RotationOptions* rotate)](#oh_arkui_createrotationtransitioneffect) | Creates a rotation object for component transition.|
| [ArkUI_TransitionEffect* OH_ArkUI_CreateMovementTransitionEffect(ArkUI_TransitionEdge edge)](#oh_arkui_createmovementtransitioneffect) | Creates a movement object for component transition.|
| [ArkUI_TransitionEffect* OH_ArkUI_CreateAsymmetricTransitionEffect(ArkUI_TransitionEffect* appear, ArkUI_TransitionEffect* disappear)](#oh_arkui_createasymmetrictransitioneffect) | Creates an asymmetric transition effect.|
| [void OH_ArkUI_TransitionEffect_Dispose(ArkUI_TransitionEffect* effect)](#oh_arkui_transitioneffect_dispose) | Disposes of a transition effect.|
| [int32_t OH_ArkUI_TransitionEffect_Combine(ArkUI_TransitionEffect* firstEffect, ArkUI_TransitionEffect* secondEffect)](#oh_arkui_transitioneffect_combine) | Sets a combination of transition effects.|
| [int32_t OH_ArkUI_TransitionEffect_SetAnimation(ArkUI_TransitionEffect* effect, ArkUI_AnimateOption* animation)](#oh_arkui_transitioneffect_setanimation) | Sets transition effect animation settings.|

## Function Description

### OH_ArkUI_AnimateOption_Create()

```
ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create()
```

**Description**


Creates an animation configuration.

**Since**: 12

**Return value**

| Type                      | Description|
|--------------------------| -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* | Pointer to the created animation configuration.|

### OH_ArkUI_AnimateOption_Dispose()

```
void OH_ArkUI_AnimateOption_Dispose(ArkUI_AnimateOption* option)
```

**Description**


Disposes of an animation configuration.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

### OH_ArkUI_AnimateOption_GetDuration()

```
uint32_t OH_ArkUI_AnimateOption_GetDuration(ArkUI_AnimateOption* option)
```

**Description**


Obtains the animation duration, in milliseconds.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Duration.|

### OH_ArkUI_AnimateOption_GetTempo()

```
float OH_ArkUI_AnimateOption_GetTempo(ArkUI_AnimateOption* option)
```

**Description**


Obtains the playback speed of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

**Return value**

| Type| Description|
| -- | -- |
| float | Animation playback speed.|

### OH_ArkUI_AnimateOption_GetCurve()

```
ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve(ArkUI_AnimateOption* option)
```

**Description**


Obtains an animation curve.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_AnimationCurve](capi-native-type-h.md#arkui_animationcurve) | Animation curve.|

### OH_ArkUI_AnimateOption_GetDelay()

```
int32_t OH_ArkUI_AnimateOption_GetDelay(ArkUI_AnimateOption* option)
```

**Description**


Obtains the animation delay, in milliseconds.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Delay of animation playback.|

### OH_ArkUI_AnimateOption_GetIterations()

```
int32_t OH_ArkUI_AnimateOption_GetIterations(ArkUI_AnimateOption* option)
```

**Description**


Obtains the number of times that an animation is played.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Number of times that the animation is played.|

### OH_ArkUI_AnimateOption_GetPlayMode()

```
ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode(ArkUI_AnimateOption* option)
```

**Description**


Obtains the playback mode of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_AnimationPlayMode](capi-native-type-h.md#arkui_animationplaymode) | Animation playback mode.|

### OH_ArkUI_AnimateOption_GetExpectedFrameRateRange()

```
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimateOption_GetExpectedFrameRateRange(ArkUI_AnimateOption* option)
```

**Description**


Obtains the expected frame rate range of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|

**Return value**

| Type                               | Description|
|-----------------------------------| -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* | Expected frame rate range of the animation.|

### OH_ArkUI_AnimateOption_SetDuration()

```
void OH_ArkUI_AnimateOption_SetDuration(ArkUI_AnimateOption* option, int32_t value)
```

**Description**


Sets the animation duration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|
| int32_t value | Duration, in milliseconds.|

### OH_ArkUI_AnimateOption_SetTempo()

```
void OH_ArkUI_AnimateOption_SetTempo(ArkUI_AnimateOption* option, float value)
```

**Description**


Sets the playback speed of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|
| float value | Animation playback speed.|

### OH_ArkUI_AnimateOption_SetCurve()

```
void OH_ArkUI_AnimateOption_SetCurve(ArkUI_AnimateOption* option, ArkUI_AnimationCurve value)
```

**Description**


Animation curve.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|
| [ArkUI_AnimationCurve](capi-native-type-h.md#arkui_animationcurve) value | Animation curve. Default value: **ARKUI_CURVE_LINEAR**.|

### OH_ArkUI_AnimateOption_SetDelay()

```
void OH_ArkUI_AnimateOption_SetDelay(ArkUI_AnimateOption* option, int32_t value)
```

**Description**


Sets the animation delay.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|
| int32_t value | Delay of animation playback.|

### OH_ArkUI_AnimateOption_SetIterations()

```
void OH_ArkUI_AnimateOption_SetIterations(ArkUI_AnimateOption* option, int32_t value)
```

**Description**


Sets the number of times that an animation is played.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|
| int32_t value | Number of times that the animation is played.|

### OH_ArkUI_AnimateOption_SetPlayMode()

```
void OH_ArkUI_AnimateOption_SetPlayMode(ArkUI_AnimateOption* option, ArkUI_AnimationPlayMode value)
```

**Description**


Sets the playback mode for an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|
| [ArkUI_AnimationPlayMode](capi-native-type-h.md#arkui_animationplaymode) value | Animation playback mode.|

### OH_ArkUI_AnimateOption_SetExpectedFrameRateRange()

```
void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange(ArkUI_AnimateOption* option, ArkUI_ExpectedFrameRateRange* value)
```

**Description**


Defines a struct for the expected frame rate range of the animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Pointer to an animation configuration.|
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* value | Expected frame rate range of the animation.|

### OH_ArkUI_AnimateOption_SetICurve()

```
void OH_ArkUI_AnimateOption_SetICurve(ArkUI_AnimateOption* option, ArkUI_CurveHandle value)
```

**Description**


Sets the animation curve for an animation.

> **NOTE**
>
> This API takes precedence over [OH_ArkUI_AnimateOption_SetCurve](#oh_arkui_animateoption_setcurve).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Animator animation parameters.|
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | Animation curve parameters.|

### OH_ArkUI_AnimateOption_GetICurve()

```
ArkUI_CurveHandle OH_ArkUI_AnimateOption_GetICurve(ArkUI_AnimateOption* option)
```

**Description**


Obtains the animation curve of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Animation curve parameters. Returns **NULL** if the option parameter is invalid. |

### OH_ArkUI_KeyframeAnimateOption_Create()

```
ArkUI_KeyframeAnimateOption* OH_ArkUI_KeyframeAnimateOption_Create(int32_t size)
```

**Description**


Obtains the keyframe animation parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t size | Number of keyframe animation states.|

**Return value**

| Type                              | Description|
|----------------------------------| -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* | Keyframe animation parameter object. Returns **NULL** if the value of **size** is less than 0.|

### OH_ArkUI_KeyframeAnimateOption_Dispose()

```
void OH_ArkUI_KeyframeAnimateOption_Dispose(ArkUI_KeyframeAnimateOption* option)
```

**Description**


Disposes of a keyframe animation parameter object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameter object.|

### OH_ArkUI_KeyframeAnimateOption_SetDelay()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetDelay(ArkUI_KeyframeAnimateOption* option, int32_t value)
```

**Description**


Sets the overall delay of a keyframe animation, in milliseconds. By default, the keyframe animation is played without delay.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| int32_t value | Delay, in milliseconds.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyframeAnimateOption_SetIterations()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetIterations(ArkUI_KeyframeAnimateOption* option, int32_t value)
```

**Description**


Sets the number of times that the keyframe animation is played. By default, the animation is played once. The value **-1** indicates that the animation is played for an unlimited number of times. The value **0** indicates that there is no animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| int32_t value | Number of times that the animation is played.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback()

```
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (*onFinish)(void* userData))
```

**Description**


Sets the callback invoked when the keyframe animation playback is complete. This API is called after the keyframe animation has played for the specified number of times.

**Since**: 12


**Parameters**

| Name                                    | Description|
|-----------------------------------------| -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| void* userData                          | Pointer to a custom object.|
| void (\*onFinish)(void\* userData)                                | Callback function.<br>- **userData**: input parameter of the callback function, a user-defined object pointer.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyframeAnimateOption_SetExpectedFrameRate()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option, ArkUI_ExpectedFrameRateRange* frameRate)
```

**Description**


Sets the expected frame rate for a keyframe animation.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* frameRate | Expected frame rate for the keyframe animation. |

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyframeAnimateOption_SetDuration()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetDuration(ArkUI_KeyframeAnimateOption* option, int32_t value, int32_t index)
```

**Description**


Sets the duration of a specific keyframe animation segment, in milliseconds.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| int32_t value | Duration, in milliseconds.|
| int32_t index | Index of the keyframe state segment.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyframeAnimateOption_SetCurve()

```
int32_t OH_ArkUI_KeyframeAnimateOption_SetCurve(ArkUI_KeyframeAnimateOption* option, ArkUI_CurveHandle value, int32_t index)
```

**Description**


Sets the animation curve for a specific keyframe animation segment.

> **NOTE**
>
> Because the **springMotion**, **responsiveSpringMotion**, and **interpolatingSpring** curves do not have effective duration settings, they are not supported.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | Animation curve to set. Default value: **EASE_IN_OUT**.|
| int32_t index | Index of the keyframe state segment.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback()

```
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (*event)(void* userData), int32_t index)
```

**Description**


Sets the closure function of the state at the time of the keyframe, that is, the state to be reached at the time of the keyframe.

**Since**: 12


**Parameters**

| Name                                    | Description|
|-----------------------------------------| -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| void* userData                          | Pointer to a user-defined object.|
| void (\*event)(void\* userData)                                   | Closure function.|
| int32_t index                           | State index value.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyframeAnimateOption_GetDelay()

```
int32_t OH_ArkUI_KeyframeAnimateOption_GetDelay(ArkUI_KeyframeAnimateOption* option)
```

**Description**


Obtains the overall delay of a keyframe animation

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Overall delay.|

### OH_ArkUI_KeyframeAnimateOption_GetIterations()

```
int32_t OH_ArkUI_KeyframeAnimateOption_GetIterations(ArkUI_KeyframeAnimateOption* option)
```

**Description**


Obtains the number of times that a keyframe animation is played.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Number of times that the animation is played.|

### OH_ArkUI_KeyframeAnimateOption_GetExpectedFrameRate()

```
ArkUI_ExpectedFrameRateRange* OH_ArkUI_KeyframeAnimateOption_GetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option)
```

**Description**


Obtains the expected frame rate from keyframe animation parameters.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|

**Return value**

| Type                               | Description|
|-----------------------------------| -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* | Returns the expected frame rate obtained.|

### OH_ArkUI_KeyframeAnimateOption_GetDuration()

```
int32_t OH_ArkUI_KeyframeAnimateOption_GetDuration(ArkUI_KeyframeAnimateOption* option, int32_t index)
```

**Description**


Obtains the duration of a specific state in a keyframe animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| int32_t index | State index value.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Duration, in milliseconds.|

### OH_ArkUI_KeyframeAnimateOption_GetCurve()

```
ArkUI_CurveHandle OH_ArkUI_KeyframeAnimateOption_GetCurve(ArkUI_KeyframeAnimateOption* option, int32_t index)
```

**Description**


Obtains the animation curve of a specific state in a keyframe animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | Keyframe animation parameters.|
| int32_t index | State index value.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Animation curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_Create()

```
ArkUI_AnimatorOption* OH_ArkUI_AnimatorOption_Create(int32_t keyframeSize)
```

**Description**


Creates an **AnimatorOption** object.

> **NOTE**
>
> If the value of **keyframeSize** is greater than 0, the animation interpolation start point is 0, and the animation interpolation end point is 1; no setting is allowed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t keyframeSize | Number of keyframes.|

**Return value**

| Type| Description|
| -- | -- |
| ArkUI_AnimatorOption* | Pointer to the animator parameter object. Returns **NULL** if the value of **size** is less than 0.|

### OH_ArkUI_AnimatorOption_Dispose()

```
void OH_ArkUI_AnimatorOption_Dispose(ArkUI_AnimatorOption* option)
```

**Description**


Disposes of an **AnimatorOption** object.

**Since**: 12

### OH_ArkUI_AnimatorOption_SetDuration()

```
int32_t OH_ArkUI_AnimatorOption_SetDuration(ArkUI_AnimatorOption* option, int32_t value)
```

**Description**


Sets the duration of an animation, in milliseconds.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| int32_t value | Playback duration, in milliseconds.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetDelay()

```
int32_t OH_ArkUI_AnimatorOption_SetDelay(ArkUI_AnimatorOption* option, int32_t value)
```

**Description**


Sets the delay of animation playback, in milliseconds.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| int32_t value | Animation delay, in milliseconds.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetIterations()

```
int32_t OH_ArkUI_AnimatorOption_SetIterations(ArkUI_AnimatorOption* option, int32_t value)
```

**Description**


Sets the number of times that an animation is played. The value **0** means not to play the animation, and **-1** means to play the animation for an unlimited number of times.

> **NOTE**
>
> If this parameter is set to a negative value other than **-1**, the value is invalid. In this case, the animation is played once.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| int32_t value | Number of times that the animation is played.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetFill()

```
int32_t OH_ArkUI_AnimatorOption_SetFill(ArkUI_AnimatorOption* option, ArkUI_AnimationFillMode value)
```

**Description**


Sets whether the animator animation is restored to the initial state after being executed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| [ArkUI_AnimationFillMode](capi-native-type-h.md#arkui_animationfillmode) value | Whether to restore the animation to the initial state after the animation is executed.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetDirection()

```
int32_t OH_ArkUI_AnimatorOption_SetDirection(ArkUI_AnimatorOption* option, ArkUI_AnimationDirection value)
```

**Description**


Set the playback direction.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| [ArkUI_AnimationDirection](capi-native-type-h.md#arkui_animationdirection) value | Animation playback direction.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetCurve()

```
int32_t OH_ArkUI_AnimatorOption_SetCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value)
```

**Description**


Sets the interpolation curve for the animation of an animator.

> **NOTE**
>
> The **springCurve**, **springMotion**, **responsiveSpringMotion**, and **interpolatingSpring customCurve** curves are not supported.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | Interpolation curve. Default value: **ARKUI_CURVE_LINEAR**.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetBegin()

```
int32_t OH_ArkUI_AnimatorOption_SetBegin(ArkUI_AnimatorOption* option, float value)
```

**Description**


Sets the interpolation start point of an animation.

> **NOTE**
>
> This API does not take effect when the animation is a keyframe animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| float value | Interpolation start point of the animation.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetEnd()

```
int32_t OH_ArkUI_AnimatorOption_SetEnd(ArkUI_AnimatorOption* option, float value)
```

**Description**


Sets the interpolation end point for the animation of an animator.

> **NOTE**
>
> This API does not take effect when the animation is a keyframe animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| float value | Interpolation end point of the animation.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange()

```
int32_t OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange(ArkUI_AnimatorOption* option, ArkUI_ExpectedFrameRateRange* value)
```

**Description**


Sets the expected frame rate range of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* value | Expected frame rate range.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetKeyframe()

```
int32_t OH_ArkUI_AnimatorOption_SetKeyframe(ArkUI_AnimatorOption* option, float time, float value, int32_t index)
```

**Description**


Sets the keyframe parameters of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| float time | Keyframe time. Value range: [0, 1]. The value must be in ascending order.|
| float value | Keyframe value.|
| int32_t index | Keyframe index.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_SetKeyframeCurve()

```
int32_t OH_ArkUI_AnimatorOption_SetKeyframeCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value, int32_t index)
```

**Description**


Sets the keyframe curve type for the animation of an animator.

> **NOTE**
>
> The **springCurve**, **springMotion**, **responsiveSpringMotion**, and **interpolatingSpring customCurve** curves are not supported.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | Interpolation curve.|
| int32_t index | Keyframe index.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_GetDuration()

```
int32_t OH_ArkUI_AnimatorOption_GetDuration(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the duration for playing an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Duration for playing the animation, in milliseconds.|

### OH_ArkUI_AnimatorOption_GetDelay()

```
int32_t OH_ArkUI_AnimatorOption_GetDelay(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the delay for playing an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Delay for playing the animation, in milliseconds.|

### OH_ArkUI_AnimatorOption_GetIterations()

```
int32_t OH_ArkUI_AnimatorOption_GetIterations(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the number of times that an animation is played.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Number of times that the animation is played.|

### OH_ArkUI_AnimatorOption_GetFill()

```
ArkUI_AnimationFillMode OH_ArkUI_AnimatorOption_GetFill(ArkUI_AnimatorOption* option)
```

**Description**


Obtains whether the animator animation is restored to the initial state after being executed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_AnimationFillMode](capi-native-type-h.md#arkui_animationfillmode) | Whether the animator animation is restored to the initial state after being executed.|

### OH_ArkUI_AnimatorOption_GetDirection()

```
ArkUI_AnimationDirection OH_ArkUI_AnimatorOption_GetDirection(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the playback direction of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_AnimationDirection](capi-native-type-h.md#arkui_animationdirection) | Animation playback direction.|

### OH_ArkUI_AnimatorOption_GetCurve()

```
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetCurve(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the interpolation curve of the animation of an animator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Interpolation curve.|

### OH_ArkUI_AnimatorOption_GetBegin()

```
float OH_ArkUI_AnimatorOption_GetBegin(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the interpolation start point of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| float | Interpolation start point of the animation.|

### OH_ArkUI_AnimatorOption_GetEnd()

```
float OH_ArkUI_AnimatorOption_GetEnd(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the interpolation end point of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| float | Interpolation end point of the animation.|

### OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange()

```
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange(ArkUI_AnimatorOption* option)
```

**Description**


Obtains the expected frame rate range of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* | Pointer to the expected frame rate range object. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_GetKeyframeTime()

```
float OH_ArkUI_AnimatorOption_GetKeyframeTime(ArkUI_AnimatorOption* option, int32_t index)
```

**Description**


Obtains the keyframe time of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| int32_t index | Keyframe index.|

**Return value**

| Type| Description|
| -- | -- |
| float | Keyframe time.|

### OH_ArkUI_AnimatorOption_GetKeyframeValue()

```
float OH_ArkUI_AnimatorOption_GetKeyframeValue(ArkUI_AnimatorOption* option, int32_t index)
```

**Description**


Obtains the keyframe value of an animation.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| int32_t index | Keyframe index.|

**Return value**

| Type| Description|
| -- | -- |
| float | Keyframe value.|

### OH_ArkUI_AnimatorOption_GetKeyframeCurve()

```
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetKeyframeCurve(ArkUI_AnimatorOption* option, int32_t index)
```

**Description**


Obtains the interpolation curve for a keyframe in the animation of an animator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Pointer to an **AnimatorOption** object.|
| int32_t index | Keyframe index.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Interpolation curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_AnimatorEvent_GetUserData()

```
void* OH_ArkUI_AnimatorEvent_GetUserData(ArkUI_AnimatorEvent* event)
```

**Description**


Obtains the user-defined object in an animation event object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorEvent](capi-arkui-nativemodule-arkui-animatorevent.md)* event | Animation event object.|

**Return value**

| Type| Description|
| -- | -- |
| void* | User-defined object.|

### OH_ArkUI_AnimatorOnFrameEvent_GetUserData()

```
void* OH_ArkUI_AnimatorOnFrameEvent_GetUserData(ArkUI_AnimatorOnFrameEvent* event)
```

**Description**


Obtains the user-defined object in an animation event object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOnFrameEvent](capi-arkui-nativemodule-arkui-animatoronframeevent.md)* event | Animation event object.|

**Return value**

| Type| Description|
| -- | -- |
| void* | User-defined object.|

### OH_ArkUI_AnimatorOnFrameEvent_GetValue()

```
float OH_ArkUI_AnimatorOnFrameEvent_GetValue(ArkUI_AnimatorOnFrameEvent* event)
```

**Description**


Obtains the current progress in an animation event object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOnFrameEvent](capi-arkui-nativemodule-arkui-animatoronframeevent.md)* event | Animation event object.|

**Return value**

| Type| Description|
| -- | -- |
| float | Animation progress.|

### OH_ArkUI_AnimatorOption_RegisterOnFrameCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnFrameCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorOnFrameEvent* event))
```

**Description**


Sets the callback invoked when the animator receives a frame.

**Since**: 12


**Parameters**

| Name                             | Description|
|----------------------------------| -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|
| void* userData                         | User-defined parameter.|
| void (\*callback)(ArkUI_AnimatorOnFrameEvent\* event)                         | Callback function.<br>- **event**: input parameter of the callback function, an animation event object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_RegisterOnFinishCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnFinishCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorEvent* event))
```

**Description**


Sets the callback invoked when the animation playback is complete.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|
| void* userData | User-defined parameter.|
| void (\*callback)(ArkUI_AnimatorEvent\* event) | Callback function.<br>- **event**: input parameter of the callback function, an animation event object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_RegisterOnCancelCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnCancelCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorEvent* event))
```

**Description**


Sets the callback invoked when the animation playback is canceled.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|
| void* userData | User-defined parameter.|
| void (\*callback)(ArkUI_AnimatorEvent\* event) | Callback function.<br>- **event**: input parameter of the callback function, an animation event object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback()

```
int32_t OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorEvent* event))
```

**Description**


Sets the callback invoked when the animation playback is repeated.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|
| void* userData | User-defined parameter.|
| void (\*callback)(ArkUI_AnimatorEvent\* event) | Callback function.<br>- **event**: input parameter of the callback function, an animation event object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t  | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_Animator_ResetAnimatorOption()

```
int32_t OH_ArkUI_Animator_ResetAnimatorOption(ArkUI_AnimatorHandle animatorHandle, ArkUI_AnimatorOption* option)
```

**Description**


Resets an animator configuration.

**Since**: 12


**Parameters**

| Name                                                                            | Description|
|---------------------------------------------------------------------------------| -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle                                         | Animator object.|
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | Animator animation parameters.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_Animator_Play()

```
int32_t OH_ArkUI_Animator_Play(ArkUI_AnimatorHandle animatorHandle)
```

**Description**


Starts the animation of an animator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | Animator object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_Animator_Finish()

```
int32_t OH_ArkUI_Animator_Finish(ArkUI_AnimatorHandle animatorHandle)
```

**Description**


Ends the animation of an animator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | Animator object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_Animator_Pause()

```
int32_t OH_ArkUI_Animator_Pause(ArkUI_AnimatorHandle animatorHandle)
```

**Description**


Pauses the animation of an animator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | Animator object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_Animator_Cancel()

```
int32_t OH_ArkUI_Animator_Cancel(ArkUI_AnimatorHandle animatorHandle)
```

**Description**


Cancels the animation of an animator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | Animator object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_Animator_Reverse()

```
int32_t OH_ArkUI_Animator_Reverse(ArkUI_AnimatorHandle animatorHandle)
```

**Description**


Plays this animation in reverse order.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | Animator object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_Curve_CreateCurveByType()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCurveByType(ArkUI_AnimationCurve curve)
```

**Description**


Implements initialization for the interpolation curve, which is used to create an interpolation curve based on the input parameter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AnimationCurve](capi-native-type-h.md#arkui_animationcurve) curve | Curve type.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_CreateStepsCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateStepsCurve(int32_t count, bool end)
```

**Description**


Creates a step curve.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t count | Number of steps. The value must be a positive integer. Value range: [1, +∞).|
| bool end | Whether the step change occurs at the start or end of each interval. **true**: The step change occurs at the end of each interval. **false**: The step change occurs at the start of each interval.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_CreateCubicBezierCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCubicBezierCurve(float x1, float y1, float x2, float y2)
```

**Description**


Creates a cubic Bezier curve.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float x1 | X-coordinate of the first point on the Bezier curve. Value range: [0, 1]. A value less than 0 is treated as **0**. A value greater than 1 is treated as **1**.|
| float y1 | Y-coordinate of the first point on the Bezier curve.|
| float x2 | X-coordinate of the second point on the Bezier curve. Value range: [0, 1]. A value less than 0 is treated as **0**. A value greater than 1 is treated as **1**.|
| float y2 | Y-coordinate of the second point on the Bezier curve.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_CreateSpringCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringCurve(float velocity, float mass, float stiffness, float damping)
```

**Description**


Creates a spring curve. The curve shape is subject to the spring parameters, and the animation duration is subject to the **duration** parameter in **animation** and **animateTo**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float velocity | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. The velocity is the normalized velocity, and its value is equal to the actual velocity at the beginning of the animation divided by the animation attribute change value.|
| float mass | Mass. It describes the inertia of the object in the elastic system, affecting the amplitude of oscillation and the speed of return to equilibrium. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.|
| float stiffness | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.|
| float damping | Damping. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_CreateSpringMotion()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringMotion(float response, float dampingFraction, float overlapDuration)
```

**Description**


Creates a spring animation curve. If multiple spring animations are applied to the same attribute of an object, each animation replaces their predecessor and inherits the velocity.

> **NOTE**
>
> The animation duration is subject to the curve parameters, rather than the **duration** parameter in **animation** or **animateTo**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float response | Duration of one complete oscillation.|
| float dampingFraction | Damping coefficient. > 0 and < 1: underdamped. In this case, the spring overshoots the equilibrium position. **1**: critically damped. > 1: overdamped. In this case, the spring approaches equilibrium gradually.|
| float overlapDuration | Duration for animations to overlap, in seconds. When animations overlap, the **response** values of these animations will transit smoothly over this duration if they are different.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_CreateResponsiveSpringMotion()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateResponsiveSpringMotion(float response, float dampingFraction, float overlapDuration)
```

**Description**


Creates a responsive spring animation curve. It is a special case of **springMotion**, with the only difference in the default values. It can be used together with **springMotion**.

> **NOTE**
>
> The animation duration is subject to the curve parameters, rather than the **duration** parameter in **animation** or **animateTo**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float response | Duration of one complete oscillation.|
| float dampingFraction | Damping coefficient. > 0 and < 1: underdamped. In this case, the spring overshoots the equilibrium position. **1**: critically damped. > 1: overdamped. In this case, the spring approaches equilibrium gradually.|
| float overlapDuration | Duration for animations to overlap, in seconds. When animations overlap, the **response** values of these animations will transit smoothly over this duration if they are different.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_CreateInterpolatingSpring()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateInterpolatingSpring(float velocity, float mass, float stiffness, float damping)
```

**Description**


Creates an interpolating spring curve animated from 0 to 1. The actual animation value is calculated based on the curve.

> **NOTE**
>
> The animation duration is subject to the curve parameters, rather than the **duration** parameter in **animation** or **animateTo**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float velocity | Initial velocity. It is applied by external factors to the spring animation, designed to help ensure the smooth transition from the previous motion state. The velocity is the normalized velocity, and its value is equal to the actual velocity at the beginning of the animation divided by the animation attribute change value.|
| float mass | Mass. It describes the inertia of the object in the elastic system, affecting the amplitude of oscillation and the speed of return to equilibrium. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.|
| float stiffness | Stiffness. It is the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the ability to resist deformation, and the faster the speed of restoring to the equilibrium position.|
| float damping | Damping. It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_CreateCustomCurve()

```
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCustomCurve(void* userData, float (*interpolate)(float fraction, void* userdata))
```

**Description**


Creates a custom curve.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| void* userData | Pointer to user-defined data.|
| float (\*interpolate)(float fraction, void\* userdata) | User-defined interpolation callback. **fraction** indicates the input x value for interpolation when the animation starts; value range: [0, 1]. The return value is the y value of the curve; value range: [0, 1]. If **fraction** is **0**, the return value **0** corresponds to the animation start point; any other return value means that the animation jumps at the start point. If **fraction** is **1**, the return value **1** corresponds to the animation end point; any other return value means that the end value of the animation is not the value of the state variable, which will result in an effect of transition from that end value to the value of the state variable.|

**Return value**

| Type                   | Description|
|-----------------------| -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | Pointer to the interpolation object of the curve. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_Curve_DisposeCurve()

```
void OH_ArkUI_Curve_DisposeCurve(ArkUI_CurveHandle curveHandle)
```

**Description**


Disposes of a custom curve.

**Since**: 12


**Parameters**

| Name                                                                | Description|
|---------------------------------------------------------------------| -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) curveHandle | Pointer to the interpolation object of the curve.|

### OH_ArkUI_CreateOpacityTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateOpacityTransitionEffect(float opacity)
```

**Description**


Creates an opacity effect object for component transitions.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float opacity | Opacity. Value range: [0, 1]. The default value is **1**. A value less than 0 is treated as 0. A value greater than 1 is treated as 1. The value **1** means fully opaque, and **0** means fully transparent.|

**Return value**

| Type                         | Description|
|-----------------------------| -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | Opacity effect object for component transitions.|

### OH_ArkUI_CreateTranslationTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateTranslationTransitionEffect(ArkUI_TranslationOptions* translate)
```

**Description**


Creates a translation effect object for component transitions.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TranslationOptions](capi-arkui-nativemodule-arkui-translationoptions.md)* translate | Translation parameter object for component transitions.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | Translation effect object for component transitions. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_CreateScaleTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateScaleTransitionEffect(ArkUI_ScaleOptions* scale)
```

**Description**


Creates a scaling effect object for component transitions.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ScaleOptions](capi-arkui-nativemodule-arkui-scaleoptions.md)* scale | Scaling parameter object for component transitions.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | Scaling effect object for component transitions. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_CreateRotationTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateRotationTransitionEffect(ArkUI_RotationOptions* rotate)
```

**Description**


Creates a rotation effect object for component transition.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_RotationOptions](capi-arkui-nativemodule-arkui-rotationoptions.md)* rotate | Rotation parameter object for component transitions.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | Rotation effect object for component transitions. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_CreateMovementTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateMovementTransitionEffect(ArkUI_TransitionEdge edge)
```

**Description**


Creates a movement transition effect object for the component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TransitionEdge](capi-native-type-h.md#arkui_transitionedge) edge | Movement transition type.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | Movement transition effect object for the component. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_CreateAsymmetricTransitionEffect()

```
ArkUI_TransitionEffect* OH_ArkUI_CreateAsymmetricTransitionEffect(ArkUI_TransitionEffect* appear, ArkUI_TransitionEffect* disappear)
```

**Description**


Creates an asymmetric transition effect.

> **NOTE**
>
> If the **asymmetric** function is not used for **TransitionEffect**, the transition effect takes effect for both appearance and disappearance of the component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* appear | Transition effect for appearance.|
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* disappear | Transition effect for disappearance.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | Asymmetric transition effect. Returns **NULL** if a parameter error occurs.|

### OH_ArkUI_TransitionEffect_Dispose()

```
void OH_ArkUI_TransitionEffect_Dispose(ArkUI_TransitionEffect* effect)
```

**Description**


Disposes of a transition effect.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* effect | Disposes a transition effect.|

### OH_ArkUI_TransitionEffect_Combine()

```
int32_t OH_ArkUI_TransitionEffect_Combine(ArkUI_TransitionEffect* firstEffect, ArkUI_TransitionEffect* secondEffect)
```

**Description**


Sets a combination of transition effects.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* firstEffect | Transition effect.|
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* secondEffect | Combination of transition effects.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TransitionEffect_SetAnimation()

```
int32_t OH_ArkUI_TransitionEffect_SetAnimation(ArkUI_TransitionEffect* effect, ArkUI_AnimateOption* animation)
```

**Description**


Sets transition effect animation settings.

> **NOTE**
>
> If **combine** is used for combining transition effects, the animation settings of a transition effect are applicable to the one following it.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* effect | Transition effect.|
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* animation | Animation settings.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
