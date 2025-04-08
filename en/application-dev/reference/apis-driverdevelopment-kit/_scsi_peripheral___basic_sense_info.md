# ScsiPeripheral_BasicSenseInfo


## Overview

Basic information about the sense data.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)

**Header file**: [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t [responseCode](#responsecode) | Response code.| 
| bool [valid](#valid) | Information validity flag.| 
| uint64_t [information](#information) | **Information** field.| 
| uint64_t [commandSpecific](#commandspecific) | **Command-specific information** field.| 
| bool [sksv](#sksv) | **Sense key specific** field flag.| 
| uint32_t [senseKeySpecific](#sensekeyspecific) | **Sense key specific** field.| 


## Member Variable Description


### commandSpecific

```
uint64_t ScsiPeripheral_BasicSenseInfo::commandSpecific
```

**Description**

**Command-specific information** field.


### information

```
uint64_t ScsiPeripheral_BasicSenseInfo::information
```

**Description**

**Information** field.


### responseCode

```
uint8_t ScsiPeripheral_BasicSenseInfo::responseCode
```

**Description**

Response code.


### senseKeySpecific

```
uint32_t ScsiPeripheral_BasicSenseInfo::senseKeySpecific
```

**Description**

**Sense key specific** field.


### sksv

```
bool ScsiPeripheral_BasicSenseInfo::sksv
```

**Description**

**Sense key specific** field flag.


### valid

```
bool ScsiPeripheral_BasicSenseInfo::valid
```

**Description**

Information validity flag.
