# ipc_error_code.h


## Overview

Defines the IPC result codes.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCErrorCode](_o_h_i_p_c_error_code.md)


## Summary


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_IPC_ErrorCode](_o_h_i_p_c_error_code.md#oh_ipc_errorcode) {<br>OH_IPC_SUCCESS = 0,<br>OH_IPC_ERROR_CODE_BASE = 1901000,<br>OH_IPC_CHECK_PARAM_ERROR = OH_IPC_ERROR_CODE_BASE,<br>OH_IPC_PARCEL_WRITE_ERROR = OH_IPC_ERROR_CODE_BASE + 1,<br>OH_IPC_PARCEL_READ_ERROR = OH_IPC_ERROR_CODE_BASE + 2,<br>OH_IPC_MEM_ALLOCATOR_ERROR = OH_IPC_ERROR_CODE_BASE + 3,<br>OH_IPC_CODE_OUT_OF_RANGE = OH_IPC_ERROR_CODE_BASE + 4,<br>OH_IPC_DEAD_REMOTE_OBJECT = OH_IPC_ERROR_CODE_BASE + 5,<br>OH_IPC_INVALID_USER_ERROR_CODE = OH_IPC_ERROR_CODE_BASE + 6,<br>OH_IPC_INNER_ERROR = OH_IPC_ERROR_CODE_BASE + 7,<br>OH_IPC_ERROR_CODE_MAX = OH_IPC_ERROR_CODE_BASE + 1000,<br>OH_IPC_USER_ERROR_CODE_MIN = 1909000,<br>OH_IPC_USER_ERROR_CODE_MAX = 1909999<br>} | Enumerates the IPC result codes.| 
