# application_context.h


## Overview

The **application_context.h** file declares the context capability at the application level.

**Library**: libability_runtime.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13

**Related module**: [AbilityRuntime](_ability_runtime.md)


## Summary

### Files

| Name                                               | Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ |
| [application_context.h](application__context_8h.md) | Declares the context capability at the application level.<br>**File to include**: <AbilityKit/ability_runtime/application_context.h><br>**Library**: libability_runtime.so|

### Functions

| Name                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCacheDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetcachedir)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the application-level cache directory.    |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetAreaMode](_ability_runtime.md#oh_abilityruntime_applicationcontextgetareamode)([AbilityRuntime_AreaMode](_ability_runtime.md#abilityruntime_areamode)* areaMode) | Obtains the application-level data encryption level.|
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleName](_ability_runtime.md#oh_abilityruntime_applicationcontextgetbundlename)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the bundle name of the application.              |
