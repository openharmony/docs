# Subscribing to Resource Leak Events (ArkTS)

## Available APIs

For details about how to use the APIs (such as parameter usage constraints and value ranges), see [Application Event Logging](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md).

| API                                             | Description                                        |
| --------------------------------------------------- | -------------------------------------------- |
| addWatcher(watcher: Watcher): AppEventPackageHolder | Adds a watcher to listen for application events.|
| removeWatcher(watcher: Watcher): void               | Removes a watcher to unsubscribe from application events.|

## How to Develop

The following describes how to subscribe to a memory leak event.

1. Create an ArkTS application project. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, import the dependent modules.

   ```ts
   import { hiAppEvent, hilog, hidebug } from '@kit.PerformanceAnalysisKit';
   ```

2. In the **entry/src/main/ets/entryability/EntryAbility.ets** file, add a watcher in **onCreate()** to subscribe to system events. The sample code is as follows:

   ```ts
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
            // You can obtain the memory information when the resource leak event occurs.
            hilog.info(0x0000, 'testTag', `HiAppEvent eventInfo.params.memory=${JSON.stringify(eventInfo)}`);
          }
        }
      }
    });
   ```

3. In the **entry/src/main/ets/pages/index.ets** file, add the **memoryleak** button and construct a scenario for triggering a resource leak event in **onClick()**.
   You can use [hidebug.setAppResourceLimit](../reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugsetappresourcelimit12) to set the application's memory limit to construct a memory leak event and trigger a resource leak event report. You are advised not to use this API in the production environment.
To obtain profiler logs, enable **System resource leak log** in **Developer options**. (You need to restart the device to enable or disable this functionality.)

   <!--RP1-->
   For details about how to locate resource leak errors, see [Memory Leak Analysis](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-snapshot).
   <!--RP1End-->

   The sample code is as follows:

   ```ts
    import hidebug from "@ohos.hidebug";

    @Entry
    @Component
    struct Index {
      @State leakedArray: string[][] = [];

      build() {
        Column() {
          Row() {
            Column() {
              Button("pss leak")
                .onClick(() => {
                  hidebug.setAppResourceLimit("pss_memory", 1024, true);
                  for (let i = 0; i < 20 * 1024; i++) {
                    this.leakedArray.push(new Array(1).fill("leak"));
                  }
                })
            }
          }
          .height('100%')
          .width('100%')
        }
      }
    }
   ```

4. Click the **Run** button in DevEco Studio to run the project, click the **pss leak** button, and then a memory leak event will be reported after 15 to 30 minutes.
   For the same application, the memory leak event can be reported at most once within 24 hours. If the memory leak needs to be reported again within a shorter time, restart the device.

5. After a memory leak event is reported, the system calls **onReceive()**. You can view the following event information in the **Log** window.

   ```text
   HiAppEvent onReceive: domain=OS
   HiAppEvent eventName=RESOURCE_OVERLIMIT
   HiAppEvent eventInfo={"domain":"OS","name":"RESOURCE_OVERLIMIT","eventType":1,"params":{"bundle_name":"com.example.myapplication","bundle_version":"1.0.0","memory":{"pss":2100257,"rss":1352644,"sys_avail_mem":250272,"sys_free_mem":60004,"sys_total_mem":1992340,"vss":2462936},"pid":20731,"resource_type":"pss_memory","time":1502348798106,"uid":20010044,"external_log": ["/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572401_6808.log", "/data/storage/el2/log/resourcelimit/RESOURCE_OVERLIMIT_1725614572412_6808.log"], "log_over_limit": false}}
   ```

6. Currently, in the nolog version<!--Del--> of the commercial OS based on OpenHarmony<!--Del-->, the function of subscribing to VM heap snapshots is enabled. The application needs to call **hidebug.setAppResourceLimit** and **hiAppEvent.addWatcher** in sequence, and configure the following environment variables in the **AppScope/app.json5** file:

    ```text
    "appEnvironments": [
      {
        "name": "DFX_RESOURCE_OVERLIMIT_OPTIONS",
        "value": "oomdump:enable"
      }
    ]
    ```

    The size of a heap snapshot file ranges from 0.4 GB to 1.2 GB (about 50 MB to 100 MB after being compressed in ZIP format). Therefore, the system limits the number of times that heap snapshots are generated. The specifications are as follows:
      - Device: The OOM heap snapshot file can be generated for five times a week. If this limit is exceeded, all applications cannot generate heap snapshots.
      - Application: The OOM heap snapshot file can be generated only once a week.
      - If the remaining storage space of the device is less than 30 GB, **oomdump** is not triggered.
    During debugging, you can adjust the system time to seven days later and restart the device to reset the number of times that the application triggers **oomdump**, so that you can quickly complete function adaptation and verification.

    > **NOTE**
    >
    > After receiving the subscribed event, the application should obtain the path of the heap snapshot file from the **external_log** field of the event, move or upload the file to the cloud as soon as possible, and then delete the original heap snapshot file. Otherwise, the next heap snapshot file may fail to be generated due to insufficient storage space (up to 2 GB) of the application sandbox path directory.<br>
    > The value **field** in the JSON5 configuration file supports the key-value pair set **key1:value1;key2:value2;...**. Currently, the **oomdump** function can be enabled in the nolog version only for applications configured with the preceding key-value pairs.<br>
    > Change the extension of the .log file generated after subscription to **.rawheap**, use [rawheap-translator](../tools/rawheap-translator.md) to convert the file to a .heapsnapshot file, and open the file using DevEco Studio or a browser. For details, see [Importing Heap Snapshots Offline](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388).
