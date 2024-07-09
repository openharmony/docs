# Using HiTraceMeter (C/C++)

**HiTrace** provides APIs to implement call chain tracing throughout a service process. You can use these APIs to quickly obtain the run log specific to the call chain of a service process and locate faults in inter-device, inter-process, or inter-thread communications.

## Available APIs

The performance tracing APIs are provided by the **HiTraceMeter** module. For details, see [Hitrace](../reference/apis-performance-analysis-kit/_hitrace.md).

| API| Description|
| -------- | -------- |
| void OH_HiTrace_StartTrace(const char* name) | Starts a synchronous time slice trace.|
| void OH_HiTrace_FinishTrace() | Ends a synchronous time slice trace.|
| void OH_HiTrace_StartAsyncTrace(const char* name, int32_t taskId) | Starts an asynchronous time slice trace.|
| void OH_HiTrace_FinishAsyncTrace(const char* name, int32_t taskId) | Ends an asynchronous time slice trace.|
| void OH_HiTrace_CountTrace(const char* name, int64_t count) | Performs an integer trace.|

**Parameter Description**

| Name| Type| Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | Yes  | Name of the variable.|
| taskId | number | Yes  | ID used to indicate the association of APIs in a trace. If multiple traces with the same name need to be performed at the same time, different task IDs must be specified in **startTrace**.|
| count  | number | Yes  | Value of the variable. |

## How to Develop

1. Add **libhitrace_ndk.z.so** to **CMakeLists.txt**.

    ```
    target_link_libraries(entry PUBLIC libhitrace_ndk.z.so)
    ```

2. Include the **trace.h** header file in the source file. 

    ```c++
    #include "hitrace/trace.h"
    ```

3. Trace performance data. The following uses an asynchronous trace as an example. (The sample code is a part of the default **hello.cpp** file. You only need to add related APIs at the required positions. For details about the APIs, see "Available APIs".)

    ```c++
    #include "napi/native_api.h"
    #include "hitrace/trace.h"
    static napi_value Add(napi_env env, napi_callback_info info)
    {
        // Start an asynchronous time slice trace.
        OH_HiTrace_StartAsyncTrace("hitraceTest", 123);
        // End the asynchronous time slice trace (The start and end points are for reference only. Add them to the code lines where you want to start and end the trace.)
        OH_HiTrace_FinishAsyncTrace("hitraceTest", 123);
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

4. Install the compiled HAP in the device. In the **cmd** window, run **hdc shell** to connect to the device, and run **hitrace --trace_begin app** to start trace.
    
    ```shell
    capturing trace...
    ```

5. Click the newly installed HAP several times on the device, and then run **hitrace --trace_dump | grep hitraceTest** in the **shell** window to view the trace result.
    
    ```shell
    <...>-2477    (-------) [001] ....   396.427165: tracing_mark_write: S|2477|H:hitraceTest 123
    <...>-2477    (-------) [001] ....   396.427196: tracing_mark_write: F|2477|H:hitraceTest 123
    ```
