# 后台任务开发指导

## 场景介绍

应用或业务模块处于后台（无可见界面）时，如果有需要继续执行或者后续执行的业务，可基于业务类型，申请短时任务延迟挂起（Suspend）或者长时任务避免进入挂起状态。

## 短时任务

### 接口说明

**表1** 短时任务主要接口

| 接口名 | 描述 |
| -------- | -------- |
| requestSuspendDelay(reason:&nbsp;string,&nbsp;callback:&nbsp;Callback&lt;void&gt;):&nbsp;[DelaySuspendInfo](../reference/apis/js-apis-backgroundTaskManager.md#delaysuspendinfo) | 后台应用申请延迟挂起。<br/>延迟挂起时间一般情况下默认值为180000，低电量时默认值为60000。 |
| getRemainingDelayTime(requestId:&nbsp;number):&nbsp;Promise&lt;number&gt; | 获取应用程序进入挂起状态前的剩余时间。<br/>使用Promise形式返回。 |
| cancelSuspendDelay(requestId:&nbsp;number):&nbsp;void | 取消延迟挂起。 |


### 开发步骤


1. 申请延迟挂起

    ```js
    import backgroundTaskManager from '@ohos.backgroundTaskManager';
    
    let myReason = 'test requestSuspendDelay';
    let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
        console.info("Request suspension delay will time out.");
    });
    
    var id = delayInfo.requestId;
    console.info("requestId is: " + id);
    ```


2. 获取进入挂起前的剩余时间

    ```js
    backgroundTaskManager.getRemainingDelayTime(id).then( res => {
        console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.code);
    });
    ```


3. 取消延迟挂起

    ```js
    backgroundTaskManager.cancelSuspendDelay(id);
    ```


### 开发实例

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
let myReason = 'test requestSuspendDelay';

// 申请延迟挂起
let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
    console.info("Request suspension delay will time out.");
});

// 打印延迟挂起信息
var id = delayInfo.requestId;
var time = delayInfo.actualDelayTime;
console.info("The requestId is: " + id);
console.info("The actualDelayTime is: " + time);

// 获取应用程序进入挂起状态前的剩余时间
backgroundTaskManager.getRemainingDelayTime(id).then( res => {
    console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
}).catch( err => {
    console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.code);
});

// 取消延迟挂起
backgroundTaskManager.cancelSuspendDelay(id);
```

## 长时任务

### 权限

ohos.permission.KEEP_BACKGROUND_RUNNING

### 接口说明

**表2** 长时任务主要接口

| 接口名 | 描述 |
| -------- | -------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt; | 服务启动后，向系统申请长时任务，使服务一直保持后台运行。 |
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | 停止后台长时任务的运行。 |


其中，wantAgent的信息详见（[WantAgent](../reference/apis/js-apis-wantAgent.md)）

**表3** 后台模式类型

| 参数名 | id值 | 描述 | 配置项 |
| -------- | -------- | -------- | -------- |
| DATA_TRANSFER           | 1 | 数据传输 | dataTransfer |
| AUDIO_PLAYBACK          | 2 | 音频播放 | audioPlayback |
| AUDIO_RECORDING         | 3 | 录音 | audioRecording |
| LOCATION                | 4 | 定位导航 | location |
| BLUETOOTH_INTERACTION   | 5 | 蓝牙相关 | bluetoothInteraction |
| MULTI_DEVICE_CONNECTION | 6 | 多设备互联 | multiDeviceConnection |
| WIFI_INTERACTION        | 7 | WLAN相关（系统保留） | wifiInteraction |
| VOIP                    | 8 | 音视频通话（系统保留） | voip |
| TASK_KEEPING            | 9 | 计算任务（仅供特定设备使用） | taskKeeping |


### 开发步骤

1. 新建Api Version 8的工程后，在工程目录中右键选择“new” -> “Ability” -> “Service Ability” 快速创建Service Ability组件。并在config.json文件中配置长时任务权限、后台模式类型，其中Ability类型为“service”。

    ```
    "module": {
      "package": "com.example.myapplication",
      "abilities": [
        {
          "backgroundModes": [
            "dataTransfer",
            "location"
          ], // 后台模式类型
          "type": "service"  // ability类型为service
        }
      ],
      "reqPermissions": [
        {
          "name": "ohos.permission.KEEP_BACKGROUND_RUNNING"  // 长时任务权限
        }
      ]
    }
    ```
    
2. 申请长时任务

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

    // 通过wantAgent模块的getWantAgent方法获取WantAgent对象
    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
        backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
            backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
            console.info("Operation startBackgroundRunning succeeded");
        }).catch((err) => {
            console.error("Operation startBackgroundRunning failed Cause: " + err);
        });
    });
    ```

3. 停止长时任务

    ```js
    import backgroundTaskManager from '@ohos.backgroundTaskManager';
    import featureAbility from '@ohos.ability.featureAbility';
    
    backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
        console.info("Operation stopBackgroundRunning succeeded");
    }).catch((err) => {
        console.error("Operation stopBackgroundRunning failed Cause: " + err);
    });
    
    ```

### 开发实例
基于FA的Service Ability使用，参考[ServiceAbility开发指导](../ability/fa-serviceability.md)。

当不需要与后台执行的长时任务交互时，可以采用startAbility()方法启动Service Ability。并在Service Ability的onStart回调方法中，调用长时任务的申请接口，声明此服务需要在后台长时运行。当任务执行完，再调用长时任务取消接口，及时释放资源。

当需要与后台执行的长时任务交互时（如播放音乐等）。可以采用connectAbility()方法启动并连接Service Ability。在获取到服务的代理对象后，与服务进行通信，控制长时任务的申请和取消。

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent from '@ohos.wantAgent';
import rpc from "@ohos.rpc";

function startBackgroundRunning() {
    let wantAgentInfo = {
        // 点击通知后，将要执行的动作列表
        wants: [
            {
                bundleName: "com.example.myapplication",
                abilityName: "com.example.myapplication.MainAbility"
            }
        ],
        // 点击通知后，动作类型
        operationType: wantAgent.OperationType.START_ABILITY,
        // 使用者自定义的一个私有值
        requestCode: 0,
        // 点击通知后，动作执行属性
        wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    // 通过wantAgent模块的getWantAgent方法获取WantAgent对象
    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
        backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
            backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
            console.info("Operation startBackgroundRunning succeeded");
        }).catch((err) => {
            console.error("Operation startBackgroundRunning failed Cause: " + err);
        });
    });
}

function stopBackgroundRunning() {
    backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
        console.info("Operation stopBackgroundRunning succeeded");
    }).catch((err) => {
        console.error("Operation stopBackgroundRunning failed Cause: " + err);
    });
}

let mMyStub;

class MyStub extends rpc.RemoteObject {
    constructor(des) {
        if (typeof des === 'string') {
            super(des);
        } else {
            return null;
        }
    }
    onRemoteRequest(code, data, reply, option) {
        console.log('ServiceAbility onRemoteRequest called');
        // code 的具体含义用户自定义
        if (code === 1) {
            // 接收到申请长时任务的请求码
            startContinuousTask();
            // 此处执行具体长时任务
        } else if (code === 2) {
            // 接收到取消长时任务的请求码
            stopContinuousTask();
        } else {
            console.log('ServiceAbility unknown request code');
        }
        return true;
    }
}

export default {
    onStart(want) {
        console.info('ServiceAbility onStart');
        mMyStub = new MyStub("ServiceAbility-test");
        startBackgroundRunning();
        // 此处执行后台具体的长时任务。
        stopBackgroundRunning();
    },
    onStop() {
        console.info('ServiceAbility onStop');
    },
    onConnect(want) {
        console.info('ServiceAbility onConnect');
        return mMyStub;
    },
    onReconnect(want) {
        console.info('ServiceAbility onReconnect');
    },
    onDisconnect() {
        console.info('ServiceAbility onDisconnect');
    },
    onCommand(want, restart, startId) {
        console.info('ServiceAbility onCommand');
    }
};
```

## 相关实例

基于后台任务管理，有以下相关实例可供参考：

- [`BackgroundTaskManager`：后台任务管理（eTS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/ResourcesSchedule/BackgroundTaskManager)