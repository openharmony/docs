# Device Usage Statistics

This module provides APIs for collecting statistics on device usage.

System applications can call these APIs to implement the following features:

- Query the usage duration in different time segments, events (foreground, background, start and end of continuous tasks), and the number of notifications, on a per application basis.
- Query the bundle group information of the invoking application itself.
- Query the idle status of applications, including the invoking application itself.

Third-party applications can call these APIs to implement the following features:

- Query the idle status of the invoking application itself.
- Query the bundle group information of the invoking application itself.
- Query the events of the invoking application itself.

> **NOTE**
>
> This module is deprecated since API version 9. You are advised to use [@ohos.resourceschedule.usageStatistics](js-apis-resourceschedule-deviceUsageStatistics.md) instead.
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>


## Modules to Import

```js
import bundleState from '@ohos.bundleState'
```

## bundleState.isIdleState

isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the application specified by **bundleName** is in the idle state. This API uses an asynchronous callback to return the result. By default, a third-party application can only check the idle state of itself. To query the idle state of other applications, it must request the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                          | Mandatory  | Description                                      |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | Yes   | Bundle name of an application.                          |
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. If the specified **bundleName** is valid, the idle state of the application is returned; otherwise, **null** is returned.|

**Example**

  ```js
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

Checks whether the application specified by **bundleName** is in the idle state. This API uses a promise to return the result. By default, a third-party application can only check the idle state of itself. To query the idle state of other applications, it must request the **ohos.permission.BUNDLE_ACTIVE_INFO** permission.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type    | Mandatory  | Description            |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes   | Bundle name of an application.|

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the specified **bundleName** is valid, the idle state of the application is returned; otherwise, **null** is returned.|

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
| Promise&lt;number&gt; | Promise used to return the priority group.|

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
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the priority group.|

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
| begin    | number                                   | Yes   | Start time, in milliseconds.                                  |
| end      | number                                   | Yes   | End time, in milliseconds.                                  |
| callback | AsyncCallback&lt;[BundleActiveInfoResponse](#bundleactiveinforesponse)&gt; | Yes   | Callback used to return the application usage duration statistics.|

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
| begin | number | Yes   | Start time, in milliseconds.|
| end   | number | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[BundleActiveInfoResponse](#bundleactiveinforesponse)&gt; | Promise used to return the application usage duration statistics.|

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
| begin      | number                                   | Yes   | Start time, in milliseconds.                                   |
| end        | number                                   | Yes   | End time, in milliseconds.                                   |
| callback   | AsyncCallback&lt;Array&lt;[BundleStateInfo](#bundlestateinfo)&gt;&gt; | Yes   | Callback used to return the application usage duration statistics.|

**Example**

  ```js
    bundleState.queryBundleStateInfoByInterval(bundleState.IntervalType.BY_OPTIMIZED, 0, 20000000000000, (err, res) => {
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
| begin      | number                        | Yes   | Start time, in milliseconds.|
| end        | number                        | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStateInfo](#bundlestateinfo)&gt;&gt; | Promise used to return the application usage duration statistics.|

**Example**

  ```js
    bundleState.queryBundleStateInfoByInterval(bundleState.IntervalType.BY_OPTIMIZED, 0, 20000000000000).then( res => {
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
| begin    | number                                   | Yes   | Start time, in milliseconds.                                  |
| end      | number                                   | Yes   | End time, in milliseconds.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Yes   | Callback used to return the events obtained.|

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
| begin | number | Yes   | Start time, in milliseconds.|
| end   | number | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Promise used to return the events obtained.|

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
| begin    | number                                   | Yes   | Start time, in milliseconds.                                  |
| end      | number                                   | Yes   | End time, in milliseconds.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Yes   | Callback used to return the events obtained.|

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
| begin | number | Yes   | Start time, in milliseconds.|
| end   | number | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleActiveState](#bundleactivestate)&gt;&gt; | Promise used to return the events obtained.|

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

## BundleStateInfo

Provides the usage duration information of an application.

### Attributes

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                     | Type    | Mandatory  | Description                                      |
| ------------------------ | ------ | ---- | ---------------------------------------- |
| bundleName               | string | Yes   | Bundle name of an application.                                   |
| abilityPrevAccessTime    | number | Yes   | Last time when the application was used.                            |
| abilityInFgTotalTime     | number | Yes   | Total time that the application runs in the foreground.                            |
| id                       | number | No   | User ID.|
| abilityPrevSeenTime      | number | No   | Last time when the application was visible in the foreground.|
| abilitySeenTotalTime     | number | No   | Total time that the application is visible in the foreground.|
| fgAbilityAccessTotalTime | number | No   | Total time that the application accesses the foreground.|
| fgAbilityPrevAccessTime  | number | No   | Last time when the application accessed the foreground.|
| infosBeginTime           | number | No   | Time logged in the first application usage record in the **BundleActiveInfo** object.|
| infosEndTime             | number | No   | Time logged in the last application usage record in the **BundleActiveInfo** object.|

## BundleActiveState

Provides information about an application event.

Provides the usage duration information of applications.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                  | Type    | Mandatory  | Description                                      |
| --------------------- | ------ | ---- | ---------------------------------------- |
| bundleName            | string | Yes   | Bundle name of an application.                                   |
| stateType             | number | Yes   | Application event type.                                 |
| stateOccurredTime     | number | Yes   | Timestamp when the application event occurs.                             |
| appUsagePriorityGroup | number | No   | Usage priority group of the application.|
| indexOfLink           | string | No   | Shortcut ID.|
| nameOfClass           | string | No   | Class name.|

## BundleActiveInfoResponse

Provides the usage duration information of applications.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                           | Type                                      | Mandatory  | Description            |
| ------------------------------ | ---------------------------------------- | ---- | -------------- |
| [key: string]: BundleStateInfo | [key: string]: [BundleStateInfo](#bundlestateinfo) | Yes   | Usage duration information by application.|

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
