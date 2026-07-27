# application_context.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

提供应用级别上下文相关的接口。

**引用文件：** <AbilityKit/ability_runtime/application_context.h>

**库：** libability_runtime.so

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 13

**相关模块：** [AbilityRuntime](capi-abilityruntime.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetcachedir) | 获取本应用的应用级的缓存目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)](#oh_abilityruntime_applicationcontextgetareamode) | 获取本应用的应用级的文件数据加密等级。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetbundlename) | 获取应用包名。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgettempdir) | 获取本应用的应用级的临时文件目录。该目录用于存储应用运行期间的临时文件，这些文件在应用退出或系统清理时可能被删除。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetfilesdir) | 获取本应用的应用级的通用文件目录。该目录用于存储应用需要持久化的文件，如用户生成的文档、下载的文件、应用数据等。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetdatabasedir) | 获取本应用的应用级的数据库文件目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetpreferencesdir) | 获取本应用的应用级的首选项文件目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetbundlecodedir) | 获取本应用的应用级的安装文件目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetdistributedfilesdir) | 获取本应用的应用级的分布式文件目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetcloudfiledir) | 获取本应用的应用级的云文件目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLogFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetlogfiledir) | 获取本应用的应用级的日志文件目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetResourceDir(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetresourcedir) | 获取本应用的应用级的资源目录。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want)](#oh_abilityruntime_startselfuiability) | 启动当前应用的UIAbility。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(AbilityBase_Want *want, AbilityRuntime_StartOptions *options)](#oh_abilityruntime_startselfuiabilitywithstartoptions) | 通过StartOptions启动当前应用的UIAbility。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetVersionCode(int64_t* versionCode)](#oh_abilityruntime_applicationcontextgetversioncode) | 获取应用版本号。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithPidResult(AbilityBase_Want *want, AbilityRuntime_StartOptions *options, int32_t *targetPid)](#oh_abilityruntime_startselfuiabilitywithpidresult) | 通过StartOptions启动当前应用的UIAbility，并获取目标UIAbility的进程号。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLaunchParameter(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetlaunchparameter) | 获取本应用首次启动UIAbility的WantParams参数。|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLatestParameter(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetlatestparameter)| 获取本应用最近一次启动UIAbility的WantParams参数。|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextNotifyPageChanged(const char* targetPageName, int32_t targetPageNameLength, int32_t windowId)](#oh_abilityruntime_applicationcontextnotifypagechanged) | 该接口仅支持三方框架调用。三方框架每次切换页面时，将目标页面信息（包含目标页面路径、目标页面路径长度、目标页面对应的窗口ID）通知给系统。使系统能够感知到当前应用窗口处于哪个页面，从而进行页面管理。 |

## 函数说明

### OH_AbilityRuntime_ApplicationContextGetCacheDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的缓存目录。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收本应用的应用级的缓存目录。 |
| int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetAreaMode()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)
```

**描述**

获取本应用的应用级的文件数据加密等级。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityRuntime_AreaMode](capi-context-constant-h.md#abilityruntime_areamode)* areaMode | 指向接收数据加密等级的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - areaMode为null。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetBundleName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用包名。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收应用包名。 |
| int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetTempDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的临时文件目录。该目录用于存储应用运行期间的临时文件，这些文件在应用退出或系统清理时可能被删除。

**起始版本：** 16

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收临时文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetFilesDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的通用文件目录。该目录用于存储应用需要持久化的文件，如用户生成的文档、下载的文件、应用数据等。

**起始版本：** 16

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收通用文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetDatabaseDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的数据库文件目录。

**起始版本：** 16

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收数据库文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetPreferencesDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的首选项文件目录。

**起始版本：** 16

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收首选项文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetBundleCodeDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的安装文件目录。

**起始版本：** 16

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收安装文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的分布式文件目录。

**起始版本：** 16

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收分布式文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetCloudFileDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的云文件目录。

**起始版本：** 16

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收云文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetLogFileDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLogFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的日志文件目录。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收日志文件目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_ApplicationContextGetResourceDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetResourceDir(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的资源目录。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* moduleName | 模块名，用于指定要获取资源目录的目标模块。开发者可通过bundleManager模块的接口获取应用包含的模块名列表，不同模块名对应不同的资源目录路径。 |
| char* buffer | 指向缓冲区的指针，用于接收资源目录。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入到缓冲区的字符串长度，单位为字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

### OH_AbilityRuntime_StartSelfUIAbility()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want)
```

**描述**

启动当前应用的UIAbility。


**需要权限：** ohos.permission.NDK_START_SELF_UI_ABILITY

**起始版本：** 15

**设备行为差异**：该接口仅在PC/2in1和Tablet设备中可正常调用，在其他设备中返回ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED错误码。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md) *want | 启动当前应用UIAbility时需要的Want信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 接口调用成功。<br>ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED - 调用方权限校验失败。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 调用方入参校验失败。<br>ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED - 设备类型不支持。<br>ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY - 指定的Ability名称不存在。<br>ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE - 接口调用Ability类型错误。<br>ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED - 众测应用到期。<br>ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE - Wukong模式，不允许启动/停止Ability。<br>ABILITY_RUNTIME_ERROR_CODE_CONTROLLED - 应用被管控。<br>ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED - 应用被EDM管控。<br>ABILITY_RUNTIME_ERROR_CODE_CROSS_APP - 限制API 11以上版本三方应用跳转。<br>ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 内部错误。<br>ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY - 非顶层应用。<br>ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED - 应用多实例已达到上限（从API17开始）。<br>ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED - 不允许设置APP_INSTANCE_KEY（从API17开始）。<br>详细内容参考AbilityRuntime_ErrorCode。 |

**示例代码：**

```cpp
#include <AbilityKit/ability_base/want.h>
#include <AbilityKit/ability_runtime/application_context.h>

void startSelfUIAbilityTest()
{
    AbilityBase_Element element;
    element.abilityName = const_cast<char*>("EntryAbility");
    element.bundleName = const_cast<char*>("com.example.myapplication");
    element.moduleName = const_cast<char*>("entry");
    AbilityBase_Want* want = OH_AbilityBase_CreateWant(element);

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_StartSelfUIAbility(want);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
        return;
    }
    // 销毁want，防止内存泄漏
    OH_AbilityBase_DestroyWant(want);
}
```

### OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(AbilityBase_Want *want,AbilityRuntime_StartOptions *options)
```

**描述**

通过StartOptions启动当前应用的UIAbility。

**需要权限：** ohos.permission.NDK_START_SELF_UI_ABILITY

**起始版本：** 17

**设备行为差异**：该接口仅在PC/2in1和Tablet设备中可正常调用，在其他设备中返回ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED错误码。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md) *want | 启动当前应用UIAbility时需要的Want信息。 |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *options | 启动当前应用UIAbility时需要的StartOptions信息。如果该参数中[startVisibility](capi-context-constant-h.md#abilityruntime_startvisibility)属性的值不为空，必须确保当前应用已添加到状态栏，否则会返回[ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode)错误码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 接口调用成功。<br>ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED - 调用方权限校验失败。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 调用方入参校验失败。<br>ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED - 设备类型不支持。<br>ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY - 指定的Ability名称不存在。<br>ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE - 接口调用Ability类型错误。<br>ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED - 众测应用到期。<br>ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE - Wukong模式，不允许启动/停止Ability。<br>ABILITY_RUNTIME_ERROR_CODE_CONTROLLED - 应用被管控。<br>ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED - 应用被EDM管控。<br>ABILITY_RUNTIME_ERROR_CODE_CROSS_APP - 限制API 11以上版本三方应用跳转。<br>ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 内部错误。<br>ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY - 非顶层应用。<br>ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED - 不允许设置窗口启动可见性。<br>ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED - 不支持应用分身和多实例。<br>ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY - 无效多实例。<br> ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED - 应用多实例已达到上限。<br>ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED - 不支持应用多实例。<br>ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED - 不允许设置APP_INSTANCE_KEY。<br>详细内容参考AbilityRuntime_ErrorCode。 |

**示例代码：**

```cpp
#include <AbilityKit/ability_base/want.h>
#include <AbilityKit/ability_runtime/application_context.h>

void demo()
{
    AbilityBase_Element element;
    element.abilityName = const_cast<char*>("EntryAbility");
    element.bundleName = const_cast<char*>("com.example.myapplication");
    element.moduleName = const_cast<char*>("entry");
    AbilityBase_Want* want = OH_AbilityBase_CreateWant(element);
    if (want == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理

        // 销毁want，防止内存泄漏
        OH_AbilityBase_DestroyWant(want);
        return;
    }
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(want, options);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁want，防止内存泄漏
    OH_AbilityBase_DestroyWant(want);

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_ApplicationContextGetVersionCode()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetVersionCode(int64_t* versionCode)
```

**描述**

获取应用版本号。

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t* [versionCode](js-apis-bundleManager-bundleInfo.md#bundleinfo-1) | 指向应用包版本号的指针，对应bundleInfo中的versionCode字段。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参versionCode为空。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。<br>ABILITY_RUNTIME_ERROR_CODE_GET_APPLICATION_INFO_FAILED  - 获取应用信息失败，如应用未安装或应用信息损坏。 |

### OH_AbilityRuntime_StartSelfUIAbilityWithPidResult()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithPidResult(AbilityBase_Want *want, AbilityRuntime_StartOptions *options, int32_t *targetPid)
```

**描述**

通过StartOptions启动当前应用的UIAbility，并获取目标UIAbility的进程号。

接口不能在应用主线程调用，但可以在应用创建的[ChildProcess](capi-childprocess.md)的主线程中调用。

如果在应用的主线程中调用，会返回ABILITY_RUNTIME_ERROR_CODE_MAIN_THREAD_NOT_SUPPORTED错误码。

**需要权限：** ohos.permission.NDK_START_SELF_UI_ABILITY

**起始版本：** 21

**设备行为差异**：该接口仅在PC/2in1和Tablet设备中可正常调用，在其他设备中返回ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED错误码。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md) *want | 启动当前应用UIAbility时需要的Want信息。 |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *options | 启动当前应用UIAbility时需要的StartOptions信息。如果该参数中[startVisibility](capi-context-constant-h.md#abilityruntime_startvisibility)属性的值不为空，必须确保当前应用已添加到状态栏，否则会返回[ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode)错误码。 |
| int32_t *targetPid | 目标UIAbility所在的进程号，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 接口调用成功。<br>ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED - 调用方权限校验失败。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 调用方入参校验失败。<br>ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED - 设备类型不支持。<br>ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY - 指定的Ability名称不存在。<br>ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE - 接口调用Ability类型错误。<br>ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED - 众测应用到期。<br>ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE - Wukong模式，不允许启动/停止Ability。<br>ABILITY_RUNTIME_ERROR_CODE_CONTROLLED - 应用被管控。<br>ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED - 应用被EDM管控。<br>ABILITY_RUNTIME_ERROR_CODE_CROSS_APP - 限制API 11以上版本三方应用跳转。<br>ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 内部错误。<br>ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY - 非顶层应用。<br>ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED - 不允许设置窗口启动可见性。<br>ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED - 不支持应用分身和多实例。<br>ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY - 无效多实例。<br> ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED - 应用多实例已达到上限。<br>ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED - 不支持应用多实例。<br>ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED - 不允许设置APP_INSTANCE_KEY。<br>ABILITY_RUNTIME_ERROR_CODE_START_TIMEOUT - 启动UIAbility超时。<br>ABILITY_RUNTIME_ERROR_CODE_MAIN_THREAD_NOT_SUPPORTED - 接口不允许在应用主线程被调用。 |

**示例代码：**

```cpp
#include <AbilityKit/ability_base/want.h>
#include <AbilityKit/ability_runtime/application_context.h>

void demo()
{
    AbilityBase_Element element;
    element.abilityName = const_cast<char*>("EntryAbility");
    element.bundleName = const_cast<char*>("com.example.myapplication");
    element.moduleName = const_cast<char*>("entry");
    AbilityBase_Want* want = OH_AbilityBase_CreateWant(element);
    if (want == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理

        // 销毁want，防止内存泄漏
        OH_AbilityBase_DestroyWant(want);
        return;
    }
    int32_t pid = -1;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_StartSelfUIAbilityWithPidResult(want, options, &pid);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁want，防止内存泄漏
    OH_AbilityBase_DestroyWant(want);

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_ApplicationContextGetLaunchParameter()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLaunchParameter(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用首次启动UIAbility时的WantParams参数，WantParams可参考[Want中的parameters参数](js-apis-inner-ability-want.md)。

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收WantParams参数。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入缓冲区的字符串长度（单位：字节）。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。|

**示例：**
```cpp
#include "napi/native_api.h"
#include "AbilityKit/ability_runtime/application_context.h"

static napi_value GetLaunchParameter(napi_env env, napi_callback_info info)
{
    const int32_t bufferSize = 2048; // 根据实际需要调整缓冲区大小
    char buffer[bufferSize] = {0};
    int32_t writeLength = 0;
    int32_t ret = OH_AbilityRuntime_ApplicationContextGetLaunchParameter(buffer, bufferSize, &writeLength);

    if (ret != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 失败处理
    }
    // 创建 JS 字符串返回WantParams
    napi_value result;
    napi_create_string_utf8(env, buffer, writeLength, &result);
    return result;
}
```

### OH_AbilityRuntime_ApplicationContextGetLatestParameter()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetLatestParameter(
    char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用最近一次启动UIAbility时的WantParams参数，WantParams可参考[Want中的parameters参数](js-apis-inner-ability-want.md)。适用于需要获取最近一次启动时传递的参数，用于处理最新的启动请求、页面跳转参数解析等场景。

**起始版本：** 21

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* buffer | 指向缓冲区的指针，用于接收WantParams参数。 |
| const int32_t bufferSize | 缓冲区大小，单位为字节。 |
| int32_t* writeLength | 在返回[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode)时，表示实际写入缓冲区的字符串长度（单位：字节）。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 应用上下文不存在，如在应用创建的[ChildProcess](capi-childprocess.md)中应用级别上下文不存在。 |

**示例：**
```cpp
#include "napi/native_api.h"
#include "AbilityKit/ability_runtime/application_context.h"

static napi_value GetLatestParameter(napi_env env, napi_callback_info info)
{
    const int32_t bufferSize = 2048; // 根据实际需要调整缓冲区大小
    char buffer[bufferSize] = {0};
    int32_t writeLength = 0;
    int32_t ret = OH_AbilityRuntime_ApplicationContextGetLatestParameter(buffer, bufferSize, &writeLength);

    if (ret != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 失败处理
    }
    // 创建 JS 字符串返回WantParams
    napi_value result;
    napi_create_string_utf8(env, buffer, writeLength, &result);
    return result;
}
```

### OH_AbilityRuntime_ApplicationContextNotifyPageChanged()

```cpp
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextNotifyPageChanged(
    const char* targetPageName, int32_t targetPageNameLength, int32_t windowId)
```

**描述**

该接口仅支持三方框架调用。三方框架每次切换页面时，将目标页面信息（包含目标页面路径、目标页面路径长度、目标页面对应的窗口ID）通知给系统。系统可按产品策略调整/恢复页面。适用于三方框架页面导航追踪、页面状态同步、系统级页面优化等场景。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* targetPageName | 目标页面路径。 |
| int32_t targetPageNameLength | 目标页面路径长度。 |
| int32_t windowId | 目标页面对应的[WindowInfo](../apis-arkui/arkts-apis-window-i.md#windowinfo18)中的窗口ID。|

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | 返回执行结果。<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 操作成功。<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参targetPageName为空或者windowId无效。<br>ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 内部错误。 |

**示例：**
```cpp
#include "napi/native_api.h"
#include "AbilityKit/ability_runtime/application_context.h"

static bool NotifyPageChanged(napi_env env, napi_callback_info info)
{
    const char* testPageName = "https://home.taobao.com/homepage";
    int32_t testPageNameLen = 32;
    int32_t testWindowId = 12; // 示例数值仅供参考，实际开发需使用有效的窗口ID。
    int32_t ret = OH_AbilityRuntime_ApplicationContextNotifyPageChanged(testPageName, testPageNameLen, testWindowId);

    if (ret != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 失败处理
        return false;
    }
    return true;
}
```