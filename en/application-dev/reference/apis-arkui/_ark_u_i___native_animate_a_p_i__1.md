# ArkUI_NativeAnimateAPI_1


## Overview

Declares the native animation APIs provided by ArkUI.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t(\* [animateTo](#animateto) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) context, [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_ContextCallback](_ark_u_i___context_callback.md) \*update, [ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) \*complete) | Defines an explicit animation. | 
| int32_t(\* [keyframeAnimateTo](#keyframeanimateto) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) context, [ArkUI_KeyframeAnimateOption](_ark_u_i___native_module.md#arkui_keyframeanimateoption) \*option) | Sets the keyframe animation. | 
| [ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle)(\* [createAnimator](#createanimator) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle-12) context, [ArkUI_AnimatorOption](_ark_u_i___native_module.md#arkui_animatoroption) \*option) | Creates animator object. | 
| void(\* [disposeAnimator](#disposeanimator) )([ArkUI_AnimatorHandle](_ark_u_i___native_module.md#arkui_animatorhandle) animator) | Disposes of an animator object. | 


## Member Variable Description


### animateTo

```
int32_t(* ArkUI_NativeAnimateAPI_1::animateTo) (ArkUI_ContextHandle context, ArkUI_AnimateOption *option, ArkUI_ContextCallback *update, ArkUI_AnimateCompleteCallback *complete)
```
**Description**

Defines an explicit animation.

**Parameters**

| Name| Description| 
| -------- | -------- |
| context | **UIContext** instance. | 
| option | Defines the animation configuration. | 
| update | Closure function for the animation. The system automatically inserts the transition animation if the state changes in the closure function. | 
| complete | Callback invoked when the animation playback is complete. | 

**NOTE**

Make sure the component attributes to be set in the event closure have been set before.

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.


### createAnimator

```
ArkUI_AnimatorHandle(* ArkUI_NativeAnimateAPI_1::createAnimator) (ArkUI_ContextHandle context, ArkUI_AnimatorOption *option)
```
**Description**

Creates an animator object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| context | **UIContext** instance. | 
| option | Animator parameter. | 

**Returns**

Returns the pointer to the animator object; returns **NULL** if a parameter error occurs.


### disposeAnimator

```
void(* ArkUI_NativeAnimateAPI_1::disposeAnimator) (ArkUI_AnimatorHandle animator)
```
**Description**

Disposes of an animator object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| animator | Animator object. | 


### keyframeAnimateTo

```
int32_t(* ArkUI_NativeAnimateAPI_1::keyframeAnimateTo) (ArkUI_ContextHandle context, ArkUI_KeyframeAnimateOption *option)
```
**Description**

Sets the keyframe animation.

**Parameters**

| Name| Description| 
| -------- | -------- |
| context | **UIContext** instance. | 
| option | Keyframe animation parameter. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
