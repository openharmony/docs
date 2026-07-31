# Subscribing to App Freeze Alarm Events (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-29T10:49:15.853Z pushedAt=2026-07-29T12:37:14.473Z -->

## Overview

This document describes how to use the ArkTS APIs provided by HiAppEvent to subscribe to app freeze alarm events. For detailed API usage instructions (parameter constraints, value ranges, etc.), see [@ohos.hiviewdfx.hiAppEvent](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

## Available APIs

| API | Description |
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds an app event watcher to subscribe to app events. |
| removeWatcher(watcher: Watcher): void | Removes an app event watcher to unsubscribe from app events. |

## How to Develop

### Adding an Event Watcher

The following uses subscribing to app freeze warning events as an example to illustrate the development procedure.

1. In DevEco Studio, create an ArkTS app project, edit the **entry > src > main > ets > entryability > EntryAbility.ets** file in the project, and import the dependent modules. The sample code is as follows:

   ```ts
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Edit the **entry > src > main > ets > entryability > EntryAbility.ets** file in the project, and add a subscription for system events in the onCreate function. The sample code is as follows:

   ```ts
   hiAppEvent.addWatcher({
     // You can customize the watcher name, which the system uses to identify different watchers.
     name: "watcher",
     // You can subscribe to system events of interest. Here, the app freeze warning event is subscribed.
     appEventFilters: [
       {
         domain: hiAppEvent.domain.OS,
         names: [hiAppEvent.event.appFreezeWarning]
       }
     ],
     // You can implement the real-time subscription callback to process the subscribed event data as needed.
     onReceive: (domain: string, appEventGroups: Array<hiAppEvent.AppEventGroup>) => {
       hilog.info(0x0000, 'testTag', `HiAppEvent onReceive: domain=${domain}`);
       for (const eventGroup of appEventGroups) {
         // You can differentiate system events by the event name in the event group.
         hilog.info(0x0000, 'testTag', `HiAppEvent eventName=${eventGroup.name}`);
         for (const eventInfo of eventGroup.appEventInfos) {
           // You can process the event data in the event group as needed. Here, the event data is printed in the log.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.domain=${eventInfo.domain}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.name=${eventInfo.name}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
           // Obtain the timestamp when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
           // Obtain the foreground/background status of the app when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
           // Obtain the unique associated ID of the app when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.app_running_unique_id=${eventInfo.params['app_running_unique_id']}`);
           // Obtain the version information of the app when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version_code=${eventInfo.params['bundle_version_code']}`);
           // Obtain the bundle name of the app when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
           // Obtain the process name of the application when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params['process_name']}`);
           // Obtain the process ID of the application when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
           // Obtain the exception type and cause when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params['exception'])}`);
           // Obtain the log information when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
           // Obtain the unhandled messages on the main thread when the app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler.size=${eventInfo.params['event_handler'].length}`);
           // Obtain the synchronous binder call information when an app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder.size=${eventInfo.params['peer_binder'].length}`);
           // Obtain the full thread call stack when an app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.threads.size=${eventInfo.params['threads'].length}`);
           // Obtain the memory information when an app freeze alarm event occurs.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo.params['memory'])}`);
           // Obtain the faulty process lifetime of the app freeze alarm event.
           hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_life_time=${eventInfo.params['process_life_time']}`);
         }
       }
     }
   });
   ```

3. Edit the **Index.ets** file under **entry > src > main > ets > pages** in the project to add a button that triggers the app freeze warning event. The sample code is as follows:

   ```ts
     @Entry
     @Component
     struct Index {
       build() {
         RelativeContainer() {
           Column() {
             Button("appFreezeWarning", { stateEffect:true, type: ButtonType.Capsule})
               .width('75%')
               .height(50)
               .margin(15)
               .fontSize(20)
               .fontWeight(FontWeight.Bold)
               .onClick(() => {
                // Construct an appFreezeWarning scenario in the button click function to trigger an app freeze alarm event.
                 const t = Date.now();
                 while (Date.now() - t <= 6500) {}
               })
           }.width('100%')
         }
         .height('100%')
         .width('100%')
       }
     }
   ```

4. Run the app project in DevEco Studio, and then click the **appFreezeWarning** button in the app UI to trigger an app freeze warning event.

### Verifying That the Observer Has Received App Freeze Warning Events

After about one minute, the **Log** window displays the logs generated when the system event data is processed:

```text
HiAppEvent onReceive: domain=OS
HiAppEvent eventName=APPFREEZE_WARNING
HiAppEvent eventInfo.domain=OS
HiAppEvent eventInfo.name=APPFREEZE_WARNING
HiAppEvent eventInfo.eventType=1
HiAppEvent eventInfo.params.time=1776946769389
HiAppEvent eventInfo.params.foreground=true
HiAppEvent eventInfo.params.app_running_unique_id=215456512336951247
HiAppEvent eventInfo.params.bundle_version=1.0.0
HiAppEvent eventInfo.params.bundle_version_code=1000000
HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
HiAppEvent eventInfo.params.process_name=com.example.myapplication
HiAppEvent eventInfo.params.pid=39067
HiAppEvent eventInfo.params.uid=20010043
HiAppEvent eventInfo.params.exception={"message":"App main thread is not response!Main handler dump start time: 2026-04-23 20:19:28.903","name":"THREAD_BLOCK_3S"}
HiAppEvent eventInfo.params.hilog.size=77
HiAppEvent eventInfo.params.event_handler.size=6
HiAppEvent eventInfo.params.peer_binder.size=0
HiAppEvent eventInfo.params.threads.size=28
HiAppEvent eventInfo.params.memory={"rss":161080,"sys_avail_mem":1361464,"sys_free_mem":796232,"sys_total_mem":1992340,"vm_heap_total_size":"9961472","vm_heap_used_size":"7596424","vss":56960692}
HiAppEvent eventInfo.params.process_life_time=18
```