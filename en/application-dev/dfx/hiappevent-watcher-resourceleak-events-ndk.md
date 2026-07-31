# Subscribing to Resource Leak Events (C/C++)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=deda4f19015dd8c61f2e0d855c3c53292d681c7b translatedAt=2026-07-31T01:28:19.533Z pushedAt=2026-07-31T06:20:49.012Z -->

## Available APIs

This section describes how to use the C/C++ APIs provided by HiAppEvent to subscribe to resource leak events. For detailed API usage instructions (parameter constraints, value ranges, etc.), refer to [hiappevent.h](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

**Subscription APIs**

| API| Description|
| -------- | -------- |
| int OH_HiAppEvent_AddWatcher(HiAppEvent_Watcher \*watcher) | Adds a watcher to listen for application events.|
| int OH_HiAppEvent_RemoveWatcher(HiAppEvent_Watcher \*watcher) | Removes a watcher to unsubscribe from the application events.|

## How to Develop

### Step 1: Creating a Project

1. Obtain the **jsoncpp** file on which the sample project depends. Specifically, download the source code package from [JsonCpp](https://github.com/open-source-parsers/jsoncpp) and obtain the **jsoncpp.cpp**, **json.h**, and **json-forwards.h** files by following the procedure described in **Amalgamated source**.

   Create a native C++ project in DevEco Studio. The directory structure is as follows:

   ```yml
   entry:
     src:
       main:
         cpp:
           - json:
               - json.h
               - json-forwards.h
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
           - jsoncpp.cpp
         ets:
           - entryability:
               - EntryAbility.ets
           - pages:
               - Index.ets
   ```

2. In the **CMakeLists.txt** file, add the source file and dynamic libraries.

   ```cmake
   # Add the jsoncpp.cpp file, which is used to parse the JSON strings in the subscription events.
   add_library(entry SHARED napi_init.cpp jsoncpp.cpp)
   # Add libhiappevent_ndk.z.so and libhilog_ndk.z.so (log output). 
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libhiappevent_ndk.z.so)
   ```

3. Import the dependencies to the **napi_init.cpp** file, and define **LOG_TAG**.

   ```c++
   #include "napi/native_api.h"
   #include "json/json.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   ```

### Step 2: Subscribing to a System Event

1. Subscribe to system events.

   - Watcher of the onReceive type:

      In the **napi_init.cpp** file, define the methods related to **onReceive()**.

      ```c++
      // Define a variable to cache the pointer to the created watcher.
      static HiAppEvent_Watcher *systemEventWatcher; 
      
      static void OnReceive(const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen) {
          for (int i = 0; i < groupLen; ++i) {
              for (int j = 0; j < appEventGroups[i].infoLen; ++j) {
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", appEventGroups[i].appEventInfos[j].domain);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", appEventGroups[i].appEventInfos[j].name);
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", appEventGroups[i].appEventInfos[j].type);
                  if (strcmp(appEventGroups[i].appEventInfos[j].domain, DOMAIN_OS) == 0 && 
                      strcmp(appEventGroups[i].appEventInfos[j].name, EVENT_RESOURCE_OVERLIMIT) == 0) {
                      Json::Value params;
                      Json::Reader reader(Json::Features::strictMode());
                      Json::FastWriter writer;
                      if (reader.parse(appEventGroups[i].appEventInfos[j].params, params)) {
                          auto time = params["time"].asInt64();
                          auto pid = params["pid"].asInt();
                          auto uid = params["uid"].asInt();
                          auto resourceType = params["resourceType"].asString();
                          auto bundleName = params["bundle_name"].asString();
                          auto appRunningUniqueId = params["app_running_unique_id"].asString();
                          auto bundleVersion = params["bundle_version"].asString();
                          auto memory = writer.write(params["memory"]);
                          auto externalLog = writer.write(params["external_log"]);
                          std::string logOverLimit = params["log_over_limit"].asBool() ? "true":"false";
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.resource_type=%{public}s", resourceType.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.app_running_unique_id=%{public}s", appRunningUniqueId.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                          OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}s", logOverLimit.c_str());
                      }
                  }
              }
          }
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onReceiverWatcher");
          // Set the event to watch to EVENT_RESOURCE_OVERLIMIT.
          const char *names[] = {EVENT_RESOURCE_OVERLIMIT};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback function. The watcher triggers the OnReceive callback immediately after receiving an event.
          OH_HiAppEvent_SetWatcherOnReceive(systemEventWatcher, OnReceive);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

   - Watcher of the onTrigger type:

      In the **napi_init.cpp** file, define the methods related to **OnTrigger()**.

      ```c++
      // Define a variable to cache the pointer of the created watcher.
      static HiAppEvent_Watcher *systemEventWatcher; 
      
      // Implement the callback function used to return the listened events. The content pointed to by the events pointer is valid only in this function.
      static void OnTake(const char *const *events, uint32_t eventLen) {
          Json::Reader reader(Json::Features::strictMode());
          Json::FastWriter writer;
          for (int i = 0; i < eventLen; ++i) {
              Json::Value eventInfo;
              if (reader.parse(events[i], eventInfo)) {
                  auto domain =  eventInfo["domain_"].asString();
                  auto name = eventInfo["name_"].asString();
                  auto type = eventInfo["type_"].asInt();
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.domain=%{public}s", domain.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.name=%{public}s", name.c_str());
                  OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.eventType=%{public}d", type);
                  if (domain ==  DOMAIN_OS && name == EVENT_RESOURCE_OVERLIMIT) {
                      auto time = eventInfo["time"].asInt64();
                      auto pid = eventInfo["pid"].asInt();
                      auto uid = eventInfo["uid"].asInt();
                      auto resourceType = eventInfo["resourceType"].asString();
                      auto bundleName = eventInfo["bundle_name"].asString();
                      auto appRunningUniqueId = eventInfo["app_running_unique_id"].asString();
                      auto bundleVersion = eventInfo["bundle_version"].asString();
                      auto memory = writer.write(eventInfo["memory"]);
                      auto externalLog = writer.write(eventInfo["external_log"]);
                      std::string logOverLimit = eventInfo["log_over_limit"].asBool() ? "true":"false";
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.time=%{public}lld", time);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.pid=%{public}d", pid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.uid=%{public}d", uid);
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.resource_type=%{public}s", resourceType.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_name=%{public}s", bundleName.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.app_running_unique_id=%{public}s", appRunningUniqueId.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.bundle_version=%{public}s", bundleVersion.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.memory=%{public}s", memory.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.external_log=%{public}s", externalLog.c_str());
                      OH_LOG_INFO(LogType::LOG_APP, "HiAppEvent eventInfo.params.log_over_limit=%{public}s", logOverLimit.c_str());
                  }
              }
          }
      }
      
      // Implement the subscription callback function to apply custom processing to the obtained event logging data.
      static void OnTrigger(int row, int size) {
          // After the callback is received, obtain the specified number of received events.
          OH_HiAppEvent_TakeWatcherData(systemEventWatcher, row, OnTake);
      }
      
      static napi_value RegisterWatcher(napi_env env, napi_callback_info info) {
          // Set the watcher name. The system identifies different watchers based on their names.
          systemEventWatcher = OH_HiAppEvent_CreateWatcher("onTriggerWatcher");
          // Set the event to watch to EVENT_RESOURCE_OVERLIMIT.
          const char *names[] = {EVENT_RESOURCE_OVERLIMIT};
          // Add the events to watch, for example, system events.
          OH_HiAppEvent_SetAppEventFilter(systemEventWatcher, DOMAIN_OS, 0, names, 1);
          // Set the implemented callback function. The callback function will be triggered when the conditions set by OH_HiAppEvent_SetTriggerCondition are met.
          OH_HiAppEvent_SetWatcherOnTrigger(systemEventWatcher, OnTrigger);
          // Set the conditions for triggering the subscription callback. For example, trigger this onTrigger callback when the number of new event logs is 2.
          OH_HiAppEvent_SetTriggerCondition(systemEventWatcher, 1, 0, 0);
          // Add a watcher to listen for the specified event.
          OH_HiAppEvent_AddWatcher(systemEventWatcher);
          return {};
      }
      ```

2. Register **RegisterWatcher** as an ArkTS API.

   In the **napi_init.cpp** file, register **RegisterWatcher** as an ArkTS API.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "registerWatcher", nullptr, RegisterWatcher, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   In the **index.d.ts** file, define the ArkTS API.

   ```typescript
   export const registerWatcher: () => void;
   ```

3. In the **EntryAbility.ets** file, add the following API to **onCreate()**.

   ```typescript
   import testNapi from 'libentry.so'
   import hidebug from '@kit.PerformanceAnalysisKit'
   export default class EntryAbility extends UIAbility {
     onCreate(want, launchParam) {
       // Register the system event watcher at startup.
       testNapi.registerWatcher();
     }
   }
   ```

### Step 3: Triggering a Resource Leak Event

1. In the **entry/src/main/ets/pages/index.ets** file, add the **memoryleak** button and construct a scenario for triggering a resource leak event in **onClick()**.

   Use [hidebug.setAppResourceLimit](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetappresourcelimit12) to set a memory limit, which triggers a memory leak. Also enable **System resource leak log** in **Developer options** (restart the device after toggling the switch). The sample code is as follows:

   <!-- @[PssLeakEvent_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   Button('pss leak')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('80%')
     .height('5%')
     .onClick(() => {
       // Set up a simple resource leak scenario.
       hilog.info(0x0000, 'testTag', 'click pss leak button');
       testNapi.leakMB(3072);
     })
   ```

2. Add the PSS leak-related content.

   Edit the **napi_init.cpp** file.

   - Add the following header files:

   <!-- @[Pss_Leak_Header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   #include <iostream>
   #include <fstream>
   #include <sstream>
   #include <thread>
   ```

   - Define the PSS leak-related methods.

   <!-- @[Pss_Leak](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Read the PSS field in /proc/self/smaps_rollup to calculate the PSS of the current process (unit: KB).
   static int GetCurrentProcessPss()
   {
       std::ifstream smapsFile("/proc/self/smaps_rollup");
       if (!smapsFile.is_open()) {
           std::cerr << "Failed to open /proc/self/smaps_rollup" << std::endl;
           return 0;
       }
       std::string line;
       int totalPss = 0;
       while (std::getline(smapsFile, line)) {
           if (line.find("Pss:") == 0) {
               std::istringstream iss(line);
               std::string label;
               int pss;
               iss >> label >>pss;
               totalPss += pss;
           }
       }
       smapsFile.close();
       std::cout << "Current pss: " << totalPss << " KB\r";
       std::cout.flush();
       return totalPss;
   }
   
   // Read the number of FDs of the current process.
   static int GetCurrentFd()
   {
       std::ifstream fdFile("/proc/self/fd_num");
       if (!fdFile.is_open()) {
           std::cerr << "Failed to open /proc/self/fd_num" << std::endl;
           return 0;
       }
       std::string line;
       int totalPss = 0;
       std::getline(fdFile, line);
       fdFile.close();
       std::cout << "Current fd: " << line << std::endl;
       std::cout.flush();
       return std::stoi(line);
   }
   
   // Allocate memory of the specified size and write data (using 'a') to the memory to increase the native memory.
   static bool InjectNativeLeakMallocWithSize(int size, char *p)
   {
       const size_t maxSafe = 1073741824;
       if (size < 0 || size > maxSafe) {
           printf("InjectNativeLeakMallocWithSize invalid size\n");
           return false;
       }
       p = (char *) malloc(size + 1);
       if (!p) {
           printf("InjectNativeLeakMallocWithSize malloc failed\n");
           return false;
       }
       void* err = memset(p, 'a', size);
       if (err == nullptr) {
           printf("InjectNativeLeakMallocWithSize memset failed\n");
           return false;
       }
       return true;
   }
   
   // Apply for or release memory cyclically so that the PSS of the process keeps approaching the target.
   static void InjectNativeLeakMallocUntil(int target)
   {
       constexpr int leakSizePerTime = 5000000;
       std::vector<char *> mems;
       int curPss = GetCurrentProcessPss();
       while (curPss != 0) {
           char *p = nullptr;
           if (curPss < target) {
               if (!InjectNativeLeakMallocWithSize(leakSizePerTime, p)) {
                   printf("InjectNativeLeakMallocUntil target = %d failed\n", target);
               }
               mems.push_back(p);
               std::cout << "Inject size: " << leakSizePerTime << ", currentSize: " << mems.size() << std::endl;
           } else {
               if (mems.size() > 0) {
                   char *dst = mems[0];
                   mems.erase(mems.begin());
                   free(dst);
               }
               std::cout << "Free size: " << leakSizePerTime << ", currentSize: " << mems.size() << std::endl;
           }
           curPss = GetCurrentProcessPss();
       }
       std::cout << std::endl;
       printf("InjectNativeLeakMallocUntil target = %d success\n", target);
   }
   
   // Start the InjectNativeLeakMallocUntil thread executed in the background to make the native memory usage close to leakSize.
   static void StartNativeLeak(int leakSize)
   {
       std::cout << "Start inject malloc until" << leakSize << "KB" << std::endl;
       std::thread t1(InjectNativeLeakMallocUntil, leakSize);
       t1.detach();
       std::cout << "Inject finished." << std::endl;
   }
   
   // N-API export method.
   static napi_value LeakMB(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1];
       napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
       if (argc < 1) {
           napi_throw_type_error(env, nullptr, "Expected 1 argument");
           return nullptr;
       }
       double x = 0;
       if (napi_get_value_double(env, args[0], &x) != napi_ok) {
           napi_throw_type_error(env, nullptr, "Argument must be a number");
           return nullptr;
       }
       const size_t kilobyte = 1024;
       StartNativeLeak(static_cast<size_t>(x * kilobyte));
       napi_value rtn;
       napi_get_undefined(env, &rtn);
       return rtn;
   }
   ```

    - Initialization:

    <!-- @[Pss_Leak_Init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/napi_init.cpp) -->

    ``` C++
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            // ...
            { "leakMB", nullptr, LeakMB, nullptr, nullptr, nullptr, napi_default, nullptr}
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
    ```

    Edit the **Index.d.ts** file:

    - Add the type declaration:

    <!-- @[Pss_Leak_Index.d.ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/types/libentry/Index.d.ts) -->

    ``` TypeScript
    export const leakMB: (size: number) => void;
    ```

3. Click the **Run** button in DevEco Studio to run the project. Click the **pss leak** button and wait for 15 to 30 minutes; the system will then report the memory leak event.

   For the same application, the resource leak event can be reported at most once within 24 hours. If the memory leak needs to be reported again within a shorter time, restart the device.

4. After the memory leak event is reported, you can view the following event information in the **Log** window.

   ```text
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.domain=OS
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.name=RESOURCE_OVERLIMIT
   08-07 03:53:35.314 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.eventType=1
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.time=1502049167732
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.pid=1587
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.uid=20010043
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.resource_type=pss_memory
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.app_running_unique_id=12369547851223645271
   08-07 03:53:35.349 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.bundle_version=1.0.0
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.memory={"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936}
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572401_6808.log","/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572412_6808.log"]
   08-07 03:53:35.350 1719-1738/? I A00000/testTag: HiAppEvent eventInfo.params.log_over_limit=false
   ```

### Step 4: Removing a Watcher

1. Remove the event watcher.

   ```c++
   static napi_value RemoveWatcher(napi_env env, napi_callback_info info) {
       // Remove the watcher to unsubscribe from events.
       OH_HiAppEvent_RemoveWatcher(systemEventWatcher);
       return {};
   }
   ```

2. Destroy the event watcher.

   ```c++
   static napi_value DestroyWatcher(napi_env env, napi_callback_info info) {
       // Destroy the created watcher and set systemEventWatcher to nullptr.
       OH_HiAppEvent_DestroyWatcher(systemEventWatcher);
       systemEventWatcher = nullptr;
       return {};
   }
   ```