# DDK_Ashmem

## Overview

Device memory map created by calling **OH_DDK_CreateAshmem**. A buffer using the device memory map can provide better performance.

**Since**: 12

**Related module**: [BaseDdk](capi-baseddk.md)

**Header file:** [ddk_types.h](capi-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t ashmemFd | File descriptor of the **Ashmem** object.|
| const uint8_t* address | Buffer address.|
| const uint32_t size | Buffer size.|
| uint32_t offset | Offset of the used buffer. The default value is **0**, indicating that there is no offset and the buffer starts from the specified address.|
| uint32_t bufferLength | Length of the buffer. By default, the value is equal to that of **size**, indicating that the entire buffer is used.|
| uint32_t transferredLength | Length of the data to be transferred.|
