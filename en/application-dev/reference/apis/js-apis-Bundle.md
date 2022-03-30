# Bundle Module (JavaScript SDK APIs)

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import bundle from '@ohos.bundle';
```

## System Capabilities

SystemCapability.BundleManager.BundleFramework

## Required Permissions

| Required Permissions                                      | Permission Level        | Description       |
| ---------------------------------------- | ------------ | --------- |
| ohos.permission.GET_BUNDLE_INFO          | normal       | Permission to query information about the current application.|
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED| system_basic | Permission to query information about all applications.|
| ohos.permission.INSTALL_BUNDLE           | system_core  | Permission to install or uninstall applications. |

## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<ApplicationInfo>

Obtains the application information based on a given bundle name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | Yes   | Bundle name of the application.                           |
| bundleFlags | number | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.           |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<ApplicationInfo> | Promise used to return the application information.|

**Example**

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

Obtains the application information based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                             | Mandatory  | Description                                     |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| bundleName  | string                          | Yes   | Bundle name of the application.                           |
| bundleFlags | number                          | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number                          | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.           |
| callback    | AsyncCallback\<ApplicationInfo> | Yes   | Callback used to return the application information.                |

**Example**

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

Obtains the application information based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                             | Mandatory  | Description                                     |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| bundleName  | string                          | Yes   | Bundle name of the application.                           |
| bundleFlags | number                          | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback    | AsyncCallback\<ApplicationInfo> | Yes   | Callback used to return the application information.                |

**Example**

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

Obtains the information of all available bundles of a specified user in the system. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type        | Mandatory  | Description                                     |
| ---------- | ---------- | ---- | --------------------------------------- |
| bundleFlag | BundleFlag | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId     | number     | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.           |

**Return value**

| Type                         | Description                        |
| --------------------------- | -------------------------- |
| Promise<Array\<BundleInfo>> | Promise used to return the information of all available bundles.|

**Example**

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

Obtains the information of all available bundles in the system. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type                               | Mandatory  | Description                                     |
| ---------- | --------------------------------- | ---- | --------------------------------------- |
| bundleFlag | BundleFlag                        | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback   | AsyncCallback<Array\<BundleInfo>> | Yes   | Callback used to return the information of all available bundles.       |

**Example**

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

Obtains the information of all available bundles in the system. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type                               | Mandatory  | Description                                     |
| ---------- | --------------------------------- | ---- | --------------------------------------- |
| bundleFlag | BundleFlag                        | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId     | number                            | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.           |
| callback   | AsyncCallback<Array\<BundleInfo>> | Yes   | Callback used to return the information of all available bundles.       |

**Example**

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

Obtains the bundle information based on a given bundle name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type           | Mandatory  | Description                                     |
| ----------- | ------------- | ---- | --------------------------------------- |
| bundleName  | string        | Yes   | Bundle name.                                     |
| bundleFlags | number        | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| options     | BundleOptions | No   | Includes **userId**.                              |

**Return value**

| Type                  | Description                          |
| -------------------- | ---------------------------- |
| Promise\<BundleInfo> | Promise used to return the bundle information.|

**Example**

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

Obtains the bundle information based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                        | Mandatory  | Description                                     |
| ----------- | -------------------------- | ---- | --------------------------------------- |
| bundleName  | string                     | Yes   | Bundle name.                                     |
| bundleFlags | number                     | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback    | AsyncCallback\<BundleInfo> | Yes   | Callback used to return the bundle information.                   |

**Example**

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

Obtains the bundle information based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                        | Mandatory  | Description                                     |
| ----------- | -------------------------- | ---- | --------------------------------------- |
| bundleName  | string                     | Yes   | Bundle name.                                     |
| bundleFlags | number                     | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| options     | BundleOptions              | Yes   | Includes **userId**.                              |
| callback    | AsyncCallback\<BundleInfo> | Yes   | Callback used to return the bundle information.                   |

**Example**

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

Obtains the information about all applications of the specified user. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleFlags | number | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.           |

**Return value**

| Type                              | Description                             |
| -------------------------------- | ------------------------------- |
| Promise<Array\<ApplicationInfo>> | Promise used to return the application information.|

**Example**

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

Obtains the information about all applications of the specified user. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                    | Mandatory  | Description                                     |
| ----------- | -------------------------------------- | ---- | --------------------------------------- |
| bundleFlags | number                                 | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number                                 | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.           |
| callback    | AsyncCallback<Array\<ApplicationInfo>> | Yes   | Callback used to return the application information.                |

**Example**

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

Obtains the information about all applications of the specified user. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                    | Mandatory  | Description                                     |
| ----------- | -------------------------------------- | ---- | --------------------------------------- |
| bundleFlags | number                                 | Yes   | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback    | AsyncCallback<Array\<ApplicationInfo>> | Yes   | Callback used to return the application information.                |

**Example**

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

## bundle.getAbilityInfo

getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>

Obtains the ability information based on a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description              |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of the application.    |
| abilityName | string | Yes   | Ability name.|

**Return value**

| Type                   | Description                   |
| --------------------- | --------------------- |
| Promise\<AbilityInfo> | Promise used to return the ability information.|

**Example**

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

Obtains the ability information based on a given bundle name and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description           |
| ----------- | ------------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of the application.    |
| abilityName | string | Yes   | Ability name.|
| callback    | AsyncCallback\<AbilityInfo> | Yes   | Callback used to return the ability information.|

**Example**

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

## bundle.getAbilityLabel<sup>8+</sup>

getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>

Obtains the application name based on a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description              |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of the application.    |
| abilityName | string | Yes   | Ability name.|

**Return value**

| Type              | Description                |
| ---------------- | ------------------ |
| Promise\<string> | Promise used to return the application name.|

**Example**

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

Obtains the application name based on a given bundle name and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                    | Mandatory  | Description              |
| ----------- | ---------------------- | ---- | ---------------- |
| bundleName  | string                 | Yes   | Bundle name of the application.    |
| abilityName | string                 | Yes   | Ability name.|
| callback    | AsyncCallback\<string> | Yes   | Callback used to return the application name.       |

**Example**

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

## bundle.isAbilityEnabled<sup>8+</sup>

isAbilityEnabled(info: AbilityInfo): Promise\<boolean>

Checks whether an ability is enabled based on a given want. This API uses a promise to return the result.

**Required permissions**

None

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name  | Type         | Mandatory  | Description          |
| ---- | ----------- | ---- | ------------ |
| info | AbilityInfo | Yes   | Ability information.|

**Return value**

| Type               | Description                       |
| ----------------- | ------------------------- |
| Promise\<boolean> | Promise used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
let Info = {
    bundleName : "com.example.myapplication",
    name : "com.example.myapplication.MainAbility"
};
bundle.isAbilityEnabled(Info)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.isAbilityEnabled<sup>8+</sup>

isAbilityEnabled(info : AbilityInfo, callback : AsyncCallback\<boolean>): void

Checks whether an ability is enabled based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

None

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name      | Type                     | Mandatory  | Description             |
| -------- | ----------------------- | ---- | --------------- |
| info     | AbilityInfo             | Yes   | Ability information.   |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
let Info = {
    bundleName : "com.example.myapplication",
    name : "com.example.myapplication.MainAbility"
};
bundle.isAbilityEnabled(Info, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.isApplicationEnabled<sup>8+</sup>

isApplicationEnabled(bundleName: string): Promise\<boolean>

Checks whether an application is enabled based on a given want. This API uses a promise to return the result.

**Required permissions**

None

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type               | Description                       |
| ----------------- | ------------------------- |
| Promise\<boolean> | Promise used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned.|

**Example**

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

Checks whether an application is enabled based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

None

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type                     | Mandatory  | Description             |
| ---------- | ----------------------- | ---- | --------------- |
| bundleName | string                  | Yes   | Bundle name of the application.   |
| callback   | AsyncCallback\<boolean> | Yes   | Callback used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned.|

**Example**

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

Obtains the ability information based on a given want. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | ------------------------------------- |
| want        | Want   | Yes   | Want that contains the bundle name.                    |
| bundleFlags | number | Yes   | Ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.          |

**Return value**

| Type                          | Description                   |
| ---------------------------- | --------------------- |
| Promise\<Array\<AbilityInfo>>| Promise used to return the ability information.|

**Example**

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

queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void

Obtains the ability information based on a given want. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                | Mandatory  | Description                                   |
| ----------- | ---------------------------------- | ---- | ------------------------------------- |
| want        | Want                               | Yes   | Want that contains the bundle name.                  |
| bundleFlags | number                             | Yes   | Ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number                             | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.          |
| callback    | AsyncCallback<Array\<AbilityInfo>> | Yes   | Callback used to return the ability information.           |

**Example**

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

Obtains the ability information based on a given want. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                | Mandatory  | Description                                   |
| ----------- | ---------------------------------- | ---- | ------------------------------------- |
| want        | Want                               | Yes   | Want that contains the bundle name.                  |
| bundleFlags | number                             | Yes   | Ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback    | AsyncCallback<Array\<AbilityInfo>> | Yes   | Callback used to return the ability information.           |

**Example**

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

Obtains the **Want** object that launches the specified application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**
| Type            | Description                                    |
| -------------- | -------------------------------------- |
| Promise\<Want> | Promise used to return the **Want** object.|

**Example**

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

Obtains the **Want** object that launches the specified application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type                  | Mandatory  | Description                            |
| ---------- | -------------------- | ---- | ------------------------------ |
| bundleName | string               | Yes   | Bundle name of the application.                  |
| callback   | AsyncCallback\<Want> | Yes   | Callback used to return the **Want** object.|

**Example**

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

Obtains the bundle name based on a UID. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name  | Type    | Mandatory  | Description      |
| ---- | ------ | ---- | -------- |
| uid  | number | Yes   | UID based on which the bundle name is to obtain.|

**Return value**
| Type              | Description                               |
| ---------------- | --------------------------------- |
| Promise\<string> | Promise used to return the bundle name.|

**Example**

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

Obtains the bundle name based on a UID. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name      | Type                    | Mandatory  | Description                       |
| -------- | ---------------------- | ---- | ------------------------- |
| uid      | number                 | Yes   | UID based on which the bundle name is to obtain.                 |
| callback | AsyncCallback\<string> | Yes   | Callback used to return the bundle name.|

**Example**

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

Obtains the [PixelMap](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-image.md) of the corresponding icon based on a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                      | Mandatory  | Description                                      |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | Yes   | Bundle name based on which the pixel map is to obtain.                         |
| abilityName | string                                   | Yes   | Ability name based on which the pixel map is to obtain.                        |

**Return value**
| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise\<image.PixelMap> | Promise used to return the [PixelMap](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-image.md)>.|

**Example**

```js
let bundleName = com.example.myapplication;
let abilityName = com.example.myapplication.MainAbility;
bundle.getAbilityIcon(bundleName, abilityName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getAbilityIcon<sup>8+</sup>

getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;

Obtains the [PixelMap](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-image.md) of the corresponding icon based on a given bundle name and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                      | Mandatory  | Description                                      |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | Yes   | Bundle name based on which the pixel map is to obtain.                         |
| abilityName | string                                   | Yes   | Ability name based on which the pixel map is to obtain.                        |
| callback   | AsyncCallback\<image.PixelMap> | Yes  | Callback used to return the [PixelMap](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-image.md)>.|

**Example**

```js
let bundleName = com.example.myapplication;
let abilityName = com.example.myapplication.MainAbility;
bundle.getAbilityIcon(bundleName, abilityName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.queryExtensionAbilityInfosByWant<sup>9+</sup>

queryExtensionAbilityInfosByWant(want: Want, extensionFlags: number, userId?: number): Promise<Array\<ExtensionAbilityInfo>>

Obtains the Extension ability information based on a given want. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type    | Mandatory  | Description                                      |
| -------------- | ------ | ---- | ---------------------------------------- |
| want           | Want   | Yes   | Want that contains the bundle name.                       |
| extensionFlags | number | Yes   | Extension ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId         | number | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.             |

**Return value**

| Type                                   | Description                            |
| ------------------------------------- | ------------------------------ |
| Promise<Array\<ExtensionAbilityInfo>> | Promise used to return the Extension ability information.|

**Example**

```js
let extensionFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryExtensionAbilityInfosByWant(want, extensionFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.queryExtensionAbilityInfosByWant<sup>9+</sup>

queryExtensionAbilityInfosByWant(want: Want, extensionFlags: number, userId: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

Obtains the Extension ability information based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type                                      | Mandatory  | Description                                      |
| -------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| want           | Want                                     | Yes   | Want that contains the bundle name.                     |
| extensionFlags | number                                   | Yes   | Extension ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId         | number                                   | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.             |
| callback       | AsyncCallback<Array\<ExtensionAbilityInfo>> | Yes   | Callback used to return the Extension ability information.     |

**Example**

```js
let extensionFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryExtensionAbilityInfosByWant(want, extensionFlags, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.queryExtensionAbilityInfosByWant<sup>9+</sup>

queryExtensionAbilityInfosByWant(want: Want, extensionFlags: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void;

Obtains the Extension ability information based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED, ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type                                      | Mandatory  | Description                                      |
| -------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| want           | Want                                     | Yes   | Want that contains the bundle name.                     |
| extensionFlags | number                                   | Yes   | Extension ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback       | AsyncCallback<Array\<ExtensionAbilityInfo>> | Yes   | Callback used to return the Extension ability information.     |

**Example**

```js
let extensionFlags = 0;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryExtensionAbilityInfosByWant(want, extensionFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## ElementName

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name         | Readable/Writable| Type    | Mandatory  | Description                                      |
| ----------- | ---- | ------ | ---- | ---------------------------------------- |
| deviceId    | Read-only  | string | No   | ID of the device that runs the ability.                     |
| bundleName  | Read-only  | string | Yes   | Bundle name of the ability. If both **bundleName** and **abilityName** are specified in a **Want**, the **Want** can directly match the specified ability.|
| abilityName | Read-only  | string | Yes   | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want**, the **Want** can directly match the specified ability.|
| uri         | Read-only  | string | No   | Resource ID.                                  |
| shortName   | Read-only  | string | No   | Short name of the **ElementName**.                         |

## InstallErrorCode

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                                      | Default Value | Description                       |
| ---------------------------------------- | ---- | ------------------------- |
| SUCCESS                                  | 0    | Installation succeeded.                     |
| STATUS_INSTALL_FAILURE                   | 1    | Installation failed. (The application to be installed does not exist.)           |
| STATUS_INSTALL_FAILURE_ABORTED           | 2    | Installation aborted.                     |
| STATUS_INSTALL_FAILURE_INVALID           | 3    | Invalid installation parameter.                   |
| STATUS_INSTALL_FAILURE_CONFLICT          | 4    | Installation conflict. (The basic information about the application to upgrade is inconsistent with that of the existing application.) |
| STATUS_INSTALL_FAILURE_STORAGE           | 5    | Failed to store the bundle information.                  |
| STATUS_INSTALL_FAILURE_INCOMPATIBLE      | 6    | Installation incompatible. (A downgrade occurs or the signature information is incorrect.) |
| STATUS_UNINSTALL_FAILURE                 | 7    | Uninstallation failed. (The application to be uninstalled does not exist.)          |
| STATUS_UNINSTALL_FAILURE_BLOCKED         | 8    | Uninstallation aborted. (This error code is not in use.)              |
| STATUS_UNINSTALL_FAILURE_ABORTED         | 9    | Uninstallation aborted. (Invalid parameters.)            |
| STATUS_UNINSTALL_FAILURE_CONFLICT        | 10   | Uninstallation conflict. (Failed to uninstall a system application or end the application process.)|
| STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT  | 0x0B | Installation failed. (Download timed out.)              |
| STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED   | 0x0C | Installation failed. (Download failed.)              |
| STATUS_RECOVER_FAILURE_INVALID<sup>8+</sup> | 0x0D | Failed to restore the pre-installed application.                 |
| STATUS_ABILITY_NOT_FOUND                 | 0x40 | Ability not found.               |
| STATUS_BMS_SERVICE_ERROR                 | 0x41 | BMS service error.                  |
| STATUS_FAILED_NO_SPACE_LEFT<sup>8+</sup> | 0x42 | Insufficient device space.                   |
| STATUS_GRANT_REQUEST_PERMISSIONS_FAILED<sup>8+</sup> | 0x43 | Application authorization failed.                   |
| STATUS_INSTALL_PERMISSION_DENIED<sup>8+</sup> | 0x44 | Installation permission denied.                   |
| STATUS_UNINSTALL_PERMISSION_DENIED<sup>8+</sup> | 0x45 | Uninstallation permission denied.                   |

## BundleFlag

Enumerates bundle flags.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                                      | Default Value       | Description                 |
| ---------------------------------------- | ---------- | ------------------- |
| GET_BUNDLE_DEFAULT                       | 0x00000000 | Obtains the default application information.          |
| GET_BUNDLE_WITH_ABILITIES                | 0x00000001 | Obtains the bundle information with the ability information.  |
| GET_ABILITY_INFO_WITH_PERMISSION         | 0x00000002 | Obtains the ability information with the permission information.   |
| GET_ABILITY_INFO_WITH_APPLICATION        | 0x00000004 | Obtains the ability information with the application information.   |
| GET_APPLICATION_INFO_WITH_PERMISSION     | 0x00000008 | Obtains the application information with the permission information.        |
| GET_BUNDLE_WITH_REQUESTED_PERMISSION     | 0x00000010 | Obtains the bundle information with the information about the required permissions.       |
| GET_ABILITY_INFO_WITH_METADATA<sup>8+</sup> | 0x00000020 | Obtains the ability metadata information.    |
| GET_BUNDLE_WITH_EXTENSION_ABILITY<sup>9+</sup> | 0x00000020 | Obtains the bundle information with the Extension ability information.|
| GET_APPLICATION_INFO_WITH_METADATA<sup>8+</sup> | 0x00000040 | Obtains the application metadata information.         |
| GET_ABILITY_INFO_SYSTEMAPP_ONLY<sup>8+</sup> | 0x00000080 | Obtains the ability information with information about system applications.|
| GET_ABILITY_INFO_WITH_DISABLE<sup>8+</sup> | 0x00000100 | Obtains information about disabled abilities.  |
| GET_APPLICATION_INFO_WITH_DISABLE<sup>8+</sup> | 0x00000200 | Obtains information about disabled applications.       |
| GET_ALL_APPLICATION_INFO                 | 0xFFFF0000 | Obtains all application information.          |

## BundleOptions

Describes the bundle options.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name    | Type    | Readable  | Writable  | Description                          |
| ------ | ------ | ---- | ---- | ---------------------------- |
| userId | number | Yes   | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

## BundleInfo

Describes the application bundle information.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                               | Type                          | Readable  | Writable  | Description                   |
| --------------------------------- | ---------------------------- | ---- | ---- | --------------------- |
| name                              | string                       | Yes   | No   | Bundle name.               |
| type                              | string                       | Yes   | No   | Bundle type.                |
| appId                             | string                       | Yes   | No   | ID of the application to which the bundle belongs.          |
| uid                               | number                       | Yes   | No   | UID of the application to which the bundle belongs.         |
| installTime                       | number                       | Yes   | No   | Time when the HAP file was installed.             |
| updateTime                        | number                       | Yes   | No   | Time when the HAP file was updated.             |
| appInfo                           | ApplicationInfo              | Yes   | No   | Application configuration information.            |
| abilityInfos                      | Array\<AbilityInfo>          | Yes   | No   | Ability configuration information.         |
| reqPermissions                    | Array\<string>               | Yes   | No   | Array of the permissions to request from the system.     |
| reqPermissionDetails              | Array\<ReqPermissionDetail>  | Yes   | No   | Detailed information of the permissions to request from the system.|
| vendor                            | string                       | Yes   | No   | Vendor of the bundle.              |
| versionCode                       | number                       | Yes   | No   | Version number of the bundle.              |
| versionName                       | string                       | Yes   | No   | Version description of the bundle.         |
| compatibleVersion                 | number                       | Yes   | No   | Earliest SDK version required for running the bundle.    |
| targetVersion                     | number                       | Yes   | No   | Latest SDK version required for running the bundle.     |
| isCompressNativeLibs              | boolean                      | Yes   | No   | Whether to compress the native library of the bundle. The default value is **true**.  |
| hapModuleInfos                    | Array\<HapModuleInfo>        | Yes   | No   | Module configuration information.              |
| entryModuleName                   | string                       | Yes   | No   | Name of the entry module.           |
| cpuAbi                            | string                       | Yes   | No   | cpuAbi information of the bundle.         |
| isSilentInstallation              | string                       | Yes   | No   | Whether to install the bundle in silent mode.             |
| minCompatibleVersionCode          | number                       | Yes   | No   | Earliest version compatible with the bundle in the distributed scenario.    |
| entryInstallationFree             | boolean                      | Yes   | No   | Whether installation-free is supported for the entry.         |
| reqPermissionStates<sup>8+</sup>  | Array\<number>               | Yes   | No   | Permission grant state.            |
| extensionAbilityInfo<sup>9+</sup> | Array\<ExtensionAbilityInfo> | Yes   | No   | Extended information of the ability.        |

## ApplicationInfo

Describes the application information.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                        | Type                                | Readable  | Writable  | Description                   |
| -------------------------- | ---------------------------------- | ---- | ---- | --------------------- |
| name                       | string                             | Yes   | No   | Application name.              |
| description                | string                             | Yes   | No   | Application description.              |
| descriptionId              | number                             | Yes   | No   | Application description ID.            |
| systemApp                  | boolean                            | Yes   | No   | Whether the application is a system application. The default value is **false**. |
| enabled                    | boolean                            | Yes   | No   | Whether the application is enabled. The default value is **true**. |
| label                      | string                             | Yes   | No   | Application label.              |
| labelId                    | string                             | Yes   | No   | Application label ID.            |
| icon                       | string                             | Yes   | No   | Application icon.              |
| iconId                     | string                             | Yes   | No   | Application icon ID.            |
| process                    | string                             | Yes   | No   | Process in which the application runs. If this parameter is not set, the bundle name is used by default.|
| supportedModes             | number                             | Yes   | No   | Running modes supported by the application.          |
| moduleSourceDirs           | Array\<string>                     | Yes   | No   | Relative paths for storing application resources.       |
| permissions                | Array\<string>                     | Yes   | No   | Permissions required for accessing the application.          |
| moduleInfos                | Array\<ModuleInfo>                 | Yes   | No   | Application module information.            |
| entryDir                   | string                             | Yes   | No   | Path for storing application files.          |
| codePath<sup>8+</sup>      | string                             | Yes   | No   | Installation directory of the application.            |
| metaData<sup>8+</sup>      | Map<string, Array\<CustomizeData>> | Yes   | No   | Custom metadata of the application.          |
| metaData<sup>9+</sup>      | Map<string, Array\<Metadata>>      | Yes   | No   | Metadata of the application.             |
| removable<sup>8+</sup>     | boolean                            | Yes   | No   | Whether the application is removable.          |
| accessTokenId<sup>8+</sup> | number                             | Yes   | No   | Access token ID of the application.   |
| uid<sup>8+</sup>           | number                             | Yes   | No   | UID of the application.             |
| entityType<sup>9+</sup>    | string                             | Yes   | No   | Entity type of the application.            |

## ModuleInfo

Describes the module information of the application.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name             | Type    | Readable  | Writable  | Description  |
| --------------- | ------ | ---- | ---- | ---- |
| moduleName      | string | Yes   | No   | Module name.|
| moduleSourceDir | string | Yes   | No   | Installation directory.|

## CustomizeData

Describes the custom metadata.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                | Type    | Readable  | Writable  | Description      |
| ------------------ | ------ | ---- | ---- | -------- |
| name               | string | Yes   | Yes   | Custom metadata name.|
| value              | string | Yes   | Yes   | Custom metadata value. |
| extra<sup>8+</sup> | string | Yes   | Yes   | Custom resources.   |


## HapModuleInfo

Describes the HAP module information.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                               | Type                          | Readable  | Writable  | Description                |
| --------------------------------- | ---------------------------- | ---- | ---- | ------------------ |
| name                              | string                       | Yes   | No   | Module name.              |
| description                       | string                       | Yes   | No   | Module description.            |
| descriptionId                     | number                       | Yes   | No   | Module description ID.            |
| icon                              | string                       | Yes   | No   | Module icon.              |
| label                             | string                       | Yes   | No   | Module label.              |
| labelId                           | number                       | Yes   | No   | Module label ID.            |
| iconId                            | number                       | Yes   | No   | Module icon ID.            |
| backgroundImg                     | string                       | Yes   | No   | Module background image.            |
| supportedModes                    | number                       | Yes   | No   | Modes supported by the module.           |
| reqCapabilities                   | Array\<string>               | Yes   | No   | Capabilities required for module running.         |
| deviceTypes                       | Array\<string>               | Yes   | No   | An array of supported device types.         |
| abilityInfo                       | Array\<AbilityInfo>          | Yes   | No   | Ability information.         |
| moduleName                        | string                       | Yes   | No   | Module name.               |
| mainAbilityName                   | string                       | Yes   | No   | Name of the entry ability.       |
| installationFree                  | boolean                      | Yes   | No   | Whether installation-free is supported.           |
| mainElementName<sup>9+</sup>      | string                       | Yes   | No   | Information about the entry ability.       |
| extensionAbilityInfo<sup>9+</sup> | Array\<ExtensionAbilityInfo> | Yes   | No   | Extension ability information.|
| metadata<sup>9+</sup>             | Array\<Metadata>             | Yes   | No   | Metadata of the ability.       |

## ReqPermissionDetail

Describes the detailed information of the permissions to request from the system.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name       | Type       | Readable  | Writable  | Description        |
| --------- | --------- | ---- | ---- | ---------- |
| name      | string    | Yes   | Yes   | Name of the permission to request. |
| reason    | string    | Yes   | Yes   | Reason for requesting the permission. |
| usedScene | UsedScene | Yes   | Yes   | Application scenario and timing for using the permission.|

## UsedScene

Describes the application scenario and timing for using the permission.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name       | Type            | Readable  | Writable  | Description              |
| --------- | -------------- | ---- | ---- | ---------------- |
| abilities | Array\<string> | Yes   | Yes   | Abilities that use the permission.|
| when      | string         | Yes   | Yes   | Time when the permission is used.        |


## AbilityInfo

Describes the ability information.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                   | Type                   | Readable  | Writable  | Description                      |
| --------------------- | --------------------- | ---- | ---- | ------------------------ |
| bundleName            | string                | Yes   | No   | Application bundle name.                    |
| name                  | string                | Yes   | No   | Ability name.               |
| label                 | string                | Yes   | No   | Ability name visible to users.         |
| description           | string                | Yes   | No   | Ability description.              |
| icon                  | string                | Yes   | No   | Index of the ability icon resource file.        |
| descriptionId         | number                | Yes   | No   | Ability description ID.            |
| iconId                | number                | Yes   | No   | Ability icon ID.            |
| moduleName            | string                | Yes   | No   | Name of the HAP file to which the ability belongs.       |
| process               | string                | Yes   | No   | Process in which this ability runs. If this parameter is not set, the bundle name is used by default.|
| targetAbility         | string                | Yes   | No   | Target ability that the ability alias points to.   |
| backgroundModes       | number                | Yes   | No   | Background service mode of the ability.               |
| isVisible             | boolean               | Yes   | No   | Whether the ability can be called by other applications.    |
| formEnabled           | boolean               | Yes   | No   | Whether the ability provides the service widget capability.       |
| type                  | AbilityType           | Yes   | No   | Ability type.               |
| orientation           | DisplayOrientation    | Yes   | No   | Ability display orientation.            |
| launchMode            | LaunchMode            | Yes   | No   | Ability launch mode.            |
| permissions           | Array\<string>        | Yes   | No   | Permissions required for other applications to call the ability.|
| deviceTypes           | Array\<string>        | Yes   | No   | Device types supported by the ability.          |
| deviceCapabilities    | Array\<string>        | Yes   | No   | Device capabilities required for the ability.          |
| readPermission        | string                | Yes   | No   | Permission required for reading the ability data.        |
| writePermission       | string                | Yes   | No   | Permission required for writing data to the ability.        |
| applicationInfo       | ApplicationInfo       | Yes   | No   | Application configuration information.               |
| uri                   | string                | Yes   | No   | URI of the ability.  |
| labelId               | number                | Yes   | No   | Ability label ID.            |
| subType               | AbilitySubType        | Yes   | No   | Subtype of the template that can be used by the ability.     |
| metaData<sup>8+</sup> | Array\<CustomizeData> | Yes   | No   | Custom information of the ability.           |
| metaData<sup>9+</sup> | Array\<Metadata>      | Yes   | No   | Metadata of the ability.             |
| enabled<sup>8+</sup>  | boolean               | Yes   | No   | Whether the ability is enabled.             |

## AbilityType

Enumerates ability types.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name     | Type  | Description               |
| ------- | ---- | ----------------- |
| UNKNOWN | None   | Unknown ability type.      |
| PAGE    | None   | Ability that has a UI.   |
| SERVICE | None   | Ability that does not have a UI.    |
| DATA    | None   | Ability that is used to provide data access services.|

## DisplayOrientation

Enumerates display orientations.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name           | Type  | Description           |
| ------------- | ---- | ------------- |
| UNSPECIFIED   | None   | The system automatically determines the display orientation.    |
| LANDSCAPE     | None   | Landscape orientation.     |
| PORTRAIT      | None   | Portrait orientation.     |
| FOLLOW_RECENT | None   | The page ability orientation is the same as that of the nearest ability in the stack.|

## LaunchMode

Enumerates launch modes.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name       | Type  | Description           |
| --------- | ---- | ------------- |
| SINGLETON | 0    | The ability has only one instance.|
| STANDARD  | 1    | The ability can have multiple instances. |

## AbilitySubType

Enumerates ability subtypes.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name         | Type  | Description                  |
| ----------- | ---- | -------------------- |
| UNSPECIFIED | 0    | Undefined ability subtype.       |
| CA          | 1    | Ability that has a UI.|


## ExtensionAbilityType<sup>9+</sup>

Enumerates Extension ability types.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                            | Type  | Description                       |
| ------------------------------ | ---- | ------------------------- |
| FORM<sup>9+</sup>              | 0    | Form included.  |
| WORK_SCHEDULER<sup>9+</sup>    | 1    | Work scheduler included.|
| INPUT_METHOD<sup>9+</sup>      | 2    | Input method included. |
| SERVICE<sup>9+</sup>           | 3    | Service included.  |
| ACCESSIBILITY<sup>9+</sup>     | 4    | Accessibility included. |
| DATA_SHARE<sup>9+</sup>        | 5    | Data sharing included.|
| FILE_SHARE<sup>9+</sup>        | 6    | File sharing included.|
| STATIC_SUBSCRIBER<sup>9+</sup> | 7    | Subscribers included. |
| WALLPAPER<sup>9+</sup>         | 8    | Wallpaper included.  |
| UNSPECIFIED<sup>9+</sup>       | 9    | Unspecified type.    |

## ExtensionFlag<sup>9+</sup>

Enumerates Extension flags.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                                      | Default Value       | Description                            |
| ---------------------------------------- | ---------- | ------------------------------ |
| GET_EXTENSION_INFO_DEFAULT<sup>9+</sup>  | 0x00000000 | Obtains the default Extension ability information.     |
| GET_EXTENSION_INFO_WITH_PERMISSION<sup>9+</sup> | 0x00000002 | Obtains the Extension ability information that carries permission information. |
| GET_EXTENSION_INFO_WITH_APPLICATION<sup>9+</sup> | 0x00000004 | Obtains the Extension ability information that carries application information. |
| GET_EXTENSION_INFO_WITH_METADATA<sup>9+</sup> | 0x00000020 | Obtains the Extension ability information that carries metadata information.|


## ColorMode

Enumerates color modes.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name        | Type  | Description  |
| ---------- | ---- | ---- |
| AUTO_MODE  | -1   | Automatic mode.|
| DARK_MODE  | 0    | Dark mode.|
| LIGHT_MODE | 1    | Light mode.|


## GrantStatus

Enumerates permission grant statuses.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                | Type  | Description  |
| ------------------ | ---- | ---- |
| PERMISSION_DENIED  | -1   | Permission denied.|
| PERMISSION_GRANTED | 0    | Permission granted.  |


## ExtensionAbilityInfo<sup>9+</sup>

Describes the Extension ability information.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                               | Type                         | Readable  | Writable  | Description                               |
| --------------------------------- | --------------------------- | ---- | ---- | --------------------------------- |
| bundleName<sup>9+</sup>           | string                      | Yes   | No   | Application bundle name.                             |
| moduleName<sup>9+</sup>           | string                      | Yes   | No   | Name of the HAP file to which the Extension ability belongs.       |
| name<sup>9+</sup>                 | string                      | Yes   | No   | Name of the Extension ability.               |
| labelId<sup>9+</sup>              | number                      | Yes   | No   | Label ID of the Extension ability.            |
| descriptionId<sup>9+</sup>        | number                      | Yes   | No   | Description ID of the Extension ability.            |
| iconId<sup>9+</sup>               | number                      | Yes   | No   | Icon ID of the Extension ability.            |
| isVisible<sup>9+</sup>            | boolean                     | Yes   | No   | Whether the Extension ability can be called by other applications.    |
| extensionAbilityType<sup>9+</sup> | bundle.ExtensionAbilityType | Yes   | No   | Type of the Extension ability.               |
| permissions<sup>9+</sup>          | Array\<string>              | Yes   | No   | Permissions required for other applications to call the Extension ability.|
| applicationInfo<sup>9+</sup>      | ApplicationInfo             | Yes   | No   | Application configuration information.                        |
| metaData<sup>9+</sup>             | Array\<Metadata>            | Yes   | No   | Metadata of the Extension ability.             |
| enabled<sup>9+</sup>              | boolean                     | Yes   | No   | Whether the Extension ability is enabled.             |
| readPermission<sup>9+</sup>       | string                      | Yes   | No   | Permission required for reading the Extension ability data.        |
| writePermission<sup>9+</sup>      | string                      | Yes   | No   | Permission required for writing data to the Extension ability.        |


## Metadata<sup>9+</sup>

Describes the metadata information.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                   | Type    | Readable  | Writable  | Description   |
| --------------------- | ------ | ---- | ---- | ----- |
| name<sup>9+</sup>     | string | Yes   | Yes   | Metadata name.|
| value<sup>9+</sup>    | string | Yes   | Yes   | Metadata value. |
| resource<sup>9+</sup> | string | Yes   | Yes   | Metadata resource.|
