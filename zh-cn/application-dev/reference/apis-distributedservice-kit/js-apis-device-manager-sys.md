# @ohos.distributedHardware.deviceManager (设备管理)(系统接口)

本模块能力已更新至新模块。建议使用新模块的接口进行开发，参见[@ohos.distributedDeviceManager](js-apis-distributedDeviceManager.md)。

本模块提供分布式设备管理能力。

系统应用可调用接口实现如下功能：

- 注册和解除注册设备上下线变化监听。
- 发现周边不可信设备。
- 认证和取消认证设备。
- 查询可信设备列表。
- 查询本地设备信息，包括设备名称，设备类型和设备标识。
- 发布设备发现。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块为系统接口，三方应用不支持调用。


## 导入模块

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;

创建一个设备管理器实例。

> 从API version 11 开始废弃。建议使用[deviceManager.createDeviceManager](js-apis-distributedDeviceManager.md#devicemanagercreatedevicemanager)替代。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                                        |
| ---------- | ---------------------------------------------------- | ---- | ----------------------------------------------------------- |
| bundleName | string                                               | 是   | 指示应用程序的Bundle名称。长度范围1~255字符。                                  |
| callback   | AsyncCallback&lt;[DeviceManager](#devicemanager)&gt; | 是   | DeviceManager实例创建时调用的回调，返回设备管理器对象实例。 |

**示例：**

  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  let dmInstance: deviceManager.DeviceManager | null = null;
  try {
    deviceManager.createDeviceManager("ohos.samples.jshelloworld", (err: BusinessError, data: deviceManager.DeviceManager) => {
      if (err) { 
        console.error("createDeviceManager errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.info("createDeviceManager success");
      dmInstance = data;
    });
  } catch(err) {
    let e: BusinessError = err as BusinessError;
    console.error("createDeviceManager errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

## DeviceInfo

设备信息。

> 从API version 11 开始废弃。建议使用[DeviceBasicInfo](js-apis-distributedDeviceManager.md#devicebasicinfo)替代。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称                     | 类型                        | 必填   | 说明       |
| ---------------------- | ------------------------- | ---- | -------- |
| deviceId               | string                    | 是    | 设备的唯一标识。 |
| deviceName             | string                    | 是    | 设备名称。    |
| deviceType             | [DeviceType](#devicetype) | 是    | 设备类型。    |
| networkId<sup>8+</sup> | string                    | 是    | 设备网络标识。  |
| range<sup>9+</sup>     | number                    | 是    | 发现设备的距离。  |
| authForm<sup>10+</sup> | [AuthForm](#authform10)     | 是    | 设备认证类型。  |

## DeviceType

表示设备类型的枚举类。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称           | 值  | 说明   |
| ------------ | ---- | ---- |
| SPEAKER      | 0x0A | 智能音箱。 |
| PHONE        | 0x0E | 手机。   |
| TABLET       | 0x11 | 平板。   |
| WEARABLE     | 0x6D | 智能穿戴。 |
| TV           | 0x9C | 智慧屏。  |
| CAR          | 0x83 | 车。    |
| UNKNOWN_TYPE | 0    | 未知设备。 |

## AuthForm<sup>10+</sup>

表示设备认证类型的枚举类。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称                 | 值  | 说明             |
| ------------------- | ---- | --------------- |
| INVALID_TYPE        | -1   | 设备没有认证。 |
| PEER_TO_PEER        | 0    | 无账号设备点对点认证。   |
| IDENTICAL_ACCOUNT   | 1    | 设备同账号认证。   |
| ACROSS_ACCOUNT      | 2    | 设备跨账号认证。 |

## DeviceStateChangeAction

表示设备状态变化的枚举。

> 从API version 11 开始废弃。建议使用[DeviceStateChange](js-apis-distributedDeviceManager.md#devicestatechange)替代。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称      | 值  | 说明              |
| ------- | ---- | --------------- |
| ONLINE  | 0    | 设备物理上线状态。           |
| READY   | 1    | 设备可用状态，表示设备间信息已在分布式数据中同步完成, 可以运行分布式业务。 |
| OFFLINE | 2    | 设备物理下线状态。           |
| CHANGE  | 3    | 设备信息更改。         |

## SubscribeInfo

发现信息。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称            | 类型                                | 必填   | 说明                |
| ------------- | --------------------------------- | ---- | ----------------- |
| subscribeId   | number                            | 是    | 发现标识，用于标识不同的发现周期。 取值范围1~65535。|
| mode          | [DiscoverMode ](#discovermode)    | 是    | 发现模式。             |
| medium        | [ExchangeMedium](#exchangemedium) | 是    | 发现类型。             |
| freq          | [ExchangeFreq](#exchangefreq)     | 是    | 发现频率。             |
| isSameAccount | boolean                           | 否    | 是否同账号，true表示同账号，false表示异账号。            |
| isWakeRemote  | boolean                           | 否    | 是否唤醒设备，true表示唤醒，false表示不用唤醒。           |
| capability    | [SubscribeCap](#subscribecap)     | 是    | 发现能力。             |

## DiscoverMode

表示发现模式的枚举。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称                    | 值  | 说明    |
| --------------------- | ---- | ----- |
| DISCOVER_MODE_PASSIVE | 0x55 | 被动模式。 |
| DISCOVER_MODE_ACTIVE  | 0xAA | 主动模式。 |


## ExchangeMedium 

表示发现类型的枚举。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称   | 值  | 说明        |
| ---- | ---- | --------- |
| AUTO | 0    | 自动发现类型。   |
| BLE  | 1    | 蓝牙发现类型。   |
| COAP | 2    | WiFi发现类型。 |
| USB  | 3    | USB发现类型。  |

## ExchangeFreq 

表示发现频率的枚举。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称         | 值  | 说明    |
| ---------- | ---- | ----- |
| LOW        | 0    | 低频率。  |
| MID        | 1    | 中频率。  |
| HIGH       | 2    | 高频率。  |
| SUPER_HIGH | 3    | 超高频率。 |


## SubscribeCap 

表示发现能力的枚举。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称                        | 值  | 说明             |
| ------------------------- | ---- | -------------- |
| SUBSCRIBE_CAPABILITY_DDMP | 0    | DDMP能力，后续会被废弃。 |
| SUBSCRIBE_CAPABILITY_OSD  | 1    | OSD能力。         |


## AuthParam

认证参数。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称        | 类型                   | 必填   | 说明         |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | 是    | 认证类型。      |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | 否    | 认证参数可扩展字段。可选，默认为undefined。 |

## AuthInfo

认证信息。

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称        | 类型                   | 必填   | 说明         |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | 是    | 认证类型。      |
| token     | number               | 是    | 认证Token。   |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | 否    | 认证信息可扩展字段。可选，默认为undefined。 |

## PublishInfo<sup>9+</sup>

发布设备参数

> 从API version 11 开始废弃。无替代接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称          | 类型                              | 必填   | 说明                |
| ------------- | --------------------------------- | ---- | ----------------- |
| publishId     | number                            | 是    | 发布设备标识，用于标识不同的发布周期。 |
| mode          | [DiscoverMode ](#discovermode)    | 是    | 发现模式。             |
| freq          | [ExchangeFreq](#exchangefreq)     | 是    | 发现频率。             |
| ranging       | boolean                           | 是    | 发布的设备是否支持测距能力，true表示支持测距能力，false表示不支持测距能力。             |

## DeviceManager

设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。

### release

release(): void;

设备管理实例不再使用后，通过该方法释放DeviceManager实例。

> 从API version 11 开始废弃。建议使用[deviceManager.releaseDeviceManager](js-apis-distributedDeviceManager.md#devicemanagerreleasedevicemanager)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600101 | Failed to execute the function.                                 |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.release();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("release errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceListSync

getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;;

同步获取所有可信设备列表。

> 从API version 11 开始废弃。建议使用[getAvailableDeviceListSync](js-apis-distributedDeviceManager.md#getavailabledevicelistsync)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 名称                                     | 说明        |
  | -------------------------------------- | --------- |
  | Array&lt;[DeviceInfo](#deviceinfo)&gt; | 返回可信设备列表。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600101 | Failed to execute the function.                                 |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    let deviceInfoList: Array<deviceManager.DeviceInfo> = dmInstance.getTrustedDeviceListSync();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getTrustedDeviceListSync errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceListSync<sup>10+</sup>

getTrustedDeviceListSync(isRefresh: boolean): Array&lt;DeviceInfo&gt;;

打开软总线系统端的心跳模式，让周围处于下线状态的可信设备快速上线，同时刷新已上线的可信设备列表。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

| 参数名        | 类型                               | 必填 | 说明                                |
| ------------- | --------------------------------- | ---- | ---------------------------------- |
|   isRefresh   | boolean                           | 是   | 是否打开心跳模式，刷新可信列表，true表示打开心跳模式，false表示关闭心跳模式。      |

**返回值：**

| 名称                                     | 说明            |
| -------------------------------------- | ---------------- |
| Array&lt;[DeviceInfo](#deviceinfo)&gt; | 返回可信设备列表。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    let deviceInfoList: Array<deviceManager.DeviceInfo> = dmInstance.getTrustedDeviceListSync(true);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getTrustedDeviceListSync errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void;

获取所有可信设备列表。使用callback异步回调。

> 从API version 11 开始废弃。建议使用[getAvailableDeviceList](js-apis-distributedDeviceManager.md#getavailabledevicelist)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                    |
  | -------- | ---------------------------------------- | ---- | --------------------- |
  | callback | AsyncCallback&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | 是    | 获取所有可信设备列表的回调，返回设备信息。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.getTrustedDeviceList((err: BusinessError, data: Array<deviceManager.DeviceInfo>) => {
      if (err) {
        console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get trusted device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getTrustedDeviceList errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;;

获取所有可信设备列表。使用Promise异步回调。

> 从API version 11 开始废弃。建议使用[getAvailableDeviceList](js-apis-distributedDeviceManager.md#getavailabledevicelist-1)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 类型                                       | 说明                    |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  dmInstance.getTrustedDeviceList().then((data: Array<deviceManager.DeviceInfo>) => {
    console.log('get trusted device info: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error("getTrustedDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### getLocalDeviceInfoSync<sup>8+</sup>

getLocalDeviceInfoSync(): [DeviceInfo](#deviceinfo);

同步获取本地设备信息。

> 从API version 11 开始废弃。建议使用[getLocalDeviceNetworkId](js-apis-distributedDeviceManager.md#getlocaldevicenetworkid),[getLocalDeviceName](js-apis-distributedDeviceManager.md#getlocaldevicename),[getLocalDeviceType](js-apis-distributedDeviceManager.md#getlocaldevicetype),[getLocalDeviceId](js-apis-distributedDeviceManager.md#getlocaldeviceid)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 名称                      | 说明              |
  | ------------------------- | ---------------- |
  | [DeviceInfo](#deviceinfo) | 返回本地设备列表。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 11600101 | Failed to execute the function.                                 |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    let deviceInfo: deviceManager.DeviceInfo = dmInstance.getLocalDeviceInfoSync();
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getLocalDeviceInfoSync errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void;

获取本地设备信息。使用callback异步回调。

> 从API version 11 开始废弃。建议使用[getLocalDeviceNetworkId](js-apis-distributedDeviceManager.md#getlocaldevicenetworkid),[getLocalDeviceName](js-apis-distributedDeviceManager.md#getlocaldevicename),[getLocalDeviceType](js-apis-distributedDeviceManager.md#getlocaldevicetype),[getLocalDeviceId](js-apis-distributedDeviceManager.md#getlocaldeviceid)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明        |
  | -------- | ---------------------------------------- | ---- | --------- |
  | callback | AsyncCallback&lt;[DeviceInfo](#deviceinfo)&gt; | 是    | 获取本地设备信息。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';


  try {
    dmInstance.getLocalDeviceInfo((err: BusinessError, data: deviceManager.DeviceInfo) => {
      if (err) {
        console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get local device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getLocalDeviceInfo errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;;

获取本地设备信息。使用Promise异步回调。

> 从API version 11 开始废弃。建议使用[getLocalDeviceNetworkId](js-apis-distributedDeviceManager.md#getlocaldevicenetworkid),[getLocalDeviceName](js-apis-distributedDeviceManager.md#getlocaldevicename),[getLocalDeviceType](js-apis-distributedDeviceManager.md#getlocaldevicetype),[getLocalDeviceId](js-apis-distributedDeviceManager.md#getlocaldeviceid)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 类型                                       | 说明                    |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;[DeviceInfo](#deviceinfo)&gt; | Promise实例，用于获取异步返回结果。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  dmInstance.getLocalDeviceInfo().then((data: deviceManager.DeviceInfo) => {
    console.log('get local device info: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### getDeviceInfo<sup>10+</sup>

getDeviceInfo(networkId: string, callback:AsyncCallback&lt;DeviceInfo&gt;): void;

通过指定设备的网络标识获取该设备的信息。使用callback异步回调。

> 从API version 11 开始废弃。建议使用[getDeviceName](js-apis-distributedDeviceManager.md#getdevicename),[getDeviceType](js-apis-distributedDeviceManager.md#getdevicetype)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明        |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | 是   | 设备的网络标识。长度范围1~255字符。 |
  | callback | AsyncCallback&lt;[DeviceInfo](#deviceinfo)&gt; | 是    | 获取指定设备信息。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  try {
    // 设备网络标识，可以从可信设备列表中获取
    let networkId = "xxxxxxx";
    dmInstance.getDeviceInfo(networkId, (err: BusinessError, data: deviceManager.DeviceInfo) => {
      if (err) {
        console.error("getDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("getDeviceInfo errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### getDeviceInfo<sup>10+</sup>

getDeviceInfo(networkId: string): Promise&lt;DeviceInfo&gt;;

通过指定设备的网络标识获取该设备的信息。使用Promise异步回调。

> 从API version 11 开始废弃。建议使用[getDeviceName](js-apis-distributedDeviceManager.md#getdevicename),[getDeviceType](js-apis-distributedDeviceManager.md#getdevicetype)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名   | 类型                                     | 必填 | 说明        |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | 是   | 设备的网络标识。长度范围1~255字符。 |
  
**返回值：**

  | 类型                                       | 说明                    |
  | ---------------------------------------- | --------------------- |
  | Promise&lt;[DeviceInfo](#deviceinfo)&gt; | Promise实例，用于获取异步返回结果。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  // 设备网络标识，可以从可信设备列表中获取
  let networkId = "xxxxxxx";
  dmInstance.getDeviceInfo(networkId).then((data: deviceManager.DeviceInfo) => {
    console.log('get device info: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("getDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### startDeviceDiscovery<sup>8+</sup>

startDeviceDiscovery(subscribeInfo: SubscribeInfo): void;

发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。

> 从API version 11 开始废弃。建议使用[startDiscovering](js-apis-distributedDeviceManager.md#startdiscovering)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名            | 类型                       | 必填 | 说明    |
  | ------------- | ------------------------------- | ---- | ----- |
  | subscribeInfo | [SubscribeInfo](#subscribeinfo) | 是   | 发现信息。|

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery unavailable.                                              |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  interface SubscribeInfo {
    subscribeId: number;
    mode: number;   // 主动模式
    medium: number; // 自动发现类型，同时支持多种发现类型
    freq: number;   // 高频率
    isSameAccount: boolean;
    isWakeRemote: boolean;
    capability: number;
  }

  // 生成发现标识，随机数确保每次调用发现接口的标识不一致
  let subscribeId = Math.floor(Math.random() * 10000 + 1000);
  let subscribeInfo: SubscribeInfo = {
    subscribeId: subscribeId,
    mode: 0xAA, // 主动模式
    medium: 0,  // 自动发现类型，同时支持多种发现类型
    freq: 2,    // 高频率
    isSameAccount: false,
    isWakeRemote: false,
    capability: 1
  };
  try {
    dmInstance.startDeviceDiscovery(subscribeInfo); // 当有设备发现时，通过deviceFound回调通知给应用程序
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("startDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### startDeviceDiscovery<sup>9+</sup>

startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void;

发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。

> 从API version 11 开始废弃。建议使用[startDiscovering](js-apis-distributedDeviceManager.md#startdiscovering)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名            | 类型                       | 必填   | 说明    |
  | ------------- | ------------------------------- | ---- | -----  |
  | subscribeInfo | [SubscribeInfo](#subscribeinfo) | 是   | 发现信息。 |
  | filterOptions | string                          | 否   | 发现设备过滤信息。可选，默认为undefined，发现未上线设备。长度范围1~255字符。|

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery unavailable.                                              |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  interface Filters {
    type: string;
    value: number;
  }

  interface FilterOptions {
    filter_op: string; // 可选, 默认"OR"
    filters: Filters[];
  }

  interface SubscribeInfo {
    subscribeId: number;
    mode: number;   // 主动模式
    medium: number; // 自动发现类型，同时支持多种发现类型
    freq: number;   // 高频率
    isSameAccount: boolean;
    isWakeRemote: boolean;
    capability: number;
  }

  // 生成发现标识，随机数确保每次调用发现接口的标识不一致
  let subscribeId = Math.floor(Math.random() * 10000 + 1000);
  let subscribeInfo: SubscribeInfo = {
    subscribeId: subscribeId,
    mode: 0xAA, // 主动模式
    medium: 0,  // 自动发现类型，同时支持多种发现类型
    freq: 2,    // 高频率
    isSameAccount: false,
    isWakeRemote: false,
    capability: 1
  };

  let filters: Filters[] = [
    {
        type: "range",
        value: 50 // 需过滤发现设备的距离，单位(cm)
    }
  ];

  let filterOptions: FilterOptions = {
    filter_op: "OR", // 可选, 默认"OR"
    filters: filters
  };
  try {
    dmInstance.startDeviceDiscovery(subscribeInfo, JSON.stringify(filterOptions)); // 当有设备发现时，通过deviceFound回调通知给应用程序
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("startDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### stopDeviceDiscovery

stopDeviceDiscovery(subscribeId: number): void;

停止发现周边设备。

> 从API version 11 开始废弃。建议使用[stopDiscovering](js-apis-distributedDeviceManager.md#stopdiscovering)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名          | 类型   | 必填   | 说明    |
  | ----------- | ------ | ---- | ----- |
  | subscribeId | number | 是    | 发现标识。取值范围为1~65535。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified networkId is greater than 255. |
| 11600101 | Failed to execute the function.                                 |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    // stopDeviceDiscovery和startDeviceDiscovery需配对使用，入参需要和startDeviceDiscovery接口传入的subscribeId值相等
    let subscribeId = 12345;
    dmInstance.stopDeviceDiscovery(subscribeId);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("stopDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### publishDeviceDiscovery<sup>9+</sup>

publishDeviceDiscovery(publishInfo: PublishInfo): void;

发布设备发现。发布状态持续两分钟，超过两分钟会停止发布。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名          | 类型                        | 必填 | 说明    |
  | ------------- | ------------------------------- | ---- | ----- |
  | publishInfo   | [PublishInfo](#publishinfo9)     | 是   | 发布设备发现信息。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |
| 11600105 | Publish unavailable.                                                |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  interface PublishInfo {
    publishId: number;
    mode: number; // 主动模式
    freq: number; // 高频率
    ranging: boolean; // 支持发现时测距
  };

  // 生成发布标识，随机数确保每次调用发布接口的标识不一致
  let publishId = Math.floor(Math.random() * 10000 + 1000);
  let publishInfo: PublishInfo = {
    publishId: publishId,
    mode: 0xAA, // 主动模式
    freq: 2,    // 高频率
    ranging: true  // 支持发现时测距
  };

  try {
    dmInstance.publishDeviceDiscovery(publishInfo); // 当有发布结果时，通过回调通知给应用程序
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### unPublishDeviceDiscovery<sup>9+</sup>

unPublishDeviceDiscovery(publishId: number): void;

停止发布设备发现。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名        | 类型 | 必填 | 说明  |
  | ----------- | -------- | ---- | ----- |
  | publishId   | number   | 是   | 发布标识。 取值范围为1~2147483647。|

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    // unPublishDeviceDiscovery和publishDeviceDiscovery配对使用，入参需要和publishDeviceDiscovery接口传入的publishId值相等
    let publishId = 12345;
    dmInstance.unPublishDeviceDiscovery(publishId);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("unPublishDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### authenticateDevice

authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback&lt;{deviceId: string, pinToken ?: number}&gt;): void;

认证设备。

> 从API version 11 开始废弃。建议使用[bindTarget](js-apis-distributedDeviceManager.md#bindtarget)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名         | 类型                                     | 必填   | 说明      |
  | ---------- | ---------------------------------------- | ---- | ------- |
  | deviceInfo | [DeviceInfo](#deviceinfo)                | 是    | 设备信息。   |
  | authParam  | [AuthParam](#authparam)                  | 是    | 认证参数。   |
  | callback   | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;pinToken&nbsp;?:&nbsp;number}&gt; | 是    | 认证结果回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    deviceId: string = "";
    pinToken?: number = 0;
  }

  interface DeviceInfo {
    deviceId: string;
    deviceName: string;
    deviceType: number;
    networkId: string;
    range: number;
  };

  interface ExtraInfo {
    targetPkgName: string;
    appName: string;
    appDescription: string;
    business: string;
  }

  interface AuthParam {
    authType: number; // 认证类型： 1 - 无账号PIN码认证
    extraInfo: ExtraInfo;
  }

  // 认证的设备信息，可以从发现的结果中获取
  let deviceInfo: deviceManager.DeviceInfo = {
    deviceId: "XXXXXXXX",
    deviceName: "",
    deviceType: 0x0E,
    networkId: "xxxxxxx",
    range: 0,
    authForm: 0
  };
  let extraInfo: ExtraInfo = {
    targetPkgName: 'ohos.samples.xxx',
    appName: 'xxx',
    appDescription: 'xxx',
    business: '0'
  };
  let authParam: AuthParam = {
    authType: 1,// 认证类型： 1 - 无账号PIN码认证
    extraInfo: extraInfo
  };

  try {
    dmInstance.authenticateDevice(deviceInfo, authParam, (err: BusinessError, data: Data) => {
      if (err) {
        console.error("authenticateDevice errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.info("authenticateDevice result:" + JSON.stringify(data));
      let token = data.pinToken;
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("authenticateDevice errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### unAuthenticateDevice<sup>8+</sup>

unAuthenticateDevice(deviceInfo: DeviceInfo): void;

解除认证设备。

> 从API version 11 开始废弃。建议使用[unbindTarget](js-apis-distributedDeviceManager.md#unbindtarget)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名         | 类型                      | 必填   | 说明    |
  | ---------- | ------------------------- | ---- | ----- |
  | deviceInfo | [DeviceInfo](#deviceinfo) | 是    | 设备信息。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备管理错误码](errorcode-device-manager.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.                                            |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |
| 11600101 | Failed to execute the function.                                 |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  interface DeviceInfo {
    deviceId: string;
    deviceName: string;
    deviceType: number;
    networkId: string;
    range: number;
  }

  try {
    let deviceInfo: deviceManager.DeviceInfo = {
      deviceId: "XXXXXXXX",
      deviceName: "",
      deviceType: 0x0E,
      networkId: "xxxxxxx",
      range: 0,
      authForm: 0
    };
    dmInstance.unAuthenticateDevice(deviceInfo);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("unAuthenticateDevice errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### verifyAuthInfo

verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void;

验证认证信息。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明      |
  | -------- | ---------------------------------------- | ---- | ------- |
  | authInfo | [AuthInfo](#authinfo)                    | 是    | 认证信息。   |
  | callback | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;level:&nbsp;number}&gt; | 是    | 验证结果回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  interface ExtraInfo {
    authType: number;
    token: number;
  }

  interface AuthInfo {
    authType: number;
    token: number;
    extraInfo: ExtraInfo;
  }

  class Data {
    deviceId: string = "";
    level: number = 0;
  }

  let extraInfo: ExtraInfo = {
    authType: 0,
    token: 0
  };

  let authInfo: AuthInfo = {
    authType: 1,
    token: 123456,
    extraInfo: extraInfo
  };
  try {
    dmInstance.verifyAuthInfo(authInfo, (err: BusinessError, data: Data) => {
      if (err) {
        console.error("verifyAuthInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
    console.info("verifyAuthInfo result:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("verifyAuthInfo errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### setUserOperation<sup>9+</sup>

setUserOperation(operateAction: number, params: string): void;

设置用户ui操作行为。

> 从API version 11 开始废弃。建议使用[replyUiAction](js-apis-distributedDeviceManager-sys.md#replyuiaction)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | operateAction | number          | 是    | 用户操作动作。取值范围为0~5。       |
  | params        | string          | 是    | 表示用户的输入参数。长度范围1~255字符。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.    |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified params is greater than 255.    |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

 try {
    /*
      operateAction = 0 - 允许授权
      operateAction = 1 - 取消授权
      operateAction = 2 - 授权框用户操作超时
      operateAction = 3 - 取消pin码框展示
      operateAction = 4 - 取消pin码输入框展示
      operateAction = 5 - pin码输入框确定操作
    */
    let operation = 0;
    dmInstance.setUserOperation(operation, "extra");
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("setUserOperation errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### requestCredentialRegisterInfo<sup>10+</sup>

requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback<{registerInfo: string}>): void;

获取凭据的注册信息。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | requestInfo   | string          | 是    | 请求凭据信息。最大长度255字符。       |
  | callback      | AsyncCallback<{registerInfo: string}>         | 是    | 凭据的注册信息回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified params is greater than 255.    |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  interface CredentialInfo {
    version: string;
    userId: string;
  }

  class Data {
    registerInfo: string = "";
  }

  let credentialInfo: CredentialInfo = {
    version: "1.2.3",
    userId: "123"
  };
  try {
    let jsonCredentialInfo = JSON.stringify(credentialInfo);
    dmInstance.requestCredentialRegisterInfo(jsonCredentialInfo, (err: BusinessError, data: Data) => {
      if (data) {
        console.info("requestCredentialRegisterInfo result:" + JSON.stringify(data));
      } else {
        console.info("requestCredentialRegisterInfo result: data is null");
      }
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("requestCredentialRegisterInfo err:" + e.code + "," + e.message);
  }
  ```

### importCredential<sup>10+</sup>

importCredential(credentialInfo: string, callback: AsyncCallback<{resultInfo: string}>): void;

导入凭据信息。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | credentialInfo| string          | 是    | 导入凭据信息。长度范围1~64000字符。       |
  | callback      | AsyncCallback<{resultInfo: string}>           | 是    | 导入凭据结果回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified credentialInfo is greater than 5999. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
<!--code_no_check-->
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    resultInfo: string = "";
  }

  interface CredentialData {
    credentialType: number;
    credentialId: string;
    serverPk: string;
    pkInfoSignature : string;
    pkInfo: string;
    authCode: string;
    peerDeviceId: string;
  }

  interface CredentialInfo {
    processType: number;
    authType: number;
    userId: string;
    deviceId: string;
    version: string;
    devicePk : string;
    credentialData : CredentialData;
  }

  let credentialData: CredentialData = {
    credentialType: 2,
    credentialId: "102",
    serverPk: "3059301306072A8648CE3D020106082A8648CE3D03",
    pkInfoSignature : "30440220490BCB4F822004C9A76AB8D97F80041FC0E",
    pkInfo: "",
    authCode: "",
    peerDeviceId: ""
  };


  let credentialInfo: CredentialInfo = {
    processType: 1,
    authType: 1,
    userId: "123",
    deviceId: "aaa",
    version: "1.2.3",
    devicePk : "0000",
    credentialData : credentialData
  };

  try {
    let jsonCredentialInfo = JSON.stringify(credentialInfo);
    dmInstance.importCredential(jsonCredentialInfo, (err: BusinessError, data: Data) => {
      if (data) {
        console.info("importCredential result:" + JSON.stringify(data));
      } else {
        console.info("importCredential result: data is null");
      }
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("importCredential err:" + e.code + "," + e.message);
  }
  ```

### deleteCredential<sup>10+</sup>

deleteCredential(queryInfo: string, callback: AsyncCallback<{resultInfo: string}>): void;

删除凭据信息。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | queryInfo     | string          | 是    | 删除凭据信息。长度范围1~64000字符。       |
  | callback      | AsyncCallback<{resultInfo: string}>           | 是    | 删除凭据结果回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified credentialInfo is greater than 5999. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    resultInfo: string = "";
  }

  interface QueryInfo {
    processType: number;
    authType: number;
    userId: string;
  }

  let queryInfo: QueryInfo = {
    processType: 1,
    authType: 1,
    userId: "123"
  };

  try {
    let jsonQueryInfo = JSON.stringify(queryInfo);
    dmInstance.deleteCredential(jsonQueryInfo, (err: BusinessError, data: Data) => {
      if (data) {
        console.info("deleteCredential result:" + JSON.stringify(data));
      } else {
        console.info("deleteCredential result: data is null");
      }
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deleteCredential err:" + e.code + "," + e.message);
  }
  ```

### on('uiStateChange')<sup>9+</sup>

on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void;

ui状态变更回调。

> 从API version 11 开始废弃。建议使用[on('replyResult')](js-apis-distributedDeviceManager-sys.md#onreplyresult)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名      | 类型                             | 必填 | 说明                            |
  | -------- | ------------------------------------ | ---- | ------------------------------ |
  | type     | string                                | 是  | 注册的设备管理器 ui 状态回调，以便在状态改变时通知应用，固定为uiStateChange。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | 是  | 指示要注册的设备管理器 ui 状态回调，返回ui状态。        |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    param: string = "";
  }

  interface TmpStr {
    verifyFailed: boolean;
  }

  try {
    dmInstance.on('uiStateChange', (data: Data) => {
      console.log("uiStateChange executed, dialog closed" + JSON.stringify(data));
      let tmpStr: TmpStr = JSON.parse(data.param);
      let isShow = tmpStr.verifyFailed;
      console.log("uiStateChange executed, dialog closed" + isShow);
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("uiStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('uiStateChange')<sup>9+</sup>

off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void;

取消ui状态变更回调。

> 从API version 11 开始废弃。建议使用[off('replyResult')](js-apis-distributedDeviceManager-sys.md#offreplyresult)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名      | 类型                              | 必填 | 说明                            |
  | -------- | ------------------------------------- | ---- | ------------------------------ |
  | type     | string                                | 是   | 取消注册的设备管理器 ui 状态回调，固定为uiStateChange。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | 否   | 指示要取消注册的设备管理器 ui 状态，返回UI状态。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.off('uiStateChange');
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("uiStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('deviceStateChange')

on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void;

注册设备状态回调。

> 从API version 11 开始废弃。建议使用[on('deviceStateChange')](js-apis-distributedDeviceManager.md#ondevicestatechange)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                             |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | 是    | 注册设备状态回调，固定为deviceStateChange。 |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChangeAction](#devicestatechangeaction),&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | 是    | 指示要注册的设备状态回调，返回设备状态和设备信息。      |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    action: deviceManager.DeviceStateChangeAction = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.on('deviceStateChange', (data: Data) => {
      console.info("deviceStateChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('deviceStateChange')

off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void;

取消注册设备状态回调。

> 从API version 11 开始废弃。建议使用[off('deviceStateChange')](js-apis-distributedDeviceManager.md#offdevicestatechange)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                          |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | 是    | 根据应用程序的包名取消注册设备状态回调，固定为deviceStateChange。        |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChangeAction](#devicestatechangeaction),&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | 否    | 指示要取消注册的设备状态回调，返回设备状态和设备信息。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    action: deviceManager.DeviceStateChangeAction = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.off('deviceStateChange', (data: Data) => {
      console.info('deviceStateChange' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceStateChange errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('deviceFound')

on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void;

注册发现设备回调监听。

> 从API version 11 开始废弃。建议使用[on('discoverSuccess')](js-apis-distributedDeviceManager.md#ondiscoversuccess)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                         |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | 是    | 注册设备发现回调，以便在发现周边设备时通知应用程序，固定为deviceFound。 |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | 是    | 注册设备发现的回调方法。               |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.on('deviceFound', (data: Data) => {
      console.info("deviceFound:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceFound errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('deviceFound')

off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void;

取消注册设备发现回调。

> 从API version 11 开始废弃。建议使用[off('discoverSuccess')](js-apis-distributedDeviceManager.md#offdiscoversuccess)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                          |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | 是    | 取消注册设备发现回调，固定为deviceFound。                |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | 否    | 指示要取消注册的设备发现回调，返回设备状态和设备信息。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import deviceManager from '@ohos.distributedHardware.deviceManager';
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    device: deviceManager.DeviceInfo = {
      deviceId: "",
      deviceName: "",
      deviceType: 0,
      networkId: "",
      range: 0,
      authForm:0
    };
  }

  try {
    dmInstance.off('deviceFound', (data: Data) => {
      console.info('deviceFound' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("deviceFound errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('discoverFail')

on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void;

注册设备发现失败回调监听。

> 从API version 11 开始废弃。建议使用[on('discoverFailure')](js-apis-distributedDeviceManager.md#ondiscoverfailure)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                             |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | 是    | 注册设备发现失败回调，以便在发现周边设备失败时通知应用程序，固定为discoverFail。 |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 是    | 注册设备发现失败的回调方法。                 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.on('discoverFail', (data: Data) => {
      console.info("discoverFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("discoverFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('discoverFail')

off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void;

取消注册设备发现失败回调。

> 从API version 11 开始废弃。建议使用[off('discoverFailure')](js-apis-distributedDeviceManager.md#offdiscoverfailure)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                |
  | -------- | ---------------------------------------- | ---- | ----------------- |
  | type     | string                                   | 是    | 取消注册设备发现失败回调，固定为discoverFail。     |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 否    | 指示要取消注册的设备发现失败回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    subscribeId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.off('discoverFail', (data: Data) => {
      console.info('discoverFail' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("discoverFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('publishSuccess')<sup>9+</sup>

on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void;

注册发布设备发现回调监听。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | 是   | 注册发布设备成功回调，以便将发布成功时通知应用程序，固定为publishSuccess。 |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | 是   | 注册设备发布成功的回调方法。               |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
  }

  try {
    dmInstance.on('publishSuccess', (data: Data) => {
      console.info("publishSuccess:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishSuccess errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('publishSuccess')<sup>9+</sup>

off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void;

取消注册设备发布成功回调。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                          |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | 是   | 取消注册设备发布成功回调，固定为publishSuccess。                 |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | 否   | 指示要取消注册的设备发布成功回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
  }

  try {
    dmInstance.off('publishSuccess', (data: Data) => {
      console.info('publishSuccess' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishSuccess errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('publishFail')<sup>9+</sup>

on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void;

注册设备发布失败回调监听。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名     | 类型                                              | 必填 | 说明                             |
  | -------- | ----------------------------------------------------- | ---- | ------------------------------ |
  | type     | string                                                | 是   | 注册设备发布失败回调，以便在发布设备失败时通知应用程序，固定为publishFail。 |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 是   | 注册设备发布失败的回调方法。                 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.on('publishFail', (data: Data) => {
      console.info("publishFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('publishFail')<sup>9+</sup>

off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void;

取消注册设备发布失败回调。

> 从API version 11 开始废弃。无替代接口。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名     | 类型                                              | 必填 | 说明                |
  | -------- | ----------------------------------------------------- | ---- | ----------------- |
  | type     | string                                                | 是   | 取消注册设备发布失败回调，固定为publishFail。     |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 否   | 指示要取消注册设备发布失败回调。 |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  class Data {
    publishId: number = 0;
    reason: number = 0;
  }

  try {
    dmInstance.off('publishFail', (data: Data) => {
      console.info('publishFail' + JSON.stringify(data));
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("publishFail errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### on('serviceDie')

on(type: 'serviceDie', callback: () =&gt; void): void;

注册设备管理服务死亡监听。

> 从API version 11 开始废弃。建议使用[on('serviceDie')](js-apis-distributedDeviceManager.md#onservicedie)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                    | 必填   | 说明                                       |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | 是    | 注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序，固定为serviceDie。 |
  | callback | ()&nbsp;=&gt;&nbsp;void | 是    | 注册serviceDie的回调方法。                       |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.on("serviceDie", () => {
      console.info("serviceDie on");
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("serviceDie errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```

### off('serviceDie')

off(type: 'serviceDie', callback?: () =&gt; void): void;

取消注册设备管理服务死亡监听。

> 从API version 11 开始废弃。建议使用[off('serviceDie')](js-apis-distributedDeviceManager.md#offservicedie)替代。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                    | 必填   | 说明                                       |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | 是    | 取消注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序，固定为serviceDie。 |
  | callback | ()&nbsp;=&gt;&nbsp;void | 否    | 取消注册serviceDie的回调方法。                     |

**错误码：**

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API.                              |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter type; 3. Parameter verification failed. 4. The size of specified eventType is greater than 255. |

**示例：**

示例中`dmInstance`的初始化请参见[DM初始化](#devicemanagercreatedevicemanager)。
  ```ts
  import { BusinessError } from '@ohos.base';

  try {
    dmInstance.off("serviceDie", () => {
      console.info("serviceDie off");
    });
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error("serviceDie errCode:" + e.code + ",errMessage:" + e.message);
  }
  ```