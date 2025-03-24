# usb_ddk_types.h


## Overview

Provides the enumerated variables, structures, and macros used in USB DDK APIs.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [UsbControlRequestSetup](_usb_control_request_setup.md) | Setup data for control transfer, corresponding to **Setup Data** in the USB protocol.|
| [UsbDeviceDescriptor](_usb_device_descriptor.md) | Standard device descriptor, corresponding to **Standard Device Descriptor** in the USB protocol.|
| [UsbConfigDescriptor](_usb_config_descriptor.md) | Standard configuration descriptor, corresponding to **Standard Configuration Descriptor** in the USB protocol.|
| [UsbInterfaceDescriptor](_usb_interface_descriptor.md) | Standard interface descriptor, corresponding to **Standard Interface Descriptor** in the USB protocol.|
| [UsbEndpointDescriptor](_usb_endpoint_descriptor.md) | Standard endpoint descriptor, corresponding to **Standard Endpoint Descriptor** in the USB protocol.|
| [UsbDdkEndpointDescriptor](_usb_ddk_endpoint_descriptor.md) | Endpoint descriptor.|
| [UsbDdkInterfaceDescriptor](_usb_ddk_interface_descriptor.md) | Interface descriptor.|
| [UsbDdkInterface](_usb_ddk_interface.md) | USB DDK interface, which is a collection of alternate settings for a particular USB interface.|
| [UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md) | Configuration descriptor.|
| [UsbRequestPipe](_usb_request_pipe.md) | Request pipe.|
| [UsbDeviceMemMap](_usb_device_mem_map.md) | Device memory map created by calling [OH_Usb_CreateDeviceMemMap()](_usb_ddk.md#oh_usb_createdevicememmap). A buffer using the device memory map can provide better performance.|
| [Usb_DeviceArray](_usb_device_array.md) | Defines the device ID list, which is used to store the device IDs and device quantity obtained using [OH_Usb_GetDevices()](_usb_ddk.md#oh_usb_getdevices16).|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [UsbDdkEndpointDescriptor](_usb_ddk_endpoint_descriptor.md) [UsbDdkEndpointDescriptor](_usb_ddk.md#usbddkendpointdescriptor) | Endpoint descriptor.|
| typedef struct [UsbDdkInterfaceDescriptor](_usb_ddk_interface_descriptor.md) [UsbDdkInterfaceDescriptor](_usb_ddk.md#usbddkinterfacedescriptor) | Interface descriptor.|
| typedef struct [UsbDdkInterface](_usb_ddk_interface.md) [UsbDdkInterface](_usb_ddk.md#usbddkinterface) | USB interface.|
| typedef struct [UsbDdkConfigDescriptor](_usb_ddk_config_descriptor.md) [UsbDdkConfigDescriptor](_usb_ddk.md#usbddkconfigdescriptor) | Configuration descriptor.|
| typedef struct [UsbDeviceMemMap](_usb_device_mem_map.md) [UsbDeviceMemMap](_usb_ddk.md#usbdevicememmap) | Device memory map created by calling [OH_Usb_CreateDeviceMemMap()](_usb_ddk.md#oh_usb_createdevicememmap). A buffer using the device memory map can provide better performance.|
| typedef struct [Usb_DeviceArray](_usb_device_array.md) [Usb_DeviceArray](_usb_ddk.md#usb_devicearray) | Defines the device ID list, which is used to store the device IDs and device quantity obtained using [OH_Usb_GetDevices()](_usb_ddk.md#oh_usb_getdevices16).|

### Enums

| Name| Description|
| -------- | -------- |
| [UsbDdkErrCode](_usb_ddk.md#usbddkerrcode)&nbsp;{<br>USB_DDK_SUCCESS&nbsp;=&nbsp;0,&nbsp;USB_DDK_FAILED&nbsp;=&nbsp;-1,&nbsp;USB_DDK_INVALID_PARAMETER&nbsp;=&nbsp;-2,&nbsp;USB_DDK_MEMORY_ERROR&nbsp;=&nbsp;-3,<br>USB_DDK_INVALID_OPERATION&nbsp;=&nbsp;-4,&nbsp;USB_DDK_NULL_PTR&nbsp;=&nbsp;-5,&nbsp;USB_DDK_DEVICE_BUSY&nbsp;=&nbsp;-6,&nbsp;USB_DDK_TIMEOUT&nbsp;=&nbsp;-7<br>} | USB DDK error code definition.|


### Variables

| Name| Description|
| -------- | -------- |
| [bmRequestType](#bmrequesttype) | Request type.|
| [bRequest](#brequest) | Specific request.|
| [wValue](#wvalue) | Value corresponding to **wValue** in the USB protocol. Its meaning varies according to the request.|
| [wIndex](#windex) | Index corresponding to **wIndex** in the USB protocol. It is usually used to transfer the index or offset. Its meaning varies according to the request. |
| [wLength](#wlength) | Data length corresponding to **wLength** in the USB protocol. If data is transferred, this field indicates the number of transferred bytes.|
| [bLength](#blength) | Size of the descriptor, in bytes.|
| [bDescriptorType](#bdescriptortype) | Descriptor type.|
| [bcdUSB](#bcdusb) | USB protocol release number.|
| [bDeviceClass](#bdeviceclass) | Interface class code allocated by the USB-IF.|
| [bDeviceSubClass](#bdevicesubclass) | Device subclass code allocated by USB-IF. The value is limited by that of bDeviceClass.|
| [bDeviceProtocol](#bdeviceprotocol) | Protocol code allocated by USB-IF. The value is limited by that of [bDeviceClass](#bdeviceclass) and [bDeviceSubClass](#bdevicesubclass).|
| [bMaxPacketSize0](#bmaxpacketsize0) | Maximum packet size of endpoint 0. Only values 8, 16, 32, and 64 are valid.|
| [idVendor](#idvendor) | Vendor ID allocated by USB-IF.|
| [idProduct](#idproduct) | Product ID allocated by the vendor.|
| [bcdDevice](#bcddevice) | Device release number.|
| [iManufacturer](#imanufacturer) | Index of the string descriptor that describes the vendor.|
| [iProduct](#iproduct) | Index of the string descriptor that describes the product.|
| [iSerialNumber](#iserialnumber) | Index of the string descriptor that describes the device SN.|
| [bNumConfigurations](#bnumconfigurations) | Configuration quantity.|
| [wTotalLength](#wtotallength) | Total length of the configuration descriptor, including the configuration, interface, endpoint, and class- or vendor-specific descriptors.|
| [bNumInterfaces](#bnuminterfaces) | Number of interfaces supported by the configuration.|
| [bConfigurationValue](#bconfigurationvalue) | Configuration index, which is used to select the configuration.|
| [iConfiguration](#iconfiguration) | Index of the string descriptor that describes the configuration.|
| [bmAttributes](#bmattributes) | Configuration attributes, including the power mode and remote wakeup.|
| [bMaxPower](#bmaxpower) | Maximum power consumption of the bus-powered USB device, in 2 mA.|
| [bInterfaceNumber](#binterfacenumber) | Interface ID.|
| [bAlternateSetting](#balternatesetting) | Value used to select the alternate setting of the interface.|
| [bNumEndpoints](#bnumendpoints) | Number of endpoints (excluding endpoint 0) used by the interface.|
| [bInterfaceClass](#binterfaceclass) | Interface class code allocated by the USB-IF.|
| [bInterfaceSubClass](#binterfacesubclass) | Device subclass code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass).|
| [bInterfaceProtocol](#binterfaceprotocol) | Protocol code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass) and [bInterfaceSubClass](#binterfacesubclass).|
| [iInterface](#iinterface) | Index of the string descriptor that describes the interface.|
| [bEndpointAddress](#bendpointaddress) | Endpoint address, including the endpoint number and endpoint direction.|
| [bmAttributes](#bmattributes) | Endpoint attributes, including the transfer type, synchronization type, and usage type.|
| [wMaxPacketSize](#wmaxpacketsize) | Maximum packet size supported by an endpoint.|
| [bInterval](#binterval) | Interval for polling endpoints for data transfer.|
| [bRefresh](#brefresh) | Refresh rate for audio devices.|
| [bSynchAddress](#bsynchaddress) | Endpoint synchronization address for audio devices.|
| [interfaceHandle](#interfacehandle) | Interface operation handle.|
| [endpoint](#endpoint) | Endpoint address.|
| [timeout](#timeout) | Timeout duration, in milliseconds.|
| [deviceIds](#deviceids) | Start address of the device ID array.|
| [num](#num) | Device quantity.|


## Variable Description


### bAlternateSetting


```
uint8_t bAlternateSetting
```

**Description**

Value used to select the alternate setting of the interface.


### bcdDevice


```
uint16_t bcdDevice
```

**Description**

Device release number.


### bcdUSB


```
uint16_t bcdUSB
```

**Description**

USB protocol release number.


### bConfigurationValue


```
uint8_t bConfigurationValue
```

**Description**

Configuration index, which is used to select the configuration.


### bDescriptorType


```
uint8_t bDescriptorType
```

**Description**

Descriptor type.


### bDeviceClass


```
uint8_t bDeviceClass
```

**Description**

Interface class code allocated by the USB-IF.


### bDeviceProtocol


```
uint8_t bDeviceProtocol
```

**Description**

Protocol code allocated by USB-IF. The value is limited by that of [bDeviceClass](#bdeviceclass) and [bDeviceSubClass](#bdevicesubclass).


### bDeviceSubClass


```
uint8_t bDeviceSubClass
```

**Description**

Device subclass code allocated by USB-IF. The value is limited by that of bDeviceClass.


### bEndpointAddress


```
uint8_t bEndpointAddress
```

**Description**

Endpoint address, including the endpoint number and endpoint direction.


### bmAttributes


```
uint8_t bmAttributes
```

**Description**

Endpoint attributes, including the transfer type, synchronization type, and usage type.


### bInterfaceClass


```
uint8_t bInterfaceClass
```

**Description**

Interface class code allocated by the USB-IF.


### bInterfaceNumber


```
uint8_t bInterfaceNumber
```

**Description**

Interface ID.


### bInterfaceProtocol


```
uint8_t bInterfaceProtocol
```

**Description**

Protocol code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass) and [bInterfaceSubClass](#binterfacesubclass).


### bInterfaceSubClass


```
uint8_t bInterfaceSubClass
```

**Description**

Device subclass code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass).


### bInterval


```
uint8_t bInterval
```

**Description**

Interval for polling endpoints for data transfer.


### bLength


```
uint8_t bLength
```

**Description**

Size of the descriptor, in bytes.


### bmAttributes


```
uint8_t bmAttributes
```

**Description**

Configuration attributes, including the power mode and remote wakeup.


### bMaxPacketSize0


```
uint8_t bMaxPacketSize0
```

**Description**

Maximum packet size of endpoint 0. Only values 8, 16, 32, and 64 are valid.


### bMaxPower


```
uint8_t bMaxPower
```

**Description**

Maximum power consumption of the bus-powered USB device, in 2 mA.


### bNumConfigurations


```
uint8_t bNumConfigurations
```

**Description**

Configuration quantity.


### bNumEndpoints


```
uint8_t bNumEndpoints
```

**Description**

Number of endpoints (excluding endpoint 0) used by the interface.


### bNumInterfaces


```
uint8_t bNumInterfaces
```

**Description**

Number of interfaces supported by the configuration.


### bRefresh


```
uint8_t bRefresh
```

**Description**

Refresh rate for audio devices.


### bSynchAddress


```
uint8_t bSynchAddress
```

**Description**

Endpoint synchronization address for audio devices.


### endpoint


```
uint8_t endpoint
```

**Description**

Endpoint address.


### iConfiguration


```
uint8_t iConfiguration
```

**Description**

Index of the string descriptor that describes the configuration.


### idProduct


```
uint16_t idProduct
```

**Description**

Product ID allocated by the vendor.


### idVendor


```
uint16_t idVendor
```

**Description**

Vendor ID allocated by USB-IF.


### iInterface


```
uint8_t iInterface
```

**Description**

Index of the string descriptor that describes the interface.


### iManufacturer


```
uint8_t iManufacturer
```

**Description**

Index of the string descriptor that describes the vendor.


### wIndex


```
uint16_t wIndex
```

**Description**

Index corresponding to **wIndex** in the USB protocol. It is usually used to transfer the index or offset. Its meaning varies according to the request. 


### interfaceHandle


```
uint64_t interfaceHandle
```

**Description**

Interface operation handle.


### iProduct


```
uint8_t iProduct
```

**Description**

Index of the string descriptor that describes the product.


### iSerialNumber


```
uint8_t iSerialNumber
```

**Description**

Index of the string descriptor that describes the device SN.


### wLength


```
uint16_t wLength
```

**Description**

Data length corresponding to **wLength** in the USB protocol. If data is transferred, this field indicates the number of transferred bytes.


### bRequest


```
uint8_t bRequest
```

**Description**

Specific request.


### bmRequestType


```
uint8_t bmRequestType
```

**Description**

Request type.


### timeout


```
uint32_t timeout
```

**Description**

Timeout duration, in milliseconds.


### wValue


```
uint16_t wValue
```

**Description**

Value corresponding to **wValue** in the USB protocol. Its meaning varies according to the request.


### wMaxPacketSize


```
uint16_t wMaxPacketSize
```

**Description**

Maximum packet size supported by an endpoint.


### wTotalLength


```
uint16_t wTotalLength
```

**Description**

Total length of the configuration descriptor, including the configuration, interface, endpoint, and class- or vendor-specific descriptors.


### deviceIds

```
uint64_t* deviceIds
```

**Description**

Defines the start address of the device ID array. The number of device IDs cannot exceed 128.
### num


```
uint32_t num
```

**Description**

Defines the device quantity. Device IDs are obtained by traversing **deviceIds** based on the value of this parameter. If the value is **0**, there is no USB device.
