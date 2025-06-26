# USB Control Transfer

## When to Use

The control transfer is used to obtain and set the device status, and control the device attribute status. You can determine whether the control transfer can read or write data based on the endpoint types supported by the device.

## Preparing the Environment

### Environment Requirements

- Development tool and configuration:

  DevEco Studio, as the driver development tool, allows you to develop, debug, and package drivers. [Download and install](https://developer.huawei.com/consumer/en/download/) DevEco Studio and verify basic operations to ensure that it can function properly. For details, see [Creating a Project](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-create-new-project) in [DevEco Studio User Guide](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-tools-overview).


- SDK version configuration:

  The ArkTs APIs for peripheral management can be used only when the SDK is of API version 16 or later.


- HDC configuration:

  HarmonyOS Device Connector (hdc) is a command-line tool for debugging. It can be used to interact with real devices or the Emulators on Windows, Linux, and macOS. For details about the configuration, see [hdc](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc).

### Environment Setup

- Install [DevEco Studio](https://developer.huawei.com/consumer/cn/download/deveco-studio) 4.1 or later on the PC.
- Update the public SDK to API version 16 or later. For details, see [Switching to Full SDK](https://gitee.com/openharmony/docs/blob/master/en/application-dev/faqs/full-sdk-switch-guide.md).
- Install hdc on the PC. You can use it to interact with a real device or the Emulator on Windows, Linux, or macOS. For details, see [HDC Configuration](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/hdc).
- Use a USB cable to connect a device to the PC.

## How to Develop

### Available APIs

| API                                                      | Description    |
| ------------------------------------------------------------ |--------|
| usbControlTransfer(pipe: USBDevicePipe, requestparam: USBDeviceRequestParams, timeout?: number): Promise&lt;number&gt; | Performs control transfer. |

For details about the APIs of device management and transfer modes, see [@ohos.usbManager (USB Manager)](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md).

### Development Procedure

Connect a host to a device and use the **usbControlTransfer** API to transfer data. The following steps describe how to implement a control transfer:

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
    Claim the corresponding interface from deviceList.
   interface1 must be one present in the device configuration.
   */
   usbManager.claimInterface(pipe, interface1, true);
   ```

5. Perform data transfer.

    ```ts
    /*
      Construct control transfer parameters.
    */
    let param: usbManager.USBDeviceRequestParams = {
      bmRequestType: 0x80,    // 0x80 indicates a standard request for data transfer from the device to the host.
      bRequest: 0x06,    // 0x06 indicates a request for the descriptor.
      wValue:0x01 << 8 | 0,    // The value is of two bytes. The high byte indicates the descriptor type. Here, 0x01 indicates the device descriptor. The low byte indicates the descriptor index. The value is set to 0 because it is not involved for the device descriptor.
      wIndex: 0,    // Descriptor index. The value can be 0.
      wLength: 18,    // Descriptor length. The value 18 indicates the length of a device descriptor. A maximum of 1024 characters are supported.
      data: new Uint8Array(18)
    };

    usbManager.usbControlTransfer(pipe, param).then((ret: number) => {
    console.info(`usbControlTransfer = ${ret}`);
    })
    ```

6. Release the USB interface, and close the USB device pipe.

   ```ts
   usbManager.releaseInterface(pipe, interface1);
   usbManager.closePipe(pipe);
   ```
