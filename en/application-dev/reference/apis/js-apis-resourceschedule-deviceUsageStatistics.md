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
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>


## Modules to Import

```
import usageStatistics from '@ohos.resourceschedule.usageStatistics'
```

## usageStatistics.isIdleState

isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the application specified by **bundleName** is in the idle state. This API uses an asynchronous callback to return the result. A third-party application can only check the idle status of itself.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                          | Mandatory  | Description                                      |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | Yes   | Bundle name of the application.                          |
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. If the specified **bundleName** is valid, the idle state of the application is returned; otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                    |
| ---------- | ----------------------------     |
| 10000001   | Memory operation failed.         | 
| 10000002   | Parcel operation failed.         | 
| 10000003   | System service operation failed. | 
| 10000004   | IPC Communication failed.        | 
| 10000006   | Get application info failed.     |

**Example**
  ```js
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

## usageStatistics.isIdleState

isIdleState(bundleName: string): Promise&lt;boolean&gt;

Checks whether the application specified by **bundleName** is in the idle state. This API uses a promise to return the result. A third-party application can only check the idle status of itself.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type    | Mandatory  | Description            |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the specified **bundleName** is valid, the idle state of the application is returned; otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                    |
| ---------- | ----------------------------     |
| 10000001   | Memory operation failed.         | 
| 10000002   | Parcel operation failed.         | 
| 10000003   | System service operation failed. | 
| 10000004   | IPC Communication failed.        | 
| 10000006   | Get application info failed.     |

**Example**

  ```js
    try{
        usageStatistics.isIdleState("com.ohos.camera").then( res => {
            console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
        }).catch( err => {
            console.log('BUNDLE_ACTIVE isIdleState promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE isIdleState throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
  ```

## usageStatistics.queryAppGroup

queryAppGroup(): Promise&lt;number&gt;

Queries the group of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the group.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**Example**

```javascript
    try{
        usageStatistics.queryAppGroup().then( res => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
```

## usageStatistics.queryAppGroup

queryAppGroup(callback: AsyncCallback&lt;number&gt;): void

Queries the group of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name     | Type                   | Mandatory  | Description                        |
| -------- | --------------------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the group.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**Example**

```javascript
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

## usageStatistics.queryBundleStatsInfos

queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleStatsMap&gt;): void

Queries the application usage duration statistics based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                  |
| end      | number                                   | Yes   | End time.                                  |
| callback | AsyncCallback&lt;[BundleStatsMap](#bundlestatsmap)&gt; | Yes   | Callback used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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

## usageStatistics.queryBundleStatsInfos

queryBundleStatsInfos(begin: number, end: number): Promise&lt;BundleStatsMap&gt;

Queries the application usage duration statistics based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[BundleStatsMap](#bundlestatsmap)&gt; | Promise used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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
  ```

## usageStatistics.queryBundleStatsInfoByInterval

queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStatsInfo&gt;&gt;): void

Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| byInterval | [IntervalType](#intervaltype)            | Yes   | Type of information to be queried.                                   |
| begin      | number                                   | Yes   | Start time.                                   |
| end        | number                                   | Yes   | End time.                                   |
| callback   | AsyncCallback&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | Yes   | Callback used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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

## usageStatistics.queryBundleStatsInfoByInterval

queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise&lt;Array&lt;BundleStatsInfo&gt;&gt;

Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name       | Type                           | Mandatory  | Description   |
| ---------- | ----------------------------- | ---- | ----- |
| byInterval | [IntervalType](#intervaltype) | Yes   | Type of information to be queried.|
| begin      | number                        | Yes   | Start time.|
| end        | number                        | Yes   | End time.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | Promise used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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
  ```

## usageStatistics.queryBundleEvents

queryBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void

Queries events of all applications based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                  |
| end      | number                                   | Yes   | End time.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Yes   | Callback used to return the events obtained.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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

## usageStatistics.queryBundleEvents

queryBundleEvents(begin: number, end: number): Promise&lt;Array&lt;BundleEvents&gt;&gt;

Queries events of all applications based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Promise used to return the events obtained.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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
  ```

## usageStatistics.queryCurrentBundleEvents

queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void

Queries events of this application based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                  |
| end      | number                                   | Yes   | End time.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Yes   | Callback used to return the events obtained.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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

## usageStatistics.queryCurrentBundleEvents

queryCurrentBundleEvents(begin: number, end: number): Promise&lt;Array&lt;BundleEvents&gt;&gt;

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
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Promise used to return the events obtained.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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
  ```

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(): Promise&lt;Array&lt;HapModuleInfo&gt;&gt;

Queries FA usage records. This API uses a promise to return a maximum of 1000 FA usage records sorted by time (most recent first).

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Return value**

| Type                                      | Description                                |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Promise used to return a maximum of 1000 FA usage records.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
    // Invocation when maxNum is not passed
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
  ```

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(callback: AsyncCallback&lt;Array&lt;HapModuleInfo&gt;&gt;): void

Queries FA usage records. This API uses an asynchronous callback to return a maximum of 1000 FA usage records sorted by time (most recent first).

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Yes   | Callback used to return a maximum of 1000 FA usage records.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(maxNum: number): Promise&lt;Array&lt;HapModuleInfo&gt;&gt;

Queries the number of FA usage records specified by **maxNum**. This API uses a promise to return the records sorted by time (most recent first).

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name   | Type    | Mandatory  | Description                                |
| ------ | ------ | ---- | ---------------------------------- |
| maxNum | number | Yes   | Maximum number of returned records. The maximum and default value is **1000**.|

**Return value**

| Type                                      | Description                                |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Promise used to return a maximum of **maxNum** FA usage records.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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
  ```

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(maxNum: number, callback: AsyncCallback&lt;Array&lt;HapModuleInfo&gt;&gt;): void

Queries the number of FA usage records. This API uses an asynchronous callback to return the records sorted by time (most recent first).

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| maxNum   | number                                   | Yes   | Maximum number of returned records. The maximum value is **1000**.|
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Yes   | Callback used to return a maximum of **maxNum** FA usage records.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**Example**

  ```js
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
  ```

## usageStatistics.queryAppGroup

queryAppGroup(bundleName : string): Promise&lt;number&gt;

Queries the group of the application specified by **bundleName**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**

| Name       | Type    | Mandatory  | Description                                      |
| ---------- | ------ | ---- | ---------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the group.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**Example**

```javascript
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
```

## usageStatistics.queryAppGroup

queryAppGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void

Queries the group of the application specified by **bundleName**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**

| Name       | Type                   | Mandatory  | Description                                      |
| ---------- | --------------------- | ---- | ---------------------------------------- |
| bundleName | string                | Yes   | Bundle name of the application.|
| callback   | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the group.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**Example**

```javascript
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

## usageStatistics.setAppGroup

setAppGroup(bundleName: string, newGroup: GroupType): Promise&lt;void&gt;

Sets a group for the application specified by **bundleName**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**

| Name       | Type       | Mandatory  | Description  |
| ---------- | --------- | ---- | ---- |
| bundleName | string    | Yes   | Bundle name of the application.|
| newGroup   | [GroupType](#grouptype) | Yes   | Group to set.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed.          |
| 10100001   | Application group operation repeated. |

**Return value**

| Type           | Description                       |
| ------------- | ------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Example**

```javascript
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;

    try{
        usageStatistics.setAppGroup(bundleName, newGroup).then( () => {
            console.log('BUNDLE_ACTIVE setAppGroup promise succeeded.');
        }).catch( err => {
            console.log('BUNDLE_ACTIVE setAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE setAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
```

## usageStatistics.setAppGroup

setAppGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback&lt;void&gt;): void

Sets a group for the application specified by **bundleName**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**

| Name       | Type                 | Mandatory  | Description                       |
| ---------- | ------------------- | ---- | ------------------------- |
| bundleName | string              | Yes   | Bundle name of the application.                     |
| newGroup   | [GroupType](#grouptype)           | Yes   | Group to set.                     |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed.          |
| 10100001   | Application group operation repeated. |

**Example**

```javascript
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;

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

## usageStatistics.registerAppGroupCallBack

registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;): Promise&lt;void&gt;

Registers a callback for application group changes. When an application group of the user changes, an [AppGroupCallbackInfo](#appgroupcallbackinfo) instance is returned to all applications that have registered the callback. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | Yes  | Callback used to return the application group changes.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |

**Return value**

| Type           | Description                     |
| ------------- | ----------------------- |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Example**

```javascript
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
```

## usageStatistics.registerAppGroupCallBack

registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

Registers a callback for application group changes. When an application group of the user changes, an [AppGroupCallbackInfo](#appgroupcallbackinfo) instance is returned to all applications that have registered the callback. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| groupCallback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | Yes  | Callback used to return the application group changes.  |
| callback | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |


**Example**

```javascript
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

## usageStatistics.unregisterAppGroupCallBack

unregisterAppGroupCallBack(): Promise&lt;void&gt;

Deregisters the callback for application group changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**: none

**Return value**

| Type           | Description                      |
| ------------- | ------------------------ |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |

**Example**

```javascript
    try{
        usageStatistics.unregisterAppGroupCallBack().then( () => {
            console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise succeeded.');
        }).catch( err => {
            console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack throw error, code is: ' + error.code + ',message is: ' + error.message);
    }
```

## usageStatistics.unregisterAppGroupCallBack

unregisterAppGroupCallBack(callback: AsyncCallback&lt;void&gt;): void;

Deregisters the callback for application group changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

**Parameters**

| Name     | Type                 | Mandatory  | Description            |
| -------- | ------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |

**Example**

```javascript
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

## usageStatistics.queryDeviceEventStats

queryDeviceEventStats(begin: number, end: number): Promise&lt;Array&lt;DeviceEventStats&gt;&gt;

Queries statistics about system events (hibernation, wakeup, unlocking, and screen locking) that occur between the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Promise used to return the result.  |

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed           |
| 10000007   | Get system or actual time failed.     |

**Example**

  ```js
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
  ```

## usageStatistics.queryDeviceEventStats

queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void

 

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                   |
| end      | number                                   | Yes   | End time.                                   |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Yes   | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed           |
| 10000007   | Get system or actual time failed.     |

**Example**

  ```js
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

## usageStatistics.queryNotificationEventStats

queryNotificationEventStats(begin: number, end: number): Promise&lt;Array&lt;DeviceEventStats&gt;&gt;

Queries the number of notifications from all applications based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time.|
| end   | number | Yes   | End time.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Promise used to return the result.  |

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed           |
| 10000007   | Get system or actual time failed.     |

**Example**

  ```js
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
  ```

## usageStatistics.queryNotificationEventStats

queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void

Queries the number of notifications from all applications based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | Yes   | Start time.                                   |
| end      | number                                   | Yes   | End time.                                   |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Yes   | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](../errorcodes/errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                         |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed           |
| 10000007   | Get system or actual time failed.     |

**Example**

  ```js
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

## HapModuleInfo
Provides the information about the FA usage.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

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
| formRecords          | Array&lt;[HapFormInfo](#hapforminfo)&gt; | Yes   | Array of widget usage records in the FA.                  |

## HapFormInfo
Provides the FA widget usage information.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

| Name             | Type    | Mandatory  | Description         |
| ---------------- | ------ | ---- | ----------- |
| formName         | string | Yes   | Widget name.      |
| formDimension    | number | Yes   | Widget dimensions.      |
| formId           | number | Yes   | Widget ID.      |
| formLastUsedTime | number | Yes   | Last time when the widget was clicked.|
| count            | number | Yes   | Number of clicks on the widget.   |

## AppGroupCallbackInfo

Provides the application group changes returned through a callback.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

| Name          | Type  | Mandatory| Description            |
| ---------------- | ------ | ---- | ---------------- |
| appOldGroup | number | Yes  | Application group before the change.|
| appNewGroup | number | Yes  | Application group after the change.|
| userId           | number | Yes  | User ID.          |
| changeReason     | number | Yes  | Reason for the group change.    |
| bundleName       | string | Yes  | Bundle name of the application.        |

## BundleStatsInfo

Provides the usage duration information of an application.

### Attributes

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

| Name                     | Type    | Mandatory  | Description                                      |
| ------------------------ | ------ | ---- | ---------------------------------------- |
| bundleName               | string | Yes   | Bundle name of the application.                                   |
| abilityPrevAccessTime    | number | Yes   | Last time when the application was used.                            |
| abilityInFgTotalTime     | number | Yes   | Total time that the application runs in the foreground.                            |
| id                       | number | No   | User ID.|
| abilityPrevSeenTime      | number | No   | Last time when the application was visible in the foreground.|
| abilitySeenTotalTime     | number | No   | Total time that the application is visible in the foreground.|
| fgAbilityAccessTotalTime | number | No   | Total time that the application accesses the foreground.|
| fgAbilityPrevAccessTime  | number | No   | Last time when the application accessed the foreground.|
| infosBeginTime           | number | No   | Time logged in the first application usage record in the **BundleActiveInfo** object.|
| infosEndTime             | number | No   | Time logged in the last application usage record in the **BundleActiveInfo** object.|

## BundleEvents

Provides information about an application event.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                  | Type    | Mandatory  | Description                                      |
| --------------------- | ------ | ---- | ---------------------------------------- |
| bundleName            | string | Yes   | Bundle name of the application.                                   |
| eventId             | number | Yes   | Application event type.                                 |
| eventOccurredTime     | number | Yes   | Timestamp when the application event occurs.                             |
| appGroup | number | No   | Usage priority group of the application.|
| indexOfLink           | string | No   | Shortcut ID.|
| nameOfClass           | string | No   | Class name.|

## BundleStatsMap

Provides the usage duration information of an application.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                           | Type                                      | Mandatory  | Description            |
| ------------------------------ | ---------------------------------------- | ---- | -------------- |
| [key: string]: BundleStatsInfo | [key: string]: [BundleStatsInfo](#bundlestatsinfo) | Yes   | Usage duration information by application.|

## DeviceEventStats

Provides statistics about notifications and system events.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**System API**: This is a system API.

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
| BY_OPTIMIZED | 0    | The system queries the application usage duration statistics in the specified time frame at the interval the system deems appropriate.|
| BY_DAILY     | 1    | The system queries the application usage duration statistics in the specified time frame on a daily basis.             |
| BY_WEEKLY    | 2    | The system queries the application usage duration statistics in the specified time frame on a weekly basis.             |
| BY_MONTHLY   | 3    | The system queries the application usage duration statistics in the specified time frame on a monthly basis.             |
| BY_ANNUALLY  | 4    | The system queries the application usage duration statistics in the specified time frame on an annual basis.             |

## GroupType

Enumerates the application group types.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**System API**: This is a system API.

| Name                | Default Value | Description               |
| ------------------ | ---- | ----------------- |
| ALIVE_GROUP | 10   | Group of active applications.             |
| DAILY_GROUP | 20   | Group of frequently used applications that are not in the active state.   |
| FIXED_GROUP | 30   | Group of applications that are used periodically but not every day.|
| RARE_GROUP  | 40   | Group of rarely used applications.     |
| LIMITED_GROUP | 50   | Group of restricted applications.           |
| NEVER_GROUP | 60   | Group of applications that have been installed but never run. |
