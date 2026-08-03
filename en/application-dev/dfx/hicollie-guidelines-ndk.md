# Using HiCollie to Detect Service Thread Stuck and Jank Events (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-31T01:30:48.945Z pushedAt=2026-07-31T06:59:56.017Z -->

## Overview

[Application freeze (AppFreeze)](appfreeze-guidelines.md) means that an application does not respond to user operations (for example, clicking) for a specified period of time. This topic describes the capabilities provided by the HiCollie module for detecting service thread stuck and jank events and reporting stuck events.

## Availability APIs

| API| Description|
| -------- | -------- |
| OH_HiCollie_Init_StuckDetection | Registers a periodic detection task for app service thread hang. You need to implement a callback function for timed detection of service thread hang.<br/>Default detection time: reports the BUSSINESS_THREAD_BLOCK_3S alarm event at 3s, and reports the BUSSINESS_THREAD_BLOCK_6S hang event at 6s.<br/>**Note:** Use this API in a non-main thread. |
| OH_HiCollie_Init_StuckDetectionWithTimeout | Registers a periodic detection task for app service thread hang. You need to implement a callback function for timed detection of service thread hang.<br/>You can set the hang detection time. The configurable range is [3, 15], in seconds.<br/>**Note:**<br/>- Use this API in a non-main thread.<br/>- This API is supported since API version 18. |
| OH_HiCollie_Init_JankDetection | Registers a callback function for app service thread jank detection.<br/>The thread jank monitoring feature requires you to implement two jank detection callback functions, which are placed before and after the service thread processes events. They serve as instrumentation functions to monitor the execution of service thread event processing.<br/>**Note:** Use this API in a non-main thread. |
| OH_HiCollie_Report | Reports an app service thread hang event, generates a hang fault log, and helps locate app hang issues.<br/>First, call OH_HiCollie_Init_StuckDetection or OH_HiCollie_Init_StuckDetectionWithTimeout to initialize the detection task.<br/>If the task times out, call OH_HiCollie_Report based on the business logic to report the hang event.<br/>**Note:**<br/>- Use this API in a non-main thread.<br/>- This API takes effect only for [release version apps](performance-analysis-kit-terminology.md#applications-of-the-release-version), not for [debug version apps](performance-analysis-kit-terminology.md#applications-of-the-debug-version). |
| OH_HiCollie_ReportInputBlock | Reports an app input unresponsive event, generates a hang fault log, and helps locate app hang issues. On PC or tablet devices, a dialog box also appears, prompting the user to continue waiting or close the app. On other devices, no dialog box appears. The following two approaches are recommended for using this API.<br/>Approach 1 (recommended): Use it together with OH_HiCollie_Report, OH_HiCollie_Init_StuckDetection, or OH_HiCollie_Init_StuckDetectionWithTimeout. The service thread periodically detects its own hang status through the above APIs. When the service thread is hung and an input event (such as a screen tap, mouse click, or keyboard input) occurs, call OH_HiCollie_ReportInputBlock.<br/>Approach 2: If the service thread can detect its own hang status without using OH_HiCollie_Report, OH_HiCollie_Init_StuckDetection, or OH_HiCollie_Init_StuckDetectionWithTimeout, call OH_HiCollie_ReportInputBlock based on the combination of the service thread hang status and input events.<br/>**Note:**<br/>- This API can be used in the main thread. For example, when an input event needs to pass through the main thread before being encapsulated and forwarded to the service thread for processing, you can maintain a status flag when the service thread is hung. The main thread then calls this API based on the service thread hang status flag and the input event.<br/>- This API takes effect only for [release version apps](performance-analysis-kit-terminology.md#applications-of-the-release-version), not for [debug version apps](performance-analysis-kit-terminology.md#applications-of-the-debug-version).<br/>- This API is supported since API version 24. |
| OH_HiCollie_SetFreezeCallback | Sets the freeze callback into the system. The system calls this function when a freeze event occurs.<br/>**Note:** This API is supported since API version 24. |
| OH_HiCollie_AssociateProcessReport | Actively reports a process freeze event. This generates an [app execution timeout event](hiappevent-watcher-apphicollie-events.md).<br/>**Note:** This API is supported since API version 24. |

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiCollie](../reference/apis-performance-analysis-kit/capi-hicollie-h.md).

## Detection Principles

1. For details about the fault specifications of service thread jank events detected by **OH_HiCollie_Init_JankDetection**, see [Main Thread Jank Event Detection Principles](hiappevent-watcher-mainthreadjank-events.md#detection-principles).

2. Service thread stuck events:

   (1) Principles of **OH_HiCollie_Init_StuckDetection**: The watchdog thread of the app periodically performs activation detection on service threads. If the activation detection is not executed for more than 3 seconds, a BUSSINESS_THREAD_BLOCK_3S thread alarm event is reported. If it remains unexecuted for more than 6 seconds, a BUSSINESS_THREAD_BLOCK_6S thread hang event is reported. The two events are matched according to system rules to generate an appfreeze fault log.

   (2) Principles of **OH_HiCollie_Init_StuckDetectionWithTimeout**: The watchdog thread of the app periodically performs activation detection on service threads. If the activation detection is not executed for more than the **stuckTimeout** duration, a BUSSINESS_THREAD_BLOCK_3S alarm event is reported. If it remains unexecuted for more than **stuckTimeout \* 2**, a BUSSINESS_THREAD_BLOCK_6S thread hang event is reported. The two events are matched to generate an appfreeze fault log.

> **NOTE**
>
> When you install and start an app by clicking the **Debug** button in DevEco Studio, the timeout detection mechanism of the current project is automatically disabled. This prevents timeout detection from interfering with your debugging process.

## Log Specifications

1. The fault log file of the service thread stuck event starts with **appfreeze-** and is generated in **Device/data/log/faultlog/faultlogger/**. The log files are named in the format of **appfreeze-application bundle name-application UID-time (milliseconds)**. For details, see [AppFreeze Log Specifications](appfreeze-guidelines.md#log-specifications).

2. For details about the log specifications of **OH_HiCollie_Init_StuckDetection**, see [main thread jank event log specifications](apptask-timeout-guidelines.md#log-specifications).

## How to Develop

The following demonstrates how to add a button in the app and click the button to call the HiCollie NDK APIs.

1. Create a native C++ project in DevEco Studio. The directory structure is as follows:

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

2. Edit the **entry > src > main > cpp > CMakeLists.txt** file in the project to add source files and dynamic libraries:

   ```cmake
   # Add libhilog_ndk.z.so (log output).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. Edit the **entry > src > main > cpp > napi_init.cpp** file in the project, import the dependent files, and define **LOG_TAG**. The following code steps are used to simulate stuck and jank scenarios. Use the code based on your service requirements. The sample code is as follows:

   - Starting from API version 12, **app thread jank detection** is supported: **OH_HiCollie_Init_JankDetection**. The sample code is as follows:

   ```c++
   #include <thread>
   #include <string>
   #include <unistd.h>
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   
   #undef LOG_TAG
   #define LOG_TAG "JankTest"
   
   // Define two callback function objects.
   static OH_HiCollie_BeginFunc beginFunc_;
   static OH_HiCollie_EndFunc endFunc_;
   
   // Define the callback functions for monitoring the start and end of app display.
   void InitBeginFunc(const char* eventName)
   {
       std::string str(eventName);
       OH_LOG_INFO(LogType::LOG_APP, "InitBeginFunc eventName: %{public}s", str.c_str());
   }
   void InitEndFunc(const char* eventName)
   {
       std::string str(eventName);
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_EndFunc eventName: %{public}s", str.c_str());
   }
   
   void StartDelayTimer()
   {
     // Wait for 1s.
     std::chrono::seconds delay(1);
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection delay before");
     std::this_thread::sleep_for(delay);
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection delay after");
   }
   
   // Define the sub-thread callback function.
   void TestJankDetection()
   {
       // Initialize the callback parameters.
       beginFunc_ = InitBeginFunc;
       endFunc_ = InitEndFunc;
       HiCollie_DetectionParam param {0};
       // Initialize the thread jank detection function.
       int initResult = OH_HiCollie_Init_JankDetection(&beginFunc_, &endFunc_, param);
       // Set the thread to be not detected within 1s after being started.
       StartDelayTimer();
       // Success result: 0
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection: %{public}d", initResult);
       int count = 0;
       while (count < 3) {
           // Set the callback used to record the start time of the processing event.
           beginFunc_("TestBegin");
           // Simulate a thread jank event by putting the thread to sleep for 350 ms.
           usleep(350 * 1000);
           // Set the callback used to record the end time of the processing event.
           endFunc_("TestEnd");
           count++;
       }
   }
   
   static napi_value TestHiCollieJankNdk(napi_env env, napi_callback_info info)
   {
       // Create a subthread.
       std::thread threadObj(TestJankDetection);
       // Execute the TestJankDetection task.
       threadObj.join();
       return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieJankNdk", nullptr, TestHiCollieJankNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
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

   - Starting from API version 12, **app thread hang detection** is supported: **OH_HiCollie_Init_StuckDetection**. The sample code is as follows:

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   #include <atomic>
   #include <thread>
   #include <string>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "StuckTest"
   
   // Custom block time for simulating a hang scenario, in seconds.
   const int64_t BLOCK_TIME = 3; 
   // Flag indicating the app thread task execution status. true: normal, false: hang.
   std::shared_ptr<std::atomic<bool>> appThreadIsAlive_ = std::make_shared<std::atomic<bool>>(true);
   // Flag for reporting an app thread hang event.
   std::shared_ptr<std::atomic<bool>> isSixSecondEvent_ = std::make_shared<std::atomic<bool>>(false);
   
   void ReportEvent() {
       bool temp = isSixSecondEvent_->load();
       int reportResult = OH_HiCollie_Report(&temp);
       // Success: 0
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report: %{public}d, isSixSecondEvent: %{public}d", reportResult, isSixSecondEvent_->load());
       isSixSecondEvent_->store(temp);
   }
   
   void SetTimeout()
   {
     int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     sleep(BLOCK_TIME);
     int64_t currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     if (currentTime - now < BLOCK_TIME) {
       appThreadIsAlive_->store(true);
       return;
     }
     appThreadIsAlive_->store(false);
   }
   
   // You can customize the periodic detection task.
   void Timer()
   {
     // Check whether the app is executing tasks normally every 3s.
     if (appThreadIsAlive_->load()) {
       OH_LOG_INFO(LogType::LOG_APP, "Check appThread isAlive.");
       // Update appThreadIsAlive_. It is set to true for the next normal detection.
       appThreadIsAlive_->store(false);
       // Simulate a timeout scenario.
       SetTimeout();
       return;
     }
     ReportEvent();
   }
   
   // Define the child thread callback function.
   void InitStuckDetection()
   {
     // Initialize the thread hang monitoring function.
     int initResult = OH_HiCollie_Init_StuckDetection(Timer);
     // Success result: 0
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetection: %{public}d", initResult);
   }
   
   static napi_value TestHiCollieStuckNdk(napi_env env, napi_callback_info info)
   {
     // Create a child thread.
     std::thread threadObj(InitStuckDetection);
     // Execute the task.
     threadObj.join();
     return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieStuckNdk", nullptr, TestHiCollieStuckNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
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

   - Starting from API version 18, **app thread hang detection with a custom detection duration** is supported: **OH_HiCollie_Init_StuckDetectionWithTimeout**. The sample code is as follows:

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   #include <thread>
   #include <string>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "StuckTest"
   
   // Custom sleep time for simulating a hang scenario.
   const int64_t BLOCK_TIME = 5; 
   // Flag indicating the app thread task execution status. true: normal, false: hang.
   std::shared_ptr<std::atomic<bool>> appThreadIsAlive_ = std::make_shared<std::atomic<bool>>(true);
   // Flag for reporting an app thread hang event.
   std::shared_ptr<std::atomic<bool>> isSixSecondEvent_ = std::make_shared<std::atomic<bool>>(false);
   
   void ReportEvent() {
       bool temp = isSixSecondEvent_->load();
       int reportResult = OH_HiCollie_Report(&temp);
       // Success: 0
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report: %{public}d, isSixSecondEvent: %{public}d", reportResult, isSixSecondEvent_->load());
       isSixSecondEvent_->store(temp);
   }
   
   void SetTimeout()
   {
     int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     sleep(BLOCK_TIME);
     int64_t currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     if (currentTime - now < BLOCK_TIME) {
       appThreadIsAlive_->store(true);
       return;
     }
     appThreadIsAlive_->store(false);
   }
   
   // You can customize the periodic detection task.
   void Timer()
   {
     // Check whether the app is executing tasks normally every 5s.
     if (appThreadIsAlive_->load()) {
       OH_LOG_INFO(LogType::LOG_APP, "Check appThread isAlive.");
       // Update appThreadIsAlive_. It is set to true for the next normal detection.
       appThreadIsAlive_->store(false);
       // Simulate a timeout scenario.
       SetTimeout();
       return;
     }
     ReportEvent();
   }
   
   // Define the child thread callback function.
   void InitStuckDetectionWithTimeout()
   {
     // Initialize the thread hang monitoring function.
     int initResult = OH_HiCollie_Init_StuckDetectionWithTimeout(Timer, BLOCK_TIME);
     // Success result: 0
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetectionWithTimeout: %{public}d", initResult);
   }
   
   static napi_value TestHiCollieStuckWithTimeoutNdk(napi_env env, napi_callback_info info)
   {
     // Create a child thread.
     std::thread threadObj(InitStuckDetectionWithTimeout);
     // Execute the task.
     threadObj.join();
     return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieStuckWithTimeoutNdk", nullptr, TestHiCollieStuckWithTimeoutNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
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

   - Starting from API version 24, **app thread hang detection with proactive reporting of input unresponsiveness faults** is supported: **OH_HiCollie_ReportInputBlock**. The sample code is as follows:

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   #include <atomic>
   #include <thread>
   #include <string>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "StuckTest"
   
   // Customize the blocking time (unit: s) to simulate a stuck scenario.
   const int64_t BLOCK_TIME = 3; 
   // Set the task execution status flag of the application thread. The value true indicates the thread is normal and the value false indicates the thread is stuck.
   std::shared_ptr<std::atomic<bool>> appThreadIsAlive_ = std::make_shared<std::atomic<bool>>(true);
   // Set the flag for reporting the application thread stuck event.
   std::shared_ptr<std::atomic<bool>> isSixSecondEvent_ = std::make_shared<std::atomic<bool>>(false);
   
   void ReportEvent() {
       bool temp = isSixSecondEvent_->load();
       int reportResult = OH_HiCollie_Report(&temp);
       // Success result: 0
       OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report: %{public}d, isSixSecondEvent: %{public}d", reportResult, isSixSecondEvent_->load());
       isSixSecondEvent_->store(temp);
   }
   
   void SetTimeout()
   {
     int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     sleep(BLOCK_TIME);
     int64_t currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
       system_clock::now().time_since_epoch()).count();
     if (currentTime - now < BLOCK_TIME) {
       appThreadIsAlive_->store(true);
       return;
     }
     appThreadIsAlive_->store(false);
   }
   
   // You can customize periodic detection tasks.
   void Timer()
   {
     // Check whether the application thread runs properly every 3 seconds.
     if (appThreadIsAlive_->load()) {
       OH_LOG_INFO(LogType::LOG_APP, "Check appThread isAlive.");
       // Update appThreadIsAlive_. The value true indicates that the application thread runs properly.
       appThreadIsAlive_->store(false);
       // Simulate a timeout scenario.
       SetTimeout();
       return;
     }
     ReportEvent();
   }
   
   // Define the sub-thread callback function.
   void InitStuckDetection()
   {
     // Initialize the thread stuck detection function.
     int initResult = OH_HiCollie_Init_StuckDetection(Timer);
     // Success result: 0
     OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetection: %{public}d", initResult);
   }
   
   static napi_value TestHiCollieStuckNdk(napi_env env, napi_callback_info info)
   {
     // Create a subthread.
     std::thread threadObj(InitStuckDetection);
     // Execute a task.
     threadObj.join();
     return 0;
   }
   
   static napi_value TestHiCollieInputBlock(napi_env env, napi_callback_info info)
   {
     // The sub-thread is not hung, and no report is made.
     if (appThreadIsAlive_->load()) {
       return 0;
     }
     OH_HiCollie_ReportInputBlock();
     return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieStuckNdk", nullptr, TestHiCollieStuckNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "testHiCollieInputBlock", nullptr, TestHiCollieInputBlock, nullptr, nullptr, nullptr, napi_default, nullptr}
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

   - Starting from API version 24, **app thread hang detection with custom log generation by third-party frameworks** is supported: **OH_HiCollie_SetFreezeCallback** and **OH_HiCollie_AssociateProcessReport**. The sample code is as follows:

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hicollie/hicollie.h"
   #include <thread>
   #include <string>
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "StuckTest"
   
   static size_t UserCall(OH_HiCollie_Freeze_Type type, void* buffer, size_t size)
   {
      std::string source("Freeze is happened");
      if (type == OH_THREAD_BLOCK_3S) {
          source += ":block 3s";
      } else if (type == OH_THREAD_BLOCK_6S) {
          source += ":block 6s";
      } else {
          source += ":other block";
      }
      char* buffer1 = (char*)buffer;
      int needed = snprintf(buffer1, size, "UserCallback%s", source.c_str());
      return needed; 
   }
   
   static napi_value TestHiCollieSetFreezeCallback(napi_env env, napi_callback_info info)
   {
      // Set the user callback.
      OH_HiCollie_SetFreezeCallback(UserCall);
      return 0;
   }
   
   static napi_value TestHiCollieAssociateProcessReport(napi_env env, napi_callback_info info)
   {
      // Report the BUSINESS_THREAD_BLOCK_3S event.
      OH_HiCollie_AssociateProcessReport(false);
      sleep(3);
      // Report the BUSINESS_THREAD_BLOCK_6S event.
      OH_HiCollie_AssociateProcessReport(true);
      return 0;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiCollieSetFreezeCallback", nullptr, TestHiCollieSetFreezeCallback, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "testHiCollieAssociateProcessReport", nullptr, TestHiCollieAssociateProcessReport, nullptr, nullptr, nullptr, napi_default, nullptr }
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

4. Edit the **Index.ets** file under **entry > src > main > cpp > types > libentry** in the project to define the ArkTS APIs.

   - Example for **OH_HiCollie_Init_JankDetection**:

   ```ts
   export const testHiCollieJankNdk: () => void;
   ```

   - Example for **OH_HiCollie_Init_StuckDetection**:

   ```ts
   export const testHiCollieStuckNdk: () => void;
   ```

   - Example for **OH_HiCollie_Init_StuckDetectionWithTimeout**:

   ```ts
   export const testHiCollieStuckWithTimeoutNdk: () => void;
   ```

    - Example for **OH_HiCollie_ReportInputBlock**:

   ```ts
   export const testHiCollieStuckNdk: () => void;
   export const testHiCollieInputBlock: () => void;
   ```

    - Example for **OH_HiCollie_SetFreezeCallback** and **OH_HiCollie_AssociateProcessReport**:

   ```ts
   export const testHiCollieSetFreezeCallback: () => void;
   export const testHiCollieAssociateProcessReport: () => void;
   ```

5. Edit the **entry > src > main > ets > pages > Index.ets** file in the project:

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     build() {
       RelativeContainer() {
         Column() {
           // Select the corresponding function below and add different click events here.
           
         }
         .width('100%')
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

   - Add a click event to trigger the **OH_HiCollie_Init_JankDetection** method.

   ```ts
   Column() {
     Button("testHiCollieJankNdk", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieJankNdk);
   }
   ```

   - Add a click event to trigger the **OH_HiCollie_Init_StuckDetection** method.

   ```ts
   Column() {
     Button("testHiCollieStuckNdk", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieStuckNdk);
   }
   ```

   - Add a click event to trigger the **OH_HiCollie_Init_StuckDetectionWithTimeout** method.

   ```ts
   Column() {
     Button("testHiCollieStuckWithTimeoutNdk", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieStuckWithTimeoutNdk);
   }
   ```

    - Add a click event to trigger the **OH_HiCollie_Init_StuckDetectionWithTimeout** method and the **OH_HiCollie_ReportInputBlock** method.

   ```ts
   Column() {
     Button("testHiCollieStuckNdk", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieStuckNdk);
     Button("testHiCollieInputBlock", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieInputBlock);
   }
   ```

    - Add a click event to trigger the **OH_HiCollie_SetFreezeCallback** method and the **OH_HiCollie_AssociateProcessReport** method.

   ```ts
   Column() {
     Button("testHiCollieSetFreezeCallback", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieSetFreezeCallback);
     Button("testHiCollieAssociateProcessReport", { stateEffect:true, type: ButtonType.Capsule})
       .width('75%')
       .height(50)
       .margin(15)
       .fontSize(20)
       .fontWeight(FontWeight.Bold)
       .onClick(testNapi.testHiCollieAssociateProcessReport);
   }
   ```

6. Click the **Run** button in DevEco Studio to run the project.

7. At the bottom of DevEco Studio, switch to the **Log** tab and filter the custom **LOG_TAG**.

   - Click the **testHiCollieJankNdk** button.

   The thread timeout information of the sampling stack obtained through **OH_HiCollie_Init_JankDetection()** is displayed. You can obtain the corresponding event by [subscribing to the main thread jank event](hiappevent-watcher-mainthreadjank-events-arkts.md).

   - Click the **testHiCollieStuckNdk** button.

   The callback used for detecting stuck events is initialized through **OH_HiCollie_Init_StuckDetection()**. You can define the detection function for stuck events as required.

   - Click the **testHiCollieStuckWithTimeoutNdk** button.

   The callback used for detecting stuck events is initialized through **OH_HiCollie_Init_StuckDetectionWithTimeout**. You can define the detection function and time for stuck events as required.

   - First click the **testHiCollieStuckNdk** button, and then repeatedly click the **testHiCollieInputBlock** button.

   At this point, the window displays that the hang detection callback function is initialized through the **OH_HiCollie_Init_StuckDetection** API. On a PC or tablet device, clicking the **testHiCollieInputBlock** button within the first 6 seconds does not trigger a dialog box, but subsequent clicks on the button will trigger one. You can define the hang detection function or the conditions for input event judgment based on your actual service scenarios.

   - First click the **testHiCollieSetFreezeCallback** button, and then click the **testHiCollieAssociateProcessReport** button.

   At this point, the window displays that a custom log function is set through the **OH_HiCollie_SetFreezeCallback** API, and then a thread timeout event is reported through the **OH_HiCollie_AssociateProcessReport** API. Subsequently, an [APP_HICOLLIE](hiappevent-watcher-apphicollie-events.md) event is generated, which contains the callback log field.