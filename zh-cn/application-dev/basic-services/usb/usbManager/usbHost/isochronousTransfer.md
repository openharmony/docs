# USB实时传输

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--SE: @w00373942-->
<!--TSE: @dong-dongzhen-->

## 场景介绍

实时传输是通过USB协议在固定时间窗口内完成数据传输，确保数据流的时序稳定性和低延迟，但允许少量数据丢失（如视频丢帧、音频杂音）的传输模式。这种传输方式适用于USB耳机、USB音响、视频会议设备等对连续性要求高、容错性强的场景。

## 环境准备

### 环境要求

- 开发工具及配置：

  DevEco Studio作为驱动开发工具，是进行驱动开发必备条件之一，开发者可以使用该工具进行开发、调试、打包等操作。请[下载安装](https://developer.huawei.com/consumer/cn/download/)该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-tools-overview)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-create-new-project)进行基本的操作验证，保证DevEco Studio可正常运行。


- SDK版本配置：

  扩展外设管理提供的ArkTs接口，所需SDK版本为API16及以上才可使用。


- HDC配置：

  HDC（HarmonyOS Device Connector）是为开发人员提供的用于调试的命令行工具，通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互，详细参考[HDC配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/hdc)。

### 搭建环境

- 在PC上安装[DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio)，要求版本在4.1及以上。
- 将public-SDK更新到API 16或以上<!--Del-->，更新SDK的具体操作可参见[更新指南](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/faqs/full-sdk-switch-guide.md)<!--DelEnd-->。
- PC安装HDC工具，通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互。
- 用USB线缆将搭载OpenHarmony的设备连接到PC。

## 开发指导

### 接口说明

| 接口名                                                                                                              | 描述                                                      |
|------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| usbSubmitTransfer(transfer: UsbDataTransferParams): void                                                         | 异步传输接口（支持实时、批量、中断传输）。                                   |
| usbCancelTransfer(transfer: UsbDataTransferParams): void                                                         | 取消已提交的异步传输。                                             |

更多关于设备管理和传输模式的详细接口介绍，请查阅[API参考文档](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md)。

### 开发步骤

主机（Host）连接设备（Device），通过`usbSubmitTransfer`接口进行数据传输。以下步骤描述了如何使用实时传输方式来传输数据：

> **说明：** 
>
> 以下示例代码只是使用实时传输方式来传输数据的必要流程，需要放入具体的方法中执行。在实际调用时，设备开发者需要遵循设备相关协议进行调用，确保数据的正确传输和设备的兼容性。

1. 导入模块。

    ```ts
    // 导入usbManager模块。
    import { usbManager } from '@kit.BasicServicesKit';
    ``` 

2. 获取设备列表。

    ```ts
    // 获取连接主设备的USB设备列表
    let usbDevices: Array<usbManager.USBDevice> = usbManager.getDevices();
    console.info(`usbDevices: ${usbDevices}`);
    if(usbDevices.length === 0) {
      console.error('usbDevices is empty');
      return;
    }
    ```

3. 获取设备操作权限。

    ```ts
    // 此处对列表中的第一台USB设备判断是否拥有访问权限
    // 函数名仅作为示例，实际需要与业务结合命名
    async function transferDefault() {
        let usbDevice: usbManager.USBDevice = usbDevices[0];
        if(!usbManager.hasRight(usbDevice.name)) {
          await usbManager.requestRight(usbDevice.name).then(result => {
            if(!result) {
              // 没有访问设备的权限且用户不授权则退出
              console.error('The user does not have permission to perform this operation');
              return;
            }
          });
        }
    }
    ```

4. 获取通过实时传输读取数据的端点。

   ```ts
   let devicePipe: usbManager.USBDevicePipe = usbManager.connectDevice(usbDevice);
   let usbConfigs: usbManager.USBConfiguration[] = usbDevice.configs;
   let usbInterfaces: usbManager.USBInterface[] = [];
   let usbInterface: usbManager.USBInterface | undefined = undefined
   let usbEndpoints: usbManager.USBEndpoint[] = [];
   let usbEndpoint: usbManager.USBEndpoint | undefined = undefined
   for (let i = 0; i < usbConfigs.length; i++) {
     usbInterfaces = usbConfigs[i].interfaces;
     for (let j = 0; j < usbInterfaces.length; j++) {
       usbEndpoints = usbInterfaces[j].endpoints;
       usbEndpoint = usbEndpoints.find((value) => {
         // direction为请求方向，0表示写入数据，128表示读取数据
         return value.direction === 128 && value.type === usbManager.UsbEndpointTransferType.TRANSFER_TYPE_ISOCHRONOUS;
       })
       if (usbEndpoint !== undefined) {
         usbInterface = usbInterfaces[j];
         break;
       }
     }
   }
   if (usbEndpoint === undefined) {
     console.error(`get usbEndpoint error`)
     return;
   }
   ```
   
5. 连接设备，注册通信接口。

    ```ts
    // 注册通信接口，注册成功返回0，注册失败返回其他错误码。
    let claimInterfaceResult: number = usbManager.claimInterface(devicePipe, usbInterface, true);
    if (claimInterfaceResult !== 0) {
      console.error(`claimInterface error = ${claimInterfaceResult}`)
      return;
    }

    // 传输类型类型为“实时传输”时，需设置设备接口。设置成功返回0，注册失败返回其他错误码。
    if (usbEndpoint.type === usbManager.UsbEndpointTransferType.TRANSFER_TYPE_ISOCHRONOUS) {
      let setInterfaceResult = usbManager.setInterface(devicePipe, usbInterface);
      if (setInterfaceResult !== 0) {
        console.error(`setInterfaceResult error = ${setInterfaceResult}`)
        return;
      }
    }
    ```

6. 传输数据。

   ```ts
   try {
     // 通信接口注册成功，传输数据
     let transferParams: usbManager.UsbDataTransferParams = {
       devPipe: devicePipe,
       flags: usbManager.UsbTransferFlags.USB_TRANSFER_SHORT_NOT_OK,
       endpoint: usbEndpoint.address,
       type: usbManager.UsbEndpointTransferType.TRANSFER_TYPE_ISOCHRONOUS,
       timeout: 2000,
       length: 10,
       callback: () => {},
       userData: new Uint8Array(10),
       buffer: new Uint8Array(10),
       isoPacketCount: 2,
     };
   
     transferParams.callback = (err: Error, callBackData: usbManager.SubmitTransferCallback) => {
       console.info(`callBackData = ${callBackData}`);
       console.info('transfer success，result = ' + transferParams.buffer.toString());
     }
     usbManager.usbSubmitTransfer(transferParams);
     console.info('USB transfer request submitted.');
   } catch (error) {
     console.error(`USB transfer failed: ${error}`);
   }
   ```

7. 取消传输，释放接口，关闭设备消息控制通道。

    ```ts
    usbManager.usbCancelTransfer(transferParams);
    usbManager.releaseInterface(devicePipe, usbInterface);
    usbManager.closePipe(devicePipe);
    ```

### 调测验证

1. 主机端通过USB接口连接支持实时传输的设备（USB耳机等）。
2. 执行上述代码。
3. log中搜索关键字`transfer success`，表示实时传输接口调用成功。