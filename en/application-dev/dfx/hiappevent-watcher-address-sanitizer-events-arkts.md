# Subscribing to Address Sanitizer Events (ArkTS)

## Available APIs

For details about how to use the APIs, see [@ohos.hiviewdfx.hiAppEvent (Application Event Logging)](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

| API| **Description**|
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to subscribe to application events.|
| removeWatcher(watcher: Watcher): void | Removes a watcher to unsubscribe from application events.|

## **How to Develop**

The following describes how to subscribe an address sanitizer event for an array bounds write.

### Step 1: Creating a Project

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
               - EntryAbility.ets
           - pages:
               - Index.ets
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file of the project, import the dependent modules.

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

### Step 2: Subscribing to Address Sanitizer Events

1. In the **entry/src/main/ets/entryability/EntryAbility.ets** file of the project, add a watcher in **onCreate()** to subscribe to system events. The sample code is as follows: 

   ```ts
   hiAppEvent.addWatcher({
     // Set the watcher name. The system identifies different watchers based on their names.
     name: "watcher",
     // You can subscribe to system events that you are interested in. For example, the address sanitizer event.
     appEventFilters: [
       
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.ADDRESS_SANITIZER]
       }
     ],
     // Implement a callback for the registered system event so that you can apply custom processing to the event data obtained.
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         // The event name uniquely identifies a system event.
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           // Customize how to process the event data obtained, for example, print the event data in the log.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.time=${eventInfo.params['time']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.bundle_version=${eventInfo.params['bundle_version']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.bundle_name=${eventInfo.params['bundle_name']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.pid=${eventInfo.params['pid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.uid=${eventInfo.params['uid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.type=${eventInfo.params['type']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.log_over_limit=${eventInfo.params['log_over_limit']}`);
         }
       }
     }
   });
   ```

### Step 3: Constructing an Address Sanitizer Error

1. In the **entry/src/main/cpp/napi_init.cpp** file, implement the array bounds write scenario and provide Node-API for the application layer code to call. The sample code is as follows:

   ```c++
   #include "napi/native_api.h"
   
   static napi_value Test(napi_env env, napi_callback_info info)
   {
       int a[10];
       // Construct the array bounds write.
       a[10] = 1;
       return {};
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "test", nullptr, Test, nullptr, nullptr, nullptr, napi_default, nullptr }
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
       .reserved = { 0 }
   };
   
   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```

2. Edit the **entry/src/main/cpp/types/libentry/index.d.ts** file. The sample code is as follows:

   ```ts
   export const test: () => void;
   ```

3. In the **entry > src > main > ets > pages > Index.ets** file, add a button to trigger an address sanitizer event.

   ```ts
   import testNapi from 'libentry.so';
   
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           Button("address-sanitizer").onClick(() => {
             testNapi.test();
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

4. In DevEco Studio, choose **entry**, click **Edit Configurations**, click **Diagnostics**, select **Address Sanitizer**, and click **OK**. Click the **Run** button to run the project. Then, click the **address-sanitizer** button to trigger an address sanitizer event. The application crashes. After restarting the application, you can view the following event information in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=ADDRESS_SANITIZER
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=ADDRESS_SANITIZER
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.time=1713161197957
   HiAppEvent eventInfo.bundle_version=1.0.0
   HiAppEvent eventInfo.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.pid=12889
   HiAppEvent eventInfo.uid=20020140
   HiAppEvent eventInfo.type=stack-buffer-overflow
   HiAppEvent eventInfo.external_log=["/data/storage/el2/log/hiappevent/ADDRESS_SANITIZER_1713161197960_12889.log"]
   HiAppEvent eventInfo.log_over_limit=false
   ```
