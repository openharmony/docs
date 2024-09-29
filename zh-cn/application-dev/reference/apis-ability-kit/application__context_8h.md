# application_context.h


## 概述

声明应用级别的上下文能力。

**库：** libability_runtime.so

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 13

**相关模块：**[AbilityRuntime](_ability_runtime.md)


## 汇总

### 文件

| 名称                                                | 描述                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ |
| [application_context.h](application__context_8h.md) | 声明应用级别的上下文能力。<br/>**引用文件**：<AbilityKit/ability_runtime/application_context.h><br/>**库**：libability_runtime.so |

### 函数

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCacheDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetcachedir)(char* buffer, int32_t bufferSize, int32_t* writeLength) | 获取应用级别的缓存目录。     |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetAreaMode](_ability_runtime.md#oh_abilityruntime_applicationcontextgetareamode)([AbilityRuntime_AreaMode](_ability_runtime.md#abilityruntime_areamode)* areaMode) | 获取应用级别的数据加密等级。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleName](_ability_runtime.md#oh_abilityruntime_applicationcontextgetbundlename)(char* buffer, int32_t bufferSize, int32_t* writeLength) | 获取应用包名。               |