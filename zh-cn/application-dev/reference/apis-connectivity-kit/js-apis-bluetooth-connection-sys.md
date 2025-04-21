# @ohos.bluetooth.connection (蓝牙connection模块)(系统接口)

connection模块提供了对蓝牙操作和管理的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.bluetooth.connection (蓝牙connection模块)](js-apis-bluetooth-connection.md)


## 导入模块

```js
import { connection } from '@kit.ConnectivityKit';
```


## connection.pairCredibleDevice

pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback&lt;void&gt;): void

向可信的远端设备发起蓝牙配对。通过非蓝牙扫描的方式(例如NFC等)获取到外设的地址，可以通过该接口发起配对。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| transport | [BluetoothTransport](js-apis-bluetooth-connection.md#bluetoothtransport) | 是    | 表示设备类型，例如传统蓝牙设备或低功耗蓝牙设备。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数。当发起配对成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.pairCredibleDevice('68:13:24:79:4C:8C', connection.BluetoothTransport
        .TRANSPORT_BR_EDR, (err: BusinessError) => {
        if (err) {
            console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
            return;
        }
        console.info('pairCredibleDevice, err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.pairCredibleDevice

pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise&lt;void&gt;

向可信的远端设备发起蓝牙配对。通过非蓝牙扫描的方式(例如NFC等)获取到外设的地址，可以通过该接口发起配对。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| transport | [BluetoothTransport](js-apis-bluetooth-connection.md#bluetoothtransport) | 是    | 表示设备类型，例如传统蓝牙设备或低功耗蓝牙设备。 |

**返回值：**

| 类型                                              | 说明                |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.pairCredibleDevice('68:13:24:79:4C:8C', 0).then(() => {
        console.info('PairCredibleDevice');
    }, (err: BusinessError) => {
        console.error('PairCredibleDevice:errCode' + err.code + ', errMessage: ' + err.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.cancelPairedDevice

cancelPairedDevice(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

删除配对的远程设备。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                    |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | 是    | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数。当删除远程配对设备成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// callback
try {
    connection.cancelPairedDevice('11:22:33:44:55:66', (err: BusinessError) => {
        console.info('cancelPairedDevice, device name err:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.cancelPairedDevice

cancelPairedDevice(deviceId: string): Promise&lt;void&gt;

删除配对的远程设备。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                    |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | 是    | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.cancelPairedDevice('11:22:33:44:55:66').then(() => {
        console.info('cancelPairedDevice');
    }, (error: BusinessError) => {
        console.info('cancelPairedDevice: errCode:' + error.code + ',errMessage' + error.message);
    })

} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.cancelPairingDevice

cancelPairingDevice(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

删除正在配对中的远程设备。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                    |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | 是    | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数。当删除远程配对设备成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.cancelPairingDevice('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.cancelPairingDevice

cancelPairingDevice(deviceId: string): Promise&lt;void&gt;

删除正在配对中的远程设备。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                    |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | 是    | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.cancelPairingDevice('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getLocalProfileUuids

getLocalProfileUuids(callback: AsyncCallback&lt;Array&lt;ProfileUuids&gt;&gt;): void

获取本地设备的profile UUID。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids)&gt;&gt; | 是    | 回调函数。当获取UUID成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.getLocalProfileUuids((err: BusinessError, data: Array<connection.ProfileUuids>) => {
        console.info('getLocalProfileUuids, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getLocalProfileUuids

getLocalProfileUuids(): Promise&lt;Array&lt;ProfileUuids&gt;&gt;

获取本地设备的profile UUID。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
|   Promise&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids)&gt;&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.           |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.getLocalProfileUuids().then(() => {
        console.info('getLocalProfileUuids');
    }, (err: BusinessError) => {
        console.error('getLocalProfileUuids: errCode' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.disconnectAllowedProfiles<sup>11+</sup>

disconnectAllowedProfiles(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

断开远端设备所有连接的profiles。使用Callback异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示断开的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;void&gt; | 是    | 以callback形式异步返回结果。当发起断开成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|202     | Non-system applications are not allowed to use system APIs.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.disconnectAllowedProfiles('68:13:24:79:4C:8C', (err: BusinessError) => {
        if (err) {
            console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
            return;
        }
        console.info('disconnectAllowedProfiles, err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.disconnectAllowedProfiles<sup>11+</sup>

disconnectAllowedProfiles(deviceId: string): Promise&lt;void&gt;

断开远端设备所有连接的profiles。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示断开的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                                              | 说明                |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | 以Promise形式返回断开profiles的结果，返回true为成功，false为失败。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|202     | Non-system applications are not allowed to use system APIs.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.disconnectAllowedProfiles('68:13:24:79:4C:8C').then(() => {
        console.info('disconnectAllowedProfiles');
    }, (err: BusinessError) => {
        console.error('disconnectAllowedProfiles:errCode' + err.code + ', errMessage: ' + err.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteProductId<sup>11+</sup>

getRemoteProductId(deviceId: string): string

获取对端蓝牙设备的Product ID。从API16开始不再校验ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH权限。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 以字符串格式返回设备Product ID。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
try {
  let remoteDeviceProductId = connection.getRemoteProductId('XX:XX:XX:XX:XX:XX');
} catch (err) {
  console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## connection.setRemoteDeviceType<sup>12+</sup>

setRemoteDeviceType(deviceId: string, type: DeviceType): Promise&lt;void&gt;

设置蓝牙远端设备自定义类型。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |
| type   | [DeviceType](#devicetype12)  | 是    | 表示设备类型。        |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 以Promise形式返回设置蓝牙远端设备类型的结果，设置失败时返回错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.setRemoteDeviceType('11:22:33:44:55:66', connection.DeviceType.DEVICE_TYPE_HEADSET).then(() => {
        console.info('setRemoteDeviceType success');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceType<sup>12+</sup>

getRemoteDeviceType(deviceId: string): Promise&lt;DeviceType&gt;

获取蓝牙远端设备自定义类型。使用Promise异步回调。从API18开始不再校验ohos.permission.ACCESS_BLUETOOTH权限。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ------------- |
| Promise&lt;[DeviceType](#devicetype12)&gt; | 以Promise形式返回设置蓝牙远端设备类型的结果，返回值为设备类型。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.getRemoteDeviceType('11:22:33:44:55:66').then((data: connection.DeviceType) => {
        console.info('getRemoteDeviceType success, DeviceType:' + JSON.stringify(data));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.controlDeviceAction<sup>15+</sup>

controlDeviceAction(controlDeviceActionParams: ControlDeviceActionParams): Promise&lt;void&gt;

查找蓝牙耳机设备时，向耳机发送控制命令。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH（该权限仅系统应用可申请）。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| controlDeviceActionParams<sup>15+</sup> | [ControlDeviceActionParams](#controldeviceactionparams15) | 是    | 控制蓝牙外设的相关信息。 |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let controlDeviceActionParams: connection.ControlDeviceActionParams = {
        deviceId: '40:DC:A5:E5:75:C3',
        type: connection.ControlType.PLAY,
        typeValue: connection.ControlTypeValue.ENABLE,
        controlObject: connection.ControlObject.LEFT_EAR
    };
    connection.controlDeviceAction(controlDeviceActionParams).then(() => {
        console.info('controlDeviceAction success');
    }, (err: BusinessError) => {
        console.error('controlDeviceAction: errCode' + err.code + ', errMessage: ' + err.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.updateCloudBluetoothDevice<sup>15+</sup>

updateCloudBluetoothDevice(trustedPairedDevices: TrustedPairedDevices): Promise&lt;void&gt;

更新云设备到蓝牙设置。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| trustedPairedDevices   | [TrustedPairedDevices](#trustedpaireddevices15)  | 是    | 表示云设备列表。  |  

**返回值：**

| 类型                  | 说明         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 以Promise形式返回设置云设备的结果。设置失败时返回错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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
import { connection } from '@kit.ConnectivityKit';
// promise
/**
 * 更新云设备到蓝牙设置项。
 */
public updateCloudBluetoothDevice() {
    const trustPairDeviceArr: connection.TrustedPairedDevice[] = [];
    let descBuffer = new ArrayBuffer(1);
    trustPairDeviceArr.push({
        sn: '',
        deviceType: '',
        modelId: '',
        manufactory: '',
        productId: '',
        hiLinkVersion: '',
        macAddress: '11:22:33:44:55:66',
        serviceType: '',
        serviceId: '',
        deviceName: '',
        uuids: '',
        bluetoothClass: 0,
        token: descBuffer,
        deviceNameTime: 0,
        secureAdvertisingInfo: descBuffer,
        pairState: 0
        });
    const trustPairDevices: connection.TrustedPairedDevices = { trustedPairedDevices: trustPairDeviceArr };
    try {
        connection.updateCloudBluetoothDevice(trustPairDevices)
            .then(() => {
                console.info('updateCloudBluetoothDevice success!');
            })
            .catch((err: BusinessError) => {
                console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
            });
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
```


## PinRequiredParam

描述配对请求参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| pinType | [PinType](#pintype) | 是    | 否    | 表示要配对的设备类型。<br/>此接口为系统接口。   |

## ControlDeviceActionParams<sup>15+</sup>

控制命令的配置参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | 是    | 否 | 表示要配对的设备ID。 |
| type | [ControlType](#controltype15) | 是    | 否    | 表示控制类型。 |
| typeValue | [ControlTypeValue](#controltypevalue15) | 是 | 否 | 表示控制动作。 |
| controlObject | [ControlObject](#controlobject15) | 是 | 否 | 表示控制对象。|

## PinType

枚举，蓝牙配对类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                               | 值    | 说明              |
| -------------------------------- | ------ | --------------- |
| PIN_TYPE_ENTER_PIN_CODE | 0 | 用户需要输入对端设备上显示的PIN码。<br/>此接口为系统接口。 |
| PIN_TYPE_ENTER_PASSKEY  | 1 | 用户需要输入对端设备上显示的PASSKEY。<br/>此接口为系统接口。  |
| PIN_TYPE_CONFIRM_PASSKEY  | 2 | 用户需要确认本地设备上显示的PASSKEY。<br/>此接口为系统接口。  |
| PIN_TYPE_NO_PASSKEY_CONSENT  | 3 | 无PASSKEY，用户需要接受或拒绝配对请求。<br/>此接口为系统接口。  |
| PIN_TYPE_NOTIFY_PASSKEY   | 4 | 本地设备显示PASSKEY，用户需要在对端设备上输入该PASSKEY。<br/>此接口为系统接口。  |
| PIN_TYPE_DISPLAY_PIN_CODE    | 5 | bluetooth 2.0设备，用户需要输入对端设备上显示的PIN码。<br/>此接口为系统接口。  |
| PIN_TYPE_OOB_CONSENT    | 6 | 用户需要接受或拒绝OOB配对请求。<br/>此接口为系统接口。  |
| PIN_TYPE_PIN_16_DIGITS    | 7 | 用户需要输入对端设备上显示的16位PIN码。<br/>此接口为系统接口。  |



## DeviceType<sup>12+</sup>

枚举，蓝牙远程设备的自定义类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                               | 值    | 说明              |
| -------------------------------- | ------ | --------------- |
| DEVICE_TYPE_DEFAULT<sup>12+</sup> | 0 | 默认设备类型，与原类型一致。<br/>此接口为系统接口。 |
| DEVICE_TYPE_CAR<sup>12+</sup>  | 1 | 汽车。<br/>此接口为系统接口。  |
| DEVICE_TYPE_HEADSET<sup>12+</sup>  | 2 | 耳机。<br/>此接口为系统接口。  |
| DEVICE_TYPE_HEARING<sup>12+</sup>   | 3 | 助听器<br/>此接口为系统接口。  |
| DEVICE_TYPE_GLASSES<sup>12+</sup>    | 4 | 眼镜。<br/>此接口为系统接口。  |
| DEVICE_TYPE_WATCH<sup>12+</sup>     | 5 | 手表。<br/>此接口为系统接口。  |
| DEVICE_TYPE_SPEAKER<sup>12+</sup>     | 6 | 音响。<br/>此接口为系统接口。  |
| DEVICE_TYPE_OTHERS<sup>12+</sup>     | 7 | 其他设备。<br/>此接口为系统接口。  |


## BatteryInfo<sup>12+</sup>

描述电量信息的内容。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | 是    | 否    | 表示远端设备的MAC地址。<br/>此接口为系统接口。 |


## ControlType<sup>15+</sup>

枚举，控制类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                               | 值    | 说明              |
| -------------------------------- | ------ | --------------- |
| PLAY | 0 | 表示控制类型为播放。 |
| VIBRATE | 1 | 表示控制类型为振动。 |
| FLASH | 2 | 表示控制类型为闪光。 |
| LOCK | 3 | 表示控制类型为锁定。 |


## ControlTypeValue<sup>15+</sup>

枚举，控制动作。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称    | 值   | 说明       |
| ------- | ---- | ---------- |
| DISABLE | 0    | 表示禁用。 |
| ENABLE  | 1    | 表示使能。 |
| QUERY   | 2    | 表示查询。 |


## ControlObject<sup>15+</sup>

枚举，控制对象。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称           | 值   | 说明                 |
| -------------- | ---- | -------------------- |
| LEFT_EAR       | 0    | 表示控制对象是左耳。 |
| RIGHT_EAR      | 1    | 表示控制对象是右耳。 |
| LEFT_RIGHT_EAR | 2    | 表示控制对象是双耳。 |


## TrustedPairedDevices<sup>15+</sup>

云设备列表。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| trustedPairedDevices  | Array&lt;[TrustedPairedDevice](#trustedpaireddevice15)&gt; | 是    | 否    | 表示云设备列表。   |

## TrustedPairedDevice<sup>15+</sup>

云设备信息。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称       | 类型   | 可读   | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| sn  | string | 是    | 否    | 表示设备的序列号。   |
| deviceType  | string | 是    | 否    | 表示设备类型。   |
| modelId  | string | 是    | 否    | 表示左侧耳机的充电状态。   |
| manufactory  | string | 是    | 否    | 表示制造商信息。   |
| productId  | string | 是    | 否    | 表示设备产品信息。   |
| hiLinkVersion  | string | 是    | 否    | 表示hilink版本信息。   |
| macAddress  | string | 是    | 否    | 表示设备MAC地址。   |
| serviceType  | string | 是    | 否    | 表示设备服务类型。   |
| serviceId  | string | 是    | 否    | 表示设备id。   |
| deviceName  | string | 是    | 否    | 表示设备名字。   |
| uuids  | string | 是    | 否    | 表示设备的UUID。   |
| bluetoothClass  | number | 是    | 否    | 表示远端设备类型。   |
| token  | ArrayBuffer | 是    | 否    | 表示设备的token信息。   |
| deviceNameTime  | number | 是    | 否    | 表示设备名字的修改时间。   |
| secureAdvertisingInfo  | ArrayBuffer | 是    | 否    | 表示设备广播信息。   |
| pairState  | number | 是    | 否    | 表示设备配对状态。   |
