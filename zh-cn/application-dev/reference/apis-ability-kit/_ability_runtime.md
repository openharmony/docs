# AbilityRuntime


## 概述

提供元能力基础框架的相关能力。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [ability_runtime_common.h](ability__runtime__common_8h.md) | 声明元能力子系统的相关错误码。<br/>**引用文件**：<AbilityKit/ability_runtime/ability_runtime_common.h><br/>**库**：libability_runtime.so |
| [application_context.h](application__context_8h.md) | 声明应用级别的上下文能力。<br/>**引用文件**：<AbilityKit/ability_runtime/application_context.h><br/>**库**：libability_runtime.so |
| [context_constant.h](context__constant_8h.md) | 声明上下文相关的枚举。<br/>**引用文件**：<AbilityKit/ability_runtime/context_constant.h><br/>**库**：libability_runtime.so |

### 枚举

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br/>} | 定义元能力模块错误码。 |
| [AbilityRuntime_AreaMode](#abilityruntime_areamode) {<br/>    ABILITY_RUNTIME_AREA_MODE_EL1 = 0,<br/>    ABILITY_RUNTIME_AREA_MODE_EL2 = 1,<br/>    ABILITY_RUNTIME_AREA_MODE_EL3 = 2,<br/>    ABILITY_RUNTIME_AREA_MODE_EL4 = 3,<br/>    ABILITY_RUNTIME_AREA_MODE_EL5 = 4<br/>} | 定义数据加密等级。     |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCacheDir](#oh_abilityruntime_applicationcontextgetcachedir)(char* buffer, int32_t bufferSize, int32_t* writeLength) | 获取应用级别的缓存目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetAreaMode](#oh_abilityruntime_applicationcontextgetareamode)([AbilityRuntime_AreaMode](#abilityruntime_areamode)* areaMode) | 获取应用级别的数据加密等级。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleName](#oh_abilityruntime_applicationcontextgetbundlename)(char* buffer, int32_t bufferSize, int32_t* writeLength) | 获取应用包名。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetTempDir](#oh_abilityruntime_applicationcontextgettempdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取应用级别的临时文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetFilesDir](#oh_abilityruntime_applicationcontextgetfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取应用级别的通用文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDatabaseDir](#oh_abilityruntime_applicationcontextgetdatabasedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取应用级别的数据库文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetPreferencesDir](#oh_abilityruntime_applicationcontextgetpreferencesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取应用级别的首选项文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleCodeDir](#oh_abilityruntime_applicationcontextgetbundlecodedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取应用级别的安装文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir](#oh_abilityruntime_applicationcontextgetdistributedfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取应用级别的分布式文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCloudFileDir](#oh_abilityruntime_applicationcontextgetcloudfiledir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取应用级别的云文件目录。 |

## 枚举类型说明

### AbilityRuntime_ErrorCode

```
enum AbilityRuntime_ErrorCode
```

**描述**

定义元能力模块错误码。

**起始版本：** 13

| 枚举值                                        | 描述           |
| --------------------------------------------- | -------------- |
| ABILITY_RUNTIME_ERROR_CODE_NO_ERROR           | 操作成功。     |
| ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID ARAM | 无效参数。     |
| ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  | 上下文不存在。 |

### AbilityRuntime_AreaMode

```
enum AbilityRuntime_AreaMode
```

**描述**

定义数据加密等级。

**起始版本：** 13

| 枚举值                        | 描述                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_AREA_MODE_EL1 | 对于私有文件，如闹铃、壁纸等，应用可以将这些文件放到设备级加密分区（EL1）中，以保证在用户输入密码前就可以被访问。 |
| ABILITY_RUNTIME_AREA_MODE_EL2 | 对于更敏感的文件，如个人隐私信息等，应用可以将这些文件放到更高级别的加密分区（EL2）中，以保证更高的安全性。 |
| ABILITY_RUNTIME_AREA_MODE_EL3 | 对于应用中的记录步数、文件下载、音乐播放，需要在锁屏时读写和创建新文件，放在（EL3）的加密分区比较合适。 |
| ABILITY_RUNTIME_AREA_MODE_EL4 | 对于用户安全信息相关的文件，锁屏时不需要读写文件、也不能创建文件，放在（EL4）的加密分区更合适。 |
| ABILITY_RUNTIME_AREA_MODE_EL5 | 对于用户隐私敏感数据文件，锁屏后默认不可读写，如果锁屏后需要读写文件，则锁屏前可以调用[Access](js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess)接口申请继续读写文件，或者锁屏后也需要创建新文件且可读写，放在（EL5）的应用级加密分区更合适。 |

## 函数说明


### OH_AbilityRuntime_ApplicationContextGetCacheDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)
```
**描述**

获取应用级别的缓存目录。

**起始版本：** 13

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 缓冲区，缓存目录字符串写入该区域。 |
| bufferSize | 缓冲区大小。 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetAreaMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)
```

**描述**

获取应用级别的数据加密等级。

**起始版本：** 13

**参数:**

| 名称     | 描述                     |
| -------- | ------------------------ |
| areaMode | 用于接受加密等级的指针。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参areaMode为空。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetBundleName

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用包名。

**起始版本：** 13

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，应用包名字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetTempDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用级别的临时文件目录。

**起始版本：** 16

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用级别的通用文件目录。

**起始版本：** 16

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetDatabaseDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength);
```

**描述**

获取应用级别的数据库文件目录。

**起始版本：** 16

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetPreferencesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用级别的首选项文件目录。

**起始版本：** 16

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetBundleCodeDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用级别的安装文件目录。

**起始版本：** 16

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用级别的分布式文件目录。

**起始版本：** 16

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetCloudFileDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取应用级别的云文件目录。

**起始版本：** 16

**参数:**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小。                                                 |
| writeLength | 在返回ABILITY_RUNTIME_ERROR_CODE_NO_ERROR时，表示实际写入到缓冲区的字符串长度。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。
