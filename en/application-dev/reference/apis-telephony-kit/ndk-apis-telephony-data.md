# Telephony Data


## Overview

Provides C interface for the telephony cellular data.

**Since**: 13

## Summary


### File

| Name                                      | Description                                           |
| -------- | -------- |
| [telephony_data.h](telephony__data_8h.md) | Provides C interface for the telephony cellular data. |

### Functions

| Name                                                         | Description                                |
| -------- | -------- |
| int32_t [OH_Telephony_GetDefaultCellularDataSlotId](#oh_telephony_getdefaultcellulardataslotid)(void) | Obtains the default cellular data slot id. |

## Function Description


### OH_Telephony_GetDefaultCellularDataSlotId()

```
int32_t OH_Telephony_GetDefaultCellularDataSlotId(void)
```

**Description**

Obtains the default cellular data slot id.

**System capability** :SystemCapability.Telephony.CellularData

**Since**: 13

**Returns**

**0**: slot 1.

**1**: slot 2.