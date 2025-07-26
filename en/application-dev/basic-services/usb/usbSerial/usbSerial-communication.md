# USB Serial Communication Management

## Overview

In the USB serial communication service, the USB port of the host is connected to the serial port of the serial port device for serial data transmission. The core objective of communication management is to implement efficient and stable data transmission and collaborative control between devices. It is mainly used in scenarios such as industrial automation and remote management, IoT device interconnection, and medical device management.

## Preparing the Environment

For details, see [Preparing the Environment](usbSerial-overview.md#preparing-the-environment) in *USB Serial Communication Development Overview*.

## How to Develop

### Available APIs

| API                                                                         | Description                      |
|------------------------------------------------------------------------------|--------------------------|
| getPortList(): Readonly&lt;SerialPort&gt;[]                                        | Obtains the serial port device list.               |
| hasSerialRight(portId: number): boolean                                      | Checks whether the application has the permission to access the serial port device.    |
| requestSerialRight(portId: number): Promise&lt;boolean&gt;                         | Requests the permission to access the serial port device.           |
| open(portId: number): void                                                   | Opens a serial port device.                 |
| close(portId: number): void                                                  | Closes a serial port device.                 |
| read(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt;  | Reads data from a serial port device. This API uses a promise to return the result.|
| readSync(portId: number, buffer: Uint8Array, timeout?: number): number       | Reads data from a serial port device in a synchronous manner.         |
| write(portId: number, buffer: Uint8Array, timeout?: number): Promise&lt;number&gt; | Writes data to a serial port device. This API uses a promise to return the result.|
| writeSync(portId: number, buffer: Uint8Array, timeout?: number): number      | Writes data to a serial port device in a synchronous manner.         |


### Development Procedure

You can read and write data as follows:

> **NOTE**
>
> The following sample code shows only a basic process. You should execute the code in a specific method.

1. Import the **usbManager** module.

    ```ts
    // Import the usbManager module.
    import serial from '@ohos.usbManager.serial';
    import { buffer } from '@kit.ArkTS';
    ```

2. Obtain the USB device list.

    ```ts
    // Obtain the list of USB devices connected to the host.
    let portList: serial.SerialPort[] = serial.getPortList();
    console.info(`usbSerial portList: ${portList}`);
    if (portList === undefined || portList.length === 0) {
      console.error('usbSerial portList is empty');
      return;
    }
    ```

3. Obtain the device operation permissions.

    ```ts
    // Check whether the first USB device in the list has the access permission.
    let portId: number = portList[0].portId;
    if (!serial.hasSerialRight(portId)) {
      await serial.requestSerialRight(portId).then(result => {
        if(!result) {
          // If the device does not have the access permission and is not granted by the user, the device exits.
          console.error('The user does not have permission to perform this operation');
          return;
        }
      });
    }
    ```

4. Open the device based on the serial port.

    ```ts
    try {
      serial.open(portId)
      console.info(`open usbSerial success, portId: ${portId}`);
    } catch (error) {
      console.error(`open usbSerial error: ${error}`);
    }
    ```

5. Read data through the serial port.

    ```ts
    // Read data asynchronously.
    let readBuffer: Uint8Array = new Uint8Array(64);
    serial.read(portId, readBuffer, 2000).then((size: number) => {
      console.info(`read usbSerial success, readBuffer: ${readBuffer}`);
    }).catch((error: Error) => {
      console.error(`read usbSerial error: ${error}`);
    })

    // Read data synchronously.
    let readSyncBuffer: Uint8Array = new Uint8Array(64);
    try {
      serial.readSync(portId, readSyncBuffer, 2000);
      console.info(`readSync usbSerial success, readSyncBuffer: ${readSyncBuffer}`);
    } catch (error) {
      console.error(`readSync usbSerial error: ${error}`);
    }
    ```

6. Write data through the serial port.

    ```ts
    // Write data asynchronously.
    let writeBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
    serial.write(portId, writeBuffer, 2000).then((size: number) => {
      console.info(`write usbSerial success, writeBuffer: ${writeBuffer}`);
    }).catch((error: Error) => {
      console.error(`write usbSerial error: ${error}`);
    })

    // Write data synchronously.
    let writeSyncBuffer: Uint8Array = new Uint8Array(buffer.from('Hello World', 'utf-8').buffer)
    try {
      serial.writeSync(portId, writeSyncBuffer, 2000);
      console.info(`writeSync usbSerial success, writeSyncBuffer: ${writeSyncBuffer}`);
    } catch (error) {
      console.error(`writeSync usbSerial error: ${error}`);
    }
    ```
   
7. Close a serial port device.

    ```ts
    try {
      serial.close(portId);
      console.info(`close usbSerial success, portId: ${portId}`);
    } catch (error) {
      console.error(`close usbSerial error: ${error}`);
    }
    ```

### Debugging and Verification

1. Prepare a USB-to-serial cable. Connect the USB port and the serial port of the cable to that of the OpenHarmony device.
2. Execute the preceding sample code on the OpenHarmony device.
3. Return **usbSerial success** if the related API is successfully called and the serial port communication of the device runs properly; return **usbSerial error** otherwise.
