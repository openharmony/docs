# usb_serial_ddk_types.h


## Overview

Provides the enum variables, structures, and macros used in USB Serial DDK APIs.

**Library**: libusb_serial.z.so

**File to include**: &lt;serial/usb_serial_ddk_types.h&gt;

**System capability**: SystemCapability.Driver.SERIAL.Extension

**Since**: 16

**Related module**: [USB Serial DDK](_serial_ddk.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[UsbSerial_Params](_usb_serial___params.md) | Defines the USB serial port parameters for the USB Serial DDK.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle)[UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) | Data structure of the USB serial port device (opaque).| 
| typedef struct [UsbSerial_Params](_usb_serial___params.md) __attribute__((aligned(8))) [UsbSerial_Params](_usb_serial___params.md) | USB serial port parameters used by the USB Serial DDK.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [UsbSerial_DdkRetCode](_serial_ddk.md#usbserial_ddkretcode) {<br>USB_SERIAL_DDK_NO_PERM = 201, USB_SERIAL_DDK_INVALID_PARAMETER = 401, USB_SERIAL_DDK_SUCCESS = 31600000, USB_SERIAL_DDK_INVALID_OPERATION = 31600001, USB_SERIAL_DDK_INIT_ERROR = 31600002, USB_SERIAL_DDK_SERVICE_ERROR = 31600003, USB_SERIAL_DDK_MEMORY_ERROR = 31600004, USB_SERIAL_DDK_IO_ERROR = 31600005, USB_SERIAL_DDK_DEVICE_NOT_FOUND = 31600006<br>} | Defines the return codes used by the USB Serial DDK.| 
| [UsbSerial_FlowControl](_serial_ddk.md#usbserial_flowcontrol) { USB_SERIAL_NO_FLOW_CONTROL = 0, USB_SERIAL_SOFTWARE_FLOW_CONTROL = 1, USB_SERIAL_HARDWARE_FLOW_CONTROL = 2 } | Defines the flow control mode for the USB Serial DDK.| 
| [UsbSerial_Parity](_serial_ddk.md#usbserial_parity) { USB_SERIAL_PARITY_NONE = 0, USB_SERIAL_PARITY_ODD = 1, USB_SERIAL_PARITY_EVEN = 2 } | Defines the enums of the parity parameter used by the USB Serial DDK.| 


### Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [baudRate](#baudrate) | Baud rate.| 
| uint8_t [nDataBits](#ndatabits) | Number of data transfer bits.| 
| uint8_t [nStopBits](#nstopbits) | Number of data stop bits.| 
| uint8_t [parity](#parity) | Parity settings.| 


## Variable Description


### baudRate

```
uint32_t baudRate
```

**Description**

Baud rate.


### nDataBits

```
uint8_t nDataBits
```

**Description**

Number of data transfer bits.


### nStopBits

```
uint8_t nStopBits
```

**Description**

Number of data stop bits.


### parity

```
uint8_t parity
```

**Description**

Parity settings.
