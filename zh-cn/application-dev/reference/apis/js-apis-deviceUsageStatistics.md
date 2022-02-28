# 设备使用信息统计

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import stats from '@ohos.usagestatskit'
```

## usagestatskit.isIdleState
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **接口**：
isIdleState(bundleName: string, callback: AsyncCallback<boolean>): void

- **说明**：
判断指定bundleName的应用当前是否是空闲状态，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用的bundleName。|
  | callback | AsyncCallback<boolean> | 是 | 指定的callback回调方法。如果指定的bundleName有效，则返回指定bundleName的应用当前是否是空闲状态；否则返回null。 |


- **示例**：

  ```
    stats.isIdleState("com.ohos.camera", (err, res) => {
        if(err.data === 0) {
            console.log('isIdleState callback succeeded, result: ' + JSON.stringify(res));
        } else {
            console.log('isIdleState callback failed, because: ' + err.data);
        }
    });
  ```

## usagestatskit.isIdleState
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **接口**：
isIdleState(bundleName: string): Promise<boolean>;

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

- **示例**：

  ```
    stats.isIdleState("com.ohos.camera").then( res => {
        console.log('isIdleState callback succeeded, result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('isIdleState callback failed, because: ' + err.data);
    });
  ```

## usagestatskit.queryAppUsagePriorityGroup
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **接口**：
queryAppUsagePriorityGroup(callback: AsyncCallback<number>): void

- **说明**：
查询（返回）当前调用者应用的使用优先级群组，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback<number> | 是 | 指定的callback回调方法。返回当前调用者应用的使用优先级群组。|

- **示例**：

  ```
    stats.queryAppUsagePriorityGroup((err, res) => {
        if(err.data === 0) {
            console.log('queryAppUsagePriorityGroup callback succeeded. result: ' + JSON.stringify(res));
        } else {
            console.log('queryAppUsagePriorityGroup callback failed. because: ' + err.data);
        }
    });
  ```

## usagestatskit.queryAppUsagePriorityGroup
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

- **接口**：
queryAppUsagePriorityGroup(): Promise<number>

- **说明**：
查询（返回）当前调用者应用的使用优先级群组，使用Promise形式返回。

- **返回值**：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise<number> | 指定的Promise回调方法。查询（返回）当前调用者应用的使用优先级群组。|

- **示例**：

  ```
    stats.queryAppUsagePriorityGroup().then( res => {
        console.log('queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('queryAppUsagePriorityGroup promise failed. because: ' + err.data);
    });
  ```

## usagestatskit.queryBundleStateInfos
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback<BundleActiveInfoResponse>): void

- **说明**：
通过指定起始和结束时间查询应用使用时长统计信息，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<BundleActiveInfoResponse> | 是 | 指定的callback回调方法。返回指定起始和结束时间内应用使用时长统计信息。|

- **示例**：

  ```
    stats.queryBundleStateInfos(0, 20000000000000, (err, res) => {
        console.log('queryBundleStateInfos callback succeeded, data number: ' + res.length);
        if(err.data == 0) {
            for(let key in res){
                console.log("queryBundleStateInfos callback key = " + key)
                console.log("queryBundleStateInfos callback bundleName = " + res[key].bundleName)
                console.log("queryBundleStateInfos callback abilityPrevAccessTime = " + res[key].abilityPrevAccessTime)
                console.log("queryBundleStateInfos callback abilityInFgTotalTime = " + res[key].abilityInFgTotalTime)
            }
        } else {
            console.log('queryBundleStateInfos callback failed, because: ' + err.data);
        }
    });
  ```

## usagestatskit.queryBundleStateInfos
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryBundleStateInfos(begin: number, end: number): Promise<BundleActiveInfoResponse>

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

- **示例**：

  ```
    stats.queryBundleStateInfos(0, 20000000000000).then( res => {
        console.log('queryBundleStateInfos promise succeeded, data number: ' + res.length);
        for(let key in res){
            console.log("queryBundleStateInfos promise key = " + key)
            console.log("queryBundleStateInfos promise bundleName = " + res[key].bundleName)
            console.log("queryBundleStateInfos promise abilityPrevAccessTime = " + res[key].abilityPrevAccessTime)
            console.log("queryBundleStateInfos promise abilityInFgTotalTime = " + res[key].abilityInFgTotalTime)
        }
    }).catch( err => {
        console.log('queryBundleStateInfos promise failed, because: ' + err.data);
    });
  ```

## usagestatskit.queryBundleStateInfoByInterval
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback<Array<BundleStateInfo>>): void

- **说明**：
通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | byInterval | IntervalType | 是 | 查询类型。|
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<Array<BundleStateInfo>> | 是 | 指定的callback回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。|

- **示例**：

  ```
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000, (err, res) => {
        console.log('queryBundleStateInfoByInterval callback succeeded, data number: ' + res.length);
        if(err.data == 0) {
            for (let i = 0; i < res.length; i++) {
                console.log("queryBundleStateInfoByInterval, callback bundleName = " + res[i].bundleName)
                console.log("queryBundleStateInfoByInterval, callback abilityPrevAccessTime = " + res[i].abilityPrevAccessTime)
                console.log("queryBundleStateInfoByInterval, callback abilityInFgTotalTime = " + res[i].abilityInFgTotalTime)
            }
        } else {
            console.log('queryBundleStateInfoByInterval callback failed, because: ' + err.data);
        }
    });
  ```

## usagestatskit.queryBundleStateInfoByInterval
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number): Promise<Array<BundleStateInfo>>

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

- **示例**：

  ```
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000).then( res => {
        console.log('queryBundleStateInfoByInterval promise succeeded, data number: ' + res.length);
        for (let i = 0; i < res.length; i++) {
            console.log("queryBundleStateInfoByInterval, promise bundleName = " + res[i].bundleName)
            console.log("queryBundleStateInfoByInterval, promise abilityPrevAccessTime = " + res[i].abilityPrevAccessTime)
            console.log("queryBundleStateInfoByInterval, promise abilityInFgTotalTime = " + res[i].abilityInFgTotalTime)
        }
    }).catch( err => {
        console.log('queryBundleStateInfoByiInterval promise failed, because: ' + err.data);
    });
  ```

## usagestatskit.queryBundleActiveStates
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void

- **说明**：
通过指定起始和结束时间查询所有应用的事件集合，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<Array<BundleActiveState>> | 是 | 指定的callback回调方法。返回指定起始和结束时间查询所有应用的事件集合。|

- **示例**：

  ```
    stats.queryBundleActiveStates(0, 20000000000000, (err, res) => {
        console.log('queryBundleActiveStates callback succeeded, data number: ' + res.length);
        if(err.data == 0) {
            for (let i = 0; i < res.length; i++) {
                console.log("queryBundleActiveStates, callback bundleName = " + res[i].bundleName)
                console.log("queryBundleActiveStates, callback stateType = " + res[i].stateType)
                console.log("queryBundleActiveStates, callback stateOccurredTime = " + res[i].stateOccurredTime)
            }
        } else {
            console.log('queryBundleActiveStates callback failed, because: ' + err.data);
        }
    });
  ```

## usagestatskit.queryBundleActiveStates
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>

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

- **示例**：

  ```
    stats.queryBundleActiveStates(0, 20000000000000).then( res => {
        console.log('queryBundleActiveStates promise succeeded, data number: ' + res.length);
        for (let i = 0; i < res.length; i++) {
            console.log("queryBundleActiveStates, promise bundleName = " + res[i].bundleName)
            console.log("queryBundleActiveStates, promise stateType = " + res[i].stateType)
            console.log("queryBundleActiveStates, promise stateOccurredTime = " + res[i].stateOccurredTime)
        }
    }).catch( err => {
        console.log('queryBundleActiveStates promise failed, because: ' + err.data);
    });
  ```

## usagestatskit.queryCurrentBundleActiveStates
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback<Array<BundleActiveState>>): void

- **说明**：
通过指定起始和结束时间查询当前应用的事件集合，使用Callback形式返回。

- **参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | begin | number | 是 | 起始时间。|
  | end | number | 是 | 结束时间。|
  | callback | AsyncCallback<Array<BundleActiveState>> | 是 | 指定的callback回调方法。返回指定起始和结束时间查询当前应用的事件集合。|

- **示例**：

  ```
    stats.queryCurrentBundleActiveStates(0, 20000000000000,(err, res) => {
        console.log('queryCurrentBundleActiveStates callback succeeded, data number: ' + res.length);
        if(err.data == 0) {
            for (let i = 0; i < res.length; i++) {
                console.log("queryCurrentBundleActiveStates, callback bundleName = " + res[i].bundleName)
                console.log("queryCurrentBundleActiveStates, callback stateType = " + res[i].stateType)
                console.log("queryCurrentBundleActiveStates, callback stateOccurredTime = " + res[i].stateOccurredTime)
            }
        } else {
            console.log('queryCurrentBundleActiveStates callback failed, because: ' + err.data);
        }
    });
  ```

## usagestatskit.queryCurrentBundleActiveStates
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

- **接口**：
queryCurrentBundleActiveStates(begin: number, end: number): Promise<Array<BundleActiveState>>

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

- **示例**：

  ```
    stats.queryCurrentBundleActiveStates(0, 20000000000000).then( res => {
        console.log('queryCurrentBundleActiveStates promise succeeded, data number: ' + res.length);
        for (let i = 0; i < res.length; i++) {
            console.log("queryCurrentBundleActiveStates, promise bundleName = " + res[i].bundleName)
            console.log("queryCurrentBundleActiveStates, promise stateType = " + res[i].stateType)
            console.log("queryCurrentBundleActiveStates, promise stateOccurredTime = " + res[i].stateOccurredTime)
        }
    }).catch( err => {
        console.log('queryCurrentBundleActiveStates promise failed, because: ' + err.data);
    });
  ```

## usagestatskit.BundleStateInfo
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

提供应用使用时长的具体信息。

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名。|
  | abilityPrevAccessTime | number | 是 | 应用最后一次使用的时间。|
  | abilityInFgTotalTime | number | 是 | 应用在前台使用的总时间。|

## usagestatskit.BundleActiveState
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

提供应用事件的具体信息。

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名。|
  | stateType | number | 是 | 应用事件类型。|
  | stateOccurredTime | number | 是 | 应用事件发生的时间戳。|

## usagestatskit.BundleActiveInfoResponse
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

提供应用使用时长的具体信息。

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | [key: string]: BundleStateInfo | BundleStateInfo | 是 | 不同应用的使用时长统计信息。|

## usagestatskit.IntervalType
- **系统能力**：
SystemCapability.ResourceSchedule.UsageStatistics.App

触发工作的网络类型。

  |名称    |默认值    |说明|
  | -------- | -------- | -------- |
  | BY_OPTIMIZED | 0 | 表示系统自己判断最合适的查询类型（天、周、月、年）去查询指定时间段间隔的应用使用时长信息。|
  | BY_DAILY | 1 | 表示系统按照天去查询指定时间段间隔的应用使用时长信息。|
  | BY_WEEKLY | 2 | 表示系统按照周去查询指定时间段间隔的应用使用时长信息。|
  | BY_MONTHLY | 3 | 表示系统按照月去查询指定时间段间隔的应用使用时长信息。|
  | BY_ANNUALLY | 4 | 表示系统按照年去查询指定时间段间隔的应用使用时长信息。|