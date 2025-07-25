# ScsiPeripheral_RequestSenseRequest

## Overview

Defines the request structure of the **request sense** command.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t allocationLength | **Allocation length** field used to specify the size of the buffer prepared by the request initiator (usually the host) for the response data.|
| uint8_t control | **Control** field used to specify control information.|
| uint8_t byte1 | First byte of the CDB.|
| uint32_t timeout | Timeout duration, in ms.|
