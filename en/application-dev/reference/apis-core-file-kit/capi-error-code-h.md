# error_code.h

## Overview

Defines the error codes for the **FileIO** module.

**File to include**: <filemanagement/fileio/error_code.h>

**Library**: NA

**System capability**: SystemCapability.FileManagement.File.FileIO

**Since**: 12

**Related module**: [FileIO](capi-fileio.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [FileManagement_ErrCode](#filemanagement_errcode) | FileManagement_ErrCode | Enumerates the error codes used in the **FileIO** module.|

## Enum Description

### FileManagement_ErrCode

```
enum FileManagement_ErrCode
```

**Description**

Enumerates the error codes used in the **FileIO** module.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| ERR_OK = 0 | The API is called successfully.|
| ERR_PERMISSION_ERROR = 201 | The permission verification fails.|
| ERR_INVALID_PARAMETER = 401 | Invalid parameter.|
| ERR_DEVICE_NOT_SUPPORTED = 801 | The device does not support this API.|
| ERR_EPERM = 13900001 | The operation is not allowed.|
| ERR_ENOENT = 13900002 | The file or folder does not exist.|
| ERR_ENOMEM = 13900011 | A memory overflow occurs.|
| ERR_UNKNOWN = 13900042 | Internal unknown error.|
