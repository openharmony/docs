# usb_serial_ddk_api.h


## Overview

Declares the USB Serial DDK APIs used by the host to access the serial port device.

**Library**: libusb_serial.z.so

**File to include**: &lt;[serial/usb_serial_ddk_api.h](zh-cn_topic_0000002155321226.xml)&gt;

**System capability**: SystemCapability.Driver.SERIAL.Extension

**Since**: 16

**Related module**: [Serial DDK](_serial_ddk.md)


## Summary


### Function

| Name| Description| 
| -------- | -------- |
| int32_t [OH_UsbSerial_Init](_serial_ddk.md#oh_usbserial_init) (void) | Initializes the USB Serial DDK.| 
| int32_t [OH_UsbSerial_Release](_serial_ddk.md#oh_usbserial_release) (void) | Releases the USB Serial DDK.| 
| int32_t [OH_UsbSerial_Open](_serial_ddk.md#oh_usbserial_open) (uint64_t deviceId, uint8_t interfaceIndex, [UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*\*dev) | Enables the USB serial port device based on the specified **deviceId** and **interfaceIndex**.| 
| int32_t [OH_UsbSerial_Close](_serial_ddk.md#oh_usbserial_close) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | Disables the USB serial port device.| 
| int32_t [OH_UsbSerial_Read](_serial_ddk.md#oh_usbserial_read) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesRead) | Reads data from the USB serial port device to the buffer.| 
| int32_t [OH_UsbSerial_Write](_serial_ddk.md#oh_usbserial_write) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesWritten) | Writes the data in the buffer to the USB serial port device.| 
| int32_t [OH_UsbSerial_SetBaudRate](_serial_ddk.md#oh_usbserial_setbaudrate) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, uint32_t [baudRate](usb__serial__ddk__types_8h.md#baudrate)) | Sets the baud rate for a USB serial port device. If the parameters of the USB serial port device are set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the baud rate.| 
| int32_t [OH_UsbSerial_SetParams](_serial_ddk.md#oh_usbserial_setparams) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, [UsbSerial_Params](_usb_serial___params.md) \*params) | Sets the parameters of the USB serial port device. If the parameters of the USB serial port device are not set to the default values (the data bit is **8**, the stop bit is **1**, and parity is disabled for data transfer), you only need to call this API to set the related parameters.| 
| int32_t [OH_UsbSerial_SetTimeout](_serial_ddk.md#oh_usbserial_settimeout) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, int timeout) | Sets the timeout interval (ms) for reading data reported by a USB serial port device. If this function is not called, the timeout value is **0** by default, indicating that data is returned immediately regardless of whether data is read. If you need to wait for a certain period of time or data must be read, call this API to set the timeout interval.| 
| int32_t [OH_UsbSerial_SetFlowControl](_serial_ddk.md#oh_usbserial_setflowcontrol) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, [UsbSerial_FlowControl](_serial_ddk.md#usbserial_flowcontrol) flowControl) | Sets flow control parameters. Flow control is used to manage the data transfer rate during communication with the USB serial port device to ensure that the sender does not send data that exceeds the processing capability of the receiver.<br>If flow control is required, call this API to set flow control parameters. If this API is not called, flow control is not performed by default.| 
| int32_t [OH_UsbSerial_Flush](_serial_ddk.md#oh_usbserial_flush) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | Clears the input and output buffers after the write operation is complete. If a large amount of data is to be transmitted to the USB serial port device, the data may be buffered in the kernel for transmission. If the application closes the file descriptor or exits before the data is completely sent out, some data may be lost.<br> You can call this API to ensure that all data is sent before subsequent operations are performed.| 
| int32_t [OH_UsbSerial_FlushInput](_serial_ddk.md#oh_usbserial_flushinput) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | Refreshes the input buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br>You can call this API to clear these exceptions to restore the communication.| 
| int32_t [OH_UsbSerial_FlushOutput](_serial_ddk.md#oh_usbserial_flushoutput) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | Refreshes the output buffer. The data in the buffer is cleared immediately. During the communication with the USB serial port device, especially in the debugging phase, disordered data packets or other exceptions may occur.<br>You can call this API to clear these exceptions to restore the communication.| 
