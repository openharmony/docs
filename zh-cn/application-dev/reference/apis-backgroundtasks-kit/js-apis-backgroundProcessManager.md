# @ohos.resourceschedule.backgroundProcessManager (后台子进程管控)

本模块提供了后台子进程管控接口。开发者可以通过本模块接口对子进程进行压制、解压制，避免子进程过多占用系统资源，导致系统使用卡顿。本模块接口仅对通过[OH_Ability_StartNativeChildProcess、OH_Ability_CreateNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md)接口创建的子进程生效。

>  **说明：**
>
> 本模块首批接口从API version 17开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';
```

## backgroundProcessManager.setProcessPriority

function setProcessPriority(pid: number, priority: ProcessPriority): Promise&lt;void&gt;

设置子进程的压制档位，子进程被压制后可获得的CPU资源将会受到限制。如果主进程调度策略发生变化，如从后台切至前台等，子进程会跟随主进程一同变化，子进程如需继续压制，需要重新调用本接口。

**系统能力:** SystemCapability.Resourceschedule.BackgroundProcessManager

**参数**：

| 参数名      | 类型                                      | 必填   | 说明                                                                                                                                                              |
|----------|-----------------------------------------| ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| pid      | number                                  | 是    | 需要被压制子进程的进程号，获取方式可参考[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md)接口最后一个参数，即启动子进程号。 |
| priority | [ProcessPriority](#ProcessPriority压制档位) | 是    | 压制档位。                                                                                                                                                           |



**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundProcessManager错误码](errorcode-backgroundProcessManager.md)。

| 错误码ID    | 错误信息             |
|----------|------------------|
| 401      | Parameter error. |
| 31800001 | remote error.    |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManaer } from '@kit.BackgroundTasksKit';

let childProcessPid = 33333;
try {
    backgroundProcessManaer.setProcessPriority(childProcessPid,
        backgroundProcessManaer.ProcessPriority.PROCESS_INACTIVE);
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```
创建子进程方法可参考[子进程创建方法](../apis-ability-kit/c-apis-ability-childprocess.md)


## backgroundProcessManager.resetProcessPriority

function resetProcessPriority(pid: number): Promise&lt;void&gt;


为子进程解压制，即子进程策略恢复为主进程调度策略。若主进程调度策略发生变化，如从后台切至前台等， 子进程会跟随主进程一同变化，等效于执行一次resetProcessPriority动作。

**系统能力:** SystemCapability.Resourceschedule.BackgroundProcessManager

**参数**：

| 参数名      | 类型                 | 必填   | 说明       |
|----------|--------------------| ---- |----------|
| pid      | number             | 是    | 子进程的进程号，获取方式可参考[OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md)接口最后一个参数，即启动子进程号。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundProcessManager错误码](errorcode-backgroundProcessManager.md)。

| 错误码ID    | 错误信息                                                                                                           |
|----------|----------------------------------------------------------------------------------------------------------------|
| 31800001 | remote error.                                                                                                  |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManaer } from '@kit.BackgroundTasksKit';

let childProcessPid = 33333;
try {
    backgroundProcessManaer.resetProcessPriority(childProcessPid);
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

# 枚举类型说明
## backgroundProcessManager错误码

> **说明：**
> 
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)

### 31800001 服务端异常

**错误信息**

remote error.

**错误描述**

客户端进程请求系统服务进程，获取系统服务操作失败。

**可能原因**

1. 系统服务还未启动
2. 系统服务异常

**处理步骤**

请稍后（1S）重试

## ProcessPriority压制档位

```
enum ProcessPriority
```

**描述**

定义子进程压制档位

**起始版本**：17

| 枚举值                                 | 描述            |
| ----------------------------------- |---------------|
| PROCESS_BACKGROUND | 进程处于后台，用户无感知。 |
| PROCESS_INACTIVE | 进程处于后台，用户可感知，例如后台播放音频、导航等。           |

