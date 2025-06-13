# Using HiTraceMeter (C/C++)

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the HiTraceMeter APIs in key codes to track service processes and check the system performance.

## Basic Concepts

**HiTraceMeter Tag**: Tag used for tracing data categorization. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. When you use the [HiTrace](hitrace.md) CLI tool to collect tracing data, only the data specified by the **Tag** parameter is collected. The HiTraceMeter tag for applications is **HITRACE_TAG_APP**, which corresponds to **app** in the tag list displayed by running the **[hitrace](hitrace.md) -l** command.

## Implementation Principles

1. The application calls HiTraceMeter APIs to trace and input the trace data to the kernel's ftrace buffer through the kernel's sysfs file interface.
2. The [HiTrace](hitrace.md) CLI tool reads the trace data in the kernel ftrace buffer and outputs the trace data as a text file on the device.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [HiTrace](../reference/apis-performance-analysis-kit/_hitrace.md).

| API                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| void OH_HiTrace_StartTraceEx(HiTrace_Output_Level level, const char* name, const char* customArgs) | Starts a synchronous time slice trace with the trace output level specified.<br>**Note**: This API is supported since API version 19.|
| void OH_HiTrace_FinishTraceEx(HiTrace_Output_Level level)    | Stops a synchronous time slice trace with the trace output level specified. The value of **level** must be the same as that of **OH_HiTrace_StartTraceEx**.<br>**Note**: This API is supported since API version 19.|
| void OH_HiTrace_StartAsyncTraceEx(HiTrace_Output_Level level, const char* name, int32_t taskId, const char* customCategory, const char* customArgs) | Starts an asynchronous time slice trace with the trace output level specified. If multiple tracing tasks with the same name need to be performed at the same time, different task IDs must be specified through **taskId**. If the tracing tasks with the same name are not performed at the same time, the same task ID can be used.<br>**Note**: This API is supported since API version 19.|
| void OH_HiTrace_FinishAsyncTraceEx(HiTrace_Output_Level level, const char* name, int32_t taskId) | Stops an asynchronous time slice trace with the trace output level specified. Stops a tracing task. The values of **name** and **taskId** must be the same as those in **OH_HiTrace_StartAsyncTraceEx**.<br>**Note**: This API is supported since API version 19.|
| void OH_HiTrace_CountTraceEx(HiTrace_Output_Level level, const char* name, int64_t count) | Traces an integer with the trace output level specified. Traces the value changes of an integer variable.<br>**Note**: This API is supported since API version 19.|
| bool OH_HiTrace_IsTraceEnabled(void)                         | Checks whether application trace capture is enabled. If not, HiTraceMeter performance tracing is invalid.<br>**Note**: This API is supported since API version 19.|

> **NOTE**
>
> The vertical bar (|) is used as the separator in [user-mode trace format](./hitracemeter-view.md#user-mode-trace-format). Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.

HiTraceMeter logging APIs are classified into three types by functionality/behavior: API for synchronous time slice tracing, API for asynchronous time slice tracing, and API for integer tracing. Both synchronous and asynchronous time slice tracing APIs are synchronous APIs. You can use HiTraceMeter APIs with [HiTraceChain](./hitracechain-guidelines-ndk.md) to perform tracing and analysis across devices, processes, and threads.

- The synchronous time slice tracing APIs are used in the scenario where tasks are executed in sequence.
- The asynchronous time slice tracing APIs are used in the scenario where tasks are executed asynchronously. The start and end of an asynchronous trace task are not in sequence. Therefore, the **name** and **taskId** parameters are used to identify the start and end of an asynchronous trace task.
- The integer tracing API is used to trace integer variables.

**Parameter Description**

| Name        | Type       | Description                                                        |
| -------------- | ----------- | ------------------------------------------------------------ |
| level          | enum        | Trace output level. Trace data whose levels are lower than the system threshold will not be output.<br>The log version threshold is **HITRACE_LEVEL_INFO**, and the nolog version threshold is **HITRACE_LEVEL_COMMERCIAL**.|
| name           | const char* | Name of the task or integer variable to trace.                            |
| taskId         | int32_t     | Task ID. If multiple tasks with the same **name** are executed at the same time, you must set different **taskId** when calling **OH_HiTrace_StartAsyncTraceEx**.|
| count          | int64_t     | Value of an integer variable.                                              |
| customCategory | const char* | Custom category name, which is used to collect asynchronous trace data of the same type.<br>If the category is not required, pass in an empty string.|
| customArgs     | const char* | Custom key-value pair. If there are multiple key-value pairs, separate them with commas (,), for example, **key1=value1,key2=value2**.<br>If this parameter is not required, pass in an empty string.|

> **NOTE**
>
> The maximum length of a [user-mode trace](./hitracemeter-view.md#user-mode-trace-format) is 512 characters. Excess characters will be truncated. Therefore, it is recommended that the total length of the **name**, **customCategory**, and **customArgs** fields be less than or equal to 420 characters.

## How to Develop

In DevEco Studio, create a native C++ project and use the HiTraceMeter NDK_C logging API. The following is an example of a native C++ project.

1. Create a native C++ project. The project directory structure is as follows:

   ```text
   ├── entry
   │   ├── src
   │       ├── main
   │       │   ├── cpp
   │       │   │   ├── CMakeLists.txt
   │       │   │   ├── napi_init.cpp
   │       │   │   └── types
   │       │   │       └── libentry
   │       │   │           ├── Index.d.ts
   │       │   │           └── oh-package.json5
   │       │   ├── ets
   │       │   │   ├── entryability
   │       │   │   │   └── EntryAbility.ets
   │       │   │   ├── entrybackupability
   │       │   │   │   └── EntryBackupAbility.ets
   │       │   │   └── pages
   │       │   │       └── Index.ets
   ```

2. In the end of the **CMakeLists.txt** file, add **libhitrace_ndk.z.so** and **libhilog_ndk.z.so**.

   ```cmake
   target_link_libraries(entry PUBLIC libhitrace_ndk.z.so libhilog_ndk.z.so)
   ```

3. In the **napi_init.cpp** file, call the HiTraceMeter NDK_C API in the **Add** function to trace the performance. The sample code is as follows:

   ```c++
   #include <cstdio>
   #include <cstring>
   
   #include "hilog/log.h"
   #include "hitrace/trace.h"
   #include "napi/native_api.h"
   
   #undef LOG_TAG
   #define LOG_TAG "traceTest"
   
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // Start the first asynchronous tracing task.
       OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1001, "categoryTest", "key=value");
       // Start the counting task.
       int64_t traceCount = 0;
       traceCount++;
       OH_HiTrace_CountTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestCountTrace", traceCount);
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1001");
   
       // Start the second asynchronous tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
       OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1002, "categoryTest", "key=value");
       // Start the counting task.
       traceCount++;
       OH_HiTrace_CountTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestCountTrace", traceCount);
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1002");
   
       // Stop the asynchronous tracing task whose taskId is 1001.
       OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1001);
       // Stop the asynchronous tracing task whose taskId is 1002.
       OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1002);
   
       // Start a synchronous tracing task.
       OH_HiTrace_StartTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestSyncTrace", "key=value");
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, synchronizing trace");
       // Stop the synchronous tracing task.
       OH_HiTrace_FinishTraceEx(HITRACE_LEVEL_COMMERCIAL);
   
       // If the process of generating the parameters passed by the HiTraceMeter API is complex, you can use isTraceEnabled to determine whether trace capture is enabled.
       // Avoid performance loss when application trace capture is not enabled.
       if (OH_HiTrace_IsTraceEnabled()) {
           char customArgs[128] = "key0=value0";
           for (int index = 1; index < 10; index++) {
               char buffer[16];
               snprintf(buffer, sizeof(buffer), ",key%d=value%d", index, index);
               strncat(customArgs, buffer, sizeof(customArgs) - strlen(customArgs) - 1);
           }
           OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1003, "categoryTest", customArgs);
           OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1003");
           OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1003);
       } else {
           OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, trace is not enabled");
       }
   
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
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   
   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry",
       .nm_priv = ((void*)0),
       .reserved = { 0 },
   };
   
   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```

4. Run the following command in DevEco Studio Terminal to enable trace capture:

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```


5. In DevEco Studio, click the **Run** button to run the project. Click the string in the middle of the screen to execute the service logic that contains the HiTraceMeter logging. Then run the following command to capture trace data:

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   The sample trace data is as follows:

   ```text
   <...>-49837   (-------) [002] .... 349137.708093: tracing_mark_write: S|49837|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   <...>-49837   (-------) [002] .... 349137.708103: tracing_mark_write: C|49837|H:myTestCountTrace|1|M62
   <...>-49837   (-------) [002] .... 349137.708201: tracing_mark_write: S|49837|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   <...>-49837   (-------) [002] .... 349137.708209: tracing_mark_write: C|49837|H:myTestCountTrace|2|M62
   <...>-49837   (-------) [002] .... 349137.708239: tracing_mark_write: F|49837|H:myTestAsyncTrace|1001|M62
   <...>-49837   (-------) [002] .... 349137.708246: tracing_mark_write: F|49837|H:myTestAsyncTrace|1002|M62
   <...>-49837   (-------) [002] .... 349137.708252: tracing_mark_write: B|49837|H:myTestSyncTrace|M62|key=value
   <...>-49837   (-------) [002] .... 349137.708301: tracing_mark_write: S|49837|H:myTestAsyncTrace|1003|M62|categoryTest|key0=value0,key1=value1,key2=value2,key3=value3,key4=value4,key5=value5,key6=value6,key7=value7,key8=value8,key9=value9
   <...>-49837   (-------) [002] .... 349137.708323: tracing_mark_write: F|49837|H:myTestAsyncTrace|1003|M62
   ```

7. Run the following command to stop the application trace capture:

   ```shell
   $ hitrace --trace_finish
   ```

8. Click the string in the middle of the screen again. The application trace capture function is disabled, and **OH_HiTrace_IsTraceEnabled** returns **false**. In the **Log** panel in DevEco Studio, select **enable** to filter logs. The following information is displayed:

   ```text
   myTraceTest running, trace is not enabled
   ```

   
