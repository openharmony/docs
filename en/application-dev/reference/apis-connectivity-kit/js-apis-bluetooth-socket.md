# @ohos.bluetooth.socket (Bluetooth Socket Module)

The **socket** module provides APIs for operating and managing Bluetooth sockets.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import { socket } from '@kit.ConnectivityKit';
```

## socket.sppListen

sppListen(name: string, options: SppOptions, callback: AsyncCallback&lt;number&gt;): void

Creates a Serial Port Profile (SPP) listening socket for the server. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                     |
| -------- | --------------------------- | ---- | ----------------------- |
| name     | string                      | Yes   | Name of the service.                 |
| options   | [SppOptions](#sppoptions)     | Yes   | SPP listening configuration.             |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the server socket ID.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let serverNumber = -1;
let serverSocket = (code: BusinessError, number: number) => {
  if (code) {
    console.error('sppListen error, code is ' + code);
    return;
  } else {
    serverNumber = number;
    console.info('sppListen success, serverNumber = ' + serverNumber);
  }
}

let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
try {
    socket.sppListen('server1', sppOption, serverSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppAccept

sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void

Accepts a connection request from the client over a socket of the server. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                     |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number                      | Yes   | Server socket ID.          |
| callback     | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the client socket ID.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1;
let serverNumber = -1;
let acceptClientSocket = (code: BusinessError, number: number) => {
  if (code) {
    console.error('sppListen error, code is ' + code);
    return;
  } else {
    clientNumber = number; // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
    console.info('sppListen success, serverNumber = ' + clientNumber);
  }
}
try {
    socket.sppAccept(serverNumber, acceptClientSocket); // serverNumber is the server number returned by the sppListen callback.
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppConnect

sppConnect(deviceId: string, options: SppOptions, callback: AsyncCallback&lt;number&gt;): void

Initiates an SPP connection to a remote device from the client. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| deviceId | string                      | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| options   | [SppOptions](#sppoptions)     | Yes   | SPP listening configuration for client.                 |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the client socket ID.       |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

let clientSocket = (code: BusinessError, number: number) => {
  if (code) {
    console.error('sppListen error, code is ' + code);
    return;
  } else {
    // The obtained number is used as the socket ID for subsequent read/write operations on the client.
    console.info('bluetooth serverSocket Number: ' + number);
  }
}
let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
try {
    socket.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppCloseServerSocket

sppCloseServerSocket(socket: number): void

Closes a listening socket of the server.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| socket | number | Yes   | Server socket ID, which is obtained by **sppListen()**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let serverNumber = -1; // Set serverNumber to the value of serverNumber returned by the sppListen callback.
try {
    socket.sppCloseServerSocket(serverNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppCloseClientSocket

sppCloseClientSocket(socket: number): void

Closes a client socket.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description      |
| ------ | ------ | ---- | ------------- |
| socket | number | Yes   | Client socket ID, which is obtained by **sppAccept()** or **sppConnect()**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // clientNumber is obtained by sppAccept or sppConnect.
try {
    socket.sppCloseClientSocket(clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppWrite

sppWrite(clientSocket: number, data: ArrayBuffer): void

Writes data to the remote device through a socket.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type         | Mandatory  | Description           |
| ------------ | ----------- | ---- | ------------- |
| clientSocket | number      | Yes   | Client socket ID, which is obtained by **sppAccept()** or **sppConnect()**.|
| data         | ArrayBuffer | Yes   | Data to write.       |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // clientNumber is obtained by sppAccept or sppConnect.
let arrayBuffer = new ArrayBuffer(8);
let data = new Uint8Array(arrayBuffer);
data[0] = 123;
try {
    socket.sppWrite(clientNumber, arrayBuffer);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.on('sppRead')

on(type: 'sppRead', clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void

Subscribes to the SPP read request events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                        |
| ------------ | --------------------------- | ---- | -------------------------- |
| type         | string                      | Yes   | Event type. The value is **sppRead**, which indicates an SPP read request event.|
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept()** or **sppConnect()**.             |
| callback     | Callback&lt;ArrayBuffer&gt; | Yes   | Callback used to return the data read.         |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.            |
|801 | Capability not supported.          |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // clientNumber is obtained by sppAccept or sppConnect.
let dataRead = (dataBuffer: ArrayBuffer) => {
    let data = new Uint8Array(dataBuffer);
    console.info('bluetooth data is: ' + data[0]);
}
try {
    socket.on('sppRead', clientNumber, dataRead);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.off('sppRead')

off(type: 'sppRead', clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void

Unsubscribes from the SPP read request events.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| type         | string                      | Yes   | Event type. The value is **sppRead**, which indicates an SPP read request event.              |
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.                           |
| callback     | Callback&lt;ArrayBuffer&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // clientNumber is obtained by sppAccept or sppConnect.
try {
    socket.off('sppRead', clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppWriteAsync<sup>18+</sup>

sppWriteAsync(clientSocket: number, data: ArrayBuffer): Promise&lt;void&gt;

Writes data to the remote device through the socket. This API uses a promise to return the result. It supports returning of SPP operation errors, if any, when the connection is disconnected.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.                           |
| data         | ArrayBuffer                 | Yes   | Data to write.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2901054 | IO error. |
|2900099 | Operation failed. |

**Example**

```js
import { socket } from '@kit.ConnectivityKit'
import { AsyncCallback,BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // clientNumber is obtained by sppAccept or sppConnect.
let arrayBuffer = new ArrayBuffer(8);
let data = new Uint8Array(arrayBuffer);
try {
    await socket.sppWriteAsync(clientNumber, arrayBuffer);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppReadAsync<sup>18+</sup>

sppReadAsync(clientSocket: number): Promise&lt;ArrayBuffer&gt;

Reads data sent from the remote device through the socket. This API uses a promise to return the result. It supports returning of SPP operation errors, if any, when the connection is disconnected.

> **NOTE**
>
> - This API cannot be used together with [socket.on('sppRead')](#socketonsppread). A socket can use either this API or [socket.on('sppRead')](#socketonsppread).
>
> - This API is used in a different way from [socket.on('sppRead')](#socketonsppread). It needs to be called cyclically to read data.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.                           |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;ArrayBuffer&gt; | Promise used to return the result. If the operation is successful, the result is returned in **ArrayBuffer**. If the operation fails, the corresponding error code is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2901054 | IO error. |
|2900099 | Operation failed. |

**Example**

```js
import { socket } from '@kit.ConnectivityKit'
import { AsyncCallback,BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // clientNumber is obtained by sppAccept or sppConnect.
let buffer = new ArrayBuffer(1024);
let data = new Uint8Array(arrayBuffer);
let flag = 1;
while (flag) {
  try {
    buffer = await socket.sppReadAsync(this.clientNumber);
    if (buffer != null) {
      console.info('sppRead success, data = ' + JSON.stringify(buffer));
      printArrayBuffer(buffer);
    } else {
      console.error('sppRead error, data is null');
    }
  } catch (err) {
    flag = 0;
    console.error('startSppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
  }
}
```


## SppOptions

Defines the SPP configuration parameters.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type               | Readable  | Writable  | Description         |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | Yes   | Yes   | UUID of the SPP.|
| secure | boolean             | Yes   | Yes   | Whether it is a secure channel. The value **true** indicates a secure channel, and the value **false** indicates a non-secure channel.   |
| type   | [SppType](#spptype)            | Yes   | Yes   | Type of the SPP link.   |


## SppType

Enumerates the SPP link types.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name        | Value | Description           |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | Radio frequency communication (RFCOMM) link.|
