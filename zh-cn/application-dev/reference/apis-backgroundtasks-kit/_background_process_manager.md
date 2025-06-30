# BackgroundProcessManager


## 概述

提供后台子进程调度策略管控C接口。

**起始版本：** 17


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [background_process_manager.h](background__process__manager_8h.md) | 本模块提供了后台子进程管控接口。开发者可以通过本模块接口对子进程进行压制、解压制，避免子进程过多占用系统资源，导致系统使用卡顿。 本模块接口仅对通过[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)接口创建的子进程生效。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) | 子进程压制档位。  | 
| typedef enum [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode) [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode) | 定义后台子进程管控错误码。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) { PROCESS_BACKGROUND = 1, PROCESS_INACTIVE = 2 } | 子进程压制档位。  | 
| [BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode) { ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS = 0, ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM = 401, ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR = 31800001 } | 定义后台子进程管控错误码。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_BackgroundProcessManager_SetProcessPriority](#oh_backgroundprocessmanager_setprocesspriority) (int pid, [BackgroundProcessManager_ProcessPriority](#backgroundprocessmanager_processpriority) priority) | 设置子进程的压制档位，子进程被压制后可获得的CPU资源将会受到限制。如果主进程调度策略发生变化，如从后台切至前台等，子进程会跟随主进程一同变化，子进程如需继续压制，需要重新调用本接口。  | 
| int [OH_BackgroundProcessManager_ResetProcessPriority](#oh_backgroundprocessmanager_resetprocesspriority) (int pid) | 为子进程解压制，即子进程策略恢复为主进程调度策略。若主进程调度策略发生变化，如从后台切至前台等，子进程会跟随主进程一同变化，等效于执行一次resetProcessPriority动作。  | 


## 类型定义说明


### BackgroundProcessManager_ErrorCode

```
typedef enum BackgroundProcessManager_ErrorCodeBackgroundProcessManager_ErrorCode
```
**描述**

定义后台子进程管控错误码。

**起始版本：** 17


### BackgroundProcessManager_ProcessPriority

```
typedef enum BackgroundProcessManager_ProcessPriorityBackgroundProcessManager_ProcessPriority
```
**描述**

子进程压制档位。

**起始版本：** 17


## 枚举类型说明


### BackgroundProcessManager_ErrorCode

```
enum BackgroundProcessManager_ErrorCode
```
**描述**

定义后台子进程管控错误码。

**起始版本：** 17

| 枚举值 | 描述 | 
| -------- | -------- |
| ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS  | 压制参数发送成功。 | 
| ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM  | 参数检查失败。 | 
| ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR  | 客户端进程请求系统服务进程，获取系统服务操作失败。 | 


### BackgroundProcessManager_ProcessPriority

```
enum BackgroundProcessManager_ProcessPriority
```
**描述**

子进程压制档位。

**起始版本：** 17

| 枚举值 | 描述 | 
| -------- | -------- |
| PROCESS_BACKGROUND  | 该档位相较PROCESS_INACTIVE压制效果更显著，获取到的CPU资源更少。推荐执行处于后台的图文页面等用户无感知业务的后台子进程时设置该档位。&nbsp;&nbsp; | 
| PROCESS_INACTIVE  | 推荐正在执行播放音频、导航等用户可感知业务的后台子进程时设置该档位。&nbsp;&nbsp; | 


## 函数说明


### OH_BackgroundProcessManager_ResetProcessPriority()

```
int OH_BackgroundProcessManager_ResetProcessPriority (int pid)
```
**描述**

为子进程解压制，即子进程策略恢复为主进程调度策略。若主进程调度策略发生变化，如从后台切至前台等， 子进程会跟随主进程一同变化，等效于执行一次resetProcessPriority动作。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pid | 子进程的进程号，[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)接口创建子进程后的pid参数，即为子进程进程号。  | 

**返回：**

返回执行的错误码。错误码定义详见[BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode)。返回 ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS，表示压制参数发送成功。 返回 ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR，表示客户端进程请求系统服务进程，获取系统服务操作失败。 


### OH_BackgroundProcessManager_SetProcessPriority()

```
int OH_BackgroundProcessManager_SetProcessPriority (int pid, BackgroundProcessManager_ProcessPriority priority )
```
**描述**

设置子进程的压制档位，子进程被压制后可获得的CPU资源将会受到限制。如果主进程调度策略发生变化，如从后台切至前台等，子进程会跟随主进程一同变化，子进程如需继续压制，需要重新调用本接口。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pid | 需要被压制子进程的进程号，[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)接口创建子进程后的pid参数，即为子进程进程号。  | 
| priority | 压制档位。 | 

**返回：**

返回执行的错误码。错误码定义详见[BackgroundProcessManager_ErrorCode](#backgroundprocessmanager_errorcode)。返回 ERR_BACKGROUND_PROCESS_MANAGER_SUCCESS，表示压制参数发送成功。 返回 ERR_BACKGROUND_PROCESS_MANAGER_INVALID_PARAM，表示参数检查失败。 返回 ERR_BACKGROUND_PROCESS_MANAGER_REMOTE_ERROR，表示客户端进程请求系统服务进程，获取系统服务操作失败。 
