# USB Service Development

<!--Kit: Basic Services Kit-->
<!--Subsystem: USB-->
<!--Owner: @hwymlgitcode-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## When to Use

In Host mode, you can obtain the list of connected USB devices, enable or disable the devices, manage device access permissions, and perform data transfer or control transfer.


## Available APIs

The USB service provides the following functions: query of USB device list, bulk data transfer, control transfer, and access permission management.

The following table lists the USB APIs currently available. For details, see the [API Reference](../../reference/apis-basic-services-kit/js-apis-usbManager.md).

**Table 1** Open USB APIs

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| hasRight(deviceName: string): boolean                         | Checks whether the user has the device access permissions.|
| requestRight(deviceName: string): Promise&lt;boolean&gt;       | Requests the device access permissions for the application. This API uses a promise to return the result.                       |
| removeRight(deviceName: string): boolean | Revokes the device access permissions of the application.|
| connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt; | Connects to the USB device based on the device information returned by **getDevices()**. If the USB service is abnormal, **undefined** may be returned. Check whether the return value of the API is empty.               |
| getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;          | Obtains the list of USB devices connected to the host. If no device is connected, an empty list is returned. When the developer mode is disabled, **undefined** may be returned if no device is connected. Check whether the return value of the API is empty.                                           |
| setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number | Sets the USB device configuration.                                            |
| setInterface(pipe: USBDevicePipe, iface: USBInterface): number   | Sets a USB interface.                                            |
| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force ?: boolean): number | Claims a USB interface.                                                  |
| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout ?: number): Promise&lt;number&gt; | Performs bulk transfer.                                                  |
| closePipe(pipe: USBDevicePipe): number                         | Closes a USB device pipe.                                      |
| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | Releases a USB interface.                                                  |
| getFileDescriptor(pipe: USBDevicePipe): number                 | Obtains the file descriptor.                                              |
| getRawDescriptor(pipe: USBDevicePipe): Uint8Array              | Obtains the raw USB descriptor. If the USB service is abnormal, **undefined** may be returned. Check whether the return value of the API is empty.                                       |
| usbControlTransfer(pipe: USBDevicePipe, requestparam: USBDeviceRequestParams, timeout?: number): Promise&lt;number&gt; | Performs control transfer.                                                  |


## How to Develop

You can set a USB device as a host to connect to a device for data transfer. The development procedure is as follows:


1. Obtain the USB device list.

   ```ts
   // Import the USB API package.
   import { usbManager } from '@kit.BasicServicesKit';
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

2. Obtain the device operation permissions.

   ```ts
   import { usbManager } from '@kit.BasicServicesKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let deviceName : string = deviceList[0].name;
   // Request the permissions to operate a specified device.
   usbManager.requestRight(deviceName).then((hasRight : boolean) => {
     console.info(`usb device request right result: ${hasRight}`);
   }).catch((error : BusinessError)=> {
     console.error(`usb device request right failed : ${error}`);
   });
   ```

3. Open the device.

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

4. Perform data transfer. Currently, only bulk transfer and control transfer are supported.

    - Bulk transfer

    ```ts
    import { usbManager } from '@kit.BasicServicesKit';
    import { BusinessError } from '@kit.BasicServicesKit';
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
      console.error(`usb readData failed`);
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

    - Control transfer

    ```ts
    import { usbManager } from '@kit.BasicServicesKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    /*
      Construct control transfer parameters.
    */
    let param: usbManager.USBDeviceRequestParams = {
      bmRequestType: 0x80,    // 0x80 indicates a standard request for data transfer from the device to the host.
      bRequest: 0x06,    // 0x06 indicates a request for the descriptor.
      wValue:0x01 << 8 | 0,    // The value is of two bytes. The high byte indicates the descriptor type. Here, 0x01 indicates the device descriptor. The low byte indicates the descriptor index. The value is set to 0 because it is not involved for the device descriptor.
      wIndex: 0,    // Descriptor index. The value can be 0.
      wLength: 18,    // Descriptor length. The value 18 indicates that a maximum of 1024 characters are supported.
      data: new Uint8Array(18)
    };

    usbManager.usbControlTransfer(pipe, param).then((ret: number) => {
    console.info(`usbControlTransfer = ${ret}`);
    })
    ```

5. Release the USB interface, and close the USB device.

   ```ts
   usbManager.releaseInterface(pipe, interface1);
   usbManager.closePipe(pipe);
   ```