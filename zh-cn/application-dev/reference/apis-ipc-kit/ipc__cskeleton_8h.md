# ipc_cskeleton.h


## 概述

提供IPC框架tokenId、凭据、PID/UID、线程池配置等功能C接口。

**库：** libipc_capi.so

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**相关模块：**[OHIPCSkeleton](_o_h_i_p_c_skeleton.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_IPCSkeleton_JoinWorkThread](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_joinworkthread) (void) | 当前线程加入IPC工作线程池。 | 
| void [OH_IPCSkeleton_StopWorkThread](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_stopworkthread) (void) | 当前线程退出IPC工作线程池。 | 
| uint64_t [OH_IPCSkeleton_GetCallingTokenId](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getcallingtokenid) (void) | 获取调用方TokenId。该接口需要在IPC上下文中调用，否则返回自身TokenId。 | 
| uint64_t [OH_IPCSkeleton_GetFirstTokenId](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getfirsttokenid) (void) | 获取首调者TokenId。 | 
| uint64_t [OH_IPCSkeleton_GetSelfTokenId](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getselftokenid) (void) | 获取自身TokenId。 | 
| uint64_t [OH_IPCSkeleton_GetCallingPid](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getcallingpid) (void) | 获取调用方进程ID。该接口需要在IPC上下文中调用，否则返当前进程ID。 | 
| uint64_t [OH_IPCSkeleton_GetCallingUid](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_getcallinguid) (void) | 获取调用方用户ID。该接口需要在IPC上下文中调用，否则返当前用户ID。 | 
| int [OH_IPCSkeleton_IsLocalCalling](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_islocalcalling) (void) | 判断是否正在进行本地调用。 | 
| int [OH_IPCSkeleton_SetMaxWorkThreadNum](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_setmaxworkthreadnum) (const int maxThreadNum) | 设置最大工作线程数。 | 
| int [OH_IPCSkeleton_ResetCallingIdentity](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_resetcallingidentity) (char \*\*identity, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | 重置调用方身份凭证为自身进程的身份凭证（包括tokenid、UID和PID信息），并返回调用方的凭证信息。 该信息主要用于OH_IPCSkeleton_SetCallingIdentity接口调用。 | 
| int [OH_IPCSkeleton_SetCallingIdentity](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_setcallingidentity) (const char \*identity) | 恢复调用方凭证信息至IPC上下文中。 | 
| int [OH_IPCSkeleton_IsHandlingTransaction](_o_h_i_p_c_skeleton.md#oh_ipcskeleton_ishandlingtransaction) (void) | 是否正在处理IPC请求。 | 
