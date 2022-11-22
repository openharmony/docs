# 设备使用信息统计(API9)

## 场景介绍

设备使用信息统计，包括app usage/notification usage/system usage等使用统计。例如应用使用信息统计，用于保存和查询应用使用详情（app usage）、事件日志数据（event log）、应用分组（app group）情况。
部件缓存的应用记录（使用历史统计和使用事件记录）会在事件上报后30分钟内刷新到数据库持久化保存。

## 接口说明
注册相关接口包导入：
```js
import usageStatistics from '@ohos.resourceschedule.usageStatistics';
```

**表1** 设备使用信息统计主要接口

| 接口名 | 描述 |
| -------- | -------- |
| function queryBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | 通过指定起始和结束时间查询所有应用的事件集合。 |
| function queryBundleStatsInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleStatsMap&gt;): void | 通过指定起始和结束时间查询应用使用时长统计信息。 |
| function queryCurrentBundleEvents(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleEvents&gt;&gt;): void | 通过指定起始和结束时间查询当前应用的事件集合。 |
| function queryBundleStatsInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStatsInfo&gt;&gt;): void | 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |
| function queryAppGroup(callback: AsyncCallback&lt;number&gt;): void | 查询当前应用的使用优先级群组。callback形式。 |
| function queryAppGroup(): Promise&lt;number&gt;; | 查询当前应用的使用优先级群组。promise形式。 |
| function queryAppGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void | 查询指定应用的使用优先级群组。callback形式。 |
| function queryAppGroup(bundleName : string): Promise&lt;number&gt;; | 查询当前调用者应用或者指定应用的使用优先级群组。promise形式。 |
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | 判断指定Bundle Name的应用当前是否是空闲状态。 |
| function queryModuleUsageRecords(callback: AsyncCallback&lt;HapModuleInfo&gt;): void | 查询FA使用记录，返回不超过1000条FA使用记录。 |
| function queryModuleUsageRecords(maxNum: number, callback: AsyncCallback&lt;HapModuleInfo&gt;): void | 根据maxNum，查询FA使用记录，返回不超过maxNum条FA使用记录。 maxNum不超过1000|
| function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | 通过指定起始和结束时间查询所有应用的通知次数。 |
| function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | 通过指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息。 |
| function setAppGroup(bundleName : string, newGroup: GroupType, callback: AsyncCallback&gt;boolean&gt;): void | 给应用名是bundleName的应用分组设置成newGroup，返回设置结果是否成功，以callback形式返回。 |
| function setAppGroup(bundleName : string, newGroup : GroupType): Promise&gt;boolean&gt;; | 给应用名是bundleName的应用分组设置成newGroup，返回设置结果是否成功，以promise形式返回。 |
| function registerAppGroupCallBack(groupCallback: Callback&gt;AppGroupCallbackInfo&gt;, callback: AsyncCallback&gt;boolean&gt;): void | 注册应用分组变化监听回调，返回注册是否成功，当应用分组发生变化时，会给所有已注册的监听者返回回调信息，以callback形式返回。 |
| function registerAppGroupCallBack(groupCallback: Callback&gt;AppGroupCallbackInfo&gt;): Promise&gt;boolean&gt;; | 注册应用分组变化监听回调，返回注册是否成功，当应用分组发生变化时，会给所有已注册的监听者返回回调信息，以promise形式返回。 |
| function unregisterAppGroupCallBack(callback: AsyncCallback&gt;boolean&gt;): void | 解除应用分组监听回调，以callback形式返回。 |
| function unregisterAppGroupCallBack(): Promise&gt;boolean&gt;; | 解除应用分组监听回调，以promise形式返回。 |

## 开发步骤

1. 获取设备使用信息之前，需要检查是否已经配置请求相应的权限。
    系统提供的设备使用信息统计的权限是ohos.permission.BUNDLE_ACTIVE_INFO
    具体配置方式请参考[权限申请声明](../security/accesstoken-guidelines.md)

2. 通过指定起始和结束时间查询所有应用的事件集合，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
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

    // 异步方法callback方式
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

3. 通过指定起始和结束时间查询应用使用时长统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
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

    // 异步方法callback方式
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

4. 通过指定起始和结束时间查询当前应用的事件集合，不需要配置权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
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

    // 异步方法callback方式
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

5. 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
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

    // 异步方法callback方式
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

6. 查询当前应用的使用优先级群组，不需要配置权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // promise方式
    try{
        usageStatistics.queryAppGroup().then( res => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
        }).catch( err => {
            console.log('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE queryAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // callback方式
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

7. 判断指定Bundle Name的应用当前是否是空闲状态，不需要配置权限，三方应用只能查询自身的空闲状态。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
    try{
        usageStatistics.isIdleState("com.ohos.camera").then( res => {
            console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
        }).catch( err => {
            console.log('BUNDLE_ACTIVE isIdleState promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE isIdleState throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // 异步方法callback方式
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

8. 查询FA使用记录。返回数量最大不超过maxNum设置的值，若不传入maxNum参数，则默认maxNum为1000, 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
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

    // 无maxNum参数异步方法promise方式
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

    // 异步方法callback方式
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

    // 无maxNum参数异步方法callback方式
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

9. 通过指定起始和结束时间查询所有应用的通知次数，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
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

    // 异步方法callback方式
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

10. 通过指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise方式
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

    // 异步方法callback方式
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

11. 查询指定bundleName的应用的使用优先级群组，返回查询的优先级分组结果，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

     ```js
     import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 有bundleName异步promise方式
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

     // 有bundleName异步方法callback方式
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

12. 给指定bundleName的应用的优先级分组设置成newGroup。 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```javascript
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = bundleState.GroupType.ACTIVE_GROUP_DAILY;

    try{
        usageStatistics.setAppGroup(bundleName, newGroup).then( () => {
            console.log('BUNDLE_ACTIVE setAppGroup promise succeeded.');
        }).catch( err => {
            console.log('BUNDLE_ACTIVE setAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE setAppGroup throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // 异步方法callback
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = bundleState.GroupType.ACTIVE_GROUP_DAILY;

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

13. 注册应用分组变化监听回调，返回注册是否成功，当应用分组发生变化时，会给所有已注册的监听者返回回调信息， 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限

    ```javascript
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // 异步方法promise形式
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

    // 异步方法callback形式
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

14. 解除应用分组监听回调， 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```javascript
    import usageStatistics from '@ohos.resourceschedule.usageStatistics'

    // promise
    try{
        usageStatistics.unregisterAppGroupCallBack().then( () => {
            console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise succeeded.');
        }).catch( err => {
            console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
        });
    } catch (error) {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack throw error, code is: ' + error.code + ',message is: ' + error.message);
    }

    // callback
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
## 相关实例
针对设备使用信息统计，有以下相关实例可供参考：
- [`DeviceUsageStatistics`：设备使用信息统计（eTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/device/DeviceUsageStatistics)

