# USB Interrupt Transfer

## When to Use

The interrupt transfer is mainly used by the host to receive a data packet sent by a device. The endpoint mode of a device determines whether the interface supports interrupt reading or interrupt writing. This mode is applicable to the transfer of a small number of scattered and unpredictable data input by devices such as the mouse, keyboard, and joystick. In addition, the endpoints of these devices support only interrupt reading.

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
- Update the public SDK to API version 16 or later. For details, see [Switching to Full SDK](https://gitee.com/openharmony/docs/blob/master/en/application-dev/faqs/full-sdk-switch-guide.md).
- Install hdc on the PC. You can use it to interact with a real device or the Emulator on Windows, Linux, or macOS. For details, see [HDC Configuration](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/hdc).
- Use a USB cable to connect a device to the PC.

## How to Develop

### Available APIs

| API                                                                                                             | Description                                                     |
|------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| usbSubmitTransfer(transfer: UsbDataTransferParams): void                                                         | Submits isochronous, bulk, or interrupt transfer in an asynchronous manner.                                  |
| usbCancelTransfer(transfer: UsbDataTransferParams): void                                                         | Cancels the submitted asynchronous transfer.                                            |

For details about the APIs of device management and transfer modes, see [@ohos.usbManager (USB Manager)](../../../../reference/apis-basic-services-kit/js-apis-usbManager.md).

### How to Develop

Connect a host to a device and use the **usbSubmitTransfer** API to transfer data. The following steps describe how to implement an interrupt transfer:

> **NOTE**
>
> The following sample code shows only a basic process. You should execute the code in a specific method. When calling this method, you must comply with device protocols to ensure proper data transfer and device compatibility.

1. Import modules.

    ```ts
    // Import the usbManager module.
    import { usbManager } from '@kit.BasicServicesKit';
    ```
   
2. Obtain the USB device list.

    ```ts
    // Obtain the list of USB devices connected to the host.
    let usbDevices: Array<usbManager.USBDevice> = usbManager.getDevices();
    console.info(`usbDevices: ${usbDevices}`);
    if(usbDevices.length === 0) {
      console.error('usbDevices is empty');
      return;
    }
    ```

3. Obtain the device operation permissions.

    ```ts
    // Check whether the first USB device in the list has the access permission.
    let usbDevice: usbManager.USBDevice = usbDevices[0];
    if(!usbManager.hasRight(usbDevice.name)) {
      await usbManager.requestRight(usbDevice.name).then(result => {
        if(!result) {
          // If the USB device does not have the access permission and is not granted by the user, the device exits.
          console.error('The user does not have permission to perform this operation');
          return;
        }
      });
    }
    ```

4. Obtain the endpoint for reading data through interrupt transfer.

   ```ts
   let devicePipe: usbManager.USBDevicePipe = usbManager.connectDevice(usbDevice);
   let usbConfigs: usbManager.USBConfiguration[] = usbDevice.configs;
   let usbInterfaces: usbManager.USBInterface[] = [];
   let usbInterface: usbManager.USBInterface | undefined = undefined
   let usbEndpoints: usbManager.USBEndpoint[] = [];
   let usbEndprint: usbManager.USBEndpoint | undefined = undefined
   for (let i = 0; i < usbConfigs.length; i++) {
     usbInterfaces = usbConfigs[i].interfaces;
     for (let i = 0; i < usbInterfaces.length; i++) {
       usbEndpoints = usbInterfaces[i].endpoints;
       usbEndprint = usbEndpoints.find((value) => {
         return value.direction === 128 && value.type === usbManager.UsbEndpointTransferType.TRANSFER_TYPE_INTERRUPT;
       })
       if (usbEndprint !== undefined) {
         usbInterface = usbInterfaces[i];
         break;
       }
     }
   }
   if (usbEndprint === undefined) {
     console.error(`get usbEndprint error`)
     return;
   }
   ```

5. Connect to the device and register the communication interface.

    ```ts
    // Register a communication interface. If the registration is successful, 0 is returned; otherwise, other error codes are returned.
    let claimInterfaceResult: number = usbManager.claimInterface(devicePipe, usbInterface, true);
    if (claimInterfaceResult !== 0) {
      console.error(`claimInterface error = ${claimInterfaceResult}`)
      return;
    }
    ```

6. Perform data transfer.

   ```ts
   try {
     // The communication interface is successfully registered and performs data transfer.
     let transferParams: usbManager.UsbDataTransferParams = {
       devPipe: devicePipe,
       flags: usbManager.UsbTransferFlags.USB_TRANSFER_SHORT_NOT_OK,
       endpoint: usbEndprint.address,
       type: usbManager.UsbEndpointTransferType.TRANSFER_TYPE_INTERRUPT,
       timeout: 2000,
       length: 10,
       callback: () => {},
       userData: new Uint8Array(10),
       buffer: new Uint8Array(10),
       isoPacketCount: 2,
     };
   
     transferParams.callback = (err: Error, callBackData: usbManager.SubmitTransferCallback) => {
       console.info(`callBackData = ${callBackData}`);
       console.info(`transfer success, result = ${transferParams.buffer}`);
     }
     usbManager.usbSubmitTransfer(transferParams);
     console.info('USB transfer request submitted.');
   } catch (error) {
     console.error(`USB transfer failed: ${error}`);
   }
   ```

7. Cancels the data transfer, releases the interface, and closes the USB device pipe.

    ```ts
    usbManager.usbCancelTransfer(transferParams);
    usbManager.releaseInterface(devicePipe, usbInterface);
    usbManager.closePipe(devicePipe);
    ```

### Verification

1. Connect the host to a terminal device (such as a mouse or a keyboard) that supports interrupt transfer through a USB interface.
2. Execute the preceding code.
3. Search for the keyword **transfer success** in the log. If the keyword is found, the interrupt transfer interface is successfully called.
