# ScsiPeripheral_InquiryInfo
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines the SCSI inquiry data.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t deviceType | Device type.|
| char idVendor | Vendor ID.|
| char idProduct | Product ID.|
| char revProduct | Product version.|
| ScsiPeripheral_DeviceMemMap* data | Inquiry data.|
