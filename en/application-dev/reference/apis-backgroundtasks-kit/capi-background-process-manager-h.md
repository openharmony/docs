# background_process_manager.h

<!--Kit: Background Tasks Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @hongjianfeng-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e9ccb11c7da46b7a5906c2fca9a820e7830def5f translatedAt=2026-08-11T01:56:22.482Z pushedAt=2026-08-11T03:04:30.295Z -->

## Overview

The **background_process_manager.h** file declares the APIs for background child process management. You can use these APIs to suppress and unsuppress child processes to prevent child processes from occupying too many system resources and causing system stuttering. The APIs take effect only for the child processes created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocess).

**File to include**: <background_process_manager/background_process_manager.h>

**Library**: libbackground_process_manager.z.so

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

**Since**: 17

**Related module**: [BackgroundProcessManager](capi-backgroundprocessmanager.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) | BackgroundProcessManager_ProcessPriority | Enumerates child process priorities.|
| [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode) | BackgroundProcessManager_ErrorCode | Enumerates the error codes used by the background child process management.|

### Functions

| Name| Description|
| -- | -- |
| [int OH_BackgroundProcessManager_SetProcessPriority(int pid, BackgroundProcessManager_ProcessPriority priority)](#oh_backgroundprocessmanager_setprocesspriority) | Sets the child process priority. After a child process is suppressed, the CPU resources that can be obtained will be limited. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. To suppress the child process, call this API again. |
| [int OH_BackgroundProcessManager_ResetProcessPriority(int pid)](#oh_backgroundprocessmanager_resetprocesspriority) | Unsuppresses the child process. In this case, the child process follows the scheduling policy of the main process. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. The effect is the same as calling **resetProcessPriority**.|

## Enum Description

### BackgroundProcessManager_ProcessPriority

```c
enum BackgroundProcessManager_ProcessPriority
```

**Description**

Enumerates child process priorities.

**Since**: 17

| Enum| Description|
| -- | -- |
| PROCESS_BACKGROUND = 1 | Compared with **PROCESS_INACTIVE**, this priority has a more obvious suppression effect. Child processes can obtain less CPU resources. You are advised to set this priority when executing background child processes that cannot be perceived by users, such as background image-text pages.|
| PROCESS_INACTIVE = 2 | You are advised to set this priority when executing background child processes that can be perceived by users, such as audio playback and navigation.|

### BackgroundProcessManager_ErrorCode

```c
enum BackgroundProcessManager_ErrorCode
```

**Description**

Enumerates the error codes used by the background child process management.

**Since**: 17

| Enum| Description|
| -- | -- |
| ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS = 0 | The suppression parameter is sent successfully.|
| ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM = 401 | Parameter check fails.|
| ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR = 31800001 | The client process fails to obtain the system service.|

## Function Description

### OH_BackgroundProcessManager_SetProcessPriority()

```c
int OH_BackgroundProcessManager_SetProcessPriority(int pid, BackgroundProcessManager_ProcessPriority priority)
```

**Description**

Sets the child process priority. After a child process is suppressed, the CPU resources that can be obtained will be limited. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. To suppress the child process, call this API again.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| int pid | ID of the child process to be suppressed, which is the value of the **pid** parameter after the child process is created through the [OH_Ability_StartNativeChildProcess](../apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocess) API.|
| [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) priority | Suppression priority. |

**Returns**

| Type| Description|
| -- | -- |
| int | [ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS](#backgroundprocessmanager_errorcode) is returned if the suppression parameter is sent successfully.<br>         [ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM](#backgroundprocessmanager_errorcode) is returned if the parameter check fails. |

### OH_BackgroundProcessManager_ResetProcessPriority()

```c
int OH_BackgroundProcessManager_ResetProcessPriority(int pid)
```

**Description**

Unsuppresses the child process. In this case, the child process follows the scheduling policy of the main process. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. The effect is the same as calling **resetProcessPriority**.

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| int pid | ID of the child process, which is the value of the **pid** parameter of the [OH_Ability_StartNativeChildProcess](../apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocess) API.|

**Returns**

| Type| Description|
| -- | -- |
| int | [ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS](#backgroundprocessmanager_errorcode) is returned if the decompression is successful. |