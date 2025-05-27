# 传输数据

## 简介
SPP是Serial Port Profile（串口协议）的缩写，是一种蓝牙协议，用于在蓝牙设备之间建立串行通信连接。通过SPP，蓝牙设备可以像使用串口一样进行数据传输，例如传输文件、文本等。

## 场景介绍

主要场景有：
- 服务端向客户端发送数据。
- 通过socket建立与对端设备的连接。

## 接口说明

完整的JS API说明以及示例代码请参考：[SPP接口](../../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md)。

具体接口说明如下表。

| 接口名                             | 功能描述                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| sppListen()                        | 创建一个服务端监听socket。                                                       |
| sppAccept()                        | 服务端监听socket等待客户端连接。                                                  |
| sppConnect()                       | 客户端向远端设备发起spp连接。                                                     |
| sppCloseServerSocket()             | 关闭服务端监听socket。                                                           |
| sppCloseClientSocket()             | 关闭客户端socket。                                                               |
| sppWrite()                         | 通过socket向远端发送数据。                                                       |
| on(type: 'sppRead')                | 订阅spp读请求事件。                                                              |
| off(type: 'sppRead')               | 取消订阅spp读请求事件。                                                           |

## 主要场景开发步骤

### 服务端向客户端发送数据
1. 导入所需的socket模块。
2. 需要SystemCapability.Communication.Bluetooth.Core系统能力。
3. 需要申请权限ohos.permission.ACCESS_BLUETOOTH。
4. 开启设备蓝牙。
5. 创建服务端socket，并返回serverId。
6. 服务端等待客户端连接，并返回clientId。
7. 服务端向客户端发送数据。
8. （可选）服务端订阅客户端发送的数据。
9. 注销服务端socket。
10. 注销客户端socket。
11. 示例代码：

    ```ts
    import { socket } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    // 创建服务器监听Socket, 返回serverId
    let serverNumber = -1;
    let sppOption: socket.SppOptions = {
      uuid: '00001101-0000-1000-8000-00805f9b34fb',
      secure: true,
      type: 0
    };
    socket.sppListen('server1', sppOption, (code, serverSocketID) => {
      if (code != null) {
        console.error('sppListen error, code is ' + (code as BusinessError).code);
        return;
      } else {
        serverNumber = serverSocketID;
        console.info('sppListen success, serverNumber = ' + serverNumber);
      }
    });

    // socket等待客户端连接，连接成功返回clientId
    let clientNumber = -1;
    socket.sppAccept(serverNumber, (code, clientSocketID) => {
      if (code != null) {
        console.error('sppAccept error, code is ' + (code as BusinessError).code);
        return;
      } else {
        clientNumber = clientSocketID;
        console.info('accept the client success');
      }
    })
    console.info('waiting for client connection');

    // 服务端向客户端发送数据
    let array = new Uint8Array(990);
    array[0] = 'A'.charCodeAt(0);
    array[1] = 'B'.charCodeAt(0);
    array[2] = 'C'.charCodeAt(0);
    array[3] = 'D'.charCodeAt(0);
    socket.sppWrite(clientNumber, array.buffer);
    console.info('sppWrite success');

    // 订阅读请求事件
    socket.on('sppRead', clientNumber, (dataBuffer: ArrayBuffer) => {
      const data = new Uint8Array(dataBuffer);
      if (data != null) {
        console.info('sppRead success, data = ' + JSON.stringify(data));
      } else {
        console.error('sppRead error, data is null');
      }
    });

    // 取消订阅读请求事件
    socket.off('sppRead', clientNumber, (dataBuffer: ArrayBuffer) => {
      const data = new Uint8Array(dataBuffer);
      if (data != null) {
        console.info('offSppRead success, data = ' + JSON.stringify(data));
      } else {
        console.error('offSppRead error, data is null');
      }
    });

    // 注销服务端socket
    socket.sppCloseServerSocket(serverNumber);
    console.info('sppCloseServerSocket success');

    // 注销客户端socket
    socket.sppCloseClientSocket(clientNumber);
    console.info('sppCloseClientSocket success');
    ```

11. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。

### 通过socket连接对端设备
1. 导入所需的socket模块。
2. 需要SystemCapability.Communication.Bluetooth.Core系统能力。
3. 开启设备蓝牙。
4. 启用BLE扫描功能，获取对端设备的MAC地址。
5. 建立与对端设备的连接。
6. 示例代码：

    ```ts
    import { socket } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    // 开启ble扫描，获取对端设备mac地址
    let deviceId = 'xx:xx:xx:xx:xx:xx';

    // 连接对端设备
    socket.sppConnect(deviceId, {
      uuid: '00001101-0000-1000-8000-00805f9b34fb',
      secure: true,
      type: 0
    }, (code, socketID) => {
      if (code != null) {
        console.error('sppConnect error, code = ' + (code as BusinessError).code);
        return;
      }
      console.info('sppConnect success, socketId = ' + socketID);
    })
    ```

7. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。