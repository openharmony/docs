# @ohos.bluetooth.baseProfile (Bluetooth baseProfile Module) (System API)

The **baseProfile** module provides APIs for using basic Bluetooth profiles.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.bluetooth.baseProfile (Bluetooth baseProfile Module)](js-apis-bluetooth-baseProfile.md).


## Modules to Import

```js
import { baseProfile } from '@kit.ConnectivityKit';
```


## ConnectionStrategy

Enumerates the profile connection strategies.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                            | Value     | Description           |
| -------------------------------- | ------ | --------------- |
| CONNECTION_STRATEGY_UNSUPPORTED   | 0 | Default connection strategy to use when the device is not paired.<br>This is a system API.|
| CONNECTION_STRATEGY_ALLOWED  | 1 |  Connection strategy to use when the device is allowed to accept or initiate pairing.<br>This is a system API.|
| CONNECTION_STRATEGY_FORBIDDEN  | 2 | Connection strategy to use when the device is not allowed to accept or initiate pairing.<br>This is a system API. |



## baseProfile.setConnectionStrategy

setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback&lt;void&gt;): void

Sets the profile connection strategy for this device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the device to pair, for example, XX:XX:XX:XX:XX:XX. |
| strategy | [ConnectionStrategy](#connectionstrategy)   | Yes   |Profile connection strategy to set.|
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

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
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.setConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError) => {
        console.info('setConnectionStrategy, err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.setConnectionStrategy

setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise&lt;void&gt;

Sets the profile connection strategy for this device. This API uses a promise to return the result. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the device to pair, for example, XX:XX:XX:XX:XX:XX. |
| strategy | [ConnectionStrategy](#connectionstrategy)   | Yes   |Profile connection strategy to set.|

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
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.setConnectionStrategy('XX:XX:XX:XX:XX:XX', 1).then(() => {
        console.info('setConnectionStrategy');
    }, (err: BusinessError) => {
        console.error('setConnectionStrategy errCode: ' + err.code + ', errMessage: ' + err.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.getConnectionStrategy

getConnectionStrategy(deviceId: string, callback: AsyncCallback&lt;ConnectionStrategy&gt;): void

Obtains the profile connection strategy. This API uses an asynchronous callback to return the result. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the device to pair, for example, XX:XX:XX:XX:XX:XX.|
| callback | AsyncCallback&lt;[ConnectionStrategy](#connectionstrategy)&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

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
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.getConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError, data: baseProfile.ConnectionStrategy) => {
        console.info('getConnectionStrategy, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## baseProfile.getConnectionStrategy

getConnectionStrategy(deviceId: string): Promise&lt;ConnectionStrategy&gt;

Obtains the profile connection strategy. This API uses a promise to return the result. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the device to pair, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
|   Promise&lt;[ConnectionStrategy](js-apis-bluetooth-baseProfile-sys.md#connectionstrategy)&gt; | Promise used to return the profile connection strategy obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                  
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |       |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.getConnectionStrategy('XX:XX:XX:XX:XX:XX', 1).then((data: baseProfile.ConnectionStrategy) => {
        console.info('getConnectionStrategy');
    }, (err: BusinessError) => {
        console.error('getConnectionStrategy errCode: ' + err.code + ', errMessage: ' + err.message);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
