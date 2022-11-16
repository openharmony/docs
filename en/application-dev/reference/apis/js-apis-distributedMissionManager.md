# Distributed Mission Management

The **distributedMissionManager** module implements system mission management across devices. You can use the APIs provided by this module to register or deregister a mission status listener, start or stop synchronizing a remote mission list, and continue a mission on a remote device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import distributedMissionManager from '@ohos.distributedMissionManager'
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
| options   | [MissionCallback](#missioncallback)     | Yes   | Callback to register. |
| callback  | AsyncCallback&lt;void&gt;               | Yes   | Callback used to return the result.|

**Example**

  ```ts
  function NotifyMissionsChanged(deviceId) {
      console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
  }
  function NotifySnapshot(deviceId, missionId) {
      console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
      console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId, state) {
      console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
      console.log('NotifyNetDisconnect state ' + JSON.stringify(state));
  }
  var parameter =  {
      deviceId: ""
  };
  var options = {
      notifyMissionsChanged: NotifyMissionsChanged,
      notifySnapshot: NotifySnapshot,
      notifyNetDisconnect: NotifyNetDisconnect
  }
  try {
      distributedMissionManager.registerMissionListener(parameter, options, (error) => {
          if (error.code != 0) {
              console.error('registerMissionListener failed, cause: ' + JSON.stringify(error))
          }
          console.info('registerMissionListener finished')
      })
  } catch (error) {
      console.error('registerMissionListener failed, cause: ' + JSON.stringify(error))
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
| parameter | [MissionDeviceInfo](#missiondeviceinfo)  | Yes   | Information about the device to listen for.   |
| options   | <a href="#missioncallback">MissionCallback</a> | Yes   | Callback to register.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  function NotifyMissionsChanged(deviceId) {
      console.log('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
  }
  function NotifySnapshot(deviceId, missionId) {
      console.log('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
      console.log('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId, state) {
      console.log('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
      console.log('NotifyNetDisconnect state ' + JSON.stringify(state));
  }
  var parameter =  {
      deviceId: ""
  };
  var options = {
      notifyMissionsChanged: NotifyMissionsChanged,
      notifySnapshot: NotifySnapshot,
      notifyNetDisconnect: NotifyNetDisconnect
  }
  try {
      distributedMissionManager.registerMissionListener(parameter, options)
      .then(data => {
          console.info('registerMissionListener finished, ' + JSON.stringify(data));
      }).catch(error => {
          console.error('registerMissionListener failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('registerMissionListener failed, cause: ' + JSON.stringify(error))
  }
  ```


## distributedMissionManager.unRegisterMissionListener

unRegisterMissionListener(parameter: MissionDeviceInfo, callback: AsyncCallback&lt;void&gt;): void;

Deregisters a mission status listener. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description       |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | Yes   | Information about the device to listen for.    |
| callback  | AsyncCallback&lt;void&gt;               | Yes   | Callback used to return the result.|

**Example**

  ```ts
  var parameter =  {
      deviceId: ""
  };
  try {
      distributedMissionManager.unRegisterMissionListener(parameter, (error) => {
          if (error.code != 0) {
              console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error))
          }
          console.info('unRegisterMissionListener finished')
      })
  } catch (error) {
      console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error))
  }
  ```


## distributedMissionManager.unRegisterMissionListener

unRegisterMissionListener(parameter: MissionDeviceInfo): Promise&lt;void&gt;

Deregisters a mission status listener. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | Yes   | Information about the device to listen for.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  var parameter =  {
      deviceId: ""
  };
  try {
      distributedMissionManager.unRegisterMissionListener(parameter)
      .then(data => {
          console.info('unRegisterMissionListener finished, ' + JSON.stringify(data));
      }).catch(error => {
          console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error))
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
| callback  | AsyncCallback&lt;void&gt;             | Yes   | Callback used to return the result.|

**Example**

  ```ts
  var parameter =  {
      deviceId: "",
      fixConflict: false, 
      tag: 0
  };
  try {
      distributedMissionManager.startSyncRemoteMissions(parameter, (error) => {
          if (error.code != 0) {
              console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error))
          }
          console.info('startSyncRemoteMissions finished')
      })
  } catch (error) {
      console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error))
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
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  var parameter =  {
      deviceId: "",
      fixConflict: false, 
      tag: 0
  };
  try {
      distributedMissionManager.startSyncRemoteMissions(parameter)
      .then(data => {
          console.info('startSyncRemoteMissions finished, ' + JSON.stringify(data));
      }).catch(error => {
          console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('startSyncRemoteMissions failed, cause: ' + JSON.stringify(error))
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
| callback  | AsyncCallback&lt;void&gt;               | Yes   | Callback used to return the result.|

**Example**

  ```ts
  var parameter =  {
      deviceId: ""
  };
  try {
      distributedMissionManager.stopSyncRemoteMissions(parameter, (error) => {
          if (error.code != 0) {
              console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error))
          }
          console.info('stopSyncRemoteMissions finished')
      })
  } catch (error) {
      console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error))
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
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  var parameter =  {
      deviceId: ""
  };
  try {
      distributedMissionManager.stopSyncRemoteMissions(parameter)
      .then(data => {
          console.info('stopSyncRemoteMissions finished, ' + JSON.stringify(data));
      }).catch(error => {
          console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('stopSyncRemoteMissions failed, cause: ' + JSON.stringify(error))
  }
  ```

## distributedMissionManager.continueMission

continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback, callback: AsyncCallback&lt;void&gt;): void;

Continues a mission on a remote device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](#continuedeviceinfo) | Yes   | Parameters required for mission continuation.|
| options | [ContinueCallback](#continuecallback) | Yes   | Callback invoked when the mission continuation is complete.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

  ```ts
  var parameter =  {
      srcDeviceId: "",
      dstDeviceId: "",
      missionId: 1,
      wantParam: {"key": "value"}
  };
  function OnContinueDone(resultCode) {
      console.log('OnContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  var options = {
      OnContinueDone: OnContinueDone
  };
  try {
      distributedMissionManager.continueMission(parameter, options, (error) => {
          if (error.code != 0) {
              console.error('continueMission failed, cause: ' + JSON.stringify(error))
          }
          console.info('continueMission finished')
      })
  } catch (error) {
      console.error('continueMission failed, cause: ' + JSON.stringify(error))
  }
  ```

## distributedMissionManager.continueMission

continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback): Promise&lt;void&gt;

Continues a mission on a remote device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_MISSIONS and ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](#continuedeviceinfo) | Yes   | Parameters required for mission continuation.|
| options | [ContinueCallback](#continuecallback) | Yes   | Callback invoked when the mission continuation is complete.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  var parameter =  {
      srcDeviceId: "",
      dstDeviceId: "",
      missionId: 1,
      wantParam: {"key": "value"}
  };
  function OnContinueDone(resultCode) {
      console.log('OnContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  var options = {
      OnContinueDone: OnContinueDone
  };
  try {
      distributedMissionManager.continueMission(parameter, options)
      .then(data => {
          console.info('continueMission finished, ' + JSON.stringify(data));
      }).catch(error => {
          console.error('continueMission failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('continueMission failed, cause: ' + JSON.stringify(error))
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
| deviceId    | string  | Yes   | Yes   | Device ID.    |
| fixConflict | boolean | Yes   | Yes   | Whether a version conflict occurs.|
| tag         | number  | Yes   | Yes   | Tag of the mission.   |

## MissionDeviceInfo

Defines the parameters required for registering a listener.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | Yes   | Yes   | Device ID.|

## ContinueDeviceInfo

Defines the parameters required for mission continuation.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| srcDeviceId | string | Yes   | Yes   | ID of the source device.|
| dstDeviceId | string | Yes   | Yes   | ID of the target device.|
| missionId | number | Yes   | Yes   | Mission ID.|
| wantParam | {[key: string]: any} | Yes   | Yes   | Extended parameters.|

## ContinueCallback

Defines the callback invoked when the mission continuation is complete.

**Required permissions**: ohos.permission.MANAGE_MISSIONS

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name                   | Type      | Readable  | Writable  | Description                |
| --------------------- | -------- | ---- | ---- | ------------------ |
| onContinueDone | function | Yes   | No   | Callback used to notify the user that the mission continuation is complete and return the continuation result.    |
