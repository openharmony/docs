# @ohos.nearlink.remoteDevice (Capability to Connect to a Remote Device)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=41ecf77f71c02d2e6f9cd090506d7778236a93de translatedAt=2026-08-12T11:31:43.373Z pushedAt=2026-08-14T06:51:58.072Z -->

This module provides functions such as querying remote device information and initiating pairing.

**System capability:** SystemCapability.Communication.NearLink.Base

**Since**: 26.0.0

## Modules to Import

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
```

## PairingState

type PairingState = nearlinkConstant.PairingState

Enumerates the pairing statuss with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Type | Description |
| -------- | -------- |
| [nearlinkConstant.PairingState](js-apis-nearlink-constant.md#pairingstate) | Pairing status with a remote device. |

## ConnectionState

type ConnectionState = nearlinkConstant.ConnectionState

Enumerates the connection states with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Type | Description |
| -------- | -------- |
| [nearlinkConstant.ConnectionState](js-apis-nearlink-constant.md#connectionstate) | Connection state with a remote device. |

## DeviceClass

type DeviceClass = nearlinkConstant.DeviceClass

Enumerates the device types.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Type | Description |
| -------- | -------- |
| [nearlinkConstant.DeviceClass](js-apis-nearlink-constant.md#deviceclass) | Device type. |

## AcbState

type AcbState = nearlinkConstant.AcbState

Enumerates the logical link connection states with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Type | Description |
| -------- | -------- |
| [nearlinkConstant.AcbState](js-apis-nearlink-constant.md#acbstate) | Logical link connection state with a remote device. |

## remoteDevice.createRemoteDevice

createRemoteDevice(address: string): RemoteDevice

Creates a **RemoteDevice** instance.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| address | string | Yes | Address of a remote device. The address format is **11:22:33:AA:BB:FF**. |

**Return value** 

| Type | Description |
| -------- | -------- |
| [RemoteDevice](#remotedevice) | **RemoteDevice** instance. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100041 | Invalid address. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  console.info('device: ' + JSON.stringify(device));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.onPairingStateChange

onPairingStateChange(callback: Callback&lt;PairingStateParam&gt;): void

Subscribes to the pairing request event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingStateParam](#pairingstateparam)&gt; | Yes | Callback used to return the result of the pairing status change event. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPairingStateEvent:(data: manager.PairingStateParam) => void = (data: manager.PairingStateParam) => {
  console.info('onPairingStateChange addr: ' + data.address + 'state:' + data.state);
};
try {
  manager.onPairingStateChange(onPairingStateEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.offPairingStateChange

offPairingStateChange(callback?: Callback&lt;PairingStateParam&gt;): void

Unsubscribes from the pairing request event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PairingStateParam](#pairingstateparam)&gt; | No | Callback used to return the result of the pairing status change event.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offPairingStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.onConnectionStateChange

onConnectionStateChange(callback: Callback&lt;ConnectionStateParam&gt;): void

Subscribes to the connection status change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionStateParam](#connectionstateparam)&gt; | Yes | Callback used to return the result of the connection status change event. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<manager.ConnectionStateParam> = (data: manager.ConnectionStateParam) => {
  console.info('data:' + JSON.stringify(data));
};
try {
  manager.onConnectionStateChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.offConnectionStateChange

offConnectionStateChange(callback?: Callback&lt;ConnectionStateParam&gt;): void

Unsubscribes from the connection status change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionStateParam](#connectionstateparam)&gt; | No | Callback used to return the result of the connection status change event.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offConnectionStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.onAcbStateChange

onAcbStateChange(callback: Callback&lt;AcbStateParam&gt;): void

Subscribes to the logical link connection status change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AcbStateParam](#acbstateparam)&gt; | Yes | Callback used to return the result of the logical link connection status change event. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<manager.AcbStateParam> = (data: manager.AcbStateParam) => {
  console.info('data:' + JSON.stringify(data));
};
try {
  manager.onAcbStateChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## remoteDevice.offAcbStateChange

offAcbStateChange(callback?: Callback&lt;AcbStateParam&gt;): void

Unsubscribes from the logical link connection status change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AcbStateParam](#acbstateparam)&gt; | No | Callback used to return the result of the logical link connection status change event.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offAcbStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## RemoteDevice

Provides the method for operating on a remote device. Before using this method, you need to use the [remoteDevice.createRemoteDevice](#remotedevicecreateremotedevice) method to create a [RemoteDevice](#remotedevice) instance.

You need to create only one instance for a device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

### startPairing

startPairing(): Promise&lt;void&gt;

Initiates pairing with a remote device. This API uses a promise to return the result. After the pairing is initiated, different types of dialog boxes will be displayed based on the input and output capability flags of both the local and remote devices. The user will need to confirm the pairing.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

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
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  device.startPairing().then(()=>{
    console.info('start pairing success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getPairingState

getPairingState(): PairingState

Obtains the pairing status with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [PairingState](js-apis-nearlink-constant.md#pairingstate) | Pairing status with a remote device. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let state: remoteDevice.PairingState = device.getPairingState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getDeviceName

getDeviceName(): string

Obtains the name of a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| string | Remote device name. The value contains a maximum of 30 characters. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let name: string = device.getDeviceName();
  console.info('name:' + JSON.stringify(name));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getDeviceClass

getDeviceClass(): DeviceClass

Obtains the type of a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [DeviceClass](js-apis-nearlink-constant.md#deviceclass) | Remote device type. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let type: remoteDevice.DeviceClass = device.getDeviceClass();
  console.info('type:' + JSON.stringify(type));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getConnectionState

getConnectionState(): ConnectionState

Obtains the connection status between the local and remote devices.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | Connection status between the local and remote devices. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let state: remoteDevice.ConnectionState = device.getConnectionState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getAcbState

getAcbState(): AcbState

Obtains the logical link connection status with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [AcbState](js-apis-nearlink-constant.md#acbstate) | Logical link connection state with a remote device. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let state: remoteDevice.AcbState = device.getAcbState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getDeviceInformation

getDeviceInformation(): DeviceInformation

Obtains the information of a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [DeviceInformation](#deviceinformation) | Information of a remote device. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { remoteDevice } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let device: remoteDevice.RemoteDevice;
try {
  device = remoteDevice.createRemoteDevice(addr);
  let deviceInfo: remoteDevice.DeviceInformation = device.getDeviceInformation();
  console.info('deviceInfo.manufacturerData:' + buffer.from(deviceInfo.manufacturerData, 'binary').toString('hex'));
  console.info('deviceInfo.modelData:' + buffer.from(deviceInfo.modelData, 'binary').toString('hex'));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### DeviceInformation

Represents the remote device information.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| manufacturerData | string | No | No | Manufacturer information. |
| modelData | string | No | No | Device model. |

### ConnectionStateParam

Represents the result of the connection status change event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Device address, indicating that the connection status with this device has changed. The address format is **11:22:33:AA:BB:FF**. |
| preState | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | No | No | Connection status before this report. |
| state | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | No | No | Current connection status. |
| connectionReason | [ConnectionReason](#connectionreason) | No | No | Reason value. |
| reasonMsg | string | No | Yes | Reason details. This field is used only for log information and is not used for logic processing. |

### ConnectionReason

Enumerates the reason values of the NearLink connection status change result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| CONNECTION_SUCCESS | 0 | The connection is successful. |
| CONNECTION_FAILURE | 1 | Connection failed. |
| CONNECTION_LOCAL_DISCONNECT | 2 | The local device proactively disconnects. |
| CONNECTION_REMOTE_DISCONNECT | 3 | The remote device proactively disconnects. |
| CONNECTION_FAIL_ACB_CONNECTION | 4 | ACB connection failed. The reason can be the remote device is powered off or the device is too far away. |
| CONNECTION_FAIL_SERVICE_DISCOVERY | 5 | Service discovery failed (possibly due to a timeout). |
| CONNECTION_FAIL_NO_AVAILABLE_SERVICE | 6 | No connectable/available profile. |
| CONNECTION_FAIL_CONNECTION_NUM_LIMITED | 7 | The number of connections exceeds the limit. |

### PairingStateParam

Represents the result of the pairing status change event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Device address, indicating that the pairing status with this device has changed. The address format is **11:22:33:AA:BB:FF**. |
| preState | [PairingState](js-apis-nearlink-constant.md#pairingstate) | No | No | Pairing status before this report. |
| state | [PairingState](js-apis-nearlink-constant.md#pairingstate) | No | No | Current pairing status. |
| reason | [PairingReason](#pairingreason) | No | No | Reason value. |
| reasonMsg | string | No | Yes | Reason details. This field is used only for log information and is not used for logic processing. |

### PairingRequestParam

Represents the result of the pairing request event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Device address, indicating that the pairing request from the device is received. The address format is **11:22:33:AA:BB:FF**. |
| passkey | string | No | No | Pairing code for interaction, which is displayed to the user for confirmation. The value is a string of six digits. |
| pairingType | [PairingType](#pairingtype) | No | No | Pairing type. |

### PairingReason

Enumerates the reason values of the NearLink pairing status change result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| PAIRING_REASON_SUCCESS | 0 | Pairing is successful. |
| PAIRING_REASON_FAILURE | 1 | Pairing failed. |
| PAIRING_REASON_ACB_CONNECTION_FAIL | 2 | ACB connection failed. The possible cause is the remote device is powered off or out of range. |
| PAIRING_REASON_EXCEED_ACB_MAX | 3 | Pairing failed because the number of connected devices has reached the upper limit. |
| PAIRING_REASON_REMOTE_CANCELED | 4 | Pairing failed because the remote device cancels the pairing. |
| PAIRING_REASON_LOCAL_CANCELED | 5 | Pairing failed because the local device cancels the pairing. |
| PAIRING_REASON_AUTH_FAIL | 6 | Authentication failed. |

## PairingType

Enumerates the NearLink pairing types.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| NO_PASSKEY_CONFIRMATION | 0 | Pairing type that does not require a passkey. Users do not need to check the pairing code. |
| PAIRING_TYPE_PASSCODE | 1 | Pairing type with passcode authentication. Users need to enter the pairing code displayed on one device into the other device. |
| PAIRING_TYPE_NUMBER_COMPARE | 2 | Pairing type with authentication based on digit comparison. Users must ensure that the pairing codes on both devices are the same. |

## AcbStateParam

Represents the result of the logical link connection status change event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Device address, indicating that the logical link connection status with the device changes. The address format is **11:22:33:AA:BB:FF**. |
| state | [AcbState](js-apis-nearlink-constant.md#acbstate) | No | No | Current logical link connection status. |