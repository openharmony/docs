# ability_runtime_common.h


## 概述

声明元能力子系统的相关错误码。

**库**：libability_runtime.so

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**起始版本**：13

**相关模块**：[AbilityRuntime](_ability_runtime.md)


## 汇总

### 文件

| 名称                                                       | 描述                                                         |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| [ability_runtime_common.h](ability__runtime__common_8h.md) | 声明元能力基础框架的相关错误码。<br/>**引用文件**：<AbilityKit/ability_runtime/ability_runtime_common.h><br/>**库**：libability_runtime.so |


### 枚举

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED = 201,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED = 801,<br>    ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY = 16000001,<br>    ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE = 16000002,<br>    ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED = 16000008,<br>    ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE = 16000009,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTROLLED = 16000012,<br>    ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED = 16000013,<br>    ABILITY_RUNTIME_ERROR_CODE_CROSS_APP = 16000018,<br>    ABILITY_RUNTIME_ERROR_CODE_INTERNAL = 16000050,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY = 16000053<br/>} | 定义元能力模块错误码。 |
