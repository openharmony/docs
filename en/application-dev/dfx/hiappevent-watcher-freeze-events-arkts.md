# Subscribing to Application Freeze Events (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-31T01:26:08.843Z pushedAt=2026-07-31T03:45:32.873Z -->

## Overview

This document describes how to use the ArkTS APIs provided by HiAppEvent to subscribe to app freeze events. For detailed usage instructions (parameter constraints, value ranges, etc.) of the APIs, see [@ohos.hiviewdfx.hiAppEvent](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

## Available APIs

| API| Description|
| -------- | -------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void | Removes a watcher to unsubscribe from application events.|

## How to Develop

### Adding an Event Watcher

The following walks you through on how to subscribe to the application freeze events.

1. In DevEco Studio, create an ArkTS app project, edit the **entry > src > main > ets > entryability > EntryAbility.ets** file in the project, and import the dependent modules. The sample code is as follows:

   ```ts
   import { BusinessError, deviceInfo } from '@kit.BasicServicesKit';
   import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, set the custom parameters in **onCreate()**. The sample code is as follows:

   ```ts
    // Assign a value to params, which is a key-value pair.
    let params: Record<string, hiAppEvent.ParamType> = {
      "test_data": 100,
    };
    // Set custom parameters for the application freeze event.
    hiAppEvent.setEventParam(params, hiAppEvent.domain.OS, hiAppEvent.event.APP_FREEZE).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to set event param`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
    });

    if (deviceInfo.sdkApiVersion >= 24) {  // API version 24 and later supports setting page switch logs.
      // Configure page switch logs.
      let switchLogPolicy : hiAppEvent.EventPolicy = {
        "appFreezePolicy": {
          "pageSwitchLogEnable": true
        }
      };
      // You can set app freeze log configuration parameters.
      hiAppEvent.configEventPolicy(switchLogPolicy).then(() => {
        hilog.info(0x0000, 'testTag', `HiAppEvent success to config event policy.`);
      }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', `HiAppEvent code: ${err.code}, message: ${err.message}`);
      });
    }
   ```

3. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add a watcher in **onCreate()** to subscribe to system events. The sample code is as follows:

   ```ts
     hiAppEvent.addWatcher({
      // Set the watcher name. The system identifies different watchers based on their names.
      name: "watcher",
      // You can subscribe to system events that you are interested in. Here, the application freeze event is subscribed to.
      appEventFilters: [
        {
          domain: hiAppEvent.domain.OS,
          names: [hiAppEvent.event.APP_FREEZE]
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
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.eventType=${eventInfo.eventType}`);
            // Obtain the timestamp when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.time=${eventInfo.params['time']}`);
            // Obtain the foreground/background status of the application when it freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.foreground=${eventInfo.params['foreground']}`);
            // Obtain the unique associated ID of the app when an app freeze event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.app_running_unique_id=${eventInfo.params['app_running_unique_id']}`);
            // Obtain the version information of the application when it freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_version=${eventInfo.params['bundle_version']}`);
            // Obtain the bundle name of the application when it freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.bundle_name=${eventInfo.params['bundle_name']}`);
            // Obtain the process name of the application when it freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_name=${eventInfo.params['process_name']}`);
            // Obtain the process ID of the application when it freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.pid=${eventInfo.params['pid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uid=${eventInfo.params['uid']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.uuid=${eventInfo.params['uuid']}`);
            // Obtain the exception type and cause of the application freeze event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.exception=${JSON.stringify(eventInfo.params['exception'])}`);
            // Obtain the log information when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.hilog.size=${eventInfo.params['hilog'].length}`);
            // Obtain the messages that are not yet processed by the main thread when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler.size=${eventInfo.params['event_handler'].length}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_3s=${eventInfo.params['event_handler_size_3s']}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.event_handler_size_6s=${eventInfo.params['event_handler_size_6s']}`);
            // Obtain the synchronous binder call information when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.peer_binder.size=${eventInfo.params['peer_binder'].length}`);
            // Obtain the full thread call stack when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.threads.size=${eventInfo.params['threads'].length}`);
            // Obtain the memory information when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo.params['memory'])}`);
            // Obtain the fault log file when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_log=${JSON.stringify(eventInfo.params['external_log'])}`);
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.log_over_limit=${eventInfo.params['log_over_limit']}`);
            // Obtain the custom test_data of the application freeze event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.test_data=${eventInfo.params['test_data']}`);
            // Obtain the lifetime of the faulty process when the application freezes.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.process_life_time=${eventInfo.params['process_life_time']}`);
            // Obtain the callback log information of the app freeze event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.external_callback_log=${eventInfo.params['external_callback_log']}`);
            // Obtain the page transition log of the app freeze event.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.page_switch_log=${JSON.stringify(eventInfo.params['page_switch_log'])}`);
          }
        }
      }
    });
   ```

4. In the **entry/src/main/ets/pages/index.ets** file, add a button and construct an application freeze scenario for triggering an application freeze event in **onClick()**. The sample code is as follows:

   ```ts
    Button("appFreeze").onClick(()=>{
      // Construct a freeze scenario in onClick() to trigger an application freeze event.
      setTimeout(() => {
        let t = Date.now();
        while (Date.now() - t <= 15000) {}
      }, 5000);
    })
   ```

5. In DevEco Studio, click the **Run** button to run the project. Then, click the **appfreeze** button to trigger an application freeze event.

### Verifying the Subscription

1. The application exits due to the application freeze event. After restarting the application, you can view the following event information in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=APP_FREEZE
   HiAppEvent eventInfo.domain=OS
   HiAppEvent eventInfo.name=APP_FREEZE
   HiAppEvent eventInfo.eventType=1
   HiAppEvent eventInfo.params.time=1711440881768
   HiAppEvent eventInfo.params.foreground=true
   HiAppEvent eventInfo.params.app_running_unique_id=215456512336951247
   HiAppEvent eventInfo.params.bundle_version=1.0.0
   HiAppEvent eventInfo.params.bundle_name=com.example.myapplication
   HiAppEvent eventInfo.params.process_name=com.example.myapplication
   HiAppEvent eventInfo.params.pid=3197
   HiAppEvent eventInfo.params.uid=20010043
   HiAppEvent eventInfo.params.uuid=27fac7098da46efe1cae9904946ec06c5acc91689c365efeefb7a23a0c37df77
   HiAppEvent eventInfo.params.exception={"message":"App main thread is not response!","name":"THREAD_BLOCK_6S"}
   HiAppEvent eventInfo.params.hilog.size=77
   HiAppEvent eventInfo.params.event_handler.size=6
   HiAppEvent eventInfo.params.event_handler_size_3s=5
   HiAppEvent eventInfo.params.event_handler_size_6s=6
   HiAppEvent eventInfo.params.peer_binder.size=0
   HiAppEvent eventInfo.params.threads.size=28
   HiAppEvent eventInfo.params.memory={"pss":0,"rss":0,"sys_avail_mem":1361464,"sys_free_mem":796232,"sys_total_mem":1992340,"vm_heap_total_size":"9961472","vm_heap_used_size":"7596424","vss":0}
   HiAppEvent eventInfo.params.external_log=["/data/storage/el2/log/hiappevent/APP_FREEZE_1711440899240_3197.log"]
   HiAppEvent eventInfo.params.log_over_limit=false
   HiAppEvent eventInfo.params.test_data=100
   HiAppEvent eventInfo.params.process_life_time=18
   HiAppEvent eventInfo.params.external_callback_log=THREAD_BLOCK_3S:log3s THREAD_BLOCK_6S:log6s
   HiAppEvent eventInfo.params.page_switch_log=["/data/storage/el2/log/page_switch/snapshot/page_switch-com.example.myapplication-1-1-20260717101852288.log"]
   ```

2. If the application fails to start or remains unstarted for a long time, you can delay the event notification by referring to [Using FaultLogExtensionAbility to Subscribe to Events](./fault-log-extension-app-events-arkts.md).

## Migrating App Freeze Events from the FaultLogger API

The [@ohos.faultLogger (FaultLogger)](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md) API has been deprecated since API version 18 and is no longer maintained. Later versions recommend using [@ohos.hiviewdfx.hiAppEvent](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md) to subscribe to app freeze events. This section guides you through migrating from the FaultLogger API to the HiAppEvent API for subscribing to app freeze events.

**APP_FREEZE** defined in the [FaultType](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md#faulttype) of FaultLogger is the app freeze fault type.

Set the event name to **hiAppEvent.event.APP_FREEZE** and event domain to **hiAppEvent.domain.OS** in the **hiAppEvent.addWatcher** API of HiAppEvent to subscribe to the application freeze event.

You can distinguish different application freeze events based on the **name** field of the **exception** field in [hiAppEvent.AppEventInfo.params](./hiappevent-watcher-freeze-events.md#params).

The following table shows the mapping between [FaultLogInfo](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md#faultloginfo) and [hiAppEvent.AppEventInfo.params](./hiappevent-watcher-freeze-events.md#params).

| FaultLogger.FaultLogInfo | hiAppEvent.AppEventInfo.params | Description |
| --- | --- | --- |
| pid | pid | N/A |
| uid | uid | N/A |
| type | The name subfield in the exception field | The types differ: FaultLogger uses a fault type enum, while hiAppEvent uses a string. |
| timestamp | time | N/A |
| module | bundle_name | N/A |
| fullLog | external_log | fullLog is the full fault log text. external_log is the specific path of the fault log file in the app sandbox (/data/storage/el2/log/). Access the file at this path to obtain the full fault log text. |
| reason | The Reason field in the external_log file content | N/A |
| summary | A specific section in the external_log file content | For APP_FREEZE, summary corresponds to the section from the line containing "appfreeze:<process name>" to the line containing "DisplayPowerInfo:" in the external_log file. |

Both [FaultLogger.query](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md#faultloggerquery9) (using callback) and [FaultLogger.query](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md#faultloggerquery9-1) (using promise) can be replaced with [hiAppEvent.addWatcher](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddwatcher) to achieve the same functionality.

For details about how to use HiAppEvent to subscribe to app freeze events (ArkTS), see [How to Develop](#how-to-develop) and [Verifying the Subscription](#verifying-the-subscription).

<!--RP1-->
<!--RP1End-->