# Device Usage Statistics Development (for System Applications Only)
<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->

## When to Use

Device usage statistics include app usage, notification usage, and system usage. For example, application usage statistics are used to save and query application usage details (app usage), event log data (event log), and application group (app group) information.

The application records (usage history statistics and usage event records) cached by components are flushed to the database for persistent storage within 30 minutes after an event is reported.

## Available APIs
Before using the APIs, import the **usageStatistics** module:
```ts
import { usageStatistics } from '@kit.BackgroundTasksKit';
```

**Table 1** Major APIs for device usage statistics

| API| Description|
| -------- | -------- |
| function queryBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | Queries the event set of all applications based on the specified start time and end time.|
| function queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleStatsMap&gt;): void | Queries statistics about application usage duration based on the specified start time and end time.|
| function queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | Queries the event set of the current application based on the specified start time and end time.|
| function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStatsInfo&gt;&gt;): void | Queries statistics about application usage duration based on the specified interval type (day, week, month, or year), start time, and end time.|
| function queryAppGroup(callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of the current application. This API uses an asynchronous callback to return the result.|
| function queryAppGroup(): Promise&lt;number&gt;; | Queries the priority group of the current application. This API uses a promise to return the result.|
|function queryAppGroupSync(): number; | Queries the priority group of the current application. This API returns the result synchronously.|
| function queryAppGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of the application specified by **bundleName**. This API uses an asynchronous callback to return the result.|
| function queryAppGroup(bundleName : string): Promise&lt;number&gt;; | Queries the priority group of the caller application or the specified application. This API uses a promise to return the result.|
|function queryAppGroupSync(bundleName: string): number; |  Queries the priority group of the caller application or the specified application. This API returns the result synchronously.|
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether the application specified by **bundleName** is currently in the idle state.|
|function isIdleStateSync(bundleName: string): boolean; | Checks whether the application specified by **bundleName** is currently in the idle state. This API returns the result synchronously.|
| function queryModuleUsageRecords(callback: AsyncCallback&lt;HapModuleInfo&gt;): void | Queries FA usage records and returns no more than 1000 FA usage records.|
| function queryModuleUsageRecords(maxNum: number, callback: AsyncCallback&lt;HapModuleInfo&gt;): void | Queries FA usage records based on **maxNum** and returns no more than **maxNum** records. **maxNum** cannot exceed 1000.|
| function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | Queries the number of notifications from all applications based on the specified start time and end time.|
| function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | Queries statistics about system events (hibernation, wakeup, unlock, and screen lock) based on the specified start time and end time.|
| function setAppGroup(bundleName : string, newGroup: GroupType, callback: AsyncCallback&lt;void&gt;): void | Sets the group of the application specified by **bundleName** to **newGroup** and returns whether the setting is successful by callback.|
| function setAppGroup(bundleName : string, newGroup : GroupType): Promise&lt;void&gt;; | Sets the group of the application specified by **bundleName** to **newGroup** and returns whether the setting is successful by promise.|
| function registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;, callback: AsyncCallback&lt;void&gt;): void | Registers a callback listener for application group changes and returns whether registration is successful. When an application group changes, callback information is returned to all registered listeners by callback.|
| function registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;): Promise&lt;void&gt;; | Registers a callback listener for application group changes and returns whether registration is successful. When an application group changes, callback information is returned to all registered listeners by promise.|
| function unregisterAppGroupCallBack(callback: AsyncCallback&lt;void&gt;): void | Unregisters the callback listener for application group changes and returns the result by callback.|
| function unregisterAppGroupCallBack(): Promise&lt;void&gt;; | Unregisters the callback listener for application group changes and returns the result by promise.|

## How to Develop

1. Before obtaining device usage statistics, check whether the corresponding permission has been configured and requested.

    The permission provided for device usage statistics is **ohos.permission.BUNDLE_ACTIVE_INFO**.

    For details about the configuration method, see [Requesting Permissions for system_basic Applications](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

2. Query the event set of all applications based on the specified start time and end time. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryBundleEvents(0, 20000000000000).then((res: Array<usageStatistics.BundleEvents>) => {
        console.info('BUNDLE_ACTIVE queryBundleEvents promise success.');
        for (let i = 0; i < res.length; i++) {
            console.info('BUNDLE_ACTIVE queryBundleEvents promise number : ' + (i + 1));
            console.info('BUNDLE_ACTIVE queryBundleEvents promise result ' + JSON.stringify(res[i]));
        }
    }).catch((err: BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryBundleEvents(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.BundleEvents>) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryBundleEvents callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryBundleEvents callback success.');
            for (let i = 0; i < res.length; i++) {
                console.info('BUNDLE_ACTIVE queryBundleEvents callback number : ' + (i + 1));
                console.info('BUNDLE_ACTIVE queryBundleEvents callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

3. Query statistics about application usage duration based on the specified start time and end time. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryBundleStatsInfos(0, 20000000000000).then((res: usageStatistics.BundleStatsMap) => {
        console.info('BUNDLE_ACTIVE queryBundleStatsInfos promise success.');
        console.info('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryBundleStatsInfos promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryBundleStatsInfos(0, 20000000000000, (err: BusinessError, res: usageStatistics.BundleStatsMap) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryBundleStatsInfos callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryBundleStatsInfos callback success.');
            console.info('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res));
        }
    });
    ```

4. Query the event set of the current application based on the specified start time and end time. No permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryCurrentBundleEvents(0, 20000000000000).then((res: Array<usageStatistics.BundleEvents>) => {
        console.info('BUNDLE_ACTIVE queryCurrentBundleEvents promise success.');
        for (let i = 0; i < res.length; i++) {
            console.info('BUNDLE_ACTIVE queryCurrentBundleEvents promise number : ' + (i + 1));
            console.info('BUNDLE_ACTIVE queryCurrentBundleEvents promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryCurrentBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryCurrentBundleEvents(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.BundleEvents>) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryCurrentBundleEvents callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryCurrentBundleEvents callback success.');
            for (let i = 0; i < res.length; i++) {
                console.info('BUNDLE_ACTIVE queryCurrentBundleEvents callback number : ' + (i + 1));
                console.info('BUNDLE_ACTIVE queryCurrentBundleEvents callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

5. Query statistics about application usage duration based on the specified interval type (day, week, month, or year), start time, and end time. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000).then((res: Array<usageStatistics.BundleStatsInfo>) => {
        console.info('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
            console.info('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise number : ' + (i + 1));
            console.info('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err: BusinessError) => {
        console.error('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode

    usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.BundleStatsInfo>) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback success.');
            for (let i = 0; i < res.length; i++) {
                console.info('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback number : ' + (i + 1));
                console.info('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

6. Query the priority group of the current application. No permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryAppGroup().then((res : number) => {
        console.info('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( (err: BusinessError) => {
        console.error('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryAppGroup((err: BusinessError, res: number) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });

    // Synchronous mode
    let priorityGroup = usageStatistics.queryAppGroupSync();

    ```

7. Check whether the application specified by **bundleName** is currently in the idle state. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.isIdleState("com.ohos.camera").then((res: boolean) => {
        console.info('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE isIdleState promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.isIdleState("com.ohos.camera", (err: BusinessError, res: boolean) => {
        if (err) {
            console.error('BUNDLE_ACTIVE isIdleState callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        }
    });

    // Synchronous mode
    let isIdleState = usageStatistics.isIdleStateSync("com.ohos.camera");
    ```

8. Query FA usage records. The maximum number of returned records cannot exceed **maxNum**. If **maxNum** is not passed in, the default value is **1000**. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryModuleUsageRecords(1000).then((res: Array<usageStatistics.HapModuleInfo>) => {
        console.info('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
        for (let i = 0; i < res.length; i++) {
            console.info('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
            console.info('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err: BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Promise mode when maxNum is not specified
    usageStatistics.queryModuleUsageRecords().then((res: Array<usageStatistics.HapModuleInfo>) => {
        console.info('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
        for (let i = 0; i < res.length; i++) {
            console.info('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
            console.info('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err: BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryModuleUsageRecords(1000, (err: BusinessError, res: Array<usageStatistics.HapModuleInfo>) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryModuleUsageRecords callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryModuleUsageRecords callback succeeded.');
            for (let i = 0; i < res.length; i++) {
                console.info('BUNDLE_ACTIVE queryModuleUsageRecords callback number : ' + (i + 1));
                console.info('BUNDLE_ACTIVE queryModuleUsageRecords callback result ' + JSON.stringify(res[i]));
            }
        }
    });

    // Callback mode when maxNum is not specified
    usageStatistics.queryModuleUsageRecords((err: BusinessError, res: Array<usageStatistics.HapModuleInfo>) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryModuleUsageRecords callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryModuleUsageRecords callback succeeded.');
            for (let i = 0; i < res.length; i++) {
                console.info('BUNDLE_ACTIVE queryModuleUsageRecords callback number : ' + (i + 1));
                console.info('BUNDLE_ACTIVE queryModuleUsageRecords callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

9. Query the number of notifications from all applications based on the specified start time and end time. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryNotificationEventStats(0, 20000000000000).then((res: Array<usageStatistics.DeviceEventStats>) => {
        console.info('BUNDLE_ACTIVE queryNotificationEventStats promise success.');
        console.info('BUNDLE_ACTIVE queryNotificationEventStats promise result ' + JSON.stringify(res));
    }).catch((err: BusinessError) => {
        console.error('BUNDLE_ACTIVE queryNotificationEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryNotificationEventStats(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.DeviceEventStats>) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryNotificationEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryNotificationEventStats callback success.');
            console.info('BUNDLE_ACTIVE queryNotificationEventStats callback result ' + JSON.stringify(res));
        }
    });
    ```

10. Query statistics about system events (hibernation, wakeup, unlock, and screen lock) based on the specified start time and end time. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.queryDeviceEventStats(0, 20000000000000).then((res: Array<usageStatistics.DeviceEventStats>) => {
        console.info('BUNDLE_ACTIVE queryDeviceEventStates promise success.');
        console.info('BUNDLE_ACTIVE queryDeviceEventStates promise result ' + JSON.stringify(res));
    }).catch( (err: BusinessError) => {
        console.error('BUNDLE_ACTIVE queryDeviceEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryDeviceEventStats(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.DeviceEventStats>) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryDeviceEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryDeviceEventStats callback success.');
            console.info('BUNDLE_ACTIVE queryDeviceEventStats callback result ' + JSON.stringify(res));
        }
    });
    ```

11. Query the priority group of the application specified by **bundleName**. The query result is the priority group of the application. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode when bundleName is specified
    let bundleName = "com.ohos.camera";
    usageStatistics.queryAppGroup(bundleName).then((res: number) => {
        console.info('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( (err: BusinessError) => {
        console.error('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode when bundleName is specified
    let bundleName = "com.ohos.camera";
    usageStatistics.queryAppGroup(bundleName, (err: BusinessError, res: number) => {
        if (err) {
            console.error('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });
    ```

12. Set the priority group of the application specified by **bundleName** to **newGroup**. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;

    usageStatistics.setAppGroup(bundleName, newGroup).then(() => {
        console.info('BUNDLE_ACTIVE setAppGroup promise succeeded.');
    }).catch((err: BusinessError) => {
        console.error('BUNDLE_ACTIVE setAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;
    usageStatistics.setAppGroup(bundleName, newGroup, (err: BusinessError) => {
        if (err) {
            console.error('BUNDLE_ACTIVE setAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE setAppGroup callback succeeded.');
        }
    });
    ```

13. Register a callback listener for application group changes and return whether registration is successful. When an application group changes, callback information is returned to all registered listeners. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    function  onBundleGroupChanged (res: usageStatistics.AppGroupCallbackInfo) {
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack RegisterGroupCallBack callback success.');
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    usageStatistics.registerAppGroupCallBack(onBundleGroupChanged).then(() => {
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack promise succeeded.');
    }).catch( (err: BusinessError) => {
        console.error('BUNDLE_ACTIVE registerAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    function onBundleGroupChanged (res: usageStatistics.AppGroupCallbackInfo) {
        console.info('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
        console.info('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    usageStatistics.registerAppGroupCallBack(onBundleGroupChanged, (err: BusinessError) => {
        if (err) {
            console.error('BUNDLE_ACTIVE registerAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
         console.info('BUNDLE_ACTIVE registerAppGroupCallBack callback success.');
        }
    });
    ```

14. Unregister the callback listener for application group changes. The **ohos.permission.BUNDLE_ACTIVE_INFO** permission is required.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { usageStatistics } from '@kit.BackgroundTasksKit';

    // Promise mode
    usageStatistics.unregisterAppGroupCallBack().then(() => {
        console.info('BUNDLE_ACTIVE unregisterAppGroupCallBack promise succeeded.');
    }).catch( (err: BusinessError) => {
        console.error('BUNDLE_ACTIVE unregisterAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.unregisterAppGroupCallBack((err: BusinessError) => {
        if (err) {
            console.error('BUNDLE_ACTIVE unregisterAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.info('BUNDLE_ACTIVE unregisterAppGroupCallBack callback success.');
        }
    });
    ```

## Samples

The following samples are available for device usage statistics:

- [Storage Statistic (ArkTS) (Full SDK) (API10)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/StorageStatistic)

- [Device Usage Statistics (ArkTS) (Full SDK) (API9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceUsageStatistics/DeviceUsageStatistics)
