# UsbControlRequestSetup
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Setup data for control transfer. It corresponds to <b>Setup Data</b> in the USB protocol.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t bmRequestType | Request type.|
| uint8_t bRequest | Specific request.|
| uint16_t wValue | Value corresponding to **wValue** in the USB protocol. Its meaning varies according to the request.|
| uint16_t wIndex | Index corresponding to **wIndex** in the USB protocol. It is usually used to pass the index or offset. Its meaning varies according to the request. |
| uint16_t wLength | Data length corresponding to **wLength** in the USB protocol. If data is transferred, this field indicates the number of transferred bytes.|
