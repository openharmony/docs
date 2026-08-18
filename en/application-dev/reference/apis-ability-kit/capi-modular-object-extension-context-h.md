# modular_object_extension_context.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:16:45.689Z pushedAt=2026-08-14T03:54:56.538Z -->

## Overview

Declares the context APIs of ModularObjectExtensionAbility, including starting a UIAbility, destroying the ModularObjectExtensionAbility itself, and creating and destroying IPC objects.

**File to include:** <AbilityKit/ability_runtime/modular_object_extension_context.h>

**Library:** libability_runtime.so

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_AbilityRuntime_ModularObjectExtensionContext*](capi-abilityruntime-oh-abilityruntime-modularobjectextensioncontext8h.md) | OH_AbilityRuntime_ModObjExtensionContextHandle | Represents the handle to the context of ModularObjectExtensionAbility. |

### Functions

| Name | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_GetBaseContext(OH_AbilityRuntime_ModObjExtensionContextHandle modObjExtensionContext, AbilityRuntime_ContextHandle* baseContext)](#oh_abilityruntime_modobjextensioncontext_getbasecontext) | Obtains the base context from the context of ModularObjectExtensionAbility. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_StartSelfUIAbility(OH_AbilityRuntime_ModObjExtensionContextHandle context, const AbilityBase_Want *want)](#oh_abilityruntime_modobjextensioncontext_startselfuiability) | Starts the UIAbility of the current app. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_StartSelfUIAbilityWithStartOptions(OH_AbilityRuntime_ModObjExtensionContextHandle context, const AbilityBase_Want *want, const AbilityRuntime_StartOptions *options)](#oh_abilityruntime_modobjextensioncontext_startselfuiabilitywithstartoptions) | Starts the UIAbility of the current app with StartOptions. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_TerminateSelf(OH_AbilityRuntime_ModObjExtensionContextHandle context)](#oh_abilityruntime_modobjextensioncontext_terminateself) | Destroys the ModularObjectExtensionAbility itself. |
| [OHIPCRemoteStub* OH_AbilityRuntime_ModObjExtensionContext_CreateIPCRemoteStub(OH_AbilityRuntime_ModObjExtensionContextHandle context, const char *descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallback destroyCallback, void *userData)](#oh_abilityruntime_modobjextensioncontext_createipcremotestub) | Creates an OHIPCRemoteStub object. The callbacks run on the thread specified by the ExtensionAbility. requestCallback and destroyCallback are executed sequentially on the thread determined by [OH_AbilityRuntime_ThreadMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_threadmode) of the ExtensionAbility. After [OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub](capi-modular-object-extension-context-h.md#oh_abilityruntime_modobjextensioncontext_destroyipcremotestub) is called, no new requestCallback will be invoked, and destroyCallback is invoked only after the ongoing requestCallback completes. The caller must call [OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub](capi-modular-object-extension-context-h.md#oh_abilityruntime_modobjextensioncontext_destroyipcremotestub) to destroy the returned object to avoid memory leaks. |
| [void OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub(OH_AbilityRuntime_ModObjExtensionContextHandle context, OHIPCRemoteStub *stub)](#oh_abilityruntime_modobjextensioncontext_destroyipcremotestub) | Destroys the OHIPCRemoteStub object. |

## Function Description

### OH_AbilityRuntime_ModObjExtensionContext_GetBaseContext()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_GetBaseContext(OH_AbilityRuntime_ModObjExtensionContextHandle modObjExtensionContext, AbilityRuntime_ContextHandle* baseContext)
```

**Description**

Obtains the base context from the ModularObjectExtensionAbility context.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionContextHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioncontext8h.md) modObjExtensionContext | Pointer to the ModularObjectExtensionAbility context. |
| AbilityRuntime_ContextHandle* baseContext | Pointer to [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md), used to receive the result. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Parameter verification failed. |

### OH_AbilityRuntime_ModObjExtensionContext_StartSelfUIAbility()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_StartSelfUIAbility(OH_AbilityRuntime_ModObjExtensionContextHandle context, const AbilityBase_Want *want)
```

**Description**

Starts the UIAbility of the current app.

**Required permissions:** ohos.permission.NDK_START_SELF_UI_ABILITY

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionContextHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioncontext8h.md) context | Pointer to the ModularObjectExtensionAbility context. |
| const [AbilityBase_Want](capi-abilitybase-want.md) *want | Want information required for starting the UIAbility of the current app. For details, see [AbilityBase_Want](capi-abilitybase-want.md). |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The caller does not have the required permission.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The input parameter is invalid.<br>         [ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The device does not support starting the UIAbility of the current app.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The target ability does not exist.<br>         [ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The ability type is incorrect.<br>         [ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The crowdtest app has expired.<br>         [ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The ability cannot be started in Wukong mode.<br>         [ABILITY_RUNTIME_ERROR_CODE_CONTROLLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The app is controlled.<br>         [ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The app is controlled by EDM.<br>         [ABILITY_RUNTIME_ERROR_CODE_CROSS_APP](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The caller attempts to start a different app.<br>         [ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) An internal error occurs.<br>         [ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The caller process is not in the foreground.<br>                 [ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) App cloning and multi-instance are not supported.<br>         [ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The app instance key is invalid.<br>         [ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The number of app instances has reached the upper limit.<br>         [ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) App multi-instance is not supported.<br>         [ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Setting APP_INSTANCE_KEY is not allowed. |

### OH_AbilityRuntime_ModObjExtensionContext_StartSelfUIAbilityWithStartOptions()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_StartSelfUIAbilityWithStartOptions(OH_AbilityRuntime_ModObjExtensionContextHandle context, const AbilityBase_Want *want, const AbilityRuntime_StartOptions *options)
```

**Description**

Starts the UIAbility of the current app with StartOptions.

**Required permissions:** ohos.permission.NDK_START_SELF_UI_ABILITY

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionContextHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioncontext8h.md) context | Pointer to the ModularObjectExtensionAbility context. |
| const [AbilityBase_Want](capi-abilitybase-want.md) *want | Want information required for starting the UIAbility of the current app. For details, see [AbilityBase_Want](capi-abilitybase-want.md). |
| const [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *options | StartOptions information required for starting the UIAbility of the current app. For details, see [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md). |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The caller does not have the required permission.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The input parameter is invalid.<br>         [ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The device does not support starting the UIAbility of the current app.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The target ability does not exist.<br>         [ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The ability type is incorrect.<br>         [ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The crowdtest app has expired.<br>         [ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The ability cannot be started in Wukong mode.<br>         [ABILITY_RUNTIME_ERROR_CODE_CONTROLLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The app is controlled.<br>         [ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The app is controlled by EDM.<br>         [ABILITY_RUNTIME_ERROR_CODE_CROSS_APP](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The caller attempts to start a different app.<br>         [ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) An internal error occurs.<br>         [ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The caller process is not in the foreground.<br>         [ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The visibility setting is disabled.<br>         [ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) App cloning and multi-instance are not supported.<br>         [ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The app instance key is invalid.<br>         [ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The number of app instances has reached the upper limit.<br>         [ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) App multi-instance is not supported.<br>         [ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Setting APP_INSTANCE_KEY is not allowed. |

### OH_AbilityRuntime_ModObjExtensionContext_TerminateSelf()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionContext_TerminateSelf(OH_AbilityRuntime_ModObjExtensionContextHandle context)
```

**Description**

Destroys the ModularObjectExtensionAbility itself.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionContextHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioncontext8h.md) context | Pointer to the ModularObjectExtensionAbility context. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The input parameter is invalid.<br>         [ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The ability cannot be destroyed in Wukong mode.<br>         [ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The context does not exist.<br>         [ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjExtensionContext_CreateIPCRemoteStub()

```c
OHIPCRemoteStub* OH_AbilityRuntime_ModObjExtensionContext_CreateIPCRemoteStub(OH_AbilityRuntime_ModObjExtensionContextHandle context, const char *descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallback destroyCallback, void *userData)
```

**Description**

Creates an OHIPCRemoteStub object. The callbacks run on the thread specified by the ExtensionAbility. requestCallback and destroyCallback are executed in sequence on the thread determined by the [OH_AbilityRuntime_ThreadMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_threadmode) of the ExtensionAbility. After [OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub](capi-modular-object-extension-context-h.md#oh_abilityruntime_modobjextensioncontext_destroyipcremotestub) is called, no new requestCallback will be invoked, and destroyCallback is invoked only after the ongoing requestCallback completes. The caller must call [OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub](capi-modular-object-extension-context-h.md#oh_abilityruntime_modobjextensioncontext_destroyipcremotestub) to destroy the returned object to avoid memory leaks.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionContextHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioncontext8h.md) context | Pointer to the ModularObjectExtensionAbility context. |
| const char *descriptor | Pointer to the descriptor of the OHIPCRemoteStub object to create. It cannot be NULL. The string is copied internally during creation, and the caller can release the descriptor after this function returns. |
| OH_OnRemoteRequestCallback requestCallback | Callback used to process data requests. It cannot be NULL. |
| OH_OnRemoteDestroyCallback destroyCallback | Callback invoked when the object is destroyed. It can be NULL. |
| void *userData | Pointer to the user data. It can be NULL and must remain valid until the object is destroyed. |

**Returns**

| Type | Description |
| -- | -- |
| OHIPCRemoteStub* | Pointer to the created OHIPCRemoteStub object if the operation is successful; NULL otherwise. |

### OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub()

```c
void OH_AbilityRuntime_ModObjExtensionContext_DestroyIPCRemoteStub(OH_AbilityRuntime_ModObjExtensionContextHandle context, OHIPCRemoteStub *stub)
```

**Description**

Destroys the OHIPCRemoteStub object.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionContextHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioncontext8h.md) context | Pointer to the ModularObjectExtensionAbility context. |
| OHIPCRemoteStub *stub | Pointer to the OHIPCRemoteStub object to destroy. |