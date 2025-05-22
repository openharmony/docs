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
| isCloud      | boolean    |   是           | 指示是否需要实时从设备云获取设备列表。       |
| deviceIdList  | Array&lt;string&gt;  | 否    | 获取指定deviceId的设备信息，deviceId取值端侧udid，无udid类的设备取MAC或者SN。       |


## ServiceProfileInfo<sup>15+</sup>

业务模板信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 必填              |  说明    |
| -------------- | ---- | --------------- | --------|
| deviceId       | string  | 是   |  设备ID。          |
| serviceId       | string  | 是   | 业务ID。           |
| serviceType     | string   | 是   | 业务类型。           |
| data       | string  | 否   |  业务数据。          |

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
|  productId     | string  | 是   |  设备所属产品ID。           |
|  subProductId  | string  | 否   |  设备所属产品子ID。         |
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


## DeviceIconInfoFilterOptions<sup>18+</sup> 

设备图标信息过滤选项。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 必填              |  说明    |
| -------------- | ---- | --------------- | --------|
|  productId      | string  | 是   |  设备所属产品ID。          |
|  subProductId   | string  | 否   |  设备所属产品子ID。      |
|  imageType      | string  | 是   |  图片类型。约定取值范围：<br />-ID.<br />-ID_Headset_L.<br />-ID_Headset_R.<br />-ID_Headset_B.<br />-ID_Headset_LB.<br />-ID_Headset_RB.         |
|  specName       | string  | 是   |  图片规格名称。约定取值范围：<br />-lg: 大图。<br />-sm: 小图。         |
|  internalModel  | string  | 否   |  设备所属产品的内部型号。        |

## DeviceIconInfo<sup>18+</sup>

设备图标信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 必填              |  说明    |
| -------------- | ---- | --------------- | --------|
|  productId      | string  | 是   |  设备所属产品ID。          |
|  subProductId   | string  | 否   |  设备所属产品子ID。     |
|  imageType      | string  | 是   |  图片类型。约定取值范围：<br />-ID.<br />-ID_Headset_L.<br />-ID_Headset_R.<br />-ID_Headset_B.<br />-ID_Headset_LB.<br />-ID_Headset_RB.         |
|  specName       | string  | 是   |  图片规格名称。约定取值范围：<br />-lg: 大图。<br />-sm: 小图。         |
|  url            | string  | 是   |  统一资源定位器。          |
|  icon           | ArrayBuffer | 是 | 图标。         |
|  internalModel  | string  | 否   |  设备所属产品的内部型号。         |

## NetworkIdQueryFilter<sup>18+</sup>

设备网络ID查询过滤器选项。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称           | 类型  | 必填              |  说明    |
| -------------- | ---- | --------------- | --------|
|  wiseDeviceId       | string  | 是   |  智能设备ID。          |
|  onlineStatus    | string  | 否   |  根据在线状态获取设备网络ID列表。      |

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

获取同账号下全部的设备列表，异步接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | filterOptions        |  &nbsp;[DeviceProfileInfoFilterOptions](#deviceprofileinfofilteroptions15)&nbsp;         | 是    | 查询设备列表参数，参数类型为map，例如: <br>isCloud：指示是否需要实时从设备云获取设备列表。<br />-false：表示从设备端获取。<br />-true：表示从设备云获取。<br>deviceIdList：获取指定deviceId的设备信息，deviceId取值端侧udid，无udid类的设备取MAC或者SN。     |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Array&lt;[DeviceProfileInfo](#devicefrofileinfo15)&gt; | Promise实例，返回设备列表。 |

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

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    dmInstance.getDeviceProfileInfoList({"isCloud": false}).then((data: Array<distributedDeviceManager.DeviceProfileInfo>) => {
      console.log('getDeviceProfileInfoList' + JSON.stringify(data));
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

更新设备列表，异步接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceProfileInfoList       |  Array&lt;[DeviceProfileInfo](#devicefrofileinfo15)&gt;        |  是   |  需要更新的设备列表。    |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | 更新结果，0成功。  |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; 4. The size of specified type is greater than 500. |
| 11600102 | Failed to obtain service.                                 |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceProfileInfoList:Array<distributedDeviceManager.DeviceProfileInfo> = [];
    dmInstance.putDeviceProfileInfoList(deviceProfileInfoList).then((data:number) => {
      console.log('put device profile info:' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('putDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('putDeviceProfileInfoList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getDeviceIconInfo<sup>18+</sup>

getDeviceIconInfo(filterOptions: DeviceIconInfoFilterOptions): Promise<DeviceIconInfo>

获取设备实物图，异步接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  filterOptions       | [DeviceIconInfoFilterOptions](#deviceiconinfofilteroptions15)         | 是    |  查询设备列表参数，参数类型为map，会携带以下key值：<br>productId: 设备所属产品ID。 <br>subProductId: 设备所属产品子ID。<br>imageType: 图片类型，例如：<br />-ID.<br />-ID_Headset_L.<br />-ID_Headset_R.<br />-ID_Headset_B.<br />-ID_Headset_LB.<br />-ID_Headset_RB.<br>specName: 图片规格，约定取值范围：<br />-lg：大图。<br />-sm: 小图。    |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  |  [DeviceIconInfo](#deviceiconinfo18) | 设备实物图信息。                                    |

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

<!--code_no_check-->
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
      console.log('getDeviceIconInfo' + JSON.stringify(data));
    }).catch((e : BusinessError) => {
      console.error('getDeviceIconInfo errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceIconInfo errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### getLocalDisplayDeviceName<sup>18+</sup>

getLocalDisplayDeviceName(maxNameLength: number): Promise<string>

获取本机指定长度（字节数）的显示名，异步接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  maxNameLength       |  number        |  否   | 设备显示名最大长度，字节数，传0不截断；取值范围[18,100]。     |

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

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let maxNameLength:number = 21;
    dmInstance.getLocalDisplayDeviceName(maxNameLength).then((data:string)=>{
      console.log('getLocalDisplayDeviceName name:' + JSON.stringify(data));
    }).catch((e: BusinessError)=>{
      console.error('getLocalDisplayDeviceName errCode:' + e.code + ',errMessage:' + e.message);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getLocalDisplayDeviceName errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```

### setLocalDeviceName<sup>18+</sup>

setLocalDeviceName(deviceName: string): Promise<number>

修改本机设备名称，异步接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceName       | string         |  是   | 自定义设备名称。     |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | 执行结果，0成功。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceName:string = 'xxx';
    dmInstance.setLocalDeviceName(deviceName).then((data:number)=>{
      console.log('setLocalDeviceName name:' + JSON.stringify(data));
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

设置配件设备名称，异步接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |  deviceId       | string         | 是    | 配件设备的udid，没有udid的设备取MAC或SN，优先取SN。     |
  |  deviceName       | string         | 是    | 自定义设备名称。     |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | number | 执行结果，0成功。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed; |
| 11600102 | Failed to obtain service.                                 |
| 11600107 | A login account is required.  |

**示例：**

<!--code_no_check-->
  ```ts
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let dmInstance = distributedDeviceManager.createDeviceManager('ohos.samples.jsHelloWorld');
    let deviceId:string = 'xxx';
    let deviceName:string = 'xxx';
    dmInstance.setRemoteDeviceName(deviceId, deviceName).then((data:number)=>{
      console.log('setRemoteDeviceName name:' + JSON.stringify(data));
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

还原网络时，还原本机设备名。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600102 | Failed to obtain service.                                 |

**示例：**

<!--code_no_check-->
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

通过条件获取设备网络ID列表。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  |   filterOptions      | [NetworkIdQueryFilter](#networkidqueryfilter18)         |  是   |   查询设备网络ID列表参数。参数类型为map，如：<br>wiseDeviceId(xx-xxxxx): 根据设备ID获取设备网络ID列表。<br>onlineStatus: <br />-0: 表示设备处于离线状态。<br />-1: 表示设备在线。   |

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Array&lt;string&gt; |  返回设备网络ID的列表。|

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

<!--code_no_check-->
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
      console.log('getDeviceNetworkIdList name:' + JSON.stringify(data));
    }).catch((e: BusinessError) => {
      console.error('getDeviceNetworkIdList errCode:' + e.code + ',errMessage:' + e.message);
    })
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error('getDeviceNetworkIdList errCode:' + e.code + ',errMessage:' + e.message);
  }
  ```
