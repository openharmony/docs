# Peripheral Management Development


## When to Use

Peripheral devices (or simply peripherals) are auxiliary devices connected to a device through physical ports, such as handwriting tablets, printers, and scanners. Applications can query and bind peripherals by using the peripheral management capabilities, so that the device can use the customized capabilities provided by the peripheral drivers, such as the printer software.

Currently, devices such as PCs and tablets are supported, but mobile phones are not supported.


## Available APIs

The following table lists the open capabilities of peripheral management. For more information, see [Peripheral Management](../reference/apis/js-apis-driver-deviceManager.md).

**Table 1** Open APIs for peripheral management

| API                                                                                                                                                     | Description                                                                                   |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;                                                                                         | Queries the peripheral list.                                                                       |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;): void | Binds a peripheral device. This API uses an asynchronous callback to return the result. If the peripheral device is bound, the **IRemoteObject** of the device driver is returned for subsequent interaction with the device driver.|
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;                       | Binds a peripheral device. This API uses a promise to return the result.                                                                 |
| unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void                                                                                 | Unbinds a peripheral device. This API uses an asynchronous callback to return the result.                                                                             |
| unbindDevice(deviceId: number): Promise&lt;number&gt;                                                                                                       | Unbinds a peripheral device. This API uses a promise to return the result.                                                                             |


## How to Develop

You can use the APIs to query and bind peripheral devices so as to use the customized driver capabilities of the peripherals. The development procedure is as follows:


1. Query the peripheral device list.

  ```ts
  import deviceManager from '@ohos.driver.deviceManager';
  import { BusinessError } from '@ohos.base';

  let matchDevice : deviceManager.USBDevice | null = null;
  try {
    let devices : Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
    for (let item of devices) {
      let device : deviceManager.USBDevice = item as deviceManager.USBDevice;
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
  import deviceManager from '@ohos.driver.deviceManager';
  import { BusinessError } from '@ohos.base';
  import rpc from '@ohos.rpc'

  let remoteObject : rpc.IRemoteObject;
  try {
    // For example, deviceId is 12345678. You can use queryDevices() to obtain the deviceId.
    deviceManager.bindDevice(12345678, (error : BusinessError, data : number) => {
      console.error('Device is disconnected');
    }, (error : BusinessError, data : {
        deviceId : number;
        remote : rpc.IRemoteObject;
    }) => {
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
  import { BusinessError } from '@ohos.base';
  import rpc from '@ohos.rpc'

  let option : rpc.MessageOption = new rpc.MessageOption();
  let data : rpc.MessageSequence = rpc.MessageSequence.create();
  let reply : rpc.MessageSequence = rpc.MessageSequence.create();
  data.writeString('hello');
  let code = 1;
  // The remoteObject application can be obtained by binding the device.
  let remoteObject : rpc.IRemoteObject;
  // The code and data content varies depending on the interface provided by the driver.
  remoteObject.sendMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption)
    .then(() => {
      console.info('sendMessageRequest finish.');
    }).catch((error : BusinessError) => {
      let errCode = (error as BusinessError).code;
      console.error('sendMessageRequest fail. code:' + errCode);
    });
  ```

4. Unbind the peripheral device after the device is used.

  ```ts
  import deviceManager from '@ohos.driver.deviceManager';
  import { BusinessError } from '@ohos.base';

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
