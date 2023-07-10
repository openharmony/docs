# @ohos.distributedDeviceManager (设备管理)

本模块提供分布式设备管理能力。

应用可调用接口实现如下功能：

- 注册和解除注册设备上下线变化监听
- 发现周边不可信设备
- 认证和取消认证设备
- 查询可信设备列表
- 查询本地设备信息，包括设备名称，设备类型和设备标识


> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import deviceManager from '@ohos.distributedDeviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void;

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


## BindParam

认证参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称        | 类型                   | 必填   | 说明         |
| --------- | -------------------- | ---- | ---------- |
| bindType  | number               | 是    | 认证类型。默认会携带以下key值：<br />-1: PIN码。<br />-2: 二维码。<br />-3: NFC。<br />-4: 没有交互。     |
| extraInfo | {[key:string]&nbsp;:&nbsp;Object} | 否    | 认证参数可扩展字段。可选，默认为undefined。 可携带以下key值:<br />- targetPkgName： 绑定目标的包名。<br />- appName: 尝试绑定目标的应用名称。<br />-appOperation : app要绑定目标包的原因。


## DeviceManager

设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。

### releaseDeviceManager

releaseDeviceManager(): void;

设备管理实例不再使用后，通过该方法释放DeviceManager实例。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

getAvailableDeviceListSync(): Array&lt;DeviceBasicInfo&gt;;

同步获取所有可信设备列表。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

getAvailableDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceBasicInfo&gt;&gt;): void;

获取所有可信设备列表。使用callback异步回调。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

getAvailableDeviceList(): Promise&lt;Array&lt;DeviceBasicInfo&gt;&gt;;

获取所有可信设备列表。使用Promise异步回调。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

getLocalDeviceNetworkIdSync(): string;

同步获取本地设备网络标识。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

getLocalDeviceNameSync(): string;

同步获取本地设备名称。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

getLocalDeviceTypeSync(): number;

同步获取本地设备类型。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

getLocalDeviceIdSync(): string;

同步获取本地设备id。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

### startDiscovering

startDiscovering(discoverParameter:string, filterOptions?: string): void;

发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名            | 类型                        | 必填   | 说明    |
  | ------------- | ------------------------------- | ---- | -----  |
  | discoverParameter   | string                          | 是   | 发现标识。 标识发现的目标类型。目前只支持一种类型。 发现附件设备，值为1。|
  | filterOptions | string                          | 否   | 发现设备过滤信息。可选，默认为undefined，发现未上线设备。会携带以下key值：<br />-filter_op: 过滤设备的条件。值类型为字符串，如'or'或'and'。<br />-filters: 根据该参数过滤设备。如果filter_op为'or'，则发现满足其中一个过滤器的设备；如果filter_op为'and'，则查找满足所有过滤器的设备；过滤器的值类型为key-value，如：<br />-credible: 仅发现设备是可信的，取值为0或1。<br />-range： 仅发现范围内的设备，值小于1米。<br />-isTrusted: 仅发现受信任的设备，取值为0或1。<br />-authForm: 仅发现设备指定身份验证，取值范围为1~4。<br />-deviceType: 仅发现指定类型的设备，取值如下: <br />-0: 未知设备类型。<br />-8: 智能摄像机。<br />-10: 智能音箱。<br />-12: 智能PC。<br />-14: 智能手机。<br />-17: 智能PAD。<br />-109: 智能手表。<br />-131: 汽车。<br />-156: 智能电视。|

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |
| 11600104 | Discovery invalid.                                              |

**示例：**

  ```js
  var discoverParameter = "1";
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
    dmInstance.startDiscovering(discoverParameter, filterOptions); // 当有设备发现时，通过discoverSuccess回调通知给应用程序
  } catch (err) {
    console.error("startDiscovering errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### stopDiscovering

stopDiscovering(): void;

停止发现周边设备。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**错误码：**

以下的错误码的详细介绍请参见[设备管理错误码](../errorcodes/errorcode-device-manager.md)

| 错误码ID | 错误信息                                                        |
| -------- | --------------------------------------------------------------- |
| 11600101 | Failed to execute the function.                                 |

**示例：**

  ```js
  try {
    dmInstance.stopDiscovering();
  } catch (err) {
    console.error("stopDiscovering errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### bindTarget

bindTarget(deviceId: string, bindParam: BindParam, callback: AsyncCallback&lt;{deviceId: string}&gt;): void;

认证设备。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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
    dmInstance.bindTarget(deviceId, authParam, (err, data) => {
      if (err) {
          console.error("bindTarget errCode:" + err.code + ",errMessage:" + err.message);
          return;
      }
      console.info("bindTarget result:" + JSON.stringify(data));
    });
  } catch (err) {
    console.error("bindTarget errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### unbindTarget

unbindTarget(deviceId: string): void;

解除认证设备。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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
    dmInstance.unbindTarget(deviceId);
  } catch (err) {
    console.error("unbindTarget errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### replyUiAction

replyUiAction(action: number, params: string): void;

回复用户ui操作行为。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**系统API**： 此接口为系统接口。

**参数：**

  | 参数名       | 类型            | 必填  | 说明                |
  | ------------- | --------------- | ---- | ------------------- |
  | action        | number          | 是    | 用户操作动作。       |
  | params        | string          | 是    | 表示用户的输入参数。 |

**示例：**

  ```js
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
    dmInstance.replyUiAction(operation, "extra")
    } catch (err) {
      console.error("replyUiAction errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('replyResult')

on(type: 'replyResult', callback: Callback&lt;{ param: string}&gt;): void;

回复UI操作结果回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

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
    dmInstance.on('replyResult', (data) => {
    console.log("replyResult executed, dialog closed" + JSON.stringify(data))
    var tmpStr = JSON.parse(data.param)
    var isShow = tmpStr.verifyFailed
    console.log("replyResult executed, dialog closed" + isShow)
  });
  } catch (err) {
    console.error("replyResult errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### off('replyResult')

off(type: 'replyResult', callback?: Callback&lt;{ param: string}&gt;): void;

取消回复UI操作结果回调。

**需要权限**：ohos.permission.ACCESS_SERVICE_DM

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
    dmInstance.off('replyResult');
  } catch (err) {
    console.error("replyResult errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

### on('deviceStatusChange')

on(type: 'deviceStatusChange', callback: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void;

注册设备状态回调。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

off(type: 'deviceStatusChange', callback?: Callback&lt;{ action: DeviceStatusChange, device: DeviceBasicInfo }&gt;): void;

取消注册设备状态回调。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

on(type: 'discoverSuccess', callback: Callback&lt;{ device: DeviceBasicInfo }&gt;): void;

注册发现设备成功回调监听。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                         |
  | -------- | ---------------------------------------- | ---- | -------------------------- |
  | type     | string                                   | 是    | 注册设备发现回调，以便在发现周边设备时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | 是    | 注册设备发现的回调方法。               |

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

off(type: 'discoverSuccess', callback?: Callback&lt;{ device: DeviceBasicInfo }&gt;): void;

取消注册设备发现成功回调。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                          |
  | -------- | ---------------------------------------- | ---- | --------------------------- |
  | type     | string                                   | 是    | 取消注册设备发现回调。                 |
  | callback | Callback&lt;{&nbsp;device:&nbsp;[DeviceBasicInfo](#devicebasicinfo)&nbsp;}&gt; | 否    | 指示要取消注册的设备发现回调，返回设备状态和设备信息。 |

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

on(type: 'deviceNameChange', callback: Callback&lt;{ deviceName: string }&gt;): void;

注册设备名称变更回调监听。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

off(type: 'deviceNameChange', callback?: Callback&lt;{ deviceName: string }&gt;): void;

取消注册设备名称变更回调监听。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

on(type: 'discoverFail', callback: Callback&lt;{ reason: number }&gt;): void;

注册设备发现失败回调监听。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                             |
  | -------- | ---------------------------------------- | ---- | ------------------------------ |
  | type     | string                                   | 是    | 注册设备发现失败回调，以便在发现周边设备失败时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;reason:&nbsp;number&nbsp;}&gt; | 是    | 注册设备发现失败的回调方法。                 |

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

off(type: 'discoverFail', callback?: Callback&lt;{ reason: number }&gt;): void;

取消注册设备发现失败回调。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

**参数：**

  | 参数名       | 类型                                     | 必填   | 说明                |
  | -------- | ---------------------------------------- | ---- | ----------------- |
  | type     | string                                   | 是    | 取消注册设备发现失败回调。     |
  | callback | Callback&lt;{&nbsp;reason:&nbsp;number&nbsp;}&gt; | 否    | 指示要取消注册的设备发现失败回调。 |

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

### on('serviceDie')

on(type: 'serviceDie', callback: () =&gt; void): void;

注册设备管理服务死亡监听。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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

off(type: 'serviceDie', callback?: () =&gt; void): void;

取消注册设备管理服务死亡监听。

**需要权限**：ohos.permission.DISTRIBUTED_DATASYNC

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
  