# OHIPCSkeleton


## Overview

Provides C interfaces for managing the token IDs, credentials, process IDs (PIDs), user IDs (UIDs), and thread pool in the IPC framework.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [ipc_cskeleton.h](ipc__cskeleton_8h.md) | Provides C interfaces for managing the token IDs, credentials, process IDs (PIDs), user IDs (UIDs), and thread pool in the IPC framework.|


### Functions

| Name| Description|
| -------- | -------- |
| void [OH_IPCSkeleton_JoinWorkThread](#oh_ipcskeleton_joinworkthread) (void) | Joints this thread to the IPC worker thread pool.|
| void [OH_IPCSkeleton_StopWorkThread](#oh_ipcskeleton_stopworkthread) (void) | Stops this thread.|
| uint64_t [OH_IPCSkeleton_GetCallingTokenId](#oh_ipcskeleton_getcallingtokenid) (void) | Obtains the token ID of the caller. This function must be called in the IPC context. Otherwise, the local token ID is returned.|
| uint64_t [OH_IPCSkeleton_GetFirstTokenId](#oh_ipcskeleton_getfirsttokenid) (void) | Obtains the token ID of the first caller. |
| uint64_t [OH_IPCSkeleton_GetSelfTokenId](#oh_ipcskeleton_getselftokenid) (void) | Obtains the local token ID. |
| uint64_t [OH_IPCSkeleton_GetCallingPid](#oh_ipcskeleton_getcallingpid) (void) | Obtains the PID of the caller. This function must be called in the IPC context. Otherwise, the local PID is returned.|
| uint64_t [OH_IPCSkeleton_GetCallingUid](#oh_ipcskeleton_getcallinguid) (void) | Obtains the UID of the caller. This function must be called in the IPC context. Otherwise, the local UID is returned.|
| int [OH_IPCSkeleton_IsLocalCalling](#oh_ipcskeleton_islocalcalling) (void) | Checks whether a local calling is being made.|
| int [OH_IPCSkeleton_SetMaxWorkThreadNum](#oh_ipcskeleton_setmaxworkthreadnum) (const int maxThreadNum) | Sets the maximum number of worker threads.|
| int [OH_IPCSkeleton_ResetCallingIdentity](#oh_ipcskeleton_resetcallingidentity) (char \*\*identity, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | Resets the caller identity credential (including the token ID, UID, and PID) to that of this process and returns the caller credential information. The credential information is used in **OH_IPCSkeleton_SetCallingIdentity**.|
| int [OH_IPCSkeleton_SetCallingIdentity](#oh_ipcskeleton_setcallingidentity) (const char \*identity) | Sets the caller credential information to the IPC context.|
| int [OH_IPCSkeleton_IsHandlingTransaction](#oh_ipcskeleton_ishandlingtransaction) (void) | Checks whether an IPC request is being handled.|


## Function Description


### OH_IPCSkeleton_GetCallingPid()

```
uint64_t OH_IPCSkeleton_GetCallingPid (void )
```

**Description**

Obtains the PID of the caller. This function must be called in the IPC context. Otherwise, the local PID is returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns the caller PID.


### OH_IPCSkeleton_GetCallingTokenId()

```
uint64_t OH_IPCSkeleton_GetCallingTokenId (void )
```

**Description**

Obtains the token ID of the caller. This function must be called in the IPC context. Otherwise, the local token ID is returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns the caller token ID.


### OH_IPCSkeleton_GetCallingUid()

```
uint64_t OH_IPCSkeleton_GetCallingUid (void )
```

**Description**

Obtains the UID of the caller. This function must be called in the IPC context. Otherwise, the local UID is returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns the caller UID.


### OH_IPCSkeleton_GetFirstTokenId()

```
uint64_t OH_IPCSkeleton_GetFirstTokenId (void )
```

**Description**

Obtains the token ID of the first caller.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns the token ID of the first caller.


### OH_IPCSkeleton_GetSelfTokenId()

```
uint64_t OH_IPCSkeleton_GetSelfTokenId (void )
```

**Description**

Obtains the local token ID.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns the local token ID.


### OH_IPCSkeleton_IsHandlingTransaction()

```
int OH_IPCSkeleton_IsHandlingTransaction (void )
```

**Description**

Checks whether an IPC request is being handled.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns **1** if an IPC request is being handled; returns **0** otherwise.


### OH_IPCSkeleton_IsLocalCalling()

```
int OH_IPCSkeleton_IsLocalCalling (void )
```

**Description**

Checks whether a local calling is being made.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns **1** if a local calling is in progress; returns **0** otherwise.


### OH_IPCSkeleton_JoinWorkThread()

```
void OH_IPCSkeleton_JoinWorkThread (void )
```

**Description**

Joints this thread to the IPC worker thread pool.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12


### OH_IPCSkeleton_ResetCallingIdentity()

```
int OH_IPCSkeleton_ResetCallingIdentity (char ** identity, int32_t * len, OH_IPC_MemAllocator allocator )
```

**Description**

Resets the caller identity credential (including the token ID, UID, and PID) to that of this process and returns the caller credential information. The credential information is used in **OH_IPCSkeleton_SetCallingIdentity**.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| identity | Pointer to the address of the memory for holding the caller identity information. The memory is allocated by the allocator provided by the user and needs to be released. This pointer cannot be NULL.|
| len | Pointer to the length of the data written to the identity. The value cannot be empty.|
| allocator | Memory allocator specified by the user for allocating memory. This parameter cannot be empty.|

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if incorrect parameters are detected.

Returns [OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](_o_h_i_p_c_error_code.md) if memory allocation fails.

Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md) in other cases.


### OH_IPCSkeleton_SetCallingIdentity()

```
int OH_IPCSkeleton_SetCallingIdentity (const char * identity)
```

**Description**

Sets the caller credential information to the IPC context.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| identity | Pointer to the caller credential, which cannot be empty. The value is returned by **OH_IPCSkeleton_ResetCallingIdentity**.|

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if incorrect parameters are detected.

Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md) in other cases.


### OH_IPCSkeleton_SetMaxWorkThreadNum()

```
int OH_IPCSkeleton_SetMaxWorkThreadNum (const int maxThreadNum)
```

**Description**

Sets the maximum number of worker threads.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| maxThreadNum | Maximum number of worker threads.<br>Value range: [1, 32]<br>Default value: **16** |

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if incorrect parameters are detected.

Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md) in other cases.


### OH_IPCSkeleton_StopWorkThread()

```
void OH_IPCSkeleton_StopWorkThread (void )
```

**Description**

Stops this thread.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12
