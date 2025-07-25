# UsbDdkInterfaceDescriptor

## Overview

Defines USB interface descriptors.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| struct UsbInterfaceDescriptor interfaceDescriptor | Standard USB interface descriptor.|
| struct UsbDdkEndpointDescriptor* endPoint | Endpoint descriptor contained in the interface.|
| uint8_t* extra | Unresolved descriptor, including class- or vendor-specific descriptors.|
| uint32_t extraLength | Length of the unresolved descriptor.|
