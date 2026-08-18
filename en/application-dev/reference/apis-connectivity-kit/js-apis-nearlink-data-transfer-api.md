# @ohos.nearlink.dataTransfer (NearLink Data Transfer Capability)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=aa9545020692baaf11004432a3eb3c2a031071bf translatedAt=2026-08-17T08:51:26.076Z pushedAt=2026-08-18T11:58:05.422Z -->

This module provides the NearLink data transfer capability, including port channel management, connection management, data sending and receiving, and connection status query and subscription.

**Since**: 26.0.0

## Modules to Import

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
```

## ConnectionState

type ConnectionState = nearlinkConstant.ConnectionState

Enumerates the connection states with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Type | Description |
| -------- | -------- |
| [nearlinkConstant.ConnectionState](js-apis-nearlink-constant.md#connectionstate) | Connection state with a remote device. |

## dataTransfer.createPort

createPort(uuid: string): void

Registers a port channel. A port channel can be used to connect to a remote device only after being registered. If the port channel is no longer needed after use, call [dataTransfer.destroyPort](#datatransferdestroyport) to destroy it.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uuid | string | Yes | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100020 | The UUID is already registered. |
| 36100021 | Port exceeds the upper limit. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let uuid: string = 'FFFFFFFF-FC70-11EA-B720-000078951234'; // NearLink service UUID
  dataTransfer.createPort(uuid);
  console.info('create port success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.destroyPort

destroyPort(uuid: string): void

Destroys the port channel.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| uuid | string | Yes | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100022 | The UUID is not registered. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let uuid: string = 'FFFFFFFF-FC70-11EA-B720-000078951234'; // NearLink service UUID
  dataTransfer.destroyPort(uuid);
  console.info('destroy port success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.connect

connect(params: ConnectionParams): Promise&lt;void&gt;

Connects to a remote device. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| params | [ConnectionParams](#connectionparams) | Yes | Connection parameters of the port. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Construct connection parameters.
  let connectionParams:dataTransfer.ConnectionParams = {
    address: '01:02:03:04:05:06', // NearLink remote device address, which can be obtained by scanning.
    uuid: 'FFFFFFFF-1234-5678-ABCD-000000001234', // NearLink service UUID
  };
  dataTransfer.connect(connectionParams).then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.disconnect

disconnect(params: ConnectionParams): Promise&lt;void&gt;

Disconnects from the remote device. This method is called to disconnect from the remote device after it is successfully connected using [dataTransfer.connect](#datatransferconnect). This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| params | [ConnectionParams](#connectionparams) | Yes | Connection parameters of the port. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Construct connection parameters to specify the connection to be disconnected.
  let connectionParams:dataTransfer.ConnectionParams = {
    address: '01:02:03:04:05:06', // Address of the remote NearLink device, which can be obtained through scanning.
    uuid: 'FFFFFFFF-1234-5678-ABCD-000000001234', // NearLink service UUID
  };
  dataTransfer.disconnect(connectionParams).then(() => {
    console.info('disconnect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.onConnectionStateChanged

onConnectionStateChanged(callback: Callback&lt;ConnectionResult&gt;): void

Subscribes to the connection state change event of the port channel. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionResult](#connectionresult)&gt; | Yes | Callback used to return the negotiation result of port connection parameters with a remote device. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<dataTransfer.ConnectionResult> = (data: dataTransfer.ConnectionResult) => {
  console.info('data: ' + JSON.stringify(data));
};
try {
  dataTransfer.onConnectionStateChanged(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.offConnectionStateChanged

offConnectionStateChanged(callback?: Callback&lt;ConnectionResult&gt;): void

Unsubscribes from the connection state change event of the port channel. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionResult](#connectionresult)&gt; | No | Callback used to return the result of port connection parameter negotiation with a remote device.<br>If this parameter is set, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the event are unregistered. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dataTransfer.offConnectionStateChanged();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.getConnectionState

getConnectionState(params: ConnectionStateParams): ConnectionState

Obtains the port channel connection state with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| params | [ConnectionStateParams](#connectionstateparams) | Yes | Connection parameters of the port. |

**Return value** 

| Type | Description |
| -------- | -------- |
| [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | NearLink port channel connection state with a remote device. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID in connection parameters. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let connectionStateParams:dataTransfer.ConnectionStateParams = {
    address: '01:02:03:04:05:06', // Address of the remote device obtained through scanning
    uuid: 'FFFFFFFF-FC70-11EA-B720-000078951234' // NearLink service UUID
  };
  let state:dataTransfer.ConnectionState = dataTransfer.getConnectionState(connectionStateParams);
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.writeData

writeData(params: DataParams): Promise&lt;void&gt;

Sends data to a remote device using the device address and UUID. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| params | [DataParams](#dataparams) | Yes | Parameters for sending data, including the remote device address, service UUID, and data packet to send. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100023 | Write data congestion. |
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Construct the parameters for sending data.
  let transferValueBuffer: Uint8Array = new Uint8Array(4);
  transferValueBuffer[0] = 1;
  transferValueBuffer[1] = 2;
  transferValueBuffer[2] = 3;
  transferValueBuffer[3] = 4;
  let dataParams: dataTransfer.DataParams = {
    address: '01:02:03:04:05:06', // Address of the remote NearLink device
    uuid: 'FFFFFFFF-1234-5678-ABCD-000000001234', //  NearLink service UUID
    data: transferValueBuffer.buffer // Data to be transferred between NearLink devices
  };
  dataTransfer.writeData(dataParams).then(() => {
    console.info('writeData success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.onReadData

onReadData(callback: Callback&lt;DataParams&gt;): void

Subscribes to the port channel data receiving event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[DataParams](#dataparams)&gt; | Yes | Callback used to return the parameters for data received by the port channel. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<dataTransfer.DataParams> = (data: dataTransfer.DataParams) => {
  console.info('data: ' + JSON.stringify(data));
};
try {
  dataTransfer.onReadData(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## dataTransfer.offReadData

offReadData(callback?: Callback&lt;DataParams&gt;): void

Unsubscribes from the port channel data receiving event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[DataParams](#dataparams)&gt; | No | Callback used to return the parameters for data received by the port channel.<br>If this parameter is set, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the event are unregistered. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { dataTransfer } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dataTransfer.offReadData();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ConnectionParams

Defines the parameters for initiating a port connection.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | NearLink address of a remote device. The address format is **11:22:33:AA:BB:FF**. |
| uuid | string | No | No | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| transferMode | [TransferMode](#transfermode) | No | Yes | Data transfer mode with a remote device. The default value is **BASIC**. |

## DataParams

Defines the parameters for port data sending and receiving.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | NearLink address of a remote device. The address format is **11:22:33:AA:BB:FF**. |
| uuid | string | No | No | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| data | ArrayBuffer | No | No | Data packet. When this parameter is used in [dataTransfer.writeData](#datatransferwritedata), it indicates the data to be sent. When the parameter is used in [dataTransfer.onReadData](#datatransferonreaddata), it indicates the received data. |

## ConnectionResult

Represents the result of port connection parameter negotiation with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | NearLink address of a remote device. The address format is **11:22:33:AA:BB:FF**. |
| uuid | string | No | No | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| mtu | number | No | No | Negotiated packet size of data to be sent and received, in bytes. The value range is [0, 65535]. |
| state | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | No | No | Connection state with a remote device. |

## ConnectionStateParams

Defines the parameters for obtaining the port channel connection state.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | NearLink address of a remote device. The address format is **11:22:33:AA:BB:FF**. |
| uuid | string | No | No | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |

## TransferMode

Enumerates the data transfer modes with a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| BASIC | 0 | Basic mode, without a data retransfer mechanism. This mode is applicable to services sensitive to latency and throughput. |
| RELIABLE | 1 | Reliable mode, with a data retransfer mechanism. This mode is applicable to services that require high data integrity. |