# oh_preferences_err_code.h

## Overview

Defines the error codes used in the **Preferences** module.

**File to include**: <database/preferences/oh_preferences_err_code.h>

**Library**: libohpreferences.so

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Since**: 13

**Related module**: [Preferences](capi-preferences.md)

## Summary

### Enums

| Name                                             | typedef Keyword         | Description        |
| ------------------------------------------------- | ---------------------- | ------------ |
| [OH_Preferences_ErrCode](#oh_preferences_errcode) | OH_Preferences_ErrCode | Enumerates the error codes.|

## Enum Description

### OH_Preferences_ErrCode

```
enum OH_Preferences_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 13

| Enum Item                                           | Description                      |
| ------------------------------------------------- | -------------------------- |
| PREFERENCES_OK = 0                                | The operation is successful.            |
| PREFERENCES_ERROR_INVALID_PARAM = 401             | Invalid parameter.              |
| PREFERENCES_ERROR_NOT_SUPPORTED = 801             | The system capability is not supported.          |
| PREFERENCES_ERROR_BASE = 15500000                 | Base error code.              |
| PREFERENCES_ERROR_DELETE_FILE = 15500010          | Failed to delete the file.            |
| PREFERENCES_ERROR_STORAGE = 15500011              | The storage is abnormal.                |
| PREFERENCES_ERROR_MALLOC = 15500012               | Memory allocation fails.            |
| PREFERENCES_ERROR_KEY_NOT_FOUND = 15500013        | The key does not exist.               |
| PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT = 15500019 | Failed to obtain the data change subscription service.|
