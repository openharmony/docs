# @ohos.resourceschedule.usageStatistics (设备使用信息统计)(系统接口)

本模块提供设备使用信息统计能力，包括查询应用是否为常用应用、优先级分组、使用时长、系统事件（休眠、唤醒、解锁、锁屏）信息、应用事件（前台、后台、长时任务开始和结束）信息、通知次数等不同类型信息。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口为系统接口。

## 导入模块

```
import { usageStatistics } from '@kit.BackgroundTasksKit'
```

## usageStatistics.isIdleState

isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

查询指定的应用是否为常用应用（GroupType值≤30），使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型                           | 必填   | 说明                                       |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | 是    | 应用的bundleName。                           |
| callback   | AsyncCallback&lt;boolean&gt; | 是    | 回调函数。<br>若应用为常用应用，返回true；若指定应用不是常用应用或bundleName无效，则返回false。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：
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

查询指定的应用是否为常用应用（GroupType值≤30），使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型     | 必填   | 说明             |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是    | 应用的bundleName。 |

**返回值**：

| 类型                     | 说明                                       |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。<br>若应用为常用应用，返回true；若指定应用不是常用应用或bundleName无效，则返回false。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

查询指定的应用是否为常用应用（GroupType值≤30），使用同步方式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型                           | 必填   | 说明                                       |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | 是    | 应用的bundleName。                           |

**返回值**：

| 类型                     | 说明                                       |
| ---------------------- | ---------------------------------------- |
| boolean | 若应用为常用应用，返回true；若指定应用不是常用应用或bundleName无效，则返回false。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：
```ts
let isIdleState: boolean = usageStatistics.isIdleStateSync("com.ohos.camera");
```

## usageStatistics.queryAppGroup

queryAppGroup(): Promise&lt;number&gt;

查询当前应用的优先级分组，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**返回值**：

| 类型              | 说明                          |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise对象。返回当前应用优先级分组结果，值越小，优先级越高。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

查询当前应用的优先级分组，使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名      | 类型                    | 必填   | 说明                         |
| -------- | --------------------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调函数，返回当前应用优先级分组结果，值越小，优先级越高。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

查询当前应用的优先级分组，使用同步方式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**返回值**：

| 类型              | 说明                          |
| --------------- | --------------------------- |
| number | 返回当前应用优先级分组结果，值越小，优先级越高。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

```ts
let priorityGroup: number = usageStatistics.queryAppGroupSync();
```

## usageStatistics.queryAppGroup

queryAppGroup(bundleName : string): Promise&lt;number&gt;

查询指定bundleName应用的优先级分组，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型     | 必填   | 说明                                       |
| ---------- | ------ | ---- | ---------------------------------------- |
| bundleName | string | 是    | 应用的bundleName。 |

**返回值**：

| 类型              | 说明                          |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | Promise对象。返回指定应用的优先级分组结果，值越小，优先级越高。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

```javascript
//有bundleName的promise
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

查询指定bundleName应用的优先级分组，使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型                    | 必填   | 说明                                       |
| ---------- | --------------------- | ---- | ---------------------------------------- |
| bundleName | string                | 是    | 应用的bundleName。 |
| callback   | AsyncCallback&lt;number&gt; | 是    | 回调函数，返回指定应用的优先级分组结果，值越小，优先级越高。|

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

查询指定bundleName应用的优先级分组，使用同步方式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型                           | 必填   | 说明                                       |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | 是    | 应用的bundleName。                           |

**返回值**：

| 类型              | 说明                          |
| --------------- | --------------------------- |
| number | 返回应用的优先级分组结果，值越小，优先级越高。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

```ts
let priorityGroup: number = usageStatistics.queryAppGroupSync("com.ohos.camera");
```

## usageStatistics.setAppGroup

setAppGroup(bundleName: string, newGroup: GroupType): Promise&lt;void&gt;

将指定bundleName应用的分组设置为newGroup，仅支持当前应用为其他应用设置，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型        | 必填   | 说明   |
| ---------- | --------- | ---- | ---- |
| bundleName | string    | 是    | 应用的bundleName。 |
| newGroup   | [GroupType](#grouptype) | 是    | 应用分组类型。  |

**返回值**：

| 类型            | 说明                        |
| ------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

将指定bundleName应用的分组设置为newGroup，仅支持当前应用为其他应用设置，使用CallBack异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型                  | 必填   | 说明                        |
| ---------- | ------------------- | ---- | ------------------------- |
| bundleName | string              | 是    | 应用的bundleName。                    |
| newGroup   | [GroupType](#grouptype)           | 是    | 应用分组类型。                      |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调函数，返回是否设置成功。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询应用使用时长的具体信息，统计的最小颗粒度是天，使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间，以毫秒为单位。                                   |
| end      | number                                   | 是    | 结束时间，以毫秒为单位。                                   |
| callback | AsyncCallback&lt;[BundleStatsMap](#bundlestatsmap)&gt; | 是    | 回调函数，返回指定时间段内应用使用时长的具体信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询应用使用时长的具体信息，统计的最小颗粒度是天，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，以毫秒为单位。 |
| end   | number | 是    | 结束时间，以毫秒为单位。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[BundleStatsMap](#bundlestatsmap)&gt; | Promise对象。返回指定时间段内应用使用时长的具体信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryBundleStatsInfos(0, 20000000000000).then((res:usageStatistics.BundleStatsMap) => {
  console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise success.');
  console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise result ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryAppStatsInfos<sup>15+</sup>

queryAppStatsInfos(begin: number, end: number): Promise&lt;AppStatsMap&gt;

通过指定起始和结束时间，查询应用使用时长的具体信息，统计的最小颗粒度是天，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，以毫秒为单位。 |
| end   | number | 是    | 结束时间，以毫秒为单位。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[AppStatsMap](#appstatsmap15)&gt; | Promise对象。返回指定时间段内应用使用的具体信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryAppStatsInfos(0, 20000000000000).then((res:usageStatistics.AppStatsMap) => {
  console.log('queryAppStatsInfos promise success.');
  console.log('queryAppStatsInfos promise result ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('queryAppStatsInfos promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryLastUseTime<sup>15+</sup>

queryLastUseTime(appInfo: Record&lt;string, Array&lt;number&gt;&gt;): Promise&lt;AppStatsMap&gt;

通过指定bundleName和应用的index，查询应用使用具体信息，统计的最小颗粒度是天，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| appInfo | Record&lt;string, Array&lt;number&gt;&gt; | 是    | 参数为map结构，key是bundleName，value是查询应用的index（可以有多个，通过Array传入）。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[AppStatsMap](#appstatsmap15)&gt; | Promise对象。返回指定bundleName和index应用使用的具体信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

usageStatistics.queryLastUseTime({"com.huawei.hmos.ailife": [0]}).then((res:usageStatistics.AppStatsMap) => {
  console.log('queryLastUseTime promise success.');
  console.log('queryLastUseTime promise result ' + JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.log('queryLastUseTime promise failed. code is: ' + err.code + ',message is: ' + err.message);
});
```

## usageStatistics.queryBundleStatsInfoByInterval

queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStatsInfo&gt;&gt;): void

通过指定时间段间隔（天、周、月、年），查询应用使用时长的统计信息，使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名        | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| byInterval | [IntervalType](#intervaltype)            | 是    | 查询类型。                                    |
| begin      | number                                   | 是    | 起始时间，以毫秒为单位。                                    |
| end        | number                                   | 是    | 结束时间，以毫秒为单位。                                    |
| callback   | AsyncCallback&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | 是    | 回调函数，返回指定时间段间隔内，应用使用时长的统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定时间段间隔（天、周、月、年），查询应用使用时长的统计信息，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App 

**参数**：

| 参数名        | 类型                            | 必填   | 说明    |
| ---------- | ----------------------------- | ---- | ----- |
| byInterval | [IntervalType](#intervaltype) | 是    | 查询类型。 |
| begin      | number                        | 是    | 起始时间，以毫秒为单位。 |
| end        | number                        | 是    | 结束时间，以毫秒为单位。 |

**返回值**：

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | Promise对象。返回指定时间段间隔内，应用使用时长的统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询所有应用的事件集合，使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间，以毫秒为单位。                                   |
| end      | number                                   | 是    | 结束时间，以毫秒为单位。                                   |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | 是    | 回调函数，返回起始和结束时间段内，所有应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询所有应用的事件集合，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，以毫秒为单位。 |
| end   | number | 是    | 结束时间，以毫秒为单位。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Promise对象。返回起始和结束时间段内，所有应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询当前应用的事件集合，使用Callback异步回调。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间，以毫秒为单位。                                   |
| end      | number                                   | 是    | 结束时间，以毫秒为单位。                                   |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | 是    | 回调函数，返回指定起始和结束时间段内，当前应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间段内，查询当前应用的事件集合，使用Promise异步回调。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，以毫秒为单位。 |
| end   | number | 是    | 结束时间，以毫秒为单位。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | Promise对象。返回指定起始和结束时间段内，当前应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询系统事件（休眠、唤醒、解锁、锁屏）的统计信息，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，以毫秒为单位。 |
| end   | number | 是    | 结束时间，以毫秒为单位。 |

**返回值**：

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Promise对象。返回起始和结束时间段内，系统事件（休眠、唤醒、解锁、锁屏）的统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询系统事件（休眠、唤醒、解锁、锁屏）的统计信息，使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | 是    | 起始时间，以毫秒为单位。                                    |
| end      | number                                   | 是    | 结束时间，以毫秒为单位。                                    |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | 是    | 回调函数，返回起始和结束时间段内，系统事件（休眠、唤醒、解锁、锁屏）的统计信息。 | 

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询所有应用的通知次数，使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，以毫秒为单位。 |
| end   | number | 是    | 结束时间，以毫秒为单位。 |

**返回值**：

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | Promise对象。返回指定起始和结束时间段内，所有应用的通知次数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

通过指定起始和结束时间，查询所有应用的通知次数，使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | 是    | 起始时间，以毫秒为单位。                                    |
| end      | number                                   | 是    | 结束时间，以毫秒为单位。                                    |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | 是    | 回调函数，返回指定起始和结束时间段内，所有应用的通知次数。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

查询FA模型下各应用不用Hap包的使用记录（不超过1000条）。若Hap包中存在FA卡片，使用信息中也包含卡片信息。使用Promise异步回调。

使用Promise形式返回不超过1000条FA使用记录，FA使用记录由近及远排序。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**返回值**：

| 类型                                       | 说明                                 |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Promise对象。返回FA模型下各应用不用Hap包的使用记录（不超过1000条）。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

```ts
// 无maxNum参数调用方式
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

查询FA模型下各应用不用Hap包的使用记录（不超过1000条）。若Hap包中存在FA卡片，使用信息中也包含卡片信息。使用CallBack异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | 是    | 回调函数，返回FA模型下各应用不用Hap包的使用记录（不超过1000条）。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           |
| 10000002   | Parcel operation failed.           |
| 10000003   | System service operation failed.   |
| 10000004   | IPC failed.          |
| 10000006   | Failed to get the application information.       |
| 10000007   | Failed to get the system time.  |

**示例**：

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

根据设置的maxNum，查询FA模型下各应用不用Hap包的使用记录。若Hap包中存在FA卡片，使用信息中也包含卡片信息。使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名    | 类型     | 必填   | 说明                                 |
| ------ | ------ | ---- | ---------------------------------- |
| maxNum | number | 是    | 使用记录的条数，取值范围为[1，1000]。 |

**返回值**：

| 类型                                       | 说明                                 |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | Promise对象，返回不超过maxNum条，FA模型下各应用不用Hap包的使用记录。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

根据设置的maxNum，查询FA模型下各应用不用Hap包的使用记录。若Hap包中存在FA卡片，使用信息中也包含卡片信息。使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| maxNum   | number                                   | 是    |  使用记录的条数，取值范围为[1，1000]。 |
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | 是    | 回调方法，返回不超过maxNum条，FA模型下各应用不用Hap包的使用记录。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

注册应用分组变化监听，即用户名下的某个应用分组发生变化时，向所有已注册分组变化监听的应用返回[AppGroupCallbackInfo](#appgroupcallbackinfo)信息。使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| groupCallback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | 是   | 返回的应用分组变化信息。 |

**返回值**：

| 类型            | 说明                      |
| ------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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


**示例**：

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

应用注册分组变化监听，即用户名下的某个应用分组发生变化时，向所有已注册分组变化监听的应用返回[AppGroupCallbackInfo](#appgroupcallbackinfo)信息。使用Callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| groupCallback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | 是   | 返回的应用分组变化信息。   |
| callback | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数，返回注册监听是否成功。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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


**示例**：

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

应用解除分组变化监听。使用Promise异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**返回值**：

| 类型            | 说明                       |
| ------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

应用解除分组变化监听。使用callback异步回调。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名      | 类型                  | 必填   | 说明             |
| -------- | ------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，返回是否成功解除监听。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[设备信息使用统计错误码](errorcode-DeviceUsageStatistics.md)。

| 错误码ID  | 错误信息             |
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

**示例**：

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

FA模型的使用信息属性集合。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

| 名称                  | 类型                                       | 必填   | 说明                            |
| -------------------- | ---------------------------------------- | ---- | ----------------------------- |
| deviceId             | string                                   | 否    | 设备Id。                 |
| bundleName           | string                                   | 是    | 应用名称。             |
| moduleName           | string                                   | 是    | FA所属module名。                  |
| abilityName          | string                                   | 否    | FA的MainAbility名。              |
| appLabelId           | number                                   | 否    | FA的应用labelId。                 |
| labelId              | number                                   | 否    | FA所属module的labelId。           |
| descriptionId        | number                                   | 否    | FA所属的应用descriptionId。         |
| abilityLableId       | number                                   | 否    | FA的MainAbility labelId。       |
| abilityDescriptionId | number                                   | 否    | FA的MainAbility descriptionId。 |
| abilityIconId        | number                                   | 否    | FA的MainAbility iconId。        |
| launchedCount        | number                                   | 是    | FA的启动次数。                      |
| lastModuleUsedTime   | number                                   | 是    | FA的上一次使用时间。                   |
| formRecords          | Array&lt;[HapFormInfo](#hapforminfo)&gt; | 是    | FA中卡片的使用记录。                   |

## HapFormInfo

FA卡片的使用信息属性集合。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

| 名称              | 类型     | 必填   | 说明          |
| ---------------- | ------ | ---- | ----------- |
| formName         | string | 是    | 卡片名称。       |
| formDimension    | number | 是    | 卡片尺寸。       |
| formId           | number | 是    | 卡片Id。       |
| formLastUsedTime | number | 是    | 卡片的上一次点击时间。 |
| count            | number | 是    | 卡片的点击次数。    |

## AppGroupCallbackInfo

应用分组变化回调返回的属性集合

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

| 名称           | 类型   | 必填 | 说明             |
| ---------------- | ------ | ---- | ---------------- |
| appOldGroup | number | 是   | 变化前的应用分组。 |
| appNewGroup | number | 是   | 变化后的应用分组。|
| userId           | number | 是   | 用户id。           |
| changeReason     | number | 是   | 分组变化原因。<br>- 256:使用记录初创建时，默认匹配的原因。<br>- 512:计算优先级分组时异常。<br>- 768:使用时长变化。  <br>- 1024:有其他应用为当前应用强制设置优先级分组。|
| bundleName       | string | 是   | 应用名称。         |

## BundleStatsInfo

应用使用时长的具体信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

| 名称                      | 类型     | 必填   | 说明                                       |
| ------------------------ | ------ | ---- | ---------------------------------------- |
| bundleName               | string | 否    | 应用包名。                                    |
| abilityPrevAccessTime    | number | 否    | 应用最后一次使用的时间。                             |
| abilityInFgTotalTime     | number | 否    | 应用在前台使用的总时间。                             |
| id                       | number | 是    | 用户id。 |
| abilityPrevSeenTime      | number | 否    | 应用最后一次在前台可见的时间。 |
| abilitySeenTotalTime     | number | 否    | 应用在前台可见的总时间。 |
| fgAbilityAccessTotalTime | number | 否    | 应用访问前台的总时间。 |
| fgAbilityPrevAccessTime  | number | 否    | 应用最后一次访问前台的时间。|
| infosBeginTime           | number | 否    | BundleActiveInfo对象中第一条应用使用统计的记录时间。 |
| infosEndTime             | number | 否    | BundleActiveInfo对象中最后一条应用使用统计的记录时间。 |
| appIndex<sup>15+</sup>                 | number | 否    | 应用程序的索引。 |

## BundleEvents

应用事件的具体信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

| 名称                   | 类型     | 必填   | 说明                                       |
| --------------------- | ------ | ---- | ---------------------------------------- |
| bundleName            | string | 否    | 应用包名。                                    |
| eventId             | number | 否    | 应用事件类型。                                  |
| eventOccurredTime     | number | 否    | 应用事件发生的时间戳。                              |
| appGroup | number | 否    | 应用程序的使用优先级组。|
| indexOfLink           | string | 否    | 快捷方式id。|
| nameOfClass           | string | 否    | 类名。|

## BundleStatsMap

应用使用时长的具体信息。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

|名称                           | 描述                                       |
| ------------------------------ | ---------------------------------------- |
| Record<string, [BundleStatsInfo](#bundlestatsinfo)> | 不同应用的使用时长统计信息 |

## AppStatsMap<sup>15+</sup>

应用使用的具体信息(包含分身应用)。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

|名称                           | 描述                                       |
| ------------------------------ | ---------------------------------------- |
| Record<string, Array<[BundleStatsInfo](#bundlestatsinfo)>> | 不同应用的使用统计信息（包含分身应用）。 |

## DeviceEventStats

提供通知、系统事件的统计信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

| 名称     | 类型     | 必填   | 说明                |
| ------- | ------ | ---- | ----------------- |
| name    | string | 是    | 通知应用包名或者系统事件名。    |
| eventId | number | 是    | 通知、系统事件类型。        |
| count   | number | 是    | 应用通知次数或者系统事件触发次数。 |

## IntervalType

应用使用时长的查询类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

| 名称           | 值  | 说明                                       |
| ------------ | ---- | ---------------------------------------- |
| BY_OPTIMIZED | 0    | 表示系统自行判断最合适的查询类型（天、周、月、年）去查询指定时间段间隔的应用使用时长信息。 |
| BY_DAILY     | 1    | 表示系统按照天去查询指定时间段间隔的应用使用时长信息。              |
| BY_WEEKLY    | 2    | 表示系统按照周去查询指定时间段间隔的应用使用时长信息。              |
| BY_MONTHLY   | 3    | 表示系统按照月去查询指定时间段间隔的应用使用时长信息。              |
| BY_ANNUALLY  | 4    | 表示系统按照年去查询指定时间段间隔的应用使用时长信息。              |

## GroupType

应用分组的设置类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

| 名称                 | 值  | 说明                |
| ------------------ | ---- | ----------------- |
| ALIVE_GROUP | 10   | 活跃分组。              |
| DAILY_GROUP | 20   | 经常使用，但当前并未在活跃态。    |
| FIXED_GROUP | 30   | 常用分组，定期使用，但不是每天使用。 |
| RARE_GROUP  | 40   | 极少使用分组，不经常使用。      |
| LIMITED_GROUP | 50   | 受限使用分组。            |
| NEVER_GROUP | 60   | 从未使用分组，安装但是从未运行过。  |