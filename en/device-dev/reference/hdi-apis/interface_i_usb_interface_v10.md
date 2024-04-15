# IUsbInterface


## Overview

Provides APIs to implement basic operations of the USB driver module.

The USB service can call related APIs to enable or disable a device, obtain a device descriptor, and read or write data in bulk mode.

**Since**: 3.2

**Related module**: [USB](_u_s_b_v10.md)


## Summary


### Public Member Functions

| Name| Description| 
| -------- | -------- |
| [OpenDevice](#opendevice) ([in] struct [UsbDev](_usb_dev_v10.md) dev) | Opens a USB device to set up a connection. | 
| [CloseDevice](#closedevice) ([in] struct [UsbDev](_usb_dev_v10.md) dev) | Closes a USB device to release all system resources related to the device. | 
| [GetDeviceDescriptor](#getdevicedescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char[] descriptor) | Obtains the device descriptor of a USB device. The device descriptor provides information about the device, device configuration, and device class. | 
| [GetStringDescriptor](#getstringdescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char descId, [out] unsigned char[] descriptor) | Obtains the string descriptor of a USB device based on the specified string ID. The string descriptor provides information about a device interface, such as the vendor name and product SN. | 
| [GetConfigDescriptor](#getconfigdescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char descId, [out] unsigned char[] descriptor) | Obtains the configuration descriptor of a USB device based on the specified configuration ID. The configuration descriptor provides information about the device configuration and interfaces, alternate settings, and endpoints. | 
| [GetRawDescriptor](#getrawdescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char[] descriptor) | Obtains the raw descriptor of a USB device. | 
| [GetFileDescriptor](#getfiledescriptor) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] int fd) | Obtains the file descriptor of a USB device. | 
| [SetConfig](#setconfig) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char configIndex) | Sets the configuration for a USB device. After a USB device is configured by the host, the host can use all functions provided by the device. | 
| [GetConfig](#getconfig) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char configIndex) | Obtains the configuration of a USB device. | 
| [ClaimInterface](#claiminterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [in] unsigned char force) | Claims a USB interface exclusively. This must be done before data transfer. | 
| [ReleaseInterface](#releaseinterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid) | Releases a USB interface and the resources in use. This is usually done after data transfer. | 
| [ManageInterface](#manageinterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [in] bool disable) | Enables or disables a USB interface. | 
| [SetInterface](#setinterface) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [in] unsigned char altIndex) | Sets the alternate settings for a USB interface. This allows you to switch between two interfaces with the same ID but different alternate settings. | 
| [BulkTransferRead](#bulktransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [out] unsigned char[] data) | Reads data through bulk transfer when a USB endpoint is in the data reading direction. | 
| [BulkTransferWrite](#bulktransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [in] unsigned char[] data) | Writes data through bulk transfer when a USB endpoint is in the data writing direction. | 
| [ControlTransferRead](#controltransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbCtrlTransfer](_usb_ctrl_transfer_v10.md) ctrl, [out] unsigned char[] data) | Reads data through control transfer when endpoint 0 is the control endpoint and is in the data reading direction. | 
| [ControlTransferWrite](#controltransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbCtrlTransfer](_usb_ctrl_transfer_v10.md) ctrl, [in] unsigned char[] data) | Writes data through control transfer when endpoint 0 is the control endpoint and is in the data writing direction. | 
| [InterruptTransferRead](#interrupttransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [out] unsigned char[] data) | Reads data through interrupt transfer when a USB endpoint is in the data reading direction. | 
| [InterruptTransferWrite](#interrupttransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [in] unsigned char[] data) | Writes data through interrupt transfer when a USB endpoint is in the data writing direction. | 
| [IsoTransferRead](#isotransferread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [out] unsigned char[] data) | Reads data through isochronous transfer when a USB endpoint is in the data reading direction. | 
| [IsoTransferWrite](#isotransferwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] int timeout, [in] unsigned char[] data) | Writes data through isochronous transfer when a USB endpoint is in the data writing direction. | 
| [RequestQueue](#requestqueue) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] unsigned char[] clientData, [in] unsigned char[] buffer) | Sends or receives data through asynchronous transfer on a USB endpoint. The data transfer direction is determined by the endpoint direction. | 
| [RequestWait](#requestwait) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char[] clientData, [out] unsigned char[] buffer, [in] int timeout) | Waits for the operation result of an asynchronous transfer request. | 
| [RequestCancel](#requestcancel) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe) | Cancels a data transfer request. | 
| [GetCurrentFunctions](#getcurrentfunctions) ([out] int funcs) | Obtains the list of functions (represented by bit field) supported by the USB device. | 
| [SetCurrentFunctions](#setcurrentfunctions) ([in] int funcs) | Sets the list of functions (represented by bit field) supported by the USB device. | 
| [SetPortRole](#setportrole) ([in] int portId, [in] int powerRole, [in] int dataRole) | Sets the role of a USB device port. | 
| [QueryPort](#queryport) ([out] int portId, [out] int powerRole, [out] int dataRole, [out] int mode) | Queries the settings of a USB device port. | 
| [BindUsbdSubscriber](#bindusbdsubscriber) ([in] [IUsbdSubscriber](interface_i_usbd_subscriber_v10.md) subscriber) | Binds a subscriber. | 
| [UnbindUsbdSubscriber](#unbindusbdsubscriber) ([in] [IUsbdSubscriber](interface_i_usbd_subscriber_v10.md) subscriber) | Unbinds a subscriber. | 
| [RegBulkCallback](#regbulkcallback) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] [IUsbdBulkCallback](interface_i_usbd_bulk_callback_v10.md) cb) | Registers an asynchronous callback for bulk transfer. | 
| [UnRegBulkCallback](#unregbulkcallback) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe) | Unregisters the asynchronous callback for bulk transfer. | 
| [BulkRead](#bulkread) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] Ashmem ashmem) | Reads data asynchronously during bulk transfer. | 
| [BulkWrite](#bulkwrite) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe, [in] Ashmem ashmem) | Writes data asynchronously during bulk transfer. | 
| [BulkCancel](#bulkcancel) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] struct [UsbPipe](_usb_pipe_v10.md) pipe) | Cancels bulk transfer. The asynchronous read and write operations on the current USB interface will be canceled. | 


## Member Function Description


### BindUsbdSubscriber()

```
IUsbInterface::BindUsbdSubscriber ([in] IUsbdSubscriber subscriber)
```
**Description**<br>
Binds a subscriber.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| subscriber | Subscriber information. For details, see [IUsbdSubscriber](interface_i_usbd_subscriber_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### BulkCancel()

```
IUsbInterface::BulkCancel ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```
**Description**<br>
Cancels bulk transfer. The asynchronous read and write operations on the current USB interface will be canceled.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### BulkRead()

```
IUsbInterface::BulkRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem )
```
**Description**<br>
Reads data asynchronously during bulk transfer.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| ashmem | Shared memory used to store the read data.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### BulkTransferRead()

```
IUsbInterface::BulkTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```
**Description**<br>
Reads data through bulk transfer when a USB endpoint is in the data reading direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| timeout | Timeout duration. | 
| data | Data read.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### BulkTransferWrite()

```
IUsbInterface::BulkTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```
**Description**<br>
Writes data through bulk transfer when a USB endpoint is in the data writing direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| timeout | Timeout duration. | 
| data | Data to write.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### BulkWrite()

```
IUsbInterface::BulkWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] Ashmem ashmem )
```
**Description**<br>
Writes data asynchronously during bulk transfer.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| ashmem | Shared memory used to store the written data.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### ClaimInterface()

```
IUsbInterface::ClaimInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char force )
```
**Description**<br>
Claims a USB interface exclusively. This must be done before data transfer.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| interfaceid | USB interface ID. | 
| force | Whether to perform the operation forcibly. The value **1** means to perform the operation forcibly, and **0** means indicates the opposite.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### CloseDevice()

```
IUsbInterface::CloseDevice ([in] struct UsbDev dev)
```
**Description**<br>
Closes a USB device to release all system resources related to the device.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### ControlTransferRead()

```
IUsbInterface::ControlTransferRead ([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [out] unsigned char[] data )
```
**Description**<br>
Reads data through control transfer when endpoint 0 is the control endpoint and is in the data reading direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| ctrl | USB control transfer data. For details, see [UsbCtrlTransfer](_usb_ctrl_transfer_v10.md). | 
| data | Data read.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### ControlTransferWrite()

```
IUsbInterface::ControlTransferWrite ([in] struct UsbDev dev, [in] struct UsbCtrlTransfer ctrl, [in] unsigned char[] data )
```
**Description**<br>
Writes data through control transfer when endpoint 0 is the control endpoint and is in the data writing direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| ctrl | USB control transfer data. For details, see [UsbCtrlTransfer](_usb_ctrl_transfer_v10.md). | 
| data | Data to write.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### GetConfig()

```
IUsbInterface::GetConfig ([in] struct UsbDev dev, [out] unsigned char configIndex )
```
**Description**<br>
Obtains the configuration of a USB device.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| configIndex | Index (a numeric string) of the string descriptor for the USB device configuration.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### GetConfigDescriptor()

```
IUsbInterface::GetConfigDescriptor ([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor )
```
**Description**<br>
Obtains the configuration descriptor of a USB device based on the specified configuration ID. The configuration descriptor provides information about the device configuration and interfaces, alternate settings, and endpoints.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| descId | Configuration ID of the USB device. | 
| descriptor | Configuration descriptor of the USB device.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### GetCurrentFunctions()

```
IUsbInterface::GetCurrentFunctions ([out] int funcs)
```
**Description**<br>
Obtains the list of functions (represented by bit field) supported by the USB device.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| funcs | Functions of the USB device.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### GetDeviceDescriptor()

```
IUsbInterface::GetDeviceDescriptor ([in] struct UsbDev dev, [out] unsigned char[] descriptor )
```
**Description**<br>
Obtains the device descriptor of a USB device. The device descriptor provides information about the device, device configuration, and device class.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| descriptor | USB device descriptor.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### GetFileDescriptor()

```
IUsbInterface::GetFileDescriptor ([in] struct UsbDev dev, [out] int fd )
```
**Description**<br>
Obtains the file descriptor of a USB device.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| fd | File descriptor of the USB device.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### GetRawDescriptor()

```
IUsbInterface::GetRawDescriptor ([in] struct UsbDev dev, [out] unsigned char[] descriptor )
```
**Description**<br>
Obtains the raw descriptor of a USB device.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| descriptor | Raw descriptor of the USB device.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### GetStringDescriptor()

```
IUsbInterface::GetStringDescriptor ([in] struct UsbDev dev, [in] unsigned char descId, [out] unsigned char[] descriptor )
```
**Description**<br>
Obtains the string descriptor of a USB device based on the specified string ID. The string descriptor provides information about a device interface, such as the vendor name and product SN.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| descId | Descriptor ID of the USB device. | 
| descriptor | String descriptor of the USB device.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### InterruptTransferRead()

```
IUsbInterface::InterruptTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```
**Description**<br>
Reads data through interrupt transfer when a USB endpoint is in the data reading direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| timeout | Timeout duration. | 
| data | Data read.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### InterruptTransferWrite()

```
IUsbInterface::InterruptTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```
**Description**<br>
Writes data through interrupt transfer when a USB endpoint is in the data writing direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| timeout | Timeout duration. | 
| data | Data to write.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### IsoTransferRead()

```
IUsbInterface::IsoTransferRead ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [out] unsigned char[] data )
```
**Description**<br>
Reads data through isochronous transfer when a USB endpoint is in the data reading direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| timeout | Timeout duration. | 
| data | Data read.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### IsoTransferWrite()

```
IUsbInterface::IsoTransferWrite ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] int timeout, [in] unsigned char[] data )
```
**Description**<br>
Writes data through isochronous transfer when a USB endpoint is in the data writing direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| timeout | Timeout duration. | 
| data | Data to write.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### ManageInterface()

```
IUsbInterface::ManageInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] bool disable )
```
**Description**<br>
Enables or disables a USB interface.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| interfaceid | USB interface ID. | 
| disable | Whether to disable the USB interface. The value **true** means to disable the interface, and **false** means to enable it.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### OpenDevice()

```
IUsbInterface::OpenDevice ([in] struct UsbDev dev)
```
**Description**<br>
Opens a USB device to set up a connection.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### QueryPort()

```
IUsbInterface::QueryPort ([out] int portId, [out] int powerRole, [out] int dataRole, [out] int mode )
```
**Description**<br>
Queries the settings of a USB device port.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| portId | Port ID of the USB device. | 
| powerRole | Power role of the USB device. | 
| dataRole | Data role of the USB device. | 
| mode | USB device mode.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### RegBulkCallback()

```
IUsbInterface::RegBulkCallback ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] IUsbdBulkCallback cb )
```
**Description**<br>
Registers an asynchronous callback for bulk transfer.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| cb | Callback function object. For details, see [IUsbdBulkCallback](interface_i_usbd_bulk_callback_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### ReleaseInterface()

```
IUsbInterface::ReleaseInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid )
```
**Description**<br>
Releases a USB interface and the resources in use. This is usually done after data transfer.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| interfaceid | USB interface ID.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### RequestCancel()

```
IUsbInterface::RequestCancel ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```
**Description**<br>
Cancels a data transfer request.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### RequestQueue()

```
IUsbInterface::RequestQueue ([in] struct UsbDev dev, [in] struct UsbPipe pipe, [in] unsigned char[] clientData, [in] unsigned char[] buffer )
```
**Description**<br>
Sends or receives data through asynchronous transfer on a USB endpoint. The data transfer direction is determined by the endpoint direction.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md). | 
| clientData | Client data. | 
| buffer | Data to transfer.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### RequestWait()

```
IUsbInterface::RequestWait ([in] struct UsbDev dev, [out] unsigned char[] clientData, [out] unsigned char[] buffer, [in] int timeout )
```
**Description**<br>
Waits for the operation result of an asynchronous transfer request.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| clientData | Client data. | 
| buffer | Data to transfer. | 
| timeout | Timeout duration.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### SetConfig()

```
IUsbInterface::SetConfig ([in] struct UsbDev dev, [in] unsigned char configIndex )
```
**Description**<br>
Sets the configuration for a USB device. After a USB device is configured by the host, the host can use all functions provided by the device.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| configIndex | Index (a numeric string) of the string descriptor for the USB device configuration.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### SetCurrentFunctions()

```
IUsbInterface::SetCurrentFunctions ([in] int funcs)
```
**Description**<br>
Sets the list of functions (represented by bit field) supported by the USB device.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| funcs | List of functions supported by the USB device.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### SetInterface()

```
IUsbInterface::SetInterface ([in] struct UsbDev dev, [in] unsigned char interfaceid, [in] unsigned char altIndex )
```
**Description**<br>
Sets the alternate settings for a USB interface. This allows you to switch between two interfaces with the same ID but different alternate settings.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| interfaceid | USB interface ID. | 
| altIndex | Alternate settings of the USB interface.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### SetPortRole()

```
IUsbInterface::SetPortRole ([in] int portId, [in] int powerRole, [in] int dataRole )
```
**Description**<br>
Sets the role of a USB device port.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| portId | Port ID of the USB device. | 
| powerRole | Power role. | 
| dataRole | Data role.| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### UnbindUsbdSubscriber()

```
IUsbInterface::UnbindUsbdSubscriber ([in] IUsbdSubscriber subscriber)
```
**Description**<br>
Unbinds a subscriber.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| subscriber | Subscriber information. For details, see [IUsbdSubscriber](interface_i_usbd_subscriber_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.


### UnRegBulkCallback()

```
IUsbInterface::UnRegBulkCallback ([in] struct UsbDev dev, [in] struct UsbPipe pipe )
```
**Description**<br>
Unregisters the asynchronous callback for bulk transfer.

**Since**: 3.2

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| pipe | USB pipe information. For details, see [UsbPipe](_usb_pipe_v10.md).| 

**Returns**

**0**: The operation is successful.

Other values: The operation fails.
