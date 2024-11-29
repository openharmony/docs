# 外设扩展驱动客户端开发指导

## 场景介绍

扩展外设主要是指通过物理接口连入主设备的配件设备，如手写板、打印机和扫描仪等。应用通过扩展外设管理能力可以查询绑定扩展外设，从而使用扩展外设驱动提供的定制能力来使用扩展外设，如打印机的配套软件。

扩展外设管理能力支持所有可移植OpenHarmony系统的设备使用。

## 环境搭建

### 开发工具及配置

DevEco Studio是驱动开发工具，进行驱动开发必备条件之一，我们可以使用该工具进行开发、调试、打包等操作。

请[下载安装](https://developer.huawei.com/consumer/cn/download/)该工具，并参考[DevEco Studio使用指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-tools-overview-V5)中的[创建工程及运行](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-create-new-project-V5)进行基本的操作验证，保证DevEco Studio可正常运行。

### SDK版本配置

扩展外设管理提供的ArkTs接口，所需SDK版本为API10及以上版本才可使用。

### HDC配置

HDC（HarmonyOS Device Connector）是为开发人员提供的用于调试的命令行工具，通过该工具可以在Windows/Linux/Mac系统上与真实设备或者模拟器进行交互，详细参考[HDC配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/hdc-V5)。

**注意：** “配置环境变量hdc_server_port”和“全局环境变量”为必须操作。

### 开发设备

* 当前开发调试及验证，以RK3568作为开发设备进行说明。关于RK3568的编译、烧录操作等方法，可参考[快速入门](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-pkg-3568-burn.md)。
* 开发客户端和驱动时，需要一个外接USB设备进行调试，**当前仅支持USB总线的外接设备**。
* 需要知道外接USB设备的ProductId和VendorId，用于定义驱动以及IPC通信。

## 接口说明

扩展外设管理基本能力如下，更多详情请查阅[API参考文档](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager.md)。

**表1** 扩展外设管理基本能力接口

| 接口名                                                                                                                                                       | 描述                                                                                    |
| -----------------------------------------------------------------------------------------------------------------------------------------------------------  | --------------------------------------------------------------------------------------- |
| queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;                                                                                          | 查询扩展外设列表。                                                                       |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&lt;{deviceId: number; remote: rpc.IRemoteObject;}&gt;): void | 绑定设备，绑定成功后返回设备驱动的IRemoteObject通信对象，通过该对象与设备驱动进行交互。 |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number; remote: rpc.IRemoteObject;}&gt;                       | 绑定设备的Promise形式。                                                                 |
| bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&gt;RemoteDeviceDriver&gt;): void;                                  | 绑定设备，API11开始支持。                                                                 |
| bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;RemoteDeviceDriver&gt;;                                                        | 绑定设备的Promise形式，API11开始支持。    
| unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void                                                                                  | 解绑设备。                                                                              |
| unbindDevice(deviceId: number): Promise&lt;number&gt;                                                                                                        | 解绑设备的Promise形式。                                                                              |

<!--Del-->
扩展外设管理系统接口如下，具体请查阅[API参考文档](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager-sys.md)。

**表2** 扩展外设管理系统接口

| 接口名                                                                          | 描述              |
|------------------------------------------------------------------------------|-----------------|
| queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;  | 查询扩展外设详细信息列表。   |
| queryDriverInfo(driverUid?: string): Array&lt;Readonly&lt;DriverInfo&gt;&gt; | 查询扩展外设驱动详细信息列表。 |
<!--DelEnd-->

## 开发步骤

应用可通过查询绑定扩展外设，从而使用扩展外设的定制驱动能力。

开发示例如下（仅供参考）：为开发者提供的示例代码为同时开发客户端和服务端的Demo，并实现IPC通信。

1. 创建新工程，请参考[创建一个新的工程](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-create-new-project-V5)，创建一个OpenHarmony工程。

    **注意：**

    > 开发驱动客户端，请选择Empty Ability模板。
    >
    > 开发驱动服务端，请选择Native C++模板。
    >
    >同时开发驱动客户端和服务端，请选择Native C++模板。


2. 在文件中导入相关Kit，并声明想要绑定的USB设备的productId、vendorId以及与驱动通信的Code。

    **说明：**

    > 以下示例代码均写在entry/src/main/ets/pages/Index.ets文件中。

    ```ts
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { deviceManager } from '@kit.DriverDevelopmentKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';

    const REQUEST_CODE: number = 99; // 自定义通信Code，此处仅供参考
    const productId: number = 4258;  // 请声明连接的USB设备的productId
    const vendorId: number = 4817;   // 请声明连接的USB设备的vendorId
    ```

3. 定义message变量和远程对象变量，后续与驱动通信使用。

    **说明：**

    > 第3步开始，以下接口均在struct Index{}中定义。

    ```ts
    @State message: string = 'Hello';
    private remote: rpc.IRemoteObject | null = null;
    ```

4. 定义查询设备接口，通过queryDevices获取目标设备ID。

    ```ts
    private async queryTargetDeviceId(): Promise<number> {
    try {
      const devices: Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
      const index = devices.findIndex((item: deviceManager.Device) => {
        let usbDevice = item as deviceManager.USBDevice;
        // 如果不知道设备productId和vendorId，可以通过该日志查看连接的usb设备的相关信息
        hilog.info(0, 'testTag', `usbDevice.productId = ${usbDevice.productId}, usbDevice.vendorId = ${usbDevice.vendorId}`);
        return usbDevice.productId === productId && usbDevice.vendorId === vendorId;
      });
      if (index < 0) {
        hilog.error(0, 'testTag', 'can not find device');
        return -1;
      }
      return devices[index].deviceId;
    } catch (error) {
      hilog.error(0, 'testTag', `queryDevice failed, err: ${JSON.stringify(error)}`);
    }
    return -1;
    }
    ```

5. 定义获取对应驱动远程对象的接口，通过bindDeviceDriver获取远程对象。

    ```ts
    private async getDriverRemote(deviceId: number): Promise<rpc.IRemoteObject | null> {
    try {
      let remoteDeviceDriver: deviceManager.RemoteDeviceDriver = await deviceManager.bindDeviceDriver(deviceId,
        (err: BusinessError, id: number) => {
        hilog.info(0, 'testTag', `device[${id}] id disconnect, err: ${JSON.stringify(err)}}`);
      });
      return remoteDeviceDriver.remote;
    } catch (error) {
      hilog.error(0, 'testTag', `bindDeviceDriver failed, err: ${JSON.stringify(error)}`);
    }
      return null;
    }
    ```

6. 定义与远程对象通信接口，通过sendMessageRequest与远程对象进行IPC通信。

    ```ts
    private async communicateWithRemote(): Promise<void> {
      const deviceId: number = await this.queryTargetDeviceId();
      if (deviceId < 0) {
        hilog.error(0, 'testTag', 'can not find target device');
        return;
      }
      this.remote = await this.getDriverRemote(deviceId);
      if (this.remote === null) {
        hilog.error(0, 'testTag', `getDriverRemote failed`);
        return;
      }

      let option = new rpc.MessageOption();
      let data = new rpc.MessageSequence();
      let reply = new rpc.MessageSequence();

      // 向驱动发送信息"Hello"
      data.writeString(this.message); 

      try {
        await this.remote.sendMessageRequest(REQUEST_CODE, data, reply, option);
        // 获取驱动返回信息"Hello world"
        this.message = reply.readString();
        hilog.info(0, 'testTag', `sendMessageRequest, message: ${this.message}}`);
      } catch (error) {
        hilog.error(0, 'testTag', `sendMessageRequest failed, err: ${JSON.stringify(error)}`);
      }
    }
    ```

7. 渲染UI界面，更多UI界面开发请参考[UI开发](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/arkts-ui-development-V5)。

    ```ts
    build() {
      Row() {
        Column() {
          Text(this.message) // 显示"Hello"
            .fontSize(60)
            .fontWeight(FontWeight.Bold)
            .onClick(() => { // 点击"Hello"，与远程对象通信，显示"Hello World"
              this.communicateWithRemote();
            })
        }
        .width('100%')
      }
      .height('100%')
    }
    ```

8. 接下来请参考[外设扩展驱动开发指导](driverextensionability.md)，进行对应驱动的示例代码开发。

<!--Del-->
系统应用可通过查询外设详细信息和驱动详细信息，从而管理外设和驱动。开发示例如下：

1. 导入相关Kit

    ```ts
     import { deviceManager } from '@kit.DriverDevelopmentKit';
     import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 查询扩展外设详细信息列表。

    ```ts 
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

3. 查询扩展外设驱动详细信息列表。

    ```ts
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

## 应用签名

**注意：** 先配置权限，再自动签名。

应用需要配置签名文件才能在设备上运行，并且扩展外设管理客户端开发，需要配置扩展外设的权限：ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER。

自动签名方法： 请参考[自动签名](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-signing-V5#section18815157237)。

权限配置方法： 请参考[使用ACL的签名配置指导](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-signing-V5#section157591551175916)。
