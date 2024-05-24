# @ohos.bluetooth.a2dp (Bluetooth A2DP Module) (System API)

The **a2dp** module provides APIs for using the Bluetooth Advanced Audio Distribution Profile (A2DP), which defines how to stream high quality audio from one device to another over a Bluetooth connection.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.bluetooth.a2dp (Bluetooth A2DP Module)](js-apis-bluetooth-a2dp.md).


## Modules to Import

```js
import a2dp from '@ohos.bluetooth.a2dp';
```


### connect

connect(deviceId: string): void

Connects to an A2DP device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the device to connect. |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900004 | Profile is not supported.      |
|2900099 | Operation failed.              |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect

disconnect(deviceId: string): void

Disconnects from an A2DP device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the device to disconnect. |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### isAbsoluteVolumeSupported<sup>11+</sup>

isAbsoluteVolumeSupported(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a device supports the absolute volume capability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the device to check. |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the device supports absolute volume, **supported** is returned.|


**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeSupported('XX:XX:XX:XX:XX:XX', (err, supported) => {
        console.info('device support absolute volume ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### isAbsoluteVolumeSupported<sup>11+</sup>

isAbsoluteVolumeSupported(deviceId: string): Promise&lt;boolean&gt;

Checks whether a device supports the absolute volume capability. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the device to check. |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the device supports absolute volume, **supported** is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeSupported('XX:XX:XX:XX:XX:XX').then((supported) => {
        console.info('device support absolute volume ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### isAbsoluteVolumeEnabled<sup>11+</sup>

isAbsoluteVolumeEnabled(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the absolute volume capability is enabled for a device. This API uses an asynchronous callback to return the result. Before using this API, use [isAbsoluteVolumeSupported](#isabsolutevolumesupported11) to check whether the device supports the absolute volume capability.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the device to check. |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If absolute volume is enabled, **enabled** is returned.|


**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeEnabled('XX:XX:XX:XX:XX:XX', (err, enabled) => {
        console.info('device absolute volume enable ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### isAbsoluteVolumeEnabled<sup>11+</sup>

isAbsoluteVolumeEnabled(deviceId: string): Promise&lt;boolean&gt;

Checks whether the absolute volume capability is enabled for a device. This API uses a promise to return the result. Before using this API, use [isAbsoluteVolumeSupported](#isabsolutevolumesupported11) to check whether the device supports the absolute volume capability.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the device to check. |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If absolute volume is enabled, **enabled** is returned.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeEnabled('XX:XX:XX:XX:XX:XX').then((enabled) => {
        console.info('device absolute volume enable ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### enableAbsoluteVolume<sup>11+</sup>

enableAbsoluteVolume(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Enables the absolute volume capability for a device. This API uses an asynchronous callback to return the result. Before using this API, use [isAbsoluteVolumeSupported](#isabsolutevolumesupported11) to check whether the device supports the absolute volume capability.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the target device. |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|


**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.enableAbsoluteVolume('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("enableAbsoluteVolume error");
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### enableAbsoluteVolume<sup>11+</sup>

enableAbsoluteVolume(deviceId: string): Promise&lt;void&gt;

Enables the absolute volume capability for a device. This API uses a promise to return the result. Before using this API, use [isAbsoluteVolumeSupported](#isabsolutevolumesupported11) to check whether the device supports the absolute volume capability.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the target device. |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.enableAbsoluteVolume('XX:XX:XX:XX:XX:XX').then(() => {
            console.info("enableAbsoluteVolume");
        }
    );
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### disableAbsoluteVolume<sup>11+</sup>

disableAbsoluteVolume(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

Disables the absolute volume capability for a device. This API uses an asynchronous callback to return the result. Before using this API, use [isAbsoluteVolumeSupported](#isabsolutevolumesupported11) to check whether the device supports the absolute volume capability.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the target device. |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|


**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.disableAbsoluteVolume('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("disableAbsoluteVolume error");
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### disableAbsoluteVolume<sup>11+</sup>

disableAbsoluteVolume(deviceId: string): Promise&lt;void&gt;

Disables the absolute volume capability for a device. This API uses a promise to return the result. Before using this API, use [isAbsoluteVolumeSupported](#isabsolutevolumesupported11) to check whether the device supports the absolute volume capability.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the target device. |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.disableAbsoluteVolume('XX:XX:XX:XX:XX:XX').then(() => {
        console.info("disableAbsoluteVolume");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getCurrentCodecInfo<sup>11+</sup>

getCurrentCodecInfo(deviceId: string): CodecInfo

Obtains the current codec information.

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
| [CodecInfo](js-apis-bluetooth-a2dp#codecinfo11)| Codec information obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let codecInfo : a2dp.CodecInfo = a2dpSrc.getCurrentCodecInfo('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setCurrentCodecInfo<sup>11+</sup>

setCurrentCodecInfo(deviceId: string, codecInfo: CodecInfo): void

Sets the current codec information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|
| codecInfo | [CodecInfo](js-apis-bluetooth-a2dp.md#codecinfo11) | Yes   | Codec information to set.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let codecInfo : a2dp.CodecInfo = {
        codecType: 0,
        codecBitsPerSample: 1,
        codecChannelMode: 2,
        codecSampleRate: 1,
    }
    a2dpSrc.setCurrentCodecInfo('XX:XX:XX:XX:XX:XX', codecInfo);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
