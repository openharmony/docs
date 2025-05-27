# USB串口通信管理

## 简介

USB串口通信服务中通过Host设备的USB接口连接串口设备的串口进行串行数据传输，通信管理核心目标是实现设备间的高效、稳定数据传输与协同控制。主要使用在工业自动化与远程监控、物联网设备互联、医疗设备管理等场景。

## 环境准备

请参考USB串口通信服务开发概述[环境准备](usbSerial-overview.md#环境准备)。

## 开发指导

### 接口说明

| 接口名                                                                          | 描述                       |
|------------------------------------------------------------------------------|--------------------------|
| getPortList(): Readonly&lt;SerialPort&gt;[]                                        | 获取串口设备列表。                |
| hasSerialRight(portId: number): boolean                                      | 检查应用程序是否具有访问串口设备的权限。     |
| requestSerialRight(portId: number): Promise&lt;boolean&gt;                         | 请求对串口设备的访问权限。            |
| open(portId: number): void                                                   | 打开串口设备。                  |
| close(portId: number): void                                                  | 关闭串口设备。                  |
| read(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;  | 从串口设备读取数据，使用Promise异步返回。 |
| readSync(portId: number, buffer: Uint8Array, timeout?: number): number       | 以同步方法从串口设备读取数据。          |
| write(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt; | 往串口设备写入数据，使用Promise异步返回。 |
| writeSync(portId: number, buffer: Uint8Array, timeout?: number): number      | 以同步方法往串口设备写入数据。          |


### 开发步骤

开发者可以通过上述接口读取和写入数据：

1. 导入模块。

    ```ts
    // 导入usbManager模块。
    import serial from '@ohos.usbManager.serial';
    import { buffer } from '@kit.ArkTS';
    ``` 

2. 获取设备列表。

    ```ts
    // 获取连接主设备的USB设备列表
    let portList: serial.SerialPort[] = serial.getPortList();
    console.info('usbSerial portList: ' + JSON.stringify(portList));
    if (portList === undefined || portList.length === 0) {
      console.info('usbSerial portList is empty');
      return;
    }
    ```

3. 获取设备操作权限。

    ```ts
    // 此处对列表中的第一台USB设备判断是否拥有访问权限
    let portId: number = portList[0].portId;
    if (!serial.hasSerialRight(portId)) {
      await serial.requestSerialRight(portId).then(result => {
        if(!result) {
          // 没有访问设备的权限且用户不授权则退出
          console.info('usbSerial user is not granted the operation permission');
          return;
        }
      });
    }
    ```

4. 根据串口打开设备。

    ```ts
    try {
      serial.open(portId)
      console.info('open usbSerial success, portId: ' + portId);
    } catch (error) {
      console.error('open usbSerial error, ' + JSON.stringify(error));
    }
    ```

5. 通过串口读取数据。

    ```ts
    // 异步读取 
    let readBuffer: Uint8Array = new Uint8Array(64);
    serial.read(portId, readBuffer, 2000).then((size: number) => {
      console.info('read usbSerial success, readBuffer: ' + readBuffer.toString());
    }).catch((error: Error) => {
      console.error('read usbSerial error, ' + JSON.stringify(error));
    })

    // 同步读取
    let readSyncBuffer: Uint8Array = new Uint8Array(64);
    try {
      serial.readSync(portId, readSyncBuffer, 2000);
      console.info('readSync usbSerial success, readSyncBuffer: ' + readSyncBuffer.toString());
    } catch (error) {
      console.error('readSync usbSerial error, ' + JSON.stringify(error));
    }
    ```

6. 通过串口写入数据。

    ```ts
    // 异步写入
    let writeBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
    serial.write(portId, writeBuffer, 2000).then((size: number) => {
      console.info('write usbSerial success, writeBuffer: ' + writeBuffer.toString());
    }).catch((error: Error) => {
      console.error('write usbSerial error, ' + JSON.stringify(error));
    })

    // 同步写入
    let writeSyncBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
    try {
      serial.writeSync(portId, writeSyncBuffer, 2000);
      console.info('writeSync usbSerial success, writeSyncBuffer: ' + writeSyncBuffer.toString());
    } catch (error) {
      console.error('writeSync usbSerial error, ' + JSON.stringify(error));
    }
    ```
   
7. 关闭串口设备

    ```ts
    try {
      serial.close(portId);
      console.info('close usbSerial success, portId: ' + portId);
    } catch (error) {
      console.error('close usbSerial error, ' + JSON.stringify(error));
    }
    ```

### 调测验证

1. 准备一根USB转串口线缆，线缆的USB接口连接到OpenHarmony设备USB端口（该端口需支持USB转串口），线缆的串口接口连接到目标设备的串口上。
2. 在OpenHarmony设备上执行上述示例。
3. 返回`usbSerial success`，表示相关接口调用成功，设备串口通信能力正常；返回`usbSerial error`，表示接口调用失败。