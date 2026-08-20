# modular_object_extension_ability.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:16:42.314Z pushedAt=2026-08-14T03:36:35.350Z -->

## Overview

Declares the interfaces of a ModularObjectExtensionAbility instance, including the capabilities of registering lifecycle callback functions and obtaining the context. It is applicable to scenarios where the lifecycle of ModularObjectExtensionAbility is processed.

**File to include:** <AbilityKit/ability_runtime/modular_object_extension_ability.h>

**Library:** libability_runtime.so

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| OH_AbilityRuntime_ModularObjectExtensionInstance | OH_AbilityRuntime_ModObjExtensionInstance | Represents a ModularObjectExtensionAbility instance. |
| [OH_AbilityRuntime_ModObjExtensionInstance*] | OH_AbilityRuntime_ModObjExtensionInstanceHandle | Defines a pointer to OH_AbilityRuntime_ModObjExtensionInstance. |

### Functions

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [typedef void (\*OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, AbilityBase_Want *want)](#oh_abilityruntime_modobjextensionability_oncreatefunc) | OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc | Callback function type triggered when a ModularObjectExtensionAbility is created, used for initialization. |
| [typedef void (\*OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance)](#oh_abilityruntime_modobjextensionability_ondestroyfunc) | OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc | Callback function type triggered before a ModularObjectExtensionAbility is destroyed. |
| [typedef OHIPCRemoteStub* (\*OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, AbilityBase_Want *want)](#oh_abilityruntime_modobjextensionability_onconnectfunc) | OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc | Callback function type triggered when a ModularObjectExtensionAbility is connected. |
| [typedef void (\*OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance)](#oh_abilityruntime_modobjextensionability_ondisconnectfunc) | OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc | Callback function type triggered when all connections of the current ModularObjectExtensionAbility are disconnected. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnCreateFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc onCreateFunc)](#oh_abilityruntime_modobjextensionability_registeroncreatefunc) | - | Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_oncreatefunc) callback function with OH_AbilityRuntime_ModObjExtensionInstance. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDestroyFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc onDestroyFunc)](#oh_abilityruntime_modobjextensionability_registerondestroyfunc) | - | Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondestroyfunc) callback function with OH_AbilityRuntime_ModObjExtensionInstance. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnConnectFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc onConnectFunc)](#oh_abilityruntime_modobjextensionability_registeronconnectfunc) | - | Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_onconnectfunc) callback function with OH_AbilityRuntime_ModObjExtensionInstance. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDisconnectFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc onDisconnectFunc)](#oh_abilityruntime_modobjextensionability_registerondisconnectfunc) | - | Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondisconnectfunc) callback function with OH_AbilityRuntime_ModObjExtensionInstance. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_GetContextFromInstance(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionContextHandle* context)](#oh_abilityruntime_modobjextensionability_getcontextfrominstance) | - | Obtains the ExtensionAbility context from a ModularObjectExtensionAbility instance. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_GetInstanceFromBase(AbilityRuntime_ExtensionInstanceHandle baseExtensionInstance, OH_AbilityRuntime_ModObjExtensionInstanceHandle* modObjExtensionInstance)](#oh_abilityruntime_modobjextensionability_getinstancefrombase) | - | Obtains a ModularObjectExtensionAbility instance from a base ExtensionAbility instance. |

## Function Description

### OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc()

```c
typedef void (*OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, AbilityBase_Want *want)
```

**Description**

Defines a pointer to the callback function invoked when a ModularObjectExtensionAbility is created, used for initialization.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |
| AbilityBase_Want \*want | Want information when the ModularObjectExtensionAbility is created. For details, see [AbilityBase_Want](capi-abilitybase-want.md). |

### OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc()

```c
typedef void (*OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance)
```

**Description**

Called before the ModularObjectExtensionAbility instance is destroyed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |

### OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc()

```c
typedef OHIPCRemoteStub* (*OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, AbilityBase_Want *want)
```

**Description**

Callback function invoked when the ModularObjectExtensionAbility is connected. It must return an OHIPCRemoteStub object to provide cross-process communication services.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |
| AbilityBase_Want \*want | Want information when connecting to the ModularObjectExtensionAbility. For details, see [AbilityBase_Want](capi-abilitybase-want.md). |

**Returns**

| Type | Description |
| -- | -- |
| [OHIPCRemoteStub](../apis-ipc-kit/capi-ohipcparcel-ohipcremotestub.md)* | Returns the IPC remote stub object used for cross-process communication services. |

### OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc()

```c
typedef void (*OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc)(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance)
```

**Description**

Callback function invoked when all client connections of the current ModularObjectExtensionAbility are disconnected.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |

### OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnCreateFunc()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnCreateFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc onCreateFunc)
```

**Description**

Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_oncreatefunc) callback function with the OH_AbilityRuntime_ModObjExtensionInstance.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |
| [OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_oncreatefunc) onCreateFunc | OnCreate callback function to register. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode): the API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode): parameter validation failed. Check whether the input parameters are valid. |

### OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDestroyFunc()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDestroyFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc onDestroyFunc)
```

**Description**

Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondestroyfunc) callback function with the OH_AbilityRuntime_ModObjExtensionInstance.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |
| [OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondestroyfunc) onDestroyFunc | Callback to be registered for the OnDestroy event. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode): API call success.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode): parameter validation failure. Check whether the input parameters are valid. |

### OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnConnectFunc()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnConnectFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc onConnectFunc)
```

**Description**

Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_onconnectfunc) callback function with the OH_AbilityRuntime_ModObjExtensionInstance.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |
| [OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_onconnectfunc) onConnectFunc | OnConnect callback function to be registered. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode): the API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode): parameter validation failed. Check whether the input parameters are valid. |

### OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDisconnectFunc()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_RegisterOnDisconnectFunc(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc onDisconnectFunc)
```

**Description**

Registers the [OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondisconnectfunc) callback function with the OH_AbilityRuntime_ModObjExtensionInstance.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |
| [OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc](capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondisconnectfunc) onDisconnectFunc | OnDisconnect callback function to register. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode): API call success.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode): parameter validation failure. Check whether the passed parameters are valid. |

### OH_AbilityRuntime_ModObjExtensionAbility_GetContextFromInstance()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_GetContextFromInstance(OH_AbilityRuntime_ModObjExtensionInstanceHandle instance, OH_AbilityRuntime_ModObjExtensionContextHandle* context)
```

**Description**

Obtains the ExtensionAbility context from a ModularObjectExtensionAbility instance.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| OH_AbilityRuntime_ModObjExtensionInstanceHandle instance | Pointer to the OH_AbilityRuntime_ModObjExtensionInstance instance. |
| [OH_AbilityRuntime_ModObjExtensionContextHandle]* context | Pointer to OH_AbilityRuntime_ModObjExtensionContextHandle, used as an output parameter to receive the ExtensionAbility context. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode): API call success.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode): parameter validation failure. Check whether the input parameters are valid. |

### OH_AbilityRuntime_ModObjExtensionAbility_GetInstanceFromBase()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjExtensionAbility_GetInstanceFromBase(AbilityRuntime_ExtensionInstanceHandle baseExtensionInstance, OH_AbilityRuntime_ModObjExtensionInstanceHandle* modObjExtensionInstance)
```

**Description**

Obtains a ModularObjectExtensionAbility instance from a base ExtensionAbility instance. If the passed-in instance is not of the ModularObjectExtensionAbility type, the error code ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE is returned.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| AbilityRuntime_ExtensionInstanceHandle baseExtensionInstance | Pointer to AbilityRuntime_ExtensionInstance. |
| [OH_AbilityRuntime_ModObjExtensionInstanceHandle]* modObjExtensionInstance | Pointer to OH_AbilityRuntime_ModObjExtensionInstance, used to receive the ModularObjectExtensionAbility instance as an output parameter. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode): the API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode): parameter validation failed. Check whether the passed-in parameters are valid.<br>         [ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE](capi-ability-runtime-common-h.md#abilityruntime_errorcode): the ExtensionAbility instance is not of the ModularObjectExtensionAbility type. Ensure that the type of the passed-in ExtensionAbility instance is correct. |