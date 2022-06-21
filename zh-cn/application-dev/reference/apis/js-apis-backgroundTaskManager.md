# 后台任务管理

本模块提供后台任务管理能力。

当应用或业务模块处于后台（无可见界面）时，如果有需要继续执行或者后续执行的业务，可基于业务类型，申请短时任务延迟挂起（Suspend）或者长时任务避免进入挂起状态，例如：应用有不可中断且短时间能完成的任务时，可以使用短时任务机制；应用有用户能够直观感受到的且需要一直在后台运行的业务时，可以使用长时任务机制。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```


## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

后台应用申请延迟挂起。

延迟挂起时间一般情况下默认值为180000，低电量（依据系统低电量广播）时默认值为60000。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：
| 参数名      | 类型                   | 必填   | 说明                             |
| -------- | -------------------- | ---- | ------------------------------ |
| reason   | string               | 是    | 延迟挂起申请的原因。                     |
| callback | Callback&lt;void&gt; | 是    | 延迟即将超时的回调函数，一般在超时前6秒通过此回调通知应用。 |

**返回值**：
| 类型                                    | 说明        |
| ------------------------------------- | --------- |
| [DelaySuspendInfo](#delaysuspendinfo) | 返回延迟挂起信息。 |

**示例**：

  ```js
  let myReason = 'test requestSuspendDelay';
  let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
      console.info("Request suspension delay will time out.");
  })
  
  var id = delayInfo.requestId;
  var time = delayInfo.actualDelayTime;
  console.info("The requestId is: " + id);
  console.info("The actualDelayTime is: " + time);
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

获取应用程序进入挂起状态前的剩余时间，使用callback形式返回。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：
| 参数名       | 类型                          | 必填   | 说明                                       |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | 是    | 延迟挂起的请求ID。                               |
| callback  | AsyncCallback&lt;number&gt; | 是    | 指定的callback回调方法。用于返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

**示例**：

  ```js
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id, (err, res) => {
      if(err) {
          console.log('callback => Operation getRemainingDelayTime failed. Cause: ' + err.code);
      } else {
          console.log('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
      }
  })
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

获取应用程序进入挂起状态前的剩余时间，使用Promise形式返回。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：
| 参数名       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 延迟挂起的请求ID。 |

**返回值**：
| 类型                    | 说明                                       |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回应用程序进入挂起状态之前的剩余时间，以毫秒为单位。 |

**示例**：
  ```js
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id).then( res => {
      console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
  }).catch( err => {
      console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.code);
  })
  ```


## backgroundTaskManager.cancelSuspendDelay

cancelSuspendDelay(requestId: number): void

取消延迟挂起。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**参数**：
| 参数名       | 类型     | 必填   | 说明         |
| --------- | ------ | ---- | ---------- |
| requestId | number | 是    | 延迟挂起的请求ID。 |

**示例**：
  ```js
  backgroundTaskManager.cancelSuspendDelay(id);
  ```


## backgroundTaskManager.startBackgroundRunning<sup>8+</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

向系统申请长时任务，使用callback形式返回结果。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：
| 参数名       | 类型                                 | 必填   | 说明                       |
| --------- | ---------------------------------- | ---- | ------------------------ |
| context   | [Context](js-apis-Context.md)      | 是    | 应用运行的上下文。                |
| bgMode    | [BackgroundMode](#backgroundmode8) | 是    | 向系统申请的后台模式。              |
| wantAgent | [WantAgent](js-apis-wantAgent.md)  | 是    | 通知参数，用于指定长时任务通知点击后跳转的界面。 |
| callback  | AsyncCallback&lt;void&gt;          | 是    | callback形式返回启动长时任务的结果。   |

**示例**：
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent from '@ohos.wantAgent';

function callback(err, data) {
    if (err) {
        console.error("Operation startBackgroundRunning failed Cause: " + err);
    } else {
        console.info("Operation startBackgroundRunning succeeded");
    }
}

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
        backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj, callback)
});

```

## backgroundTaskManager.startBackgroundRunning<sup>8+</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;

向系统申请长时任务，使用promise形式返回结果。

**需要权限:** ohos.permission.KEEP_BACKGROUND_RUNNING

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：

| 参数名       | 类型                                 | 必填   | 说明                      |
| --------- | ---------------------------------- | ---- | ----------------------- |
| context   | [Context](js-apis-Context.md)      | 是    | 应用运行的上下文。               |
| bgMode    | [BackgroundMode](#backgroundmode8) | 是    | 向系统申请的后台模式。             |
| wantAgent | [WantAgent](js-apis-wantAgent.md)  | 是    | 通知参数，用于指定长时任务通知点击跳转的界面。 |

**返回值**
| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例**：
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent from '@ohos.wantAgent';

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
        backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
        console.info("Operation startBackgroundRunning succeeded");
    }).catch((err) => {
        console.error("Operation startBackgroundRunning failed Cause: " + err);
    });
});

```

## backgroundTaskManager.stopBackgroundRunning<sup>8+</sup>

stopBackgroundRunning(context: Context, callback: AsyncCallback&lt;void&gt;): void

向系统申请取消长时任务，使用callback形式返回结果。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：
| 参数名      | 类型                            | 必填   | 说明                     |
| -------- | ----------------------------- | ---- | ---------------------- |
| context  | [Context](js-apis-Context.md) | 是    | 应用运行的上下文。              |
| callback | AsyncCallback&lt;void&gt;     | 是    | callback形式返回启动长时任务的结果。 |

**示例**：
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';

function callback(err, data) {
    if (err) {
        console.error("Operation stopBackgroundRunning failed Cause: " + err);
    } else {
        console.info("Operation stopBackgroundRunning succeeded");
    }
}

backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext(), callback);

```

## backgroundTaskManager.stopBackgroundRunning<sup>8+</sup>

stopBackgroundRunning(context: Context): Promise&lt;void&gt;

向系统申请取消长时任务，使用promise形式返回结果。

**系统能力:** SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**参数**：
| 参数名     | 类型                            | 必填   | 说明        |
| ------- | ----------------------------- | ---- | --------- |
| context | [Context](js-apis-Context.md) | 是    | 应用运行的上下文。 |

**返回值**
| 类型             | 说明               |
| -------------- | ---------------- |
| Promise\<void> | 使用Promise形式返回结果。 |

**示例**：
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';

backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
    console.info("Operation stopBackgroundRunning succeeded");
}).catch((err) => {
    console.error("Operation stopBackgroundRunning failed Cause: " + err);
});

```

## DelaySuspendInfo

延迟挂起信息。

**系统能力:** 以下各项对应的系统能力均为SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| 参数名             | 类型     | 必填   | 说明                                       |
| --------------- | ------ | ---- | ---------------------------------------- |
| requestId       | number | 是    | 延迟挂起的请求ID。                               |
| actualDelayTime | number | 是    | 应用的实际挂起延迟时间，以毫秒为单位。<br/>一般情况下默认值为180000，低电量（依据系统低电量广播）时默认值为60000。 |


## BackgroundMode<sup>8+</sup>

**系统能力:** 以下各项对应的系统能力均为SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| 参数名                  | 参数值 | 描述                         |
| ----------------------- | ------ | ---------------------------- |
| DATA_TRANSFER           | 1      | 数据传输                     |
| AUDIO_PLAYBACK          | 2      | 音频播放                     |
| AUDIO_RECORDING         | 3      | 录音                         |
| LOCATION                | 4      | 定位导航                     |
| BLUETOOTH_INTERACTION   | 5      | 蓝牙相关                     |
| MULTI_DEVICE_CONNECTION | 6      | 多设备互联                   |
| WIFI_INTERACTION        | 7      | WLAN相关（系统保留）         |
| VOIP                    | 8      | 音视频通话（系统保留）       |
| TASK_KEEPING            | 9      | 计算任务（仅在特定设备生效） |