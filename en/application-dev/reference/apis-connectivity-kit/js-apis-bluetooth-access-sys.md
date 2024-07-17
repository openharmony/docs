# @ohos.bluetooth.access (Bluetooth Access Module) (System API)

The **access** module provides APIs for enabling and disabling Bluetooth and obtaining the Bluetooth status.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.bluetooth.access (Bluetooth Access Module)](js-apis-bluetooth-access.md).


## Modules to Import

```js
import { access } from '@kit.ConnectivityKit';
```


## access.factoryReset<sup>11+</sup>

factoryReset(callback: AsyncCallback&lt;void&gt;): void

Restores the Bluetooth factory settings. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name  | Type                                              | Mandatory | Description                                                      |
| -------- | ------------------------------------------------- | ----- | ---------------------------------------------------------- |
| callback     | AsyncCallback&lt;void&gt;             | Yes   | Callback used to return the result.<br>If the Bluetooth factory settings are restored successfully, **err** is **undefined**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.           |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.factoryReset((err: BusinessError) => {
        if (err) {
            console.error("factoryReset error");
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.factoryReset<sup>11+</sup>

factoryReset(): Promise&lt;void&gt;

Restores the Bluetooth factory settings. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.factoryReset().then(() => {
        console.info("factoryReset");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.getLocalAddress<sup>11+</sup><a name="getLocalAddress"></a>

getLocalAddress(): string;

Obtains the Bluetooth address of the local device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.GET_BLUETOOTH_LOCAL_MAC

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description               |
| --------- | ------------------ |
| string    | Bluetooth address obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
try {
    let localAddr = access.getLocalAddress();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.restrictBluetooth<sup>12+</sup><a name="restrictBluetooth"></a>

restrictBluetooth(): Promise&lt;void&gt;

Restricts the BR/EDR capability of this Bluetooth device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.restrictBluetooth().then(() => {
        console.info("restrictBluetooth");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
