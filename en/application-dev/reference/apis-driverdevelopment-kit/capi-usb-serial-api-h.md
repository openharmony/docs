# usb_serial_api.h

## Overview

Declares the USB Serial DDK APIs used by the host to access the serial port device.

**File to include**: <usb_serial/usb_serial_api.h>

**Library**: libusb_serial.z.so

**System capability**: SystemCapability.Driver.UsbSerial.Extension

**Since**: 18

**Related module**: [SerialDdk](capi-serialddk.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_UsbSerial_Init(void)](#oh_usbserial_init) | Initializes the USB Serial DDK.|
| [int32_t OH_UsbSerial_Release(void)](#oh_usbserial_release) | Releases the USB Serial DDK.|
| [int32_t OH_UsbSerial_Open(uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_DeviceHandle **dev)](#oh_usbserial_open) | Enables the USB serial port device based on the specified **deviceId** and **interfaceIndex**.|
| [int32_t OH_UsbSerial_Close(UsbSerial_DeviceHandle *dev)](#oh_usbserial_close) | Disables the USB serial port device.|
| [int32_t OH_UsbSerial_Read(UsbSerial_DeviceHandle *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesRead)](#oh_usbserial_read) | Reads data from the USB serial port device to the buffer.|
| [int32_t OH_UsbSerial_Write(UsbSerial_DeviceHandle *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesWritten)](#oh_usbserial_write) | Writes the data in the buffer to the USB serial port device.|
| [int32_t OH_UsbSerial_SetBaudRate(UsbSerial_DeviceHandle *dev, uint32_t baudRate)](#oh_usbserial_setbaudrate) | Sets the baud rate for a USB serial port device. If the parameters of the USB serial port device are set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the baud rate.|
| [int32_t OH_UsbSerial_SetParams(UsbSerial_DeviceHandle *dev, UsbSerial_Params *params)](#oh_usbserial_setparams) | Sets the parameters of the USB serial port device. If the parameters of the USB serial port device are not set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the related parameters.|
| [int32_t OH_UsbSerial_SetTimeout(UsbSerial_DeviceHandle *dev, int timeout)](#oh_usbserial_settimeout) | Sets the timeout interval (ms) for reading data reported by a USB serial port device. If this function is not called, the timeout value is **0** by default, indicating that data is returned immediately regardless of whether data is read. If you need to wait for a certain period of time or data must be read, call this API to set the timeout interval.|
| [int32_t OH_UsbSerial_SetFlowControl(UsbSerial_DeviceHandle *dev, UsbSerial_FlowControl flowControl)](#oh_usbserial_setflowcontrol) | Sets flow control parameters. Flow control is used to manage the data transfer rate during communication with the USB serial port device to ensure that the sender does not send data that exceeds the processing capability of the receiver.<br> If flow control is required, call this API to set flow control parameters. If this API is not called, flow control is not performed by default.|
| [int32_t OH_UsbSerial_Flush(UsbSerial_DeviceHandle *dev)](#oh_usbserial_flush) | Clears the input and output buffers after the write operation is complete. If a large amount of data is to be transmitted to the USB serial port device, the data may be buffered in the kernel for transmission. If the application closes the file descriptor or exits before the data is completely sent out, some data may be lost.<br> If the data is not sent out, some data may be lost. You can call this API to ensure that all data is sent before subsequent operations are performed.|
| [int32_t OH_UsbSerial_FlushInput(UsbSerial_DeviceHandle *dev)](#oh_usbserial_flushinput) | Refreshes the input buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br> You can call this API to clear these exceptions to restore the communication.|
| [int32_t OH_UsbSerial_FlushOutput(UsbSerial_DeviceHandle *dev)](#oh_usbserial_flushoutput) | Refreshes the output buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br> You can call this API to clear these exceptions to restore the communication.|

## Function Description

### OH_UsbSerial_Init()

```
int32_t OH_UsbSerial_Init(void)
```

**Description**

Initializes the USB Serial DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18

**Returns**

| Type| Description                                                                                                                                                                                                                               |
| -- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.|

### OH_UsbSerial_Release()

```
int32_t OH_UsbSerial_Release(void)
```

**Description**

Releases the USB Serial DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.|

### OH_UsbSerial_Open()

```
int32_t OH_UsbSerial_Open(uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_DeviceHandle **dev)
```

**Description**

Enables the USB serial port device based on the specified **deviceId** and **interfaceIndex**.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name                             | Description                                        |
|----------------------------------|--------------------------------------------|
| uint64_t deviceId                | Device ID.                            |
| uint8_t interfaceIndex           | Interface index, which corresponds to [bInterfaceNumber](capi-usbddk-usbinterfacedescriptor.md) in the USB protocol.|
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) **dev | Device handle.                                     |

**Returns**

| Type| Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| -- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible cause: The input **dev** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_MEMORY_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The memory is insufficient.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_DEVICE_NOT_FOUND](capi-usb-serial-types-h.md#usbserial_ddkretcode): The device or interface is not found.|

### OH_UsbSerial_Close()

```
int32_t OH_UsbSerial_Close(UsbSerial_DeviceHandle *dev)
```

**Description**

Disables the USB serial port device.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|

**Returns**

| Type| Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| -- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible cause: The input **dev** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_Read()

```
int32_t OH_UsbSerial_Read(UsbSerial_DeviceHandle *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesRead)
```

**Description**

Reads data from the USB serial port device to the buffer.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|
| uint8_t *buff | Buffer for storing the data read from the USB serial port device.|
| uint32_t bufferSize | Buffer size.|
| uint32_t *bytesRead | Number of bytes that are actually read. If the block mode is set, the number of bytes that are actually read is returned only when it is equal to the value of **bufferSize**.<br>                  For details, see [OH_UsbSerial_SetTimeout](capi-usb-serial-api-h.md#oh_usbserial_settimeout).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible causes: 1. **dev** is a null pointer.<br>         2. **buff** is a null pointer. 3. **bufferSize** is **0**. 4. **bytesRead** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_MEMORY_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The buffer address is invalid.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_Write()

```
int32_t OH_UsbSerial_Write(UsbSerial_DeviceHandle *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesWritten)
```

**Description**

Writes the data in the buffer to the USB serial port device.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|
| uint8_t *buff | Buffer to which the data of the USB serial port device is written.|
| uint32_t bufferSize | Buffer size.|
| uint32_t *bytesWritten | Number of bytes that are actually written.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible causes: 1. **dev** is a null pointer.<br>         2. **buff** is a null pointer. 3. **bufferSize** is **0**. 4. **bytesWritten** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_MEMORY_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The buffer address is invalid.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_SetBaudRate()

```
int32_t OH_UsbSerial_SetBaudRate(UsbSerial_DeviceHandle *dev, uint32_t baudRate)
```

**Description**

Sets the baud rate for a USB serial port device. If the parameters of the USB serial port device are set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the baud rate.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|
| uint32_t baudRate | Baud rate of the USB serial port device.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible cause: The input **dev** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_SetParams()

```
int32_t OH_UsbSerial_SetParams(UsbSerial_DeviceHandle *dev, UsbSerial_Params *params)
```

**Description**

Sets the parameters of the USB serial port device. If the parameters of the USB serial port device are not set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the related parameters.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name                                                                    | Description|
|-------------------------------------------------------------------------| -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|
| [UsbSerial_Params](capi-serialddk-usbserial-params.md) *params                                            | USB serial port device parameters. For details, see [UsbSerial_Params](capi-serialddk-usbserial-params.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible causes: 1. **dev** is a null pointer.<br>         2. **params** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_SetTimeout()

```
int32_t OH_UsbSerial_SetTimeout(UsbSerial_DeviceHandle *dev, int timeout)
```

**Description**

Sets the timeout interval (ms) for reading data reported by a USB serial port device. If this function is not called, the timeout value is **0** by default, indicating that data is returned immediately regardless of whether data is read. If you need to wait for a certain period of time or data must be read, call this API to set the timeout interval.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|
| int timeout | Timeout interval for reading data from a USB serial port device, in milliseconds. The value range is - (0, 25500]. The value is rounded off to the nearest 100 milliseconds as the actual timeout interval. For example, if the value is set to **12321**, the effective timeout interval is **12300**. - **0**: Data is returned immediately. - **-1**: Data is read in block mode. That is, data is returned only after data of the specified length is read. For details, see [OH_UsbSerial_Read](capi-usb-serial-api-h.md#oh_usbserial_read).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible causes: 1. **dev** is a null pointer.<br>         2. timeout < -1 or timeout > 25500.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_SetFlowControl()

```
int32_t OH_UsbSerial_SetFlowControl(UsbSerial_DeviceHandle *dev, UsbSerial_FlowControl flowControl)
```

**Description**

Sets flow control parameters. Flow control is used to manage the data transfer rate during communication with the USB serial port device to ensure that the sender does not send data that exceeds the processing capability of the receiver.<br> If flow control is required, call this API to set flow control parameters. If this API is not called, flow control is not performed by default.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name                                                                                  | Description|
|---------------------------------------------------------------------------------------| -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev               | Device handle.|
| [UsbSerial_FlowControl](capi-usb-serial-types-h.md#usbserial_flowcontrol) flowControl | Flow control mode. For details, see [UsbSerial_FlowControl](capi-usb-serial-types-h.md#usbserial_flowcontrol).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible cause: The input **dev** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_Flush()

```
int32_t OH_UsbSerial_Flush(UsbSerial_DeviceHandle *dev)
```

**Description**

Clears the input and output buffers after the write operation is complete. If a large amount of data is to be transmitted to the USB serial port device, the data may be buffered in the kernel for transmission. If the application closes the file descriptor or exits before the data is completely sent out, some data may be lost.<br> If the data is not sent out, some data may be lost. You can call this API to ensure that all data is sent before subsequent operations are performed.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible cause: The input **dev** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_FlushInput()

```
int32_t OH_UsbSerial_FlushInput(UsbSerial_DeviceHandle *dev)
```

**Description**

Refreshes the input buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br> You can call this API to clear these exceptions to restore the communication.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible cause: The input **dev** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|

### OH_UsbSerial_FlushOutput()

```
int32_t OH_UsbSerial_FlushOutput(UsbSerial_DeviceHandle *dev)
```

**Description**

Refreshes the output buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br> You can call this API to clear these exceptions to restore the communication.

**Required permissions**: ohos.permission.ACCESS_DDK_USB_SERIAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) *dev | Device handle.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is successful.<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode): The permission verification fails.<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode): The parameter verification fails. Possible cause: The input **dev** is a null pointer.<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK initialization fails.<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): The DDK service communication fails.<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode): An I/O exception occurs.<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode): The operation is invalid.|
