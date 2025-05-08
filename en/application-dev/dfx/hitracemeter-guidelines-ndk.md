# Using HiTraceMeter (C/C++)

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the HiTraceMeter APIs in key codes to track service processes and check the system performance.

## Basic Concepts

**HiTraceMeter Tag**: Tag used for tracing data categorization. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. When you use the [HiTrace](hitrace.md) CLI tool to collect tracing data, only the data specified by the **Tag** parameter is collected. The HiTraceMeter tag for applications is **HITRACE_TAG_APP**, which corresponds to **app** in the tag list displayed by running the **[hitrace](hitrace.md) -l** command.

## Implementation Principles

1. The application calls HiTraceMeter APIs to trace and input the trace data to the kernel's ftrace buffer through the kernel's sysfs file interface.
2. The [HiTrace](hitrace.md) CLI tool reads the trace data in the kernel ftrace buffer and outputs the trace data as a text file on the device.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [Hitrace](../reference/apis-performance-analysis-kit/_hitrace.md).

| API                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| void OH_HiTrace_StartTraceEx(HiTrace_Output_Level level, const char* name, const char* customArgs) | Starts a synchronous time slice trace with the trace output level specified.              |
| void OH_HiTrace_FinishTraceEx(HiTrace_Output_Level level)    | Stops a synchronous time slice trace with the trace output level specified. The value of **level** must be the same as that of **OH_HiTrace_StartTraceEx**.|
| void OH_HiTrace_StartAsyncTraceEx(HiTrace_Output_Level level, const char* name, int32_t taskId, const char* customCategory, const char* customArgs) | Starts an asynchronous time slice trace with the trace output level specified. If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.|
| void OH_HiTrace_FinishAsyncTraceEx(HiTrace_Output_Level level, const char* name, int32_t taskId) | Stops an asynchronous time slice trace with the trace output level specified. Stops a tracing task. The values of **name** and **taskId** must be the same as those in **OH_HiTrace_StartAsyncTraceEx**.|
| void OH_HiTrace_CountTraceEx(HiTrace_Output_Level level, const char* name, int64_t count) | Traces an integer with the trace output level specified. Traces the value changes of an integer variable.|
| bool OH_HiTrace_IsTraceEnabled(void)                         | Checks whether application trace capture is enabled. If not, HiTraceMeter performance tracing is invalid.|

HiTraceMeter logging APIs are classified into three types by functionality/behavior: API for synchronous time slice tracing, API for asynchronous time slice tracing, and API for integer tracing. Both synchronous and asynchronous time slice tracing APIs are synchronous APIs. You can use HiTraceMeter APIs with [HiTraceChain](./hitracechain-guidelines-ndk.md) to perform tracing and analysis across devices, processes, and threads.

- The synchronous time slice tracing APIs are used in the scenario where tasks are executed in sequence.
- The asynchronous time slice tracing APIs are used in the scenario where tasks are executed asynchronously. The start and end of an asynchronous trace task are not in sequence. Therefore, the **name** and **taskId** parameters are used to identify the start and end of an asynchronous trace task.
- The integer tracing API is used to trace integer variables.

**Parameter Description**

| Name        | Type       | Description                                                        |
| -------------- | ----------- | ------------------------------------------------------------ |
| level          | enum        | Trace output level. Trace data whose levels are lower than the system threshold will not be output.<br>The log version threshold is **HITRACE_LEVEL_INFO**, and the nolog version threshold is **HITRACE_LEVEL_COMMERCIAL**.|
| name           | const char* | Name of the task or integer variable to trace. The value contains a maximum of 320 characters. If the value length exceeds this limit, excess content will be truncated.|
| taskId         | int32_t     | Task ID. If multiple tasks with the same **name** are executed at the same time, you must set different **taskId** when calling **OH_HiTrace_StartAsyncTraceEx**.|
| count          | int64_t     | Value of an integer variable.                                              |
| customCategory | const char* | Custom category name, which is used to collect asynchronous trace data of the same type. The value contains a maximum of 64 characters. If the value length exceeds this limit, excess content will be truncated.<br>If the category is not required, pass in an empty string.|
| customArgs     | const char* | Custom key-value pair. If there are multiple key-value pairs, separate them with commas (,), for example, **key1=value1,key2=value2**.<br>A maximum of 512 characters are output. If the **name** and **customCategory** parameters occupy too many characters, the value of **customArgs** may be truncated.<br>If this parameter is not required, pass in an empty string.|

## How to Develop

In the following example, the **OH_HiTrace_StartAsyncTraceEx** and **OH_HiTrace_FinishAsyncTraceEx** APIs are used in an NDK C/C++ application.

1. Add **libhitrace_ndk.z.so** to **CMakeLists.txt**.

   ```
   target_link_libraries(entry PUBLIC libhitrace_ndk.z.so)
   ```

2. Include the **trace.h** header file in the source file. 

   ```c++
   #include "hitrace/trace.h"
   ```

3. Trace performance data. The following uses an asynchronous trace as an example. (The sample code is a part of the default **hello.cpp** file. You only need to add related APIs at the required positions.)

   ```c++
   #include "napi/native_api.h"
   #include "hitrace/trace.h"
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // Start an asynchronous time slice trace.
       OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "hitraceTest", 123, "categoryTest", "key=value");
       // End the asynchronous time slice trace (The start and end points are for reference only. Add them to the code lines where you want to start and end the trace.)
       OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "hitraceTest", 123);
       size_t requireArgc = 2;
       size_t argc = 2;
       napi_value args[2] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
   
       napi_valuetype valuetype0;
       napi_typeof(env, args[0], &valuetype0);
   
       napi_valuetype valuetype1;
       napi_typeof(env, args[1], &valuetype1);
   
       double value0;
       napi_get_value_double(env, args[0], &value0);
   
       double value1;
       napi_get_value_double(env, args[1], &value1);
   
       napi_value sum;
       napi_create_double(env, value0 + value1, &sum);
   
       return sum;
   }
   ```

4. Install the compiled HAP in the device. In the **cmd** window, run **hdc shell** to connect to the device, and run the following command to start tracing.

   ```shell
   $ hitrace --trace_begin app
   ```

5. Start the application, execute the service call logic (including HiTraceMeter APIs), and run the following commands to view trace data.

   ```shell
   $ hitrace --trace_dump | grep hitraceTest
   $ hitrace --trace_finish
   ```

   The following is an example of the captured trace data:

   ```text
   <...>-26889   (-------) [001] ....  3100.023070: tracing_mark_write: S|26889|H:hitraceTest|123|M62|categoryTest|key=value
   <...>-26889   (-------) [001] ....  3100.023080: tracing_mark_write: F|26889|H:hitraceTest|123|M62
   ```
