# AbilityRuntime


## Overview

The module provides capabilities related to the ability framework.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [ability_runtime_common.h](ability__runtime__common_8h.md) | Declares the error codes of the ability framework.<br>**File to include**: <AbilityKit/ability_runtime/ability_runtime_common.h><br>**Library**: libability_runtime.so|
| [application_context.h](application__context_8h.md) | Declares the context capability at the application level.<br>**File to include**: <AbilityKit/ability_runtime/application_context.h><br>**Library**: libability_runtime.so|
| [context_constant.h](context__constant_8h.md) | Declares the context-related enums.<br>**File to include**: <AbilityKit/ability_runtime/context_constant.h><br>**Library**: libability_runtime.so|
| [start_options.h](start__options_8h.md) | Declares the StartOptions struct and related functions.<br>**File to include**: <AbilityKit/ability_runtime/start_options.h><br>**Library**: libability_runtime.so|

### Enums

| Name                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED = 201,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED = 801,<br>    ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY = 16000001,<br>    ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE = 16000002,<br>    ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED = 16000008,<br>    ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE = 16000009,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTROLLED = 16000012,<br>    ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED = 16000013,<br>    ABILITY_RUNTIME_ERROR_CODE_CROSS_APP = 16000018,<br>    ABILITY_RUNTIME_ERROR_CODE_INTERNAL = 16000050,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY = 16000053,<br>    ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED = 16000067,<br>    ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED = 16000072,<br>    ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY = 16000076,<br>    ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED = 16000077,<br>    ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED = 16000078,<br>    ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED = 16000079<br>} | Enumerates the error codes used by the ability framework.|
| [AbilityRuntime_AreaMode](#abilityruntime_areamode) {<br>    ABILITY_RUNTIME_AREA_MODE_EL1 = 0,<br>    ABILITY_RUNTIME_AREA_MODE_EL2 = 1,<br>    ABILITY_RUNTIME_AREA_MODE_EL3 = 2,<br>    ABILITY_RUNTIME_AREA_MODE_EL4 = 3,<br>    ABILITY_RUNTIME_AREA_MODE_EL5 = 4<br>} | Enumerates the data encryption levels.    |
| [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility) {<br>    ABILITY_RUNTIME_HIDE_UPON_START = 0,<br>    ABILITY_RUNTIME_SHOW_UPON_START = 1<br>} | Enumerates the visibility modes of the window and dock bar icons when the ability is started.    |
| [AbilityRuntime_WindowMode](#abilityruntime_windowmode) {<br>    ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED = 0,<br>    ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN = 1<br>} | Enumerates the window modes in which an ability can be displayed at startup.    |
| [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode) {<br>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN = 0,<br>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT = 1,<br>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING = 2<br>} | Enumerates the window modes supported by an ability when it is started.    |

### Functions

| Name| Description|
| -------- | -------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCacheDir](#oh_abilityruntime_applicationcontextgetcachedir)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the application-level cache directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetAreaMode](#oh_abilityruntime_applicationcontextgetareamode)([AbilityRuntime_AreaMode](#abilityruntime_areamode)* areaMode) | Obtains the application-level data encryption level of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleName](#oh_abilityruntime_applicationcontextgetbundlename)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the bundle name of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetTempDir](#oh_abilityruntime_applicationcontextgettempdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level temporary file directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetFilesDir](#oh_abilityruntime_applicationcontextgetfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level common file directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDatabaseDir](#oh_abilityruntime_applicationcontextgetdatabasedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level database file directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetPreferencesDir](#oh_abilityruntime_applicationcontextgetpreferencesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level preferences file directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleCodeDir](#oh_abilityruntime_applicationcontextgetbundlecodedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level installation file directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir](#oh_abilityruntime_applicationcontextgetdistributedfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level distributed file directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCloudFileDir](#oh_abilityruntime_applicationcontextgetcloudfiledir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level cloud file directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetResourceDir](#oh_abilityruntime_applicationcontextgetresourcedir)(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level resource directory of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_StartSelfUIAbility](#oh_abilityruntime_startselfuiability)([AbilityBase_Want](_ability_base.md#abilitybase_want) *want) | Starts the UIAbility of the current application.|
| [AbilityRuntime_StartOptions*](#abilityruntime_startoptions) [OH_AbilityRuntime_CreateStartOptions](#oh_abilityruntime_createstartoptions)(void) | Creates the StartOptions struct required for starting the UIAbility of the current application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_DestroyStartOptions](#oh_abilityruntime_destroystartoptions)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) **startOptions) | Destroys a StartOptions struct.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowMode](#oh_abilityruntime_setstartoptionswindowmode)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_WindowMode](#abilityruntime_windowmode) windowMode) | Sets the window mode for starting an ability.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowMode](#oh_abilityruntime_getstartoptionswindowmode)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_WindowMode](#abilityruntime_windowmode) &windowMode) | Obtains the window mode for starting an ability.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsDisplayId](#oh_abilityruntime_setstartoptionsdisplayid)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t displayId) | Sets the ID of the display where the window is launched when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsDisplayId](#oh_abilityruntime_getstartoptionsdisplayid)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &displayId) | Obtains the ID of the display where the window is launched when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWithAnimation](#oh_abilityruntime_setstartoptionswithanimation)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, bool withAnimation) | Sets whether to use animation effects when an ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWithAnimation](#oh_abilityruntime_getstartoptionswithanimation)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, bool &withAnimation) | Checks whether animation effects are used when an ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowLeft](#oh_abilityruntime_setstartoptionswindowleft)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowLeft) | Sets the left position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowLeft](#oh_abilityruntime_getstartoptionswindowleft)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowLeft) | Obtains the left position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowTop](#oh_abilityruntime_setstartoptionswindowtop)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowTop) | Sets the top position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowTop](#oh_abilityruntime_getstartoptionswindowtop)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowTop) | Obtains the top position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowHeight](#oh_abilityruntime_setstartoptionswindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowHeight) | Sets the height of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowHeight](#oh_abilityruntime_getstartoptionswindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowHeight) | Obtains the height of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsWindowWidth](#oh_abilityruntime_setstartoptionswindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t windowWidth) | Sets the width of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsWindowWidth](#oh_abilityruntime_getstartoptionswindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &windowWidth) | Obtains the width of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartVisibility](#oh_abilityruntime_setstartoptionsstartvisibility)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility) startVisibility) | Sets the visibility of the window and dock bar icons when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartVisibility](#oh_abilityruntime_getstartoptionsstartvisibility)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility) &startVisibility) | Obtains the visibility of the window and dock bar icons when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartWindowIcon](#oh_abilityruntime_setstartoptionsstartwindowicon)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [OH_PixelmapNative](../apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md) *startWindowIcon) | Sets the startup icon of the window when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartWindowIcon](#oh_abilityruntime_getstartoptionsstartwindowicon)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [OH_PixelmapNative](../apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md) **startWindowIcon) | Obtains the startup icon of the window when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor](#oh_abilityruntime_setstartoptionsstartwindowbackgroundcolor)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, const char *startWindowBackgroundColor) | Sets the background color of the window when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor](#oh_abilityruntime_getstartoptionsstartwindowbackgroundcolor)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, char **startWindowBackgroundColor, size_t &size) | Obtains the background color of the window when the ability is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsSupportedWindowModes](#oh_abilityruntime_setstartoptionssupportedwindowmodes)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode) *supportedWindowModes, size_t size) | Sets the window modes supported by the ability when it is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsSupportedWindowModes](#oh_abilityruntime_getstartoptionssupportedwindowmodes)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode) **supportedWindowModes, size_t &size) | Obtains the window modes supported by the ability when it is started.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMinWindowWidth](#oh_abilityruntime_setstartoptionsminwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t minWindowWidth) | Sets the minimum window width for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMinWindowWidth](#oh_abilityruntime_getstartoptionsminwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &minWindowWidth) | Obtains the minimum window width for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMaxWindowWidth](#oh_abilityruntime_setstartoptionsmaxwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t maxWindowWidth) | Sets the maximum window width for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMaxWindowWidth](#oh_abilityruntime_getstartoptionsmaxwindowwidth)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &maxWindowWidth) | Obtains the maximum window width for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMinWindowHeight](#oh_abilityruntime_setstartoptionsminwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t minWindowHeight) | Sets the minimum window height for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMinWindowHeight](#oh_abilityruntime_getstartoptionsminwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &minWindowHeight) | Obtains the minimum window height for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsMaxWindowHeight](#oh_abilityruntime_setstartoptionsmaxwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t maxWindowHeig) | Sets the maximum window height for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsMaxWindowHeight](#oh_abilityruntime_getstartoptionsmaxwindowheight)([AbilityRuntime_StartOptions](#abilityruntime_startoptions) *startOptions, int32_t &maxWindowHeight) | Obtains the maximum window height for starting the ability, in vp.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions](#oh_abilityruntime_startselfuiabilitywithstartoptions)([AbilityBase_Want](_ability_base.md#abilitybase_want) *want, [AbilityRuntime_StartOptions](#abilityruntime_startoptions) *options) | Starts the UIAbility of the current application.|

## Structs

### AbilityRuntime_StartOptions

```
AbilityRuntime_StartOptions
```

**Description**

StartOptions struct.

**Since**: 17

## Enum Description

### AbilityRuntime_ErrorCode

```
enum AbilityRuntime_ErrorCode
```

**Description**

Enumerates the error codes used by the ability framework.

**Since**: 13

| Value                                       | Description          |
| --------------------------------------------- | -------------- |
| ABILITY_RUNTIME_ERROR_CODE_NO_ERROR           | Operation successful.    |
| ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID | Invalid parameter.    |
| ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  | The context does not exist.|
| ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED | Permission verification failed.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED | The device type is not supported.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY | The specified ability name does not exist.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE | The ability type is incorrect.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED | The crowdtesting application expires.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE | An ability cannot be started or stopped in Wukong mode.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CONTROLLED | The application is under control.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED | The application is under control by EDM.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CROSS_APP | Redirection to third-party applications is not allowed in API versions later than 11.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_INTERNAL | Internal error.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY | The application is not on top.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED | The window visibility cannot be set when the application is started.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED | The application does not support clone or multi-instance mode.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY | The instance key is invalid.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED | The number of instances has reached the upper limit.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED | The application does not support multi-instance mode.<br>**Since**: 17|
| ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED | Setting **instanceKey** is not supported.<br>**Since**: 17|

### AbilityRuntime_AreaMode

```
enum AbilityRuntime_AreaMode
```

**Description**

Enumerates the data encryption levels.

**Since**: 13

| Value                       | Description                                                        |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_AREA_MODE_EL1 | For private files, such as alarms and wallpapers, the application can place them in a directory with the device-level encryption (EL1) to ensure that they can be accessed before the user enters the password.|
| ABILITY_RUNTIME_AREA_MODE_EL2 | For sensitive files, such as personal privacy data, the application can place them in a directory with the user-level encryption (EL2).|
| ABILITY_RUNTIME_AREA_MODE_EL3 | For step recording, file download, or music playback that needs to read, write, and create files when the screen is locked, the application can place these files in EL3.|
| ABILITY_RUNTIME_AREA_MODE_EL4 | For files that are related to user security information and do not need to be read, written, or created when the screen is locked, the application can place them in EL4.|
| ABILITY_RUNTIME_AREA_MODE_EL5 | By default, sensitive user privacy files cannot be read or written on the lock screen. If such files need to be read or written on the lock screen, you can call [Access](js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess) to apply for reading or writing files before the screen is locked or create new files that can be read and written after the screen is locked. It is more appropriate to place these files in EL5.|

### AbilityRuntime_StartVisibility

```
enum AbilityRuntime_StartVisibility
```

**Description**

Enumerates the visibility modes of the window and dock bar icons when the ability is started.

**Since**: 17

| Value                       | Description                                                        |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_HIDE_UPON_START | Hides the window and dock bar icons. This mode takes effect only on 2-in-1 devices. |
| ABILITY_RUNTIME_SHOW_UPON_START | Displays the window and dock bar icons. This mode takes effect only on 2-in-1 devices.|

### AbilityRuntime_WindowMode

```
enum AbilityRuntime_WindowMode
```

**Description**

Enumerates the window modes in which an ability can be displayed at startup.

**Since**: 17

| Value                       | Description                                                        |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED | Undefined window mode.|
| ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN | Full-screen mode. This mode takes effect only on 2-in-1 devices.|

### AbilityRuntime_SupportedWindowMode

```
enum AbilityRuntime_SupportedWindowMode
```

**Description**

Enumerates the window modes supported by an ability when it is started. The supported window mode specifies whether to display the maximize, minimize, or split-screen button when the UIAbility is launched in an application. If this enum is not set, the value of **supportWindowMode** configured under [abilities](../../quick-start/module-configuration-file.md#abilities) in the [module.json5](../../quick-start/module-configuration-file.md) file corresponding to the UIAbility is used by default.

**Since**: 17

| Value                       | Description                                                        |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN | A window in full-screen mode is supported.|
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT | A window in split-screen mode is supported. Generally, **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN** or **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING** must be used together. You are not advised to configure only **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT**. If only **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT** is configured, the window on 2-in-1 devices is in floating window mode by default and can transition to the split-screen mode. |
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING | A floating window is supported.|

## Function Description


### OH_AbilityRuntime_ApplicationContextGetCacheDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)
```
**Description**

Obtains the application-level cache directory of the application.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to the buffer. The cache directory string is written to this area.|
| bufferSize | Buffer siz, in bytes.|
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetAreaMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)
```

**Description**

Obtains the application-level data encryption level of the application.

**Since**: 13

**Parameters**

| Name    | Description                    |
| -------- | ------------------------ |
| areaMode | Pointer to the data encryption level.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **areaMode** is null.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetBundleName

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the bundle name of the application.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The bundle name string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetTempDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level temporary file directory of the application.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level common file directory of the application.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetDatabaseDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level database file directory of the application.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetPreferencesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level preferences file directory of the application.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetBundleCodeDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level installation file directory of the application.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level distributed file directory of the application.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetCloudFileDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level cloud file directory of the application.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetResourceDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetResourceDir(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level resource directory of the application.

**Since**: 20

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| moduleName  | Pointer to the module name.                                                    |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer siz, in bytes.                                                |
| writeLength | Pointer to the length of the string actually written to the buffer, in bytes.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.

**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_StartSelfUIAbility

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want)
```

**Description**

Starts the UIAbility of the current application.

> **NOTE**
>
> This function is valid only for 2-in-1 devices.

**Required permissions**: ohos.permission.NDK_START_SELF_UI_ABILITY

**Since**: 15

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| want      | Pointer to the Want information required for starting the UIAbility.                          |

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The API call is successful.

**ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED**: Permission verification fails.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The Want information is null, or if the bundleName or abilityName in the Want information is null.

**ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED**: The device type is not supported.

**ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY**: The specified ability name does not exist.

**ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE**: The ability type is incorrect.

**ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED**: The crowdtesting application expires.

**ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE**: The ability is started or stopped in Wukong mode.

**ABILITY_RUNTIME_ERROR_CODE_CONTROLLED**: The application is under control.

**ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED**: The application is under control by EDM.

**ABILITY_RUNTIME_ERROR_CODE_CROSS_APP**: Redirecting to third-party applications is not allowed in API versions later than 11.

**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error occurs.

**ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY**: The application is not a top one.

**ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED**: The number of instances has reached the upper limit.

**ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED**: **APP_INSTANCE_KEY** cannot be set.

**Example**
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
        // Record error logs and other service processing.
        return;
    }
    // Destroy the Want to prevent memory leakage.
    OH_AbilityBase_DestroyWant(want);
}
```

### OH_AbilityRuntime_CreateStartOptions

```
AbilityRuntime_StartOptions* OH_AbilityRuntime_CreateStartOptions(void)
```

**Description**

Creates the StartOptions struct required for starting the UIAbility of the current application.

**Since**: 17

**Returns**

Pointer to **AbilityRuntime_StartOptions**, which is the StartOptions struct.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void createStartOptionsTest()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_DestroyStartOptions

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_DestroyStartOptions(AbilityRuntime_StartOptions **startOptions)
```

**Description**

Destroys a StartOptions struct.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Double pointer to the StartOptions struct.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The struct is destroyed successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void destroyStartOptionsTest()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_WindowMode windowMode);
```

**Description**

Sets the window mode for starting an ability.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowMode     | Window mode. For details about the available options, see [AbilityRuntime_WindowMode](_ability_runtime.md#abilityruntime_windowmode).                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null or **WindowMode** is invalid.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowMode(options,
        ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_WindowMode &windowMode);
```

**Description**

Obtains the window mode for starting an ability.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowMode     | Window mode. For details about the available options, see [AbilityRuntime_WindowMode](_ability_runtime.md#abilityruntime_windowmode).                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_WindowMode windowMode = ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowMode(options, windowMode);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsDisplayId

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions, int32_t displayId);
```

**Description**

Sets the ID of the display where the window is launched when the ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| displayId     | Display ID.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsDisplayId(options, 1);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsDisplayId

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions, int32_t &displayId);
```

**Description**

Obtains the ID of the display where the window is launched when the ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| displayId     | Display ID.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t displayId = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsDisplayId(options, displayId);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWithAnimation

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions, bool withAnimation);
```

**Description**

Sets whether to use animation effects when an ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| withAnimation     | Whether to use animation effects.<br>**NOTE**<br>The value **true** means that the ability has an animation effect when being started.<br>The value **false** means that the ability does not have an animation effect when being started.<br>         |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWithAnimation(options, true);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWithAnimation

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions, bool &withAnimation);
```

**Description**

Checks whether animation effects are used when an ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| withAnimation     | Whether animation effects are used.<br>**NOTE**<br>The value **true** means that the ability has an animation effect when being started.<br>The value **false** means that the ability does not have an animation effect when being started.<br>                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    bool withAnimation = false;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWithAnimation(options, withAnimation);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowLeft

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions, int32_t windowLeft);
```

**Description**

Sets the left position of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowLeft     | Left position of the window, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowLeft(options, 200);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowLeft

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions, int32_t &windowLeft);
```

**Description**

Obtains the left position of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowLeft     | Left position of the window, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t windowLeft = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowLeft(options, windowLeft);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowTop

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions, int32_t windowTop);
```

**Description**

Sets the top position of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowTop     | Top position of the window, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowTop(options, 500);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowTop

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions, int32_t &windowTop);
```

**Description**

Obtains the top position of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowTop     | Top position of the window, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t windowTop = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowTop(options, windowTop);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t windowHeight);
```

**Description**

Sets the height of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowHeight     | Window height, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowHeight(options, 500);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t &windowHeight);
```

**Description**

Obtains the height of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowHeight     | Window height, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t windowHeight = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowHeight(options, windowHeight);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t windowWidth);
```

**Description**

Sets the width of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowWidth     | Window width, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsWindowWidth(options, 500);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t &windowWidth);
```

**Description**

Obtains the width of the window when the ability is started, in px.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| windowWidth     | Window width, in px.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t windowWidth = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsWindowWidth(options, windowWidth);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsStartWindowIcon

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions, OH_PixelmapNative *startWindowIcon)
```

**Description**

Sets the startup icon of the window when the ability is started. The maximum size of an image used as the startup icon is 600 MB.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| startWindowIcon     | Startup icon.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** or **OH_PixelmapNative** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    uint8_t data[96];
    size_t dataSize = 96;
    for (int i = 0; i < dataSize; i++) {
        data[i] = i + 1;
    }

    // Create a parameter structure instance and set parameters.
    OH_Pixelmap_InitializationOptions *createOpts = nullptr;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, 6);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, 4);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);

    // Create a Pixelmap instance.
    OH_PixelmapNative *startWindowIcon = nullptr;
    Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &startWindowIcon);
    if (errCode != IMAGE_SUCCESS) {
        // Record error logs and other service processing.

        // Destroy createOpts to prevent memory leakage.
        OH_PixelmapInitializationOptions_Release(createOpts);
        return;
    }

    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.

        // Destroy createOpts to prevent memory leakage.
        OH_PixelmapInitializationOptions_Release(createOpts);

        // Destroy startWindowIcon to prevent memory leakage.
        OH_PixelmapNative_Release(startWindowIcon);
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsStartWindowIcon(options, startWindowIcon);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy createOpts to prevent memory leakage.
    OH_PixelmapInitializationOptions_Release(createOpts);

    // Destroy startWindowIcon to prevent memory leakage.
    OH_PixelmapNative_Release(startWindowIcon);

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsStartVisibility

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_StartVisibility startVisibility);
```

**Description**

Sets the visibility of the window and dock bar icons when the ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| startVisibility     | Visibility. For details about the available options, see [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility).                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null or **startVisibility** is not an enumerated value of **AbilityRuntime_StartVisibility**.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_StartVisibility visibility = AbilityRuntime_StartVisibility::ABILITY_RUNTIME_SHOW_UPON_START;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsStartVisibility(options, visibility);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsStartVisibility

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_StartVisibility &startVisibility);
```

**Description**

Obtains the visibility of the window and dock bar icons when the ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| startVisibility     | Visibility. For details about the available options, see [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility).                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** or **startVisibility** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_StartVisibility visibility;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsStartVisibility(options, visibility);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsStartWindowIcon

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,
    OH_PixelmapNative **startWindowIcon)
```

**Description**

Obtains the startup icon of the window when the ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| startWindowIcon     | Startup icon.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null or **OH_PixelmapNative** is not nullptr.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    OH_PixelmapNative *startWindowIcon = nullptr;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsStartWindowIcon(options, &startWindowIcon);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy startWindowIcon to prevent memory leakage.
    OH_PixelmapNative_Release(startWindowIcon);

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, const char *startWindowBackgroundColor)
```

**Description**

Sets the background color of the window when the ability is started. Background color of the window. If this function is not called, the value of **startWindowBackground** configured under [abilities](../../quick-start/module-configuration-file.md#abilities) in the [module.json5](../../quick-start/module-configuration-file.md) file corresponding to the UIAbility is used by default.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| startWindowBackgroundColor     | Background color of the window. The value is in ARGB format, for example, **#E5FFFFFF**.|

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** or **StartWindowBackgroundColor** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor(options, "#00000000");
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, char **startWindowBackgroundColor, size_t &size)
```

**Description**

Obtains the background color of the window when the ability is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| startWindowBackgroundColor     | Background color of the window. The value is in ARGB format, for example, **#E5FFFFFF**.|
| size     | Size of the background color.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null or **StartWindowBackgroundColor** is not mullptr.

**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error that cannot be rectified, such as internal malloc error or string copy function error, occurs.

**Example**
```cpp
#include <cstdlib>

#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    char *startWindowBackgroundColor = nullptr;
    size_t size = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor(options,
        &startWindowBackgroundColor, size);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    if (startWindowBackgroundColor != nullptr) {
        // Destroy startWindowBackgroundColor to prevent memory leakage.
        free(startWindowBackgroundColor);
        startWindowBackgroundColor = nullptr;
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsSupportedWindowModes

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_SupportedWindowMode *supportedWindowModes, size_t size)
```

**Description**

Sets the window modes supported by the ability when it is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| supportedWindowModes     | Window modes supported. For details about the available options, see [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode).                          |
| size     | Size of the window modes supported.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** or **SupportedWindowModes** is null, or **Size** is **0**.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
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
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsSupportedWindowModes

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions,
    AbilityRuntime_SupportedWindowMode **supportedWindowModes, size_t &size)
```

**Description**

Obtains the window modes supported by the ability when it is started.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| supportedWindowModes     | Window modes supported. For details about the available options, see [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode).                          |
| size     | Size of the window modes supported.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null or **SupportWindowMode** is not nullptr.

**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error that cannot be rectified, such as internal malloc error, occurs.

**Example**
```cpp
#include <cstdlib>

#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_SupportedWindowMode *supportedWindowModes = nullptr;
    size_t size = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsSupportedWindowModes(options,
        &supportedWindowModes, size);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    if (supportedWindowModes != nullptr) {
        // Destroy supportedWindowModes to prevent memory leakage.
        free(supportedWindowModes);
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMinWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t minWindowWidth)
```

**Description**

Sets the minimum window width for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| minWindowWidth     | Minimum window width, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMinWindowWidth(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMinWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t &minWindowWidth)
```

**Description**

Obtains the minimum window width for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| minWindowWidth     | Minimum window width, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t minWindowWidth = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMinWindowWidth(options, minWindowWidth);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMaxWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t maxWindowWidth)
```

**Description**

Sets the maximum window width for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| maxWindowWidth     | Maximum window width, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMaxWindowWidth(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMaxWindowWidth

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions,
    int32_t &maxWindowWidth)
```

**Description**

Obtains the maximum window width for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| maxWindowWidth     | Maximum window width, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t maxWindowWidth = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMaxWindowWidth(options, maxWindowWidth);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMinWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t minWindowHeight)
```

**Description**

Sets the minimum window height for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| minWindowHeight     | Minimum window height, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMinWindowHeight(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMinWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t &minWindowHeight)
```

**Description**

Obtains the minimum window height for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| minWindowHeight     | Minimum window height, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t minWindowHeight = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMinWindowHeight(options, minWindowHeight);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_SetStartOptionsMaxWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t maxWindowHeight)
```

**Description**

Sets the maximum window height for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| maxWindowHeight     | Maximum window height, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_SetStartOptionsMaxWindowHeight(options, 100);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_GetStartOptionsMaxWindowHeight

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions,
    int32_t &maxWindowHeight)
```

**Description**

Obtains the maximum window height for starting the ability, in vp.

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| startOptions     | Pointer to the StartOptions struct.                          |
| maxWindowHeight     | Maximum window height, in vp.                          |

**Since**: 17

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The information is obtained successfully.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **startOptions** is null.

**Example**
```cpp
#include <AbilityKit/ability_runtime/start_options.h>

void demo()
{
    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    int32_t maxWindowHeight = 0;
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_GetStartOptionsMaxWindowHeight(options, maxWindowHeight);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(AbilityBase_Want *want, AbilityRuntime_StartOptions *options)
```

**Description**

Starts the UIAbility of the current application.

> **NOTE**
>
> This function is valid only for 2-in-1 devices.

**Required permissions**: ohos.permission.NDK_START_SELF_UI_ABILITY

**Since**: 17

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| want      | Pointer to the Want information required for starting the UIAbility.                          |
| options      | Pointer to the StartOptions required for starting the UIAbility.<br>**NOTE**<br>If the value of [startVisibility](#abilityruntime_startvisibility) is not null, ensure that the current application has been added to the status bar. Otherwise, the **ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED** error code is returned.|

**Returns**

**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.

**ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED**: Permission verification fails.

**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The Want or StartOptions information is null, or if the bundleName or abilityName in the Want information is null.

**ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED**: The device type is not supported.

**ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY**: The specified ability name does not exist.

**ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE**: The ability type is incorrect.

**ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED**: The crowdtesting application expires.

**ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE**: The ability is started or stopped in Wukong mode.

**ABILITY_RUNTIME_ERROR_CODE_CONTROLLED**: The application is under control.

**ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED**: The application is under control by EDM.

**ABILITY_RUNTIME_ERROR_CODE_CROSS_APP**: It is forbidden to start other applications.

**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error occurs.

**ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY**: The application is not in the foreground.

**ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED**: It is forbidden to set the application visibility.

**ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED**: The application does not support clone and multi-instance mode.

**ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY**: The instance key is invalid.

**ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED**: The number of instances has reached the upper limit.

**ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED**: The application does not support multi-instance mode.

**ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED**: APP_INSTANCE_KEY cannot be assigned a value.

**Example**
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
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.

        // Destroy the Want to prevent memory leakage.
        OH_AbilityBase_DestroyWant(want);
        return;
    }
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(want, options);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy the Want to prevent memory leakage.
    OH_AbilityBase_DestroyWant(want);

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```