# Telephony Data


## Overview

Provides C APIs for the cellular data module.

**Since**: 13


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [telephony_data.h](telephony__data_8h.md) | Defines C APIs for cellular data module.<br>**File to include**: \<telephony\/cellular_data\/telephony_data.h\>|

### Functions

| Name| Description|
| -------- | -------- |
| int32_t [OH_Telephony_GetDefaultCellularDataSlotId](#oh_telephony_getdefaultcellulardataslotid)(void) | Obtains the default SIM card used for mobile data.|

## Function Description


### OH_Telephony_GetDefaultCellularDataSlotId()

```
int32_t OH_Telephony_GetDefaultCellularDataSlotId(void)
```

**Description**

Obtains the default SIM card used for mobile data.

**System capability**: SystemCapability.Telephony.CellularData

**Since**: 13

**Returns**

**0**: card slot 1.

**1**: card slot 2
