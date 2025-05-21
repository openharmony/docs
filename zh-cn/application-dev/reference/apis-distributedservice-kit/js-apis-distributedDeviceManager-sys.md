# @ohos.distributedDeviceManager (设备管理)(系统接口)

本模块提供分布式设备管理能力。

应用可调用接口实现如下功能：

- 注册和解除注册设备上下线变化监听。
- 发现周边不可信设备。
- 认证和取消认证设备。
- 查询可信设备列表。
- 查询本地设备信息，包括设备名称，设备类型和设备标识等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.distributedDeviceManager (设备管理)](js-apis-distributedDeviceManager.md)。

## 导入模块

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
```

## StrategyForHeartbeat<sup>15+</sup>

表示心跳广播策略。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称         | 值  | 说明              |
| ----------- | ---- | --------------- |
| TEMP_STOP_HEARTBEAT      | 100    | 临时停止心跳广播，超时后自动恢复。             |
| START_HEARTBEAT          | 101    | 开始心跳广播。                               |

## DeviceProfileInfoFilterOptions<sup>15+</sup>

设备配置文件信息过滤器选项。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称         | 类型  | 必填              |  说明    |
| ----------- | ---- | --------------- | ------- |
| isCloud      | boolean    |   是           | 是否向云端请求数据。       |
| deviceIdList  | Array&lt;string&gt;  | 否    | 设备Id列表。       |

## DeviceProfileInfo<sup>15+</sup>

设备配置文件信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 必填              |  说明    |
| -------------- | ---- | --------------- | --------|
|  deviceId      | string  | 是   |  设备ID。          |
|  deviceSn      | string  | 是   |  设备序列号。      |
|  mac           | string  | 是   |  MAC地址。         |
|  model         | string  | 是   |  设备型号。         |
|  deviceType    | string  | 是   |  设备类型。         |
|  manufacturer  | string  | 是   |  制造商。           |
|  deviceName    | string  | 是   |  设备名称。         |
|  productId     | string  | 是   |  产品ID。           |
|  subProductId  | string  | 否   |  产品子ID。         |
|  sdkVersion    | string  | 是   |  SDK版本。          |
|  bleMac        | string  | 是   |  蓝牙BLE的MAC地址。  |
|  brMac         | string  | 是   |  蓝牙BR的MAC地址。  |
|  sleMac        | string  | 是   |  Starflash的MAC地址。 |
|  firmwareVersion | string | 是  |  固件版本。          |
|  hardwareVersion | string | 是  |  硬件版本。          |
|  softwareVersion | string | 是  |  软件版本。          |
|  protocolType    | number | 是  |  协议类型。          |
|  setupType       | number | 是  |  设备类型。          |
|  wiseDeviceId    | string | 是  |  智能设备ID。        |
|  wiseUserId      | string | 是  |  智能用户ID。        |
|  registerTime    | string | 是  |  注册时间。          |
|  modifyTime      | string | 是  |  修改时间。          |
|  shareTime       | string | 是  |  分享时间。          |
|  isLocalDevice   | boolean | 是 |  是否为本地设备。     |
|  services        | Array&lt;ServiceProfileInfo&gt; | 否  | 业务模板信息列表。 |
|  productName     | string  | 否 |  设备所属的产品名称。    |
|  internalModel   | string  | 否 |  设备所属产品的内部型号。 |

## DeviceManager

设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。

### replyUiAction

replyUiAction(action: number, actionResult: string): void

回复用户UI操作行为。此接口只能被devicemanager的PIN码hap使用。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | action        | number          | 是    | 用户操作动作。<br />-0：允许授权。<br />-1：取消授权。<br />-2：授权框用户操作超时。<br />-3：取消pin码框展示。<br />-4：取消pin码输入框展示。<br />-5：pin码输入框确定操作。     |
  | actionResult        | string          | 是    | 表示用户操作结果，长度范围1~255字符。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified actionResult is greater than 255. |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

 try {
    /*
      action = 0 - 允许授权
      action = 1 - 取消授权
      action = 2 - 授权框用户操作超时
      action = 3 - 取消pin码框展示
      action = 4 - 取消pin码输入框展示
      action = 5 - pin码输入框确定操作
    */
    let operation = 0;
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.replyUiAction(operation, 'extra');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyUiAction errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### on('replyResult')

on(type: 'replyResult', callback: Callback&lt;{ param: string;}&gt;): void

回复UI操作结果回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名      | 类型                             | 必填 | 说明                            |
  | -------- | ------------------------------------ | ---- | ------------------------------ |
  | type     | string                                | 是  | 注册的设备管理器 UI 状态回调，以便在状态改变时通知应用，固定为replyResult。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string;}&gt; | 是  | 指示要注册的设备管理器 UI 状态回调，返回UI状态。        |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                            |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255. |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class Data {
    param: string = '';
  }

  interface TmpStr {
    verifyFailed: boolean;
  }

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.on('replyResult', (data: Data) => {
      console.log('replyResult executed, dialog closed' + JSON.stringify(data));
      let tmpStr: TmpStr = JSON.parse(data.param);
      let isShow = tmpStr.verifyFailed;
      console.log('replyResult executed, dialog closed' + isShow);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### off('replyResult')

off(type: 'replyResult', callback?: Callback&lt;{ param: string;}&gt;): void

取消回复UI操作结果回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名      | 类型                              | 必填 | 说明                            |
  | -------- | ------------------------------------- | ---- | ------------------------------ |
  | type     | string                                | 是   | 取消注册的设备管理器 UI 状态回调，固定为replyResult。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string;}&gt; | 否   | 指示要取消注册的设备管理器 UI 状态，返回UI状态。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 255. |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.off('replyResult');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('replyResult errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setHeartbeatPolicy<sup>15+</sup>

setHeartbeatPolicy(policy: StrategyForHeartbeat, delayTime: number): void

设置心跳广播策略。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | policy        |  &nbsp;[StrategyForHeartbeat](#strategyforheartbeat15)&nbsp;         | 是    | 心跳广播策略。       |
  | delayTime     | number          | 是    | 临时关闭心跳广播的时长，单位为：ms，取值范围1000ms到15000ms。            |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 11600102 | Failed to obtain service.                                 |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let policy = distributedDeviceManager.StrategyForHeartbeat.TEMP_STOP_HEARTBEAT;
    let delayTime = 1000;
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.setHeartbeatPolicy(policy, delayTime);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('setHeartbeatPolicy errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceProfileInfoList<sup>15+</sup>

getDeviceProfileInfoList(filterOptions: DeviceProfileInfoFilterOptions): Promise&lt;Array&lt;DeviceProfileInfo&gt;&gt;

获取同一账号下的设备列表。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | filterOptions        |  &nbsp;[DeviceProfileInfoFilterOptions](#deviceprofileinfofilteroptions15)&nbsp;         | 是    |        |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Promise&lt;Array&lt;[DeviceProfileInfo](#devicefrofileinfo)&gt;&gt; | Promise实例，返回设备列表。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 11600102 | Failed to obtain service.                                 |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';


  ```