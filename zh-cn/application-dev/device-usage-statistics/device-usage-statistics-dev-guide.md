# 设备使用信息统计(API7)

## 场景介绍

设备使用信息统计，包括app usage/notification usage/system usage等使用统计。例如应用使用信息统计，用于保存和查询应用使用详情（app usage）、事件日志数据（event log）、应用分组（bundle group）情况。
部件缓存的应用记录（使用历史统计和使用事件记录）会在事件上报后30分钟内刷新到数据库持久化保存。

根据设备的使用信息统计接口，开发者可以开发出健康管理类应用来实现个人设备健康使用功能，并向用户展示其个人设备的使用记录。

## 接口说明
注册相关接口包导入：
```js
import stats from '@ohos.bundleState';
```

**表1** 设备使用信息统计主要接口

| 接口名 | 描述 |
| -------- | -------- |
| function queryBundleActiveStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;): void | 通过指定起始和结束时间查询所有应用的事件集合。 |
| function queryBundleStateInfos(begin: number, end: number, callback: AsyncCallback&lt;BundleActiveInfoResponse&gt;): void | 通过指定起始和结束时间查询应用使用时长统计信息。 |
| function queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;): void | 通过指定起始和结束时间查询当前应用的事件集合。 |
| function queryBundleStateInfoByInterval(byInterval: IntervalType, begin: number, end: number, callback: AsyncCallback&lt;Array&lt;BundleStateInfo&gt;&gt;): void | 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息。 |
| function queryAppUsagePriorityGroup(callback: AsyncCallback&lt;number&gt;): void | 查询当前应用的使用优先级群组。callback形式。 |
| function queryAppUsagePriorityGroup(): Promise&lt;number&gt;; | 查询当前应用的使用优先级群组。promise形式。 |
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | 判断指定Bundle Name的应用当前是否是空闲状态。 |

## 开发步骤

1. 获取设备使用信息之前，需要检查是否已经配置请求相应的权限。
    系统提供的设备使用信息统计的权限是ohos.permission.BUNDLE_ACTIVE_INFO
    具体配置方式请参考[权限申请声明](../security/accesstoken-guidelines.md)

2. 通过指定起始和结束时间查询所有应用的事件集合，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import stats from '@ohos.bundleState'

    stats.queryBundleActiveStates(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise failed, because: ' + err.code);
    });
    ```

3. 通过指定起始和结束时间查询应用使用时长统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import stats from '@ohos.bundleState'

    stats.queryBundleStateInfos(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfos promise success.');
        let i = 1;
        for (let key in res){
            console.log('BUNDLE_ACTIVE queryBundleStateInfos promise number : ' + i);
            console.log('BUNDLE_ACTIVE queryBundleStateInfos promise result ' + JSON.stringify(res[key]));
            i++;
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfos promise failed, because: ' + err.code);
    });
    ```

4. 通过指定起始和结束时间查询当前应用的事件集合，不需要配置权限。

    ```js
    import stats from '@ohos.bundleState'

    stats.queryCurrentBundleActiveStates(0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise failed, because: ' + err.code);
    });
    ```

5. 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限。

    ```js
    import stats from '@ohos.bundleState'

    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000).then(res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise failed, because: ' + err.code);
    });

    ```

6. 查询（无参）当前调用者应用的使用优先级群组，不需要配置权限。

    ```js
    import stats from '@ohos.bundleState'

    stats.queryAppUsagePriorityGroup().then(res => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch(err => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise failed. because: ' + err.code);
    });
    ```

7. 判断指定Bundle Name的应用当前是否是空闲状态，需要配置ohos.permission.BUNDLE_ACTIVE_INFO权限，三方应用只能查询自身的空闲状态。

    ```js
    import stats from '@ohos.bundleState'

    stats.isIdleState("com.ohos.camera").then(res => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch(err => {
        console.log('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);
    });

    ```
## 相关实例
针对设备使用信息统计，有以下相关实例可供参考：
- [`DeviceUsageStatistics`：设备使用信息统计（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/device/DeviceUsageStatistics)

