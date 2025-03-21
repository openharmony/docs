# @ohos.resourceschedule.backgroundProcessManager (后台子进程管控)

本模块提供了后台子进程管控接口。开发者可以通过本模块接口对子进程进行压制、解压制，避免子进程过多占用系统资源，导致系统使用卡顿。本模块接口仅对通过[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)接口创建的子进程生效。

>  **说明：**
>
> 本模块首批接口从API version 15开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';
```

## backgroundProcessManager.setProcessPriority

setProcessPriority(pid: number, priority: ProcessPriority): Promise&lt;void&gt;

设置子进程的压制档位，子进程被压制后可获得的CPU资源将会受到限制。如果主进程调度策略发生变化，如从后台切至前台等，子进程会跟随主进程一同变化，子进程如需继续压制，需要重新调用本接口。

**系统能力:** SystemCapability.Resourceschedule.BackgroundProcessManager

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                                                                                                            |
|----------|-------------------------------------| ---- |-------------------------------------------------------------------------------------------------------------------------------|
| pid      | number                              | 是    | 需要被压制子进程的进程号，[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)接口创建子进程后的pid参数，即为子进程进程号。 |
| priority | [ProcessPriority](#processpriority) | 是    | 压制档位。                                                                                                                         |



**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundProcessManager错误码](errorcode-backgroundProcessManager.md)。

| 错误码ID    | 错误信息             |
|----------|------------------|
| 401      | Parameter error. Possible causes: priority is out of range. |
| 31800001 | remote error. Possible causes: remote is not work.    |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';

let childProcessPid = 33333;
try {
    backgroundProcessManager.setProcessPriority(childProcessPid,
        backgroundProcessManager.ProcessPriority.PROCESS_INACTIVE);
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## backgroundProcessManager.resetProcessPriority

resetProcessPriority(pid: number): Promise&lt;void&gt;

为子进程解压制，即子进程策略恢复为主进程调度策略。若主进程调度策略发生变化，如从后台切至前台等， 子进程会跟随主进程一同变化，等效于执行一次resetProcessPriority动作。

**系统能力:** SystemCapability.Resourceschedule.BackgroundProcessManager

**参数**：

| 参数名      | 类型                 | 必填   | 说明                                                                                                                        |
|----------|--------------------| ---- |---------------------------------------------------------------------------------------------------------------------------|
| pid      | number             | 是    | 子进程的进程号，[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)接口创建子进程后的pid参数，即为子进程进程号。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundProcessManager错误码](errorcode-backgroundProcessManager.md)。

| 错误码ID    | 错误信息                                                                                                           |
|----------|----------------------------------------------------------------------------------------------------------------|
| 31800001 | remote error. Possible causes: remote is not work.                                                             |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';

let childProcessPid = 33333;
try {
    backgroundProcessManager.resetProcessPriority(childProcessPid); 
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## ProcessPriority

子进程压制档位。

**系统能力：** SystemCapability.Resourceschedule.BackgroundProcessManager

| 名称                   |  值      | 说明                                                                             |
|----------------------| -------- |--------------------------------------------------------------------------------|
| PROCESS_BACKGROUND   | 1        | 该档位相较PROCESS_INACTIVE压制效果更显著，获取到的CPU资源更少。推荐执行处于后台的图文页面等用户无感知业务的后台子进程时设置该档位。  |
| PROCESS_INACTIVE     | 2        | 推荐正在执行播放音频、导航等用户可感知业务的后台子进程时设置该档位。                                             |

