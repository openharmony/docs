# start_options.h


## 概述

声明StartOptions结构体以及结构体相关函数。

**引用文件**：<AbilityKit/ability_runtime/start_options.h>

**库**：libability_runtime.so

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**起始版本**：17

**相关模块**：[AbilityRuntime](_ability_runtime.md)

## 汇总

### 文件

| 名称                                                | 描述                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ |
| [start_options.h](start__options_8h.md) | 声明StartOptions结构体。<br/>**引用文件**：<AbilityKit/ability_runtime/start_options.h><br/>**库**：libability_runtime.so |

### 结构体

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions)  | StartOptions数据结构。 |

### 函数

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityRuntime_StartOptions*](_ability_runtime.md#abilityruntime_startoptions) [OH_AbilityRuntime_CreateStartOptions](_ability_runtime.md#oh_abilityruntime_createstartoptions)(void) | 创建启动当前应用的UIAbility所需要的StartOptions结构体。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_DestroyStartOptions](_ability_runtime.md#oh_abilityruntime_destroystartoptions)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) **startOptions) | 销毁StartOptions结构体。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowMode](_ability_runtime.md#oh_abilityruntime_setstartoptionswindowmode)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_WindowMode](_ability_runtime.md#abilityruntime_windowmode) windowMode) | 设置启动Ability时的窗口模式。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowMode](_ability_runtime.md#oh_abilityruntime_getstartoptionswindowmode)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_WindowMode](_ability_runtime.md#abilityruntime_windowmode) &windowMode) | 获取启动Ability时的窗口模式。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsDisplayId](_ability_runtime.md#oh_abilityruntime_setstartoptionsdisplayid)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t displayId) | 设置启动Ability时窗口所在的屏幕ID。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsDisplayId](_ability_runtime.md#oh_abilityruntime_getstartoptionsdisplayid)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &displayId) | 获取启动Ability时窗口所在的屏幕ID。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWithAnimation](_ability_runtime.md#oh_abilityruntime_setstartoptionswithanimation)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, bool withAnimation) | 设置启动Ability时是否具有动画效果。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWithAnimation](_ability_runtime.md#oh_abilityruntime_getstartoptionswithanimation)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, bool &withAnimation) | 获取启动Ability时是否具有动画效果。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowLeft](_ability_runtime.md#oh_abilityruntime_setstartoptionswindowleft)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t windowLeft) | 设置启动Ability时的窗口左侧位置，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowLeft](_ability_runtime.md#oh_abilityruntime_getstartoptionswindowleft)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &windowLeft) | 获取启动Ability时的窗口左侧位置，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowTop](_ability_runtime.md#oh_abilityruntime_setstartoptionswindowtop)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t windowTop) | 设置启动Ability时的窗口顶部位置，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowTop](_ability_runtime.md#oh_abilityruntime_getstartoptionswindowtop)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &windowTop) | 获取启动Ability时的窗口顶部位置，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowHeight](_ability_runtime.md#oh_abilityruntime_setstartoptionswindowheight)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t windowHeight) | 设置启动Ability时的窗口高度，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowHeight](_ability_runtime.md#oh_abilityruntime_getstartoptionswindowheight)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &windowHeight) | 获取启动Ability时的窗口高度，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowWidth](_ability_runtime.md#oh_abilityruntime_setstartoptionswindowwidth)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t windowWidth) | 设置启动Ability时的窗口宽度，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowWidth](_ability_runtime.md#oh_abilityruntime_getstartoptionswindowwidth)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &windowWidth) | 获取启动Ability时的窗口宽度，单位为px。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartVisibility](_ability_runtime.md#oh_abilityruntime_setstartoptionsstartvisibility)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](_ability_runtime.md#abilityruntime_startvisibility) startVisibility) | 设置启动Ability时窗口和dock栏图标的显示模式。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartVisibility](_ability_runtime.md#oh_abilityruntime_getstartoptionsstartvisibility)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](_ability_runtime.md#abilityruntime_startvisibility) &startVisibility) | 获得启动Ability时窗口和dock栏图标的显示模式。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartWindowIcon](_ability_runtime.md#oh_abilityruntime_setstartoptionsstartwindowicon)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [OH_PixelmapNative](../apis-image-kit/capi-oh-pixelmapnative.md) *startWindowIcon) | 设置启动Ability时的窗口启动图标。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartWindowIcon](_ability_runtime.md#oh_abilityruntime_getstartoptionsstartwindowicon)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [OH_PixelmapNative](../apis-image-kit/capi-oh-pixelmapnative.md) **startWindowIcon) | 获取启动Ability时的窗口启动图标。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor](_ability_runtime.md#oh_abilityruntime_setstartoptionsstartwindowbackgroundcolor)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, const char *startWindowBackgroundColor) | 设置启动Ability时的窗口背景颜色。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor](_ability_runtime.md#oh_abilityruntime_getstartoptionsstartwindowbackgroundcolor)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, char **startWindowBackgroundColor, size_t &size) | 获取启动Ability时的窗口背景颜色。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsSupportedWindowModes](_ability_runtime.md#oh_abilityruntime_setstartoptionssupportedwindowmodes)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_SupportedWindowMode](_ability_runtime.md#abilityruntime_supportedwindowmode) *supportedWindowModes, size_t size) | 设置启动Ability时组件所支持的窗口模式。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsSupportedWindowModes](_ability_runtime.md#oh_abilityruntime_getstartoptionssupportedwindowmodes)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_SupportedWindowMode](_ability_runtime.md#abilityruntime_supportedwindowmode) **supportedWindowModes, size_t &size) | 获取启动Ability时组件所支持的窗口模式。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMinWindowWidth](_ability_runtime.md#oh_abilityruntime_setstartoptionsminwindowwidth)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t minWindowWidth) | 设置启动Ability时的最小窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMinWindowWidth](_ability_runtime.md#oh_abilityruntime_getstartoptionsminwindowwidth)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &minWindowWidth) | 获取启动Ability时的最小窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMaxWindowWidth](_ability_runtime.md#oh_abilityruntime_setstartoptionsmaxwindowwidth)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t maxWindowWidth) | 设置启动Ability时的最大窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMaxWindowWidth](_ability_runtime.md#oh_abilityruntime_getstartoptionsmaxwindowwidth)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &maxWindowWidth) | 获取启动Ability时的最大窗口宽度，单位为vp。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMinWindowHeight](_ability_runtime.md#oh_abilityruntime_setstartoptionsminwindowheight)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t minWindowHeight) | 设置启动Ability时的最小窗口高度，单位为vp。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMinWindowHeight](_ability_runtime.md#oh_abilityruntime_getstartoptionsminwindowheight)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &minWindowHeight) | 获取启动Ability时的最小窗口高度，单位为vp。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMaxWindowHeight](_ability_runtime.md#oh_abilityruntime_setstartoptionsmaxwindowheight)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t maxWindowHeig) | 设置启动Ability时的最大窗口高度，单位为vp。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMaxWindowHeight](_ability_runtime.md#oh_abilityruntime_getstartoptionsmaxwindowheight)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, int32_t &maxWindowHeight) | 获取启动Ability时的最大窗口高度，单位为vp。 |
