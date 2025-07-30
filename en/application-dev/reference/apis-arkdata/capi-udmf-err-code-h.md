# udmf_err_code.h

## Overview

Declares the error codes used in the UDMF.

**File to include**: <database/udmf/udmf_err_code.h>

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](capi-udmf.md)

## Summary

### Enums

| Name                                       | typedef Keyword      | Description                        |
| ------------------------------------------- | ------------------- | ---------------------------- |
| [Udmf_ErrCode](#udmf_errcode)               | Udmf_ErrCode        | Enumerates the error codes.                |
| [Udmf_ListenerStatus](#udmf_listenerstatus) | Udmf_ListenerStatus | Enumerates the status codes returned when data is obtained asynchronously.|

## Enum Description

### Udmf_ErrCode

```
enum Udmf_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Enum Item                               | Description        |
| ------------------------------------- | ------------ |
| UDMF_E_OK = 0                         | Operation successful.  |
| UDMF_ERR = 20400000                   | Universal error codes.|
| UDMF_E_INVALID_PARAM = (UDMF_ERR + 1) | Invalid parameter.  |

### Udmf_ListenerStatus

```
enum Udmf_ListenerStatus
```

**Description**

Enumerates the status codes returned when data is obtained asynchronously.

**Since**: 15

| Enum Item                 | Description                        |
| ----------------------- | ---------------------------- |
| UDMF_FINISHED = 0       | Data is obtained successfully.          |
| UDMF_PROCESSING         | This task is being processed.            |
| UDMF_CANCELED           | This task is canceled.      |
| UDMF_INNER_ERROR = 200  | An internal error occurs.        |
| UDMF_INVALID_PARAMETERS | Invalid parameters are contained.          |
| UDMF_DATA_NOT_FOUND     | No data is obtained.        |
| UDMF_SYNC_FAILED        | An error occurs during data synchronization.|
| UDMF_COPY_FILE_FAILED   | Failed to copy the file.|
