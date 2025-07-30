# @ohos.bluetooth.socket (蓝牙socket模块)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--SE: @chengguohong; @tangjia15-->
<!--TSE: @wangfeng517-->

socket模块提供了操作和管理蓝牙socket的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import { socket } from '@kit.ConnectivityKit';
```

## socket.sppListen

sppListen(name: string, options: SppOptions, callback: AsyncCallback&lt;number&gt;): void

创建一个服务端监听Socket。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                      |
| -------- | --------------------------- | ---- | ----------------------- |
| name     | string                      | 是    | 服务的名称，该字符串的字符个数范围为[0, 256]。                  |
| options   | [SppOptions](#sppoptions)     | 是    | spp监听配置参数。              |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调函数。当创建服务端scoket成功，err为undefined，data为获取到的服务端socket的id；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

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

服务端监听socket等待客户端连接。使用Callback异步回调。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                      |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number                      | 是    | 服务端socket的id。<br>该值是调用[sppListen](#socketspplisten)接口后，通过其异步callback获取到的。           |
| callback     | AsyncCallback&lt;number&gt; | 是    | 回调函数。当收到客户端的连接时，err为undefined，data为该客户端socket的id；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1;
let serverNumber = -1;
let acceptClientSocket = (code: BusinessError, number: number) => {
  if (code) {
    console.error('sppListen error, code is ' + code);
    return;
  } else {
    clientNumber = number; // 获取的clientNumber用作客户端后续读/写操作socket的id。
    console.info('sppListen success, clientNumber = ' + clientNumber);
  }
}
try {
    socket.sppAccept(serverNumber, acceptClientSocket); // serverNumber是sppListen回调中得到的serverNumber。
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppConnect

sppConnect(deviceId: string, options: SppOptions, callback: AsyncCallback&lt;number&gt;): void

客户端向远端设备发起spp连接。使用Callback异步回调。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                             |
| -------- | --------------------------- | ---- | ------------------------------ |
| deviceId | string                      | 是    | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| options   | [SppOptions](#sppoptions)     | 是    | spp客户端连接配置参数。                  |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调函数。当客户端发起连接成功，err为undefined，data为当前客户端socket的id；否则为错误对象。        |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';

let clientSocket = (code: BusinessError, number: number) => {
  if (code) {
    console.error('sppConnect error, code is ' + code);
    return;
  } else {
    // 获取的number用作客户端后续读/写操作的socket id。
    console.info('bluetooth clientSocket Number: ' + number);
  }
}
let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
try {
    socket.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.getDeviceId<sup>17+</sup>

getDeviceId(clientSocket: number): string

通过clientSocket获取对端设备地址。服务端、客户端均可调用，传入非法clientSocket无法获取。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                          | 必填   | 说明                             |
| -------- | ------------------------------- | ---- | ------------------------------ |
| clientSocket | number                      | 是    | 客户端socket的id。<br>该值是调用[sppAccept](#socketsppaccept)或[sppConnect](#socketsppconnect)接口，通过其异步callback获取到的。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| string | 返回对端设备地址。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |

**示例：**

```js
import { socket } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// 服务端获取客户端设备地址。
let clientSocket = -1; // clientSocket是sppAccept回调中得到的，调getDeviceId接口前需更新clientSocket。
try {
    let deviceAddr: string = socket.getDeviceId(clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// 客户端获取服务端设备地址。
// clientSocket是sppConnect回调中得到的，调getDeviceId接口前需更新clientSocket。
try {
    let deviceAddr: string = socket.getDeviceId(clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppCloseServerSocket

sppCloseServerSocket(socket: number): void

关闭服务端监听Socket，入参socket由sppListen接口返回。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明              |
| ------ | ------ | ---- | --------------- |
| socket | number | 是    | 服务端监听socket的id。<br>该值是调用[sppListen](#socketspplisten)接口，通过其异步callback获取到的。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let serverNumber = -1; // 此处serverNumber需赋值为调用sppListen接口后，回调中得到的serverNumber。
try {
    socket.sppCloseServerSocket(serverNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppCloseClientSocket

sppCloseClientSocket(socket: number): void

关闭客户端socket，入参socket由sppAccept或sppConnect接口获取。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明       |
| ------ | ------ | ---- | ------------- |
| socket | number | 是    | 客户端socket的id。<br>该值是调用[sppAccept](#socketsppaccept)或[sppConnect](#socketsppconnect)接口，通过其异步callback获取到的。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // 入参clientNumber由sppAccept或sppConnect接口获取。
try {
    socket.sppCloseClientSocket(clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppWrite

sppWrite(clientSocket: number, data: ArrayBuffer): void

通过socket向远端发送数据，入参clientSocket由sppAccept或sppConnect接口获取 。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型          | 必填   | 说明            |
| ------------ | ----------- | ---- | ------------- |
| clientSocket | number      | 是    | 客户端socket的id。<br>该值是调用[sppAccept](#socketsppaccept)或[sppConnect](#socketsppconnect)接口，通过其异步callback获取到的。 |
| data         | ArrayBuffer | 是    | 写入的数据。        |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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

订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。使用Callback异步回调。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                         |
| ------------ | --------------------------- | ---- | -------------------------- |
| type         | string                      | 是    | 事件回调类型，支持的事件为'sppRead'，表示订阅spp读请求事件。<br>当收到了对端发送的数据时，触发该事件。|
| clientSocket | number                      | 是    | 客户端socket的id。<br>该值是调用[sppAccept](#socketsppaccept)或[sppConnect](#socketsppconnect)接口，通过其异步callback获取到的。              |
| callback     | Callback&lt;ArrayBuffer&gt; | 是    | 指定订阅的回调函数，会返回读取到的数据。       |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.            |
|801 | Capability not supported.          |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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

取消订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                                       |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| type         | string                      | 是    | 事件回调类型，支持的事件为'sppRead'，表示取消订阅spp读请求事件。               |
| clientSocket | number                      | 是    | 客户端socket的id。<br>该值是调用[sppAccept](#socketsppaccept)或[sppConnect](#socketsppconnect)接口，通过其异步callback获取到的。                            |
| callback     | Callback&lt;ArrayBuffer&gt; | 否    | 指定取消订阅的回调函数通知。<br>若传参，则需与[socket.on('sppRead')](#socketonsppread)中的回调函数一致；若无传参，则取消订阅该type对应的所有回调函数通知。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // 入参clientNumber由sppAccept或sppConnect接口获取。
try {
    socket.off('sppRead', clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppWriteAsync<sup>18+</sup>

sppWriteAsync(clientSocket: number, data: ArrayBuffer): Promise&lt;void&gt;

通过socket向远端发送数据的异步接口，该接口支持断开连接时SPP操作异常错误返回。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名          | 类型                          | 必填   | 说明                                       |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | 是    | 客户端socket的id。<br>该值是调用[sppAccept](#socketsppaccept)或[sppConnect](#socketsppconnect)接口，通过其异步callback获取到的。                            |
| data         | ArrayBuffer                 | 是    | 写入的数据。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|801 | Capability not supported.          |
|2901054 | IO error. |
|2900099 | Operation failed. |

**示例：**

```js
import { socket } from '@kit.ConnectivityKit';
import { AsyncCallback,BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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

通过socket读取对端所发送数据的异步接口，该接口支持断开连接时SPP操作异常错误返回。

> **注意**：
>
> - 该接口不可与[socket.on('sppRead')](#socketonsppread)接口混用，同一路socket只能使用[socket.on('sppRead')](#socketonsppread)或者socket.sppReadAsync其中一个接口。
>
> - 该接口与[socket.on('sppRead')](#socketonsppread)使用方式不同，需要业务循环使用读取数据。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名          | 类型                          | 必填   | 说明                                       |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| clientSocket | number                      | 是    | 客户端socket的id。<br>该值是调用[sppAccept](#socketsppaccept)或[sppConnect](#socketsppconnect)接口，通过其异步callback获取到的。                            |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;ArrayBuffer&gt; | Promise对象。返回读取的数据。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|801 | Capability not supported.          |
|2901054 | IO error. |
|2900099 | Operation failed. |

**示例：**

```js
import { socket } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let clientNumber = -1; // 入参clientNumber由sppAccept或sppConnect接口获取。
let buffer = new ArrayBuffer(1024);
let data = new Uint8Array(buffer);
let flag = 1;
while (flag) {
  try {
    socket.sppReadAsync(clientNumber).then((outBuffer: ArrayBuffer) => {
      buffer = outBuffer;
    });
    if (buffer != null) {
      console.info('sppRead success, data = ' + JSON.stringify(buffer));
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

描述spp的配置参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称     | 类型                | 只读   | 可选   | 说明          |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | 否    | 否    | spp单据的uuid。 |
| secure | boolean             | 否    | 否    | 是否是安全通道。true表示是安全通道，false表示非安全通道。    |
| type   | [SppType](#spptype)            | 否    | 否    | Spp链路类型。    |


## SppType

枚举，Spp链路类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称         | 值  | 说明            |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | 表示rfcomm链路类型。 |