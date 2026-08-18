# @ohos.nearlink.ssap (NearLink SSAP Connection Capability) (System API)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=1ea30971dd72430fd05350c54203dfeca06c3f03 translatedAt=2026-08-17T08:48:26.851Z pushedAt=2026-08-18T02:12:39.160Z -->

This module provides the SparkLink Service Access Protocol (SSAP) connection capability, including creating and connecting to a client, calling server methods, reading and writing descriptors, and subscribing to event notifications.

**Since**: 26.0.0

> **NOTE**
>
> The APIs provided by this module are system APIs.

## Modules to Import

```typescript
import { ssap } from '@kit.ConnectivityKit';
```

## Client

Represents a SSAP client class. It provides APIs for connecting to and transmitting data with the server.

Before using the methods of this class, use the [ssap.createClient](js-apis-nearlink-ssap.md#ssapcreateclient) method to construct an instance of this class.

An app only needs to create only one [Client](#client) instance for a remote device. Repeated creation will increase unnecessary resource overhead.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

### setPropertyIndication

setPropertyIndication(property: Property, enable: boolean): Promise&lt;void&gt;

Enables or disables indication for property value change. When the property value changes, the server proactively sends a notification to the client. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| property | [Property](js-apis-nearlink-ssap.md#property) | Yes | Property from the server. |
| enable | boolean | Yes | Whether to enable indication for property value changes. **true**: enables indication. **false**: disables indication. |

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
| 36100030 | The connection is not established. |
| 36100043 | Invalid UUID in property. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  let arrayBufferProperty = new ArrayBuffer(1);
  let propertyValue = new Uint8Array(arrayBufferProperty);
  propertyValue[0] = 1;
  let property: ssap.Property = {
    serviceUuid: 'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: arrayBufferProperty
  };
  client = ssap.createClient(addr); // An app only needs to create one instance for a remote device.
  client.setPropertyIndication(property, true).then(() => {
    console.info('setPropertyIndication successfully');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### callMethod

callMethod(method: Method): Promise&lt;Method&gt;

Describes the method for calling the server. For example, in a device control scenario, the client can call the configuration method provided by the server to remotely set device parameters or trigger specific operations. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| method | [Method](#method) | Yes | Method for calling the server. The value must correspond to the method in the service on a remote device obtained during service discovery. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;[Method](#method)&gt; | Promise used to return the **Method** object corresponding to the calling result. The **result** field is the return value after the server method is executed. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID. |
| 36100044 | NearLink standard UUID not allowed. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr); //  An app only needs to create one instance for a remote device.
  client.connect().then(() => {
    console.info('connect success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  let valueBuffer = new ArrayBuffer(8);
  let method: ssap.Method = { // This method must be the same as that in the service on a remote device during service discovery.
    serviceUuid: 'FFFFFFFF-1234-5678-ABCD-000000004386',
    methodUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    parameter: valueBuffer
  };
  // The connection takes a long time, and the service can only be accessed once the connection is set up. You can adjust the timer length based on the connection speed.
  setTimeout(() => {
    client.callMethod(method).then((result: ssap.Method) => {
      console.info('callMethod successfully: ' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### readDescriptor

readDescriptor(descriptor: PropertyDescriptor): Promise&lt;PropertyDescriptor&gt;

Reads a server descriptor. This API can be used only after a connection is established by calling [connect](js-apis-nearlink-ssap.md#connect). This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| descriptor | [PropertyDescriptor](js-apis-nearlink-ssap.md#propertydescriptor) | Yes | Server property descriptor. The value must correspond to the descriptor in the service on a remote device obtained during service discovery. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;[PropertyDescriptor](js-apis-nearlink-ssap.md#propertydescriptor)&gt; | Promise used to return the **PropertyDescriptor** object read from the server. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 36100003 | NearLink disabled. |
| 36100043 | Invalid UUID in descriptor. |
| 36100044 | NearLink standard UUID not allowed. |
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
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  let valueBuffer = new ArrayBuffer(8);
  let descriptor: ssap.PropertyDescriptor = { // This descriptor must be the same as that in the service on a remote device during service discovery.
    serviceUuid: 'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: valueBuffer,
    descriptorType: ssap.PropertyDescriptorType.PROPERTY,
    isWriteable: true
  };
  // The connection takes a long time, and the service can only be accessed once the connection is set up. You can adjust the timer length based on the connection speed.
  setTimeout(() => {
    client.readDescriptor(descriptor).then((result: ssap.PropertyDescriptor) => {
      console.info('readDescriptor successfully: ' + JSON.stringify(result));
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### writeDescriptor

writeDescriptor(descriptor: PropertyDescriptor): Promise&lt;void&gt;

Rewrites the server descriptor. This API uses a promise to return the result.

> **NOTE**
>
> This API does not support writing the client property configuration descriptor (**CLIENT_PROPERTY_CONFIG**). To configure the client property notification or indication, use [setPropertyNotification](js-apis-nearlink-ssap.md#setpropertynotification) or [setPropertyIndication](#setpropertyindication).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| descriptor | [PropertyDescriptor](js-apis-nearlink-ssap.md#propertydescriptor) | Yes | Server property descriptor. The value must correspond to the descriptor in the service on a remote device obtained during service discovery. |

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
| 36100043 | Invalid UUID in descriptor. |
| 36100044 | NearLink standard UUID not allowed. |
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
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
  let valueBuffer = new ArrayBuffer(8);
  let descriptor: ssap.PropertyDescriptor = { // This descriptor must be the same as that in the service on a remote device during service discovery.
    serviceUuid: 'FFFFFFFF-1234-5678-ABCD-000000004386',
    propertyUuid: 'FFFFFFFF-1234-5678-ABCD-000000001234',
    value: valueBuffer,
    descriptorType: ssap.PropertyDescriptorType.PROPERTY,
    isWriteable: true
  };
  // The connection takes a long time, and the service can only be accessed once the connection is set up. You can adjust the timer length based on the connection speed.
  setTimeout(() => {
    client.writeDescriptor(descriptor).then(() => {
      console.info('writeDescriptor successfully');
    }).catch((err: BusinessError) => {
      console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
    });
  }, 3000);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onEventNotify

onEventNotify(callback: Callback&lt;Event&gt;): void

Subscribes to event notification events. For example, in a device status monitoring scenario, the client subscribes to events to receive status change notifications (such as device alarms and data updates) pushed by the server in real time. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[Event](#event)&gt; | Yes | Callback used to return the **Event** object of the service. |

**Example**

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onEventNotify:(data: ssap.Event) => void = (data: ssap.Event) => {
  console.info('eventNotify data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An app only needs to create one instance for a remote device.
  client.onEventNotify(onEventNotify);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offEventNotify

offEventNotify(callback?: Callback&lt;Event&gt;): void

Unsubscribes from event notification events. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[Event](#event)&gt; | No | Callback used to return the **Event** object of the service.<br>If this parameter is specified, the current callback is unregistered. If this parameter is not set, all callbacks corresponding to the type are unsubscribed. |

**Example**

```typescript
import { ssap } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onEventNotify:(data: ssap.Event) => void = (data: ssap.Event) => {
  console.info('eventNotify data:' + JSON.stringify(data));
};
let addr: string = '00:11:22:33:AA:FF'; // Remote device address obtained through scanning
let client: ssap.Client;
try {
  client = ssap.createClient(addr); // An app only needs to create one instance for a remote device.
  client.onEventNotify(onEventNotify);
  client.offEventNotify(onEventNotify);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Service

Represents the NearLink service.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | No | No | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| properties | [Property](js-apis-nearlink-ssap.md#property)[] | No | No | Properties of a service. |
| methods | [Method](#method)[] | No | Yes | Methods of a service. If this field is not specified, the service does not provide any method. |
| events | [Event](#event)[] | No | Yes | Events of a service. If this field is not specified, the service does not provide any event. |

## Method

Represents a method of the service.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | No | No | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| methodUuid | string | No | No | Method UUID. The data format is the same as that of **serviceUuid**. |
| parameter | ArrayBuffer | No | Yes | Method parameters. The data format is defined by the specific service. By default, this field is not used if not set. |
| result | ArrayBuffer | No | Yes | Return value of the method. The data format is defined by the specific service. By default, this field is not used if not set. |

## Event

Represents a service event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | No | No | NearLink service UUID, which is a string of 36 characters. The value consists of 32 hexadecimal digits and four hyphens (-), for example, **FFFFFFFF-1234-5678-ABCD-000000001234**, which indicates a 128-bit ID. The value cannot be set to a standard NearLink UUID. |
| eventUuid | string | No | No | Event UUID. The data format is the same as that of **serviceUuid**. |
| parameter | ArrayBuffer | No | Yes | Event parameters. The data format is defined by the specific service. By default, this field is not used if not set. |