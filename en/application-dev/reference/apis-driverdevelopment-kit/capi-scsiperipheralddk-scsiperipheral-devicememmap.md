# ScsiPeripheral_DeviceMemMap

## Overview

Represents the device memory mapping created by calling **OH_ScsiPeripheral_CreateDeviceMemMap**. The buffer that uses the device memory mapping can provide better performance.

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

**Header file**: [scsi_peripheral_types.h](capi-scsi-peripheral-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t* const address | Buffer address.|
| const size_t size | Buffer size.|
| uint32_t offset | Offset of the used buffer. The default value is **0**, indicating that there is no offset and the buffer starts from the specified address.|
| uint32_t bufferLength | Length of the used buffer. By default, the value is equal to the size of the buffer, indicating that the entire buffer is used.|
| uint32_t transferredLength | Length of the data to be transferred.|
