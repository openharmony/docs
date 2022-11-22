# Device Usage Statistics

This module provides APIs for collecting statistics on device usage.

System applications can call these APIs to implement the following features:

- Query the usage duration in different time segments, events (foreground, background, start and end of continuous tasks), and the number of notifications, on a per application basis.
- Query statistics about system events (sleep, wakeup, unlock, and screen lock).
- Query the bundle group information of applications, including the invoking application itself.
- Query the idle status of applications, including the invoking application itself.
- Set the bundle group for other applications.
- Register and deregister the callback for application group changes.

Third-party applications can call these APIs to implement the following features:

- Query the idle status of the invoking application itself.
- Query the bundle group information of the invoking application itself.
- Query the events of the invoking application itself.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import bundleState from '@ohos.bundleState'
```

## bundleState.isIdleState

isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the application specified by **bundleName** is in the idle state. This API uses an asynchronous callback to return the result. A third-party application can only check the idle status of itself.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                          | Mandatory  | Description                                      |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | Yes   | Bundle name of an application.                          |
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. Returns the idle state of the application if the specified **bundleName** is valid; returns **null** otherwise.|

**Example**

  ```
    bundleState.isIdleState("com.ohos.camera", (err, res) => {
        if (err) {
            console.log('BUNDLE_ACTIVE isIdleState callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        }
    });
  ```

## bundleState.isIdleState

isIdleState(bundleName: string): Promise&lt;boolean&gt;

Checks whether the application specified by **bundleName** is in the idle state. This API uses a promise to return the result. A third-party application can only check the idle status of itself.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type    | Mandatory  | Description            |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes   | Bundle name of an application.|

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns the idle state of the application if the specified **bundleName** is valid; returns **null** otherwise.|

**Example**

  ```js
    bundleState.isIdleState("com.ohos.camera").then( res => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);
    });
  ```

## bundleState.queryAppUsagePriorityGroup

queryAppUsagePriorityGroup(): Promise&lt;number&gt;

Queries the priority group of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```javascript
bundleState.queryAppUsagePriorityGroup().then( res => {
    console.log('BUNDLE_ACTIVE QueryPackageGroup promise succeeded. result: ' + JSON.stringify(res));
}).catch( err => {
    console.log('BUNDLE_ACTIVE QueryPackageGroup promise failed. because: ' + err.code);
});
```

## bundleState.queryAppUsagePriorityGroup

queryAppUsagePriorityGroup(callback: AsyncCallback&lt;number&gt;): void

Queries the priority group of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name     | Type                   | Mandatory  | Description                        |
| -------- | --------------------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.|

**Example**

```javascript
bundleState.queryAppUsagePriorityGroup((err, res) => {
    if(err) {
        console.log('BUNDLE_ACTIVE QueryPackageGroup callback failed. because: ' + err.code);
    } else {
        console.log('BUNDLE_ACTIVE QueryPackageGroup callback succeeded. result: ' + JSON.stringify(res));
    }
});
```

## bundleState.queryBundleStateInfos

queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleActiveInfoResponse&gt;): void

Queries the application usage duration statistics based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                  |
| end      | number                                   | Yes   | End time.                                  |
| callback | AsyncCallback&lt;[BundleActiveInfoResponse](#bundleactiveinforesponse)&gt; | Yes   | Callback used to return the result.|

**Example**

  ```js
    bundleState.queryBundleStateInfos(0, 20000000000000, (err, res) => {
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

## bundleState.queryBundleStateInfos

queryBundleStateInfos(begin: number, end: number): Promise&lt;BundleActiveInfoResponse&gt;

Queries the application usage duration statistics based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[BundleActiveInfoResponse](#bundleactiveinforesponse)&gt; | Promise used to return the result.|

**Example**

  ```js
    bundleState.queryBundleStateInfos(0, 20000000000000).then( res => {
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
  ```

## bundleState.queryBundleStateInfoByInterval

queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStateInfo&gt;&gt;): void

Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| byInterval | [IntervalType](#intervaltype)            | Yes   | Type of information to be queried.                                   |
| begin      | number                                   | Yes   | Start time.                                   |
| end        | number                                   | Yes   | End time.                                   |
| callback   | AsyncCallback&lt;Array&lt;[BundleStateInfo](#bundlestateinfo)&gt;&gt; | Yes   | Callback used to return the result.|

**Example**

  ```js
    bundleState.queryBundleStateInfoByInterval(0, 0, 20000000000000, (err, res) => {
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

## bundleState.queryBundleStateInfoByInterval

queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise&lt;Array&lt;BundleStateInfo&gt;&gt;

Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type                           | Mandatory  | Description   |
| ---------- | ----------------------------- | ---- | ----- |
| byInterval | [IntervalType](#intervaltype) | Yes   | Type of information to be queried.|
| begin      | number                        | Yes   | Start time.|
| end        | number                        | Yes   | End time.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStateInfo](#bundlestateinfo)&gt;&gt; | Promise used to return the result. |

**Example**

  ```js
    bundleState.queryBundleStateInfoByInterval(0, 0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise failed, because: ' + err.code);
    });
  ```

## bundleState.queryBundleActiveStates

queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;): void

Queries events of all applications based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                  |
| end      | number                                   | Yes   | End time.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Yes   | Callback used to return the result. |

**Example**

  ```js
    bundleState.queryBundleActiveStates(0, 20000000000000, (err, res) => {
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

## bundleState.queryBundleActiveStates

queryBundleActiveStates(begin: number, end: number): Promise&lt;Array&lt;BundleActiveState&gt;&gt;

Queries events of all applications based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Promise used to return the result. |

**Example**

  ```js
    bundleState.queryBundleActiveStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise failed, because: ' + err.code);
    });
  ```

## bundleState.queryCurrentBundleActiveStates

queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;): void

Queries events of this application based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                  |
| end      | number                                   | Yes   | End time.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Yes   | Callback used to return the result. |

**Example**

  ```js
    bundleState.queryCurrentBundleActiveStates(0, 20000000000000, (err, res) => {
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

## bundleState.queryCurrentBundleActiveStates

queryCurrentBundleActiveStates(begin: number, end: number): Promise&lt;Array&lt;BundleActiveState&gt;&gt;

Queries events of this application based on the specified start time and end time. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Promise used to return the result. |

**Example**

  ```js
    bundleState.queryCurrentBundleActiveStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise failed, because: ' + err.code);
    });
  ```

## bundleState.getRecentlyUsedModules<sup>9+</sup>

getRecentlyUsedModules(maxNum?: number): Promise&lt;Array&lt;BundleActiveModuleInfo&gt;&gt;

Obtains the number of FA usage records specified by **maxNum**. This API uses a promise to return the records sorted by time (most recent first).

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name   | Type    | Mandatory  | Description                                |
| ------ | ------ | ---- | ---------------------------------- |
| maxNum | number | No   | Maximum number of returned records. The maximum and default value is **1000**. If this parameter is not specified, **1000** is used.|

**Return value**

| Type                                      | Description                                |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[BundleActiveModuleInfo](#bundleactivemoduleinfo9)&gt;&gt; | Promise used to return the result. |

**Example**

  ```js
    bundleState.getRecentlyUsedModules(1000).then( res => {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise succeeded');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err=> {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise failed, because: ' + err.code);
    });

    // Invocation when maxNum is not passed
    bundleState.getRecentlyUsedModules().then( res => {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise succeeded');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err=> {
        console.log('BUNDLE_ACTIVE getRecentlyUsedModules promise failed, because: ' + err.code);
    });
  ```

## bundleState.getRecentlyUsedModules<sup>9+</sup>

getRecentlyUsedModules(callback: AsyncCallback&lt;Array&lt;BundleActiveModuleInfo&gt;&gt;): void

Obtains FA usage records. This API uses an asynchronous callback to return a maximum of 1000 FA usage records sorted by time in descending order.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveModuleInfo](#bundleactivemoduleinfo9)&gt;&gt; | Yes   | Callback used to return the result. |

**Example**

  ```js
    bundleState.getRecentlyUsedModules((err, res) => {
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
  ```

## bundleState.getRecentlyUsedModules<sup>9+</sup>

getRecentlyUsedModules(maxNum: number, callback: AsyncCallback&lt;Array&lt;BundleActiveModuleInfo&gt;&gt;): void

Obtains the number of FA usage records specified by **maxNum**. This API uses an asynchronous callback to return the records sorted by time (most recent first).

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| maxNum   | number                                   | Yes   | Maximum number of returned records. The maximum value is **1000**.|
| callback | AsyncCallback&lt;Array&lt;[BundleActiveModuleInfo](#bundleactivemoduleinfo9)&gt;&gt; | Yes   | Callback used to return the result. |

**Example**

  ```js
    bundleState.getRecentlyUsedModules(1000,(err, res) => {
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
  ```

## bundleState.queryAppUsagePriorityGroup<sup>9+</sup>

queryAppUsagePriorityGroup(bundleName? : string): Promise&lt;number&gt;

Queries the priority group of the application specified by **bundleName**. If **bundleName** is not specified, the priority group of the current application is queried. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type    | Mandatory  | Description                                      |
| ---------- | ------ | ---- | ---------------------------------------- |
| bundleName | string | No   | Bundle name of the target application. If this parameter is not specified, the priority group of the current application is queried.|

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Example**

```javascript
// Promise mode when bundleName is specified
let bundleName = "com.ohos.camera";
bundleState.queryAppUsagePriorityGroup(bundleName).then( res => {
    console.log('BUNDLE_ACTIVE QueryPackageGroup promise succeeded. result: ' + JSON.stringify(res));
}).catch( err => {
    console.log('BUNDLE_ACTIVE QueryPackageGroup promise failed. because: ' + err.code);
});
// Promise mode when bundleName is not specified
bundleState.queryAppUsagePriorityGroup().then( res => {
    console.log('BUNDLE_ACTIVE QueryPackageGroup promise succeeded. result: ' + JSON.stringify(res));
}).catch( err => {
    console.log('BUNDLE_ACTIVE QueryPackageGroup promise failed. because: ' + err.code);
});
```

## bundleState.queryAppUsagePriorityGroup<sup>9+</sup>

queryAppUsagePriorityGroup(callback: AsyncCallback&lt;number&gt;): void

Queries the priority group of this application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type                   | Mandatory  | Description                                      |
| ---------- | --------------------- | ---- | ---------------------------------------- |
| callback   | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result.               |

**Example**

```javascript
bundleState.queryAppUsagePriorityGroup((err, res) => {
    if(err) {
        console.log('BUNDLE_ACTIVE QueryPackageGroup callback failed. because: ' + err.code);
    } else {
        console.log('BUNDLE_ACTIVE QueryPackageGroup callback succeeded. result: ' + JSON.stringify(res));
    }
});
```

## bundleState.queryAppUsagePriorityGroup<sup>9+</sup>

queryAppUsagePriorityGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void

Queries the priority group of the application specified by **bundleName**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type                   | Mandatory  | Description                                      |
| ---------- | --------------------- | ---- | ---------------------------------------- |
| bundleName | string                | Yes   | Bundle name of the target application.|
| callback   | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result. |

**Example**

```javascript
let bundleName = "com.ohos.camera";
bundleState.queryAppUsagePriorityGroup(bundleName, (err, res) => {
    if(err) {
        console.log('BUNDLE_ACTIVE QueryPackageGroup callback failed. because: ' + err.code);
    } else {
        console.log('BUNDLE_ACTIVE QueryPackageGroup callback succeeded. result: ' + JSON.stringify(res));
    }
});
```

## bundleState.setBundleGroup<sup>9+</sup>

setBundleGroup(bundleName: string, newGroup: GroupType): Promise&lt;void&gt;

Sets the group for the application specified by **bundleName**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type       | Mandatory  | Description  |
| ---------- | --------- | ---- | ---- |
| bundleName | string    | Yes   | Bundle name of an application.|
| newGroup   | [GroupType](#grouptype) | Yes   | Application group.|

**Return value**

| Type           | Description                       |
| ------------- | ------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```javascript
let bundleName = "com.example.deviceUsageStatistics";
let newGroup = bundleState.GroupType.ACTIVE_GROUP_DAILY;

bundleState.setBundleGroup(bundleName, newGroup).then( () => {
    console.log('BUNDLE_ACTIVE SetBundleGroup promise succeeded.');
}).catch( err => {
    console.log('BUNDLE_ACTIVE SetBundleGroup promise failed. because: ' + err.code);
});
```

## bundleState.setBundleGroup<sup>9+</sup>

setBundleGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback&lt;void&gt;): void

Sets the group for the application specified by **bundleName**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type                 | Mandatory  | Description                       |
| ---------- | ------------------- | ---- | ------------------------- |
| bundleName | string              | Yes   | Bundle name of an application.                     |
| newGroup   | [GroupType](#grouptype)           | Yes   | Application group.                     |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. |

**Example**

```javascript
let bundleName = "com.example.deviceUsageStatistics";
let newGroup = bundleState.GroupType.ACTIVE_GROUP_DAILY;

bundleState.setBundleGroup(bundleName, newGroup, (err) => {
    if(err) {
        console.log('BUNDLE_ACTIVE SetBundleGroup callback failed. because: ' + err.code);
    } else {
        console.log('BUNDLE_ACTIVE SetBundleGroup callback succeeded.');
    }
});
```

## bundleState.registerGroupCallBack<sup>9+</sup>

registerGroupCallBack(groupCallback: Callback&lt;BundleActiveGroupCallbackInfo&gt;): Promise&lt;void&gt;

Registers a callback for application group changes. When an application group of the user changes, a **[BundleActiveGroupCallbackInfo](#bundleactivegroupcallbackinfo9)** instance is returned to all applications that have registered the callback. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | Callback&lt;[BundleActiveGroupCallbackInfo](#bundleactivegroupcallbackinfo9)&gt; | Yes  | Callback used to return the application group changes.|

**Return value**

| Type           | Description                     |
| ------------- | ----------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```javascript
let onBundleGroupChanged = (err,res) =>{
    console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result appUsageOldGroup is : ' + res.appUsageOldGroup);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result appUsageNewGroup is : ' + res.appUsageNewGroup);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result changeReason is : ' + res.changeReason);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result userId is : ' + res.userId);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result bundleName is : ' + res.bundleName);
};
bundleState.registerGroupCallBack(onBundleGroupChanged).then( () => {
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack promise succeeded.');
}).catch( err => {
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack promise failed. because: ' + err.code);
});
```

## bundleState.registerGroupCallBack<sup>9+</sup>

registerGroupCallBack(groupCallback: Callback&lt;BundleActiveGroupCallbackInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

Registers a callback for application group changes. When an application group of the user changes, a **[BundleActiveGroupCallbackInfo](#bundleactivegroupcallbackinfo9)** instance is returned to all applications that have registered the callback. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | Callback&lt;[BundleActiveGroupCallbackInfo](#bundleactivegroupcallbackinfo9)&gt; | Yes  | Callback used to return the application group changes.  |
| callback | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result.|

**Example**

```javascript
let onBundleGroupChanged = (err,res) =>{
    console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result appUsageOldGroup is : ' + res.appUsageOldGroup);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result appUsageNewGroup is : ' + res.appUsageNewGroup);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result changeReason is : ' + res.changeReason);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result userId is : ' + res.userId);
    console.log('BUNDLE_ACTIVE RegisterGroupCallBack result bundleName is : ' + res.bundleName);
};
bundleState.registerGroupCallBack(onBundleGroupChanged, (err)=>{
    if(err) {
        console.log('BUNDLE_ACTIVE RegisterGroupCallBack callback failed, because: ' + err.code);
    } else {
        console.log('BUNDLE_ACTIVE RegisterGroupCallBack callback success.');
    }
});
```

## bundleState.unRegisterGroupCallBack<sup>9+</sup>

unRegisterGroupCallBack(): Promise&lt;void&gt;

Deregisters the callback for application group changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**: none

**Return value**

| Type           | Description                      |
| ------------- | ------------------------ |
| Promise&lt;void&gt; | Promise used to return the result. |

**Example**

```javascript
bundleState.unRegisterGroupCallBack().then( () => {
    console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack promise succeeded.');
}).catch( err => {
    console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack promise failed. because: ' + err.code);
});
```

## bundleState.unRegisterGroupCallBack<sup>9+</sup>

unRegisterGroupCallBack(callback: AsyncCallback&lt;void&gt;): void;

Deregisters the callback for application group changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                 | Mandatory  | Description            |
| -------- | ------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

```javascript
bundleState.unRegisterGroupCallBack((err)=>{
    if(err) {
        console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack callback failed, because: ' + err.code);
    } else {
        console.log('BUNDLE_ACTIVE UnRegisterGroupCallBack callback success.');
    }
});
```

## bundleState.queryBundleActiveEventStates<sup>9+</sup>

queryBundleActiveEventStates(begin: number, end: number): Promise&lt;Array&lt;BundleActiveEventState&gt;&gt;

Queries statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleActiveEventState](#bundleactiveeventstate9)&gt;&gt; | Promise used to return the result. |

**Example**

  ```js
    bundleState.queryBundleActiveEventStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleActiveEventStates promise success.');
        console.log('BUNDLE_ACTIVE queryBundleActiveEventStates promise result ' + JSON.stringify(res));
    }).catch( err=> {
        console.log('BUNDLE_ACTIVE queryBundleActiveEventStates promise failed, because: ' + err.code);
    });
  ```

## bundleState.queryBundleActiveEventStates<sup>9+</sup>

queryBundleActiveEventStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveEventState&gt;&gt;): void

Queries statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                   |
| end      | number                                   | Yes   | End time.                                   |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveEventState](#bundleactiveeventstate9)&gt;&gt; | Yes   | Callback used to return the result. |

**Example**

  ```js
    bundleState.queryBundleActiveEventStates(0, 20000000000000, (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryBundleActiveEventStates callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleActiveEventStates callback success.');
            console.log('BUNDLE_ACTIVE queryBundleActiveEventStates callback result ' + JSON.stringify(res));
        }
    });
  ```

## bundleState.queryAppNotificationNumber<sup>9+</sup>

queryAppNotificationNumber(begin: number, end: number): Promise&lt;Array&lt;BundleActiveEventState&gt;&gt;

Queries the number of notifications from all applications based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleActiveEventState](#bundleactiveeventstate9)&gt;&gt; | Promise used to return the result. |

**Example**

  ```js
    bundleState.queryAppNotificationNumber(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryAppNotificationNumber promise success.');
        console.log('BUNDLE_ACTIVE queryAppNotificationNumber promise result ' + JSON.stringify(res));
    }).catch( err=> {
        console.log('BUNDLE_ACTIVE queryAppNotificationNumber promise failed, because: ' + err.code);
    });
  ```

## bundleState.queryAppNotificationNumber<sup>9+</sup>

queryAppNotificationNumber(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveEventState&gt;&gt;): void

Queries the number of notifications from all applications based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                   |
| end      | number                                   | Yes   | End time.                                   |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveEventState](#bundleactiveeventstate9)&gt;&gt; | Yes   | Callback used to return the result. |

**Example**

  ```js
    bundleState.queryAppNotificationNumber(0, 20000000000000, (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryAppNotificationNumberCallBack callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryAppNotificationNumberCallBack callback success.');
            console.log('BUNDLE_ACTIVE queryAppNotificationNumberCallBack callback result ' + JSON.stringify(res));
        }
    });
  ```

## BundleActiveModuleInfo<sup>9+</sup>
Provides the information about the FA usage.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

| Name                 | Type                                      | Mandatory  | Description                           |
| -------------------- | ---------------------------------------- | ---- | ----------------------------- |
| deviceId             | string                                   | No   | ID of the device to which the FA belongs.                |
| bundleName           | string                                   | Yes   | Name of the application bundle to which the FA belongs.                    |
| moduleName           | string                                   | Yes   | Name of the module to which the FA belongs.                 |
| abilityName          | string                                   | No   | **MainAbility** name of the FA.             |
| appLabelId           | number                                   | No   | Application label ID of the FA.                |
| labelId              | number                                   | No   | Label ID of the module to which the FA belongs.          |
| descriptionId        | number                                   | No   | Description ID of the application to which the FA belongs.        |
| abilityLableId       | number                                   | No   | **MainAbility** label ID of the FA.      |
| abilityDescriptionId | number                                   | No   | **MainAbility** description ID of the FA.|
| abilityIconId        | number                                   | No   | **MainAbility** icon ID of the FA.       |
| launchedCount        | number                                   | Yes   | Number of FA startup times.                     |
| lastModuleUsedTime   | number                                   | Yes   | Last time when the FA was used.                  |
| formRecords          | Array&lt;[BundleActiveFormInfo](#bundleactiveforminfo9)&gt; | Yes   | Array of widget usage records in the FA.                  |

## BundleActiveFormInfo<sup>9+</sup>
Provides the FA widget usage information.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

| Name             | Type    | Mandatory  | Description         |
| ---------------- | ------ | ---- | ----------- |
| formName         | string | Yes   | Widget name.      |
| formDimension    | number | Yes   | Widget dimensions.      |
| formId           | number | Yes   | Widget ID.      |
| formLastUsedTime | number | Yes   | Last time when the widget was clicked.|
| count            | number | Yes   | Number of clicks on the widget.   |

## BundleActiveGroupCallbackInfo<sup>9+</sup>

Provides the application group changes returned through a callback.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Type  | Mandatory| Description            |
| ---------------- | ------ | ---- | ---------------- |
| appUsageOldGroup | number | Yes  | Application group before the change.|
| appUsageNewGroup | number | Yes  | Application group after the change.|
| userId           | number | Yes  | User ID.          |
| changeReason     | number | Yes  | Reason for the group change.    |
| bundleName       | string | Yes  | Bundle name of an application.        |

## BundleStateInfo

Provides the usage duration information of applications.

### Attributes

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                     | Type    | Mandatory  | Description                                      |
| ------------------------ | ------ | ---- | ---------------------------------------- |
| bundleName               | string | Yes   | Bundle name of an application.                                   |
| abilityPrevAccessTime    | number | Yes   | Last time when the application was used.                            |
| abilityInFgTotalTime     | number | Yes   | Total time that the application runs in the foreground.                            |
| id                       | number | No   | User ID.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| abilityPrevSeenTime      | number | No   | Last time when the application was visible in the foreground.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| abilitySeenTotalTime     | number | No   | Total time that the application is visible in the foreground.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| fgAbilityAccessTotalTime | number | No   | Total time that the application accesses the foreground.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| fgAbilityPrevAccessTime  | number | No   | Last time when the application accessed the foreground.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| infosBeginTime           | number | No   | Time logged in the first application usage record in the **BundleActiveInfo** object.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| infosEndTime             | number | No   | Time logged in the last application usage record in the **BundleActiveInfo** object.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|

## BundleActiveState

Provides information about an application event.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                  | Type    | Mandatory  | Description                                      |
| --------------------- | ------ | ---- | ---------------------------------------- |
| bundleName            | string | Yes   | Bundle name of an application.                                   |
| stateType             | number | Yes   | Application event type.                                 |
| stateOccurredTime     | number | Yes   | Timestamp when the application event occurs.                             |
| appUsagePriorityGroup | number | No   | Usage priority group of the application.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| indexOfLink           | string | No   | Shortcut ID.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|
| nameOfClass           | string | No   | Class name.<br>This API is defined but not implemented in OpenHarmony 3.1 Release. It will be available for use in OpenHarmony 3.1 MR.|

## BundleActiveInfoResponse

Provides the usage duration information of applications.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                           | Type                                      | Mandatory  | Description            |
| ------------------------------ | ---------------------------------------- | ---- | -------------- |
| [key: string]: BundleStateInfo | [key: string]: [BundleStateInfo](#bundlestateinfo) | Yes   | Usage duration information by application.|

## BundleActiveEventState<sup>9+</sup>

Provides statistics about notifications and system events.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API and cannot be called by third-party applications.

| Name    | Type    | Mandatory  | Description               |
| ------- | ------ | ---- | ----------------- |
| name    | string | Yes   | Bundle name of the notification sending application or system event name.   |
| eventId | number | Yes   | Type of the notification or system event.       |
| count   | number | Yes   | Number of application notifications or system event triggering times.|

## IntervalType

Enumerates the interval types for querying the application usage duration.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name          | Default Value | Description                                      |
| ------------ | ---- | ---------------------------------------- |
| BY_OPTIMIZED | 0    | The system obtains the application usage duration statistics in the specified time frame at the interval the system deems appropriate.|
| BY_DAILY     | 1    | The system obtains the application usage duration statistics in the specified time frame on a daily basis.             |
| BY_WEEKLY    | 2    | The system obtains the application usage duration statistics in the specified time frame on a weekly basis.             |
| BY_MONTHLY   | 3    | The system obtains the application usage duration statistics in the specified time frame on a monthly basis.             |
| BY_ANNUALLY  | 4    | The system obtains the application usage duration statistics in the specified time frame on an annual basis.             |

## GroupType<sup>9+</sup>

Enumerates the application group types.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Default Value | Description               |
| ------------------ | ---- | ----------------- |
| ACTIVE_GROUP_ALIVE | 10   | Group of active applications.             |
| ACTIVE_GROUP_DAILY | 20   | Group of frequently used applications that are not in the active state.   |
| ACTIVE_GROUP_FIXED | 30   | Group of applications that are used periodically but not every day.|
| ACTIVE_GROUP_RARE  | 40   | Group of rarely used applications.     |
| ACTIVE_GROUP_LIMIT | 50   | Group of restricted applications.           |
| ACTIVE_GROUP_NEVER | 60   | Group of applications that have been installed but never run. |
