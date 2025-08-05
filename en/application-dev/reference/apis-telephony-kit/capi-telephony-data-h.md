# telephony_data.h

## Overview

Defines C APIs for cellular data module.

**File to include**: <telephony/core_service/telephony_radio.h>

**Library**: libtelephony_data.so

**System capability**: SystemCapability.Telephony.CellularData

**Since**: 13

**Related module**: [Telephony](capi-telephony.md)


## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_Telephony_GetDefaultCellularDataSlotId(void)](#oh_telephony_getdefaultcellulardataslotid) | Obtains the default SIM card used for mobile data.|

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

| Type| Description|
| -- | -- |
| int32_t | Default SIM card used for mobile data. The value **0** indicates card slot 1, and the value **1** indicates card slot 2.|
