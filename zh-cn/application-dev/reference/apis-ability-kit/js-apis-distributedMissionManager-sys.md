# @ohos.distributedMissionManager (分布式任务管理)(系统接口)

分布式任务管理模块提供跨设备任务管理能力，包括注册和取消任务状态监听、开始和停止同步远端设备任务列表、通过任务ID和包名进行迁移任务等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```js
import { distributedMissionManager } from '@kit.AbilityKit';
```

## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback&lt;void&gt;): void;

注册任务状态监听。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 注册监听时的设备信息。 |
| options   | [MissionCallback](#missioncallback)     | 是    | 注册的回调方法。 |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 回调函数，注册监听成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  // 实现回调函数
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
    // 调用registerMissionListener接口
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

注册任务状态监听。使用promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo)  | 是    | 注册监听时的设备信息。   |
| options   | <a href="#missioncallback">MissionCallback</a> | 是    | 注册的回调方法。|

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // 实现回调函数
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
      // 调用registerMissionListener接口
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

取消任务状态监听。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 注册监听时的设备信息。    |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 回调函数，取消监听成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

取消任务状态监听。使用promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 注册监听时的设备信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

开始同步远端设备的任务列表。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                    | 必填   | 说明        |
| --------- | ------------------------------------- | ---- | --------- |
| parameter | [MissionParameter](#missionparameter) | 是    | 同步信息。     |
| callback  | AsyncCallback&lt;void&gt;             | 是    | 回调函数，同步远端任务列表成功时，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

开始同步远端设备的任务列表。使用promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| parameter | [MissionParameter](#missionparameter) | 是    | 同步信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

停止同步远端设备的任务列表。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 同步信息。     |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 回调函数，停止同步远端任务列表成功时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

停止同步远端设备的任务列表。使用promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo) | 是    | 同步信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

通过指定任务ID（missionId）的方式进行迁移任务。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo-sys.md) | 是    | 迁移信息。 |
| options | [ContinueCallback](js-apis-inner-application-continueCallback-sys.md) | 是    | 迁移任务完成回调函数。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，迁移任务完成时，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[分布式调度错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300502 | Failed to get the missionInfo of the specified missionId. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // 实现回调函数
  function onContinueDone(resultCode: number): void {
    console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  try {
    // 调用continueMission接口
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

通过指定任务ID（missionId）的方式进行迁移任务。使用promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo-sys.md) | 是    | 迁移信息。 |
| options | [ContinueCallback](js-apis-inner-application-continueCallback-sys.md) | 是    | 迁移任务完成回调函数。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |无返回结果的promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[分布式调度错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300502 | Failed to get the missionInfo of the specified missionId. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // 实现回调函数
  function onContinueDone(resultCode: number): void {
    console.log('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  try {
    // 调用continueMission接口
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

通过指定包名（bundleName）的方式进行迁移任务。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo-sys.md) | 是    | 迁移信息。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，通过指定包名迁移任务完成时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[分布式调度错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |
| 16300507 | Failed to get the missionInfo of the specified bundle name. |

**示例：**

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

通过指定包名（bundleName）的方式进行迁移任务。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo-sys.md) | 是    | 迁移信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[分布式调度错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16300501 | The system ability work abnormally. |
| 16300503 | The application is not installed on the remote end and installation-free is not supported. |
| 16300504 | The application is not installed on the remote end but installation-free is supported, try again with freeInstall flag. |
| 16300505 | The operation device must be the device where the application to be continued is located or the target device to be continued. |
| 16300506 | The local continuation task is already in progress. |
| 16300507 | Failed to get the missionInfo of the specified bundle name. |

**示例：**

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

## distributedMissionManager.on('continueStateChange')<sup>10+</sup>

on(type: 'continueStateChange',  callback: Callback&lt;ContinueCallbackInfo&gt;): void

注册当前任务流转状态的监听。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | 是    | 当前任务流转状态，取值为'continueStateChange'。    |
| callback | Callback&lt;[ContinueCallbackInfo](#continuecallbackinfo11)&gt; | 是    | 回调函数，返回当前任务的流转状态和流转信息。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

## distributedMissionManager.off('continueStateChange')<sup>10+</sup>

off(type: 'continueStateChange',  callback?: Callback&lt;ContinueCallbackInfo&gt;): void

取消当前任务流转的状态监听。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | 是    | 当前任务流转状态，取值为'continueStateChange'。    |
| callback | Callback&lt;[ContinueCallbackInfo](#continuecallbackinfo11)&gt; | 否    | 需要取消的回调函数。<br>参数不填写，取消type对应的所有回调监听。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission denied.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

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

开始同步后，建立的回调函数。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称                    | 类型       | 可读   | 可写   | 说明                 |
| --------------------- | -------- | ---- | ---- | ------------------ |
| notifyMissionsChanged | function | 是    | 否    | 通知任务变化，返回设备ID。     |
| notifySnapshot        | function | 是    | 否    | 通知快照变化，返回设备ID，任务ID。 |
| notifyNetDisconnect   | function | 是    | 否    | 通知断开连接，返回设备ID，网络状态。 |

## MissionParameter

同步时所需参数的枚举。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称          | 类型    | 可读   | 可写   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | 是    | 是    | 表示设备ID。详细介绍请参见[getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync)     |
| fixConflict | boolean | 是    | 是    | 表示是否存在版本冲突。 |
| tag         | number  | 是    | 是    | 表示特定的标签。    |

## MissionDeviceInfo

注册监听时所需参数的枚举。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | 是    | 是    | 表示设备ID。详细介绍请参见[getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync) |

## ContinueState<sup>10+</sup>

当前任务流转状态的枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称           | 值       | 说明                                                         |
| ------------- | --------- | ------------------------------------------------------------ |
| ACTIVE        | 0         | 表示当前任务流转处于激活状态。                              |
| INACTIVE      | 1         | 表示当前任务流转处于未激活状态。                            |

## ContinueCallbackInfo<sup>11+</sup>

当前任务流转状态监听的回调信息，包含流转状态和流转信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型    | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| state | [ContinueState](#continuestate10)   | 是    | 否    |   表示当前任务的流转状态。 |
| info  | [ContinuableInfo](./js-apis-inner-application-continuableInfo-sys.md) | 是    | 否    |   表示当前任务的流转信息。 |