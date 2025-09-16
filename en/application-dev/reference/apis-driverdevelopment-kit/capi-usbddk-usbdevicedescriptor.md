# UsbDeviceDescriptor
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines standard device descriptors, which correspond to **Standard Device Descriptor** in the USB protocol.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t bLength | Size of the descriptor, in bytes.|
| uint8_t bDescriptorType | Descriptor type.|
| uint16_t bcdUSB | USB protocol release number.|
| uint8_t bDeviceClass | Interface class code allocated by the USB-IF.|
| uint8_t bDeviceSubClass | Device subclass code allocated by USB-IF. The value is limited by that of {@link bDeviceClass}.|
| uint8_t bDeviceProtocol | Protocol code allocated by USB-IF. The value is limited by that of {@link bDeviceClass} and {@link bDeviceSubClass}.|
| uint8_t bMaxPacketSize0 | Maximum packet size of endpoint 0. Only values 8, 16, 32, and 64 are valid.|
| uint16_t idVendor | Vendor ID allocated by USB-IF.|
| uint16_t idProduct | Product ID allocated by the vendor.|
| uint16_t bcdDevice | Device SN.|
| uint8_t iManufacturer | Index of the string descriptor that describes the vendor.|
| uint8_t iProduct | Index of the string descriptor that describes the product.|
| uint8_t iSerialNumber | Index of the string descriptor that describes the device SN.|
| uint8_t bNumConfigurations | Configuration quantity.|
