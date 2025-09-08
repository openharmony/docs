# UsbDeviceMemMap
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Device memory map created by calling <b>OH_Usb_CreateDeviceMemMap</b>. A buffer using the device memory map can provide better performance.

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

**Header file:** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t* const address |  Buffer address.|
| const size_t size | Pointer to the buffer size.|
| uint32_t offset | Offset of the used buffer. The default value is **0**, indicating that there is no offset and the buffer starts from the specified {@link address}.|
| uint32_t bufferLength | Length of the used buffer. By default, the value is equal to the {@link size}, indicating that the entire buffer is used.|
| uint32_t transferedLength | Length of the transferred data.|
