# UsbRequestPipe

## Overview

Defines a USB request pipe.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint64_t interfaceHandle | Interface operation handle.|
| uint8_t endpoint | Endpoint address.|
| uint32_t timeout | Timeout duration, in milliseconds.|
