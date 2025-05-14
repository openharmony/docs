# BackgroundProcessManager


## Overview

The **BackgroundProcessManager** module provides C APIs for managing the scheduling policy of background child processes.

**Since**: 15


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [background_process_manager.h](background__process__manager_8h.md) | The **background_process_manager.h** file declares the APIs for background child process management. You can use these APIs to suppress and unsuppress child processes to prevent child processes from occupying too many system resources and causing system stuttering. The APIs take effect only for the child processes created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess). | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) | Defines an enum for the child process priority. | 
| typedef enum [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode) [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode) | Defines an enum for the error codes used by the background child process management. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) { PROCESS_BACKGROUND = 1, PROCESS_INACTIVE = 2 } | Enumerates child process priorities. | 
| [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode) { ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS = 0, ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM = 401, ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR = 31800001 } | Enumerates the error codes used by the background child process management. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_BackgroundProcessManager_SetProcessPriority](#oh_backgroundprocessmanager_setprocesspriority) (int pid, [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) priority) | Sets the child process priority. After a child process is suppressed, the CPU resources that can be obtained will be limited. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. To suppress the child process, call this API again. | 
| int [OH_BackgroundProcessManager_ResetProcessPriority](#oh_backgroundprocessmanager_resetprocesspriority) (int pid) | Unsuppresses the child process. In this case, the child process follows the scheduling policy of the main process. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. The effect is the same as calling **resetProcessPriority**. | 


## Type Description


### BackgroundProcessManager_ErrorCode

```
typedef enum BackgroundProcessManager_ErrorCodeBackgroundProcessManager_ErrorCode
```
**Description**

Defines an enum for the error codes used by the background child process management.

**Since**: 15


### BackgroundProcessManager_ProcessPriority

```
typedef enum BackgroundProcessManager_ProcessPriorityBackgroundProcessManager_ProcessPriority
```
**Description**

Defines an enum for the child process priority.

**Since**: 15


## Enum Description


### BackgroundProcessManager_ErrorCode

```
enum BackgroundProcessManager_ErrorCode
```
**Description**

Enumerates the error codes used by the background child process management.

**Since**: 15

| Value| Description| 
| -------- | -------- |
| ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS  | The suppression parameter is sent successfully.| 
| ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM  | Parameter check failed.| 
| ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR  | The client process fails to obtain the system service.| 


### BackgroundProcessManager_ProcessPriority

```
enum BackgroundProcessManager_ProcessPriority
```
**Description**

Enumerates child process priorities.

**Since**: 15

| Value| Description| 
| -------- | -------- |
| PROCESS_BACKGROUND  | Compared with **PROCESS_INACTIVE**, this priority has a more obvious suppression effect. Child processes can obtain less CPU resources. You are advised to set this priority when executing background child processes that cannot be perceived by users, such as background image-text pages.&nbsp;&nbsp; | 
| PROCESS_INACTIVE  | You are advised to set this priority when executing background child processes that can be perceived by users, such as audio playback and navigation.&nbsp;&nbsp; | 


## Function Description


### OH_BackgroundProcessManager_ResetProcessPriority()

```
int OH_BackgroundProcessManager_ResetProcessPriority (int pid)
```
**Description**

Unsuppresses the child process. In this case, the child process follows the scheduling policy of the main process. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. The effect is the same as calling **resetProcessPriority**.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| pid | Child process ID, which is returned when the child process is created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess). | 

**Returns**

Returns an error code. For details about the error codes, see [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode). **ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS** is returned if the suppression parameter is sent successfully. **ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR** is returned if the client process fails to obtain the system service.


### OH_BackgroundProcessManager_SetProcessPriority()

```
int OH_BackgroundProcessManager_SetProcessPriority (int pid, BackgroundProcessManager_ProcessPriority priority )
```
**Description**

Sets the child process priority. After a child process is suppressed, the CPU resources that can be obtained will be limited. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. To suppress the child process, call this API again.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| pid | ID of the child process to be suppressed, which is returned when the child process is created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess). | 
| priority | Suppression priority.| 

**Returns**

Returns an error code. For details about the error codes, see [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode). **ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS** is returned if the suppression parameter is sent successfully. **ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM** is returned if the parameter check fails. **ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR** is returned if the client process fails to obtain the system service.
