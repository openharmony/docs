# @ohos.nearlink.ssap (NearLink SSAP Connection Capability)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=6610f64dcfdc39e7239dc52b313502bf3f4a9b0b translatedAt=2026-08-12T11:33:39.653Z pushedAt=2026-08-14T10:53:52.286Z -->

This module provides the SSAP (SparkLink Service Access Protocol) connection capability.

**Model restriction**: This API can be used only in the stage model.

## Modules to Import

```typescript
import { ssap } from '@kit.ConnectivityKit';
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

## ssap.createClient

createClient(address: string): Client

Creates an SSAP client instance.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| address | string | Yes | Address of the remote server device. The address format is **11:22:33:AA:BB:FF**. |

**Return value** 

| Type | Description |
| -------- | -------- |
| [Client](#client) | SSAP client instance. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr);
  console.info('client: ' + JSON.stringify(client));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ssap.createServer

createServer(): Server

Creates an SSAP server instance.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [Server](#server) | SSAP server instance. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let server: ssap.Server;
try {
  server = ssap.createServer();
  console.info('server: ' + JSON.stringify(server));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Client

Provides methods for SSAP data interaction with remote devices. Before use, you need to call the [ssap.createClient](#ssapcreateclient) method to create a [Client](#client) instance.

An app only needs to create one instance per remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

### connect

connect(): Promise&lt;void&gt;

Initiates a connection to the server. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An application needs to create only one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### disconnect

disconnect(): Promise&lt;void&gt;

Initiates a disconnection to the server, disconnecting an existing connection or terminating a connection being established. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An application needs to create only one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success'); // Establish the connection.
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  client.disconnect().then(() => {
    console.info('disconnect success'); // Disconnect.
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### close

close(): void

Closes the client.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try { 
  client = ssap.createClient(addr); // An application needs to create only one instance for a remote device.
  client.close();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getServices

getServices(): Promise&lt;Service[]&gt;

Obtains the list of services supported by the server. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;[Service](#service)[]&gt; | Promise used to return the result. The list of services supported by the server. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An app only needs to create one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // The connection takes a long time. Wait until the connection is complete before obtaining services. Adjust the timer duration based on the actual connection speed.
  setTimeout(() => {
    client.getServices().then((result: ssap.Service[]) => {
      console.info('getServices successfully:' + JSON.stringify(result));
    }).catch ((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### readProperty

readProperty(property: Property): Promise&lt;Property&gt;

Reads a server attribute. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| property | [Property](#property) | Yes | Server attribute. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;[Property](#property)&gt; | Promise used to return the server attribute. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //An app only needs to create one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // Create the property. In actual development, obtain it from the server through the getServices API.
  let arrayBufferC = new ArrayBuffer(8);
  let properV = new Uint8Array(arrayBufferC);
  properV[0] = 1;
  let property: ssap.Property = {
    serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: arrayBufferC
  };
  // The connection takes a long time. Wait until the connection is complete before obtaining services. In actual development, adjust the timer duration based on the connection speed.
  setTimeout(()=>{
    client.readProperty(property).then((result: ssap.Property) => {
      console.info('readProperty successfully:' + JSON.stringify(result));
    }).catch ((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### writeProperty

writeProperty(property: Property, writeType: PropertyWriteType): Promise&lt;void&gt;

Writes the server property value. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| property | [Property](#property) | Yes | Server attribute. |
| writeType | [PropertyWriteType](#propertywritetype) | Yes | Write type, which supports two modes: with and without server response. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //An app only needs to create one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // Create the property. In actual development, obtain it from the server through the getServices API.
  let arrayBufferC = new ArrayBuffer(8);
  // Expected property value to write.
  let properV = new Uint8Array(arrayBufferC);
  properV[0] = 1;
  let property: ssap.Property = {
    serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: arrayBufferC
  };
  // The connection takes a long time. Wait until the connection is complete before obtaining services. In actual development, adjust the timer duration based on the connection speed.
  setTimeout(()=>{
    client.writeProperty(property, ssap.PropertyWriteType.WRITE_NO_RESPONSE).then(() => {
      console.info('writeProperty success');
    }).catch ((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setPropertyNotification

setPropertyNotification(property: Property, enable: boolean): Promise&lt;void&gt;

Sets Property change notification. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| property | [Property](#property) | Yes | Server attribute. |
| enable | boolean | Yes | Whether to enable notification. The value **true** means to enable notification, and **false** means to disable notification. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. No return value. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //An app only needs to create one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  // Create the property. In actual development, obtain it from the server through the getServices API.
  let arrayBufferC = new ArrayBuffer(8);
  let properV = new Uint8Array(arrayBufferC);
  properV[0] = 1;
  let property: ssap.Property = {
    serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: arrayBufferC
  };
  // The connection takes a long time. Wait until the connection is complete before obtaining services. In actual development, adjust the timer duration based on the connection speed.
  setTimeout(()=>{
    client.setPropertyNotification(property, true).then(() => {
      console.info('setPropertyNotification success');
    }).catch ((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### requestMtuSize

requestMtuSize(mtu: number): Promise&lt;void&gt;

Initiates an MTU negotiation request. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| mtu | number | Yes | MTU parameter. Value range: [22, 1024], unit: byte. The default value is **251**. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Code](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //An app only needs to create one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success');
  });
  // The connection takes a long time. Wait until the connection is complete before obtaining services. In actual development, adjust the timer duration based on the connection speed.
  setTimeout(()=>{
    client.requestMtuSize(128).then(() => {
      console.info('requestMtuSize success');
    }).catch ((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onPropertyChange

onPropertyChange(callback: Callback&lt;Property&gt;): void

Subscribes to the Property change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[Property](#property)&gt; | Yes | Callback used to return the Property of the service. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyChange:(data: ssap.Property) => void = (data: ssap.Property) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //An app only needs to create one instance for a remote device.
  client.onPropertyChange(onPropertyChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offPropertyChange

offPropertyChange(callback?: Callback&lt;Property&gt;): void

Unsubscribes from the property change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[Property](#property)&gt; | No | Callback for the property change event, which returns the Property of the service.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyChange:(data: ssap.Property) => void = (data: ssap.Property) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //An app only needs to create one instance for a remote device.
  client.offPropertyChange(onPropertyChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onConnectionStateChange

onConnectionStateChange(callback: Callback&lt;ConnectionChangeState&gt;): void

Subscribes to the connection status change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | Yes | Callback used to return the connection status reporting parameters. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //An app only needs to create one instance for a remote device.
  client.onConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offConnectionStateChange

offConnectionStateChange(callback?: Callback&lt;ConnectionChangeState&gt;): void

Unsubscribes from the connection status change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | No | Callback used to return the connection status reporting parameters.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An app only needs to create one instance for a remote device.
  client.offConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onMtuChange

onMtuChange(callback: Callback&lt;number&gt;): void

Subscribes to the MTU change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | Yes | Callback used to return the MTU after negotiation. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An app only needs to create one instance for a remote device.
  client.onMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offMtuChange

offMtuChange(callback?: Callback&lt;number&gt;): void

Unsubscribes from the MTU change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | No | Callback used to return the MTU after negotiation.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning.
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An app only needs to create one instance for a remote device.
  client.offMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Server

Interacts with a remote device through SSAP. Before using this API, you need to call **createServer** to create a server instance.

An app only needs to create one instance for a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

### addService

addService(service: Service): void

Adds a service on the server.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| service | [Service](#service) | Yes | Service provided by the server. Multiple services can be added, identified by their UUIDs.|

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Construct a descriptor.
let descriptorsArray: ssap.PropertyDescriptor[] = [];
let arrayBuffer = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBuffer);
descValue[0] = 11;
descValue[1] = 22;
let descriptor: ssap.PropertyDescriptor = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBuffer,
  descriptorType: ssap.PropertyDescriptorType.PROPERTY,
  isWriteable: true
};
descriptorsArray[0] = descriptor;
// Construct properties.
let propertiesArray: ssap.Property[] = [];
let arrayBufferProperty = new ArrayBuffer(8);
let properValue = new Uint8Array(arrayBufferProperty);
properValue[0] = 1;
let property1: ssap.Property = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBufferProperty,
  descriptors:descriptorsArray
};
let property2: ssap.Property = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000003421',
  value: arrayBufferProperty,
  descriptors:descriptorsArray,
  operation:12
};
propertiesArray[0] = property1;
propertiesArray[1] = property2;
// Construct a service.
let service: ssap.Service = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  properties:propertiesArray
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.addService(service);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### removeService

removeService(serviceUuid: string): void

Removes a service from the server.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| serviceUuid | string | Yes | NearLink service UUID, which is a string of 36 bytes. The value consists of 36 hexadecimal digits and hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let server: ssap.Server;
try {
  server = ssap.createServer();
  // The service has been added using addService. You can remove a service by specifying its UUID.
  let serviceUuid = 'FFFFFFFF-1234-5678-ABCD-000000004386';
  server.removeService(serviceUuid);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### close

close(): void

Closes the server instance.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.NearLink.Base

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let server: ssap.Server;
try {
  server = ssap.createServer();
  server.close();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### notifyPropertyChanged

notifyPropertyChanged(address: string, property: Property): Promise&lt;void&gt;

Notifies the client of property value updates. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability**: SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| address | string | Yes | Client device address. The address format is **11:22:33:AA:BB:FF**. |
| property | [Property](#property) | Yes | Property whose value changes. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Construct a descriptor.
let descriptorsArray: ssap.PropertyDescriptor[] = [];
let arrayBuffer = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBuffer);
descValue[0] = 11;
descValue[1] = 22;
let descriptor: ssap.PropertyDescriptor = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBuffer,
  descriptorType:ssap.PropertyDescriptorType.PROPERTY,
  isWriteable:true
};
descriptorsArray[0] = descriptor;
// Construct properties.
let arrayBufferProperty = new ArrayBuffer(8);
let properValue = new Uint8Array(arrayBufferProperty);
properValue[0] = 123; // Value after the update
let property: ssap.Property = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000004386',
  propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
  value: arrayBufferProperty,
  descriptors:descriptorsArray
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  // This address is that of the connected client device and is cached on the server.
  server.notifyPropertyChanged('00:11:22:33:AA:FF', property).then(() => {
    console.info('notifyPropertyChanged success');
  }).catch ((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### sendResponse

sendResponse(response: ServerResponse): void

Replies to read or write requests from the client.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| response | [ServerResponse](#serverresponse) | Yes | Response data for the client. |

**Error codes**

For details about the following error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// After receiving a read or write request, use this API to respond to the request.
let arrayBuffer = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBuffer);
descValue[0] = 11;
descValue[1] = 22;
let resp: ssap.ServerResponse = {
  address: '00:11:22:33:AA:FF', // Address of a requester client.
  requestId: 1, // Request ID.
  value: arrayBuffer // Response data.
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  // This address is that of the connected client device and is cached on the server.
  server.sendResponse(resp);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onConnectionStateChange

onConnectionStateChange(callback: Callback&lt;ConnectionChangeState&gt;): void

Subscribes to the connection status change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | Yes | Callback used to return the connection status reporting parameters. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offConnectionStateChange

offConnectionStateChange(callback?: Callback&lt;ConnectionChangeState&gt;): void

Unsubscribes from the connection status change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[ConnectionChangeState](#connectionchangestate)&gt; | No | Callback used to return the connection status reporting parameters.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onConnectionStateChange:(data: ssap.ConnectionChangeState) => void = (data: ssap.ConnectionChangeState) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offConnectionStateChange(onConnectionStateChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onPropertyRead

onPropertyRead(callback: Callback&lt;PropertyReadRequest&gt;): void

Subscribes to the client property read request event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyReadRequest](#propertyreadrequest)&gt; | Yes | Callback used to return the property read request parameters of the client. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyReadRequest:(data: ssap.PropertyReadRequest) => void = (data: ssap.PropertyReadRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onPropertyRead(onPropertyReadRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offPropertyRead

offPropertyRead(callback?: Callback&lt;PropertyReadRequest&gt;): void

Unsubscribes from the client property read request event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyReadRequest](#propertyreadrequest)&gt; | No | Callback used to return the property read request parameters of the client.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyReadRequest:(data: ssap.PropertyReadRequest) => void = (data: ssap.PropertyReadRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offPropertyRead(onPropertyReadRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onPropertyWrite

onPropertyWrite(callback: Callback&lt;PropertyWriteRequest&gt;): void

Subscribes to the client property write request event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyWriteRequest](#propertywriterequest)&gt; | Yes | Callback used to return the property write request parameters of the client. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyWriteRequest:(data: ssap.PropertyWriteRequest) => void = (data: ssap.PropertyWriteRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onPropertyWrite(onPropertyWriteRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offPropertyWrite

offPropertyWrite(callback?: Callback&lt;PropertyWriteRequest&gt;): void

Unsubscribes from the client property write request event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[PropertyWriteRequest](#propertywriterequest)&gt; | No | Callback used to return the property write request parameters of the client. If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onPropertyWriteRequest:(data: ssap.PropertyWriteRequest) => void = (data: ssap.PropertyWriteRequest) => {
  console.info('data:' + JSON.stringify(data));
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offPropertyWrite(onPropertyWriteRequest);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onMtuChange

onMtuChange(callback: Callback&lt;number&gt;): void

Subscribes to the MTU change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | Yes | Callback used to return the MTU after negotiation. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.onMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offMtuChange

offMtuChange(callback?: Callback&lt;number&gt;): void

Unsubscribes from the MTU change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;number&gt; | No | Callback used to return the MTU after negotiation.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the type are unregistered. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onMtuChange:(data: number) => void = (data: number) => {
  console.info('data:' + data);
};
let server: ssap.Server;
try {
  server = ssap.createServer();
  server.offMtuChange(onMtuChange);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Service

Represents the NearLink service.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | No | No | NearLink service UUID, which is a string of 36 bytes. The value consists of 36 hexadecimal digits and hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| properties | [Property](#property)[] | No | No | Properties of a service. |

## Property

Represents a service Property.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | No | No | NearLink service UUID, which is a string of 36 bytes. The value consists of 36 hexadecimal digits and hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| propertyUuid | string | No | No | Property UUID, in the same format as **serviceUuid**. |
| value | ArrayBuffer | No | No | Data value of a property. |
| descriptors | [PropertyDescriptor](#propertydescriptor)[] | No | Yes | Descriptors of the current property. By default, this field is not used if not set. |
| operation | number | No | Yes | Operation modes supported by the property. The default value is **READABLE\|WRITE_NO_RESPONSE**, indicating that the property is readable and writable and no response is required. To enable a property to support an operation, you need to assign a value to this field, for example, **READABLE\|WRITE_NO_RESPONSE\|NOTIFY**. The value range is [0, 15]. For details about the operation corresponding to each bit, please refer to [Operation](#operation). |

## PropertyDescriptor

Defines the descriptor of a property.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | No | No | NearLink service UUID. The length must be 36 bytes. The value consists of 36 hexadecimal digits and hyphens (-), for example, FFFFFFFF-1234-5678-ABCD-000000001234, representing a 128-bit identifier. Standard NearLink UUIDs are not allowed. |
| propertyUuid | string | No | No | UUID of the property. The data format is the same as that of serviceUuid. |
| value | ArrayBuffer | No | No | Data value of the descriptor. |
| descriptorType | [PropertyDescriptorType](#propertydescriptortype) | No | No | Descriptor type of the property. |
| isWriteable | boolean | No | Yes | Whether the descriptor is writable. The value true means writable, and false means not writable. The default value is true. |

## PropertyReadRequest

Represents the Property read request parameter of the client.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Client device address. The address format is **11:22:33:AA:BB:FF**. |
| serviceUuid | string | No | No | NearLink service UUID. The length must be 36 bytes. The value consists of 36 hexadecimal digits and hyphens (-), for example, FFFFFFFF-1234-5678-ABCD-000000001234, representing a 128-bit identifier. NearLink standard UUIDs are not allowed. |
| propertyUuid | string | No | No | UUID of the property. The data format is the same as that of serviceUuid. |
| requestId | number | No | No | Request ID. Value range: [0, 65535]. |

## PropertyWriteRequest

Define a client property write request.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Client device address. The address format is **11:22:33:AA:BB:FF**. |
| serviceUuid | string | No | No | NearLink service UUID, which is a string of 36 bytes. The value consists of 36 hexadecimal digits and hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| propertyUuid | string | No | No | Property UUID, in the same format as **serviceUuid**. |
| value | ArrayBuffer | No | No | Value written by the client. |
| requestId | number | No | No | Write request ID of the client. This ID must be carried in the response returned by the server. The value range is [0, 65535]. |
| writeType | [PropertyWriteType](#propertywritetype) | No | No | Property write type of the client. |

## ServerResponse

Defines a response to a client request.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Client device address. The address format is **11:22:33:AA:BB:FF**. |
| requestId | number | No | No | Request ID. The value range is [0, 65535]. |
| value | ArrayBuffer | No | No | Data value of the response. |

## ConnectionChangeState

Defines the connection status reporting parameters.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Remote device address. The address format is **11:22:33:AA:BB:FF**. |
| state | [ConnectionState](js-apis-nearlink-constant.md#connectionstate) | No | No | Connection status with a remote device. |

## PropertyDescriptorType

Enumerates the property descriptor types.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| PROPERTY | 1 | Property. |
| CLIENT_PROPERTY_CONFIG | 2 | Property configuration on the client. |
| SERVER_PROPERTY_CONFIG | 3 | Property configuration on the server. |
| PROPERTY_FORMAT | 4 | Property format. |
| TYPE_VENDOR | 255 | Vendor-defined field. |

## Operation

Enumerates the operation types supported by a property.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| READABLE | 0x01 | Data is readable. |
| WRITE_NO_RESPONSE | 0x02 | Write requests without responses are supported. |
| WRITE_WITH_RESPONSE | 0x04 | Write requests with responses are supported. |
| NOTIFY | 0x08 | Notifications are supported. |

## PropertyWriteType

Enumerates the write types supported by a property.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| WRITE | 1 | Property write request that requires a response from the server. |
| WRITE_NO_RESPONSE | 2 | Property write request that does not require a response from the server. |