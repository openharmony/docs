# @ohos.resourceschedule.backgroundTaskManager (后台任务管理)

本模块提供申请后台任务的接口。当应用退至后台时，开发者可以通过本模块接口为应用申请短时、长时任务，避免应用进程被终止或挂起。

>  **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
```

## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

申请短时任务。

>  **说明：**
>
> 短时任务的申请和使用过程中的约束与限制请参考[指南](../../task-management/transient-task.md#约束与限制)。

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

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

获取本次短时任务的剩余时间，使用callback异步回调。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名       | 类型                          | 必填   | 说明                                       |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | 是    | 短时任务的请求ID。                               |
| callback  | AsyncCallback&lt;number&gt; | 是    | 回调函数，返回本次短时任务的剩余时间，单位为毫秒。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |


**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

获取本次短时任务的剩余时间，使用promise异步回调。

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

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息 |
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**示例**：

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';

  let id = 1;
  try {
    backgroundTaskManager.cancelSuspendDelay(id);
  } catch (error) {
    console.error(`cancelSuspendDelay failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
  }
  ```

## backgroundTaskManager.startBackgroundRunning

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

申请长时任务，使用callback异步回调。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmode) | 是    | 长时任务类型。                              |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是    | 通知参数，用于指定点击长时任务通知后跳转的界面。           |
| callback  | AsyncCallback&lt;void&gt;          | 是    | 回调函数，申请长时任务成功时，err为undefined，否则为错误对象。    |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. | 
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. | 
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

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
            actionType: wantAgent.OperationType.START_ABILITY,
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

申请长时任务，使用promise异步回调。在一个长时任务中仅能申请一种类型。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmode) | 是    | 长时任务类型。                              |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是    | 通知参数，用于指定点击长时任务通知后跳转的界面。                 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. | 
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

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
            actionType: wantAgent.OperationType.START_ABILITY,
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

取消长时任务，使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名      | 类型                        | 必填   | 说明                                       |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| context  | Context                   | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，取消长时任务成功时，err为undefined，否则为错误对象。|

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

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

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名     | 类型      | 必填   | 说明                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| context | Context | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

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

## backgroundTaskManager.startBackgroundRunning<sup>12+</sup>

startBackgroundRunning(context: Context, bgModes: string[], wantAgent: WantAgent): Promise&lt;ContinuousTaskNotification&gt;

申请长时任务，使用promise异步回调。支持在一个长时任务中可以申请多种类型。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | 是    | 应用运行的上下文。 |
| bgModes    | string[] | 是    | 长时任务类型，支持的类型请参考[BackgroundMode](#backgroundmode)。<br> **说明** ：支持传入一个或多个类型。|
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是    | 通知参数，用于指定点击长时任务通知后跳转的界面。                 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<ContinuousTaskNotification> | 返回[ContinuousTaskNotification](#continuoustasknotification12)类型的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
import { notificationManager } from '@kit.NotificationKit';

export default class EntryAbility extends UIAbility {
  id: number = 0; // 保存通知id

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
      actionType: wantAgent.OperationType.START_ABILITY,
      // 使用者自定义的一个私有值
      requestCode: 0,
      // 点击通知后，动作执行属性
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    try {
      // 通过wantAgent模块下getWantAgent方法获取WantAgent对象
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
        try {
          let list: Array<string> = ["dataTransfer"];
          backgroundTaskManager.startBackgroundRunning(this.context, list, wantAgentObj).then((res: backgroundTaskManager.ContinuousTaskNotification) => {
            console.info("Operation startBackgroundRunning succeeded");
            // 对于上传下载类的长时任务，应用可以使用res中返回的notificationId来更新通知，比如发送带进度条的模板通知。
            this.id = res.notificationId;
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

  updateProcess(process: Number) {
    // 应用定义下载类通知模版
    let downLoadTemplate: notificationManager.NotificationTemplate = {
      name: 'downloadTemplate', // 当前只支持downloadTemplate，保持不变
      data: {
        title: '文件下载：music.mp4', // 必填。
        fileName: 'senTemplate', // 必填。
        progressValue: process, // 应用更新进度值，自定义。
      }
    };
    let request: notificationManager.NotificationRequest = {
      content: {
        // 系统实况类型，保持不变
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW,
        systemLiveView: {
          typeCode: 8, // 上传下载类型需要填写 8，当前仅支持此类型。保持不变
          title: "test", // 应用自定义
          text: "test", // 应用自定义
        }
      },
      id: this.id, // 必须是申请长时任务返回的id，否则应用更新通知失败。
      notificationSlotType: notificationManager.SlotType.LIVE_VIEW, // 实况窗类型，保持不变
      template: downLoadTemplate // 应用需要设置的模版名称
    };

    try {
      notificationManager.publish(request).then(() => {
        console.info("publish success, id= " + this.id);
      }).catch((err: BusinessError) => {
        console.error(`publish fail: ${JSON.stringify(err)}`);
      });
    } catch (err) {
      console.error(`publish fail: ${JSON.stringify(err)}`);
    }
  }
};
```
## backgroundTaskManager.updateBackgroundRunning<sup>12+</sup>

updateBackgroundRunning(context: Context, bgModes: string[]): Promise&lt;ContinuousTaskNotification&gt;

更新长时任务类型，使用promise异步回调。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名       | 类型                                 | 必填   | 说明                                       |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | 是    | 应用运行的上下文。 |
| bgModes    | string[] | 是    | 更新后的长时任务类型，支持的类型请参考[BackgroundMode](#backgroundmode)。<br> **说明** ：支持传入一个或多个类型。 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<ContinuousTaskNotification> | 返回[ContinuousTaskNotification](#continuoustasknotification12)类型的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[backgroundTaskManager错误码](errorcode-backgroundTaskMgr.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID  | 错误信息             |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Parcel operation failed. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**示例**：

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        try {
                try {
                    // 必须先执行startBackgroundRunning，才能调用updateBackgroundRunning。这里假设已经申请过。
                    let list: Array<string> = ["audioPlayback"];
                    backgroundTaskManager.updateBackgroundRunning(this.context, list).then(() => {
                        console.info("Operation updateBackgroundRunning succeeded");
                    }).catch((error: BusinessError) => {
                        console.error(`Operation updateBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
                    });
                } catch (error) {
                    console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
                }
        } catch (error) {
            console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
    }
};
```

## DelaySuspendInfo

短时任务信息。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| requestId       | number | 是    | 短时任务的请求ID。                               |
| actualDelayTime | number | 是    | 应用实际申请的短时任务时间，单位为毫秒。<br/> **说明** ：申请时间最长为3分钟，[低电量](../apis-basic-services-kit/js-apis-battery-info.md)时最长为1分钟。 |

## BackgroundMode

长时任务模式。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 名称                     | 值  | 说明                    |
| ----------------------- | ---- | --------------------- |
| DATA_TRANSFER           | 1    | 数据传输。                  |
| AUDIO_PLAYBACK          | 2    | 音频播放。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                  |
| AUDIO_RECORDING         | 3    | 录制。                    |
| LOCATION                | 4    | 定位导航。                  |
| BLUETOOTH_INTERACTION   | 5    | 蓝牙相关。                  |
| MULTI_DEVICE_CONNECTION | 6    | 多设备互联。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                 |
| VOIP<sup>13+</sup> | 8    | 音视频通话。                 |
| TASK_KEEPING            | 9    | 计算任务（仅对2in1开放）。        |

## ContinuousTaskNotification<sup>12+</sup>

长时任务通知信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| slotType       | [notificationManager.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | 是    | 长时任务通知的渠道类型。|
| contentType | [notificationManager.ContentType](../apis-notification-kit/js-apis-notificationManager.md#contenttype) | 是    | 长时任务通知的内容类型。|
| notificationId | number | 是    | 长时任务通知 Id。|