# native_animate.h


## Overview

Defines a set of animation APIs of ArkUI on the native side.

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) | Defines the expected frame rate range of the animation. | 
| struct&nbsp;&nbsp;[ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) | Defines the callback type for when the animation playback is complete. | 
| struct&nbsp;&nbsp;[ArkUI_NativeAnimateAPI_1](_ark_u_i___native_animate_a_p_i__1.md) | Implements the native animation APIs provided by ArkUI. | 


### Types

| Name | Description | 
| -------- | -------- |
| typedef struct [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) | Defines the animation configuration. | 


### Callback

| Event | Description | 
| -------- | -------- |
| [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \* [OH_ArkUI_AnimateOption_Create](_ark_u_i___native_module.md#oh_arkui_animateoption_create) () | Create animation effect parameters. | 
| void [OH_ArkUI_AnimateOption_Dispose](_ark_u_i___native_module.md#oh_arkui_animateoption_dispose) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Destroys an animation configuration. | 
| uint32_t [OH_ArkUI_AnimateOption_GetDuration](_ark_u_i___native_module.md#oh_arkui_animateoption_getduration) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Obtains the animation duration, in milliseconds. | 
| float [OH_ArkUI_AnimateOption_GetTempo](_ark_u_i___native_module.md#oh_arkui_animateoption_gettempo) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Obtains the playback speed of an animation. | 
| [ArkUI_AnimationCurve](_ark_u_i___native_module.md#arkui_animationcurve) [OH_ArkUI_AnimateOption_GetCurve](_ark_u_i___native_module.md#oh_arkui_animateoption_getcurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Obtains the animation curve. | 
| uint32_t [OH_ArkUI_AnimateOption_GetDelay](_ark_u_i___native_module.md#oh_arkui_animateoption_getdelay) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Obtains the animation delay, in milliseconds. | 
| uint32_t [OH_ArkUI_AnimateOption_GetIterations](_ark_u_i___native_module.md#oh_arkui_animateoption_getiterations) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Obtains the number of times that an animation is played. | 
| [ArkUI_AnimationPlayMode](_ark_u_i___native_module.md#arkui_animationplaymode) [OH_ArkUI_AnimateOption_GetPlayMode](_ark_u_i___native_module.md#oh_arkui_animateoption_getplaymode) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Obtains the animation playback mode. | 
| [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \* [OH_ArkUI_AnimateOption_GetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animateoption_getexpectedframeraterange) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option) | Obtains the expected frame rate range of an animation. | 
| void [OH_ArkUI_AnimateOption_SetDuration](_ark_u_i___native_module.md#oh_arkui_animateoption_setduration) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, uint32_t value) | Sets the animation duration. | 
| void [OH_ArkUI_AnimateOption_SetTempo](_ark_u_i___native_module.md#oh_arkui_animateoption_settempo) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, float value) | Sets the playback speed of an animation. | 
| void [OH_ArkUI_AnimateOption_SetCurve](_ark_u_i___native_module.md#oh_arkui_animateoption_setcurve) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_AnimationCurve](_ark_u_i___native_module.md#arkui_animationcurve) value) | Animation curve. | 
| void [OH_ArkUI_AnimateOption_SetDelay](_ark_u_i___native_module.md#oh_arkui_animateoption_setdelay) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, uint32_t value) | Sets the animation delay. | 
| void [OH_ArkUI_AnimateOption_SetIterations](_ark_u_i___native_module.md#oh_arkui_animateoption_setiterations) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, uint32_t value) | Number of times that the frame animation is played. | 
| void [OH_ArkUI_AnimateOption_SetPlayMode](_ark_u_i___native_module.md#oh_arkui_animateoption_setplaymode) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_AnimationPlayMode](_ark_u_i___native_module.md#arkui_animationplaymode) value) | Sets the animation playing mode. | 
| void [OH_ArkUI_AnimateOption_SetExpectedFrameRateRange](_ark_u_i___native_module.md#oh_arkui_animateoption_setexpectedframeraterange) ([ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_ExpectedFrameRateRange](_ark_u_i___expected_frame_rate_range.md) \*value) | Defines the expected frame rate range of the animation. | 
