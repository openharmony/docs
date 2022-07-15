# 设备管理

本模块提供分布式设备管理能力。

系统应用可调用接口实现如下功能：

- 注册和解除注册设备上下线变化监听
- 发现周边不可信设备
- 认证和取消认证设备
- 查询可信设备列表
- 查询本地设备信息，包括设备名称，设备类型和设备标识

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用。


## 导入模块

```
import deviceManager from '@ohos.distributedHardware.deviceManager';
```


## deviceManager.createDeviceManager

createDeviceManager(bundleName: string, callback: AsyncCallback&lt;DeviceManager&gt;): void

创建一个设备管理器实例。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 指示应用程序的包名。 |
  | callback | AsyncCallback&lt;[DeviceManager](#devicemanager)&gt; | 是 | DeviceManager实例创建时调用的回调，返回设备管理器对象实例。 |

- 示例：
  ```
  deviceManager.createDeviceManager("ohos.samples.jshelloworld", (err, data) => {     
      if (err) { 
          console.info("createDeviceManager err:" + JSON.stringify(err));    
          return;
      }
      console.info("createDeviceManager success");
      this.dmInstance = data;
  });
  ```

## DeviceInfo

设备信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 设备的唯一标识。 |
| deviceName | string | 是 | 设备名称。 |
| deviceType | [DeviceType](#deviceType) | 是 | 设备类型。 |
| networkId<sup>8+</sup> | string | 是 | 设备网络标识。 |


## DeviceType

表示设备类型的枚举类。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SPEAKER | 0x0A | 智能音箱 |
| PHONE | 0x0E | 手机 |
| TABLET | 0x11 | 平板 |
| WEARABLE | 0x6D | 智能穿戴 |
| TV | 0x9C | 智慧屏 |
| CAR | 0x83 | 车 |
| UNKNOWN_TYPE | 0 | 未知设备 |


## DeviceStateChangeAction

表示设备状态变化的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| ONLINE | 0 | 设备上线。 |
| READY | 1 | 设备就绪，设备信息同步已完成。 |
| OFFLINE | 2 | 设备下线。 |
| CHANGE | 3 | 设备信息更改。 |

## SubscribeInfo

发现信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| subscribeId | number | 是 | 发现标识，用于标识不同的发现周期。 |
| mode | [DiscoverMode ](#discoverMode) | 否 | 发现模式。 |
| medium | [ExchangeMedium](#exchangeMedium) | 否 | 发现类型。 |
| freq | [ExchangeFreq](#exchangeFreq) | 否 | 发现频率。 |
| isSameAccount | boolean | 否 | 是否同账号。 |
| isWakeRemote | boolean | 否 | 是否唤醒设备。 |
| capability | [SubscribeCap](#subscribeCap) | 否 | 发现能力。 |


## DiscoverMode 

表示发现模式的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| DISCOVER_MODE_PASSIVE | 0x55 | 被动模式。 |
| DISCOVER_MODE_ACTIVE | 0xAA | 主动模式。 |


## ExchangeMedium 

表示发现类型的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| AUTO | 0 | 自动发现类型。 |
| BLE | 1 | 蓝牙发现类型。 |
| COAP | 2 | WiFi发现类型。 |
| USB | 3 | USB发现类型。 |

## ExchangeFreq 

表示发现频率的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| LOW | 0 | 低频率。 |
| MID | 1 | 中频率。 |
| HIGH | 2 | 高频率。 |
| SUPER_HIGH | 3 | 超高频率。 |


## SubscribeCap 

表示发现能力的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SUBSCRIBE_CAPABILITY_DDMP | 0 | DDMP能力，后续会被废弃。 |
| SUBSCRIBE_CAPABILITY_OSD | 1 | OSD能力。 |


## AuthParam

认证参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| authType | number | 是 | 认证类型。 |
| extraInfo | {[key:string] : any} | 否 | 认证参数可扩展字段。 |

## AuthInfo

认证信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| authType | number | 是 | 认证类型。 |
| token | number | 是 | 认证Token。 |
| extraInfo | {[key:string] : any} | 否 | 认证信息可扩展字段。 |


## DeviceManager

设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。


### release

release(): void

设备管理实例不再使用后，通过该方法释放DeviceManager实例。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 示例：
  ```js
  dmInstance.release();
  ```


### getTrustedDeviceListSync

getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt;

同步获取所有可信设备列表。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 返回值：
  | 名称 | 说明 |
  | -------- | -------- |
  | Array&lt;[DeviceInfo](#deviceinfo)&gt; | 返回可信设备列表。 |

- 示例：
  ```js
  var deviceInfoList = dmInstance.getTrustedDeviceListSync();
  ```


### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(callback:AsyncCallback&lt;Array&lt;DeviceInfo&gt;&gt;): void

获取所有可信设备列表。使用callback异步回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | 是 | 获取所有可信设备列表的回调，返回设备信息。 |

- 示例：
  ```js
  dmInstance.getTrustedDeviceList((err, data) => {
      console.log("getTrustedDeviceList err: " + JSON.stringify(err));
      console.log('get trusted device info: ' + JSON.stringify(data));
    }
  );
  ```

### getTrustedDeviceList<sup>8+</sup>

getTrustedDeviceList(): Promise&lt;Array&lt;DeviceInfo&gt;&gt;

获取所有可信设备列表。使用Promise异步回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[DeviceInfo](#deviceinfo)&gt;&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：
  ```js
  dmInstance.getTrustedDeviceList().then((data) => { 
      console.log('get trusted device info: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getTrustedDeviceList err: " + JSON.stringify(err));
  });
  ```

### getLocalDeviceInfoSync<sup>8+</sup>

getLocalDeviceInfoSync(): [DeviceInfo](#deviceinfo)

同步获取本地设备信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 返回值：
  | 名称 | 说明 |
  | -------- | -------- |
  | Array&lt;[DeviceInfo](#deviceinfo)&gt; | 返回本地设备列表。 |

- 示例：
  ```js
  var deviceInfo = dmInstance.getLocalDeviceInfoSync();
  ```


### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(callback:AsyncCallback&lt;DeviceInfo&gt;): void

获取本地设备信息。使用callback异步回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DeviceInfo](#deviceinfo)&gt; | 是 | 获取本地设备信息。 |

- 示例：
  ```js
  dmInstance.getLocalDeviceInfo((err, data) => {
      console.log("getLocalDeviceInfo err: " + JSON.stringify(err));
      console.log('get local device info: ' + JSON.stringify(data));
    }
  );
  ```

### getLocalDeviceInfo<sup>8+</sup>

getLocalDeviceInfo(): Promise&lt;DeviceInfo&gt;

获取本地设备信息。使用Promise异步回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[DeviceInfo](#deviceinfo)&gt; | Promise实例，用于获取异步返回结果。 |

- 示例：
  ```js
  dmInstance.getLocalDeviceInfo().then((data) => { 
      console.log('get local device info: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getLocalDeviceInfo err: " + JSON.stringify(err));
  });
  ```

### startDeviceDiscovery

startDeviceDiscovery(subscribeInfo: SubscribeInfo): void

发现周边设备。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | subscribeInfo | [SubscribeInfo](#subscribeInfo) | 是 | 发现信息。 |

- 示例：
  ```js
  //生成发现标识，随机数确保每次调用发现接口的标识不一致
  var subscribeId = Math.floor(Math.random() * 10000 + 1000);
  var subscribeInfo = {
      "subscribeId": subscribeId,
      "mode": 0xAA, //主动模式
      "medium": 0,  //自动发现类型，同时支持多种发现类型
      "freq": 2,    //高频率
      "isSameAccount": false,
      "isWakeRemote": false,
      "capability": 1
  };
  dmInstance.startDeviceDiscovery(subscribeInfo); //当有设备发现时，通过deviceFound回调通知给应用程序
  ```

### stopDeviceDiscovery

stopDeviceDiscovery(subscribeId: number): void

停止发现周边设备。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | subscribeId | number | 是 | 发现标识。 |

- 示例：
  ```js
  //入参需要和startDeviceDiscovery接口传入的subscribeId配对使用
  dmInstance.stopDeviceDiscovery(subscribeId);
  ```

### authenticateDevice

authenticateDevice(deviceInfo: DeviceInfo, authParam: AuthParam, callback: AsyncCallback<{deviceId: string, pinToken ?: number}>): void

认证设备。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceInfo | [DeviceInfo](#deviceInfo) | 是 | 设备信息。 |
  | authParam | [AuthParam](#authParam) | 是 | 认证参数。 |
  | callback | AsyncCallback<{ deviceId: string, pinToken ?: number }> | 是 | 认证结果回调。 |

- 示例：
  ```js
  //认证的设备信息，可以从发现的结果中获取
  var deviceInfo ={
      "deviceId": "XXXXXXXX",
      "deviceName": "",
      deviceType: 0x0E
  };
  let authParam = {
      "authType": 1, //认证类型： 1 - 无账号PIN码认证
      "extraInfo": {} 
  }
  dmInstance.authenticateDevice(deviceInfo, authParam, (err, data) => {
      if (err) {
          console.info(TAG + "authenticateDevice err:" + JSON.stringify(err));
          return;
      }
      console.info(TAG + "authenticateDevice result:" + JSON.stringify(data));
      token = data.pinToken;
  });
  ```

### unAuthenticateDevice<sup>8+</sup>

unAuthenticateDevice(deviceInfo: DeviceInfo): void

解除认证设备。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | deviceInfo | [DeviceInfo](#deviceInfo) | 是 | 设备信息。 |

- 示例：
  ```js
  dmInstance.unAuthenticateDevice(deviceInfo);
  ```


### verifyAuthInfo

verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback<{deviceId: string, level: number}>): void

验证认证信息。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | authInfo | [AuthInfo](#authInfo) | 是 | 认证信息。 |
  | authInfo | AsyncCallback<{ deviceId: string, level: number }> | 是 | 验证结果回调。 |

- 示例：
  ```js
  let authInfo = {
    "authType": 1,
    "token": xxxxxx,
    "extraInfo": {}
  }
  dmInstance.verifyAuthInfo(authInfo, (err, data) => {
    if (err) {
        console.info(TAG + "verifyAuthInfo err:" + JSON.stringify(err));
        return;
    }
    console.info(TAG + "verifyAuthInfo result:" + JSON.stringify(data));
  });
  ```


### on('deviceStateChange')

on(type: 'deviceStateChange',  callback: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

注册设备状态回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 注册设备状态回调，固定为deviceStateChange。 |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChangeAction](#devicestatechangeaction),&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;}&gt; | 是 | 指示要注册的设备状态回调，返回设备状态和设备信息。 |

- 示例：
  ```js
  dmInstance.on('deviceStateChange', (data) => {      
        console.info("deviceStateChange on:" + JSON.stringify(data));
      }
  );
  ```


### off('deviceStateChange')

off(type: 'deviceStateChange', callback?: Callback&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

取消注册设备状态回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 根据应用程序的包名取消注册设备状态回调。 |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChangeAction](#devicestatechangeaction),&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;&nbsp;}&gt; | 是 | 指示要取消注册的设备状态回调，返回设备状态和设备信息。 |

- 示例：
  ```js
  dmInstance.off('deviceStateChange', (data) => {      
        console.info('deviceStateChange' + JSON.stringify(data));
     }
  );
  ```


### on('deviceFound')

on(type: 'deviceFound', callback: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

注册发现设备回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 注册设备发现回调，以便在发现周边设备时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;subscribeId: number, device: DeviceInfo&nbsp;}&gt; | 是 | 注册设备发现的回调方法。 |

- 示例：
  ```js
  dmInstance.on('deviceFound', (data) => {
        console.info("deviceFound:" + JSON.stringify(data));
      }
  );
  ```

### off('deviceFound')

off(type: 'deviceFound', callback?: Callback&lt;{ subscribeId: number, device: DeviceInfo }&gt;): void

取消注册设备发现回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消注册设备发现回调。 |
  | callback | Callback&lt;{&nbsp;subscribeId: number, device: DeviceInfo&nbsp;}&gt; | 是 | 指示要取消注册的设备发现回调，返回设备状态和设备信息。 |

- 示例：
  ```js
  dmInstance.off('deviceFound', (data) => {      
        console.info('deviceFound' + JSON.stringify(data));
      }
  );
  ```

### on('discoverFail')

on(type: 'discoverFail', callback: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

注册设备发现失败回调监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 注册设备发现失败回调，以便在发现周边设备失败时通知应用程序。 |
  | callback | Callback&lt;{&nbsp;subscribeId: number, reason: number&nbsp;}&gt; | 是 | 注册设备发现失败的回调方法。 |

- 示例：
  ```js
  dmInstance.on('discoverFail', (data) => {
        this.log("discoverFail on:" + JSON.stringify(data));
      }
  );
  ```

### off('discoverFail')

off(type: 'discoverFail', callback?: Callback&lt;{ subscribeId: number, reason: number }&gt;): void

取消注册设备发现失败回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消注册设备发现失败回调。 |
  | callback | Callback&lt;{&nbsp;subscribeId: number, reason: number&nbsp;}&gt; | 是 | 指示要取消注册的设备发现失败回调。 |

- 示例：
  ```js
  dmInstance.off('deviceFound', (data) => {      
        console.info('deviceFound' + JSON.stringify(data));
      }
  );
  ```


### on('serviceDie')

on(type: 'serviceDie', callback: () =&gt; void): void

注册设备管理服务死亡监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序。 |
  | callback | ()&nbsp;=&gt;&nbsp;void | 是 | 注册serviceDie的回调方法。 |

- 示例：
  ```js
  dmInstance.on("serviceDie", () => {      
        console.info("serviceDie on");
     }
  );
  ```


### off('serviceDie')

off(type: 'serviceDie', callback?: () =&gt; void): void

取消注册设备管理服务死亡监听。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 取消注册serviceDie回调，以便在devicemanager服务异常终止时通知应用程序。 |
  | callback | ()&nbsp;=&gt;&nbsp;void | 否 | 取消注册serviceDie的回调方法。 |

- 示例：
  ```js
  dmInstance.off("serviceDie", () => {      
        console.info("serviceDie off");
    }
  );
  ```