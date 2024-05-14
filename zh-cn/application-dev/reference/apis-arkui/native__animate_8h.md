# native_animate.h


## 概述

提供ArkUI在Native侧的动画接口定义集合。

**库：** libace_ndk.z.so

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


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \* [OH_ArkUI_AnimateOption_Create](_ark_u_i___native_module.md#oh_arkui_animateoption_create) () | 创建动画效果参数。  | 
| void [OH_ArkUI_AnimateOption_Dispose](_ark_u_i___native_module.md#oh_arkui_animateoption_dispose) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 销毁动画效果参数指针。  | 
| uint32_t [OH_ArkUI_AnimateOption_GetDuration](_ark_u_i___native_module.md#oh_arkui_animateoption_getduration) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画持续时间，单位为ms(毫秒)。  | 
| float [OH_ArkUI_AnimateOption_GetTempo](_ark_u_i___native_module.md#oh_arkui_animateoption_gettempo) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画播放速度。  | 
| [ArkUI_AnimationCurve](_ark_u_i___native_module.md#arkui_animationcurve) [OH_ArkUI_AnimateOption_GetCurve](_ark_u_i___native_module.md#oh_arkui_animateoption_getcurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画曲线。  | 
| uint32_t [OH_ArkUI_AnimateOption_GetDelay](_ark_u_i___native_module.md#oh_arkui_animateoption_getdelay) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画延迟播放时间，单位为ms(毫秒)。  | 
| uint32_t [OH_ArkUI_AnimateOption_GetIterations](_ark_u_i___native_module.md#oh_arkui_animateoption_getiterations) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画播放次数。  | 
| [ArkUI_AnimationPlayMode](_ark_u_i___native_module.md#arkui_animationplaymode) [OH_ArkUI_AnimateOption_GetPlayMode](_ark_u_i___native_module.md#oh_arkui_animateoption_getplaymode) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画播放模式。  | 
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimateOption_GetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animateoption_getexpectedframeraterange) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | 获取动画的期望帧率。  | 
| void [OH_ArkUI_AnimateOption_SetDuration](_ark_u_i___native_module.md#oh_arkui_animateoption_setduration) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, uint32_t value) | 设置动画持续时间。  | 
| void [OH_ArkUI_AnimateOption_SetTempo](_ark_u_i___native_module.md#oh_arkui_animateoption_settempo) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, float value) | 设置动画播放速度。  | 
| void [OH_ArkUI_AnimateOption_SetCurve](_ark_u_i___native_module.md#oh_arkui_animateoption_setcurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_AnimationCurve](_ark_u_i___native_module.md#arkui_animationcurve) value) | 设置动画曲线。  | 
| void [OH_ArkUI_AnimateOption_SetDelay](_ark_u_i___native_module.md#oh_arkui_animateoption_setdelay) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, uint32_t value) | 设置动画延迟播放时间。  | 
| void [OH_ArkUI_AnimateOption_SetIterations](_ark_u_i___native_module.md#oh_arkui_animateoption_setiterations) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, uint32_t value) | 设置动画播放次数。  | 
| void [OH_ArkUI_AnimateOption_SetPlayMode](_ark_u_i___native_module.md#oh_arkui_animateoption_setplaymode) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_AnimationPlayMode](_ark_u_i___native_module.md#arkui_animationplaymode) value) | 设置动画播放模式。  | 
| void [OH_ArkUI_AnimateOption_SetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animateoption_setexpectedframeraterange) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | 设置动画的期望帧率。  | 
