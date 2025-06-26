# USB Bulk Transfer

## When to Use

Bulk transfer is used to transfer and receive a large amount of data without bandwidth or interval requirements, for example, file or image transfer. Devices such as printers and scanners support this type of transfer.

## Preparing the Environment

### Environment Requirements

- Development tool and configuration:

  DevEco Studio, as the driver development tool, allows you to develop, debug, and package drivers. [Download and install](https://developer.huawei.com/consumer/cn/download/) DevEco Studio and verify basic operations to ensure that it can function properly. For details, see [Creating and Running a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V14/ide-create-new-project-V14) in [DevEco Studio User Guide](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V14/ide-tools-overview-V14).


- SDK version configuration:

  The ArkTs APIs for peripheral management can be used only when the SDK is of API version 16 or later.


- HDC configuration:

  HarmonyOS Device Connector (hdc) is a command-line tool for debugging. It can be used to interact with real devices or the Emulators on Windows, Linux, and macOS. For details about the configuration, see [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/hdc-V5).

### Environment Setup

- Install [DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio) 4.1 or later on the PC.
- Update the public-SDK to API version 16 or later. For details, see [Switching to Full SDK](https://gitee.com/openharmony/docs/blob/master/en/application-dev/faqs/full-sdk-switch-guide.md).
- Install hdc on the PC. You can use it to interact with a real device or emulator on Windows, Linux, or macOS. For details, see [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/hdc-V5).
- Use a USB cable to connect a device to the PC.

## How to Develop

### Available APIs

| API                                                                                                              | Description                   |
|-------------------------------------------------------------------------------------------------------------------|-----------------------|
| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout ?: number): Promise&lt;number&gt;  | Performs bulk transfer.                |

For details about the APIs of device management and transfer modes, see [@ohos.usbManager (USB Manager)](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md).

### Development Procedure

Connect a host to a device and use the **bulkTransfer** API to transfer data. The following steps describe how to implement a bulk transfer:

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
     console.info("usb device request right failed : " + error);
   });
   ```

4. Open the device.

   ```ts
   // Open the device, and obtain the USB device pipe for data transfer.
   let pipe : usbManager.USBDevicePipe = usbManager.connectDevice(deviceList[0]);
   let interface1 : usbManager.USBInterface = deviceList[0].configs[0].interfaces[0];
   /*
    Claim the corresponding interface from deviceList.
   interface1 must be one present in the device configuration.
   */
   usbManager.claimInterface(pipe, interface1, true);
   ```

5. Perform data transfer.

    ```ts
    /*
      Read data. Select the corresponding RX endpoint from deviceList for data transfer.
    (endpoint.direction == 0x80); dataUint8Array indicates the data to read. The data type is Uint8Array.
    */
    let inEndpoint : usbManager.USBEndpoint = interface1.endpoints[2];
    let outEndpoint : usbManager.USBEndpoint = interface1.endpoints[1];
    let dataUint8Array : Uint8Array = new Uint8Array(1024);
    usbManager.bulkTransfer(pipe, inEndpoint, dataUint8Array, 15000).then((dataLength : number) => {
    if (dataLength >= 0) {
      console.info("usb readData result Length : " + dataLength);
    } else {
      console.info("usb readData failed : " + dataLength);
    }
    }).catch((error : BusinessError) => {
    console.info("usb readData error : " + JSON.stringify(error));
    });
    // Send data. Select the corresponding TX endpoint from deviceList for data transfer. (endpoint.direction == 0)
    usbManager.bulkTransfer(pipe, outEndpoint, dataUint8Array, 15000).then((dataLength : number) => {
      if (dataLength >= 0) {
        console.info("usb writeData result write length : " + dataLength);
      } else {
        console.info("writeData failed");
      }
    }).catch((error : BusinessError) => {
      console.info("usb writeData error : " + JSON.stringify(error));
    });
    ```

6. Release the USB interface, and close the USB device pipe.

   ```ts
   usbManager.releaseInterface(pipe, interface1);
   usbManager.closePipe(pipe);
   ```
