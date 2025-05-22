# Device Usage Statistics Development

## When to Use

Device usage statistics include the usage of applications, notifications, and the system. For example, you can use the APIs for application usage statistics to obtain information about the application usage, event logs, and application groups.

The application records (usage history statistics and event records) cached by components are flushed to the database for persistent storage within 30 minutes after an event is reported.

## Available APIs
Before using the APIs, import the **usageStatistics** module:
```ts
import { usageStatistics } from '@kit.BackgroundTasksKit'
```

**Table 1** Major APIs for device usage statistics

| API | Description |
| -------- | -------- |
| function queryBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | Queries events of all applications based on the specified start time and end time. |
| function queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleStatsMap&gt;): void | Queries the application usage duration based on the specified start time and end time. |
| function queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | Queries events of this application based on the specified start time and end time. |
| function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStatsInfo&gt;&gt;): void | Queries the application usage duration in the specified time frame at the specified interval (daily, weekly, monthly, or annually). |
| function queryAppGroup(callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of this application. This API uses an asynchronous callback to return the result. |
| function queryAppGroup(): Promise&lt;number&gt;; | Queries the priority group of this application. This API uses a promise to return the result. |
|function queryAppGroupSync(): number; | Queries the priority group of this application. This API returns the result synchronously.|
| function queryAppGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of the application specified by **bundleName**. This API uses an asynchronous callback to return the result. |
| function queryAppGroup(bundleName : string): Promise&lt;number&gt;; | Queries the priority group of the application specified by **bundleName**. If **bundleName** is not specified, the priority group of the current application is queried. This API uses a promise to return the result. |
|function queryAppGroupSync(bundleName: string): number; |  Queries the priority group of the application specified by **bundleName**. If **bundleName** is not specified, the priority group of the current application is queried. This API returns the result synchronously.|
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether the application specified by **bundleName** is in the idle state.  |
|function isIdleStateSync(bundleName: string): boolean; | Checks whether the application specified by **bundleName** is in the idle state. This API returns the result synchronously. |
| function queryModuleUsageRecords(callback: AsyncCallback&lt;HapModuleInfo&gt;): void | Obtains a maximum of 1000 FA usage records. |
| function queryModuleUsageRecords(maxNum: number, callback: AsyncCallback&lt;HapModuleInfo&gt;): void | Obtains the number of FA usage records specified by **maxNum**, which cannot exceed 1000.|
| function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | Queries the number of notifications from all applications based on the specified start time and end time. |
| function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | Queries system events (hibernation, wakeup, lock, and unlock) that occur between the specified start time and end time. |
| function setAppGroup(bundleName : string, newGroup: GroupType, callback: AsyncCallback&lt;void&gt;): void | Sets the group for the application specified by **bundleName**. This API uses an asynchronous callback to return the result. |
| function setAppGroup(bundleName : string, newGroup : GroupType): Promise&lt;void&gt;; | Sets the group for the application specified by **bundleName**. This API uses a promise to return the result. |
| function registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;, callback: AsyncCallback&lt;void&gt;): void | Registers a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. This API uses an asynchronous callback to return the result. |
| function registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;): Promise&lt;void&gt;; | Registers a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. This API uses a promise to return the result. |
| function unregisterAppGroupCallBack(callback: AsyncCallback&lt;void&gt;): void | Deregisters the callback for application group changes. This API uses an asynchronous callback to return the result. |
| function unregisterAppGroupCallBack(): Promise&lt;void&gt;; | Deregisters the callback for application group changes. This API uses a promise to return the result. |

## How to Develop

1. Before obtaining the device usage statistics, check that the application has the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.
   
    For details, see [Requesting Permissions for system_basic Applications](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

2. Query events of all applications based on the specified start time and end time. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryBundleEvents(0, 20000000000000).then( (res : Array<usageStatistics.BundleEvents>) => {
        console.log('BUNDLE_ACTIVE queryBundleEvents promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleEvents promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleEvents promise result ' + JSON.stringify(res[i]));
        }
    }).catch((err : BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    usageStatistics.queryBundleEvents(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.BundleEvents>) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryBundleEvents callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleEvents callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleEvents callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleEvents callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

3. Query the application usage duration based on the specified start time and end time. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryBundleStatsInfos(0, 20000000000000).then( (res : usageStatistics.BundleStatsMap) => {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise success.');
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryBundleStatsInfos promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    usageStatistics.queryBundleStatsInfos(0, 20000000000000, (err : BusinessError, res : usageStatistics.BundleStatsMap) => {
        if (err) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback success.');
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res));
        }
    });
    ```

4. Query events of this application based on the specified start time and end time. No permission is required for calling the **queryCurrentBundleEvents()** API.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryCurrentBundleEvents(0, 20000000000000).then( (res : Array<usageStatistics.BundleEvents>) => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise success.');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryCurrentBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    usageStatistics.queryCurrentBundleEvents(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.BundleEvents>) => {
        if (err) {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents callback success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleEvents callback number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryCurrentBundleEvents callback result ' + JSON.stringify(res[i]));
        }
        }
    });
    ```

5. Query the application usage duration in the specified time frame at the specified interval (daily, weekly, monthly, or annually). The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000).then( (res : Array<usageStatistics.BundleStatsInfo>) => {
    console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode

    usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.BundleStatsInfo>) => {
        if (err) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval callback result ' + JSON.stringify(res[i]));
        }
        }
    });
    ```

6. Query the priority group of the current application. No permission is required for calling the **queryAppGroup()** API.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryAppGroup().then( (res : number) => {
        console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.queryAppGroup((err : BusinessError, res : number) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });

    // Synchronous mode
    let priorityGroup = usageStatistics.queryAppGroupSync();

    ```

7. Check whether the application specified by **bundleName** is in the idle state. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.isIdleState("com.ohos.camera").then( (res : boolean) => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE isIdleState promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    usageStatistics.isIdleState("com.ohos.camera", (err : BusinessError, res : boolean) => {
        if (err) {
        console.log('BUNDLE_ACTIVE isIdleState callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        }
    });

    // Synchronous mode
    let isIdleState = usageStatistics.isIdleStateSync("com.ohos.camera");
    ```

8. Obtain the number of FA usage records specified by **maxNum**. If **maxNum** is not specified, the default value **1000** is used. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryModuleUsageRecords(1000).then( (res : Array<usageStatistics.HapModuleInfo>) => {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Promise mode when maxNum is not specified
    usageStatistics.queryModuleUsageRecords().then( (res : Array<usageStatistics.HapModuleInfo>) => {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    usageStatistics.queryModuleUsageRecords(1000, (err : BusinessError, res : Array<usageStatistics.HapModuleInfo>) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback succeeded.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback result ' + JSON.stringify(res[i]));
        }
        }
    });

    // Asynchronous callback mode when maxNum is not specified
    usageStatistics.queryModuleUsageRecords((err : BusinessError, res : Array<usageStatistics.HapModuleInfo>) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback succeeded.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords callback result ' + JSON.stringify(res[i]));
        }
        }
    });
    ```

9. Query the number of notifications from all applications based on the specified start time and end time. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryNotificationEventStats(0, 20000000000000).then( (res : Array<usageStatistics.DeviceEventStats>) => {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats promise success.');
        console.log('BUNDLE_ACTIVE queryNotificationEventStats promise result ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryNotificationEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    usageStatistics.queryNotificationEventStats(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.DeviceEventStats>) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats callback success.');
        console.log('BUNDLE_ACTIVE queryNotificationEventStats callback result ' + JSON.stringify(res));
        }
    });
    ```

10. Query statistics about system events (hibernation, wakeup, lock, and unlock) that occur between the specified start time and end time. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.queryDeviceEventStats(0, 20000000000000).then( (res : Array<usageStatistics.DeviceEventStats>) => {
        console.log('BUNDLE_ACTIVE queryDeviceEventStates promise success.');
        console.log('BUNDLE_ACTIVE queryDeviceEventStates promise result ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryDeviceEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    usageStatistics.queryDeviceEventStats(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.DeviceEventStats>) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryDeviceEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryDeviceEventStats callback success.');
        console.log('BUNDLE_ACTIVE queryDeviceEventStats callback result ' + JSON.stringify(res));
        }
    });
    ```

11. Query the priority group of the application specified by **bundleName**. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

     ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode when bundleName is specified
    let bundleName = "com.ohos.camera";
    usageStatistics.queryAppGroup(bundleName).then( (res : number) => {
        console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode when bundleName is specified
    let bundleName = "com.ohos.camera";
    usageStatistics.queryAppGroup(bundleName, (err : BusinessError, res : number) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });
     ```

12. Set the priority group of for application specified by **bundleName**. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;

    usageStatistics.setAppGroup(bundleName, newGroup).then( () => {
        console.log('BUNDLE_ACTIVE setAppGroup promise succeeded.');
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE setAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;
    usageStatistics.setAppGroup(bundleName, newGroup, (err : BusinessError) => {
        if(err) {
        console.log('BUNDLE_ACTIVE setAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE setAppGroup callback succeeded.');
        }
    });
    ```

13. Register a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    function  onBundleGroupChanged (res : usageStatistics.AppGroupCallbackInfo) {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack RegisterGroupCallBack callback success.');
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    usageStatistics.registerAppGroupCallBack(onBundleGroupChanged).then( () => {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack promise succeeded.');
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE registerAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Asynchronous callback mode
    function onBundleGroupChanged (res : usageStatistics.AppGroupCallbackInfo) {
    console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    usageStatistics.registerAppGroupCallBack(onBundleGroupChanged, (err : BusinessError) => {
    if(err) {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
    } else {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback success.');
    }
    });
    ```

14. Deregister the callback for application group changes. The caller must have the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // Promise mode
    usageStatistics.unregisterAppGroupCallBack().then( () => {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise succeeded.');
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE unregisterAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // Callback mode
    usageStatistics.unregisterAppGroupCallBack((err : BusinessError) => {
        if(err) {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback success.');
        }
    });
    ```
