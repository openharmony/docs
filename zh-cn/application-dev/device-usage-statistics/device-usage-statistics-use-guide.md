# 设备使用信息统计开发指导

## 场景介绍

设备使用信息统计，包括app usage/notification usage/system usage等使用统计。例如应用使用信息统计，用于保存和查询应用使用详情（app usage）、事件日志数据（event log）、应用分组（app group）情况。
部件缓存的应用记录（使用历史统计和使用事件记录）会在事件上报后30分钟内刷新到数据库持久化保存。

## 接口说明
注册相关接口包导入：
```ts
import { usageStatistics } from '@kit.BackgroundTasksKit'
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
|function queryAppGroupSync(): number; | 查询当前应用的使用优先级群组。同步接口。|
| function queryAppGroup(bundleName : string, callback: AsyncCallback&lt;number&gt;): void | 查询指定应用的使用优先级群组。callback形式。 |
| function queryAppGroup(bundleName : string): Promise&lt;number&gt;; | 查询当前调用者应用或者指定应用的使用优先级群组。promise形式。 |
|function queryAppGroupSync(bundleName: string): number; |  查询当前调用者应用或者指定应用的使用优先级群组。同步接口。|
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | 判断指定Bundle Name的应用当前是否是空闲状态。 |
|function isIdleStateSync(bundleName: string): boolean; | 判断指定Bundle Name的应用当前是否是空闲状态，同步接口。 |
| function queryModuleUsageRecords(callback: AsyncCallback&lt;HapModuleInfo&gt;): void | 查询FA使用记录，返回不超过1000条FA使用记录。 |
| function queryModuleUsageRecords(maxNum: number, callback: AsyncCallback&lt;HapModuleInfo&gt;): void | 根据maxNum，查询FA使用记录，返回不超过maxNum条FA使用记录。 maxNum不超过1000|
| function queryNotificationEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | 通过指定起始和结束时间查询所有应用的通知次数。 |
| function queryDeviceEventStats(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;DeviceEventStats&gt;&gt;): void | 通过指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息。 |
| function setAppGroup(bundleName : string, newGroup: GroupType, callback: AsyncCallback&lt;void&gt;): void | 给应用名是bundleName的应用分组设置成newGroup，返回设置结果是否成功，以callback形式返回。 |
| function setAppGroup(bundleName : string, newGroup : GroupType): Promise&lt;void&gt;; | 给应用名是bundleName的应用分组设置成newGroup，返回设置结果是否成功，以promise形式返回。 |
| function registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;, callback: AsyncCallback&lt;void&gt;): void | 注册应用分组变化监听回调，返回注册是否成功，当应用分组发生变化时，会给所有已注册的监听者返回回调信息，以callback形式返回。 |
| function registerAppGroupCallBack(groupCallback: Callback&lt;AppGroupCallbackInfo&gt;): Promise&lt;void&gt;; | 注册应用分组变化监听回调，返回注册是否成功，当应用分组发生变化时，会给所有已注册的监听者返回回调信息，以promise形式返回。 |
| function unregisterAppGroupCallBack(callback: AsyncCallback&lt;void&gt;): void | 解除应用分组监听回调，以callback形式返回。 |
| function unregisterAppGroupCallBack(): Promise&lt;void&gt;; | 解除应用分组监听回调，以promise形式返回。 |

## 开发步骤

1. 获取设备使用信息之前，需要检查是否已经配置请求相应的权限。
    系统提供的设备使用信息统计的权限是ohos.permission.BUNDLE_ACTIVE_INFO
    具体配置方式请参考[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

2. 通过指定起始和结束时间查询所有应用的事件集合，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.queryBundleEvents(0, 20000000000000).then( (res : Array<usageStatistics.BundleEvents>) => {
        console.log('BUNDLE_ACTIVE queryBundleEvents promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleEvents promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleEvents promise result ' + JSON.stringify(res[i]));
        }
    }).catch((err : BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式
    usageStatistics.queryBundleEvents(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.BundleEvents>) => {
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

3. 通过指定起始和结束时间查询应用使用时长统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.queryBundleStatsInfos(0, 20000000000000).then( (res : usageStatistics.BundleStatsMap) => {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos promise success.');
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryBundleStatsInfos promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式
    usageStatistics.queryBundleStatsInfos(0, 20000000000000, (err : BusinessError, res : usageStatistics.BundleStatsMap) => {
        if (err) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback success.');
        console.log('BUNDLE_ACTIVE queryBundleStatsInfos callback result ' + JSON.stringify(res));
        }
    });
    ```

4. 通过指定起始和结束时间查询当前应用的事件集合，不需要配置权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.queryCurrentBundleEvents(0, 20000000000000).then( (res : Array<usageStatistics.BundleEvents>) => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise success.');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryCurrentBundleEvents promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryCurrentBundleEvents promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式
    usageStatistics.queryCurrentBundleEvents(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.BundleEvents>) => {
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

5. 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000).then( (res : Array<usageStatistics.BundleStatsInfo>) => {
    console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryBundleStatsInfoByInterval promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式

    usageStatistics.queryBundleStatsInfoByInterval(0, 0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.BundleStatsInfo>) => {
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

6. 查询当前应用的使用优先级群组，不需要配置权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // promise方式
    usageStatistics.queryAppGroup().then( (res : number) => {
        console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // callback方式
    usageStatistics.queryAppGroup((err : BusinessError, res : number) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
            console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });

    //同步方式
    let priorityGroup = usageStatistics.queryAppGroupSync();

    ```

7. 判断指定Bundle Name的应用当前是否是空闲状态，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.isIdleState("com.ohos.camera").then( (res : boolean) => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE isIdleState promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式
    usageStatistics.isIdleState("com.ohos.camera", (err : BusinessError, res : boolean) => {
        if (err) {
        console.log('BUNDLE_ACTIVE isIdleState callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        }
    });

    //同步方式
    let isIdleState = usageStatistics.isIdleStateSync("com.ohos.camera");
    ```

8. 查询FA使用记录。返回数量最大不超过maxNum设置的值，若不传入maxNum参数，则默认maxNum为1000, 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.queryModuleUsageRecords(1000).then( (res : Array<usageStatistics.HapModuleInfo>) => {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 无maxNum参数异步方法promise方式
    usageStatistics.queryModuleUsageRecords().then( (res : Array<usageStatistics.HapModuleInfo>) => {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise succeeded');
        for (let i = 0; i < res.length; i++) {
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise number : ' + (i + 1));
        console.log('BUNDLE_ACTIVE queryModuleUsageRecords promise result ' + JSON.stringify(res[i]));
        }
    }).catch( (err : BusinessError)=> {
        console.error('BUNDLE_ACTIVE queryModuleUsageRecords promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式
    usageStatistics.queryModuleUsageRecords(1000, (err : BusinessError, res : Array<usageStatistics.HapModuleInfo>) => {
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

    // 无maxNum参数异步方法callback方式
    usageStatistics.queryModuleUsageRecords((err : BusinessError, res : Array<usageStatistics.HapModuleInfo>) => {
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

9. 通过指定起始和结束时间查询所有应用的通知次数，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.queryNotificationEventStats(0, 20000000000000).then( (res : Array<usageStatistics.DeviceEventStats>) => {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats promise success.');
        console.log('BUNDLE_ACTIVE queryNotificationEventStats promise result ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryNotificationEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式
    usageStatistics.queryNotificationEventStats(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.DeviceEventStats>) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryNotificationEventStats callback success.');
        console.log('BUNDLE_ACTIVE queryNotificationEventStats callback result ' + JSON.stringify(res));
        }
    });
    ```

10. 通过指定起始和结束时间查询系统事件（休眠、唤醒、解锁、锁屏）统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise方式
    usageStatistics.queryDeviceEventStats(0, 20000000000000).then( (res : Array<usageStatistics.DeviceEventStats>) => {
        console.log('BUNDLE_ACTIVE queryDeviceEventStates promise success.');
        console.log('BUNDLE_ACTIVE queryDeviceEventStates promise result ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryDeviceEventStats promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback方式
    usageStatistics.queryDeviceEventStats(0, 20000000000000, (err : BusinessError, res : Array<usageStatistics.DeviceEventStats>) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryDeviceEventStats callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryDeviceEventStats callback success.');
        console.log('BUNDLE_ACTIVE queryDeviceEventStats callback result ' + JSON.stringify(res));
        }
    });
    ```

11. 查询指定bundleName的应用的使用优先级群组，返回查询的优先级分组结果，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

     ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 有bundleName异步promise方式
    let bundleName = "com.ohos.camera";
    usageStatistics.queryAppGroup(bundleName).then( (res : number) => {
        console.log('BUNDLE_ACTIVE queryAppGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE queryAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 有bundleName异步方法callback方式
    let bundleName = "com.ohos.camera";
    usageStatistics.queryAppGroup(bundleName, (err : BusinessError, res : number) => {
        if(err) {
        console.log('BUNDLE_ACTIVE queryAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE queryAppGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });
     ```

12. 给指定bundleName的应用的优先级分组设置成newGroup。 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;

    usageStatistics.setAppGroup(bundleName, newGroup).then( () => {
        console.log('BUNDLE_ACTIVE setAppGroup promise succeeded.');
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE setAppGroup promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback
    let bundleName = "com.example.deviceUsageStatistics";
    let newGroup = usageStatistics.GroupType.DAILY_GROUP;
    usageStatistics.setAppGroup(bundleName, newGroup, (err : BusinessError) => {
        if(err) {
        console.log('BUNDLE_ACTIVE setAppGroup callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE setAppGroup callback succeeded.');
        }
    });
    ```

13. 注册应用分组变化监听回调，返回注册是否成功，当应用分组发生变化时，会给所有已注册的监听者返回回调信息， 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // 异步方法promise形式
    function  onBundleGroupChanged (res : usageStatistics.AppGroupCallbackInfo) {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack RegisterGroupCallBack callback success.');
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    usageStatistics.registerAppGroupCallBack(onBundleGroupChanged).then( () => {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack promise succeeded.');
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE registerAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // 异步方法callback形式
    function onBundleGroupChanged (res : usageStatistics.AppGroupCallbackInfo) {
    console.log('BUNDLE_ACTIVE onBundleGroupChanged RegisterGroupCallBack callback success.');
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appOldGroup is : ' + res.appOldGroup);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result appNewGroup is : ' + res.appNewGroup);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result changeReason is : ' + res.changeReason);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result userId is : ' + res.userId);
    console.log('BUNDLE_ACTIVE registerAppGroupCallBack result bundleName is : ' + res.bundleName);
    };
    usageStatistics.registerAppGroupCallBack(onBundleGroupChanged, (err : BusinessError) => {
    if(err) {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
    } else {
        console.log('BUNDLE_ACTIVE registerAppGroupCallBack callback success.');
    }
    });
    ```

14. 解除应用分组监听回调， 需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    // promise
    usageStatistics.unregisterAppGroupCallBack().then( () => {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack promise succeeded.');
    }).catch( (err : BusinessError) => {
        console.error('BUNDLE_ACTIVE unregisterAppGroupCallBack promise failed. code is: ' + err.code + ',message is: ' + err.message);
    });

    // callback
    usageStatistics.unregisterAppGroupCallBack((err : BusinessError) => {
        if(err) {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback failed. code is: ' + err.code + ',message is: ' + err.message);
        } else {
        console.log('BUNDLE_ACTIVE unregisterAppGroupCallBack callback success.');
        }
    });
    ```
## 相关实例

针对设备使用信息统计，有以下相关实例可供参考：

- [存储空间统计（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SystemFeature/DeviceManagement/StorageStatistic)

- [设备使用信息统计（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SystemFeature/DeviceUsageStatistics/DeviceUsageStatistics)