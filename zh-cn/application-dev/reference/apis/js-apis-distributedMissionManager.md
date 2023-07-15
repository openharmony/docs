# @ohos.distributedMissionManager (分布式任务管理)

分布式任务管理模块提供跨设备系统任务管理能力，包括注册系统任务状态监听、取消系统任务状态监听、开始同步远端任务列表、停止同步远端任务列表、迁移任务操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```js
import distributedMissionManager from '@ohos.distributedMissionManager'
```


## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback&lt;void&gt;): void;

注册系统任务状态监听，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 注册监听设备信息。 |
| options   | [MissionCallback](#missioncallback)     | 是    | 注册的回调方法。  |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 执行结果回调函数。 |

**示例：**

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

注册系统任务状态监听，以promise的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo)  | 是    | 设备信息。    |
| options   | <a href="#missioncallback">MissionCallback</a> | 是    | 注册的回调方法。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | promise方式返回执行结果。 |

**示例：**

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

取消任务状态监听, 以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 设备信息。     |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 执行结果回调函数。 |

**示例：**

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

取消任务状态监听，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 设备信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | promise方式返回执行结果。 |

**示例：**

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

开始同步远端任务列表, 以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                    | 必填   | 说明        |
| --------- | ------------------------------------- | ---- | --------- |
| parameter | [MissionParameter](#missionparameter) | 是    | 同步信息。     |
| callback  | AsyncCallback&lt;void&gt;             | 是    | 执行结果回调函数。 |

**示例：**

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

开始同步远端任务列表，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| parameter | [MissionParameter](#missionparameter) | 是    | 同步信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | promise方式返回执行结果。 |

**示例：**

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

停止同步远端任务列表, 以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 同步信息。     |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 执行结果回调函数。 |

**示例：**

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

停止同步远端任务列表，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 同步信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | promise方式返回执行结果。 |

**示例：**

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

迁移任务，以回调函数的方式返回。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo.md) | 是    | 迁移信息。 |
| options | [ContinueCallback](js-apis-inner-application-continueCallback.md) | 是    | 迁移任务完成回调函数。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 执行结果回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16300501 | The system ability work abnormally. |
| 16300502 | Failed to get the missionInfo of the specified missionId. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |

**示例：**

  ```ts
  var parameter =  {
      srcDeviceId: "",
      dstDeviceId: "",
      missionId: 1,
      wantParam: {"key": "value"}
  };
  function onContinueDone(resultCode) {
      console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  var options = {
      onContinueDone: onContinueDone
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

迁移任务，以promise方式返回执行结果。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo.md) | 是    | 迁移信息。 |
| options | [ContinueCallback](js-apis-inner-application-continueCallback.md) | 是    | 迁移任务完成回调函数。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16300501 | The system ability work abnormally. |
| 16300502 | Failed to get the missionInfo of the specified missionId. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |

**示例：**

  ```ts
  var parameter =  {
      srcDeviceId: "",
      dstDeviceId: "",
      missionId: 1,
      wantParam: {"key": "value"}
  };
  function onContinueDone(resultCode) {
      console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  var options = {
      onContinueDone: onContinueDone
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

## distributedMissionManager.continueMission<sup>10+</sup>

continueMission(parameter: ContinueMissionInfo, callback: AsyncCallback&lt;void&gt;): void;

通过指定包名的方式进行迁移任务，使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo.md) | 是    | 迁移信息。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 迁移任务完成回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16300501 | The system ability work abnormally. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |
| 16300507 | Failed to get the missionInfo of the specified bundle name. |

**示例：**

  ```ts
  var parameter =  {
      srcDeviceId: "",
      dstDeviceId: "",
      bundleName: "ohos.test.continueapp",
      wantParam: {"key": "value"}
  };
  try {
      distributedMissionManager.continueMission(parameter, (error) => {
          if (error.code != 0) {
              console.error('continueMission failed, cause: ' + JSON.stringify(error))
          }
          console.info('continueMission finished')
      })
  } catch (error) {
      console.error('continueMission failed, cause: ' + JSON.stringify(error))
  }
  ```

## distributedMissionManager.continueMission<sup>10+</sup>

continueMission(parameter: ContinueMissionInfo): Promise&lt;void&gt;

通过指定包名的方式进行迁移任务，使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo.md) | 是    | 迁移信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | promise方式返回执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16300501 | The system ability work abnormally. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |
| 16300507 | Failed to get the missionInfo of the specified bundle name. |

**示例：**

  ```ts
  var parameter =  {
      srcDeviceId: "",
      dstDeviceId: "",
      bundleName: "ohos.test.continueapp",
      wantParam: {"key": "value"}
  };
  try {
      distributedMissionManager.continueMission(parameter)
      .then(data => {
          console.info('continueMission finished, ' + JSON.stringify(data));
      }).catch(error => {
          console.error('continueMission failed, cause: ' + JSON.stringify(error));
      })
  } catch (error) {
      console.error('continueMission failed, cause: ' + JSON.stringify(error))
  }
  ```

## distributedMissionManager.on('continueStateChange')<sup>10+</sup>

on(type: 'continueStateChange',  callback: Callback&lt;{ state: ContinueState, info: ContinuableInfo }&gt;): void

注册当前应用任务流转状态的监听。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | 是    | 注册当前应用任务流转的状态监听，取值为continueStateChange    |
| callback | Callback&lt;{&nbsp;state:&nbsp;[ContinueState](#continuestate10),&nbsp;info:&nbsp;[ContinuableInfo](./js-apis-inner-application-continuableInfo.md)&nbsp;}&gt; | 是    | 指示要注册的应用任务流转状态监听的回调，返回应用任务流转状态和流转信息。      |

**示例：**

```js
  try {
    distributedMissionManager.on('continueStateChange', (data) => {
      console.info("continueStateChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("continueStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## distributedMissionManager.off('continueStateChange')<sup>10+</sup>

off(type: 'continueStateChange',  callback?: Callback&lt;{ state: ContinueState, info: ContinuableInfo }&gt;): void

取消当前应用任务流转的状态监听。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | 是    | 取消当前应用任务流转的状态监听，取值为continueStateChange    |
| callback | Callback&lt;{&nbsp;state:&nbsp;[ContinueState](#continuestate10),&nbsp;info:&nbsp;[ContinuableInfo](./js-apis-inner-application-continuableInfo.md)&nbsp;}&gt; | 否    | 指示要取消的应用任务流转状态监听的回调。      |

**示例：**

```js
  try {
    distributedMissionManager.off('continueStateChange', (data) => {
      console.info("continueStateChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("continueStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## MissionCallback

表示开始同步后，建立的回调函数。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称                    | 类型       | 可读   | 可写   | 说明                 |
| --------------------- | -------- | ---- | ---- | ------------------ |
| notifyMissionsChanged | function | 是    | 否    | 通知任务变化，返回设备ID。     |
| notifySnapshot        | function | 是    | 否    | 通知快照变化，返回设备ID，任务ID |
| notifyNetDisconnect   | function | 是    | 否    | 通知断开连接，返回设备ID，网络状态 |

## MissionParameter

表示同步时所需参数的枚举。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称          | 类型    | 可读   | 可写   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | 是    | 是    | 表示设备ID。     |
| fixConflict | boolean | 是    | 是    | 表示是否存在版本冲突。 |
| tag         | number  | 是    | 是    | 表示特定的标签。    |

## MissionDeviceInfo

表示注册监听时所需参数的枚举。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | 是    | 是    | 表示设备ID。 |

## ContinueState<sup>10+</sup>

ContinueState说明枚举，表示当前应用任务流转的状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称           | 值       | 说明                                                         |
| ------------- | --------- | ------------------------------------------------------------ |
| ACTIVE        | 0         | 表示当前应用任务流转处于激活状态。                              |
| INACTIVE      | 1         | 表示当前应用任务流转处于未激活状态。                            |