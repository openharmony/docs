# ability_runtime_common.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## Overview

The file declares the error codes of the AbilityRuntime module.

**File to include**: <AbilityKit/ability_runtime/ability_runtime_common.h>

**Library**: libability_runtime.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13

**Related module**: [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) | AbilityRuntime_ErrorCode | Enumerates the error codes of the AbilityRuntime module.|

## Enum Description

### AbilityRuntime_ErrorCode

```
enum AbilityRuntime_ErrorCode
```

**Description**

Enumerates the error codes of the AbilityRuntime module.

**Since**: 13

| Value| Description|
| -- | -- |
| ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0 | Operation successful.|
| ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED = 201 |  Permission verification fails.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401 | Invalid parameter.|
| ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED = 801 |  The device type is not supported.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY = 16000001 |  The specified ability name does not exist.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE = 16000002 |  The ability type is incorrect.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED = 16000008 |  The crowdtesting application expires.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE = 16000009 |  An ability cannot be started or stopped in Wukong mode.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011 | The context does not exist.|
| ABILITY_RUNTIME_ERROR_CODE_CONTROLLED = 16000012 |  The application is under control.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED = 16000013 |  The application is under control by EDM.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CROSS_APP = 16000018 |  Redirection to third-party applications is not allowed in API versions later than 11.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_INTERNAL = 16000050 |  Internal server error.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY = 16000053 |  The application is not on top.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED = 16000067 |  Setting the window visibility during startup is not allowed.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED = 16000072 |  The application does not support clone or multi-instance mode.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY = 16000076 |  The multi-instance key is invalid.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED = 16000077 |  The number of instances has reached the upper limit.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED = 16000078 |  The application does not support multi-instance mode.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED = 16000079 |  Setting **APP_INSTANCE_KEY** is not supported.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_GET_APPLICATION_INFO_FAILED = 16000081 |  Failed to obtain the application information.<br>**Since**: 21|
