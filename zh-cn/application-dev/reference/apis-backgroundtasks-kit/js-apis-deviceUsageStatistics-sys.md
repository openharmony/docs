# @ohos.bundleState (设备使用信息统计)(系统接口)

本模块提供设备使用信息统计能力。

设备使用信息统计，系统应用可调用接口实现如下功能：

- 查询设备上各应用在不同时间段的使用时长、各应用的事件（前台、后台、长时任务开始、长时任务结束）信息及各应用的通知次数信息。
- 查询应用分组信息（仅限自身应用）。
- 查询应用空闲状态（其他应用和自身应用）。

> **说明：**
>
> 从API version9开始，该接口不再维护，推荐使用新接口[@ohos.resourceschedule.usageStatistics (设备使用信息统计)(系统接口)](js-apis-resourceschedule-deviceUsageStatistics-sys.md)
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口，其他公开接口请参见[@ohos.bundleState (设备使用信息统计)](js-apis-deviceUsageStatistics.md)。

## 导入模块

```js
import bundleState from '@ohos.bundleState'
```

## bundleState.queryBundleStateInfos

queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleActiveInfoResponse&gt;): void

通过指定起始和结束时间查询应用使用时长统计信息，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间，单位毫秒。                                   |
| end      | number                                   | 是    | 结束时间，单位毫秒。                                   |
| callback | AsyncCallback&lt;[BundleActiveInfoResponse](js-apis-deviceUsageStatistics.md#bundleactiveinforesponse)&gt; | 是    | 指定的callback回调方法。返回指定起始和结束时间内应用使用时长统计信息。 |

**示例**：

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

通过指定起始和结束时间查询应用使用时长统计信息，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，单位毫秒。 |
| end   | number | 是    | 结束时间，单位毫秒。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[BundleActiveInfoResponse](js-apis-deviceUsageStatistics.md#bundleactiveinforesponse)&gt; | 指定的Promise回调方法。返回指定起始和结束时间内应用使用时长统计信息。 |

**示例**：

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

通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| byInterval | [IntervalType](js-apis-deviceUsageStatistics.md#intervaltype)            | 是    | 查询类型。                                    |
| begin      | number                                   | 是    | 起始时间，单位毫秒。                                    |
| end        | number                                   | 是    | 结束时间，单位毫秒。                                    |
| callback   | AsyncCallback&lt;Array&lt;[BundleStateInfo](js-apis-deviceUsageStatistics.md#bundlestateinfo)&gt;&gt; | 是    | 指定的callback回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |

**示例**：

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

通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

| 参数名        | 类型                            | 必填   | 说明    |
| ---------- | ----------------------------- | ---- | ----- |
| byInterval | [IntervalType](js-apis-deviceUsageStatistics.md#intervaltype) | 是    | 查询类型。 |
| begin      | number                        | 是    | 起始时间，单位毫秒。 |
| end        | number                        | 是    | 结束时间，单位毫秒。 |

**返回值**：

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStateInfo](js-apis-deviceUsageStatistics.md#bundlestateinfo)&gt;&gt; | 指定的Promise回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |

**示例**：

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

通过指定起始和结束时间查询所有应用的事件集合，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间，单位毫秒。                                   |
| end      | number                                   | 是    | 结束时间，单位毫秒。                                   |
| callback | AsyncCallback&lt;Array&lt;[BundleActiveState](js-apis-deviceUsageStatistics.md#bundleactivestate)&gt;&gt; | 是    | 指定的callback回调方法。返回指定起始和结束时间查询所有应用的事件集合。 |

**示例**：

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

通过指定起始和结束时间查询所有应用的事件集合，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间，单位毫秒。 |
| end   | number | 是    | 结束时间，单位毫秒。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleActiveState](js-apis-deviceUsageStatistics.md#bundleactivestate)&gt;&gt; | 指定的Promise回调方法。返回指定起始和结束时间查询所有应用的事件集合。 |

**示例**：

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