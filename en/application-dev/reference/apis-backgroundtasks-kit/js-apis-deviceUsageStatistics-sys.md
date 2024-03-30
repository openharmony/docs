# @ohos.bundleState (Device Usage Statistics) (System API)

This module provides APIs for collecting statistics on device usage.

System applications can call these APIs to implement the following features:

- Query the usage duration in different time segments, events (foreground, background, start and end of continuous tasks), and the number of notifications, on a per application basis.
- Query the bundle group information of the invoking application itself.
- Query the idle status of applications, including the invoking application itself.

> **NOTE**
>
> This module is deprecated since API version 9. You are advised to use [@ohos.resourceschedule.usageStatistics (Device Usage Statistics) (System API)](js-apis-resourceschedule-deviceUsageStatistics-sys.md) instead.
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.bundleState](js-apis-deviceUsageStatistics.md).

## Modules to Import

```js
import bundleState from '@ohos.bundleState'
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
| callback | AsyncCallback&lt;[BundleActiveInfoResponse](js-apis-deviceUsageStatistics.md#bundleactiveinforesponse)&gt; | Yes   | Callback used to return the application usage duration statistics.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

bundleState.queryBundleStateInfos(0, 20000000000000, (err: BusinessError ,
  res: bundleState.BundleActiveInfoResponse ) => {
  if (err) {
    console.error('BUNDLE_ACTIVE queryBundleStateInfos callback failed, because: ' + err.code);
  } else {
    console.log('BUNDLE_ACTIVE queryBundleStateInfos callback success.');
    console.log('BUNDLE_ACTIVE queryBundleStateInfos callback result ' + JSON.stringify(res));
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
| Promise&lt;[BundleActiveInfoResponse](js-apis-deviceUsageStatistics.md#bundleactiveinforesponse)&gt; | Promise used to return the result. return the application usage duration statistics.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

bundleState.queryBundleStateInfos(0, 20000000000000).then((res: bundleState.BundleActiveInfoResponse) => {
  console.log('BUNDLE_ACTIVE queryBundleStateInfos promise success.');
  console.log('BUNDLE_ACTIVE queryBundleStateInfos promise result ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.error('BUNDLE_ACTIVE queryBundleStateInfos promise failed, because: ' + err.code);
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
| byInterval | [IntervalType](js-apis-deviceUsageStatistics.md#intervaltype)            | Yes   | Type of information to be queried.                                   |
| begin      | number                                   | Yes   | Start time, in milliseconds.                                   |
| end        | number                                   | Yes   | End time, in milliseconds.                                   |
| callback   | AsyncCallback&lt;Array&lt;[BundleStateInfo](js-apis-deviceUsageStatistics.md#bundlestateinfo)&gt;&gt; | Yes   | Callback used to return the application usage duration statistics.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

bundleState.queryBundleStateInfoByInterval(bundleState.IntervalType.BY_OPTIMIZED, 0, 20000000000000, (err: BusinessError, res: Array<bundleState.BundleStateInfo>) => {
  if (err) {
    console.error('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback failed, because: ' + err.code);
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
| byInterval | [IntervalType](js-apis-deviceUsageStatistics.md#intervaltype) | Yes   | Type of information to be queried.|
| begin      | number                        | Yes   | Start time, in milliseconds.|
| end        | number                        | Yes   | End time, in milliseconds.|

**Return value**

| Type                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStateInfo](js-apis-deviceUsageStatistics.md#bundlestateinfo)&gt;&gt; | Promise used to return the result. return the application usage duration statistics.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

bundleState.queryBundleStateInfoByInterval(bundleState.IntervalType.BY_OPTIMIZED, 0, 20000000000000).then((res: Array<bundleState.BundleStateInfo>) => {
  console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise success.');
  for (let i = 0; i < res.length; i++) {
    console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise number : ' + (i + 1));
    console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise result ' + JSON.stringify(res[i]));
  }
}).catch((err: BusinessError) => {
  console.error('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise failed, because: ' + err.code);
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
| callback | AsyncCallback&lt;Array&lt;[BundleActiveState](js-apis-deviceUsageStatistics.md#bundleactivestate)&gt;&gt; | Yes   | Callback used to return the events obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

bundleState.queryBundleActiveStates(0, 20000000000000, (err: BusinessError, res: Array<bundleState.BundleActiveState>) => {
  if (err) {
    console.error('BUNDLE_ACTIVE queryBundleActiveStates callback failed, because: ' + err.code);
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
| Promise&lt;Array&lt;[BundleActiveState](js-apis-deviceUsageStatistics.md#bundleactivestate)&gt;&gt; | Promise used to return the result. return the events obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

bundleState.queryBundleActiveStates(0, 20000000000000).then((res: Array<bundleState.BundleActiveState>) => {
  console.log('BUNDLE_ACTIVE queryBundleActiveStates promise success.');
  for (let i = 0; i < res.length; i++) {
    console.log('BUNDLE_ACTIVE queryBundleActiveStates promise number : ' + (i + 1));
    console.log('BUNDLE_ACTIVE queryBundleActiveStates promise result ' + JSON.stringify(res[i]));
  }
}).catch((err: BusinessError) => {
  console.error('BUNDLE_ACTIVE queryBundleActiveStates promise failed, because: ' + err.code);
});
```
