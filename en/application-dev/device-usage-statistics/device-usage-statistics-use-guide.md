# Device Usage Statistics Development (API Version 9)

## When to Use

With device usage statistics APIs, you can have a better understanding of the application, notification, and system usage. For example, in application usage statistics, you can query the application usage, event log, and application group.
The application records (usage history statistics and event records) cached by components are updated to the database for persistent storage within 30 minutes after an event is reported.

## Available APIs
Import the **stats** package to implement registration:
```js
import usageStatistics from '@ohos.resourceschedule.usageStatistics';
```

**Table 1** Major APIs for device usage statistics

| API| Description|
| -------- | -------- |
| function queryBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | Queries events of all applications based on the specified start time and end time.|
| function queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleStatsMap&gt;): void | Queries the application usage duration statistics based on the specified start time and end time.|
| function queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | Queries events of this application based on the specified start time and end time.|
| function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStatsInfo&gt;&gt;): void | Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually).|
| function queryAppGroup(callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of this application. This API uses an asynchronous callback to return the result.|
| function queryAppGroup(): Promise&lt;number&gt;; | Queries the priority group of this application. This API uses a promise to return the result.|
| function queryAppGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of the application specified by **bundleName**. This API uses an asynchronous callback to return the result.|
| function queryAppGroup(bundleName : string): Promise&lt;number&gt;; | Queries the priority group of the application specified by **bundleName**. If **bundleName** is not specified, the priority group of the current application is queried. This API uses a promise to return the result.|
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether the application specified by **bundleName** is in the idle state. |
| function queryModuleUsageRecords(callback: AsyncCallback&lt;HapModuleInfo&gt;): void | Obtains a maximum of 1000 FA usage records.|
| function queryModuleUsageRecords(maxNum: number, callback: AsyncCallback&lt;HapModuleInfo&gt;): void | Obtains the number of FA usage records specified by **maxNum**, which cannot exceed 1000.|
| function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | Queries the number of notifications from all applications based on the specified start time and end time.|
| function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | Queries statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time.|
| function setAppGroup(bundleName : string, newGroup: GroupType, callback: AsyncCallback&gt;boolean&gt;): void | Sets the group for the application specified by **bundleName**. This API uses an asynchronous callback to return the result.|
| function setAppGroup(bundleName : string, newGroup : GroupType): Promise&gt;boolean&gt;; | Sets the group for the application specified by **bundleName**. This API uses a promise to return the result.|
| function registerAppGroupCallBack(groupCallback: Callback&gt;AppGroupCallbackInfo&gt;, callback: AsyncCallback&gt;boolean&gt;): void | Registers a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. This API uses an asynchronous callback to return the result.|
| function registerAppGroupCallBack(groupCallback: Callback&gt;AppGroupCallbackInfo&gt;): Promise&gt;boolean&gt;; | Registers a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. This API uses a promise to return the result.|
| function unregisterAppGroupCallBack(callback: AsyncCallback&gt;boolean&gt;): void | Deregisters the callback for application group changes. This API uses an asynchronous callback to return the result.|
| function unregisterAppGroupCallBack(): Promise&gt;boolean&gt;; | Deregisters the callback for application group changes. This API uses a promise to return the result.|

## How to Develop

1. Before obtaining the device usage statistics, check whether the **ohos.permission.BUNDLE_ACTIVE_INFO** permission is configured. For details about how to configure a permission, see [Declaring Permissions](../security/accesstoken-guidelines.md).
   
2. Query events of all applications based on the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryBundleEvents(0, 20000000000000).then( res => {
            console.log('BUNDLE_ACTIVE queryBundleEvents promise success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleEvents promise number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleEvents promise result ' + JSON.stringify(res[i]));
            }
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryBundleEvents throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.queryBundleEvents(0, 20000000000000, (err, res) => {
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
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryBundleEvents throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

3. Query the application usage duration statistics based on the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryBundleStatsInfos(0, 20000000000000).then( res => {
            console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise success.');
            let i = 1;
            for(let key in res){
                console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise number : ' + i);
                console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise result ' + JSON.stringify(res[key]));
                i++;
            }
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.queryBundleStatsInfos(0, 20000000000000, (err, res) => {
            if (err) {
                console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback success.');
            let i = 1;
            for(let key in res){
                console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback number : ' + i);
                console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res[key]));
                i++;
            }
            }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

4. Query events of this application based on the specified start time and end time. This requires no permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryCurrentBundleEvents(0, 20000000000000).then( res => {
            console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise result ' + JSON.stringify(res[i]));
            }
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.queryCurrentBundleEvents(0, 20000000000000, (err, res) => {
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
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

5. Query the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000).then( res => {
            console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise result ' + JSON.stringify(res[i]));
            }
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000, (err, res) => {
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
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

6. Query the priority group of the current application. This requires no permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryAppGroup().then( res => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Callback mode
    try{
        usageStatistics.queryAppGroup((err, res) => {
            if(err) {
                console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
            }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

7. Check whether the application specified by **bundleName** is in the idle state. This requires no permission to be configured. A third-party application can only check the idle status of itself.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.isIdleState("com.ohos.camera").then( res => {
            console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
        }).catch( err => {
            console.log('BUNDLE_ACTIVE isIdleState promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE isIdleState throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.isIdleState("com.ohos.camera", (err, res) => {
            if (err) {
                console.log('BUNDLE_ACTIVE isIdleState callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
            }
        });
    } catch(error) {
        console.log('BUNDLE_ACTIVE isIdleState throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

8. Obtain the number of FA usage records specified by **maxNum**. If **maxNum** is not specified, the default value **1000** is used. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryModuleUsageRecords(1000).then( res => {
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
            }
        }).catch( err=> {
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Promise mode when maxNum is not specified
    try{
        usageStatistics.queryModuleUsageRecords().then( res => {
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
            }
        }).catch( err=> {
            console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.queryModuleUsageRecords(1000, (err, res) => {
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
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode when maxNum is not specified
    try{
        usageStatistics.queryModuleUsageRecords((err, res) => {
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
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

9. Query the number of notifications from all applications based on the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryNotificationEventStats(0, 20000000000000).then( res => {
            console.log('BUNDLE_ACTIVE queryNotificationEventStats promise success.');
            console.log('BUNDLE_ACTIVE queryNotificationEventStats promise result ' + JSON.stringify(res));
        }).catch( err=> {
            console.log('BUNDLE_ACTIVE queryNotificationEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.queryNotificationEventStats(0, 20000000000000, (err, res) => {
            if(err) {
                console.log('BUNDLE_ACTIVE queryNotificationEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE queryNotificationEventStats callback success.');
                console.log('BUNDLE_ACTIVE queryNotificationEventStats callback result ' + JSON.stringify(res));
            }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

10. Query statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    try{
        usageStatistics.queryDeviceEventStats(0, 20000000000000).then( res => {
            console.log('BUNDLE_ACTIVE queryDeviceEventStates promise success.');
            console.log('BUNDLE_ACTIVE queryDeviceEventStates promise result ' + JSON.stringify(res));
        }).catch( err=> {
            console.log('BUNDLE_ACTIVE queryDeviceEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryDeviceEventStats throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    try{
        usageStatistics.queryDeviceEventStats(0, 20000000000000, (err, res) => {
            if(err) {
                console.log('BUNDLE_ACTIVE queryDeviceEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE queryDeviceEventStats callback success.');
                console.log('BUNDLE_ACTIVE queryDeviceEventStats callback result ' + JSON.stringify(res));
            }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryDeviceEventStats throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

11. Query the priority group of the application specified by **bundleName**. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

     ```js
     import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode when bundleName is specified
    let bundleName = "com.ohos.camera";
    try{
        usageStatistics.queryAppGroup(bundleName).then( res => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

     // Asynchronous callback mode when bundleName is specified
    let bundleName = "com.ohos.camera";
    try{
        usageStatistics.queryAppGroup(bundleName, (err, res) => {
            if(err) {
                console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
            }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
     ```

12. Set the priority group of for application specified by **bundleName**. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```javascript
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = bundleState.GroupType.ACTIVE_GROUP_DAILY;

    try{
        usageStatistics.setAppGroup(bundleName, newGroup).then( () => {
            console.log('BUNDLE_ACTIVE setAppGroup promise succeeded.');
        }).catch( err => {
            console.log('BUNDLE_ACTIVE setAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE setAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = bundleState.GroupType.ACTIVE_GROUP_DAILY;

    try{
        usageStatistics.setAppGroup(bundleName, newGroup, (err) => {
            if(err) {
                console.log('BUNDLE_ACTIVE setAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE setAppGroup callback succeeded.');
            }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE setAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

13. Register a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```javascript
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // Promise mode
    let onBundleGroupChanged = (res) =>{
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack RegisterGroupCallBack callback success.');
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    try{
        usageStatistics.registerAppGroupCallBack(onBundleGroupChanged).then( () => {
            console.log('BUNDLE_ACTIVE registerAppGroupCallBack promise succeeded.');
        }).catch( err => {
            console.log('BUNDLE_ACTIVE registerAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // Asynchronous callback mode
    let onBundleGroupChanged = (err, res) =>{
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    try{
        usageStatistics.registerAppGroupCallBack(onBundleGroupChanged, err => {
        if(err) {
            console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback success.');
        }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```

14. Deregister the callback for application group changes. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured.

    ```javascript
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // promise
    try{
        usageStatistics.unregisterAppGroupCallBack().then( () => {
            console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise succeeded.');
        }).catch( err => {
            console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // callback
    try{
        usageStatistics.unregisterAppGroupCallBack(err => {
            if(err) {
                console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
            } else {
                console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback success.');
            }
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
    ```