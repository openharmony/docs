# ipc_error_code.h


## 概述

提供IPC错误码定义。

**库：** libipc_capi.so

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**相关模块：**[OHIPCErrorCode](_o_h_i_p_c_error_code.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_IPC_ErrorCode](_o_h_i_p_c_error_code.md#oh_ipc_errorcode) {<br/>OH_IPC_SUCCESS = 0,<br/>OH_IPC_ERROR_CODE_BASE = 1901000,<br/>OH_IPC_CHECK_PARAM_ERROR = OH_IPC_ERROR_CODE_BASE,<br/>OH_IPC_PARCEL_WRITE_ERROR = OH_IPC_ERROR_CODE_BASE + 1,<br/>OH_IPC_PARCEL_READ_ERROR = OH_IPC_ERROR_CODE_BASE + 2,<br/>OH_IPC_MEM_ALLOCATOR_ERROR = OH_IPC_ERROR_CODE_BASE + 3,<br/>OH_IPC_CODE_OUT_OF_RANGE = OH_IPC_ERROR_CODE_BASE + 4,<br/>OH_IPC_DEAD_REMOTE_OBJECT = OH_IPC_ERROR_CODE_BASE + 5,<br/>OH_IPC_INVALID_USER_ERROR_CODE = OH_IPC_ERROR_CODE_BASE + 6,<br/>OH_IPC_INNER_ERROR = OH_IPC_ERROR_CODE_BASE + 7,<br/>OH_IPC_ERROR_CODE_MAX = OH_IPC_ERROR_CODE_BASE + 1000,<br/>OH_IPC_USER_ERROR_CODE_MIN = 1909000,<br/>OH_IPC_USER_ERROR_CODE_MAX = 1909999<br/>} | IPC错误码定义。 | 
