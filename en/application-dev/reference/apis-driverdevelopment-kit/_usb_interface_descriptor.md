# UsbInterfaceDescriptor


## Overview

Defines standard interface descriptors, which correspond to **Standard Interface Descriptor** in the USB protocol.

**Since**

10

**Related Modules**

[USB DDK](_usb_ddk.md)

**Header file**: [usb_ddk_types.h](usb__ddk__types_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [bLength](#blength) | Size of the descriptor, in bytes.|
| [bDescriptorType](#bdescriptortype) | Descriptor type.|
| [bInterfaceNumber](#binterfacenumber) | Interface ID.|
| [bAlternateSetting](#balternatesetting) | Value used to select the alternate setting of the interface.|
| [bNumEndpoints](#bnumendpoints) | Number of endpoints (excluding endpoint 0) used by the interface.|
| [bInterfaceClass](#binterfaceclass) | Interface class code allocated by the USB-IF.|
| [bInterfaceSubClass](#binterfacesubclass) | Device subclass code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass).|
| [bInterfaceProtocol](#binterfaceprotocol) | Protocol code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass) and [bInterfaceSubClass](#binterfacesubclass).|
| [iInterface](#iinterface) | Index of the string descriptor that describes the interface.|


## Member Variable Description


### bAlternateSetting


```
uint8_t UsbInterfaceDescriptor::bAlternateSetting
```

**Description**

Value used to select the alternate setting of the interface.


### bDescriptorType


```
uint8_t UsbInterfaceDescriptor::bDescriptorType
```

**Description**

Descriptor type.


### bInterfaceClass


```
uint8_t UsbInterfaceDescriptor::bInterfaceClass
```

**Description**

Interface class code allocated by the USB-IF.


### bInterfaceNumber


```
uint8_t UsbInterfaceDescriptor::bInterfaceNumber
```

**Description**

Interface ID.


### bInterfaceProtocol


```
uint8_t UsbInterfaceDescriptor::bInterfaceProtocol
```

**Description**

Protocol code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass) and [bInterfaceSubClass](#binterfacesubclass).


### bInterfaceSubClass


```
uint8_t UsbInterfaceDescriptor::bInterfaceSubClass
```

**Description**

Device subclass code allocated by USB-IF. The value is limited by that of [bInterfaceClass](#binterfaceclass).


### bLength


```
uint8_t UsbInterfaceDescriptor::bLength
```

**Description**

Size of the descriptor, in bytes.


### bNumEndpoints


```
uint8_t UsbInterfaceDescriptor::bNumEndpoints
```

**Description**

Number of endpoints (excluding endpoint 0) used by the interface.


### iInterface


```
uint8_t UsbInterfaceDescriptor::iInterface
```

**Description**

Index of the string descriptor that describes the interface.
