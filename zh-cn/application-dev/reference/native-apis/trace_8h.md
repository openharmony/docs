# trace.h


## 概述

HiTraceMeterH模块打点接口定义，通过这些接口实现性能打点相关功能。

使用示例:

同步时间片跟踪事件：

  
```
OH_HiTrace_StartTrace("hitraceTest");
OH_HiTrace_FinishTrace();
```

结果输出：

  
```
<...>-1668 (----—) [003] .... 135.059377: tracing_mark_write: B|1668|H:hitraceTest
<...>-1668 (----—) [003] .... 135.059415: tracing_mark_write: E|1668|
```

异步时间片跟踪事件：

  
```
OH_HiTrace_StartAsyncTrace("hitraceTest", 123);
OH_HiTrace_FinishAsyncTrace("hitraceTest", 123);
```

结果输出：

  
```
<...>-2477 (----—) [001] .... 396.427165: tracing_mark_write: S|2477|H:hitraceTest 123
<...>-2477 (----—) [001] .... 396.427196: tracing_mark_write: F|2477|H:hitraceTest 123
```

整数值跟踪事件：

  
```
OH_HiTrace_CountTrace("hitraceTest", 500);
```

结果输出：

  
```
<...>-2638 (----—) [002] .... 458.904382: tracing_mark_write: C|2638|H:hitraceTest 500
```

**起始版本：**

10

**相关模块:**

[Hitrace](_hitrace.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_HiTrace_StartTrace](_hitrace.md#oh_hitrace_starttrace) (const char \*name) | 标记一个同步跟踪耗时任务的开始。 | 
| [OH_HiTrace_FinishTrace](_hitrace.md#oh_hitrace_finishtrace) (void) | 标记一个同步跟踪耗时任务的结束。 | 
| [OH_HiTrace_StartAsyncTrace](_hitrace.md#oh_hitrace_startasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的开始。 | 
| [OH_HiTrace_FinishAsyncTrace](_hitrace.md#oh_hitrace_finishasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的结束。 | 
| [OH_HiTrace_CountTrace](_hitrace.md#oh_hitrace_counttrace) (const char \*name, int64_t count) | 用于跟踪给定整数变量名和整数值。 | 
