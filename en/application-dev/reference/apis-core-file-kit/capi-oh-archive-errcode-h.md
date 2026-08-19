# oh_archive_errcode.h

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rl123567-->
<!--Designer: @selina_jiang; @RainbowLLL-->
<!--Tester: @zheng1368-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=bb49b7ed5e4e9e800a0691df554198c36528b3e0 translatedAt=2026-08-14T11:48:35.842Z pushedAt=2026-08-17T03:46:04.158Z -->

## Overview

Provides the error codes returned by the compression and decompression module.

**File to include:** <filemanagement/archive/oh_archive_errcode.h>

**Library:** liboharchive.so

**System capability**: SystemCapability.FileManagement.File.FileIO

**Since**: 26.0.0

**Related module:** [Archive](capi-archive.md)

## Summary

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_Archive_ErrCode](#oh_archive_errcode) | OH_Archive_ErrCode | Enumerates the error codes used in the compression and decompression module. |

## Enum Description

### OH_Archive_ErrCode

```c
enum OH_Archive_ErrCode
```

**Description**

Enumerates the error codes used in the compression and decompression module.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ARCHIVE_OK = 0 | The operation is successful.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_PARAM_ERROR = 401 | The input parameter is invalid.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_UNKNOWN_ERROR = 13900100 | An unknown error occurs.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_CANCEL_ERROR = 13900101 | User canceled the operation.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_UNSUPPORTED_ERROR = 13900102 | The current compression algorithm is not supported.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_MEM_ERROR = 13900103 | Memory allocation fails.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_OPEN_ERROR = 13900104 | The compressed package fails to be opened.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_WRITE_ERROR = 13900105 | The write operation fails.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_READ_ERROR = 13900106 | The read operation fails.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_STREAM_OUTPUT_ERROR = 13900107 | A stream output error occurs.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_INSUFFICIENT_OUTBUF_ERROR = 13900108 | The output buffer space is insufficient.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_NO_SPACE_ERROR = 13900200 | The disk space is insufficient.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_PATH_NOT_EXIST_ERROR = 13900201 | The path does not exist.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_PATH_EXISTS_ERROR = 13900202 | The path already exists.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_PATH_ACCESS_ERROR = 13900203 | A path access error occurs.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_NAME_TOO_LONG_ERROR = 13900204 | The file name is too long.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_FULL_PATH_TOO_LONG_ERROR = 13900205 | The complete path is too long.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_DATA_ERROR = 13900300 | A data integrity error occurs.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_CRC_ERROR = 13900301 | A CRC error occurs.<br>**Since:** 26.0.0 |
| OH_ARCHIVE_DEFLATE_ERROR = 13900302 | A DEFLATE algorithm error occurs.<br>**Since:** 26.0.0 |