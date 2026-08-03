# ipc_cskeleton.h

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=b912109263e3af9f49b553da7dcefbe5a5b3e9d6 translatedAt=2026-07-30T02:34:36.407Z pushedAt=2026-07-30T03:39:09.423Z -->

## Overview

This file provides C APIs for IPC framework features such as the token ID, credentials, PID/UID, and thread pool configuration. It is mainly used for context management and thread management in inter-process communication.

**File to include**: <IPCKit/ipc_cskeleton.h>

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCSkeleton](capi-ohipcskeleton.md)

## Summary

### Function

| Name| Description|
| ---- | ---- |
| [void OH_IPCSkeleton_JoinWorkThread(void)](#oh_ipcskeleton_joinworkthread) | Joins this thread to the IPC worker thread pool.|
| [void OH_IPCSkeleton_StopWorkThread(void)](#oh_ipcskeleton_stopworkthread) | Removes the current thread from the IPC worker thread pool.|
| [uint64_t OH_IPCSkeleton_GetCallingTokenId(void)](#oh_ipcskeleton_getcallingtokenid) | Obtains the token ID of the caller. This function must be called in the IPC context. Otherwise, the local token ID is returned.|
| [uint64_t OH_IPCSkeleton_GetFirstTokenId(void)](#oh_ipcskeleton_getfirsttokenid) | Obtains the token ID of the first caller. This API must be called in an IPC context; otherwise, the local token ID is returned. |
| [uint64_t OH_IPCSkeleton_GetSelfTokenId(void)](#oh_ipcskeleton_getselftokenid) | Obtains the local token ID.|
| [uint64_t OH_IPCSkeleton_GetCallingPid(void)](#oh_ipcskeleton_getcallingpid) | Obtains the PID of the caller. This function must be called in the IPC context. Otherwise, the local PID is returned.|
| [uint64_t OH_IPCSkeleton_GetCallingUid(void)](#oh_ipcskeleton_getcallinguid) | Obtains the UID of the caller. This function must be called in the IPC context. Otherwise, the local UID is returned.|
| [int OH_IPCSkeleton_IsLocalCalling(void)](#oh_ipcskeleton_islocalcalling) | Checks whether a local calling is being made.|
| [int OH_IPCSkeleton_SetMaxWorkThreadNum(const int maxThreadNum)](#oh_ipcskeleton_setmaxworkthreadnum) | Sets the maximum number of worker threads.|
| [int OH_IPCSkeleton_ResetCallingIdentity(char **identity, int32_t *len, OH_IPC_MemAllocator allocator)](#oh_ipcskeleton_resetcallingidentity) | Resets the identity credentials of the caller to the credentials (including the token ID, UID, and PID information) of the local process, and returns the caller's credential information. This information is mainly used for calling the **OH_IPCSkeleton_SetCallingIdentity** API. |
| [int OH_IPCSkeleton_SetCallingIdentity(const char *identity)](#oh_ipcskeleton_setcallingidentity) | Sets the caller credential information to the IPC context.|
| [int OH_IPCSkeleton_IsHandlingTransaction(void)](#oh_ipcskeleton_ishandlingtransaction) | Checks whether an IPC request is being processed. This API must be called in an IPC context; otherwise, **0** is returned. |

## Function Description

### OH_IPCSkeleton_JoinWorkThread()

```C
void OH_IPCSkeleton_JoinWorkThread(void)
```

**Description**

Joins the current thread to the IPC worker thread pool so that it can participate in processing IPC requests. This function is applicable to scenarios where custom IPC request processing threads are needed, for example, manually adding worker threads when the IPC concurrent processing capability needs to be expanded, or using dedicated threads to process IPC requests in specific service scenarios to improve response speed.

**Behavior after calling**

After this method is called, the current thread is registered as an IPC worker thread and participates in processing IPC requests from other processes until [OH_IPCSkeleton_StopWorkThread()](#oh_ipcskeleton_stopworkthread) is called to exit the thread pool.

**Constraints**

- Call this function only in scenarios where IPC request processing is required.

- After this function is called, the thread blocks and waits to process IPC requests.

- It is recommended to use this function together with [OH_IPCSkeleton_StopWorkThread()](#oh_ipcskeleton_stopworkthread) to properly exit the thread pool.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

### OH_IPCSkeleton_StopWorkThread()

```C
void OH_IPCSkeleton_StopWorkThread(void)
```

**Description**

Exits the current thread from the IPC worker thread pool so that it no longer participates in processing IPC requests.

**Behavior after calling**

After this method is called, the current thread is removed from the IPC worker thread pool and is no longer assigned IPC request processing tasks. The thread can then perform other operations.

**Constraints**

- Call this function when IPC request processing is no longer needed.

- Before calling this function, ensure that the current thread has joined the thread pool through [OH_IPCSkeleton_JoinWorkThread()](#oh_ipcskeleton_joinworkthread).

- Ensure that all IPC transactions are completed before the thread exits.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

### OH_IPCSkeleton_GetCallingTokenId()

```C
uint64_t OH_IPCSkeleton_GetCallingTokenId(void)
```

**Description**

Obtains the token ID of the caller. This is applicable to scenarios such as permission verification and identity identification on the IPC server side. Identity‑based access control can be implemented through the token ID. This API must be called in the IPC context. Otherwise, the local token ID is returned.

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

Obtains the token ID of the first caller in the IPC call chain. This API must be called in the IPC context. Otherwise, the local token ID is returned. This API is applicable to permission tracing and security audit scenarios in multi-level service calls. For example, it can be used in permission audits where you need to trace the identity of the original caller rather than the intermediate proxy service, or in cross‑process permission inheritance verification to confirm the source of the original permissions.

**Behavior after calling**

This API returns the token ID of the first client that initiated the IPC call.

**Constraints**

- This API is meaningful only in multi-level IPC call scenarios.

- In single-level call scenarios, the return value of this function is the same as that of [OH_IPCSkeleton_GetCallingTokenId()](#oh_ipcskeleton_getcallingtokenid).

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

Obtains the token ID of the current process. This is applicable to scenarios such as process self‑authentication and permission status verification. For example, it can be used to verify the permission status of the process itself during service startup, to confirm whether the process has the required permissions to access specific resources during permission checks, and to identify the current process identity in security audits.

**Behavior after calling**

This API returns the token ID of the current process, regardless of whether it is called in the IPC context.

The token ID is a unique identifier assigned by the system to each process, used for permission verification and identity identification.

**Constraints**

- This function can be called in any context and does not depend on the IPC context.

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

Obtains the PID of the caller. This is applicable to process-level permission control and security audit scenarios, for example, checking whether the caller process is in the trustlist during trustlist verification, recording caller process information in audit logs for security tracing, and making permission decisions based on the PID in cross-process access control. This API must be called in the IPC context. Otherwise, the PID of the current process is returned.

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

Obtains the UID of the caller. This is applicable to user-level permission control and identity identification in multi-user environments, for example, determining access permissions based on the UID in permission management, isolating data access for different users in multi-user systems, and recording user identities in security audits for behavior tracing. This API must be called in the IPC context. Otherwise, the ID of the current user is returned.

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

Checks whether the current IPC call is a local call.

**Behavior after calling**

The function returns **1** if the call is a local call, and **0** if the call is a remote call.

**Constraints**

- This function must be called in the IPC context.

- This function is commonly used to adopt different processing strategies based on the call type.

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

Sets the maximum number of threads in the IPC worker thread pool to control the concurrent processing capability of IPC requests.

**When to call**

- It is recommended to call this function at app startup to avoid frequent modifications at runtime.

- This configuration should be completed before calling [OH_IPCSkeleton_JoinWorkThread()](#oh_ipcskeleton_joinworkthread) to join the worker thread pool, to ensure that the thread pool works at the configured size.

- This configuration affects the capacity control of threads that subsequently join the thread pool.

**Behavior after calling**

After this method is called, the IPC framework manages worker threads based on the set maximum number of threads. When the number of concurrent IPC requests exceeds the number of threads, the requests are queued.

**Constraints**

- Unless there are special requirements, it is not recommended to change the maximum number of threads.

- Too many threads increase system resource consumption, while too few may affect IPC concurrent processing performance.

- Set this value appropriately based on actual service scenarios and device capabilities.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

  | Name| Description|
  | ------ | ---- |
  | const int maxThreadNum   | Maximum number of worker threads. Default value: 16. Value range: [1, 32]. This parameter controls the IPC concurrent processing capability. A smaller value saves system resources, while a larger value improves concurrent processing efficiency. If the value is out of range, the parameter error **OH_IPC_CHECK_PARAM_ERROR** is returned. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Result code.<br> Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) (value: **0**) if the operation is successful.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) (value: **-1**) if the parameter is invalid. Possible cause: **maxThreadNum** is not within the valid range [1, 32]. Solution: Check and adjust the parameter value.<br> Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) (value: **-2**) in other cases. Possible cause: Internal exception in the IPC framework. Solution: Check the IPC service status or restart the app. |

### OH_IPCSkeleton_ResetCallingIdentity()

```C
int OH_IPCSkeleton_ResetCallingIdentity(char **identity, int32_t *len, OH_IPC_MemAllocator allocator)
```

**Description**

Resets the caller identity credential to the identity credential of the local process (including TokenId, UID, and PID information), and returns the caller credential information. This is applicable to scenarios where you need to temporarily elevate permissions or perform operations with the identity of a service process. For example, it can be used to temporarily switch to a service identity when accessing protected resources in system services, or to perform privileged operations on behalf of a service process in permission proxy scenarios.

**Behavior after calling**

After this method is called, the identity credential in the current IPC context is switched to the credential of the local process, and the original caller credential information is returned for subsequent restoration.

**Constraints**

- This function must be called in the IPC request processing context.

- The returned credential information must be properly managed by the caller and released after use.

- This function must be used in pair with [OH_IPCSkeleton_SetCallingIdentity()](#oh_ipcskeleton_setcallingidentity) to restore the original credential after the operation is completed.

- Avoid maintaining the reset state for a long time, as it may affect permission verification.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| char **identity | Pointer to the memory address for storing the calling credential. The credential contains identity information such as the caller's token ID, UID, and PID, and can be used later to restore the calling identity via [OH_IPCSkeleton_SetCallingIdentity()](#oh_ipcskeleton_setcallingidentity). The memory is allocated by the user-provided allocator, and the user must release it after use. This function must be called in an IPC request processing context. This parameter cannot be null. |
| int32_t *len | Pointer to the length (in bytes) of the data written to identity. It informs the caller of the actual size of the credential data for subsequent correct use and memory release. This function must be called in an IPC request processing context. This parameter cannot be null. |
| [OH_IPC_MemAllocator](capi-ipc-cparcel-h.md#oh_ipc_memallocator) allocator | User-specified memory allocator used to allocate memory for **identity**. A custom allocator allows control over the memory allocation strategy (for example, using shared memory or heap memory). This function must be called in an IPC request processing context. This parameter cannot be null. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) (value: **0**) if successful.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) (value: **-1**) if the parameter is invalid. Possible cause: The **identity**, **len**, or **allocator** parameter is null. Solution: Ensure that the parameters are not null.<br> Returns [OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) (value: **-3**) if memory allocation fails. Possible cause: Insufficient system memory or an abnormal memory allocator. Solution: Release memory and retry, or check the memory allocator.<br> Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) (value: **-2**) in other cases. Possible cause: Internal IPC framework exception. Solution: Check the IPC service status or restart the app. |

### OH_IPCSkeleton_SetCallingIdentity()

```C
int OH_IPCSkeleton_SetCallingIdentity(const char *identity)
```

**Description**

Restores the caller credential information to the IPC context. This function restores the identity credential in the IPC context to the original caller credential. It must be called in the IPC request processing context. This is applicable to scenarios where normal permissions are restored after temporary privilege escalation operations, for example, restoring the caller identity after accessing protected resources on the server side, and restoring the caller permission state after permission proxy operations are completed.

**Behavior after calling**

After this method is called, the identity credential in the IPC context is restored to the caller credential previously saved through [OH_IPCSkeleton_ResetCallingIdentity()](#oh_ipcskeleton_resetcallingidentity).

**Constraints**

- This function and [OH_IPCSkeleton_ResetCallingIdentity()](#oh_ipcskeleton_resetcallingidentity) must be used in pairs.

- Only the valid credential returned by [OH_IPCSkeleton_ResetCallingIdentity()](#oh_ipcskeleton_resetcallingidentity) can be used.

- Call this function immediately after completing operations that require the server identity.

- Identity credentials should be properly managed to prevent credential leakage.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const char *identity | Caller identity, which cannot be null. This value comes from the return value of **OH_IPCSkeleton_ResetCallingIdentity**. This parameter and **OH_IPCSkeleton_ResetCallingIdentity** must be used in pairs. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the operation is successful.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the parameters are incorrect.<br> Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) in other cases.|

### OH_IPCSkeleton_IsHandlingTransaction()

```C
int OH_IPCSkeleton_IsHandlingTransaction(void)
```

**Description**

Checks whether an IPC request is being processed. This is applicable to scenarios where conditional judgment is needed based on the current IPC processing status, such as avoiding re-entry and status checks.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| int | Whether an IPC request is being processed. The value **1** indicates that an IPC request is being processed, and **0** indicates that no IPC request is being processed. |