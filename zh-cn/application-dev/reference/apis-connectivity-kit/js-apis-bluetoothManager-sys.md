# @ohos.bluetoothManager (蓝牙)(系统接口)

蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API Version 10 开始，该接口不再维护，推荐使用[`@ohos.bluetooth.ble`](js-apis-bluetooth-ble.md)等相关profile接口。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetoothManager](js-apis-bluetoothManager.md)。



## 导入模块

```js
import bluetoothManager from '@ohos.bluetoothManager';
```


## bluetoothManager.cancelPairedDevice<sup>(deprecated)</sup><a name="cancelPairedDevice"></a>

cancelPairedDevice(deviceId: string): void

删除配对的远程设备。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[connection.cancelPairedDevice](js-apis-bluetooth-connection-sys.md#connectioncancelpaireddevice)替代。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                    |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | 是    | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    bluetoothManager.cancelPairedDevice("XX:XX:XX:XX:XX:XX");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### connect<sup>(deprecated)</sup><a name="HidHost-connect"></a>

connect(device: string): void

连接设备的HidHost服务。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[hid.HidHostProfile#connect](js-apis-bluetooth-hid-sys.md#connect)替代。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let hidHostProfile: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST) as bluetoothManager.HidHostProfile;
    hidHostProfile.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### disconnect<sup>(deprecated)</sup><a name="HidHost-disconnect"></a>

disconnect(device: string): void

断开连接设备的HidHost服务。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[hid.HidHostProfile#disconnect](js-apis-bluetooth-hid-sys.md#disconnect)替代。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let hidHostProfile: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST) as bluetoothManager.HidHostProfile;
    hidHostProfile.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```



### disconnect<sup>(deprecated)</sup><a name="PanP-disconnect"></a>

disconnect(device: string): void

断开连接设备的Pan服务。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[pan.PanProfile#disconnect](js-apis-bluetooth-pan-sys.md#disconnect)替代。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;
    panProfile.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```

### setTethering<sup>(deprecated)</sup><a name="setTethering"></a>

setTethering(enable: boolean): void

设置网络共享状态。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，替代接口仅向系统应用开放。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| enable | boolean | 是    | 是否启用网络共享。true表示启用，false表示不启用。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;
    panProfile.setTethering(true);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### isTetheringOn<sup>(deprecated)</sup><a name="isTetheringOn"></a>

isTetheringOn(): boolean

获取网络共享状态。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[isTetheringOn](js-apis-bluetooth-pan-sys.md#istetheringon)替代。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型      | 说明                  |
| --------------------- | --------------------------------- |
| boolean | 网络共享开启返回true，网络共享关闭返回false。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;
    panProfile.isTetheringOn();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```