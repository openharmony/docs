# 扩展外设管理开发指导


## 场景介绍

扩展外设主要是指通过物理接口连入主设备的配件设备，如手写板、打印机和扫描仪等。应用通过扩展外设管理能力可以查询绑定扩展外设，从而使用扩展外设驱动提供的定制能力来使用扩展外设，如打印机的配套软件。

扩展外设支持Tablet和特定设备上使用。


## 接口说明

扩展外设管理主要提供的功能有：查询扩展外设列表、绑定查询到的设备、解绑已绑定的设备、查询扩展外设详细信息和查询扩展外设驱动详细信息。

扩展外设管理开放能力如下，具体请查阅[API参考文档](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager.md)。

**表1** 扩展外设管理开放能力接口

| 接口名                                                                                                                                                      | 描述                                                                                    |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;                                                                                         | 查询扩展外设列表。                                                                       |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;): void | 绑定设备，绑定成功后返回设备驱动的IRemoteObject通信对象，通过该对象与设备驱动进行交互。 |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;                       | 绑定设备的Promise形式。                                                                 |
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

应用可通过查询绑定扩展外设，从而使用扩展外设的定制驱动能力。开发示例如下：


1. 查询设备列表。

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

2. 绑定相应的设备。

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

3. 绑定成功后使用设备驱动能力。

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
        });
    }
    ```

4. 设备使用完成，解绑设备。

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