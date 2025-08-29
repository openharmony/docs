# Subscribing to Application Killed Events (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @shead-master-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Event Specifications

For details, see [Application Killed Event Overview](./hiappevent-watcher-app-killed-events.md).

## Available APIs

For details about how to use the APIs (such as parameter usage restrictions and value ranges), see [HiAppEvent](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md).

| Name                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void               | Removes a watcher for the specified application events.|

## How to Develop

To ensure that the event callback can be successfully received in the development phase, you are advised to create a native C++ project, implement subscription in the ArkTs code, and use the C ++ fault injection code to construct a fault to trigger the application killed event.

1. In the **entry/src/main/ets/entryability/EntryAbility.ets** file of the project, import the dependent modules.

   ```ts
   import { hiAppEvent } from '@kit.PerformanceAnalysisKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add a watcher in **onCreate()** to subscribe to system events. The sample code is as follows:

   ```ts
   hiAppEvent.addWatcher({
     // Set the watcher name. The system identifies different watchers based on their names.
     name: "watcher",
     // You can subscribe to system events that you are interested in. Here, the application killed event is subscribed to.
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.APP_KILLED]
       }
     ],
     // Implement a callback for the registered system event so that you can apply custom processing to the event data obtained.
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         // The event name uniquely identifies a system event.
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           // Apply custom processing to the event data obtained, for example, print the event data in the log.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
           // Obtain the timestamp when the application is killed.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
           // Obtain the foreground and background status of the application when the killed event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
           // Obtain the cause of the application killed event.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.reason=${eventInfo.params['reason']}`);
         }
       }
     }
   });
   ```

3. Edit the **napi_init.cpp** file and add the following code to implement the fault-injection functionality in C++.

   ```C++
   #include <thread>
   
   static void NativeLeak()
   {
       constexpr int leak_size_per_time = 500000;
       while (true) {
           char *p = (char *)malloc(leak_size_per_time + 1);
           if (!p) {
               break;
           }
           memset(p, 'a', leak_size_per_time);
           std::this_thread::sleep_for(std::chrono::milliseconds(10));
       }
   }
   
   static napi_value Leak(napi_env env, napi_callback_info info) {
   	std::thread t1(NativeLeak);
   	t1.detach();
       return {};
   }
   ```

4. In the **napi_init.cpp** file, register **Leak** as an ArkTS API.

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "leak", nullptr, Leak, nullptr, nullptr, nullptr, napi_default, nullptr }, // Add this line.
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

5. In the **index.d.ts** file, define the ArkTS API.

   ```ts
   export const leak: () => void;
   ```

6. In the **entry/src/main/ets/pages/Index.ets** file,  add the **OnClick** function under **build()** and call the **Leak** API.

   ```ts
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   
   const DOMAIN = 0x0000;
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Start To Leak';
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize($r('app.float.page_text_font_size'))
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               if (this.message != 'Leaking') {
                 this.message = 'Leaking';
                 hilog.info(DOMAIN, 'testTag', 'Start leaking');
                 testNapi.leak();
               }
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

7. Click the **Run** button in DevEco Studio to run the project. Click **Start To Leak**, and wait for 2 to 3 minutes until **RssThresholdKiller** is triggered.

8. After the application is killed, open the application again. The killed event is reported, and the system calls **onReceive()**. You can view the following event information in the **Log** window.

   Sample stack of the application killed event:

   ```text
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_KILLED
   HiAppEvent eventInfo.params.time=1717597063727
   HiAppEvent eventInfo.params.reason="RssThresholdKiller"
   HiAppEvent eventInfo.params.foreground=true
   ```
