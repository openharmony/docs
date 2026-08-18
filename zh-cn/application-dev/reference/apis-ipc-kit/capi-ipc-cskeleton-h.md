# ipc_cskeleton.h
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->

## 概述

ipc_cskeleton.h提供IPC框架TokenId、凭据、PID/UID、线程池配置等功能C接口，主要用于进程间通信的上下文管理和线程管理。

**引用文件：** <IPCKit/ipc_cskeleton.h>

**库：** libipc_capi.so

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**相关模块：** [OHIPCSkeleton](capi-ohipcskeleton.md)

## 汇总

### 函数

| 名称 | 描述 |
| ---- | ---- |
| [void OH_IPCSkeleton_JoinWorkThread(void)](#oh_ipcskeleton_joinworkthread) | 当前线程加入IPC工作线程池。 |
| [void OH_IPCSkeleton_StopWorkThread(void)](#oh_ipcskeleton_stopworkthread) | 当前线程退出IPC工作线程池。 |
| [uint64_t OH_IPCSkeleton_GetCallingTokenId(void)](#oh_ipcskeleton_getcallingtokenid) | 获取调用方TokenId。该接口需要在IPC上下文中调用，否则返回自身TokenId。 |
| [uint64_t OH_IPCSkeleton_GetFirstTokenId(void)](#oh_ipcskeleton_getfirsttokenid) | 获取首调者TokenId。该接口需要在IPC上下文中调用，否则返回自身TokenId。 |
| [uint64_t OH_IPCSkeleton_GetSelfTokenId(void)](#oh_ipcskeleton_getselftokenid) | 获取自身TokenId。 |
| [uint64_t OH_IPCSkeleton_GetCallingPid(void)](#oh_ipcskeleton_getcallingpid) | 获取调用方进程ID。该接口需要在IPC上下文中调用，否则返回当前进程ID。 |
| [uint64_t OH_IPCSkeleton_GetCallingUid(void)](#oh_ipcskeleton_getcallinguid) | 获取调用方用户ID。该接口需要在IPC上下文中调用，否则返回当前用户ID。 |
| [int OH_IPCSkeleton_IsLocalCalling(void)](#oh_ipcskeleton_islocalcalling) | 判断是否正在进行本地调用。 |
| [int OH_IPCSkeleton_SetMaxWorkThreadNum(const int maxThreadNum)](#oh_ipcskeleton_setmaxworkthreadnum) | 设置最大工作线程数。 |
| [int OH_IPCSkeleton_ResetCallingIdentity(char **identity, int32_t *len, OH_IPC_MemAllocator allocator)](#oh_ipcskeleton_resetcallingidentity) | 重置调用方身份凭证为自身进程的身份凭证（包括TokenId、UID和PID信息），并返回调用方的凭证信息。 该信息主要用于OH_IPCSkeleton_SetCallingIdentity接口调用。 |
| [int OH_IPCSkeleton_SetCallingIdentity(const char *identity)](#oh_ipcskeleton_setcallingidentity) | 恢复调用方凭证信息至IPC上下文中。 |
| [int OH_IPCSkeleton_IsHandlingTransaction(void)](#oh_ipcskeleton_ishandlingtransaction) | 是否正在处理IPC请求。该接口需要在IPC上下文中调用，否则返回0。 |

## 函数说明

### OH_IPCSkeleton_JoinWorkThread()

```C
void OH_IPCSkeleton_JoinWorkThread(void)
```

**描述：**

当前线程加入IPC工作线程池，使其能够参与处理IPC请求。适用于需要自定义IPC请求处理线程的场景，例如：在需要扩展IPC并发处理能力时手动添加工作线程、在特定业务场景下需要专用线程处理IPC请求以提高响应速度。调用此方法后，当前线程将被注册为IPC工作线程，参与处理来自其他进程的IPC请求，直到调用[OH_IPCSkeleton_StopWorkThread()](#oh_ipcskeleton_stopworkthread)退出线程池。

- 仅在需要处理IPC请求的场景下调用。
- 调用后线程将阻塞等待处理IPC请求。
- 建议配合[OH_IPCSkeleton_StopWorkThread()](#oh_ipcskeleton_stopworkthread)使用以正确退出线程池。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

### OH_IPCSkeleton_StopWorkThread()

```C
void OH_IPCSkeleton_StopWorkThread(void)
```

**描述：**

当前线程退出IPC工作线程池，不再参与处理IPC请求。调用此方法后，当前线程将从IPC工作线程池中移除，不再被分配处理IPC请求的任务，线程可以执行其他操作。

- 应在不再需要处理IPC请求时调用。
- 调用前需确保当前线程已通过[OH_IPCSkeleton_JoinWorkThread()](#oh_ipcskeleton_joinworkthread)加入线程池。
- 线程退出时应确保所有IPC事务处理完成。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

### OH_IPCSkeleton_GetCallingTokenId()

```C
uint64_t OH_IPCSkeleton_GetCallingTokenId(void)
```

**描述：**

获取调用方TokenId。适用于在IPC服务端进行权限校验、身份识别等场景，通过TokenId可以实现基于身份的访问控制。该接口需要在IPC上下文中调用，否则返回自身TokenId。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| uint64_t | 返回调用方TokenId。 |

### OH_IPCSkeleton_GetFirstTokenId()

```C
uint64_t OH_IPCSkeleton_GetFirstTokenId(void)
```

**描述：**

获取IPC调用链中首个调用方的TokenId。该接口需要在IPC上下文中调用，否则返回自身TokenId。适用于多级服务调用中的权限追溯和安全审计场景，例如：在需要追踪原始调用方身份而非中间代理服务的权限审计中、在跨进程的权限继承验证中确认最原始的权限来源。返回发起IPC调用的首个客户端的TokenId标识。

- 仅在多级IPC调用场景中有意义。
- 在单级调用场景中，与[OH_IPCSkeleton_GetCallingTokenId()](#oh_ipcskeleton_getcallingtokenid)返回值相同。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| uint64_t | 返回首调者TokenId。 |

### OH_IPCSkeleton_GetSelfTokenId()

```C
uint64_t OH_IPCSkeleton_GetSelfTokenId(void)
```

**描述：**

获取当前进程自身的TokenId标识。适用于进程自我身份验证和权限状态确认场景，例如：在服务启动时校验自身权限状态、在权限检查中确认自身是否具备访问特定资源的权限、在安全审计中标识当前进程身份。返回当前进程的TokenId，无论是否在IPC上下文中调用。

- 可在任意上下文中调用，不依赖IPC上下文。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| uint64_t | 返回自身TokenId。 |

### OH_IPCSkeleton_GetCallingPid()

```C
uint64_t OH_IPCSkeleton_GetCallingPid(void)
```

**描述：**

获取调用方进程ID。适用于进程级权限控制和安全审计场景，例如：在白名单验证中检查调用方进程是否在允许列表中、在审计日志中记录调用方进程信息用于安全追溯、在跨进程访问控制中基于进程ID进行权限判断。该接口需要在IPC上下文中调用，否则返回当前进程ID。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| uint64_t | 返回调用方进程ID。 |

### OH_IPCSkeleton_GetCallingUid()

```C
uint64_t OH_IPCSkeleton_GetCallingUid(void)
```

**描述：**

获取调用方用户ID。适用于用户级权限控制和多用户环境下的身份识别场景，例如：在权限管理中根据用户ID判断访问权限、在多用户系统中隔离不同用户的数据访问、在安全审计中记录用户身份用于行为追溯。该接口需要在IPC上下文中调用，否则返回当前用户ID。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| uint64_t | 返回调用方用户ID。 |

### OH_IPCSkeleton_IsLocalCalling()

```C
int OH_IPCSkeleton_IsLocalCalling(void)
```

**描述：**

判断当前IPC调用是否为本地调用。

- 需在IPC上下文中调用。
- 常用于根据调用类型采取不同处理策略。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| int | 正在进行本地调用，返回1；否则，返回0。 |

### OH_IPCSkeleton_SetMaxWorkThreadNum()

```C
int OH_IPCSkeleton_SetMaxWorkThreadNum(const int maxThreadNum)
```

**描述：**

设置IPC工作线程池的最大线程数，控制IPC请求的并发处理能力。调用此方法后，IPC框架将按照设置的最大线程数管理工作线程，当并发IPC请求数超过线程数时，请求将排队等待。

- 建议在应用启动时调用，避免运行时频繁修改。
- 此配置应在调用[OH_IPCSkeleton_JoinWorkThread()](#oh_ipcskeleton_joinworkthread)加入工作线程池之前完成，以确保线程池按配置大小工作。
- 此配置影响后续加入线程池的线程容量控制。
- 若无特殊诉求，不建议用户更改最大线程数。
- 线程数过多会增加系统资源消耗，过少可能影响IPC并发处理性能。
- 需根据实际业务场景和设备能力合理设置。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数：**

  | 参数项 | 描述 |
  | ------ | ---- |
  | const int maxThreadNum   | 最大工作线程数，单位：个，默认16，范围:[1, 32]。设置该参数可控制IPC并发处理能力，较小的值可节省系统资源，较大的值可提高并发处理效率。超出范围时返回参数错误OH_IPC_CHECK_PARAM_ERROR。 |

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| int | 成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode)（对应值：0）；<br> 参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode)（对应值：-1）；可能原因：maxThreadNum不在有效范围[1, 32]内，解决措施：检查并调整参数值；<br> 其它情况返回[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode)（对应值：-2）。可能原因：IPC框架内部异常，解决措施：检查IPC服务状态或重启应用。 |

### OH_IPCSkeleton_ResetCallingIdentity()

```C
int OH_IPCSkeleton_ResetCallingIdentity(char **identity, int32_t *len, OH_IPC_MemAllocator allocator)
```

**描述：**

重置调用方身份凭证为自身进程的身份凭证（包括TokenId、UID和PID信息），并返回调用方的凭证信息。适用于需要临时提升权限或以服务进程身份执行操作的场景，例如：在系统服务中需要访问受保护资源时临时切换为服务身份、在权限代理场景中以服务身份代为执行特权操作。调用此方法后，当前IPC上下文的身份凭证将切换为自身进程的凭证，同时返回原始调用方的凭证信息，用于后续恢复。

- 必须在IPC请求处理上下文中调用。
- 返回的凭证信息需要由调用方妥善管理，使用后需释放。
- 必须与[OH_IPCSkeleton_SetCallingIdentity()](#oh_ipcskeleton_setcallingidentity)配对使用，在操作完成后恢复原始凭证。
- 避免长时间保持重置状态，可能影响权限校验。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| ------ | ---- |
| char **identity | identity 用于存储调用凭证的内存地址，凭证中包含调用方的TokenId、UID和PID等身份信息，可用于后续通过[OH_IPCSkeleton_SetCallingIdentity()](#oh_ipcskeleton_setcallingidentity)恢复调用方身份。该内存由用户提供的分配器进行内存分配，用户使用完后需要主动释放。必须在IPC请求处理上下文中调用。不能为空。 |
| int32_t *len | len 写入identity的数据长度（字节数），用于告知调用者凭证数据的实际大小，便于后续正确使用和释放内存。必须在IPC请求处理上下文中调用。不能为空。 |
| [OH_IPC_MemAllocator](capi-ipc-cparcel-h.md#oh_ipc_memallocator) allocator | allocator 用户指定的内存分配器，用于为identity分配内存。通过自定义分配器可控制内存分配策略（如使用共享内存或堆内存）。必须在IPC请求处理上下文中调用。不能为空。 |

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| int | 成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode)（对应值：0）；<br> 参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode)（对应值：-1）；可能原因：identity、len或allocator参数为空，解决措施：确保参数不为空；<br> 内存分配失败返回[OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode)（对应值：-3）；可能原因：系统内存不足或内存分配器异常，解决措施：释放内存后重试或检查内存分配器；<br> 其它情况返回[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode)（对应值：-2）；可能原因：IPC框架内部异常，解决措施：检查IPC服务状态或重启应用。 |

### OH_IPCSkeleton_SetCallingIdentity()

```C
int OH_IPCSkeleton_SetCallingIdentity(const char *identity)
```

**描述：**

恢复调用方凭证信息至IPC上下文中。将IPC上下文的身份凭证恢复为原始调用方的凭证。必须在IPC请求处理上下文中调用。适用于完成临时权限提升操作后恢复正常权限的场景，例如：在服务端完成受保护资源访问后恢复调用方身份、在权限代理操作完成后还原调用方权限状态。

- 调用此方法后，IPC上下文的身份凭证将恢复为之前通过[OH_IPCSkeleton_ResetCallingIdentity()](#oh_ipcskeleton_resetcallingidentity)保存的调用方凭证。
- 应在完成需要服务端身份的操作后立即调用。
- 身份凭证应正确管理，避免凭证泄露。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| ------ | ---- |
| const char *identity | identity 调用方凭证，不能为空。来源于OH_IPCSkeleton_ResetCallingIdentity的返回值。需与OH_IPCSkeleton_ResetCallingIdentity配对使用。 |

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| int | 成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode)；<br> 参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode)；<br> 其它情况返回[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode)。 |

### OH_IPCSkeleton_IsHandlingTransaction()

```C
int OH_IPCSkeleton_IsHandlingTransaction(void)
```

**描述：**

是否正在处理IPC请求。适用于需要根据当前IPC处理状态进行条件判断的场景，如避免重入、状态检查等。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| ---- | ---- |
| int | 正在处理IPC请求，返回1表示正在处理IPC请求；返回0表示未处理IPC请求。 |
