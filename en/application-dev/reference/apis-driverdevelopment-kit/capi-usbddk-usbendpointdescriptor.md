# UsbEndpointDescriptor
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines standard endpoint descriptors, which correspond to **Standard Endpoint Descriptor** in the USB protocol.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t bLength | Size of the descriptor, in bytes.|
| uint8_t bDescriptorType | Descriptor type.|
| uint8_t bEndpointAddress | Endpoint address, including the endpoint number and endpoint direction.|
| uint8_t bmAttributes | Endpoint attributes, including the transfer type, synchronization type, and usage type.|
| uint16_t wMaxPacketSize | Maximum packet size supported by an endpoint.|
| uint8_t bInterval | Interval for polling endpoints for data transfer.|
| uint8_t bRefresh | Refresh rate for audio devices.|
| uint8_t bSynchAddress | Endpoint synchronization address for audio devices.|
