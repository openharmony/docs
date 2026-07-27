# native_ability_wrapper.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wangzhen416-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @HelloCrease-->

## 概述

提供NativeAbility数据信息相关接口，用于获取Ability实例ID、Ability名称和napi_env等信息。

**引用文件：** <AbilityKit/ability_runtime/native_ability_wrapper.h>

**库：** libability_runtime.so

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 26.0.0

**相关模块：** [AbilityRuntime](capi-abilityruntime.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [AbilityRuntime_NativeAbilityWrapper](capi-abilityruntime-nativeabilitywrapper.md) | AbilityRuntime_NativeAbilityWrapper | NativeAbility数据信息结构体类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetAbilityInstanceId(const AbilityRuntime_NativeAbilityWrapper* nativeAbilityWrapper, char* buffer, const int32_t bufferSize)](#oh_abilityruntime_getabilityinstanceid) | 从NativeAbility数据信息中获取Ability实例ID。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetAbilityName(const AbilityRuntime_NativeAbilityWrapper *nativeAbilityWrapper, char *buffer, const int32_t bufferSize, int32_t *writeLength)](#oh_abilityruntime_getabilityname) | 从NativeAbility数据信息中获取Ability名称。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetEnv(const AbilityRuntime_NativeAbilityWrapper* nativeAbilityWrapper, napi_env* env)](#oh_abilityruntime_getenv) | 从NativeAbility数据信息中获取napi_env。 |

## 函数说明

### OH_AbilityRuntime_GetAbilityInstanceId()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetAbilityInstanceId(
    const AbilityRuntime_NativeAbilityWrapper* nativeAbilityWrapper,
    char* buffer,
    const int32_t bufferSize)
```

**描述**

从NativeAbility数据信息中获取Ability实例ID。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityRuntime_NativeAbilityWrapper](capi-abilityruntime-nativeabilitywrapper.md)* nativeAbilityWrapper | NativeAbility数据信息指针。 |
| char* buffer | 接收实例ID字符串的缓冲区指针。实例ID为UUID格式，长度为37字节。 |
| int32_t bufferSize | 缓冲区长度，必须至少为37字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回错误码。<br>返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示操作成功。<br>返回[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示nativeAbilityWrapper或buffer为空指针，或bufferSize小于37。 |

**示例代码：**

```cpp
#include <AbilityKit/ability_runtime/native_ability_wrapper.h>
#include <AbilityKit/ability_runtime/ability_runtime_common.h>

void GetAbilityInstanceId(const AbilityRuntime_NativeAbilityWrapper* wrapper)
{
    if (wrapper == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }
    // buffer中存储了UUID格式的Ability实例ID
    char buffer[37] = {0};
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetAbilityInstanceId(wrapper, buffer, 37);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
        return;
    }
}
```

### OH_AbilityRuntime_GetAbilityName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetAbilityName(
    const AbilityRuntime_NativeAbilityWrapper *nativeAbilityWrapper, 
    char *buffer, 
    const int32_t bufferSize,
    int32_t *writeLength)
```

**描述**

从NativeAbility数据信息中获取Ability名称。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityRuntime_NativeAbilityWrapper](capi-abilityruntime-nativeabilitywrapper.md)* nativeAbilityWrapper | NativeAbility数据信息指针。 |
| char* buffer | 接收Ability名称字符串的缓冲区指针。传入nullptr可查询Ability名称长度。 |
| int32_t bufferSize | 缓冲区长度（字节）。确保缓冲区至少有额外一个字节用于'\0'。 |
| int32_t* writeLength | 输出Ability名称字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回错误码。<br>返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示操作成功。<br>返回[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示nativeAbilityWrapper或writeLength为空指针，或缓冲区太小无法存储Ability名称。<br>返回[ABILITY_RUNTIME_ERROR_CODE_ABILITY_WRAPPER_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示NativeAbility数据信息无效或不完整。<br>返回[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示内部错误。 |

**示例代码：**

```cpp
#include <AbilityKit/ability_runtime/native_ability_wrapper.h>
#include <AbilityKit/ability_runtime/ability_runtime_common.h>

void GetAbilityName(const AbilityRuntime_NativeAbilityWrapper* wrapper)
{
    if (wrapper == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    const int32_t bufferSize = 256; // 根据实际需要调整缓冲区大小
    char buffer[bufferSize] = {0};
    int32_t writeLength = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetAbilityName(wrapper, buffer, bufferSize, &writeLength);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
        return;
    }
}
```

### OH_AbilityRuntime_GetEnv()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetEnv(
    const AbilityRuntime_NativeAbilityWrapper* nativeAbilityWrapper, 
    napi_env* env)
```

**描述**

从NativeAbility数据信息中获取napi_env。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityRuntime_NativeAbilityWrapper](capi-abilityruntime-nativeabilitywrapper.md)* nativeAbilityWrapper | NativeAbility数据信息指针。 |
| napi_env* env | 接收napi_env值的指针。napi_env在进程终止前一直有效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回错误码。<br>返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示操作成功。<br>返回[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示nativeAbilityWrapper或env为空指针。<br>返回[ABILITY_RUNTIME_ERROR_CODE_ABILITY_WRAPPER_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode)表示NativeAbility数据信息无效或不完整。 |

**示例代码：**

```cpp
#include <AbilityKit/ability_runtime/native_ability_wrapper.h>
#include <AbilityKit/ability_runtime/ability_runtime_common.h>
#include <napi/native_api.h>

void GetEnv(const AbilityRuntime_NativeAbilityWrapper* wrapper)
{
    if (wrapper == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    napi_env env = nullptr;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetEnv(wrapper, &env);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
        return;
    }
}
```