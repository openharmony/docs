# ScsiPeripheral_InquiryInfo

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
