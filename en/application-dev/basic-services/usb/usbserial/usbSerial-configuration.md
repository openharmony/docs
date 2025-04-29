# USB Serial Configuration Management

## Overview

In the USB serial configuration management, the baud rate, data bit, parity bit, and stop bit are the core parameters of the serial port communication protocol. They define the format and rules of data transmission. By properly setting these parameters, you can significantly improve the reliability and efficiency of serial port communication.

### Basic Concepts

Before developing the USB serial port, you should have a basic understanding of the following concepts:

- Baud rate

  The baud rate indicates the number of symbols transmitted by a serial port device per second. A symbol is a binary bit, including the data bit, start bit, stop bit, and parity bit. The unit is baud. For example, 9600 baud indicates that 9600 symbols are transmitted per second. The sender and receiver must use the same baud rate. Otherwise, data cannot be correctly parsed.


- Data bit

  The data bit indicates the number of valid binary bits actually transmitted in each data packet, which determines the data capacity of a single character. Commonly, a data bit may consist of five to eight digits. The data bit determines the amount of information transmitted at a time. The more the data bits, the larger the amount of information transmitted at a time, but more time is required for synchronization.


- Parity bit

  A parity bit is a 1-bit binary value appended to a data frame. It is generated based on the content of the data bit according to specific rules. Commonly, for an odd parity check, the total number of **1** in the data bits and parity bit is an odd number; for an even parity check, the total number of **1** is an even number; for no parity check, no parity bit is added to the data bit. By verifying the number of **1** in the data bit, the parity bit determines whether errors such as bit flipping and noise interference occur during data transfer. Increasing the parity bit slightly reduces the transfer efficiency but improves the error tolerance.


- Stop bit

  The stop bit is located at the end of a data frame. It is a logic high-level signal and is used to identify the end of a character (data packet) transfer. Its length can be 1 bit, 1.5 bits, or 2 bits. (In actual development, 1 bit is most commonly used, and 1.5 bits and 2 bits are mainly used in anti-interference scenarios.) A core function of this bit is to provide a space to tolerate the errors that may occur during time-sequence synchronization for a receiver and ensure data integrity.


## Preparing the Environment

For details, see [Preparing the Environment](usbSerial-overview.md#preparing-the-environment) in *USB Serial Communication Development Overview*.

## How to Develop

### Available APIs

| API                                                                         | Description       |
|------------------------------------------------------------------------------|-----------|
| getAttribute(portId: number): Readonly&lt;SerialAttribute&gt;                      | Obtains the serial port device configuration.|
| setAttribute(portId: number, attribute: SerialAttribute): void               | Sets the serial port device configuration.|

### Development Procedure

You can obtain and set the serial port configuration as follows:

1. Import the **usbManager** module.

    ```ts
    // Import the usbManager module.
    import serial from '@ohos.usbManager.serial';
    ``` 

2. Obtain the USB device list.

    ```ts
    // Obtain the list of USB devices connected to the host.
    let portList: serial.SerialPort[] = serial.getPortList();
    console.info('usbSerial portList: ' + JSON.stringify(portList));
    if (portList === undefined || portList.length === 0) {
      console.info('usbSerial portList is empty');
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
          console.info('usbSerial user is not granted the operation permission');
          return;
        }
      });
    }
    ```

4. Open the device based on the serial port.

    ```ts
    try {
      serial.open(portId)
      console.info('open usbSerial success, portId: ' + portId);
    } catch (error) {
      console.error('open usbSerial error, ' + JSON.stringify(error));
    }
    ```

5. Obtain and modify serial port configurations.

    ```ts
    // Obtain the serial port configuration.
    try {
      let attribute: serial.SerialAttribute = serial.getAttribute(portId);
      if (attribute === undefined) {
        console.error('getAttribute usbSerial error, attribute is undefined');
      } else {
        console.info('getAttribute usbSerial success, attribute: ' + JSON.stringify(attribute));
      }
    } catch (error) {
      console.error('getAttribute usbSerial error, ' + JSON.stringify(error));
    }
   
    // Set the serial port configuration.
    try {
      let attribute: serial.SerialAttribute = {
        baudRate: serial.BaudRates.BAUDRATE_9600,
        dataBits: serial.DataBits.DATABIT_8,
        parity: serial.Parity.PARITY_NONE,
        stopBits: serial.StopBits.STOPBIT_1
      }
      serial.setAttribute(portId, attribute);
      console.info('setAttribute usbSerial success, attribute: ' + JSON.stringify(attribute));
    } catch (error) {
      console.error('setAttribute usbSerial error, ' + JSON.stringify(error));
    }
    ```

### Debugging and Verification

1. Prepare a USB-to-serial cable. Connect the USB port and the serial port of the cable to that of the OpenHarmony device.
2. Execute the preceding sample code on the OpenHarmony device.
3. Return **getAttribute usbSerial success** and **setAttribute usbSerial success** if related APIs are successfully called. You can view the current serial port configuration.
