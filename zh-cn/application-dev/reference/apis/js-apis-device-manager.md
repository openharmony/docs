# 设备管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


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


## DeviceStateChangeAction

表示设备状态变化的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| ONLINE | 0 | 设备上线。 |
| READY | 1 | 设备就绪，设备信息同步已完成。 |
| OFFLINE | 2 | 设备下线。 |
| CHANGE | 3 | 设备信息更改。 |


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



## DeviceInfo

设备信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.DistributedHardware.DeviceManager

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| deviceId | number | 是 | 设备的唯一标识。 |
| deviceName | string | 是 | 设备名称。 |
| deviceType | number | 是 | 设备类型。 |


## DeviceManager

设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。


### release

release(): void

设备管理实例不再使用后，通过该方法释放DeviceManager实例。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 示例：
  ```
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
  ```
  var deviceInfoList = dmInstance.getTrustedDeviceListSync();
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
  ```
  dmInstance.on('deviceStateChange', (data) => {      
        console.info("deviceStateChange on:" + JSON.stringify(data));
      }
  );
  ```


### off('deviceStateChange')

off(type: 'deviceStateChange', callback?: Call	back&lt;{ action: DeviceStateChangeAction, device: DeviceInfo }&gt;): void

取消注册设备状态回调。

**系统能力**：SystemCapability.DistributedHardware.DeviceManager

- 参数：
  | 名称 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 根据应用程序的包名取消注册设备状态回调。 |
  | callback | Callback&lt;{&nbsp;action:&nbsp;[DeviceStateChangeAction](#devicestatechangeaction),&nbsp;device:&nbsp;[DeviceInfo](#deviceinfo)&nbsp;&nbsp;}&gt; | 是 | 指示要取消注册的设备状态回调，返回设备状态和设备信息。 |

- 示例：
  ```
  dmInstance.off('deviceStateChange', (data) => {      
        console.info('deviceStateChange' + JSON.stringify(data));
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
  ```
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
  ```
  dmInstance.off("serviceDie", () => {      
        console.info("serviceDie off");
    }
  );
  ```
