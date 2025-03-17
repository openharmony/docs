# Using HiCollie to Detect Service Thread Stuck and Jank Events (C/C++)

## Overview

HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events.

## Availability APIs

| API                         | Description                             |
| ------------------------------- | --------------------------------- |
| OH_HiCollie_Init_StuckDetection | Registers a callback to periodically detect service thread stuck events.           |
| OH_HiCollie_Init_StuckDetectionWithTimeout | Registers a callback to periodically detect service thread stuck events.  You can set the detection time.|
| OH_HiCollie_Init_JankDetection | Registers a callback to detect service thread jank events. To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.                  |
| OH_HiCollie_Report | Reports service thread stuck events and generates timeout logs to help locate application timeout events. This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs.|

The usage of HiCollie:

- For details (such as parameter usage and value ranges), see [HiCollie](../reference/apis-performance-analysis-kit/_hi_collie.md).
- The service thread stuck faultlog starts with **appfreeze-** and is generated in **Device/data/log/faultlog/faultlogger/**. The log files are named in the format of **appfreeze-application bundle name-application UID-time (seconds)**. For details, see [appfreeze Log Analysis](./appfreeze-guidelines.md#appfreeze-log-analysis).
- For details about the specifications of service thread jank event logs, see [Main Thread Jank Event Specifications](./hiappevent-watcher-mainthreadjank-events.md#main-thread-jank-event-specifications).

## How to Develop

The following describes how to add a button in the application and click the button to call the HiCollie APIs.

1. Create a native C++ project. The directory structure is as follows:

   ```yml
   entry:
     src:
       main:
         cpp:
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           - entryability:
               - EntryAbility.ts
           - pages:
               - Index.ets
   ```

2. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add libhilog_ndk.z.so (log output).
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG**. The following code steps are used to simulate the jank and stuck scenarios. Use the code based on service requirements. The sample code is as follows:

  (1) **OH_HiCollie_Init_JankDetection**:

  ```c++
  #include <thread>
  #include <string>
  #include <unistd.h>
  #include <atomic>
  #include "napi/native_api.h"
  #include "hilog/log.h"
  #include "hicollie/hicollie.h"

  #undef LOG_TAG
  #define LOG_TAG "JankTest"

  //Define two callback objects.
  static OH_HiCollie_BeginFunc beginFunc_;
  static OH_HiCollie_EndFunc endFunc_;

  //Define the callbacks for monitoring application display start and end.
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
    //Wait for 10s.
    std::chrono::seconds delay(10);
    OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection delay before");
    std::this_thread::sleep_for(delay);
    OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection delay after");
  }

  // Define the callback of the subthread.
  void TestJankDetection()
  {
      // Initialize the callback parameters.
      beginFunc_ = InitBeginFunc;
      endFunc_ = InitEndFunc;
      HiCollie_DetectionParam param {0};
      // Initialize the thread jank detection function.
      int initResult = OH_HiCollie_Init_JankDetection(&beginFunc_, &endFunc_, param);
      // Set the thread to be not detected within 10s after being started.
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
      threadObj.detach();
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

  (2) **OH_HiCollie_Init_StuckDetection**:

  ```c++
  #include "napi/native_api.h"
  #include "hilog/log.h"
  #include "hicollie/hicollie.h"
  #include <thread>
  #include <string>
  #include <unistd.h>
  
  #undef LOG_TAG
  #define LOG_TAG "StruckTest"

  // Check whether the thread is running properly. The value 1 indicates that the thread is running properly, and the value 0 indicates that the thread is stuck.
  const int64_t CHECK_BUSSINESS_THREAD_IS_ALIVE = 1;
  // Simulate a thread stuck event by putting the thread to sleep for a custom time.
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

  // Define the callback of the subthread.
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

  (3) **OH_HiCollie_Init_StuckDetectionWithTimeout**:

  ```c++
  #include "napi/native_api.h"
  #include "hilog/log.h"
  #include "hicollie/hicollie.h"
  #include <thread>
  #include <string>
  #include <unistd.h>
  
  #undef LOG_TAG
  #define LOG_TAG "StruckTest"

  // Check whether the thread is running properly. The value 1 indicates that the thread is running properly, and the value 0 indicates that the thread is stuck.
  const int64_t CHECK_BUSSINESS_THREAD_IS_ALIVE = 1;
  // Simulate a thread stuck event by putting the thread to sleep for a custom time.
  const int64_t BLOCK_TIME = 5; 
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
    // Check whether the application thread runs properly every 5 seconds.
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

  // Define the callback of the subthread.
  void InitStuckDetectionWithTimeout()
  {
    // Initialize the thread stuck detection function.
    int initResult = OH_HiCollie_Init_StuckDetectionWithTimeout(Timer, BLOCK_TIME);
    // Success result: 0
    OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetection: %{public}d", initResult);
  }

  static napi_value TestHiCollieStuckWithTimeoutNdk(napi_env env, napi_callback_info info)
  {
    // Create a subthread.
    std::thread threadObj(InitStuckDetectionWithTimeout);
    // Execute a task.
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

4. Register **TestHiCollieNdk** as an ArkTS API.

  (1) **OH_HiCollie_Init_JankDetection**:

  ```typescript
  export const testHiCollieJankNdk: () => void;
  ```

  (2) **OH_HiCollie_Init_StuckDetection**:

  ```typescript
  export const testHiCollieStuckNdk: () => void;
  ```

  (3) **OH_HiCollie_Init_StuckDetectionWithTimeout**:

  ```typescript
  export const testHiCollieStuckWithTimeoutNdk: () => void;
  ```

5. Edit the **Index.ets** file.

  ```ts
  import testNapi from 'libentry.so'
  
  @Entry
  @Component
  struct Index {
    build() {
      RelativeContainer() {
        Column() {
          //Add the click event corresponding to the detection.
          
        }.width('100%')
      }
      .height('100%')
      .width('100%')
    }
  }
  ```

  (1) Add a click event to trigger **OH_HiCollie_Init_JankDetection()**.

  ```ts
  Button("testHiCollieJankNdk", { stateEffect:true, type: ButtonType.Capsule})
    .width('75%')
    .height(50)
    .margin(15)
    .fontSize(20)
    .fontWeight(FontWeight.Bold)
    .onClick(testNapi.testHiCollieJankNdk);
  ```

  (2) Add a click event to trigger **OH_HiCollie_Init_StuckDetection()**.

  ```ts
  Button("testHiCollieStuckNdk", { stateEffect:true, type: ButtonType.Capsule})
    .width('75%')
    .height(50)
    .margin(15)
    .fontSize(20)
    .fontWeight(FontWeight.Bold)
    .onClick(testNapi.testHiCollieStuckNdk);
  ```

  (3) Add a click event to trigger **OH_HiCollie_Init_StuckDetectionWithTimeout()**.

  ```ts
  Button("testHiCollieStuckWithTimeoutNdk", { stateEffect:true, type: ButtonType.Capsule})
    .width('75%')
    .height(50)
    .margin(15)
    .fontSize(20)
    .fontWeight(FontWeight.Bold)
    .onClick(testNapi.testHiCollieStuckWithTimeoutNdk);
  ```

6. Click the **Run** button in DevEco Studio to run the project.

7. At the bottom of DevEco Studio, switch to the **Log** tab and filter the custom **LOG_TAG**.

  (1) Wait for 10s and click the **testHiCollieJankNdk** button. (The jank event detection is not performed within 10s after the thread starts.)
    The thread timeout information of the sampling stack obtained through **OH_HiCollie_Init_JankDetection()** is displayed. You can obtain the corresponding event by [subscribing to the main thread timeout event](./hiappevent-watcher-mainthreadjank-events-arkts.md).

  (2) Click the **testHiCollieStuckNdk** button.
    The callback used for detecting stuck events is initialized through **OH_HiCollie_Init_StuckDetection()**. You can define the detection function for stuck events as required.

  (3) Click the **testHiCollieStuckWithTimeoutNdk** button.
    The callback used for detecting stuck events is initialized through **OH_HiCollie_Init_StuckDetectionWithTimeout**. You can define the detection function and time for stuck events as required.
