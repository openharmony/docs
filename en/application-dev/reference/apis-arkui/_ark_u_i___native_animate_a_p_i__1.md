# ArkUI_NativeAnimateAPI_1


## Overview

Implements the native animation APIs provided by ArkUI.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| int32_t(\* [animateTo](#animateto) )([ArkUI_ContextHandle](_ark_u_i___native_module.md#arkui_contexthandle) context, [ArkUI_AnimateOption](_ark_u_i___native_module.md#arkui_animateoption) \*option, [ArkUI_ContextCallback](_ark_u_i___context_callback.md) \*update, [ArkUI_AnimateCompleteCallback](_ark_u_i___animate_complete_callback.md) \*complete) | Explicit Animation Interface | 


## Member Variable Description


### animateTo

```
int32_t(* ArkUI_NativeAnimateAPI_1::animateTo) (ArkUI_ContextHandle context, ArkUI_AnimateOption *option, ArkUI_ContextCallback *update, ArkUI_AnimateCompleteCallback *complete)
```
**Description**

Explicit Animation Interface

**Parameters**

| Name | Description | 
| -------- | -------- |
| context | UIContext instance. | 
| option | Defines the animation configuration. | 
| update | Closure function that displays the animation. The system automatically inserts the transition animation if the state changes in the closure function. | 
| complete | Sets the callback parameter when the animation playback is complete. | 

**NOTE**

* @note Make sure the component attributes to be set in the event closure have been set before.

**Returns**

Returns **0** if the operation is successful; returns **401** if a parameter error occurs.
