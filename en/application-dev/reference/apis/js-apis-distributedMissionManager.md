# Distributed Mission Management

The **distributedMissionManager** module implements system mission management across devices. You can use the APIs provided by this module to register or deregister a mission status listener, and start or stop synchronizing the remote mission list.

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
  	deviceId: remoteDeviceId
  };
  var options = {
      notifyMissionsChanged: NotifyMissionsChanged,
      notifySnapshot: NotifySnapshot,
      notifyNetDisconnect: NotifyNetDisconnect
  }
  distributedMissionManager.registerMissionListener(parameter, options, (error) => {
      console.log("error.code = " + error.code)
  })
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
  	deviceId: remoteDeviceId
  };
  var options = {
      notifyMissionsChanged: NotifyMissionsChanged,
      notifySnapshot: NotifySnapshot,
      notifyNetDisconnect: NotifyNetDisconnect
  }
  distributedMissionManager.registerMissionListener(parameter, options)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
  ```


## distributedMissionManager.unregisterMissionListener

unregisterMissionListener(parameter: MissionDeviceInfo, callback: AsyncCallback&lt;void&gt;): void;

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
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.unregisterMissionListener(parameter, (error) => {
      console.log("error.code = " + error.code)
  })
  ```


## distributedMissionManager.unregisterMissionListener

unregisterMissionListener(parameter: MissionDeviceInfo): Promise&lt;void&gt;

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
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.unregisterMissionListener(parameter)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
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
  	deviceId: remoteDeviceId,
      fixConflict: false, 
      tag: 0
  };
  distributedMissionManager.startSyncRemoteMissions(parameter, (error) => {
      console.log("error.code = " + error.code)
  })
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
  	deviceId: remoteDeviceId,
      fixConflict: false, 
      tag: 0
  };
  distributedMissionManager.startSyncRemoteMissions(parameter)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
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
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.stopSyncRemoteMissions(parameter, (error) => {
      console.log("error.code = " + error.code)
  })
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
  	deviceId: remoteDeviceId
  };
  distributedMissionManager.stopSyncRemoteMissions(parameter)
  .then(data => {
      console.info('success data is ' + data);
  }).catch(error => {
      console.info('error error is ' + error);
  })
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
