# ipc_error_code.h
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--SE: @zhaopeng_gitee-->
<!--TSE: @maxiaorong2-->

## Overview

Defines the IPC error codes.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCErrorCode](capi-ohipcerrorcode.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [OH_IPC_ErrorCode](#oh_ipc_errorcode) | OH_IPC_ErrorCode | Enumerates IPC error messages.|

## Enum Description

### OH_IPC_ErrorCode

```C
enum OH_IPC_ErrorCode
```

**Description**

Enumerates the IPC error codes.

**Since**: 12

| Value| Description|
| ------ | ---- |
| OH_IPC_SUCCESS = 0 | Execution successful.|
| OH_IPC_ERROR_CODE_BASE = 1901000 | Start error code.|
| OH_IPC_CHECK_PARAM_ERROR = OH_IPC_ERROR_CODE_BASE | Invalid parameter.|
| OH_IPC_PARCEL_WRITE_ERROR = OH_IPC_ERROR_CODE_BASE + 1 | Failed to write data to the serialized object.|
| OH_IPC_PARCEL_READ_ERROR = OH_IPC_ERROR_CODE_BASE + 2 | Failed to read data from the serialized object.|
| OH_IPC_MEM_ALLOCATOR_ERROR = OH_IPC_ERROR_CODE_BASE + 3 | Failed to allocate memory.|
| OH_IPC_CODE_OUT_OF_RANGE = OH_IPC_ERROR_CODE_BASE + 4 | The command word is out of the value range [0x01, 0x00ffffff].|
| OH_IPC_DEAD_REMOTE_OBJECT = OH_IPC_ERROR_CODE_BASE + 5 | The remote object is dead.|
| OH_IPC_INVALID_USER_ERROR_CODE = OH_IPC_ERROR_CODE_BASE + 6 | The custom error code is out of the range [1900001, 1999999].|
| OH_IPC_INNER_ERROR = OH_IPC_ERROR_CODE_BASE + 7| IPC internal error.|
| OH_IPC_ERROR_CODE_MAX = OH_IPC_ERROR_CODE_BASE + 8| Maximum error code.|
| OH_IPC_USER_ERROR_CODE_MIN = OH_IPC_ERROR_CODE_BASE + 9| Minimum value for a custom error code.|
| OH_IPC_USER_ERROR_CODE_MAX = OH_IPC_ERROR_CODE_BASE + 10| Maximum value for a custom error code.|
