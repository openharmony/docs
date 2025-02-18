# USB串行端口设备开发指导

## 场景介绍

可以获取到已经连接的USB设备列表，并根据需要打开和关闭设备、控制设备权限、进行数据传输等。

## 接口说明

USB串行端口能力主要提供的功能有：查询USB设备列表、批量数据传输、控制命令传输、权限控制等。

USB串行端口能力如下。

| 接口名                                                                          | 描述                        |
|------------------------------------------------------------------------------|---------------------------|
| getPortList(): Readonly<SerialPort>[]                                        | 获取串行端口设备列表                |
| hasSerialRight(portId: number): boolean                                      | 检查应用程序是否具有访问串行端口的权限       |
| requestSerialRight(portId: number): Promise<boolean>                         | 请求对串行端口的访问权限              |
| addSerialRight(tokenId: number, portId: number): void                        | 添加对串行设备的访问权限              |
| cancelSerialRight(portId: number): void                                      | 移除对串行设备的访问权限              |
| open(portId: number): void                                                   | 打开串行端口设备                  |
| close(portId: number): void                                                  | 关闭串行端口设备                  |
| getAttribute(portId: number): Readonly<SerialAttribute>                      | 获取串行端口设备属性                |
| setAttribute(portId: number, attribute: SerialAttribute): void               | 设置串行端口设备属性                |
| read(portId: number, buffer: Uint8Array, timeout?: number): Promise<number>  | 从串行端口设备读取数据，使用Promise异步返回 |
| readSync(portId: number, buffer: Uint8Array, timeout?: number): number       | 以同步方法从串行端口设备读取数据          |
| write(portId: number, buffer: Uint8Array, timeout?: number): Promise<number> | 往串行端口设备写入数据，使用Promise异步返回 |
| writeSync(portId: number, buffer: Uint8Array, timeout?: number): number      | 以同步方法往串行端口设备写入数据          |

## 开发步骤

1. 导入USB串行端口API包。

```ts
import serial from '@ohos.usbManager.serial'
```

2. 获取设备列表，申请访问权限。

```ts
let portList: serial.SerialPort[] = serial.getPortList();
if(portList.length < 1) {
  console.info('port list is null');
  return;
}

// 此处对列表中的第一台USB设备判断是否拥有访问权限
let usbPortId: number = portList[0].portId;
if (!serial.hasSerialRight(usbPortId)) {
  if (!await serial.requestSerialRight(usbPortId)) {
    // 没有访问串行端口的权限且用户不授权则退出
    console.info('user is not granted the operation permission');
    return
  }
}
```

3.打开串行端口设备，传输数据。

```ts
try {
  // 打开端口
  serial.open(usbPortId);
  
  // 同步读数据
  let dataBuffer: Uint8Array = new Uint8Array(80);
  serial.readSync(usbPortId, dataBuffer, 2000);
  console.info('readSync end: ', dataBuffer.toString());

  // 同步写数据
  let writeStr: string = 'Hello World';
  serial.writeSync(usbPortId, new Uint8Array(buffer.from(writeStr, 'utf-8').buffer), 500);
} catch (err) {
  serial.close(usbPortId);
  console.error('serial err', err);
}
```

4.关闭串行端口设备
```ts
serial.close(usbPortId);
```