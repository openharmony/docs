# context_constant.h

## Overview

The file declares the context constants of the AbilityRuntime module.

**File to include**: <AbilityKit/ability_runtime/context_constant.h>

**Library**: libability_runtime.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13

**Related module**: [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AbilityRuntime_AreaMode](#abilityruntime_areamode) | AbilityRuntime_AreaMode | Enumerates the data encryption levels.|
| [AbilityRuntime_StartVisibility](#abilityruntime_startvisibility) | AbilityRuntime_StartVisibility | Enumerates the visibility modes of the window and dock bar icons when the ability is started.|
| [AbilityRuntime_WindowMode](#abilityruntime_windowmode) | AbilityRuntime_WindowMode | Enumerates the window modes.|
| [AbilityRuntime_SupportedWindowMode](#abilityruntime_supportedwindowmode) | AbilityRuntime_SupportedWindowMode | Enumerates the window modes supported by an ability when it is started. The supported window mode specifies whether to display the maximize, minimize, or split-screen button when the UIAbility is launched in an application.|

## Enum Description

### AbilityRuntime_AreaMode

```
enum AbilityRuntime_AreaMode
```

**Description**

Enumerates the data encryption levels.

**Since**: 13

| Value| Description|
| -- | -- |
| ABILITY_RUNTIME_AREA_MODE_EL1 = 0 | Device-level encryption. Directories with this encryption level are accessible after the device is powered on.<br>For private files, such as alarms and wallpapers, the application can place them in a directory with the device-level encryption (EL1) to ensure that they can be accessed before the user enters the password.|
| ABILITY_RUNTIME_AREA_MODE_EL2 = 1 | User-level encryption. Directories with this encryption level are accessible only after the device is powered on and the password is entered (for the first time).<br>For private files, such as alarms and wallpapers, the application can place them in a directory with the device-level encryption (EL1) to ensure that they can be accessed before the user enters the password.|
| ABILITY_RUNTIME_AREA_MODE_EL3 = 2 | User-level encryption. The file permissions vary according to their scenarios.<br>- Open files: You can read and write to files that are already open, whether the screen is locked or unlocked.<br>- Closed files: When the screen is locked, you cannot open, read, or write to closed files. Once the screen is unlocked, you can open, read, and write to closed files.<br>- New files: When the screen is locked, you can create, open, and write to new files, but reading them is not permitted. Once the screen is unlocked, you can create, open, read, and write to new files.<br>For step recording, file download, or music playback that needs to read, write, and create files when the screen is locked, the application can place these files in EL3.|
| ABILITY_RUNTIME_AREA_MODE_EL4 = 3 | User-level encryption. The file permissions vary according to their scenarios.<br>- Open files: When the screen is locked, you can read and write to open files in FEB2.0, but not in FEB3.0. When the screen is unlocked, you can read and write to open files.<br>- Closed files: When the screen is locked, you cannot open, read, or write to closed files. Once the screen is unlocked, you can open, read, and write to closed files.<br>- New files: When the screen is locked, you cannot create files. Once the screen is unlocked, you can create, open, read, and write to new files.<br>For files that are related to user security information and do not need to be read, written, or created when the screen is locked, the application can place them in EL4.|
| ABILITY_RUNTIME_AREA_MODE_EL5 = 4 | Application-level encryption. The file permissions vary according to their scenarios.<br>- Open files: You can read and write to files that are already open, whether the screen is locked or unlocked.<br>* Closed files: When the screen is locked, you can open, read, and write to closed files only if a DataAccessLock (JS API) is obtained. When the screen is unlocked, you can always open, read, and write to closed files.<br>- New files: You can create, open, read, and write to new files, whether the screen is locked or unlocked.<br>By default, sensitive user privacy files cannot be read or written on the lock screen. If such files need to be read or written on the lock screen, you can call [Access](js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess) to apply for reading or writing files before the screen is locked or create new files that can be read and written after the screen is locked. It is more appropriate to place these files in EL5.|

### AbilityRuntime_StartVisibility

```
enum AbilityRuntime_StartVisibility
```

**Description**

Enumerates the visibility modes of the window and dock bar icons when the ability is started.

**Since**: 17

| Value| Description|
| -- | -- |
| ABILITY_RUNTIME_HIDE_UPON_START = 0 | Hides the window and dock bar icons. This mode takes effect only on 2-in-1 devices.|
| ABILITY_RUNTIME_SHOW_UPON_START = 1 | Displays the window and dock bar icons. This mode takes effect only on 2-in-1 devices.|

### AbilityRuntime_WindowMode

```
enum AbilityRuntime_WindowMode
```

**Description**

Enumerates the window modes.

**Since**: 17

| Value| Description|
| -- | -- |
| ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED = 0 | Window mode not defined.|
| ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN = 1 | Full-screen mode. This mode takes effect only on 2-in-1 devices.|

### AbilityRuntime_SupportedWindowMode

```
enum AbilityRuntime_SupportedWindowMode
```

**Description**

Enumerates the window modes supported by an ability when it is started. The supported window mode specifies whether to display the maximize, minimize, or split-screen button when the UIAbility is launched in an application. If this property is not set, the value of **supportWindowMode** configured under [abilities](../../quick-start/module-configuration-file.md#abilities) in the [module.json5](../../quick-start/module-configuration-file.md) file corresponding to the UIAbility is used by default.

**Since**: 17

| Value| Description|
| -- | -- |
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN = 0 | A window in full-screen mode is supported.|
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT = 1 | A window in split-screen mode is supported. Generally, **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN** or **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING** must be used together. You are not advised to configure only **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT**. If only **ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT** is configured, the window on 2-in-1 devices is in floating window mode by default and can transition to the split-screen mode.|
| ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING = 2 | A floating window is supported.|
