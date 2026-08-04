# ipc_error_code.h

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=ceec5d18179ba29b1eca79fa9240e27795b5216c translatedAt=2026-07-28T02:18:25.124Z pushedAt=2026-07-29T07:30:25.136Z -->

## Overview

Provides IPC error code definitions for identifying and handling various errors that may occur during IPC communication. Based on the returned error codes, you can quickly locate the cause of issues, such as parameter errors, serialization failures, memory allocation failures, and remote object death, and take appropriate error handling measures.

**File to include**: <IPCKit/ipc_error_code.h>

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Supported device types** This API is available for all device types. You can determine whether the function is available by checking the system capability SystemCapability.Communication.IPC.Core.

**Since**: 12

**Related module**: [OHIPCErrorCode](capi-ohipcerrorcode.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [OH_IPC_ErrorCode](#oh_ipc_errorcode) | OH_IPC_ErrorCode | Enumerates the IPC error codes. |

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
| OH_IPC_ERROR_CODE_BASE = 1901000 | Start of the error code range. |
| OH_IPC_CHECK_PARAM_ERROR = OH_IPC_ERROR_CODE_BASE | Parameter error. This error code is returned when the passed parameter is a null pointer, the parameter value exceeds the valid range, or the parameter type does not match. You should check the validity and legality of the parameters. |
| OH_IPC_PARCEL_WRITE_ERROR = OH_IPC_ERROR_CODE_BASE + 1 | Serialized object write failed. This error may occur when memory is insufficient during data serialization or the data format is not supported. You should check whether the data size and format meet the requirements. |
| OH_IPC_PARCEL_READ_ERROR = OH_IPC_ERROR_CODE_BASE + 2 | Serialized object read failed. This error may occur when the length of the data being read exceeds the actual data length or the data format does not match. You should check whether the data reading order and data format are correct. |
| OH_IPC_MEM_ALLOCATOR_ERROR = OH_IPC_ERROR_CODE_BASE + 3 | Memory allocation failed. This error code is returned when the system memory is insufficient or the memory allocator is abnormal. You should check memory usage, release unnecessary resources, and retry. |
| OH_IPC_CODE_OUT_OF_RANGE = OH_IPC_ERROR_CODE_BASE + 4 | Command word out of the defined range [0x01, 0x00FFFFFF]. This error code is returned when the command word used in IPC communication is not within the valid range. You should check whether the command word definition complies with the specification requirements. |
| OH_IPC_DEAD_REMOTE_OBJECT = OH_IPC_ERROR_CODE_BASE + 5 | Remote object is dead. This error code is returned when the peer process of the IPC communication has exited or the remote object has been destroyed. You should re-establish the connection or use an alternative service. |
| OH_IPC_INVALID_USER_ERROR_CODE = OH_IPC_ERROR_CODE_BASE + 6 | User-defined error code out of range [1909000, 1909999]. This error code is returned when the custom error code set by you is not within the allowed range. You should ensure that the custom error code is within the valid range. |
| OH_IPC_INNER_ERROR = OH_IPC_ERROR_CODE_BASE + 7 | IPC internal error. This error code is returned when an unknown error occurs inside the IPC system. You can log the error and contact technical support or retry later. |
| OH_IPC_ERROR_CODE_MAX = OH_IPC_ERROR_CODE_BASE + 1000| Maximum error code.|
| OH_IPC_USER_ERROR_CODE_MIN = 1909000 | Minimum value for a custom error code.|
| OH_IPC_USER_ERROR_CODE_MAX = 1909999 | Maximum value for a custom error code.|