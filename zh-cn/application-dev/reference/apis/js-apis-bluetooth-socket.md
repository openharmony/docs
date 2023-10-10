# @ohos.bluetooth.socket (蓝牙socket模块)

socket模块提供了操作和管理蓝牙socket的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import socket from '@ohos.bluetooth.socket';
```

## socket.sppListen<a name="sppListen"></a>

sppListen(name: string, options: SppOptions, callback: AsyncCallback&lt;number&gt;): void

创建一个服务端监听Socket。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                      |
| -------- | --------------------------- | ---- | ----------------------- |
| name     | string                      | 是    | 服务的名称。                  |
| option   | [SppOptions](#sppoptions)     | 是    | spp监听配置参数。              |
| callback | AsyncCallback&lt;number&gt; | 是    | 表示回调函数的入参，服务端Socket的id。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}

let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
try {
    socket.sppListen('server1', sppOption, serverSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppAccept<a name="sppAccept"></a>

sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void

服务端监听socket等待客户端连接。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                      |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number                      | 是    | 服务端socket的id。           |
| callback     | AsyncCallback&lt;number&gt; | 是    | 表示回调函数的入参，客户端socket的id。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
let clientNumber = -1;
function acceptClientSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth clientSocket Number: ' + number);
    // 获取的clientNumber用作服务端后续读/写操作socket的id。
    clientNumber = number;
  }
}
try {
    socket.sppAccept(serverNumber, acceptClientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppConnect<a name="sppConnect"></a>

sppConnect(deviceId: string, options: SppOptions, callback: AsyncCallback&lt;number&gt;): void

客户端向远端设备发起spp连接。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                             |
| -------- | --------------------------- | ---- | ------------------------------ |
| deviceId | string                      | 是    | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| option   | [SppOptions](#sppoptions)     | 是    | spp客户端连接配置参数。                  |
| callback | AsyncCallback&lt;number&gt; | 是    | 表示回调函数的入参，客户端socket的id。        |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';

let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
let sppOption:socket.SppOptions = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
try {
    socket.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppCloseServerSocket<a name="sppCloseServerSocket"></a>

sppCloseServerSocket(socket: number): void

关闭服务端监听Socket，入参socket由sppListen接口返回。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明              |
| ------ | ------ | ---- | --------------- |
| socket | number | 是    | 服务端监听socket的id。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
try {
    socket.sppCloseServerSocket(serverNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppCloseClientSocket<a name="sppCloseClientSocket"></a>

sppCloseClientSocket(socket: number): void

关闭客户端socket，入参socket由sppAccept或sppConnect接口获取。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明       |
| ------ | ------ | ---- | ------------- |
| socket | number | 是    | 客户端socket的id。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
try {
    socket.sppCloseClientSocket(clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## socket.sppWrite<a name="sppWrite"></a>

sppWrite(clientSocket: number, data: ArrayBuffer): void

通过socket向远端发送数据，入参clientSocket由sppAccept或sppConnect接口获取 。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型          | 必填   | 说明            |
| ------------ | ----------- | ---- | ------------- |
| clientSocket | number      | 是    | 客户端socket的id。 |
| data         | ArrayBuffer | 是    | 写入的数据。        |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
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

订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                         |
| ------------ | --------------------------- | ---- | -------------------------- |
| type         | string                      | 是    | 填写"sppRead"字符串，表示spp读请求事件。 |
| clientSocket | number                      | 是    | 客户端socket的id。              |
| callback     | Callback&lt;ArrayBuffer&gt; | 是    | 表示回调函数的入参，读取到的数据。          |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
function dataRead(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.log('bluetooth data is: ' + data[0]);
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
| type         | string                      | 是    | 填写"sppRead"字符串，表示spp读请求事件。               |
| clientSocket | number                      | 是    | 客户端Socket的id。                            |
| callback     | Callback&lt;ArrayBuffer&gt; | 否    | 表示取消订阅spp读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
try {
    socket.off('sppRead', clientNumber);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## SppOptions<a name="SppOptions"></a>

描述spp的配置参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称     | 类型                | 可读   | 可写   | 说明          |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | 是    | 是    | spp单据的uuid。 |
| secure | boolean             | 是    | 是    | 是否是安全通道。    |
| type   | [SppType](#SppType)            | 是    | 是    | Spp链路类型。    |


## SppType<a name="SppType"></a>

枚举，Spp链路类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称         | 值  | 说明            |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | 表示rfcomm链路类型。 |