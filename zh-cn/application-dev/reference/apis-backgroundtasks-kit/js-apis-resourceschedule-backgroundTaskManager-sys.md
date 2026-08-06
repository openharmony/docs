# @ohos.resourceschedule.backgroundTaskManager (后台任务管理)(系统接口)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->

本模块提供申请后台任务的接口。当应用退至后台时，开发者可以通过本模块接口为应用申请短时、长时任务，避免应用进程被终止或挂起。

>  **说明：**
> 
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - 当前页面仅包含本模块的系统接口，其他公开接口请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](js-apis-resourceschedule-backgroundTaskManager.md)。

## 导入模块

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';  
```

## backgroundTaskManager.applyEfficiencyResources

applyEfficiencyResources(request: EfficiencyResourcesRequest): void

申请能效资源。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

**参数**：

| 参数名     | 类型      | 必填   | 说明                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| request | [EfficiencyResourcesRequest](#efficiencyresourcesrequest) | 是    | 请求的必要信息，包括资源类型、超时时间等。 |


**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed for an energy resource request. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';  
import { BusinessError } from '@kit.BasicServicesKit';

let request: backgroundTaskManager.EfficiencyResourcesRequest = {
    resourceTypes: backgroundTaskManager.ResourceType.CPU,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true,
    isProcess: false,
    cpuLevel: backgroundTaskManager.EfficiencyResourcesCpuLevel.SMALL_CPU // 运行在小核，从API version 23开始支持。
};
try {
    backgroundTaskManager.applyEfficiencyResources(request);
    console.info("applyEfficiencyResources success. ");
} catch (error) {
    console.error(`applyEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.resetAllEfficiencyResources

resetAllEfficiencyResources(): void

释放已申请的全部能效资源。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. Possible causes: 1. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed for an energy resource request. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';  
import { BusinessError } from '@kit.BasicServicesKit';

try {
    backgroundTaskManager.resetAllEfficiencyResources();
} catch (error) {
    console.error(`resetAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.getAllEfficiencyResources<sup>20+</sup>

getAllEfficiencyResources(): Promise&lt;EfficiencyResourcesInfo[]&gt;

获取已申请的所有能效资源信息，如能效资源类型等，使用Promise异步回调。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

**返回值**：

| 类型                                            | 说明          |
|-----------------------------------------------|-------------|
|  Promise&lt;[EfficiencyResourcesInfo](#efficiencyresourcesinfo20)[]&gt; | Promise对象，返回所有能效资源信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 202 | Not System App. |
| 18700001 | Caller information verification failed for an energy resource request. |
| 18700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 18700004 | System service operation failed. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    backgroundTaskManager.getAllEfficiencyResources().then((res: backgroundTaskManager.EfficiencyResourcesInfo[]) => {
        console.info(`Operation getAllEfficiencyResources succeeded. data: ` + JSON.stringify(res));
    }).catch((error : BusinessError) => {
        console.error(`Operation getAllEfficiencyResources failed. code is ${error.code} message is ${error.message}`);
    });
} catch (error) {
    console.error(`Operation getAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.setBackgroundTaskState<sup>22+</sup>

setBackgroundTaskState(stateInfo: BackgroundTaskStateInfo): void

设置长时任务授权信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**: ohos.permission.SET_BACKGROUND_TASK_STATE

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**参数**：

| 参数名     | 类型      | 必填   | 说明                    |
| ------- | ------- | ---- |-----------------------|
| stateInfo | [BackgroundTaskStateInfo](#backgroundtaskstateinfo22) | 是    | 授权的必要信息，包括用户ID、应用包名、应用分身ID等。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // 请开发者根据实际情况更新参数
    let backgroundTaskStateInfo: backgroundTaskManager.BackgroundTaskStateInfo = {
        userId: 100,
        bundleName: 'com.example.continuoustask',
        appIndex: 0,
        authResult: backgroundTaskManager.UserAuthResult.DENIED
    };
    backgroundTaskManager.setBackgroundTaskState(backgroundTaskStateInfo);
    console.info('Operation setBackgroundTaskState succeeded.');
} catch (error) {
    console.error(`Operation setBackgroundTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.getBackgroundTaskState<sup>22+</sup>

getBackgroundTaskState(stateInfo: BackgroundTaskStateInfo): UserAuthResult

获取长时任务授权信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**: ohos.permission.SET_BACKGROUND_TASK_STATE

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**参数**：

| 参数名     | 类型      | 必填   | 说明                    |
| ------- | ------- | ---- |-----------------------|
| stateInfo | [BackgroundTaskStateInfo](#backgroundtaskstateinfo22) | 是    | 授权的必要信息，包括用户ID、应用包名、应用分身ID等。 |

**返回值**：

| 类型                                            | 说明          |
|-----------------------------------------------|-------------|
|  [UserAuthResult](./js-apis-resourceschedule-backgroundTaskManager.md#userauthresult22) | 授权结果。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // 请开发者根据实际情况更新参数
    let backgroundTaskStateInfo: backgroundTaskManager.BackgroundTaskStateInfo = {
        userId: 100,
        bundleName: 'com.example.continuoustask',
        appIndex: 0
    };
    let auth = backgroundTaskManager.getBackgroundTaskState(backgroundTaskStateInfo);
    console.info('Operation getBackgroundTaskState succeeded. data: ' + JSON.stringify(auth));
} catch (error) {
    console.error(`Operation getBackgroundTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.obtainAllContinuousTasks<sup>23+</sup>

obtainAllContinuousTasks(): Promise&lt;ContinuousTaskInfo[]&gt;

获取所有长时任务信息，如长时任务ID、长时任务类型等。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**: ohos.permission.GET_BACKGROUND_TASK_INFO

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**返回值**：

| 类型                                            | 说明          |
|-----------------------------------------------|-------------|
|  Promise&lt;[ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20)[]&gt; | Promise对象，返回所有长时任务信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 9800004 | System service operation failed. |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // 如果当前没有申请长时任务，则获取到一个空数组
    backgroundTaskManager.obtainAllContinuousTasks().then((res: backgroundTaskManager.ContinuousTaskInfo[]) => {
        console.info(`Operation obtainAllContinuousTasks succeeded. data: ` + JSON.stringify(res));
    }).catch((error: BusinessError) => {
        console.error(`Operation obtainAllContinuousTasks failed. code is ${error.code} message is ${error.message}`);
    });
} catch (error) {
    console.error(`Operation obtainAllContinuousTasks failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.subscribeContinuousTaskState<sup>23+</sup>

subscribeContinuousTaskState(subscriber: BackgroundTaskSubscriber): void

注册长时任务变化回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**: ohos.permission.GET_BACKGROUND_TASK_INFO

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**参数**：

| 参数名     | 类型      | 必填   | 说明                    |
| ------- | ------- | ---- |-----------------------|
| subscriber | [BackgroundTaskSubscriber](#backgroundtasksubscriber23) | 是    | 后台任务监听对象，包含长时任务开始，长时任务更新，长时任务结束。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID   | 错误信息 |
|---------| ------- |
| 201     | Permission denied. |
| 202     | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}

try {
    backgroundTaskManager.subscribeContinuousTaskState(backgroundTaskSubscriber);
    console.info('Operation subscribeContinuousTaskState succeeded');
} catch (error) {
    console.error(`Operation subscribeContinuousTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.unsubscribeContinuousTaskState<sup>23+</sup>

unsubscribeContinuousTaskState(subscriber: BackgroundTaskSubscriber): void

解注册长时任务变化回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限**: ohos.permission.GET_BACKGROUND_TASK_INFO

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**参数**：

| 参数名     | 类型      | 必填   | 说明                    |
| ------- | ------- | ---- |-----------------------|
| subscriber | [BackgroundTaskSubscriber](#backgroundtasksubscriber23) | 是    | 后台任务监听对象，包含长时任务开始，长时任务更新，长时任务结束。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)。

| 错误码ID   | 错误信息 |
|---------| ------- |
| 201     | Permission denied. |
| 202     | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}

try {
    backgroundTaskManager.unsubscribeContinuousTaskState(backgroundTaskSubscriber);
    console.info('Operation unsubscribeContinuousTaskState succeeded');
} catch (error) {
    console.error(`Operation unsubscribeContinuousTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## BackgroundMode

长时任务模式。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 名称                     | 值  | 说明                    |
| ----------------------- | ---- | --------------------- |
| WIFI_INTERACTION        | 7    | WLAN相关。<br>**系统API**: 此接口为系统接口。 |

## EfficiencyResourcesRequest

能效资源申请参数。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

| 名称             | 类型     | 只读   | 可选   | 说明                                       |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| resourceTypes   | number  | 否    | 否    | 申请的资源类型。                               |
| isApply         | boolean | 否    | 否    | 申请或释放资源。<br>- true表示申请资源。<br>- false表示释放部分资源。 |
| timeOut         | number  | 否    | 否    | 资源使用时间，单位：ms。                |
| isPersist       | boolean | 否    | 是    | 是否永久持有资源，默认为false。<br>- true表示永久持有。<br>- false表示有限时间内持有。|
| isProcess       | boolean | 否    | 是    | 进程或应用申请，默认为false。<br>- true表示进程申请。<br>- false表示应用申请。         |
| reason          | string  | 否    | 否    | 申请资源原因。                |
| cpuLevel<sup>23+</sup> | [EfficiencyResourcesCpuLevel](#efficiencyresourcescpulevel23) | 否    | 是    | 指定CPU级别，能效资源类型resourceTypes为CPU时该参数用于指定CPU资源大小，系统会在负载空闲时间（例如灭屏场景）分配指定的CPU资源给应用。 |

## ResourceType

能效资源类型。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

| 名称                     | 值  | 说明                    |
| ----------------------- | ---- | --------------------- |
| CPU                     | 1    | CPU资源，申请后应用进程不被挂起。             |
| COMMON_EVENT            | 2    | 公共事件资源，申请后应用进程被挂起后，可以收到公共事件。 |
| TIMER                   | 4    | 计时器，申请后应用进程被挂起后，Timer仍然可以唤醒应用。 |
| WORK_SCHEDULER          | 8    | 延迟任务资源，申请后延迟任务管控变宽松。 |
| BLUETOOTH               | 16   | 蓝牙资源，申请后应用进程被挂起后，蓝牙相关事件仍然可以唤醒应用。 |
| GPS                     | 32   | GPS资源，申请后应用进程被挂起后，GPS相关事件可以唤醒应用。 |
| AUDIO                   | 64   | 音频资源，有音频播放时对应的应用进程不被挂起。 |
| RUNNING_LOCK<sup>10+</sup> | 128 | RUNNING_LOCK资源，申请后挂起状态不会代理RUNNING_BACKGROUND锁。 |
| SENSOR<sup>10+</sup> | 256 | 申请后不拦截SENSOR回调。 |

## EfficiencyResourcesInfo<sup>20+</sup>

能效资源信息。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

| 名称                             | 类型      | 只读   | 可选   | 说明          |
|--------------------------------|---------| ---- | ---- |-------------|
| [resourceTypes](#resourcetype) | number  | 否    | 否    | 能效资源类型。     |
| timeout                        | number  | 否    | 否    | 超时时间，单位：ms。 |
| isPersistent                   | boolean | 否    | 否    | 是否永久持有资源，默认为false。取值为true表示永久持有。取值为false表示有限时间内持有。      |
| isForProcess                   | boolean | 否    | 否    | 进程或应用申请，取值为true表示进程申请。取值为false表示应用申请。   |
| reason                         | string  | 否    | 否    | 申请资源原因。       |
| uid                            | number  | 否    | 否    | 应用的UID。     |
| pid                            | number  | 否    | 否    | 应用进程的PID。   |
| cpuLevel<sup>23+</sup>         | [EfficiencyResourcesCpuLevel](#efficiencyresourcescpulevel23)  | 否    | 是    |  指定CPU级别，能效资源类型resourceTypes为CPU时该参数用于指定CPU资源大小，系统会在负载空闲时间（例如灭屏场景）分配指定的CPU资源给应用。 |

## EfficiencyResourcesCpuLevel<sup>23+</sup>

能效资源CPU级别。

**系统能力：** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统接口：** 此接口为系统接口。

| 名称                      | 值  | 说明                    |
| ------------------------ | ---- | ---------------------  |
| SMALL_CPU | 0 | 表示运行在小核，用于处理轻量级后台任务，CPU频点较低。 |
| MEDIUM_CPU | 1 | 表示最高可以运行在中核，系统基于负载决策运行在小核或中核。平衡性能与能效，用于需要处理复杂任务的场景，CPU频点高。 |
| LARGE_CPU | 2 | 表示最高可以运行在大核，系统基于负载决策运行在小核、中核或大核。 极致性能，用于应对重载任务的场景，CPU频点最高。 |

## BackgroundTaskMode<sup>21+</sup>

长时任务主类型。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

| 名称                     | 值  | 说明                    |
| ------------------------ | ---- | --------------------- |
| MODE_ALLOW_WIFI_AWARE           | 7         | WLAN相关业务。            |

## BackgroundTaskStateInfo<sup>22+</sup>

长时任务授权信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

| 名称 | 类型                                  | 只读   | 可选 | 说明      |
|--|-------------------------------------| ---- |----|---------|
| userId | number                              | 否    | 否  | 用户ID。   |
| bundleName | string                              | 否    | 否  | 应用包名。   |
| appIndex | number                              | 否    | 否  | 应用分身ID。 |
| authResult | [UserAuthResult](./js-apis-resourceschedule-backgroundTaskManager.md#userauthresult22) | 否    | 是  | 授权结果。   |

## BackgroundTaskSubscriber<sup>23+</sup>

后台任务监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

### onContinuousTaskStart<sup>23+</sup>

onContinuousTaskStart(info: ContinuousTaskInfo): void

长时任务开始回调接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**参数**：

| 参数名  | 类型      | 必填   | 说明                |
|------| ------- | ---- |-------------------|
| info | [ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20) | 是    | 长时任务回调信息，长时任务ID、长时任务类型等。 |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}
```

### onContinuousTaskUpdate<sup>23+</sup>

onContinuousTaskUpdate(info: ContinuousTaskInfo): void

长时任务更新回调接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**参数**：

| 参数名  | 类型      | 必填   | 说明                |
|------| ------- | ---- |-------------------|
| info | [ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20) | 是    | 长时任务回调信息，长时任务ID、长时任务类型等。 |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}
```

### onContinuousTaskStop<sup>23+</sup>

onContinuousTaskStop(info: ContinuousTaskInfo): void

长时任务结束回调接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**系统API**: 此接口为系统接口。

**参数**：

| 参数名  | 类型      | 必填   | 说明                |
|------| ------- | ---- |-------------------|
| info | [ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20) | 是    | 长时任务回调信息，长时任务ID、长时任务类型等。 |

**示例**：

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}
```