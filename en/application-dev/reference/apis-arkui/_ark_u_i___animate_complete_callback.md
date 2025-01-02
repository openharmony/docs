# ArkUI_AnimateCompleteCallback


## Overview

Defines the callback type for when the animation playback is complete.

**Since**: 12

**Related module**: [ArkUI_NativeModule](_ark_u_i___native_module.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [ArkUI_FinishCallbackType](_ark_u_i___native_module.md#arkui_finishcallbacktype) [type](#type) | **onFinish** callback. | 
| void(\* [callback](#callback) )(void \*[userData](#userdata)) | Callback invoked when the animation playback is complete. | 
| void \* [userData](#userdata) | Callback of a custom type. | 


## Member Variable Description


### callback

```
void(* ArkUI_AnimateCompleteCallback::callback) (void *userData)
```
**Description**

Callback invoked when the animation playback is complete.


### type

```
ArkUI_FinishCallbackType ArkUI_AnimateCompleteCallback::type
```
**Description**

Type of the **onFinish** callback.


### userData

```
void* ArkUI_AnimateCompleteCallback::userData
```
**Description**

Callback of a custom type.
