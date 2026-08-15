# Subscribing to Resource Leak Events (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @xuxinao-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=281a5975cfb5f25896e63aa56d3d9f8deabd3462 translatedAt=2026-08-15T01:48:14.606Z pushedAt=2026-08-15T07:14:44.534Z -->

## Available APIs

This document describes how to use the ArkTS APIs provided by HiAppEvent to subscribe to resource leak events. For detailed usage instructions (parameter constraints, value ranges, etc.) of the APIs, see [@ohos.hiviewdfx.hiAppEvent](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

### APIs for Setting Custom Parameters

| API| Description|
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType&gt;, domain: string, name?: string): Promise&lt;void&gt; | Sets custom parameters of an event. In resource leak events, only parameters of the JS memory leak event can be set.<br>Note: This API is supported since API version 20.|

### APIs for Setting Custom Configurations

| API| Description|
| -------- | -------- |
| setEventConfig(name: string, config: Record&lt;string, ParamType>): Promise&lt;void> | Sets custom configurations of an event. For resource leak events, only the JS memory leak event can be configured.<br>Note: This API is supported since API version 20.|

### Subscription APIs

| API| Description|
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void | Removes a watcher to unsubscribe from application events.|

## How to Develop

The following example describes how to subscribe to the memory leak event.

### Step 1: Creating a Project

1. Create a project in DevEco Studio and select **Empty Ability**. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules.

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   import { deviceInfo, BusinessError } from '@kit.BasicServicesKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file of the project, add a watcher in **onCreate()** to subscribe to system events. The sample code is as follows:

   ```ts
   // Assign a value to params, which is a key-value pair.
   let params: Record<string, hiAppEvent.ParamType> = {
     "test_data": 100,
   };
   // Set custom parameters for the resource leak event.
   hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.RESOURCE_OVERLIMIT).then(() => {
     hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
   });
   // Assign a value to the custom key-value pair.
   let configParams: Record<string, hiAppEvent.ParamType> = {
     "js_heap_logtype": "event", // Obtain only events.
   }
   // Set custom configurations for the resource leak event.
   hiAppEvent.setEventConfig(hiAppEvent.event.RESOURCE_OVERLIMIT, configParams);
   if (deviceInfo.sdkApiVersion >= 24) {  // API Version 24 and later supports setting page switch logs.
     // Configure page switch logs.
     let switchLogPolicy : hiAppEvent.EventPolicy = {
       "resourceOverlimitPolicy": {
         "pageSwitchLogEnable": true
       }
     };
     // You can set resource leak log configuration parameters.
     hiAppEvent.configEventPolicy(switchLogPolicy).then(() => {
       hilog.info(0x0000, 'testTag', `HiAppEvent success to config event policy.`);
     }).catch((err: BusinessError) => {
       hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
     });
   }

   hiAppEvent.addWatcher({
     // Set the watcher name. The system identifies different watchers based on their names.
     name: "watcher",
     // Add the system events to watch, for example, the resource leak event.
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.RESOURCE_OVERLIMIT]
       }
     ],
     // Implement a callback for the registered system event so that you can apply custom processing to the event data obtained.
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         // The event name uniquely identifies a system event.
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           // Obtain the memory information when the resource leak event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo=${JSON.stringify(eventInfo)}`);
           // You can obtain page switch logs for resource leak events.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.page_switch_log=${JSON.stringify(eventInfo.params['page_switch_log'])}`);
         }
       }
     }
   });
   ```

### Step 2: Subscribing to Resource Leak Events

1. In the **entry/src/main/ets/pages/index.ets** file, add the **memoryleak** button and construct a scenario for triggering a resource leak event in **onClick()**.

   In this case, use [hidebug.setAppResourceLimit](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetappresourcelimit12) to set the memory limit to trigger a memory leak event, and enable **System resource leak log** in **Developer options**. (Restart the device to enable or disable this functionality.)

   <!--RP1-->

   For details about how to locate resource leak errors, see [Memory Leak Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-snapshot).

   <!--RP1End-->

   The sample code is as follows:

   <!-- @[PssLeakEventTS_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/ets/pages/Index.ets) -->

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
   Button('js leak')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('80%')
     .height('5%')
     .onClick(() => {
       for (let i = 0; i < 10000; i++) {
         this.leakedArray.push(new Array(500000).fill(1));
       }
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

   - Perform the initialization.

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

   Edit the **Index.d.ts** file.

   - Add the following type declaration:

   <!-- @[Pss_Leak_Index.d.ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiAppEvent/EventSub/entry/src/main/cpp/types/libentry/Index.d.ts) -->

   ``` TypeScript
   export const leakMB: (size: number) => void;
   ```

3. Click the **Run** button in DevEco Studio to run the project, click the **pss leak** button, and then a PSS memory leak event will be reported after 15 to 30 minutes.

   For the same application, the resource leak event can be reported at most once within 24 hours. If the memory leak needs to be reported again within a shorter time, restart the device.

4. After a PSS memory leak event is reported, the system calls **onReceive()**. You can view the following event information in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication", "app_running_unique_id":"26457812872126536953", "bundle_version":"1.0.0","memory":{"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936},"pid":20731,"resource_type":"pss_memory","time":1502348798106,"uid":20010044,"external_log": ["/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572401_6808.log", "/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572412_6808.log"], "log_over_limit": false}}
   HiAppEvent eventInfo.params.page_switch_log="[\"/data/storage/el2/log/page_switch/snapshot/page_switch-com.example.myapplication-1-1-20260427162423841.log\"]"
   ```

   As shown in the preceding information, **eventInfo** contains the [params](hiappevent-watcher-resourceleak-events.md#params) field of the resource leak event. You can determine the current leak type based on the **resource_type** field in **eventInfo**.

5. Enable **System resource leak log** in **Developer options**. (You need to restart the device to enable or disable this functionality.) Click the **Run** button in DevEco Studio to run the project. Click **js leak** and wait for 3 to 5 seconds. The app will exit unexpectedly. After the app restarts, the system reports a JS memory leak event.

   For the same app, the JS memory leak event can be reported at most once within 24 hours. If the memory leak needs to be reported again within a shorter time, restart the device.

6. After the JS memory leak event is reported, the system calls the **onReceive** function of the app. You can view the following event information in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication", "app_running_unique_id":"45354125624752145258", "bundle_version":"1.0.0","external_log":[],"log_over_limit":true,"memory":{"limit_size":0,"live_object_size":0},"pid":14941,"resource_type":"js_heap","test_data":100,"time":1752564700511,"uid":20020181}}
   HiAppEvent eventInfo.params.page_switch_log="[\"/data/storage/el2/log/page_switch/snapshot/page_switch-com.example.myapplication-1-1-20260427162423841.log\"]"
   ```

   In the preceding information, the **test_data** field in **eventInfo** is the content of the key-value pair set in step 1.

## Subscribing to js_heap Snapshots in the Nolog Version

After receiving the subscribed event, the application should obtain the path of the heap snapshot file from the **external_log** field of the event, move or upload the file to the cloud as soon as possible, and then delete the original heap snapshot file. Otherwise, the next heap snapshot file may fail to be generated due to insufficient storage space (up to 2 GB) of the application sandbox path directory.

Change the extension of the .log file generated after subscription to **.rawheap**, use [rawheap-translator](../tools/rawheap-translator.md) to convert the file to a .heapsnapshot file, and open the file using DevEco Studio or a browser. For details, see [Importing Heap Snapshots Offline](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388).

Since API version 14, you can change the log file name extension to **.rawheap** and import it to DevEco Studio for display. For details, see [Importing Memory Snapshots Offline](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388).

You can select either of the following methods:

### Configuring Environment Variables in the AppScope/app.json5 File

```text
"appEnvironments": [
  {
    "name": "DFX_RESOURCE_OVERLIMIT_OPTIONS",
    "value": "oomdump:enable"
  }
]
```

**VM Heap Snapshot Generation Specifications of the Nolog Version**

The heap snapshot file size is about 0.4 GB to 1.2 GB (about 50 MB to 100 MB after being compressed into a .zip package). Due to the large size, the system controls the number of times that heap snapshots can be generated. The specifications are as follows:

- Device: The JS heap snapshot file can be generated for five times a week. If this limit is exceeded, all apps cannot generate heap snapshots.

- App: The JS heap snapshot file can be generated only once a week. Within seven days after the app triggers the oomdump function, it cannot be triggered again.

- If the remaining storage space of the device is less than 30 GB, the oomdump function is not triggered.

  During debugging, you can adjust the system time to seven days later and restart the device to reset the number of times that the app triggers oomdump, so that you can quickly complete function adaptation and verification.

> **NOTE**
>
> The value field in the JSON5 configuration file supports the key-value pair set "key1:value1;key2:value2;...". Currently, the system only supports apps configured with the preceding key-value pair to enable the oomdump function in the nolog version.

### Calling setEventConfig and Passing in the Required Parameters

```ts
let configParams: Record<string, hiAppEvent.ParamType> = {
  "js_heap_logtype": "event_rawheap",
};

hiAppEvent.setEventConfig(hiAppEvent.event.RESOURCE_OVERLIMIT, configParams);
```

The number of heap snapshots generated by the setEventConfig method is **not** subject to the **VM heap snapshot generation specifications of the nolog version**.