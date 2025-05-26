# USB设备管理

## 场景介绍

当有USB设备插入时，可以通过`usbManager`获取一些USB设备的基本信息，如设备类型、支持的功能等。 Host侧主要通过封装的pipe来完成和USB设备的通信。在OpenHarmony系统中，USB管理服务是核心组件，负责管理与USB设备的连接和通信。通过USB管理服务，应用程序可以检测USB设备的连接与断开，管理USB设备的权限请求和设备配置，以及进行数据传输和设备控制。

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
- 将public-SDK更新到API 16或以上，更新SDK的具体操作可参见[更新指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/faqs/full-sdk-switch-guide.md)。
- PC安装HDC工具，通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互，详细参考[HDC配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/hdc)。
- 用USB线缆将搭载OpenHarmony的设备连接到PC。

## 开发指导

### 接口说明

USB设备管理主要提供的功能有：查询USB设备列表、USB设备权限控制、设置USB设备配置等。

USB类开放能力如下，具体请查阅[API参考文档](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md)。

**表1** USB类的开放能力接口

| 接口名                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| hasRight(deviceName: string): boolean                         | 判断是否有权访问该设备。 |
| requestRight(deviceName: string): Promise&lt;boolean&gt;       | 请求软件包的临时权限以访问设备。使用Promise异步回调。                        |
| removeRight(deviceName: string): boolean | 移除软件包对设备的访问权限。|
| connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt; | 根据`getDevices()`返回的设备信息打开USB设备。                |
| getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;          | 获取接入主设备的USB设备列表。如果没有设备接入，那么将会返回一个空的列表。                                            |
| setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number | 设置设备的配置。                                             |
| setInterface(pipe: USBDevicePipe, iface: USBInterface): number   | 设置设备的接口。                                             |
| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force ?: boolean): number | 注册通信接口。                                                   |
| closePipe(pipe: USBDevicePipe): number                         | 关闭设备消息控制通道。                                       |
| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | 释放注册过的通信接口。                                                   |
| getFileDescriptor(pipe: USBDevicePipe): number                 | 获取文件描述符。                                             |
| getRawDescriptor(pipe: USBDevicePipe): Uint8Array              | 获取原始的USB描述符。                                        |

### 开发步骤

USB设备可作为Host连接Device进行设备管理，开发示例如下：


1. 导入模块。

   ```ts
   // 导入usbManager模块。
   import { usbManager } from '@kit.BasicServicesKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. 获取设备列表。

   ```ts
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

3. 获取设备操作权限。

   ```ts
   let deviceName : string = deviceList[0].name;
   // 申请操作指定的device的操作权限。
   usbManager.requestRight(deviceName).then((hasRight : boolean) => {
     console.info("usb device request right result: " + hasRight);
   }).catch((error : BusinessError)=> {
     console.info("usb device request right failed : " + error);
   });
   ```

4. 打开Device设备。

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

5. 释放接口，关闭设备。

   ```ts
   usbManager.releaseInterface(pipe, interface1);
   usbManager.closePipe(pipe);
   ```

### 相关实例

针对USB管理开发，有以下相关实例可供参考：

- [`DeviceManagementCollection`：设备管理合集（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/DeviceManagementCollection)