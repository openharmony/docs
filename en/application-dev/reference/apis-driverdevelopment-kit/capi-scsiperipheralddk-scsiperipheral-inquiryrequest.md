# ScsiPeripheral_InquiryRequest
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines the request structure of the **inquiry** command.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t pageCode | **Page code** field. Set this field if you want to obtain certain types of device information. When an **Inquiry** command with a specific page code is run, the device returns details related to the page code. If the page code is set to **0x00**, it indicates that the standard inquiry data rather than the data of specific pages is requested.|
| uint16_t allocationLength | **Allocation length** field used to specify the size of the buffer prepared by the request initiator (usually the host) for the response data.|
| uint8_t control | **Control** field used to specify control information.|
| uint8_t byte1 | First byte of the CDB.|
| uint32_t timeout | Timeout duration, in ms.|
