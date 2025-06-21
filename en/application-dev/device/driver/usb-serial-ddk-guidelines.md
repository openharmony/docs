# USB Serial DDK Development

## Overview

Non-standard serial port devices, such as temperature and humidity meters and special identity card readers, are used in industrial scenarios and on some legacy devices. If the system does not have a driver that adapts to the devices, the devices cannot be used after being connected. The USB Serial Driver Development Kit (DDK) is a toolset that helps you develop USB serial drivers at the application layer based on the user mode. The USB Serial DDK provides a series of APIs for the host to access devices, including APIs for enabling and disabling devices on the host and read/write data through serial ports. With these APIs, third-party peripheral devices can seamlessly integrate with the OpenHarmony ecosystem.

### Basic Concepts

Before developing the SCSI Peripheral DDK, you must understand the following basic concepts:

- **USB serial port**

    USB-to-Serial is an interface conversion technology that allows data communication with traditional serial ports (such as RS-232 and RS-485) over USB interfaces. This technology is usually implemented by using a dedicated hardware adapter or a specific built-in chip.

- **AMS**

    The Ability Manager Service (AMS) is a system service used to coordinate the running relationships of abilities and schedule the lifecycle of abilities. You can use it to start and disable **DriverExtensionAbility** during driver development.

- **BMS**

    The Bundle Manager Service (BMS) is responsible for application installation, uninstallation, and data management on OpenHarmony.

- **DDK**

    DDK is a tool package provided by OpenHarmony for developing drivers for non-standard USB serial port devices based on the peripheral framework.

- **Non-standard peripherals**

    Non-standard peripherals (also called custom peripherals or dedicated peripherals) are peripherals that do not comply with general standards or are customized for specific application scenarios. This type of device usually requires special software support or special interfaces to implement communication with the host system.

- **Standard peripherals**

    Standard peripherals refer to peripherals (such as USB keyboards and mouse devices) that comply with industry standards and specifications. Such devices typically have uniform interface protocols, physical dimensions, and electrical characteristics, so that they can be used interchangeably between different systems.

### Implementation Principles

A non-standard peripheral application obtains the USB serial port device ID by using the peripheral management service, and delivers the ID and the action to the USB serial port driver application through RPC. The USB serial port driver application can set the serial port attributes (such as the baud rate, data bit, and parity bit) and read the serial port data by calling the USB Serial DDK API. Then, the DDK API uses the HDI service to deliver instructions to the kernel driver, and the kernel driver uses instructions to communicate with the device.

**Figure 1** Principles of invoking the USB Serial DDK

![USBSerial_DDK schematic diagram](figures/ddk-schematic-diagram.png)

### Constraints

- The open APIs of USB Serial DDK can be used to develop drivers of non-standard USB peripherals that use USB serial ports.

- The open APIs of USB Serial DDK can be used only within the **DriverExtensionAbility** lifecycle.

- To use the open APIs of USB Serial DDK, you need to declare the matching ACL permissions in **module.json5**, for example, **ohos.permission.ACCESS_DDK_USB_SERIAL**.

## Environment Setup

Before you get started, make necessary preparations by following instructions in [Environment Preparation](environmental-preparation.md).

## How to Develop

### Available APIs

| Name| Description|
| -------- | -------- |
| OH_UsbSerial_Init(void) | Initializes the USB Serial DDK.|
| OH_UsbSerial_Release(void) | Releases the USB Serial DDK.|
| OH_UsbSerial_Open(uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_Device **dev) | Opens the USB serial port device based on the specified **deviceId** and **interfaceIndex**. Call **OH_UsbSerial_Close ()** to close the device after use. Otherwise, memory leakage occurs.|
| OH_UsbSerial_Close(UsbSerial_Device **dev) | Closes the USB serial port device after use. Otherwise, memory leakage occurs.|
| OH_UsbSerial_Read(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesRead) | Reads data from the USB serial port device to the buffer.|
| OH_UsbSerial_Write(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesWritten) | Writes the data in the buffer to the USB serial port device.|
| OH_UsbSerial_SetBaudRate(UsbSerial_DeviceHandle *dev, uint32_t baudRate) | Sets the baud rate for a USB serial port device. Call this API if the data bit of the serial port is **8**, the stop bit is **1**, and parity check is not performed.|
| OH_UsbSerial_SetParams(UsbSerial_Device *dev, UsbSerial_Params *params) | Sets the parameters of the USB serial port device, including the baud rate, data transfer bit, stop bit, and parity check.|
| OH_UsbSerial_SetTimeout(UsbSerial_Device *dev, int timeout) | Sets the timeout interval for reading data reported by a USB serial port device. The default value is **0**.|
| OH_UsbSerial_SetFlowControl(UsbSerial_Device *dev, UsbSerial_FlowControl flowControl) | Sets flow control parameters.|
| OH_UsbSerial_Flush(UsbSerial_Device *dev) | Flushes the input and output buffers after the write operation is complete.|
| OH_UsbSerial_FlushInput(UsbSerial_Device *dev) | Refreshes the input buffer. The data in the buffer is cleared immediately.|
| OH_UsbSerial_FlushOutput(UsbSerial_Device *dev) | Refreshes the output buffer. The data in the buffer is cleared immediately.|

For details about the APIs, see [USB Serial DDK](../../reference/apis-driverdevelopment-kit/_serial_ddk.md).

### How to Develop

To develop the USB serial port driver by using the USB Serial DDK, perform the following steps:

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**.
```txt
libusb_serial_ndk.z.so
```

**Including Header Files**
```c++
#include <serial/usb_serial_api.h>
#include <serial/usb_serial_types.h>
```

1. Initialize the USB Serial DDK.

    Use **OH_UsbSerial_Init** in **usb_serial_api.h** to initialize the USB Serial DDK.

    ```c++
    // Initialize the USB Serial DDK.
    OH_UsbSerial_Init();
    ```

2. Open the USB serial port device.

    Use **OH_UsbSerial_Open** in **usb_serial_api.h** to enable the device.

    ```c++
    UsbSerial_Device *dev = NULL;
    uint64_t deviceId = 1688858450198529;
    uint8_t interfaceIndex = 0;
    // Open the USB serial port device specified by deviceId and interfaceIndex.
    OH_UsbSerial_Open(deviceId, interfaceIndex, &dev);
    ```

3. Sets the parameters of the USB serial port device.

    Use **OH_UsbSerial_SetParams** in **usb_serial_api.h** to set the serial port parameters, or directly use **OH_UsbSerial_SetBaudRate** to set the baud rate, and use **OH_UsbSerial_SetTimeout** to set the timeout interval for reading data.

    ```c++
    UsbSerial_Params params;
    params.baudRate = 9600;
    params.nDataBits = 8;
    params.nStopBits = 1;
    params.parity = 0;
    // Set serial port parameters.
    OH_UsbSerial_SetParams(dev, &params);

    // Set the baud rate.
    uint32_t baudRate = 9600;
    OH_UsbSerial_SetBaudRate(dev, baudRate);

    // Set the timeout interval.
    int timeout = 500;
    OH_UsbSerial_SetTimeout(dev, timeout);
    ```

4. Set flow control and flush the buffer.

    Use **OH_UsbSerial_SetFlowControl** in **usb_serial_api.h** to set the flow control mode, use **OH_UsbSerial_Flush** to flush the buffer, use **OH_UsbSerial_FlushInput** to flush the input buffer, and use **OH_UsbSerial_FlushOutput** to flush the output buffer.

    ```c++
    // Set flow control.
    OH_UsbSerial_SetFlowControl(dev, USB_SERIAL_SOFTWARE_FLOW_CONTROL);

    // Flush the buffer.
    OH_UsbSerial_Flush(dev);

    // Flush the input buffer.
    OH_UsbSerial_FlushInput(dev);

    // Flush the output buffer.
    OH_UsbSerial_FlushOutput(dev);
    ```
5. Write or read data to or from a USB serial port device.

    Use **OH_UsbSerial_Write** in **usb_serial_api.h** to send data to the device, and use **OH_UsbSerial_Read** to read the data sent by the device.

    ```c++
    uint32_t bytesWritten = 0;
    // Command used by the test device to read data. The command varies depending on the device protocol.
    uint8_t writeBuff[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0xA};
    // Send data over the connection.
    OH_UsbSerial_Write(dev, writeBuff, sizeof(writeBuff), &bytesWritten);

    // Callback invoked to receive data.
    uint8_t readBuff[100];
    uint32_t bytesRead = 0;
    OH_UsbSerial_Read(dev, readBuff, sizeof(readBuff), &bytesRead);
    ```

6. Close the USB serial port device.

    After all requests are processed and before the program exits, use **OH_UsbSerial_Close** in **usb_serial_api.h** to close the device.
    ```c++
    // Close the device.
    OH_UsbSerial_Close(&dev);
    ```

7. Release the USB Serial DDK.

    After the USB serial port device is closed, use **OH_UsbSerial_Release** in **usb_serial_api.h** to release the USB Serial DDK.

    ```c++
    // Release the USB Serial DDK.
    OH_UsbSerial_Release();
    ```

### Debugging and Verification

Upon completion of driver application development, you can install the application on the OpenHarmony device. The test procedure is as follows:

1. Click the driver application on the device. The application is started on the device.
2. Click the set button to set serial port attributes such as the baud rate.
3. Click the data read button to read the data of the serial port device.
