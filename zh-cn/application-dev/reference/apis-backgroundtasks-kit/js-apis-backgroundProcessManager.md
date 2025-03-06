# @ohos.resourceschedule.backgroundProcessManager (后台子进程管控)

应用可以调用OH_Ability_StartNativeChildProcess、OH_Ability_CreateNativeChildProcess来创建子进程处理相应业务，通过该方式创建的子进程调度策略默认跟随主进程。
本模块提供了对上述子进程进行调度管控的接口，开发者可以通过本模块接口对子进程进行压制、恢复，并且可以针对进程业务不同设置不同的压制档位。

>  **说明：**
>
> 本模块首批接口从API version 16开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';
```

## backgroundProcessManager.setProcessPriority

function setProcessPriority(pid: number, priority: ProcessPriority): Promise<void>;

设置压制档位。

>  **说明：**
>
>  (1) 本接口只对通过调用OH_Ability_StartNativeChildProcess、OH_Ability_CreateNativeChildProcess创建的子进程生效  
>  (2) 调用本接口的进程和需要被压制子进程uid需一致  
>  (3) 如果主进程状态发生变化（可见性、前后台切换等），子进程会跟随主进程一同变化，子进程如需继续压制，需重新调用本接口

**系统能力:** SystemCapability.Resourceschedule.BackgroundProcessManager

**参数**：

| 参数名      | 类型                 | 必填   | 说明                             |
|----------|--------------------| ---- | ------------------------------ |
| pid      | number             | 是    | 需要被压制子进程的进程号                     |
| priority | ProcessPriority    | 是    | 压制档位 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundProcessManager错误码](errorcode-backgroundProcessManager.md)。

| 错误码ID    | 错误信息                                                                                                           |
|----------|----------------------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 31800001 | remote error.                                                                                                  |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManaer } from '@kit.BackgroundTasksKit'

// 如何创建子进程
let childProcessPid = 33333;
try {
    backgroundProcessManaer.setProcessPriority(childProcessPid,
        backgroundProcessManaer.ProcessPriority.PROCESS_INACTIVE);
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## backgroundProcessManager.resetProcessPriority

function resetProcessPriority(pid: number): Promise<void>;

恢复进程管控策略为系统默认策略（跟随主进程策略）。


>  **说明：**
>
>  (1) 本接口只对通过调用OH_Ability_StartNativeChildProcess、OH_Ability_CreateNativeChildProcess创建的子进程生效  
>  (2) 调用本接口的进程和需要被压制子进程uid需一致  
>  (3) 如果主进程状态发生变化（可见性、前后台切换等），子进程会跟随主进程一同变化，等效于执行一次resetProcessPriority动作

**系统能力:** SystemCapability.Resourceschedule.BackgroundProcessManager

**参数**：

| 参数名      | 类型                 | 必填   | 说明                             |
|----------|--------------------| ---- | ------------------------------ |
| pid      | number             | 是    | 需要恢复系统默认策略子进程的进程号                     |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundProcessManager错误码](errorcode-backgroundProcessManager.md)。

| 错误码ID    | 错误信息                                                                                                           |
|----------|----------------------------------------------------------------------------------------------------------------|
| 31800001 | remote error.                                                                                                  |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManaer } from '@kit.BackgroundTasksKit'

// 
let childProcessPid = 33333;
try {
    backgroundProcessManaer.resetProcessPriority(childProcessPid);
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
