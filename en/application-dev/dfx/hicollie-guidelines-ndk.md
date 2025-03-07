# Using HiCollie to Detect Service Thread Stuck and Jank Events (C/C++)

HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events.

## Availability APIs
| API                         | Description                             |
| ------------------------------- | --------------------------------- |
| OH_HiCollie_Init_StuckDetection | Registers a callback to periodically detect service thread stuck events.           |
| OH_HiCollie_Init_JankDetection | Registers a callback to detect service thread jank events. To monitor thread jank events, you should implement two callbacks as instrumentation functions, placing them before and after the service thread processing event.                  |
| OH_HiCollie_Report | Reports service thread stuck events and generates timeout logs to help locate application timeout events. This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs.|

> **NOTE**
>
> The service thread stuck faultlog starts with **appfreeze-** and is generated in **Device/data/log/faultlog/faultlogger/**. The log files are named in the format of **appfreeze-application bundle name-application UID-time (seconds)**. For details, see [appfreeze Log Analysis](./appfreeze-guidelines.md#appfreeze-log-analysis).
>
> For details about the specifications of service thread jank event logs, see [Main Thread Jank Event Specifications](./hiappevent-watcher-mainthreadjank-events.md#main-thread-jank-event-specifications).


For details (such as parameter usage and value ranges), see [HiCollie](../reference/apis-performance-analysis-kit/_hi_hicollie.md).

## How to Develop
The following describes how to add a button in the application and click the button to call the HiCollie APIs.

1. Create a native C++ project and import the **jsoncpp** file to the project. The directory structure is as follows:

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

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG** and the test method.

   ```c++
    #include "napi/native_api.h"
    #include "hilog/log.h"
    #include "hicollie/hicollie.h"
    #include <thread>
    #include <string>
    #include <unistd.h>
    #include <atomic>
    
    #undef LOG_TAG
    #define LOG_TAG "testTag"

    static OH_HiCollie_BeginFunc beginFunc_; // Define the callback object used before the processing event.
    static OH_HiCollie_EndFunc endFunc_; // Define the callback object used after the processing event.
    HiCollie_DetectionParam param {.sampleStackTriggerTime = 150, .reserved = 0}; // Define a struct.
    int64_t lastWatchTime = 0; // Record the last detection time.
    const int64_t CHECK_INTERNAL_TIME = 3000; // Set the detection interval.
    std::shared_ptr<std::atomic<bool>> isReport = std::make_shared<std::atomic<bool>>(false); // Set the flag for reporting stuck events.
    int count = 0; // Record the first initialization.
    bool needReport = false; // Set whether to report the stuck events.

    // Define the callback.
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
    // Define the callback of the subthread.
    void TestJankDetection()
    {
        beginFunc_ = InitBeginFunc; // Initialize the callback.
        endFunc_ = InitEndFunc;
        int initResult = OH_HiCollie_Init_JankDetection(&beginFunc_, &endFunc_, param); // Initialize the function for detecting thread jank events.
        OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_JankDetection: %{public}d", initResult); // Display the success result 0.
        int count = 0;
        while (count < 2) {
            beginFunc_("TestBegin"); // Set the callback used to record the start time of the processing event.
            usleep(350 * 1000); // Simulate a thread jank event by putting the thread to sleep for 350 ms.
            endFunc_("TestEnd"); // Set the callback used to record the end time of the processing event.
            count++;
        }
    }

    static napi_value TestHiCollieJankNdk(napi_env env, napi_callback_info info)
    {
        std::thread threadObj(TestJankDetection); // Create a subthread.
        threadObj.join(); // Execute the callback.
        return 0;
    }

    int64_t GetCurrentTime()
    {
      return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::
          system_clock::now().time_since_epoch()).count();
    }

    bool ReportEvent()
    {
      if ((GetCurrentTime() - lastWatchTime) > CHECK_INTERNAL_TIME) {
          return true;
      }
      return false;
    }

    void TestTask()
    {
        if (needReport && ReportEvent()) {
          bool temp = isReport->load();
          int reportResult = OH_HiCollie_Report(&temp);
          OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report: %{public}d", reportResult); // Display the success result 0.
          OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Report isReport: %{public}d", temp);
          needReport = false;
        }
        int64_t now = GetCurrentTime();
        if ((now - lastWatchTime) >= (CHECK_INTERNAL_TIME / 2)) {
            lastWatchTime = now;
        }
    }

    // Define the callback of the subthread.
    void TestStuckDetection()
    {
        int initResult = -1;
        if(count == 0) {
          initResult = OH_HiCollie_Init_StuckDetection(TestTask); // Initialize the function for detecting thread stuck events.
          OH_LOG_INFO(LogType::LOG_APP, "OH_HiCollie_Init_StuckDetection: %{public}d", initResult); // Display the success result 0.
          count++;
        }
    }
    static napi_value TestHiCollieStuckNdk(napi_env env, napi_callback_info info)
    {
      std::thread threadObj(TestStuckDetection); // Create a subthread.
      threadObj.join(); // Execute the callback.
      return 0;
    }
   ```

4. Register **TestHiCollieNdk** as an ArkTS API.

   In the **napi_init.cpp** file, register **TestHiCollieNdk** as an ArkTS API.

   ```c++
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "testHiCollieJankNdk", nullptr, TestHiCollieJankNdk, nullptr, nullptr, nullptr, napi_default, nullptr },
            { "testHiCollieStuckNdk", nullptr, TestHiCollieStuckNdk, nullptr, nullptr, nullptr, napi_default, nullptr }};
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const testHiCollieJankNdk: () => void;
   export const testHiCollieStuckNdk: () => void;
   ```

5. Edit the **Index.ets** file.

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Button("testHiCollieJankNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiCollieJankNdk);// Add a click event to trigger testHiCollieJankNdk().
           Button("testHiCollieStuckNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiCollieStuckNdk);// Add a click event to trigger testHiCollieStuckNdk().
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. Click the **Run** button in DevEco Studio to run the project.

7. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **testTag**.

    (1) Wait for 10s and click the **testHiCollieJankNdk** button. (The jank event detection is not performed within 10s after the thread starts.)
      The thread timeout information of the sampling stack obtained through **OH_HiCollie_Init_JankDetection()** is displayed
      in **/data/app/el2/100/log/application bundle name/watchdog/BUSSINESS_THREAD_JANK_XXX.txt.**

    (2) Click the **testHiCollieStuckNdk** button.
      The callback used for detecting stuck events is initialized through **OH_HiCollie_Init_StuckDetection()**. You can define the detection function for stuck events as required.
