# @ohos.distributedMissionManager (分布式任务管理)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: DistributedAbilityManager-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @hanjiawei-->
<!--Adviser: @hu-zhiqiong-->

分布式任务管理模块提供跨设备任务管理能力，包括注册和取消任务状态监听、开始和停止同步远端设备任务列表、通过任务ID和包名进行迁移任务等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```js
import { distributedMissionManager } from '@kit.AbilityKit';
```

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback, callback: AsyncCallback&lt;void&gt;): void;

注册任务状态监听。使用callback异步回调。调用成功后，系统将开始监听指定设备上的任务状态变化，该监听需与 `unRegisterMissionListener` 成对使用，注册后应在不需要监听任务状态时及时调用 `unRegisterMissionListener` 取消监听，以释放资源。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo10) | 是    | 注册监听时的设备信息，deviceId为设备标识符。 |
| options   | [MissionCallback](#missioncallback10)     | 是    | 注册的回调方法。 |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 回调函数，注册监听完成时err为undefined，否则为错误对象。 |

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
    console.info('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
  }
  function NotifySnapshot(deviceId: string, missionId: number): void {
    console.info('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
    console.info('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId: string, state: number): void {
    console.info('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
    console.info('NotifyNetDisconnect state ' + JSON.stringify(state));
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
          console.error(`Failed to register mission listener. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('registerMissionListener finished');
      });
     } catch (error) {
    console.error(`Failed to register mission listener. Code: ${error.code}, message: ${error.message}`);
  }
  ```
## distributedMissionManager.registerMissionListener

registerMissionListener(parameter: MissionDeviceInfo, options: MissionCallback): Promise&lt;void&gt;

注册任务状态监听。使用Promise异步回调。调用成功后，系统将开始监听指定设备上的任务状态变化，该监听需与 `unRegisterMissionListener` 成对使用，注册后应在不需要监听任务状态时及时调用 `unRegisterMissionListener` 取消监听，以释放资源。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo10)  | 是    | 注册监听时的设备信息，deviceId为设备标识符。   |
| options   | [MissionCallback](#missioncallback10) | 是    | 注册的回调方法。|

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 返回的Promise对象，操作成功时表示任务状态监听已成功注册，失败时返回错误信息。 |

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
    console.info('NotifyMissionsChanged deviceId ' + JSON.stringify(deviceId));
   }
  function NotifySnapshot(deviceId: string, missionId: number): void {
    console.info('NotifySnapshot deviceId ' + JSON.stringify(deviceId));
    console.info('NotifySnapshot missionId ' + JSON.stringify(missionId));
  }
  function NotifyNetDisconnect(deviceId: string, state: number): void {
    console.info('NotifyNetDisconnect deviceId ' + JSON.stringify(deviceId));
    console.info('NotifyNetDisconnect state ' + JSON.stringify(state));
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

取消任务状态监听。使用callback异步回调。停止监听前，请确保已通过 registerMissionListener 完成注册，否则调用无效。成功调用后，系统将不再监听该设备上的任务状态变化。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo10) | 是    | 取消监听时指定的设备信息，deviceId为设备标识符。    |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 回调函数，取消监听完成时err为undefined，否则为错误对象。|

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
    // 取消任务状态监听
    distributedMissionManager.unRegisterMissionListener(
      { deviceId: "" },
      (error: BusinessError) => {
        if (error) {
            console.error(`unRegisterMissionListener failed. Code: ${error.code}, message: ${error.message}`);
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

取消任务状态监听。使用Promise异步回调。停止监听前，请确保已通过 registerMissionListener 完成注册，否则调用无效。成功调用后，系统将不再监听该设备上的任务状态变化。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo10) | 是    | 取消监听时的设备信息，deviceId为设备标识符。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |返回的Promise对象，操作成功时表示任务状态监听已成功取消，失败时返回错误信息。|

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
        console.error(`unRegisterMissionListener failed. Code: ${error.code}, message: ${error.message}`);
    });
  } catch (error) {
      console.error('unRegisterMissionListener failed, cause: ' + JSON.stringify(error));
  }
  ```

## distributedMissionManager.startSyncRemoteMissions

startSyncRemoteMissions(parameter: MissionParameter, callback: AsyncCallback&lt;void&gt;): void;

开始同步远端设备的任务列表。使用callback异步回调。使用时须与 stopSyncRemoteMissions 严格配对，按“先启动、后停止”的顺序执行，同步完成后应立即停止以释放系统资源。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明        |
| --------- | ------------------------------------- | ---- | --------- |
| parameter | [MissionParameter](#missionparameter10) | 是    | 同步信息，包含deviceId、fixConflict和tag字段。tag为同步标识，用于区分不同同步会话，取值需满足场景需求。fixConflict表示是否解决冲突，建议在可能存在任务冲突的场景下设置为true以避免任务冲突问题。|
| callback  | AsyncCallback&lt;void&gt;             | 是    | 回调函数，同步远端任务列表完成时err为undefined，否则返回错误对象。 |

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
    // 开始同步远端设备的任务列表
    distributedMissionManager.startSyncRemoteMissions(
      {
        deviceId: "",
        fixConflict: false,
        tag: 0
      },
      (error: BusinessError) => {
        if (error) {
          console.error(`startSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('startSyncRemoteMissions finished');}
    )
  } catch (error) {
    console.error(`startSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.startSyncRemoteMissions

startSyncRemoteMissions(parameter: MissionParameter): Promise&lt;void&gt;

开始同步远端设备的任务列表。使用Promise异步回调。使用时须与 stopSyncRemoteMissions 严格配对，按“先启动、后停止”的顺序执行，同步完成后应立即停止以释放系统资源。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| parameter | [MissionParameter](#missionparameter10) | 是    | 同步信息，包含deviceId、fixConflict和tag字段。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 返回的Promise对象，操作成功时表示远端设备任务列表同步已成功启动，失败时返回错误信息。|

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
      console.error(`startSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
    });
  } catch (error) {
    console.error(`startSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.stopSyncRemoteMissions

stopSyncRemoteMissions(parameter: MissionDeviceInfo, callback: AsyncCallback&lt;void&gt;): void;

调用该接口停止同步远端设备的任务列表。使用callback异步回调。调用成功后，系统将停止同步指定远端设备的任务列表。需先调用 startSyncRemoteMissions 启动同步后再调用，未启动同步时调用不生效。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明        |
| --------- | --------------------------------------- | ---- | --------- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo10) | 是    | 停止同步的设备信息，deviceId为要停止同步的远端设备ID。   |
| callback  | AsyncCallback&lt;void&gt;               | 是    | 回调函数，停止同步远端任务列表完成时err为undefined，否则为错误对象。 |

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
    // 停止同步远端设备的任务列表
    distributedMissionManager.stopSyncRemoteMissions(
      {
        deviceId: ""
      },
      (error: BusinessError) => {
        if (error) {
          console.error(`stopSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('stopSyncRemoteMissions finished');}
    )
  } catch (error) {
    console.error(`stopSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.stopSyncRemoteMissions

stopSyncRemoteMissions(parameter: MissionDeviceInfo): Promise&lt;void&gt;

停止同步远端设备的任务列表。使用Promise异步回调。调用成功后，系统将停止同步指定远端设备的任务列表。需先调用 startSyncRemoteMissions 启动同步后再调用，未启动同步时调用不生效。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [MissionDeviceInfo](#missiondeviceinfo10) | 是    | 停止同步的设备信息，deviceId为要停止同步的远端设备ID。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 返回的Promise对象，操作成功时表示远端设备任务列表同步已成功停止，失败时返回错误信息。|

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
      console.error(`stopSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
    });
  } catch (error) {
    console.error(`stopSyncRemoteMissions failed. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.continueMission

continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback, callback: AsyncCallback&lt;void&gt;): void;

通过指定任务ID（missionId）的方式进行迁移任务。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo-sys.md) | 是    | 通过任务ID方式迁移时的迁移信息，包含源设备ID、目标设备ID、任务ID等。 |
| options | [ContinueCallback](js-apis-inner-application-continueCallback-sys.md) | 是    | 通过任务ID方式迁移任务完成时的回调函数，用于接收迁移结果。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，迁移任务完成时err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[DistributedSchedule错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // 实现回调函数
  function onContinueDone(resultCode: number): void {
    console.info('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  try {
    // 通过任务ID方式迁移任务
    // missionId需通过系统API获取实际任务ID
    distributedMissionManager.continueMission(
      {
        srcDeviceId: '',
        dstDeviceId: '',
        missionId: 1,
        wantParam: {'key': 'value'}
      },
      { onContinueDone: onContinueDone },
      (error: BusinessError) => {
        if (error) {
          console.error(`continueMission failed. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('continueMission finished');
    })
  } catch (error) {
    console.error(`continueMission failed. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.continueMission

continueMission(parameter: ContinueDeviceInfo, options: ContinueCallback): Promise&lt;void&gt;

通过指定任务ID（missionId）的方式将任务从源设备迁移到目标设备。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueDeviceInfo](js-apis-inner-application-continueDeviceInfo-sys.md) | 是    | 迁移信息，包含源设备ID、目标设备ID、任务ID和自定义参数等字段。 |
| options | [ContinueCallback](js-apis-inner-application-continueCallback-sys.md) | 是    | 迁移任务完成回调函数。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; |返回的Promise对象，操作成功时表示通过任务ID方式迁移任务已完成，失败时返回错误信息。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[DistributedSchedule错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // 实现回调函数
  function onContinueDone(resultCode: number): void {
    console.info('onContinueDone resultCode: ' + JSON.stringify(resultCode));
  };
  try {
    // 通过任务ID方式迁移任务
    // missionId需通过系统API获取实际任务ID
    distributedMissionManager.continueMission(
      {
        srcDeviceId: '',
        dstDeviceId: '',
        missionId: 1,
        wantParam: {'key': 'value'}
      },
      { onContinueDone: onContinueDone }).then(() => {
        console.info('continueMission finished successfully');
      }).catch((error: BusinessError) => {
      console.error(`continueMission failed. Code: ${error.code}, message: ${error.message}`);
    });
  } catch (error) {
    console.error(`continueMission failed. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.continueMission<sup>10+</sup>

continueMission(parameter: ContinueMissionInfo, callback: AsyncCallback&lt;void&gt;): void;

通过指定包名（bundleName）的方式将指定应用的任务从源设备迁移到目标设备。使用callback异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo-sys.md) | 是    | 迁移信息，包含源设备ID、目标设备ID、应用包名和自定义参数等字段。|
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，通过指定包名迁移任务完成时，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[DistributedSchedule错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    distributedMissionManager.continueMission(
      {
        srcDeviceId: '',
        dstDeviceId: '',
        bundleName: 'ohos.test.continueapp',
        wantParam: {'key': 'value'}
      },
      (error: BusinessError) => {
        if (error) {
          console.error(`continueMission failed. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('continueMission finished');
    })
  } catch (error) {
    console.error(`continueMission failed. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.continueMission<sup>10+</sup>

continueMission(parameter: ContinueMissionInfo): Promise&lt;void&gt;

通过指定包名（bundleName）的方式将指定应用的任务从源设备迁移到目标设备。使用Promise异步回调。

**需要权限**：ohos.permission.MANAGE_MISSIONS，ohos.permission.DISTRIBUTED_DATASYNC

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| parameter | [ContinueMissionInfo](./js-apis-inner-application-continueMissionInfo-sys.md) | 是    | 迁移信息，包含源设备ID、目标设备ID、应用包名和自定义参数等字段。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 返回的Promise对象，操作成功时表示通过包名方式迁移任务已完成，失败时返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[DistributedSchedule错误码](./errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
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

**示例：**

  ```ts
  import { distributedMissionManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
      distributedMissionManager.continueMission(
        {
          srcDeviceId: '',
          dstDeviceId: '',
          bundleName: 'ohos.test.continueapp',
          wantParam: {"key": "value"}
        }
      ).then(() => {
          console.info('continueMission finished successfully');
      }).catch((error: BusinessError) => {
          console.error(`Failed to continue mission. Code: ${error.code}, message: ${error.message}`);
      });
  } catch (error) {
      console.error(`Failed to continue mission. Code: ${error.code}, message: ${error.message}`);
  }
  ```

## distributedMissionManager.on('continueStateChange')<sup>10+</sup>

on(type: 'continueStateChange',  callback: Callback&lt;ContinueCallbackInfo&gt;): void

注册当前任务流转状态变化事件的监听。此接口需与 `off('continueStateChange')` 成对使用，不再监听时应及时取消；调用顺序为先通过 `on` 注册监听，不需要时再调用 `off` 取消监听。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | 是    | 订阅的事件类型，取值为'continueStateChange'，表示订阅任务流转状态变化事件。 |
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
    // 注册任务流转状态变化事件监听
    distributedMissionManager.on('continueStateChange', (data) => {
      console.info("continueStateChange on:" + JSON.stringify(data));
    });
  } catch (error) {
    console.error(`continueStateChange failed. Code: ${error.code}, message: ${error.message}`);
  }
```

## distributedMissionManager.off('continueStateChange')<sup>10+</sup>

off(type: 'continueStateChange',  callback?: Callback&lt;ContinueCallbackInfo&gt;): void

取消当前任务流转的状态监听。此接口需与 `on('continueStateChange')` 成对使用，在不需要监听时应及时调用以释放资源。

**需要权限**：ohos.permission.MANAGE_MISSIONS

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**参数：**

| 参数名       | 类型                                       | 必填   | 说明       |
| --------- | ---------------------------------------- | ---- | -------- |
| type | string  | 是    | 取消订阅的事件类型，固定取值为'continueStateChange'，表示取消订阅任务流转状态变化事件。    |
| callback | Callback&lt;[ContinueCallbackInfo](#continuecallbackinfo11)&gt; | 否    | 需要取消的回调函数。<br>当需要取消特定回调监听时传入callback参数，当需要取消type对应的所有回调监听时不传callback参数。不传入时将取消该事件类型的所有回调监听。|

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
    // 取消任务流转状态变化事件监听
    distributedMissionManager.off('continueStateChange', (data) => {
      console.info("continueStateChange off:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error(`continueStateChange failed. Code: ${err.code}, message: ${err.message}`);
  }
```

## MissionCallback<sup>10+</sup>

type MissionCallback = _MissionCallback

用于监听任务状态变化的回调函数，包含任务列表变化通知、任务快照通知和断开连接通知等功能。作为[registerMissionListener](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerregistermissionlistener)的入参，表示注册监听后建立的回调函数。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

| 类型 | 说明 |
| --- | --- |
| [_MissionCallback](js-apis-inner-application-missionCallbacks-sys.md) | 用于监听任务状态变化的回调函数，包含任务列表变化通知、任务快照通知和断开连接通知等功能。作为registerMissionListener的入参，表示注册监听后建立的回调函数。|

## MissionParameter<sup>10+</sup>

type MissionParameter = _MissionParameter

同步远程任务列表时所需的参数对象，包含deviceId、fixConflict和tag等字段。作为[startSyncRemoteMissions](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerstartsyncremotemissions)的入参。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

| 类型 | 说明 |
| --- | --- |
| [_MissionParameter](js-apis-inner-application-missionParameter-sys.md) | 同步远端设备任务列表时所需的参数对象，包含deviceId、fixConflict和tag等字段。|

## MissionDeviceInfo<sup>10+</sup>

type MissionDeviceInfo = _MissionDeviceInfo

注册任务状态监听时所需的设备信息对象，包含deviceId等设备标识符字段。作为[registerMissionListener](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerregistermissionlistener)的入参。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

| 类型 | 说明 |
| --- | --- |
| [_MissionDeviceInfo](js-apis-inner-application-missionDeviceInfo-sys.md) | 注册监听时所需的设备信息对象，包含deviceId字段。 |

## ContinueState<sup>10+</sup>

当前任务流转状态的枚举。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

| 名称           | 值       | 说明                                                         |
| ------------- | --------- | ------------------------------------------------------------ |
| ACTIVE        | 0         | 表示当前任务流转处于激活状态。                              |
| INACTIVE      | 1         | 表示当前任务流转处于未激活状态。                            |

## ContinueCallbackInfo<sup>11+</sup>

任务流转状态监听回调时返回的信息对象，包含state（流转状态）和info（流转详细信息）两个字段。state为ACTIVE表示流转处于激活状态，INACTIVE表示流转处于未激活状态。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

| 名称       | 类型    | 只读   | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| state | [ContinueState](#continuestate10)   | 否    | 否    |   表示当前任务的流转状态，取值为ACTIVE（激活）或INACTIVE（未激活），根据任务实际流转状态设置。 |
| info  | [ContinuableInfo](./js-apis-inner-application-continuableInfo-sys.md) | 否    | 否    |  表示当前任务的流转信息。 |