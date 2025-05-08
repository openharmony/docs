# @ohos.bluetooth.connection (Bluetooth Connection Module) (System API)

The **connection** module provides APIs for operating and managing Bluetooth.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.bluetooth.connection (Bluetooth Connection Module)](js-apis-bluetooth-connection.md).


## Modules to Import

```js
import { connection } from '@kit.ConnectivityKit';
```


## connection.pairCredibleDevice

pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback&lt;void&gt;): void

Pairs a trusted device whose address is obtained in a non-Bluetooth scan mode (such as using NFC). This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the device to pair, for example, XX:XX:XX:XX:XX:XX.|
| transport | [BluetoothTransport](js-apis-bluetooth-connection.md#bluetoothtransport) | Yes   | Device type, for example, a classic Bluetooth device or a Bluetooth low energy (BLE) device.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Pairs a trusted device whose address is obtained in a non-Bluetooth scan mode (such as using NFC). This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the device to pair, for example, XX:XX:XX:XX:XX:XX.|
| transport | [BluetoothTransport](js-apis-bluetooth-connection.md#bluetoothtransport) | Yes   | Device type, for example, a classic Bluetooth device or a BLE device.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Cancels a paired device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                   |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | Yes   | Address of the device to cancel, for example, XX:XX:XX:XX:XX:XX.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Cancels a paired device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                   |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | Yes   | Address of the device to cancel, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Cancels the pairing of a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                   |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | Yes   | Address of the device to cancel, for example, XX:XX:XX:XX:XX:XX.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Cancels the pairing of a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                   |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | Yes   | Address of the device to cancel, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Obtains the profile UUIDs of the local device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids)&gt;&gt; | Yes   | Callback used to return the profile UUIDs obtained. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Obtains the profile UUIDs of the local device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
|   Promise&lt;Array&lt;[ProfileUuids](js-apis-bluetooth-constant.md#profileuuids)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.           |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Disconnects all connected profiles for a remote device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the target remote device, for example, XX:XX:XX:XX:XX.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|202     | Non-system applications are not allowed to use system APIs.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Disconnects all connected profiles for a remote device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the target remote device, for example, XX:XX:XX:XX:XX.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|202     | Non-system applications are not allowed to use system APIs.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Obtains the product ID of a remote Bluetooth device. Since API version 16, the **ohos.permission.ACCESS_BLUETOOTH** and **ohos.permission.MANAGE_BLUETOOTH** permissions are no longer verified.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                               |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Product ID obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
try {
  let remoteDeviceProductId = connection.getRemoteProductId('XX:XX:XX:XX:XX:XX');
} catch (err) {
  console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## connection.setRemoteDeviceType<sup>12+</sup>

setRemoteDeviceType(deviceId: string, type: DeviceType): Promise&lt;void&gt;

Sets the type of a remote Bluetooth device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type     | Mandatory  | Description                              |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | Yes   | MAC address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| type   | [DeviceType](#devicetype12)  | Yes   | Device type to set.       |

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the device type set. If the operation fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**Example**

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

Obtains the type of a remote Bluetooth device. This API uses a promise to return the result. Since API version 18, the **ohos.permission.ACCESS_BLUETOOTH** permission is no longer verified.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type     | Mandatory  | Description                              |
| ------ | ------- | ---- | -------------------------------- |
| deviceId | string  | Yes   | MAC address of the remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                 | Description        |
| ------------------- | ------------- |
| Promise&lt;[DeviceType](#devicetype12)&gt; | Promise used to return the device type obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |

**Example**

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

Sends a control command to Bluetooth headsets during scanning. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH (available only for system applications)

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type     | Mandatory  | Description                              |
| ------ | ------- | ---- | -------------------------------- |
| controlDeviceActionParams<sup>15+</sup> | [ControlDeviceActionParams](#controldeviceactionparams15) | Yes   | Bluetooth peripheral control information.|

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

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

Updates cloud devices in Bluetooth settings. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type     | Mandatory  | Description                              |
| ------ | ------- | ---- | -------------------------------- |
| trustedPairedDevices   | [TrustedPairedDevices](#trustedpaireddevices15)  | Yes   | Cloud device list. |  

**Return value**

| Type                 | Description        |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result. If the setting fails, an error code is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { connection } from '@kit.ConnectivityKit';
// promise
/**
 * Update cloud devices in Bluetooth settings.
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

Represents the pairing request parameters.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| pinType | [PinType](#pintype) | Yes   | No   | Type of the device to pair.<br>This is a system API.  |

## ControlDeviceActionParams<sup>15+</sup>

Defines the configuration parameters of the control command.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | Yes   | No| Device ID.|
| type | [ControlType](#controltype15) | Yes   | No   | Control type.|
| typeValue | [ControlTypeValue](#controltypevalue15) | Yes| No| Control action.|
| controlObject | [ControlObject](#controlobject15) | Yes| No| Control object.|

## PinType

Enumerates the Bluetooth pairing types.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                              | Value   | Description             |
| -------------------------------- | ------ | --------------- |
| PIN_TYPE_ENTER_PIN_CODE | 0 | The user needs to enter the PIN displayed on the peer device.<br>This is a system API.|
| PIN_TYPE_ENTER_PASSKEY  | 1 | The user needs to enter the PASSKEY displayed on the peer device.<br>This is a system API. |
| PIN_TYPE_CONFIRM_PASSKEY  | 2 | The user needs to confirm the PASSKEY displayed on the local device.<br>This is a system API. |
| PIN_TYPE_NO_PASSKEY_CONSENT  | 3 | There is no PASSKEY, and the user needs to accept or reject the pairing request.<br>This is a system API. |
| PIN_TYPE_NOTIFY_PASSKEY   | 4 | The user needs to enter the PASSKEY displayed on the local device on the peer device.<br>This is a system API. |
| PIN_TYPE_DISPLAY_PIN_CODE    | 5 | The user needs to enter the PIN displayed on the peer device for Bluetooth 2.0 devices.<br>This is a system API. |
| PIN_TYPE_OOB_CONSENT    | 6 | The user needs to accept or reject the out of band (OOB) pairing request.<br>This is a system API. |
| PIN_TYPE_PIN_16_DIGITS    | 7 | The user needs to enter the 16-digit PIN displayed on the peer device.<br>This is a system API. |



## DeviceType<sup>12+</sup>

Enumerates the custom types of a remote Bluetooth device.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                              | Value   | Description             |
| -------------------------------- | ------ | --------------- |
| DEVICE_TYPE_DEFAULT<sup>12+</sup> | 0 | Default device type, which is the same as the original type.<br>This is a system API.|
| DEVICE_TYPE_CAR<sup>12+</sup>  | 1 | Car.<br>This is a system API. |
| DEVICE_TYPE_HEADSET<sup>12+</sup>  | 2 | Headset.<br>This is a system API. |
| DEVICE_TYPE_HEARING<sup>12+</sup>   | 3 | Hearing aid.<br>This is a system API. |
| DEVICE_TYPE_GLASSES<sup>12+</sup>    | 4 | Glasses. <br>This is a system API. |
| DEVICE_TYPE_WATCH<sup>12+</sup>     | 5 | Watch.<br>This is a system API. |
| DEVICE_TYPE_SPEAKER<sup>12+</sup>     | 6 | Speaker.<br>This is a system API. |
| DEVICE_TYPE_OTHERS<sup>12+</sup>     | 7 | Other device.<br>This is a system API. |


## BatteryInfo<sup>12+</sup>

Represents the battery information.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | Yes   | No   | MAC address of the remote device.<br>This is a system API.|


## ControlType<sup>15+</sup>

Enumerates control types.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                              | Value   | Description             |
| -------------------------------- | ------ | --------------- |
| PLAY | 0 | Play|
| VIBRATE | 1 | Vibration|
| FLASH | 2 | Flash|
| LOCK | 3 | Lock|


## ControlTypeValue<sup>15+</sup>

Enumerates control actions.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name   | Value  | Description      |
| ------- | ---- | ---------- |
| DISABLE | 0    | Disable|
| ENABLE  | 1    | Enable|
| QUERY   | 2    | Query|


## ControlObject<sup>15+</sup>

Enumerates control objects.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name          | Value  | Description                |
| -------------- | ---- | -------------------- |
| LEFT_EAR       | 0    | Left earbud.|
| RIGHT_EAR      | 1    | Right earbud.|
| LEFT_RIGHT_EAR | 2    | Left and right earbuds.|


## TrustedPairedDevices<sup>15+</sup>

Defines the cloud device list.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Optional  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| trustedPairedDevices  | Array&lt;[TrustedPairedDevice](#trustedpaireddevice15)&gt; | Yes   | No   | Cloud device list.  |

## TrustedPairedDevice<sup>15+</sup>

Defines the cloud device information.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Optional  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| sn  | string | Yes   | No   | Device SN.  |
| deviceType  | string | Yes   | No   | Device type to set.  |
| modelId  | string | Yes   | No   | Charging state of the left earbud.  |
| manufactory  | string | Yes   | No   | Manufacturer information.  |
| productId  | string | Yes   | No   | Product information.  |
| hiLinkVersion  | string | Yes   | No   | HiLink version.  |
| macAddress  | string | Yes   | No   | MAC address.  |
| serviceType  | string | Yes   | No   | Service type.  |
| serviceId  | string | Yes   | No   | Device ID.  |
| deviceName  | string | Yes   | No   | Device name.  |
| uuids  | string | Yes   | No   | Device UUID.  |
| bluetoothClass  | number | Yes   | No   | Peer device type.  |
| token  | ArrayBuffer | Yes   | No   | Device token information.  |
| deviceNameTime  | number | Yes   | No   | Device name modification time.  |
| secureAdvertisingInfo  | ArrayBuffer | Yes   | No   | Device advertising information.  |
| pairState  | number | Yes   | No   | Device pairing status.  |
