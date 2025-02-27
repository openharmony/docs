# USB串口通信管理

## 场景介绍

本模块主要提供USB Host转串口协议通信的功能，USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备。
它提供获取USB Host转串口协议的、已连接的端口列表，同时提供打开端口、关闭端口、设置参数、获取参数、读取数据、写入数据和设备权限管理这些基本功能。

USB Host转串口协议的端口以下简称串口。

## 环境准备

### 环境要求

- 开发工具及配置：

  DevEco Studio作为开发工具，是进行开发必备条件之一，开发者可以使用该工具进行开发、调试、打包等操作。请[下载安装](https://developer.huawei.com/consumer/cn/download/)该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V14/ide-tools-overview-V14)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V14/ide-create-new-project-V14)进行基本的操作验证，保证DevEco Studio可正常运行。

- SDK版本配置：

  本模块提供的ArkTs接口，所需SDK版本为API16及以上才可使用。

### 搭建环境

- 在PC上安装[DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio)，要求版本在4.1及以上。
- 将public-SDK更新到API 16或以上，更新SDK的具体操作可参见[更新指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/faqs/full-sdk-switch-guide.md)。
- USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备。

## 开发指导

### 接口说明

| 接口名                                                                          | 描述                        |
|------------------------------------------------------------------------------|---------------------------|
| getPortList(): Readonly&lt;SerialPort&gt;[]                                        | 获取串口设备列表                |
| hasSerialRight(portId: number): boolean                                      | 检查应用程序是否具有访问串口设备的权限       |
| requestSerialRight(portId: number): Promise&lt;boolean&gt;                         | 请求对串口设备的访问权限              |
| open(portId: number): void                                                   | 打开串口设备                  |
| close(portId: number): void                                                  | 关闭串口设备                  |
| read(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;  | 从串口设备读取数据，使用Promise异步返回 |
| readSync(portId: number, buffer: Uint8Array, timeout?: number): number       | 以同步方法从串口设备读取数据          |
| write(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt; | 往串口设备写入数据，使用Promise异步返回 |
| writeSync(portId: number, buffer: Uint8Array, timeout?: number): number      | 以同步方法往串口设备写入数据          |


### 开发步骤

USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备，以下步骤介绍了关键接口的调用方式：

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

1. USB线缆一端连接到OpenHarmony设备，另一端连接到标准串口设备。
2. 执行上述代码。
3. log中关键字`usbSerial success`，表示接口调用成功，关键字`usbSerial error`，表示接口调用失败。