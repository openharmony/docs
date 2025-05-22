# native_animate.h


## 概述

提供ArkUI在Native侧的动画接口定义集合。

**库：** libace_ndk.z.so

**引用文件：** <arkui/native_animate.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) | 设置动画的期望帧率。  | 
| struct&nbsp;&nbsp;[ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) | 动画播放完成回调类型。  | 
| struct&nbsp;&nbsp;[ArkUI_NativeAnimateAPI_1](_ark_u_i___native_animate_a_p_i__1.md) | ArkUI提供的Native侧动画接口集合。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) | 设置动画效果相关参数。  | 
| typedef struct ArkUI_Curve \* [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) | 定义曲线的插值对象指针定义。  | 
| typedef struct [ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) [ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) | 定义关键帧动画参数对象。  | 
| typedef struct [ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) [ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) | 定义animator动画参数对象。  | 
| typedef struct ArkUI_Animator \* [ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) | 定义animator动画对象指针。  | 
| typedef struct [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) | 定义transition属性配置转场参数对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \* [OH_ArkUI_AnimateOption_Create](_ark_u_i___native_module.md#oh_arkui_animateoption_create) () | 创建动画效果参数。  | 
| void [OH_ArkUI_AnimateOption_Dispose](_ark_u_i___native_module.md#oh_arkui_animateoption_dispose) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 销毁动画效果参数指针。  | 
| int32_t [OH_ArkUI_AnimateOption_GetDuration](_ark_u_i___native_module.md#oh_arkui_animateoption_getduration) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画持续时间，单位为ms(毫秒)。  | 
| float [OH_ArkUI_AnimateOption_GetTempo](_ark_u_i___native_module.md#oh_arkui_animateoption_gettempo) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画播放速度。  | 
| [ArkUI_AnimationCurve](_ark_u_i___native_module.md#arkui_animationcurve) [OH_ArkUI_AnimateOption_GetCurve](_ark_u_i___native_module.md#oh_arkui_animateoption_getcurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画曲线。  | 
| int32_t [OH_ArkUI_AnimateOption_GetDelay](_ark_u_i___native_module.md#oh_arkui_animateoption_getdelay) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画延迟播放时间，单位为ms(毫秒)。  | 
| int32_t [OH_ArkUI_AnimateOption_GetIterations](_ark_u_i___native_module.md#oh_arkui_animateoption_getiterations) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画播放次数。  | 
| [ArkUI_AnimationPlayMode](_ark_u_i___native_module.md#arkui_animationplaymode) [OH_ArkUI_AnimateOption_GetPlayMode](_ark_u_i___native_module.md#oh_arkui_animateoption_getplaymode) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画播放模式。  | 
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimateOption_GetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animateoption_getexpectedframeraterange) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画的期望帧率。  | 
| void [OH_ArkUI_AnimateOption_SetDuration](_ark_u_i___native_module.md#oh_arkui_animateoption_setduration) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, int32_t value) | 设置动画持续时间。  | 
| void [OH_ArkUI_AnimateOption_SetTempo](_ark_u_i___native_module.md#oh_arkui_animateoption_settempo) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, float value) | 设置动画播放速度。  | 
| void [OH_ArkUI_AnimateOption_SetCurve](_ark_u_i___native_module.md#oh_arkui_animateoption_setcurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_AnimationCurve](_ark_u_i___native_module.md#arkui_animationcurve) value) | 设置动画曲线。  | 
| void [OH_ArkUI_AnimateOption_SetDelay](_ark_u_i___native_module.md#oh_arkui_animateoption_setdelay) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, int32_t value) | 设置动画延迟播放时间。  | 
| void [OH_ArkUI_AnimateOption_SetIterations](_ark_u_i___native_module.md#oh_arkui_animateoption_setiterations) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, int32_t value) | 设置动画播放次数。  | 
| void [OH_ArkUI_AnimateOption_SetPlayMode](_ark_u_i___native_module.md#oh_arkui_animateoption_setplaymode) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_AnimationPlayMode](_ark_u_i___native_module.md#arkui_animationplaymode) value) | 设置动画播放模式。  | 
| void [OH_ArkUI_AnimateOption_SetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animateoption_setexpectedframeraterange) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | 设置动画的期望帧率。  | 
| void [OH_ArkUI_AnimateOption_SetICurve](_ark_u_i___native_module.md#oh_arkui_animateoption_seticurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) value) | 设置动画的动画曲线。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_AnimateOption_GetICurve](_ark_u_i___native_module.md#oh_arkui_animateoption_geticurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画的动画曲线。  | 
| [ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \* [OH_ArkUI_KeyframeAnimateOption_Create](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_create) (int32_t size) | 获取关键帧动画参数。  | 
| void [OH_ArkUI_KeyframeAnimateOption_Dispose](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_dispose) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option) | 销毁关键帧动画参数。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetDelay](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_setdelay) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, int32_t value) | 设置关键帧动画的整体延时时间，单位为ms(毫秒)，默认不延时播放。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetIterations](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_setiterations) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, int32_t value) | 设置关键帧动画的动画播放次数。默认播放一次，设置为-1时表示无限次播放。设置为0时表示无动画效果。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_RegisterOnFinishCallback](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_registeronfinishcallback) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, void \*userData, void(\*onFinish)(void \*userData)) | 设置关键帧动画播放完成回调。当keyframe动画所有次数播放完成后调用。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetDuration](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_setduration) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, int32_t value, int32_t index) | 设置关键帧动画某段关键帧动画的持续时间，单位为毫秒。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_SetCurve](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_setcurve) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) value, int32_t index) | 设置关键帧动画某段关键帧使用的动画曲线。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_RegisterOnEventCallback](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_registeroneventcallback) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, void \*userData, void(\*event)(void \*userData), int32_t index) | 设置关键帧时刻状态的闭包函数，即在该关键帧时刻要达到的状态。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_GetDelay](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_getdelay) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option) | 获取关键帧整体延时时间。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_GetIterations](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_getiterations) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option) | 获取关键帧动画播放次数。  | 
| int32_t [OH_ArkUI_KeyframeAnimateOption_GetDuration](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_getduration) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, int32_t index) | 获取关键帧动画某段状态持续时间。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_KeyframeAnimateOption_GetCurve](_ark_u_i___native_module.md#oh_arkui_keyframeanimateoption_getcurve) ([ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option, int32_t index) | 获取关键帧动画某段状态动画曲线。  | 
| [ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \* [OH_ArkUI_AnimatorOption_Create](_ark_u_i___native_module.md#oh_arkui_animatoroption_create) (int32_t keyframeSize) | 创建animator动画对象参数。  | 
| void [OH_ArkUI_AnimatorOption_Dispose](_ark_u_i___native_module.md#oh_arkui_animatoroption_dispose) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 销毁animator动画对象参数。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetDuration](_ark_u_i___native_module.md#oh_arkui_animatoroption_setduration) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, int32_t value) | 设置animator动画播放的时长，单位毫秒。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetDelay](_ark_u_i___native_module.md#oh_arkui_animatoroption_setdelay) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, int32_t value) | 设置animator动画延时播放时长，单位毫秒。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetIterations](_ark_u_i___native_module.md#oh_arkui_animatoroption_setiterations) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, int32_t value) | 设置animator动画播放次数。设置为0时不播放，设置为-1时无限次播放。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetFill](_ark_u_i___native_module.md#oh_arkui_animatoroption_setfill) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, [ArkUI_AnimationFillMode](_ark_u_i___native_module.md#arkui_animationfillmode) value) | 设置animator动画执行后是否恢复到初始状态。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetDirection](_ark_u_i___native_module.md#oh_arkui_animatoroption_setdirection) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, [ArkUI_AnimationDirection](_ark_u_i___native_module.md#arkui_animationdirection) value) | 设置animator动画播放方向。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetCurve](_ark_u_i___native_module.md#oh_arkui_animatoroption_setcurve) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) value) | 设置animator动画插值曲线。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetBegin](_ark_u_i___native_module.md#oh_arkui_animatoroption_setbegin) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, float value) | 设置animator动画插值起点。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetEnd](_ark_u_i___native_module.md#oh_arkui_animatoroption_setend) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, float value) | 设置animator动画插值终点。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animatoroption_setexpectedframeraterange) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | 设置animator动画期望的帧率范围。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetKeyframe](_ark_u_i___native_module.md#oh_arkui_animatoroption_setkeyframe) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, float time, float value, int32_t index) | 设置animator动画关键帧参数。  | 
| int32_t [OH_ArkUI_AnimatorOption_SetKeyframeCurve](_ark_u_i___native_module.md#oh_arkui_animatoroption_setkeyframecurve) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) value, int32_t index) | 设置animator动画关键帧曲线类型。  | 
| int32_t [OH_ArkUI_AnimatorOption_GetDuration](_ark_u_i___native_module.md#oh_arkui_animatoroption_getduration) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画播放的时长。  | 
| int32_t [OH_ArkUI_AnimatorOption_GetDelay](_ark_u_i___native_module.md#oh_arkui_animatoroption_getdelay) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画延时播放时长。  | 
| int32_t [OH_ArkUI_AnimatorOption_GetIterations](_ark_u_i___native_module.md#oh_arkui_animatoroption_getiterations) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画播放次数。  | 
| [ArkUI_AnimationDirection](_ark_u_i___native_module.md#arkui_animationdirection) [OH_ArkUI_AnimatorOption_GetDirection](_ark_u_i___native_module.md#oh_arkui_animatoroption_getdirection) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画播放方向。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_AnimatorOption_GetCurve](_ark_u_i___native_module.md#oh_arkui_animatoroption_getcurve) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画插值曲线。  | 
| float [OH_ArkUI_AnimatorOption_GetBegin](_ark_u_i___native_module.md#oh_arkui_animatoroption_getbegin) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画插值起点。  | 
| float [OH_ArkUI_AnimatorOption_GetEnd](_ark_u_i___native_module.md#oh_arkui_animatoroption_getend) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画插值终点。  | 
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimatorOption_GetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animatoroption_getexpectedframeraterange) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 获取animator动画期望的帧率范围。  | 
| float [OH_ArkUI_AnimatorOption_GetKeyframeTime](_ark_u_i___native_module.md#oh_arkui_animatoroption_getkeyframetime) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, int32_t index) | 获取animator动画关键帧时间。  | 
| float [OH_ArkUI_AnimatorOption_GetKeyframeValue](_ark_u_i___native_module.md#oh_arkui_animatoroption_getkeyframevalue) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, int32_t index) | 获取animator动画关键帧数值。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_AnimatorOption_GetKeyframeCurve](_ark_u_i___native_module.md#oh_arkui_animatoroption_getkeyframecurve) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, int32_t index) | 获取animator动画关键帧动画插值曲线。  | 
| void \* [OH_ArkUI_AnimatorEvent_GetUserData](_ark_u_i___native_module.md#oh_arkui_animatorevent_getuserdata) (ArkUI_AnimatorEvent \*event) | 获取动画事件对象中的用户自定义对象。  | 
| void \* [OH_ArkUI_AnimatorOnFrameEvent_GetUserData](_ark_u_i___native_module.md#oh_arkui_animatoronframeevent_getuserdata) (ArkUI_AnimatorOnFrameEvent \*event) | 获取动画事件对象中的用户自定义对象。  | 
| float [OH_ArkUI_AnimatorOnFrameEvent_GetValue](_ark_u_i___native_module.md#oh_arkui_animatoronframeevent_getvalue) (ArkUI_AnimatorOnFrameEvent \*event) | 获取动画事件对象中的当前进度。  | 
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnFrameCallback](_ark_u_i___native_module.md#oh_arkui_animatoroption_registeronframecallback) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorOnFrameEvent \*event)) | 设置animator动画接收到帧时回调。  | 
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnFinishCallback](_ark_u_i___native_module.md#oh_arkui_animatoroption_registeronfinishcallback) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorEvent \*event)) | 设置animator动画完成时回调。  | 
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnCancelCallback](_ark_u_i___native_module.md#oh_arkui_animatoroption_registeroncancelcallback) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorEvent \*event)) | 设置animator动画被取消时回调。  | 
| int32_t [OH_ArkUI_AnimatorOption_RegisterOnRepeatCallback](_ark_u_i___native_module.md#oh_arkui_animatoroption_registeronrepeatcallback) ([ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option, void \*userData, void(\*callback)(ArkUI_AnimatorEvent \*event)) | 设置animator动画重复时回调。  | 
| int32_t [OH_ArkUI_Animator_ResetAnimatorOption](_ark_u_i___native_module.md#oh_arkui_animator_resetanimatoroption) ([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator, [ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | 更新animator动画。  | 
| int32_t [OH_ArkUI_Animator_Play](_ark_u_i___native_module.md#oh_arkui_animator_play) ([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator) | 启动animator动画。  | 
| int32_t [OH_ArkUI_Animator_Finish](_ark_u_i___native_module.md#oh_arkui_animator_finish) ([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator) | 结束animator动画。  | 
| int32_t [OH_ArkUI_Animator_Pause](_ark_u_i___native_module.md#oh_arkui_animator_pause) ([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator) | 暂停animator动画。  | 
| int32_t [OH_ArkUI_Animator_Cancel](_ark_u_i___native_module.md#oh_arkui_animator_cancel) ([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator) | 取消animator动画。  | 
| int32_t [OH_ArkUI_Animator_Reverse](_ark_u_i___native_module.md#oh_arkui_animator_reverse) ([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator) | 以相反的顺序播放animator动画。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateCurveByType](_ark_u_i___native_module.md#oh_arkui_curve_createcurvebytype) ([ArkUI_AnimationCurve](_ark_u_i___native_module.md#arkui_animationcurve) curve) | 插值曲线的初始化函数，可以根据入参创建一个插值曲线对象。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateStepsCurve](_ark_u_i___native_module.md#oh_arkui_curve_createstepscurve) (int32_t count, bool end) | 构造阶梯曲线对象。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateCubicBezierCurve](_ark_u_i___native_module.md#oh_arkui_curve_createcubicbeziercurve) (float x1, float y1, float x2, float y2) | 构造三阶贝塞尔曲线对象。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateSpringCurve](_ark_u_i___native_module.md#oh_arkui_curve_createspringcurve) (float velocity, float mass, float stiffness, float damping) | 构造弹簧曲线对象，曲线形状由弹簧参数决定，动画时长受animation、animateTo中的duration参数控制。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateSpringMotion](_ark_u_i___native_module.md#oh_arkui_curve_createspringmotion) (float response, float dampingFraction, float overlapDuration) | 构造弹性动画曲线对象。如果对同一对象的同一属性进行多个弹性动画，每个动画会替换掉前一个动画，并继承之前的速度。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateResponsiveSpringMotion](_ark_u_i___native_module.md#oh_arkui_curve_createresponsivespringmotion) (float response, float dampingFraction, float overlapDuration) | 构造弹性跟手动画曲线对象，是springMotion的一种特例，仅默认参数不同，可与springMotion混合使用。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateInterpolatingSpring](_ark_u_i___native_module.md#oh_arkui_curve_createinterpolatingspring) (float velocity, float mass, float stiffness, float damping) | 构造插值器弹簧曲线对象，生成一条从0到1的动画曲线，实际动画值根据曲线进行插值计算。  | 
| [ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) [OH_ArkUI_Curve_CreateCustomCurve](_ark_u_i___native_module.md#oh_arkui_curve_createcustomcurve) (void \*userData, float(\*interpolate)(float fraction, void \*userdata)) | 构造自定义曲线对象。  | 
| void [OH_ArkUI_Curve_DisposeCurve](_ark_u_i___native_module.md#oh_arkui_curve_disposecurve) ([ArkUI_CurveHandle](_ark_u_i___native_module.md#arkui_curvehandle) curveHandle) | 销毁自定义曲线对象。  | 
| [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \* [OH_ArkUI_CreateOpacityTransitionEffect](_ark_u_i___native_module.md#oh_arkui_createopacitytransitioneffect) (float opacity) | 创建组件转场时的透明度效果对象。  | 
| [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \* [OH_ArkUI_CreateTranslationTransitionEffect](_ark_u_i___native_module.md#oh_arkui_createtranslationtransitioneffect) ([ArkUI_TranslationOptions](_ark_u_i___translation_options.md) \*translate) | 创建组件转场时的平移效果对象。  | 
| [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \* [OH_ArkUI_CreateScaleTransitionEffect](_ark_u_i___native_module.md#oh_arkui_createscaletransitioneffect) ([ArkUI_ScaleOptions](_ark_u_i___scale_options.md) \*scale) | 创建组件转场时的缩放效果对象。  | 
| [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \* [OH_ArkUI_CreateRotationTransitionEffect](_ark_u_i___native_module.md#oh_arkui_createrotationtransitioneffect) ([ArkUI_RotationOptions](_ark_u_i___rotation_options.md) \*rotate) | 创建组件转场时的旋转效果对象。  | 
| [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \* [OH_ArkUI_CreateMovementTransitionEffect](_ark_u_i___native_module.md#oh_arkui_createmovementtransitioneffect) ([ArkUI_TransitionEdge](_ark_u_i___native_module.md#arkui_transitionedge) move) | 创建组件平移效果对象。  | 
| [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \* [OH_ArkUI_CreateAsymmetricTransitionEffect](_ark_u_i___native_module.md#oh_arkui_createasymmetrictransitioneffect) ([ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \*appear, [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \*disappear) | 创建非对称的转场效果对象。  | 
| void [OH_ArkUI_TransitionEffect_Dispose](_ark_u_i___native_module.md#oh_arkui_transitioneffect_dispose) ([ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \*option) | 销毁转场效果对象。  | 
| int32_t [OH_ArkUI_TransitionEffect_Combine](_ark_u_i___native_module.md#oh_arkui_transitioneffect_combine) ([ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \*option, [ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \*combine) | 设置转场效果链式组合，以形成包含多种转场效果的TransitionEffect。  | 
| int32_t [OH_ArkUI_TransitionEffect_SetAnimation](_ark_u_i___native_module.md#oh_arkui_transitioneffect_setanimation) ([ArkUI_TransitionEffect](_ark_u_i___native_module.md#arkui_transitioneffect) \*option, [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*animation) | 设置转场效果动画参数。  | 
