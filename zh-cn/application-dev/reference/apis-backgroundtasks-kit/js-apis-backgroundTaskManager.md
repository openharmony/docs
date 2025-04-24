# @ohos.backgroundTaskManager (后台任务管理)

本模块提供后台任务管理能力。

当应用或业务模块处于后台（无可见界面）时，如果有需要继续执行或者后续执行的业务，可基于业务类型，申请短时任务延迟挂起（Suspend）或者长时任务避免进入挂起状态。

应用有不可中断且短时间能完成的任务时（如，用户在文件管理器上点击垃圾文件清理，若清理未完成时退到后台，文件管理器需要申请短时任务完成清理），可以使用短时任务机制。

应用中存在用户能够直观感受到的且需要一直在后台运行的业务时（如，后台播放音乐），可以使用长时任务机制。


>  **说明：**
>
> - 从API Version 9 开始，该接口不再维护，推荐使用新接口[@ohos.resourceschedule.backgroundTaskManager (后台任务管理)](js-apis-resourceschedule-backgroundTaskManager.md)。
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```


## backgroundTaskManager.requestSuspendDelay<sup>(deprecated)</sup>

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

后台应用申请延迟挂起。

延迟挂起时间一般情况下默认值为3分钟，低电量（依据系统低电量广播）时默认值为1分钟。

> **说明：**
> 从API version 7开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.requestSuspendDelay](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerrequestsuspenddelay)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| reason   | string               | 是    | 延迟挂起申请的原因。                     |
| callback | Callback&lt;void&gt; | 是    | 延迟即将超时的回调函数，一般在超时前6秒通过此回调通知应用。 |

**返回值**：

| 类型                                    | 说明        |
| ------------------------------------- | --------- |
| [DelaySuspendInfo](#delaysuspendinfodeprecated) | 返回延迟挂起信息。 |

**示例**：

  ```ts
  import backgroundTaskManager from '@ohos.backgroundTaskManager';
  import { BusinessError } from '@ohos.base';
  
  // 设置延迟任务挂起的原因
  let myReason = 'test requestSuspendDelay';
  // 申请延迟任务
  let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
      console.info("Request suspension delay will time out.");
  })
  // 打印延迟任务信息
  let id = delayInfo.requestId;
  let time = delayInfo.actualDelayTime;
  console.info("The requestId is: " + id);
  console.info("The actualDelayTime is: " + time);
  ```


## backgroundTaskManager.getRemainingDelayTime<sup>(deprecated)</sup>

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

获取应用程序进入挂起状态前的剩余时间，使用callback形式返回。

> **说明：**
> 从API version 7开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.getRemainingDelayTime](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagergetremainingdelaytime)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名       | 类型                          | 必填   | 说明                                       |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | 是    | 延迟挂起的请求ID。这个值通过调用[requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelaydeprecated)方法获取。 |
| callback  | AsyncCallback&lt;number&gt; | 是    | 指定的callback回调方法。用于返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

**示例**：

  ```ts
  import backgroundTaskManager from '@ohos.backgroundTaskManager';
  import { BusinessError } from '@ohos.base';

  let delayInfo = backgroundTaskManager.requestSuspendDelay("test", () => {});
  backgroundTaskManager.getRemainingDelayTime(delayInfo.requestId, (err: BusinessError, res: number) => {
      if(err) {
          console.log('callback => Operation getRemainingDelayTime failed. Cause: ' + err.code);
      } else {
          console.log('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
      }
  })
  ```


## backgroundTaskManager.getRemainingDelayTime<sup>(deprecated)</sup>

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

获取应用程序进入挂起状态前的剩余时间，使用Promise形式返回。

> **说明：**
> 从API version 7开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.getRemainingDelayTime](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagergetremainingdelaytime-1)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 延迟挂起的请求ID。这个值通过调用[requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelaydeprecated)方法获取。 |

**返回值**：

| 类型                    | 说明                                       |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

**示例**：

```ts
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import { BusinessError } from '@ohos.base';

let delayInfo = backgroundTaskManager.requestSuspendDelay("test", () => {});
    backgroundTaskManager.getRemainingDelayTime(delayInfo.requestId).then((res:number) => {
    console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
}).catch((err : BusinessError) => {
    console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.code);
})
```


## backgroundTaskManager.cancelSuspendDelay<sup>(deprecated)</sup>

cancelSuspendDelay(requestId: number): void

取消延迟挂起。

> **说明：**
> 从API version 7开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.cancelSuspendDelay](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagercancelsuspenddelay)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：

| 参数名       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 延迟挂起的请求ID。这个值通过调用[requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelaydeprecated)方法获取。 |

**示例**：

  ```ts
  let delayInfo = backgroundTaskManager.requestSuspendDelay("test", () => {});
  backgroundTaskManager.cancelSuspendDelay(delayInfo.requestId);
  ```


## backgroundTaskManager.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

向系统申请长时任务，使用callback形式返回结果。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.startBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning)替代。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名    | 类型                                          | 必填 | 说明                                                         |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| context   | Context                                       | 是   | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmodedeprecated)            | 是   | 向系统申请的后台模式。                                       |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是   | 通知参数，用于指定长时任务通知点击后跳转的界面。             |
| callback  | AsyncCallback&lt;void&gt;                     | 是   | callback形式返回启动长时任务的结果。                         |

**示例**：

FA模型示例：

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation startBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation startBackgroundRunning succeeded");
  }
}

let wantAgentInfo : wantAgent.WantAgentInfo = {
  wants: [
    {
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility"
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
  backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
    backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj, callback)
});

```

Stage模型示例：

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation startBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation startBackgroundRunning succeeded");
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo : wantAgent.WantAgentInfo = {
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
      backgroundTaskManager.startBackgroundRunning(this.context,
        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj, callback)
    });
  }
};
```

## backgroundTaskManager.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;

向系统申请长时任务，使用promise形式返回结果。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.startBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning-1)替代。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名    | 类型                                          | 必填 | 说明                                                         |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| context   | Context                                       | 是   | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| bgMode    | [BackgroundMode](#backgroundmodedeprecated)            | 是   | 向系统申请的后台模式。                                       |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是   | 通知参数，用于指定长时任务通知点击跳转的界面。               |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例**：

FA模型示例（需使用js代码开发）：

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

let wantAgentInfo : wantAgent.WantAgentInfo = {
  wants: [
    {
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility"
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
  backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
    backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj).then(() => {
    console.info("Operation startBackgroundRunning succeeded");
  }).catch((err: BusinessError) => {
    console.error("Operation startBackgroundRunning failed Cause: " + err);
  });
});
```

Stage模型示例：

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo : wantAgent.WantAgentInfo = {
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      // 点击通知后，动作类型
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      // 点击通知后，动作执行属性
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
      backgroundTaskManager.startBackgroundRunning(this.context,
        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj).then(() => {
        console.info("Operation startBackgroundRunning succeeded");
      }).catch((err: BusinessError) => {
        console.error("Operation startBackgroundRunning failed Cause: " + err);
      });
    });
  }
};
```

## backgroundTaskManager.stopBackgroundRunning<sup>(deprecated)</sup>

stopBackgroundRunning(context: Context, callback: AsyncCallback&lt;void&gt;): void

向系统申请取消长时任务，使用callback形式返回结果。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.stopBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名      | 类型                        | 必填   | 说明                                       |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| context  | Context                   | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| callback | AsyncCallback&lt;void&gt; | 是    | callback形式返回启动长时任务的结果。                   |

**示例**：

FA模型示例（需使用js代码开发）：

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation stopBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation stopBackgroundRunning succeeded");
  }
}

backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext(), callback);

```

Stage模型示例：

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation stopBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation stopBackgroundRunning succeeded");
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    backgroundTaskManager.stopBackgroundRunning(this.context, callback);
  }
};
```

## backgroundTaskManager.stopBackgroundRunning<sup>(deprecated)</sup>

stopBackgroundRunning(context: Context): Promise&lt;void&gt;

向系统申请取消长时任务，使用promise形式返回结果。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃。建议使用[backgroundTaskManager.stopBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning-1)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名     | 类型      | 必填   | 说明                                       |
| ------- | ------- | ---- | ---------------------------------------- |
| context | Context | 是    | 应用运行的上下文。<br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |

**返回值**：

| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例**：

FA模型示例：

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

// 取消长时任务
backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
  console.info("Operation stopBackgroundRunning succeeded");
}).catch((err: BusinessError) => {
  console.error("Operation stopBackgroundRunning failed Cause: " + err);
});

```

Stage模型示例：

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // 取消长时任务
    backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
      console.info("Operation stopBackgroundRunning succeeded");
    }).catch((err: BusinessError) => {
      console.error("Operation stopBackgroundRunning failed Cause: " + err);
    });
  }
};
```

## DelaySuspendInfo<sup>(deprecated)</sup>

延迟挂起信息。

> **说明：**
> 从API version 7开始支持，从API version 9开始废弃。建议使用[DelaySuspendInfo](js-apis-resourceschedule-backgroundTaskManager.md#delaysuspendinfo)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| 名称             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| requestId       | number | 是    | 延迟挂起的请求ID。                               |
| actualDelayTime | number | 是    | 应用的实际挂起延迟时间，以毫秒为单位。<br/>一般情况下默认值为180000，低电量（依据系统低电量广播）时默认值为60000。 |


## BackgroundMode<sup>(deprecated)</sup>

长时任务类型。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃。建议使用[BackgroundMode](js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode)替代。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 名称                     | 值  | 说明                    |
| ----------------------- | ---- | --------------------- |
| DATA_TRANSFER           | 1    | 数据传输。                  |
| AUDIO_PLAYBACK          | 2    | 音频播放。                  |
| AUDIO_RECORDING         | 3    | 录音。                    |
| LOCATION                | 4    | 定位导航。                  |
| BLUETOOTH_INTERACTION   | 5    | 蓝牙相关。                  |
| MULTI_DEVICE_CONNECTION | 6    | 多设备互联。                 |
| TASK_KEEPING            | 9    | 计算任务（仅在特定设备生效）。        |
