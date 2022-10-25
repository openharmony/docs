# USB Service Development

## When to Use

In Host mode, you can obtain the list of connected devices, enable or disable the devices, manage device access permissions, and perform data transfer or control transfer.

## APIs

The USB service provides the following functions: query of USB device list, bulk data transfer, control transfer, and access permission management.

The following table lists the USB APIs currently available. For details, see the [API Reference](../reference/apis/js-apis-usb.md).

**Table  1**  Open USB APIs

| API                                                          | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| hasRight(deviceName: string): boolean                        | Checks whether the user, for example, the application or system, has the device access permissions. The value **true** is returned if the user has the device access permissions; the value **false** is returned otherwise. |
| requestRight(deviceName: string): Promise\<boolean>          | Requests the temporary permission for a given application to access the USB device. |
| connectDevice(device: USBDevice): Readonly\<USBDevicePipe>   | Connects to the USB device based on the device information returned by `getDevices()`. |
| getDevices(): Array<Readonly\<USBDevice>>                    | Obtains the USB device list.                                 |
| setConfiguration(pipe: USBDevicePipe, config: USBConfig): number | Sets the USB device configuration.                           |
| setInterface(pipe: USBDevicePipe, iface: USBInterface): number | Sets a USB interface.                                        |
| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number | Claims a USB interface.                                       |
| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number): Promise\<number> | Performs bulk transfer.                                      |
| closePipe(pipe: USBDevicePipe): number                       | Closes a USB device pipe.                                    |
| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | Releases a USB interface.                                    |
| getFileDescriptor(pipe: USBDevicePipe): number               | Obtains the file descriptor.                                 |
| getRawDescriptor(pipe: USBDevicePipe): Uint8Array            | Obtains the raw USB descriptor.                              |
| controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise\<number> | Performs control transfer.                                   |

## How to Develop

You can set a USB device as the USB host to connect to other USB devices for data transfer. The development procedure is as follows:

1.  Obtain the USB device list.

    ```js
    // Import the USB API package.
    import usb from '@ohos.usb';
    // Obtain the USB device list.
    let deviceList = usb.getDevices();
    /*
    Example deviceList structure
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
        subclass: 0,
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
                subclass: 0,
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

2.  Obtain the device operation permissions.

    ```js
    let deviceName = deviceList[0].name;
    // Request the permissions to operate a specified device.
    usb.requestRight(deviceName).then(hasRight => {
      console.info("usb device request right result: " + hasRight);
    }).catch(error => {
      console.info("usb device request right failed : " + error);
    });
    ```

3.  Open the device.

    ```js
    // Open the device, and obtain the USB device pipe for data transfer.
    let pipe = usb.connectDevice(deviceList[0]);
    /*
    Claim the corresponding interface from deviceList.
    interface1 must be one present in the device configuration.
    */
    usb.claimInterface(pipe, interface1, true);
    ```

4.  Perform data transfer.

    ```js
    /*
    Read data. Select the corresponding RX endpoint from deviceList for data transfer.
    (endpoint.direction == 0x80); dataUint8Array indicates the data to read. The data type is Uint8Array.
    */
    
    usb.bulkTransfer(pipe, inEndpoint, dataUint8Array, 15000).then(dataLength => {
    if (dataLength >= 0) {
      console.info("usb readData result Length : " + dataLength);
      let resultStr = this.ab2str(dataUint8Array); // Convert uint8 data into a string.
      console.info("usb readData buffer : " + resultStr);
    } else {
      console.info("usb readData failed : " + dataLength);
    }
    }).catch(error => {
    console.info("usb readData error : " + JSON.stringify(error));
    });
    // Send data. Select the corresponding TX endpoint from deviceList for data transfer. (endpoint.direction == 0)
    usb.bulkTransfer(pipe, endpoint, dataUint8Array, 15000).then(dataLength => {
      if (dataLength >= 0) {
        console.info("usb writeData result write length : " + dataLength);
      } else {
        console.info("writeData failed");
      }
    }).catch(error => {
      console.info("usb writeData error : " + JSON.stringify(error));
    });
    ```

5.  Release the USB interface, and close the USB device.

    ```js
    usb.releaseInterface(pipe, interface);
    usb.closePipe(pipe);
    ```