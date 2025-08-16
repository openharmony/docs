# ipc_cskeleton.h
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--SE: @zhaopeng_gitee-->
<!--TSE: @maxiaorong2-->

## Overview

Provides C APIs for managing the token IDs, credentials, process IDs (PIDs), user IDs (UIDs), and thread pool in the IPC framework.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCSkeleton](capi-ohipcskeleton.md)

## Summary

### Function

| Name| Description|
| ---- | ---- |
| [void OH_IPCSkeleton_JoinWorkThread(void)](#oh_ipcskeleton_joinworkthread) | Joints this thread to the IPC worker thread pool.|
| [void OH_IPCSkeleton_StopWorkThread(void)](#oh_ipcskeleton_stopworkthread) | Stops this thread.|
| [uint64_t OH_IPCSkeleton_GetCallingTokenId(void)](#oh_ipcskeleton_getcallingtokenid) | Obtains the token ID of the caller. This function must be called in the IPC context. Otherwise, the local token ID is returned.|
| [uint64_t OH_IPCSkeleton_GetFirstTokenId(void)](#oh_ipcskeleton_getfirsttokenid) | Obtains the token ID of the first caller.|
| [uint64_t OH_IPCSkeleton_GetSelfTokenId(void)](#oh_ipcskeleton_getselftokenid) | Obtains the local token ID.|
| [uint64_t OH_IPCSkeleton_GetCallingPid(void)](#oh_ipcskeleton_getcallingpid) | Obtains the PID of the caller. This function must be called in the IPC context. Otherwise, the local PID is returned.|
| [uint64_t OH_IPCSkeleton_GetCallingUid(void)](#oh_ipcskeleton_getcallinguid) | Obtains the UID of the caller. This function must be called in the IPC context. Otherwise, the local UID is returned.|
| [int OH_IPCSkeleton_IsLocalCalling(void)](#oh_ipcskeleton_islocalcalling) | Checks whether a local calling is being made.|
| [int OH_IPCSkeleton_SetMaxWorkThreadNum(const int maxThreadNum)](#oh_ipcskeleton_setmaxworkthreadnum) | Sets the maximum number of worker threads.|
| [int OH_IPCSkeleton_ResetCallingIdentity(char **identity, int32_t *len, OH_IPC_MemAllocator allocator)](#oh_ipcskeleton_resetcallingidentity) | Resets the caller identity credential (including the token ID, UID, and PID) to that of this process and returns the caller credential information. The credential information is used in **OH_IPCSkeleton_SetCallingIdentity**.|
| [int OH_IPCSkeleton_SetCallingIdentity(const char *identity)](#oh_ipcskeleton_setcallingidentity) | Sets the caller credential information to the IPC context.|
| [int OH_IPCSkeleton_IsHandlingTransaction(void)](#oh_ipcskeleton_ishandlingtransaction) | Checks whether an IPC request is being handled.|

## Function Description

### OH_IPCSkeleton_JoinWorkThread()

```C
void OH_IPCSkeleton_JoinWorkThread(void)
```

**Description**

Joints this thread to the IPC worker thread pool.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

### OH_IPCSkeleton_StopWorkThread()

```C
void OH_IPCSkeleton_StopWorkThread(void)
```

**Description**

Stops this thread.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

### OH_IPCSkeleton_GetCallingTokenId()

```C
uint64_t OH_IPCSkeleton_GetCallingTokenId(void)
```

**Description**

Obtains the token ID of the caller. This function must be called in the IPC context. Otherwise, the local token ID is returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| uint64_t | Returns the caller token ID.|

### OH_IPCSkeleton_GetFirstTokenId()

```C
uint64_t OH_IPCSkeleton_GetFirstTokenId(void)
```

**Description**

Obtains the token ID of the first caller.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| uint64_t | Returns the token ID of the first caller.|

### OH_IPCSkeleton_GetSelfTokenId()

```C
uint64_t OH_IPCSkeleton_GetSelfTokenId(void)
```

**Description**

Obtains the local token ID.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| uint64_t | Returns the local token ID.|

### OH_IPCSkeleton_GetCallingPid()

```C
uint64_t OH_IPCSkeleton_GetCallingPid(void)
```

**Description**

Obtains the PID of the caller. This function must be called in the IPC context. Otherwise, the local PID is returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| uint64_t | Returns the caller PID.|

### OH_IPCSkeleton_GetCallingUid()

```C
uint64_t OH_IPCSkeleton_GetCallingUid(void)
```

**Description**

Obtains the UID of the caller. This function must be called in the IPC context. Otherwise, the local UID is returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| uint64_t | Returns the caller UID.|

### OH_IPCSkeleton_IsLocalCalling()

```C
int OH_IPCSkeleton_IsLocalCalling(void)
```

**Description**

Checks whether a local calling is being made.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns **1** if a local calling is in progress; returns **0** otherwise.|

### OH_IPCSkeleton_SetMaxWorkThreadNum()

```C
int OH_IPCSkeleton_SetMaxWorkThreadNum(const int maxThreadNum)
```

**Description**

Sets the maximum number of worker threads.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const int maxThreadNum | Maximum number of worker threads.<br>Value range: [1, 32]<br>Default value: **16**|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if the parameter is incorrect;<br> returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md) in other cases.|

### OH_IPCSkeleton_ResetCallingIdentity()

```C
int OH_IPCSkeleton_ResetCallingIdentity(char **identity, int32_t *len, OH_IPC_MemAllocator allocator)
```

**Description**

Resets the caller identity credential (including the token ID, UID, and PID) to that of this process and returns the caller credential information. The credential information is used in **OH_IPCSkeleton_SetCallingIdentity**.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| char **identity | Double pointer to the address of the memory for holding the caller identity information. The memory is allocated by the allocator provided by the user and needs to be released. This pointer cannot be NULL.|
| int32_t *len | Pointer to the length of the data written to the identity. The value cannot be empty.|
| [OH_IPC_MemAllocator](capi-ipc-cparcel-h.md#oh_ipc_memallocator) allocator | Memory allocator specified by the user for allocating memory for **identity**. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if the parameter is incorrect;<br> returns [OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](capi-ipc-error-code-h.md) if memory allocation fails;<br> returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md) in other cases.|

### OH_IPCSkeleton_SetCallingIdentity()

```C
int OH_IPCSkeleton_SetCallingIdentity(const char *identity)
```

**Description**

Sets the caller credential information to the IPC context.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const char *identity | Pointer to the caller credential, which cannot be empty. The value is returned by **OH_IPCSkeleton_ResetCallingIdentity**.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if the parameter is incorrect;<br> returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md) in other cases.|

### OH_IPCSkeleton_IsHandlingTransaction()

```C
int OH_IPCSkeleton_IsHandlingTransaction(void)
```

**Description**

Checks whether an IPC request is being handled.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns **1** if an IPC request is being handled; returns **0** otherwise.|
