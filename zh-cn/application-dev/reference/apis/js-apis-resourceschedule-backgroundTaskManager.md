# 后台任务管理

本模块提供后台任务管理能力。

当应用或业务模块处于后台（无可见界面）时，如果有需要继续执行或者后续执行的业务，可基于业务类型，申请短时任务延迟挂起（Suspend）或者长时任务避免进入挂起状态。

应用有不可中断且短时间能完成的任务时（如，用户在文件管理器上点击垃圾文件清理，若清理未完成时退到后台，文件管理器需要申请短时任务完成清理），可以使用短时任务机制。

应用中存在用户能够直观感受到的且需要一直在后台运行的业务时（如，后台播放音乐），可以使用长时任务机制。

对于系统特权应用，提供独立的能效资源申请接口。系统特权应用如果需要使用特定的系统资源，例如在被挂起期间仍然能够收到系统公共事件，可以使用能效资源申请接口。

>  **说明：**
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
```

## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

后台应用申请延迟挂起。

延迟挂起时间一般情况下默认值为3分钟，低电量（依据系统低电量广播）时默认值为1分钟。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 名称      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| reason   | string               | 是    | 延迟挂起申请的原因。                     |
| callback | Callback&lt;void&gt; | 是    | 延迟即将超时的回调函数，一般在超时前6秒通过此回调通知应用。 |

**返回值**：

| 类型                                    | 说明        |
| ------------------------------------- | --------- |
| [DelaySuspendInfo](#delaysuspendinfo) | 返回延迟挂起信息。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**示例**：

  ```js
  import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

  let myReason = 'test requestSuspendDelay';
  try {
    let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
        console.info("Request suspension delay will time out.");
    })
    var id = delayInfo.requestId;
    var time = delayInfo.actualDelayTime;
    console.info("The requestId is: " + id);
    console.info("The actualDelayTime is: " + time);
  } catch (error) {
    console.error(`requestSuspendDelay failed. code is ${error.code} message is ${error.message}`);
  }
  ```


## backgroundTaskManager.getRemainingDelayTime:callback

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

获取应用程序进入挂起状态前的剩余时间，使用callback形式返回。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 名称       | 类型                          | 必填   | 说明                                       |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | 是    | 延迟挂起的请求ID。                               |
| callback  | AsyncCallback&lt;number&gt; | 是    | 指定的callback回调方法。用于返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |


**示例**：

  ```js
  import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

  let id = 1;
  try {
    backgroundTaskManager.getRemainingDelayTime(id, (error, res) => {
        if(error) {
            console.error(`callback => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
        } else {
            console.log('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
        }
    })
  } catch (error) {
    console.error(`callback => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
  }
  ```


## backgroundTaskManager.getRemainingDelayTime:promise

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

获取应用程序进入挂起状态前的剩余时间，使用Promise形式返回。



**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 名称       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 延迟挂起的请求ID。 |

**返回值**：

| 类型                    | 说明                                       |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**示例**：

  ```js
  import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

  let id = 1;
  try {
    backgroundTaskManager.getRemainingDelayTime(id).then( res => {
        console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
    }).catch( error => {
        console.error(`promise => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
    })
  } catch (error) {
    console.error(`promise => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
  }
  ```


## backgroundTaskManager.cancelSuspendDelay

cancelSuspendDelay(requestId: number): void

取消延迟挂起。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 名称       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 延迟挂起的请求ID。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**示例**：

  ```js
  import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

  let id = 1;
  try {
    backgroundTaskManager.cancelSuspendDelay(id);
  } catch (error) {
    console.error(`cancelSuspendDelay failed. code is ${error.code} message is ${error.message}`);
  }
  ```


## backgroundTaskManager.startBackgroundRunning:callback

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

向系统申请长时任务，使用callback形式返回结果。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 名称       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmode) | 是    | 向系统申请的后台模式。                              |
| wantAgent | [WantAgent](js-apis-wantAgent.md)  | 是    | 通知参数，用于指定长时任务通知点击后跳转的界面。                 |
| callback  | AsyncCallback&lt;void&gt;          | 是    | callback形式返回启动长时任务的结果。                   |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import Ability from '@ohos.application.Ability'
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
import wantAgent from '@ohos.wantAgent';

function callback(error, data) {
    if (error) {
        console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
    } else {
        console.info("Operation startBackgroundRunning succeeded");
    }
}

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        let wantAgentInfo = {
            wants: [
                {
                    bundleName: "com.example.myapplication",
                    abilityName: "MainAbility"
                }
            ],
            operationType: wantAgent.OperationType.START_ABILITY,
            requestCode: 0,
            wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
        };

        wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
            try {
                backgroundTaskManager.startBackgroundRunning(this.context,
                    backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj, callback)
            } catch (error) {
                console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
            }
        });
    }
};
```

## backgroundTaskManager.startBackgroundRunning:promise

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;

向系统申请长时任务，使用promise形式返回结果。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 名称       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmode) | 是    | 向系统申请的后台模式。                              |
| wantAgent | [WantAgent](js-apis-wantAgent.md)  | 是    | 通知参数，用于指定长时任务通知点击跳转的界面。                  |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import Ability from '@ohos.application.Ability'
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager'; 
import wantAgent from '@ohos.wantAgent';

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        let wantAgentInfo = {
            wants: [
                {
                    bundleName: "com.example.myapplication",
                    abilityName: "MainAbility"
                }
            ],
            operationType: wantAgent.OperationType.START_ABILITY,
            requestCode: 0,
            wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
        };

        wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
            try {
                backgroundTaskManager.startBackgroundRunning(this.context,
                    backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj).then(() => {
                    console.info("Operation startBackgroundRunning succeeded");
                }).catch((error) => {
                    console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
                });
            } catch (error) {
                console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
            }
        });
    }
};
```

## backgroundTaskManager.stopBackgroundRunning:callback

stopBackgroundRunning(context: Context, callback: AsyncCallback&lt;void&gt;): void

向系统申请取消长时任务，使用callback形式返回结果。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 名称      | 类型                        | 必填   | 说明                                       |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| context  | Context                   | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |
| callback | AsyncCallback&lt;void&gt; | 是    | callback形式返回启动长时任务的结果。                   |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import Ability from '@ohos.application.Ability'
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

function callback(error, data) {
    if (error) {
        console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
    } else {
        console.info("Operation stopBackgroundRunning succeeded");
    }
}

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        try {
            backgroundTaskManager.stopBackgroundRunning(this.context, callback);
        } catch (error) {
            console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
        }
    }
};
```

## backgroundTaskManager.stopBackgroundRunning:promise

stopBackgroundRunning(context: Context): Promise&lt;void&gt;

向系统申请取消长时任务，使用promise形式返回结果。



**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 名称     | 类型      | 必填   | 说明                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| context | Context | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](js-apis-Context.md)。<br>Stage模型的应用Context定义见[Context](js-apis-ability-context.md)。 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed. |
| 9800007 | Task storage failed. |

**示例**：

```js
import Ability from '@ohos.application.Ability'
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        try {
            backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
                console.info("Operation stopBackgroundRunning succeeded");
            }).catch((error) => {
                console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
            });
        } catch (error) {
            console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
        }
    }
};
```

## backgroundTaskManager.applyEfficiencyResources

applyEfficiencyResources(request: [EfficiencyResourcesRequest](#efficiencyresourcesrequest)): void

向系统申请能效资源。
进程和它所属的应用可以同时申请某一类资源，例如CPU资源，但是应用释放资源的时候会将进程的资源一起释放。

**系统能力**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

**参数**：

| 名称     | 类型      | 必填   | 说明                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| request | [EfficiencyResourcesRequest](#efficiencyresourcesrequest) | 是    | 请求的必要信息。包括资源类型，超时时间等信息。详见[EfficiencyResourcesRequest](#efficiencyresourcesrequest)。 |


**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |

**示例**：

```js
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

let request = {
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
    console.error(`applyEfficiencyResources failed. code is ${error.code} message is ${error.message}`);
}
```

## backgroundTaskManager.resetAllEfficiencyResources

resetAllEfficiencyResources(): void

释放所有已经申请的资源。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](../errorcodes/errorcode-backgroundTaskMgr.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | IPC failed. | |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed when applying for efficiency resources. |

**示例**：

```js
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  

try {
    backgroundTaskManager.resetAllEfficiencyResources();
} catch (error) {
    console.error(`resetAllEfficiencyResources failed. code is ${error.code} message is ${error.message}`);
}
```

## DelaySuspendInfo

延迟挂起信息。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| requestId       | number | 是    | 延迟挂起的请求ID。                               |
| actualDelayTime | number | 是    | 应用的实际挂起延迟时间，以毫秒为单位。<br/>一般情况下默认值为180000，低电量（依据系统低电量广播）时默认值为60000。 |


## BackgroundMode

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 名称                     | 值  | 描述                    |
| ----------------------- | ---- | --------------------- |
| DATA_TRANSFER           | 1    | 数据传输。                  |
| AUDIO_PLAYBACK          | 2    | 音频播放。                  |
| AUDIO_RECORDING         | 3    | 录音。                    |
| LOCATION                | 4    | 定位导航。                  |
| BLUETOOTH_INTERACTION   | 5    | 蓝牙相关。                  |
| MULTI_DEVICE_CONNECTION | 6    | 多设备互联。                 |
| WIFI_INTERACTION        | 7    | WLAN相关（此接口为系统接口）。 |
| VOIP                    | 8    | 音视频通话（此接口为系统接口）。  |
| TASK_KEEPING            | 9    | 计算任务（仅在特定设备生效）。        |

## EfficiencyResourcesRequest

能效资源申请参数。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| resourceTypes   | number  | 是    | 申请的资源类型。                               |
| isApply         | boolean | 是    | 申请资源或者是释放资源。          |
| timeOut         | number  | 是    | 资源的使用时间，以毫秒为单位。                |
| isPersist       | boolean | 否    | 是否永久持有资源，如果是true，那么timeOut就无效。    |
| isProcess       | boolean | 否    | 应用申请或者是进程申请。          |
| reason          | string  | 是    | 申请资源的原因。                |

## ResourceType

能效资源类型。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**系统API**: 此接口为系统接口。

| 名称                     | 值  | 描述                    |
| ----------------------- | ---- | --------------------- |
| CPU                     | 1    | CPU资源，申请后不被挂起。             |
| COMMON_EVENT            | 2    | 公共事件，申请后挂起状态下不被代理掉。  |
| TIMER                   | 4    | 计时器，申请后挂起状态下不被代理掉。    |
| WORK_SCHEDULER          | 8    | 延迟任务，申请后有更长的执行时间。      |
| BLUETOOTH               | 16   | 蓝牙相关，申请后挂起状态下不被代理掉。  |
| GPS                     | 32   | GPS相关，申请后挂起状态下不被代理掉。  |
| AUDIO                   | 64   | 音频资源，申请后挂起状态下不被代理掉。 |

