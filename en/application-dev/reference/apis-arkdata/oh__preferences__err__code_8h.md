# oh_preferences_err_code.h


## **Overview**

Defines the error codes used in the **Preferences** module.

**File to include**: &lt;database/preferences/oh_preferences_err_code.h&gt;

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

**Related module**: [Preferences](_preferences.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OH_Preferences_ErrCode](_preferences.md#oh_preferences_errcode) [OH_Preferences_ErrCode](_preferences.md#oh_preferences_errcode) | Defines an enum for error codes. |


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Preferences_ErrCode](_preferences.md#oh_preferences_errcode) {<br>PREFERENCES_OK = 0, PREFERENCES_ERROR_INVALID_PARAM = 401, PREFERENCES_ERROR_NOT_SUPPORTED = 801, PREFERENCES_ERROR_BASE = 15500000,<br>PREFERENCES_ERROR_DELETE_FILE = 15500010, PREFERENCES_ERROR_STORAGE = 15500011, PREFERENCES_ERROR_MALLOC = 15500012, PREFERENCES_ERROR_KEY_NOT_FOUND= 15500013,<br>PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT = 15500019<br>} | Enumerates the error codes used in the **Preferences** module. |
