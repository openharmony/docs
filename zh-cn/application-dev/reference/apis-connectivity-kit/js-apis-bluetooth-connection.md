# @ohos.bluetooth.connection (蓝牙connection模块)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

connection模块提供了蓝牙设备的配对、连接及状态查询等能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import { connection } from '@kit.ConnectivityKit';
```


## ProfileConnectionState

type ProfileConnectionState = constant.ProfileConnectionState

蓝牙设备的Profile协议连接状态。Profile协议包括A2DP（Advanced Audio Distribution Profile）、HFP（Hands-Free Profile）和HID（Human Interface Device）等。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | 蓝牙设备的Profile协议连接状态。 |


## ProfileId

type ProfileId = constant.ProfileId

枚举，蓝牙Profile协议。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.ProfileId](js-apis-bluetooth-constant.md#profileid) | 蓝牙Profile协议的枚举。 |


## ProfileUuids<sup>12+</sup>

type ProfileUuids = constant.ProfileUuids

蓝牙Profile协议的UUID。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.ProfileUuids](js-apis-bluetooth-constant.md#profileuuids12) | 蓝牙Profile协议的UUID。 |


## MajorClass

type MajorClass = constant.MajorClass

蓝牙设备的主要类型。蓝牙标准协议字段。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.MajorClass](js-apis-bluetooth-constant.md#majorclass) | 蓝牙设备的主要类型。 |


## MajorMinorClass

type MajorMinorClass = constant.MajorMinorClass

蓝牙设备的子类型，在[MajorClass](js-apis-bluetooth-constant.md#majorclass)基础上进一步细分的类型。蓝牙标准协议字段。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.MajorMinorClass](js-apis-bluetooth-constant.md#majorminorclass) | 蓝牙设备的子类型。 |


## BluetoothAddress<sup>21+</sup>

type BluetoothAddress = common.BluetoothAddress

描述蓝牙设备地址信息的参数结构，包括地址与地址类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [common.BluetoothAddress](js-apis-bluetooth-common.md#bluetoothaddress) | 蓝牙设备的地址信息。 |


## connection.pairDevice

pairDevice(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

主动发起与对端蓝牙设备的配对流程。使用Callback异步回调。
- 若开发者不知道目标设备的[地址类型](js-apis-bluetooth-common.md#bluetoothaddresstype)，建议调用此接口发起配对。
- 蓝牙配对状态通过[on('bondStateChange')](#connectiononbondstatechange)的回调结果获取。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 需要配对的对端蓝牙设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;void&gt;  | 是    | 回调函数。当配对成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// callback
try {
    connection.pairDevice('11:22:33:44:55:66', (err: BusinessError) => {
        console.info('pairDevice, device name err:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


## connection.pairDevice

pairDevice(deviceId: string): Promise&lt;void&gt;

主动发起与对端蓝牙设备的配对流程。使用Promise异步回调。
- 若开发者不知道目标设备的[地址类型](js-apis-bluetooth-common.md#bluetoothaddresstype)，建议调用此接口发起配对。
- 蓝牙配对状态通过[on('bondStateChange')](#connectiononbondstatechange)的回调结果获取。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 需要配对的对端蓝牙设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.pairDevice('11:22:33:44:55:66').then(() => {
        console.info('pairDevice');
    }, (error: BusinessError) => {
        console.error('pairDevice: errCode:' + error.code + ',errMessage' + error.message);
    })

} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.pairDevice<sup>21+</sup>

pairDevice(deviceId: BluetoothAddress): Promise&lt;void&gt;

主动发起与对端蓝牙设备的配对流程。使用Promise异步回调。
- 若开发者已知目标设备的MAC地址及[地址类型](js-apis-bluetooth-common.md#bluetoothaddresstype)，建议调用此接口发起配对。
- 蓝牙配对状态通过[on('bondStateChange')](#connectiononbondstatechange)的回调结果获取。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | [BluetoothAddress](js-apis-bluetooth-common.md#bluetoothaddress) | 是    | 需要配对的对端蓝牙设备地址信息，包括地址与地址类型。 |

**返回值**：

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.ConnectivityKit';
// promise
try {
    let btAddr: common.BluetoothAddress = {
        "address": '11:22:33:44:55:66', // 目标设备的实际MAC地址或虚拟MAC地址
        "addressType": common.BluetoothAddressType.REAL, // 相应的地址类型
    }
    connection.pairDevice(btAddr).then(() => {
        console.info('pairDevice');
    }, (error: BusinessError) => {
        console.error('errCode: ' + error.code + ', errMessage' + error.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceName

getRemoteDeviceName(deviceId: string): string

获取对端蓝牙设备的名称。

- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取设备名称。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示对端设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型     | 说明            |
| ------ | ------------- |
| string | 以字符串格式返回设备名称。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let remoteDeviceName: string = connection.getRemoteDeviceName('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceName<sup>16+</sup>

getRemoteDeviceName(deviceId: string, alias?: boolean): string

获取对端蓝牙设备的名称，其中alias为可选参数。

- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取设备名称。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示对端设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |
| alias | boolean | 否    | 表示是否获取对端蓝牙设备别名。<br>- 如果携带alias，则根据alias判断是否获取对端蓝牙设备别名：true表示获取对端蓝牙设备别名，false表示获取对端蓝牙设备原始名称。<br>- 如果未携带alias，则默认值为true，返回对端蓝牙设备别名。 |

**返回值**：

| 类型     | 说明            |
| ------ | ------------- |
| string | 以字符串格式返回设备名称。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Failed to obtain the name or alias of the peer Bluetooth device.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let remoteDeviceName: string = connection.getRemoteDeviceName('XX:XX:XX:XX:XX:XX', true);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceClass

getRemoteDeviceClass(deviceId: string): DeviceClass

获取对端蓝牙设备的类别。

- 从API version 18开始，此接口不再校验ohos.permission.ACCESS_BLUETOOTH权限。
- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取设备类别信息。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示对端设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型                          | 说明       |
| --------------------------- | -------- |
| [DeviceClass](#deviceclass) | 对端设备的类别。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 |Permission denied.<br>适用版本：10-17 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let remoteDeviceClass: connection.DeviceClass = connection.getRemoteDeviceClass('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## connection.getRemoteDeviceTransport<sup>20+</sup>

getRemoteDeviceTransport(deviceId: string): BluetoothTransport

获取对端蓝牙设备的传输类型。

- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取设备的传输类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示对端设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型                          | 说明       |
| --------------------------- | -------- |
| [BluetoothTransport](#bluetoothtransport) | 对端设备的传输类型。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Get transport failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let transport: connection.BluetoothTransport = connection.getRemoteDeviceTransport('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## connection.getRemoteProfileUuids<sup>12+</sup>

getRemoteProfileUuids(deviceId: string, callback: AsyncCallback&lt;Array&lt;ProfileUuids&gt;&gt;): void

获取对端蓝牙设备的Profile协议能力，通过UUID区分。使用Callback异步回调。
- 建议仅对已配对的设备调用该方法。
- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取Profile协议能力。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids12)&gt;&gt; | 是    | 回调函数。当获取UUID成功，err为undefined，获取到的是Profile协议能力集合；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter.    |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    connection.getRemoteProfileUuids('XX:XX:XX:XX:XX:XX', (err: BusinessError, data: Array<connection.ProfileUuids>) => {
        console.info('getRemoteProfileUuids, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


## connection.getRemoteProfileUuids<sup>12+</sup>

getRemoteProfileUuids(deviceId: string): Promise&lt;Array&lt;ProfileUuids&gt;&gt;

获取对端蓝牙设备的Profile协议能力，通过UUID区分。使用Promise异步回调。
- 建议仅对已配对的设备调用该方法。
- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取Profile协议能力。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型                  | 说明            |
| ------------------- | ------------- |
|   Promise&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids12)&gt;&gt; | Promise对象，返回支持的Profile协议能力集合。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter.    |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    connection.getRemoteProfileUuids('XX:XX:XX:XX:XX:XX').then(() => {
        console.info('getRemoteProfileUuids');
    }, (err: BusinessError) => {
        console.error('getRemoteProfileUuids: errCode' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getLocalName

getLocalName(): string

获取本机蓝牙设备的名称。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型     | 说明        |
| ------ | --------- |
| string | 本机蓝牙设备名称。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let localName: string = connection.getLocalName();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getPairedDevices

getPairedDevices(): Array&lt;string&gt;

获取已配对蓝牙设备的地址集合。

**需要权限**：
- API版本26.0.0+：ohos.permission.ACCESS_BLUETOOTH 或 (ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_PEERS_MAC)
- API版本10-24：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型                  | 说明            |
| ------------------- | ------------- |
| Array&lt;string&gt; | 已配对蓝牙设备的地址集合。<br>基于信息安全考虑，此处获取的设备地址为虚拟MAC地址。<br>- 已配对的地址不会变更。<br>- 若该设备重启蓝牙开关，重新获取到的虚拟地址会立即变更。<br>- 若取消配对，蓝牙子系统会根据该地址的实际使用情况，决策后续变更时机；若其他应用正在使用该地址，则不会立刻变更。<br>- 若要持久化保存该地址，可使用[access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16)方法。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let devices: Array<string> = connection.getPairedDevices();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getPairState<sup>11+</sup>

getPairState(deviceId: string): BondState

获取对端蓝牙设备的配对状态信息。

- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取配对状态信息。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示对端设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型                          | 说明       |
| --------------------------- | -------- |
| [BondState](#bondstate) | 表示设备的蓝牙配对状态。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let res: connection.BondState = connection.getPairState("XX:XX:XX:XX:XX:XX");
    console.info('getPairState: ' + res);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getProfileConnectionState

getProfileConnectionState(profileId?: ProfileId): ProfileConnectionState

获取蓝牙Profile协议的连接状态，其中ProfileId为可选参数。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

<!--Table: 10%; 10%; 10%; 70%-->
| 参数名       | 类型        | 必填   | 说明                                    |
| --------- | --------- | ---- | ------------------------------------- |
| profileId | [ProfileId](js-apis-bluetooth-constant.md#profileid) | 否    | 表示Profile协议的枚举值。如果携带ProfileId，则返回指定Profile协议的连接状态。如果未携带ProfileId，则检查所有支持的Profile连接状态，按如下优先级顺序检查并返回：<br>- 存在已连接的Profile协议，则返回[STATE_CONNECTED](js-apis-bluetooth-constant.md#profileconnectionstate)。<br>- 存在正在连接的Profile协议，则返回[STATE_CONNECTING](js-apis-bluetooth-constant.md#profileconnectionstate)。<br>- 存在正在断连的Profile协议，则返回[STATE_DISCONNECTING](js-apis-bluetooth-constant.md#profileconnectionstate)。<br>- 以上条件均不满足，则返回[STATE_DISCONNECTED](js-apis-bluetooth-constant.md#profileconnectionstate)。 |

**返回值**：

| 类型                                              | 说明                |
| ------------------------------------------------- | ------------------- |
| [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | Profile协议的连接状态。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Incorrect parameter types.        |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { constant } from '@kit.ConnectivityKit';
try {
    let result: connection.ProfileConnectionState = connection.getProfileConnectionState(constant.ProfileId.PROFILE_A2DP_SOURCE);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setDevicePairingConfirmation

setDevicePairingConfirmation(deviceId: string, accept: boolean): void

收到对端蓝牙设备的配对请求事件后，确认请求结果。
- 对端蓝牙的配对请求通过[on('pinRequired')](#connectiononpinrequired)的回调结果获取。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH（该权限仅系统应用可申请）

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名    | 类型      | 必填   | 说明                               |
| ------   | ------- | ---- | -------------------------------- |
| deviceId | string | 是 | 表示对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| accept   | boolean | 是    | 是否接受对端设备的配对请求。true表示接受，false表示不接受。       |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// 订阅“pinRequired”配对请求事件，收到对端配对请求后设置配对确认。
function onReceivePinRequiredEvent(data: connection.PinRequiredParam) { // data为配对请求的入参，配对请求参数。
    console.info('pin required  = '+ JSON.stringify(data));
    connection.setDevicePairingConfirmation(data.deviceId, true);
}
try {
    connection.on('pinRequired', onReceivePinRequiredEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setDevicePinCode

setDevicePinCode(deviceId: string, code: string, callback: AsyncCallback&lt;void&gt;): void

蓝牙配对时，弹框提示用户输入个人身份识别码（Personal identification number，PIN），调用此接口设置PIN码，完成蓝牙配对。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示对端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |
| code   | string  | 是    | 用户输入的PIN码，该字符串的字符个数范围为(0, 16]，例如："12345"。        |
| callback   | AsyncCallback&lt;void&gt;  | 是    | 回调函数，当设置PinCode成功，err为undefined，否则为错误对象。        |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// callback
try {
    connection.setDevicePinCode('11:22:33:44:55:66', '12345', (err: BusinessError) => {
        console.info('setDevicePinCode,device name err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setDevicePinCode

setDevicePinCode(deviceId: string, code: string): Promise&lt;void&gt;

蓝牙配对时，弹框提示用户输入PIN码，调用此接口请求用户输入PIN码，完成蓝牙配对。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示对端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |
| code   | string  | 是    | 用户输入的PIN码，该字符串的字符个数范围为(0, 16]，例如："12345"。        |

**返回值**：

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.setDevicePinCode('11:22:33:44:55:66', '12345').then(() => {
        console.info('setDevicePinCode');
    }, (error: BusinessError) => {
        console.error('setDevicePinCode: errCode:' + error.code + ',errMessage' + error.message);
    })

} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setLocalName<sup>(deprecated)</sup>

setLocalName(name: string): void

设置本机蓝牙设备名称，不能设置为空字符串。如果设为空字符串会失败。

> **说明**：<br/>
> 从API version 10开始支持，从API version 12开始废弃，不再提供替代接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名  | 类型     | 必填   | 说明                    |
| ---- | ------ | ---- | --------------------- |
| name | string | 是    | 需要设置的蓝牙名称，名称长度范围：(0, 248]，单位：Byte。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    connection.setLocalName('device_name');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setBluetoothScanMode

setBluetoothScanMode(mode: ScanMode, duration: number): void

设置蓝牙扫描模式，决定本机设备是否可被连接，或者可被发现。搭配[onScanModeChange](#connectiononscanmodechange23)接口使用，可实时监听蓝牙扫描模式变更事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                    | 必填   | 说明                           |
| -------- | --------------------- | ---- | ---------------------------- |
| mode     | [ScanMode](#scanmode) | 是    | 蓝牙扫描模式。当扫描模式为SCAN_MODE_GENERAL_DISCOVERABLE时，超出duration持续时间(不为0)，扫描模式会重新设置为SCAN_MODE_CONNECTABLE。               |
| duration | number                | 是    | 设备可被发现的持续时间，单位：ms。设置为0则表示持续可发现。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    // 设置为可连接可发现才可被对端设备扫描到，可以连接。
    connection.setBluetoothScanMode(connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getBluetoothScanMode

getBluetoothScanMode(): ScanMode

获取蓝牙扫描模式。搭配[onScanModeChange](#connectiononscanmodechange23)接口使用，可实时监听蓝牙扫描模式变更事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型                    | 说明      |
| --------------------- | ------- |
| [ScanMode](#scanmode) | 蓝牙扫描模式。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let scanMode: connection.ScanMode = connection.getBluetoothScanMode();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.startBluetoothDiscovery

startBluetoothDiscovery(): void

开启蓝牙扫描，发现对端蓝牙设备。<br>
- 该接口支持发现传统蓝牙设备和低功耗蓝牙设备，整个蓝牙扫描过程大约持续12s。<br>
- 扫描结果可通过API version 10开始支持的[connection.on('bluetoothDeviceFind')](#connectiononbluetoothdevicefind)或者API version 18开始支持的[connection.on('discoveryResult')](#connectionondiscoveryresult18)的回调函数获取到。推荐使用[connection.on('discoveryResult')](#connectionondiscoveryresult18)，该方式可以获取到更多设备信息。<br>
- 若在扫描过程中，请勿重复调用该方法（可使用[connection.isBluetoothDiscovering](#connectionisbluetoothdiscovering11)判断蓝牙当前是否处于扫描过程中）。<br>
- 调用[connection.stopBluetoothDiscovery](#connectionstopbluetoothdiscovery)可以停止该方法开启的扫描流程，扫描停止后，才能开启下一次蓝牙扫描。<br>

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<string>) {
    console.info('data length' + data.length);
}
try {
    connection.on('bluetoothDeviceFind', onReceiveEvent);
    connection.startBluetoothDiscovery();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.stopBluetoothDiscovery

stopBluetoothDiscovery(): void

关闭蓝牙扫描。<br>
- 关闭的扫描是由[connection.startBluetoothDiscovery](#connectionstartbluetoothdiscovery)触发的。<br>
- 当应用不再需要扫描设备时，需主动调用该方法关闭扫描。<br>
- 若不在扫描过程中，请勿重复调用该方法（可使用[connection.isBluetoothDiscovering](#connectionisbluetoothdiscovering11)判断蓝牙当前是否处于扫描过程中）。<br>

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    connection.stopBluetoothDiscovery();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.isBluetoothDiscovering<sup>11+</sup>

isBluetoothDiscovering(): boolean

判断本机蓝牙设备是否处于设备扫描状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**返回值**：

| 类型                  | 说明            |
| ------------------- | ------------- |
|   boolean           | 是否开启蓝牙发现。true表示正在发起设备扫描，false表示未发起设备扫描。  |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let res: boolean = connection.isBluetoothDiscovering();
    console.info('isBluetoothDiscovering: ' + res);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## connection.setRemoteDeviceName<sup>12+</sup>

setRemoteDeviceName(deviceId: string, name: string): Promise&lt;void&gt;

设置对端蓝牙设备的名称，不能设置为空字符串。如果设为空字符串会失败。使用Promise异步回调。
- 建议仅对已配对的设备调用该方法。
- 从API version 21开始，此接口支持使用对端设备的实际MAC地址进行名称设置。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| deviceId     | string                              | 是    | 表示对端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |
| name | string | 是    | 修改对端设备名称，名称长度范围：(0, 64]，单位：Byte。    |

**返回值**：

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.            |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.setRemoteDeviceName('11:22:33:44:55:66', 'RemoteDeviceName').then(() => {
        console.info('setRemoteDeviceName success');
    }, (error: BusinessError) => {
        console.error('setRemoteDeviceName: errCode: ' + error.code + ',errMessage' + error.message);
    })
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceBatteryInfo<sup>12+</sup>

getRemoteDeviceBatteryInfo(deviceId: string): Promise&lt;BatteryInfo&gt;

获取对端蓝牙设备的电量信息。使用Promise异步回调。
- 对端蓝牙设备的电量信息变更通过[on('batteryChange')](#connectiononbatterychange12)的回调结果获取。
- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取电量信息。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示对端蓝牙设备的MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型                  | 说明         |
| ------------------- | ------------- |
| Promise&lt;[BatteryInfo](#batteryinfo12)&gt; | Promise对象，返回电量信息对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.            |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.getRemoteDeviceBatteryInfo('11:22:33:AA:BB:FF').then((data: connection.BatteryInfo) => {
        console.info('getRemoteDeviceBatteryInfo success, DeviceType:' + JSON.stringify(data));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.on('batteryChange')<sup>12+</sup>

on(type: 'batteryChange', callback: Callback&lt;BatteryInfo&gt;): void

订阅对端设备的电量信息变化事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | 是    | 事件回调类型，支持的事件为'batteryChange'，表示对端设备的电量信息变化事件。当该设备通知电量变化时，会触发该事件。 |
| callback | Callback&lt;[BatteryInfo](#batteryinfo12)&gt; | 是    | 指定订阅的回调函数，返回电量信息。    |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
let onReceiveEvent: (data: connection.BatteryInfo) => void = (data: connection.BatteryInfo) => {
    console.info('BatteryInfo = '+ JSON.stringify(data));
}
try {
    connection.on('batteryChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.off('batteryChange')<sup>12+</sup>

off(type: 'batteryChange', callback?: Callback&lt;BatteryInfo&gt;): void

取消订阅对端设备的电量信息变化事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | 是    | 事件回调类型，支持的事件为'batteryChange'，表示对端设备的电量信息变化事件。   |
| callback | Callback&lt;[BatteryInfo](#batteryinfo12)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[connection.on('batteryChange')](#connectiononbatterychange12)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
let onReceiveEvent: (data: connection.BatteryInfo) => void = (data: connection.BatteryInfo) => {
    console.info('BatteryInfo = '+ JSON.stringify(data));
}
try {
    connection.on('batteryChange', onReceiveEvent);
    connection.off('batteryChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.on('bluetoothDeviceFind')

on(type: 'bluetoothDeviceFind', callback: Callback&lt;Array&lt;string&gt;&gt;): void

订阅蓝牙设备扫描结果上报事件。使用Callback异步回调。<br>
- 可扫描到的设备类型包括传统蓝牙设备和低功耗蓝牙设备。<br>
- 该上报方式只支持获取设备地址信息。<br>
- 推荐使用API version 18开始支持的[connection.on('discoveryResult')](#connectionondiscoveryresult18)扫描上报方式，可获取到更多设备信息，包括设备地址、设备信号强度、设备名称和设备类型。

**需要权限**：
- API版本26.0.0+：ohos.permission.ACCESS_BLUETOOTH 或 (ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_PEERS_MAC)
- API版本10-24：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | 是    | 事件回调类型，支持的事件为'bluetoothDeviceFind'，表示蓝牙设备扫描结果上报事件。当调用[connection.startBluetoothDiscovery](#connectionstartbluetoothdiscovery)后，开始设备扫描，若扫描到设备，触发该事件。 |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 是    | 指定订阅的回调函数，会携带扫描到的设备地址集合。<br>基于信息安全考虑，此处获取的设备地址为虚拟MAC地址。<br>- 已配对的地址不会变更。<br>- 若该设备重启蓝牙开关，重新获取到的虚拟地址会立即变更。<br>- 若取消配对，蓝牙子系统会根据该地址的实际使用情况，决策后续变更时机；若其他应用正在使用该地址，则不会立刻变更。<br>- 若要持久化保存该地址，可使用[access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16)方法。   |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.<br>适用版本：10-24                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<string>) { // data为蓝牙设备地址集合。
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    connection.on('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.off('bluetoothDeviceFind')

off(type: 'bluetoothDeviceFind', callback?: Callback&lt;Array&lt;string&gt;&gt;): void

取消订阅蓝牙设备扫描结果上报事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | 是    | 事件回调类型，支持的事件为'bluetoothDeviceFind'，表示蓝牙设备扫描结果上报事件。   |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[connection.on('bluetoothDeviceFind')](#connectiononbluetoothdevicefind)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<string>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    connection.on('bluetoothDeviceFind', onReceiveEvent);
    connection.off('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.on('bondStateChange')

on(type: 'bondStateChange', callback: Callback&lt;BondStateParam&gt;): void

订阅蓝牙配对状态变化事件。使用Callback异步回调。

**需要权限**：
- API版本26.0.0+：ohos.permission.ACCESS_BLUETOOTH 或 (ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_PEERS_MAC)
- API版本10-24：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'bondStateChange'，表示蓝牙配对状态变化事件。<br>当调用[connection.pairDevice](#connectionpairdevice)发起主动配对，或者本机设备收到其他设备的配对请求时，触发该事件。 |
| callback | Callback&lt;[BondStateParam](#bondstateparam)&gt; | 是    | 指定订阅的回调函数，会携带配对状态结果。    |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.<br>适用版本：10-24                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: connection.BondStateParam) { // data为回调函数入参，表示配对的状态。
    console.info('pair state = '+ JSON.stringify(data));
}
try {
    connection.on('bondStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.off('bondStateChange')

off(type: 'bondStateChange', callback?: Callback&lt;BondStateParam&gt;): void

取消订阅蓝牙配对状态变化事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'bondStateChange'，表示蓝牙配对状态变化事件。     |
| callback | Callback&lt;[BondStateParam](#bondstateparam)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[connection.on('bondStateChange')](#connectiononbondstatechange)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: connection.BondStateParam) {
    console.info('bond state = '+ JSON.stringify(data));
}
try {
    connection.on('bondStateChange', onReceiveEvent);
    connection.off('bondStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.on('pinRequired')

on(type: 'pinRequired', callback: Callback&lt;PinRequiredParam&gt;): void

订阅配对请求事件。使用Callback异步回调。

**需要权限**：
- API版本26.0.0+：ohos.permission.ACCESS_BLUETOOTH 或 (ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_PEERS_MAC)
- API版本10-24：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'pinRequired'，表示配对请求事件。<br>当调用[connection.pairDevice](#connectionpairdevice)发起主动配对，或者本机设备收到其他设备的配对请求时，触发该事件。     |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | 是    | 指定订阅的回调函数，会携带配对请求。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.<br>适用版本：10-24                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: connection.PinRequiredParam) { // data为配对请求参数。
    console.info('pin required = '+ JSON.stringify(data));
}
try {
    connection.on('pinRequired', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.off('pinRequired')

off(type: 'pinRequired', callback?: Callback&lt;PinRequiredParam&gt;): void

取消订阅配对请求事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'pinRequired'，表示配对请求事件。             |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[connection.on('pinRequired')](#connectiononpinrequired)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: connection.PinRequiredParam) {
    console.info('pin required = '+ JSON.stringify(data));
}
try {
    connection.on('pinRequired', onReceiveEvent);
    connection.off('pinRequired', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.on('discoveryResult')<sup>18+</sup>

on(type: 'discoveryResult', callback: Callback&lt;Array&lt;DiscoveryResult&gt;&gt;): void

订阅蓝牙设备扫描结果上报事件。使用Callback异步回调。<br>
- 可扫描到的设备类型包括传统蓝牙设备和低功耗蓝牙设备。<br>
- 该上报方式支持获取设备地址、设备信号强度、设备名称和设备类型。

**需要权限**：
- API版本26.0.0+：ohos.permission.ACCESS_BLUETOOTH 或 (ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_PEERS_MAC)
- API版本18-24：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | 是    | 事件回调类型，支持的事件为'discoveryResult'，表示蓝牙设备扫描结果上报事件。当调用[connection.startBluetoothDiscovery](#connectionstartbluetoothdiscovery)后，开始设备扫描，若扫描到设备，触发该事件。 |
| callback | Callback&lt;Array&lt;[DiscoveryResult](#discoveryresult18)&gt;&gt; | 是    | 指定订阅的回调函数，会携带扫描结果的集合。    |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.<br>适用版本：18-24                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
let onReceiveEvent: (data: Array<connection.DiscoveryResult>) => void = (data: Array<connection.DiscoveryResult>) => { // data为蓝牙设备扫描结果集合。
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    connection.on('discoveryResult', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.off('discoveryResult')<sup>18+</sup>

off(type: 'discoveryResult', callback?: Callback&lt;Array&lt;DiscoveryResult&gt;&gt;): void

取消订阅蓝牙设备发现上报事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | 是    | 事件回调类型，支持的事件为'discoveryResult'，表示蓝牙设备扫描结果上报事件。   |
| callback | Callback&lt;Array&lt;[DiscoveryResult](#discoveryresult18)&gt;&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[connection.on('discoveryResult')](#connectionondiscoveryresult18)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
let onReceiveEvent: (data: Array<connection.DiscoveryResult>) => void = (data: Array<connection.DiscoveryResult>) => { // data为蓝牙设备扫描结果集合。
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    connection.on('discoveryResult', onReceiveEvent);
    connection.off('discoveryResult', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.onScanModeChange<sup>23+</sup>

onScanModeChange(callback: Callback&lt;ScanMode&gt;): void

订阅蓝牙扫描模式变更事件。使用Callback异步回调。当调用[setBluetoothScanMode](#connectionsetbluetoothscanmode)更改当前蓝牙扫描模式后，如订阅此事件，则会收到携带最新扫描模式的回调函数。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| callback | Callback&lt;[ScanMode](#scanmode)&gt; | 是    | 指定订阅的回调函数，会携带变更后最新的蓝牙扫描模式。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.              |

**示例**：

```js
function ScanModeChangeEvent(scanMode: connection.ScanMode) {
    console.info(`Scan mode has changed, new mode: ${scanMode}`);
}
try {
    connection.onScanModeChange(ScanModeChangeEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```


## connection.offScanModeChange<sup>23+</sup>

offScanModeChange(callback?: Callback&lt;ScanMode&gt;): void

取消订阅蓝牙扫描模式变更事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| callback | Callback&lt;[ScanMode](#scanmode)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[connection.onScanModeChange](#connectiononscanmodechange23)中的回调函数一致；若无传参，则取消订阅所有蓝牙扫描模式变更的回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例**：

```js
function ScanModeChangeEvent(scanMode: connection.ScanMode) {
    console.info(`Scan mode has changed, new mode: ${scanMode}`);
}
try {
    connection.offScanModeChange(ScanModeChangeEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```


## connection.getLastConnectionTime<sup>15+</sup>

getLastConnectionTime(deviceId: string): Promise&lt;number&gt;

获取对端蓝牙设备最近一次连接的时间点。使用Promise异步回调。

- 从API version 21开始，此接口支持使用对端设备的实际MAC地址获取最近一次连接时间。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备MAC地址。例如："XX:XX:XX:XX:XX:XX"。 |

**返回值**：

| 类型                  | 说明         |
| ------------------- | ------------- |
| Promise&lt;number&gt; | Promise对象，返回对端蓝牙设备最近一次连接的时间点，格式为秒级的UNIX时间戳。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.getLastConnectionTime('11:22:33:44:55:66').then((time: number) => {
        console.info(`connectionTime: ${time}`);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## connection.connectAllowedProfiles<sup>16+</sup>

connectAllowedProfiles(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

连接对端设备支持的profile（只包括A2DP、HFP和HID）。使用Callback异步回调。
- API版本26.0.0之前，需先调用[connection.pairDevice](#connectionpairdevice)发起配对，且仅允许在每次发起配对后30秒内调用此接口一次。
- 从API版本26.0.0开始，针对A2DP和HFP，调用接口无时间限制，可以在调用[connection.pairDevice](#connectionpairdevice)发起配对后任意时间内进行调用。
- 当配对成功后，建议先调用[getRemoteProfileUuids](#connectiongetremoteprofileuuids12)主动查询目标设备支持的profile能力。若存在应用需要的能力，才调用此接口。
- 需要与接口[connection.disconnectAllowedProfiles](#connectiondisconnectallowedprofiles)配合使用。
- 从API version 21开始，此接口支持使用对端设备的实际MAC地址进行profile连接。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型    | 必填  | 说明                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是   | 表示需要连接的对端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。|
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当发起连接成功，err为undefined，否则为错误对象。  |

**错误码**：

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID| 错误信息|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
  connection.connectAllowedProfiles('68:13:24:79:4C:8C', (err: BusinessError) => {
    if (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
      return;
    }
    console.info('connectAllowedProfiles');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.connectAllowedProfiles<sup>16+</sup>

connectAllowedProfiles(deviceId: string): Promise&lt;void&gt;

连接对端设备支持的profile（只包括A2DP、HFP和HID）。使用Promise异步回调。
- API版本26.0.0之前，需先调用[connection.pairDevice](#connectionpairdevice)发起配对，且仅允许在每次发起配对后30秒内调用此接口一次。
- 从API版本26.0.0开始，针对A2DP和HFP，调用接口无时间限制，可以在调用[connection.pairDevice](#connectionpairdevice)发起配对后任意时间内进行调用。
- 当配对成功后，建议先调用[getRemoteProfileUuids](#connectiongetremoteprofileuuids12)主动查询目标设备支持的profile能力。若存在应用需要的能力，才调用此接口。
- 需要与接口[connection.disconnectAllowedProfiles](#connectiondisconnectallowedprofiles)配合使用。
- 从API version 21开始，此接口支持使用对端设备的实际MAC地址进行profile连接。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型    | 必填  | 说明                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是   | 表示需要连接的对端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。|

**返回值**：

| 类型                                             | 说明               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果。|

**错误码**：

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID| 错误信息|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
  connection.connectAllowedProfiles('68:13:24:79:4C:8C').then(() => {
      console.info('connectAllowedProfiles');
    }, (err: BusinessError) => {
      console.error('connectAllowedProfiles:errCode' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## connection.disconnectAllowedProfiles

disconnectAllowedProfiles(deviceId: string): Promise&lt;void&gt;

断开对端设备支持的profile（只包括A2DP和HFP）。
- 需要与接口[connection.connectAllowedProfiles](#connectionconnectallowedprofiles16)配合使用。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型    | 必填  | 说明                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是   | 表示需要断开连接的对端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。|

**返回值**：

| 类型                                             | 说明               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果。|

**错误码**：

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID| 错误信息|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|801     | Capability not supported. Failed to call the API when the short-range chip is not inserted on 2in1 device.               |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例**：

```js
try {
  await connection.disconnectAllowedProfiles('68:13:24:79:4C:8C');
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## connection.getVirtualAddressByHash<sup>24+</sup>

getVirtualAddressByHash(algorithmType: HashAlgorithmType, hashValue: string): string

根据已配对设备[实际MAC地址](../../connectivity/bluetooth/bluetooth-overview.md#蓝牙设备地址类型)的哈希值获取对应的[虚拟MAC地址](../../connectivity/bluetooth/bluetooth-overview.md#蓝牙设备地址类型)。

当[HashAlgorithmType](#hashalgorithmtype24)为HASH_ALGORITHM_SHA256时，应使用大写实际MAC地址通过SHA256算法生成对应的哈希值（十六进制64位），取后32位作为输入，哈希值字母不区分大小写。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名     | 类型    | 必填  | 说明                                 |
| -------- | ------ | ---- | ----------------------------------- |
| algorithmType | [HashAlgorithmType](#hashalgorithmtype24) | 是   | 哈希算法类型。|
| hashValue | string | 是   | 哈希值，例如："c10b57deb2e1aafd255596e0d4fd6789"。|

**返回值**：

| 类型                                             | 说明               |
| ------------------------------------------------- | ------------------- |
| string | 返回与哈希值相对应的设备虚拟MAC地址，例如："XX:XX:XX:XX:XX:XX"，返回地址为大写。|

**错误码**：

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID| 错误信息|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|801     | Capability not supported. Failed to call the API when the short-range chip is not inserted on 2in1 device.               |
|2900003 | Bluetooth disabled.                 |
|2900015 | Parameter format mismatch with specification.   |
|2900016 | Device unpaired.   |
|2900099 | Internal system error. For example, IPC error. Detailed error messages can be used to assist in locating the problem.                        |

**示例**：

```js
// 若查询的真实地址为11:22:33:44:55:AA,
// 对应的64位哈希值为 d2204cb9b6d3d3962cc90fa54130efb4c10b57deb2e1aafd255596e0d4fd6789,
// 当HashAlgorithmType为HASH_ALGORITHM_SHA256时取后32位哈希值
let hashValue: string = "c10b57deb2e1aafd255596e0d4fd6789";
try {
  let addr: string = connection.getVirtualAddressByHash(connection.HashAlgorithmType.HASH_ALGORITHM_SHA256, hashValue);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## connection.onAclStateChange

onAclStateChange(callback: Callback&lt;AclStateResult&gt;): void

订阅蓝牙ACL链路连接状态变化事件。当触发蓝牙ACL链路连接与断开连接时，如订阅此事件，则会收到携带对应设备的地址与连接状态的回调函数。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 或 (ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_PEERS_MAC)

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| callback | Callback&lt;[AclStateResult](#aclstateresult)&gt; | 是    | 回调函数，返回蓝牙外设连接状态 |

**错误码**：

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.<br>Failed to call the API when the short-range chip is not inserted on 2in1 device.       |
|2900099 | Internal system error.<br>For example, IPC error. Detailed error messages can be used to assist in locating the problem.              |

**示例**：

```js
function AclStateChangeEvent(aclStateResult: connection.AclStateResult) {
    console.info('acl state changed:'+ JSON.stringify(aclStateResult));
}
try {
    connection.onAclStateChange(AclStateChangeEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## connection.offAclStateChange

offAclStateChange(callback?: Callback&lt;AclStateResult&gt;): void

取消订阅蓝牙ACL链路连接状态变化事件。

**起始版本**：26.0.0

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 或 (ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.GET_BLUETOOTH_PEERS_MAC)

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| callback | Callback&lt;[AclStateResult](#aclstateresult)&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[connection.onAclStateChange](#connectiononaclstatechange)中的回调函数一致；若无传参，则取消订阅所有蓝牙ACL连接状态变更的回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.<br>Failed to call the API when the short-range chip is not inserted on 2in1 device.|
|2900099 | Internal system error.<br>For example, IPC error. Detailed error messages can be used to assist in locating the problem.                        |

**示例**：

```js
function AclStateChangeEvent(aclStateResult: connection.AclStateResult) {
    console.info('acl state changed:'+ JSON.stringify(aclStateResult));
}
try {
    connection.offAclStateChange(AclStateChangeEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## BondStateParam

描述配对状态结果的参数结构。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称       | 类型   | 只读 | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string      | 否    | 否    | 配对中的对端设备地址。 |
| state    | [BondState](#bondstate)   | 否    | 否    | 配对状态。 |
| cause<sup>12+</sup>| [UnbondCause](#unbondcause12) | 否 | 否 | 配对失败的原因。|
| causeMessage | string | 否 | 是 | 配对失败的具体原因，例如：本端业务主动删除配对时，返回：USER_REMOVED。<br> **起始版本**：26.0.0  |


## PinRequiredParam

描述配对请求的参数结构。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称       | 类型   | 只读   | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | 否    | 否    | 要配对的对端设备地址。 |
| pinCode  | string | 否    | 否    | 配对过程中的密钥。   |



## DeviceClass

描述蓝牙设备的类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称              | 类型                                | 只读   | 可选   | 说明               |
| --------------- | ----------------------------------- | ---- | ---- | ---------------- |
| majorClass      | [MajorClass](js-apis-bluetooth-constant.md#majorclass)           | 否    | 否    | 主要类型。是蓝牙标准协议中定义的类型字段。   |
| majorMinorClass | [MajorMinorClass](js-apis-bluetooth-constant.md#majorminorclass) | 否    | 否    | 子类型，是在主要类型上基础上进一步细分的类型。是蓝牙标准协议中定义的类型字段。 |
| classOfDevice   | number                              | 否    | 否    | 设备类型。是蓝牙标准协议中定义的类型字段，包含了[MajorClass](js-apis-bluetooth-constant.md#majorclass)、[MajorMinorClass](js-apis-bluetooth-constant.md#majorminorclass)和支持的主要服务这三种设备信息。          |


## BatteryInfo<sup>12+</sup>

描述设备的电量信息。<br>只有支持蓝牙标准协议定义的电量信息AT（Attention）命令（包括：+XEVENT和IPHONEACCEV）的设备才支持上报有效的电量信息。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称       | 类型   | 只读   | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| batteryLevel  | number | 否    | 否    | 表示设备的电量值。<br>如果该值为-1，表示没有电量信息。   |
| leftEarBatteryLevel  | number | 否    | 否    | 若是蓝牙耳机设备类型，表示左侧耳机的电量值。<br>如果该值为-1，表示没有电量信息。   |
| leftEarChargeState  | [DeviceChargeState](#devicechargestate12) | 否    | 否    | 若是蓝牙耳机设备类型，表示左侧耳机的充电状态。   |
| rightEarBatteryLevel  | number | 否    | 否    | 若是蓝牙耳机设备类型，表示右侧耳机的电量值。<br>如果该值为-1，表示没有电量信息。   |
| rightEarChargeState  | [DeviceChargeState](#devicechargestate12) | 否    | 否    | 若是蓝牙耳机设备类型，表示右侧耳机的充电状态。   |
| boxBatteryLevel  | number | 否    | 否    | 若是蓝牙耳机设备类型，表示耳机仓的电量值。<br>如果值该为-1，表示没有电量信息。   |
| boxChargeState  | [DeviceChargeState](#devicechargestate12) | 否    | 否    | 若是蓝牙耳机设备类型，表示耳机仓的充电状态。   |


## BluetoothTransport

枚举，表示设备传输类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                               | 值    | 说明              |
| -------------------------------- | ------ | --------------- |
| TRANSPORT_BR_EDR   | 0 | 传统蓝牙（Basic Rate/Enhanced Data Rate，BR/EDR）设备传输方式。  |
| TRANSPORT_LE  | 1 | 低功耗蓝牙（Bluetooth Low Energy，BLE）设备传输方式。  |
| TRANSPORT_DUAL<sup>20+</sup>  | 2 | 同时支持传统蓝牙（BR/EDR）和低功耗蓝牙（BLE）的双模设备传输方式。设备可以根据需要选择使用传统蓝牙（BR/EDR）或低功耗蓝牙（BLE）进行通信。  |
| TRANSPORT_UNKNOWN<sup>20+</sup>  | 3 | 未知的设备传输方式。  |


## ScanMode

枚举，表示扫描模式。该模式决定设备是否可被发现或可被连接。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                                       | 值  | 说明              |
| ---------------------------------------- | ---- | --------------- |
| SCAN_MODE_NONE                           | 0    | 不可发现、不可连接模式。         |
| SCAN_MODE_CONNECTABLE                    | 1    | 可连接模式。        |
| SCAN_MODE_GENERAL_DISCOVERABLE           | 2    | 通用可发现模式，可被长时间发现。    |
| SCAN_MODE_LIMITED_DISCOVERABLE           | 3    | 有限可发现模式，持续一定时间。    |
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE | 4    | 可连接及通用可发现模式。 |
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE | 5    | 可连接及有限可发现模式。 |


## BondState

枚举，配对状态。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| BOND_STATE_INVALID | 0    | 未配对状态。 |
| BOND_STATE_BONDING | 1    | 配对中的状态。  |
| BOND_STATE_BONDED  | 2    | 已配对状态。   |


## UnbondCause<sup>12+</sup>

枚举，配对失败原因。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| USER_REMOVED        | 0    | 用户主动移除设备。若配对状态[BondState](#bondstate)是已配对，也表示配对成功。|
| REMOTE_DEVICE_DOWN  | 1    | 对端设备不在线。例如：对端设备蓝牙是关闭的。|
| AUTH_FAILURE        | 2    | 鉴权失败。例如：两端设备密钥不匹配。|
| AUTH_REJECTED       | 3    | 鉴权被拒绝。例如：对端设备拒绝了配对请求。 |
| INTERNAL_ERROR      | 4    | 内部错误。例如：设备不支持配对、配对过程超时等异常。 |


## DeviceChargeState<sup>12+</sup>

枚举，表示设备当前的充电状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| DEVICE_NORMAL_CHARGE_NOT_CHARGED        | 0    | 不支持超级快充能力的设备当前处于未充电状态。|
| DEVICE_NORMAL_CHARGE_IN_CHARGING       | 1    | 不支持超级快充能力的设备当前处于充电状态。|
| DEVICE_SUPER_CHARGE_NOT_CHARGED        | 2    | 支持超级快充能力的设备当前处于未充电状态。|
| DEVICE_SUPER_CHARGE_IN_CHARGING       | 3    | 支持超级快充能力的设备当前处于充电状态。|

## DiscoveryResult<sup>18+</sup>

扫描到设备后，上报的扫描结果。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

<!--Table: 15%; 15%; 10%; 10%; 50%-->
| 名称       | 类型   | 只读   | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId    | string      | 否    | 否    | 扫描到的设备地址。<br>基于信息安全考虑，此处获取的设备地址为虚拟MAC地址。<br>- 已配对的地址不会变更。<br>- 若该设备重启蓝牙开关，重新获取到的虚拟地址会立即变更。<br>- 若取消配对，蓝牙子系统会根据该地址的实际使用情况，决策后续变更时机；若其他应用正在使用该地址，则不会立刻变更。<br>- 若要持久化保存该地址，可使用[access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16)方法。|
| rssi     | number      | 否    | 否    | 扫描到的设备信号强度，单位：dBm。|
| deviceName     | string      | 否    | 否    | 扫描到的设备名称。|
| deviceClass     | [DeviceClass](#deviceclass)      | 否    | 否    | 扫描到的设备类型。|

## HashAlgorithmType<sup>24+</sup>

枚举，表示哈希算法类型。

哈希算法是一种数学函数，通过对输入数据进行复杂计算，生成一个唯一且固定长度的字符串（即哈希值）。常用于数据完整性校验、数字签名等场景。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| HASH_ALGORITHM_SHA256        | 0    | SHA256哈希算法。|


## AclStateResult

描述ACL连接状态的参数结构。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称       | 类型   | 只读 | 可选   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string      | 否    | 否    | 表示对端设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |
| state    | [AclState](#aclstate)   | 否    | 否    | 连接状态。 |


## AclState

枚举，表示ACL连接状态。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| STATE_CONNECTED        | 0    | ACL链路已连接。|
| STATE_DISCONNECTED        | 1    | ACL链路已断开连接。|