# USB服务开发指导

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--SE: @w00373942-->
<!--TSE: @dong-dongzhen-->

## 场景介绍

Host模式下，可以获取到已经连接的USB设备列表，并根据需要打开和关闭设备、控制设备权限、进行数据传输等。


## 接口说明

USB服务主要提供的功能有：查询USB设备列表、批量数据传输、控制命令传输、权限控制等。

USB类开放能力如下，具体请查阅[API参考文档](../../reference/apis-basic-services-kit/js-apis-usbManager.md)。

**表1** USB类的开放能力接口

| 接口名                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| hasRight(deviceName: string): boolean                         | 判断是否有权访问该设备。 |
| requestRight(deviceName: string): Promise&lt;boolean&gt;       | 请求软件包的临时权限以访问设备。使用Promise异步回调。                        |
| removeRight(deviceName: string): boolean | 移除软件包对设备的访问权限。|
| connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt; | 根据`getDevices()`返回的设备信息打开USB设备。如果USB服务异常，可能返回`undefined`，注意需要对接口返回值做判空处理。                |
| getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;          | 获取接入主设备的USB设备列表。如果没有设备接入，那么将会返回一个空的列表。开发者模式关闭时，如果没有设备接入，接口可能返回`undefined`，注意需要对接口返回值做判空处理。                                            |
| setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number | 设置设备的配置。                                             |
| setInterface(pipe: USBDevicePipe, iface: USBInterface): number   | 设置设备的接口。                                             |
| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force ?: boolean): number | 注册通信接口。                                                   |
| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout ?: number): Promise&lt;number&gt; | 批量传输。                                                   |
| closePipe(pipe: USBDevicePipe): number                         | 关闭设备消息控制通道。                                       |
| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | 释放注册过的通信接口。                                                   |
| getFileDescriptor(pipe: USBDevicePipe): number                 | 获取文件描述符。                                             |
| getRawDescriptor(pipe: USBDevicePipe): Uint8Array              | 获取原始的USB描述符。如果USB服务异常，可能返回`undefined`，注意需要对接口返回值做判空处理。                                        |
| usbControlTransfer(pipe: USBDevicePipe, requestparam: USBDeviceRequestParams, timeout?: number): Promise&lt;number&gt; | 控制传输。                                                   |


## 开发步骤

USB设备可作为Host设备连接Device设备进行数据传输。开发示例如下：


1. 获取设备列表。

   ```ts
   // 导入USB接口api包。
   import { usbManager } from '@kit.BasicServicesKit';
   // 获取设备列表。
   let deviceList : Array<usbManager.USBDevice> = usbManager.getDevices();
   /*
   deviceList结构示例
   [
     {
       name: "1-1",
       serial: "",
       manufacturerName: "",
       productName: "",
       version: "",
       vendorId: 7531,
       productId: 2,
       clazz: 9,
       subClass: 0,
       protocol: 1,
       devAddress: 1,
       busNum: 1,
       configs: [
         {
           id: 1,
           attributes: 224,
           isRemoteWakeup: true,
           isSelfPowered: true,
           maxPower: 0,
           name: "1-1",
           interfaces: [
             {
               id: 0,
               protocol: 0,
               clazz: 9,
               subClass: 0,
               alternateSetting: 0,
               name: "1-1",
               endpoints: [
                 {
                   address: 129,
                   attributes: 3,
                   interval: 12,
                   maxPacketSize: 4,
                   direction: 128,
                   number: 1,
                   type: 3,
                   interfaceId: 0,
                 }
               ]
             }
           ]
         }
       ]
     }
   ]
   */
   ```

2. 获取设备操作权限。

   ```ts
   import { usbManager } from '@kit.BasicServicesKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let deviceName : string = deviceList[0].name;
   // 申请操作指定的device的操作权限。
   usbManager.requestRight(deviceName).then((hasRight : boolean) => {
     console.info(`usb device request right result: ${hasRight}`);
   }).catch((error : BusinessError)=> {
     console.error(`usb device request right failed : ${error}`);
   });
   ```

3. 打开Device设备。

   ```ts
   // 打开设备，获取数据传输通道。
   let pipe : usbManager.USBDevicePipe = usbManager.connectDevice(deviceList[0]);
   let interface1 : usbManager.USBInterface = deviceList[0].configs[0].interfaces[0];
   /*
    打开对应接口，在设备信息（deviceList）中选取对应的interface。
   interface1为设备配置中的一个接口。
   */
   usbManager.claimInterface(pipe, interface1, true);
   ```

4. 数据传输。当前仅支持批量传输和控制传输。

    - 批量传输

    ```ts
    import { usbManager } from '@kit.BasicServicesKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    /*
      读取数据，在device信息中选取对应数据接收的endpoint来做数据传输
    （endpoint.direction == 0x80）；dataUint8Array是要读取的数据，类型为Uint8Array。
    */
    let inEndpoint : usbManager.USBEndpoint = interface1.endpoints[2];
    let outEndpoint : usbManager.USBEndpoint = interface1.endpoints[1];
    let dataUint8Array : Uint8Array = new Uint8Array(1024);
    usbManager.bulkTransfer(pipe, inEndpoint, dataUint8Array, 15000).then((dataLength : number) => {
    if (dataLength >= 0) {
      console.info(`usb readData result Length : ${dataLength}`);
    } else {
      console.error(`usb readData failed`);
    }
    }).catch((error : BusinessError) => {
    console.error(`usb readData error : ${error}`);
    });
    // 发送数据，在device信息中选取对应数据发送的endpoint来做数据传输。（endpoint.direction == 0）
    usbManager.bulkTransfer(pipe, outEndpoint, dataUint8Array, 15000).then((dataLength : number) => {
      if (dataLength >= 0) {
        console.info(`usb writeData result write length : ${dataLength}`);
      } else {
        console.error("usb writeData failed");
      }
    }).catch((error : BusinessError) => {
      console.error(`usb writeData error : ${error}`);
    });
    ```

    - 控制传输

    ```ts
    import { usbManager } from '@kit.BasicServicesKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    /*
      构造控制传输参数
    */
    let param: usbManager.USBDeviceRequestParams = {
      bmRequestType: 0x80,    //0x80指一次由设备到主机的标准请求命令
      bRequest: 0x06,    //0x06指获取描述符
      wValue:0x01 << 8 | 0,    //该值为2个字节，高字节指描述符类型，此处0x01指设备描述符；低字节指描述符索引，设备描述符不涉及，填0
      wIndex: 0,    //索引值，可填0
      wLength: 18,    //描述符的长度，此处18表示设备描述符长度，最大支持1024
      data: new Uint8Array(18)
    };

    usbManager.usbControlTransfer(pipe, param).then((ret: number) => {
    console.info(`usbControlTransfer = ${ret}`);
    })
    ```

5. 释放接口，关闭设备。

   ```ts
   usbManager.releaseInterface(pipe, interface1);
   usbManager.closePipe(pipe);
   ```

## 相关实例

针对USB管理开发，有以下相关实例可供参考：

- [`DeviceManagementCollection`：设备管理合集（ArkTS）（API9）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/DeviceManagementCollection)