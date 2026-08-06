# Using HiTraceMeter (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @yu_haoqiaida-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=2adb7aac313c0d1259fce6baf2f9705077b01aa9 translatedAt=2026-07-31T01:34:44.160Z pushedAt=2026-07-31T08:06:26.545Z -->

## Overview

HiTraceMeter provides APIs for system performance tracing. You can call the APIs at key code to track processes and check system and application performance.

## Available APIs

The **HiTraceMeter** module provides APIs for performance tracing. For details, see [trace.h](../reference/apis-performance-analysis-kit/capi-trace-h.md).

| API| Description|
| -------- | -------- |
| void OH_HiTrace_StartTraceEx(HiTrace_Output_Level level, const char\* name, const char\* customArgs) | Starts a synchronous time slice tracking event with hierarchical control of trace output.<br>**Note:** This API is supported since API version 19. |
| void OH_HiTrace_FinishTraceEx(HiTrace_Output_Level level) | Ends a synchronous time slice tracking event with hierarchical control of trace output.<br>The level must be the same as the corresponding parameter value in OH_HiTrace_StartTraceEx() that started the trace.<br>**Note:** This API is supported since API version 19. |
| void OH_HiTrace_StartAsyncTraceEx(HiTrace_Output_Level level, const char\* name, int32_t taskId, const char\* customCategory, const char\* customArgs) | Starts an asynchronous time slice tracking event with hierarchical control of trace output.<br>taskId is an ID used to indicate correlation in the trace. If multiple tasks with the same name are executed in parallel, you must pass a different taskId each time you call OH_HiTrace_StartAsyncTraceEx(). If tasks with the same name are executed serially, the taskId can be the same.<br>**Note:** This API is supported since API version 19. |
| void OH_HiTrace_FinishAsyncTraceEx(HiTrace_Output_Level level, const char\* name, int32_t taskId) | Ends an asynchronous time slice tracking event with hierarchical control of trace output.<br>The level, name, and taskId must be the same as the corresponding parameter values in OH_HiTrace_StartAsyncTraceEx() that started the trace.<br>**Note:** This API is supported since API version 19. |
| void OH_HiTrace_CountTraceEx(HiTrace_Output_Level level, const char\* name, int64_t count) | Creates an integer tracking event with hierarchical control of trace output.<br>name and count are used to mark the name and integer value of a tracked integer variable, respectively.<br>**Note:** This API is supported since API version 19. |
| bool OH_HiTrace_IsTraceEnabled(void) | Checks whether app trace capture is currently enabled.<br>Returns **true** when capture is enabled through the hitrace CLI tool or other methods. Returns **false** when capture is not enabled or has been stopped, in which case calling HiTraceMeter performance tracing interfaces has no effect.<br>**Note:** This API is supported since API version 19. |
| int32_t OH_HiTrace_RegisterTraceListener(OH_HiTrace_TraceEventListener callback) | Registers a callback for app trace capture switch notifications. This API uses an asynchronous callback to return the result.<br>After successful registration, the callback is executed immediately once. Subsequent callbacks are triggered by changes in the app trace capture switch state.<br>**Note:** This API is supported since API version 22. |
| int32_t OH_HiTrace_UnregisterTraceListener(int32_t index); | Unregisters the callback for app trace capture switch notifications.<br>**Note:** This API is supported since API version 22. |

> **NOTE**
>
> The vertical bar (|) is used as the separator in [user-mode trace format](hitracemeter-view.md#user-mode-trace-format). Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.

### API Category

HiTraceMeter APIs are classified into three types: synchronous timeslice tracing APIs, asynchronous timeslice tracing APIs, and integer tracing APIs. HiTraceMeter APIs are synchronous. The synchronous and asynchronous modes describe the traced services. The synchronous timeslice tracing APIs are used for synchronous services, and the asynchronous timeslice tracing APIs are used for asynchronous services. HiTraceMeter APIs can be used with [HiTraceChain](hitracechain-guidelines-ndk.md) to associate and analyze logging across devices, processes, or threads.

### Use Scenarios

- Synchronous timeslice tracing APIs:

  The **OH_HiTrace_StartTraceEx()** and **OH_HiTrace_FinishTraceEx()** APIs must be used sequentially for logging during sequential execution. If they are not called in the correct order, the trace file will appear abnormal in visualization tools such as SmartPerf.

- Asynchronous timeslice tracing APIs:

  The **OH_HiTrace_StartAsyncTraceEx()** API is called to start logging before an asynchronous operation is performed, and the **OH_HiTrace_FinishAsyncTraceEx()** API is called to end logging after the asynchronous operation is performed. 

  During trace parsing, different asynchronous traces are identified by the **name** and **taskId** parameters. These two APIs must be used in sequence as a pair, with the same **name** and **taskId** passed. 

  Different **name** and **taskId** values must be used for different asynchronous processes. However, the same **name** and **taskId** values can be used if asynchronous processes do not occur at the same time. 

  If the API is called incorrectly, the trace file will appear abnormal in visualization tools such as SmartPerf.

- Integer tracing APIs:

  The APIs are used to trace integer variables. The **OH_HiTrace_CountTraceEx()** API is called when integer values change. You can view the change in the lane diagram of SmartPerf. The values during the interval between the start of data collection and the first logging cannot be viewed.

### Parameter Description

| Name| Type| Description|
| -------- | -------- | -------- |
| level | enum | Trace output level. Traces below the system threshold will not be output.<br>The threshold is HITRACE_LEVEL_INFO for the log version and HITRACE_LEVEL_COMMERCIAL for the nolog version. |
| name | const char\* | Name of the task or integer variable to trace.|
| taskId | int32_t | Task ID. If multiple tasks with the same **name** are executed at the same time, you must set different **taskId** when calling **OH_HiTrace_StartAsyncTraceEx()**.|
| count | int64_t | Value of an integer variable.|
| customCategory | const char\* | Custom clustering name, used to cluster asynchronous tracing events of the same category.<br>If clustering is not required, pass an empty string. |
| customArgs | const char\* | Custom key-value pair. If there are multiple key-value pairs, separate them with commas, for example, "key1=value1,key2=value2".<br>If this parameter is not required, pass an empty string. |
| callback | void (*)(bool) | Registered callback.|
| index | int32_t | Callback index returned by **OH_HiTrace_RegisterTraceListener()**.|

> **NOTE**
>
> The maximum length of a [user-mode trace](hitracemeter-view.md#user-mode-trace-format) is 512 characters. Excess characters will be truncated. Therefore, it is recommended that the total length of the **name**, **customCategory**, and **customArgs** fields be less than or equal to 420 characters.

## How to Develop

The following is an example of a native C++ application that uses the HiTraceMeter APIs.

### Step 1: Creating a Project

1. Create a project in DevEco Studio and select **Native C++**. The project directory structure is as follows:

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

2. In the **entry/src/main/cpp/CMakeLists.txt** file, add **libhitrace_ndk.z.so** and **libhilog_ndk.z.so**. The complete file content is as follows:

    <!-- @[hitracemeter_ndk_cmake_code](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceMeter_NDK/entry/src/main/cpp/CMakeLists.txt) -->

    ``` cmake
    # the minimum version of CMake.
    cmake_minimum_required(VERSION 3.5.0)
    project(HiTraceChainTest03)
   
    set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
    if(DEFINED PACKAGE_FIND_FILE)
        include(${PACKAGE_FIND_FILE})
    endif()
   
    include_directories(${NATIVERENDER_ROOT_PATH}
                        ${NATIVERENDER_ROOT_PATH}/include)
   
    add_library(entry SHARED napi_init.cpp)
    target_link_libraries(entry PUBLIC libace_napi.z.so libhitrace_ndk.z.so libhilog_ndk.z.so)
    ```

3. In the **entry/src/main/cpp/napi_init.cpp** file, call the HiTraceMeter NDK_C API in the **Add** function to trace performance. The sample code is as follows:

   <!-- @[hitracemeter_ndk_native_code](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiTrace/HitraceMeter_NDK/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
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
       HiTrace_Output_Level level = HITRACE_LEVEL_COMMERCIAL;
       constexpr int64_t taskIdOne = 1001;
       OH_HiTrace_StartAsyncTraceEx(level, "myTestAsyncTrace", taskIdOne, "categoryTest", "key=value");
       // Start the counting task.
       int64_t traceCount = 0;
       traceCount++;
       OH_HiTrace_CountTraceEx(level, "myTestCountTrace", traceCount);
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1001");
       // Start the second asynchronous tracing task with the same name while the first task is still running. The tasks are running concurrently and therefore their taskId must be different.
       constexpr int64_t taskIdTwo = 1002;
       OH_HiTrace_StartAsyncTraceEx(level, "myTestAsyncTrace", taskIdTwo, "categoryTest", "key=value");
       // Start the counting task.
       traceCount++;
       OH_HiTrace_CountTraceEx(level, "myTestCountTrace", traceCount);
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1002");
   
       // Stop the asynchronous tracing task whose taskId is 1001.
       OH_HiTrace_FinishAsyncTraceEx(level, "myTestAsyncTrace", taskIdOne);
       // Stop the asynchronous tracing task whose taskId is 1002.
       OH_HiTrace_FinishAsyncTraceEx(level, "myTestAsyncTrace", taskIdTwo);
   
       // Start a synchronous tracing task.
       OH_HiTrace_StartTraceEx(level, "myTestSyncTrace", "key=value");
       // Keep the service process running.
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, synchronizing trace");
       // Stop the synchronous tracing task.
       OH_HiTrace_FinishTraceEx(level);
   
       // If the process of generating the parameters passed by the HiTraceMeter API is complex, you can use isTraceEnabled to determine whether trace capture is enabled.
       // Avoid performance loss when application trace capture is not enabled.
       constexpr int64_t taskIdThree = 1003;
       constexpr int loopTime = 10;
       if (OH_HiTrace_IsTraceEnabled()) {
           char customArgs[128] = "key0=value0";
           for (int index = 1; index < loopTime; index++) {
               char buffer[16];
               snprintf(buffer, sizeof(buffer), ",key%d=value%d", index, index);
               strncat(customArgs, buffer, sizeof(customArgs) - strlen(customArgs) - 1);
           }
           OH_HiTrace_StartAsyncTraceEx(level, "myTestAsyncTrace", taskIdThree, "categoryTest", customArgs);
           OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1003");
           OH_HiTrace_FinishAsyncTraceEx(level, "myTestAsyncTrace", taskIdThree);
       } else {
           OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, trace is not enabled");
       }
   
       size_t requireArgc = 2;
       size_t argc = 2;
       napi_value args[2] = {nullptr};
   
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
   
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

### Step 2: Collecting and Viewing Trace Information

1. Run the following command in DevEco Studio Terminal to enable trace capture:

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

2. Click the **Run** button in DevEco Studio to run the project. Then, click "Hello world" to execute the service logic that contains HiTraceMeter logging. Run the following command to capture trace data and filter the trace data using the keyword **myTest** (the name field prefix passed by the logging API is **myTest** in this example).

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

### Step 3: Stopping Trace Capture

1. Run the following command to stop the application trace capture:

   ```shell
   $ hitrace --trace_finish
   ```

2. Click "Hello World" on the application screen again. The trace capture of the application is disabled, and the **OH_HiTrace_IsTraceEnabled()** API returns **false**. In the **Log** window of the DevEco Studio, input the keyword **not enabled** for filtering and the following log is displayed.

   ```text
   myTraceTest running, trace is not enabled
   ```

   > **NOTE**
   >
   > In the log version, after the **hitrace --trace_finish** command is used to stop capture, the snapshot mode is automatically started and trace capture is enabled. In this case, the **OH_HiTrace_IsTraceEnabled()** API returns **true**, and the preceding log is not printed.