# context_constant.h


## Overview

The **context_constant.h** file declares context-related enums.

**Library**: libability_runtime.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13

**Related module**: [AbilityRuntime](_ability_runtime.md)


## Summary

### Files

| Name                                         | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [context_constant.h](context__constant_8h.md) | Declares context-related enums.<br>**File to include**: <AbilityKit/ability_runtime/context_constant.h><br>**Library**: libability_runtime.so|


### Enums

| Name                                                        | Description              |
| ------------------------------------------------------------ | ------------------ |
| [AbilityRuntime_AreaMode](_ability_runtime.md#abilityruntime_areamode) {<br>    ABILITY_RUNTIME_AREA_MODE_EL1 = 0,<br>    ABILITY_RUNTIME_AREA_MODE_EL2 = 1,<br>    ABILITY_RUNTIME_AREA_MODE_EL3 = 2,<br>    ABILITY_RUNTIME_AREA_MODE_EL4 = 3,<br>    ABILITY_RUNTIME_AREA_MODE_EL5 = 4<br>} | Enumerates the data encryption levels.|
| [AbilityRuntime_StartVisibility](_ability_runtime.md#abilityruntime_startvisibility) {<br>    ABILITY_RUNTIME_HIDE_UPON_START = 0,<br>    ABILITY_RUNTIME_SHOW_UPON_START = 1<br>} | Enumerates the visibility modes of the window and dock bar icons when the ability is started.    |
| [AbilityRuntime_WindowMode](_ability_runtime.md#abilityruntime_windowmode) {<br>    ABILITY_RUNTIME_WINDOW_MODE_UNDEFINED = 0,<br>    ABILITY_RUNTIME_WINDOW_MODE_FULL_SCREEN = 1<br>} | Enumerates the window modes in which an ability can be displayed at startup.    |
| [AbilityRuntime_SupportedWindowMode](_ability_runtime.md#abilityruntime_supportedwindowmode) {<br>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FULL_SCREEN = 0,<br>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_SPLIT = 1,<br>    ABILITY_RUNTIME_SUPPORTED_WINDOW_MODE_FLOATING = 2<br>} | Enumerates the window modes supported by an ability when it is started.    |
