# UsbInterfaceDescriptor

## Overview

Defines standard interface descriptors, which correspond to **Standard Interface Descriptor** in the USB protocol.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t bLength | Size of the descriptor, in bytes.|
| uint8_t bDescriptorType | Descriptor type.|
| uint8_t bInterfaceNumber | Interface ID.|
| uint8_t bAlternateSetting | Value used to select the alternate setting of the interface.|
| uint8_t bNumEndpoints | Number of endpoints (excluding endpoint 0) used by the interface.|
| uint8_t bInterfaceClass | Interface class code allocated by the USB-IF.|
| uint8_t bInterfaceSubClass | Device subclass code allocated by USB-IF. The value is limited by that of {@link bInterfaceClass}.|
| uint8_t bInterfaceProtocol | Protocol code allocated by USB-IF. The value is limited by that of {@link bInterfaceClass} and {@link bInterfaceSubClass}.|
| uint8_t iInterface | Index of the string descriptor that describes the interface.|
