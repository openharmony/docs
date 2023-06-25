# @ohos.distributedDeviceManager (设备管理)

本模块提供分布式设备管理能力。

应用可调用接口实现如下功能：

- 注册和解除注册设备上下线变化监听
- 发现周边不可信设备
- 认证和取消认证设备
- 查询可信设备列表
- 查询本地设备信息，包括设备名称，设备类型和设备标识

系统应用可调用接口实现如下功能：

- 发布设备发现

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import deviceManager from '@ohos.distributedDeviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void

创建一个设备管理器实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                                        |
| ---------- | ---------------------------------------------------- | ---- | ----------------------------------------------------------- |
| bundleName | string                                               | 是   | 指示应用程序的Bundle名称。                                  |
| callback   | AsyncCallback&lt;[DeviceManager](#devicemanager)&gt; | 是   | DeviceManager实例创建时调用的回调，返回设备管理器对象实例。 |

**示例：**

  ```js
  try {
    deviceManager.createDeviceManager("ohos.samples.jshelloworld", (err, data) => {
      if (err) { 
        console.error("createDeviceManager errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.info("createDeviceManager success");
      let dmInstance = data;
    });
  } catch(err) {
    console.error("createDeviceManager errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## DeviceBasicInfo

设备信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称                     | 类型                        | 必填   | 说明       |
| ---------------------- | ------------------------- | ---- | -------- |
| deviceId               | string                    | 是    | 设备的唯一标识。 |
| deviceName             | string                    | 是    | 设备名称。    |
| deviceType             | number                    | 是    | 设备类型。    |
| networkId              | string                    | 是    | 设备网络标识。  |

## DeviceStatusChange

表示设备状态变化的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称         | 值  | 说明              |
| ----------- | ---- | --------------- |
| UNKNOWN     | 0    | 设备物理上线，此时状态未知。           |
| AVAILABLE   | 1    | 设备可用状态，表示设备间信息已在分布式数据中同步完成, 可以运行分布式业务。 |
| UNAVAILABLE | 2    | 设备物理下线，此时状态未知。           |


## DiscoverMode

表示发现模式的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称                    | 值  | 说明    |
| --------------------- | ---- | ----- |
| DISCOVER_MODE_PASSIVE | 0x55 | 被动模式。 |
| DISCOVER_MODE_ACTIVE  | 0xAA | 主动模式。 |


## ExchangeFreq 

表示发现频率的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称         | 值  | 说明    |
| ---------- | ---- | ----- |
| LOW        | 0    | 低频率。  |
| MID        | 1    | 中频率。  |
| HIGH       | 2    | 高频率。  |
| SUPER_HIGH | 3    | 超高频率。 |


## BindParam

认证参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称        | 类型                   | 必填   | 说明         |
| --------- | -------------------- | ---- | ---------- |
| bindType  | number               | 是    | 认证类型。      |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | 否    | 认证参数可扩展字段。可选，默认为undefined。 |

## AuthInfo

认证信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称        | 类型                   | 必填   | 说明         |
| --------- | -------------------- | ---- | ---------- |
| authType  | number               | 是    | 认证类型。      |
| token     | number               | 是    | 认证Token。   |
| extraInfo | {[key:string]&nbsp;:&nbsp;any} | 否    | 认证信息可扩展字段。可选，默认为undefined。 |

## PublishInfo

发布设备参数

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

| 名称          | 类型                              | 必填   | 说明                |
| ------------- | --------------------------------- | ---- | ----------------- |
| publishId     | number                            | 是    | 发布设备标识，用于标识不同的发布周期。 |
| mode          | [DiscoverMode ](#discovermode)    | 是    | 发现模式。             |
| freq          | [ExchangeFreq](#exchangefreq)     | 是    | 发现频率。             |
| ranging       | boolean                           | 是    | 发布的设备是否支持测距能力。             |

## DeviceManager

设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。

### releaseDeviceManager

releaseDeviceManager(): void

设备管理实例不再使用后，通过该方法释放DeviceManager实例。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    dmInstance.releaseDeviceManager();
  } catch (err) {
    console.error("release device manager errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getAvailableDeviceListSync

getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;

同步获取所有可信设备列表。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 名称                                        | 说明        |
  | ------------------------------------------- | --------- |
  | Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt; | 返回可信设备列表。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    var deviceInfoList = dmInstance.getAvailableDeviceListSync();
  } catch (err) {
    console.error("getAvailableDeviceListSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getAvailableDeviceList

getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void

获取所有可信设备列表。使用callback异步回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                    |
  | -------- | ---------------------------------------- | ---- | --------------------- |
  | callback | AsyncCallback&lt;Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt;&gt; | 是    | 获取所有可信设备列表的回调，返回设备信息。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    dmInstance.getAvailableDeviceList((err, data) => {
      if (err) {
        console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);
        return;
      }
      console.log('get available device info: ' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getAvailableDeviceList

getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;

获取所有可信设备列表。使用Promise异步回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 类型                                                       | 说明                               |
  | ---------------------------------------------------------- | ---------------------------------- |
  | Promise&lt;Array&lt;[DeviceBasicInfo](#devicebasicinfo)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  dmInstance.getAvailableDeviceList().then((data) => {
    console.log('get available device info: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);
  });
  ```

### getLocalDeviceNetworkIdSync

getLocalDeviceNetworkIdSync(): string

同步获取本地设备网络标识。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 名称                      | 说明              |
  | ------------------------- | ---------------- |
  | string | 返回本地设备网络标识。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    var deviceNetworkId = dmInstance.getLocalDeviceNetworkIdSync();
    console.log('local device networkId: ' + JSON.stringify(deviceNetworkId));
  } catch (err) {
    console.error("getLocalDeviceNetworkIdSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceNameSync

getLocalDeviceNameSync(): string

同步获取本地设备名称。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 名称                      | 说明              |
  | ------------------------- | ---------------- |
  | string                    | 返回本地设备名称。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    var deviceName = dmInstance.getLocalDeviceNameSync();
    console.log('local device name: ' + JSON.stringify(deviceName));
  } catch (err) {
    console.error("getLocalDeviceNameSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceTypeSync

getLocalDeviceTypeSync(): number

同步获取本地设备类型。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 名称                      | 说明              |
  | ------------------------- | ---------------- |
  | number                    | 返回本地设备类型。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    var deviceType = dmInstance.getLocalDeviceTypeSync();
    console.log('local device type: ' + JSON.stringify(deviceType));
  } catch (err) {
    console.error("getLocalDeviceTypeSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getLocalDeviceIdSync

getLocalDeviceIdSync(): string

同步获取本地设备id。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**返回值：**

  | 名称                      | 说明              |
  | ------------------------- | ---------------- |
  | string                    | 返回本地设备id。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    var deviceId = dmInstance.getLocalDeviceIdSync();
    console.log('local device id: ' + JSON.stringify(deviceId));
  } catch (err) {
    console.error("getLocalDeviceIdSync errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getDeviceNameSync

getDeviceNameSync(networkId: string): string;

通过指定设备的网络标识同步获取该设备名称。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明        |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | 是   | 设备的网络标识。 |

**返回值：**

  | 名称                      | 说明              |
  | ------------------------- | ---------------- |
  | string                    | 返回指定设备名称。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    // 设备网络标识，可以从可信设备列表中获取
    let networkId = "xxxxxxx"
    var deviceName = dmInstance.getDeviceNameSync(networkId);
    console.log('device name: ' + JSON.stringify(deviceName)); 
  } catch (err) {
    console.error("getDeviceName errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### getDeviceTypeSync

getDeviceTypeSync(networkId: string): number;

通过指定设备的网络标识同步获取该设备类型。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明        |
  | -------- | ---------------------------------------- | ---- | --------- |
  | networkId| string                                   | 是   | 设备的网络标识。 |

**返回值：**

  | 名称                      | 说明              |
  | ------------------------- | ---------------- |
  | number                    | 返回指定设备类型。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    // 设备网络标识，可以从可信设备列表中获取
    let networkId = "xxxxxxx"
    var deviceType = dmInstance.getDeviceTypeSync(networkId);
    console.log('device type: ' + JSON.stringify(deviceType)); 
  } catch (err) {
    console.error("getDeviceType errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### startDeviceDiscovery

startDeviceDiscovery(subscribeId: number, filterOptions?: string): void;

发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名            | 类型                        | 必填   | 说明    |
  | ------------- | ------------------------------- | ---- | -----  |
  | subscribeId   | number                          | 是   | 发现标识。 |
  | filterOptions | string                          | 否   | 发现设备过滤信息。可选，默认为undefined，发现未上线设备。|

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery invalid.                                              |

**示例：**

  ```js
  // 生成发现标识，随机数确保每次调用发现接口的标识不一致
  var subscribeId = Math.floor(Math.random() * 10000 + 1000);
  var filterOptions = {
    "filter_op": "OR", // 可选, 默认"OR"
    "filters": [
        {
            "type": "range",
            "value": 50 // 需过滤发现设备的距离，单位(cm)
        }
    ]
  };
  try {
    dmInstance.startDeviceDiscovery(subscribeId, filterOptions); // 当有设备发现时，通过deviceFound回调通知给应用程序
  } catch (err) {
    console.error("startDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### stopDeviceDiscovery

stopDeviceDiscovery(subscribeId: number): void

停止发现周边设备。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名          | 类型   | 必填   | 说明    |
  | ----------- | ------ | ---- | ----- |
  | subscribeId | number | 是    | 发现标识。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    // stopDeviceDiscovery和startDeviceDiscovery需配对使用，入参需要和startDeviceDiscovery接口传入的subscribeId值相等
    var subscribeId = 12345;
    dmInstance.stopDeviceDiscovery(subscribeId);
  } catch (err) {
    console.error("stopDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### publishDeviceDiscovery

publishDeviceDiscovery(publishInfo: PublishInfo): void

发布设备发现。发布状态持续两分钟，超过两分钟会停止发布。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名          | 类型                        | 必填 | 说明    |
  | ------------- | ------------------------------- | ---- | ----- |
  | publishInfo   | [PublishInfo](#publishinfo)     | 是   | 发布设备发现信息。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600105 | Publish invalid.                                                |

**示例：**

  ```js
  // 生成发布标识，随机数确保每次调用发布接口的标识不一致
  var publishId = Math.floor(Math.random() * 10000 + 1000);
  var publishInfo = {
      "publishId": publishId,
      "mode": 0xAA, // 主动模式
      "freq": 2,    // 高频率
      "ranging": true  // 支持发现时测距
  };
  try {
    dmInstance.publishDeviceDiscovery(publishInfo); // 当有发布结果时，通过回调通知给应用程序
  } catch (err) {
    console.error("publishDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### unPublishDeviceDiscovery

unPublishDeviceDiscovery(publishId: number): void

停止发布设备发现。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名        | 类型 | 必填 | 说明  |
  | ----------- | -------- | ---- | ----- |
  | publishId   | number   | 是   | 发布标识。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    // unPublishDeviceDiscovery和publishDeviceDiscovery配对使用，入参需要和publishDeviceDiscovery接口传入的publishId值相等
    var publishId = 12345;
    dmInstance.unPublishDeviceDiscovery(publishId);
  } catch (err) {
    console.error("unPublishDeviceDiscovery errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### bindDevice

bindDevice(deviceId: string, bindParam: BindParam, callback: AsyncCallback<{deviceId: string}>): void;

认证设备。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名     | 类型                                                | 必填  | 说明         |
  | ---------- | --------------------------------------------------- | ----- | ------------ |
  | deviceId   | string                                              | 是    | 设备标识。   |
  | bindParam  | [BindParam](#bindparam)                             | 是    | 认证参数。   |
  | callback   | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;}&gt; | 是    | 认证结果回调 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600103 | Bind invalid.                                                   |

**示例：**

  ```js
  // 认证的设备信息，可以从发现的结果中获取
  var deviceId ="XXXXXXXX";
  let extraInfo = {
          'targetPkgName': 'ohos.samples.xxx',
          'appName': 'xxx',
          'appDescription': 'xxx',
          'business': '0'
  }
  let bindParam = {
      'bindType': 1,// 认证类型： 1 - 无帐号PIN码认证
      'extraInfo': extraInfo
  }
  try {
    dmInstance.bindDevice(deviceId, authParam, (err, data) => {
      if (err) {
          console.error("bindDevice errCode:" + err.code + ",errMessage:" + err.message);
          return;
      }
      console.info("bindDevice result:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("bindDevice errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### unbindDevice

unbindDevice(deviceId: string): void;

解除认证设备。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名   | 类型                      | 必填 | 说明       |
  | -------- | ------------------------- | ---- | ---------- |
  | deviceId | string                    | 是   | 设备标识。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    var deviceId ="XXXXXXXX";
    dmInstance.unbindDevice(deviceId);
  } catch (err) {
    console.error("unbindDevice errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### verifyAuthInfo

verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback&lt;{deviceId: string, level: number}&gt;): void

验证认证信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明      |
  | -------- | ---------------------------------------- | ---- | ------- |
  | authInfo | [AuthInfo](#authinfo)                    | 是    | 认证信息。   |
  | callback | AsyncCallback&lt;{deviceId:&nbsp;string,&nbsp;level:&nbsp;number}&gt; | 是    | 验证结果回调。 |

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  let authInfo = {
    "authType": 1,
    "token": 123456,
    "extraInfo": {}
  }
  try {
    dmInstance.verifyAuthInfo(authInfo, (err, data) => {
    if (err) {
        console.error("verifyAuthInfo errCode:" + err.code + ",errMessage:" + err.message);
        return;
    }
    console.info("verifyAuthInfo result:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("verifyAuthInfo errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### setUserOperation

setUserOperation(operateAction: number, params: string): void;

设置用户ui操作行为。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | operateAction | number          | 是    | 用户操作动作。       |
  | params        | string          | 是    | 表示用户的输入参数。 |

**示例：**

  ```js
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
    dmInstance.setUserOperation(operation, "extra")
    } catch (err) {
      console.error("setUserOperation errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### requestCredentialRegisterInfo

requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback<{registerInfo: string}>): void;

获取凭据的注册信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | requestInfo   | string          | 是    | 请求凭据信息。       |
  | callback      | AsyncCallback<{registerInfo: string}>         | 是    | 凭据的注册信息回调。 |

**示例：**

  ```js
  let credentialInfo = {
    "version" : "1.2.3",
    "userId" : "123"
  }
  try {
    dmInstance.requestCredentialRegisterInfo(credentialInfo, (data) => {
      if (data) {
          console.info("requestCredentialRegisterInfo result:" + JSON.stringify(data));
      } else {
          console.info("requestCredentialRegisterInfo result: data is null");
      }
    });
  } catch (err) {
    console.error("requestCredentialRegisterInfo err:" + err.code + "," + err.message);
  }
  ```

### importCredential

importCredential(credentialInfo: string, callback: AsyncCallback<{resultInfo: string}>): void;

导入凭据信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | credentialInfo| string          | 是    | 导入凭据信息。       |
  | callback      | AsyncCallback<{resultInfo: string}>           | 是    | 导入凭据结果回调。 |

**示例：**

  ```js
  let credentialInfo = {
    "processType" : 1,
    "authType" : 1,
    "userId" : "123",
    "deviceId" : "aaa",
    "version" : "1.2.3",
    "devicePk" : "0000",
    "credentialData" : 
    [
      {
        "credentialType" : 2,
        "credentialId" : "102",
        "serverPk" : "3059301306072A8648CE3D020106082A8648CE3D03",
        "pkInfoSignature" : "30440220490BCB4F822004C9A76AB8D97F80041FC0E",
        "pkInfo" : "",
        "authCode" : "",
        "peerDeviceId" : ""
      }
    ]
  }
  try {
    dmInstance.importCredential(credentialInfo, (data) => {
      if (data) {
          console.info("importCredential result:" + JSON.stringify(data));
      } else {
          console.info("importCredential result: data is null");
      }
    });
  } catch (err) {
    console.error("importCredential err:" + err.code + "," + err.message);
  }
  ```

### deleteCredential

deleteCredential(queryInfo: string, callback: AsyncCallback<{resultInfo: string}>): void;

删除凭据信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | queryInfo     | string          | 是    | 删除凭据信息。       |
  | callback      | AsyncCallback<{resultInfo: string}>           | 是    | 删除凭据结果回调。 |

**示例：**

  ```js
  let queryInfo = {
    "processType" : 1,
    "authType" : 1,
    "userId" : "123"
  }
  try {
    dmInstance.deleteCredential(queryInfo, (data) => {
      if (data) {
          console.info("deleteCredential result:" + JSON.stringify(data));
      } else {
          console.info("deleteCredential result: data is null");
      }
    });
  } catch (err) {
    console.error("deleteCredential err:" + err.code + "," + err.message);
  }
  ```

### on('uiStateChange')

on(type: 'uiStateChange', callback: Callback&lt;{ param: string}&gt;): void;

ui状态变更回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名      | 类型                             | 必填 | 说明                            |
  | -------- | ------------------------------------ | ---- | ------------------------------ |
  | type     | string                                | 是  | 注册的设备管理器 ui 状态回调，以便在状态改变时通知应用。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | 是  | 指示要注册的设备管理器 ui 状态回调，返回ui状态。        |

**示例：**

  ```js
  try {
    dmInstance.on('uiStateChange', (data) => {
    console.log("uiStateChange executed, dialog closed" + JSON.stringify(data))
    var tmpStr = JSON.parse(data.param)
    var isShow = tmpStr.verifyFailed
    console.log("uiStateChange executed, dialog closed" + isShow)
  });
  } catch (err) {
    console.error("uiStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('uiStateChange')

off(type: 'uiStateChange', callback?: Callback&lt;{ param: string}&gt;): void;

取消ui状态变更回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名      | 类型                              | 必填 | 说明                            |
  | -------- | ------------------------------------- | ---- | ------------------------------ |
  | type     | string                                | 是   | 取消注册的设备管理器 ui 状态回调。 |
  | callback | Callback&lt;{&nbsp;param:&nbsp;string}&gt; | 否   | 指示要取消注册的设备管理器 ui 状态，返回UI状态。 |

**示例：**

  ```js
  try {
    dmInstance.off('uiStateChange');
  } catch (err) {
    console.error("uiStateChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('deviceStatusChange')

on(type: 'deviceStatusChange', callback: Callback<{ action: DeviceStatusChange, device: DeviceBasicInfo }>): void;

注册设备状态回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                             |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | 是    | 注册设备状态回调，固定为deviceStateChange。 |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStatusChange](#devicestatuschange),&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | 是    | 指示要注册的设备状态回调，返回设备状态和设备信息。      |

**示例：**

  ```js
  try {
    dmInstance.on('deviceStatusChange', (data) => {
      console.info("deviceStatusChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceStatusChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('deviceStatusChange')

off(type: 'deviceStatusChange', callback?: Callback<{ action: DeviceStatusChange, device: DeviceBasicInfo }>): void;

取消注册设备状态回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                          |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | 是    | 根据应用程序的包名取消注册设备状态回调。        |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStatusChange](#devicestatuschange),&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | 否    | 指示要取消注册的设备状态回调，返回设备状态和设备信息。 |

**示例：**

  ```js
  try {
    dmInstance.off('deviceStatusChange', (data) => {
      console.info('deviceStatusChange' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceStatusChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('discoverSuccess')

on(type: 'discoverSuccess', callback: Callback<{ subscribeId: number, device: DeviceBasicInfo }>): void;

注册发现设备成功回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                         |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | 是    | 注册设备发现回调，以便在发现周边设备时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | 是    | 注册设备发现的回调方法。               |

**示例：**

  ```js
  try {
    dmInstance.on('discoverSuccess', (data) => {
      console.info("discoverSuccess:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('discoverSuccess')

off(type: 'discoverSuccess', callback?: Callback<{ subscribeId: number, device: DeviceBasicInfo }>): void;

取消注册设备发现回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                          |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | 是    | 取消注册设备发现回调。                 |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | 否    | 指示要取消注册的设备发现回调，返回设备状态和设备信息。 |

**示例：**

  ```js
  try {
    dmInstance.off('discoverSuccess', (data) => {
      console.info('discoverSuccess' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('deviceNameChange')

on(type: 'deviceNameChange', callback: Callback<{ deviceName: string }>): void;

注册设备名称改变回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                             |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | 是    | 注册设备名称改变回调，以便在设备名称改变时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;deviceName:&nbsp;string}&gt; | 是    | 注册设备名称改变的回调方法。                 |

**示例：**

  ```js
  try {
    dmInstance.on('deviceNameChange', (data) => {
        console.info("deviceNameChange on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceNameChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('deviceNameChange')

off(type: 'deviceNameChange', callback?: Callback<{ deviceName: string }>): void;

取消注册设备名称改变回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                             |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | 是    | 取消注册设备名称改变回调。 |
  | callback | Callback&lt;{&nbsp;deviceName:&nbsp;string}&gt; | 否    | 指示要取消注册设备名称改变的回调方法。                 |

**示例：**

  ```js
  try {
    dmInstance.off('deviceNameChange', (data) => {
      console.info('deviceNameChange' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("deviceNameChange errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('discoverFail')

on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

注册设备发现失败回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                             |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | 是    | 注册设备发现失败回调，以便在发现周边设备失败时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 是    | 注册设备发现失败的回调方法。                 |

**示例：**

  ```js
  try {
    dmInstance.on('discoverFail', (data) => {
        console.info("discoverFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('discoverFail')

off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

取消注册设备发现失败回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                |
  | -------- | ---------------------------------------- | ---- | ----------------- |
  | type     | string                                   | 是    | 取消注册设备发现失败回调。     |
  | callback | Callback&lt;{&nbsp;subscribeId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 否    | 指示要取消注册的设备发现失败回调。 |

**示例：**

  ```js
  try {
    dmInstance.off('discoverFail', (data) => {
      console.info('discoverFail' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("discoverFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('publishSuccess')

on(type: 'publishSuccess', callback: Callback&lt;{ publishId: number }&gt;): void

注册发布设备发现回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | 是   | 注册发布设备成功回调，以便将发布成功时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | 是   | 注册设备发布成功的回调方法。               |

**示例：**

  ```js
  try {
    dmInstance.on('publishSuccess', (data) => {
      console.info("publishSuccess:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('publishSuccess')

off(type: 'publishSuccess', callback?: Callback&lt;{ publishId: number }&gt;): void

取消注册设备发布成功回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                          |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | 是   | 取消注册设备发布成功回调。                 |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number&nbsp;}&gt;    | 否   | 指示要取消注册的设备发布成功回调。 |

**示例：**

  ```js
  try {
    dmInstance.off('publishSuccess', (data) => {
      console.info('publishSuccess' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishSuccess errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('publishFail')

on(type: 'publishFail', callback: Callback&lt;{ publishId: number, reason: number }&gt;): void

注册设备发布失败回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名     | 类型                                              | 必填 | 说明                             |
  | -------- | ----------------------------------------------------- | ---- | ------------------------------ |
  | type     | string                                                | 是   | 注册设备发布失败回调，以便在发布设备失败时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 是   | 注册设备发布失败的回调方法。                 |

**示例：**

  ```js
  try {
    dmInstance.on('publishFail', (data) => {
      console.info("publishFail on:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('publishFail')

off(type: 'publishFail', callback?: Callback&lt;{ publishId: number, reason: number }&gt;): void

取消注册设备发布失败回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名     | 类型                                              | 必填 | 说明                |
  | -------- | ----------------------------------------------------- | ---- | ----------------- |
  | type     | string                                                | 是   | 取消注册设备发布失败回调。     |
  | callback | Callback&lt;{&nbsp;publishId:&nbsp;number,&nbsp;reason:&nbsp;number&nbsp;}&gt; | 否   | 指示要取消注册设备发布失败回调。 |

**示例：**

  ```js
  try {
    dmInstance.off('publishFail', (data) => {
      console.info('publishFail' + JSON.stringify(data));
    });
  } catch (err) {
    console.error("publishFail errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('serviceDie')

on(type: 'serviceDie', callback: () =&gt; void): void

注册设备管理服务死亡监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                    | 必填   | 说明                                       |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | 是    | 注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序。 |
  | callback | ()&nbsp;=&gt;&nbsp;void | 是    | 注册serviceDie的回调方法。                       |

**示例：**

  ```js
  try {
    dmInstance.on("serviceDie", () => {
      console.info("serviceDie on");
    });
  } catch (err) {
    console.error("serviceDie errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('serviceDie')

off(type: 'serviceDie', callback?: () =&gt; void): void

取消注册设备管理服务死亡监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                    | 必填   | 说明                                       |
  | -------- | ----------------------- | ---- | ---------------------------------------- |
  | type     | string                  | 是    | 取消注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序。 |
  | callback | ()&nbsp;=&gt;&nbsp;void | 否    | 取消注册serviceDie的回调方法。                     |

**示例：**

  ```js
  try {
    dmInstance.off("serviceDie", () => {
      console.info("serviceDie off");
    });
  } catch (err) {
    console.error("serviceDie errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```
  