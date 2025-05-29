# CMSIS 接口


## **汇总**


### 文件

  | 文件&nbsp;Name | 描述 | 
| -------- | -------- |
| cmsis_os2.h | CMSIS&nbsp;2.0&nbsp;标准接口头文件。 | 


### 结构体

  | 结构体&nbsp;Name | 描述 | 
| -------- | -------- |
| [osVersion_t](os_version__t.md) | 系统版本信息。&nbsp;[更多...](os_version__t.md) | 
| [osThreadAttr_t](os_thread_attr__t.md) | 线程参数类型。&nbsp;[更多...](os_thread_attr__t.md) | 
| [osTimerAttr_t](os_timer_attr__t.md) | 定时器参数类型，不支持配置。&nbsp;[更多...](os_timer_attr__t.md) | 
| [osEventFlagsAttr_t](os_event_flags_attr__t.md) | 事件参数类型，不支持配置。&nbsp;[更多...](os_event_flags_attr__t.md) | 
| [osMutexAttr_t](os_mutex_attr__t.md) | 互斥锁参数类型，不支持配置。&nbsp;[更多...](os_mutex_attr__t.md) | 
| [osSemaphoreAttr_t](os_semaphore_attr__t.md) | 信号量参数类型，不支持配置。&nbsp;[更多...](os_semaphore_attr__t.md) | 
| [osMemoryPoolAttr_t](os_memory_pool_attr__t.md) | 内存池参数类型。&nbsp;[更多...](os_memory_pool_attr__t.md) | 
| [osMessageQueueAttr_t](os_message_queue_attr__t.md) | 消息队列参数类型。&nbsp;[更多...](os_message_queue_attr__t.md) | 


### 宏定义

  | 宏定义&nbsp;Name | 描述 | 
| -------- | -------- |
| [osWaitForever](#oswaitforever)&nbsp;&nbsp;&nbsp;0xFFFFFFFFU | 系统永久等待。&nbsp;[更多...](#oswaitforever) | 
| [osFlagsWaitAny](#osflagswaitany)&nbsp;&nbsp;&nbsp;0x00000000U | 等待任何标志触发。&nbsp;[更多...](#osflagswaitany) | 
| [osFlagsWaitAll](#osflagswaitall)&nbsp;&nbsp;&nbsp;0x00000001U | 等待全部标志触发。&nbsp;[更多...](#osflagswaitall) | 
| [osFlagsNoClear](#osflagsnoclear)&nbsp;&nbsp;&nbsp;0x00000002U | 不清除指定等待标志。&nbsp;[更多...](#osflagsnoclear) | 
| [osFlagsError](#osflagserror)&nbsp;&nbsp;&nbsp;0x80000000U | 标志相关函数最高位错误，不支持。&nbsp;[更多...](#osflagserror) | 
| [osFlagsErrorUnknown](#osflagserrorunknown)&nbsp;&nbsp;&nbsp;0xFFFFFFFFU | 线程标志未知错误。&nbsp;[更多...](#osflagserrorunknown) | 
| [osFlagsErrorTimeout](#osflagserrortimeout)&nbsp;&nbsp;&nbsp;0xFFFFFFFEU | 线程标志超时错误。&nbsp;[更多...](#osflagserrortimeout) | 
| [osFlagsErrorResource](#osflagserrorresource)&nbsp;&nbsp;&nbsp;0xFFFFFFFDU | 线程标志资源错误。&nbsp;[更多...](#osflagserrorresource) | 
| [osFlagsErrorParameter](#osflagserrorparameter)&nbsp;&nbsp;&nbsp;0xFFFFFFFCU | 线程标志参数错误。&nbsp;[更多...](#osflagserrorparameter) | 
| [osFlagsErrorISR](#osflagserrorisr)&nbsp;&nbsp;&nbsp;0xFFFFFFFAU | 线程标志中断错误。&nbsp;[更多...](#osflagserrorisr) | 
| [osThreadDetached](#osthreaddetached)&nbsp;&nbsp;&nbsp;0x00000000U | 表示线程不可加入状态的宏。&nbsp;[更多...](#osthreaddetached) | 
| [osThreadJoinable](#osthreadjoinable)&nbsp;&nbsp;&nbsp;0x00000001U | 表示线程可加入状态的宏。&nbsp;[更多...](#osthreadjoinable) | 
| [osMutexRecursive](#osmutexrecursive)&nbsp;&nbsp;&nbsp;0x00000001U | 互斥锁递归属性宏，不支持。&nbsp;[更多...](#osmutexrecursive) | 
| [osMutexPrioInherit](#osmutexprioinherit)&nbsp;&nbsp;&nbsp;0x00000002U | 互斥锁优先级继承属性宏，不支持。&nbsp;[更多...](#osmutexprioinherit) | 
| [osMutexRobust](#osmutexrobust)&nbsp;&nbsp;&nbsp;0x00000008U | 互斥锁不自动释放属性宏，不支持。&nbsp;[更多...](#osmutexrobust) | 


### 类型定义

  | 类型定义&nbsp;Name | 描述 | 
| -------- | -------- |
| [osThreadFunc_t](#osthreadfunc_t) | 线程入口类型。&nbsp;[更多...](#osthreadfunc_t) | 
| [osTimerFunc_t](#ostimerfunc_t) | 定时器入口类型。&nbsp;[更多...](#ostimerfunc_t) | 
| [osThreadId_t](#osthreadid_t) | 线程ID类型。&nbsp;[更多...](#osthreadid_t) | 
| [osTimerId_t](#ostimerid_t) | 定时器ID类型。&nbsp;[更多...](#ostimerid_t) | 
| [osEventFlagsId_t](#oseventflagsid_t) | 事件ID类型。&nbsp;[更多...](#oseventflagsid_t) | 
| [osMutexId_t](#osmutexid_t) | 互斥锁ID类型。&nbsp;[更多...](#osmutexid_t) | 
| [osSemaphoreId_t](#ossemaphoreid_t) | 信号量ID类型。&nbsp;[更多...](#ossemaphoreid_t) | 
| [osMemoryPoolId_t](#osmemorypoolid_t) | 内存池ID类型。&nbsp;[更多...](#osmemorypoolid_t) | 
| [osMessageQueueId_t](#osmessagequeueid_t) | 消息队列ID类型。&nbsp;[更多...](#osmessagequeueid_t) | 
| [TZ_ModuleId_t](#tz_moduleid_t) | 线程安全模块ID类型，不支持。&nbsp;[更多...](#tz_moduleid_t) | 


### 枚举

  | 枚举&nbsp;Name | 描述 | 
| -------- | -------- |
| [osKernelState_t](#oskernelstate_t) | 内核状态枚举。&nbsp;[更多...](#oskernelstate_t) | 
| [osThreadState_t](#osthreadstate_t) | 线程状态枚举。&nbsp;[更多...](#osthreadstate_t) | 
| [osPriority_t](#ospriority_t) | 优先级枚举。&nbsp;[更多...](#ospriority_t) | 
| [osTimerType_t](#ostimertype_t) | 定时器类型枚举。&nbsp;[更多...](#ostimertype_t) | 
| [osStatus_t](#osstatus_t) | CMSIS 标准返回值枚举。&nbsp;[更多...](#osstatus_t) | 


### 函数

  | 函数&nbsp;Name | 描述 | 
| -------- | -------- |
| [osKernelInitialize](#oskernelinitialize)&nbsp;(void) | 内核初始化函数。&nbsp;[更多...](#oskernelinitialize) | 
| [osKernelGetInfo](#oskernelgetinfo)&nbsp;([osVersion_t](os_version__t.md)&nbsp;\*version,&nbsp;char&nbsp;\*id_buf,&nbsp;uint32_t&nbsp;id_size) | 获取内核信息函数。&nbsp;[更多...](#oskernelgetinfo) | 
| [osKernelGetState](#oskernelgetstate)&nbsp;(void) | 获取内核状态。&nbsp;[更多...](#oskernelgetstate) | 
| [osKernelStart](#oskernelstart)&nbsp;(void) | 内核启动函数。&nbsp;[更多...](#oskernelstart) | 
| [osKernelLock](#oskernellock)&nbsp;(void) | 内核调度锁定函数。&nbsp;[更多...](#oskernellock) | 
| [osKernelUnlock](#oskernelunlock)&nbsp;(void) | 内核调度解锁函数。&nbsp;[更多...](#oskernelunlock) | 
| [osKernelRestoreLock](#oskernelrestorelock)&nbsp;(int32_t&nbsp;lock) | 内核调度锁恢复函数。&nbsp;[更多...](#oskernelrestorelock) | 
| [osKernelSuspend](#oskernelsuspend)&nbsp;(void) | 内核挂起函数，不支持。&nbsp;[更多...](#oskernelsuspend) | 
| [osKernelResume](#oskernelresume)&nbsp;(uint32_t&nbsp;sleep_ticks) | 内核挂起恢复函数，不支持。&nbsp;[更多...](#oskernelresume) | 
| [osKernelGetTickCount](#oskernelgettickcount)&nbsp;(void) | 获取内核tick函数。&nbsp;[更多...](#oskernelgettickcount) | 
| [osKernelGetTickFreq](#oskernelgettickfreq)&nbsp;(void) | 获取内核tick频率函数。&nbsp;[更多...](#oskernelgettickfreq) | 
| [osKernelGetSysTimerCount](#oskernelgetsystimercount)&nbsp;(void) | 获取系统启动后时间。&nbsp;[更多...](#oskernelgetsystimercount) | 
| [osKernelGetSysTimerFreq](#oskernelgetsystimerfreq)&nbsp;(void) | 获取内核cpu&nbsp;cycle频率函数。&nbsp;[更多...](#oskernelgetsystimerfreq) | 
| [osThreadNew](#osthreadnew)&nbsp;([osThreadFunc_t](#osthreadfunc_t)&nbsp;func,&nbsp;void&nbsp;\*argument,&nbsp;const&nbsp;[osThreadAttr_t](os_thread_attr__t.md)&nbsp;\*attr) | 创建线程函数。&nbsp;[更多...](#osthreadnew) | 
| [osThreadGetName](#osthreadgetname)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 获取线程名称函数。&nbsp;[更多...](#osthreadgetname) | 
| [osThreadGetId](#osthreadgetid)&nbsp;(void) | 获取线程ID函数。&nbsp;[更多...](#osthreadgetid) | 
| [osThreadGetState](#osthreadgetstate)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 获取线程状态函数。&nbsp;[更多...](#osthreadgetstate) | 
| [osThreadGetStackSize](#osthreadgetstacksize)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 获取线程栈大小函数。&nbsp;[更多...](#osthreadgetstacksize) | 
| [osThreadGetStackSpace](#osthreadgetstackspace)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 获取线程栈使用水线函数。&nbsp;[更多...](#osthreadgetstackspace) | 
| [osThreadSetPriority](#osthreadsetpriority)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id,&nbsp;[osPriority_t](#ospriority_t)&nbsp;priority) | 设置线程优先级函数。&nbsp;[更多...](#osthreadsetpriority) | 
| [osThreadGetPriority](#osthreadgetpriority)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 获取线程优先级函数。&nbsp;[更多...](#osthreadgetpriority) | 
| [osThreadYield](#osthreadyield)&nbsp;(void) | 线程调度函数。&nbsp;[更多...](#osthreadyield) | 
| [osThreadSuspend](#osthreadsuspend)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 线程挂起函数。&nbsp;[更多...](#osthreadsuspend) | 
| [osThreadResume](#osthreadresume)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 线程挂起恢复函数。&nbsp;[更多...](#osthreadresume) | 
| [osThreadDetach](#osthreaddetach)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 线程分离函数。&nbsp;[更多...](#osthreaddetach) | 
| [osThreadJoin](#osthreadjoin)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 等待指定线程终止函数。&nbsp;[更多...](#osthreadjoin) | 
| [osThreadExit](#osthreadexit)&nbsp;(void) | 当前线程退出函数。&nbsp;[更多...](#osthreadexit) | 
| [osThreadTerminate](#osthreadterminate)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id) | 指定线程终止函数。&nbsp;[更多...](#osthreadterminate) | 
| [osThreadGetCount](#osthreadgetcount)&nbsp;(void) | 获取使用中的线程数量。&nbsp;[更多...](#osthreadgetcount) | 
| [osThreadEnumerate](#osthreadenumerate)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;\*thread_array,&nbsp;uint32_t&nbsp;array_items) | 获取活动线程枚举，不支持。&nbsp;[更多...](#osthreadenumerate) | 
| [osThreadFlagsSet](#osthreadflagsset)&nbsp;([osThreadId_t](#osthreadid_t)&nbsp;thread_id,&nbsp;uint32_t&nbsp;flags) | 设置线程的指定线程标志。&nbsp;[更多...](#osthreadflagsset) | 
| [osThreadFlagsClear](#osthreadflagsclear)&nbsp;(uint32_t&nbsp;flags) | 清除线程的指定线程标志。&nbsp;[更多...](#osthreadflagsclear) | 
| [osThreadFlagsGet](#osthreadflagsget)&nbsp;(void) | 获取线程的线程标志。&nbsp;[更多...](#osthreadflagsget) | 
| [osThreadFlagsWait](#osthreadflagswait)&nbsp;(uint32_t&nbsp;flags,&nbsp;uint32_t&nbsp;options,&nbsp;uint32_t&nbsp;timeout) | 等待指定线程标志。&nbsp;[更多...](#osthreadflagswait) | 
| [osDelay](#osdelay)&nbsp;(uint32_t&nbsp;ticks) | 延时等待函数。&nbsp;[更多...](#osdelay) | 
| [osDelayUntil](#osdelayuntil)&nbsp;(uint32_t&nbsp;ticks) | 指定到期时间的延时等待函数。&nbsp;[更多...](#osdelayuntil) | 
| [osTimerNew](#ostimernew)&nbsp;([osTimerFunc_t](#ostimerfunc_t)&nbsp;func,&nbsp;[osTimerType_t](#ostimertype_t)&nbsp;type,&nbsp;void&nbsp;\*argument,&nbsp;const&nbsp;[osTimerAttr_t](os_timer_attr__t.md)&nbsp;\*attr) | 定时器创建函数。&nbsp;[更多...](#ostimernew) | 
| [osTimerGetName](#ostimergetname)&nbsp;([osTimerId_t](#ostimerid_t)&nbsp;timer_id) | 获取定时器名称函数。&nbsp;[更多...](#ostimergetname) | 
| [osTimerStart](#ostimerstart)&nbsp;([osTimerId_t](#ostimerid_t)&nbsp;timer_id,&nbsp;uint32_t&nbsp;ticks) | 定时器开始运行函数。&nbsp;[更多...](#ostimerstart) | 
| [osTimerStop](#ostimerstop)&nbsp;([osTimerId_t](#ostimerid_t)&nbsp;timer_id) | 定时器停止运行函数。&nbsp;[更多...](#ostimerstop) | 
| [osTimerIsRunning](#ostimerisrunning)&nbsp;([osTimerId_t](#ostimerid_t)&nbsp;timer_id) | 定时器状态查询函数。&nbsp;[更多...](#ostimerisrunning) | 
| [osTimerDelete](#ostimerdelete)&nbsp;([osTimerId_t](#ostimerid_t)&nbsp;timer_id) | 定时器删除函数。&nbsp;[更多...](#ostimerdelete) | 
| [osEventFlagsNew](#oseventflagsnew)&nbsp;(const&nbsp;[osEventFlagsAttr_t](os_event_flags_attr__t.md)&nbsp;\*attr) | 事件初始化函数。&nbsp;[更多...](#oseventflagsnew) | 
| [osEventFlagsGetName](#oseventflagsgetname)&nbsp;([osEventFlagsId_t](#oseventflagsid_t)&nbsp;ef_id) | 获取事件名称函数。&nbsp;[更多...](#oseventflagsgetname) | 
| [osEventFlagsSet](#oseventflagsset)&nbsp;([osEventFlagsId_t](#oseventflagsid_t)&nbsp;ef_id,&nbsp;uint32_t&nbsp;flags) | 设置事件标志函数。&nbsp;[更多...](#oseventflagsset) | 
| [osEventFlagsClear](#oseventflagsclear)&nbsp;([osEventFlagsId_t](#oseventflagsid_t)&nbsp;ef_id,&nbsp;uint32_t&nbsp;flags) | 清除事件标志函数。&nbsp;[更多...](#oseventflagsclear) | 
| [osEventFlagsGet](#oseventflagsget)&nbsp;([osEventFlagsId_t](#oseventflagsid_t)&nbsp;ef_id) | 获取事件标志函数。&nbsp;[更多...](#oseventflagsget) | 
| [osEventFlagsWait](#oseventflagswait)&nbsp;([osEventFlagsId_t](#oseventflagsid_t)&nbsp;ef_id,&nbsp;uint32_t&nbsp;flags,&nbsp;uint32_t&nbsp;options,&nbsp;uint32_t&nbsp;timeout) | 事件标志等待函数。&nbsp;[更多...](#oseventflagswait) | 
| [osEventFlagsDelete](#oseventflagsdelete)&nbsp;([osEventFlagsId_t](#oseventflagsid_t)&nbsp;ef_id) | 事件删除函数。&nbsp;[更多...](#oseventflagsdelete) | 
| [osMutexNew](#osmutexnew)&nbsp;(const&nbsp;[osMutexAttr_t](os_mutex_attr__t.md)&nbsp;\*attr) | 互斥锁初始化函数。&nbsp;[更多...](#osmutexnew) | 
| [osMutexGetName](#osmutexgetname)&nbsp;([osMutexId_t](#osmutexid_t)&nbsp;mutex_id) | 获取互斥锁名称函数，不支持。&nbsp;[更多...](#osmutexgetname) | 
| [osMutexAcquire](#osmutexacquire)&nbsp;([osMutexId_t](#osmutexid_t)&nbsp;mutex_id,&nbsp;uint32_t&nbsp;timeout) | 获取互斥锁函数。&nbsp;[更多...](#osmutexacquire) | 
| [osMutexRelease](#osmutexrelease)&nbsp;([osMutexId_t](#osmutexid_t)&nbsp;mutex_id) | 释放互斥锁函数。&nbsp;[更多...](#osmutexrelease) | 
| [osMutexGetOwner](#osmutexgetowner)&nbsp;([osMutexId_t](#osmutexid_t)&nbsp;mutex_id) | 获取互斥锁所有者函数。&nbsp;[更多...](#osmutexgetowner) | 
| [osMutexDelete](#osmutexdelete)&nbsp;([osMutexId_t](#osmutexid_t)&nbsp;mutex_id) | 互斥锁删除函数。&nbsp;[更多...](#osmutexdelete) | 
| [osSemaphoreNew](#ossemaphorenew)&nbsp;(uint32_t&nbsp;max_count,&nbsp;uint32_t&nbsp;initial_count,&nbsp;const&nbsp;[osSemaphoreAttr_t](os_semaphore_attr__t.md)&nbsp;\*attr) | 信号量初始化函数。&nbsp;[更多...](#ossemaphorenew) | 
| [osSemaphoreGetName](#ossemaphoregetname)&nbsp;([osSemaphoreId_t](#ossemaphoreid_t)&nbsp;semaphore_id) | 获取信号量名称函数。&nbsp;[更多...](#ossemaphoregetname) | 
| [osSemaphoreAcquire](#ossemaphoreacquire)&nbsp;([osSemaphoreId_t](#ossemaphoreid_t)&nbsp;semaphore_id,&nbsp;uint32_t&nbsp;timeout) | 获取信号量函数。&nbsp;[更多...](#ossemaphoreacquire) | 
| [osSemaphoreRelease](#ossemaphorerelease)&nbsp;([osSemaphoreId_t](#ossemaphoreid_t)&nbsp;semaphore_id) | 释放信号量函数。&nbsp;[更多...](#ossemaphorerelease) | 
| [osSemaphoreGetCount](#ossemaphoregetcount)&nbsp;([osSemaphoreId_t](#ossemaphoreid_t)&nbsp;semaphore_id) | 获取信号量状态量函数。&nbsp;[更多...](#ossemaphoregetcount) | 
| [osSemaphoreDelete](#ossemaphoredelete)&nbsp;([osSemaphoreId_t](#ossemaphoreid_t)&nbsp;semaphore_id) | 信号量删除函数。&nbsp;[更多...](#ossemaphoredelete) | 
| [osMemoryPoolNew](#osmemorypoolnew)&nbsp;(uint32_t&nbsp;block_count,&nbsp;uint32_t&nbsp;block_size,&nbsp;const&nbsp;[osMemoryPoolAttr_t](os_memory_pool_attr__t.md)&nbsp;\*attr) | 内存池初始化函数。&nbsp;[更多...](#osmemorypoolnew) | 
| [osMemoryPoolGetName](#osmemorypoolgetname)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id) | 获取内存池名称函数。&nbsp;[更多...](#osmemorypoolgetname) | 
| [osMemoryPoolAlloc](#osmemorypoolalloc)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id,&nbsp;uint32_t&nbsp;timeout) | 申请内存函数。&nbsp;[更多...](#osmemorypoolalloc) | 
| [osMemoryPoolFree](#osmemorypoolfree)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id,&nbsp;void&nbsp;\*block) | 释放内存函数。&nbsp;[更多...](#osmemorypoolfree) | 
| [osMemoryPoolGetCapacity](#osmemorypoolgetcapacity)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id) | 获取内存池拥有块数量函数。&nbsp;[更多...](#osmemorypoolgetcapacity) | 
| [osMemoryPoolGetBlockSize](#osmemorypoolgetblocksize)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id) | 获取内存池块大小函数。&nbsp;[更多...](#osmemorypoolgetblocksize) | 
| [osMemoryPoolGetCount](#osmemorypoolgetcount)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id) | 获取内存池块使用块函数。&nbsp;[更多...](#osmemorypoolgetcount) | 
| [osMemoryPoolGetSpace](#osmemorypoolgetspace)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id) | 获取内存池剩余块函数。&nbsp;[更多...](#osmemorypoolgetspace) | 
| [osMemoryPoolDelete](#osmemorypooldelete)&nbsp;([osMemoryPoolId_t](#osmemorypoolid_t)&nbsp;mp_id) | 删除内存池函数。&nbsp;[更多...](#osmemorypooldelete) | 
| [osMessageQueueNew](#osmessagequeuenew)&nbsp;(uint32_t&nbsp;msg_count,&nbsp;uint32_t&nbsp;msg_size,&nbsp;const&nbsp;[osMessageQueueAttr_t](os_message_queue_attr__t.md)&nbsp;\*attr) | 消息队列初始化函数。&nbsp;[更多...](#osmessagequeuenew) | 
| [osMessageQueueGetName](#osmessagequeuegetname)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id) | 获取消息队列名称函数。&nbsp;[更多...](#osmessagequeuegetname) | 
| [osMessageQueuePut](#osmessagequeueput)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id,&nbsp;const&nbsp;void&nbsp;\*msg_ptr,&nbsp;uint8_t&nbsp;msg_prio,&nbsp;uint32_t&nbsp;timeout) | 消息队列发送消息函数。&nbsp;[更多...](#osmessagequeueput) | 
| [osMessageQueueGet](#osmessagequeueget)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id,&nbsp;void&nbsp;\*msg_ptr,&nbsp;uint8_t&nbsp;\*msg_prio,&nbsp;uint32_t&nbsp;timeout) | 消息队列接收消息函数。&nbsp;[更多...](#osmessagequeueget) | 
| [osMessageQueueGetCapacity](#osmessagequeuegetcapacity)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id) | 获取消息队列最大节点数函数。&nbsp;[更多...](#osmessagequeuegetcapacity) | 
| [osMessageQueueGetMsgSize](#osmessagequeuegetmsgsize)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id) | 获取消息队列节点大小函数。&nbsp;[更多...](#osmessagequeuegetmsgsize) | 
| [osMessageQueueGetCount](#osmessagequeuegetcount)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id) | 获取消息队列待读节点数量函数。&nbsp;[更多...](#osmessagequeuegetcount) | 
| [osMessageQueueGetSpace](#osmessagequeuegetspace)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id) | 获取消息队列剩余可用节点数量函数。&nbsp;[更多...](#osmessagequeuegetspace) | 
| [osMessageQueueReset](#osmessagequeuereset)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id) | 消息队列重置函数，不支持。&nbsp;[更多...](#osmessagequeuereset) | 
| [osMessageQueueDelete](#osmessagequeuedelete)&nbsp;([osMessageQueueId_t](#osmessagequeueid_t)&nbsp;mq_id) | 删除消息队列函数。&nbsp;[更多...](#osmessagequeuedelete) | 


## **详细描述**


## **宏定义说明**


### osFlagsError


```
#define osFlagsError   0x80000000U
```

**描述:**

标志相关函数最高位错误，不支持。


### osFlagsErrorISR


```
#define osFlagsErrorISR   0xFFFFFFFAU
```

**描述:**

线程标志中断错误。


### osFlagsErrorParameter


```
#define osFlagsErrorParameter   0xFFFFFFFCU
```

**描述:**

线程标志参数错误。


### osFlagsErrorResource


```
#define osFlagsErrorResource   0xFFFFFFFDU
```

**描述:**

线程标志资源错误。


### osFlagsErrorTimeout


```
#define osFlagsErrorTimeout   0xFFFFFFFEU
```

**描述:**

线程标志超时错误。


### osFlagsErrorUnknown


```
#define osFlagsErrorUnknown   0xFFFFFFFFU
```

**描述:**

线程标志未知错误。


### osFlagsNoClear


```
#define osFlagsNoClear   0x00000002U
```

**描述:**

不清除指定等待标志。

该宏用于标志相关函数中设置触发的方式。


### osFlagsWaitAll


```
#define osFlagsWaitAll   0x00000001U
```

**描述:**

等待全部标志触发。

该宏用于标志相关函数中设置触发的方式。


### osFlagsWaitAny


```
#define osFlagsWaitAny   0x00000000U
```

**描述:**

等待任何标志触发。

该宏用于标志相关函数中设置触发的方式。


### osMutexPrioInherit


```
#define osMutexPrioInherit   0x00000002U
```

**描述:**

互斥锁优先级继承属性宏，不支持。


### osMutexRecursive


```
#define osMutexRecursive   0x00000001U
```

**描述:**

互斥锁递归属性宏，不支持。


### osMutexRobust


```
#define osMutexRobust   0x00000008U
```

**描述:**

互斥锁不自动释放属性宏，不支持。


### osThreadDetached


```
#define osThreadDetached   0x00000000U
```

**描述:**

表示线程不可加入状态的宏。

该宏表示无法使用[osThreadJoin](#osthreadjoin)加入处于此状态的线程。


### osThreadJoinable


```
#define osThreadJoinable   0x00000001U
```

**描述:**

表示线程可加入状态的宏。

该宏表示可以使用[osThreadJoin](#osthreadjoin)加入处于这种状态的线程。


### osWaitForever


```
#define osWaitForever   0xFFFFFFFFU
```

**描述:**

该宏表示系统永久等待，直到资源变得可用。

## **类型定义说明**


### osEventFlagsId_t


```
typedef void* osEventFlagsId_t
```

**描述:**

事件ID类型。

该类型用于识别不同事件。


### osMemoryPoolId_t


```
typedef void* osMemoryPoolId_t
```

**描述:**

内存池ID类型。

该类型用于识别不同内存池。


### osMessageQueueId_t


```
typedef void* osMessageQueueId_t
```

**描述:**

消息队列ID类型。

该类型用于识别不同消息队列。


### osMutexId_t


```
typedef void* osMutexId_t
```

**描述:**

互斥锁ID类型。

该类型用于识别不同互斥锁。


### osSemaphoreId_t


```
typedef void* osSemaphoreId_t
```

**描述:**

信号量ID类型。

该类型用于识别不同信号量。


### osThreadFunc_t


```
typedef void(* osThreadFunc_t) (void *argument)
```

**描述:**

线程入口类型。

该类型用于线程调度时回调。


### osThreadId_t


```
typedef void* osThreadId_t
```

**描述:**

线程ID类型。

该类型用于识别不同线程。


### osTimerFunc_t


```
typedef void(* osTimerFunc_t) (void *argument)
```

**描述:**

定时器入口类型。

该类型用于定时器触发时回调。


### osTimerId_t


```
typedef void* osTimerId_t
```

**描述:**

定时器ID类型。

该类型用于识别不同定时器。


### TZ_ModuleId_t


```
typedef uint32_t TZ_ModuleId_t
```

**描述:**

线程安全模块ID类型，不支持。


## **枚举类型说明**


### osKernelState_t


```
enum osKernelState_t
```

**描述:**

内核状态枚举。

该枚举用于描述内核的运行状态。

  | 枚举值 | 描述 | 
| -------- | -------- |
| osKernelInactive | 内核未启动 | 
| osKernelReady | 内核就绪 | 
| osKernelRunning | 内核运行中 | 
| osKernelLocked | 内核锁定 | 
| osKernelSuspended | 内核挂起 | 
| osKernelError | 内核异常 | 
| osKernelReserved | 保留的状态，用于阻止编译器对枚举进行优化 | 


### osPriority_t


```
enum osPriority_t
```

**描述:**

优先级枚举。

该枚举用于描述各级别优先级。

  | 枚举值 | 描述 | 
| -------- | -------- |
| osPriorityNone | 未初始化的优先级 | 
| osPriorityIdle | 为空闲线程保留的最低优先级，非空闲线程不能使用该优先级 | 
| osPriorityLow | 低优先级，这是非空闲线程当前版本可使用的最低优先级 | 
| osPriorityLow1 | 低优先级&nbsp;+&nbsp;1 | 
| osPriorityLow2 | 低优先级&nbsp;+&nbsp;2 | 
| osPriorityLow3 | 低优先级&nbsp;+&nbsp;3 | 
| osPriorityLow4 | 低优先级&nbsp;+&nbsp;4 | 
| osPriorityLow5 | 低优先级&nbsp;+&nbsp;5 | 
| osPriorityLow6 | 低优先级&nbsp;+&nbsp;6 | 
| osPriorityLow7 | 低优先级&nbsp;+&nbsp;7 | 
| osPriorityBelowNormal | 比普通等级稍低的优先级 | 
| osPriorityBelowNormal1 | 比普通等级稍低的优先级&nbsp;+&nbsp;1 | 
| osPriorityBelowNormal2 | 比普通等级稍低的优先级&nbsp;+&nbsp;2 | 
| osPriorityBelowNormal3 | 比普通等级稍低的优先级&nbsp;+&nbsp;3 | 
| osPriorityBelowNormal4 | 比普通等级稍低的优先级&nbsp;+&nbsp;4 | 
| osPriorityBelowNormal5 | 比普通等级稍低的优先级&nbsp;+&nbsp;5 | 
| osPriorityBelowNormal6 | 比普通等级稍低的优先级&nbsp;+&nbsp;6 | 
| osPriorityBelowNormal7 | 比普通等级稍低的优先级&nbsp;+&nbsp;7 | 
| osPriorityNormal | 普通优先级 | 
| osPriorityNormal1 | 普通优先级&nbsp;+&nbsp;1 | 
| osPriorityNormal2 | 普通优先级&nbsp;+&nbsp;2 | 
| osPriorityNormal3 | 普通优先级&nbsp;+&nbsp;3 | 
| osPriorityNormal4 | 普通优先级&nbsp;+&nbsp;4 | 
| osPriorityNormal5 | 普通优先级&nbsp;+&nbsp;5 | 
| osPriorityNormal6 | 普通优先级&nbsp;+&nbsp;6 | 
| osPriorityNormal7 | 普通优先级&nbsp;+&nbsp;7 | 
| osPriorityAboveNormal | 比普通等级稍高的优先级 | 
| osPriorityAboveNormal1 | 比普通等级稍高的优先级&nbsp;+&nbsp;1，这是当前版本可用的最高优先级 | 
| osPriorityAboveNormal2 | 比普通等级稍高的优先级&nbsp;+&nbsp;2 | 
| osPriorityAboveNormal3 | 比普通等级稍高的优先级&nbsp;+&nbsp;3 | 
| osPriorityAboveNormal4 | 比普通等级稍高的优先级&nbsp;+&nbsp;4 | 
| osPriorityAboveNormal5 | 比普通等级稍高的优先级&nbsp;+&nbsp;5 | 
| osPriorityAboveNormal6 | 比普通等级稍高的优先级&nbsp;+&nbsp;6 | 
| osPriorityAboveNormal7 | 比普通等级稍高的优先级&nbsp;+&nbsp;7 | 
| osPriorityHigh | 高优先级 | 
| osPriorityHigh1 | 高优先级&nbsp;+&nbsp;1 | 
| osPriorityHigh2 | 高优先级&nbsp;+&nbsp;2 | 
| osPriorityHigh3 | 高优先级&nbsp;+&nbsp;3 | 
| osPriorityHigh4 | 高优先级&nbsp;+&nbsp;4 | 
| osPriorityHigh5 | 高优先级&nbsp;+&nbsp;5 | 
| osPriorityHigh6 | 高优先级&nbsp;+&nbsp;6 | 
| osPriorityHigh7 | 高优先级&nbsp;+&nbsp;7 | 
| osPriorityRealtime | 实时优先级 | 
| osPriorityRealtime1 | 实时优先级&nbsp;+&nbsp;1 | 
| osPriorityRealtime2 | 实时优先级&nbsp;+&nbsp;2 | 
| osPriorityRealtime3 | 实时优先级&nbsp;+&nbsp;3 | 
| osPriorityRealtime4 | 实时优先级&nbsp;+&nbsp;4 | 
| osPriorityRealtime5 | 实时优先级&nbsp;+&nbsp;5 | 
| osPriorityRealtime6 | 实时优先级&nbsp;+&nbsp;6 | 
| osPriorityRealtime7 | 实时优先级&nbsp;+&nbsp;7 | 
| osPriorityISR | 为ISR（interrupt&nbsp;service&nbsp;routine，中断服务程序）保留的优先级 | 
| osPriorityError | 非法的优先级 | 
| osPriorityReserved | 保留的优先级，用于阻止编译器对枚举进行优化 | 


### osStatus_t


```
enum osStatus_t
```

**描述:**

CMSIS接口标准返回值枚举。

  | 枚举值 | 描述 | 
| -------- | -------- |
| osOK | 操作成功 | 
| osError | 未特别说明的错误 | 
| osErrorTimeout | 超时错误 | 
| osErrorResource | 资源错误 | 
| osErrorParameter | 参数错误 | 
| osErrorNoMemory | 内存不足 | 
| osErrorISR | 中断服务错误 | 
| osStatusReserved | 保留的定义，用于阻止编译器对枚举进行优化 | 


### osThreadState_t


```
enum osThreadState_t
```

**描述:**

线程状态枚举。

该枚举用于描述线程的运行状态。

  | 枚举值 | 描述 | 
| -------- | -------- |
| osThreadInactive | 线程未运行 | 
| osThreadReady | 线程就绪 | 
| osThreadRunning | 线程运行中 | 
| osThreadBlocked | 线程阻塞 | 
| osThreadTerminated | 线程结束 | 
| osThreadError | 线程异常 | 
| osThreadReserved | 保留的状态，用于阻止编译器对枚举进行优化 | 


### osTimerType_t


```
enum osTimerType_t
```

**描述:**

定时器类型枚举。

该枚举用于定义定时器的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| osTimerOnce | 单次触发定时器 | 
| osTimerPeriodic | 重复触发定时器 | 


## **函数说明**


### osDelay


```
osStatus_t osDelay (uint32_t ticks)
```

**描述:**

延时等待函数。

用于把本线程置于挂起状态并立即发生上下文切换。开发者可自行提供硬件延时函数VOID HalDelay(UINT32 ticks)，即可在系统未运行时执行本函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ticks | 任务延时的tick数。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osDelayUntil


```
osStatus_t osDelayUntil (uint32_t ticks)
```

**描述:**

指定到期时间的延时等待函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ticks | 绝对时间，不能小于当前时间。 | 

**返回:**

osOK，表示执行成功。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osEventFlagsClear


```
uint32_t osEventFlagsClear (osEventFlagsId_t ef_id, uint32_t flags)
```

**描述:**

清除事件标志函数。

用于清除指定的事件标志，并返回清除前的事件标志。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ef_id | 定时器ID（由[osEventFlagsNew](#oseventflagsnew)创建）。 | 
| flags | 待清除标志。 | 

**返回:**

成功，返回清除前的事件标志。

osFlagsErrorParameter，表示参数错误。

osFlagsErrorResource，表示其他错误。


### osEventFlagsDelete


```
osStatus_t osEventFlagsDelete (osEventFlagsId_t ef_id)
```

**描述:**

事件删除函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ef_id | 定时器ID（由[osEventFlagsNew](#oseventflagsnew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorISR，表示在中断中调用本函数。


### osEventFlagsGet


```
uint32_t osEventFlagsGet (osEventFlagsId_t ef_id)
```

**描述:**

获取事件标志函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ef_id | 定时器ID（由[osEventFlagsNew](#oseventflagsnew)创建）。 | 

**返回:**

成功，返回当前事件标志数值。

0，表示执行失败。


### osEventFlagsGetName


```
const char* osEventFlagsGetName (osEventFlagsId_t ef_id)
```

**描述:**

获取事件名称函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ef_id | 定时器ID（由[osEventFlagsNew](#oseventflagsnew)创建）。 | 

**返回:**

当前只能返回NULL。


### osEventFlagsNew


```
osEventFlagsId_t osEventFlagsNew (const osEventFlagsAttr_t * attr)
```

**描述:**

事件初始化函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| attr | 事件参数，当前不支持该参数，参数可为NULL。 | 

**返回:**

成功，返回创建的事件ID。

NULL，表示执行失败或在中断中调用该函数。


### osEventFlagsSet


```
uint32_t osEventFlagsSet (osEventFlagsId_t ef_id, uint32_t flags)
```

**描述:**

设置事件标志函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ef_id | 定时器ID（由[osEventFlagsNew](#oseventflagsnew)创建）。 | 
| flags | 待设置标志，第25位不能设置为1。 | 

**返回:**

成功，返回设置后的标志。

osFlagsErrorParameter，表示参数错误。

osFlagsErrorResource，表示其他问题。


### osEventFlagsWait


```
uint32_t osEventFlagsWait (osEventFlagsId_t ef_id, uint32_t flags, uint32_t options, uint32_t timeout)
```

**描述:**

事件标志等待函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| ef_id | 定时器ID（由[osEventFlagsNew](#oseventflagsnew)创建）。 | 
| flags | 等待的标志，第25位不能设置为1。 | 
| options | 等待设置，仅限于osFlagsWaitAny&nbsp;\|&nbsp;osFlagsWaitAll&nbsp;\|&nbsp;osFlagsNoClear。 | 
| timeout | 超时时间，单位：tick。 | 

**返回:**

成功，返回等到的标志，内容与参数options设置有关。

osFlagsErrorParameter，表示参数错误或中断中调用该函数。

osFlagsErrorTimeout，表示超时错误。

osFlagsErrorResource，表示其他问题。


### osKernelGetInfo


```
osStatus_t osKernelGetInfo (osVersion_t * version, char * id_buf, uint32_t id_size)
```

**描述:**

获取内核信息函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| version | 指向获取版本信息缓冲区的指针。 | 
| id_buf | 指向获取内核版本缓冲区的指针。 | 
| id_size | 用于获取内核版本缓冲区的大小，单位字节。 | 

**返回:**

osOK，表示执行成功。

osError，表示其他错误。


### osKernelGetState


```
osKernelState_t osKernelGetState (void)
```

**描述:**

获取内核状态。

**返回:**

返回系统状态的枚举值。


### osKernelGetSysTimerCount


```
uint32_t osKernelGetSysTimerCount (void)
```

**描述:**

获取系统启动后时间。

**返回:**

返回启动后的时间（单位: cycle）。


### osKernelGetSysTimerFreq


```
uint32_t osKernelGetSysTimerFreq (void)
```

**描述:**

获取内核cpu cycle频率函数。

**返回:**

返回每秒cycle数（单位: cycle）。


### osKernelGetTickCount


```
uint32_t osKernelGetTickCount (void)
```

**描述:**

获取内核tick函数。

**返回:**

返回当前的tick。


### osKernelGetTickFreq


```
uint32_t osKernelGetTickFreq (void)
```

**描述:**

获取内核tick频率函数。

**返回:**

返回每秒的tick数。


### osKernelInitialize


```
osStatus_t osKernelInitialize (void)
```

**描述:**

内核初始化函数。

初始化实时操作系统内核，大部分接口无法在初始化之前使用。

**返回:**

osOK，表示执行成功。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osKernelLock


```
int32_t osKernelLock (void)
```

**描述:**

内核调度锁定函数。

**返回:**

成功，返回前一次的锁定状态（1为锁定，0为未锁定）。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osKernelRestoreLock


```
int32_t osKernelRestoreLock (int32_t lock)
```

**描述:**

内核调度锁恢复函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| lock | 待恢复的锁定状态。 | 

**返回:**

成功，返回恢复后的锁定状态（1为锁定，0为未锁定）。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osKernelResume


```
void osKernelResume (uint32_t sleep_ticks)
```

**描述:**

内核挂起恢复函数，不支持。


### osKernelStart


```
osStatus_t osKernelStart (void)
```

**描述:**

内核启动函数。

用于开启内核调度，调度之前需要[osKernelInitialize](#oskernelinitialize)。

**返回:**

osOK，表示执行成功。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osKernelSuspend


```
uint32_t osKernelSuspend (void)
```

**描述:**

内核挂起函数，不支持。


### osKernelUnlock


```
int32_t osKernelUnlock (void)
```

**描述:**

内核调度解锁函数。

**返回:**

成功，返回前一次的锁定状态（1为锁定，0为未锁定）。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osMemoryPoolAlloc


```
void* osMemoryPoolAlloc (osMemoryPoolId_t mp_id, uint32_t timeout)
```

**描述:**

申请内存函数。

用于从内存池中获取到一块内存，该函数不会阻塞。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 
| timeout | 超时时间，当前不支持阻塞，参数不生效。 | 

**返回:**

成功，返回分配内存块的地址。

NULL，表示参数错误或中断中调用本函数。


### osMemoryPoolDelete


```
osStatus_t osMemoryPoolDelete (osMemoryPoolId_t mp_id)
```

**描述:**

删除内存池函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorISR，表示在中断中调用本函数。

osErrorResource，表示其他错误。


### osMemoryPoolFree


```
osStatus_t osMemoryPoolFree (osMemoryPoolId_t mp_id, void * block)
```

**描述:**

释放内存函数。

用于从内存池中释放一块内存。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 
| block | 要释放的块地址。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。


### osMemoryPoolGetBlockSize


```
uint32_t osMemoryPoolGetBlockSize (osMemoryPoolId_t mp_id)
```

**描述:**

获取内存池块大小函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 

**返回:**

成功，返回块大小，单位字节。

0，表示参数错误。


### osMemoryPoolGetCapacity


```
uint32_t osMemoryPoolGetCapacity (osMemoryPoolId_t mp_id)
```

**描述:**

获取内存池拥有块数量函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 

**返回:**

成功，返回块数量。

0，表示参数错误。


### osMemoryPoolGetCount


```
uint32_t osMemoryPoolGetCount (osMemoryPoolId_t mp_id)
```

**描述:**

获取内存池块使用块函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 

**返回:**

成功，返回已使用块数量。

0，表示参数错误。


### osMemoryPoolGetName


```
const char* osMemoryPoolGetName (osMemoryPoolId_t mp_id)
```

**描述:**

获取内存池名称函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 

**返回:**

成功，返回内存池名。

NULL，表示参数错误或中断中调用本函数。


### osMemoryPoolGetSpace


```
uint32_t osMemoryPoolGetSpace (osMemoryPoolId_t mp_id)
```

**描述:**

获取内存池剩余块函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mp_id | 内存池ID（由[osMemoryPoolNew](#osmemorypoolnew)创建）。 | 

**返回:**

成功，返回剩余数量。

0，表示参数错误。


### osMemoryPoolNew


```
osMemoryPoolId_t osMemoryPoolNew (uint32_t block_count, uint32_t block_size, const osMemoryPoolAttr_t * attr)
```

**描述:**

内存池初始化函数。

**参数:**

| Name | 描述 |
| -------- | -------- |
| block_count | 内存池块数。 |
| block_size | 内存池块大小，单位：字节。 |
| attr | 内存池参数，若参数为NULL则使用默认配置。<br/>-&nbsp;attr-&gt;name&nbsp;不支持配置。<br/>-&nbsp;attr-&gt;attr_bits&nbsp;不支持配置。<br/>-&nbsp;attr-&gt;cb_mem不为NULL且attr-&gt;cb_size大于控制块所需大小即可使用外部传入的内存池控制块。&nbsp;内存池控制块必需大小当前为36字节（sizeof(MemPoolCB)，MemPoolCB定义在cmsis_liteos2.c中）。<br/>-&nbsp;attr-&gt;mp_mem，用户指定的内存池指针，指向的地址符合4字节对齐时使用用户指定的内存作为内存池。<br/>-&nbsp;attr-&gt;mp_size，用户指定的内存大小，使用用户指定内存作为内存池时，需配置为不小于内存池所有节点所需的空间。 |

**返回:**

成功，返回内存池ID。

NULL，表示参数错误或中断中调用本函数。


### osMessageQueueDelete


```
osStatus_t osMessageQueueDelete (osMessageQueueId_t mq_id)
```

**描述:**

删除消息队列函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。


### osMessageQueueGet


```
osStatus_t osMessageQueueGet (osMessageQueueId_t mq_id, void * msg_ptr, uint8_t * msg_prio, uint32_t timeout)
```

**描述:**

消息队列接收消息函数。

用于把消息队列中读取一条消息，当前不支持消息优先级。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 
| msg_ptr | 指向缓冲区的指针，获取到的数据会拷贝到该缓冲区。 | 
| msg_prio | 消息优先级，当前不支持该参数。 | 
| timeout | 超时时间，单位：tick。在中断中调用时必须设置为0。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorTimeout，表示超时错误。


### osMessageQueueGetCapacity


```
uint32_t osMessageQueueGetCapacity (osMessageQueueId_t mq_id)
```

**描述:**

获取消息队列最大节点数函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 

**返回:**

成功，返回队列最大节点数。

0，表示参数错误。


### osMessageQueueGetCount


```
uint32_t osMessageQueueGetCount (osMessageQueueId_t mq_id)
```

**描述:**

获取消息队列待读节点数量函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 

**返回:**

成功，返回待读节点数量。

0，表示参数错误。


### osMessageQueueGetMsgSize


```
uint32_t osMessageQueueGetMsgSize (osMessageQueueId_t mq_id)
```

**描述:**

获取消息队列节点大小函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 

**返回:**

成功，返回队列节点大小，单位: 字节。

0，表示参数错误。


### osMessageQueueGetName


```
const char* osMessageQueueGetName (osMessageQueueId_t mq_id)
```

**描述:**

获取消息队列名称函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 

**返回:**

成功，返回消息队列名。

NULL，表示参数错误或未设置队列名。


### osMessageQueueGetSpace


```
uint32_t osMessageQueueGetSpace (osMessageQueueId_t mq_id)
```

**描述:**

获取消息队列剩余可用节点数量函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 

**返回:**

成功，返回剩余可用节点数量。

0，表示参数错误。


### osMessageQueueNew


```
osMessageQueueId_t osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osMessageQueueAttr_t * attr)
```

**描述:**

消息队列初始化函数。

用于初始化消息队列，使用外部内存做队列空间时，需提前打开内核编译选项 LOSCFG_BASE_IPC_QUEUE_STATIC。

**参数:**

| Name | 描述 |
| -------- | -------- |
| msg_count | 队列的节点数量。 |
| msg_size | 队列的单个节点空间大小，单位:&nbsp;字节，使用用户指定内存做队列空间时该参数不生效但不可设置为0。 |
| attr | 队列参数，若参数为NULL则使用默认配置。<br/>-&nbsp;attr-&gt;name&nbsp;入参可为NULL，若传递非NULL时需确保传递一个常量。<br/>-&nbsp;attr-&gt;attr_bits&nbsp;不支持配置。<br/>-&nbsp;attr-&gt;cb_mem&nbsp;不支持配置。<br/>-&nbsp;attr-&gt;cb_size&nbsp;不支持配置。<br/>-&nbsp;attr-&gt;mq_mem 用户指定内存指针做为队列空间，为NULL则内存由系统自动分配。<br/>-&nbsp;attr-&gt;mq_size 用户指定内存大小，由单个节点大小和节点数量相乘获得。 |

**返回:**

成功，返回消息队列ID。

NULL，表示参数错误或中断中调用本函数。


### osMessageQueuePut


```
osStatus_t osMessageQueuePut (osMessageQueueId_t mq_id, const void * msg_ptr, uint8_t msg_prio, uint32_t timeout)
```

**描述:**

消息队列发送消息函数。

用于把消息插入队列中，当前不支持消息优先级，新消息会在队列尾部。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mq_id | 消息队列ID（由[osMessageQueueNew](#osmessagequeuenew)创建）。 | 
| msg_ptr | 指向缓冲区的指针，数据会拷贝到消息队列中。 | 
| msg_prio | 消息优先级，当前不支持该参数。 | 
| timeout | 超时时间，单位：tick。在中断中调用时必须设置为0。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorTimeout，表示超时错误。


### osMessageQueueReset


```
osStatus_t osMessageQueueReset (osMessageQueueId_t mq_id)
```

**描述:**

消息队列重置函数，不支持。


### osMutexAcquire


```
osStatus_t osMutexAcquire (osMutexId_t mutex_id, uint32_t timeout)
```

**描述:**

获取互斥锁函数。

会阻塞线程运行直到获取互斥锁成功或超时。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mutex_id | 互斥锁ID（由[osMutexNew](#osmutexnew)创建）。 | 
| timeout | 互斥锁获取超时时间，单位：tick。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。

osErrorTimeout，表示超时错误。


### osMutexDelete


```
osStatus_t osMutexDelete (osMutexId_t mutex_id)
```

**描述:**

互斥锁删除函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mutex_id | 互斥锁ID（由[osMutexNew](#osmutexnew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。


### osMutexGetName


```
const char* osMutexGetName (osMutexId_t mutex_id)
```

**描述:**

获取互斥锁名称函数，不支持。


### osMutexGetOwner


```
osThreadId_t osMutexGetOwner (osMutexId_t mutex_id)
```

**描述:**

获取互斥锁所有者函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mutex_id | 互斥锁ID（由[osMutexNew](#osmutexnew)创建）。 | 

**返回:**

成功，返回线程ID。

NULL，表示参数错误或中断中调用本函数。


### osMutexNew


```
osMutexId_t osMutexNew (const osMutexAttr_t * attr)
```

**描述:**

互斥锁初始化函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| attr | 互斥锁参数，当前内部未使用该参数，参数可为NULL。 | 

**返回:**

成功，返回互斥锁ID。

NULL，执行失败或在中断中调用该函数。


### osMutexRelease


```
osStatus_t osMutexRelease (osMutexId_t mutex_id)
```

**描述:**

释放互斥锁函数。

等待该互斥锁的线程会从阻塞中恢复。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| mutex_id | 互斥锁ID（由[osMutexNew](#osmutexnew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。


### osSemaphoreAcquire


```
osStatus_t osSemaphoreAcquire (osSemaphoreId_t semaphore_id, uint32_t timeout)
```

**描述:**

获取信号量函数。

会阻塞线程运行直到获取信号量成功或超时。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| semaphore_id | 信号量ID（由[osSemaphoreNew](#ossemaphorenew)创建）。 | 
| timeout | 超时时间，单位：tick。在中断中调用时必须设置为0。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorTimeout，表示超时错误。


### osSemaphoreDelete


```
osStatus_t osSemaphoreDelete (osSemaphoreId_t semaphore_id)
```

**描述:**

信号量删除函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| semaphore_id | 信号量ID（由[osSemaphoreNew](#ossemaphorenew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误或中断中调用本函数。

osErrorResource，表示其他错误。


### osSemaphoreGetCount


```
uint32_t osSemaphoreGetCount (osSemaphoreId_t semaphore_id)
```

**描述:**

获取信号量可用数量。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| semaphore_id | 信号量ID（由[osSemaphoreNew](#ossemaphorenew)创建）。 | 

**返回:**

成功，返回当前可用信号量数量。

０，表示执行失败或当执行成功但无可用信号量。


### osSemaphoreGetName


```
const char* osSemaphoreGetName (osSemaphoreId_t semaphore_id)
```

**描述:**

获取信号量名称函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| semaphore_id | 信号量ID（由[osSemaphoreNew](#ossemaphorenew)创建）。 | 

**返回:**

当前只能返回NULL。


### osSemaphoreNew


```
osSemaphoreId_t osSemaphoreNew (uint32_t max_count, uint32_t initial_count, const osSemaphoreAttr_t * attr)
```

**描述:**

信号量初始化函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| max_count | 信号量可申请最大值，max_count值为1时会创建一个二元信号量。 | 
| initial_count | 信号量初始值。 | 
| attr | 信号量参数，当前内部未使用该参数，参数可为NULL。 | 

**返回:**

成功，返回信号量ID。

NULL，表示参数错误或中断中调用本函数。


### osSemaphoreRelease


```
osStatus_t osSemaphoreRelease (osSemaphoreId_t semaphore_id)
```

**描述:**

释放信号量函数。

等待该信号量的线程会从阻塞中恢复。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| semaphore_id | 信号量ID（由[osSemaphoreNew](#ossemaphorenew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。


### osThreadDetach


```
osStatus_t osThreadDetach (osThreadId_t thread_id)
```

**描述:**

线程分离函数。

用于把指定线程属性设置为[osThreadDetached](#osthreaddetached)。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。


### osThreadEnumerate


```
uint32_t osThreadEnumerate (osThreadId_t * thread_array, uint32_t array_items)
```

**描述:**

获取活动线程枚举，不支持。


### osThreadExit


```
__NO_RETURN void osThreadExit (void)
```

**描述:**

当前线程退出函数。

用于线程退出，本函数不会返回。

**返回:**

本函数不会返回。


### osThreadFlagsClear


```
uint32_t osThreadFlagsClear (uint32_t flags)
```

**描述:**

清除线程的指定线程标志。

用于清除当前正在运行的线程的指定线程标志。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| flags | 待清除的标志，线程标志的第25位为错误标志。 | 

**返回:**

成功，返回清除前的标志。

osFlagsErrorUnknown，表示在中断中调用本函数。

osFlagsErrorResource，表示其他错误。


### osThreadFlagsGet


```
uint32_t osThreadFlagsGet (void)
```

**描述:**

获取线程的线程标志。

**返回:**

成功，返回当前的标志。

osFlagsErrorUnknown，表示在中断中调用本函数。


### osThreadFlagsSet


```
uint32_t osThreadFlagsSet (osThreadId_t thread_id, uint32_t flags)
```

**描述:**

设置线程的指定线程标志。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 
| flags | 设置的标志，第25位不能设置为1，函数会返回参数错误。 | 

**返回:**

成功，返回设置后的标志。

osFlagsErrorParameter，表示参数错误。

osFlagsErrorResource，表示其他错误。


### osThreadFlagsWait


```
uint32_t osThreadFlagsWait (uint32_t flags, uint32_t options, uint32_t timeout)
```

**描述:**

等待指定线程标志。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| flags | 等待的标志，第&nbsp;25&nbsp;位为错误标志。 | 
| options | 等待的方式，仅限于[osFlagsWaitAny](#osflagswaitany)&nbsp;\|&nbsp;[osFlagsWaitAll](#osflagswaitall)&nbsp;\|&nbsp;[osFlagsNoClear](#osflagsnoclear)。 | 
| timeout | 等待超时时间，单位：tick。 | 

**返回:**

成功，返回等到的标志，内容与参数options设置有关。

osFlagsErrorUnknown，表示在中断中调用本函数。

osFlagsErrorParameter，表示flag错误或者options错误。

osFlagsErrorTimeout，表示等待超时。

osFlagsErrorResource，表示其他问题。


### osThreadGetCount


```
uint32_t osThreadGetCount (void)
```

**描述:**

获取使用中的线程数量。


**返回:**

返回线程数量。

０，表示中断中调用该函数。


### osThreadGetId


```
osThreadId_t osThreadGetId (void)
```

**描述:**

获取当前线程ID函数。


**返回:**

返回线程ID，该函数不会返回失败。


### osThreadGetName


```
const char* osThreadGetName (osThreadId_t thread_id)
```

**描述:**

获取线程名称函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

返回线程名称。

NULL，表示失败或在中断中调用该函数。


### osThreadGetPriority


```
osPriority_t osThreadGetPriority (osThreadId_t thread_id)
```

**描述:**

获取线程优先级函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

成功，返回有效的线程优先级。

osPriorityError，表示参数错误或在中断中调用本函数。


### osThreadGetStackSize


```
uint32_t osThreadGetStackSize (osThreadId_t thread_id)
```

**描述:**

获取线程栈大小函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

返回指定线程栈大小，单位: 字节。

０，表示失败或在中断中调用该函数。


### osThreadGetStackSpace


```
uint32_t osThreadGetStackSpace (osThreadId_t thread_id)
```

**描述:**

获取线程栈使用水线函数。

用于获取指定线程的栈使用水线，该函数无法通过配置来返回栈剩余空间。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

返回指定线程栈水线，单位: 字节。

０，表示失败或在中断中调用该函数。


### osThreadGetState


```
osThreadState_t osThreadGetState (osThreadId_t thread_id)
```

**描述:**

获取线程状态函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

返回线程状态枚举。

osThreadError，表示在中断中调用该函数。


### osThreadJoin


```
osStatus_t osThreadJoin (osThreadId_t thread_id)
```

**描述:**

等待指定线程终止函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。


### osThreadNew


```
osThreadId_t osThreadNew (osThreadFunc_t func, void * argument, const osThreadAttr_t * attr)
```

**描述:**

创建线程函数。

用于创建一个活跃的线程，当创建的线程函数的优先级高于当前的运行线程时创建的线程函数立即启动，成为新的运行线程。

**参数:**

| Name | 描述 |
| -------- | -------- |
| func | 线程回调入口函数 |
| argument | 传递给线程回调函数的参数 |
| attr | 线程属性，传递NULL或者对于非NULL结构体中未配置的成员会使用默认值。<br/>-&nbsp;attr-&gt;name&nbsp;入参为NULL时使用默认名称，若传递非NULL时需确保传递常量。<br/>-&nbsp;attr-&gt;attr_bits&nbsp;未设置为[osThreadJoinable](#osthreadjoinable)时会默认设置为[osThreadDetached](#osthreaddetached)。<br/>-&nbsp;attr-&gt;cb_mem&nbsp;不支持。<br/>-&nbsp;attr-&gt;cb_size&nbsp;不支持。<br/>-&nbsp;attr-&gt;stack_mem和attr-&gt;stack_size同时设置有效数据才能使用用户指定内存作为任务栈。<br/>-&nbsp;attr-&gt;stack_size&nbsp;设置为0会使用默认栈大小。<br/>-&nbsp;attr-&gt;priority&nbsp;当前可用优先级最高为osPriorityAboveNormal1，最低为osPriorityLow。<br/>-&nbsp;attr-&gt;tz_module&nbsp;不支持。 |

**返回:**

返回创建的线程ID。

NULL，表示执行失败或在中断中调用该函数。


### osThreadResume


```
osStatus_t osThreadResume (osThreadId_t thread_id)
```

**描述:**

线程挂起恢复函数。

用于把指定线程设置为就绪状态。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示线程未创建或未挂起。

osErrorISR，表示在中断中调用本函数。


### osThreadSetPriority


```
osStatus_t osThreadSetPriority (osThreadId_t thread_id, osPriority_t priority)
```

**描述:**

设置线程优先级函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 
| priority | 待设置的优先级，当前可用优先级最高为osPriorityAboveNormal1，最低为osPriorityLow。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示对未创建的线程进行操作。

osErrorISR，表示在中断中调用本函数。


### osThreadSuspend


```
osStatus_t osThreadSuspend (osThreadId_t thread_id)
```

**描述:**

线程挂起函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示线程未创建或已挂起或已锁定。

osErrorISR，表示在中断中调用本函数。


### osThreadTerminate


```
osStatus_t osThreadTerminate (osThreadId_t thread_id)
```

**描述:**

指定线程终止函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| thread_id | 线程ID（由[osThreadNew](#osthreadnew)创建或[osThreadGetId](#osthreadgetid)获取）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示线程未创建。

osErrorISR，表示在中断中调用本函数。


### osThreadYield


```
osStatus_t osThreadYield (void)
```

**描述:**

线程显式放权。

用于将控制权让给其他线程，由于本线程未设置为阻塞态，若无其他同优先级可执行线程，可能继续执行本线程。

**返回:**

osOK，表示执行成功。

osErrorISR，表示在中断中调用本函数。

osError，表示其他错误。


### osTimerDelete


```
osStatus_t osTimerDelete (osTimerId_t timer_id)
```

**描述:**

定时器删除函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| timer_id | 定时器ID（由[osTimerNew](#ostimernew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。


### osTimerGetName


```
const char* osTimerGetName (osTimerId_t timer_id)
```

**描述:**

获取定时器名称函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| timer_id | 定时器ID（由[osTimerNew](#ostimernew)创建）。 | 

**返回:**

当前只能返回NULL。


### osTimerIsRunning


```
uint32_t osTimerIsRunning (osTimerId_t timer_id)
```

**描述:**

定时器状态查询函数。

用于判断定时器是否在运行。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| timer_id | 定时器ID（由[osTimerNew](#ostimernew)创建）。 | 

**返回:**

成功，返回状态（0为未运行，1为运行）。

osErrorISR，表示在中断中调用本函数。

０，表示入参为NULL或未运行。


### osTimerNew


```
osTimerId_t osTimerNew (osTimerFunc_t func, osTimerType_t type, void * argument, const osTimerAttr_t * attr)
```

**描述:**

定时器创建函数。

用于创建一个定时器，定时器[osTimerStart](#ostimerstart)启动之前处于停止状态。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| func | 定时器回调函数。 | 
| type | 定时器类型，仅限于osTimerOnce或osTimerPeriodic。 | 
| argument | 定时器回调函数参数。 | 
| attr | 定时器属性，当前不支持该参数，参数可为NULL。 | 

**返回:**

返回创建的定时器ID。

NULL，表示执行失败或在中断中调用该函数。


### osTimerStart


```
osStatus_t osTimerStart (osTimerId_t timer_id, uint32_t ticks)
```

**描述:**

定时器开始运行函数。


**参数:**

  | Name | 描述 | 
| -------- | -------- |
| timer_id | 定时器ID（由[osTimerNew](#ostimernew)创建）。 | 
| ticks | 定时器颗粒度。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。


### osTimerStop


```
osStatus_t osTimerStop (osTimerId_t timer_id)
```

**描述:**

定时器停止运行函数。

**参数:**

  | Name | 描述 | 
| -------- | -------- |
| timer_id | 定时器ID（由[osTimerNew](#ostimernew)创建）。 | 

**返回:**

osOK，表示执行成功。

osErrorParameter，表示参数错误。

osErrorResource，表示其他错误。

osErrorISR，表示在中断中调用本函数。
