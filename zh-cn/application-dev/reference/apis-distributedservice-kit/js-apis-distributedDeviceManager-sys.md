# @ohos.distributedDeviceManager (设备管理)(系统接口)
<!--Kit: Distributed Service Kit-->
<!--Subsystem: DistributedHardware-->
<!--Owner: @hwzhangchuang-->
<!--Designer: @hwzhangchuang-->
<!--Tester: @Lyuxin-->
<!--Adviser: @hu-zhiqiong-->

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

设备信息过滤器选项。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称         | 类型  | 只读 | 可选             |  说明    |
| ----------- | ---- | -- | --- |--------------- | 
| isCloud      | boolean    |  否 | 否           | 表示是否需要实时从云端获取设备列表。<br />- false：表示从设备获取。<br />- true：表示从云端获取。       |
| deviceIdList  | Array&lt;string&gt;  | 否 | 是    | 表示获取指定deviceId的设备信息，deviceId一般为设备的UDID，如设备无UDID，则取其MAC或SN作为deviceId。默认为空。       |


## ServiceProfileInfo<sup>15+</sup>

服务配置信息。根据云端返回的数据填充。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 只读| 可选              |  说明    |
| -------------- | ---- | --------| ------- | --------|
| deviceId       | string  | 否 | 否   |  设备ID。          |
| serviceId       | string  | 否 |否   | 服务ID。           |
| serviceType     | string   | 否 | 否   | 服务类型。           |
| data       | string  | 否 | 是   |  服务数据。字符长度不超过1000个字符。默认为空。          |

## DeviceProfileInfo<sup>15+</sup>

设备信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 只读   |可选              |  说明    |
| -------------- | ---- | ---| --------------- | --------|
|  deviceId      | string  |  否    | 否   |  设备ID。          |
|  deviceSn      | string  |  否    | 否   |  设备序列号。      |
|  mac           | string  |  否    | 否   |  MAC地址。         |
|  model         | string  |  否    | 否   |  设备型号。         |
|  deviceType    | string  |  否    | 否   |  设备类型。         |
|  manufacturer  | string  |  否    | 否   |  制造商。           |
|  deviceName    | string  |  否    | 否   |  设备名称。         |
|  productId     | string  |  否    | 否   |  设备所属产品ID。    |
|  subProductId  | string  |  否    | 是   |  设备所属产品子ID。默认为空。         |
|  sdkVersion    | string  |  否    | 否   |  SDK版本。          |
|  bleMac        | string  |  否    | 否   |  蓝牙BLE的MAC地址。  |
|  brMac         | string  |  否    | 否   |  蓝牙BR的MAC地址。  |
|  sleMac        | string  |  否    | 否   |  Starflash的MAC地址。 |
|  firmwareVersion | string |  否   | 否  |  固件版本。          |
|  hardwareVersion | string |  否   | 否  |  硬件版本。          |
|  softwareVersion | string |  否  | 否  |  软件版本。          |
|  protocolType    | number |  否   | 否  |  协议类型。          |
|  setupType       | number |  否   | 否  |  设备类型。          |
|  wiseDeviceId    | string |  否   | 否  |  已注册设备标识。        |
|  wiseUserId      | string |  否   | 否  |  已注册用户标识。        |
|  registerTime    | string |  否   | 否  |  注册时间。          |
|  modifyTime      | string |  否   | 否  |  修改时间。          |
|  shareTime       | string |  否   | 否  |  分享时间。          |
|  isLocalDevice   | boolean | 否   | 否 |  是否为本地设备。<br />- false：表示非本地设备，即被查询的其他设备。<br />- true：表示本地设备，即当前正在使用该接口的设备。     |
|  services        | Array&lt;[ServiceProfileInfo](#serviceprofileinfo15)&gt; | 否  | 是  | 服务配置信息列表。默认为空。 |
|  productName<sup>18+</sup>     | string  | 否   | 是 |  设备所属的产品名称。默认为空。    |
|  internalModel<sup>18+</sup>   | string  | 否   | 是 |  设备所属产品的内部型号。默认为空。 |


## DeviceIconInfoFilterOptions<sup>18+</sup> 

设备图标信息过滤选项。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 只读 | 可选              |  说明    |
| -------------- | ---- | -------| -------- | --------|
|  productId      | string  | 否 | 否   |  设备所属产品ID。          |
|  subProductId   | string  | 否 | 是   |  设备所属产品子ID。默认为空。      |
|  imageType      | string  | 否 | 否   |  图片类型。固定值为"ID"，表示产品实物图。 |
|  specName       | string  | 否 | 否   |  图片规格名称。取值范围：<br />- lg：大图，尺寸为1016064px。<br />- sm：小图，尺寸为65536px。         |
|  internalModel  | string  | 否 | 是   |  设备所属产品的内部型号。默认为空。        |

## DeviceIconInfo<sup>18+</sup>

设备图标信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 只读  |可选              |  说明    |
| -------------- | ---- | ------| --------- | --------|
|  productId      | string  | 否 | 否   |  设备所属产品ID。          |
|  subProductId   | string  | 否 | 是   |  设备所属产品子ID。默认为空字符。     |
|  imageType      | string  | 否 | 否   |  图片类型。固定值为"ID"，表示产品实物图。        |
|  specName       | string  | 否 | 否   |  图片规格名称。取值范围：<br />- lg：大图，尺寸为1016064px。<br />- sm：小图，尺寸为65536px。         |
|  url            | string  | 否 | 否   |  URL。          |
|  icon           | ArrayBuffer | 否| 否 | 图标。         |
|  internalModel  | string  | 否 | 是   |  设备所属产品的内部型号。默认为空。         |

## NetworkIdQueryFilter<sup>18+</sup>

设备网络ID过滤器选项。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 只读 | 可选              |  说明    |
| -------------- | ---- | ------ | --------- | --------|
|  wiseDeviceId       | string  | 否 | 否   |  已注册设备标识。          |
|  onlineStatus    | number  | 否 | 否   |  设备在线状态，包括<br />- 0：表示设备处于离线状态。<br />- 1：表示设备处于在线状态。      |

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
  | action        | number          | 是    | 用户操作动作。<br />- 0：允许授权。<br />- 1：取消授权。<br />- 2：授权框用户操作超时。<br />- 3：取消pin码框展示。<br />- 4：取消pin码输入框展示。<br />- 5：pin码输入框确定操作。     |
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
      console.info('replyResult executed, dialog closed' + JSON.stringify(data));
      let tmpStr: TmpStr = JSON.parse(data.param);
      let isShow = tmpStr.verifyFailed;
      console.info('replyResult executed, dialog closed' + isShow);
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

获取同账号下全部的设备列表，使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | filterOptions        |  &nbsp;[DeviceProfileInfoFilterOptions](#deviceprofileinfofilteroptions15)&nbsp;         | 是    | 查询过程中使用的过滤条件。     |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Promise&lt;Array&lt;[DeviceProfileInfo](#deviceprofileinfo15)&gt;&gt; | Promise实例，返回设备列表。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 500. |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Get data from cloud fail. |
| 11600107 | A login account is required.  |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.getDeviceProfileInfoList({"isCloud": false}).then((data: Array<distributedDeviceManager.DeviceProfileInfo>) => {
      console.info('getDeviceProfileInfoList' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('getDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### putDeviceProfileInfoList<sup>18+</sup>

putDeviceProfileInfoList(deviceProfileInfoList: Array&lt;DeviceProfileInfo&gt;): Promise&lt;number&gt;

业务调用更新设备列表，使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceProfileInfoList       |  Array&lt;[DeviceProfileInfo](#deviceprofileinfo15)&gt;        |  是   |  需要更新的设备列表。    |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | 操作结果，0表示本次调用成功。  |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 500. |
| 11600102 | Failed to obtain service.                                 |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceProfileInfoList:Array<distributedDeviceManager.DeviceProfileInfo> = [];
    dmInstance.putDeviceProfileInfoList(deviceProfileInfoList).then((data:number) => {
      console.info('put device profile info:' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('putDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('putDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceIconInfo<sup>18+</sup>

getDeviceIconInfo(filterOptions: DeviceIconInfoFilterOptions): Promise&lt;DeviceIconInfo&gt;

获取设备图标，使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  filterOptions       | [DeviceIconInfoFilterOptions](#deviceiconinfofilteroptions18)         | 是    |  查询过程中使用的过滤条件。    |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  |  Promise&lt;[DeviceIconInfo](#deviceiconinfo18)&gt; | Promise实例，返回设备图标信息。                                    |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Get data from cloud fail. |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let productIds:Array<string> = ['M0D2', 'M0D3', 'M0D5', 'M0AB', 'M0BD', 'M0E9', 'M0BC', 'M0EA'];
    let options:distributedDeviceManager.DeviceIconInfoFilterOptions = {
      productId: 'P14U',
      imageType: 'ID',
      specName: 'lg',
    };
    if (productIds.indexOf(options.productId) != -1) {
      options.internalModel = '';
    } else {
      options.subProductId = '';
    }
    dmInstance.getDeviceIconInfo(options).then((data: distributedDeviceManager.DeviceIconInfo) => {
      console.info('getDeviceIconInfo' + JSON.stringify(data));
    }).catch((e : BusinessError) => {
      console.error('getDeviceIconInfo errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceIconInfo errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getLocalDisplayDeviceName<sup>18+</sup>

getLocalDisplayDeviceName(maxNameLength: number): Promise&lt;string&gt;

获取本机指定长度（字节数）的显示名，使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  maxNameLength       |  number        |  是  | 可显示的设备名称长度（字节数），取值范围为[18，100]，为0时表示不限制。     |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | string | 指定名称长度最大字节数的本机设备显示名。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let maxNameLength:number = 21;
    dmInstance.getLocalDisplayDeviceName(maxNameLength).then((data:string)=>{
      console.info('getLocalDisplayDeviceName name:' + JSON.stringify(data));
    }).catch((e: BusinessError)=>{
      console.error('getLocalDisplayDeviceName errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getLocalDisplayDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setLocalDeviceName<sup>18+</sup>

setLocalDeviceName(deviceName: string): Promise&lt;number&gt;

修改本机设备名称，使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceName       | string         |  是   | 自定义设备名称。字符串长度范围1~255。     |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | 操作结果，0表示本次调用成功。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Failed to get data from the cloud. |
| 11600107 | A login account is required.  |
| 11600108 | The device name contains non-compliant content. |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceName:string = 'xxx';
    dmInstance.setLocalDeviceName(deviceName).then((data:number)=>{
      console.info('setLocalDeviceName name:' + JSON.stringify(data));
    }).catch((e: BusinessError)=>{
      console.error('setLocalDeviceName errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('setLocalDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setRemoteDeviceName<sup>18+</sup>

setRemoteDeviceName(deviceId: string, deviceName: string): Promise&lt;number&gt;

设置配件设备名称，使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceId       | string         | 是    | 配件设备的UDID，没有UDID的设备取MAC或SN，优先取SN。     |
  |  deviceName       | string         | 是    | 自定义设备名称。字符串长度范围1~255。    |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | 操作结果，0表示本次调用成功。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600106 | Failed to get data from the cloud. |
| 11600107 | A login account is required.  |
| 11600108 | The device name contains non-compliant content. |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceId:string = 'xxx';
    let deviceName:string = 'xxx';
    dmInstance.setRemoteDeviceName(deviceId, deviceName).then((data:number)=>{
      console.info('setRemoteDeviceName name:' + JSON.stringify(data));
    }).catch((e: BusinessError)=>{
      console.error('setRemoteDeviceName errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('setRemoteDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### restoreLocalDeivceName<sup>18+</sup>

restoreLocalDeivceName(): void

系统重置还原网络设置时，还原本机设备名。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600102 | Failed to obtain the service.                                 |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.restoreLocalDeivceName();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('restoreLocalDeivceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceNetworkIdList<sup>18+</sup>

getDeviceNetworkIdList(filterOptions: NetworkIdQueryFilter): Promise&lt;Array&lt;string&gt;&gt;

获取符合条件的网络设备ID列表。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |   filterOptions      | [NetworkIdQueryFilter](#networkidqueryfilter18)         |  是   |   查询过程中使用的过滤条件。   |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Promise&lt;Array&lt;string&gt;&gt; |  Promise实例，返回设备网络ID的列表。|

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600107 | A login account is required.  |

**示例：**

  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let queryFiler: distributedDeviceManager.NetworkIdQueryFilter = {
      wiseDeviceId: '',
      onlineStatus: 1,
    }
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.getDeviceNetworkIdList(queryFiler).then((data:Array<string>) => {
      console.info('getDeviceNetworkIdList name:' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('getDeviceNetworkIdList errCode:' + e.code + ',errMessage:' + e.message);
    })
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceNetworkIdList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```
