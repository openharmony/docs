# UsbConfigDescriptor

## Overview

Defines standard configuration descriptors, which correspond to **Standard Configuration Descriptor** in the USB protocol.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t bLength | Size of the descriptor, in bytes.|
| uint8_t bDescriptorType | Descriptor type.|
| uint16_t wTotalLength | Total length of the configuration descriptor, including the configuration, interface, endpoint, and class- or vendor-specific descriptors.|
| uint8_t bNumInterfaces | Number of interfaces supported by the configuration.|
| uint8_t bConfigurationValue | Configuration index, which is used to select the configuration.|
| uint8_t iConfiguration | Index of the string descriptor that describes the configuration.|
| uint8_t bmAttributes | Configuration attributes, including the power mode and remote wakeup.|
| uint8_t bMaxPower | Maximum power consumption of the bus-powered USB device, in 2 mA.|
