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
| function queryAppUsagePriorityGroup(callback: AsyncCallback&lt;number&gt;): void | Queries the priority group of the current invoker application.|
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether the application specified by **bundleName** is in the idle state. |

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

    // Use a promise to return the result.
    stats.queryBundleActiveStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise failed, because: ' + err.code);
    });

    // Use an asynchronous callback to return the result.
    stats.queryBundleActiveStates(0, 20000000000000, (err, res) => {
        if(err.code == 0) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleActiveStates callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleActiveStates callback result ' + JSON.stringify(res[i]));
            }
        } else {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates callback failed, because: ' + err.code);
        }
    });
    ```

3. Query the application usage duration statistics based on the specified start time and end time. This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Use a promise to return the result.
    stats.queryBundleStateInfos(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfos promise success.');
        let i = 1;
        for(let key in res){
            console.log('BUNDLE_ACTIVE queryBundleStateInfos promise number : ' + i);
            console.log('BUNDLE_ACTIVE queryBundleStateInfos promise result ' + JSON.stringify(res[key]));
            i++;
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfos promise failed, because: ' + err.code);
    });

    // Use an asynchronous callback to return the result.
    stats.queryBundleStateInfos(0, 20000000000000, (err, res) => {
        if(err.code == 0) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfos callback success.');
            let i = 1;
            for(let key in res){
                console.log('BUNDLE_ACTIVE queryBundleStateInfos callback number : ' + i);
                console.log('BUNDLE_ACTIVE queryBundleStateInfos callback result ' + JSON.stringify(res[key]));
                i++;
            }
        } else {
            console.log('BUNDLE_ACTIVE queryBundleStateInfos callback failed, because: ' + err.code);
        }
    });
    ```

4. Query events of this application based on the specified start time and end time. This requires no permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Use a promise to return the result.
    stats.queryCurrentBundleActiveStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise failed, because: ' + err.code);
    });

    // Use an asynchronous callback to return the result.
    stats.queryCurrentBundleActiveStates(0, 20000000000000, (err, res) => {
        if(err.code == 0) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback result ' + JSON.stringify(res[i]));
             }
        } else {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback failed, because: ' + err.code);
        }
    });
    ```

5. Query the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This requires the **ohos.permission.BUNDLE_ACTIVE_INFO** permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Use a promise to return the result.
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise failed, because: ' + err.code);
    });

    // Use an asynchronous callback to return the result.
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000, (err, res) => {
        if(err.code == 0) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback result ' + JSON.stringify(res[i]));
            }
        } else {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback failed, because: ' + err.code);
        }
    });
    ```

6. Query the priority group of the current invoker application. This requires no permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Use a promise to return the result.
    stats.queryAppUsagePriorityGroup().then( res => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise failed. because: ' + err.code);
    });

    // Use an asynchronous callback to return the result.
    stats.queryAppUsagePriorityGroup((err, res) => {
        if(err.code === 0) {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback succeeded. result: ' + JSON.stringify(res));
        } else {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback failed. because: ' + err.code);
        }
    });
    ```

7. Check whether the application specified by **bundleName** is in the idle state. This requires no permission to be configured in the **config.json** file.

    ```js
    import stats from '@ohos.bundleState'

    // Use a promise to return the result.
    stats.isIdleState("com.ohos.camera").then( res => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);
    });

    // Use an asynchronous callback to return the result.
    stats.isIdleState("com.ohos.camera", (err, res) => {
        if(err.code === 0) {
            console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        } else {
            console.log('BUNDLE_ACTIVE isIdleState callback failed, because: ' + err.code);
        }
    });
    ```
