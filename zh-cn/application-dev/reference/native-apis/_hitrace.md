# Hitrace


## 概述

hiTraceMeter为开发者提供系统性能打点接口。

开发者通过在自己的业务逻辑中的关键代码位置调用HiTraceMeter系统跟踪提供的API接口，能够有效进行关键执行流程耗时度量和问题定位。

\@syscap SystemCapability.HiviewDFX.HiTrace

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [trace.h](trace_8h.md) | HiTraceMeterH模块打点接口定义，通过这些接口实现性能打点相关功能。<br>**引用文件：**<hitrace/trace.h><br>**库：**libhitrace_ndk.z.so | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_HiTrace_StartTrace](#oh_hitrace_starttrace) (const char \*name) | 标记一个同步跟踪耗时任务的开始。 | 
| [OH_HiTrace_FinishTrace](#oh_hitrace_finishtrace) (void) | 标记一个同步跟踪耗时任务的结束。 | 
| [OH_HiTrace_StartAsyncTrace](#oh_hitrace_startasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的开始。 | 
| [OH_HiTrace_FinishAsyncTrace](#oh_hitrace_finishasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的结束。 | 
| [OH_HiTrace_CountTrace](#oh_hitrace_counttrace) (const char \*name, int64_t count) | 用于跟踪给定整数变量名和整数值。 | 


## 函数说明


### OH_HiTrace_CountTrace()

  
```
void OH_HiTrace_CountTrace (const char * name, int64_t count )
```

**描述:**

用于跟踪给定整数变量名和整数值。

多次执行该接口可以跟踪给定整数变量在不同时刻的数值变化。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 整数变量跟踪的名字，不必与真实变量名相同。 | 
| count | 整数数值，一般可以传入整数变量。 | 

**起始版本：**

10


### OH_HiTrace_FinishAsyncTrace()

  
```
void OH_HiTrace_FinishAsyncTrace (const char * name, int32_t taskId )
```

**描述:**

标记一个异步跟踪耗时任务的结束。

在异步操作完成后如回调函数中调用，进行结束打点。 和OH_HiTrace_StartAsyncTrace配对使用，参数name和taskId必须与异步跟踪的开始打点接口OH_HiTrace_StartAsyncTrace的对应参数值一致。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 异步跟踪的名字。 | 
| taskId | 异步跟踪的ID。异步跟踪开始和结束由于不是顺序发生的，所以需要通过name和每次执行唯一的taskId进行开始和结束的匹配。 | 

**起始版本：**

10


### OH_HiTrace_FinishTrace()

  
```
void OH_HiTrace_FinishTrace (void )
```

**描述:**

标记一个同步跟踪耗时任务的结束。

必须和OH_HiTrace_StartTrace配对使用。跟踪数据解析时，和其前执行流程中最近的OH_HiTrace_StartTrace进行匹配。

**起始版本：**

10


### OH_HiTrace_StartAsyncTrace()

  
```
void OH_HiTrace_StartAsyncTrace (const char * name, int32_t taskId )
```

**描述:**

标记一个异步跟踪耗时任务的开始。

用于在异步操作前调用进行开始打点，异步跟踪开始和结束数据由于不是顺序发生的，所以解析时需要通过一个唯一的taskId进行识别，这个taskId作为异步接口的参数传入。 和OH_HiTrace_FinishAsyncTrace配对使用，参数name和taskId相同的这两个接口调用匹配成一个异步跟踪耗时任务。 如果有多个相同name的任务需要跟踪或者对同一个任务跟踪多次，并且任务同时被执行，则每次调用startTrace的taskId不相同。 如果具有相同name的任务是串行执行的，则taskId可以相同。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 异步跟踪的名字。 | 
| taskId | 异步跟踪的ID。 异步跟踪开始和结束由于不是顺序发生的，所以需要通过name和每次执行唯一的taskId进行开始和结束的匹配。 | 

**起始版本：**

10


### OH_HiTrace_StartTrace()

  
```
void OH_HiTrace_StartTrace (const char * name)
```

**描述:**

标记一个同步跟踪耗时任务的开始。

同步跟踪打点接口OH_HiTrace_StartTrace和OH_HiTrace_FinishTrace必须配对使用。 OH_HiTrace_StartTrace和OH_HiTrace_FinishTrace函数对可以以嵌套模式使用，跟踪数据解析时使用栈式数据结构进行匹配。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 跟踪的名字。 | 

**起始版本：**

10
