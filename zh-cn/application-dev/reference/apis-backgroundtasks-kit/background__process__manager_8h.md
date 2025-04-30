# background_process_manager.h


## 概述

本模块提供了后台子进程管控接口。开发者可以通过本模块接口对子进程进行压制、解压制，避免子进程过多占用系统资源，导致系统使用卡顿。 本模块接口仅对通过[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)接口创建的子进程生效。

**库：** libbackground_process_manager.z.so

**系统能力：** SystemCapability.Resourceschedule.BackgroundProcessManager

**起始版本：** 17

**相关模块：**[BackgroundProcessManager](_background_process_manager.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) | 子进程压制档位。  | 
| typedef enum [BackgroundProcessManager_ErrorCode](_background_process_manager.md#backgroundprocessmanager_errorcode) [BackgroundProcessManager_ErrorCode](_background_process_manager.md#backgroundprocessmanager_errorcode) | 定义后台子进程管控错误码。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) { [PROCESS_BACKGROUND](_background_process_manager.md) = 1, [PROCESS_INACTIVE](_background_process_manager.md) = 2 } | 子进程压制档位。  | 
| [BackgroundProcessManager_ErrorCode](_background_process_manager.md#backgroundprocessmanager_errorcode) { [ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS](_background_process_manager.md) = 0, [ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM](_background_process_manager.md) = 401, [ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR](_background_process_manager.md) = 31800001 } | 定义后台子进程管控错误码。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_BackgroundProcessManager_SetProcessPriority](_background_process_manager.md#oh_backgroundprocessmanager_setprocesspriority) (int pid, [BackgroundProcessManager_ProcessPriority](_background_process_manager.md#backgroundprocessmanager_processpriority) priority) | 设置子进程的压制档位，子进程被压制后可获得的CPU资源将会受到限制。如果主进程调度策略发生变化，如从后台切至前台等， 子进程会跟随主进程一同变化，子进程如需继续压制，需要重新调用本接口。  | 
| int [OH_BackgroundProcessManager_ResetProcessPriority](_background_process_manager.md#oh_backgroundprocessmanager_resetprocesspriority) (int pid) | 为子进程解压制，即子进程策略恢复为主进程调度策略。若主进程调度策略发生变化，如从后台切至前台等， 子进程会跟随主进程一同变化，等效于执行一次resetProcessPriority动作。  | 
