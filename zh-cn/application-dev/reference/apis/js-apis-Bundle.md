# Bundle模块(JS端SDK接口)

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> API9 当前为Canary版本，仅供试用，不保证接口可稳定调用。
## 导入模块

```
import bundle from '@ohos.bundle';
```

## 系统能力

SystemCapability.BundleManager.BundleFramework

## 权限列表

| 权限                                       | 权限等级         | 描述        |
| ---------------------------------------- | ------------ | --------- |
| ohos.permission.GET_BUNDLE_INFO          | normal       | 仅限查询本应用信息 |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息 |
| ohos.permission.INSTALL_BUNDLE           | system_core  | 可安装、卸载应用  |

## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<ApplicationInfo>

以异步方法根据给定的包名获取ApplicationInfo，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | 是    | 要查询的应用程序包名称。                            |
| bundleFlags | number | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId      | number | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。            |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Promise形式返回应用程序信息。 |

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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                              | 必填   | 描述                                      |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| bundleName  | string                          | 是    | 要查询的应用程序包名称。                            |
| bundleFlags | number                          | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId      | number                          | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。            |
| callback    | AsyncCallback\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | 是    | 程序启动作为入参的回调函数，返回应用程序信息。                 |

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


## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<ApplicationInfo>): void

以异步方法根据给定的包名获取ApplicationInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                              | 必填   | 描述                                      |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| bundleName  | string                          | 是    | 要查询的应用程序包名称。                            |
| bundleFlags | number                          | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| callback    | AsyncCallback\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | 是    | 程序启动作为入参的回调函数，返回应用程序信息。                 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 0;
bundle.getApplicationInfo(bundleName, bundleFlags, (err, data) => {
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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型         | 必填   | 描述                                      |
| ---------- | ---------- | ---- | --------------------------------------- |
| bundleFlag | BundleFlag | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId     | number     | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。            |

**返回值：**

| 类型                          | 说明                         |
| --------------------------- | -------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | Promise形式返回所有可用的BundleInfo |

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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型                                | 必填   | 描述                                      |
| ---------- | --------------------------------- | ---- | --------------------------------------- |
| bundleFlag | BundleFlag                        | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| callback   | AsyncCallback<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | 是    | 程序启动作为入参的回调函数，返回所有可用的BundleInfo。        |

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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型                                | 必填   | 描述                                      |
| ---------- | --------------------------------- | ---- | --------------------------------------- |
| bundleFlag | BundleFlag                        | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId     | number                            | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。            |
| callback   | AsyncCallback<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | 是    | 程序启动作为入参的回调函数，返回所有可用的BundleInfo。        |

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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型            | 必填   | 描述                                      |
| ----------- | ------------- | ---- | --------------------------------------- |
| bundleName  | string        | 是    | 包名                                      |
| bundleFlags | number        | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| options     | [BundleOptions](#bundleoptions) | 否    | 包含userid。                               |

**返回值：**

| 类型                   | 说明                           |
| -------------------- | ---------------------------- |
| Promise\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | 返回值为Promise对象，Promise中包含包信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
let options = {
  "userId" : 100
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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                         | 必填   | 描述                                      |
| ----------- | -------------------------- | ---- | --------------------------------------- |
| bundleName  | string                     | 是    | 包名                                      |
| bundleFlags | number                     | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | 是    | 程序启动作为入参的回调函数，返回包信息。                    |

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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                         | 必填   | 描述                                      |
| ----------- | -------------------------- | ---- | --------------------------------------- |
| bundleName  | string                     | 是    | 包名                                      |
| bundleFlags | number                     | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| options     | [BundleOptions](#bundleoptions)              | 是    | 包含userid。                               |
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | 是    | 程序启动作为入参的回调函数，返回包信息。                    |

**示例：**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
let options = {
  "userId" : 100
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

getAllApplicationInfo(bundleFlags: number, userId?: number): Promise<Array\<ApplicationInfo>>

获取指定用户下所有已安装的应用信息，通过Promise获取返回值。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述                                      |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleFlags | number | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId      | number | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。            |

**返回值：**

| 类型                               | 说明                              |
| -------------------------------- | ------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | 返回值为Promise对象，Promise中包含应用信息列表。 |

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

获取指定用户下所有已安装的应用信息，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                     | 必填   | 描述                                      |
| ----------- | -------------------------------------- | ---- | --------------------------------------- |
| bundleFlags | number                                 | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| userId      | number                                 | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。            |
| callback    | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | 是    | 程序启动作为入参的回调函数，返回应用信息列表。                 |

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


## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, callback: AsyncCallback<Array\<ApplicationInfo>>) : void;

获取指定用户下所有已安装的应用信息，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                     | 必填   | 描述                                      |
| ----------- | -------------------------------------- | ---- | --------------------------------------- |
| bundleFlags | number                                 | 是    | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0。 |
| callback    | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | 是    | 程序启动作为入参的回调函数，返回应用信息列表。                 |

**示例：**

```js
let bundleFlags = 8;
bundle.getAllApplicationInfo(bundleFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number) : Promise<BundleInfo>

以异步方法获取有关HAP包中包含的应用程序包的信息，使用Promise形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型     | 必填   | 描述           |
| ---------- | ------ | ---- | ------------ |
| hapFilePath | string | 是    | HAP存放路径。路径应指向当前应用程序的数据目录的相对目录。 |
| bundleFlags | number | 是    | 用于指定要返回的BundleInfo对象中包含信息的标记。默认值：0，取值范围：大于0。 |

**返回值：**
| 类型             | 说明                                     |
| -------------- | -------------------------------------- |
| Promise\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | 返回值为Promise对象，Promise中包含有关hap包中包含的应用程序的信息。 |

**示例：**

```js
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = 0;
bundle.getBundleArchiveInfo(hapFilePath, bundleFlags)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback<BundleInfo>) : void

以异步方法获取有关HAP包中包含的应用程序包的信息，使用callback形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型     | 必填   | 描述           |
| ---------- | ------ | ---- | ------------ |
| hapFilePath | string | 是    | HAP存放路径。路径应指向当前应用程序的数据目录的相对目录。 |
| bundleFlags | number | 是    | 用于指定要返回的BundleInfo对象中包含信息的标记。默认值：0，取值范围：大于0。|
| callback| AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | 是    | 用于指定要返回的BundleInfo对象中包含信息的标记。默认值：0，取值范围：大于0。|

**示例：**

```js
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = 0;
bundle.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.getAbilityInfo

getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>

通过包名称和abilityName获取Ability信息，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述               |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | 是    | 应用程序包名。     |
| abilityName | string | 是    | Ability名称。 |

**返回值：**

| 类型                    | 说明                    |
| --------------------- | --------------------- |
| Promise\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Promise形式返回Ability信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityInfo(bundleName, abilityName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getAbilityInfo

getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void;

通过包名称和abilityName获取Ability信息，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型     | 必填   | 描述            |
| ----------- | ------------ | ---- | ---------------- |
| bundleName  | string | 是    | 应用程序包名。     |
| abilityName | string | 是    | Ability名称。 |
| callback    | AsyncCallback\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | 是    | 程序启动作为入参的回调函数，返回Ability信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityInfo(bundleName, abilityName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```
## bundle.getAbilityInfo<sup>9+</sup>

getAbilityInfo(bundleName: string, moduleName: string, abilityName: string): Promise\<AbilityInfo>

通过包名称、moduleName和abilityName获取Ability信息，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述               |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | 是    | 应用程序包名。     |
| moduleName  | string | 是    | Module名称。     |
| abilityName | string | 是    | Ability名称。 |

**返回值：**

| 类型                    | 说明                    |
| --------------------- | --------------------- |
| Promise\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Promise形式返回Ability信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let moduleName = "entry";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityInfo(bundleName, moduleName, abilityName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getAbilityInfo<sup>9+</sup>

getAbilityInfo(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void;

通过包名称、moduleName和abilityName获取Ability信息，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型     | 必填   | 描述            |
| ----------- | ------------ | ---- | ---------------- |
| bundleName  | string | 是    | 应用程序包名。     |
| moduleName  | string | 是    | Module名称。     |
| abilityName | string | 是    | Ability名称。 |
| callback    | AsyncCallback\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | 是    | 程序启动作为入参的回调函数，返回Ability信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let moduleName = "entry";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityInfo(bundleName, moduleName, abilityName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getAbilityLabel<sup>8+</sup>

getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>

通过包名称和abilityName获取应用名称，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述               |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | 是    | 应用程序包名。     |
| abilityName | string | 是    | Ability名称。 |

**返回值：**

| 类型               | 说明                 |
| ---------------- | ------------------ |
| Promise\<string> | Promise形式返回应用名称信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityLabel(bundleName, abilityName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getAbilityLabel<sup>8+</sup>

getAbilityLabel(bundleName: string, abilityName: string, callback : AsyncCallback\<string>): void

通过包名称和abilityName获取应用名称，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                     | 必填   | 描述               |
| ----------- | ---------------------- | ---- | ---------------- |
| bundleName  | string                 | 是    | 应用程序包名。     |
| abilityName | string                 | 是    | Ability名称。 |
| callback    | AsyncCallback\<string> | 是    | 程序启动作为入参的回调函数，返回应用名称信息。        |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityLabel(bundleName, abilityName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```
## bundle.getAbilityLabel<sup>9+</sup>

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>

通过包名称、moduleName和abilityName获取应用名称，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述               |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | 是    | 应用程序包名。     |
| moduleName  | string | 是    | Module名称。     |
| abilityName | string | 是    | Ability名称。 |

**返回值：**

| 类型               | 说明                 |
| ---------------- | ------------------ |
| Promise\<string> | Promise形式返回应用名称信息。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let moduleName = "entry";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityLabel(bundleName, moduleName, abilityName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getAbilityLabel<sup>9+</sup>

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback : AsyncCallback\<string>): void

通过包名称、moduleName和abilityName获取应用名称，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                     | 必填   | 描述               |
| ----------- | ---------------------- | ---- | ---------------- |
| bundleName  | string                 | 是    | 应用程序包名。     |
| moduleName  | string | 是    | Module名称。     |
| abilityName | string                 | 是    | Ability名称。 |
| callback    | AsyncCallback\<string> | 是    | 程序启动作为入参的回调函数，返回应用名称信息。        |

**示例：**

```js
let bundleName = "com.example.myapplication";
let moduleName = "entry";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityLabel(bundleName, moduleName, abilityName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.isAbilityEnabled<sup>8+</sup>

isAbilityEnabled(info: AbilityInfo): Promise\<boolean>

以异步方法根据给定的AbilityInfo查询ability是否已经启用，使用Promise形式返回结果。

**需要权限：**

无

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称   | 类型          | 必填   | 描述           |
| ---- | ----------- | ---- | ------------ |
| info | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | 是    | Ability的配置信息 |

**返回值：**

| 类型                | 说明                        |
| ----------------- | ------------------------- |
| Promise\<boolean> | Promise形式返回boolean代表是否启用。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityInfo(bundleName, abilityName).then((abilityInfo)=>{
    bundle.isAbilityEnabled(abilityInfo).then((data) => {
        console.info('Operation successful. Data: ' + JSON.stringify(data));
    }).catch((error) => {
        console.error('Operation failed. Cause: ' + JSON.stringify(error));
    })
})
```

## bundle.isAbilityEnabled<sup>8+</sup>

isAbilityEnabled(info : AbilityInfo, callback : AsyncCallback\<boolean>): void

以异步方法根据给定的AbilityInfo查询ability是否已经启用，使用callback形式返回结果。

**需要权限：**

无

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称       | 类型                      | 必填   | 描述              |
| -------- | ----------------------- | ---- | --------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md)             | 是    | Ability的配置信息    |
| callback | AsyncCallback\<boolean> | 是    | 返回boolean代表是否启用 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityInfo(bundleName, abilityName).then((abilityInfo)=>{
    bundle.isAbilityEnabled(abilityInfo, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
    })
})
```

## bundle.isApplicationEnabled<sup>8+</sup>

isApplicationEnabled(bundleName: string): Promise\<boolean>

以异步方法根据给定的bundleName查询指定应用程序是否已经启用，使用Promise形式返回结果。

**需要权限：**

无

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型     | 必填   | 描述           |
| ---------- | ------ | ---- | ------------ |
| bundleName | string | 是    | 要查询的应用程序包名称。 |

**返回值：**

| 类型                | 说明                        |
| ----------------- | ------------------------- |
| Promise\<boolean> | Promise形式返回boolean代表是否启用。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
bundle.isApplicationEnabled(bundleName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.isApplicationEnabled<sup>8+</sup>

isApplicationEnabled(bundleName: string, callback : AsyncCallback\<boolean>): void

以异步方法根据给定的bundleName查询指定应用程序是否已经启用，使用callback形式返回结果。

**需要权限：**

无

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型                      | 必填   | 描述              |
| ---------- | ----------------------- | ---- | --------------- |
| bundleName | string                  | 是    | 要查询的应用程序包名称。    |
| callback   | AsyncCallback\<boolean> | 是    | 返回boolean代表是否启用 |

**示例：**

```js
let bundleName = "com.example.myapplication";
bundle.isApplicationEnabled(bundleName, (err, data) => {
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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型     | 必填   | 描述                                    |
| ----------- | ------ | ---- | ------------------------------------- |
| want        | [Want](js-apis-application-Want.md)   | 是    | 包含要查询的应用程序包名称的意图。                     |
| bundleFlags | number | 是    | 用于指定返回abilityInfo信息。默认值：0，取值范围：大于等于0。 |
| userId      | number | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0           |

**返回值：**

| 类型                           | 说明                    |
| ---------------------------- | --------------------- |
| Promise<Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>> | Promise形式返回Ability信息。 |

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

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                 | 必填   | 描述                                    |
| ----------- | ---------------------------------- | ---- | ------------------------------------- |
| want        | [Want](js-apis-application-Want.md)                               | 是    | 指示包含要查询的应用程序包名称的意图。                   |
| bundleFlags | number                             | 是    | 用于指定返回abilityInfo信息。默认值：0，取值范围：大于等于0。 |
| userId      | number                             | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0           |
| callback    | AsyncCallback<Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>> | 是    | 程序启动作为入参的回调函数，返回Ability信息。            |

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

queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback<Array\<AbilityInfo>>): void;

以异步方法根据给定的意图获取Ability信息，使用callback形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                 | 必填   | 描述                                    |
| ----------- | ---------------------------------- | ---- | ------------------------------------- |
| want        | [Want](js-apis-application-Want.md)                               | 是    | 指示包含要查询的应用程序包名称的意图。                   |
| bundleFlags | number                             | 是    | 用于指定返回abilityInfo信息。默认值：0，取值范围：大于等于0。 |
| callback    | AsyncCallback<Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>> | 是    | 程序启动作为入参的回调函数，返回Ability信息。            |

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



## bundle.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string): Promise\<Want>

以异步方法查询拉起指定应用的want对象，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型     | 必填   | 描述           |
| ---------- | ------ | ---- | ------------ |
| bundleName | string | 是    | 要查询的应用程序包名称。 |

**返回值：**
| 类型             | 说明                                     |
| -------------- | -------------------------------------- |
| Promise\<[Want](js-apis-application-Want.md)> | 返回值为Promise对象，Promise中包含拉起指定应用的Want对象。 |

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

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void;

以异步方法查询拉起指定应用的want对象，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称         | 类型                   | 必填   | 描述                             |
| ---------- | -------------------- | ---- | ------------------------------ |
| bundleName | string               | 是    | 要查询的应用程序包名称。                   |
| callback   | AsyncCallback\<[Want](js-apis-application-Want.md)> | 是    | 程序启动作为入参的回调函数，返回拉起指定应用的want对象。 |

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


## bundle.getNameForUid<sup>8+</sup>

getNameForUid(uid: number): Promise\<string>

以异步方法通过uid获取对应的包名，使用Promise形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称   | 类型     | 必填   | 描述       |
| ---- | ------ | ---- | -------- |
| uid  | number | 是    | 要查询的uid。 |

**返回值：**
| 类型               | 说明                                |
| ---------------- | --------------------------------- |
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

## bundle.getNameForUid<sup>8+</sup>

getNameForUid(uid: number, callback: AsyncCallback\<string>) : void

以异步方法通过uid获取对应的包名，使用callback形式返回结果。

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称       | 类型                     | 必填   | 描述                        |
| -------- | ---------------------- | ---- | ------------------------- |
| uid      | number                 | 是    | 要查询的uid。                  |
| callback | AsyncCallback\<string> | 是    | 程序启动作为入参的回调函数，返回指定uid的包名。 |

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


## bundle.getAbilityIcon<sup>8+</sup>

getAbilityIcon(bundleName: string, abilityName: string): Promise\<image.PixelMap>;

以异步方法通过bundleName和abilityName获取对应Icon的[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                       | 必填   | 描述                                       |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | 是    | 要查询的bundleName。                          |
| abilityName | string                                   | 是    | 要查询的abilityName。                         |

**返回值：**
| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise\<image.PixelMap> | 返回值为[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityIcon(bundleName, abilityName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getAbilityIcon<sup>8+</sup>

getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;

以异步方法通过bundleName和abilityName获取对应Icon的[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                       | 必填   | 描述                                       |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | 是    | 要查询的bundleName。                          |
| abilityName | string                                   | 是    | 要查询的abilityName。                         |
| callback   | AsyncCallback\<image.PixelMap> | 是   | 程序启动作为入参的回调函数，返回指定[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityIcon(bundleName, abilityName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getAbilityIcon<sup>9+</sup>

getAbilityIcon(bundleName: string, moduleName: string, abilityName: string): Promise\<image.PixelMap>;

以异步方法通过bundleName、moduleName和abilityName获取对应Icon的[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                       | 必填   | 描述                                       |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | 是    | 要查询的bundleName。                          |
| moduleName  | string                                   | 是    | moduleName。                          |
| abilityName | string                                   | 是    | 要查询的abilityName。                         |

**返回值：**
| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise\<image.PixelMap> | 返回值为[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let moduleName = "entry";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityIcon(bundleName, moduleName, abilityName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getAbilityIcon<sup>9+</sup>

getAbilityIcon(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;

以异步方法通过bundleName、moduleName和abilityName获取对应Icon的[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称          | 类型                                       | 必填   | 描述                                       |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | 是    | 要查询的bundleName。                          |
| moduleName  | string                                   | 是    | moduleName。                          |
| abilityName | string                                   | 是    | 要查询的abilityName。                         |
| callback   | AsyncCallback\<image.PixelMap> | 是   | 程序启动作为入参的回调函数，返回指定[PixelMap](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-image.md)。 |

**示例：**

```js
let bundleName = "com.example.myapplication";
let moduleName = "entry";
let abilityName = "com.example.myapplication.MainAbility";
bundle.getAbilityIcon(bundleName, moduleName, abilityName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.queryExtensionAbilityInfos<sup>9+</sup>

queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, userId?: number): Promise<Array\<ExtensionAbilityInfo>>

以异步方法根据给定的意图获取ExtensionAbility信息，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称             | 类型     | 必填   | 描述                                       |
| -------------- | ------ | ---- | ---------------------------------------- |
| want           | [Want](js-apis-application-Want.md)   | 是    | 包含要查询的应用程序包名称的意图。                        |
| extensionType  | number | 是    | 用于指定查找的extensionAbilityInfo的类型。 默认值：0，取值范围：枚举值: [ExtensionAbilityType](#ExtensionAbilityType9) |
| extensionFlags | number | 是    | 用于指定返回ExtensionAbilityInfo信息。默认值：0，取值范围：枚举值: [ExtensionFlags](#ExtensionFlag9) |
| userId         | number | 否    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0              |

**返回值：**

| 类型                                    | 说明                             |
| ------------------------------------- | ------------------------------ |
| Promise<Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)>> | Promise形式返回ExtensionAbility信息。 |

**示例：**

```js
let extensionType = 0;
let extensionFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryExtensionAbilityInfos(want, extensionType, extensionFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.queryExtensionAbilityInfos<sup>9+</sup>

queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, userId: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

以异步方法根据给定的意图获取ExtensionAbility信息，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称           | 类型                                                         | 必填 | 描述                                                         |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want           | [Want](js-apis-application-Want.md)                                                        | 是   | 指示包含要查询的应用程序包名称的意图。                       |
| extensionType  | number                                                       | 是   | 用于指定查找的extensionAbilityInfo的类型。 默认值：0，取值范围：枚举值: [ExtensionAbilityType](#ExtensionAbilityType9) |
| extensionFlags | number                                                       | 是   | 用于指定返回ExtensionAbilityInfo信息。默认值：0，取值范围：枚举值:  [ExtensionFlags](#ExtensionFlag9)|
| userId         | number                                                       | 是   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0          |
| callback       | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)>> | 是   | 程序启动作为入参的回调函数，返回ExtensionAbility信息。       |

**示例：**

```js
let extensionType = 0;
let extensionFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
const receiver = function onReceive(err, data) {
    var errValue = JSON.stringify(err)
    var dataValue = JSON.stringify(data)
    console.error('Operation failed. Cause: ' + errValue);
    console.error('Operation failed. Cause: ' + dataValue);
}
bundle.queryExtensionAbilityInfos(want, extensionType, extensionFlags, userId, receiver)
```

## bundle.queryExtensionAbilityInfos<sup>9+</sup>

queryExtensionAbilityInfos(want: Want, extensionType: number, extensionFlags: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void;

以异步方法根据给定的意图获取ExtensionAbility信息，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**系统能力：**

SystemCapability.BundleManager.BundleFramework

**参数：**

| 名称             | 类型                                       | 必填   | 描述                                       |
| -------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| want           | [Want](js-apis-application-Want.md)                                     | 是    | 指示包含要查询的应用程序包名称的意图。                      |
| extensionType  | number                                   | 是    | 用于指定查找的extensionAbilityInfo的类型。 默认值：0，取值范围：枚举值: [ExtensionAbilityType](#ExtensionAbilityType9) |
| extensionFlags | number                                   | 是    | 用于指定返回ExtensionAbilityInfo信息。默认值：0，取值范围：枚举值: [ExtensionFlags](#ExtensionFlag9) |
| callback       | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)>> | 是    | 程序启动作为入参的回调函数，返回ExtensionAbility信息。      |

**示例：**

```js
let extensionType = 0;
let extensionFlags = 0;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
const receiver = function onReceive(err, data) {
    var errValue = JSON.stringify(err)
    var dataValue = JSON.stringify(data)
    console.error('Operation failed. Cause: ' + errValue);
    console.error('Operation failed. Cause: ' + dataValue);
}
bundle.queryExtensionAbilityInfos(want, extensionType, extensionFlags, receiver)
```

## InstallErrorCode

 **系统能力:** SystemCapability.BundleManager.BundleFramework

| 名称                                       | 默认值  | 说明                        |
| ---------------------------------------- | ---- | ------------------------- |
| SUCCESS                                  | 0    | 安装成功                      |
| STATUS_INSTALL_FAILURE                   | 1    | 安装失败（不存在安装的应用）            |
| STATUS_INSTALL_FAILURE_ABORTED           | 2    | 安装中止                      |
| STATUS_INSTALL_FAILURE_INVALID           | 3    | 安装参数无效                    |
| STATUS_INSTALL_FAILURE_CONFLICT          | 4    | 安装冲突 （常见于升级和已有应用基本信息不一致）  |
| STATUS_INSTALL_FAILURE_STORAGE           | 5    | 存储包信息失败                   |
| STATUS_INSTALL_FAILURE_INCOMPATIBLE      | 6    | 安装不兼容（常见于版本降级安装或者签名信息错误）  |
| STATUS_UNINSTALL_FAILURE                 | 7    | 卸载失败 （不存在卸载的应用）           |
| STATUS_UNINSTALL_FAILURE_BLOCKED         | 8    | 卸载中止 （没有使用）               |
| STATUS_UNINSTALL_FAILURE_ABORTED         | 9    | 卸载中止 （参数无效导致）             |
| STATUS_UNINSTALL_FAILURE_CONFLICT        | 10   | 卸载冲突 （卸载系统应用失败， 结束应用进程失败） |
| STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT  | 0x0B | 安装失败 （下载超时）               |
| STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED   | 0x0C | 安装失败 （下载失败）               |
| STATUS_RECOVER_FAILURE_INVALID<sup>8+</sup> | 0x0D | 恢复预置应用失败                  |
| STATUS_ABILITY_NOT_FOUND                 | 0x40 | Ability未找到                |
| STATUS_BMS_SERVICE_ERROR                 | 0x41 | BMS服务错误                   |
| STATUS_FAILED_NO_SPACE_LEFT<sup>8+</sup> | 0x42 | 设备空间不足                    |
| STATUS_GRANT_REQUEST_PERMISSIONS_FAILED<sup>8+</sup> | 0x43 | 应用授权失败                    |
| STATUS_INSTALL_PERMISSION_DENIED<sup>8+</sup> | 0x44 | 安装权限拒绝                    |
| STATUS_UNINSTALL_PERMISSION_DENIED<sup>8+</sup> | 0x45 | 卸载权限拒绝                    |

## BundleFlag

包的标志

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                                       | 默认值        | 说明                  |
| ---------------------------------------- | ---------- | ------------------- |
| GET_BUNDLE_DEFAULT                       | 0x00000000 | 获取默认的应用信息           |
| GET_BUNDLE_WITH_ABILITIES                | 0x00000001 | 获取包括Ability信息的包信息   |
| GET_ABILITY_INFO_WITH_PERMISSION         | 0x00000002 | 获取包括权限的Ability信息    |
| GET_ABILITY_INFO_WITH_APPLICATION        | 0x00000004 | 获取包括应用的Ability信息    |
| GET_APPLICATION_INFO_WITH_PERMISSION     | 0x00000008 | 获取包括权限的应用信息         |
| GET_BUNDLE_WITH_REQUESTED_PERMISSION     | 0x00000010 | 获取包括所需权限的包信息        |
| GET_ABILITY_INFO_WITH_METADATA<sup>8+</sup> | 0x00000020 | 获取ability的元数据信息     |
| GET_BUNDLE_WITH_EXTENSION_ABILITY<sup>9+</sup> | 0x00000020 | 获取包括Ability信息的扩展包信息 |
| GET_APPLICATION_INFO_WITH_METADATA<sup>8+</sup> | 0x00000040 | 获取应用的元数据信息          |
| GET_ABILITY_INFO_SYSTEMAPP_ONLY<sup>8+</sup> | 0x00000080 | 获取仅包括系统应用的ability信息 |
| GET_ABILITY_INFO_WITH_DISABLE<sup>8+</sup> | 0x00000100 | 获取包括被禁用的ability信息   |
| GET_APPLICATION_INFO_WITH_DISABLE<sup>8+</sup> | 0x00000200 | 获取包括被禁用的应用信息        |
| GET_APPLICATION_INFO_WITH_CERTIFICATE_FINGERPRINT <sup>9+</sup> | 0x00000400 | 获取包括应用申请的签名证书的指纹信息        |
| GET_ALL_APPLICATION_INFO                 | 0xFFFF0000 | 获取应用所有的信息           |
| GET_BUNDLE_WITH_HASH_VALUE<sup>9+</sup> | 0x00000030 | 获取包含Hash值的包信息.       |

## BundleOptions

包的选项

 **系统能力:** SystemCapability.BundleManager.BundleFramework

| 名称     | 类型     | 可读   | 可写   | 说明                           |
| ------ | ------ | ---- | ---- | ---------------------------- |
| userId | number | 是    | 是    | 用户ID。默认值：调用方所在用户，取值范围：大于等于0。 |

## AbilityType

Ability类型

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称      | 类型   | 说明                |
| ------- | ---- | ----------------- |
| UNKNOWN | 无    | 未知Ability类型       |
| PAGE    | 无    | Ability有一个UI界面    |
| SERVICE | 无    | Ability没有UI界面     |
| DATA    | 无    | Ability用于提供数据访问服务 |

## DisplayOrientation

屏幕显示方向

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称            | 类型   | 说明            |
| ------------- | ---- | ------------- |
| UNSPECIFIED   | 无    | 屏幕方向--不指定     |
| LANDSCAPE     | 无    | 屏幕方向--横屏      |
| PORTRAIT      | 无    | 屏幕方向--竖屏      |
| FOLLOW_RECENT | 无    | 屏幕方向--紧跟上一个组件 |

## LaunchMode

启动模式

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称        | 类型   | 说明            |
| --------- | ---- | ------------- |
| SINGLETON | 0    | Ability只有一个示例 |
| STANDARD  | 1    | Ability有多个示例  |

## AbilitySubType

Ability的子类型

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称          | 类型   | 说明                   |
| ----------- | ---- | -------------------- |
| UNSPECIFIED | 0    | 未定义Ability子类型        |
| CA          | 1    | Ability子类型是带有 UI 的服务 |

## ExtensionAbilityType<sup>9+</sup>

ExtensionAbility的类型

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                             | 类型   | 说明                        |
| ------------------------------ | ---- | ------------------------- |
| FORM<sup>9+</sup>              | 0    | ExtensionAbility的类型包括卡片   |
| WORK_SCHEDULER<sup>9+</sup>    | 1    | ExtensionAbility的类型包括行程安排 |
| INPUT_METHOD<sup>9+</sup>      | 2    | ExtensionAbility的类型包括输入法  |
| SERVICE<sup>9+</sup>           | 3    | ExtensionAbility的类型包括服务   |
| ACCESSIBILITY<sup>9+</sup>     | 4    | ExtensionAbility的类型包括无障碍  |
| DATA_SHARE<sup>9+</sup>        | 5    | ExtensionAbility的类型包括数据共享 |
| FILE_SHARE<sup>9+</sup>        | 6    | ExtensionAbility的类型包括文件共享 |
| STATIC_SUBSCRIBER<sup>9+</sup> | 7    | ExtensionAbility的类型包括订阅者  |
| WALLPAPER<sup>9+</sup>         | 8    | ExtensionAbility的类型包括墙纸   |
| BACKUP<sup>9+</sup>            | 9    | ExtensionAbility的类型包括数据备份恢复   |
| UNSPECIFIED<sup>9+</sup>       | 20    | ExtensionAbility未指定类型     |

## ExtensionFlag<sup>9+</sup>

扩展标志

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                                       | 默认值        | 说明                             |
| ---------------------------------------- | ---------- | ------------------------------ |
| GET_EXTENSION_INFO_DEFAULT<sup>9+</sup>  | 0x00000000 | 获取默认的extensionAbilityInfo      |
| GET_EXTENSION_INFO_WITH_PERMISSION<sup>9+</sup> | 0x00000002 | 获取携带权限信息的extensionAbilityInfo  |
| GET_EXTENSION_INFO_WITH_APPLICATION<sup>9+</sup> | 0x00000004 | 获取携带应用信息的extensionAbilityInfo  |
| GET_EXTENSION_INFO_WITH_METADATA<sup>9+</sup> | 0x00000020 | 获取携带元数据信息的extensionAbilityInfo |

## ColorMode

颜色模式

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称         | 类型   | 说明   |
| ---------- | ---- | ---- |
| AUTO_MODE  | -1   | 自动模式 |
| DARK_MODE  | 0    | 黑色模式 |
| LIGHT_MODE | 1    | 亮度模式 |


## GrantStatus

授予状态

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework

| 名称                 | 类型   | 说明   |
| ------------------ | ---- | ---- |
| PERMISSION_DENIED  | -1   | 拒绝许可 |
| PERMISSION_GRANTED | 0    | 批准   |
