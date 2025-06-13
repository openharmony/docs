# AbilityRuntime


## 概述

提供元能力基础框架的相关能力。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**起始版本**：13


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [ability_runtime_common.h](ability__runtime__common_8h.md) | 声明元能力子系统的相关错误码。<br/>**引用文件**：<AbilityKit/ability_runtime/ability_runtime_common.h><br/>**库**：libability_runtime.so |
| [application_context.h](application__context_8h.md) | 声明应用级别的上下文能力。<br/>**引用文件**：<AbilityKit/ability_runtime/application_context.h><br/>**库**：libability_runtime.so |
| [context_constant.h](context__constant_8h.md) | 声明上下文相关的枚举。<br/>**引用文件**：<AbilityKit/ability_runtime/context_constant.h><br/>**库**：libability_runtime.so |
| [start_options.h](start__options_8h.md) | 声明StartOptions结构体以及结构体相关函数。<br/>**引用文件**：<AbilityKit/ability_runtime/start_options.h><br/>**库**：libability_runtime.so |

### 枚举

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED = 201,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED = 801,<br>    ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY = 16000001,<br>    ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE = 16000002,<br>    ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED = 16000008,<br>    ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE = 16000009,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTROLLED = 16000012,<br>    ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED = 16000013,<br>    ABILITY_RUNTIME_ERROR_CODE_CROSS_APP = 16000018,<br>    ABILITY_RUNTIME_ERROR_CODE_INTERNAL = 16000050,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY = 16000053,<br>    ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED = 16000067,<br>    ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED = 16000072,<br>    ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY = 16000076,<br>    ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED = 16000077,<br>    ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED = 16000078,<br>    ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED = 16000079<br/>} | 定义元能力模块错误码。 |
| [AbilityRuntime_AreaMode](#abilityruntime_areamode) {<br/>    ABILITY_RUNTIME_AREA_MODE_EL1 = 0,<br/>    ABILITY_RUNTIME_AREA_MODE_EL2 = 1,<br/>    ABILITY_RUNTIME_AREA_MODE_EL3 = 2,<br/>    ABILITY_RUNTIME_AREA_MODE_EL4 = 3,<br/>    ABILITY_RUNTIME_AREA_MODE_EL5 = 4<br/>} | 定义数据加密等级。     |
| [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility) {<br/>    ABILITY_RUNTIME_HIDE_UPON_START = 0,<br/>    ABILITY_RUNTIME_SHOW_UPON_START = 1<br/>} | 定义启动Ability时的窗口和dock栏图标显示模式。     |
| [AbilityRuntime_WindowMode](#abilityruntime_windowmode) {<br/>    ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED = 0,</br>    ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN = 1<br/>} | 定义启动应用时支持的窗口模式。     |
| [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode) {<br/>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN = 0,<br/>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT = 1,<br/>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING = 2<br/>} | 定义启动应用时支持的窗口模式。     |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCacheDir](#oh_abilityruntime_applicationcontextgetcachedir)(char* buffer, int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的缓存目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetAreaMode](#oh_abilityruntime_applicationcontextgetareamode)([AbilityRuntime_AreaMode](#abilityruntime_areamode)* areaMode) | 获取本应用的应用级的数据加密等级。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleName](#oh_abilityruntime_applicationcontextgetbundlename)(char* buffer, int32_t bufferSize, int32_t* writeLength) | 获取应用包名。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetTempDir](#oh_abilityruntime_applicationcontextgettempdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的临时文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetFilesDir](#oh_abilityruntime_applicationcontextgetfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的通用文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDatabaseDir](#oh_abilityruntime_applicationcontextgetdatabasedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的数据库文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetPreferencesDir](#oh_abilityruntime_applicationcontextgetpreferencesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的首选项文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleCodeDir](#oh_abilityruntime_applicationcontextgetbundlecodedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的安装文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir](#oh_abilityruntime_applicationcontextgetdistributedfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的分布式文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCloudFileDir](#oh_abilityruntime_applicationcontextgetcloudfiledir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的云文件目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetResourceDir](#oh_abilityruntime_applicationcontextgetresourcedir)(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength) | 获取本应用的应用级的资源目录。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_StartSelfUIAbility](#oh_abilityruntime_startselfuiability)([AbilityBase_Want](_ability_base.md#abilitybase_want) *want) | 启动当前应用的UIAbility。 |
| [AbilityRuntime_StartOptions*](#abilityruntime_startoptions) [OH_AbilityRuntime_CreateStartOptions](#oh_abilityruntime_createstartoptions)(void) | 创建启动当前应用的UIAbility所需要的StartOptions结构体。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_DestroyStartOptions](#oh_abilityruntime_destroystartoptions)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) **startOptions) | 销毁StartOptions结构体。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowMode](#oh_abilityruntime_setstartoptionswindowmode)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_WindowMode](#abilityruntime_windowmode) windowMode) | 设置启动Ability时的窗口模式。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowMode](#oh_abilityruntime_getstartoptionswindowmode)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_WindowMode](#abilityruntime_windowmode) &windowMode) | 获取启动Ability时的窗口模式。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsDisplayId](#oh_abilityruntime_setstartoptionsdisplayid)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t displayId) | 设置启动Ability时窗口所在的屏幕ID。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsDisplayId](#oh_abilityruntime_getstartoptionsdisplayid)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &displayId) | 获取启动Ability时窗口所在的屏幕ID。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWithAnimation](#oh_abilityruntime_setstartoptionswithanimation)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, bool withAnimation) | 设置启动Ability时是否具有动画效果。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWithAnimation](#oh_abilityruntime_getstartoptionswithanimation)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, bool &withAnimation) | 获取启动Ability时是否具有动画效果。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowLeft](#oh_abilityruntime_setstartoptionswindowleft)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowLeft) | 设置启动Ability时的窗口左侧位置，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowLeft](#oh_abilityruntime_getstartoptionswindowleft)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowLeft) | 获取启动Ability时的窗口左侧位置，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowTop](#oh_abilityruntime_setstartoptionswindowtop)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowTop) | 设置启动Ability时的窗口顶部位置，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowTop](#oh_abilityruntime_getstartoptionswindowtop)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowTop) | 获取启动Ability时的窗口顶部位置，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowHeight](#oh_abilityruntime_setstartoptionswindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowHeight) | 设置启动Ability时的窗口高度，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowHeight](#oh_abilityruntime_getstartoptionswindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowHeight) | 获取启动Ability时的窗口高度，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowWidth](#oh_abilityruntime_setstartoptionswindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowWidth) | 设置启动Ability时的窗口宽度，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowWidth](#oh_abilityruntime_getstartoptionswindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowWidth) | 获取启动Ability时的窗口宽度，单位为px。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartVisibility](#oh_abilityruntime_setstartoptionsstartvisibility)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility) startVisibility) | 设置启动Ability时窗口和dock栏图标的显示模式。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartVisibility](#oh_abilityruntime_getstartoptionsstartvisibility)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility) &startVisibility) | 获取启动Ability时窗口和dock栏图标的显示模式。|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartWindowIcon](#oh_abilityruntime_setstartoptionsstartwindowicon)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [OH_PixelmapNative](../apis-image-kit/capi-oh-pixelmapnative.md) *startWindowIcon) | 设置启动Ability时的窗口启动图标。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartWindowIcon](#oh_abilityruntime_getstartoptionsstartwindowicon)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [OH_PixelmapNative](../apis-image-kit/capi-oh-pixelmapnative.md) **startWindowIcon) | 获取启动Ability时的窗口启动图标。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor](#oh_abilityruntime_setstartoptionsstartwindowbackgroundcolor)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, const char *startWindowBackgroundColor) | 设置启动Ability时的窗口背景颜色。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor](#oh_abilityruntime_getstartoptionsstartwindowbackgroundcolor)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, char **startWindowBackgroundColor, size_t &size) | 获取启动Ability时的窗口背景颜色。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsSupportedWindowModes](#oh_abilityruntime_setstartoptionssupportedwindowmodes)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode) *supportedWindowModes, size_t size) | 设置启动Ability时组件所支持的窗口模式。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsSupportedWindowModes](#oh_abilityruntime_getstartoptionssupportedwindowmodes)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode) **supportedWindowModes, size_t &size) | 获取启动Ability时组件所支持的窗口模式。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMinWindowWidth](#oh_abilityruntime_setstartoptionsminwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t minWindowWidth) | 设置启动Ability时的最小窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMinWindowWidth](#oh_abilityruntime_getstartoptionsminwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &minWindowWidth) | 获取启动Ability时的最小窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMaxWindowWidth](#oh_abilityruntime_setstartoptionsmaxwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t maxWindowWidth) | 设置启动Ability时的最大窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMaxWindowWidth](#oh_abilityruntime_getstartoptionsmaxwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &maxWindowWidth) | 获取启动Ability时的最大窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMinWindowHeight](#oh_abilityruntime_setstartoptionsminwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t minWindowHeight) | 设置启动Ability时的最小窗口高度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMinWindowHeight](#oh_abilityruntime_getstartoptionsminwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &minWindowHeight) | 获取启动Ability时的最小窗口高度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMaxWindowHeight](#oh_abilityruntime_setstartoptionsmaxwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t maxWindowHeig) | 设置启动Ability时的最大窗口高度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMaxWindowHeight](#oh_abilityruntime_getstartoptionsmaxwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &maxWindowHeight) | 获取启动Ability时的最大窗口高度，单位为vp。 |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions](#oh_abilityruntime_startselfuiabilitywithstartoptions)([AbilityBase_Want](_ability_base.md#abilitybase_want) *want, [AbilityRuntime_StartOptions](#abilityruntime_startoptions) *options) | 启动当前应用的UIAbility。 |

## 结构体

### AbilityRuntime_StartOptions

```
AbilityRuntime_StartOptions
```

**描述**

StartOptions数据结构。

**起始版本：** 17

## 枚举类型说明

### AbilityRuntime_ErrorCode

```
enum AbilityRuntime_ErrorCode
```

**描述**

定义元能力模块错误码。

**起始版本**：13

| 枚举值                                        | 描述           |
| --------------------------------------------- | -------------- |
| ABILITY_RUNTIME_ERROR_CODE_NO_ERROR           | 操作成功。     |
| ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID | 无效参数。     |
| ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  | 上下文不存在。 |
| ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED | 权限校验失败。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED | 设备类型不支持。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY | 指定的Ability名称不存在。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE | 接口调用Ability类型错误。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED | 众测应用到期。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE | wukong模式，不允许启动/停止ability。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_CONTROLLED | 应用被管控。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED | 应用被EDM管控。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_CROSS_APP | 限制API 11以上版本三方应用跳转。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_INTERNAL | 内部错误。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY | 非顶层应用。<br/>**起始版本：** 15 |
| ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED | 不支持设置应用启动时窗口可见性。<br/>**起始版本：** 17 |
| ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED | 应用既不支持分身也不支持多实例。<br/>**起始版本：** 17 |
| ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY | 传入的instanceKey无效。<br/>**起始版本：** 17 |
| ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED | 多实例数量已达到上限。<br/>**起始版本：** 17 |
| ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED | 应用不支持多实例。<br/>**起始版本：** 17 |
| ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED | 不支持设置instanceKey。<br/>**起始版本：** 17 |

### AbilityRuntime_AreaMode

```
enum AbilityRuntime_AreaMode
```

**描述**

定义数据加密等级。

**起始版本**：13

| 枚举值                        | 描述                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_AREA_MODE_EL1 | 对于私有文件，如闹铃、壁纸等，应用可以将这些文件放到设备级加密分区（EL1）中，以保证在用户输入密码前就可以被访问。 |
| ABILITY_RUNTIME_AREA_MODE_EL2 | 对于更敏感的文件，如个人隐私信息等，应用可以将这些文件放到更高级别的加密分区（EL2）中，以保证更高的安全性。 |
| ABILITY_RUNTIME_AREA_MODE_EL3 | 对于应用中的记录步数、文件下载、音乐播放，需要在锁屏时读写和创建新文件，放在（EL3）的加密分区比较合适。 |
| ABILITY_RUNTIME_AREA_MODE_EL4 | 对于用户安全信息相关的文件，锁屏时不需要读写文件、也不能创建文件，放在（EL4）的加密分区更合适。 |
| ABILITY_RUNTIME_AREA_MODE_EL5 | 对于用户隐私敏感数据文件，锁屏后默认不可读写，如果锁屏后需要读写文件，则锁屏前可以调用[Access](js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess)接口申请继续读写文件，或者锁屏后也需要创建新文件且可读写，放在（EL5）的应用级加密分区更合适。 |

### AbilityRuntime_StartVisibility

```
enum AbilityRuntime_StartVisibility
```

**描述**

启动Ability时的窗口和dock栏图标的显示模式。

**起始版本：** 17

| 枚举值                        | 描述                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_HIDE_UPON_START | 隐藏窗口及dock栏图标。仅在2in1设备上生效。  |
| ABILITY_RUNTIME_SHOW_UPON_START | 显示窗口及dock栏图标。仅在2in1设备上生效。 |

### AbilityRuntime_WindowMode

```
enum AbilityRuntime_WindowMode
```

**描述**

启动Ability时的窗口模式。

**起始版本：** 17

| 枚举值                        | 描述                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED | 未定义窗口模式。 |
| ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN | 全屏模式。仅在2in1设备上生效。 |

### AbilityRuntime_SupportedWindowMode

```
enum AbilityRuntime_SupportedWindowMode
```

**描述**

在应用内启动UIAbility时，指定窗口是否显示最大化/窗口化/分屏按键。如果未配置该字段，则默认采用该UIAbility对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中[abilities标签](../../quick-start/module-configuration-file.md#abilities标签)的supportWindowMode字段取值。

**起始版本：** 17

| 枚举值                        | 描述                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN | 窗口支持全屏显示。 |
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT | 窗口支持分屏显示。通常需要配合ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN或ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING一起使用，不建议只配置ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT。当仅配置ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT时，2in1设备上的窗口默认为悬浮窗模式，支持进入分屏模式。  |
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING | 支持窗口化显示。 |

## 函数说明


### OH_AbilityRuntime_ApplicationContextGetCacheDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)
```
**描述**

获取本应用的应用级的缓存目录。

**起始版本**：13

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 缓冲区，缓存目录字符串写入该区域。 |
| bufferSize | 缓冲区大小（单位：字节）。 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetAreaMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)
```

**描述**

获取本应用的应用级的数据加密等级。

**起始版本**：13

**参数：**

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

**起始版本**：13

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，应用包名字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetTempDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的临时文件目录。

**起始版本：** 16

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的通用文件目录。

**起始版本：** 16

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetDatabaseDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的数据库文件目录。

**起始版本：** 16

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetPreferencesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的首选项文件目录。

**起始版本：** 16

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetBundleCodeDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的安装文件目录。

**起始版本：** 16

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的分布式文件目录。

**起始版本：** 16

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetCloudFileDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的云文件目录。

**起始版本：** 16

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_ApplicationContextGetResourceDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetResourceDir(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**描述**

获取本应用的应用级的资源目录。

**起始版本：** 20

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| moduleName  | 模块名。                                                     |
| buffer      | 缓冲区，缓存目录字符串写入该区域。                           |
| bufferSize  | 缓冲区大小（单位：字节）。                                                 |
| writeLength | 实际写入到缓冲区的字符串长度（单位：字节）。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 查询成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - 入参buffer或者writeLength为空，或者缓冲区大小小于需要写入的大小。

ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - 当前环境的上下文不存在，如在应用创建的[子进程](c-apis-ability-childprocess.md)中应用级别上下文不存在。

### OH_AbilityRuntime_StartSelfUIAbility

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want)
```

**描述**

启动当前应用的UIAbility。

> **说明：**
>
> 当前仅支持2in1设备。

**需要权限**：ohos.permission.NDK_START_SELF_UI_ABILITY

**起始版本：** 15

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| want      | 启动当前应用UIAbility时需要的Want信息。                           |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 接口调用成功。

ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED - 权限校验失败。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - Want信息为空，或者Want信息里bundleName或abilityName为空。

ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED - 设备类型不支持。

ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY - 指定的Ability名称不存在。

ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE - 接口调用Ability类型错误。

ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED - 众测应用到期。

ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE - wukong模式，不允许启动/停止Ability。

ABILITY_RUNTIME_ERROR_CODE_CONTROLLED - 应用被管控。

ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED - 应用被EDM管控。

ABILITY_RUNTIME_ERROR_CODE_CROSS_APP - 限制API 11以上版本三方应用跳转。

ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 内部错误。

ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY - 非顶层应用。

ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED - 表示应用多实例已达到上限。

ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED - 表示不允许设置APP_INSTANCE_KEY。

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

### OH_AbilityRuntime_CreateStartOptions

```
AbilityRuntime_StartOptions* OH_AbilityRuntime_CreateStartOptions(void)
```

**描述**

创建启动当前应用的UIAbility所需要的StartOptions结构体。

**起始版本：** 17

**返回：**

AbilityRuntime_StartOptions - StartOptions数据结构。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void createStartOptionsTest()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_DestroyStartOptions

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_DestroyStartOptions(AbilityRuntime_StartOptions **startOptions)
```

**描述**

销毁StartOptions结构体。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | 需要销毁的StartOptions结构体。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 销毁成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void destroyStartOptionsTest()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_WindowMode windowMode);
```

**描述**

设置启动Ability时的窗口模式。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowMode     | 需要设置的窗口模式。取值范围参见[AbilityRuntime_WindowMode](_ability_runtime.md#abilityruntime_windowmode)。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空或者WindowMode无效。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowMode(options,
        ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_WindowMode &windowMode);
```

**描述**

获取启动Ability时的窗口模式。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowMode     | 获取到的窗口模式。取值范围参见[AbilityRuntime_WindowMode](_ability_runtime.md#abilityruntime_windowmode)。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_WindowMode windowMode = ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowMode(options, windowMode);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsDisplayId

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions, int32_t displayId);
```

**描述**

设置启动Ability时窗口所在的屏幕ID。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| displayId     | 启动Ability时窗口所在的屏幕ID。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsDisplayId(options, 1);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsDisplayId

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions, int32_t &displayId);
```

**描述**

获取启动Ability时窗口所在的屏幕ID。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| displayId     | 获取到的屏幕ID。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t displayId = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsDisplayId(options, displayId);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWithAnimation

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions, bool withAnimation);
```

**描述**

设置启动Ability时是否具有动画效果。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| withAnimation     | 启动Ability时是否具有动画效果。<br>**说明**：<br>true表示启动Ability时具有动画效果；<br>false表示启动Ability时不具有动画效果。</br>          |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWithAnimation(options, true);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWithAnimation

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions, bool &withAnimation);
```

**描述**

获取启动Ability时是否具有动画效果。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| withAnimation     | 启动Ability时是否具有动画效果。<br>**说明**：<br>true表示启动Ability时具有动画效果；<br>false表示启动Ability时不具有动画效果。</br>                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    bool withAnimation = false;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWithAnimation(options, withAnimation);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowLeft

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions, int32_t windowLeft);
```

**描述**

设置启动Ability时的窗口左侧位置，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowLeft     | 需要设置的窗口左侧位置，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowLeft(options, 200);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowLeft

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions, int32_t &windowLeft);
```

**描述**

获取启动Ability时的窗口左侧位置，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowLeft     | 获取到的窗口左侧位置，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t windowLeft = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowLeft(options, windowLeft);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowTop

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions, int32_t windowTop);
```

**描述**

设置启动Ability时的窗口顶部位置，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowTop     | 需要设置的窗口顶部位置，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowTop(options, 500);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowTop

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions, int32_t &windowTop);
```

**描述**

获取启动Ability时的窗口顶部位置，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowTop     | 获取到的窗口顶部位置，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t windowTop = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowTop(options, windowTop);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t windowHeight);
```

**描述**

设置启动Ability时的窗口高度，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowHeight     | 需要设置的窗口高度，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowHeight(options, 500);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t &windowHeight);
```

**描述**

获取启动Ability时的窗口高度，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowHeight     | 获取到的窗口高度，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t windowHeight = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowHeight(options, windowHeight);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t windowWidth);
```

**描述**

设置启动Ability时的窗口宽度，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowWidth     | 需要设置的窗口宽度，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowWidth(options, 500);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t &windowWidth);
```

**描述**

获取启动Ability时的窗口宽度，单位为px。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| windowWidth     | 获取到的窗口宽度，单位为px。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t windowWidth = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowWidth(options, windowWidth);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsStartWindowIcon

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions, OH_PixelmapNative *startWindowIcon)
```

**描述**

设置启动Ability时的窗口启动图标。图片数据大小限制为600M。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| startWindowIcon     | 需要设置的窗口启动图标。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions或者OH_PixelmapNative信息为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    uint8_t data[96];
    size_t dataSize = 96;
    for (int i = 0; i < dataSize; i++) {
        data[i] = i + 1;
    }

    //创建参数结构体实例，并设置参数
    OH_Pixelmap_InitializationOptions *createOpts = nullptr;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, 6);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, 4);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);

    //创建Pixelmap实例
    OH_PixelmapNative *startWindowIcon = nullptr;
    Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &startWindowIcon);
    if (errCode != IMAGE_SUCCESS) {
        // 记录错误日志以及其他业务处理

        // 销毁createOpts，防止内存泄漏
        OH_PixelmapInitializationOptions_Release(createOpts);
        return;
    }

    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理

        // 销毁createOpts，防止内存泄漏
        OH_PixelmapInitializationOptions_Release(createOpts);

        // 销毁startWindowIcon，防止内存泄漏
        OH_PixelmapNative_Release(startWindowIcon);
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsStartWindowIcon(options, startWindowIcon);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁createOpts，防止内存泄漏
    OH_PixelmapInitializationOptions_Release(createOpts);

    // 销毁startWindowIcon，防止内存泄漏
    OH_PixelmapNative_Release(startWindowIcon);

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsStartVisibility

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_StartVisibility startVisibility);
```

**描述**

设置启动Ability时窗口和dock栏图标的显示模式。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| startVisibility     | 需要设置的显示模式。取值范围参见[AbilityRuntime_StartVisibility](#abilityruntime_startvisibility)。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空，或startVisibility取值不在枚举类AbilityRuntime_StartVisibility中。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_StartVisibility visibility = AbilityRuntime_StartVisibility::ABILITY_RUNTIME_SHOW_UPON_START;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsStartVisibility(options, visibility);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsStartVisibility

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_StartVisibility &startVisibility);
```

**描述**

获取启动Ability时窗口和dock栏图标的显示模式。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| startVisibility     | 获取到的显示模式。取值范围参见[AbilityRuntime_StartVisibility](#abilityruntime_startvisibility)。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空，或startVisibility未被设置。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_StartVisibility visibility;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsStartVisibility(options, visibility);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }
    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsStartWindowIcon

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,
    OH_PixelmapNative **startWindowIcon)
```

**描述**

获取启动Ability时的窗口启动图标。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| startWindowIcon     | 获取到的窗口启动图标。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空，或者OH_PixelmapNative没有置为空指针。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    OH_PixelmapNative *startWindowIcon = nullptr;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsStartWindowIcon(options, &startWindowIcon);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁startWindowIcon，防止内存泄漏
    OH_PixelmapNative_Release(startWindowIcon);

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, const char *startWindowBackgroundColor)
```

**描述**

设置启动Ability时的窗口背景颜色。启动UIAbility时，启动页所显示的背景颜色。如果未设置该字段，则默认采用[module.json5配置文件](../../quick-start/module-configuration-file.md)中[abilities标签](../../quick-start/module-configuration-file.md#abilities标签)的startWindowBackground字段的配置。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| startWindowBackgroundColor     | 需要设置的窗口背景颜色。固定为ARGB格式, 如：`#E5FFFFFF`。|

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions或者StartWindowBackgroundColor为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor(options, "#00000000");
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, char **startWindowBackgroundColor, size_t &size)
```

**描述**

获取启动Ability时的窗口背景颜色。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| startWindowBackgroundColor     | 获取到的窗口背景颜色。固定为ARGB格式, 如：`#E5FFFFFF`。|
| size     | 获取到的窗口背景颜色的大小。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空，或者StartWindowBackgroundColor没有置为空指针。

ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 开发者无法恢复的内部错误，比如内部调用malloc错误，或者字符串拷贝函数出错。

**示例代码：**
```cpp
#include <cstdlib>

#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    char *startWindowBackgroundColor = nullptr;
    size_t size = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor(options,
        &startWindowBackgroundColor, size);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    if (startWindowBackgroundColor != nullptr) {
        // 销毁startWindowBackgroundColor，防止内存泄漏
        free(startWindowBackgroundColor);
        startWindowBackgroundColor = nullptr;
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsSupportedWindowModes

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_SupportedWindowMode *supportedWindowModes, size_t size)
```

**描述**

设置启动Ability时组件所支持的窗口模式。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| supportedWindowModes     | 需要设置的组件所支持的窗口模式。取值范围参见[AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode)。                           |
| size     | 组件所支持的窗口模式的大小。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions或者SupportedWindowModes为空，或者Size为0。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    size_t supportedWindowModesSize = 3;
    AbilityRuntime_SupportedWindowMode supportedWindowModes[3] = {
        ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN,
        ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT,
        ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING,
    };
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsSupportedWindowModes(options,
        supportedWindowModes, supportedWindowModesSize);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsSupportedWindowModes

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_SupportedWindowMode **supportedWindowModes, size_t &size)
```

**描述**

获取启动Ability时组件所支持的窗口模式。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| supportedWindowModes     | 获取到的组件所支持的窗口模式。取值范围参见[AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode)。                           |
| size     | 获取到的组件所支持的窗口模式的大小。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空，或者SupportWindowMode没有置为空指针。

ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 开发者无法恢复的内部错误，比如内部调用malloc错误。

**示例代码：**
```cpp
#include <cstdlib>

#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_SupportedWindowMode *supportedWindowModes = nullptr;
    size_t size = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsSupportedWindowModes(options,
        &supportedWindowModes, size);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    if (supportedWindowModes != nullptr) {
        // 销毁supportedWindowModes，防止内存泄漏
        free(supportedWindowModes);
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMinWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t minWindowWidth)
```

**描述**

设置启动Ability时的最小窗口宽度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| minWindowWidth     | 需要设置的最小窗口宽度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMinWindowWidth(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMinWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t &minWindowWidth)
```

**描述**

获取启动Ability时的最小窗口宽度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| minWindowWidth     | 获取到的最小窗口宽度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t minWindowWidth = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMinWindowWidth(options, minWindowWidth);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMaxWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t maxWindowWidth)
```

**描述**

设置启动Ability时的最大窗口宽度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| maxWindowWidth     | 需要设置的最大窗口宽度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMaxWindowWidth(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMaxWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t &maxWindowWidth)
```

**描述**

获取启动Ability时的最大窗口宽度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| maxWindowWidth     | 获取到的最大窗口宽度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t maxWindowWidth = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMaxWindowWidth(options, maxWindowWidth);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMinWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t minWindowHeight)
```

**描述**

设置启动Ability时的最小窗口高度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| minWindowHeight     | 需要设置的最小窗口高度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMinWindowHeight(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMinWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t &minWindowHeight)
```

**描述**

获取启动Ability时的最小窗口高度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| minWindowHeight     | 获取到的最小窗口高度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t minWindowHeight = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMinWindowHeight(options, minWindowHeight);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMaxWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t maxWindowHeight)
```

**描述**

设置启动Ability时的最大窗口高度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| maxWindowHeight     | 需要设置的最大窗口高度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 设置成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMaxWindowHeight(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMaxWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t &maxWindowHeight)
```

**描述**

获取启动Ability时的最大窗口高度，单位为vp。

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| startOptions     | StartOptions结构体。                           |
| maxWindowHeight     | 获取到的最大窗口高度，单位为vp。                           |

**起始版本：** 17

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 获取成功。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - StartOptions为空。

**示例代码：**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // 记录错误日志以及其他业务处理
        return;
    }

    int32_t maxWindowHeight = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMaxWindowHeight(options, maxWindowHeight);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // 记录错误日志以及其他业务处理
    }

    // 销毁options，防止内存泄漏
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(AbilityBase_Want *want, AbilityRuntime_StartOptions *options)
```

**描述**

启动当前应用的UIAbility。

> **说明：**
>
> 当前仅支持2in1设备。

**需要权限**：ohos.permission.NDK_START_SELF_UI_ABILITY

**起始版本：** 17

**参数：**

| 名称        | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| want      | 启动当前应用UIAbility时需要的Want信息。                           |
| options      | 启动当前应用UIAbility时需要的StartOptions信息。<br>**说明：**<br>如果该参数中[startVisibility](#abilityruntime_startvisibility)属性的值不为空，必须确保当前应用已添加到状态栏，否则会返回ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED错误码。 |

**返回：**

ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - 成功。

ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED - 权限校验失败。

ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - Want或者StartOptions为空，或者Want信息里bundleName或abilityName为空。

ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED - 设备类型不支持。

ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY - 指定的Ability名称不存在。

ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE - 接口调用Ability类型错误。

ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED - 众测应用到期。

ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE - wukong模式，不允许启动/停止Ability。

ABILITY_RUNTIME_ERROR_CODE_CONTROLLED - 应用被管控。

ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED - 应用被EDM管控。

ABILITY_RUNTIME_ERROR_CODE_CROSS_APP - 禁止拉起其他应用。

ABILITY_RUNTIME_ERROR_CODE_INTERNAL - 内部错误。

ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY - 当前应用不是前台进程。

ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED - 禁止设置应用启动可见性。

ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED - 应用不支持分身和多实例。

ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY - 传入的instanceKey无效。

ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED - 多实例已达到上限。

ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED - 应用不支持多实例。

ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED - APP_INSTANCE_KEY不能被赋值。

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
