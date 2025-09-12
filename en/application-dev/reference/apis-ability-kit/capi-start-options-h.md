# start_options.h

## Overview

The file declares the [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) struct for application startup parameters and the functions for setting and obtaining data.

**File to include**: <AbilityKit/ability_runtime/start_options.h>

**Library**: libability_runtime.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 17

**Related module**: [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) | AbilityRuntime_StartOptions | StartOptions struct.|

### Functions

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions* OH_AbilityRuntime_CreateStartOptions(void)](#oh_abilityruntime_createstartoptions) | Creates an AbilityRuntime_StartOptions object.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_DestroyStartOptions(AbilityRuntime_StartOptions **startOptions)](#oh_abilityruntime_destroystartoptions) | Destroys an AbilityRuntime_StartOptions object.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_WindowMode windowMode)](#oh_abilityruntime_setstartoptionswindowmode) | Sets the window mode for starting an ability.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_WindowMode &windowMode)](#oh_abilityruntime_getstartoptionswindowmode) | Obtains the window mode for starting an ability.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions,int32_t displayId)](#oh_abilityruntime_setstartoptionsdisplayid) | Sets the ID of the display where the window is launched when the ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions,int32_t &displayId)](#oh_abilityruntime_getstartoptionsdisplayid) | Obtains the ID of the display where the window is launched when the ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions,bool withAnimation)](#oh_abilityruntime_setstartoptionswithanimation) | Sets whether to use animation effects when an ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions,bool &withAnimation)](#oh_abilityruntime_getstartoptionswithanimation) | Checks whether animation effects are used when an ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions,int32_t windowLeft)](#oh_abilityruntime_setstartoptionswindowleft) | Sets the left position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions,int32_t &windowLeft)](#oh_abilityruntime_getstartoptionswindowleft) | Obtains the left position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions,int32_t windowTop)](#oh_abilityruntime_setstartoptionswindowtop) | Sets the top position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions,int32_t &windowTop)](#oh_abilityruntime_getstartoptionswindowtop) | Obtains the top position of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions,int32_t windowHeight)](#oh_abilityruntime_setstartoptionswindowheight) | Sets the height of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions,int32_t &windowHeight)](#oh_abilityruntime_getstartoptionswindowheight) | Obtains the height of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions,int32_t windowWidth)](#oh_abilityruntime_setstartoptionswindowwidth) | Sets the width of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions,int32_t &windowWidth)](#oh_abilityruntime_getstartoptionswindowwidth) | Obtains the width of the window when the ability is started, in px.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_StartVisibility startVisibility)](#oh_abilityruntime_setstartoptionsstartvisibility) | Sets the visibility of the window and dock bar icons when the ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_StartVisibility &startVisibility)](#oh_abilityruntime_getstartoptionsstartvisibility) | Obtains the visibility of the window and dock bar icons when the ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,OH_PixelmapNative *startWindowIcon)](#oh_abilityruntime_setstartoptionsstartwindowicon) | Sets the startup icon of the window when the ability is started. The maximum size of an image used as the startup icon is 600 MB.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,OH_PixelmapNative **startWindowIcon)](#oh_abilityruntime_getstartoptionsstartwindowicon) | Obtains the startup icon of the window when the ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, const char *startWindowBackgroundColor)](#oh_abilityruntime_setstartoptionsstartwindowbackgroundcolor) | Sets the background color of the window when the ability is started. If this function is not called, the value of **startWindowBackground** configured under **abilities** in the **module.json5** file corresponding to the UIAbility is used by default.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, char **startWindowBackgroundColor, size_t &size)](#oh_abilityruntime_getstartoptionsstartwindowbackgroundcolor) | Obtains the background color of the window when the ability is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_SupportedWindowMode *supportedWindowModes,size_t size)](#oh_abilityruntime_setstartoptionssupportedwindowmodes) | Sets the window modes supported by the ability when it is started. If this function is not called, the value of **supportWindowMode** configured under **abilities** in the **module.json5** file corresponding to the UIAbility is used by default.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_SupportedWindowMode **supportedWindowModes,size_t &size)](#oh_abilityruntime_getstartoptionssupportedwindowmodes) | Obtains the window modes supported by the ability when it is started.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t minWindowWidth)](#oh_abilityruntime_setstartoptionsminwindowwidth) | Sets the minimum width of the window when the ability is started, in vp.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t &minWindowWidth)](#oh_abilityruntime_getstartoptionsminwindowwidth) | Obtains the minimum width of the window when the ability is started, in vp.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t maxWindowWidth)](#oh_abilityruntime_setstartoptionsmaxwindowwidth) | Sets the maximum width of the window when the ability is started, in vp.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t &maxWindowWidth)](#oh_abilityruntime_getstartoptionsmaxwindowwidth) | Obtains the maximum width of the window when the ability is started, in vp.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t minWindowHeight)](#oh_abilityruntime_setstartoptionsminwindowheight) | Sets the minimum height of the window when the ability is started, in vp.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t &minWindowHeight)](#oh_abilityruntime_getstartoptionsminwindowheight) | Obtains the minimum height of the window when the ability is started, in vp.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t maxWindowHeight)](#oh_abilityruntime_setstartoptionsmaxwindowheight) | Sets the maximum height of the window when the ability is started, in vp.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t &maxWindowHeight)](#oh_abilityruntime_getstartoptionsmaxwindowheight) | Obtains the maximum height of the window when the ability is started, in vp.|

## Function Description

### OH_AbilityRuntime_CreateStartOptions()

```
AbilityRuntime_StartOptions* OH_AbilityRuntime_CreateStartOptions(void)
```

**Description**

Creates an [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) object.

**Since**: 17

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md)* | Pointer to the AbilityRuntime_StartOptions object created.|

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

### OH_AbilityRuntime_DestroyStartOptions()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_DestroyStartOptions(AbilityRuntime_StartOptions **startOptions)
```

**Description**

Destroys an [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) object.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) **startOptions | Double pointer to the AbilityRuntime_StartOptions object.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsWindowMode()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_WindowMode windowMode)
```

**Description**

Sets the window mode for starting an ability.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| [AbilityRuntime_WindowMode](capi-context-constant-h.md#abilityruntime_windowmode) windowMode | Window mode. For details about the available options, see **AbilityRuntime_WindowMode**.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr, or **WindowMode** is invalid.|

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

### OH_AbilityRuntime_GetStartOptionsWindowMode()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowMode(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_WindowMode &windowMode)
```

**Description**

Obtains the window mode for starting an ability.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| [AbilityRuntime_WindowMode](capi-context-constant-h.md#abilityruntime_windowmode) windowMode | Window mode. For details about the available options, see **AbilityRuntime_WindowMode**.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsDisplayId()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions,int32_t displayId)
```

**Description**

Sets the ID of the display where the window is launched when the ability is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t displayId | Display ID.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsDisplayId()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsDisplayId(AbilityRuntime_StartOptions *startOptions,int32_t &displayId)
```

**Description**

Obtains the ID of the display where the window is launched when the ability is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &displayId | Display ID.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsWithAnimation()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions,bool withAnimation)
```

**Description**

Sets whether to use animation effects when an ability is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| bool withAnimation | Whether to use animation effects.<br>**true** to use, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsWithAnimation()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWithAnimation(AbilityRuntime_StartOptions *startOptions,bool &withAnimation)
```

**Description**

Checks whether animation effects are used when an ability is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| bool &withAnimation | Check result for whether animation effects are used.<br>**true** if used, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsWindowLeft()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions,int32_t windowLeft)
```

**Description**

Sets the left position of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t windowLeft | Left position of the window, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsWindowLeft()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowLeft(AbilityRuntime_StartOptions *startOptions,int32_t &windowLeft)
```

**Description**

Obtains the left position of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &windowLeft | Left position of the window, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsWindowTop()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions,int32_t windowTop)
```

**Description**

Sets the top position of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t windowTop | Top position of the window, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsWindowTop()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowTop(AbilityRuntime_StartOptions *startOptions,int32_t &windowTop)
```

**Description**

Obtains the top position of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &windowTop | Top position of the window, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsWindowHeight()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions,int32_t windowHeight)
```

**Description**

Sets the height of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t windowHeight | Window height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsWindowHeight()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowHeight(AbilityRuntime_StartOptions *startOptions,int32_t &windowHeight)
```

**Description**

Obtains the height of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &windowHeight | Window height, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsWindowWidth()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions,int32_t windowWidth)
```

**Description**

Sets the width of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t windowWidth | Window width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsWindowWidth()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsWindowWidth(AbilityRuntime_StartOptions *startOptions,int32_t &windowWidth)
```

**Description**

Obtains the width of the window when the ability is started, in px.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &windowWidth | Window width, in px.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsStartVisibility()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_StartVisibility startVisibility)
```

**Description**

Sets the visibility of the window and dock bar icons when the ability is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to the StartOptions struct.|
| [AbilityRuntime_StartVisibility](capi-context-constant-h.md#abilityruntime_startvisibility) startVisibility | Visibility. For details about the available options, see **AbilityRuntime_StartVisibility**.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The setting is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr, or **startVisibility** is not an enumerated value of **AbilityRuntime_StartVisibility**.|

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

### OH_AbilityRuntime_GetStartOptionsStartVisibility()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartVisibility(AbilityRuntime_StartOptions *startOptions,AbilityRuntime_StartVisibility &startVisibility)
```

**Description**

Obtains the visibility of the window and dock bar icons when the ability is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to the StartOptions struct.|
| [bilityRuntime_StartVisibility](capi-context-constant-h.md#abilityruntime_startvisibility) &startVisibility | Visibility. For details about the available options, see **AbilityRuntime_StartVisibility**.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The retrieval is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr, or **startVisibility** is empty.|

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

### OH_AbilityRuntime_SetStartOptionsStartWindowIcon()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,OH_PixelmapNative *startWindowIcon)
```

**Description**

Sets the startup icon of the window when the ability is started. The maximum size of an image used as the startup icon is 600 MB.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| OH_PixelmapNative *startWindowIcon | Pointer to the startup icon of the window. The maximum size of an image used as the startup icon is 600 MB.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr, or **OH_PixelmapNative** is not nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsStartWindowIcon()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowIcon(AbilityRuntime_StartOptions *startOptions,OH_PixelmapNative **startWindowIcon)
```

**Description**

Obtains the startup icon of the window when the ability is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| OH_PixelmapNative **startWindowIcon | Double pointer to the startup icon of the window.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** or **StartWindowBackgroundColor** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, const char *startWindowBackgroundColor)
```

**Description**

Sets the background color of the window when the ability is started. If this property is not set, the value of **startWindowBackground** configured under [abilities](../../quick-start/module-configuration-file.md#abilities) in the [module.json5](../../quick-start/module-configuration-file.md) file corresponding to the UIAbility is used by default.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| const char *startWindowBackgroundColor | Pointer to the background color of the window. The value is in ARGB format, for example, **#E5FFFFFF**.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr, or **StartWindowBackgroundColor** is not nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsStartWindowBackgroundColor(AbilityRuntime_StartOptions *startOptions, char **startWindowBackgroundColor, size_t &size)
```

**Description**

Obtains the background color of the window when the ability is started.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| char **startWindowBackgroundColor | Double pointer to the background color of the window. The value is in ARGB format, for example, **#E5FFFFFF**.|
| size_t &size | Size of the background color.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** or **SupportedWindowModes** is nullptr, or **Size** is **0**.<br>**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error that cannot be rectified, such as internal malloc error or string copy function error, occurs.|

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

### OH_AbilityRuntime_SetStartOptionsSupportedWindowModes()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_SupportedWindowMode *supportedWindowModes,size_t size)
```

**Description**

Sets the window modes supported by the ability when it is started.


**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| [AbilityRuntime_SupportedWindowMode](capi-context-constant-h.md#abilityruntime_supportedwindowmode) *supportedWindowModes | Pointer to the window modes supported. For details about the available options, see **AbilityRuntime_SupportedWindowMode**.|
| size_t size | Size of the window modes supported.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** or **SupportedWindowModes** is nullptr, or **Size** is **0**.|

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

### OH_AbilityRuntime_GetStartOptionsSupportedWindowModes()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsSupportedWindowModes(AbilityRuntime_StartOptions *startOptions, AbilityRuntime_SupportedWindowMode **supportedWindowModes,size_t &size)
```

**Description**

Obtains the window modes supported by the ability when it is started.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| [AbilityRuntime_SupportedWindowMode](capi-context-constant-h.md#abilityruntime_supportedwindowmode) **supportedWindowModes | Double pointer to the window modes supported. For details about the available options, see **AbilityRuntime_SupportedWindowMode**.|
| size | Size of the window modes supported.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr, or **SupportWindowMode** is not nullptr.<br>**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error that cannot be rectified, such as internal malloc error, occurs.|

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

### OH_AbilityRuntime_SetStartOptionsMinWindowWidth()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t minWindowWidth)
```

**Description**

Sets the minimum width of the window when the ability is started, in vp.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t minWindowWidth | Minimum width of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsMinWindowWidth()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t &minWindowWidth)
```

**Description**

Obtains the minimum width of the window when the ability is started, in vp.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &minWindowWidth | Minimum width of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsMaxWindowWidth()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t maxWindowWidth)
```

**Description**

Sets the maximum width of the window when the ability is started, in vp.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t maxWindowWidth | Maximum width of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsMaxWindowWidth()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowWidth(AbilityRuntime_StartOptions *startOptions, int32_t &maxWindowWidth)
```

**Description**

Obtains the maximum width of the window when the ability is started, in vp.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &maxWindowWidth | Maximum width of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsMinWindowHeight()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t minWindowHeight)
```

**Description**

Sets the minimum height of the window when the ability is started, in vp.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t minWindowHeight | Minimum height of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsMinWindowHeight()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMinWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t &minWindowHeight)
```

**Description**

Obtains the minimum height of the window when the ability is started, in vp.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &minWindowHeight | Minimum height of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_SetStartOptionsMaxWindowHeight()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_SetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t maxWindowHeight)
```

**Description**

Sets the maximum height of the window when the ability is started, in vp.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t maxWindowHeight | Maximum height of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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

### OH_AbilityRuntime_GetStartOptionsMaxWindowHeight()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_GetStartOptionsMaxWindowHeight(AbilityRuntime_StartOptions *startOptions, int32_t &maxWindowHeight)
```

**Description**

Obtains the maximum height of the window when the ability is started, in vp.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *startOptions | Pointer to an AbilityRuntime_StartOptions object.|
| int32_t &maxWindowHeight | Maximum height of the window, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The input parameter **StartOptions** is nullptr.|

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
