# USB Service Terms

## B

### Baud rate

The baud rate indicates the number of symbols transmitted by a serial port device per second. A symbol is a binary bit, including the data bit, start bit, stop bit, and parity bit. The unit is baud. For example, 9600 baud indicates that 9600 symbols are transmitted per second. The sender and receiver must use the same baud rate. Otherwise, data cannot be correctly parsed.

### Bulk transfer

A one-way data transfer mode of the USB service, which is applicable to the scenario where a large amount of data needs to be transferred. During the transfer, the bulk transactions (IN/OUT token packet, data packet, and handshake packet) are used to increase the overall transfer volume, and the error detection and retransfer mechanisms are used to ensure the reliability of data transfer. However, bulk transfer has the lowest priority among the USB transfer modes. It is mainly used in devices that require low real-time performance but high reliability, such as USB flash drives, printers, and scanners.

## C

### Control transfer

A two-way data transfer mode of the USB service, which is applicable to device configuration, status query, and command transfer. Its process consists of three phases: setup phase (SETUP transaction), data phase (optional batch transaction), and status phase (handshake confirmation). This mode is mainly used for basic control operations such as device enumeration (such as descriptor reading), initialization configuration, and firmware upgrade.

## D

### Data bit

The data bit indicates the number of valid binary bits actually transmitted in each data packet, which determines the data capacity of a single character. Commonly, a data bit may consist of five to eight digits. The data bit determines the amount of information transmitted at a time. The more the data bits, the larger the amount of information transmitted at a time, but more time is required for synchronization.

### Device

A device is a peripheral connected to the host. It executes specific functions (such as storage and data input/output) and passively responds to instructions from the host. For example, a USB flash drive, mouse, or printer is a device.

## E

### Endpoint

An endpoint is a logical end point for data transfer between a device and a host. It is a basic unit for USB communication. Each endpoint has a unique address and direction (**IN** indicates device-to-host, and **OUT** indicates host-to-device). Each endpoint represents a one-way or two-way data transfer pipe.

## H

### Host

The host is a device that controls and manages the USB. It manages the connected devices on the bus and coordinates data transfer and communication. The host is usually a calculator or another host, such as a PC, a smartphone, or a tablet, which can connect to and control multiple devices through the USB port to provide data transfer and charging.

## I

### Interface

An interface is a logical abstraction of a functional module in a USB device, and represents an independent function (such as audio, storage, or communication) of the device. Each interface contains a group of endpoints and manages their activation status through USB configuration. Through flexible interface configuration, USB devices can reuse multiple functions and dynamically switch functions. This is the core mechanism for the USB protocol to support plug-and-play and complex peripherals.

### Interrupt transfer

A one-way data transfer mode of the USB service. The host periodically polls the device (for example, 1 ms to 255 ms) to ensure isochronous performance and accuracy. The transaction structure is similar to that of bulk transfer, but the priority is higher. It is applicable to input devices that require low-latency response, such as keyboard, mouse, and game controller.

### Isochronous transfer

A one-way data transfer mode of the USB service. No handshake packet is transferred. The fixed bandwidth is used to ensure isochronous performance but allow data loss. A transaction contains only tokens and data phases and is suitable for streaming media transfer. It is applicable to devices that require high continuity and fault tolerance, such as cameras, USB speakers, and video conferencing devices.

## P

### Parity bit

A parity bit is a 1-bit binary value appended to a data frame. It is generated based on the content of the data bit according to specific rules. Commonly, for an odd parity check, the total number of **1** in the data bits and parity bit is an odd number; for an even parity check, the total number of **1** is an even number; for no parity check, no parity bit is added to the data bit. By verifying the number of **1** in the data bit, the parity bit determines whether errors such as bit flipping and noise interference occur during data transfer. Increasing the parity bit slightly reduces the transfer efficiency but improves the error tolerance.

### Pipe

A pipe is a logical communication channel between a host and an endpoint for data transfer. A pipe is not a physical connection, but an abstract communication path between a host and a device endpoint. Each pipe corresponds to a specific endpoint of the device. Pipes provide one-way data transfer, and the direction is determined by the endpoint. For example, the IN endpoint indicates that the data is transferred from a pipe to the host, while the OUT endpoint indicates that the data is transferred from the host to a pipe.
  
## S

### Stop bit

The stop bit is located at the end of a data frame. It is a logic high-level signal and is used to identify the end of a character (data packet) transfer. Its length can be 1 bit, 1.5 bits, or 2 bits. (In actual development, 1 bit is most commonly used, and 1.5 bits and 2 bits are mainly used in anti-interference scenarios.) A core function of this bit is to provide a space to tolerate the errors that may occur during time-sequence synchronization for a receiver and ensure data integrity.

## U

### USBConfiguration

USBConfiguration indicates a function set of the USB device. A USB device supports multiple configurations, but only one of them can be activated at a time. Each USBconfiguration contains multiple interfaces, and each interface represents an independent function (such as data transfer and audio output). In addition, each interface contains multiple endpoints for data transfer (such as control transfer and bulk transfer).
