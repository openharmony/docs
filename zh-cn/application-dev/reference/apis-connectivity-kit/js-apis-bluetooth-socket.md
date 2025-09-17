# @ohos.bluetooth.socket (蓝牙socket模块)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

本模块提供一种蓝牙套接字功能，可实现设备间连接和数据传输。当两个设备间进行蓝牙套接字通信交互时，依据设备功能的不同，可区分客户端与服务端。

支持的套接字链路类型包括[RFCOMM](../../connectivity/terminology.md#rfcomm)和[L2CAP](../../connectivity/terminology.md#l2cap)。

- RFCOMM链路类型也称为串口通信协议（Serial Port Profile, [SPP](../../connectivity/terminology.md#spp)），适用于传统蓝牙（[BR](../../connectivity/terminology.md#br)/[EDR](../../connectivity/terminology.md#edr)）。
- L2CAP链路类型适用于传统蓝牙（BR/EDR）和低功耗蓝牙（[BLE](../../connectivity/terminology.md#ble)）。

通过[socket.sppConnect](#socketsppconnect)创建客户端套接字并向服务端发起连接。

通过[socket.sppListen](#socketspplisten)创建服务端套接字并监听客户端的连接。

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
| callback | AsyncCallback&lt;number&gt; | 是    | 回调函数。当创建服务端socket成功，err为undefined，data为获取到的服务端socket的id；否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

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

## socket.getL2capPsm<sup>20+</sup>
getL2capPsm(serverSocket: number): number

获取服务端L2CAP链路类型套接字的协议/服务多路复用器值（Protocol/Service Multiplexer, [PSM](../../connectivity/terminology.md#psm)），该值用于标识特定的服务数据传输通道。

>**说明：**
>
> 需要在服务端调用完[socket.sppListen](#socketspplisten)后调用该接口，且传入的链路类型[SppType](#spptype)需是SPP_L2CAP或SPP_L2CAP_BLE。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名          | 类型                          | 必填   | 说明                      |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number | 是 | 服务端套接字的id。<br>该值是调用[socket.sppListen](#socketspplisten)接口后，通过其异步callback获取到的。           |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| number | 返回L2CAP链路类型套接字的psm值。<br>- [SppType](#spptype)设置为SPP_L2CAP_BLE时，返回值的有效值范围为[0x01, 0xFF]。<br>- [SppType](#spptype)设置为SPP_L2CAP时，返回值的有效值范围为[0x0000, 0xFFFF]。<br>- 服务端通道建立异常或[SppType](#spptype)非L2CAP链路类型时，返回-1。|          

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';

// 服务端获取客户端设备地址。
let serverNumber = 1; // 此处serverNumber需赋值为调用sppListen接口后，回调中得到的serverNumber。
try {
    let l2capPsm: number = socket.getL2capPsm(serverNumber);
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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = -1;
let serverNumber = 1;
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
import { BusinessError } from '@kit.BasicServicesKit';

// 服务端获取客户端设备地址。
let clientSocket = 1; // clientSocket是sppAccept回调中得到的，调用getDeviceId接口前需更新clientSocket。
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
import { BusinessError } from '@kit.BasicServicesKit';

let serverNumber = 1; // 此处serverNumber需赋值为调用sppListen接口后，在回调中得到的serverNumber。
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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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
- 不可以和API version 18开始支持的[socket.sppReadAsync](#socketsppreadasync18)接口混用，同一路socket只能使用socket.on('sppRead')接口或者[socket.sppReadAsync](#socketsppreadasync18)接口。

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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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
import { BusinessError } from '@kit.BasicServicesKit';

let clientNumber = 1; // 入参clientNumber由sppAccept或sppConnect接口获取。
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
- 不可以和API version 10开始支持的[socket.on('sppRead')](#socketonsppread)接口混用，同一路socket只能使用[socket.on('sppRead')](#socketonsppread)接口或者socket.sppReadAsync接口。
- 通过Promise异步返回读取的数据，建议在连接成功后循环调用去获取接收到的数据，若不及时调用会丢失接收的数据。
- 该接口为异步接口，需要等异步回调结果返回后才能进行下一次调用。

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
import { BusinessError } from '@kit.BasicServicesKit';

// 入参clientNumber由sppAccept或sppConnect接口获取。
async function readAsync(clientNumber: number) {
  let flag = 1;
  try {
    while (flag) { // 该接口需业务循环调用读取，具体循环形式按业务需要来实现，这里只是示例。
      let buffer = await socket.sppReadAsync(clientNumber); // 使用await确保顺序读取。
      let data = new Uint8Array(buffer);
      if (data) {
        console.info('sppRead success, data length = ' + data.byteLength);
        // 在此处理接收到的数据。
      }
    }
  } catch (err) {
    console.error('startSppRead errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    socket.sppCloseClientSocket(clientNumber); // 发生错误时关闭连接。
  }
}
```


## SppOptions

描述套接字的配置参数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称     | 类型                | 只读   | 可选   | 说明          |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | 否    | 否    | RFCOMM套接字链路类型的服务UUID，例如"00001101-0000-1000-8000-00805F9B34FB"。<br>- 建议开发者使用自定义的服务UUID（可通过工具函数[util.generateRandomUUID](../apis-arkts/js-apis-util.md#utilgeneraterandomuuid9)生成），也可以使用标准协议定义的Serial Port UUID服务(00001101-0000-1000-8000-00805F9B34FB)。<br>- SppType设置为SPP_RFCOMM时该参数必选。<br>- SppType设置为SPP_L2CAP或SPP_L2CAP_BLE时设置为空字符串。|
| secure | boolean             | 否    | 否    | 是否是安全通道。true表示是安全通道，false表示非安全通道。    |
| type   | [SppType](#spptype)            | 否    | 否    | 蓝牙套接字链路类型。    |
| psm<sup>20+</sup>   | number              | 否    | 是    |协议/服务多路复用器值，用于标识特定的服务数据传输通道。不填写该参数时默认值为-1。<br>对于客户端：<br>- SppType设置为SPP_RFCOMM时，该参数不填。<br>-  SppType设置为SPP_L2CAP_BLE或SPP_L2CAP时，需和服务端的psm值保持一致。<br>对于服务端：<br>- SppType设置为SPP_RFCOMM时，该参数不填。<br>- SppType设置为SPP_L2CAP_BLE时，psm值必须由系统自动分配，有效值范围为[0x01, 0xFF]。<br>- SppType设置为SPP_L2CAP时，psm值可以主动设置或蓝牙子系统分配，若为主动设置，其有效范围为[0x00, 0xFFFF]，并且需要满足低位字节最低位必须为1，高位字节最低位必须为0；若为蓝牙子系统分配，该参数不填，可以通过[socket.getL2capPsm](#socketgetl2cappsm20)接口获取psm值。|




## SppType 

枚举，蓝牙套接字链路类型。

- 不同类型的蓝牙设备需要选取不同的链路类型。
- 针对低功耗蓝牙（BLE）设备，必须使用L2CAP链路类型。
- 针对传统蓝牙（BR/EDR）设备，建议优先采用RFCOMM链路进行连接。其优势在于可通过UUID服务动态协商信道（即设备通过查询服务UUID自动确定通信频道的过程），同时具备更高的安全性和可靠性。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称         | 值  | 说明            |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | 基于传统蓝牙（BR/EDR）的RFCOMM链路。 |
| SPP_L2CAP<sup>20+</sup> | 1    | 基于传统蓝牙（BR/EDR）的L2CAP链路。 |
| SPP_L2CAP_BLE<sup>20+</sup> | 2    | 基于低功耗蓝牙（BLE）的L2CAP链路。 |