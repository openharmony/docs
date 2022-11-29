# 设备使用信息统计

本模块提供设备使用信息统计能力。

设备使用信息统计，系统应用可调用接口实现如下功能：

- 查询设备上各应用在不同时间段的使用时长、各应用的事件（前台、后台、长时任务开始、长时任务结束）信息及各应用的通知次数信息。
- 查询系统事件（休眠、唤醒、解锁、锁屏）统计信息。
- 查询应用分组信息（其他应用和自身应用）。
- 查询应用空闲状态（其他应用和自身应用）。
- 设置应用分组信息（其他应用）。
- 注册和解除注册应用分组变化监听。

三方应用可调用接口实现如下功能：

- 查询应用空闲状态（仅限自身应用）。
- 查询应用分组信息（仅限自身应用）。
- 查询应用事件（仅限自身应用）。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>


## 导入模块

```
import usageStatistics from '@ohos.resourceschedule.usageStatistics'
```

## usageStatistics.isIdleState

isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

判断指定bundleName的应用当前是否是空闲状态，三方应用只能查询自身的空闲状态，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型                           | 必填   | 说明                                       |
| ---------- | ---------------------------- | ---- | ---------------------------------------- |
| bundleName | string                       | 是    | 应用的bundleName。                           |
| callback   | AsyncCallback&lt;boolean&gt; | 是    | 指定的callback回调方法。如果指定的bundleName有效，则返回指定bundleName的应用当前是否是空闲状态；否则返回null。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                     |
| ---------- | ----------------------------     |
| 10000001   | Memory operation failed.         | 
| 10000002   | Parcel operation failed.         | 
| 10000003   | System service operation failed. | 
| 10000004   | IPC Communication failed.        | 
| 10000006   | Get application info failed.     |

**示例**：
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

判断指定bundleName的应用当前是否是空闲状态，三方应用只能查询自身的空闲状态，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名        | 类型     | 必填   | 说明             |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | 是    | 应用的bundleName。 |

**返回值**：

| 类型                     | 说明                                       |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | 指定的Promise回调方法。如果指定的bundleName有效，则返回指定bundleName的应用当前是否是空闲状态；否则返回null。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                     |
| ---------- | ----------------------------     |
| 10000001   | Memory operation failed.         | 
| 10000002   | Parcel operation failed.         | 
| 10000003   | System service operation failed. | 
| 10000004   | IPC Communication failed.        | 
| 10000006   | Get application info failed.     |

**示例**：

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

查询当前应用的优先级分组。使用Promise形式返回其应用分组。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**返回值**：

| 类型              | 说明                          |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回查询的应用分组结果。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**示例**：

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

查询当前应用的优先级分组。使用callback形式返回其应用分组。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**参数**：

| 参数名      | 类型                    | 必填   | 说明                         |
| -------- | --------------------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是    | 指定的CallBack回调方法。返回查询的应用分组。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**示例**：

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

通过指定起始和结束时间查询应用使用时长统计信息，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间。                                   |
| end      | number                                   | 是    | 结束时间。                                   |
| callback | AsyncCallback&lt;[BundleStatsMap](#bundlestatsmap)&gt; | 是    | 指定的callback回调方法。返回指定起始和结束时间内应用使用时长统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

通过指定起始和结束时间查询应用使用时长统计信息，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间。 |
| end   | number | 是    | 结束时间。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;[BundleStatsMap](#bundlestatsmap)&gt; | 指定的Promise回调方法。返回指定起始和结束时间内应用使用时长统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明                                       |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| byInterval | [IntervalType](#intervaltype)            | 是    | 查询类型。                                    |
| begin      | number                                   | 是    | 起始时间。                                    |
| end        | number                                   | 是    | 结束时间。                                    |
| callback   | AsyncCallback&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | 是    | 指定的callback回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名        | 类型                            | 必填   | 说明    |
| ---------- | ----------------------------- | ---- | ----- |
| byInterval | [IntervalType](#intervaltype) | 是    | 查询类型。 |
| begin      | number                        | 是    | 起始时间。 |
| end        | number                        | 是    | 结束时间。 |

**返回值**：

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt;&gt; | 指定的Promise回调方法。返回指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

通过指定起始和结束时间查询所有应用的事件集合，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间。                                   |
| end      | number                                   | 是    | 结束时间。                                   |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | 是    | 指定的callback回调方法。返回指定起始和结束时间查询所有应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

通过指定起始和结束时间查询所有应用的事件集合，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间。 |
| end   | number | 是    | 结束时间。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | 指定的Promise回调方法。返回指定起始和结束时间查询所有应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

通过指定起始和结束时间查询当前应用的事件集合，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| begin    | number                                   | 是    | 起始时间。                                   |
| end      | number                                   | 是    | 结束时间。                                   |
| callback | AsyncCallback&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | 是    | 指定的callback回调方法。返回指定起始和结束时间查询当前应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

通过指定起始和结束时间查询当前应用的事件集合，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间。 |
| end   | number | 是    | 结束时间。 |

**返回值**：

| 类型                                       | 说明                                     |
| ---------------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;[BundleEvents](#bundleevents)&gt;&gt; | 指定的Promise回调方法。返回指定起始和结束时间查询当前应用的事件集合。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

使用Promise形式返回不超过1000条FA使用记录，FA使用记录由近及远排序。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**返回值**：

| 类型                                       | 说明                                 |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | 指定的Promise回调方法。返回不超过1000条FA使用记录。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

  ```js
    // 无maxNum参数调用方式
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

查询FA使用记录。使用CallBack形式返回数量不超过1000条FA使用记录（FA记录按时间由近及远排序）。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | 是    | 指定的CallBack回调方法。返回不超过maxNum条FA使用记录。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       | 
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

据maxNum，查询FA使用记录，使用Promise形式返回不超过maxNum条FA使用记录，FA使用记录由近及远排序，maxNum最大为1000。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名    | 类型     | 必填   | 说明                                 |
| ------ | ------ | ---- | ---------------------------------- |
| maxNum | number | 是    | 返回条目的最大数量，最多支持1000条。 |

**返回值**：

| 类型                                       | 说明                                 |
| ---------------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | 指定的Promise回调方法。返回不超过maxNum条FA使用记录。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

查询FA使用记录。使用CallBack形式返回数量最大不超过maxNum设置的值，FA使用记录由近及远排序，maxNum最大为1000。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| maxNum   | number                                   | 是    | 返回FA记录的最大数量，maxNum最大为1000。|
| callback | AsyncCallback&lt;Array&lt;[HapModuleInfo](#hapmoduleinfo)&gt;&gt; | 是    | 指定的CallBack回调方法。返回不超过maxNum条FA使用记录。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          |  
| 10000006   | Get application info failed.       |
| 10000007   | Get system or actual time failed.  |

**示例**：

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

查询指定bundleName的应用的优先级分组。使用Promise形式返回其应用分组结果。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**参数**：

| 参数名        | 类型     | 必填   | 说明                                       |
| ---------- | ------ | ---- | ---------------------------------------- |
| bundleName | string | 是    | 查询指定bundleName的应用的优先级分组。 |

**返回值**：

| 类型              | 说明                          |
| --------------- | --------------------------- |
| Promise&lt;number&gt; | 指定的Promise回调方法。返回查询的应用分组结果。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**示例**：

```javascript
//有bundleName的promise
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

查询指定bundleName对应应用的分组。使用callback形式返回其应用分组。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**参数**：

| 参数名        | 类型                    | 必填   | 说明                                       |
| ---------- | --------------------- | ---- | ---------------------------------------- |
| bundleName | string                | 是    | 查询指定bundleName对应应用的分组。 |
| callback   | AsyncCallback&lt;number&gt; | 是    | 指定的CallBack回调方法。返回制指定bundleName的应用分组。|

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                       |
| ---------- | ----------------------------       |
| 10000001   | Memory operation failed.           | 
| 10000002   | Parcel operation failed.           | 
| 10000003   | System service operation failed.   | 
| 10000004   | IPC Communication failed.          | 
| 10000005   | Application is not installed.      | 
| 10000006   | Get application info failed.       |
| 10100002   | Get Application group info failed. |

**示例**：

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

将指定bundleName的应用的分组设置为newGroup，使用Promise形式返回设置是否成功。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**参数**：

| 参数名        | 类型        | 必填   | 说明   |
| ---------- | --------- | ---- | ---- |
| bundleName | string    | 是    | 应用名称 |
| newGroup   | [GroupType](#grouptype) | 是    | 应用分组 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed.          |
| 10100001   | Application group operation repeated. |

**返回值**：

| 类型            | 说明                        |
| ------------- | ------------------------- |
| Promise&lt;void&gt; | 指定的Promise回调方法。返回本次设置是否成功 |

**示例**：

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

将指定bundleName的应用的分组设置为newGroup，使用CallBack形式返回设置是否成功。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**参数**：

| 参数名        | 类型                  | 必填   | 说明                        |
| ---------- | ------------------- | ---- | ------------------------- |
| bundleName | string              | 是    | 应用名称                      |
| newGroup   | [GroupType](#grouptype)           | 是    | 应用分组                      |
| callback   | AsyncCallback&lt;void&gt; | 是    | 指定的CallBack回调方法。返回设置是否成功。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed.          |
| 10100001   | Application group operation repeated. |

**示例**：

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

应用注册分组变化监听，待用户名下的某个应用分组发生变化时，通过callback形式向所有已注册分组变化监听的应用返回[AppGroupCallbackInfo](#appgroupcallbackinfo)信息。使用Promise形式返回注册是否成功。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**参数**：

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | 是   | 指定的callback函数，返回应用分组变化的信息 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |

**返回值**：

| 类型            | 说明                      |
| ------------- | ----------------------- |
| Promise&lt;void&gt; | 指定的Promise回调方法。返回注册监听是否成功 |

**示例**：

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

应用注册分组变化监听，待用户名下的某个应用分组发生变化时，通过callback形式向所有已注册分组变化监听的应用返回[AppGroupCallbackInfo](#appgroupcallbackinfo)信息。使用异步callback形式返回注册监听是否成功。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**参数**：

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| groupCallback | Callback&lt;[AppGroupCallbackInfo](#appgroupcallbackinfo)&gt; | 是   | 指定的callback函数，返回应用分组变化的信息   |
| callback | AsyncCallback&lt;void&gt;                                    | 是   | 指定的异步callback函数，返回注册监听是否成功 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |


**示例**：

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

应用解除分组变化监听，解除通过调用注册接口生成的监听。使用Promise形式返回解除监听是否成功。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**返回值**：

| 类型            | 说明                       |
| ------------- | ------------------------ |
| Promise&lt;void&gt; | 指定的Promise回调方法。返回解除监听是否成功 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |

**示例**：

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

应用解除分组变化监听，解除通过调用注册接口生成的监听。使用异步callback形式返回解除监听是否成功。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

**参数**：

| 参数名      | 类型                  | 必填   | 说明             |
| -------- | ------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | 是    | 解除监听是否成功的异步回调函数 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10100001   | Application group operation repeated. |

**示例**：

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

通过指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间。 |
| end   | number | 是    | 结束时间。 |

**返回值**：

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | 指定的Promise回调方法。返回指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed           |
| 10000007   | Get system or actual time failed.     |

**示例**：

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

通过指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | 是    | 起始时间。                                    |
| end      | number                                   | 是    | 结束时间。                                    |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | 是    | 指定的callback回调方法。返回指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed.           |
| 10000007   | Get system or actual time failed.     |

**示例**：

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

通过指定起始和结束时间查询所有应用的通知次数信息，使用Promise形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| begin | number | 是    | 起始时间。 |
| end   | number | 是    | 结束时间。 |

**返回值**：

| 类型                                       | 说明                                       |
| ---------------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | 指定的Promise回调方法。返回指定起始和结束时间查询所有应用的通知次数信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          |
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed.          |
| 10000007   | Get system or actual time failed.     |

**示例**：

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

通过指定起始和结束时间查询所有应用的通知次数信息，使用Callback形式返回。

**需要权限**：ohos.permission.BUNDLE_ACTIVE_INFO

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

**参数**：

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| begin    | number                                   | 是    | 起始时间。                                    |
| end      | number                                   | 是    | 结束时间。                                    |
| callback | AsyncCallback&lt;Array&lt;[DeviceEventStats](#deviceeventstats)&gt;&gt; | 是    | 指定的callback回调方法。返回通过指定起始和结束时间查询所有应用的通知次数信息。 |

**错误码**：

以下错误码的详细介绍请参见[设备信息使用统计错误码](../errorcodes/errcode-DeviceUsageStatistics.md)。

| 错误码ID        | 错误信息                          |
| ---------- | ----------------------------          | 
| 10000001   | Memory operation failed.              | 
| 10000002   | Parcel operation failed.              | 
| 10000003   | System service operation failed.      | 
| 10000004   | IPC Communication failed.             | 
| 10000006   | Get application info failed           |
| 10000007   | Get system or actual time failed.     |

**示例**：

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
FA的使用信息的属性集合。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

| 名称                  | 类型                                       | 必填   | 说明                            |
| -------------------- | ---------------------------------------- | ---- | ----------------------------- |
| deviceId             | string                                   | 否    | FA所属deviceId。                 |
| bundleName           | string                                   | 是    | FA所属应用包名。                     |
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
FA卡片的使用信息的属性集合。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

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

**系统API**：此接口为系统接口。

| 名称           | 类型   | 必填 | 说明             |
| ---------------- | ------ | ---- | ---------------- |
| appOldGroup | number | 是   | 变化前的应用分组 |
| appNewGroup | number | 是   | 变化后的应用分组 |
| userId           | number | 是   | 用户id           |
| changeReason     | number | 是   | 分组变化原因     |
| bundleName       | string | 是   | 应用名称         |

## BundleStatsInfo

提供应用使用时长的具体信息。

### 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

| 名称                      | 类型     | 必填   | 说明                                       |
| ------------------------ | ------ | ---- | ---------------------------------------- |
| bundleName               | string | 是    | 应用包名。                                    |
| abilityPrevAccessTime    | number | 是    | 应用最后一次使用的时间。                             |
| abilityInFgTotalTime     | number | 是    | 应用在前台使用的总时间。                             |
| id                       | number | 否    | 用户id。 |
| abilityPrevSeenTime      | number | 否    | 应用最后一次在前台可见的时间。 |
| abilitySeenTotalTime     | number | 否    | 应用在前台可见的总时间。 |
| fgAbilityAccessTotalTime | number | 否    | 应用访问前台的总时间。 |
| fgAbilityPrevAccessTime  | number | 否    | 应用最后一次访问前台的时间。|
| infosBeginTime           | number | 否    | BundleActiveInfo对象中第一条应用使用统计的记录时间。 |
| infosEndTime             | number | 否    | BundleActiveInfo对象中最后一条应用使用统计的记录时间。 |

## BundleEvents

提供应用事件的具体信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

| 名称                   | 类型     | 必填   | 说明                                       |
| --------------------- | ------ | ---- | ---------------------------------------- |
| bundleName            | string | 是    | 应用包名。                                    |
| eventId             | number | 是    | 应用事件类型。                                  |
| eventOccurredTime     | number | 是    | 应用事件发生的时间戳。                              |
| appGroup | number | 否    | 应用程序的使用优先级组。|
| indexOfLink           | string | 否    | 快捷方式id。|
| nameOfClass           | string | 否    | 类名。|

## BundleStatsMap

提供应用使用时长的具体信息。

**系统能力**：SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

| 参数名                            | 类型                                       | 必填   | 说明             |
| ------------------------------ | ---------------------------------------- | ---- | -------------- |
| [key: string]: BundleStatsInfo | [key: string]: [BundleStatsInfo](#bundlestatsinfo) | 是    | 不同应用的使用时长统计信息。 |

## DeviceEventStats

提供通知、系统事件的统计信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

| 名称     | 类型     | 必填   | 说明                |
| ------- | ------ | ---- | ----------------- |
| name    | string | 是    | 通知应用包名或者系统事件名。    |
| eventId | number | 是    | 通知、系统事件类型。        |
| count   | number | 是    | 应用通知次数或者系统事件触发次数。 |

## IntervalType

提供应用使用时长的查询类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.App

**系统API**：此接口为系统接口。

| 名称           | 值  | 说明                                       |
| ------------ | ---- | ---------------------------------------- |
| BY_OPTIMIZED | 0    | 表示系统自行判断最合适的查询类型（天、周、月、年）去查询指定时间段间隔的应用使用时长信息。 |
| BY_DAILY     | 1    | 表示系统按照天去查询指定时间段间隔的应用使用时长信息。              |
| BY_WEEKLY    | 2    | 表示系统按照周去查询指定时间段间隔的应用使用时长信息。              |
| BY_MONTHLY   | 3    | 表示系统按照月去查询指定时间段间隔的应用使用时长信息。              |
| BY_ANNUALLY  | 4    | 表示系统按照年去查询指定时间段间隔的应用使用时长信息。              |

## GroupType

提供应用分组的设置类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

**系统API**：此接口为系统接口。

| 名称                 | 值  | 说明                |
| ------------------ | ---- | ----------------- |
| ALIVE_GROUP | 10   | 活跃分组。              |
| DAILY_GROUP | 20   | 经常使用，但当前并未在活跃态。    |
| FIXED_GROUP | 30   | 常用分组，定期使用，但不是每天使用。 |
| RARE_GROUP  | 40   | 极少使用分组，不经常使用。      |
| LIMITED_GROUP | 50   | 受限使用分组。            |
| NEVER_GROUP | 60   | 从未使用分组，安装但是从未运行过。  |