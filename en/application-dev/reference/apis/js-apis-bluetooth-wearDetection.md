# @ohos.bluetooth.wearDetection (Bluetooth Wear Detection Module)

The **bluetooth.wearDetection** module provides APIs for checking whether a Bluetooth audio device (such as a Bluetooth earphone) supports wear detection and whether wear detection is enabled, and enabling or disabling wear detection for a device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import wearDetection from '@ohos.bluetooth.wearDetection';
```


## wearDetection.enableWearDetection<sup>11+</sup><a name="enableWearDetection"></a>

enableWearDetection(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Enables wear detection for a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.enableWearDetection('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("enableWearDetection error");
        }
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.enableWearDetection<sup>11+</sup><a name="enableWearDetection"></a>

enableWearDetection(deviceId: string): Promise&lt;void&gt;

Enables wear detection for a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.enableWearDetection('XX:XX:XX:XX:XX:XX').then(() => {
        console.info("enableWearDetection");
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.disableWearDetection<sup>11+</sup><a name="disableWearDetection"></a>

disableWearDetection(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Disables wear detection for a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.disableWearDetection('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("disableWearDetection error");
        }
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.disableWearDetection<sup>11+</sup><a name="disableWearDetection"></a>

disableWearDetection(deviceId: string): Promise&lt;void&gt;

Disables wear detection for a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.disableWearDetection('XX:XX:XX:XX:XX:XX').then(() => {
        console.info("disableWearDetection");
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionSupported<sup>11+</sup><a name="isWearDetectionSupported"></a>

isWearDetectionSupported(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a device supports wear detection. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If the device supports wear detection, **supported** is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.isWearDetectionSupported('XX:XX:XX:XX:XX:XX', (err, supported) => {
        console.info('device support wear detection ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionSupported<sup>11+</sup><a name="isWearDetectionSupported"></a>

isWearDetectionSupported(deviceId: string): Promise&lt;boolean&gt;

Checks whether a device supports wear detection. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the device supports wear detection, **supported** is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.isWearDetectionSupported('XX:XX:XX:XX:XX:XX').then((supported) => {
        console.info('device support wear detection ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionEnabled<sup>11+</sup><a name="isWearDetectionEnabled"></a>

isWearDetectionEnabled(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether wear detection is enabled for a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If wear detection is enabled, **enabled** is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.isWearDetectionEnabled('XX:XX:XX:XX:XX:XX', (err, enabled) => {
        console.info('device enable wear detection ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## wearDetection.isWearDetectionEnabled<sup>11+</sup><a name="isWearDetectionEnabled"></a>

isWearDetectionEnabled(deviceId: string): Promise&lt;boolean&gt;

Checks whether wear detection is enabled for a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If wear detection is enabled, **enabled** is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900099 | Operation failed.              |

**Example**

```js
try {
    wearDetection.isWearDetectionEnabled('XX:XX:XX:XX:XX:XX').then((enabled) => {
        console.info('device enable wear detection ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```
