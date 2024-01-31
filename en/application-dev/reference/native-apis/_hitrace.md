# Hitrace


## Overview

hiTraceMeter provides APIs for system performance tracing.

You can call the APIs provided by hiTraceMeter in your own service logic to effectively track service processes and check the system performance.

\@syscap SystemCapability.HiviewDFX.HiTrace

**Since**

10


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [trace.h](trace_8h.md) | Defines APIs of the HiTraceMeter module for performance trace.<br>**File to include**: <hitrace/trace.h><br>**Library**: libhitrace_ndk.z.so| 

### Functions

| Name| Description| 
| -------- | -------- |
| [OH_HiTrace_StartTrace](#oh_hitrace_starttrace) (const char \*name) | Marks the start of a synchronous trace.| 
| [OH_HiTrace_FinishTrace](#oh_hitrace_finishtrace) (void) | Marks the end of a synchronous trace.| 
| [OH_HiTrace_StartAsyncTrace](#oh_hitrace_startasynctrace) (const char \*name, int32_t taskId) | Marks the start of an asynchronous trace.| 
| [OH_HiTrace_FinishAsyncTrace](#oh_hitrace_finishasynctrace) (const char \*name, int32_t taskId) | Marks the end of an asynchronous trace.| 
| [OH_HiTrace_CountTrace](#oh_hitrace_counttrace) (const char \*name, int64_t count) | Traces the value change of an integer variable based on its name.| 


## Function Description


### OH_HiTrace_CountTrace()

  
```
void OH_HiTrace_CountTrace (const char * name, int64_t count )
```

**Description**

Traces the value change of an integer variable based on its name.

This API can be executed for multiple times to trace the value change of a given integer variable at different time points.

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Name of the integer variable. It does not need to be the same as the real variable name.| 
| count | Integer value. Generally, an integer variable can be specified.| 

**Since**

10


### OH_HiTrace_FinishAsyncTrace()

  
```
void OH_HiTrace_FinishAsyncTrace (const char * name, int32_t taskId )
```

**Description**

Marks the end of an asynchronous trace.

This API is called in the callback function after an asynchronous trace is complete. It is used with **OH_HiTrace_StartAsyncTrace** in pairs. Its name and task ID must be the same as those of **OH_HiTrace_StartAsyncTrace**.

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Name of the asynchronous trace.| 
| taskId | ID of the asynchronous trace. The start and end of an asynchronous trace task do not occur in sequence. Therefore, the start and end of an asynchronous trace need to be matched based on the task name and the unique task ID together.| 

**Since**

10


### OH_HiTrace_FinishTrace()

  
```
void OH_HiTrace_FinishTrace (void )
```

**Description**

Marks the end of a synchronous trace.

This API must be used with **OH_HiTrace_StartTrace** in pairs. During trace data parsing, the system matches it with the **OH_HiTrace_StartTrace** API recently invoked in the service process.

**Since**

10


### OH_HiTrace_StartAsyncTrace()

  
```
void OH_HiTrace_StartAsyncTrace (const char * name, int32_t taskId )
```

**Description**

Marks the start of an asynchronous trace.

This API is called to implement performance trace in asynchronous manner. The start and end of an asynchronous trace task do not occur in sequence. Therefore, a unique **taskId** is required to ensure proper data parsing. It is passed as an input parameter for the asynchronous API. This API is used with **OH_HiTrace_FinishAsyncTrace** in pairs. The two APIs that have the same name and task ID together form an asynchronous trace. If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified in **OH_HiTrace_StartTrace**. If the trace tasks with the same name are not performed at the same time, the same taskId can be used.

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Name of the asynchronous trace.| 
| taskId | ID of the asynchronous trace. The start and end of an asynchronous trace task do not occur in sequence. Therefore, the start and end of an asynchronous trace need to be matched based on the task name and the unique task ID together.| 

**Since**

10


### OH_HiTrace_StartTrace()

  
```
void OH_HiTrace_StartTrace (const char * name)
```

**Description**

Marks the start of a synchronous trace.

This API is used with **OH_HiTrace_FinishTrace** in pairs. The two APIs can be used in nested mode. The stack data structure is used for matching during trace data parsing.

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Name of the synchronous trace.| 

**Since**

10
