# @ohos.bluetoothManager (Bluetooth) (System API)

The **Bluetooth** module provides classic Bluetooth capabilities and Bluetooth Low Energy (BLE) scan and advertising.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are no longer maintained since API version 10. You are advised to use profile APIs of [@ohos.bluetooth.ble](js-apis-bluetooth-ble.md).
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.bluetoothManager](js-apis-bluetoothManager.md).



## Modules to Import

```js
import bluetoothManager from '@ohos.bluetoothManager';
```


## bluetoothManager.cancelPairedDevice<sup>(deprecated)</sup><a name="cancelPairedDevice"></a>

cancelPairedDevice(deviceId: string): void

Cancels a paired remote device.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [connection.cancelPairedDevice](js-apis-bluetooth-connection-sys.md#connectioncancelpaireddevice) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                   |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | Yes   | Address of the remote device to cancel, for example, XX:XX:XX:XX:XX:XX.|

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
import { BusinessError } from '@ohos.base';
try {
    bluetoothManager.cancelPairedDevice("XX:XX:XX:XX:XX:XX");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### connect<a name="HidHost-connect"></a>

connect(device: string): void

Connects to the HidHost service of a device.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [hid.HidHostProfile#connect](js-apis-bluetooth-hid-sys.md#connect) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

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
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

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

Disconnects from the HidHost service of a device.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [hid.HidHostProfile#disconnect](js-apis-bluetooth-hid-sys.md#disconnect) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

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
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

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

Disconnects from the Personal Area Network (PAN) service of a device.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [pan.PanProfile#disconnect](js-apis-bluetooth-pan-sys.md#disconnect) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

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
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

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

Sets tethering.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. Its substitute is available only to system applications.

**System API**: This is a system API.

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| value | boolean | Yes   | Whether to set tethering over a Bluetooth PAN.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

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

Obtains the tethering status.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 10. You are advised to use [pan.PanProfile#isTetheringOn](js-apis-bluetooth-pan-sys.md#isTetheringOn) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                 |
| --------------------- | --------------------------------- |
| boolean | Returns **true** if tethering is available over a Bluetooth PAN; return **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;
    panProfile.isTetheringOn();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```
