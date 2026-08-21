# @ohos.nearlink.remoteDevice (NearLink Remote Device Connection Capability) (System API)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=1f7ebf6194dca265f1a8eeefc330905f60a6cb97 translatedAt=2026-08-17T08:48:30.948Z pushedAt=2026-08-18T12:08:21.250Z -->

This module provides the capabilities of connecting to and managing NearLink remote devices, including connecting to and disconnecting from remote devices, pairing with a trusted device and confirmation, adjusting the connection interval, and subscribing to pairing requests.

**Since**: 26.0.0

> **NOTE**
>
> The APIs provided by this module are system APIs.

## Modules to Import

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
```

## ConnectionInterval

type ConnectionInterval = nearlinkConstant.ConnectionInterval

Enumerates the connection intervals.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Type | Description |
| -------- | -------- |
| [nearlinkConstant.ConnectionInterval](js-apis-nearlink-constant-sys.md#connectioninterval) | Connection interval. |

## DeviceModel

Describes the model of a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| modelId | string | No | No | Model ID of the remote device. |
| subModelId | string | No | No | Sub-model ID of the remote device. |
| iconId | string | No | No | Icon ID of the remote device. |

## RemoteDevice

Provides the method for operating on a remote device. Before using this method, you need to call [remoteDevice.createRemoteDevice](js-apis-nearlink-remote-device.md#remotedevicecreateremotedevice) to create a [RemoteDevice](js-apis-nearlink-remote-device.md#remotedevice) instance. You need to create only one instance for a device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

### startCrediblePairing

startCrediblePairing(): Promise&lt;void&gt;

Initiates pairing with a trusted remote device without a dialog box. This API uses a promise to return the result.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.startCrediblePairing().then(() => {
    console.info('start pairing success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### removePairedDevice

removePairedDevice(): Promise&lt;void&gt;

Removes a paired device. This API uses a promise to return the result.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.removePairedDevice().then(() => {
    console.info('remove paired device success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setPairingConfirmation

setPairingConfirmation(accept: boolean): void

Sets the pairing confirmation. You can obtain the pairing request of the peer device using [remoteDevice.onPairingRequest](#remotedeviceonpairingrequest).

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| accept | boolean | Yes | Pairing confirmation. **true**: Accept the pairing. **false**: Reject the pairing. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.setPairingConfirmation(true);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### connect

connect(): Promise&lt;void&gt;

Initiates a connection request to a remote device. This API uses a promise to return the result.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.connect().then(() => {
    console.info('connect success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### disconnect

disconnect(): Promise&lt;void&gt;

Disconnects from the remote device. This API uses a promise to return the result.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = '11:22:33:44:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.disconnect().then(() => {
    console.info('disconnect success');
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setDeviceAlias

setDeviceAlias(alias: string): void

Sets the alias of a remote device.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| alias | string | Yes | Alias of the remote device. The value can contain a maximum of 64 characters and cannot be empty. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100046 | String exceeds maximum length. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

let addr: string = '11:22:33:44:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
try {
  let alias: string = 'test';
  device.setDeviceAlias(alias);
  console.info('set alias success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getDeviceAlias

getDeviceAlias(): string

Obtains the alias of a remote device.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| string | Alias of the remote device. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

let addr: string = '11:22:33:44:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
try {
  let alias: string = 'test';
  device.setDeviceAlias(alias);
  let ret: string = device.getDeviceAlias();
  console.info('get alias success, ret:' + ret);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getDeviceModel

getDeviceModel(): DeviceModel

Obtains the model of a remote device.

**Since**: 26.0.0

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| [DeviceModel](#devicemodel) | Model of the remote device. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  let model: remoteDevice.DeviceModel = device.getDeviceModel();
  console.info('modelId:' + JSON.stringify(model.modelId));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### cancelDevicePairing

cancelDevicePairing(): Promise&lt;void&gt;

Cancels the ongoing pairing request. This API uses a promise to return the result.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.cancelDevicePairing().then(() => {
    console.info('cancelDevicePairing success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setPairingPasscode

setPairingPasscode(passcode: string): Promise&lt;void&gt;

Sets the pairing passcode. This API uses a promise to return the result.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| passcode | string | Yes | Pairing passcode entered by the user, which must be a six-digit number. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100045 | Passcode must be a 6-digit number. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let passcode: string = '123456';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.setPairingPasscode(passcode).then(() => {
    console.info('setPairingPasscode success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getRssiValue

getRssiValue(): Promise&lt;number&gt;

Obtains the received signal strength indicator (RSSI) of a remote device. This API uses a promise to return the result.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the RSSI value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  device.getRssiValue().then((rssi: number) => {
    console.info('getRssiValue: ' + rssi);
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setConnectionInterval

setConnectionInterval(interval: ConnectionInterval): void

Sets the interval for connecting to a remote device.

**Since**: 26.0.0

**System API:** This is a system API.

**Required permissions:** ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| interval | [ConnectionInterval](#connectioninterval) | Yes | Connection interval to be set. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice, nearlinkConstant } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let addr: string = '00:11:22:33:AA:FF';
  let device: remoteDevice.RemoteDevice = remoteDevice.createRemoteDevice(addr);
  let interval: nearlinkConstant.ConnectionInterval = nearlinkConstant.ConnectionInterval.HIGH_SPEED_INTERVAL_4_5;
  device.setConnectionInterval(interval);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### remoteDevice.onPairingRequest

onPairingRequest(callback: Callback&lt;PairingRequestParam&gt;): void

Subscribes to the pairing request event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

By default, a random address is returned for the event. If the app has the system permission **ohos.permission.GET_NEARLINK_PEER_MAC**, the actual device address is returned.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingRequestParam](js-apis-nearlink-remote-device.md#pairingrequestparam)&gt; | Yes | Callback used to return the pairing request field. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@ohos.base';

let callback: Callback<remoteDevice.PairingRequestParam> = (data: remoteDevice.PairingRequestParam) => {
  console.info('pairing request param: ' + JSON.stringify(data));
};

try {
  remoteDevice.onPairingRequest(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### remoteDevice.offPairingRequest

offPairingRequest(callback?: Callback&lt;PairingRequestParam&gt;): void

Unsubscribes from the pairing request event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingRequestParam](js-apis-nearlink-remote-device.md#pairingrequestparam)&gt; | No | Callback used to return the pairing request field.<br>If this parameter is specified, the subscription of the current callback is canceled. If this parameter is not specified, all callbacks corresponding to this event are canceled. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  remoteDevice.offPairingRequest();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```