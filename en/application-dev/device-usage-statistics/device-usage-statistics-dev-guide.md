# Device Usage Statistics Development

## When to Use

With device usage statistics APIs, you can have a better understanding of the application, notification, and system usage. For example, in application usage statistics, you can query the application usage, event log, and bundle group.
The application records (usage history statistics and event records) cached by components are updated to the database for persistent storage within 30 minutes after an event is reported.

## Available APIs
Import the **stats** package to implement registration:
```js
import stats from '@ohos.bundleState';
```

**Table 1** Major APIs for device usage statistics

| API| Description|
| -------- | -------- |
| function queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;): void | Queries events of all applications based on the specified start time and end time.|
| function queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleActiveInfoResponse&gt;): void | Queries the application usage duration statistics based on the specified start time and end time.|
| function queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;): void | Queries events of this application based on the specified start time and end time.|
| function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStateInfo&gt;&gt;): void | Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually).|
| function queryAppUsagePriorityGroup(callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of this application. This API uses an asynchronous callback to return the result.|
| function queryAppUsagePriorityGroup(): Promise&lt;number&gt;; | Queries the priority group of this application. This API uses a promise to return the result.|
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether the application specified by **bundleName** is in the idle state. |
| function getRecentlyUsedModules(callback: AsyncCallback&lt;BundleActiveModuleInfo&gt;): void | Obtains a maximum of 1000 FA usage records. |
| function getRecentlyUsedModules(maxNum: number, callback: AsyncCallback&lt;BundleActiveModuleInfo&gt;): void | Obtains the number of FA usage records specified by **maxNum**, which cannot exceed 1000.|
| function queryAppNotificationNumber(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveEventState&gt;&gt;): void | Queries the number of notifications from all applications based on the specified start time and end time.|
| function queryBundleActiveEventStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveEventState&gt;&gt;): void | Queries statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time.|
| function queryAppUsagePriorityGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of the application specified by **bundleName**. This API uses an asynchronous callback to return the result.|
| function queryAppUsagePriorityGroup(bundleName? : string): Promise&lt;number&gt;; | Queries the priority group of the application specified by **bundleName**. If **bundleName** is not specified, the priority group of the current application is queried. This API uses a promise to return the result.|
| function setBundleGroup(bundleName : string, newGroup: GroupType, callback: AsyncCallback&gt;boolean&gt;): void | Sets the group for the application specified by **bundleName**. This API uses an asynchronous callback to return the result.|
| function setBundleGroup(bundleName : string, newGroup : GroupType): Promise&gt;boolean&gt;; | Sets the group for the application specified by **bundleName**. This API uses a promise to return the result.|
| function registerGroupCallBack(groupCallback: Callback&gt;BundleActiveGroupCallbackInfo&gt;, callback: AsyncCallback&gt;boolean&gt;): void | Registers a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. This API uses an asynchronous callback to return the result.|
| function registerGroupCallBack(groupCallback: Callback&gt;BundleActiveGroupCallbackInfo&gt;): Promise&gt;boolean&gt;; | Registers a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback. This API uses a promise to return the result.|
| function unRegisterGroupCallBack(callback: AsyncCallback&gt;boolean&gt;): void | Deregisters the callback for application group changes. This API uses an asynchronous callback to return the result.|
| function unRegisterGroupCallBack(): Promise&gt;boolean&gt;; | Deregisters the callback for application group changes. This API uses a promise to return the result.|

## How to Develop

1. Configure the device usage statistics permission in the **config.json** file.

    ```json
    "module": {
        "package": "com.example.deviceUsageStatistics",
        ...,
        "reqPermissions": [
            {
                "name": "ohos.permission.BUNDLE_ACTIVE_INFO"
            }
        ]
    }
    ```

2. Query events of all applications based on the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.queryBundleActiveStates(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.queryBundleActiveStates(0, 20000000000000, (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleActiveStates callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleActiveStates callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

3. Query the application usage duration statistics based on the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.queryBundleStateInfos(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfos promise success.');
        let i = 1;
        for (let key in res){
            console.log('BUNDLE_ACTIVE queryBundleStateInfos promise number : ' + i);
            console.log('BUNDLE_ACTIVE queryBundleStateInfos promise result ' + JSON.stringify(res[key]));
            i++;
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfos promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.queryBundleStateInfos(0, 20000000000000, (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfos callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleStateInfos callback success.');
            let i = 1;
            for(let key in res){
                console.log('BUNDLE_ACTIVE queryBundleStateInfos callback number : ' + i);
                console.log('BUNDLE_ACTIVE queryBundleStateInfos callback result ' + JSON.stringify(res[key]));
                i++;
            }
        }
    });
    ```

4. Query events of this application based on the specified start time and end time. This requires no permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.queryCurrentBundleActiveStates(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.queryCurrentBundleActiveStates(0, 20000000000000, (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

5. Query the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000, (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

6. Query the priority group of the current application. This requires no permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.queryAppUsagePriorityGroup().then(res => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise failed. because: ' + err.code);
    });

    // Callback mode
    stats.queryAppUsagePriorityGroup((err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback failed. because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });
    ```

7. Check whether the application specified by **bundleName** is in the idle state. This requires no permission to be configured in the **config.json** file. A third-party application can only check the idle status of itself.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.isIdleState("com.ohos.camera").then(res => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch(err => {
        console.log('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.isIdleState("com.ohos.camera", (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE isIdleState callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        }
    });
    ```

8. Obtain the number of FA usage records specified by **maxNum**. If **maxNum** is not specified, the default value **1000** is used. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.getRecentlyUsedModules(1000).then(res => {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise succeeded');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise result ' + JSON.stringify(res[i]));
        }
    }).catch(err=> {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise failed, because: ' + err.code);
    });

    // Promise mode when maxNum is not specified
    stats.getRecentlyUsedModules().then(res => {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise succeeded');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err=> {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.getRecentlyUsedModules(1000, (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback succeeded.');
                for (let i = 0; i < res.length; i++) {
                    console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback number : ' + (i + 1));
                    console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback result ' + JSON.stringify(res[i]));
                }
            }
    });

    // Asynchronous callback mode when maxNum is not specified
    stats.getRecentlyUsedModules((err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback succeeded.');
                for (let i = 0; i < res.length; i++) {
                    console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback number : ' + (i + 1));
                    console.log('BUNDLE_ACTIVE getRecentlyUsedModules callback result ' + JSON.stringify(res[i]));
                }
            }
    });
    ```

9. Query the number of notifications from all applications based on the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.queryAppNotificationNumber(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryAppNotificationNumber promise success.');
        console.log('BUNDLE_ACTIVE queryAppNotificationNumber promise result ' + JSON.stringify(res));
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryAppNotificationNumber promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.queryAppNotificationNumber(0, 20000000000000, (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryAppNotificationNumber callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryAppNotificationNumber callback success.');
            console.log('BUNDLE_ACTIVE queryAppNotificationNumber callback result ' + JSON.stringify(res));
        }
    });
    ```

10. Query statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.queryBundleActiveEventStates(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryBundleActiveEventStates promise success.');
        console.log('BUNDLE_ACTIVE queryBundleActiveEventStates promise result ' + JSON.stringify(res));
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryBundleActiveEventStates promise failed, because: ' + err.code);
    });

    // Asynchronous callback mode
    stats.queryBundleActiveEventStates(0, 20000000000000, (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE queryBundleActiveEventStates callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleActiveEventStates callback success.');
            console.log('BUNDLE_ACTIVE queryBundleActiveEventStates callback result ' + JSON.stringify(res));
        }
    });
    ```

11. Query the priority group of the current application. This requires no permission to be configured in the **config.json** file. Query the priority group of a specified application. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

     ```js
     import stats from '@ohos.bundleState'

     // Promise mode when bundleName is not specified
     stats.queryAppUsagePriorityGroup().then(res => {
         console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
     }).catch(err => {
         console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise failed. because: ' + err.code);
     });

     // Asynchronous callback mode when bundleName is not specified
     stats.queryAppUsagePriorityGroup((err, res) => {
         if (err) {
             console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback failed. because: ' + err.code);
         } else {
             console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback succeeded. result: ' + JSON.stringify(res));
         }
     });
    let bundleName = "com.ohos.camera";
     // Promise mode when bundleName is specified
     stats.queryAppUsagePriorityGroup(bundleName).then(res => {
         console.log('BUNDLE_ACTIVE QueryPackageGroup promise succeeded. result: ' + JSON.stringify(res));
     }).catch(err => {
         console.log('BUNDLE_ACTIVE QueryPackageGroup promise failed. because: ' + err.code);
     });

     // Asynchronous callback mode when bundleName is specified
     stats.queryAppUsagePriorityGroup(bundleName, (err, res) => {
         if (err) {
             console.log('BUNDLE_ACTIVE QueryPackageGroup callback failed. because: ' + err.code);
         } else {
             console.log('BUNDLE_ACTIVE QueryPackageGroup callback succeeded. result: ' + JSON.stringify(res));
         }
     });
     ```

11. Set the group for the application specified by **bundleName**.

    ```javascript
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.setBundleGroup(this.bundleName, this.newGroup).then(() => {
        console.log('BUNDLE_ACTIVE SetBundleGroup promise succeeded.');
    }).catch( err => {
        console.log('BUNDLE_ACTIVE SetBundleGroup promise failed. because: ' + err.code);
    });
    // Asynchronous callback mode
    stats.setBundleGroup(this.bundleName, this.newGroup, (err) => {
        if (err) {
            console.log('BUNDLE_ACTIVE SetBundleGroup callback failed. because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE SetBundleGroup callback succeeded.');
        }
    });
    ```

12. Register a callback for application group changes. When an application group of the user changes, the change is returned to all applications that have registered the callback.

    ```javascript
    import stats from '@ohos.bundleState'

    // Promise mode
    let onBundleGroupChanged = (err,res) => {
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result oldGroup is : ' + res.oldGroup);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result newGroup is : ' + res.newGroup);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result changeReason is : ' + res.newGroup);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result userId is : ' + res.userId);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result bundleName is : ' + res.bundleName);
    };
    stats.registerGroupCallBack(onBundleGroupChanged).then(() => {
        console.log('BUNDLE_ACTIVE RegisterGroupCallBack promise succeeded.');
    }).catch(err => {
        console.log('BUNDLE_ACTIVE RegisterGroupCallBack promise failed. because: ' + err.code);
    });
    // Asynchronous callback mode
    let onBundleGroupChanged = (err,res) => {
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result's oldGroup is : ' + res.oldGroup);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result's newGroup is : ' + res.newGroup);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result's changeReason is : ' + res.newGroup);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result's userId is : ' + res.userId);
        console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack result's bundleName is : ' + res.bundleName);
    };
    stats.registerGroupCallBack(onBundleGroupChanged, (err) => {
        if (err) {
            console.log('BUNDLE_ACTIVE RegisterGroupCallBack callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE RegisterGroupCallBack callback success.');
        }
    });
    ```

13. Deregister the callback for application group changes.

    ```javascript
    import stats from '@ohos.bundleState'

    // Promise mode
    stats.unRegisterGroupCallBack().then(() => {
        console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack promise succeeded.');
    }).catch(err => {
        console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack promise failed. because: ' + err.code);
    });
    // Asynchronous callback mode
    stats.unRegisterGroupCallBack((err) => {
        if (err) {
            console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack callback success.');
        }
    });
    ```

