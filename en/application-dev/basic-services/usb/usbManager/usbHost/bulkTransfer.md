# USB Bulk Transfer

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## When to Use

Bulk transfer is used to transfer and receive a large amount of data without bandwidth or interval requirements, for example, file or image transfer. Devices such as printers and scanners support this type of transfer.

## Preparing the Environment

### Environment Requirements

- Development tool and configuration:

  DevEco Studio, as the driver development tool, allows you to develop, debug, and package drivers. [Download and install](https://developer.huawei.com/consumer/en/download/) DevEco Studio and verify basic operations to ensure that it can function properly. For details, see [Creating a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-create-new-project) in [DevEco Studio User Guide](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-tools-overview).


- SDK version configuration:

  The ArkTs APIs for peripheral management can be used only when the SDK is of API version 16 or later.


- HDC configuration:

  HarmonyOS Device Connector (hdc) is a command-line tool for debugging. It can be used to interact with real devices or the Emulator on Windows, Linux, and macOS. For details about the configuration, see [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc).

### Environment Setup

- Install [DevEco Studio](https://developer.huawei.com/consumer/en/download/) 4.1 or later on the PC.
- Update the public SDK to API version 16 or later.<!--Del--> For details, see [Switching to Full SDK](../../../../faqs/full-sdk-switch-guide.md).<!--DelEnd-->
- Install hdc on the PC. You can use it to interact with a real device or the Emulator on Windows, Linux, or macOS.
- Use a USB cable to connect a device to the PC.

## How to Develop

### Available APIs

| API                                                                                                              | Description                   |
|-------------------------------------------------------------------------------------------------------------------|-----------------------|
| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout ?: number): Promise&lt;number&gt;  | Performs bulk transfer.                |

For details about the APIs of device management and transfer modes, see [@ohos.usbManager (USB Manager)](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md).

### Development Procedure

Connect a host to a device and use the **bulkTransfer** API to transfer data. The following steps describe how to implement a bulk transfer:

> **NOTE**
>
> The following sample code shows only a basic process. You should execute the code in a specific method. When calling this method, you must comply with device protocols to ensure proper data transfer and device compatibility.

1. Import modules.

   ```ts
   // Import the usbManager module.
   import { usbManager } from '@kit.BasicServicesKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```
   
2. Obtain the USB device list.

> **NOTE**
>
> Bulk transfer can be performed only on the endpoint whose [transfer type](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md#usbendpointtransfertype18) is **2**. If an incorrect endpoint type is used, an I/O error is returned.

   ```ts
   // Obtain the USB device list.
   let deviceList : Array<usbManager.USBDevice> = usbManager.getDevices();
   console.info(`deviceList: ${deviceList}`);
   if(deviceList.length === 0) {
     console.error('deviceList is empty');
     return;
   }
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
                   type: 2, // Determine the transfer type.
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
     console.info(`usb device request right result: ${hasRight}`);
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
    Claim the corresponding interface from deviceList.
   interface1 must be one present in the device configuration.
   */
   usbManager.claimInterface(pipe, interface1, true);
   ```

5. Perform data transfer.

**NOTE**

> Before data transfer, you are advised to obtain the **type** of the **endpoint** to which the **interface** belongs and determine whether the **interface** supports the required transfer type.
>
> If the transfer API fails to be called, check whether the device interface supports [alternateSetting](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md#usbinterface). If it is supported, you can call [usbManager.setInterface](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md#usbmanagersetinterface) to reset the **interface** before data transfer to match the endpoint with the transfer type, ensuring normal communications.

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
      console.info(`usb readData result Length : ${dataLength}`);
    } else {
      console.error("usb readData failed");
    }
    }).catch((error : BusinessError) => {
    console.error(`usb readData error : ${error}`);
    });
    // Send data. Select the corresponding TX endpoint from deviceList for data transfer. (endpoint.direction == 0)
    usbManager.bulkTransfer(pipe, outEndpoint, dataUint8Array, 15000).then((dataLength : number) => {
      if (dataLength >= 0) {
        console.info(`usb writeData result write length : ${dataLength}`);
      } else {
        console.error("usb writeData failed");
      }
    }).catch((error : BusinessError) => {
      console.error(`usb writeData error : ${error}`);
    });
    ```

6. Release the USB interface, and close the USB device pipe.

   ```ts
   usbManager.releaseInterface(pipe, interface1);
   usbManager.closePipe(pipe);
   ```
