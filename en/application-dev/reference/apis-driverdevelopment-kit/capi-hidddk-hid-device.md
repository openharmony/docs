# Hid_Device
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines a struct for basic device information.

**Since**: 11

**Related module**: [HidDdk](capi-hidddk.md)

**Header file:** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| const char* deviceName | Device name.|
| uint16_t vendorId | Vendor ID.|
| uint16_t productId | Product ID.|
| uint16_t version | Version number.|
| uint16_t bustype | Bus type.|
| Hid_DeviceProp* properties | Device properties.|
| uint16_t propLength | Number of device properties.|
