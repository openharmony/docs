# @ohos.distributedMissionManager (Distributed Mission Management) (System API)

The distributedMissionManager module implements mission management across devices. You can use the APIs provided by this module to register or unregister a mission status listener, start or stop synchronizing a remote mission list, and continue a mission on a remote device by mission ID or bundle name.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import { distributedMissionManager } from '@kit.AbilityKit';
```

## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback&lt;void&gt;): void;

Registers a mission status listener. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | Yes   | Information about the device to listen for.|
| options   | [MissionCallback](#missioncallback)     | Yes   | Callback to register.|
| callback  | AsyncCallback&lt;void&gt;               | Yes   | Callback used to return the result. If the listener is registered, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  // Implement a callback function.
  function NotifyMissionsChanged(deviceId: string): void {
    console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
  }
  function NotifySnapshot(deviceId: string, missionId: number): void {
    console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
    console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId: string, state: number): void {
    console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
    console.log('NotifyNetDisconnect state ' + JSON.stringify(state));
  }
  try {
    // Call registerMissionListener.
    distributedMissionManager.registerMissionListener(
      { deviceId: "" },
      {
        notifyMissionsChanged: NotifyMissionsChanged,
        notifySnapshot: NotifySnapshot,
        notifyNetDisconnect: NotifyNetDisconnect
      },
      (error: BusinessError) => {
        if (error) {
          console.error('registerMissionListener failed, cause: ' + JSON.stringify(error));
          return;
        }
        console.info('registerMissionListener finished');
      });
  } catch (error) {
    console.error('registerMissionListener failed, cause: ' + JSON.stringify(error));
  }
  ```
## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback): Promise&lt;void&gt;

Registers a mission status listener. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo)  | Yes   | Information about the device to listen for.  |
| options   | <a href="#missioncallback">MissionCallback</a> | Yes   | Callback to register.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Implement a callback function.
  function NotifyMissionsChanged(deviceId: string): void {
    console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
  }
  function NotifySnapshot(deviceId: string, missionId: number): void {
    console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
    console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId: string, state: number): void {
    console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
    console.log('NotifyNetDisconnect state ' + JSON.stringify(state));
  }
  try {
      // Call registerMissionListener.
      distributedMissionManager.registerMissionListener(
        { deviceId: "" },
        {
          notifyMissionsChanged: NotifyMissionsChanged,
          notifySnapshot: NotifySnapshot,
          notifyNetDisconnect: NotifyNetDisconnect
        }).then(() => {
          console.info('registerMissionListener finished. ');
      }).catch((error: BusinessError) => {
          console.error('registerMissionListener failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('registerMissionListener failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.unRegisterMissionListener

unRegisterMissionListener(parameter: MissionDeviceInfo, callback: AsyncCallback&lt;void&gt;): void;

Unregisters a mission status listener. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | Yes   | Information about the device to listen for.   |
| callback  | AsyncCallback&lt;void&gt;               | Yes   | Callback used to return the result. If the listener is unregistered, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.unRegisterMissionListener(
      { deviceId: "" },
      (error: BusinessError) => {
        if (error) {
            console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error));
            return;
        }
        console.info('unRegisterMissionListener finished');
    })
  } catch (error) {
      console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.unRegisterMissionListener

unRegisterMissionListener(parameter: MissionDeviceInfo): Promise&lt;void&gt;

Unregisters a mission status listener. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | Yes   | Information about the device to listen for.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.unRegisterMissionListener({deviceId: ""}).then(() => {
      console.info('unRegisterMissionListener finished successfully');
    }).catch((error: BusinessError) => {
        console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error));
    })
  } catch (error) {
      console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.startSyncRemoteMissions

startSyncRemoteMissions(parameter: MissionParameter, callback: AsyncCallback&lt;void&gt;): void;

Starts to synchronize the remote mission list. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                   | Mandatory  | Description       |
| --------- | ------------------------------------- | ---- | --------- |
| parameter | [MissionParameter](#missionparameter) | Yes   | Parameters required for synchronization.    |
| callback  | AsyncCallback&lt;void&gt;             | Yes   | Callback used to return the result. If the synchronization is started, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.startSyncRemoteMissions(
      {
        deviceId: "",
        fixConflict: false,
        tag: 0
      },
      (error: BusinessError) => {
        if (error) {
          console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
          return;
        }
        console.info('startSyncRemoteMissions finished');}
    )
  } catch (error) {
    console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.startSyncRemoteMissions

startSyncRemoteMissions(parameter: MissionParameter): Promise&lt;void&gt;

Starts to synchronize the remote mission list. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| parameter | [MissionParameter](#missionparameter) | Yes   | Parameters required for synchronization.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.startSyncRemoteMissions(
      {
        deviceId: "",
        fixConflict: false,
        tag: 0
      }
    ).then(() => {
        console.info('startSyncRemoteMissions finished successfully');
      }).catch((error: BusinessError) => {
      console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
    })
  } catch (error) {
    console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.stopSyncRemoteMissions

stopSyncRemoteMissions(parameter: MissionDeviceInfo, callback: AsyncCallback&lt;void&gt;): void;

Stops synchronizing the remote mission list. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | Yes   | Parameters required for synchronization.    |
| callback  | AsyncCallback&lt;void&gt;               | Yes   | Callback used to return the result. If the synchronization is stopped, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.stopSyncRemoteMissions(
      {
        deviceId: ""
      },
      (error: BusinessError) => {
        if (error) {
          console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
          return;
        }
        console.info('stopSyncRemoteMissions finished');}
    )
  } catch (error) {
    console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.stopSyncRemoteMissions

stopSyncRemoteMissions(parameter: MissionDeviceInfo): Promise&lt;void&gt;

Stops synchronizing the remote mission list. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | Yes   | Parameters required for synchronization.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.stopSyncRemoteMissions(
      {
        deviceId: ""
      }).then(() => {
        console.info('stopSyncRemoteMissions finished successfully');
      }).catch((error: BusinessError) => {
      console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
    })
  } catch (error) {
    console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.continueMission

continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback, callback: AsyncCallback&lt;void&gt;): void;

Continues a mission on a remote device, with the mission ID specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo-sys.md) | Yes   | Parameters required for mission continuation.|
| options | [ContinueCallback](js-apis-inner-application-continueCallback-sys.md) | Yes   | Callback invoked when the mission continuation is complete.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the mission is continued, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 202 | The application is not system-app, can not use system-api. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300502 | Failed to get the missionInfo of the specified missionId. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Implement a callback function.
  function onContinueDone(resultCode: number): void {
    console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  try {
    // Call continueMission.
    distributedMissionManager.continueMission(
      {
        srcDeviceId: "",
        dstDeviceId: "",
        missionId: 1,
        wantParam: {"key": "value"}
      },
      { onContinueDone: onContinueDone },
      (error: BusinessError) => {
        if (error) {
          console.error('continueMission failed, cause: ' + JSON.stringify(error));
          return;
        }
        console.info('continueMission finished');
    })
  } catch (error) {
    console.error('continueMission failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.continueMission

continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback): Promise&lt;void&gt;

Continues a mission on a remote device, with the mission ID specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo-sys.md) | Yes   | Parameters required for mission continuation.|
| options | [ContinueCallback](js-apis-inner-application-continueCallback-sys.md) | Yes   | Callback invoked when the mission continuation is complete.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 202 | The application is not system-app, can not use system-api. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300502 | Failed to get the missionInfo of the specified missionId. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Implement a callback function.
  function onContinueDone(resultCode: number): void {
    console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  try {
    // Call continueMission.
    distributedMissionManager.continueMission(
      {
        srcDeviceId: "",
        dstDeviceId: "",
        missionId: 1,
        wantParam: {"key": "value"}
      },
      { onContinueDone: onContinueDone }).then(() => {
        console.info('continueMission finished successfully');
      }).catch((error: BusinessError) => {
      console.error('continueMission failed, cause: ' + JSON.stringify(error));
    })
  } catch (error) {
    console.error('continueMission failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.continueMission<sup>10+</sup>

continueMission(parameter: ContinueMissionInfo, callback: AsyncCallback&lt;void&gt;): void;

Continues a mission on a remote device, with the bundle name specified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo-sys.md) | Yes   | Parameters required for mission continuation.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the mission is continued, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 202 | The application is not system-app, can not use system-api. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |
| 16300507 | Failed to get the missionInfo of the specified bundle name. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.continueMission(
      {
        srcDeviceId: "",
        dstDeviceId: "",
        bundleName: "ohos.test.continueapp",
        wantParam: {"key": "value"}
      },
      (error: BusinessError) => {
        if (error) {
          console.error('continueMission failed, cause: ' + JSON.stringify(error));
          return;
        }
        console.info('continueMission finished');
    })
  } catch (error) {
    console.error('continueMission failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.continueMission<sup>10+</sup>

continueMission(parameter: ContinueMissionInfo): Promise&lt;void&gt;

Continues a mission on a remote device, with the bundle name specified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo-sys.md) | Yes   | Parameters required for mission continuation.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Distributed Scheduler Error Codes](errorcode-DistributedSchedule.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 202 | The application is not system-app, can not use system-api. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |
| 16300507 | Failed to get the missionInfo of the specified bundle name. |

**Example**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
      distributedMissionManager.continueMission(
        {
          srcDeviceId: "",
          dstDeviceId: "",
          bundleName: "ohos.test.continueapp",
          wantParam: {"key": "value"}
        }
      ).then(() => {
          console.info('continueMission finished successfully');
      }).catch((error: BusinessError) => {
          console.error('continueMission failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('continueMission failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.on('continueStateChange')<sup>11+</sup>

on(type: 'continueStateChange',  callback: Callback&lt;ContinueCallbackInfo&gt;): void

Subscribes to continuation state change events of the current mission.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | Yes   | Event type. The value **'continueStateChange'** indicates the continuation state change event of the current mission.    |
| callback | Callback&lt;[ContinueCallbackInfo](#continuecallbackinfo11)&gt; | Yes   | Callback used to return the continuation state and information of the current mission.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
  import { distributedMissionManager } from '@kit.AbilityKit';

  try {
    distributedMissionManager.on('continueStateChange', (data) => {
      console.info("continueStateChange on:" + JSON.stringify(data));
    });
  } catch (error) {
    console.error("continueStateChange err: " + JSON.stringify(error));
  }
```

## distributedMissionManager.off('continueStateChange')<sup>11+</sup>

off(type: 'continueStateChange',  callback?: Callback&lt;ContinueCallbackInfo&gt;): void

Unsubscribes from continuation state change events of the current mission.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | Yes   | Event type. The value **'continueStateChange'** indicates the continuation state change event of the current mission.    |
| callback | Callback&lt;[ContinueCallbackInfo](#continuecallbackinfo11)&gt; | No   | Callback used for unsubscription.<br>If the callback is unspecified, all subscriptions to the specified event are canceled.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
  import { distributedMissionManager } from '@kit.AbilityKit';

  try {
    distributedMissionManager.off('continueStateChange', (data) => {
      console.info("continueStateChange off:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("continueStateChange err: " + JSON.stringify(err));
  }
```

## MissionCallback

Defines the callbacks that can be registered as a mission status listener.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name                   | Type      | Readable  | Writable  | Description                |
| --------------------- | -------- | ---- | ---- | ------------------ |
| notifyMissionsChanged | function | Yes   | No   | Callback used to notify the mission change event and return the device ID.    |
| notifySnapshot        | function | Yes   | No   | Callback used to notify the snapshot change event and return the device ID and mission ID.|
| notifyNetDisconnect   | function | Yes   | No   | Callback used to notify the disconnection event and return the device ID and network status.|

## MissionParameter

Defines the parameters required for mission synchronization.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name         | Type   | Readable  | Writable  | Description         |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | Yes   | Yes   | Device ID. For details, see [getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).    |
| fixConflict | boolean | Yes   | Yes   | Whether a version conflict occurs.|
| tag         | number  | Yes   | Yes   | Tag of the mission.   |

## MissionDeviceInfo

Defines the parameters required for registering a listener.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | Yes   | Yes   | Device ID. For details, see [getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).|

## ContinueState<sup>10+</sup>

Enumerates the mission continuation states.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name          | Value      | Description                                                        |
| ------------- | --------- | ------------------------------------------------------------ |
| ACTIVE        | 0         | Continuation is activated for the current mission.                             |
| INACTIVE      | 1         | Continuation is not activated for the current mission.                           |

## ContinueCallbackInfo<sup>11+</sup>

Defines the information about the callback that is triggered for mission continuation state changes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type   | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| state | [ContinueState](#continuestate10)   | Yes   | No   |   Continuation state of the mission.|
| info  | [ContinuableInfo](./js-apis-inner-application-continuableInfo-sys.md) | Yes   | No   |   Continuation information of the mission.|
