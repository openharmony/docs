# USB实时传输

## 场景介绍

实时传输主要用于音频、视频流等实时性较高的数据传输，对数据传输的及时性要求较高，允许一定的数据丢包，具有容错性，属于异步传输。USB耳机、耳麦和摄像头等设备属于这种类型的设备。根据设备支持的端点类型支持实时传输读和写。

## 环境准备

### 环境要求

- 开发工具及配置： DevEco Studio是驱动开发工具，进行驱动开发必备条件之一，我们可以使用该工具进行开发、调试、打包等操作。请[下载安装](https://developer.huawei.com/consumer/cn/download/)该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-tools-overview-V13)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-create-new-project-V13)进行基本的操作验证，保证DevEco Studio可正常运行。
- SDK版本配置： 扩展外设管理提供的ArkTs接口，所需SDK版本为API16及以上版本才可使用。
- HDC配置 HDC（HarmonyOS Device Connector）是为开发人员提供的用于调试的命令行工具，通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互，详细参考[HDC配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/hdc-V5)。

### 搭建环境

- 在PC上安装[DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio)，要求版本在4.1及以上。
- 将public-SDK更新到API 16或以上，更新SDK的具体操作可参见[更新指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/faqs/full-sdk-switch-guide.md)。
- PC安装HDC工具（HarmonyOS Device Connector），通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互，详细参考[HDC配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/hdc-V5)。
- 用USB线缆将搭载HarmonyOS的设备连接到PC。

## 开发指导

### 接口说明

| 接口名                                                                                                              | 描述                                                      |
|------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| usbSubmitTransfer(transfer: UsbDataTransferParams): void                                                         | 异步传输接口（支持实时、批量、中断传输）。                                   |
| usbCancelTransfer(transfer: UsbDataTransferParams): void                                                         | 取消已提交的异步传输。                                             |

详细的接口说明请查阅[API参考文档](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md)。

### 开发步骤

主机端连接终端设备，通过`usbSubmitTransfer`接口进行数据传输。以下步骤描述了如何使用实时传输方式来传输数据：

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

3. 获取通过实时传输读取数据的端点

   ```ts
   let devicePipe: usbManager.USBDevicePipe = usbManager.connectDevice(usbDevice);
   let usbConfigs: usbManager.USBConfiguration[] = usbDevice.configs;
   let usbInterfaces: usbManager.USBInterface[] = [];
   let usbInterface: usbManager.USBInterface | undefined = undefined
   let usbEndpoints: usbManager.USBEndpoint[] = [];
   let usbEndprint: usbManager.USBEndpoint | undefined = undefined
   for (let i = 0; i < usbConfigs.length; i++) {
   usbInterfaces = usbConfigs[i].interfaces;
   for (let i = 0; i < usbInterfaces.length; i++) {
     usbEndpoints = usbInterfaces[i].endpoints;
     usbEndprint = usbEndpoints.find((value) => {
       return value.direction === usbManager.USBRequestDirection.USB_REQUEST_DIR_FROM_DEVICE // 读取数据
         && value.type === usbManager.UsbEndpointTransferType.TRANSFER_TYPE_ISOCHRONOUS; // 实时传输
     })
     if (usbEndprint !== undefined) {
       usbInterface = usbInterfaces[i];
       break;
     }
   }
   }
   if (usbEndprint === undefined) {
     console.error(`get usbEndprint error`)
     return;
   }
   ```
   
4. 连接USB设备，注册通信接口。

    ```ts
    // 注册通信接口，注册成功返回0，注册失败返回其他错误码。
    let claimInterfaceResult: number = usbManager.claimInterface(devicePipe, usbInterface, true);
    if (claimInterfaceResult !== 0) {
      console.error(`claimInterface error = ${claimInterfaceResult}`)
      return;
    }

    // 传输类型类型为“实时传输”时，需设置设备接口。设置成功返回0，注册失败返回其他错误码。
    if (this.type === usbManager.UsbEndpointTransferType.TRANSFER_TYPE_ISOCHRONOUS) {
      let setInterfaceResult = usbManager.setInterface(devicePipe, usbInterface);
      if (setInterfaceResult !== 0) {
        console.info(`setInterfaceResult error = ${setInterfaceResult}`)
        return;
      }
    }
   ```

5. 传输数据。

   ```ts
   try {
     // 通信接口注册成功，传输数据
     let transferParams: usbManager.UsbDataTransferParams = {
       devPipe: devicePipe,
       flags: usbManager.UsbTransferFlags.USB_TRANSFER_SHORT_NOT_OK,
       endpoint: usbEndprint.address,
       type: usbManager.UsbEndpointTransferType.TRANSFER_TYPE_ISOCHRONOUS,
       timeout: 2000,
       length: 10,
       callback: () => {},
       userData: new Uint8Array(10),
       buffer: new Uint8Array(10),
       isoPacketCount: 2,
     };
   
     transferParams.callback = (err: Error, callBackData: usbManager.SubmitTransferCallback) => {
       console.info('callBackData = ' + JSON.stringify(callBackData));
       console.info('transferData = ' + transferParams.buffer.toString());
       this.text = transferParams.buffer.toString()
     }
     console.log(`transferParams: `+ JSON.stringify(transferParams));
     usbManager.usbSubmitTransfer(transferParams);
     console.info('USB transfer request submitted.');
   } catch (error) {
     console.error('USB transfer failed:', error);
   }
   ```

6. 取消传输，释放接口，关闭设备消息控制通道。

    ```ts
    usbManager.usbCancelTransfer(transferParams);
    usbManager.releaseInterface(devicePipe, usbInterface);
    usbManager.closePipe(devicePipe);
    ```