# ScsiPeripheral_RequestSenseRequest


## Overview

Defines the request structure of the **request sense** command.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)

**Header file**: [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t [allocationLength](#allocationlength) | **Allocation length** field used to specify the size of the buffer prepared by the request initiator (usually the host) for the response data.| 
| uint8_t [control](#control) | **Control** field used to specify control information.| 
| uint8_t [byte1](#byte1) | First byte of the CDB.| 
| uint32_t [timeout](#timeout) | Timeout duration, in ms.| 


## Member Variable Description


### allocationLength

```
uint8_t ScsiPeripheral_RequestSenseRequest::allocationLength
```

**Description**

**Allocation length** field used to specify the size of the buffer prepared by the request initiator (usually the host) for the response data.


### byte1

```
uint8_t ScsiPeripheral_RequestSenseRequest::byte1
```

**Description**

First byte of the CDB.


### control

```
uint8_t ScsiPeripheral_RequestSenseRequest::control
```

**Description**

**Control** field used to specify control information.


### timeout

```
uint32_t ScsiPeripheral_RequestSenseRequest::timeout
```

**Description**

Timeout duration, in ms.
