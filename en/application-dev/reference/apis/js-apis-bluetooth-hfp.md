# @ohos.bluetooth.hfp (Bluetooth hfp Module)

The **hfp** module provides APIs for using the Bluetooth Hands-Free Profile (HFP).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import hfp from '@ohos.bluetooth.hfp';
```


## hfp.createHfpAgProfile<a name="createHfpAgProfile"></a>

createHfpAgProfile(): HandsFreeAudioGatewayProfile

Creates an **HfpAgProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| HandsFreeAudioGatewayProfile | **HfpAgProfile** instance created.|

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let hfpAgProfile = hfp.createHfpAgProfile();
    console.info('hfpAg success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## HandsFreeAudioGatewayProfile

Before using any API of **HandsFreeAudioGatewayProfile**, you need to create an instance of this class by using **createHfpAgProfile()**.


### connect<a name="hfp-connect"></a>

connect(deviceId: string): void

Connects to a hands-free device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

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
    let hfpAg = hfp.createHfpAgProfile();
    hfpAg.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect<a name="hfp-disconnect"></a>

disconnect(deviceId: string): void

Disconnects from a hands-free device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

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
    let hfpAg = hfp.createHfpAgProfile();
    hfpAg.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
