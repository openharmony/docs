# Background Task Management Development

## When to Use

If a service needs to be continued when the application or service module is running in the background (not visible to users), the application or service module can request a transient task or continuous task for delayed suspension based on the service type. 

## Transient Tasks

### Available APIs

**Table 1** Main APIs for transient tasks

| API| Description|
| -------- | -------- |
| requestSuspendDelay(reason:&nbsp;string,&nbsp;callback:&nbsp;Callback&lt;void&gt;):&nbsp;[DelaySuspendInfo](../reference/apis/js-apis-backgroundTaskManager.md#delaysuspendinfo) | Requests delayed suspension after the application switches to the background.<br>The default duration value of delayed suspension is 180000 when the battery level is normal and 60000 when the battery level is low.|
| getRemainingDelayTime(requestId:&nbsp;number):&nbsp;Promise&lt;number&gt; | Obtains the remaining duration before the application is suspended.<br>This API uses a promise to return the task execution result.|
| cancelSuspendDelay(requestId:&nbsp;number):&nbsp;void | Cancels the suspension delay.|


### How to Develop


1. Request a suspension delay.

    ```js
    import backgroundTaskManager from '@ohos.backgroundTaskManager';
    
    let myReason = 'test requestSuspendDelay';
    let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
        console.info("Request suspension delay will time out.");
    });
    
    var id = delayInfo.requestId;
    console.info("requestId is: " + id);
    ```


2. Obtain the remaining duration before the application is suspended.

    ```js
    backgroundTaskManager.getRemainingDelayTime(id).then( res => {
        console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.data);
    });
    ```


3. Cancel the suspension delay.

    ```js
    backgroundTaskManager.cancelSuspendDelay(id);
    ```


### Development Examples

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
let myReason = 'test requestSuspendDelay';

// Request a suspension delay.
let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
    console.info("Request suspension delay will time out.");
});

// Print the suspension delay information.
var id = delayInfo.requestId;
var time = delayInfo.actualDelayTime;
console.info("The requestId is: " + id);
console.info("The actualDelayTime is: " + time);

// Obtain the remaining duration before the application is suspended.
backgroundTaskManager.getRemainingDelayTime(id).then( res => {
    console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
}).catch( err => {
    console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.data);
});

// Cancel the suspension delay.
backgroundTaskManager.cancelSuspendDelay(id);
```

## Continuous Tasks

### Required Permissions

ohos.permission.KEEP_BACKGROUND_RUNNING

### Available APIs

**Table 2** Main APIs for continuous tasks

| API| Description|
| -------- | -------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt; | Requests a continuous task from the system so that the application keeps running in the background.|
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | Cancels the continuous task.|


For details about **wantAgent**, see [WantAgent](../reference/apis/js-apis-wantAgent.md).

**Table 3** Background modes

| Name| ID Value| Description| Item|
| -------- | -------- | -------- | -------- |
| DATA_TRANSFER           | 1 | Data transfer.| dataTransfer |
| AUDIO_PLAYBACK          | 2 | Audio playback.| audioPlayback |
| AUDIO_RECORDING         | 3 | Audio recording.| audioRecording |
| LOCATION                | 4 | Positioning and navigation.| location |
| BLUETOOTH_INTERACTION   | 5 | Bluetooth-related task.| bluetoothInteraction |
| MULTI_DEVICE_CONNECTION | 6 | Multi-device connection.| multiDeviceConnection |
| WIFI_INTERACTION        | 7 | WLAN-related task (reserved).| wifiInteraction |
| VOIP                    | 8 | Voice and video call (reserved).| voip |
| TASK_KEEPING            | 9 | Computing task (for specific devices only).| taskKeeping |


### How to Develop

1. Configure the continuous task permission and background mode type in the **config.json** file, with the ability type set to **service**.

    ```json
    "module": {
      "package": "com.example.myapplication",
      "abilities": [
        {
          "backgroundModes": [
            "dataTransfer",
            "location"
          ], // Background mode
          "type": "service"  // The ability type is service.
        }
      ],
      "reqPermissions": [
        {
          "name": "ohos.permission.KEEP_BACKGROUND_RUNNING" // Continuous task permission
        }
      ]
    }
    ```
    
2. Request a continuous task.

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

    // Obtain the WantAgent object by using the getWantAgent method of the wantAgent module.
    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
        backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
            backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
            console.info("Operation startBackgroundRunning succeeded");
        }).catch((err) => {
            console.error("Operation startBackgroundRunning failed Cause: " + err);
        });
    });
    ```

3. Cancel the continuous task.

    ```js
    import backgroundTaskManager from '@ohos.backgroundTaskManager';
    import featureAbility from '@ohos.ability.featureAbility';
    
    backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
        console.info("Operation stopBackgroundRunning succeeded");
    }).catch((err) => {
        console.error("Operation stopBackgroundRunning failed Cause: " + err);
    });
    
    ```

### Development Examples

After a service is started, call the API for requesting a continuous task in the **onStart** callback of the Service ability to declare that the service needs to run in the background for a long time. In the **onStop** callback, call the API for canceling the continuous task.
In the **service.js** file:

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent from '@ohos.wantAgent';

function startBackgroundRunning() {
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

    // Obtain the WantAgent object by using the getWantAgent method of the wantAgent module.
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

export default {
    onStart(want) {
        console.info('ServiceAbility onStart');
        startBackgroundRunning();
    },
    onStop() {
        console.info('ServiceAbility onStop');
        stopBackgroundRunning();
    },
    onConnect(want) {
        console.info('ServiceAbility onConnect');
        return {};
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
