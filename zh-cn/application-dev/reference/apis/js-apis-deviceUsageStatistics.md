# 设备使用信息统计

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import stats from '@ohos.bundleState'
```

## bundleState.isIdleState
isIdleState(bundleName: string, callback: AsyncCallback<boolean>): void

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **说明**：
判断指定bundleName的应用当前是否是空闲状态，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用的bundleName。|
  | callback | AsyncCallback<boolean> | 是 | 指定的callback回调方法。如果指定的bundleName有效，则返回指定bundleName的应用当前是否是空闲状态；否则返回null。 |

- **权限**：
无权限

- **示例**：

  ```
    stats.isIdleState("com.ohos.camera", (err, res) => {
        if(err.code === 0) {
            console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        } else {
            console.log('BUNDLE_ACTIVE isIdleState callback failed, because: ' + err.code);
        }
    });
  ```

## bundleState.isIdleState
isIdleState(bundleName: string): Promise<boolean>;

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **说明**：
判断指定bundleName的应用当前是否是空闲状态，使用Promise形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用的bundleName。|

- **返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise<boolean> | 指定的Promise回调方法。如果指定的bundleName有效，则返回指定bundleName的应用当前是否是空闲状态；否则返回null。 |

- **权限**：
无权限

- **示例**：

  ```
    stats.isIdleState("com.ohos.camera").then( res => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);
    });
  ```

## bundleState.queryAppUsagePriorityGroup
queryAppUsagePriorityGroup(callback: AsyncCallback<number>): void

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **说明**：
查询（返回）当前调用者应用的使用优先级群组，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback<number> | 是 | 指定的callback回调方法。返回当前调用者应用的使用优先级群组。|

- **权限**：
无权限

- **示例**：

  ```
    stats.queryAppUsagePriorityGroup((err, res) => {
        if(err.code === 0) {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback succeeded. result: ' + JSON.stringify(res));
        } else {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback failed. because: ' + err.code);
        }
    });
  ```

## bundleState.queryAppUsagePriorityGroup
queryAppUsagePriorityGroup(): Promise<number>

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **说明**：
查询（返回）当前调用者应用的使用优先级群组，使用Promise形式返回。

- **返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise<number> | 指定的Promise回调方法。查询（返回）当前调用者应用的使用优先级群组。|

- **权限**：
无权限

- **示例**：

  ```
    stats.queryAppUsagePriorityGroup().then( res => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise failed. because: ' + err.code);
    });
  ```

## bundleState.queryBundleStateInfos
queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback<BundleActiveInfoResponse>): void

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定起始和结束时间查询应用使用时长统计信息，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<BundleActiveInfoResponse> | 是 | 指定的callback回调方法。返回指定起始和结束时间内应用使用时长统计信息。|

- **权限**：
ohos.permission.BUNDLE_ACTIVE_INFO

- **示例**：

  ```
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

## bundleState.queryBundleStateInfos
queryBundleStateInfos(begin: number, end: number): Promise<BundleActiveInfoResponse>

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定起始和结束时间查询应用使用时长统计信息，使用Promise形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|

- **返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise<BundleActiveInfoResponse> | 指定的Promise回调方法。返回指定起始和结束时间内应用使用时长统计信息。|

- **权限**：
ohos.permission.BUNDLE_ACTIVE_INFO

- **示例**：

  ```
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
  ```

## bundleState.queryBundleStateInfoByInterval
queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback<Array<BundleStateInfo>>): void

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | byInterval | IntervalType | 是 | 查询类型。|
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<Array<BundleStateInfo>> | 是 | 指定的callback回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。|

- **权限**：
ohos.permission.BUNDLE_ACTIVE_INFO

- **示例**：

  ```
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

## bundleState.queryBundleStateInfoByInterval
queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise<Array<BundleStateInfo>>

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Promise形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | byInterval | IntervalType | 是 | 查询类型。|
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|

- **返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise<Array<BundleStateInfo>> | 指定的Promise回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。|

- **权限**：
ohos.permission.BUNDLE_ACTIVE_INFO

- **示例**：

  ```
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000).then( res => {
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
queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定起始和结束时间查询所有应用的事件集合，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<Array<BundleActiveState>> | 是 | 指定的callback回调方法。返回指定起始和结束时间查询所有应用的事件集合。|

- **权限**：
ohos.permission.BUNDLE_ACTIVE_INFO

- **示例**：

  ```
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

## bundleState.queryBundleActiveStates
queryBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定起始和结束时间查询所有应用的事件集合，使用Promise形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|

- **返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise<Array<BundleActiveState>> | 指定的Promise回调方法。返回指定起始和结束时间查询所有应用的事件集合。|

- **权限**：
ohos.permission.BUNDLE_ACTIVE_INFO

- **示例**：

  ```
    stats.queryBundleActiveStates(0, 20000000000000).then( res => {
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
queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定起始和结束时间查询当前应用的事件集合，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<Array<BundleActiveState>> | 是 | 指定的callback回调方法。返回指定起始和结束时间查询当前应用的事件集合。|

- **权限**：
无权限

- **示例**：

  ```
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

## bundleState.queryCurrentBundleActiveStates
queryCurrentBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>

- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **说明**：
通过指定起始和结束时间查询当前应用的事件集合，使用Promise形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|

- **返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise<Array<BundleActiveState>> | 指定的Promise回调方法。返回指定起始和结束时间查询当前应用的事件集合。|

- **权限**：
无权限

- **示例**：

  ```
    stats.queryCurrentBundleActiveStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise failed, because: ' + err.code);
    });
  ```

## bundleState.BundleStateInfo
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **参数**：

  提供应用使用时长的具体信息。

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名。|
  | abilityPrevAccessTime | number | 是 | 应用最后一次使用的时间。|
  | abilityInFgTotalTime | number | 是 | 应用在前台使用的总时间。|

## bundleState.BundleActiveState
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **参数**：

  提供应用事件的具体信息。

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名。|
  | stateType | number | 是 | 应用事件类型。|
  | stateOccurredTime | number | 是 | 应用事件发生的时间戳。|

## bundleState.BundleActiveInfoResponse
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **参数**：

  提供应用使用时长的具体信息。

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | [key: string]: BundleStateInfo | BundleStateInfo | 是 | 不同应用的使用时长统计信息。|

## bundleState.IntervalType
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **参数**：

  提供查询的类型

  |名称    |默认值    |说明|
  | -------- | -------- | -------- |
  | BY_OPTIMIZED | 0 | 表示系统自己判断最合适的查询类型（天、周、月、年）去查询指定时间段间隔的应用使用时长信息。|
  | BY_DAILY | 1 | 表示系统按照天去查询指定时间段间隔的应用使用时长信息。|
  | BY_WEEKLY | 2 | 表示系统按照周去查询指定时间段间隔的应用使用时长信息。|
  | BY_MONTHLY | 3 | 表示系统按照月去查询指定时间段间隔的应用使用时长信息。|
  | BY_ANNUALLY | 4 | 表示系统按照年去查询指定时间段间隔的应用使用时长信息。|