# native_animate.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

提供ArkUI（方舟UI框架）在Native侧的动画接口定义集合。native_animate.h中的接口需要在主线程上调用。

**引用文件：** <arkui/native_animate.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[AnimationNDK](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/AnimationNDK)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md) | ArkUI_ExpectedFrameRateRange | 设置动画的期望帧率。该结构体通过min、max和expected三个字段定义帧率范围，系统尽可能满足期望帧率。 |
| [ArkUI_AnimateCompleteCallback](capi-arkui-nativemodule-arkui-animatecompletecallback.md) | ArkUI_AnimateCompleteCallback | 动画播放结束回调类型，用于在动画播放完成时通知开发者动画已结束。开发者可通过type字段指定回调触发方式，通过callback字段设置自定义回调函数，并通过userData字段传递自定义数据至回调函数中。 |
| [ArkUI_NativeAnimateAPI_1](capi-arkui-nativemodule-arkui-nativeanimateapi-1.md) | ArkUI_NativeAnimateAPI_1 | ArkUI（方舟UI框架）提供的Native侧动画接口集合。 |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md) | ArkUI_AnimateOption | 定义动画效果的配置参数，用于配置动画的相关属性。 |
| [ArkUI_Curve](capi-arkui-nativemodule-arkui-curve.md) | ArkUI_Curve | 提供动画曲线的插值对象定义，用于动画属性值的插值计算。 |
| [ArkUI_Curve*](capi-arkui-nativemodule-arkui-curve8h.md) | ArkUI_CurveHandle | 曲线插值对象的指针类型定义。曲线插值用于控制动画属性值随时间的变化规律，不同类型的插值曲线可实现不同的动画过渡效果。 |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md) | ArkUI_KeyframeAnimateOption | 定义关键帧动画参数对象，作为关键帧动画接口的输入参数使用。相关接口需要在主线程上调用。 |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md) | ArkUI_AnimatorOption | 定义animator动画参数对象，用于创建animator动画时配置动画属性参数。 |
| [ArkUI_Animator*](capi-arkui-nativemodule-arkui-animator8h.md) | ArkUI_AnimatorHandle | 定义animator动画对象指针，用于对ArkUI（方舟UI框架）动画对象进行操作和控制。 |
| [ArkUI_AnimatorEvent](capi-arkui-nativemodule-arkui-animatorevent.md) | ArkUI_AnimatorEvent | 定义animator回调事件对象，用于在动画状态变化回调中接收事件。 |
| [ArkUI_AnimatorOnFrameEvent](capi-arkui-nativemodule-arkui-animatoronframeevent.md) | ArkUI_AnimatorOnFrameEvent | 定义animator动画播放过程中逐帧回调的事件数据对象。 |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md) | ArkUI_TransitionEffect | 定义transition属性的转场效果参数对象，用于配置组件出现或消失时的过渡动画效果。 |

### 函数

<!--Table: 40%; 60%-->
| 名称 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create()](#oh_arkui_animateoption_create) | 创建动画效果参数。 |
| [void OH_ArkUI_AnimateOption_Dispose(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_dispose) | 销毁动画效果参数指针。 |
| [uint32_t OH_ArkUI_AnimateOption_GetDuration(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getduration) | 获取动画持续时间，单位为ms（毫秒）。 |
| [float OH_ArkUI_AnimateOption_GetTempo(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_gettempo) | 获取动画播放速度。 |
| [ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getcurve) | 获取动画曲线。 |
| [int32_t OH_ArkUI_AnimateOption_GetDelay(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getdelay) | 获取动画延迟播放时间，单位为ms（毫秒）。 |
| [int32_t OH_ArkUI_AnimateOption_GetIterations(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getiterations) | 获取动画播放次数。 |
| [ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getplaymode) | 获取动画播放模式。 |
| [ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimateOption_GetExpectedFrameRateRange(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_getexpectedframeraterange) | 获取动画的期望帧率。 |
| [void OH_ArkUI_AnimateOption_SetDuration(ArkUI_AnimateOption* option, int32_t value)](#oh_arkui_animateoption_setduration) | 设置动画持续时间，单位为ms（毫秒）。 |
| [void OH_ArkUI_AnimateOption_SetTempo(ArkUI_AnimateOption* option, float value)](#oh_arkui_animateoption_settempo) | 设置动画播放速度。 |
| [void OH_ArkUI_AnimateOption_SetCurve(ArkUI_AnimateOption* option, ArkUI_AnimationCurve value)](#oh_arkui_animateoption_setcurve) | 设置动画的自定义曲线。 |
| [void OH_ArkUI_AnimateOption_SetDelay(ArkUI_AnimateOption* option, int32_t value)](#oh_arkui_animateoption_setdelay) | 设置动画延迟播放时间，单位为ms（毫秒）。 |
| [void OH_ArkUI_AnimateOption_SetIterations(ArkUI_AnimateOption* option, int32_t value)](#oh_arkui_animateoption_setiterations) | 设置动画播放次数。 |
| [void OH_ArkUI_AnimateOption_SetPlayMode(ArkUI_AnimateOption* option, ArkUI_AnimationPlayMode value)](#oh_arkui_animateoption_setplaymode) | 设置动画播放模式。 |
| [void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange(ArkUI_AnimateOption* option, ArkUI_ExpectedFrameRateRange* value)](#oh_arkui_animateoption_setexpectedframeraterange) | 设置动画的期望帧率。 |
| [void OH_ArkUI_AnimateOption_SetICurve(ArkUI_AnimateOption* option, ArkUI_CurveHandle value)](#oh_arkui_animateoption_seticurve) | 设置动画的插值曲线。 |
| [ArkUI_CurveHandle OH_ArkUI_AnimateOption_GetICurve(ArkUI_AnimateOption* option)](#oh_arkui_animateoption_geticurve) | 获取动画的插值曲线。 |
| [ArkUI_KeyframeAnimateOption* OH_ArkUI_KeyframeAnimateOption_Create(int32_t size)](#oh_arkui_keyframeanimateoption_create) | 创建关键帧动画参数。 |
| [void OH_ArkUI_KeyframeAnimateOption_Dispose(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_dispose) | 销毁关键帧动画参数。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetDelay(ArkUI_KeyframeAnimateOption* option, int32_t value)](#oh_arkui_keyframeanimateoption_setdelay) | 设置关键帧动画的整体延迟时间，单位为ms（毫秒），默认不延迟播放。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetIterations(ArkUI_KeyframeAnimateOption* option, int32_t value)](#oh_arkui_keyframeanimateoption_setiterations) | 设置关键帧动画播放次数。默认播放一次，设置为-1时表示无限次播放，设置为0时表示无动画效果。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (\*onFinish)(void* userData))](#oh_arkui_keyframeanimateoption_registeronfinishcallback) | 设置关键帧动画播放完成回调。当关键帧动画[ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)所有次数播放完成后调用。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option, ArkUI_ExpectedFrameRateRange* frameRate)](#oh_arkui_keyframeanimateoption_setexpectedframerate) | 设置关键帧动画期望帧率。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetDuration(ArkUI_KeyframeAnimateOption* option, int32_t value, int32_t index)](#oh_arkui_keyframeanimateoption_setduration) | 设置关键帧动画某段关键帧动画的持续时间，单位为ms（毫秒）。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_SetCurve(ArkUI_KeyframeAnimateOption* option, ArkUI_CurveHandle value, int32_t index)](#oh_arkui_keyframeanimateoption_setcurve) | 设置关键帧动画某段关键帧使用的动画曲线。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (\*event)(void* userData), int32_t index)](#oh_arkui_keyframeanimateoption_registeroneventcallback) | 设置关键帧时刻状态的闭包函数，即在该关键帧时刻要达到的状态。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_GetDelay(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_getdelay) | 获取关键帧整体延迟时间，单位为ms（毫秒）。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_GetIterations(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_getiterations) | 获取关键帧动画播放次数。 |
| [ArkUI_ExpectedFrameRateRange* OH_ArkUI_KeyframeAnimateOption_GetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option)](#oh_arkui_keyframeanimateoption_getexpectedframerate) | 获取关键帧动画参数的期望帧率。 |
| [int32_t OH_ArkUI_KeyframeAnimateOption_GetDuration(ArkUI_KeyframeAnimateOption* option, int32_t index)](#oh_arkui_keyframeanimateoption_getduration) | 获取关键帧动画某段状态持续时间，单位为ms（毫秒）。 |
| [ArkUI_CurveHandle OH_ArkUI_KeyframeAnimateOption_GetCurve(ArkUI_KeyframeAnimateOption* option, int32_t index)](#oh_arkui_keyframeanimateoption_getcurve) | 获取关键帧动画某段状态动画曲线。 |
| [ArkUI_AnimatorOption* OH_ArkUI_AnimatorOption_Create(int32_t keyframeSize)](#oh_arkui_animatoroption_create) | 创建animator动画对象参数。 |
| [void OH_ArkUI_AnimatorOption_Dispose(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_dispose) | 销毁animator动画对象参数。 |
| [int32_t OH_ArkUI_AnimatorOption_SetDuration(ArkUI_AnimatorOption* option, int32_t value)](#oh_arkui_animatoroption_setduration) | 设置animator动画播放的时长，单位为ms（毫秒）。 |
| [int32_t OH_ArkUI_AnimatorOption_SetDelay(ArkUI_AnimatorOption* option, int32_t value)](#oh_arkui_animatoroption_setdelay) | 设置animator动画延迟播放的时间，单位为ms（毫秒）。 |
| [int32_t OH_ArkUI_AnimatorOption_SetIterations(ArkUI_AnimatorOption* option, int32_t value)](#oh_arkui_animatoroption_setiterations) | 设置animator动画播放次数。默认播放一次，设置为-1时表示无限次播放，设置为0时表示无动画效果。 |
| [int32_t OH_ArkUI_AnimatorOption_SetFill(ArkUI_AnimatorOption* option, ArkUI_AnimationFillMode value)](#oh_arkui_animatoroption_setfill) | 设置组件在动画开始前和结束后保持的状态。 |
| [int32_t OH_ArkUI_AnimatorOption_SetDirection(ArkUI_AnimatorOption* option, ArkUI_AnimationDirection value)](#oh_arkui_animatoroption_setdirection) | 设置animator动画播放方向。 |
| [int32_t OH_ArkUI_AnimatorOption_SetCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value)](#oh_arkui_animatoroption_setcurve) | 设置animator动画插值曲线。 |
| [int32_t OH_ArkUI_AnimatorOption_SetBegin(ArkUI_AnimatorOption* option, float value)](#oh_arkui_animatoroption_setbegin) | 设置animator动画插值起点。 |
| [int32_t OH_ArkUI_AnimatorOption_SetEnd(ArkUI_AnimatorOption* option, float value)](#oh_arkui_animatoroption_setend) | 设置animator动画插值终点。 |
| [int32_t OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange(ArkUI_AnimatorOption* option, ArkUI_ExpectedFrameRateRange* value)](#oh_arkui_animatoroption_setexpectedframeraterange) | 设置animator动画期望的帧率范围。 |
| [int32_t OH_ArkUI_AnimatorOption_SetKeyframe(ArkUI_AnimatorOption* option, float time, float value, int32_t index)](#oh_arkui_animatoroption_setkeyframe) | 设置animator动画关键帧参数。 |
| [int32_t OH_ArkUI_AnimatorOption_SetKeyframeCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value, int32_t index)](#oh_arkui_animatoroption_setkeyframecurve) | 设置animator动画关键帧曲线类型。 |
| [int32_t OH_ArkUI_AnimatorOption_GetDuration(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getduration) | 获取animator动画播放的时长，单位为ms（毫秒）。 |
| [int32_t OH_ArkUI_AnimatorOption_GetDelay(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getdelay) | 获取animator动画延迟播放时长，单位为ms（毫秒）。 |
| [int32_t OH_ArkUI_AnimatorOption_GetIterations(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getiterations) | 获取animator动画播放次数。 |
| [ArkUI_AnimationFillMode OH_ArkUI_AnimatorOption_GetFill(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getfill) | 获取animator动画执行时组件在动画开始前和结束后的状态。 |
| [ArkUI_AnimationDirection OH_ArkUI_AnimatorOption_GetDirection(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getdirection) | 获取animator动画播放方向。 |
| [ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetCurve(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getcurve) | 获取animator动画插值曲线。 |
| [float OH_ArkUI_AnimatorOption_GetBegin(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getbegin) | 获取animator动画插值起点。当Animator动画为关键帧动画时，此方法返回的值无实际意义。 |
| [float OH_ArkUI_AnimatorOption_GetEnd(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getend) | 获取animator动画插值终点。当Animator动画为关键帧动画时，此方法返回的值无实际意义。 |
| [ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange(ArkUI_AnimatorOption* option)](#oh_arkui_animatoroption_getexpectedframeraterange) | 获取animator动画期望的帧率范围。 |
| [float OH_ArkUI_AnimatorOption_GetKeyframeTime(ArkUI_AnimatorOption* option, int32_t index)](#oh_arkui_animatoroption_getkeyframetime) | 获取animator动画关键帧时间，单位为ms（毫秒）。 |
| [float OH_ArkUI_AnimatorOption_GetKeyframeValue(ArkUI_AnimatorOption* option, int32_t index)](#oh_arkui_animatoroption_getkeyframevalue) | 获取animator动画在该关键帧位置的插值目标值。 |
| [ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetKeyframeCurve(ArkUI_AnimatorOption* option, int32_t index)](#oh_arkui_animatoroption_getkeyframecurve) | 获取animator动画关键帧动画插值曲线。 |
| [void* OH_ArkUI_AnimatorEvent_GetUserData(ArkUI_AnimatorEvent* event)](#oh_arkui_animatorevent_getuserdata) | 获取动画事件对象中的用户自定义对象。 |
| [void* OH_ArkUI_AnimatorOnFrameEvent_GetUserData(ArkUI_AnimatorOnFrameEvent* event)](#oh_arkui_animatoronframeevent_getuserdata) | 获取动画的帧事件中的用户自定义对象。 |
| [float OH_ArkUI_AnimatorOnFrameEvent_GetValue(ArkUI_AnimatorOnFrameEvent* event)](#oh_arkui_animatoronframeevent_getvalue) | 获取动画帧回调事件对象中的插值结果。 |
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnFrameCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorOnFrameEvent* event))](#oh_arkui_animatoroption_registeronframecallback) | 设置animator动画接收到帧时回调。 |
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnFinishCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorEvent* event))](#oh_arkui_animatoroption_registeronfinishcallback) | 设置animator动画完成时回调。当animator动画所有次数播放完成后调用，或调用[OH_ArkUI_Animator_Finish](#oh_arkui_animator_finish)结束时也会触发。 |
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnCancelCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorEvent* event))](#oh_arkui_animatoroption_registeroncancelcallback) | 设置animator动画被取消时回调。 |
| [int32_t OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback(ArkUI_AnimatorOption* option, void* userData, void (\*callback)(ArkUI_AnimatorEvent* event))](#oh_arkui_animatoroption_registeronrepeatcallback) | 设置animator动画重复时回调。 |
| [int32_t OH_ArkUI_Animator_ResetAnimatorOption(ArkUI_AnimatorHandle animatorHandle, ArkUI_AnimatorOption* option)](#oh_arkui_animator_resetanimatoroption) | 重置animator动画的配置参数。 |
| [int32_t OH_ArkUI_Animator_Play(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_play) | 启动animator动画。 |
| [int32_t OH_ArkUI_Animator_Finish(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_finish) | 结束animator动画，动画将跳到终点状态。与OH_ArkUI_Animator_Cancel的区别：Finish使动画完成至终点状态，Cancel中断动画并回到初始状态。 |
| [int32_t OH_ArkUI_Animator_Pause(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_pause) | 暂停animator动画。 |
| [int32_t OH_ArkUI_Animator_Cancel(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_cancel) | 取消animator动画。 |
| [int32_t OH_ArkUI_Animator_Reverse(ArkUI_AnimatorHandle animatorHandle)](#oh_arkui_animator_reverse) | 以相反的顺序播放animator动画。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateCurveByType(ArkUI_AnimationCurve curve)](#oh_arkui_curve_createcurvebytype) | 插值曲线的初始化函数，可以根据入参创建一个插值曲线对象。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateStepsCurve(int32_t count, bool end)](#oh_arkui_curve_createstepscurve) | 构造阶梯曲线对象。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateCubicBezierCurve(float x1, float y1, float x2, float y2)](#oh_arkui_curve_createcubicbeziercurve) | 构造三阶贝塞尔曲线对象。动画时长受动画参数中的时长参数控制。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringCurve(float velocity, float mass, float stiffness, float damping)](#oh_arkui_curve_createspringcurve) | 构造弹簧曲线对象，曲线形状由弹簧参数决定，动画时长受动画参数中的时长参数控制。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringMotion(float response, float dampingFraction, float overlapDuration)](#oh_arkui_curve_createspringmotion) | 构造弹性动画曲线对象。如果对同一对象的同一属性进行多个弹性动画，每个动画会替换掉前一个动画，并继承之前的速度。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateResponsiveSpringMotion(float response, float dampingFraction, float overlapDuration)](#oh_arkui_curve_createresponsivespringmotion) | 构造弹性跟手动画曲线对象，是springMotion的一种特例，仅默认参数不同，可与springMotion混合使用。如果对同一对象的同一属性进行多个弹性动画，每个动画会替换掉前一个动画，并继承之前的速度。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateInterpolatingSpring(float velocity, float mass, float stiffness, float damping)](#oh_arkui_curve_createinterpolatingspring) | 构造插值器弹簧曲线对象，生成一条从0到1的动画曲线，实际动画值根据曲线进行插值计算。 |
| [ArkUI_CurveHandle OH_ArkUI_Curve_CreateCustomCurve(void* userData, float (\*interpolate)(float fraction, void* userdata))](#oh_arkui_curve_createcustomcurve) | 构造自定义曲线对象。 |
| [void OH_ArkUI_Curve_DisposeCurve(ArkUI_CurveHandle curveHandle)](#oh_arkui_curve_disposecurve) | 销毁自定义曲线对象。 |
| [ArkUI_TransitionEffect* OH_ArkUI_CreateOpacityTransitionEffect(float opacity)](#oh_arkui_createopacitytransitioneffect) | 创建组件转场时的透明度效果对象。 |
| [ArkUI_TransitionEffect* OH_ArkUI_CreateTranslationTransitionEffect(ArkUI_TranslationOptions* translate)](#oh_arkui_createtranslationtransitioneffect) | 创建组件转场时的平移效果对象。 |
| [ArkUI_TransitionEffect* OH_ArkUI_CreateScaleTransitionEffect(ArkUI_ScaleOptions* scale)](#oh_arkui_createscaletransitioneffect) | 创建组件转场时的缩放效果对象。 |
| [ArkUI_TransitionEffect* OH_ArkUI_CreateRotationTransitionEffect(ArkUI_RotationOptions* rotate)](#oh_arkui_createrotationtransitioneffect) | 创建组件转场时的旋转效果对象。 |
| [ArkUI_TransitionEffect* OH_ArkUI_CreateMovementTransitionEffect(ArkUI_TransitionEdge edge)](#oh_arkui_createmovementtransitioneffect) | 创建组件平移效果对象，用于组件从指定边缘滑入或滑出的转场效果，适用于仅需指定滑动方向的简单场景。与[OH_ArkUI_CreateTranslationTransitionEffect](#oh_arkui_createtranslationtransitioneffect)不同：后者支持自定义x/y/z方向的精确平移参数，适用于需要指定具体位移距离的场景。 |
| [ArkUI_TransitionEffect* OH_ArkUI_CreateAsymmetricTransitionEffect(ArkUI_TransitionEffect* appear, ArkUI_TransitionEffect* disappear)](#oh_arkui_createasymmetrictransitioneffect) | 创建非对称的转场效果对象。 |
| [ArkUI_TransitionEffect* OH_ArkUI_CreateIdentityTransitionEffect(void)](#oh_arkui_createidentitytransitioneffect) | 创建无转场效果对象。 |
| [void OH_ArkUI_TransitionEffect_Dispose(ArkUI_TransitionEffect* effect)](#oh_arkui_transitioneffect_dispose) | 销毁转场效果对象。 |
| [int32_t OH_ArkUI_TransitionEffect_Combine(ArkUI_TransitionEffect* firstEffect, ArkUI_TransitionEffect* secondEffect)](#oh_arkui_transitioneffect_combine) | 设置转场效果链式组合，以形成包含多种转场效果的TransitionEffect。 |
| [int32_t OH_ArkUI_TransitionEffect_SetAnimation(ArkUI_TransitionEffect* effect, ArkUI_AnimateOption* animation)](#oh_arkui_transitioneffect_setanimation) | 设置转场效果动画参数。 |

## 函数说明

### OH_ArkUI_AnimateOption_Create()

```c
ArkUI_AnimateOption* OH_ArkUI_AnimateOption_Create()
```

**描述：**


创建动画效果参数。

**起始版本：** 12

**返回：**

| 类型                       | 说明 |
|--------------------------| -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* | 新的动画效果参数指针。 |

### OH_ArkUI_AnimateOption_Dispose()

```c
void OH_ArkUI_AnimateOption_Dispose(ArkUI_AnimateOption* option)
```

**描述：**


销毁动画效果参数指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |

### OH_ArkUI_AnimateOption_GetDuration()

```c
uint32_t OH_ArkUI_AnimateOption_GetDuration(ArkUI_AnimateOption* option)
```


**描述：**


获取动画持续时间，单位为ms（毫秒）。


**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 动画持续时间，单位为ms（毫秒）。option异常时返回0。 |

### OH_ArkUI_AnimateOption_GetTempo()

```c
float OH_ArkUI_AnimateOption_GetTempo(ArkUI_AnimateOption* option)
```

**描述：**


获取动画播放速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回0.0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 动画播放速度。取值范围：[0, +∞)。option异常时返回0.0。 |

### OH_ArkUI_AnimateOption_GetCurve()

```c
ArkUI_AnimationCurve OH_ArkUI_AnimateOption_GetCurve(ArkUI_AnimateOption* option)
```

**描述：**


获取动画曲线。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回-1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve) | 动画曲线。返回值包括：ARKUI_CURVE_LINEAR（0，线性曲线）、ARKUI_CURVE_EASE（1，缓动曲线）、ARKUI_CURVE_EASE_IN（2，加速曲线）、ARKUI_CURVE_EASE_OUT（3，减速曲线）、ARKUI_CURVE_EASE_IN_OUT（4，先加速后减速曲线）、ARKUI_CURVE_FAST_OUT_SLOW_IN（5，标准曲线）、ARKUI_CURVE_LINEAR_OUT_SLOW_IN（6，减速曲线）、ARKUI_CURVE_FAST_OUT_LINEAR_IN（7，加速曲线）、ARKUI_CURVE_EXTREME_DECELERATION（8，急减速曲线）、ARKUI_CURVE_SHARP（9，锐利曲线）、ARKUI_CURVE_RHYTHM（10，节奏曲线）、ARKUI_CURVE_SMOOTH（11，平滑曲线）、ARKUI_CURVE_FRICTION（12，阻尼曲线）。option异常时返回-1。 |

### OH_ArkUI_AnimateOption_GetDelay()

```c
int32_t OH_ArkUI_AnimateOption_GetDelay(ArkUI_AnimateOption* option)
```

**描述：**


获取动画延迟播放时间，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 动画延迟播放时间，单位为ms（毫秒）。option异常时返回0。 |

### OH_ArkUI_AnimateOption_GetIterations()

```c
int32_t OH_ArkUI_AnimateOption_GetIterations(ArkUI_AnimateOption* option)
```

**描述：**


获取动画播放次数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 动画播放次数。option异常时返回0。 |

### OH_ArkUI_AnimateOption_GetPlayMode()

```c
ArkUI_AnimationPlayMode OH_ArkUI_AnimateOption_GetPlayMode(ArkUI_AnimateOption* option)
```

**描述：**


获取动画播放模式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回-1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode) | 动画播放模式。返回值包括：ARKUI_ANIMATION_PLAY_MODE_NORMAL（0，正向播放）、ARKUI_ANIMATION_PLAY_MODE_REVERSE（1，反向播放）、ARKUI_ANIMATION_PLAY_MODE_ALTERNATE（2，交替播放）、ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE（3，反向交替播放）。option异常时返回-1。 |

### OH_ArkUI_AnimateOption_GetExpectedFrameRateRange()

```c
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimateOption_GetExpectedFrameRateRange(ArkUI_AnimateOption* option)
```

**描述：**


获取动画的期望帧率，单位为帧/秒（fps）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回NULL。 |

**返回：**

| 类型                                | 说明 |
|-----------------------------------| -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* | 动画的期望帧率，单位为帧/秒（fps）。option异常时返回NULL。 |

### OH_ArkUI_AnimateOption_SetDuration()

```c
void OH_ArkUI_AnimateOption_SetDuration(ArkUI_AnimateOption* option, int32_t value)
```

**描述：**


设置动画持续时间，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| int32_t value | 动画持续时间，单位为ms（毫秒），默认值1000ms。取值范围：[0, +∞)。<br>value小于0时，按0处理。 |

### OH_ArkUI_AnimateOption_SetTempo()

```c
void OH_ArkUI_AnimateOption_SetTempo(ArkUI_AnimateOption* option, float value)
```

**描述：**


设置动画播放速度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| float value | 动画播放速度，默认值1.0。取值范围：[0, +∞)。<br>**说明：**<br>传入小于0的数值，会默认设置为1。 |


### OH_ArkUI_AnimateOption_SetCurve()

```c
void OH_ArkUI_AnimateOption_SetCurve(ArkUI_AnimateOption* option, ArkUI_AnimationCurve value)
```

**描述：**


设置动画自定义曲线。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| [ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve) value | 动画曲线。默认值：[ARKUI_CURVE_EASE_IN_OUT](capi-native-type-visual-h.md#arkui_animationcurve)，建议使用ARKUI_CURVE_EASE_IN_OUT获得更平滑的动画效果。<br>value值异常时，设置无效。<br>**说明：**若同时设置了[OH_ArkUI_AnimateOption_SetICurve](#oh_arkui_animateoption_seticurve)，则SetICurve优先生效，本设置不生效。|

### OH_ArkUI_AnimateOption_SetDelay()

```c
void OH_ArkUI_AnimateOption_SetDelay(ArkUI_AnimateOption* option, int32_t value)
```

**描述：**


设置动画延迟播放时间，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| int32_t value | 动画延迟播放时间，单位为ms（毫秒）。取值范围：(-∞, +∞)。默认值：0，表示不延迟。value大于0时表示延迟播放，小于0表示提前播放。value小于0时，如果value的绝对值小于实际动画时长，动画将在开始后第一帧直接运动到value绝对值的时刻的状态；如果value的绝对值大于等于实际动画时长，动画将在开始后第一帧直接运动到终点状态。其中实际动画时长等于单次动画时长乘以动画播放次数。 |

### OH_ArkUI_AnimateOption_SetIterations()

```c
void OH_ArkUI_AnimateOption_SetIterations(ArkUI_AnimateOption* option, int32_t value)
```

**描述：**


设置动画播放次数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| int32_t value | 动画播放次数。取值范围：[-1, +∞)，其中设置为0时不播放，-1表示无限次播放。默认值：1（播放一次）。<br>value小于-1时，操作无效。 |

### OH_ArkUI_AnimateOption_SetPlayMode()

```c
void OH_ArkUI_AnimateOption_SetPlayMode(ArkUI_AnimateOption* option, ArkUI_AnimationPlayMode value)
```

**描述：**


设置动画播放模式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| [ArkUI_AnimationPlayMode](capi-native-type-visual-h.md#arkui_animationplaymode) value | 动画播放模式。默认值：[ARKUI_ANIMATION_PLAY_MODE_NORMAL](capi-native-type-visual-h.md#arkui_animationplaymode)。ARKUI_ANIMATION_PLAY_MODE_NORMAL表示正向播放，ARKUI_ANIMATION_PLAY_MODE_REVERSE表示反向播放，ARKUI_ANIMATION_PLAY_MODE_ALTERNATE表示交替正反向播放，ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE表示交替反向和正向播放，奇数次反向，偶数次正向。<br>value值异常时，操作无效。 |

### OH_ArkUI_AnimateOption_SetExpectedFrameRateRange()

```c
void OH_ArkUI_AnimateOption_SetExpectedFrameRateRange(ArkUI_AnimateOption* option, ArkUI_ExpectedFrameRateRange* value)
```

**描述：**


设置动画的期望帧率。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* value | 动画的期望帧率，单位为帧/秒（fps）。<br>value为NULL时，操作无效。 |

### OH_ArkUI_AnimateOption_SetICurve()

```c
void OH_ArkUI_AnimateOption_SetICurve(ArkUI_AnimateOption* option, ArkUI_CurveHandle value)
```

**描述：**


设置动画的插值曲线。

> **说明：**
>
> 此方法优先于[OH_ArkUI_AnimateOption_SetCurve](#oh_arkui_animateoption_setcurve)生效。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，操作无效。 |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | 动画曲线参数。<br>value为NULL时，操作无效。 |

### OH_ArkUI_AnimateOption_GetICurve()

```c
ArkUI_CurveHandle OH_ArkUI_AnimateOption_GetICurve(ArkUI_AnimateOption* option)
```

**描述：**


获取动画的插值曲线。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* option | 动画效果参数。<br>option为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 动画的插值曲线。参数option异常时返回NULL。 |

### OH_ArkUI_KeyframeAnimateOption_Create()

```c
ArkUI_KeyframeAnimateOption* OH_ArkUI_KeyframeAnimateOption_Create(int32_t size)
```

**描述：**


创建关键帧动画参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t size | 关键帧动画状态数。取值范围：[0, +∞)，需要为正整数才能产生动画效果。<br>size小于0时返回NULL。 |

**返回：**

| 类型                               | 说明 |
|----------------------------------| -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* | 关键帧动画参数对象。size小于0时返回NULL，option异常时返回NULL。 |

### OH_ArkUI_KeyframeAnimateOption_Dispose()

```c
void OH_ArkUI_KeyframeAnimateOption_Dispose(ArkUI_KeyframeAnimateOption* option)
```

**描述：**


销毁关键帧动画参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数对象。<br>option为NULL时，操作无效。 |

### OH_ArkUI_KeyframeAnimateOption_SetDelay()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_SetDelay(ArkUI_KeyframeAnimateOption* option, int32_t value)
```

**描述：**


设置关键帧动画的整体延迟时间，单位为ms（毫秒），默认不延迟播放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t value | 动画延迟播放时间，单位为ms（毫秒）。取值范围：(-∞, +∞)。默认值：0，表示不延迟。value大于0为延迟播放，value小于0表示提前播放。对于value小于0的情况：当value的绝对值小于实际动画时长，动画将在开始后第一帧直接运动到value绝对值的时刻的状态；当value的绝对值大于等于实际动画时长，动画将在开始后第一帧直接运动到终点状态。其中实际动画时长等于单次动画时长乘以动画播放次数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。可能原因：option为NULL。解决措施：请确保option为有效的动画参数对象指针。 |

### OH_ArkUI_KeyframeAnimateOption_SetIterations()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_SetIterations(ArkUI_KeyframeAnimateOption* option, int32_t value)
```

**描述：**


设置关键帧动画播放次数。默认播放一次，设置为-1时表示无限次播放，设置为0时表示无动画效果。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t value | 动画播放次数。取值范围：[-1, +∞)，其中设置为0时不播放，-1表示无限次播放。默认值：1，表示播放一次。<br>value小于-1时，操作无效，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |


**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (*onFinish)(void* userData))
```

**描述：**


设置关键帧动画播放完成回调。当关键帧动画[ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)所有次数播放完成后调用。

**起始版本：** 12


**参数：**

| 参数项                                     | 描述 |
|-----------------------------------------| -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void* userData                          | 用户自定义对象指针。<br>不涉及异常值处理。 |
| void (\*onFinish)(void\* userData)                                | 回调函数。<br>userData：回调函数的入参，用户自定义对象指针。<br>onFinish为NULL时，操作无效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_KeyframeAnimateOption_SetExpectedFrameRate()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_SetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option, ArkUI_ExpectedFrameRateRange* frameRate)
```

**描述：**


设置关键帧动画期望帧率。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* frameRate | 关键帧动画的期望帧率。<br>frameRate为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_KeyframeAnimateOption_SetDuration()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_SetDuration(ArkUI_KeyframeAnimateOption* option, int32_t value, int32_t index)
```

**描述：**


设置关键帧动画某段关键帧动画的持续时间，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t value | 关键帧动画的持续时间，单位为ms（毫秒），默认值1000ms。取值范围：[0, +∞)。<br>value小于0时，按0处理。 |
| int32_t index | 状态索引值。取值范围：[0, size-1]，其中size为关键帧动画状态数。<br>index超出范围时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_KeyframeAnimateOption_SetCurve()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_SetCurve(ArkUI_KeyframeAnimateOption* option, ArkUI_CurveHandle value, int32_t index)
```

**描述：**


设置关键帧动画某段关键帧使用的动画曲线。

> **说明：**
>
> 由于[springMotion](#oh_arkui_curve_createspringmotion)、[responsiveSpringMotion](#oh_arkui_curve_createresponsivespringmotion)、[interpolatingSpring](#oh_arkui_curve_createinterpolatingspring)曲线时长不生效，故不支持这三种曲线。关键帧动画支持[springCurve](#oh_arkui_curve_createspringcurve)和[customCurve](#oh_arkui_curve_createcustomcurve)曲线。


**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | 该关键帧使用的动画曲线。默认值：[ARKUI_CURVE_EASE_IN_OUT](capi-native-type-visual-h.md#arkui_animationcurve)。 |
| int32_t index | 状态索引值。取值范围：[0, size-1]，其中size为关键帧动画状态数。<br>index小于0或index超出范围时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback(ArkUI_KeyframeAnimateOption* option, void* userData, void (*event)(void* userData), int32_t index)
```

**描述：**


设置关键帧时刻状态的闭包函数，即在该关键帧时刻要达到的状态。

**起始版本：** 12


**参数：**

| 参数项                                     | 描述 |
|-----------------------------------------| -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void* userData                          | 用户定义对象指针。<br>不涉及异常值处理。 |
| void (\*event)(void\* userData)                                   | 闭包函数。<br>userData：回调函数的入参，用户自定义对象指针。<br>event为NULL时，操作无效。 |
| int32_t index                           | 状态索引值。取值范围：[0, size-1]，其中size为关键帧动画状态数。<br>index小于0或index超出范围时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_KeyframeAnimateOption_GetDelay()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_GetDelay(ArkUI_KeyframeAnimateOption* option)
```

**描述：**


获取关键帧整体延迟时间，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 整体延迟时间，单位为ms（毫秒）。option异常时返回0。 |

### OH_ArkUI_KeyframeAnimateOption_GetIterations()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_GetIterations(ArkUI_KeyframeAnimateOption* option)
```

**描述：**


获取关键帧动画播放次数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 动画播放次数。option异常时返回0。 |

### OH_ArkUI_KeyframeAnimateOption_GetExpectedFrameRate()

```c
ArkUI_ExpectedFrameRateRange* OH_ArkUI_KeyframeAnimateOption_GetExpectedFrameRate(ArkUI_KeyframeAnimateOption* option)
```

**描述：**


获取关键帧动画参数的期望帧率。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回NULL。 |

**返回：**

| 类型                                | 说明 |
|-----------------------------------| -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* | 关键帧动画参数的期望帧率。option异常时返回NULL。 |

### OH_ArkUI_KeyframeAnimateOption_GetDuration()

```c
int32_t OH_ArkUI_KeyframeAnimateOption_GetDuration(ArkUI_KeyframeAnimateOption* option, int32_t index)
```

**描述：**


获取关键帧动画某段状态持续时间，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回0。 |
| int32_t index | 状态索引值。取值范围：[0, size-1]，其中size为关键帧动画状态数。<br>index不在取值范围内时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 持续时间，单位为ms（毫秒）。option异常时返回0。 |

### OH_ArkUI_KeyframeAnimateOption_GetCurve()

```c
ArkUI_CurveHandle OH_ArkUI_KeyframeAnimateOption_GetCurve(ArkUI_KeyframeAnimateOption* option, int32_t index)
```

**描述：**


获取关键帧动画某段状态动画曲线。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_KeyframeAnimateOption](capi-arkui-nativemodule-arkui-keyframeanimateoption.md)* option | 关键帧动画参数。<br>option为NULL时，返回NULL。 |
| int32_t index | 状态索引值。取值范围：[0, size-1]，其中size为关键帧动画状态数。<br>index不在取值范围内时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 动画曲线。参数异常时返回NULL。 |

### OH_ArkUI_AnimatorOption_Create()

```c
ArkUI_AnimatorOption* OH_ArkUI_AnimatorOption_Create(int32_t keyframeSize)
```

**描述：**


创建animator动画对象参数。

> **说明：**
>
> keyframeSize大于0时，动画插值起点默认是0，动画插值终点默认值是1。不支持设置。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t keyframeSize | 需要创建的关键帧个数。<br>keyframeSize小于0时返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* | animator动画对象参数指针。keyframeSize小于0时返回NULL，option异常时返回NULL。 |

### OH_ArkUI_AnimatorOption_Dispose()

```c
void OH_ArkUI_AnimatorOption_Dispose(ArkUI_AnimatorOption* option)
```

**描述：**


销毁animator动画对象参数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，操作无效。 |

### OH_ArkUI_AnimatorOption_SetDuration()

```c
int32_t OH_ArkUI_AnimatorOption_SetDuration(ArkUI_AnimatorOption* option, int32_t value)
```

**描述：**


设置animator动画播放的时长，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t value | 播放的时长，单位为ms（毫秒），默认值0ms。取值范围：[0, +∞)。<br>value小于0时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetDelay()

```c
int32_t OH_ArkUI_AnimatorOption_SetDelay(ArkUI_AnimatorOption* option, int32_t value)
```

**描述：**


设置animator动画延迟播放的时间，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t value | 动画延迟播放时间，单位为ms（毫秒）。取值范围：(-∞, +∞)。默认值：0，表示不延迟。value大于0为延迟播放，value小于0表示提前播放。对于value小于0的情况：当value的绝对值小于实际动画时长，动画将在开始后第一帧直接运动到value绝对值的时刻的状态；当value的绝对值大于等于实际动画时长，动画将在开始后第一帧直接运动到终点状态。其中实际动画时长等于单次动画时长乘以动画播放次数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetIterations()

```c
int32_t OH_ArkUI_AnimatorOption_SetIterations(ArkUI_AnimatorOption* option, int32_t value)
```

**描述：**


设置animator动画播放次数。默认播放一次，设置为-1时表示无限次播放，设置为0时表示无动画效果。

> **说明：**
>
> 设置为除-1外其他负数视为无效取值，无效取值动画默认播放1次。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| int32_t value | 取值范围：[-1, +∞)，其中设置为0时不播放，-1表示无限次播放。默认值：1（播放一次）。<br>value小于-1时，操作无效。 |


**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetFill()

```c
int32_t OH_ArkUI_AnimatorOption_SetFill(ArkUI_AnimatorOption* option, ArkUI_AnimationFillMode value)
```

**描述：**


设置组件在动画开始前和结束后保持的状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_AnimationFillMode](capi-native-type-visual-h.md#arkui_animationfillmode) value | 动画执行时组件在动画开始前和结束后的状态。默认值：[ARKUI_ANIMATION_FILL_MODE_FORWARDS](capi-native-type-visual-h.md#arkui_animationfillmode)。<br>ARKUI_ANIMATION_FILL_MODE_NONE（0）表示动画前后均恢复初始状态，ARKUI_ANIMATION_FILL_MODE_FORWARDS（1）表示动画结束后保持终点状态，ARKUI_ANIMATION_FILL_MODE_BACKWARDS（2）表示动画开始前保持起点状态，ARKUI_ANIMATION_FILL_MODE_BOTH（3）表示动画前后均保持对应状态。<br>value小于0时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetDirection()

```c
int32_t OH_ArkUI_AnimatorOption_SetDirection(ArkUI_AnimatorOption* option, ArkUI_AnimationDirection value)
```

**描述：**


设置animator动画播放方向。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_AnimationDirection](capi-native-type-visual-h.md#arkui_animationdirection) value | 动画播放方向。默认值：[ARKUI_ANIMATION_DIRECTION_NORMAL](capi-native-type-visual-h.md#arkui_animationdirection)。<br>ARKUI_ANIMATION_DIRECTION_NORMAL（0）表示正向播放，ARKUI_ANIMATION_DIRECTION_REVERSE（1）表示反向播放，ARKUI_ANIMATION_DIRECTION_ALTERNATE（2）表示交替正向和反向播放，奇数次正向，偶数次反向，ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE（3）表示交替反向和正向播放，奇数次反向，偶数次正向。<br>value超出取值范围时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetCurve()

```c
int32_t OH_ArkUI_AnimatorOption_SetCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value)
```

**描述：**


设置animator动画插值曲线。

> **说明：**
>
> 不支持[springCurve](#oh_arkui_curve_createspringcurve)、[springMotion](#oh_arkui_curve_createspringmotion)、[responsiveSpringMotion](#oh_arkui_curve_createresponsivespringmotion)、[interpolatingSpring](#oh_arkui_curve_createinterpolatingspring)、[customCurve](#oh_arkui_curve_createcustomcurve)动画曲线。


**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | 动画插值曲线。默认值：[ARKUI_CURVE_LINEAR](capi-native-type-visual-h.md#arkui_animationcurve)，建议使用[ARKUI_CURVE_EASE_IN_OUT](capi-native-type-visual-h.md#arkui_animationcurve)获得更平滑的动画效果。<br>value为NULL时，使用默认曲线[ARKUI_CURVE_LINEAR](capi-native-type-visual-h.md#arkui_animationcurve)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetBegin()

```c
int32_t OH_ArkUI_AnimatorOption_SetBegin(ArkUI_AnimatorOption* option, float value)
```

**描述：**


设置animator动画插值起点。

> **说明：**
>
> 当animator动画为关键帧动画时，此方法返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| float value | 动画插值起点，默认值0.0。取值范围：(-∞, +∞)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetEnd()

```c
int32_t OH_ArkUI_AnimatorOption_SetEnd(ArkUI_AnimatorOption* option, float value)
```

**描述：**


设置animator动画插值终点。

> **说明：**
>
> 当animator动画为关键帧动画时，此方法返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| float value | 动画插值终点。取值范围：(-∞, +∞)。默认值：1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange()

```c
int32_t OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange(ArkUI_AnimatorOption* option, ArkUI_ExpectedFrameRateRange* value)
```

**描述：**


设置animator动画期望的帧率范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* value | 期望的帧率范围对象。<br>value为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetKeyframe()

```c
int32_t OH_ArkUI_AnimatorOption_SetKeyframe(ArkUI_AnimatorOption* option, float time, float value, int32_t index)
```

**描述：**


设置animator动画关键帧参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| float time | 关键帧时间。取值范围：[0, 1], 各关键帧时间必须依次递增，即后一关键帧的time值大于前一关键帧的time值。默认值：按索引均匀分布（如第1帧为0.0，第2帧为0.5，第3帧为1.0）。<br>time小于0或time大于1时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| float value | 关键帧对应的插值目标值，表示动画在该关键帧时刻要达到的属性值。取值范围：(-∞, +∞)。 |
| int32_t index | 关键帧的索引值。<br>index小于0时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_SetKeyframeCurve()

```c
int32_t OH_ArkUI_AnimatorOption_SetKeyframeCurve(ArkUI_AnimatorOption* option, ArkUI_CurveHandle value, int32_t index)
```

**描述：**


设置animator动画关键帧曲线类型。

> **说明：**
>
> 不支持[springCurve](#oh_arkui_curve_createspringcurve)、[springMotion](#oh_arkui_curve_createspringmotion)、[responsiveSpringMotion](#oh_arkui_curve_createresponsivespringmotion)、[interpolatingSpring](#oh_arkui_curve_createinterpolatingspring)、[customCurve](#oh_arkui_curve_createcustomcurve)动画曲线。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) value | 动画插值曲线。默认值：NULL，表示线性插值。 |
| int32_t index | 关键帧的索引值。取值范围：[0, keyframeSize-1]，其中keyframeSize为关键帧个数。<br>index超出取值范围时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_GetDuration()

```c
int32_t OH_ArkUI_AnimatorOption_GetDuration(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画播放的时长，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。<br>option为NULL时，返回-1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 动画播放的时长，单位为ms（毫秒）。option异常时返回0。 |

### OH_ArkUI_AnimatorOption_GetDelay()

```c
int32_t OH_ArkUI_AnimatorOption_GetDelay(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画延迟播放时长，单位为ms（毫秒）。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。option为NULL时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 动画延迟播放时长，单位为ms（毫秒）。option异常时返回0。 |

### OH_ArkUI_AnimatorOption_GetIterations()

```c
int32_t OH_ArkUI_AnimatorOption_GetIterations(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画播放次数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 动画播放次数。option异常时返回0。 |

### OH_ArkUI_AnimatorOption_GetFill()

```c
ArkUI_AnimationFillMode OH_ArkUI_AnimatorOption_GetFill(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画执行时组件在动画开始前和结束后的状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。option为NULL时，返回-1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_AnimationFillMode](capi-native-type-visual-h.md#arkui_animationfillmode) | 动画执行时组件在动画开始前和结束后的状态。返回值包括：ARKUI_ANIMATION_FILL_MODE_NONE（0，播放完成后恢复初始状态）、ARKUI_ANIMATION_FILL_MODE_FORWARDS（1，播放完成后保持终点状态）、ARKUI_ANIMATION_FILL_MODE_BACKWARDS（2，延时播放时保持起点状态）、ARKUI_ANIMATION_FILL_MODE_BOTH（3，同时应用FORWARDS和BACKWARDS效果）。option异常时返回-1。 |

### OH_ArkUI_AnimatorOption_GetDirection()

```c
ArkUI_AnimationDirection OH_ArkUI_AnimatorOption_GetDirection(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画播放方向。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_AnimationDirection](capi-native-type-visual-h.md#arkui_animationdirection) | 动画播放方向。返回值包括：ARKUI_ANIMATION_DIRECTION_NORMAL（0，正向播放）、ARKUI_ANIMATION_DIRECTION_REVERSE（1，反向播放）、ARKUI_ANIMATION_DIRECTION_ALTERNATE（2，交替正向和反向播放，奇数次正向，偶数次反向）、ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE（3，交替反向和正向播放，奇数次反向，偶数次正向）。option异常时返回-1。 |

### OH_ArkUI_AnimatorOption_GetCurve()

```c
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetCurve(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画插值曲线。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 动画插值曲线。option异常时返回NULL。 |

### OH_ArkUI_AnimatorOption_GetBegin()

```c
float OH_ArkUI_AnimatorOption_GetBegin(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画插值起点。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 动画插值起点。option异常时返回0.0。 |

### OH_ArkUI_AnimatorOption_GetEnd()

```c
float OH_ArkUI_AnimatorOption_GetEnd(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画插值终点。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 动画插值终点。option异常时返回0.0。 |

### OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange()

```c
ArkUI_ExpectedFrameRateRange* OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange(ArkUI_AnimatorOption* option)
```

**描述：**


获取animator动画期望的帧率范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ExpectedFrameRateRange](capi-arkui-nativemodule-arkui-expectedframeraterange.md)* | 期望的帧率范围对象指针。函数参数异常时返回NULL。 |

### OH_ArkUI_AnimatorOption_GetKeyframeTime()

```c
float OH_ArkUI_AnimatorOption_GetKeyframeTime(ArkUI_AnimatorOption* option, int32_t index)
```

**描述：**


获取animator动画关键帧时间，取值范围[0, 1]，为归一化时间比例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。 |
| int32_t index | 关键帧的索引值。取值范围：[0, keyframeSize-1]，其中keyframeSize为关键帧个数。<br>index超出范围时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 关键帧时间，取值范围[0, 1]，为归一化时间比例。 |

### OH_ArkUI_AnimatorOption_GetKeyframeValue()

```c
float OH_ArkUI_AnimatorOption_GetKeyframeValue(ArkUI_AnimatorOption* option, int32_t index)
```

**描述：**


获取animator动画关键帧数值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回0.0。 |
| int32_t index | 关键帧的索引值。取值范围：[0, keyframeSize-1]，其中keyframeSize为关键帧个数。<br>index超出范围时，返回0.0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 关键帧数值。 |

### OH_ArkUI_AnimatorOption_GetKeyframeCurve()

```c
ArkUI_CurveHandle OH_ArkUI_AnimatorOption_GetKeyframeCurve(ArkUI_AnimatorOption* option, int32_t index)
```

**描述：**


获取animator动画关键帧动画插值曲线。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回空指针。 |
| int32_t index | 关键帧的索引值。取值范围：[0, keyframeSize-1]，其中keyframeSize为关键帧个数。<br>index超出范围时，返回空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 动画插值曲线。函数参数异常时返回NULL。 |

### OH_ArkUI_AnimatorEvent_GetUserData()

```c
void* OH_ArkUI_AnimatorEvent_GetUserData(ArkUI_AnimatorEvent* event)
```

**描述：**


获取动画事件对象中的用户自定义对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorEvent](capi-arkui-nativemodule-arkui-animatorevent.md)* event | 动画事件对象。event为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 用户自定义对象。 |

### OH_ArkUI_AnimatorOnFrameEvent_GetUserData()

```c
void* OH_ArkUI_AnimatorOnFrameEvent_GetUserData(ArkUI_AnimatorOnFrameEvent* event)
```

**描述：**

获取动画的帧事件中的用户自定义对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOnFrameEvent](capi-arkui-nativemodule-arkui-animatoronframeevent.md)* event | 动画事件对象。event为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 用户自定义对象。 |

### OH_ArkUI_AnimatorOnFrameEvent_GetValue()

```c
float OH_ArkUI_AnimatorOnFrameEvent_GetValue(ArkUI_AnimatorOnFrameEvent* event)
```

**描述：**


获取动画帧回调事件对象中的插值结果。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOnFrameEvent](capi-arkui-nativemodule-arkui-animatoronframeevent.md)* event | 动画事件对象。event为NULL时，返回0.0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 动画插值结果。<br>**说明：** <br>在动画过程中，插值结果根据动画参数在插值起点[OH_ArkUI_AnimatorOption_SetBegin](#oh_arkui_animatoroption_setbegin)和插值终点[OH_ArkUI_AnimatorOption_SetEnd](#oh_arkui_animatoroption_setend)间变化。 |

### OH_ArkUI_AnimatorOption_RegisterOnFrameCallback()

```c
int32_t OH_ArkUI_AnimatorOption_RegisterOnFrameCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorOnFrameEvent* event))
```

**描述：**


设置animator动画接收到帧时回调。

**起始版本：** 12


**参数：**

| 参数项                              | 描述 |
|----------------------------------| -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void* userData                         | 用户自定义参数。 |
| void (\*callback)(ArkUI_AnimatorOnFrameEvent\* event)                         | 回调函数。<br>- event：回调函数的入参，动画事件对象。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_RegisterOnFinishCallback()

```c
int32_t OH_ArkUI_AnimatorOption_RegisterOnFinishCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorEvent* event))
```

**描述：**


设置animator动画完成时回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void* userData | 用户自定义参数。 |
| void (\*callback)(ArkUI_AnimatorEvent\* event) | 回调函数。 <br>- event：回调函数的入参，动画事件对象。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_RegisterOnCancelCallback()

```c
int32_t OH_ArkUI_AnimatorOption_RegisterOnCancelCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorEvent* event))
```

**描述：**


设置animator动画被取消时回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回 [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void* userData | 用户自定义参数。 |
| void (\*callback)(ArkUI_AnimatorEvent\* event) | 回调函数。 <br>- event：回调函数的入参，动画事件对象。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback()

```c
int32_t OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback(ArkUI_AnimatorOption* option, void* userData, void (*callback)(ArkUI_AnimatorEvent* event))
```

**描述：**


设置animator动画重复时回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画对象参数。option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| void* userData | 用户自定义参数。 |
| void (\*callback)(ArkUI_AnimatorEvent\* event) | 回调函数。<br>- event：回调函数的入参，动画事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t  | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_Animator_ResetAnimatorOption()

```c
int32_t OH_ArkUI_Animator_ResetAnimatorOption(ArkUI_AnimatorHandle animatorHandle, ArkUI_AnimatorOption* option)
```

**描述：**


重置animator动画的配置参数。

**起始版本：** 12


**参数：**

| 参数项                                                                             | 描述 |
|---------------------------------------------------------------------------------| -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | animator动画对象。<br>animatorHandle为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_AnimatorOption](capi-arkui-nativemodule-arkui-animatoroption.md)* option | animator动画参数。<br>option为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_Animator_Play()

```c
int32_t OH_ArkUI_Animator_Play(ArkUI_AnimatorHandle animatorHandle)
```

**描述：**


启动animator动画。需要在主线程上调用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | animator动画对象。animatorHandle为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_Animator_Finish()

```c
int32_t OH_ArkUI_Animator_Finish(ArkUI_AnimatorHandle animatorHandle)
```

**描述：**


结束animator动画，动画将跳到终点状态后停止。与[OH_ArkUI_Animator_Cancel](#oh_arkui_animator_cancel)的区别：Cancel会立即中断动画并回到初始状态，Finish会让动画直接跳到终点状态后停止。需要在主线程上调用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | animator动画对象。animatorHandle为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_Animator_Pause()

```c
int32_t OH_ArkUI_Animator_Pause(ArkUI_AnimatorHandle animatorHandle)
```

**描述：**


暂停animator动画。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | animator动画对象。animatorHandle为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_Animator_Cancel()

```c
int32_t OH_ArkUI_Animator_Cancel(ArkUI_AnimatorHandle animatorHandle)
```

**描述：**


取消animator动画。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | animator动画对象。animatorHandle为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_Animator_Reverse()

```c
int32_t OH_ArkUI_Animator_Reverse(ArkUI_AnimatorHandle animatorHandle)
```

**描述：**


以相反的顺序播放animator动画。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimatorHandle](capi-arkui-nativemodule-arkui-animator8h.md) animatorHandle | animator动画对象。animatorHandle为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_Curve_CreateCurveByType()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCurveByType(ArkUI_AnimationCurve curve)
```

**描述：**


插值曲线的初始化函数，可以根据入参创建一个插值曲线对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AnimationCurve](capi-native-type-visual-h.md#arkui_animationcurve) curve | 曲线类型。curve值异常时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 插值曲线对象指针，用于动画属性值的插值计算。curve值异常时返回NULL。 |

### OH_ArkUI_Curve_CreateStepsCurve()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateStepsCurve(int32_t count, bool end)
```

**描述：**


构造阶梯曲线对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t count | 阶梯的数量，需要为正整数，取值范围：[1, +∞)。<br>count值异常时，操作无效。 |
| bool end | 在每个间隔的起点或是终点发生阶跃变化。true：在终点发生阶跃变化。false：在起点发生阶跃变化。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 阶梯曲线对象指针。如果参数异常返回NULL。 |

### OH_ArkUI_Curve_CreateCubicBezierCurve()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCubicBezierCurve(float x1, float y1, float x2, float y2)
```

**描述：**


构造三阶贝塞尔曲线对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float x1 | 确定贝塞尔曲线第一点横坐标，取值范围：[0, 1]。设置的值小于0时，按0处理；设置的值大于1时，按1处理。 |
| float y1 | 确定贝塞尔曲线第一点纵坐标。取值范围：(-∞, +∞)。 |
| float x2 | 确定贝塞尔曲线第二点横坐标，取值范围：[0, 1]。设置的值小于0时，按0处理；设置的值大于1时，按1处理。 |
| float y2 | 确定贝塞尔曲线第二点纵坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 三阶贝塞尔曲线对象指针。 |

### OH_ArkUI_Curve_CreateSpringCurve()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringCurve(float velocity, float mass, float stiffness, float damping)
```

**描述：**


构造弹簧曲线对象，曲线形状由弹簧参数决定，动画时长受动画参数中的时长参数控制。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float velocity | 初始速度。是由外部因素对弹性动效产生的影响参数，其目的是保证对象从之前的运动状态平滑地过渡到弹性动效。该速度是归一化速度，其值等于动画开始时的实际速度除以动画属性改变值。 |
| float mass | 质量。弹性系统的受力对象，会对弹性系统产生惯性影响。质量越大，震荡的幅度越大，恢复到平衡位置的速度越慢。取值范围：[0, +∞)。<br>value小于等于0时，按1处理。 |
| float stiffness | 刚度。是物体抵抗施加的力而形变的程度。在弹性系统中，刚度越大，抵抗变形的能力越强，恢复到平衡位置的速度就越快。取值范围：[0, +∞)。<br>value小于等于0时，按1处理。 |
| float damping | 阻尼。用于描述系统在受到扰动后震荡及衰减的情形。阻尼越大，弹性运动的震荡次数越少、震荡幅度越小。取值范围：[0, +∞)。<br>value小于等于0时，按1处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 插值器弹簧曲线的插值对象指针，用于基于弹簧物理模型进行插值计算，生成从0到1的动画曲线。如果参数异常返回NULL。 |

### OH_ArkUI_Curve_CreateSpringMotion()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateSpringMotion(float response, float dampingFraction, float overlapDuration)
```

**描述：**


构造弹性动画曲线对象。如果对同一对象的同一属性进行多个弹性动画，每个动画会替换掉前一个动画，并继承之前的速度。

> **说明：**
>
> 动画时间由曲线参数决定，不受[animation](#oh_arkui_transitioneffect_setanimation)、[animateTo](./capi-arkui-nativemodule-arkui-nativeanimateapi-1.md#animateto)中的duration参数控制。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float response | 弹簧自然振动周期，决定弹簧复位的速度，单位为s（秒）。取值范围：(0, +∞)。<br>参数小于等于0时，按0.55处理。 |
| float dampingFraction | 阻尼系数。大于0小于1的值为欠阻尼，运动过程中会超出目标值；等于1为临界阻尼；大于1为过阻尼，运动过程中逐渐趋于目标值。取值范围：(0, +∞)。<br>参数小于等于0时，按0.825处理。 |
| float overlapDuration | 弹性动画衔接时长，单位为s（秒）。发生动画继承时，如果前后两个弹性动画response不一致，response参数会在overlapDuration时间内平滑过渡。取值范围：[0, +∞)。<br>参数小于0时，按0处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 弹性动画曲线的插值对象指针，使用响应式参数构造曲线，支持动画间的速度继承。如果参数异常返回NULL。 |

### OH_ArkUI_Curve_CreateResponsiveSpringMotion()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateResponsiveSpringMotion(float response, float dampingFraction, float overlapDuration)
```

**描述：**


构造弹性跟手动画曲线对象，是springMotion的一种特例，仅默认参数不同，可与springMotion混合使用。

> **说明：**
>
> 动画时间由曲线参数决定，不受[animation](#oh_arkui_transitioneffect_setanimation)、[animateTo](./capi-arkui-nativemodule-arkui-nativeanimateapi-1.md#animateto)中的duration参数控制。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float response | 弹簧自然振动周期，决定弹簧复位的速度，单位为s（秒）。取值范围：(0, +∞)。<br>参数小于等于0时，按0.15处理。 |
| float dampingFraction | 阻尼系数。大于0小于1的值为欠阻尼，运动过程中会超出目标值；等于1为临界阻尼；大于1为过阻尼，运动过程中逐渐趋于目标值。取值范围：[0, +∞)。<br>参数小于0时，按0.86处理。 |
| float overlapDuration | 弹性动画衔接时长，单位为s（秒）。发生动画继承时，如果前后两个弹性动画response不一致，response参数会在overlapDuration时间内平滑过渡。取值范围：[0, +∞)。<br>参数小于0时，按0.25处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 响应式弹簧动画曲线的插值对象指针，是springMotion的一种特例，仅默认参数不同。如果参数异常返回NULL。 |

### OH_ArkUI_Curve_CreateInterpolatingSpring()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateInterpolatingSpring(float velocity, float mass, float stiffness, float damping)
```

**描述：**


构造插值器弹簧曲线对象，生成一条从0到1的动画曲线，实际动画值根据曲线进行插值计算。

> **说明：**
>
> 动画时间由曲线参数决定，不受[animation](#oh_arkui_transitioneffect_setanimation)、[animateTo](./capi-arkui-nativemodule-arkui-nativeanimateapi-1.md#animateto)中的duration参数控制。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float velocity | 初始速度。外部因素对弹性动效产生的影响参数，目的是保证对象从之前的运动状态平滑地过渡到弹性动效。该速度是归一化速度，其值等于动画开始时的实际速度除以动画属性改变值。取值范围：(-∞, +∞)。 |
| float mass | 质量。弹性系统的受力对象，会对弹性系统产生惯性影响。质量越大，震荡的幅度越大，恢复到平衡位置的速度越慢。取值范围：[0, +∞)。<br>value小于等于0时，按1处理。 |
| float stiffness | 刚度。表示物体抵抗施加的力而形变的程度。刚度越大，抵抗变形的能力越强，恢复到平衡位置的速度越快。取值范围：[0, +∞)。<br>value小于等于0时，按1处理。 |
| float damping | 阻尼。用于描述系统在受到扰动后震荡及衰减的情形。阻尼越大，弹性运动的震荡次数越少、震荡幅度越小。取值范围：[0, +∞)。<br>value小于等于0时，按1处理。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 曲线的插值对象指针。如果参数异常返回NULL。 |

### OH_ArkUI_Curve_CreateCustomCurve()

```c
ArkUI_CurveHandle OH_ArkUI_Curve_CreateCustomCurve(void* userData, float (*interpolate)(float fraction, void* userdata))
```

**描述：**


构造自定义曲线对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* userData | 用户自定义数据。 |
| float (\*interpolate)(float fraction, void\* userdata) | 用户自定义的插值回调函数。fraction为动画开始时的插值输入x值。取值范围：[0,1]。返回值为曲线的y值。取值范围：[0,1]。fraction等于0时，返回值为0对应动画起点，返回不为0，动画在起点处有跳变效果。fraction等于1时，返回值为1对应动画终点，返回值不为1将导致动画的终值不是状态变量的值，出现大于或者小于状态变量值，再跳变到状态变量值的效果。 |

**返回：**

| 类型                    | 说明 |
|-----------------------| -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) | 曲线的插值对象指针。如果参数异常返回NULL。 |

### OH_ArkUI_Curve_DisposeCurve()

```c
void OH_ArkUI_Curve_DisposeCurve(ArkUI_CurveHandle curveHandle)
```

**描述：**


销毁自定义曲线对象。

**起始版本：** 12


**参数：**

| 参数项                                                                 | 描述 |
|---------------------------------------------------------------------| -- |
| [ArkUI_CurveHandle](capi-arkui-nativemodule-arkui-curve8h.md) curveHandle | 曲线的插值对象指针。<br>curveHandle为NULL时，操作无效。 |

### OH_ArkUI_CreateOpacityTransitionEffect()

```c
ArkUI_TransitionEffect* OH_ArkUI_CreateOpacityTransitionEffect(float opacity)
```

**描述：**


创建组件转场时的透明度效果对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| float opacity | 透明度，取值范围为[0, 1]。默认值为1。设置小于0的非法值按0处理，大于1的非法值按1处理，1表示不透明，0表示完全透明。 |

**返回：**

| 类型                          | 说明 |
|-----------------------------| -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | 组件转场时的透明度效果对象。 |

### OH_ArkUI_CreateTranslationTransitionEffect()

```c
ArkUI_TransitionEffect* OH_ArkUI_CreateTranslationTransitionEffect(ArkUI_TranslationOptions* translate)
```

**描述：**


创建组件转场时的平移效果对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TranslationOptions](capi-arkui-nativemodule-arkui-translationoptions.md)* translate | 组件转场时的平移参数对象。<br>translate为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | 组件转场时的平移效果对象。如果参数异常返回NULL。 |

### OH_ArkUI_CreateScaleTransitionEffect()

```c
ArkUI_TransitionEffect* OH_ArkUI_CreateScaleTransitionEffect(ArkUI_ScaleOptions* scale)
```

**描述：**


创建组件转场时的缩放效果对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ScaleOptions](capi-arkui-nativemodule-arkui-scaleoptions.md)* scale | 组件转场时的缩放参数对象。scale为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | 组件转场时的缩放效果对象。如果参数异常返回NULL。 |

### OH_ArkUI_CreateRotationTransitionEffect()

```c
ArkUI_TransitionEffect* OH_ArkUI_CreateRotationTransitionEffect(ArkUI_RotationOptions* rotate)
```

**描述：**


创建组件转场时的旋转效果对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_RotationOptions](capi-arkui-nativemodule-arkui-rotationoptions.md)* rotate | 组件转场时的旋转参数对象。rotate为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | 组件转场时的旋转效果对象。如果参数异常返回NULL。 |

### OH_ArkUI_CreateMovementTransitionEffect()

```c
ArkUI_TransitionEffect* OH_ArkUI_CreateMovementTransitionEffect(ArkUI_TransitionEdge edge)
```

**描述：**


创建组件平移效果对象，通过指定边缘方向（上、下、左、右）控制组件的滑入滑出方向，适用于仅需指定滑动方向的简单场景。与OH_ArkUI_CreateTranslationTransitionEffect不同：后者支持自定义x/y/z方向的精确平移参数，适用于需要指定具体位移距离的场景。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TransitionEdge](capi-native-type-visual-h.md#arkui_transitionedge) edge | 组件平移的方向类型，决定组件出现和消失时的平移方向。edge值异常时，按[ARKUI_TRANSITION_EDGE_START](capi-native-type-visual-h.md#arkui_transitionedge)处理。<br>ARKUI_TRANSITION_EDGE_TOP（0）表示从上方滑入/滑出，ARKUI_TRANSITION_EDGE_BOTTOM（1）表示从下方滑入/滑出，ARKUI_TRANSITION_EDGE_START（2）表示从左侧滑入/滑出，ARKUI_TRANSITION_EDGE_END（3）表示从右侧滑入/滑出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | 组件转场时的平移效果对象。如果参数异常返回NULL。 |

### OH_ArkUI_CreateAsymmetricTransitionEffect()

```c
ArkUI_TransitionEffect* OH_ArkUI_CreateAsymmetricTransitionEffect(ArkUI_TransitionEffect* appear, ArkUI_TransitionEffect* disappear)
```

**描述：**


创建非对称的转场效果对象。

> **说明：**
>
> 如果不通过该函数构造[ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)，则表明该效果在组件出现和消失时均生效。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* appear | 组件出现时的转场效果。appear为NULL时，返回NULL。 |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* disappear | 组件消失时的转场效果。disappear为NULL时，返回NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | 非对称的转场效果对象。如果参数异常返回NULL。 |

### OH_ArkUI_CreateIdentityTransitionEffect()

```c
ArkUI_TransitionEffect* OH_ArkUI_CreateIdentityTransitionEffect(void)
```

**描述：**


创建无转场效果对象。

**起始版本：** 26.0.0


**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* | 创建的无转场效果对象指针。调用者需要调用[OH_ArkUI_TransitionEffect_Dispose](#oh_arkui_transitioneffect_dispose)释放该对象。 |

### OH_ArkUI_TransitionEffect_Dispose()

```c
void OH_ArkUI_TransitionEffect_Dispose(ArkUI_TransitionEffect* effect)
```

**描述：**


销毁转场效果对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* effect | 转场效果对象。<br>effect为NULL时，操作无效。 |

### OH_ArkUI_TransitionEffect_Combine()

```c
int32_t OH_ArkUI_TransitionEffect_Combine(ArkUI_TransitionEffect* firstEffect, ArkUI_TransitionEffect* secondEffect)
```

**描述：**


设置转场效果链式组合，以形成包含多种转场效果的TransitionEffect。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* firstEffect | 链式组合的前一个转场效果，将与secondEffect组合形成包含多种转场效果的TransitionEffect。<br>firstEffect为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* secondEffect | 需要组合的后一个转场效果，将与firstEffect链式组合形成包含多种转场效果的TransitionEffect。<br>secondEffect为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_TransitionEffect_SetAnimation()

```c
int32_t OH_ArkUI_TransitionEffect_SetAnimation(ArkUI_TransitionEffect* effect, ArkUI_AnimateOption* animation)
```

**描述：**


设置转场效果动画参数。

> **说明：**
>
> 如果通过[OH_ArkUI_TransitionEffect_Combine](#oh_arkui_transitioneffect_combine)进行转场效果的组合，前一转场效果的动画参数也可用于后一转场效果。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TransitionEffect](capi-arkui-nativemodule-arkui-transitioneffect.md)* effect | 要设置动画参数的转场效果对象。<br>effect为NULL时，返回错误码[ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode)。 |
| [ArkUI_AnimateOption](capi-arkui-nativemodule-arkui-animateoption.md)* animation | 属性显示动画效果相关参数。<br>animation为NULL时，设置动画参数为空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) 函数参数异常。 |


