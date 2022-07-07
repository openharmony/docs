# 设备使用信息统计

## 场景介绍

设备使用信息统计，包括app usage/notification usage/system usage等使用统计。例如应用使用信息统计，用于保存和查询应用使用详情（app usage）、事件日志数据（event log）、应用分组（bundle group）情况。
部件缓存的应用记录（使用历史统计和使用事件记录）会在事件上报后30分钟内刷新到数据库持久化保存。

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
| function queryAppUsagePriorityGroup(callback: AsyncCallback&lt;number&gt;): void | 查询（返回）当前调用者应用的使用优先级群组。 |
| function isIdleState(bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void | 判断指定Bundle Name的应用当前是否是空闲状态。 |

## 开发步骤

1. 在config.json文件中配置设备使用信息统计权限。

    ```json
    "module": {
        "package": "com.example.deviceUsageStatistics",
        ...,
        "reqPermissions": [
            {
            "name": "ohos.permission.BUNDLE_ACTIVE_INFO"
            }
        ]
    }
    ```

2. 通过指定起始和结束时间查询所有应用的事件集合，config.json中需要配置权限：ohos.permission.BUNDLE_ACTIVE_INFO。

    ```js
    import stats from '@ohos.bundleState'

    // 异步方法promise方式
    stats.queryBundleActiveStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryBundleActiveStates promise failed, because: ' + err.code);
    });

    // 异步方法callback方式
    stats.queryBundleActiveStates(0, 20000000000000, (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleActiveStates callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleActiveStates callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleActiveStates callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

3. 通过指定起始和结束时间查询应用使用时长统计信息，config.json中需要配置权限：ohos.permission.BUNDLE_ACTIVE_INFO。

    ```js
    import stats from '@ohos.bundleState'

    // 异步方法promise方式
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

    // 异步方法callback方式
    stats.queryBundleStateInfos(0, 20000000000000, (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfos callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleStateInfos callback success.');
            let i = 1;
            for(let key in res){
                console.log('BUNDLE_ACTIVE queryBundleStateInfos callback number : ' + i);
                console.log('BUNDLE_ACTIVE queryBundleStateInfos callback result ' + JSON.stringify(res[key]));
                i++;
            }
        }
    });
    ```

4. 通过指定起始和结束时间查询当前应用的事件集合，config.json中不需要配置权限。

    ```js
    import stats from '@ohos.bundleState'

    // 异步方法promise方式
    stats.queryCurrentBundleActiveStates(0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates promise failed, because: ' + err.code);
    });

    // 异步方法callback方式
    stats.queryCurrentBundleActiveStates(0, 20000000000000, (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryCurrentBundleActiveStates callback result ' + JSON.stringify(res[i]));
             }
        }
    });
    ```

5. 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息，config.json中需要配置权限：ohos.permission.BUNDLE_ACTIVE_INFO。

    ```js
    import stats from '@ohos.bundleState'

    // 异步方法promise方式
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000).then( res => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise success.');
        for (let i = 0; i < res.length; i++) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise number : ' + (i + 1));
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise result ' + JSON.stringify(res[i]));
        }
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval promise failed, because: ' + err.code);
    });

    // 异步方法callback方式
    stats.queryBundleStateInfoByInterval(0, 0, 20000000000000, (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback success.');
            for (let i = 0; i < res.length; i++) {
                console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback number : ' + (i + 1));
                console.log('BUNDLE_ACTIVE queryBundleStateInfoByInterval callback result ' + JSON.stringify(res[i]));
            }
        }
    });
    ```

6. 查询（返回）当前调用者应用的使用优先级群组，config.json中不需要配置权限。

    ```js
    import stats from '@ohos.bundleState'

    // 异步方法promise方式
    stats.queryAppUsagePriorityGroup().then( res => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup promise failed. because: ' + err.code);
    });

    // 异步方法callback方式
    stats.queryAppUsagePriorityGroup((err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback failed. because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE queryAppUsagePriorityGroup callback succeeded. result: ' + JSON.stringify(res));
        }
    });
    ```

7. 判断指定Bundle Name的应用当前是否是空闲状态，config.json中不需要配置权限。

    ```js
    import stats from '@ohos.bundleState'

    // 异步方法promise方式
    stats.isIdleState("com.ohos.camera").then( res => {
        console.log('BUNDLE_ACTIVE isIdleState promise succeeded, result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('BUNDLE_ACTIVE isIdleState promise failed, because: ' + err.code);
    });

    // 异步方法callback方式
    stats.isIdleState("com.ohos.camera", (err, res) => {
        if(err) {
            console.log('BUNDLE_ACTIVE isIdleState callback failed, because: ' + err.code);
        } else {
            console.log('BUNDLE_ACTIVE isIdleState callback succeeded, result: ' + JSON.stringify(res));
        }
    });
    ```