# ScsiPeripheral_ReadCapacityRequest


## Overview

Defines the request structure of the **read capacity** command.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | Address of the logical unit.| 
| uint8_t [control](#control) | Control field used to specify control information.| 
| uint8_t [byte8](#byte8) | Eighth byte of the CDB.| 
| uint32_t [timeout](#timeout) | Timeout duration, in ms.| 


## Member Variable Description


### byte8

```
uint8_t ScsiPeripheral_ReadCapacityRequest::byte8
```

**Description**

Eighth byte of the CDB.


### control

```
uint8_t ScsiPeripheral_ReadCapacityRequest::control
```

**Description**

Control field used to specify control information.


### lbAddress

```
uint32_t ScsiPeripheral_ReadCapacityRequest::lbAddress
```

**Description**

Address of the logical unit.


### timeout

```
uint32_t ScsiPeripheral_ReadCapacityRequest::timeout
```

**Description**

Timeout duration, in ms.
