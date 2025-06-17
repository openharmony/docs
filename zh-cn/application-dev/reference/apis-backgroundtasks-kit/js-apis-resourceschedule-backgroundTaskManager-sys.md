# @ohos.resourceschedule.backgroundTaskManager (后台任务管理)(系统接口)

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
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed for an energy resource request. |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';

let request: backgroundTaskManager.EfficiencyResourcesRequest = {
    resourceTypes: backgroundTaskManager.ResourceType.CPU,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true,
    isProcess: false,
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
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed for an energy resource request. |

**示例**：

```js
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

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| resourceTypes   | number  | 是    | 申请的资源类型。                               |
| isApply         | boolean | 是    | 申请或释放资源。<br>- true表示申请资源。<br>- false表示释放部分资源。 |
| timeOut         | number  | 是    | 资源使用时间，单位为毫秒。                |
| isPersist       | boolean | 否    | 是否永久持有资源，默认为false。<br>- true表示永久持有。<br>- false表示有限时间内持有。|
| isProcess       | boolean | 否    | 进程或应用申请，默认为false。<br>- true表示进程申请。<br>- false表示应用申请。         |
| reason          | string  | 是    | 申请资源原因。                |

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
| SENSOR<sup>10+</sup> | 256 | 申请后不拦截Sensor回调。 |

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