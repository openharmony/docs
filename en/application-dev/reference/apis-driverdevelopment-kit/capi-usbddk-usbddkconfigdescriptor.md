# UsbDdkConfigDescriptor

## Overview

Defines configuration descriptors.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| struct UsbConfigDescriptor configDescriptor | Standard configuration descriptor.|
| struct UsbDdkInterface* interface | Interfaces contained in the configuration.|
| uint8_t* extra | Unresolved descriptor, including class- or vendor-specific descriptors.|
| uint32_t extraLength | Length of the unresolved descriptor.|
