# ScsiPeripheral_TestUnitReadyRequest


## Overview

Defines the request structure of the **test unit ready** command.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t [control](#control) | **Control** field used to specify control information.| 
| uint32_t [timeout](#timeout) | Timeout duration, in ms.| 


## Member Variable Description


### control

```
uint8_t ScsiPeripheral_TestUnitReadyRequest::control
```

**Description**

**Control** field used to specify control information.


### timeout

```
uint32_t ScsiPeripheral_TestUnitReadyRequest::timeout
```

**Description**

Timeout duration, in ms.
