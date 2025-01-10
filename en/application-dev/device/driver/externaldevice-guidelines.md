# Peripheral Driver Client Development

## When to Use

Peripheral devices (or simply peripherals) are auxiliary devices connected to a device through physical ports, such as handwriting tablets, printers, and scanners. Applications can query and bind peripherals via peripheral management, so that the peripherals can use the customized capabilities provided by the peripheral drivers, such as the printer software.

Peripheral management applies to all devices that can be ported to the OpenHarmony.

## Environment Setup

### Development Tool and Configuration

DevEco Studio, as the driver development tool, allows you to develop, debug, and package drivers.

Download and install DevEco Studio and verify basic operations to ensure that it can function properly. For details, see [Creating and Running a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-create-new-project-V13) in [DevEco Studio User Guide](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-tools-overview-V13).

### SDK Version Configuration

The ArkTs APIs for peripheral management can be used only when the SDK is of API version 10 or later.

### HDC Configuration

HarmonyOS Device Connector (HDC) is a command-line tool for debugging. It can be used to interact with real devices or emulators on Windows, Linux, and Mac. For details, see [HDC Configuration](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/hdc-V5).

**NOTE**<br>Configuration of the environment variable **hdc_server_port** and global environment variables is mandatory.

### Development Device

* Currently, RK3568 is used as the device for development, debugging, and verification. For details about how to compile and burn the RK3568, see [Quick Start](https://gitee.com/openharmony/docs/blob/master/en/device-dev/quick-start/quickstart-pkg-3568-burn.md).
* During client and driver development, you need to connect an external USB device for debugging. **Currently, only an external USB device is supported.**
* The product ID and vendor ID of the USB device are required for defining drivers and implementing IPC.

## Available APIs

The following table describes the basic peripheral management capabilities. For details, see [API Reference](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager.md).

**Table 1** APIs for basic peripheral management

| Name                                                                                                                                                      | Description                                                                                   |
| -----------------------------------------------------------------------------------------------------------------------------------------------------------  | --------------------------------------------------------------------------------------- |
| queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;                                                                                          | Queries the peripheral list.                                                                      |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&lt;{deviceId: number; remote: rpc.IRemoteObject;}&gt;): void | Binds a peripheral device. This API uses an asynchronous callback to return the result. If the peripheral device is bound, the **IRemoteObject** of the device driver is returned for subsequent interaction with the device driver.|
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number; remote: rpc.IRemoteObject;}&gt;                       | Binds a peripheral. This API uses a promise to return the result.                                                                 |
| bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&gt;RemoteDeviceDriver&gt;): void;                                  | Binds a peripheral. This API uses an asynchronous callback to return the result. It is supported since API version 11.                                                                |
| bindDeviceDriver(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;RemoteDeviceDriver&gt;;                                                        | Binds a peripheral. This API uses a promise to return the result. It is supported since API version 11.   
| unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void                                                                                  | Unbinds a peripheral device. This API uses an asynchronous callback to return the result.                                                                             |
| unbindDevice(deviceId: number): Promise&lt;number&gt;                                                                                                        | Unbinds a peripheral device. This API uses a promise to return the result.                                                                             |

<!--Del-->
The following table lists the APIs for extended peripheral management. For details, see [deviceManager API Reference](../../reference/apis-driverdevelopment-kit/js-apis-driver-deviceManager-sys.md).

**Table 2** APIs for extended peripheral management

| Name                                                                         | Description             |
|------------------------------------------------------------------------------|-----------------|
| queryDeviceInfo(deviceId?: number): Array&lt;Readonly&lt;DeviceInfo&gt;&gt;  | Obtains the list of detailed information about peripherals.  |
| queryDriverInfo(driverUid?: string): Array&lt;Readonly&lt;DriverInfo&gt;&gt; | Obtains the list of detailed information about peripheral drivers.|
<!--DelEnd-->

## How to Develop

You can use the APIs to query and bind peripheral devices so as to use the customized driver capabilities of the peripherals.

The following sample code is a demo that illustrates how to develop both the client and server and implement IPC.

1. Create an OpenHarmony project. For details, see [Creating a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-create-new-project-V13).

    **NOTE**

    > To develop a driver client, select the **Empty Ability** template.
    >
    > To develop the driver server, select the **Native C++** template.
    >
    >To develop both the driver client and server, select the **Native C++** template.


2. Import the related kit, and declare the product ID, vendor ID, and code of the USB device to be bound.

    **NOTE**

    > Write following sample code in the **entry/src/main/ets/pages/Index.ets** file.

    ```ts
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { deviceManager } from '@kit.DriverDevelopmentKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';

    const REQUEST_CODE: number = 99; // Custom communication code, which is for reference only.
    const productId: number = 4258; // Declare the product ID of the connected USB device.
    const vendorId: number = 4817; // Declare the vendor ID of the connected USB device.
    ```

3. Define the **message** variable and remote object variable for communication with the driver.

    **NOTE**

    > The following APIs are defined in **struct Index{}**.

    ```ts
    @State message: string = 'Hello';
    private remote: rpc.IRemoteObject | null = null;
    ```

4. Define the **queryDevices** API, and use it to obtain the device ID of the peripheral.

    ```ts
    private async queryTargetDeviceId(): Promise<number> {
    try {
      const devices: Array<deviceManager.Device> = deviceManager.queryDevices(deviceManager.BusType.USB);
      const index = devices.findIndex((item: deviceManager.Device) => {
        let usbDevice = item as deviceManager.USBDevice;
        // If the product ID and vendor ID of the peripheral are unknown, you can view the information about the connected USB device in the log.
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

5. Define the **bindDeviceDriver** API, and use it to obtain the remote driver object.

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

6. Define the **sendMessageRequest** API, and use it to perform IPC with the remote driver object.

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

      // Send "Hello" to the driver.
      data.writeString(this.message); 

      try {
        await this.remote.sendMessageRequest(REQUEST_CODE, data, reply, option);
        // Obtain the "Hello world" information returned by the driver.
        this.message = reply.readString();
        hilog.info(0, 'testTag', `sendMessageRequest, message: ${this.message}}`);
      } catch (error) {
        hilog.error(0, 'testTag', `sendMessageRequest failed, err: ${JSON.stringify(error)}`);
      }
    }
    ```

7. Render the UI. For details about UI development, see [UI Development](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/arkts-ui-development-V5).

    ```ts
    build() {
      Row() {
        Column() {
          Text (this.message) // "Hello" is displayed.
            .fontSize(60)
            .fontWeight(FontWeight.Bold)
            .onClick (() => { // Click Hello to communicate with the remote driver object. The message "Hello World" is displayed.
              this.communicateWithRemote();
            })
        }
        .width('100%')
      }
      .height('100%')
    }
    ```

8. Develop the driver code. For details, see [Peripheral Driver Development](driverextensionability.md).

<!--Del-->
System applications can query detailed information about peripherals and drivers to implement management. The development procedure is as follows:

1. Import the related kit.

    ```ts
     import { deviceManager } from '@kit.DriverDevelopmentKit';
     import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Obtain the list of detailed information about peripherals.

    ```ts 
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

3. Obtains the list of detailed information about peripheral drivers.

    ```ts
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
<!--DelEnd-->

## Application Signing

**NOTE**<br>Configure the permission before enabling automatic signing.

You need to configure a signature file for your application to run on a device. Besides, to develop a peripheral driver client, you need to declare the **ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER** permission for the peripheral.

Automatic signing: [Signing Your App/Service Automatically](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-signing-V13#section18815157237)

Permission configuration: [Requesting ACL Permissions and Signing Your App/Service](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V13/ide-signing-V13#section157591551175916).
