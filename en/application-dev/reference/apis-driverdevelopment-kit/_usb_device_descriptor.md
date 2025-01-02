# UsbDeviceDescriptor


## Overview

Defines standard device descriptors, which correspond to **Standard Device Descriptor** in the USB protocol.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
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


## Member Variable Description


### bcdDevice


```
uint16_t UsbDeviceDescriptor::bcdDevice
```

**Description**

Device release number.


### bcdUSB


```
uint16_t UsbDeviceDescriptor::bcdUSB
```

**Description**

USB protocol release number.


### bDescriptorType


```
uint8_t UsbDeviceDescriptor::bDescriptorType
```

**Description**

Descriptor type.


### bDeviceClass


```
uint8_t UsbDeviceDescriptor::bDeviceClass
```

**Description**

Interface class code allocated by the USB-IF.


### bDeviceProtocol


```
uint8_t UsbDeviceDescriptor::bDeviceProtocol
```

**Description**

Protocol code allocated by USB-IF. The value is limited by that of [bDeviceClass](#bdeviceclass) and [bDeviceSubClass](#bdevicesubclass).


### bDeviceSubClass


```
uint8_t UsbDeviceDescriptor::bDeviceSubClass
```

**Description**

Device subclass code allocated by USB-IF. The value is limited by that of bDeviceClass.


### bLength


```
uint8_t UsbDeviceDescriptor::bLength
```

**Description**

Size of the descriptor, in bytes.


### bMaxPacketSize0


```
uint8_t UsbDeviceDescriptor::bMaxPacketSize0
```

**Description**

Maximum packet size of endpoint 0. Only values 8, 16, 32, and 64 are valid.


### bNumConfigurations


```
uint8_t UsbDeviceDescriptor::bNumConfigurations
```

**Description**

Configuration quantity.


### idProduct


```
uint16_t UsbDeviceDescriptor::idProduct
```

**Description**

Product ID allocated by the vendor.


### idVendor


```
uint16_t UsbDeviceDescriptor::idVendor
```

**Description**

Vendor ID allocated by USB-IF.


### iManufacturer


```
uint8_t UsbDeviceDescriptor::iManufacturer
```

**Description**

Index of the string descriptor that describes the vendor.


### iProduct


```
uint8_t UsbDeviceDescriptor::iProduct
```

**Description**

Index of the string descriptor that describes the product.


### iSerialNumber


```
uint8_t UsbDeviceDescriptor::iSerialNumber
```

**Description**

Index of the string descriptor that describes the device SN.
