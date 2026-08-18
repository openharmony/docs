# modular_object_extension_manager.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:17:17.032Z pushedAt=2026-08-14T07:08:45.607Z -->

## Overview

Declares the APIs for managing ModularObjectExtensionAbility, including querying ModularObjectExtensionAbility information, connecting to and disconnecting from it. Developers can use the APIs provided by this module to query the information of all registered ModularObjectExtensionAbility instances in the current app (including the startup mode, process mode, thread mode, component name, and disabled state), and establish or disconnect the communication connection with ModularObjectExtensionAbility as needed.

**File to include:** <AbilityKit/ability_runtime/modular_object_extension_manager.h>

**Library:** libability_runtime.so

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_AbilityRuntime_ModularObjectExtensionInfo*](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) | OH_AbilityRuntime_ModObjExtensionInfoHandle | Represents the information handle of a single ModularObjectExtensionAbility. This handle points to the complete information of a ModularObjectExtensionAbility, including the startup mode, process mode, thread mode, component name ([AbilityBase_Element](capi-abilitybase-element.md)), and disabled state. |
| [OH_AbilityRuntime_AllModularObjectExtensionInfos*](capi-abilityruntime-oh-abilityruntime-allmodularobjectextensioninfos8h.md) | OH_AbilityRuntime_AllModObjExtensionInfosHandle | Represents the collection handle of the information of all ModularObjectExtensionAbility instances in the current app. This handle points to a collection that contains multiple [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) instances. You can use [OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getcountfromallmodobjextensioninfos) to obtain the number of elements in the collection, and use [OH_AbilityRuntime_GetModObjExtensionInfoByIndex](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getmodobjextensioninfobyindex) to traverse by index and obtain the information of a single ModularObjectExtensionAbility. After use, release the collection through [OH_AbilityRuntime_ReleaseAllExtensionInfos](#oh_abilityruntime_releaseallextensioninfos). |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_AbilityRuntime_LaunchMode](#oh_abilityruntime_launchmode) | OH_AbilityRuntime_LaunchMode | Defines the startup mode of ModularObjectExtensionAbility. |
| [OH_AbilityRuntime_ProcessMode](#oh_abilityruntime_processmode) | OH_AbilityRuntime_ProcessMode | Defines the process mode of ModularObjectExtensionAbility. |
| [OH_AbilityRuntime_ThreadMode](#oh_abilityruntime_threadmode) | OH_AbilityRuntime_ThreadMode | Defines the thread mode of ModularObjectExtensionAbility. |

### Functions

| Name | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoLaunchMode(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, OH_AbilityRuntime_LaunchMode *launchMode)](#oh_abilityruntime_getmodularobjectextensioninfolaunchmode) | Obtains the startup mode from the specified ModularObjectExtensionAbility information. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoProcessMode(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, OH_AbilityRuntime_ProcessMode *processMode)](#oh_abilityruntime_getmodularobjectextensioninfoprocessmode) | Obtains the process mode from the specified ModularObjectExtensionAbility information. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoThreadMode(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, OH_AbilityRuntime_ThreadMode *threadMode)](#oh_abilityruntime_getmodularobjectextensioninfothreadmode) | Obtains the thread mode from the specified ModularObjectExtensionAbility information. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoElementName(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, AbilityBase_Element *element)](#oh_abilityruntime_getmodularobjectextensioninfoelementname) | Obtains the component name ([AbilityBase_Element](capi-abilitybase-element.md)) from the specified ModularObjectExtensionAbility information. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoDisableState(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, bool *isDisabled)](#oh_abilityruntime_getmodularobjectextensioninfodisablestate) | Obtains the disabled state from the specified ModularObjectExtensionAbility information. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_AcquireSelfModularObjectExtensionInfos(OH_AbilityRuntime_AllModObjExtensionInfosHandle *outOwnedAllExtensionInfos)](#oh_abilityruntime_acquireselfmodularobjectextensioninfos) | Obtains the information of all registered ModularObjectExtensionAbility instances of the current app. This API returns a handle to the information collection of all registered ModularObjectExtensionAbility instances of the current app. Developers can use [OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getcountfromallmodobjextensioninfos) and [OH_AbilityRuntime_GetModObjExtensionInfoByIndex](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getmodobjextensioninfobyindex) to traverse each ModularObjectExtensionAbility information in the collection, and then obtain the startup mode, process mode, thread mode, and other attributes of each ModularObjectExtensionAbility. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ReleaseAllExtensionInfos(OH_AbilityRuntime_AllModObjExtensionInfosHandle *allExtensionInfos)](#oh_abilityruntime_releaseallextensioninfos) | Releases the ModularObjectExtensionAbility information collection obtained by [OH_AbilityRuntime_AcquireSelfModularObjectExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_acquireselfmodularobjectextensioninfos). When the ModularObjectExtensionAbility information collection is no longer needed, this API must be called to release the related resources to avoid memory leaks. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos(OH_AbilityRuntime_AllModObjExtensionInfosHandle allExtensionInfos, size_t *count)](#oh_abilityruntime_getcountfromallmodobjextensioninfos) | Obtains the number of ModularObjectExtensionAbility information items contained in the ModularObjectExtensionAbility information collection. The returned count can be used to determine the upper index limit when traversing the collection, and works with [OH_AbilityRuntime_GetModObjExtensionInfoByIndex](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getmodobjextensioninfobyindex) to access each ModularObjectExtensionAbility information in the collection one by one. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModObjExtensionInfoByIndex(OH_AbilityRuntime_AllModObjExtensionInfosHandle allExtensionInfos, size_t index, OH_AbilityRuntime_ModObjExtensionInfoHandle *extensionInfo)](#oh_abilityruntime_getmodobjextensioninfobyindex) | Obtains the specified ModularObjectExtensionAbility information from the ModularObjectExtensionAbility information collection by index. The valid index range is [0, count), where count can be obtained by [OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getcountfromallmodobjextensioninfos). The obtained ModularObjectExtensionAbility information handle can be used to query the startup mode, process mode, thread mode, and other attributes of the ModularObjectExtensionAbility. |

## Enum Description

### OH_AbilityRuntime_LaunchMode

```c
enum OH_AbilityRuntime_LaunchMode
```

**Description**

Defines the startup mode of ModularObjectExtensionAbility.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ABILITY_RUNTIME_LAUNCH_MODE_IN_PROCESS = 0 | Indicates that ModularObjectExtensionAbility will be started in the caller (client) process. In this mode, ModularObjectExtensionAbility shares the same process with the caller, which is suitable for scenarios that do not require process isolation. |
| OH_ABILITY_RUNTIME_LAUNCH_MODE_CROSS_PROCESS = 1 | Indicates that ModularObjectExtensionAbility can be started across processes. In this mode, ModularObjectExtensionAbility runs in an independent process, isolated from the caller process, which is suitable for scenarios that require process-level isolation to improve stability and security. |

### OH_AbilityRuntime_ProcessMode

```c
enum OH_AbilityRuntime_ProcessMode
```

**Description**

Defines the process mode of ModularObjectExtensionAbility.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ABILITY_RUNTIME_PROCESS_MODE_BUNDLE = 0 | Indicates that all ModularObjectExtensionAbility instances of the same app share one process. All instances run in the same process, reducing system resource consumption. |
| OH_ABILITY_RUNTIME_PROCESS_MODE_TYPE = 1 | Indicates that ModularObjectExtensionAbility instances with the same Ability name share one process. ModularObjectExtensionAbility instances with the same Ability name are assigned to the same process, while instances with different Ability names run in different processes. |
| OH_ABILITY_RUNTIME_PROCESS_MODE_INSTANCE = 2 | Indicates that each ModularObjectExtensionAbility instance exclusively occupies one process. Each ModularObjectExtensionAbility instance has an independent process space, achieving maximum process isolation. This mode is suitable for scenarios with extremely high requirements on stability and security. |

### OH_AbilityRuntime_ThreadMode

```c
enum OH_AbilityRuntime_ThreadMode
```

**Description**

Defines the thread mode of ModularObjectExtensionAbility.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ABILITY_RUNTIME_THREAD_MODE_BUNDLE = 0 | Indicates that all ModularObjectExtensionAbility instances of the same app share a thread. All instances are executed sequentially in the same thread, minimizing resource overhead, but avoid blocking other instances due to a single instance. |
| OH_ABILITY_RUNTIME_THREAD_MODE_TYPE = 1 | Indicates that ModularObjectExtensionAbility instances with the same Ability name share a thread. ModularObjectExtensionAbility instances with the same Ability name share a thread, while instances with different Ability names use different threads, balancing resource consumption and concurrency performance. |
| OH_ABILITY_RUNTIME_THREAD_MODE_INSTANCE = 2 | Indicates that each ModularObjectExtensionAbility instance exclusively occupies a thread. Each ModularObjectExtensionAbility instance has an independent thread without interfering with each other, suitable for scenarios requiring high concurrency or strict response time. |

## Function Description

### OH_AbilityRuntime_GetModularObjectExtensionInfoLaunchMode()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoLaunchMode(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, OH_AbilityRuntime_LaunchMode *launchMode)
```

**Description**

Obtains the startup mode from the specified ModularObjectExtensionAbility information.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) extensionInfo | Information handle of the target ModularObjectExtensionAbility. |
| [OH_AbilityRuntime_LaunchMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_launchmode) *launchMode | Pointer to [OH_AbilityRuntime_LaunchMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_launchmode), used to receive the startup mode. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) extensionInfo or launchMode is null. |

### OH_AbilityRuntime_GetModularObjectExtensionInfoProcessMode()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoProcessMode(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, OH_AbilityRuntime_ProcessMode *processMode)
```

**Description**

Obtains the process mode from the specified ModularObjectExtensionAbility information.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) extensionInfo | Information handle of the target ModularObjectExtensionAbility. |
| [OH_AbilityRuntime_ProcessMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_processmode) *processMode | Pointer to [OH_AbilityRuntime_ProcessMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_processmode) for receiving the process mode. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) extensionInfo or processMode is null. |

### OH_AbilityRuntime_GetModularObjectExtensionInfoThreadMode()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoThreadMode(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, OH_AbilityRuntime_ThreadMode *threadMode)
```

**Description**

Obtains the thread mode from the specified ModularObjectExtensionAbility information.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) extensionInfo | Information handle of the target ModularObjectExtensionAbility. |
| [OH_AbilityRuntime_ThreadMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_threadmode) *threadMode | Pointer to [OH_AbilityRuntime_ThreadMode](capi-modular-object-extension-manager-h.md#oh_abilityruntime_threadmode) used to receive the thread mode. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) extensionInfo or threadMode is null. |

### OH_AbilityRuntime_GetModularObjectExtensionInfoElementName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoElementName(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, AbilityBase_Element *element)
```

**Description**

Obtains the component name ([AbilityBase_Element](capi-abilitybase-element.md)) from the specified ModularObjectExtensionAbility information.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) extensionInfo | Information handle of the target ModularObjectExtensionAbility. |
| [AbilityBase_Element](capi-abilitybase-element.md) *element | Pointer to [AbilityBase_Element](capi-abilitybase-element.md) for receiving the component name. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) extensionInfo or element is null. |

### OH_AbilityRuntime_GetModularObjectExtensionInfoDisableState()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModularObjectExtensionInfoDisableState(OH_AbilityRuntime_ModObjExtensionInfoHandle extensionInfo, bool *isDisabled)
```

**Description**

Obtains the disabled state from the specified ModularObjectExtensionAbility information.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) extensionInfo | Information handle of the target ModularObjectExtensionAbility. |
| bool *isDisabled | Pointer to the boolean value used to receive the disabled state. The value **true** indicates that the ability is disabled and other apps are not allowed to connect to it; the value **false** indicates that the ability is not disabled and other apps are allowed to connect to it. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode): the API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode): extensionInfo or isDisabled is null. |

### OH_AbilityRuntime_AcquireSelfModularObjectExtensionInfos()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_AcquireSelfModularObjectExtensionInfos(OH_AbilityRuntime_AllModObjExtensionInfosHandle *outOwnedAllExtensionInfos)
```

**Description**

Obtains the information about all registered ModularObjectExtensionAbility instances of the current app, and returns the handle to the ModularObjectExtensionAbility information collection. Use [OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getcountfromallmodobjextensioninfos) to obtain the number of elements in the collection, and use [OH_AbilityRuntime_GetModObjExtensionInfoByIndex](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getmodobjextensioninfobyindex) to traverse each ModularObjectExtensionAbility information by index to obtain the startup mode, process mode, thread mode, and other attributes.

**Since**: 26.0.0

**Device behavior difference**: This API can be called normally only on PC/2in1 devices. On other devices, it returns the ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED error code.

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_AllModObjExtensionInfosHandle](capi-abilityruntime-oh-abilityruntime-allmodularobjectextensioninfos8h.md) *outOwnedAllExtensionInfos | Pointer to [OH_AbilityRuntime_AllModObjExtensionInfosHandle](capi-abilityruntime-oh-abilityruntime-allmodularobjectextensioninfos8h.md) for receiving the ModularObjectExtensionAbility information collection. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) outOwnedAllExtensionInfos is null.<br>         [ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The device does not support this operation. |

### OH_AbilityRuntime_ReleaseAllExtensionInfos()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ReleaseAllExtensionInfos(OH_AbilityRuntime_AllModObjExtensionInfosHandle *allExtensionInfos)
```

**Description**

Releases the ModularObjectExtensionAbility information collection obtained by [OH_AbilityRuntime_AcquireSelfModularObjectExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_acquireselfmodularobjectextensioninfos). When the ModularObjectExtensionAbility information collection is no longer needed, you must call this API to release the related resources to avoid memory leaks.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_AllModObjExtensionInfosHandle](capi-abilityruntime-oh-abilityruntime-allmodularobjectextensioninfos8h.md) *allExtensionInfos | Pointer to the handle of the ModularObjectExtensionAbility information collection to be released. After the release, this pointer is set to null. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) allExtensionInfos is null. |

**Reference**

[OH_AbilityRuntime_AcquireSelfModularObjectExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_acquireselfmodularobjectextensioninfos)

### OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos(OH_AbilityRuntime_AllModObjExtensionInfosHandle allExtensionInfos, size_t *count)
```

**Description**

Obtains the number of ModularObjectExtensionAbility information items contained in the ModularObjectExtensionAbility information collection. The returned count can be used to determine the upper limit of the index when traversing the collection, and works with [OH_AbilityRuntime_GetModObjExtensionInfoByIndex](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getmodobjextensioninfobyindex) to access each ModularObjectExtensionAbility information item in the collection.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_AllModObjExtensionInfosHandle](capi-abilityruntime-oh-abilityruntime-allmodularobjectextensioninfos8h.md) allExtensionInfos | Handle to the ModularObjectExtensionAbility information collection. |
| size_t *count | Pointer to a size_t used to receive the number of ModularObjectExtensionAbility information items. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) allExtensionInfos or count is null. |

### OH_AbilityRuntime_GetModObjExtensionInfoByIndex()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetModObjExtensionInfoByIndex(OH_AbilityRuntime_AllModObjExtensionInfosHandle allExtensionInfos, size_t index, OH_AbilityRuntime_ModObjExtensionInfoHandle *extensionInfo)
```

**Description**

Obtains the specified ModularObjectExtensionAbility information from the ModularObjectExtensionAbility information collection by index. The valid index range is [0, count), where count can be obtained through [OH_AbilityRuntime_GetCountFromAllModObjExtensionInfos](capi-modular-object-extension-manager-h.md#oh_abilityruntime_getcountfromallmodobjextensioninfos). The obtained ModularObjectExtensionAbility information handle can be used to query the startup mode, process mode, thread mode, and other attributes of the ModularObjectExtensionAbility.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_AllModObjExtensionInfosHandle](capi-abilityruntime-oh-abilityruntime-allmodularobjectextensioninfos8h.md) allExtensionInfos | Handle to the ModularObjectExtensionAbility information collection. |
| size_t index | Index of the target ModularObjectExtensionAbility information in the collection, which must be less than the information count contained in the collection. |
| [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md) *extensionInfo | Pointer to [OH_AbilityRuntime_ModObjExtensionInfoHandle](capi-abilityruntime-oh-abilityruntime-modularobjectextensioninfo8h.md), used to receive the ModularObjectExtensionAbility information handle at the specified index. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) allExtensionInfos or extensionInfo is null,<br>         or index is greater than or equal to the information count of ModularObjectExtensionAbility in the collection. |

### OH_AbilityRuntime_ConnectModularObjectExtensionAbility()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ConnectModularObjectExtensionAbility(AbilityBase_Want *want, OH_AbilityRuntime_ConnectOptions *connectOptions, int64_t *connectionId)
```

**Description**

Connects to a ModularObjectExtensionAbility.

**Since**: 26.0.0

**Device behavior difference:** This API can be called normally only on PC/2-in-1 devices. On other devices, it returns the error code ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED.

**Parameters**

| Name | Description |
| -- | -- |
| AbilityBase_Want *want | Want information required for connecting to the ModularObjectExtensionAbility. For details, see [AbilityBase_Want](capi-abilitybase-want.md). |
| OH_AbilityRuntime_ConnectOptions *connectOptions | Connection options. For details, see [OH_AbilityRuntime_ConnectOptions](capi-abilityruntime-oh-abilityruntime-connectoptions.md). |
| int64_t *connectionId | Pointer to an int64_t used to receive the connection ID. It can be used in a subsequent call to [OH_AbilityRuntime_DisconnectModularObjectExtensionAbility](capi-modular-object-extension-manager-h.md#oh_abilityruntime_disconnectmodularobjectextensionability). |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Returns a specific error code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The input parameter is invalid.<br>         [ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The device does not support connecting to a ModularObjectExtensionAbility.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The target ability does not exist.<br>         [ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The ability type is incorrect.<br>         [ABILITY_RUNTIME_ERROR_CODE_VISIBILITY_VERIFICATION_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The invisible component cannot be started.<br>         [ABILITY_RUNTIME_ERROR_CODE_STATIC_CFG_PERMISSION](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The specified process does not have the required permission.<br>         [ABILITY_RUNTIME_ERROR_CODE_CROSS_USER_OPERATION](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Cross-user operations are not allowed.<br>         [ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The crowdtest app has expired.<br>         [ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error.<br>         [ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The caller process is not in the foreground.<br>         [ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The number of instances of abilities with the same name exceeds 20.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_RUNNING_ABILITIES_WITH_UI](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The target app has no running UIAbility or UIExtensionAbility.<br>         [ABILITY_RUNTIME_ERROR_CODE_UPPER_RATE_LIMIT](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call frequency is too high, exceeding 20 times per second.<br>         [ABILITY_RUNTIME_ERROR_CODE_UPPER_CONNECTION_NUMBER_LIMIT](capi-ability-runtime-common-h.md#abilityruntime_errorcode) A process can connect to at most 5 abilities with the same name.<br>         [ABILITY_RUNTIME_ERROR_CODE_CROSS_APP_IN_PROCESS](capi-ability-runtime-common-h.md#abilityruntime_errorcode) In [OH_ABILITY_RUNTIME_LAUNCH_MODE_IN_PROCESS](capi-modular-object-extension-manager-h.md#oh_abilityruntime_launchmode) mode, the caller and the target ability are not in the same app. |

### OH_AbilityRuntime_DisconnectModularObjectExtensionAbility()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_DisconnectModularObjectExtensionAbility(int64_t connectionId)
```

**Description**

Disconnects from the ModularObjectExtensionAbility.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| int64_t connectionId | Connection ID, returned by [OH_AbilityRuntime_ConnectModularObjectExtensionAbility](capi-modular-object-extension-manager-h.md#oh_abilityruntime_connectmodularobjectextensionability). |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>         [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API call is successful.<br>         [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The input parameter is invalid.<br>         [ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |