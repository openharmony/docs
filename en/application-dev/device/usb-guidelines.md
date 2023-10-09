# USB Service Development



## When to Use

In Host mode, you can obtain the list of connected USB devices, enable or disable the devices, manage device access permissions, and perform data transfer or control transfer.


## Available APIs

The USB service provides the following functions: query of USB device list, bulk data transfer, control transfer, and access permission management.

The following table lists the USB APIs currently available. For details, see the [API Reference](../reference/apis/js-apis-usbManager.md).

**Table 1** Open USB APIs

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| hasRight(deviceName: string): boolean                         | Checks whether the user has the device access permissions.|
| requestRight(deviceName: string): Promise&lt;boolean&gt;       | Requests the device access permissions for the application. This API uses a promise to return the result.                       |
| removeRight(deviceName: string): boolean | Revokes the device access permissions of the application.|
| connectDevice(device: USBDevice): Readonly&lt;USBDevicePipe&gt; | Connects to the USB device based on the device information returned by `getDevices()`.               |
| getDevices(): Array&lt;Readonly&lt;USBDevice&gt;&gt;          | Obtains the list of USB devices connected to the host. If no device is connected, an empty list is returned.                                           |
| setConfiguration(pipe: USBDevicePipe, config: USBConfiguration): number | Sets the USB device configuration.                                            |
| setInterface(pipe: USBDevicePipe, iface: USBInterface): number   | Sets a USB interface.                                            |
| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force ?: boolean): number | Claims a USB interface.                                                  |
| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout ?: number): Promise&lt;number&gt; | Performs bulk transfer.                                                  |
| closePipe(pipe: USBDevicePipe): number                         | Closes a USB device pipe.                                      |
| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | Releases a USB interface.                                                  |
| getFileDescriptor(pipe: USBDevicePipe): number                 | Obtains the file descriptor.                                              |
| getRawDescriptor(pipe: USBDevicePipe): Uint8Array              | Obtains the raw USB descriptor.                                       |
| controlTransfer(pipe: USBDevicePipe, controlparam: USBControlParams, timeout ?: number): Promise&lt;number&gt; | Performs control transfer.                                                  |


## How to Develop

You can set a USB device as a host to connect to a device for data transfer. The development procedure is as follows:


1. Obtain the USB device list.

   ```ts
   // Import the USB API package.
   import usb from '@ohos.usbManager';
   // Obtain the USB device list.
   let deviceList : Array<usb.USBDevice> = usb.getDevices();
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
   import usb from '@ohos.usbManager';
   import { BusinessError } from '@ohos.base';

   let deviceName : string = deviceList[0].name;
   // Request the permissions to operate a specified device.
   usb.requestRight(deviceName).then((hasRight : boolean) => {
     console.info("usb device request right result: " + hasRight);
   }).catch((error : BusinessError)=> {
     console.info("usb device request right failed : " + error);
   });
   ```

3. Open the device.

   ```ts
   // Open the device, and obtain the USB device pipe for data transfer.
   let pipe : USBDevicePipe = usb.connectDevice(deviceList[0]);
   let interface1 : number = deviceList[0].configs[0].interfaces[0];
   /*
    Claim the corresponding interface from **deviceList**.
   interface1 must be one present in the device configuration.
   */
   usb.claimInterface(pipe, interface1, true);
   ```

4. Perform data transfer.

   ```ts
   import usb from '@ohos.usbManager';
   import { BusinessError } from '@ohos.base';
   /*
    Read data. Select the corresponding RX endpoint from deviceList for data transfer.
   (endpoint.direction == 0x80); dataUint8Array indicates the data to read. The data type is Uint8Array.
   */
   let inEndpoint : USBEndpoint = interface1.endpoints[2];
   let outEndpoint : USBEndpoint = interface1.endpoints[1];
   let dataUint8Array : Array<number> = new Uint8Array(1024);
   usb.bulkTransfer(pipe, inEndpoint, dataUint8Array, 15000).then((dataLength : number) => {
   if (dataLength >= 0) {
     console.info("usb readData result Length : " + dataLength);
   } else {
     console.info("usb readData failed : " + dataLength);
   }
   }).catch((error : BusinessError) => {
   console.info("usb readData error : " + JSON.stringify(error));
   });
   // Send data. Select the corresponding TX endpoint from deviceList for data transfer. (endpoint.direction == 0)
   usb.bulkTransfer(pipe, outEndpoint, dataUint8Array, 15000).then((dataLength : number) => {
     if (dataLength >= 0) {
       console.info("usb writeData result write length : " + dataLength);
     } else {
       console.info("writeData failed");
     }
   }).catch((error : BusinessError) => {
     console.info("usb writeData error : " + JSON.stringify(error));
   });
   ```

5. Release the USB interface, and close the USB device.

   ```ts
   usb.releaseInterface(pipe, interface1);
   usb.closePipe(pipe);
   ```

