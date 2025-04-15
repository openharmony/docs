# ScsiPeripheral_IORequest


## Overview

Defines the read/write operation request.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)

**Header file**: [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | Start address of a logical block.| 
| uint16_t [transferLength](#transferlength) | Number of consecutive logical blocks to be operated.| 
| uint8_t [control](#control) | **Control** field used to specify control information.| 
| uint8_t [byte1](#byte1) | First byte of the CDB.| 
| uint8_t [byte6](#byte6) | Sixth byte of the CDB.| 
| [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \* [data](#data) | Buffer for data transmission.| 
| uint32_t [timeout](#timeout) | Timeout duration, in ms.| 


## Member Variable Description


### byte1

```
uint8_t ScsiPeripheral_IORequest::byte1
```

**Description**

First byte of the CDB.


### byte6

```
uint8_t ScsiPeripheral_IORequest::byte6
```

**Description**

Sixth byte of the CDB.


### control

```
uint8_t ScsiPeripheral_IORequest::control
```

**Description**

**Control** field used to specify control information.


### data

```
ScsiPeripheral_DeviceMemMap* ScsiPeripheral_IORequest::data
```

**Description**

Buffer for data transmission.


### lbAddress

```
uint32_t ScsiPeripheral_IORequest::lbAddress
```

**Description**

Start address of a logical block.


### timeout

```
uint32_t ScsiPeripheral_IORequest::timeout
```

**Description**

Timeout duration, in ms.


### transferLength

```
uint16_t ScsiPeripheral_IORequest::transferLength
```

**Description**

Number of consecutive logical blocks to be operated.
