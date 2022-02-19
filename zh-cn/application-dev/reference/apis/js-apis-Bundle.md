# Bundle模块(JS端SDK接口)

## 导入模块

```
import bundle from '@ohos.bundle';
```

## 系统能力

SystemCapability.BundleManager.BundleFramework

## 权限列表

|  权限 | 权限等级 | 描述 |
|-------| --------- | ---- |
| ohos.permission.GET_BUNDLE_INFO | normal | 仅限查询本应用信息 |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息 |
| ohos.permission.INSTALL_BUNDLE | system_core | 可安装、卸载应用 |

## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number): Promise\<ApplicationInfo>

以异步方法根据给定的包名获取ApplicationInfo，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | 是   | 要查询的应用程序包名称。                                     |
| bundleFlags | number | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId      | number | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。                     |

**返回值：**

| 类型      | 说明 |
| ----------- | -------- |
| Promise\<ApplicationInfo> | Promise形式返回应用程序信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 0;
let userId = 100;
bundle.getApplicationInfo(bundleName, bundleFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void

以异步方法根据给定的包名获取ApplicationInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型                            | 必填 | 描述                                                         |
| ----------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                          | 是   | 要查询的应用程序包名称。                                     |
| bundleFlags | number                          | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId      | number                          | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。                     |
| callback    | AsyncCallback\<ApplicationInfo> | 是   | 程序启动作为入参的回调函数，返回应用程序信息。               |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 0;
let userId = 100;
bundle.getApplicationInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```



## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, userId?: number): Promise<Array\<BundleInfo>>

以异步方法获取系统中所有可用的BundleInfo，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 名称       | 类型       | 必填 | 描述                                                        |
| ---------- | ---------- | ---- | ----------------------------------------------------------- |
| bundleFlag | BundleFlag | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId     | number     | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。  |

**返回值：**

| 类型                        | 说明                                |
| --------------------------- | ----------------------------------- |
| Promise<Array\<BundleInfo>> | Promise形式返回所有可用的BundleInfo |

**示例：**

```js
let bundleFlag = 0;
let userId = 100;
bundle.getAllBundleInfo(bundleFlag, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback<Array\<BundleInfo>>): void

以异步方法获取系统中所有可用的BundleInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 名称       | 类型                              | 必填 | 描述                                                         |
| ---------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                        | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。|
| callback   | AsyncCallback<Array\<BundleInfo>> | 是   | 程序启动作为入参的回调函数，返回所有可用的BundleInfo。       |

**示例：**

```js
let bundleFlag = 0;
bundle.getAllBundleInfo(bundleFlag, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```


## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback<Array\<BundleInfo>>): void

以异步方法获取系统中所有可用的BundleInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 名称       | 类型                              | 必填 | 描述                                                         |
| ---------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                        | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。|
| userId     | number                            | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。  |
| callback   | AsyncCallback<Array\<BundleInfo>> | 是   | 程序启动作为入参的回调函数，返回所有可用的BundleInfo。       |

**示例：**

```js
let bundleFlag = 0;
let userId = 100;
bundle.getAllBundleInfo(bundleFlag, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```



## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, options?: BundleOptions): Promise\<BundleInfo>

以异步方法根据给定的包名获取BundleInfo，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | 是   | 包名                                                         |
| bundleFlags | number | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| options     | BundleOptions              | 否   | 包含userid和networkid。                                    |

**返回值：**

| 类型                 | 说明                                       |
| -------------------- | ------------------------------------------ |
| Promise\<BundleInfo> | 返回值为Promise对象，Promise中包含包信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
let options = {
  "userId" : 100,
  "networkId" : null
};
bundle.getBundleInfo(bundleName, bundleFlags, options)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

以异步方法根据给定的包名获取BundleInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型                       | 必填 | 描述                                                         |
| ----------- | -------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                     | 是   | 包名                                                         |
| bundleFlags | number                     | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| callback    | AsyncCallback\<BundleInfo> | 是   | 程序启动作为入参的回调函数，返回包信息。                     |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
bundle.getBundleInfo(bundleName, bundleFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, options: BundleOptions, callback: AsyncCallback\<BundleInfo>): void

以异步方法根据给定的包名获取BundleInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型                       | 必填 | 描述                                                         |
| ----------- | -------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                     | 是   | 包名                                                         |
| bundleFlags | number                     | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| options     | BundleOptions              | 是   | 包含userid和networkid。                                    |
| callback    | AsyncCallback\<BundleInfo> | 是   | 程序启动作为入参的回调函数，返回包信息。                     |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
let options = {
  "userId" : 100,
  "networkId" : null
};
bundle.getBundleInfo(bundleName, bundleFlags, options, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, userId: number): Promise<Array\<ApplicationInfo>>

获取指定用户下所有已安装的应用信息，通过Promise获取返回值。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 名称        | 类型   | 必填 | 描述                                                   |
| ----------- | ------ | ---- | ------------------------------------------------------ |
| bundleFlags | number | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId      | number | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。   |

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise<Array\<ApplicationInfo>> | 返回值为Promise对象，Promise中包含应用信息列表。 |

**示例：**

```js
let bundleFlags = 8;
let userId = 100;
bundle.getAllApplicationInfo(bundleFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, userId: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

获取指定用户下所有已安装的应用信息，通过回调函数获取返回值。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 名称        | 类型                                   | 必填 | 描述                                                   |
| ----------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| bundleFlags | number                                 | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。|
| userId      | number                                 | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。    |
| callback    | AsyncCallback<Array\<ApplicationInfo>> | 是   | 程序启动作为入参的回调函数，返回应用信息列表。         |

**示例：**

```js
let bundleFlags = 8;
let userId = 100;
bundle.getAllApplicationInfo(bundleFlags, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```



## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

以异步方法根据给定的意图获取Ability信息，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| want        | Want   | 是   | 包含要查询的应用程序包名称的意图。                           |
| bundleFlags | number | 是   | 用于指定返回abilityInfo信息。默认值：0，取值范围：大于等于0。 |
| userId      | number | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0          |

**返回值：**

| 类型                         | 说明                         |
| ---------------------------- | ---------------------------- |
| Promise<Array\<AbilityInfo>> | Promise形式返回Ability信息。 |

**示例：**

```js
let bundleFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryAbilityByWant(want, bundleFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

以异步方法根据给定的意图获取Ability信息，使用callback形式返回结果。

**参数：**

| 名称        | 类型                               | 必填 | 描述                                                         |
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | 是   | 指示包含要查询的应用程序包名称的意图。                       |
| bundleFlags | number                             | 是   | 用于指定返回abilityInfo信息。默认值：0，取值范围：大于等于0。 |
| userId      | number                             | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0          |
| callback    | AsyncCallback<Array\<AbilityInfo>> | 是   | 程序启动作为入参的回调函数，返回Ability信息。                |

**示例：**

```js
let bundleFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryAbilityByWant(want, bundleFlags, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback<Array<AbilityInfo>>): void

以异步方法根据给定的意图获取Ability信息，使用callback形式返回结果。

**参数：**

| 名称        | 类型                               | 必填 | 描述                                                         |
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | 是   | 指示包含要查询的应用程序包名称的意图。                       |
| bundleFlags | number                             | 是   | 用于指定返回abilityInfo信息。默认值：0，取值范围：大于等于0。 |
| callback    | AsyncCallback<Array\<AbilityInfo>> | 是   | 程序启动作为入参的回调函数，返回Ability信息。                |

**示例：**

```js
let bundleFlags = 0;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryAbilityByWant(want, bundleFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number): Promise\<BundleInfo>

以异步方法从给定的HAP中获取BundleInfo，使用Promise形式返回结果。

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | 是   | HAP文件路径                                                  |
| bundleFlags | number | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |

**返回值：**

| 类型                 | 说明                                       |
| -------------------- | ------------------------------------------ |
| Promise\<BundleInfo> | 返回值为Promise对象，Promise中包含包信息。 |

**示例：**

```js
let hapFilePath = "/data/test.hap";
let bundleFlags = 1;
bundle.getBundleArchiveInfo(hapFilePath, bundleFlags)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

以异步方法从给定的HAP中获取BundleInfo，使用callback形式返回结果。

**参数：**

| 名称        | 类型                      | 必填 | 描述                                                         |
| ----------- | ------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePath | string                    | 是   | HAP文件路径                                                  |
| bundleFlags | number                    | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| callback    | AsyncCallback<BundleInfo> | 是   | 程序启动作为入参的回调函数，返回包信息。                     |

**示例：**

```js
let hapFilePath = "/data/test.hap";
let bundleFlags = 1;
bundle.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getBundleInstaller

getBundleInstaller(): Promise<BundleInstaller>

以异步方法获取BundleInstaller，使用Promise形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**返回值：**

| 类型                     | 说明                                                |
| ------------------------ | --------------------------------------------------- |
| Promise<BundleInstaller> | 返回值为Promise对象，Promise中包含BundleInstaller。 |

**示例：**

```js
let bundleFilePaths = ['/data/test.hap'];
let param = {
    userId : 100,
    installFlag : 1,
    isKeepData : false
};
bundle.getBundleInstaller()
.then((installerObject) => {
    console.info('Operation successful. ');
    installerObject.install(bundleFilePaths, param)
    .then((data) => {
        console.info('Operation successful. Data:' + JSON.stringify(data));
    }).catch((error) => {
        console.error('Operation failed. Cause: ' + JSON.stringify(error));
    })
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getBundleInstaller

getBundleInstaller(callback: AsyncCallback<BundleInstaller>): void;

以异步方法获取BundleInstaller，使用callback形式返回结果。

**需要权限：**

ohos.permission.INSTALL_BUNDLE

**参数：**

| 名称     | 类型                           | 必填 | 描述                                              |
| -------- | ------------------------------ | ---- | ------------------------------------------------- |
| callback | AsyncCallback<BundleInstaller> | 是   | 程序启动作为入参的回调函数，返回BundleInstaller。 |

**示例：**

```js
let bundleFilePaths = ['/data/test.hap'];
let param = {
    userId : 100,
    installFlag : 1,
    isKeepData : false
};
bundle.getBundleInstaller((err, installerObject) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
    }
    console.info('Operation successful. Data:' + JSON.stringify(installerObject));
    installerObject.install(bundleFilePaths, param, (err, data) => {
        if (err) {
            console.error('Operation failed. Cause: ' + JSON.stringify(err));
        }
        console.info('Operation successful. Data:' + JSON.stringify(data));
    })
})
```


## bundle.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string): Promise\<Want>

以异步方法查询拉起指定应用的want对象，使用Promise形式返回结果。

**参数：**

| 名称       | 类型   | 必填 | 描述     |
| ---------- | ------ | ---- | -------- |
| bundleName | string | 是   | 要查询的应用程序包名称。 |

**返回值：**
| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise\<Want> | 返回值为Promise对象，Promise中包含拉起指定应用的Want对象。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
bundle.getLaunchWantForBundle(bundleName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback<Want>): void;

以异步方法查询拉起指定应用的want对象，使用callback形式返回结果。

**参数：**

| 名称       | 类型   | 必填 | 描述     |
| ---------- | ------ | ---- | -------- |
| bundleName | string | 是   | 要查询的应用程序包名称。 |
| callback   | AsyncCallback\<Want> | 是   | 程序启动作为入参的回调函数，返回拉起指定应用的want对象。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
bundle.getLaunchWantForBundle(bundleName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.getNameForUid

getNameForUid(uid: number): Promise\<string>

以异步方法通过uid获取对应的包名，使用Promise形式返回结果。

**参数：**

| 名称       | 类型   | 必填 | 描述     |
| ---------- | ------ | ---- | -------- |
| uid | number | 是   | 要查询的uid。 |

**返回值：**
| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise\<string> | 返回值为Promise对象，Promise中包含指定uid的包名。 |

**示例：**

```js
let uid = 20010005;
bundle.getNameForUid(uid)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getNameForUid

getNameForUid(uid: number, callback: AsyncCallback<string>): void;

以异步方法通过uid获取对应的包名，使用callback形式返回结果。

**参数：**

| 名称       | 类型   | 必填 | 描述     |
| ---------- | ------ | ---- | -------- |
| uid | number | 是   | 要查询的uid。 |
| callback   | AsyncCallback\<string> | 是   | 程序启动作为入参的回调函数，返回指定uid的包名。 |

**示例：**

```js
let uid = 20010005;
bundle.getNameForUid(uid, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## ElementName

| 名称        | 读写属性 | 类型   | 必填 | 描述                                                         |
| ----------- | -------- | ------ | ---- | ------------------------------------------------------------ |
| deviceId    | 只读     | string | 否   | 表示运行指定Ability的设备ID。                                |
| bundleName  | 只读     | string | 是   | 表示包描述。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| abilityName | 只读     | string | 是   | 表示待启动的Ability名称。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |

## InstallStatus

| 名称          | 读写属性 | 类型             | 必填 | 描述                                                         |
| ------------- | -------- | ---------------- | ---- | ------------------------------------------------------------ |
| status        | 只读     | InstallErrorCode | 是   | 安装结果code<br/>SUCCESS = 0<br/>STATUS_INSTALL_FAILURE = 1<br/>STATUS_INSTALL_FAILURE_ABORTED = 2,<br/>STATUS_INSTALL_FAILURE_INVALID = 3<br/>STATUS_INSTALL_FAILURE_CONFLICT = 4<br/>STATUS_INSTALL_FAILURE_STORAGE = 5<br/>STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br/>STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br/>STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br/>STATUS_ABILITY_NOT_FOUND = 0x40<br/>STATUS_BMS_SERVICE_ERROR = 0x41 |
| statusMessage | 只读     | string           | 是   | 安装结果Message                                              |

## BundleFlag

包的标志

| 名称               | 默认值 | 说明   |
| ------ | ------ | ------ |
| GET_BUNDLE_DEFAULT | 0x00000000 | 获取默认的应用信息 |
| GET_BUNDLE_WITH_ABILITIES | 0x00000001 | 获取包括Ability信息的包信息 |
| GET_ABILITY_INFO_WITH_PERMISSION | 0x00000002 | 获取包括权限的Ability信息 |
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000004 | 获取包括应用的Ability信息 |
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000008 | 获取包括权限的应用信息 |
| GET_BUNDLE_WITH_REQUESTED_PERMISSION | 0x00000010 | 获取包括所需权限的包信息 |
| GET_ABILITY_INFO_WITH_METADATA | 0x00000020 | 获取ability的元数据信息 |
| GET_APPLICATION_INFO_WITH_METADATA | 0x00000040 | 获取应用的元数据信息 |
| GET_ABILITY_INFO_SYSTEMAPP_ONLY | 0x00000080 | 获取仅包括系统应用的ability信息 |
| GET_ABILITY_INFO_WITH_DISABLE | 0x00000100 | 获取包括被禁用的ability信息 |
| GET_APPLICATION_INFO_WITH_DISABLE | 0x00000200 | 获取包括被禁用的应用信息 |

## BundleOptions

包的选项

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| userId | number | 是 | 是 | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |
| networkId | string | 是 | 是 | 网络Id，默认值：null。 |

## BundleInfo

应用包的信息。

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| name                     | string                     | 是   | 否   | 应用包的名称                               |
| type                     | string                     | 是   | 否   | 应用包类型                                 |
| appId                    | string                     | 是   | 否   | 应用包里应用程序的id                       |
| uid                      | number                     | 是   | 否   | 应用包里应用程序的uid                      |
| installTime              | number                     | 是   | 否   | HAP包安装时间                              |
| updateTime               | number                     | 是   | 否   | HAP包更新时间                              |
| appInfo                  | ApplicationInfo        | 是   | 否   | 应用程序的配置信息                         |
| abilityInfo              | Array<AbilityInfo>         | 是   | 否   | Ability的配置信息                          |
| reqPermissions           | Array<string>              | 是   | 否   | 应用运行时需向系统申请的权限集合           |
| reqPermissionDetails     | Array<ReqPermissionDetail> | 是   | 否   | 应用运行时需向系统申请的权限集合的详细信息 |
| vendor                   | string                     | 是   | 否   | 应用包的供应商                             |
| versionCode              | number                     | 是   | 否   | 应用包的版本号                             |
| versionName              | string                     | 是   | 否   | 应用包的版本文本描述信息                   |
| compatibleVersion        | number                     | 是   | 否   | 运行应用包所需要最低的SDK版本号            |
| targetVersion            | number                     | 是   | 否   | 运行应用包所需要最高SDK版本号              |
| isCompressNativeLibs     | boolean                    | 是   | 否   | 是否压缩应用包的本地库，默认为true         |
| hapModuleInfo            | Array<HapModuleInfo>       | 是   | 否   | 模块的配置信息                             |
| entryModuleName          | string                     | 是   | 否   | Entry的模块名称                            |
| cpuAbi                   | string                     | 是   | 否   | 应用包的cpuAbi信息                         |
| isSilentInstallation     | string                     | 是   | 否   | 是否通过静默安装                           |
| minCompatibleVersionCode | number                     | 是   | 否   | 分布式场景下的应用包兼容的最低版本         |
| entryInstallationFree | boolean | 是 | 否 | Entry是否支持免安装 |
| reqPermissionStates | Array<number> | 是 | 否 | 申请权限的授予状态 |

## ApplicationInfo

应用程序信息。

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| name             | string        | 是   | 否   | 应用程序的名称                             |
| description      | string        | 是   | 否   | 应用程序的描述                             |
| descriptionId    | number        | 是   | 否   | 应用程序的描述id                           |
| systemApp        | boolean       | 是   | 否   | 判断是否为系统应用程序，默认为false        |
| enabled          | boolean       | 是   | 否   | 判断应用程序是否可以使用，默认为true       |
| label            | string        | 是   | 否   | 应用程序的标签                             |
| labelId          | string        | 是   | 否   | 应用程序的标签id                           |
| icon             | string        | 是   | 否   | 应用程序的图标                             |
| iconId           | string        | 是   | 否   | 应用程序的图标id                           |
| process          | string        | 是   | 否   | 应用程序的进程，如果不设置，默认为包的名称 |
| supportedModes   | number        | 是   | 否   | 应用程序支持的运行模式                     |
| moduleSourceDirs | Array<string> | 是   | 否   | 应用程序的资源存放的相对路径               |
| permissions      | Array<string> | 是   | 否   | 访问应用程序所需的权限                     |
| moduleInfos | Array<ModuleInfo> | 是   | 否   | 应用程序的模块信息                         |
| entryDir         | string        | 是   | 否   | 应用程序的文件保存路径                     |
| customizeData    | Map<string, Array<CustomizeData>> | 是   | 是   | 应用程序的自定义数据                       |
| codePath | string | 是 | 否 | 应用程序的安装目录 |
| metaData | Map<string, Array<CustomizeData>> | 是 | 否 | 应用程序的自定义元信息 |
| removable | boolean | 是 | 否 | 应用程序是否可以被移除 |
| accessTokenId | number | 是 | 否 | 应用程序的accessTokenId |
| uid | number | 是 | 否 | 应用程序的uid |

## ModuleInfo

应用程序的模块信息。

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| moduleName      | string | 是   | 否   | 模块名称 |
| moduleSourceDir | string | 是   | 否   | 安装目录 |

## CustomizeData

自定义元数据。

| 名称  | 类型   | 可读 | 可写 | 说明             |
| ----- | ------ | ---- | ---- | ---------------- |
| name  | string | 是   | 是   | 自定义元数据名称 |
| value | string | 是   | 是   | 自定义元数据值   |
| extra | string | 是   | 是   | 自定义资源       |


## HapModuleInfo

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| name             | string        | 是   | 否   | 模块名称           |
| description      | string        | 是   | 否   | 模块描述信息       |
| descriptionId    | number        | 是   | 否   | 描述信息ID         |
| icon             | string        | 是   | 否   | 模块图标           |
| label            | string        | 是   | 否   | 模块标签           |
| labelId          | number        | 是   | 否   | 模块标签ID         |
| iconId           | number        | 是   | 否   | 模块图标ID         |
| backgroundImg    | string        | 是   | 否   | 模块背景图片       |
| supportedModes   | number        | 是   | 否   | 模块支持的模式     |
| reqCapabilities  | Array<string> | 是   | 否   | 模块运行需要的能力 |
| deviceTypes      | Array<string> | 是   | 否   | 支持运行的设备类型 |
| abilityInfo      | Array<AbilityInfo> | 是   | 否   | Ability信息        |
| moduleName       | string        | 是   | 否   | 模块名             |
| mainAbilityName  | string        | 是   | 否   | 入口Ability名称    |
| installationFree | boolean       | 是   | 否   | 是否支持免安装     |
| mainElementName | string | 是 | 否 | 入口ability信息 |

## ReqPermissionDetail

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| name      | string    | 是   | 是   | 需要使用的权限名称   |
| reason    | string    | 是   | 是   | 描述申请权限的原因   |
| usedScene | UsedScene | 是 | 是 | 权限使用的场景和时机 |

## UsedScene

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| abilities | Array<string> | 是   | 是   | 使用到该权限的Ability集合 |
| when      | string        | 是   | 是   | 使用该权限的时机          |


## AbilityInfo

| 名称               | 类型 | 可读 | 可写 | 说明 |
| ------ | ------ | ------ | ------ | ------ |
| bundleName         | string                                                       | 是   | 否   | 应用包名                                  |
| name               | string                                                       | 是   | 否   | Ability名称                               |
| label              | string                                                       | 是   | 否   | Ability对用户显示的名称                   |
| description        | string                                                       | 是   | 否   | Ability的描述                             |
| icon               | string                                                       | 是   | 否   | Ability的图标资源文件索引                 |
| descriptionId      | number                                                       | 是   | 否   | Ability的描述id                           |
| iconId             | number                                                       | 是   | 否   | Ability的图标id                           |
| moduleName         | string                                                       | 是   | 否   | Ability所属的HAP包的名称                  |
| process            | string                                                       | 是   | 否   | Ability的进程，如果不设置，默认为包的名称 |
| targetAbility      | string                                                       | 是   | 否   | 当前Ability重用的目标Ability              |
| backgroundModes    | number                                                       | 是   | 否   | 表示后台服务的类型                        |
| isVisible          | boolean                                                      | 是   | 否   | 判断Ability是否可以被其他应用调用         |
| formEnabled        | boolean                                                      | 是   | 否   | 判断Ability是否提供卡片能力               |
| type               | AbilityType | 是   | 否   | Ability类型                               |
| orientation        | DisplayOrientation | 是   | 否   | Ability的显示模式                         |
| launchMode         | LaunchMode | 是   | 否   | Ability的启动模式                         |
| permissions        | Array<string>                                                | 是   | 否   | 被其他应用Ability调用时需要申请的权限集合 |
| deviceTypes        | Array<string>                                                | 是   | 否   | Ability支持的设备类型                     |
| deviceCapabilities | Array<string>                                                | 是   | 否   | Ability需要的设备能力                     |
| readPermission     | string                                                       | 是   | 否   | 读取Ability数据所需的权限                 |
| writePermission    | string                                                       | 是   | 否   | 向Ability写数据所需的权限                 |
| applicationInfo    | ApplicationInfo | 是   | 否   | 应用程序的配置信息                        |
| formEntity         | number                                                       | 是   | 否   | 显示表单的位置                            |
| minFormHeight      | number                                                       | 是   | 否   | Ability的最小高度                         |
| defaultFormHeight  | number                                                       | 是   | 否   | Ability的默认高度                         |
| minFormWidth       | number                                                       | 是   | 否   | Ability的最小宽度                         |
| defaultFormWidth   | number                                                       | 是   | 否   | Ability的默认宽度                         |
| uri                | string                                                       | 是   | 否   | 获取Ability的统一资源标识符（URI）        |
| customizeData      | Map<string, Array<CustomizeData>> | 是   | 是   | Ability的自定义数据                       |
| labelId            | number                                                       | 是   | 否   | Ability的标签id                           |
| subType            | AbilitySubType | 是   | 否   | Ability中枚举使用的模板的子类型           |
| metaData | Array<Metadata> | 是 | 否 | ability的自定义元信息 |
| enabled | boolean | 是 | 否 | ability是否可用 |

## AbilityType

| 名称    | 类型 | 说明                        |
| ------- | ---- | --------------------------- |
| UNKNOWN | 无   | 未知Ability类型             |
| PAGE    | 无   | Ability有一个UI界面         |
| SERVICE | 无   | Ability没有UI界面           |
| DATA    | 无   | Ability用于提供数据访问服务 |

## DisplayOrientation

| 名称          | 类型 | 说明                     |
| ------------- | ---- | ------------------------ |
| UNSPECIFIED   | 无   | 屏幕方向--不指定         |
| LANDSCAPE     | 无   | 屏幕方向--横屏           |
| PORTRAIT      | 无   | 屏幕方向--竖屏           |
| FOLLOW_RECENT | 无   | 屏幕方向--紧跟上一个组件 |

## LaunchMode

| 名称        | 类型 | 说明                |
| ----------- | ---- | ------------------- |
| UNSPECIFIED | 0    | Ability只有一个示例 |
| STANDARD    | 1    | Ability有多个示例   |
