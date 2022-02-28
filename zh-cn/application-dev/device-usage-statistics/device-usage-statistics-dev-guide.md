## 设备使用信息统计

### 权限

ohos.permission.BUNDLE_ACTIVE_INFO

**表1** 设备使用信息统计主要接口

| 接口名 | 描述 |
| -------- | -------- |
| function queryBundleActiveStates(begin:number, end:number, callback:AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;):void | 通过指定起始和结束时间查询所有应用的事件集合 |
| function queryBundleStateInfos(begin:number, end:number, callback:AsyncCallback&lt;BundleStateInfoResponse&gt;):void | 通过指定起始和结束时间查询应用使用时长统计信息 |
| function queryCurrentBundleActiveStates(begin:number, end:number, callback:AsyncCallback&lt;Array&lt;BundleActiveState&gt;&gt;):void | 通过指定起始和结束时间查询当前应用的事件集合 |
| function queryBundleStateInfoByInterval(byInterval:intervalType, begin:number, end:number, callback:AsyncCallback&lt;Array&lt;BundleStateInfo&gt;&gt;):void | 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息 |
| function queryAppUsagePriorityGroup(callback:AsyncCallback&lt;number&gt;):void | 查询（返回）当前调用者应用的使用优先级群组 |
| function isIdleState(bundleName:string, callback:AsyncCallback&lt;boolean&gt;):void | 判断指定Bundle Name的应用当前是否是空闲状态 |

## 开发步骤

1. 在config.json文件中配置长时任务权限

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

2. 通过指定起始和结束时间查询所有应用的事件集合

    ```js
    import stats from '@ohos.usagestatskit'

    // 异步方法promise方式
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

    // 异步方法callback方式
    setTimeout(()=>{
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
        })
    }, 500);
    ```

3. 通过指定起始和结束时间查询应用使用时长统计信息

    ```js
    import stats from '@ohos.usagestatskit'

    // 异步方法promise方式
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

    // 异步方法callback方式
    setTimeout(()=>{
        stats.queryBundleStateInfos(0, 20000000000000,(err, res) => {
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
        })
    }, 500);
    ```

4. 通过指定起始和结束时间查询当前应用的事件集合

    ```js
    import stats from '@ohos.usagestatskit'

    // 异步方法promise方式
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

    // 异步方法callback方式
    setTimeout(()=>{
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
        })
    }, 500);
    ```

5. 通过指定时间段间隔（天、周、月、年）查询应用使用时长统计信息

    ```js
    import stats from '@ohos.usagestatskit'

    // 异步方法promise方式
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

    // 异步方法callback方式
    setTimeout(()=>{
        stats.queryBundleStateInfoByInterval(0, 0, 20000000000000,(err, res) => {
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
        })
    }, 500);
    ```

6. 查询（返回）当前调用者应用的使用优先级群组

    ```js
    import stats from '@ohos.usagestatskit'

    // 异步方法promise方式
    stats.queryAppUsagePriorityGroup().then( res => {
        console.log('queryAppUsagePriorityGroup promise succeeded. result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('queryAppUsagePriorityGroup promise failed, because: ' + err.data);
    });

    // 异步方法callback方式
    setTimeout(()=>{
        stats.queryAppUsagePriorityGroup((err, res) => {
            if(err.data === 0) {
                console.log('queryAppUsagePriorityGroup callback succeeded. result: ' + JSON.stringify(res));
            } else {
                console.log('queryAppUsagePriorityGroup callback failed, because: ' + err.data);
            }
        })
    }, 500);
    ```

7. 判断指定Bundle Name的应用当前是否是空闲状态

    ```js
    import stats from '@ohos.usagestatskit'

    // 异步方法promise方式
    stats.isIdleState("com.ohos.camera").then( res => {
        console.log('isIdleState promise succeeded. result: ' + JSON.stringify(res));
    }).catch( err => {
        console.log('isIdleState promise failed, because: ' + err.data);
    });

    // 异步方法callback方式
    setTimeout(()=>{
        stats.isIdleState("com.ohos.camera", (err, res) => {
            if(err.data === 0) {
                console.log('isIdleState callback succeeded. result: ' + JSON.stringify(res));
            } else {
                console.log('isIdleState callback failed, because: ' + err.data);
            }
        })
    }, 500);
    ```