# ScsiPeripheral_CapacityInfo


## Overview

Defines the SCSI read capacity.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)

**Header file**: [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [lbAddress](#lbaddress) | Address of the logical unit.| 
| uint32_t [lbLength](#lblength) | Length of a single logical unit, in bytes.| 


## Member Variable Description


### lbAddress

```
uint32_t ScsiPeripheral_CapacityInfo::lbAddress
```

**Description**

Address of the logical unit.


### lbLength

```
uint32_t ScsiPeripheral_CapacityInfo::lbLength
```

**Description**

Length of a single logical unit, in bytes.
