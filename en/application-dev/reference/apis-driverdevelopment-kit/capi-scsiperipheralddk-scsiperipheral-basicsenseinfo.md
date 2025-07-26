# ScsiPeripheral_BasicSenseInfo

## Overview

Defines the basic information about the sense data.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t responseCode | Response code.|
| bool valid | Information validity flag.|
| uint64_t information | **Information** field.|
| uint64_t commandSpecific | **Command-specific information** field.|
| bool sksv | Flag of the **Sense key specific** field.|
| uint32_t senseKeySpecific | **Sense key specific** field.|
