# ScsiPeripheral_ReadCapacityRequest

## Overview

Request structure of the **read capacity** command.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t lbAddress | Address of the logical unit.|
| uint8_t control | **Control** field used to specify control information.|
| uint8_t byte8 | Eighth byte of the CDB.|
| uint32_t timeout | Timeout duration, in ms.|
