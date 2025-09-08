# USB串口通信管理

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

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

> **说明：** 
>
> 以下示例代码只是串口数据传输的必要流程，需要放入具体的方法中执行。

1. 导入模块。

    ```ts
    // 导入serialManager模块。
    import { serialManager } from '@kit.BasicServicesKit';
    import { buffer } from '@kit.ArkTS';
    ``` 

2. 获取设备列表。

    ```ts
    // 获取连接主设备的USB设备列表
    let portList: serialManager.SerialPort[] = serialManager.getPortList();
    console.info(`usbSerial portList: ${portList}`);
    if (portList === undefined || portList.length === 0) {
      console.error('usbSerial portList is empty');
      return;
    }
    ```

3. 获取设备操作权限。

    ```ts
    // 此处对列表中的第一台USB设备判断是否拥有访问权限
    // 函数名仅作为示例，实际需要与业务结合命名
    async function serialDefault() {
      let portId: number = portList[0].portId;
      if (!serialManager.hasSerialRight(portId)) {
        await serialManager.requestSerialRight(portId).then(result => {
          if(!result) {
            // 没有访问设备的权限且用户不授权则退出
            console.error('The user does not have permission to perform this operation');
            return;
          }
        });
      }
    }
    ```

4. 根据串口打开设备。

    ```ts
    try {
      serialManager.open(portId)
      console.info(`open usbSerial success, portId: ${portId}`);
    } catch (error) {
      console.error(`open usbSerial error： ${error}`);
    }
    ```

5. 通过串口读取数据。

    ```ts
    // 异步读取 
    let readBuffer: Uint8Array = new Uint8Array(64);
    serialManager.read(portId, readBuffer, 2000).then((size: number) => {
      console.info(`read usbSerial success, readBuffer: ${readBuffer}`);
    }).catch((error: Error) => {
      console.error(`read usbSerial error: ${error}`);
    })

    // 同步读取
    let readSyncBuffer: Uint8Array = new Uint8Array(64);
    try {
      serialManager.readSync(portId, readSyncBuffer, 2000);
      console.info(`readSync usbSerial success, readSyncBuffer: ${readSyncBuffer}`);
    } catch (error) {
      console.error(`readSync usbSerial error: ${error}`);
    }
    ```

6. 通过串口写入数据。

    ```ts
    // 异步写入
    let writeBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
    serialManager.write(portId, writeBuffer, 2000).then((size: number) => {
      console.info(`write usbSerial success, writeBuffer: ${writeBuffer}`);
    }).catch((error: Error) => {
      console.error(`write usbSerial error: ${error}`);
    })

    // 同步写入
    let writeSyncBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
    try {
      serialManager.writeSync(portId, writeSyncBuffer, 2000);
      console.info(`writeSync usbSerial success, writeSyncBuffer: ${writeSyncBuffer}`);
    } catch (error) {
      console.error(`writeSync usbSerial error: ${error}`);
    }
    ```
   
7. 关闭串口设备。

    ```ts
    try {
      serialManager.close(portId);
      console.info(`close usbSerial success, portId: ${portId}`);
    } catch (error) {
      console.error(`close usbSerial error: ${error}`);
    }
    ```

### 调测验证

1. 准备一根USB转串口线缆，线缆的USB接口连接到OpenHarmony设备USB端口（该端口需支持USB转串口），线缆的串口接口连接到目标设备的串口上。
2. 在OpenHarmony设备上执行上述示例。
3. 返回`usbSerial success`，表示相关接口调用成功，设备串口通信能力正常；返回`usbSerial error`，表示接口调用失败。