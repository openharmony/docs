# oh_pasteboard_err_code.h

## Overview

Defines the error code information of the pasteboard.

**Library**: libpasteboard.so

**File to include**: <database/pasteboard/oh_pasteboard_err_code.h>

**System capability**: SystemCapability.MiscServices.Pasteboard

**Since**: 13

**Related module**: [Pasteboard](_pasteboard.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [PASTEBOARD_ErrCode](_pasteboard.md#pasteboard_errcode) [PASTEBOARD_ErrCode](_pasteboard.md#pasteboard_errcode) | Defines an enum for error codes. |


### Enums

| Name| Description|
| -------- | -------- |
| [PASTEBOARD_ErrCode](_pasteboard.md#pasteboard_errcode) {<br>[ERR_OK] = 0, [ERR_PERMISSION_ERROR]) = 201, [ERR_INVALID_PARAMETER] = 401, [ERR_DEVICE_NOT_SUPPORTED] = 801,<br>[ERR_INNER_ERROR] = 12900000, [ERR_BUSY] = 12900003, [ERR_PASTEBOARD_COPY_FILE_ERROR] = 12900007, [ERR_PASTEBOARD_PROGRESS_START_ERROR] = 12900008, [ERR_PASTEBOARD_PROGRESS_ABNORMAL] = 12900009, [ERR_PASTEBOARD_GET_DATA_FAILED] = 12900010, [ERR_BUSY_PROCESSING] = 27787277, [ERR_COPY_FORBIDDEN] = 27787278<br>} | Enumerates the error codes. |
