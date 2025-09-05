# ScsiPeripheral_Request
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines the request structure.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t commandDescriptorBlock[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN] | Command descriptor block.|
| uint8_t cdbLength | Length of the command descriptor block.|
| int8_t dataTransferDirection | Data transmission direction.|
| ScsiPeripheral_DeviceMemMap* data | Buffer for data transmission.|
| uint32_t timeout | Timeout duration, in ms.|
