# USB服务开发指导

## 场景介绍

Host模式下，可以获取到已经连接的USB设备列表，并根据需要打开和关闭设备、控制设备权限、进行数据传输等。

## 接口说明

USB服务主要提供的功能有：查询USB设备列表、批量数据传输、控制命令传输、权限控制等。

USB类开放能力如下，具体请查阅[API参考文档](../../reference/apis-basic-services-kit/js-apis-usbManager.md)。

**表1** USB类的开放能力接口

| 接口名                                                                                                              | 描述                                                      |
|------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| getDevices(): Array<Readonly<USBDevice>>                                                                         | 获取接入主设备的USB设备列表。如果没有设备接入，那么将会返回一个空的列表。                  |
| connectDevice(device: USBDevice): Readonly<USBDevicePipe>                                                        | 根据`getDevices()`返回的设备信息打开USB设备。                         |
| hasRight(deviceName: string): boolean                                                                            | 判断是否有权访问该设备。                                            |
| requestRight(deviceName: string): Promise<boolean>                                                               | 请求软件包的临时权限以访问设备。使用Promise异步回调。系统应用默认拥有访问设备权限，无需调用此接口申请。 |
| removeRight(deviceName: string): boolean                                                                         | 移除软件包访问设备的权限。系统应用默认拥有访问设备权限，调用此接口不会产生影响。                |
| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number                                | 注册通信接口。                                                 |
| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number                                               | 释放注册过的通信接口。                                             |
| setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number                                          | 设置设备配置。                                                 |
| setInterface(pipe: USBDevicePipe, iface: USBInterface): number                                                   | 设置设备接口。                                                 |
| getRawDescriptor(pipe: USBDevicePipe): Uint8Array                                                                | 获取原始的USB描述符。                                            |
| getFileDescriptor(pipe: USBDevicePipe): number                                                                   | 获取文件描述符。                                                |
| controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout?: number): Promise<number>          | 控制传输。                                                   |
| usbControlTransfer(pipe: USBDevicePipe, requestparam: USBDeviceRequestParams, timeout?: number): Promise<number> | 控制传输。                                                   |
| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number): Promise<number>  | 批量传输。                                                   |
| usbSubmitTransfer(transfer: UsbDataTransferParams): void                                                         | 异步传输接口（支持实时、批量、中断传输）。                                   |
| usbCancelTransfer(transfer: UsbDataTransferParams): void                                                         | 取消已提交的异步传输。                                             |
| closePipe(pipe: USBDevicePipe): number                                                                           | 关闭设备消息控制通道。                                             |
| hasAccessoryRight(accessory: USBAccessory): boolean                                                              | 检查应用程序是否有权访问USB配件。                                      |
| requestAccessoryRight(accessory: USBAccessory): Promise<boolean>                                                 | 为指定应用程序申请访问USB配件的访问权限。                                  |
| cancelAccessoryRight(accessory: USBAccessory): void                                                              | 取消当前应用程序访问USB配件的权限。                                     |
| getAccessoryList(): Array<Readonly<USBAccessory>>                                                                | 获取当前已接入主机的USB配件列表。                                      |
| openAccessory(accessory: USBAccessory): USBAccessoryHandle                                                       | 获取配件句柄并打开配件文件描述符。                                       |
| closeAccessory(accessoryHandle: USBAccessoryHandle): void                                                        | 关闭配件文件描述符。                                              |


## 开发步骤

USB设备连接Device设备通过usbSubmitTransfer接口进行数据传输。开发示例如下：

1. 获取设备列表。

```ts
// 导入usbManager
import { usbManager } from '@kit.BasicServicesKit';

// 获取连接主设备的USB设备列表
let usbDevices: Array<usbManager.USBDevice> = usbManager.getDevices();
console.info('usbDevices: ', JSON.stringify(usbDevices));
if(usbDevices.length === 0) {
  console.info('usbDevices is empty');
  return;
}
```

2. 获取设备操作权限。

```ts
// 此处对列表中的第一台USB设备判断是否拥有访问权限
let usbDevice: usbManager.USBDevice = usbDevices[0];
if(!usbManager.hasRight(usbDevice.name)) {
  await usbManager.requestRight(usbDevice.name).then(result => {
    if(!result) {
      // 没有访问设备的权限且用户不授权则退出
      console.info('user is not granted the operation permission');
      return;
    }
  });
}
```

3.连接USB设备，注册通信接口。

```ts
// 根据USB设备信息连接USB设备
let devicePipe: usbManager.USBDevicePipe = usbManager.connectDevice(usbDevice);
let interfaces: usbManager.USBInterface = usbDevice.configs[0].interfaces[0];

// 注册通信接口，注册成功返回0，注册失败返回其他错误码。
let claimInterfaceResult: number = usbManager.claimInterface(devicePipe, interfaces, true);
if (claimInterfaceResult !== 0) {
  console.error(`claimInterface error = ${claimInterfaceResult}`)
  return;
}
```

4.传输数据。

```ts
try {
  // 通信接口注册成功，传输数据
  let transferParams: usbManager.UsbDataTransferParams = {
    devPipe: devicePipe,
    flags: usbManager.UsbTransferFlags.USB_TRANSFER_SHORT_NOT_OK,
    endpoint: 0,
    type: usbManager.UsbEndpointTransferType.TRANSFER_TYPE_BULK,
    timeout: 2000,
    length: 10,
    callback: () => {},
    userData: new Uint8Array(10),
    buffer: new Uint8Array(10),
    isoPacketCount: 0,
  };

  // direction为读或者写数据的请求方向。type为传输类型。此处应根据实际开发场景确认。
  let endpoint: usbManager.USBEndpoint | undefined = interfaces.endpoints.find((value) => {
    return value.direction === usbManager.USBRequestDirection.USB_REQUEST_DIR_FROM_DEVICE
      && value.type === usbManager.UsbEndpointTransferType.TRANSFER_TYPE_INTERRUPT;
  })
  if(typeof endpoint === 'undefined') {
    return;
  }

  transferParams.endpoint = endpoint.address
  transferParams.callback = (err: Error, callBackData: usbManager.SubmitTransferCallback) => {
    console.info('callBackData = ' + JSON.stringify(callBackData));
    console.info('transferData = ' + transferParams.buffer.toString())
  }
  console.log(`transferParams: `+ JSON.stringify(transferParams));
  usbManager.usbSubmitTransfer(transferParams);
  console.info('USB transfer request submitted.');
} catch (error) {
  console.error('USB transfer failed:', error);
}
```

5.关闭设备消息控制通道。

```ts
usbManager.closePipe(this.usbDevicePipe);
```

## 相关实例

针对USB管理开发，有以下相关实例可供参考：

- [`DeviceManagementCollection`：设备管理合集（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/DeviceManagementCollection)