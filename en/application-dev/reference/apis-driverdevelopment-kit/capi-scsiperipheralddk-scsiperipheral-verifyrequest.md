# ScsiPeripheral_VerifyRequest

## Overview

Defines the request structure of the **verify** command.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t lbAddress | Start address of logical blocks.|
| uint16_t verificationLength | Number of consecutive logical blocks.|
| uint8_t control | **Control** field used to specify control information.|
| uint8_t byte1 | First byte of the CDB.|
| uint8_t byte6 | Sixth byte of the CDB.|
| uint32_t timeout | Timeout duration, in ms.|
