# trace.h


## Overview

Defines APIs of the HiTraceMeter module for performance trace.

Example

Synchronous time slice trace event:

  
```
OH_HiTrace_StartTrace("hitraceTest");
OH_HiTrace_FinishTrace();
```

Output:

  
```
<...>-1668 (----—) [003] .... 135.059377: tracing_mark_write: B|1668|H:hitraceTest
<...>-1668 (----—) [003] .... 135.059415: tracing_mark_write: E|1668|
```

Asynchronous time slice trace event:

  
```
OH_HiTrace_StartAsyncTrace("hitraceTest", 123);
OH_HiTrace_FinishAsyncTrace("hitraceTest", 123);
```

Output:

  
```
<...>-2477 (----—) [001] .... 396.427165: tracing_mark_write: S|2477|H:hitraceTest 123
<...>-2477 (----—) [001] .... 396.427196: tracing_mark_write: F|2477|H:hitraceTest 123
```

Integer value trace event:

  
```
OH_HiTrace_CountTrace("hitraceTest", 500);
```

Output:

  
```
<...>-2638 (----—) [002] .... 458.904382: tracing_mark_write: C|2638|H:hitraceTest 500
```

**Since**

10

**Related Modules**

[Hitrace](_hitrace.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_HiTrace_StartTrace](_hitrace.md#oh_hitrace_starttrace) (const char \*name) | Marks the start of a synchronous trace.| 
| [OH_HiTrace_FinishTrace](_hitrace.md#oh_hitrace_finishtrace) (void) | Marks the end of a synchronous trace.| 
| [OH_HiTrace_StartAsyncTrace](_hitrace.md#oh_hitrace_startasynctrace) (const char \*name, int32_t taskId) | Marks the start of an asynchronous trace.| 
| [OH_HiTrace_FinishAsyncTrace](_hitrace.md#oh_hitrace_finishasynctrace) (const char \*name, int32_t taskId) | Marks the end of an asynchronous trace.| 
| [OH_HiTrace_CountTrace](_hitrace.md#oh_hitrace_counttrace) (const char \*name, int64_t count) | Traces the value change of an integer variable based on its name.| 
