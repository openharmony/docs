# 扩展外设管理客户端开发指导

## 场景介绍

扩展外设管理主要是指通过物理接口连入主设备的配件设备，如手写板、打印机和扫描仪等。应用通过扩展外设管理能力可以查询绑定扩展外设，从而使用扩展外设驱动提供的定制能力来使用扩展外设，如打印机的配套软件。

扩展外设支持Tablet和特定设备上使用。

## 环境搭建

### 开发工具及配置

DevEco Studio是驱动开发工具，进行驱动开发必备条件之一，我们可以使用该工具进行开发、调试、打包等操作。

请[下载安装](https://developer.huawei.com/consumer/cn/download/)该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-tools-overview-0000001558763037-V5)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-create-new-project-0000001053342414-V5)进行基本的操作验证，保证DevEco Studio可正常运行。


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

## 约束与限制

* 开发我们扩展外设应用，需要有可以植入OpenHarmony系统的开发板或其他设备。
* 开发客户端和驱动时，需要一个外接USB设备进行调试。

## 接口说明

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

## 开发步骤

应用可通过查询绑定扩展外设，从而使用扩展外设的定制驱动能力。开发示例如下(仅供参考)：

**注意：**

* 开发驱动客户端，请选择Empty Ability模板。
* 开发驱动服务端，请选择Native C++模板。
* 同时开发驱动客户端和服务端，请选择Native C++模板。

1. 创建新工程，请参考[创建一个新的工程](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-create-new-project-0000001053342414-V5)

**注意：**

* 以下示例代码均写在entry/src/main/ets/pages/Index.ets文件中。

2. 在文件中导入相关Kit，并声明想要绑定的USB设备的productId、vendorId以及与驱动通信的Code。

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { deviceManager } from '@kit.DriverDevelopmentKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { rpc } from '@kit.IPCKit';

  const REQUEST_CODE: number = 99;
  const productId: number = 4258; 
  const vendorId: number = 4817;
  ```

3. 查询设备列表。

  ```ts
  private async queryTargetDeviceId(): Promise<number> {
  try {
    const devices: Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
    const index = devices.findIndex((item: deviceManager.Device) => {
      let usbDevice = item as deviceManager.USBDevice;
      hilog.info(0, 'testTag', `usbDevice.productId = ${usbDevice.productId}, usbDevice.vendorId = ${usbDevice.vendorId}`);
      return usbDevice.productId === productId && usbDevice.vendorId === vendorId;
    });
    if (index < 0) {
      hilog.error(0, 'testTag', 'can not find device');
      return -1;
    }
    return devices[index].deviceId;
  } catch (e) {
    hilog.error(0, 'testTag', `queryDevice failed, err: ${JSON.stringify(e)}`);
  }
  return -1;
  }
  ```

4. 绑定相应的设备。

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
      deviceManager.bindDevice(matchDevice.deviceId, (error : BusinessError, data : number) => {
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

5. 绑定成功后使用设备驱动能力。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';

    let option: rpc.MessageOption = new rpc.MessageOption();
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    let reply: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeString('hello');
    let code = 99;
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

6. 设备使用完成，解绑设备。

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
