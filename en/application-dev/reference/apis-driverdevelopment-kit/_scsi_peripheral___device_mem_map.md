# ScsiPeripheral_DeviceMemMap


## Overview

Represents the device memory mapping created by calling **OH_ScsiPeripheral_CreateDeviceMemMap**. The buffer that uses the device memory mapping can provide better performance.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)

**Header file**: [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t \*const [address](#address) | Buffer address.| 
| const size_t [size](#size) | Buffer size.| 
| uint32_t [offset](#offset) | Offset of the used buffer. The default value is **0**, indicating that there is no offset and the buffer starts from the specified address.| 
| uint32_t [bufferLength](#bufferlength) | Length of the used buffer. By default, the value is equal to the size of the buffer, indicating that the entire buffer is used.| 
| uint32_t [transferredLength](#transferredlength) | Length of the data to be transferred.| 


## Member Variable Description


### address

```
uint8_t* const ScsiPeripheral_DeviceMemMap::address
```

**Description**

Buffer address.


### bufferLength

```
uint32_t ScsiPeripheral_DeviceMemMap::bufferLength
```

**Description**

Length of the used buffer. By default, the value is equal to the size of the buffer, indicating that the entire buffer is used.


### offset

```
uint32_t ScsiPeripheral_DeviceMemMap::offset
```

**Description**

Offset of the used buffer. The default value is **0**, indicating that there is no offset and the buffer starts from the specified address.


### size

```
const size_t ScsiPeripheral_DeviceMemMap::size
```

**Description**

Buffer size.


### transferredLength

```
uint32_t ScsiPeripheral_DeviceMemMap::transferredLength
```

**Description**

Length of the data to be transferred.
