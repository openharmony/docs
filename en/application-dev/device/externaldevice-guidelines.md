# Peripheral Management Development


## When to Use

Peripheral devices (or simply peripherals) are auxiliary devices connected to a device through physical ports, such as handwriting tablets, printers, and scanners. Applications can query and bind peripherals by using the peripheral management capabilities, so that the device can use the customized capabilities provided by the peripheral drivers, such as the printer software.


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

  ```js
  var matchDevice;
  try {
    let devices = deviceManager.queryDevices(deviceManager.BusType.USB);
    for (let item of devices) {
      let device = item as deviceManager.USBDevice;
      // Match the USB device based on productId and vendorId.
      if (device.productId == 1234 && device.vendorId === 2345) {
        matchDevice = device;
        break;
      }
    }
  } catch (error) {
    console.error('Failed to query device. Code is ${error.code}, message is ${error.message}');
  }
  if (!matchDevice) {
    console.error('No match device');
    return;
  }
  ```

2. Bind a peripheral device.

  ```js
  var remoteObject;
  try {
    deviceManager.bindDevice(matchDevice.deviceId, (error, data) => {
      console.error('Device is disconnected');
    }, (error, data) => {
      if (error) {
        console.error('bindDevice async fail. Code is ${error.code}, message is ${error.message}');
        return;
      }
      console.info('bindDevice success');
      remoteObject = data.remote;
    });
  } catch (error) {
    console.error('bindDevice fail. Code is ${error.code}, message is ${error.message}');
  }
  ```

3. Use the capabilities provided by the peripheral device driver.

  ```js
  let option = new rpc.MessageOption();
  let data = rpc.MessageSequence.create();
  let repy = rpc.MessageSequence.create();
  data.writeString('hello');
  let code = 1;
  // The code and data content varies depending on the interface provided by the driver.
  remoteObject.sendMessageRequest(code, data, reply, option)
    .then(result => {
      console.info('sendMessageRequest finish.');
    }).catch(error => {
      console.error('sendMessageRequest fail. code:' + error.code);
    });
  ```

4. Unbind the peripheral device after the device is used.

  ```js
  try {
    deviceManager.unbindDevice(matchDevice.deviceId, (error, data) => {
      if (error) {
        console.error('unbindDevice async fail. Code is ${error.code}, message is ${error.message}');
        return;
      }
      console.info('unbindDevice success');
    });
  } catch (error) {
    console.error('unbindDevice fail. Code is ${error.code}, message is ${error.message}');
  }
  ```
