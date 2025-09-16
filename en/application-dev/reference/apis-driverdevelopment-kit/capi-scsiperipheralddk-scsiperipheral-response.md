# ScsiPeripheral_Response
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines the response structure.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t senseData[SCSIPERIPHERAL_MAX_SENSE_DATA_LEN] | Sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.|
| ScsiPeripheral_Status status | Status when the call is complete, for example, **Good** or **Busy**.|
| uint8_t maskedStatus | Masked status, which is used in SCSI Generic (SG) interfaces of Linux to store the processed SCSI status for easy access by applications.|
| uint8_t msgStatus | Message status.|
| uint8_t sbLenWr | Number of bytes that are actually written to the sense buffer.|
| uint16_t hostStatus | Host adapter status, for example, success (0x00), connection failure (0x01), busy bus (0x02), or timeout (0x03).|
| uint16_t driverStatus | Driver status, for example, success (0x00) or busy device or resource (0x01).|
| int32_t resId | Length deviation of the actually transmitted data, that is, the number of bytes that are not transmitted.|
| uint32_t duration | Command execution duration, in ms.|
