# @ohos.bluetooth.connection (蓝牙connection模块)

connection模块提供了对蓝牙操作和管理的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import { connection } from '@kit.ConnectivityKit';
```


## ProfileConnectionState

type ProfileConnectionState = constant.ProfileConnectionState

蓝牙设备的profile连接状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | 蓝牙设备的profile连接状态。 |


## ProfileId

type ProfileId = constant.ProfileId

蓝牙profile枚举。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.ProfileId](js-apis-bluetooth-constant.md#profileid) | 蓝牙profile枚举。 |


## ProfileUuids<sup>12+</sup>

type ProfileUuids = constant.ProfileUuids

表示Profile的UUID。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.ProfileUuids](js-apis-bluetooth-constant.md#profileuuids) | 表示Profile的UUID。 |


## MajorClass

type MajorClass = constant.MajorClass

蓝牙设备主要类别。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.MajorClass](js-apis-bluetooth-constant.md#majorclass) | 蓝牙设备主要类别。 |


## MajorMinorClass

type MajorMinorClass = constant.MajorMinorClass

主要次要蓝牙设备类别。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| [constant.MajorMinorClass](js-apis-bluetooth-constant.md#majorminorclass) | 主要次要蓝牙设备类别。 |


## connection.pairDevice

pairDevice(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

发起蓝牙配对。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

发起蓝牙配对。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 返回promise对象。 |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.pairDevice('11:22:33:44:55:66').then(() => {
        console.info('pairDevice');
    }, (error: BusinessError) => {
        console.info('pairDevice: errCode:' + error.code + ',errMessage' + error.message);
    })

} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceName

getRemoteDeviceName(deviceId: string): string

获取对端蓝牙设备的名称。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let remoteDeviceName: string = connection.getRemoteDeviceName('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceName<sup>16+</sup>

getRemoteDeviceName(deviceId: string, alias?: boolean): string

获取对端蓝牙设备的名称，其中alias为可选参数。
- 如果携带alias，则根据alias判断是否获取对端蓝牙设备别名。
- 如果未携带alias，则默认返回对端蓝牙设备别名。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |
| alias | boolean | 否    | 是否获取对端蓝牙设备别名。获取成功为true，否则设置为false。 |

**返回值：**

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let remoteDeviceName: string = connection.getRemoteDeviceName('XX:XX:XX:XX:XX:XX', true);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceClass

getRemoteDeviceClass(deviceId: string): DeviceClass

获取对端蓝牙设备的类别。从API18开始不再校验ohos.permission.ACCESS_BLUETOOTH权限。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                          | 说明       |
| --------------------------- | -------- |
| [DeviceClass](#deviceclass) | 远程设备的类别。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let remoteDeviceClass: connection.DeviceClass = connection.getRemoteDeviceClass('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteProfileUuids<sup>12+</sup>

getRemoteProfileUuids(deviceId: string, callback: AsyncCallback&lt;Array&lt;ProfileUuids&gt;&gt;): void

获取对端蓝牙设备支持的Profile UUID。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| callback | AsyncCallback&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids12)&gt;&gt; | 是    | 回调函数。当获取UUID成功，err为undefined，否则为错误对象。 |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

获取对端蓝牙设备支持的Profile UUID。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
|   Promise&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids12)&gt;&gt; | 返回promise对象。 |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

获取蓝牙本地设备名称。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 蓝牙本地设备名称。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let localName: string = connection.getLocalName();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getPairedDevices

getPairedDevices(): Array&lt;string&gt;

获取蓝牙配对列表。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Array&lt;string&gt; | 已配对蓝牙设备的地址列表。<br>- 基于信息安全考虑，此处获取的设备地址为随机MAC地址。<br>- 配对成功后，该地址不会变更。<br>- 已配对设备取消配对后重新扫描或蓝牙服务下电时，该随机地址会变更。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let devices: Array<string> = connection.getPairedDevices();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getPairState<sup>11+</sup>

getPairState(deviceId: string): BondState

获取蓝牙配对状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let res: connection.BondState = connection.getPairState("XX:XX:XX:XX:XX:XX");
    console.info('getPairState: ' + res);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getProfileConnectionState

getProfileConnectionState(profileId?: ProfileId): ProfileConnectionState

获取蓝牙Profile的连接状态，其中ProfileId为可选参数。
- 如果携带ProfileId，则返回的是当前Profile的连接状态。
- 如果未携带ProfileId，任一Profile已连接则返回[STATE_CONNECTED](js-apis-bluetooth-constant.md#profileconnectionstate)，否则返回[STATE_DISCONNECTED](js-apis-bluetooth-constant.md#profileconnectionstate)。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名       | 类型        | 必填   | 说明                                    |
| --------- | --------- | ---- | ------------------------------------- |
| profileId | [ProfileId](js-apis-bluetooth-constant.md#profileid) | 否    | 表示profile的枚举值，例如：PROFILE_A2DP_SOURCE。 |

**返回值：**

| 类型                                              | 说明                |
| ------------------------------------------------- | ------------------- |
| [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | profile的连接状态。 |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { constant } from '@kit.ConnectivityKit';
try {
    let result: connection.ProfileConnectionState = connection.getProfileConnectionState(constant.ProfileId.PROFILE_A2DP_SOURCE);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setDevicePairingConfirmation

setDevicePairingConfirmation(deviceId: string, accept: boolean): void

设置设备配对请求确认。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH（该权限仅系统应用可申请）

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------   | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| accept   | boolean | 是    | 接受配对请求设置为true，否则设置为false。        |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// 订阅“pinRequired”配对请求事件，收到远端配对请求后设置配对确认。
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

当蓝牙配对类型PinType为PIN_TYPE_ENTER_PIN_CODE或PIN_TYPE_PIN_16_DIGITS时调用此接口，请求用户输入PIN码。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |
| code   | string  | 是    | 用户输入的PIN码。        |
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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// callback
try {
    connection.setDevicePinCode('11:22:33:44:55:66', '12345', (err: BusinessError) => {
        console.info('setDevicePinCode,device name err:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setDevicePinCode

setDevicePinCode(deviceId: string, code: string): Promise&lt;void&gt;

当蓝牙配对类型PinType为PIN_TYPE_ENTER_PIN_CODE或PIN_TYPE_PIN_16_DIGITS时调用此接口，请求用户输入PIN码。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |
| code   | string  | 是    | 用户输入的PIN码。        |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 返回promise对象。 |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.setDevicePinCode('11:22:33:44:55:66', '12345').then(() => {
        console.info('setDevicePinCode');
    }, (error: BusinessError) => {
        console.info('setDevicePinCode: errCode:' + error.code + ',errMessage' + error.message);
    })

} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setLocalName<sup>(deprecated)</sup>

setLocalName(name: string): void

设置蓝牙本地设备名称。

> **说明：**<br/>
> 从API version 10开始支持，从API version 12开始废弃，不再提供替代接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名  | 类型     | 必填   | 说明                    |
| ---- | ------ | ---- | --------------------- |
| name | string | 是    | 要设置的蓝牙名称，最大长度为248字节数。 |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.setLocalName('device_name');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.setBluetoothScanMode

setBluetoothScanMode(mode: ScanMode, duration: number): void

设置蓝牙扫描模式，可以被远端设备发现。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                    | 必填   | 说明                           |
| -------- | --------------------- | ---- | ---------------------------- |
| mode     | [ScanMode](#scanmode) | 是    | 蓝牙扫描模式。当扫描模式为SCAN_MODE_GENERAL_DISCOVERABLE时，超出duration持续时间(不为0)，扫描模式会重新设置为SCAN_MODE_CONNECTABLE。               |
| duration | number                | 是    | 设备可被发现的持续时间，单位为毫秒。设置为0则持续可发现。 |

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    // 设置为可连接可发现才可被远端设备扫描到，可以连接。
    connection.setBluetoothScanMode(connection.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getBluetoothScanMode

getBluetoothScanMode(): ScanMode

获取蓝牙扫描模式。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

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

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let scanMode: connection.ScanMode = connection.getBluetoothScanMode();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.startBluetoothDiscovery

startBluetoothDiscovery(): void

开启蓝牙扫描，可以发现远端设备。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

关闭蓝牙扫描。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    connection.stopBluetoothDiscovery();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.isBluetoothDiscovering<sup>11+</sup>

isBluetoothDiscovering(): boolean

查询设备的蓝牙发现状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
|   boolean           | 设备已开启蓝牙发现为true，否则为false。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let res: boolean = connection.isBluetoothDiscovering();
    console.info('isBluetoothDiscovering: ' + res);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## connection.setRemoteDeviceName<sup>12+</sup>

setRemoteDeviceName(deviceId: string, name: string): Promise&lt;void&gt;

设置蓝牙远端设备名称。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| deviceId     | string                              | 是    | 表示远端设备MAC地址，例如："XX:XX:XX:XX:XX:XX"。 |
| name | string | 是    | 修改远端设备名称，最大长度为64字节。    |

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Promise&lt;void&gt; | 以Promise形式返回设置蓝牙远端设备名称的结果，设置失败时返回错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.            |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    connection.setRemoteDeviceName('11:22:33:44:55:66', 'RemoteDeviceName').then(() => {
        console.info('setRemoteDeviceName success');
    }, (error: BusinessError) => {
        console.error('setRemoteDeviceName: errCode:' + error.code + ',errMessage' + error.message);
    })

} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## connection.getRemoteDeviceBatteryInfo<sup>12+</sup>

getRemoteDeviceBatteryInfo(deviceId: string): Promise&lt;BatteryInfo&gt;

获取蓝牙远端设备的电量信息。使用Promise异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备MAC地址，例如："11:22:33:AA:BB:FF"。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ------------- |
| Promise&lt;[BatteryInfo](#batteryinfo12)&gt; | 以Promise形式返回蓝牙远端设备的电量信息。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.            |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

订阅蓝牙远程设备的电量信息变更事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | 是    | 填写"batteryChange"字符串，表示蓝牙远端设备的电池信息变更事件。 |
| callback | Callback&lt;[BatteryInfo](#batteryinfo12)&gt; | 是    | 表示回调函数的入参，返回电量信息。    |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

取消订阅蓝牙远程设备的电量信息变更事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | 是    | 填写"batteryChange"字符串，表示取消蓝牙远端设备的电池信息变更事件。   |
| callback | Callback&lt;[BatteryInfo](#batteryinfo12)&gt; | 否    | 表示回调函数的入参，返回电量信息。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

订阅蓝牙设备发现上报事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | 是    | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。 |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 是    | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。基于信息安全考虑，此处获取的设备地址为随机MAC地址。配对成功后，该地址不会变更；已配对设备取消配对后重新扫描或蓝牙服务下电时，该随机地址会变更。    |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

取消订阅蓝牙设备发现上报事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | 是    | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。   |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 否    | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

订阅蓝牙配对状态改变事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | string                                   | 是    | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。 |
| callback | Callback&lt;[BondStateParam](#bondstateparam)&gt; | 是    | 表示回调函数的入参，配对的状态。回调函数由用户创建通过该接口注册。    |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

取消订阅蓝牙配对状态改变事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。     |
| callback | Callback&lt;[BondStateParam](#bondstateparam)&gt; | 否    | 表示取消订阅蓝牙配对状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

订阅远端蓝牙设备的配对请求事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | 是    | 填写"pinRequired"字符串，表示配对请求事件。     |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | 是    | 表示回调函数的入参，配对请求。回调函数由用户创建通过该接口注册。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

取消订阅远端蓝牙设备的配对请求事件。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"pinRequired"字符串，表示配对请求事件。             |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | 否    | 表示取消订阅蓝牙配对请求事件上报，入参为配对请求参数。不填该参数则取消订阅该type对应的所有回调。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

订阅蓝牙设备发现上报事件。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | 是    | 填写"discoveryResult"字符串，表示蓝牙设备发现事件。 |
| callback | Callback&lt;Array&lt;[DiscoveryResult](#discoveryresult18)&gt;&gt; | 是    | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。    |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | 是    | 填写"discoveryResult"字符串，表示蓝牙设备发现事件。   |
| callback | Callback&lt;Array&lt;[DiscoveryResult](#discoveryresult18)&gt;&gt; | 否    | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
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


## connection.getLastConnectionTime<sup>15+</sup>

getLastConnectionTime(deviceId: string): Promise&lt;number&gt;

获取蓝牙远端设备最近一次连接的时间点。使用Promise异步回调。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | 是    | 表示远端设备MAC地址。例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ------------- |
| Promise&lt;number&gt; | 以Promise形式返回设置蓝牙远端设备最近一次连接的时间点结果，返回promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { connection } from '@kit.ConnectivityKit';
// promise
try {
    connection.getLastConnectionTime('11:22:33:44:55:66').then((time: number) => {
        console.info('connectionTime: ${time}');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## connection.connectAllowedProfiles<sup>16+</sup>

connectAllowedProfiles(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

连接远端设备所有允许连接的profiles。使用Callback异步回调。<br/>需先调用pairDevice发起配对，且仅允许在每次发起配对后30s内调用此接口一次。<br/>建议用法：订阅UUID_VALUE公共事件回调，配对成功后会收到公共事件回调。建议在此回调中调用connectAllowedProfiles接口。

**需要权限：**: ohos.permission.ACCESS_BLUETOOTH

**系统能力：**: SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型    | 必填  | 说明                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是   | 表示连接的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。|
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当发起连接成功，err为undefined，否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID| 错误信息|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { commonEventManager, AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { connection } from '@kit.ConnectivityKit';
// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber: commonEventManager.CommonEventSubscriber;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ["usual.event.bluetooth.remotedevice.UUID_VALUE"]
};
// 订阅公共事件回调
function SubscribeCB(err: BusinessError, data: commonEventManager.CommonEventData) {
  if (err) {
    console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in subscribing, data is ` + JSON.stringify(data));
    // 调用connectAllowedProfiles前，需确保已收到UUID_VALUE的系统公共事件
    try {
        connection.connectAllowedProfiles('68:13:24:79:4C:8C', (err: BusinessError) => {
            if (err) {
                console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
                return;
            }
            console.info('connectAllowedProfiles, err: ' + JSON.stringify(err));
        });
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}
// 创建订阅者回调
function createCB(err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) {
  if(!err) {
    console.info(`Succeeded in creating subscriber.`);
    subscriber = commonEventSubscriber;
    // 订阅公共事件
    try {
      commonEventManager.subscribe(subscriber, SubscribeCB);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
    }
  } else {
    console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
  }
}

// 创建订阅者，并订阅公共事件回调
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
}
```


## connection.connectAllowedProfiles<sup>16+</sup>

connectAllowedProfiles(deviceId: string): Promise&lt;void&gt;

连接远端设备所有允许连接的profiles。使用Promise异步回调。<br/>需先调用pairDevice发起配对，且仅允许在每次发起配对后30s内调用此接口一次。<br/>建议用法：订阅UUID_VALUE公共事件回调，配对成功后会收到公共事件回调.建议在此回调中调用connectAllowedProfiles接口。

**需要权限：**: ohos.permission.ACCESS_BLUETOOTH

**系统能力：**: SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型    | 必填  | 说明                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是   | 表示连接的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。|

**返回值：**

| 类型                                             | 说明               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | Promise对象。|

**错误码：**

以下错误码的详细介绍请参见 [通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID| 错误信息|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { commonEventManager, AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { connection } from '@kit.ConnectivityKit';
// 定义订阅者，用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
let subscriber: commonEventManager.CommonEventSubscriber;
// 订阅者信息
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ["usual.event.bluetooth.remotedevice.UUID_VALUE"]
};
// 订阅公共事件回调
function SubscribeCB(err: BusinessError, data: commonEventManager.CommonEventData) {
  if (err) {
    console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`Succeeded in subscribing, data is ` + JSON.stringify(data));
    // 调用connectAllowedProfiles前，需确保已收到UUID_VALUE的系统公共事件
    try {
        connection.connectAllowedProfiles('68:13:24:79:4C:8C').then(() => {
            console.info('connectAllowedProfiles');
        }, (err: BusinessError) => {
            console.error('connectAllowedProfiles:errCode' + err.code + ', errMessage: ' + err.message);
        });
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}
// 创建订阅者回调
function createCB(err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) {
  if(!err) {
    console.info(`Succeeded in creating subscriber.`);
    subscriber = commonEventSubscriber;
    // 订阅公共事件
    try {
      commonEventManager.subscribe(subscriber, SubscribeCB);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
    }
  } else {
    console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
  }
}

// 创建订阅者，并订阅公共事件回调
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
}
```

## BondStateParam

描述配对状态参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string      | 是    | 否    | 表示要配对的设备ID。 |
| state    | BondState   | 是    | 否    | 表示配对设备的状态。 |
| cause<sup>12+</sup>| [UnbondCause](#unbondcause12) | 是 | 否 | 表示配对失败的原因。|


## PinRequiredParam

描述配对请求参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | 是    | 否    | 表示要配对的设备ID。 |
| pinCode  | string | 是    | 否    | 表示要配对的密钥。   |



## DeviceClass

描述蓝牙设备的类别。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称              | 类型                                | 可读   | 可写   | 说明               |
| --------------- | ----------------------------------- | ---- | ---- | ---------------- |
| majorClass      | [MajorClass](js-apis-bluetooth-constant.md#majorclass)           | 是    | 否    | 表示蓝牙设备主要类别的枚举。   |
| majorMinorClass | [MajorMinorClass](js-apis-bluetooth-constant.md#majorminorclass) | 是    | 否    | 表示主要次要蓝牙设备类别的枚举。 |
| classOfDevice   | number                              | 是    | 否    | 表示设备类别。          |


## BatteryInfo<sup>12+</sup>

描述电量信息的内容。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| batteryLevel  | number | 是    | 否    | 表示远端设备的电量值，如果值为-1，表示没有电量信息。   |
| leftEarBatteryLevel  | number | 是    | 否    | 表示左侧耳机的电量值，如果值为-1，表示没有电量信息。   |
| leftEarChargeState  | [DeviceChargeState](#devicechargestate12) | 是    | 否    | 表示左侧耳机的充电状态。   |
| rightEarBatteryLevel  | number | 是    | 否    | 表示右侧耳机的电量值，如果值为-1，表示没有电量信息。   |
| rightEarChargeState  | [DeviceChargeState](#devicechargestate12) | 是    | 否    | 表示右侧耳机的充电状态。   |
| boxBatteryLevel  | number | 是    | 否    | 表示耳机仓的电量值，如果值为-1，表示没有电量信息。   |
| boxChargeState  | [DeviceChargeState](#devicechargestate12) | 是    | 否    | 表示耳机仓的充电状态。   |


## BluetoothTransport

枚举，表示设备类型。例如传统蓝牙设备或低功耗蓝牙设备，支持双模默认使用TRANSPORT_BR_EDR。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                               | 值    | 说明              |
| -------------------------------- | ------ | --------------- |
| TRANSPORT_BR_EDR   | 0 | 表示传统蓝牙(BR/EDR)设备。 |
| TRANSPORT_LE  | 1 | 表示低功耗蓝牙(BLE)设备。  |


## ScanMode

枚举，扫描模式。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                                       | 值  | 说明              |
| ---------------------------------------- | ---- | --------------- |
| SCAN_MODE_NONE                           | 0    | 没有扫描模式。         |
| SCAN_MODE_CONNECTABLE                    | 1    | 可连接扫描模式。        |
| SCAN_MODE_GENERAL_DISCOVERABLE           | 2    | general发现模式。    |
| SCAN_MODE_LIMITED_DISCOVERABLE           | 3    | limited发现模式。    |
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE | 4    | 可连接general发现模式。 |
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE | 5    | 可连接limited发现模式。 |


## BondState

枚举，配对状态。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| BOND_STATE_INVALID | 0    | 无效的配对。 |
| BOND_STATE_BONDING | 1    | 正在配对。  |
| BOND_STATE_BONDED  | 2    | 已配对。   |


## UnbondCause<sup>12+</sup>

枚举，配对失败原因。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| USER_REMOVED        | 0    | 用户主动移除设备。|
| REMOTE_DEVICE_DOWN  | 1    | 远端设备关闭。|
| AUTH_FAILURE        | 2    | PIN码错误。|
| AUTH_REJECTED       | 3    | 远端设备鉴权拒绝。 |
| INTERNAL_ERROR      | 4    | 内部错误。 |


## DeviceChargeState<sup>12+</sup>

枚举，表示充电状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| DEVICE_NORMAL_CHARGE_NOT_CHARGED        | 0    | 未充电，不支持超级充电。|
| DEVICE_NORMAL_CHARGE_IN_CHARGING       | 1    | 正在充电，不支持超级充电。|
| DEVICE_SUPER_CHARGE_NOT_CHARGED        | 2    | 未充电，支持超级充电。|
| DEVICE_SUPER_CHARGE_IN_CHARGING       | 3    | 正在充电，支持超级充电。|

## DiscoveryResult<sup>18+</sup>

描述扫描设备状态参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId    | string      | 是    | 否    | 表示扫描到的设备ID。|
| rssi     | number      | 是    | 否    | 表示扫描到的设备的信号强度。|
| deviceName     | string      | 是    | 否    | 表示扫描到的设备的设备名称。|
| deviceClass     | DeviceClass      | 是    | 否    | 表示扫描到的设备的设备类别。|