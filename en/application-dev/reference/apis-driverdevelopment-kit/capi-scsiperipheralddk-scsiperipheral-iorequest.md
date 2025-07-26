# ScsiPeripheral_IORequest

## Overview

Defines the read/write operation request.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t lbAddress | Start address of a logical block.|
| uint16_t transferLength | Number of consecutive logical blocks to be operated.|
| uint8_t control | **Control** field used to specify control information.|
| uint8_t byte1 | First byte of the CDB.|
| uint8_t byte6 | Sixth byte of the CDB.|
| ScsiPeripheral_DeviceMemMap* data | Buffer for data transmission.|
| uint32_t timeout | Timeout duration, in ms.|
