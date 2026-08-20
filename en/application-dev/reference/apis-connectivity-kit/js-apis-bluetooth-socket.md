# @ohos.bluetooth.socket (Bluetooth Socket Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=14ca614ebb030bf413b2d8393352ad7521a1d1b9 translatedAt=2026-08-20T01:52:17.861Z pushedAt=2026-08-20T01:58:08.147Z -->

The **socket** module provides the Bluetooth socket function, which can be used to implement inter-device connection and data transmission. When two devices communicate via Bluetooth sockets, they can be distinguished as client and server based on their respective functions.

The supported socket connections can be classified into two types, namely, [Radio Frequency Communication Protocol (RFCOMM)](../../connectivity/bluetooth/terminology.md#rfcomm) and [Logical Link Control and Adaptation Protocol (L2CAP)](../../connectivity/bluetooth/terminology.md#l2cap).

- RFCOMM is also known as Serial Port Profile ([SPP](../../connectivity/bluetooth/terminology.md#spp)) and applies to Bluetooth Classic, which is also referred to as [basic rate (BR)](../../connectivity/bluetooth/terminology.md#br)/[enhanced data rate (EDR)](../../connectivity/bluetooth/terminology.md#edr).

- L2CAP applies to Bluetooth Classic (BR/EDR) and Bluetooth Low Energy ([BLE](../../connectivity/bluetooth/terminology.md#ble)).

To create a client socket and initiate a connection to the server, use [socket.sppConnect](#socketsppconnect).

To create a server socket and listen for the client connection, use [socket.sppListen](#socketspplisten).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { socket } from '@kit.ConnectivityKit';
```

## socket.sppListen

sppListen(name: string, options: SppOptions, callback: AsyncCallback&lt;number&gt;): void

Creates a server listening socket. This API uses an asynchronous callback to return the result.

- To adapt to different use cases, you can create server sockets for different link types by setting the **type** parameter in [socket.SppOptions](#sppoptions). This operation registers the corresponding service with the Bluetooth subsystem to indicate the capabilities supported by the server.

- The client can send a connection request to the server by calling [socket.sppConnect](#socketsppconnect).

- If the server socket is no longer needed, the application needs to proactively close the socket by calling [socket.sppCloseServerSocket](#socketsppcloseserversocket). The Bluetooth subsystem then deletes the corresponding service registered earlier. If the client initiates a connection at this time, the connection fails.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                     |
| -------- | --------------------------- | ---- | ----------------------- |
| name     | string                      | Yes   | Service name, which is a string of 0 to 256 characters.                 |
| options   | [SppOptions](#sppoptions)     | Yes   | Socket configuration parameters.             |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result. If the server socket is created successfully, **err** is **undefined**, and **data** is the ID (a non-negative number) of the server socket. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@kit.BasicServicesKit';

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

// Use the RFCOMM socket as an example.
let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: socket.SppType.SPP_RFCOMM};
try {
    socket.sppListen('server1', sppOption, serverSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.getL2capPsm<sup>20+</sup>

getL2capPsm(serverSocket: number): number

Obtains the (Protocol/Service Multiplexer [PSM](../../connectivity/bluetooth/terminology.md#psm)) value of the L2CAP socket on the server. The PSM value is used to identify a specific service data transmission channel.

>**NOTE**
>
> This API must be called on the server after [socket.sppListen](#socketspplisten) is called, and the [SppType](#spptype) passed to this API must be **SPP_L2CAP** or **SPP_L2CAP_BLE**.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                     |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number | Yes| ID of the server socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppListen](#socketspplisten) is called.          |

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| number | PSM value of the L2CAP socket.<br>- If [SppType](#spptype) is set to **SPP_L2CAP_BLE**, the valid value range of the return value is [0x01, 0xFF].<br>- If [SppType](#spptype) is set to **SPP_L2CAP**, the valid value range of the return value is [0x0000, 0xFFFF].<br>- If the server connection fails to be established or [SppType](#spptype) is not set to **L2CAP**, **-1** is returned.|          

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// The server obtains the address of the client.
let serverNumber = 1; // Set serverNumber to the value of serverNumber returned by the sppListen callback.
try {
    let l2capPsm: number = socket.getL2capPsm(serverNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.sppAccept

sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void

Accepts the socket connection request from the client. This API uses an asynchronous callback to return the result.

- This API can be called to listen for the client connection request only after the server socket is created by calling [socket.sppListen](#socketspplisten).

- The client can send a connection request to the server by calling [socket.sppConnect](#socketsppconnect).

- After the connection is established, the server can send data to the client by calling APIs such as [socket.sppWrite](#socketsppwrite), [socket.sppWriteAsync](#socketsppwriteasync18) and [socket.sppReadAsync](#socketsppreadasync18).

- If the connection is no longer needed, the server can call [socket.sppCloseClientSocket](#socketsppcloseclientsocket) to disconnect the specified client socket.

**System capability:** SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                     |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number                      | Yes   | ID of the server socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppListen](#socketspplisten) is called.          |
| callback     | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result. If the connection is established successfully, **err** is **undefined**, and **data** is the ID (a non-negative number) of the client socket that initiates the connection request. Otherwise, **err** is an error object.|

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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = -1;
let serverNumber = 1;
let acceptClientSocket = (code: BusinessError, number: number) => {
  if (code) {
    console.error('sppListen error, code is ' + code);
    return;
  } else {
    clientNumber = number; // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
    console.info('sppListen success, clientNumber = ' + clientNumber);
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

Creates a client socket and sends a connection request to the specific service of the server.

- The **type** parameter in [SppOptions](#sppoptions) indicates the type of the service to be connected.

- Ensure that the service to be connected is available on the server. The server can use [socket.sppListen](#socketspplisten) to subscribe to connection requests from the client.

- After the connection is established, the client can call [socket.sppWrite](#socketsppwrite) or [socket.sppWriteAsync](#socketsppwriteasync18) to transmit data with the server.

- If the connection is no longer needed, the client can call [socket.sppCloseclientSocket](#socketsppcloseclientsocket) to disconnect the connection.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| deviceId | string                      | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| options   | [SppOptions](#sppoptions)     | Yes   | Socket configuration parameters.                 |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result. If the connection is successfully initiated by the client, **err** is **undefined**, and data is the ID (a non-negative number) of the current client socket. Otherwise, **err** is an error object.       |

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
import { BusinessError } from '@kit.BasicServicesKit';

let clientSocket = (code: BusinessError, number: number) => {
  if (code) {
    console.error('sppConnect error, code is ' + code);
    return;
  } else {
    // The obtained number is used as the socket ID for subsequent read/write operations on the client.
    console.info('bluetooth clientSocket Number: ' + number);
  }
}

// Use the RFCOMM socket as an example.
let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: socket.SppType.SPP_RFCOMM};
try {
    socket.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.getDeviceId<sup>17+</sup>

getDeviceId(clientSocket: number): string

Obtains the Bluetooth address of the peer end in the socket connection. This API can be used on both the client and server.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | ------------------------------- | ---- | ------------------------------ |
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppAccept](#socketsppaccept) or [socket.sppConnect](#socketsppconnect) is called.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| string | IP address of the peer device.<br>For security purposes, the device addresses obtained are virtual MAC addresses.<br>- The virtual address of a paired Bluetooth device will not change.<br>- If Bluetooth is disabled and then enabled again, the virtual address will change immediately.<br>- If the pairing is canceled, the Bluetooth subsystem will determine when to change the address based on the actual usage of the address. If the address is being used by another application, the address will not change immediately.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// The server obtains the address of the client.
let clientSocket = 1; // clientSocket is obtained from the sppAccept callback. Before calling getDeviceId, update the clientSocket.
try {
    let deviceAddr: string = socket.getDeviceId(clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// The client obtains the address of the server.
// clientSocket is obtained from the sppConnect callback. Before calling getDeviceId, update the clientSocket.
try {
    let deviceAddr: string = socket.getDeviceId(clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.sppCloseServerSocket

sppCloseServerSocket(socket: number): void

Deletes the specified server socket. This API can only be used on the server.

- You need to call [socket.sppListen](#socketspplisten) first to obtain the valid ID of the server socket.

- If listening is no longer required for the server socket, you can call this API to close the socket. The Bluetooth subsystem then deletes the corresponding service registered earlier. If the client initiates a connection at this time, the connection fails.

- If the server socket is connected to other clients, the connection will be disconnected after this API is called.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| socket | number | Yes   | ID of the server socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppListen](#socketspplisten) is called.|

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
import { BusinessError } from '@kit.BasicServicesKit';

let serverNumber = 1; // Set serverNumber to the value of serverNumber returned by the sppListen callback.
try {
    socket.sppCloseServerSocket(serverNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.sppCloseClientSocket

sppCloseClientSocket(socket: number): void

Closes the specified client socket and disconnects the client from the server. This API can be used on both the client and server.

- To use this API on the client, make sure that a connection has been established successfully after [socket.sppConnect](#socketsppconnect) is called.

- To use this API on the server, make sure that a connection has been established successfully after [socket.sppAccept](#socketsppaccept) is called.

- If a socket connection is no longer needed, the application must disconnect the connection between the client and server by calling this API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description      |
| ------ | ------ | ---- | ------------- |
| socket | number | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppAccept](#socketsppaccept) or [socket.sppConnect](#socketsppconnect) is called.|

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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // clientNumber is obtained by sppAccept or sppConnect.
try {
    socket.sppCloseClientSocket(clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.sppWrite

sppWrite(clientSocket: number, data: ArrayBuffer): void

Sends data to the peer end. This API can be used on both the client and server.

- This API is valid only after the connection between the client and server is successfully established.

- To use this API on the client, make sure that a connection has been established successfully after [socket.sppConnect](#socketsppconnect) is called.

- To use this API on the server, make sure that a connection has been established successfully after [socket.sppAccept](#socketsppaccept) is called.

- If you need to detect errors such as abnormal disconnection during data transmission, you are advised to use [socket.sppWriteAsync](#socketsppwriteasync18).

- According to the Bluetooth protocol, the data channel needs to enter the sleep mode when it is idle to reduce power consumption. During the Bluetooth subsystem implementation, the data channel enters the sleep mode when no data is exchanged within 5s to 7s. As a result, it takes about 500 ms to exit the sleep mode before data is sent using this API.

- To reduce the time taken for the data channel to exit the sleep mode before data is sent, you are advised to send heartbeat data of any size to the data channel every 3s to keep the data channel alive. This prevents the data channel from entering the sleep mode, but increases the device power consumption.

<!--RP1--><!--RP1End-->

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type         | Mandatory  | Description           |
| ------------ | ----------- | ---- | ------------- |
| clientSocket | number      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppAccept](#socketsppaccept) or [socket.sppConnect](#socketsppconnect) is called.|
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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // clientNumber is obtained by sppAccept or sppConnect.
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

Subscribes to socket read request events. This API can be used on both the client and server. After this API is called, the subscribed callback is invoked when data sent by the peer end is received.

- To use this API on the client, make sure that a connection has been established successfully after [socket.sppConnect](#socketsppconnect) is called.

- To use this API on the server, make sure that a connection has been established successfully after [socket.sppAccept](#socketsppaccept) is called.

- This API cannot be used with [socket.sppReadAsync](#socketsppreadasync18), which is supported since API version 18. For the same socket connection, only the **socket.on('sppRead')** or [socket.sppReadAsync](#socketsppreadasync18) API can be used.

- If you need to detect errors such as abnormal disconnection during data transmission, you are advised to use [socket.sppReadAsync](#socketsppreadasync18).

<!--RP2--><!--RP2End-->

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                        |
| ------------ | --------------------------- | ---- | -------------------------- |
| type         | string                      | Yes   | Event type. The value **sppRead** indicates the SPP read request event.<br>This event is triggered when data sent by the peer device is received.|
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppAccept](#socketsppaccept) or [socket.sppConnect](#socketsppconnect) is called.             |
| callback     | Callback&lt;ArrayBuffer&gt; | Yes   | Callback used to return the read data.      |

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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // clientNumber is obtained by sppAccept or sppConnect.
let dataRead = (dataBuffer: ArrayBuffer) => {
    let data = new Uint8Array(dataBuffer);
    console.info('bluetooth data length is: ' + data.byteLength);
}
try {
    socket.on('sppRead', clientNumber, dataRead);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.off('sppRead')

off(type: 'sppRead', clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void

Unsubscribes from socket read request events.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| type         | string                      | Yes   | Event type. The value **sppRead** indicates the SPP read request event.              |
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [socket.sppAccept](#socketsppaccept) or [socket.sppConnect](#socketsppconnect) is called.                           |
| callback     | Callback&lt;ArrayBuffer&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [socket.on('sppRead')](#socketonsppread). If this parameter is not specified, all callbacks corresponding to the event type are unregistered.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // clientNumber is obtained by sppAccept or sppConnect.
try {
    socket.off('sppRead', clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.sppWriteAsync<sup>18+</sup>

sppWriteAsync(clientSocket: number, data: ArrayBuffer): Promise&lt;void&gt;

Sends data to the peer end. This API can be used on both the client and server. This API uses a promise to return the result. If the connection is disconnected, this API will throw and return an error code.

- This API is valid only after the connection between the client and server is successfully established.

- To use this API on the client, make sure that a connection has been established successfully after [socket.sppConnect](#socketsppconnect) is called.

- To use this API on the server, make sure that a connection has been established successfully after [socket.sppAccept](#socketsppaccept) is called.

- According to the Bluetooth protocol, the data channel needs to enter the sleep mode when it is idle to reduce power consumption. During the Bluetooth subsystem implementation, the data channel enters the sleep mode when no data is exchanged within 5s to 7s. As a result, it takes about 500 ms to exit the sleep mode before data is sent using this API.

- To reduce the time taken for the data channel to exit the sleep mode before data is sent, you are advised to send heartbeat data of any size to the data channel every 3s to keep the data channel alive. This prevents the data channel from entering the sleep mode, but increases the device power consumption.

<!--RP3--><!--RP3End-->

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [sppAccept](#socketsppaccept) or [sppConnect](#socketsppconnect) is called.                           |
| data         | ArrayBuffer                 | Yes   | Data to write.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|801 | Capability not supported.          |
|2901054 | IO error. |
|2900099 | Operation failed. |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // clientNumber is obtained by sppAccept or sppConnect.
let arrayBuffer = new ArrayBuffer(8);
let data = new Uint8Array(arrayBuffer);
try {
    socket.sppWriteAsync(clientNumber, arrayBuffer).then(() => {
      console.info("sppWrite success");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.sppReadAsync<sup>18+</sup>

sppReadAsync(clientSocket: number): Promise&lt;ArrayBuffer&gt;

Reads data sent by the peer end. This API can be used on both the client and server. This API uses a promise to return the result. If the connection is disconnected, this API will throw and return an error code.

- To use this API on the client, make sure that a connection has been established successfully after [socket.sppConnect](#socketsppconnect) is called.

- To use this API on the server, make sure that a connection has been established successfully after [socket.sppAccept](#socketsppaccept) is called.

- This API cannot be used with [socket.on('sppRead')](#socketonsppread), which is supported since API version 10. For the same socket, only the [socket.on('sppRead')](#socketonsppread) or **socket.sppReadAsync** API can be used.

- This API returns the read data using a promise. You are advised to call this API cyclically after successful connection to obtain the received data. If this API is not called in a timely manner, the received data will be lost.

- This API works in asynchronous mode. The next call is allowed only after the asynchronous callback is returned.

<!--RP4--><!--RP4End-->

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [sppAccept](#socketsppaccept) or [sppConnect](#socketsppconnect) is called.                           |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| Promise&lt;ArrayBuffer&gt; | Promise used to return the read data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|801 | Capability not supported.          |
|2901054 | IO error. |
|2900099 | Operation failed. |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// clientNumber is obtained via sppAccept or sppConnect.
async function readAsync(clientNumber: number) {
  let flag = 1;
  try {
    while (flag) { // Call the API cyclically to read data. This example is for reference only. You need to change the implementation based on the service requirements. 
      let buffer = await socket.sppReadAsync(clientNumber); // Use await to ensure sequential reading.
      let data = new Uint8Array(buffer);
      if (data) {
        console.info('sppRead success, data length = ' + data.byteLength);
        // Process the received data.
      }
    }
  } catch (err) {
    console.error('startSppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    socket.sppCloseClientSocket(clientNumber); // Close the connection when an error occurs.
  }
}
```

## socket.getMaxReceiveDataSize<sup>22+</sup>

getMaxReceiveDataSize(clientSocket: number): number

Obtains the maximum size of data that can be received on the current socket link type. This API can be used by both the client and server.

- To use this API on the client, make sure that a connection has been established successfully after [socket.sppConnect](#socketsppconnect) is called.

- To use this API on the server, make sure that a connection has been established successfully after [socket.sppAccept](#socketsppaccept) is called.

- The returned value is **0** if the socket link type is [SPP_RFCOMM](#spptype), indicating that the maximum size of received data is unlimited.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [sppAccept](#socketsppaccept) or [sppConnect](#socketsppconnect) is called.                           |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| number | Maximum size of the received data, in bytes.|

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// clientNumber is obtained via sppAccept or sppConnect.
let clientSocket = 1; 
try {
    let result: number = socket.getMaxReceiveDataSize(clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.getMaxTransmitDataSize<sup>22+</sup>

getMaxTransmitDataSize(clientSocket: number): number

Obtains the maximum size of data that can be sent on the current socket link type. This API can be used by both the client and server.

- To use this API on the client, make sure that a connection has been established successfully after [socket.sppConnect](#socketsppconnect) is called.

- To use this API on the server, make sure that a connection has been established successfully after [socket.sppAccept](#socketsppaccept) is called.

- The returned value is **0** if the socket link type is [SPP_RFCOMM](#spptype), indicating that the maximum size of data to be sent is unlimited.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [sppAccept](#socketsppaccept) or [sppConnect](#socketsppconnect) is called.                           |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| number | Maximum size of the sent data, in bytes.|

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// clientNumber is obtained via sppAccept or sppConnect.
let clientSocket = 1; 
try {
    let result: number = socket.getMaxTransmitDataSize(clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## socket.isConnected<sup>22+</sup>

isConnected(clientSocket: number): boolean

Checks whether the current link is connected. This API can be used by both the client and server.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | Yes   | ID of the client socket.<br>You can obtain the value from the asynchronous callback returned after [sppAccept](#socketsppaccept) or [sppConnect](#socketsppconnect) is called.                           |

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| boolean | Whether the socket link is connected. The value **true** indicates that the socket link is connected, and **false** indicates the opposite.|

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// clientNumber is obtained via sppAccept or sppConnect.
let clientSocket = 1; 
try {
    let result: boolean = socket.isConnected(clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## SppOptions

Defines the socket configuration parameters.

**System capability**: SystemCapability.Communication.Bluetooth.Core

<!--Table: 10%; 10%; 10%; 10%; 60%-->

| Name    | Type               | Read-Only  | Optional  | Description         |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | No   | No   | Service UUID of the RFCOMM socket, for example, **00001101-0000-1000-8000-00805F9B34FB**.<br>- You are advised to use a custom service UUID (which can be generated using the [util.generateRandomUUID](../apis-arkts/js-apis-util.md#utilgeneraterandomuuid9)) or the Serial Port UUID (00001101-0000-1000-8000-00805F9B34FB) defined in the standard protocol.<br>- This parameter is mandatory when **SppType** is set to **SPP_RFCOMM**.<br>- This parameter is set to an empty string when **SppType** is set to **SPP_L2CAP** or **SPP_L2CAP_BLE**.|
| secure | boolean             | No   | No   | Whether it is a secure channel. The value **true** indicates a secure channel, and the value **false** indicates a non-secure channel.   |
| type   | [SppType](#spptype)            | No   | No   | Bluetooth socket type.   |
| psm<sup>20+</sup>   | number              | No   | Yes   |PSM value, which is used to identify a specific service data transmission channel. If this parameter is not set, the default value **-1** is used.<br>For the client:<br>- If **SppType** is set to **SPP_RFCOMM**, this parameter is left empty.<br>- If **SppType** is set to **SPP_L2CAP_BLE** or **SPP_L2CAP**, the value of this parameter must be the same as that of the server.<br>For the server:<br>- If **SppType** is set to **SPP_RFCOMM**, this parameter is left empty.<br>- If **SppType** is set to **SPP_L2CAP_BLE**, the value of this parameter must be automatically allocated by the system. The valid value range is [0x01, 0xFF].<br>- If **SppType** is set to **SPP_L2CAP**, the value of this parameter can be manually set or automatically allocated by the Bluetooth subsystem. If the value is set, the valid value range is [0x00, 0xFFFF], and the least significant bit of the least significant byte must be **1**, and the least significant bit of the most significant byte must be **0**. If the value is allocated by the Bluetooth subsystem, this parameter is left unspecified. You can obtain the value of this parameter by calling [socket.getL2capPsm](#socketgetl2cappsm20).|

## SppType

Enumerates the Bluetooth socket types.

- You need to select different socket types for different Bluetooth devices.

- You must use the L2CAP socket type for BLE devices.

- You are advised to use the RFCOMM socket type for BR/EDR devices. This mode enables dynamic negotiation of channels via the service UUID (that is, the process where devices automatically determine communication channels by querying the service UUID), while providing higher security and reliability.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name        | Value | Description           |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | RFCOMM socket for BR/EDR devices.|
| SPP_L2CAP<sup>20+</sup> | 1    | L2CAP socket for BR/EDR devices.|
| SPP_L2CAP_BLE<sup>20+</sup> | 2    | L2CAP socket for BLE devices.|