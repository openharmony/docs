# background_process_manager.h


## Overview

The **background_process_manager.h** file declares the APIs for background child process management. You can use these APIs to suppress and unsuppress child processes to prevent child processes from occupying too many system resources and causing system stuttering. The APIs take effect only for the child processes created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess).

**Library**: libbackground_process_manager.z.so

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

**Since**: 15

**Related module**: [BackgroundProcessManager](_background_process_manager.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) | Defines an enum for the child process priority. | 
| typedef enum [BackgroundProcessManager_ErrorCode](_background_process_manager.md#backgroundprocessmanager_errorcode) [BackgroundProcessManager_ErrorCode](_background_process_manager.md#backgroundprocessmanager_errorcode) | Defines an enum for the error codes used by the background child process management. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) { [PROCESS_BACKGROUND](_background_process_manager.md) = 1, [PROCESS_INACTIVE](_background_process_manager.md) = 2 } | Enumerates child process priorities. | 
| [BackgroundProcessManager_ErrorCode](_background_process_manager.md#backgroundprocessmanager_errorcode) { [ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS](_background_process_manager.md) = 0, [ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM](_background_process_manager.md) = 401, [ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR](_background_process_manager.md) = 31800001 } | Enumerates the error codes used by the background child process management. | 


### Function

| Name| Description| 
| -------- | -------- |
| int [OH_BackgroundProcessManager_SetProcessPriority](_background_process_manager.md#oh_backgroundprocessmanager_setprocesspriority) (int pid, [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) priority) | Sets the child process priority. After a child process is suppressed, the CPU resources that can be obtained will be limited. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. To suppress the child process, call this API again. | 
| int [OH_BackgroundProcessManager_ResetProcessPriority](_background_process_manager.md#oh_backgroundprocessmanager_resetprocesspriority) (int pid) | Unsuppresses the child process. In this case, the child process follows the scheduling policy of the main process. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. The effect is the same as calling **resetProcessPriority**. | 
