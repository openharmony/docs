# ipc_cskeleton.h


## Overview

Provides C interfaces for managing the token IDs, credentials, process IDs (PIDs), user IDs (UIDs), and thread pool in the IPC framework.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCSkeleton](_o_h_i_p_c_skeleton.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| void [OH_IPCSkeleton_JoinWorkThread](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_joinworkthread) (void) | Joints this thread to the IPC worker thread pool. | 
| void [OH_IPCSkeleton_StopWorkThread](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_stopworkthread) (void) | Stops this thread. | 
| uint64_t [OH_IPCSkeleton_GetCallingTokenId](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getcallingtokenid) (void) | Obtains the token ID of the caller. This function must be called in the IPC context. Otherwise, the local token ID is returned. | 
| uint64_t [OH_IPCSkeleton_GetFirstTokenId](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getfirsttokenid) (void) | Obtain the token ID of the first invoker. | 
| uint64_t [OH_IPCSkeleton_GetSelfTokenId](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getselftokenid) (void) | Obtain the local token ID. | 
| uint64_t [OH_IPCSkeleton_GetCallingPid](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getcallingpid) (void) | Obtains the PID of the caller. This function must be called in the IPC context. Otherwise, the local PID is returned. | 
| uint64_t [OH_IPCSkeleton_GetCallingUid](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getcallinguid) (void) | Obtains the UID of the caller. This function must be called in the IPC context. Otherwise, the local UID is returned. | 
| int [OH_IPCSkeleton_IsLocalCalling](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_islocalcalling) (void) | Checks whether a local calling is being made. | 
| int [OH_IPCSkeleton_SetMaxWorkThreadNum](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_setmaxworkthreadnum) (const int maxThreadNum) | Sets the maximum number of worker threads. | 
| int [OH_IPCSkeleton_ResetCallingIdentity](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_resetcallingidentity) (char \*\*identity, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | Resets the caller identity credential (including the token ID, UID, and PID) to that of this process and returns the caller credential information. The credential information is used in **OH_IPCSkeleton_SetCallingIdentity**. | 
| int [OH_IPCSkeleton_SetCallingIdentity](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_setcallingidentity) (const char \*identity) | Sets the caller credential information to the IPC context. | 
| int [OH_IPCSkeleton_IsHandlingTransaction](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_ishandlingtransaction) (void) | Checks whether an IPC request is being handled. | 
