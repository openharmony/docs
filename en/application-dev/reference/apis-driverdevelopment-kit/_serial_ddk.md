# USB Serial DDK

## Overview

USB Serial DDK is a development kit for USB drivers. This module provides USB Serial DDK APIs as well as the enum types and data structs used by them.

Serial port communication is often used in industrial scenarios and some legacy devices, such as card issuers and ID card readers. By using the USB Serial DDK APIs, you can develop extended drivers for non-standard peripherals to implement extended functions for USB serial port devices.

**System capability**: SystemCapability.Driver.SERIAL.Extension

**Since**: 16


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [usb_serial_ddk_api.h](usb__serial__ddk__api_8h.md) | Declares the USB Serial DDK APIs used by the host to access the serial port device.<br>**File to include**: &lt;serial/usb_serial_ddk_api.h&gt;<br>**Library**: libusb_serial.z.so| 
| [usb_serial_ddk_types.h](usb__serial__ddk__types_8h.md) | Provides the enum variables, structures, and macros used in USB Serial DDK APIs.<br>**File to include**: &lt;serial/usb_serial_ddk_types.h&gt;<br>**Library**: libusb_serial.z.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[UsbSerial_Params](_usb_serial___params.md) | Defines the USB serial port parameters for the USB Serial DDK.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [UsbSerial_DeviceHandle](#usbserial_devicehandle)[UsbSerial_DeviceHandle](#usbserial_devicehandle) | Defines the data structures for the USB serial port device (opaque).| 
| typedef struct [UsbSerial_Params](_usb_serial___params.md) __attribute__((aligned(8))) [UsbSerial_Params](_usb_serial___params.md) | Defines the USB serial port parameters used by the USB Serial DDK.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [UsbSerial_DdkRetCode](#usbserial_ddkretcode) {<br>USB_SERIAL_DDK_NO_PERM = 201, USB_SERIAL_DDK_INVALID_PARAMETER = 401, USB_SERIAL_DDK_SUCCESS = 31600000, USB_SERIAL_DDK_INVALID_OPERATION = 31600001, USB_SERIAL_DDK_INIT_ERROR = 31600002, USB_SERIAL_DDK_SERVICE_ERROR = 31600003, USB_SERIAL_DDK_MEMORY_ERROR = 31600004, USB_SERIAL_DDK_IO_ERROR = 31600005, USB_SERIAL_DDK_DEVICE_NOT_FOUND = 31600006<br>} | Defines the return codes used by the USB Serial DDK.| 
| [UsbSerial_FlowControl](#usbserial_flowcontrol) { USB_SERIAL_NO_FLOW_CONTROL = 0, USB_SERIAL_SOFTWARE_FLOW_CONTROL = 1, USB_SERIAL_HARDWARE_FLOW_CONTROL = 2 } | Defines the flow control in the USB Serial DDK.| 
| [UsbSerial_Parity](#usbserial_parity) { USB_SERIAL_PARITY_NONE = 0, USB_SERIAL_PARITY_ODD = 1, USB_SERIAL_PARITY_EVEN = 2 } | Defines the enums of the parity parameter used by the USB Serial DDK.| 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_UsbSerial_Init](#oh_usbserial_init) (void) | Initializes the USB Serial DDK.| 
| int32_t [OH_UsbSerial_Release](#oh_usbserial_release) (void) | Releases the USB Serial DDK.| 
| int32_t [OH_UsbSerial_Open](#oh_usbserial_open) (uint64_t deviceId, uint8_t interfaceIndex, [UsbSerial_DeviceHandle](#usbserial_devicehandle) \*\*dev) | Enables the USB serial port device based on the specified **deviceId** and **interfaceIndex**.| 
| int32_t [OH_UsbSerial_Close](#oh_usbserial_close) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | Disables the USB serial port device.| 
| int32_t [OH_UsbSerial_Read](#oh_usbserial_read) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesRead) | Reads data from the USB serial port device to the buffer.| 
| int32_t [OH_UsbSerial_Write](#oh_usbserial_write) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesWritten) | Writes the data in the buffer to the USB serial port device.| 
| int32_t [OH_UsbSerial_SetBaudRate](#oh_usbserial_setbaudrate) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, uint32_t [baudRate](usb__serial__ddk__types_8h.md#baudrate)) | Sets the baud rate for a USB serial port device. If the parameters of the USB serial port device are set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the baud rate.| 
| int32_t [OH_UsbSerial_SetParams](#oh_usbserial_setparams) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, [UsbSerial_Params](_usb_serial___params.md) \*params) | Sets the parameters of the USB serial port device. If the parameters of the USB serial port device are not set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the related parameters.| 
| int32_t [OH_UsbSerial_SetTimeout](#oh_usbserial_settimeout) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, int timeout) | Sets the timeout interval (ms) for reading data reported by a USB serial port device. If this function is not called, the timeout value is **0** by default, indicating that data is returned immediately regardless of whether data is read. If you need to wait for a certain period of time or data must be read, call this API to set the timeout interval.| 
| int32_t [OH_UsbSerial_SetFlowControl](#oh_usbserial_setflowcontrol) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, [UsbSerial_FlowControl](#usbserial_flowcontrol) flowControl) | Sets flow control parameters. Flow control is used to manage the data transfer rate during communication with the USB serial port device to ensure that the sender does not send data that exceeds the processing capability of the receiver.<br>If flow control is required, call this API to set flow control parameters. If this API is not called, flow control is not performed by default.| 
| int32_t [OH_UsbSerial_Flush](#oh_usbserial_flush) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | Clears the input and output buffers after the write operation is complete. If a large amount of data is to be transmitted to the USB serial port device, the data may be buffered in the kernel for transmission. If the application closes the file descriptor or exits before the data is completely sent out, some data may be lost.<br> You can call this API to ensure that all data is sent before subsequent operations are performed.| 
| int32_t [OH_UsbSerial_FlushInput](#oh_usbserial_flushinput) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | Refreshes the input buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br>You can call this API to clear these exceptions to restore the communication.| 
| int32_t [OH_UsbSerial_FlushOutput](#oh_usbserial_flushoutput) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | Refreshes the output buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br>You can call this API to clear these exceptions to restore the communication.| 


## Type Description


### UsbSerial_DeviceHandle

```
typedef struct UsbSerial_DeviceHandleUsbSerial_DeviceHandle
```

**Description**

Defines the data structures for the USB serial port device (opaque).

**Since**: 16


### UsbSerial_Params

```
typedef struct UsbSerial_Params __attribute__((aligned(8))) UsbSerial_Params
```

**Description**

Defines the USB serial port parameters for the USB Serial DDK.

**Since**: 16


## Enum Description


### UsbSerial_DdkRetCode

```
enum UsbSerial_DdkRetCode
```

**Description**

Defines the return codes used by the USB Serial DDK.

**Since**: 16

| Value| Description| 
| -------- | -------- |
| USB_SERIAL_DDK_NO_PERM | No access permission.| 
| USB_SERIAL_DDK_INVALID_PARAMETER | Invalid parameter.| 
| USB_SERIAL_DDK_SUCCESS | Operation succeeded.| 
| USB_SERIAL_DDK_INVALID_OPERATION | Invalid operation.| 
| USB_SERIAL_DDK_INIT_ERROR | Initialization error.| 
| USB_SERIAL_DDK_SERVICE_ERROR | Service error.| 
| USB_SERIAL_DDK_MEMORY_ERROR | Memory-related errors, such as insufficient memory, memory data replication failure, or memory application fault.| 
| USB_SERIAL_DDK_IO_ERROR | I/O error.| 
| USB_SERIAL_DDK_DEVICE_NOT_FOUND | Device not found.| 


### UsbSerial_FlowControl

```
enum UsbSerial_FlowControl
```

**Description**

Defines the flow control mode for the USB Serial DDK.

**Since**: 16

| Value| Description| 
| -------- | -------- |
| USB_SERIAL_NO_FLOW_CONTROL | No flow control.| 
| USB_SERIAL_SOFTWARE_FLOW_CONTROL | Software flow control.| 
| USB_SERIAL_HARDWARE_FLOW_CONTROL | Hardware flow control.| 


### UsbSerial_Parity

```
enum UsbSerial_Parity
```

**Description**

Defines the enums of the parity parameter used by the USB Serial DDK.

**Since**: 16

| Value| Description| 
| -------- | -------- |
| USB_SERIAL_PARITY_NONE | No parity.| 
| USB_SERIAL_PARITY_ODD | Odd parity.| 
| USB_SERIAL_PARITY_EVEN | Even parity.| 


## Function Description


### OH_UsbSerial_Close()

```
int32_t OH_UsbSerial_Close (UsbSerial_DeviceHandle * dev)
```

**Description**

Disables the USB serial port device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible cause: The input **dev** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_Flush()

```
int32_t OH_UsbSerial_Flush (UsbSerial_DeviceHandle * dev)
```

**Description**

Clears the input and output buffers after the write operation is complete.

If a large amount of data is to be transmitted to the USB serial port device, the data may be buffered in the kernel for transmission. If the application closes the file descriptor or exits before the data is completely sent out, some data may be lost. You can call this API to ensure that all data is sent before subsequent operations are performed.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible cause: The input **dev** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_FlushInput()

```
int32_t OH_UsbSerial_FlushInput (UsbSerial_DeviceHandle * dev)
```

**Description**

Refreshes the input buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.

You can call this API to clear these exceptions to restore the communication.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible cause: The input **dev** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_FlushOutput()

```
int32_t OH_UsbSerial_FlushOutput (UsbSerial_DeviceHandle * dev)
```

**Description**

Refreshes the output buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.

You can call this API to clear these exceptions to restore the communication.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible cause: The input **dev** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_Init()

```
int32_t OH_UsbSerial_Init (void )
```

**Description**

Initializes the USB Serial DDK.

**Since**: 16

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.


### OH_UsbSerial_Open()

```
int32_t OH_UsbSerial_Open (uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_DeviceHandle ** dev )
```

**Description**

Enables the USB serial port device based on the specified **deviceId** and **interfaceIndex**.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | Device ID.| 
| interfaceIndex | Interface index, which corresponds to **bInterfaceNumber** in the USB protocol.| 
| dev | Device handle.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible cause: The input **dev** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_MEMORY_ERROR: Insufficient memory.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_DEVICE_NOT_FOUND: Device or interface not found.


### OH_UsbSerial_Read()

```
int32_t OH_UsbSerial_Read (UsbSerial_DeviceHandle * dev, uint8_t * buff, uint32_t bufferSize, uint32_t * bytesRead )
```

**Description**

Reads data from the USB serial port device to the buffer.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 
| buff | Buffer for storing the data read from the USB serial port device.| 
| bufferSize | Buffer size.| 
| bytesRead | Number of bytes that are actually read. If the block mode is set, the number of bytes that are actually read is returned only when it is equal to the value of **bufferSize**.<br>For details, see [OH_UsbSerial_SetTimeout](#oh_usbserial_settimeout).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is a null pointer. 2. **buff** is a null pointer. 3. **bufferSize** is **0**. 4. **bytesRead** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_MEMORY_ERROR: Invalid buffer address.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_Release()

```
int32_t OH_UsbSerial_Release (void )
```

**Description**

Releases the USB Serial DDK.

**Since**: 16

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.


### OH_UsbSerial_SetBaudRate()

```
int32_t OH_UsbSerial_SetBaudRate (UsbSerial_DeviceHandle * dev, uint32_t baudRate )
```

**Description**

Sets the baud rate for a USB serial port device. If the parameters of the USB serial port device are set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the baud rate.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 
| baudRate | Baud rate of the USB serial port device.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible cause: The input **dev** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_SetFlowControl()

```
int32_t OH_UsbSerial_SetFlowControl (UsbSerial_DeviceHandle * dev, UsbSerial_FlowControl flowControl )
```

**Description**

Sets flow control parameters. Flow control is used to manage the data transfer rate during communication with the USB serial port device to ensure that the sender does not send data that exceeds the processing capability of the receiver.

If flow control is required, call this API to set flow control parameters. If this API is not called, flow control is not performed by default.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 
| flowControl | Flow control mode. For details, see [UsbSerial_FlowControl](#usbserial_flowcontrol).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible cause: The input **dev** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_SetParams()

```
int32_t OH_UsbSerial_SetParams (UsbSerial_DeviceHandle * dev, UsbSerial_Params * params )
```

**Description**

Sets the parameters of the USB serial port device. If the parameters of the USB serial port device are not set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the related parameters.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 
| params | USB serial port device parameters. For details, see [UsbSerial_Params](_usb_serial___params.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is a null pointer. 2. **params** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_SetTimeout()

```
int32_t OH_UsbSerial_SetTimeout (UsbSerial_DeviceHandle * dev, int timeout )
```

**Description**

Sets the timeout interval (ms) for reading data reported by a USB serial port device.

If this function is not called, the timeout value is **0** by default, indicating that data is returned immediately regardless of whether data is read. If you need to wait for a certain period of time or data must be read, call this API to set the timeout interval.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 
| timeout | Timeout interval for reading data from a USB serial port device. The value range is as follows:<br>- (0, 25500]: time value in milliseconds. The value is rounded off to the nearest 100 milliseconds as the actual timeout interval. For example, if the value is set to **12321**, the effective timeout interval is **12300**.<br>- **0**: Data is returned immediately.<br>- **-1**: Data is read in block mode. That is, data is returned only after data of the specified length is read. For details, see [OH_UsbSerial_Read](#oh_usbserial_read).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is a null pointer. 2. **timeout** is less than **-1** or greater than **25500**.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.


### OH_UsbSerial_Write()

```
int32_t OH_UsbSerial_Write (UsbSerial_DeviceHandle * dev, uint8_t * buff, uint32_t bufferSize, uint32_t * bytesWritten )
```

**Description**

Writes the data in the buffer to the USB serial port device.

**Since**: 16

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle.| 
| buff | Buffer to which the data of the USB serial port device is written.| 
| bufferSize | Buffer size.| 
| bytesWritten | Number of bytes that are actually written.| 

**Required Permissions**

ohos.permission.ACCESS_DDK_USB_SERIAL

**Returns**

- USB_SERIAL_DDK_SUCCESS: Operation succeeded.

- USB_SERIAL_DDK_NO_PERM: Permission verification failed.

- USB_SERIAL_DDK_INVALID_PARAMETER: Parameter verification failed. Possible causes: 1. **dev** is a null pointer. 2. **buff** is a null pointer. 3. **bufferSize** is **0**. 4. **bytesWritten** is a null pointer.

- USB_SERIAL_DDK_INIT_ERROR: DDK initialization error.

- USB_SERIAL_DDK_SERVICE_ERROR: DDK service communication error.

- USB_SERIAL_DDK_MEMORY_ERROR: Invalid buffer address.

- USB_SERIAL_DDK_IO_ERROR: DDK I/O error.

- USB_SERIAL_DDK_INVALID_OPERATION: Invalid operation.
