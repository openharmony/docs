# 扩展外设管理开发指导

## 场景介绍

扩展外设主要是指通过物理接口连入主设备的配件设备，如手写板、打印机和扫描仪等。应用通过扩展外设管理能力可以查询绑定扩展外设，从而使用扩展外设驱动提供的定制能力来使用扩展外设，如打印机的配套软件。

扩展外设支持Tablet和特定设备上使用。

## 环境搭建

### 开发工具及配置

DevEco Studio是驱动开发工具，进行驱动开发必备条件之一，我们可以使用该工具进行开发、调试、打包等操作。

请下载安装该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-tools-overview-0000001558763037-V5)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-create-new-project-0000001053342414-V5)进行基本的操作验证，保证DevEco Studio可正常运行。


### SDK版本配置

目前各SDK支持的版本如下：

| 外设SDK名称 | 支持最小API | 对应OpenHarmony/HarmonyOS版本 |
| ------------ | ------------ | ------------ |
| 应用开发接口（ArkTS接口）| API10 | 4.0及以上 |
| USB DDK接口 | API10 | 4.0及以上 |
| HID DDK接口 | API11 | 4.1及以上 |


### HDC配置

hdc（HarmonyOS Device Connector）是HarmonyOS为开发人员提供的用于调试的命令行工具，通过该工具可以在windows/linux/mac系统上与真实设备或者模拟器进行交互，详细参考[HDC配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/hdc-V5)

**注意：** “配置环境变量hdc_server_port”和“全局环境变量”为必须操作。

### 开发设备

下述开发调试及验证，以RK3568作为开发设备进行说明。

RK3568的烧录流程请参考：[快速入门](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-pkg-3568-burn.md)

## 操作流程

扩展外设管理驱动开发，分为驱动客户端开发和驱动服务端开发。

* 驱动客户端：绑定驱动，获取远程对象，与驱动服务端进行通信。

* 驱动服务端：获取驱动客户端传递信息，并进行信息处理，返回给客户端。

## 驱动客户端开发指导

客户端：开发相关前端页面和客户端功能，不涉及驱动开发。

### 接口说明

扩展外设管理主要提供的功能有：查询扩展外设列表、绑定查询到的设备、解绑已绑定的设备、查询扩展外设详细信息和查询扩展外设驱动详细信息。

扩展外设管理开放能力如下，具体请查阅[API参考文档](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager.md)。

**表1** 扩展外设管理开放能力接口

| 接口名                                                                                                                                                      | 描述                                                                                    |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;                                                                                         | 查询扩展外设列表。                                                                       |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&lt;{deviceId: number; remote: rpc.IRemoteObject;}&gt;): void | 绑定设备，绑定成功后返回设备驱动的IRemoteObject通信对象，通过该对象与设备驱动进行交互。 |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number; remote: rpc.IRemoteObject;}&gt;                       | 绑定设备的Promise形式。                                                                 |
| unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void                                                                                 | 解绑设备。                                                                              |
| unbindDevice(deviceId: number): Promise&lt;number&gt;                                                                                                       | 解绑设备的Promise形式。                                                                              |


<!--Del-->
扩展外设管理系统接口如下，具体请查阅[API参考文档](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager-sys.md)。

**表2** 扩展外设管理系统接口

| 接口名                                                                          | 描述              |
|------------------------------------------------------------------------------|-----------------|
| queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;  | 查询扩展外设详细信息列表。   |
| queryDriverInfo(driverUid?: string): Array&lt;Readonly&lt;DriverInfo&gt;&gt; | 查询扩展外设驱动详细信息列表。 |
<!--DelEnd-->

### 开发步骤

应用可通过查询绑定扩展外设，从而使用扩展外设的定制驱动能力。开发示例如下：

1. 创建新工程，请参考[创建一个新的工程](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-create-new-project-0000001053342414-V5)

**注意：**

* 开发驱动客户端，请选择Empty Ability模板。
* 开发驱动服务端，请选择Native C++模板。
* 同时开发驱动客户端和服务端，请选择Native C++模板。 

2. 创建tool文件夹，新建一个RpcTool.ets文件，以下示例代码都在RpcTool.ets文件中添加；

![rpctool.ets文件](./figures/rpcTool.png)

2. 查询设备列表。

    ```ts
    import { deviceManager } from '@kit.DriverDevelopmentKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let matchDevice: deviceManager.USBDevice | null = null;
    try {
      let devices: Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
      for (let item of devices) {
        let device: deviceManager.USBDevice = item as deviceManager.USBDevice;
        // 通过productId和vendorId来匹配要使用的USB设备
        if (device.productId == 1234 && device.vendorId === 2345) {
          matchDevice = device;
          break;
        }
      }
    } catch (error) {
      let errCode = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`Failed to query device. Code is ${errCode}, message is ${message}`);
    }
    if (!matchDevice) {
      console.error('No match device');
    }
    ```

3. 绑定相应的设备。

    ```ts
    import { deviceManager } from '@kit.DriverDevelopmentKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';

    interface DataType {
      deviceId : number;
      remote : rpc.IRemoteObject;
    }

    let remoteObject : rpc.IRemoteObject | null = null;
    try {
      // 12345678为示例deviceId，应用开发时可以通过queryDevices查询到相应设备的deviceId作为入参
      deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {
        console.error('Device is disconnected');
      }, (error : BusinessError, data : DataType) => {
        if (error) {
          console.error(`bindDevice async fail. Code is ${error.code}, message is ${error.message}`);
          return;
        }
        console.info('bindDevice success');
        remoteObject = data.remote;
      });
    } catch (error) {
      let errCode = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`bindDevice fail. Code is ${errCode}, message is ${message}`);
    }
    if (!remoteObject) {
      console.error('Bind device failed');
    }
    ```

4. 绑定成功后使用设备驱动能力。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';

    let option: rpc.MessageOption = new rpc.MessageOption();
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    let reply: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeString('hello');
    let code = 1;
    // remoteObject应用可以通过绑定设备获取到
    let remoteObject : rpc.IRemoteObject | null = null;
    // code和data内容取决于驱动提供的接口
    if (remoteObject != null) {
      (remoteObject as rpc.IRemoteObject).sendMessageRequest(code, data, reply, option)
        .then(() => {
          console.info('sendMessageRequest finish.');
        }).catch((error : BusinessError) => {
          let errCode = (error as BusinessError).code;
          console.error('sendMessageRequest fail. code:' + errCode);
        }
      );
    }
    ```

5. 设备使用完成，解绑设备。

    ```ts
    import { deviceManager } from '@kit.DriverDevelopmentKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      // 12345678为示例deviceId，应用开发时可以通过queryDevices查询到相应设备的deviceId作为入参
      deviceManager.unbindDevice(12345678, (error : BusinessError, data : number) => {
        if (error) {
          let errCode = (error as BusinessError).code;
          let message = (error as BusinessError).message;
          console.error(`unbindDevice async fail. Code is ${errCode}, message is ${message}`);
          return;
        }
        console.info(`unbindDevice success`);
      });
    } catch (error) {
      let errCode = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`unbindDevice fail. Code is ${errCode}, message is ${message}`);
    }
    ```
<!--Del-->
系统应用可通过查询外设详细信息和驱动详细信息，从而管理外设和驱动。开发示例如下：

1. 查询扩展外设详细信息列表。

   ```ts
   import { deviceManager } from '@kit.DriverDevelopmentKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   try {
      // 12345678为示例deviceId，应用开发时可通过queryDevices查询到相应设备的deviceId作为入参
      let deviceInfos : Array<deviceManager.DeviceInfo> = deviceManager.queryDeviceInfo(12345678);
      for (let item of deviceInfos) {
         console.info(`Device id is ${item.deviceId}`)
      }
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to query device info. Code is ${err.code}, message is ${err.message}`);
    }
   ```

2. 查询扩展外设驱动详细信息列表。

   ```ts
   import { deviceManager } from '@kit.DriverDevelopmentKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   try {
      // driver-12345为示例driverUid，应用开发时可通过queryDeviceInfo查询到相应设备匹配到的驱动的driverUid作为入参
      let driverInfos : Array<deviceManager.DriverInfo> = deviceManager.queryDriverInfo("driver-12345");
      for (let item of driverInfos) {
         console.info(`driver name is ${item.driverName}`)
      }
   } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to query driver info. Code is ${err.code}, message is ${err.message}`);
   }
   ```
<!--DelEnd-->

## 驱动服务端开发指导

开发相关外设对应驱动，主要是调用扩展外设管理模块的DriverExtensionAbility；

开发详情请见[DriverExtensionAbility](./driverextensionability.md)简介。

## 常见问题

### SDK版本问题

编译或运行时报错：“usb/usb_ddk_api.h not found”, "hid/hid_ddk_api.h not found" 等，请检查编译的OpenHarmony/HarmonyOS版本。如果是运行时，请检查设备的系统版本

安装出现报错 “compileSdkVersion and releaseType of the app do not match the apiVersion and releaseType on the device” 请检查设备系统版本与hap版本是否匹配
