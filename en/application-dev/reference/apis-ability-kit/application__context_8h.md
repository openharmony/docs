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
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetTempDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgettempdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level temporary file directory.  |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetFilesDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level common file directory.  |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDatabaseDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetdatabasedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level database file directory.|
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetPreferencesDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetpreferencesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level preferences file directory.|
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleCodeDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetbundlecodedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level installation file directory.  |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetdistributedfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level distributed file directory.|
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCloudFileDir](_ability_runtime.md#oh_abilityruntime_applicationcontextgetcloudfiledir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level cloud file directory.    |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_StartSelfUIAbility](_ability_runtime.md#oh_abilityruntime_startselfuiability)([AbilityBase_Want](_ability_base.md#abilitybase_want) *want) | Starts the UIAbility of the current application.    |
