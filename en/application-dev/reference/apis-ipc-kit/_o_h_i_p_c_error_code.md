# OH_IPC_ErrorCode


## Overview

Defines the IPC result codes.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [ipc_error_code.h](ipc__error__code_8h.md) | Defines the IPC result codes.| 


### Enums

| Name| Description| 
| -------- | -------- |
| OH_IPC_ErrorCode {<br>OH_IPC_SUCCESS = 0,<br>OH_IPC_ERROR_CODE_BASE = 1901000,<br>OH_IPC_CHECK_PARAM_ERROR = OH_IPC_ERROR_CODE_BASE,<br>OH_IPC_PARCEL_WRITE_ERROR = OH_IPC_ERROR_CODE_BASE + 1,<br>OH_IPC_PARCEL_READ_ERROR = OH_IPC_ERROR_CODE_BASE + 2,<br>OH_IPC_MEM_ALLOCATOR_ERROR = OH_IPC_ERROR_CODE_BASE + 3,<br>OH_IPC_CODE_OUT_OF_RANGE = OH_IPC_ERROR_CODE_BASE + 4,<br>OH_IPC_DEAD_REMOTE_OBJECT = OH_IPC_ERROR_CODE_BASE + 5,<br>OH_IPC_INVALID_USER_ERROR_CODE = OH_IPC_ERROR_CODE_BASE + 6,<br>OH_IPC_INNER_ERROR = OH_IPC_ERROR_CODE_BASE + 7,<br>OH_IPC_ERROR_CODE_MAX = OH_IPC_ERROR_CODE_BASE + 1000,<br>OH_IPC_USER_ERROR_CODE_MIN = 1909000,<br>OH_IPC_USER_ERROR_CODE_MAX = 1909999<br>} | Enumerates the IPC result codes.| 


## Enum Description


### OH_IPC_ErrorCode

```
enum OH_IPC_ErrorCode
```

**Description**

Enumerates the IPC result codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_IPC_SUCCESS | Execution success.| 
| OH_IPC_ERROR_CODE_BASE | Start error code.| 
| OH_IPC_CHECK_PARAM_ERROR | Parameter error.| 
| OH_IPC_PARCEL_WRITE_ERROR | Failed to write data to the serialized object.| 
| OH_IPC_PARCEL_READ_ERROR | Failed to read data from the serialized object.| 
| OH_IPC_MEM_ALLOCATOR_ERROR | Failed to allocate memory.| 
| OH_IPC_CODE_OUT_OF_RANGE | The command word is out of the value range [0x01,0x00ffffff].| 
| OH_IPC_DEAD_REMOTE_OBJECT | The remote object is dead.| 
| OH_IPC_INVALID_USER_ERROR_CODE | The custom error code is out of the range [1900001, 1999999].| 
| OH_IPC_INNER_ERROR | IPC internal error.| 
| OH_IPC_ERROR_CODE_MAX | Maximum error code.| 
| OH_IPC_USER_ERROR_CODE_MIN | Minimum value for a custom error code.| 
| OH_IPC_USER_ERROR_CODE_MAX | Maximum value for a custom error code.| 
