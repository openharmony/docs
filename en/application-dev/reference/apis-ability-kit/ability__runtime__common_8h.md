# ability_runtime_common.h


## Overview

The **ability_runtime_common.h** file declares the error codes of the ability framework.

**Library**: libability_runtime.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13

**Related module**: [AbilityRuntime](_ability_runtime.md)


## Summary

### Files

| Name                                                      | Description                                                        |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| [ability_runtime_common.h](ability__runtime__common_8h.md) | Declares error codes related to the ability framework.<br>**File to include**: <AbilityKit/ability_runtime/ability_runtime_common.h><br>**Library**: libability_runtime.so|


### Enums

| Name                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED = 201,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED = 801,<br>    ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY = 16000001,<br>    ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE = 16000002,<br>    ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED = 16000008,<br>    ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE = 16000009,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTROLLED = 16000012,<br>    ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED = 16000013,<br>    ABILITY_RUNTIME_ERROR_CODE_CROSS_APP = 16000018,<br>    ABILITY_RUNTIME_ERROR_CODE_INTERNAL = 16000050,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY = 16000053<br/>} | Enumerates the error codes used by the ability framework. |
