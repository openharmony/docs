# Using HiTraceMeter (C/C++)

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the HiTraceMeter APIs in key codes to track service processes and check the system performance.

## Basic Concepts

**HiTraceMeter Tag**: Tag used for tracing data categorization. It is also known as **HiTraceMeter Category**. Generally, one subsystem maps to a tag. The [HiTrace](https://gitee.com/openharmony/docs/blob/master/en/application-dev/dfx/hitrace.md) tool collects only the trace data of the specified tag. The tag for application logging is **HITRACE_TAG_APP**, corresponding to **app** in the tag list displayed by running **hitrace -l** command using [HiTrace](https://gitee.com/openharmony/docs/blob/master/en/application-dev/dfx/hitrace.md).

## Implementation Principles

1. The application calls HiTraceMeter APIs to trace and input the trace data to the kernel's ftrace buffer through the kernel's sysfs file interface.
2. [HiTrace](https://gitee.com/openharmony/docs/blob/master/en/application-dev/dfx/hitrace.md) reads trace data from the kernel ftrace buffer and outputs the trace data to a file on the device.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [HiTrace](../reference/apis-performance-analysis-kit/_hitrace.md).

| API| Description|
| -------- | -------- |
| void OH_HiTrace_StartTrace(const char* name) | Starts a synchronous time slice trace.|
| void OH_HiTrace_FinishTrace() | Ends a synchronous time slice trace.|
| void OH_HiTrace_StartAsyncTrace(const char* name, int32_t taskId) | Starts an asynchronous time slice trace.|
| void OH_HiTrace_FinishAsyncTrace(const char* name, int32_t taskId) | Ends an asynchronous time slice trace.|
| void OH_HiTrace_CountTrace(const char* name, int64_t count) | Performs an integer trace.|

HiTraceMeter logging APIs are classified into three types by functionality/behavior: API for synchronous time slice tracing, API for asynchronous time slice tracing, and API for integer tracing. Both synchronous and asynchronous time slice tracing APIs are synchronous APIs. The HiTraceMeter APIs can be used with [HiTraceChain](https://gitee.com/openharmony/docs/blob/master/en/application-dev/dfx/hitracechain-guidelines-arkts.md) for logging and analysis across devices, processes, and threads.

- The synchronous time slice tracing APIs are used in the scenario where tasks are executed in sequence.
- The asynchronous time slice tracing APIs are used in the scenario where tasks are executed asynchronously. The start and end of an asynchronous trace task are not in sequence. Therefore, the **name** and **taskId** parameters are used to identify the start and end of an asynchronous trace task.
- The integer tracing API is used to trace integer variables.

**Parameter Description**

| Name| Type| Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | Yes  | Name of the variable.|
| taskId | number | Yes  | ID used to indicate the association of APIs in a trace. If multiple traces with the same name need to be performed at the same time, different task IDs must be specified in **startTrace**.|
| count  | number | Yes  | Value of the variable. |

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
   #include "hilog/log.h"
   #include "hitrace/trace.h"
   #include "napi/native_api.h"
   
   #undef LOG_TAG
   #define LOG_TAG "traceTest"
   
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // Start the first asynchronous tracing task.
       OH_HiTrace_StartAsyncTrace("myTestAsyncTrace", 1001);
       // Start the counting task.
       int64_t traceCount = 0;
       traceCount++;
       OH_HiTrace_CountTrace("myTestCountTrace", traceCount);
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1001");
   
       // Start the second asynchronous tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
       OH_HiTrace_StartAsyncTrace("myTestAsyncTrace", 1002);
       // Start the counting task.
       traceCount++;
       OH_HiTrace_CountTrace("myTestCountTrace", traceCount);
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1002");
   
       // Stop the asynchronous tracing task whose taskId is 1001.
       OH_HiTrace_FinishAsyncTrace("myTestAsyncTrace", 1001);
       // Stop the asynchronous tracing task whose taskId is 1002.
       OH_HiTrace_FinishAsyncTrace("myTestAsyncTrace", 1002);
   
       // Start a synchronous tracing task.
       OH_HiTrace_StartTrace("myTestSyncTrace");
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, synchronizing trace");
       // Stop the synchronous tracing task.
       OH_HiTrace_FinishTrace();
   
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
   <...>-21458   (-------) [009] .... 372404.331037: tracing_mark_write: S|21458|H:myTestAsyncTrace 1001
   <...>-21458   (-------) [009] .... 372404.331040: tracing_mark_write: C|21458|H:myTestCountTrace 1
   <...>-21458   (-------) [009] .... 372404.331083: tracing_mark_write: S|21458|H:myTestAsyncTrace 1002
   <...>-21458   (-------) [009] .... 372404.331085: tracing_mark_write: C|21458|H:myTestCountTrace 2
   <...>-21458   (-------) [009] .... 372404.331091: tracing_mark_write: F|21458|H:myTestAsyncTrace 1001
   <...>-21458   (-------) [009] .... 372404.331093: tracing_mark_write: F|21458|H:myTestAsyncTrace 1002
   <...>-21458   (-------) [009] .... 372404.331095: tracing_mark_write: B|21458|H:myTestSyncTrace 
   ```

6. Run the following command to stop the application trace capture:

   ```shell
   $ hitrace --trace_finish
   ```
