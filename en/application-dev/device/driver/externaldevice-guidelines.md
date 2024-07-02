# Peripheral Management Development


## When to Use

Peripheral devices (or simply peripherals) are auxiliary devices connected to a device through physical ports, such as handwriting tablets, printers, and scanners. Applications can query and bind peripherals by using the peripheral management capabilities, so that the device can use the customized capabilities provided by the peripheral drivers, such as the printer software.

Peripherals can be used on tablets and specific devices.


## Available APIs

Peripheral management provides the following functions: querying the peripheral list, binding and unbinding peripherals, querying information about peripherals and peripheral drivers.

For more information, see [Peripheral Management](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager.md).

**Table 1** Open APIs for peripheral management

| API                                                                                                                                                     | Description                                                                                   |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;                                                                                         | Queries the peripheral list.                                                                      |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;): void | Binds a peripheral device. This API uses an asynchronous callback to return the result. If the peripheral device is bound, the **IRemoteObject** of the device driver is returned for subsequent interaction with the device driver.|
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;                       | Binds a peripheral device. This API uses a promise to return the result.                                                                 |
| unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void                                                                                 | Unbinds a peripheral device. This API uses an asynchronous callback to return the result.                                                                             |
| unbindDevice(deviceId: number): Promise&lt;number&gt;                                                                                                       | Unbinds a peripheral device. This API uses a promise to return the result.                                                                             |

The following table lists the APIs for extended peripheral management. For details, see [deviceManager API Reference](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager-sys.md).

**Table 2** APIs for extended peripheral management

| API                                                                         | Description             |
|------------------------------------------------------------------------------|-----------------|
| queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;  | Obtains the list of detailed information about peripherals.  |
| queryDriverInfo(driverUid?: string): Array&lt;Readonly&lt;DriverInfo&gt;&gt; | Obtains the list of detailed information about peripheral drivers.|

## How to Develop

You can use the APIs to query and bind peripheral devices so as to use the customized driver capabilities of the peripherals. The development procedure is as follows:


1. Query the peripheral device list.

    ```ts
    import { deviceManager } from '@kit.DriverDevelopmentKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let matchDevice: deviceManager.USBDevice | null = null;
    try {
      let devices: Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
      for (let item of devices) {
        let device: deviceManager.USBDevice = item as deviceManager.USBDevice;
        // Match the USB device based on productId and vendorId.
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

2. Bind a peripheral device.

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
      // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
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

3. Use the capabilities provided by the peripheral device driver.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';

    let option: rpc.MessageOption = new rpc.MessageOption();
    let data: rpc.MessageSequence = rpc.MessageSequence.create();
    let reply: rpc.MessageSequence = rpc.MessageSequence.create();
    data.writeString('hello');
    let code = 1;
    // The remoteObject application can be obtained by binding the device.
    let remoteObject : rpc.IRemoteObject | null = null;
    // The code and data content varies depending on the interface provided by the driver.
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

4. Unbind the peripheral device after the device is used.

    ```ts
    import { deviceManager } from '@kit.DriverDevelopmentKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
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

System applications can query detailed information about peripherals and drivers to implement management. The development procedure is as follows:

1. Obtain the list of detailed information about peripherals.
   ```ts
   import { deviceManager } from '@kit.DriverDevelopmentKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   try {
      // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
      let deviceInfos : Array<deviceManager.DeviceInfo> = deviceManager.queryDeviceInfo(12345678);
      for (let item of deviceInfos) {
         console.info(`Device id is ${item.deviceId}`)
      }
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to query device info. Code is ${err.code}, message is ${err.message}`);
    }
   ```

2. Obtains the list of detailed information about peripheral drivers.
   ```ts
   import { deviceManager } from '@kit.DriverDevelopmentKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   try {
      // In this example, driver-12345 is the driver UID. During application development, you can use queryDeviceInfo to query the driver UID and use it as the input parameter.
      let driverInfos : Array<deviceManager.DriverInfo> = deviceManager.queryDriverInfo("driver-12345");
      for (let item of driverInfos) {
         console.info(`driver name is ${item.driverName}`)
      }
   } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`Failed to query driver info. Code is ${err.code}, message is ${err.message}`);
   }
   ```
