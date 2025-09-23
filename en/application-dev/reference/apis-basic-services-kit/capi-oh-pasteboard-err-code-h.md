# oh_pasteboard_err_code.h
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @guo867-->
<!--Tester: @maxiaorong2-->
<!--Adviser: @HelloCrease-->

## Overview

Declares the error code information of the pasteboard.

**File to include**: <database/pasteboard/oh_pasteboard_err_code.h>

**Library**: libpasteboard.so

**System capability**: SystemCapability.MiscServices.Pasteboard

**Since**: 13

**Related module**: [Pasteboard](capi-pasteboard.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [PASTEBOARD_ErrCode](#pasteboard_errcode) | PASTEBOARD_ErrCode | Enumerates the error codes.|

## Enum Description

### PASTEBOARD_ErrCode

```
enum PASTEBOARD_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| ERR_OK = 0 | Operation successful.|
| ERR_PERMISSION_ERROR = 201 | Permission verification failed.|
| ERR_INVALID_PARAMETER = 401 | Invalid parameter.|
| ERR_DEVICE_NOT_SUPPORTED = 801 | Device capability not supported.|
| ERR_INNER_ERROR = 12900000 | Internal error.|
| ERR_BUSY = 12900003 | System busy.|
| ERR_PASTEBOARD_COPY_FILE_ERROR = 12900007 | Failed to copy files.|
| ERR_PASTEBOARD_PROGRESS_START_ERROR = 12900008 | Failed to display the progress.|
| ERR_PASTEBOARD_PROGRESS_ABNORMAL = 12900009 | Abnormal progress.|
| ERR_PASTEBOARD_GET_DATA_FAILED = 12900010 | Failed to obtain the pasteboard data.|
