# @ohos.resourceschedule.usageStatistics (Device Usage Statistics) (System API)

The **usageStatistics** module provides APIs for collecting statistics on device usage. For example, you can use the APIs to query whether an application is commonly used and an application's priority group, usage duration, system events (hibernation, wakeup, unlocking, and screen locking), application events (foreground, background, and start and end of continuous tasks), and the number of notifications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```
import { usageStatistics } from '@kit.BackgroundTasksKit'
```

## usageStatistics.isIdleState

isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an application is commonly used (with the value of **GroupType** being less than or equal to 30). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                          | Mandatory  | Description                                      |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | Yes   | Bundle name of the application.                          |
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result.<br>If the application is commonly used, **true** is returned. If the application is not commonly used or **bundleName** is invalid, **false** is returned.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.         |
| 10000002   | Parcel operation failed.         |
| 10000003   | System service operation failed. |
| 10000004   | IPC failed.        |
| 10000006   | Failed to get the application information.    |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.isIdleState("com.ohos.camera", (err: BusinessError, res: boolean) => {
  if (err) {
    console.log('BUNDLE_ACTIVE isIdleState callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
  }
});
```

## usageStatistics.isIdleState

isIdleState(bundleName: string): Promise&lt;boolean&gt;

Checks whether an application is commonly used (with the value of **GroupType** being less than or equal to 30). This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type    | Mandatory  | Description            |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.<br>If the application is commonly used, **true** is returned. If the application is not commonly used or **bundleName** is invalid, **false** is returned.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.         |
| 10000002   | Parcel operation failed.         |
| 10000003   | System service operation failed. |
| 10000004   | IPC failed.        |
| 10000006   | Failed to get the application information.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.isIdleState("com.ohos.camera").then((res: boolean) => {
  console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE isIdleState promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```
## usageStatistics.isIdleStateSync<sup>10+<sup>

isIdleStateSync(bundleName: string): boolean

Checks whether an application is commonly used (with the value of **GroupType** being less than or equal to 30). This API returns the result synchronously.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                          | Mandatory  | Description                                      |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | Yes   | Bundle name of the application.                          |

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| boolean | If the application is commonly used, **true** is returned. If the application is not commonly used or **bundleName** is invalid, **false** is returned.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.         |
| 10000002   | Parcel operation failed.         |
| 10000003   | System service operation failed. |
| 10000004   | IPC failed.        |
| 10000006   | Failed to get the application information.    |

**Example**
```ts
let isIdleState: boolean = usageStatistics.isIdleStateSync("com.ohos.camera");
```

## usageStatistics.queryAppGroup

queryAppGroup(): Promise&lt;number&gt;

Queries the priority group of this application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the priority group. A smaller value indicates a higher priority.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000005   | Application is not installed.      |
| 10000006   | Failed to get the application information.       |
| 10100002   | Failed to get the application group information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryAppGroup().then((res: number) => {
  console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryAppGroup

queryAppGroup(callback: AsyncCallback&lt;number&gt;): void

Queries the priority group of this application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name     | Type                   | Mandatory  | Description                        |
| -------- | --------------------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the priority group. A smaller value indicates a higher priority.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000005   | Application is not installed.      |
| 10000006   | Failed to get the application information.       |
| 10100002   | Failed to get the application group information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryAppGroup((err: BusinessError, res: number) => {
  if(err) {
    console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
  }
});
```

## usageStatistics.queryAppGroupSync<sup>10+<sup>

queryAppGroupSync(): number

Queries the priority group of this application. This API returns the result synchronously.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| number | Priority group. A smaller value indicates a higher priority.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000005   | Application is not installed.      |
| 10000006   | Failed to get the application information.       |
| 10100002   | Failed to get the application group information. |

**Example**

```ts
let priorityGroup: number = usageStatistics.queryAppGroupSync();
```

## usageStatistics.queryAppGroup

queryAppGroup(bundleName : string): Promise&lt;number&gt;

Queries the priority group of the application specified by **bundleName**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type    | Mandatory  | Description                                      |
| ---------- | ------ | ---- | ---------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the priority group. A smaller value indicates a higher priority.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000005   | Application is not installed.      |
| 10000006   | Failed to get the application information.       |
| 10100002   | Failed to get the application group information. |

**Example**

```javascript
// Promise mode when bundleName is specified
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName: string = "com.ohos.camera";
usageStatistics.queryAppGroup(bundleName).then((res: number) => {
  console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryAppGroup

queryAppGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void

Queries the priority group of the application specified by **bundleName**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                   | Mandatory  | Description                                      |
| ---------- | --------------------- | ---- | ---------------------------------------- |
| bundleName | string                | Yes   | Bundle name of the application.|
| callback   | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the priority group. A smaller value indicates a higher priority.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000005   | Application is not installed.      |
| 10000006   | Failed to get the application information.       |
| 10100002   | Failed to get the application group information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName: string = "com.ohos.camera";
usageStatistics.queryAppGroup(bundleName, (err: BusinessError, res: number) => {
  if(err) {
    console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
  }
});
```

## usageStatistics.queryAppGroupSync<sup>10+<sup>

queryAppGroupSync(bundleName: string): number

Queries the priority group of the application specified by **bundleName**. This API returns the result synchronously.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                          | Mandatory  | Description                                      |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | Yes   | Bundle name of the application.                          |

**Return value**

| Type             | Description                         |
| --------------- | --------------------------- |
| number | Priority group. A smaller value indicates a higher priority.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000005   | Application is not installed.      |
| 10000006   | Failed to get the application information.       |
| 10100002   | Failed to get the application group information. |

**Example**

```ts
let priorityGroup: number = usageStatistics.queryAppGroupSync("com.ohos.camera");
```

## usageStatistics.setAppGroup

setAppGroup(bundleName: string, newGroup: GroupType): Promise&lt;void&gt;

Sets a new group for the application specified by **bundleName**. This API uses a promise to return the result. It can be called only by the current application.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type       | Mandatory  | Description  |
| ---------- | --------- | ---- | ---- |
| bundleName | string    | Yes   | Bundle name of the application.|
| newGroup   | [GroupType](#grouptype) | Yes   | Type of the new group. |

**Return value**

| Type           | Description                       |
| ------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10000006   | Failed to get the application information.          |
| 10100001   | Repeated operation on the application group. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName: string = "com.example.deviceUsageStatistics";
let newGroup = usageStatistics.GroupType.DAILY_GROUP;

usageStatistics.setAppGroup(bundleName, newGroup).then( () => {
  console.log('BUNDLE_ACTIVE setAppGroup promise succeeded.');
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE setAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.setAppGroup

setAppGroup(bundleName: string, newGroup: GroupType, callback: AsyncCallback&lt;void&gt;): void

Sets a new group for the application specified by **bundleName**. This API uses an asynchronous callback to return the result. It can be called only by the current application.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name       | Type                 | Mandatory  | Description                       |
| ---------- | ------------------- | ---- | ------------------------- |
| bundleName | string              | Yes   | Bundle name of the application.                   |
| newGroup   | [GroupType](#grouptype)           | Yes   | Type of the new group.                     |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10000006   | Failed to get the application information.          |
| 10100001   | Repeated operation on the application group. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName: string = "com.example.deviceUsageStatistics";
let newGroup = usageStatistics.GroupType.DAILY_GROUP;

usageStatistics.setAppGroup(bundleName, newGroup, (err: BusinessError) => {
  if(err) {
    console.log('BUNDLE_ACTIVE setAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE setAppGroup callback succeeded.');
  }
});
```

## usageStatistics.queryBundleStatsInfos

queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleStatsMap&gt;): void

Queries the application usage duration statistics based on the specified start time and end time, with the minimum granularity of a day. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time, in milliseconds.                                  |
| end      | number                                   | Yes   | End time, in milliseconds.                                  |
| callback | AsyncCallback&lt;[BundleStatsMap](#bundlestatsmap)&gt; | Yes   | Callback used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryBundleStatsInfos(0, 20000000000000, (err: BusinessError, res:usageStatistics.BundleStatsMap) => {
  if (err) {
    console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback success.');
    console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res));
  }
});
```

## usageStatistics.queryBundleStatsInfos

queryBundleStatsInfos(begin: number, end: number): Promise&lt;BundleStatsMap&gt;

Queries the application usage duration statistics based on the specified start time and end time, with the minimum granularity of a day. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time, in milliseconds.|
| end   | number | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[BundleStatsMap](#bundlestatsmap)&gt; | Promise used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryBundleStatsInfos(0, 20000000000000).then((res:usageStatistics.BundleStatsMap) => {
  console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise success.');
  console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise result ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryBundleStatsInfoByInterval

queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStatsInfo&gt;&gt;): void

Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name       | Type                                      | Mandatory  | Description                                      |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| byInterval | [IntervalType](#intervaltype)            | Yes   | Type of information to be queried.                                   |
| begin      | number                                   | Yes   | Start time, in milliseconds.                                   |
| end        | number                                   | Yes   | End time, in milliseconds.                                   |
| callback   | AsyncCallback&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | Yes   | Callback used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.BundleStatsInfo>) => {
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

## usageStatistics.queryBundleStatsInfoByInterval

queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise&lt;Array&lt;BundleStatsInfo&gt;&gt;

Queries the application usage duration statistics in the specified time frame at the specified interval (daily, weekly, monthly, or annually). This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name       | Type                           | Mandatory  | Description   |
| ---------- | ----------------------------- | ---- | ----- |
| byInterval | [IntervalType](#intervaltype) | Yes   | Type of information to be queried.|
| begin      | number                        | Yes   | Start time, in milliseconds.|
| end        | number                        | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | Promise used to return the application usage duration statistics.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000).then((res: Array<usageStatistics.BundleStatsInfo>) => {
  console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise success.');
  for (let i = 0; i < res.length; i++) {
    console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise number : ' + (i + 1));
    console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise result ' + JSON.stringify(res[i]));
  }
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryBundleEvents

queryBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void

Queries events of all applications based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time, in milliseconds.                                  |
| end      | number                                   | Yes   | End time, in milliseconds.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Yes   | Callback used to return the events.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryBundleEvents(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.BundleEvents>) => {
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

## usageStatistics.queryBundleEvents

queryBundleEvents(begin: number, end: number): Promise&lt;Array&lt;BundleEvents&gt;&gt;

Queries events of all applications based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time, in milliseconds.|
| end   | number | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Promise used to return the events.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryBundleEvents(0, 20000000000000).then((res: Array<usageStatistics.BundleEvents>) => {
  console.log('BUNDLE_ACTIVE queryBundleEvents promise success.');
  for (let i = 0; i < res.length; i++) {
    console.log('BUNDLE_ACTIVE queryBundleEvents promise number : ' + (i + 1));
    console.log('BUNDLE_ACTIVE queryBundleEvents promise result ' + JSON.stringify(res[i]));
  }
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryCurrentBundleEvents

queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void

Queries events of this application based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | Yes   | Start time, in milliseconds.                                  |
| end      | number                                   | Yes   | End time, in milliseconds.                                  |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Yes   | Callback used to return the events.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryCurrentBundleEvents(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.BundleEvents>) => {
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

## usageStatistics.queryCurrentBundleEvents

queryCurrentBundleEvents(begin: number, end: number): Promise&lt;Array&lt;BundleEvents&gt;&gt;

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
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Promise used to return the events.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.      |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryCurrentBundleEvents(0, 20000000000000).then((res: Array<usageStatistics.BundleEvents>) => {
  console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise success.');
  for (let i = 0; i < res.length; i++) {
    console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise number : ' + (i + 1));
    console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise result ' + JSON.stringify(res[i]));
  }
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryDeviceEventStats

queryDeviceEventStats(begin: number, end: number): Promise&lt;Array&lt;DeviceEventStats&gt;&gt;

Queries statistics about system events (hibernation, wakeup, unlocking, and locking) that occur between the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time, in milliseconds.|
| end   | number | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Promise used to return the statistics about system events.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10000006   | Failed to get the application information.          |
| 10000007   | Failed to get the system time.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryDeviceEventStats(0, 20000000000000).then((res: Array<usageStatistics.DeviceEventStats>) => {
  console.log('BUNDLE_ACTIVE queryDeviceEventStates promise success.');
  console.log('BUNDLE_ACTIVE queryDeviceEventStates promise result ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryDeviceEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryDeviceEventStats

queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void

Queries statistics about system events (hibernation, wakeup, unlocking, and locking) that occur between the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | Yes   | Start time, in milliseconds.                                   |
| end      | number                                   | Yes   | End time, in milliseconds.                                   |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Yes   | Callback used to return the statistics about system events.| 

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10000006   | Failed to get the application information.           |
| 10000007   | Failed to get the system time.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryDeviceEventStats(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.DeviceEventStats>) => {
  if(err) {
    console.log('BUNDLE_ACTIVE queryDeviceEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE queryDeviceEventStats callback success.');
    console.log('BUNDLE_ACTIVE queryDeviceEventStats callback result ' + JSON.stringify(res));
  }
});
```

## usageStatistics.queryNotificationEventStats

queryNotificationEventStats(begin: number, end: number): Promise&lt;Array&lt;DeviceEventStats&gt;&gt;

Queries the number of notifications from all applications based on the specified start time and end time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| begin | number | Yes   | Start time, in milliseconds.|
| end   | number | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Promise used to return the number of notifications.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10000006   | Failed to get the application information.          |
| 10000007   | Failed to get the system time.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryNotificationEventStats(0, 20000000000000).then((res: Array<usageStatistics.DeviceEventStats>) => {
  console.log('BUNDLE_ACTIVE queryNotificationEventStats promise success.');
  console.log('BUNDLE_ACTIVE queryNotificationEventStats promise result ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryNotificationEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryNotificationEventStats

queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void

Queries the number of notifications from all applications based on the specified start time and end time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | Yes   | Start time, in milliseconds.                                   |
| end      | number                                   | Yes   | End time, in milliseconds.                                   |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Yes   | Callback used to return the number of notifications.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10000006   | Failed to get the application information.          |
| 10000007   | Failed to get the system time.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryNotificationEventStats(0, 20000000000000, (err: BusinessError, res: Array<usageStatistics.DeviceEventStats>) => {
  if(err) {
    console.log('BUNDLE_ACTIVE queryNotificationEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE queryNotificationEventStats callback success.');
    console.log('BUNDLE_ACTIVE queryNotificationEventStats callback result ' + JSON.stringify(res));
  }
});
```

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(): Promise&lt;Array&lt;HapModuleInfo&gt;&gt;

Queries the usage records of unused HAP files for each application in the FA model. If the HAP file contains FA widgets, the usage records also contain the widget information. This API uses a promise to return the result.

Queries FA usage records. This API uses a promise to return a maximum of 1000 FA usage records sorted by time (most recent first).

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Return value**

| Type                                      | Description                                |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Promise used to return the result. A maximum of 1000 usage records can be returned.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
// Invocation when maxNum is not passed
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryModuleUsageRecords().then((res: Array<usageStatistics.HapModuleInfo>) => {
  console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
  for (let i = 0; i < res.length; i++) {
    console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
    console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
  }
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(callback: AsyncCallback&lt;Array&lt;HapModuleInfo&gt;&gt;): void

Queries the usage records of unused HAP files for each application in the FA model. If the HAP file contains FA widgets, the usage records also contain the widget information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Yes   | Callback used to return the result. A maximum of 1000 usage records can be returned.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md).

| ID       | Error Message                      |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryModuleUsageRecords((err: BusinessError, res: Array<usageStatistics.HapModuleInfo>) => {
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

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(maxNum: number): Promise&lt;Array&lt;HapModuleInfo&gt;&gt;

Queries a given number of usage records of unused HAP files for each application in the FA model. If the HAP file contains FA widgets, the usage records also contain the widget information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name   | Type    | Mandatory  | Description                                |
| ------ | ------ | ---- | ---------------------------------- |
| maxNum | number | Yes   | Number of usage records, in the range [1, 1000].|

**Return value**

| Type                                      | Description                                |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Promise used to return the result. The usage records returned does not exceed the value of **maxNum**.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryModuleUsageRecords(1000).then((res: Array<usageStatistics.HapModuleInfo>) => {
  console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
  for (let i = 0; i < res.length; i++) {
    console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
    console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
  }
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryModuleUsageRecords

queryModuleUsageRecords(maxNum: number, callback: AsyncCallback&lt;Array&lt;HapModuleInfo&gt;&gt;): void

Queries a given number of usage records of unused HAP files for each application in the FA model. If the HAP file contains FA widgets, the usage records also contain the widget information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| maxNum   | number                                   | Yes   |  Number of usage records, in the range [1, 1000].|
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Yes   | Callback used to return the result. The usage records returned does not exceed the value of **maxNum**.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryModuleUsageRecords(1000, (err: BusinessError, res: Array<usageStatistics.HapModuleInfo>) => {
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

## usageStatistics.registerAppGroupCallBack

registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;): Promise&lt;void&gt;

Registers a callback for application group changes. When an application group of the user changes, an [AppGroupCallbackInfo](#appgroupcallbackinfo) instance is returned to all applications that have registered the callback. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| groupCallback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | Yes  | Application group change information.|

**Return value**

| Type           | Description                     |
| ------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10100001   | Repeated operation on the application group. |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function onBundleGroupChanged(res: usageStatistics.AppGroupCallbackInfo) {
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack RegisterGroupCallBack callback success.');
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
};
usageStatistics.registerAppGroupCallBack(onBundleGroupChanged).then( () => {
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack promise succeeded.');
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.registerAppGroupCallBack

registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;, callback: AsyncCallback&lt;void&gt;): void

Registers a callback for application group changes. When an application group of the user changes, an [AppGroupCallbackInfo](#appgroupcallbackinfo) instance is returned to all applications that have registered the callback. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| groupCallback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | Yes  | Application group change information.  |
| callback | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10100001   | Repeated operation on the application group. |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function onBundleGroupChanged(res: usageStatistics.AppGroupCallbackInfo) {
  console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
  console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
};
usageStatistics.registerAppGroupCallBack(onBundleGroupChanged, (err: BusinessError) => {
  if(err) {
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback success.');
  }
});
```

## usageStatistics.unregisterAppGroupCallBack

unregisterAppGroupCallBack(): Promise&lt;void&gt;

Unregisters the callback for application group changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Return value**

| Type           | Description                      |
| ------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10100001   | Repeated operation on the application group. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.unregisterAppGroupCallBack().then( () => {
  console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise succeeded.');
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.unregisterAppGroupCallBack

unregisterAppGroupCallBack(callback: AsyncCallback&lt;void&gt;): void;

Unregisters the callback for application group changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BUNDLE_ACTIVE_INFO

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**Parameters**

| Name     | Type                 | Mandatory  | Description            |
| -------- | ------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [DeviceUsageStatistics Error Codes](errorcode-DeviceUsageStatistics.md) and [Common Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | Not System App. |
| 401 | Parameter error. |
| 801 | Capability not supported.|
| 10000001   | Memory operation failed.              |
| 10000002   | Parcel operation failed.              |
| 10000003   | System service operation failed.      |
| 10000004   | IPC failed.             |
| 10100001   | Repeated operation on the application group. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.unregisterAppGroupCallBack((err: BusinessError) => {
  if(err) {
    console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
  } else {
    console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback success.');
  }
});
```

## HapModuleInfo

Defines the information about the usage record in the FA model.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                 | Type                                      | Mandatory  | Description                           |
| -------------------- | ---------------------------------------- | ---- | ----------------------------- |
| deviceId             | string                                   | No   | Device ID.                |
| bundleName           | string                                   | Yes   | Bundle name.            |
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

Defines the information about the usage record of FA widgets.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

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

| Name          | Type  | Mandatory| Description            |
| ---------------- | ------ | ---- | ---------------- |
| appOldGroup | number | Yes  | Application group before the change.|
| appNewGroup | number | Yes  | Application group after the change.|
| userId           | number | Yes  | User ID.          |
| changeReason     | number | Yes  | Reason for the group change.<br>- 256 (default): A record is initially created.<br>- 512: An exception occurs when the priority group is calculated.<br>- 768: The usage duration changes.<br>- 1024: Another application forcibly sets a priority group for the current application.|
| bundleName       | string | Yes  | Bundle name.        |

## BundleStatsInfo

Provides the usage duration information of an application.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name                     | Type    | Mandatory  | Description                                      |
| ------------------------ | ------ | ---- | ---------------------------------------- |
| bundleName               | string | No   | Bundle name of the application.                                   |
| abilityPrevAccessTime    | number | No   | Last time when the application was used.                            |
| abilityInFgTotalTime     | number | No   | Total time that the application runs in the foreground.                            |
| id                       | number | Yes   | User ID.|
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
| bundleName            | string | No   | Bundle name of the application.                                   |
| eventId             | number | No   | Application event type.                                 |
| eventOccurredTime     | number | No   | Timestamp when the application event occurs.                             |
| appGroup | number | No   | Group of the application by usage priority.|
| indexOfLink           | string | No   | Shortcut ID.|
| nameOfClass           | string | No   | Class name.|

## BundleStatsMap

Provides the usage duration information of an application.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

|Name                          | Description                                      |
| ------------------------------ | ---------------------------------------- |
| Record<string, [BundleStatsInfo](#bundlestatsinfo)> | Usage duration information by application.|

## DeviceEventStats

Provides statistics about notifications and system events.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name    | Type    | Mandatory  | Description               |
| ------- | ------ | ---- | ----------------- |
| name    | string | Yes   | Bundle name of the notification sending application or system event name.   |
| eventId | number | Yes   | Type of the notification or system event.       |
| count   | number | Yes   | Number of application notifications or system event triggering times.|

## IntervalType

Enumerates the interval types for querying the application usage duration.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.App

| Name          | Value | Description                                      |
| ------------ | ---- | ---------------------------------------- |
| BY_OPTIMIZED | 0    | The system queries the application usage duration statistics in the specified time frame at the interval the system deems appropriate.|
| BY_DAILY     | 1    | The system queries the application usage duration statistics in the specified time frame on a daily basis.             |
| BY_WEEKLY    | 2    | The system queries the application usage duration statistics in the specified time frame on a weekly basis.             |
| BY_MONTHLY   | 3    | The system queries the application usage duration statistics in the specified time frame on a monthly basis.             |
| BY_ANNUALLY  | 4    | The system queries the application usage duration statistics in the specified time frame on an annual basis.             |

## GroupType

Enumerates the application group types.

**System capability**: SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

| Name                | Value | Description               |
| ------------------ | ---- | ----------------- |
| ALIVE_GROUP | 10   | Group of active applications.             |
| DAILY_GROUP | 20   | Group of frequently used applications that are not in the active state.   |
| FIXED_GROUP | 30   | Group of applications that are used periodically but not every day.|
| RARE_GROUP  | 40   | Group of rarely used applications.     |
| LIMITED_GROUP | 50   | Group of restricted applications.           |
| NEVER_GROUP | 60   | Group of applications that have been installed but never run. |
