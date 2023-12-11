# 串行通信开发指导

## 简介
SPP是Serial Port Profile（串口协议）的缩写，是一种蓝牙协议，用于在蓝牙设备之间建立串行通信连接。通过SPP，蓝牙设备可以像使用串口一样进行数据传输，例如传输文件、文本等。SPP是蓝牙技术中最常用的协议之一。

## 场景介绍
主要场景有：

- 创建一个服务端监听Socket。
- 服务端监听socket等待客户端连接。
- 客户端向远端设备发起spp连接。
- 关闭服务端/客户端监听Socket。
- 通过socket向远端发送数据。

## 接口说明

完整的 JS API 说明以及实例代码请参考：[SPP 接口](../../reference/apis/js-apis-bluetooth-socket.md)。

具体接口说明如下表。

| 接口名                             | 功能描述                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| sppListen()                        | 创建一个服务端监听Socket。                                                       |
| sppAccept()                        | 服务端监听socket等待客户端连接。                                                  |
| sppConnect()                       | 客户端向远端设备发起spp连接。                                                     |
| sppCloseServerSocket()             | 关闭服务端监听Socket。                                                           |
| sppCloseClientSocket()             | 关闭客户端socket。                                                               |
| sppWrite()                         | 通过socket向远端发送数据。                                                       |
| on(type: 'sppRead')                | 订阅spp读请求事件。                                                              |
| off(type: 'sppRead')               | 取消订阅spp读请求事件。                                                           |

## 主要场景开发步骤
说明：
  - 以下大部分场景的实现，都要提前开启蓝牙，创建服务端Socket。

### 创建服务端Socket
1. 导入模块: import socket from '@ohos.bluetooth.socket'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明:

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| name | string | 是    | 服务的名称。 |
| option | SppOptions | 是    | spp监听配置参数。 |
| callback | AsyncCallback\<number\> | 是    | 表示回调函数的入参，服务端Socket的id。 |
5. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 声明服务端id
let serverNumber = -1;
let sppOption: socket.SppOptions = {
    uuid: '00001101-0000-1000-8000-00805f9b34fb',
    secure: true,
    type: 0
};

// 创建蓝牙服务器监听Socket, 返回服务端ID
try {
    socket.sppListen('server1', sppOption, (code, serverSocketID) => {
        if (code != null) {
            promptAction.showToast({ message: 'sppListen error, code is ' + code.code });
            return;
        } else {
            serverNumber = serverSocketID;
            promptAction.showToast({ message: 'sppListen success, serverNumber = ' + serverNumber });
        }
    });
} catch (err) {
    promptAction.showToast({
        message: 'sppListen failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：执行该用例代码，弹框提示“sppListen success, serverNumber = xxx”，则表示创建服务端监听Socket成功。

### 接收客户端连接
1. 导入模块: import socket from '@ohos.bluetooth.socket'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明:
 
| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| serverSocket | number | 是    | 服务端socket的id。 |
| callback | AsyncCallback\<number\> | 是    | 表示回调函数的入参，客户端socket的id。 |
5. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 调用sppListen生成serverNumber
let serverNumber = -1;
// 声明clientNubmer
let clientNumber = -1;

// socket等待客户端连接
try {
    socket.sppAccept(serverNumber, (code, clientSocketID) => {
        if (code != null) {
            promptAction.showToast({ message: 'sppAccept error, code is ' + code.code });
            return;
        } else {
            clientNumber = clientSocketID;
            promptAction.showToast({ message: 'accept the client success' });
        }
    })
    promptAction.showToast({ message: 'waiting for client connection' });
} catch (err) {
    promptAction.showToast({
        message: 'sppAccept failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：创建服务端监听Socket，执行该用例代码弹框提示“waiting for client connection”。对端手机上安装“SPP蓝牙串口”软件，搜索到测试机的蓝牙后连接，弹框提示“accept the client success”，则表示客户端连接socket连接成功。

### 客户端连接服务端
1. 获取服务端mac地址。
2. 导入模块: import socket from '@ohos.bluetooth.socket'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明:
 
| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceId | string | 是    | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| option | SppOptions | 是    | spp客户端连接配置参数。 |
| callback | AsyncCallback\<number\> | 是    | 表示回调函数的入参，客户端socket的id。 |
6. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 调用bleScan扫描获取deviceId
let deviceId = 'xx:xx:xx:xx:xx:xx';

try {
    socket.sppConnect(deviceId, {
        uuid: '00001101-0000-1000-8000-00805f9b34fb',
        secure: true,
        type: 0
    }, (code, socketID) => {
        if (code != null) {
            promptAction.showToast({ message: 'sppConnect error, code = ' + code.code });
            return;
        }
        promptAction.showToast({ message: 'sppConnect success, socketId = ' + socketID });
    })
} catch (err) {
    promptAction.showToast({
        message: 'sppAccept failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：对端手机的“SPP蓝牙串口”软件开启服务端模式，测试手机开启ble扫描获取deviceId，执行该用例代码，弹框提示“sppConnect success, socketId = x”，则表示客户端向远端设备发起连接成功。

### 向客户端写入数据
1. 成功接收客户端连接。
2. 导入模块: import socket from '@ohos.bluetooth.socket'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明:
 
| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| clientSocket | number | 是    | 客户端socket的id。 |
| data | ArrayBuffer | 是    | 写入的数据。 |
6. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 调用sppAccept生成clientNumber
let clientNumber = -1;

let array = new Uint8Array(990);
array[0] = 'A'.charCodeAt(0);
array[1] = 'B'.charCodeAt(0);
array[2] = 'C'.charCodeAt(0);
array[3] = 'D'.charCodeAt(0);

try {
    socket.sppWrite(clientNumber, array.buffer);
    promptAction.showToast({ message: 'sppWrite success' });
} catch (err) {
    promptAction.showToast({
        message: 'sppWrite failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：创建服务端监听Socket，调用sppAccept接口成功，测试机执行该用例代码，弹框提示“sppWrite success”, 并且对端手机的“SPP蓝牙串口”软件上显示写入的数据，则表示写入数据成功。

### 订阅读请求事件
1. 成功接收客户端连接。
2. 导入模块: import socket from '@ohos.bluetooth.socket'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明:
 
| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| type | string | 是    | 填写"sppRead"字符串，表示spp读请求事件。 |
| clientSocket | number | 是    | 客户端socket的id。 |
| callback | Callback\<ArrayBuffer\> | 是    | 表示回调函数的入参，读取到的数据。 |
6. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 调用sppAccept生成clientNumber
let clientNumber = -1;

try {
    socket.on('sppRead', clientNumber, (dataBuffer: ArrayBuffer) => {
        const data = new Uint8Array(dataBuffer);
        if (data != null) {
            promptAction.showToast({ message: 'sppRead success, data = ' + JSON.stringify(data) });
        } else {
            promptAction.showToast({ message: 'sppRead error, data is null' });
        }
    });
} catch (err) {
    promptAction.showToast({
        message: 'sppRead failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：创建服务端监听Socket，调用sppAccept接口成功，对端手机的“SPP蓝牙串口”软件连接测试机蓝牙成功。执行该用例代码，使用对端手机发送数据，测试手机弹框“sppRead success, data = xxx”，则表示on("sppRead")调用成功。

### 取消订阅读请求事件
1. 成功接收客户端连接。
2. 成功订阅读请求事件。
3. 导入模块: import socket from '@ohos.bluetooth.socket'。
4. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
5. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
6. 参数说明:
 
| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| type | string | 是    | 填写"sppRead"字符串，表示spp读请求事件。 |
| clientSocket | number | 是    | 客户端socket的id。 |
| callback | Callback\<ArrayBuffer\> | 否    | 表示取消订阅spp读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |
7. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 调用sppAccept生成下面数据
let clientNumber = -1;

try {
    socket.off('sppRead', clientNumber, (dataBuffer: ArrayBuffer) => {
        const data = new Uint8Array(dataBuffer);
        if (data != null) {
            promptAction.showToast({ message: 'offSppRead success, data = ' + JSON.stringify(data) });
        } else {
            promptAction.showToast({ message: 'offSppRead error, data is null' });
        }
    });
} catch (err) {
    promptAction.showToast({
        message: 'offSppRead failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
8. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
9. 如何验证：创建服务端监听Socket，调用sppAccept接口成功，对端手机的“SPP蓝牙串口”软件连接测试机蓝牙成功，调用on("sppRead")成功，使用对端手机发送数据，测试手机弹框“sppRead success, data = xxx”。执行该用例代码，对端手机再次发送数据，不会有弹框“sppRead success, data = xxx”，则表示off("sppRead")调用成功。

### 注销服务端Socket
1. 导入模块: import socket from '@ohos.bluetooth.socket'。
2. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
3. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
4. 参数说明:
 
| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| socket | number | 是    | 服务端监听socket的id。 |
5. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 调用sppListen生成serverNumber
let serverNumber = -1;
try {
    socket.sppCloseServerSocket(serverNumber);
    promptAction.showToast({ message: 'sppCloseServerSocket success' });
} catch (err) {
    promptAction.showToast({
        message: 'sppCloseServerSocket failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
6. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
7. 如何验证：创建服务端监听Socket，执行该用例代码，弹框提示“sppCloseServerSocket success”，调用sppAccept接口，会提示参数错误，则表示关闭服务端监听Socket成功。

### 注销客户端Socket
1. 成功接收客户端连接。
2. 导入模块: import socket from '@ohos.bluetooth.socket'。
3. 需要权限: ohos.permission.ACCESS_BLUETOOTH。
4. 需要系统能力: SystemCapability.Communication.Bluetooth.Core。
5. 参数说明:
 
| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| socket | number | 是    | 客户端socket的id。 |
6. 示例代码：
```
import socket from '@ohos.bluetooth.socket';
import { BusinessError } from '@ohos.base';
import promptAction from '@ohos.promptAction';

// 调用sppListen和sppAccept生成下面数据
let serverNumber = -1;
let clientNumber = -1;

// 关闭客户端Socket
try {
    socket.sppCloseClientSocket(clientNumber);
    promptAction.showToast({ message: 'sppCloseClientSocket success' });
} catch (err) {
    promptAction.showToast({
        message: 'sppCloseClientSocket failed, errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message
    });
}
```
7. 错误码请参见[蓝牙服务子系统错误码](../../reference/errorcodes/errorcode-bluetoothManager.md)。
8. 如何验证：创建服务端监听Socket，调用sppAccept接口成功，执行该用例代码，弹框提示“sppCloseClientSocket success”, 则表示关闭客户端监听Socket成功。