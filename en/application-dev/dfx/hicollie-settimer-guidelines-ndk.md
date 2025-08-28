# Using HiCollie to Detect Function Execution Timeout Events (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Overview

Task execution timeout indicates that the execution duration of the monitored service code logic exceeds the expected duration. This topic describes the capability of the HiCollie module to detect function execution timeout events.

## Available APIs

| API| Description|
| -------- | -------- |
| OH_HiCollie_SetTimer | Sets a timer to check whether the execution time of a function or code block exceeds the custom time.<br>This API is used before the time-consuming function is called. It must be used together with the **OH_HiCollie_CancelTimer** API.<br>Note: This API is supported since API version 18.|
| OH_HiCollie_CancelTimer | Cancels a timer based on task ID.<br>This API is used after the function or code block is executed. It must be used together with the **OH_HiCollie_SetTimer** API.<br>If the timer is not canceled within the custom time, a callback function is executed to generate fault logs for the specified timeout event.<br>Note: This API is supported since API version 18.|

- For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiCollie](../reference/apis-performance-analysis-kit/capi-hicollie-h.md).

- The fault log file is saved in the **/data/log/faultlog/faultlogger/** directory. The file name format is **syswarning-application bundle name-application UID-second-level time.log**.

## How to Develop

The following describes how to add a button in the application and click the button to call the HiCollie APIs.

1. Create a native C++ project. The directory structure is as follows:

   ```yml
   entry:
     src:
       main:
         cpp:
           types:
             libentry:
               - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           entryability:
             - EntryAbility.ts
           pages:
             - Index.ets
   ```

2. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add libhilog_ndk.z.so (log output) and libohhicollie.so (HiCollie external APIs).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. In the **napi_init.cpp** file, import dependency header files, define **LOG_TAG** and test methods, and register **TestHiCollieTimerNdk** as an ArkTS API.

   ```c++
   #include "napi/native_api.h"
   #include "hicollie/hicollie.h"
   #include "hilog/log.h"
   
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
   // Define the callback.
   void CallBack(void*)
   {
     OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimerNdk CallBack");  // Logs are printed in the callback.
   }
   
   static napi_value TestHiCollieTimerNdk(napi_env env, napi_callback_info info)
   {
     int id;
     HiCollie_SetTimerParam param = {"testTimer", 1, CallBack, nullptr, HiCollie_Flag::HICOLLIE_FLAG_LOG};  // Set HiCollieTimer parameters (timer name, timeout interval, callback, callback parameters, and behavior after timeout).
     HiCollie_ErrorCode errorCode = OH_HiCollie_SetTimer(param, &id);  // Register a HiCollieTimer function to execute a one-off timeout detection task.
     if (errorCode == HICOLLIE_SUCCESS) {  // The HiCollieTimer task is successfully registered.
       OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimer taskId: %{public}d", id); // Log the task ID.
       sleep (2); // Simulate a time-consuming function to block the thread for 2s.
       OH_HiCollie_CancelTimer (id); // Cancel the registered timer based on the ID.
     }
     return nullptr;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "TestHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr }      // Register TestHiCollieTimerNdk as an ArkTS API.
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

4. In the **index.d.ts** file, define the ArkTS API.

   ```ts
   export const TestHiCollieTimerNdk: () => void;
   ```

5. Edit the **Index.ets** file.

   ```ts
   import testNapi from 'libentry.so';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Button("TestHiCollieTimerNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.TestHiCollieTimerNdk);  //Add a click event to trigger the testHiCollieTimerNdk method.
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. Click the **Run** button in DevEco Studio to run the project.

7. At the bottom of DevEco Studio, switch to the **Log** tab, choose **HiLog** and set the filter criteria to **testTag**.

   (1) Click the **testHiCollieTimerNdk** button to execute the timer, and the task ID is logged.

   ```
   .../testTag ... HiCollieTimer taskId: x
   ```

   (2) After 2s, the callback function is executed and logs are displayed.

   ```
   .../testTag ... HiCollieTimerNdk CallBack
   ```

   For details about how to obtain the fault file information, see [Subscribing to Task Execution Timeout Events (C/C++)](hiappevent-watcher-apphicollie-events-ndk.md).
