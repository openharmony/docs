# ScsiPeripheral_VerifyRequest


## Overview

Request structure of the **verify** command.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | Start address of logical blocks.| 
| uint16_t [verificationLength](#verificationlength) | Number of consecutive logical blocks.| 
| uint8_t [control](#control) | **Control** field used to specify control information.| 
| uint8_t [byte1](#byte1) | First byte of the CDB.| 
| uint8_t [byte6](#byte6) | Sixth byte of the CDB.| 
| uint32_t [timeout](#timeout) | Timeout duration, in ms.| 


## Member Variable Description


### byte1

```
uint8_t ScsiPeripheral_VerifyRequest::byte1
```

**Description**

First byte of the CDB.


### byte6

```
uint8_t ScsiPeripheral_VerifyRequest::byte6
```

**Description**

Sixth byte of the CDB.


### control

```
uint8_t ScsiPeripheral_VerifyRequest::control
```

**Description**

**Control** field used to specify control information.


### lbAddress

```
uint32_t ScsiPeripheral_VerifyRequest::lbAddress
```

**Description**

Start address of logical blocks.


### timeout

```
uint32_t ScsiPeripheral_VerifyRequest::timeout
```

**Description**

Timeout duration, in ms.


### verificationLength

```
uint16_t ScsiPeripheral_VerifyRequest::verificationLength
```

**Description**

Number of consecutive logical blocks.
