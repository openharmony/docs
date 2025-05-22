# Using hiTraceChain (C/C++)

## Overview

hiTraceChain is a lightweight implementation of the cloud-based distributed call chain tracing on the device side. It allows the calls made in a service process to be traced, helping locating issues across threads, processes, and devices. With hiTraceChain, a unique ID is generated for a service process, passed throughout the service process, and associated with various output information (including application events, system time, and logs). During debugging and fault locating, you can use this unique ID to quickly correlate various information related to the service process. hiTraceChain provides APIs to implement call chain tracing throughout a service process. This can help you quickly obtain the run log for the call chain of a service process and locate faults across devices, processes, and threads.

## Available APIs

The APIs for distributed call chain tracing are provided by the **hiTraceChain** module. For details, see [Hitrace](../reference/apis-performance-analysis-kit/_hitrace.md).

| API| Description|
| -------- | -------- |
| HiTraceId OH_HiTrace_BeginChain(const char *name, int flags) | Starts call chain tracing.|
| void OH_HiTrace_EndChain() | Stops call chain tracing.|
| HiTraceId OH_HiTrace_GetId() | Obtains the trace ID in TLS of this thread. |
| void OH_HiTrace_SetId(const HiTraceId *id) | Sets the trace ID of this thread.|
| void OH_HiTrace_ClearId(void) | Clears the trace ID of this thread and invalidates it.|
| HiTraceId OH_HiTrace_CreateSpan(void) | Creates a span ID based on the trace ID of this thread.|
| void OH_HiTrace_Tracepoint(HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type, const HiTraceId *id, const char *fmt, ...) | Prints HiTrace information, including the trace ID.|
| void OH_HiTrace_InitId(HiTraceId *id) | Initializes a **HiTraceId** instance.|
| void OH_HiTrace_IdFromBytes(HiTraceId *id, const uint8_t *pIdArray, int len) | Creates a **HiTraceId** instance based on a byte array.|
| bool OH_HiTrace_IsIdValid(const HiTraceId *id) | Checks whether a trace ID is valid.|
| bool OH_HiTrace_IsFlagEnabled(const HiTraceId *id, HiTrace_Flag flag) | Checks whether the specified trace flag is enabled in a **HiTraceId** instance .|
| void OH_HiTrace_EnableFlag(const HiTraceId *id, HiTrace_Flag flag) | Enables the specified trace flag in a **HiTraceId** instance.|
| int OH_HiTrace_GetFlags(const HiTraceId *id) | Obtains the trace flags in a **HiTraceId** instance.|
| void OH_HiTrace_SetFlags(HiTraceId *id, int flags) | Sets trace flags in a **HiTraceId** instance.|
| uint64_t OH_HiTrace_GetChainId(const HiTraceId *id) | Obtains a trace chain ID.|
| void OH_HiTrace_SetChainId(HiTraceId *id, uint64_t chainId) | Sets the trace chain ID in a **HiTraceId** instance.|
| uint64_t OH_HiTrace_GetSpanId(const HiTraceId *id) | Obtains the span ID in a **HiTraceId** instance.|
| void OH_HiTrace_SetSpanId(HiTraceId *id, uint64_t spanId) | Sets the span ID in a **HiTraceId** instance.|
| uint64_t OH_HiTrace_GetParentSpanId(const HiTraceId *id) | Obtains the parent span ID in a **HiTraceId** instance.|
| void OH_HiTrace_SetParentSpanId(HiTraceId *id, uint64_t parentSpanId) | Sets the parent span ID in a **HiTraceId** instance.|
| int OH_HiTrace_IdToBytes(const HiTraceId* id, uint8_t* pIdArray, int len) | Converts a **HiTraceId** instance into a byte array for caching or transfer.|


## Example

1. Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**.
    The code of **index.ets** is as follows. The function **testNapi.add()** defined in **hello.cpp** is called in **onClick()**.
    ```
    import hilog from '@ohos.hilog';
    import testNapi from 'libentry.so'

    @Entry
    @Component
    struct Index {
        @State message: string = 'Hello World'

        build() {
            Row() {
            Column() {
                Text(this.message)
                .fontSize(50)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                    hilog.info(0x0000, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));
                })
            }
            .width('100%')
            }
            .height('100%')
        }
    }

2. Add the link of **libhitrace_ndk.z.so** to **CMakeLists.txt**.

    ```
   // CMakeLists.txt
   # Minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(MyApplication)
   
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   add_library(entry SHARED hello.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhitrace_ndk.z.so)
   ```

3. Include the hiTrace header file in the **hello.cpp** file. 

    ```c++
    #include "hitrace/trace.h"
    ```

4. In **Add()** of **hello.cpp**, use **OH_HiTrace_BeginChain()** to start a trace and use **OH_HiTrace_EndChain()** to stop the trace.

    ```c++
    #include "napi/native_api.h"
    #include "hitrace/trace.h"
    static napi_value Add(napi_env env, napi_callback_info info)
    {
        // Start distributed tracing. 
        OH_HiTrace_BeginChain("hitraceTest", HITRACE_FLAG_DEFAULT);
        // Stop distributed tracing. (This is for reference only. Set the start and stop points to match your case.)
        OH_HiTrace_EndChain();
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

5. Run the project, and an HAP application is generated on the device. Click "Hello World". The **Add()** function in **hello.cpp** will be called. View the trace log, which is as follows:
    ```text
    11-02 15:13:28.922  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][dict]HiTraceBegin name:hitraceTest event flags:0x01.
    11-02 15:13:28.930  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0][dict]HiTraceEnd.
   ```
