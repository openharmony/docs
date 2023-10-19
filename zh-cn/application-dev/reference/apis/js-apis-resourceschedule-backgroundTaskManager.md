# @ohos.resourceschedule.backgroundTaskManager (后台任务管理)

本模块提供申请后台任务的接口。当应用退至后台时，开发者可以通过本模块接口为应用申请短时、长时任务，避免应用进程被终止或挂起。

>  **说明：**
> 
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
```

## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

申请短时任务。

>  **说明：**
> 
> 短时任务的申请时间最长为3分钟，[低电量](js-apis-battery-info.md)时最长为1分钟。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| reason   | string               | 是    | 申请短时任务的原因。                     |
| callback | Callback&lt;void&gt; | 是    | 短时任务即将超时的回调函数，一般在超时前6秒，通过此回调通知应用。 |

**返回值**：

| 类型                                    | 说明        |
| ------------------------------------- | --------- |
| [DelaySuspendInfo](#delaysuspendinfo) | 返回短时任务信息。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed. |
| 9900002 | Background task verification failed. |

**示例**：

```ts 
import { BusinessError } from '@ohos.base';

let myReason = 'test requestSuspendDelay';
try {
let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
    console.info("Request suspension delay will time out.");
})
let id = delayInfo.requestId;
let time = delayInfo.actualDelayTime;
console.info("The requestId is: " + id);
console.info("The actualDelayTime is: " + time);
} catch (error) {
console.error(`requestSuspendDelay failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

获取本次短时任务的剩余时间。使用callback异步回调。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名       | 类型                          | 必填   | 说明                                       |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | 是    | 短时任务的请求ID。                               |
| callback  | AsyncCallback&lt;number&gt; | 是    | 回调函数，返回本次短时任务的剩余时间，单位为毫秒。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed.  |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed. |
| 9900002 | Background task verification failed. |


**示例**：

```ts 
import { BusinessError } from '@ohos.base';

let id = 1;
backgroundTaskManager.getRemainingDelayTime(id, (error: BusinessError, res: number) => {
    if(error) {
        console.error(`callback => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
    } else {
        console.log('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
    }
})
```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

获取本次短时任务的剩余时间。使用promise异步回调。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 短时任务的请求ID。 |

**返回值**：

| 类型                    | 说明                                       |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回本次短时任务的剩余时间，单位为毫秒。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed. |
| 9900002 | Background task verification failed. |

**示例**：

```ts 
import { BusinessError } from '@ohos.base';

let id = 1;
backgroundTaskManager.getRemainingDelayTime(id).then((res: number) => {
    console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
}).catch((error: BusinessError) => {
    console.error(`promise => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
})
```


## backgroundTaskManager.cancelSuspendDelay

cancelSuspendDelay(requestId: number): void

取消短时任务。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 短时任务的请求ID。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed. |
| 9900002 | Background task verification failed. |

**示例**：

  ```js
  import { BusinessError } from '@ohos.base';

  let id = 1;
  try {
    backgroundTaskManager.cancelSuspendDelay(id);
  } catch (error) {
    console.error(`cancelSuspendDelay failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
  }
  ```

## backgroundTaskManager.startBackgroundRunning

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

申请长时任务。使用callback异步回调。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmode) | 是    | 长时任务模式。                              |
| wantAgent | [WantAgent](js-apis-app-ability-wantAgent.md) | 是    | 通知参数，用于指定点击长时任务通知后跳转的界面。           |
| callback  | AsyncCallback&lt;void&gt;          | 是    | 回调函数，申请长时任务成功时，err为undefined，否则为错误对象。    |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Background task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: void) {
    if (error) {
        console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
    } else {
        console.info("Operation startBackgroundRunning succeeded");
    }
}

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        let wantAgentInfo: wantAgent.WantAgentInfo = {
            // 点击通知后，将要执行的动作列表
            wants: [
                {
                    bundleName: "com.example.myapplication",
                    abilityName: "EntryAbility"
                }
            ],
            // 点击通知后，动作类型
            operationType: wantAgent.OperationType.START_ABILITY,
            // 使用者自定义的一个私有值
            requestCode: 0,
            // 点击通知后，动作执行属性
            wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
        };

        try {
            // 通过wantAgent模块下getWantAgent方法获取WantAgent对象
            wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
                try {
                    backgroundTaskManager.startBackgroundRunning(this.context,
                        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj, callback)
                } catch (error) {
                    console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
                }
            });
        } catch (error) {
            console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
    }
};
```

## backgroundTaskManager.startBackgroundRunning

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;

申请长时任务，使用promise异步回调。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmode) | 是    | 长时任务模式。                              |
| wantAgent | [WantAgent](js-apis-app-ability-wantAgent.md) | 是    | 通知参数，用于指定点击长时任务通知后跳转的界面。                 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Background task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager'; 
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        let wantAgentInfo: wantAgent.WantAgentInfo = {
            // 点击通知后，将要执行的动作列表
            wants: [
                {
                    bundleName: "com.example.myapplication",
                    abilityName: "EntryAbility"
                }
            ],
            // 点击通知后，动作类型
            operationType: wantAgent.OperationType.START_ABILITY,
            // 使用者自定义的一个私有值
            requestCode: 0,
            // 点击通知后，动作执行属性
            wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
        };

        try {
            // 通过wantAgent模块下getWantAgent方法获取WantAgent对象
            wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
                try {
                    backgroundTaskManager.startBackgroundRunning(this.context,
                        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj).then(() => {
                        console.info("Operation startBackgroundRunning succeeded");
                    }).catch((error: BusinessError) => {
                        console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
                    });
                } catch (error) {
                    console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
                }
            });
        } catch (error) {
            console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
    }
};
```

## backgroundTaskManager.stopBackgroundRunning

stopBackgroundRunning(context: Context, callback: AsyncCallback&lt;void&gt;): void

取消长时任务。使用callback异步回调。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名      | 类型                        | 必填   | 说明                                       |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| context  | Context                   | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，取消长时任务成功时，err为undefined，否则为错误对象。|

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Background task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: void) {
    if (error) {
        console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
    } else {
        console.info("Operation stopBackgroundRunning succeeded");
    }
}

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        try {
            backgroundTaskManager.stopBackgroundRunning(this.context, callback);
        } catch (error) {
            console.error(`Operation stopBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
    }
};
```

## backgroundTaskManager.stopBackgroundRunning

stopBackgroundRunning(context: Context): Promise&lt;void&gt;

取消长时任务，使用promise异步回调。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名     | 类型      | 必填   | 说明                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| context | Context | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-inner-application-context.md)。 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Background task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        try {
            backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
                console.info("Operation stopBackgroundRunning succeeded");
            }).catch((error: BusinessError) => {
                console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
            });
        } catch (error) {
            console.error(`Operation stopBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
    }
};
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

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed. |

**示例**：

```js
import { BusinessError } from '@ohos.base';

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

以下错误码的详细介绍请参见[backgroundTaskManager错误码](../errorcodes/errorcode-backgroundTaskMgr.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Inner transact failed. | |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed. |

**示例**：

```js
import { BusinessError } from '@ohos.base';

try {
    backgroundTaskManager.resetAllEfficiencyResources();
} catch (error) {
    console.error(`resetAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## DelaySuspendInfo

短时任务信息。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| requestId       | number | 是    | 短时任务的请求ID。                               |
| actualDelayTime | number | 是    | 应用实际申请的短时任务时间，单位为毫秒。<br/>短时任务申请时间最长为3分钟，[低电量](js-apis-battery-info.md)时最长为1分钟。 |

## BackgroundMode

长时任务模式。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 名称                     | 值  | 说明                    |
| ----------------------- | ---- | --------------------- |
| DATA_TRANSFER           | 1    | 数据传输。                  |
| AUDIO_PLAYBACK          | 2    | 音频播放。                  |
| AUDIO_RECORDING         | 3    | 录音。                    |
| LOCATION                | 4    | 定位导航。                  |
| BLUETOOTH_INTERACTION   | 5    | 蓝牙相关。                  |
| MULTI_DEVICE_CONNECTION | 6    | 多设备互联。                 |
| WIFI_INTERACTION        | 7    | WLAN相关。<br>**系统API**: 此接口为系统接口。 |
| VOIP                    | 8    | 音视频通话。<br>**系统API**: 此接口为系统接口。 |
| TASK_KEEPING            | 9    | 计算任务（仅对特定设备开放）。        |

## EfficiencyResourcesRequest

能效资源申请参数。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| resourceTypes   | number  | 是    | 申请的资源类型。                               |
| isApply         | boolean | 是    | 申请或释放资源。<br>- true表示申请资源，false表示释放部分资源。 |
| timeOut         | number  | 是    | 资源使用时间，单位为毫秒。                |
| isPersist       | boolean | 否    | 是否永久持有资源，默认为false。<br>- true表示永久持有，false表示有限时间内持有。|
| isProcess       | boolean | 否    | 进程或应用申请，默认为false。<br>- true表示进程申请，false表示应用申请。         |
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
