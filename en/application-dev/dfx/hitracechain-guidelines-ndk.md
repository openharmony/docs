# Using hiTraceChain (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Available APIs

The APIs for distributed call chain tracing are provided by the HiTraceChain module. For details, see [trace.h](../reference/apis-performance-analysis-kit/capi-trace-h.md).

The following table lists the APIs provided by HiTraceChain for implementing the basic distributed tracing functionality. The corresponding APIs are also available in ArkTS.

| API| Description| 
| -------- | -------- |
| HiTraceId OH_HiTrace_BeginChain(const char \*name, int flags) | Starts call chain tracing and returns the created **HiTraceId**.| 
| void OH_HiTrace_EndChain() | Stops call chain tracing.| 
| HiTraceId OH_HiTrace_GetId() | Obtains the trace ID in TLS of the calling thread.| 
| void OH_HiTrace_SetId(const HiTraceId \*id) | Sets the trace ID in TLS of the calling thread to **id**.| 
| void OH_HiTrace_ClearId(void) | Clears the trace ID of the current thread.| 
| HiTraceId OH_HiTrace_CreateSpan(void) | Creates a trace span. Specifically, create a **HiTraceId**, use the **chainId** and **spanId** in the Thread-Local Storage (TLS) of the current thread to initialize the **chainId** and **parentSpanId** of the **HiTraceId**, generate a new **spanId** for the **HiTraceId**, and return the **HiTraceId**.| 
| bool OH_HiTrace_IsIdValid(const HiTraceId \*id) | Checks whether the **HiTraceId** is valid.<br>The value **true** indicates that **HiTraceId** is valid, and **false** indicates the opposite.| 
| bool OH_HiTrace_IsFlagEnabled(const HiTraceId \*id, HiTrace_Flag flag) | Checks whether the trace flag specified by **HiTraceId** is enabled.<br>The value **true** indicates that the specified trace flag is enabled, and **false** indicates the opposite.| 
| void OH_HiTrace_EnableFlag(const HiTraceId \*id, HiTrace_Flag flag) | Enables the trace flag specified in **HiTraceId**.| 
| void OH_HiTrace_Tracepoint(HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type, const HiTraceId \*id, const char \*fmt, ...) | Adds a trace point for the HiTraceMeter logging.| 

The following table describes the APIs provided to extend **HiTraceId**. These APIs are available only in C/C++.

| API| Description| 
| -------- | -------- |
| void OH_HiTrace_InitId(HiTraceId \*id) | Initializes a **HiTraceId**.| 
| int OH_HiTrace_GetFlags(const HiTraceId \*id) | Obtains the trace flag set in **HiTraceId**.| 
| void OH_HiTrace_SetFlags(HiTraceId \*id, int flags) | Sets the trace flag in **HiTraceId**.| 
| uint64_t OH_HiTrace_GetChainId(const HiTraceId \*id) | Obtains the trace chain ID in **HiTraceId**.| 
| void OH_HiTrace_SetChainId(HiTraceId \*id, uint64_t chainId) | Sets the trace chain ID in **HiTraceId**.| 
| uint64_t OH_HiTrace_GetSpanId(const HiTraceId \*id) | Obtains the span ID in **HiTraceId**.| 
| void OH_HiTrace_SetSpanId(HiTraceId \*id, uint64_t spanId) | Sets the span ID in **HiTraceId**.| 
| uint64_t OH_HiTrace_GetParentSpanId(const HiTraceId \*id) | Obtains the parent span ID in **HiTraceId**.| 
| void OH_HiTrace_SetParentSpanId(HiTraceId \*id, uint64_t parentSpanId) | Sets the parent span ID in **HiTraceId**.| 
| int OH_HiTrace_IdToBytes(const HiTraceId\* id, uint8_t\* pIdArray, int len) | Converts **HiTraceId** into a byte array for cache or communication.| 
| void OH_HiTrace_IdFromBytes(HiTraceId \*id, const uint8_t \*pIdArray, int len) | Creates a **HiTraceId** based on a byte array.| 


## How to Develop

**std::thread** does not support automatic transfer of **HiTraceId**. The following example shows how to use distributed tracing in this scenario. For details about the common mechanisms that support and do not support HiTraceChain automatic transfer, see [Constraints](hitracechain-intro.md#constraints).

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

2. In the **entry > src > main > cpp > CMakeLists.tx** file, add **libhitrace_ndk.z.so** and **libhilog_ndk.z.so**. The complete file content is as follows:

   ```cmake
   # Minimum version of CMake.
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

3. In the **entry > src > main > cpp > napi_init.cpp** file, use HiTraceChain to trace multi-thread tasks. The sample code is as follows:

   ```cpp
   #include <thread>
   
   #include "hilog/log.h"
   #include "hitrace/trace.h"
   #include "napi/native_api.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
   void Print2(HiTraceId id)
   {
       // Set a HiTraceId for the thread.
       OH_HiTrace_SetId(&id);
       // Generate a spanId.
       id = OH_HiTrace_CreateSpan();
       // Set a HiTraceId with the spanId for the thread.
       OH_HiTrace_SetId(&id);
       OH_LOG_INFO(LogType::LOG_APP, "Print2");
       // End the distributed tracing of the thread. This functionality is the same as that of OH_HiTrace_EndChain().
       OH_HiTrace_ClearId();
       OH_LOG_INFO(LogType::LOG_APP, "Print2, HiTraceChain end");
   }

   void Print1(HiTraceId id)
   {
       // Set a HiTraceId for the thread.
       OH_HiTrace_SetId(&id);
       // Generate a spanId.
       id = OH_HiTrace_CreateSpan();
       // Set a HiTraceId with the spanId for the thread.
       OH_HiTrace_SetId(&id);
       OH_LOG_INFO(LogType::LOG_APP, "Print1");
       std::thread(Print2, OH_HiTrace_GetId()).detach();
       // End the distributed tracing of the thread.
       OH_HiTrace_EndChain();
       OH_LOG_INFO(LogType::LOG_APP, "Print1, HiTraceChain end");
   }
   
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // Start distributed tracing when the task starts.
       HiTraceId hiTraceId = OH_HiTrace_BeginChain("testTag: hiTraceChain begin", HiTrace_Flag::HITRACE_FLAG_DEFAULT);
       // Check whether the generated hiTraceId is valid. If yes, a HiLog log is generated.
       if (OH_HiTrace_IsIdValid(&hiTraceId)) {
           OH_LOG_INFO(LogType::LOG_APP, "HiTraceId is valid");
       }
       // Enable the HITRACE_FLAG_INCLUDE_ASYNC flag, indicating that HiTraceId is automatically transferred in the asynchronous mechanism supported by the system.
       OH_HiTrace_EnableFlag(&hiTraceId, HiTrace_Flag::HITRACE_FLAG_INCLUDE_ASYNC);
       // Check whether the HITRACE_FLAG_INCLUDE_ASYNC flag of HiTraceId is enabled. If yes, set the HiTraceId to the thread TLS.
       if (OH_HiTrace_IsFlagEnabled(&hiTraceId, HiTrace_Flag::HITRACE_FLAG_INCLUDE_ASYNC)) {
           OH_HiTrace_SetId(&hiTraceId);
           OH_LOG_INFO(LogType::LOG_APP, "HITRACE_FLAG_INCLUDE_ASYNC is enabled");
       }
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
   
       // Create a thread to execute the print task and transfer the HiTraceId of the thread.
       std::thread(Print1, OH_HiTrace_GetId()).detach();
       // Stop the distributed tracing when the task is complete.
       OH_HiTrace_EndChain();
       OH_LOG_INFO(LogType::LOG_APP, "Add, HiTraceChain end");
   
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

   In the **entry > src > main > ets > pages > Index.ets** file, call the **Add** method in the button click event. The sample code is as follows:

   ```ts
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   
   const DOMAIN = 0x0000;
   
   @Entry
   @Component
   struct Index {
     @State message: string = "clickTime=0";
     @State clickTime: number = 0;
   
     build() {
       Row() {
         Column() {
           Button(this.message)
             .fontSize(20)
             .margin(5)
             .width(350)
             .height(60)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               this.clickTime++;
               this.message = "clickTime=" + this.clickTime;
               hilog.info(DOMAIN, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

4. Click the **Run** button in DevEco Studio to run the project. Then, click **clickTime=0** on the device to trigger the service logic.

5. In the **Log** window of DevEco Studio, view the distributed tracing information.
   - If **clickTime=1** is displayed on the device screen, the button is clicked once and the service logic is triggered.
   - All HiLog logs in this example use **testTag**. You can filter logs by the keyword **testTag** to view the HiLog logs printed by the service code.

      ```txt
      06-05 21:26:01.006   9944-9944     C02D33/com.exa...tion/HiTraceC  com.examp...lication  I     [a92ab19ae90197d 0 0]HiTraceBegin name:testTag: hiTraceChain begin flags:0x00.
      06-05 21:26:01.006   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 0 0]HiTraceId is valid
      06-05 21:26:01.006   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 0 0]HITRACE_FLAG_INCLUDE_ASYNC is enabled
      06-05 21:26:01.007   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     Add, HiTraceChain end
      06-05 21:26:01.007   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     Test NAPI 2 + 3 = 5
      06-05 21:26:01.007   9944-13961    A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 2544fdb 0]Print1
      06-05 21:26:01.007   9944-13961    A00000/com.exa...ation/testTag  com.examp...lication  I     Print1, HiTraceChain end
      06-05 21:26:01.008   9944-13962    A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 236699a 2544fdb]Print2
      06-05 21:26:01.008   9944-13962    A00000/com.exa...ation/testTag  com.examp...lication  I     Print2, HiTraceChain end
      ```

   - The **[chainId spanId parentSpanId]** information added before the HiLog log is **HiTraceId** information. For example, **[a92ab19ae90197d 236699a 2544fdb]** indicates that the trace chain ID (**chainId**) is **a92ab19ae90197d**, the span ID (**spanId**) is **236699a**, and the parent span ID (**parentSpanId**) is **2544fdb**.
   - Transfer the **HiTraceId**, create a **spanId**, and set it to the child thread created by **std::thread**. The HiLog logs of the Print1 and Print2 services running in the child thread also carry the same trace ID **a92ab19ae90197d** as that of the main thread.
   - After the distributed tracing is ended using **OH_HiTrace_EndChain** or **OH_HiTrace_ClearId**, the HiLog print information does not carry the **HiTraceId** information.
