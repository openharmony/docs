# @ohos.continuation.continuationManager (continuationManager)

continuationManager模块提供了流转/协同入口管理服务能力，包括连接/取消流转管理服务，注册/解注册设备连接变化监听，拉起设备选择模块，更新连接状态。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import continuationManager from '@ohos.continuation.continuationManager'
```

## continuationManager.on("deviceSelected")<sup>9+</sup>

on(type: "deviceSelected", token: number, callback: Callback\<Array\<ContinuationResult>>): void

异步方法，监听设备连接状态，使用Callback形式返回连接的设备信息。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听的事件类型，固定值"deviceSelected"。 |
  | token | number | 是 | 注册后的token。 |
  | callback | Callback\<Array\<[ContinuationResult](js-apis-continuation-continuationResult.md)>> | 是 | 当用户从设备选择模块中选择设备时调用，返回设备ID、设备类型和设备名称供开发者使用。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';

  let token: number = 1;
  try {
    continuationManager.on("deviceSelected", token, (data) => {
      console.info('onDeviceSelected len: ' + data.length);
      for (let i = 0; i < data.length; i++) {
        console.info('onDeviceSelected deviceId: ' + JSON.stringify(data[i].id));
        console.info('onDeviceSelected deviceType: ' + JSON.stringify(data[i].type));
        console.info('onDeviceSelected deviceName: ' + JSON.stringify(data[i].name));
      }
    });
  } catch (err) {
    console.error('on failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.on("deviceUnselected")<sup>9+</sup>

on(type: "deviceUnselected", token: number, callback: Callback\<Array\<ContinuationResult>>): void

异步方法，监听设备断开状态，使用Callback形式返回断开的设备信息。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听的事件类型，固定值"deviceUnselected"。 |
  | token | number | 是 | 注册后的token。 |
  | callback | Callback\<Array\<[ContinuationResult](js-apis-continuation-continuationResult.md)>> | 是 | 当用户从设备选择模块中断开设备时调用，返回设备ID、设备类型和设备名称供开发者使用。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';

  let token: number = 1;
  try {
    continuationManager.on("deviceUnselected", token, (data) => {
      console.info('onDeviceUnselected len: ' + data.length);
      for (let i = 0; i < data.length; i++) {
        console.info('onDeviceUnselected deviceId: ' + JSON.stringify(data[i].id));
        console.info('onDeviceUnselected deviceType: ' + JSON.stringify(data[i].type));
        console.info('onDeviceUnselected deviceName: ' + JSON.stringify(data[i].name));
      }
      console.info('onDeviceUnselected finished.');
    });
  } catch (err) {
    console.error('on failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.off("deviceSelected")<sup>9+</sup>

off(type: "deviceSelected", token: number): void

取消监听设备连接状态。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消监听的事件类型，固定值"deviceSelected"。 |
  | token | number | 是 | 注册后的token。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';

  let token: number = 1;
  try {
    continuationManager.off("deviceSelected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.off("deviceUnselected")<sup>9+</sup>

off(type: "deviceUnselected", token: number): void

取消监听设备断开状态。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消监听的事件类型，固定值"deviceUnselected"。 |
  | token | number | 是 | 注册后的token。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |
| 16600004 | The specified callback has been registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';

  let token: number = 1;
  try {
    continuationManager.off("deviceUnselected", token);
  } catch (err) {
    console.error('off failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.startContinuationDeviceManager<sup>9+</sup>

startContinuationDeviceManager(token: number, callback: AsyncCallback\<void>): void

拉起设备选择模块，可显示组网内可选择设备列表信息，无过滤条件，使用AsyncCallback方式作为异步方法。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | callback | AsyncCallback\<void> | 是 | 回调函数。当模块选择完成，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';

  let token: number = -1;
  try {
    continuationManager.startContinuationDeviceManager(token, (err) => {
      if (err.code != 0) {
        console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('startContinuationDeviceManager finished. ');
    });
  } catch (err) {
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.startContinuationDeviceManager<sup>9+</sup>

startContinuationDeviceManager(token: number, options: ContinuationExtraParams, callback: AsyncCallback\<void>): void

拉起设备选择模块，可显示组网内可选择设备列表信息，使用AsyncCallback方式作为异步方法。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | 是 | 过滤可选择设备列表的额外参数。 |
  | callback | AsyncCallback\<void> | 是 | 回调函数。当模块选择完成，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';

  let token: number = -1;
  try {
    continuationManager.startContinuationDeviceManager(
      token,
      {
        deviceType: ["00E"]
      },
      (err) => {
        if (err.code != 0) {
          console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
          return;
        }
        console.info('startContinuationDeviceManager finished. ');
    });
  } catch (err) {
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.startContinuationDeviceManager<sup>9+</sup>

startContinuationDeviceManager(token: number, options?: ContinuationExtraParams): Promise\<void>

拉起设备选择模块，可显示组网内可选择设备列表信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | options | [ContinuationExtraParams](js-apis-continuation-continuationExtraParams.md) | 否 | 过滤可选择设备列表的额外参数，该参数可缺省|

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise形式返回接口调用结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';
  import { BusinessError } from '@ohos.base';

  let token: number = -1;
  try {
    continuationManager.startContinuationDeviceManager(
      token,
      {
        deviceType: ["00E"]
      }).then(() => {
        console.info('startContinuationDeviceManager finished. ');
      }).catch((err: BusinessError) => {
        console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
      });
  } catch (err) {
    console.error('startContinuationDeviceManager failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.updateContinuationState<sup>9+</sup>

updateContinuationState(token: number, deviceId: string, status: DeviceConnectState, callback: AsyncCallback\<void>): void

通知设备选择模块，更新当前的连接状态，使用AsyncCallback方式作为异步方法。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | deviceId | string | 是 | 设备ID。 |
  | status | [DeviceConnectState](#deviceconnectstate) | 是 | 设备连接状态。 |
  | callback | AsyncCallback\<void> | 是 | 回调函数。当通知设备成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';

  let token: number = 1;
  let deviceId: string = "test deviceId";
  try {
    continuationManager.updateContinuationState(token, deviceId, continuationManager.DeviceConnectState.CONNECTED, (err) => {
      if (err.code != 0) {
        console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
        return;
      }
      console.info('updateContinuationState finished. ');
    });
  } catch (err) {
    console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
  }
  ```

## continuationManager.updateContinuationState<sup>9+</sup>

updateContinuationState(token: number, deviceId: string, status: DeviceConnectState): Promise\<void>

通知设备选择模块，更新当前的连接状态，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | number | 是 | 注册后的token。 |
  | deviceId | string | 是 | 设备ID。 |
  | status | [DeviceConnectState](#deviceconnectstate) | 是 | 设备连接状态。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise形式返回接口调用结果。 |

**错误码：**

以下错误码的详细介绍请参见[分布式调度错误码](../errorcodes/errorcode-DistributedSchedule.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 16600001 | The system ability works abnormally. |
| 16600002 | The specified token or callback is not registered. |

**示例：**

  ```ts
  import continuationManager from '@ohos.continuation.continuationManager';
  import { BusinessError } from '@ohos.base';

  let token: number = 1;
  let deviceId: string = "test deviceId";
  try {
    continuationManager.updateContinuationState(token, deviceId, continuationManager.DeviceConnectState.CONNECTED)
      .then(() => {
        console.info('updateContinuationState finished. ');
      })
      .catch((err: BusinessError) => {
        console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
      });
  } catch (err) {
    console.error('updateContinuationState failed, cause: ' + JSON.stringify(err));
  }
  ```

## DeviceConnectState

设备连接状态。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| IDLE | 0 | 设备连接初始状态。 |
| CONNECTING | 1 | 设备连接中状态。 |
| CONNECTED | 2 | 设备已连接状态。 |
| DISCONNECTING | 3 | 设备断开连接状态。 |

## ContinuationMode

设备选择模块连接模式。

**系统能力**：SystemCapability.Ability.DistributedAbilityManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| COLLABORATION_SINGLE | 0 | 设备选择模块单选模式。 |
| COLLABORATION_MULTIPLE | 1 | 设备选择模块多选模式。 |