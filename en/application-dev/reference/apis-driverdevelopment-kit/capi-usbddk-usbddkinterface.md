# UsbDdkInterface

## Overview

Defines a USB DDK API, which is a collection of alternate settings for a particular USB interface.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t numAltsetting | Number of alternate settings of the USB interface.|
| struct UsbDdkInterfaceDescriptor* altsetting | Alternate setting of the USB interface.|
