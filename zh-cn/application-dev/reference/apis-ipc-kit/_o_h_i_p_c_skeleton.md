# OHIPCSkeleton


## 概述

提供IPC框架tokenId、凭据、PID/UID、线程池配置等功能C接口。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ipc_cskeleton.h](ipc__cskeleton_8h.md) | 提供IPC框架tokenId、凭据、PID/UID、线程池配置等功能C接口。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void [OH_IPCSkeleton_JoinWorkThread](#oh_ipcskeleton_joinworkthread) (void) | 当前线程加入IPC工作线程池。 | 
| void [OH_IPCSkeleton_StopWorkThread](#oh_ipcskeleton_stopworkthread) (void) | 当前线程退出IPC工作线程池。 | 
| uint64_t [OH_IPCSkeleton_GetCallingTokenId](#oh_ipcskeleton_getcallingtokenid) (void) | 获取调用方TokenId。该接口需要在IPC上下文中调用，否则返回自身TokenId。 | 
| uint64_t [OH_IPCSkeleton_GetFirstTokenId](#oh_ipcskeleton_getfirsttokenid) (void) | 获取首调者TokenId。 | 
| uint64_t [OH_IPCSkeleton_GetSelfTokenId](#oh_ipcskeleton_getselftokenid) (void) | 获取自身TokenId。 | 
| uint64_t [OH_IPCSkeleton_GetCallingPid](#oh_ipcskeleton_getcallingpid) (void) | 获取调用方进程ID。该接口需要在IPC上下文中调用，否则返当前进程ID。 | 
| uint64_t [OH_IPCSkeleton_GetCallingUid](#oh_ipcskeleton_getcallinguid) (void) | 获取调用方用户ID。该接口需要在IPC上下文中调用，否则返当前用户ID。 | 
| int [OH_IPCSkeleton_IsLocalCalling](#oh_ipcskeleton_islocalcalling) (void) | 判断是否正在进行本地调用。 | 
| int [OH_IPCSkeleton_SetMaxWorkThreadNum](#oh_ipcskeleton_setmaxworkthreadnum) (const int maxThreadNum) | 设置最大工作线程数。 | 
| int [OH_IPCSkeleton_ResetCallingIdentity](#oh_ipcskeleton_resetcallingidentity) (char \*\*identity, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | 重置调用方身份凭证为自身进程的身份凭证（包括tokenid、UID和PID信息），并返回调用方的凭证信息。 该信息主要用于OH_IPCSkeleton_SetCallingIdentity接口调用。 | 
| int [OH_IPCSkeleton_SetCallingIdentity](#oh_ipcskeleton_setcallingidentity) (const char \*identity) | 恢复调用方凭证信息至IPC上下文中。 | 
| int [OH_IPCSkeleton_IsHandlingTransaction](#oh_ipcskeleton_ishandlingtransaction) (void) | 是否正在处理IPC请求。 | 


## 函数说明


### OH_IPCSkeleton_GetCallingPid()

```
uint64_t OH_IPCSkeleton_GetCallingPid (void)
```

**描述**

获取调用方进程ID。该接口需要在IPC上下文中调用，否则返当前进程ID。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

返回调用方进程ID。


### OH_IPCSkeleton_GetCallingTokenId()

```
uint64_t OH_IPCSkeleton_GetCallingTokenId (void)
```

**描述**

获取调用方TokenId。该接口需要在IPC上下文中调用，否则返回自身TokenId。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

返回调用方TokenId。


### OH_IPCSkeleton_GetCallingUid()

```
uint64_t OH_IPCSkeleton_GetCallingUid (void)
```

**描述**

获取调用方用户ID。该接口需要在IPC上下文中调用，否则返当前用户ID。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

返回调用方用户ID。


### OH_IPCSkeleton_GetFirstTokenId()

```
uint64_t OH_IPCSkeleton_GetFirstTokenId (void)
```

**描述**

获取首调者TokenId。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

返回首调者TokenId。


### OH_IPCSkeleton_GetSelfTokenId()

```
uint64_t OH_IPCSkeleton_GetSelfTokenId (void)
```

**描述**

获取自身TokenId。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

返回自身TokenId。


### OH_IPCSkeleton_IsHandlingTransaction()

```
int OH_IPCSkeleton_IsHandlingTransaction (void)
```

**描述**

是否正在处理IPC请求。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

正在处理IPC请求，返回1；否则，返回0。


### OH_IPCSkeleton_IsLocalCalling()

```
int OH_IPCSkeleton_IsLocalCalling (void)
```

**描述**

判断是否正在进行本地调用。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

正在进行本地调用，返回1；否则，返回0。


### OH_IPCSkeleton_JoinWorkThread()

```
void OH_IPCSkeleton_JoinWorkThread (void)
```

**描述**

当前线程加入IPC工作线程池。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12


### OH_IPCSkeleton_ResetCallingIdentity()

```
int OH_IPCSkeleton_ResetCallingIdentity (char ** identity, int32_t * len, OH_IPC_MemAllocator allocator)
```

**描述**

重置调用方身份凭证为自身进程的身份凭证（包括tokenid、UID和PID信息），并返回调用方的凭证信息。 该信息主要用于OH_IPCSkeleton_SetCallingIdentity接口调用。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| identity | 用于存储调凭证的内存地址，该内存由用户提供的分配器进行内存分配，用户使用完后需要主动释放，不能为空。 | 
| len | 写入identity的数据长度，不能为空。 | 
| allocator | 用户指定的用来分配identity的内存分配器，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

内存分配失败返回[OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](_o_h_i_p_c_error_code.md)；

其它情况返回[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCSkeleton_SetCallingIdentity()

```
int OH_IPCSkeleton_SetCallingIdentity (const char * identity)
```

**描述**

恢复调用方凭证信息至IPC上下文中。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| identity | 调用方凭证，不能为空。来源于OH_IPCSkeleton_ResetCallingIdentity的返回值。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

其它情况返回[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCSkeleton_SetMaxWorkThreadNum()

```
int OH_IPCSkeleton_SetMaxWorkThreadNum (const int maxThreadNum)
```

**描述**

设置最大工作线程数。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| maxThreadNum | 最大工作线程数，默认16，范围:[1, 32]。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

其它情况返回[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCSkeleton_StopWorkThread()

```
void OH_IPCSkeleton_StopWorkThread (void)
```

**描述**

当前线程退出IPC工作线程池。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12
