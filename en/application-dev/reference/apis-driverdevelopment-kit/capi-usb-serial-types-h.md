# usb_serial_types.h

## Overview

Provides the enumerated variables, structures, and macros used in USB SERIAL DDK APIs.

**File to include**: <usb_serial/usb_serial_types.h>

**Library**: libusb_serial.z.so

**System capability**: SystemCapability.Driver.UsbSerial.Extension

**Since**: 18

**Related module**: [SerialDdk](capi-serialddk.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [UsbSerial_Params](capi-serialddk-usbserial-params.md) | __attribute__((aligned(8))) UsbSerial_Params | Defines the USB serial port parameters for the USB SERIAL DDK.|
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) | UsbSerial_DeviceHandle | Defines the data structures for the USB serial port device (opaque).|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [UsbSerial_DdkRetCode](#usbserial_ddkretcode) | UsbSerial_DdkRetCode | Defines the return codes used by the USB SERIAL DDK.|
| [UsbSerial_FlowControl](#usbserial_flowcontrol) | UsbSerial_FlowControl | Defines the flow control mode for the USB SERIAL DDK.|
| [UsbSerial_Parity](#usbserial_parity) | UsbSerial_Parity | Defines the enums of the parity parameter used by the USB SERIAL DDK.|

## Enum Description

### UsbSerial_DdkRetCode

```
enum UsbSerial_DdkRetCode
```

**Description**

Defines the return codes used by the USB SERIAL DDK.

**Since**: 18

| Enum| Description|
| -- | -- |
| USB_SERIAL_DDK_NO_PERM = 201 | No access permission.|
| USB_SERIAL_DDK_INVALID_PARAMETER = 401 | Invalid parameter.|
| USB_SERIAL_DDK_SUCCESS = 31600000 | Operation success.|
| USB_SERIAL_DDK_INVALID_OPERATION = 31600001 | Invalid operation.|
| USB_SERIAL_DDK_INIT_ERROR = 31600002 | Initialization error.|
| USB_SERIAL_DDK_SERVICE_ERROR = 31600003 | Service error.|
| USB_SERIAL_DDK_MEMORY_ERROR = 31600004 | Memory-related errors, such as insufficient memory, memory data replication failure, or memory application fault.|
| USB_SERIAL_DDK_IO_ERROR = 31600005 | I/O error.|
| USB_SERIAL_DDK_DEVICE_NOT_FOUND = 31600006 | Device not found.|

### UsbSerial_FlowControl

```
enum UsbSerial_FlowControl
```

**Description**

Defines the flow control mode for the USB SERIAL DDK.

**Since**: 18

| Enum| Description|
| -- | -- |
| USB_SERIAL_NO_FLOW_CONTROL = 0 | No flow control.|
| USB_SERIAL_SOFTWARE_FLOW_CONTROL = 1 | Software flow control.|
| USB_SERIAL_HARDWARE_FLOW_CONTROL = 2 | Hardware flow control.|

### UsbSerial_Parity

```
enum UsbSerial_Parity
```

**Description**

Defines the enums of the parity parameter used by the USB SERIAL DDK.

**Since**: 18

| Enum| Description|
| -- | -- |
| USB_SERIAL_PARITY_NONE = 0 | No parity.|
| USB_SERIAL_PARITY_ODD = 1 | Odd parity.|
| USB_SERIAL_PARITY_EVEN = 2 | Even parity.|
