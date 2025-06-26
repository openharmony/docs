# USB Device Management

## When to Use

When a USB device is inserted, you can use **usbManager** to obtain basic information about the USB device, such as the device type and supported functions. The host communicates with the USB device through the encapsulated pipe. In OpenHarmony, the USB management service is the core component that manages the connection and communication with USB devices. With the USB management service, applications can detect the USB connection and disconnection, manage permission requests and device configurations of USB devices, and perform data transfer and device control.

## Environment Preparation

### Environment Requirements

- Development tool and configuration:

  DevEco Studio, as the driver development tool, allows you to develop, debug, and package drivers. [Download and install](https://developer.huawei.com/consumer/en/download/) DevEco Studio and verify basic operations to ensure that it can function properly. For details, see [Creating a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-create-new-project) in [DevEco Studio User Guide](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-tools-overview).


- SDK version configuration:

  The ArkTs APIs for peripheral management can be used only when the SDK is of API version 16 or later.


- HDC configuration:

  HarmonyOS Device Connector (hdc) is a command-line tool for debugging. It can be used to interact with real devices or the Emulator on Windows, Linux, and macOS. For details about the configuration, see [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc).

### Environment Setup

- Install [DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio) 4.1 or later on the PC.
- Update the public SDK to API version 16 or later. For details, see [Update Guide](https://gitee.com/openharmony/docs/blob/master/en/application-dev/faqs/full-sdk-switch-guide.md).
- Install hdc on the PC. You can use it to interact with a real device or the Emulator on Windows, Linux, or macOS. For details, see [HDC Configuration](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc).
- Use a USB cable to connect an OpenHarmony device to the PC.

## How to Develop

### Available APIs

USB device management provides the following functions: querying the USB device list, controlling USB device permissions, and setting USB device configurations.

The following table lists the USB APIs currently available. For details, see [@ohos.usbManager (USB Manager)](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md).

**Table 1** Open USB APIs

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| hasRight(deviceName: string): boolean                         | Checks whether the USB has the device access permissions.|
| requestRight(deviceName: string): Promise&lt;boolean&gt;       | Requests the temporary permission for the application to access the USB device. This API uses a promise to return the result.                       |
| removeRight(deviceName: string): boolean | Removes the device access permissions of the application.|
| connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt; | Connects to the USB device based on the device information returned by **getDevices()**.               |
| getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;          | Obtains the list of USB devices connected to the host. If no device is connected, an empty list is returned.                                           |
| setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number | Sets the USB device configuration.                                            |
| setInterface(pipe: USBDevicePipe, iface: USBInterface): number   | Sets a USB interface.                                            |
| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force ?: boolean): number | Claims a USB interface.                                                  |
| closePipe(pipe: USBDevicePipe): number                         | Closes a USB device pipe.                                      |
| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | Releases a USB interface.                                                  |
| getFileDescriptor(pipe: USBDevicePipe): number                 | Obtains the file descriptor of a USB device.                                            |
| getRawDescriptor(pipe: USBDevicePipe): Uint8Array              | Obtains the raw USB descriptor.                                       |

### How to Develop

A USB device can be used as a host to connect to a device for management. The procedure is as follows:


1. Import modules.

   ```ts
   // Import the usbManager module.
   import { usbManager } from '@kit.BasicServicesKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the USB device list.

   ```ts
   // Obtain the USB device list.
   let deviceList : Array<usbManager.USBDevice> = usbManager.getDevices();
   /*
   Example deviceList structure:
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

3. Obtain the device operation permissions.

   ```ts
   let deviceName : string = deviceList[0].name;
   // Request the permissions to operate a specified device.
   usbManager.requestRight(deviceName).then((hasRight : boolean) => {
     console.info("usb device request right result: " + hasRight);
   }).catch((error : BusinessError)=> {
     console.error(`usb device request right failed : ${error}`);
   });
   ```

4. Open the device.

   ```ts
   // Open the device, and obtain the USB device pipe for data transfer.
   let pipe : usbManager.USBDevicePipe = usbManager.connectDevice(deviceList[0]);
   let interface1 : usbManager.USBInterface = deviceList[0].configs[0].interfaces[0];
   /*
    Claim the corresponding interface from **deviceList**.
   interface1 must be one present in the device configuration.
   */
   usbManager.claimInterface(pipe, interface1, true);
   ```

5. Release the USB interface, and close the USB device.

   ```ts
   usbManager.releaseInterface(pipe, interface1);
   usbManager.closePipe(pipe);
   ```
