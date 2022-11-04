# Bundle

The **Bundle** module provides APIs for querying the information about bundles, applications, abilities, Extension abilities, and application states.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> API version 9 is a canary version for trial use. The APIs of this version may be unstable.
## Modules to Import

```js
import bundle from '@ohos.bundle';
```

## Required Permissions

| Required Permissions                                      | Permission Level    | Description              |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO            | normal       | Permission to query information about a specified application.  |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED| system_basic | Permission to query information about all applications.|
| ohos.permission.INSTALL_BUNDLE             | system_core  | Permission to install or uninstall applications.  |
| ohos.permission.MANAGE_DISPOSED_APP_STATUS | system_core  | Permission to set and query the application disposal status.  |

For details, see "Permission Levels" in [Access Control Overview](../../security/accesstoken-overview.md).

## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<ApplicationInfo>

Obtains the application information based on a given bundle name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes  | Bundle name of an application.                                    |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| userId      | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Promise used to return the application information.|

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

Obtains the application information of the specified user based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName  | string                                                       | Yes  | Bundle name of an application.                                    |
| bundleFlags | number                                                       | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| userId      | number                                                       | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |
| callback    | AsyncCallback\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Yes  | Callback used to return the application information.              |

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

| Name       | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName  | string                                                       | Yes  | Bundle name of an application.                                    |
| bundleFlags | number                                                       | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| callback    | AsyncCallback\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)> | Yes  | Callback used to return the application information.              |

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

## bundle.getApplicationInfoSync<sup>9+</sup>

getApplicationInfoSync(bundleName: string, bundleFlags: number, userId: number): ApplicationInfo;

Obtains the application information of the specified user based on a given bundle name. This API returns the result synchronously.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes  | Bundle name of an application.                                              |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| userId      | number | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |

**Return value**

| Type                                                | Description               |
| ---------------------------------------------------- | ------------------- |
| [ApplicationInfo](js-apis-bundle-ApplicationInfo.md) | **ApplicationInfo** object.|

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 0;
let userId = 100;
var applicationInfo = bundle.getApplicationInfoSync(bundleName, bundleFlags, userId);
console.info('Operation successful. Name:' + applicationInfo.name);
```

## bundle.getApplicationInfoSync<sup>9+</sup>

getApplicationInfoSync(bundleName: string, bundleFlags: number) : ApplicationInfo;

Obtains the application information based on a given bundle name. This API returns the result synchronously.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes  | Bundle name of an application.                                              |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|

**Return value**

| Type                                                | Description               |
| ---------------------------------------------------- | ------------------- |
| [ApplicationInfo](js-apis-bundle-ApplicationInfo.md) | **ApplicationInfo** object.|

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 0;
var applicationInfo = bundle.getApplicationInfoSync(bundleName, bundleFlags);
console.info('Operation successful. Name:' + applicationInfo.name);
```

## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, userId?: number): Promise<Array\<BundleInfo>>

Obtains the information of all available bundles of the specified user in the system. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name      | Type      | Mandatory| Description                                                        |
| ---------- | ---------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| userId     | number     | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |

**Return value**

| Type                         | Description                        |
| --------------------------- | -------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | Promise used to return the information of all available bundles.|

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

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                                                   | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| callback   | AsyncCallback<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | Yes  | Callback used to return the information of all available bundles.      |

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

Obtains the information of all available bundles of the specified user in the system. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                                                   | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| userId     | number                                                       | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |
| callback   | AsyncCallback<Array\<[BundleInfo](js-apis-bundle-BundleInfo.md)>> | Yes  | Callback used to return the information of all available bundles.      |

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
| bundleName  | string        | Yes   | Bundle name of an application.                                     |
| bundleFlags | number        | Yes   | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| options     | [BundleOptions](#bundleoptions) | No   | Includes **userId**.                              |

**Return value**

| Type                  | Description                          |
| -------------------- | ---------------------------- |
| Promise\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Promise used to return the bundle information.|

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

| Name       | Type                                                      | Mandatory| Description                                                        |
| ----------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                                                     | Yes  | Bundle name of an application.                                                        |
| bundleFlags | number                                                     | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Yes  | Callback used to return the bundle information.                    |

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

Obtains the bundle information based on a given bundle name and bundle options. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type                                                      | Mandatory| Description                                                        |
| ----------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                                                     | Yes  | Bundle name of an application.                                                        |
| bundleFlags | number                                                     | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| options     | [BundleOptions](#bundleoptions)                            | Yes  | Includes **userId**.                                                |
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Yes  | Callback used to return the bundle information.                    |

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

## bundle.getBundleInfoSync<sup>9+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number, options: BundleOptions): BundleInfo;

Obtains the bundle information based on a given bundle name and bundle options. This API returns the result synchronously.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type                           | Mandatory| Description                                                        |
| ----------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                          | Yes  | Bundle name of an application.                                              |
| bundleFlags | number                          | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| options     | [BundleOptions](#bundleoptions) | Yes  | Options of the bundle.                                              |

**Return value**

| Type                                      | Description          |
| ------------------------------------------ | -------------- |
| [BundleInfo](js-apis-bundle-BundleInfo.md) | **BundleInfo** object.|

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
let options = {
  "userId" : 100
};
var bundleInfo = bundle.getBundleInfoSync(bundleName, bundleFlags, options);
console.info('Operation successful. Name:' + bundleInfo.name);
```

## bundle.getBundleInfoSync<sup>9+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo;

Obtains the bundle information based on a given bundle name. This API returns the result synchronously.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes  | Bundle name of an application.                                              |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|

**Return value**

| Type                                      | Description          |
| ------------------------------------------ | -------------- |
| [BundleInfo](js-apis-bundle-BundleInfo.md) | **BundleInfo** object.|

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
var bundleInfo = bundle.getBundleInfoSync(bundleName, bundleFlags);
console.info('Operation successful. Name:' + bundleInfo.name);
```

## bundle.getBundleInstaller

getBundleInstaller(): Promise&lt;BundleInstaller&gt;;

Obtains the installation package information. This API uses a promise to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                        | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| Promise<[BundleInstaller](js-apis-bundle-BundleInstaller.md)> | Promise used to return the installation package information.|

## bundle.getBundleInstaller

getBundleInstaller(callback: AsyncCallback&lt;BundleInstaller&gt;): void;

Obtains the installation package information. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                                        | Mandatory| Description            |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| callback | AsyncCallback<[BundleInstaller](js-apis-bundle-BundleInstaller.md)> | Yes  | Callback used to return the installation package information.|

## bundle.cleanBundleCacheFiles<sup>8+</sup>

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

Clears the cache data of an application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.REMOVE_CACHE_FILES

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type               | Mandatory| Description                                 |
| ---------- | ------------------- | ---- | ------------------------------------- |
| bundleName | string              | Yes  | Bundle name of an application.|
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.         |

## bundle.cleanBundleCacheFiles<sup>8+</sup>

cleanBundleCacheFiles(bundleName: string): Promise&lt;void&gt;

Clears the cache data of an application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.REMOVE_CACHE_FILES

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type  | Mandatory| Description                                 |
| ---------- | ------ | ---- | ------------------------------------- |
| bundleName | string | Yes  | Bundle name of an application.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

## bundle.setApplicationEnabled<sup>8+</sup>

setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void;

Sets whether to enable an application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type               | Mandatory| Description                                           |
| ---------- | ------------------- | ---- | ----------------------------------------------- |
| bundleName | string              | Yes  | Bundle name of an application.                               |
| isEnable   | boolean             | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite.|
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.                   |

## bundle.setApplicationEnabled<sup>8+</sup>

setApplicationEnabled(bundleName: string, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable an application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type   | Mandatory| Description                                           |
| ---------- | ------- | ---- | ----------------------------------------------- |
| bundleName | string  | Yes  | Bundle name of an application.                               |
| isEnable   | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

## bundle.setAbilityEnabled<sup>8+</sup>

setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void;

Sets whether to enable an ability. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                        | Mandatory| Description                                           |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.                                  |
| isEnable | boolean                                      | Yes  | Whether to enable the ability. The value **true** means to enable the ability, and **false** means the opposite.|
| callback | AsyncCallback\<void>                          | Yes  | Callback used to return the result.                   |

## bundle.setAbilityEnabled<sup>8+</sup>

setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable an ability. This API uses a promise to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                        | Mandatory| Description                                           |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.                                  |
| isEnable | boolean                                      | Yes  | Whether to enable the ability. The value **true** means to enable the ability, and **false** means the opposite.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

## bundle.getPermissionDef<sup>8+</sup>

getPermissionDef(permissionName: string, callback: AsyncCallback&lt;PermissionDef&gt;): void;

Obtains the permission details by permission name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name          | Type                                                        | Mandatory| Description                                            |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| permissionName | string                                                       | Yes  | Name of the permission.                                |
| callback       | AsyncCallback<[PermissionDef](js-apis-bundle-PermissionDef)> | Yes  | Callback used to return the permission details.|

## bundle.getPermissionDef<sup>8+</sup>

getPermissionDef(permissionName: string): Promise&lt;PermissionDef&gt;

Obtains the permission details by permission name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name          | Type  | Mandatory| Description            |
| -------------- | ------ | ---- | ---------------- |
| permissionName | string | Yes  | Name of the permission.|

**Return value**

| Type                                                  | Description                                                  |
| ------------------------------------------------------ | ------------------------------------------------------ |
| Promise<[PermissionDef](js-apis-bundle-PermissionDef)> | Promise used to return the permission details.|

## bundle.setModuleUpgradeFlag<sup>9+</sup>

setModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag, callback: AsyncCallback&lt;void&gt;):void;

Sets whether the module needs an upgrade. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type                       | Mandatory| Description                        |
| ----------- | --------------------------- | ---- | ---------------------------- |
| bundleName  | string                      | Yes  | Bundle name of an application.            |
| moduleName  | string                      | Yes  | Module name of the application.          |
| upgradeFlag | [UpgradeFlag](#upgradeflag) | Yes  | Upgrade flag, which is used only by the internal system.      |
| callback    | AsyncCallback\<void>         | Yes  | Callback used to return the result.|

## bundle.setModuleUpgradeFlag<sup>9+</sup>

setModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag): Promise&lt;void&gt;

Sets whether the module needs an upgrade. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name       | Type                       | Mandatory| Description                  |
| ----------- | --------------------------- | ---- | ---------------------- |
| bundleName  | string                      | Yes  | Bundle name of an application.      |
| moduleName  | string                      | Yes  | Module name of the application.    |
| upgradeFlag | [UpgradeFlag](#upgradeflag) | Yes  | Upgrade flag, which is for internal use only.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

## bundle.isModuleRemovable<sup>9+</sup>

isModuleRemovable(bundleName: string, moduleName: string, callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether a module is removable. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                  | Mandatory| Description                                         |
| ---------- | ---------------------- | ---- | --------------------------------------------- |
| bundleName | string                 | Yes  | Bundle name of an application.                             |
| moduleName | string                 | Yes  | Module name of the application.                           |
| callback   | AsyncCallback\<boolean> | Yes  | Callback used to return the result. If the module is removable, **true** is returned. Otherwise, **false** is returned.|

## bundle.isModuleRemovable<sup>9+</sup>

isModuleRemovable(bundleName: string, moduleName: string): Promise&lt;boolean&gt;

Checks whether a module is removable. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type  | Mandatory| Description              |
| ---------- | ------ | ---- | ------------------ |
| bundleName | string | Yes  | Bundle name of an application.  |
| moduleName | string | Yes  | Module name of the application.|

**Return value**

| Type            | Description                        |
| ---------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. If the module is removable, **true** is returned. Otherwise, **false** is returned.|

## bundle.getBundlePackInfo<sup>9+</sup>

getBundlePackInfo(bundleName: string, bundlePackFlag : pack.BundlePackFlag, callback: AsyncCallback&lt;pack.BundlePackInfo&gt;): void;

Obtains the bundle package information based on a given bundle name and bundle flags. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name          | Type                                                        | Mandatory| Description                                                |
| -------------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| bundleName     | string                                                       | Yes  | Bundle name of an application.                                    |
| bundlePackFlag | pack.BundlePackFlag            | Yes  | Flags of the bundle package.                              |
| callback       | AsyncCallback<pack.BundlePackInfo> | Yes  | Callback used to return the bundle package information.|

## bundle.getBundlePackInfo<sup>9+</sup>

getBundlePackInfo(bundleName: string, bundlePackFlag : pack.BundlePackFlag): Promise&lt;pack.BundlePackInfo&gt;;

Obtains the bundle package information based on a given bundle name and bundle flags. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name          | Type                                             | Mandatory| Description                  |
| -------------- | ------------------------------------------------- | ---- | ---------------------- |
| bundleName     | string                                            | Yes  | Bundle name of an application.      |
| bundlePackFlag | pack.BundlePackFlag | Yes  | Flags of the bundle package.|

**Return value**

| Type                         | Description                                            |
| ---------------------------- | ------------------------------------------------------ |
| Promise<pack.BundlePackInfo> | Promise used to return the bundle package information. |

## bundle.getDispatcherVersion<sup>9+</sup>

getDispatcherVersion(callback: AsyncCallback&lt;DispatchInfo&gt;): void;

Obtains the dispatcher version. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                                  | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[DispatchInfo](js-apis-dispatchInfo.md)> | Yes  | Callback used to return the [DispatchInfo](js-apis-dispatchInfo.md).|

## bundle.getDispatcherVersion<sup>9+</sup>

getDispatcherVersion(): Promise&lt;DispatchInfo&gt;;

Obtains the dispatcher version. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                            | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| Promise<[DispatchInfo](js-apis-dispatchInfo.md)> | Promise used to return the [DispatchInfo](js-apis-dispatchInfo.md).|

## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, userId?: number): Promise<Array\<ApplicationInfo>>

Obtains the information about all applications of the specified user. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| userId      | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |

**Return value**

| Type                              | Description                             |
| -------------------------------- | ------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | Promise used to return the application information.|

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

| Name       | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number                                                       | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| userId      | number                                                       | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |
| callback    | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | Yes  | Callback used to return the application information.              |

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

Obtains the information about all applications. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number                                                       | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| callback    | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundle-ApplicationInfo.md)>> | Yes  | Callback used to return the application information.              |

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

## bundle.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number) : Promise\<BundleInfo>

Obtains information about the bundles contained in a HAP file. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| hapFilePath | string | Yes   | Path where the HAP file is stored. The path should point to the relative directory of the current application's data directory.|
| bundleFlags | number | Yes   | Flags used to specify information contained in the **BundleInfo** object that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|

**Return value**
| Type            | Description                                    |
| -------------- | -------------------------------------- |
| Promise\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Promise used to return the information about the bundles.|

**Example**

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

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>) : void

Obtains information about the bundles contained in a HAP file. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| hapFilePath | string | Yes   | Path where the HAP file is stored. The path should point to the relative directory of the current application's data directory.|
| bundleFlags | number | Yes   | Flags used to specify information contained in the **BundleInfo** object that will be returned. The default value is **0**. For details on the available enumerated values, see the bundle information flags in [BundleFlag](#bundleflag).|
| callback| AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Yes   | Callback used to return the information about the bundles.|

**Example**

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

Obtains the ability information based on a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description              |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of an application.    |
| abilityName | string | Yes   | Ability name.|

**Return value**

| Type                   | Description                   |
| --------------------- | --------------------- |
| Promise\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Promise used to return the ability information.|

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
| bundleName  | string | Yes   | Bundle name of an application.    |
| abilityName | string | Yes   | Ability name.|
| callback    | AsyncCallback\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Yes   | Callback used to return the ability information.|

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
## bundle.getAbilityInfo<sup>9+</sup>

getAbilityInfo(bundleName: string, moduleName: string, abilityName: string): Promise\<AbilityInfo>

Obtains the ability information based on a given bundle name, module name, and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description              |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of an application.    |
| moduleName  | string | Yes   | Module name of the application.    |
| abilityName | string | Yes   | Ability name.|

**Return value**

| Type                   | Description                   |
| --------------------- | --------------------- |
| Promise\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Promise used to return the ability information.|

**Example**

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

Obtains the ability information based on a given bundle name, module name, and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description           |
| ----------- | ------------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of an application.    |
| moduleName  | string | Yes   | Module name of the application.    |
| abilityName | string | Yes   | Ability name.|
| callback    | AsyncCallback\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)> | Yes   | Callback used to return the ability information.|

**Example**

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

Obtains the application name based on a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description              |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of an application.    |
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
| bundleName  | string                 | Yes   | Bundle name of an application.    |
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
## bundle.getAbilityLabel<sup>9+</sup>

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>

Obtains the application name based on a given bundle name, module name, and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type    | Mandatory  | Description              |
| ----------- | ------ | ---- | ---------------- |
| bundleName  | string | Yes   | Bundle name of an application.    |
| moduleName  | string | Yes   | Module name of the application.    |
| abilityName | string | Yes   | Ability name.|

**Return value**

| Type              | Description                |
| ---------------- | ------------------ |
| Promise\<string> | Promise used to return the application name.|

**Example**

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

Obtains the application name based on a given bundle name, module name, and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                    | Mandatory  | Description              |
| ----------- | ---------------------- | ---- | ---------------- |
| bundleName  | string                 | Yes   | Bundle name of an application.    |
| moduleName  | string | Yes   | Module name of the application.    |
| abilityName | string                 | Yes   | Ability name.|
| callback    | AsyncCallback\<string> | Yes   | Callback used to return the application name.       |

**Example**

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

Checks whether the ability that matches a given **AbilityInfo** object is enabled. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name  | Type         | Mandatory  | Description          |
| ---- | ----------- | ---- | ------------ |
| info | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes   | Ability information.|

**Return value**

| Type               | Description                       |
| ----------------- | ------------------------- |
| Promise\<boolean> | Promise used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned.|

**Example**

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

Checks whether the ability that matches a given **AbilityInfo** object is enabled. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name      | Type                     | Mandatory  | Description             |
| -------- | ----------------------- | ---- | --------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md)             | Yes   | Ability information.   |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned.|

**Example**

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

Checks whether an application is enabled based on a given bundle name. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| bundleName | string | Yes   | Bundle name of an application.|

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

Checks whether an application is enabled based on a given bundle name. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type                     | Mandatory  | Description             |
| ---------- | ----------------------- | ---- | --------------- |
| bundleName | string                  | Yes   | Bundle name of an application.   |
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
| want        | [Want](js-apis-application-Want.md)   | Yes   | Want that contains the bundle name.                    |
| bundleFlags | number | Yes   | Ability information to be returned. The default value is **0**. For details on the available enumerated values, see the ability information flags in [BundleFlag](#bundleflag).|
| userId      | number | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.          |

**Return value**

| Type                          | Description                   |
| ---------------------------- | --------------------- |
| Promise<Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>> | Promise used to return the ability information.|

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

queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

Obtains the ability information of the specified user based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want        | [Want](js-apis-application-Want.md)                          | Yes  | Want that contains the bundle name.                      |
| bundleFlags | number                                                       | Yes  | Ability information to be returned. The default value is **0**. For details on the available enumerated values, see the ability information flags in [BundleFlag](#bundleflag).|
| userId      | number                                                       | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.         |
| callback    | AsyncCallback<Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>> | Yes  | Callback used to return the ability information.               |

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

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want        | [Want](js-apis-application-Want.md)                          | Yes  | Want that contains the bundle name.                      |
| bundleFlags | number                                                       | Yes  | Ability information to be returned. The default value is **0**. For details on the available enumerated values, see the ability information flags in [BundleFlag](#bundleflag).|
| callback    | AsyncCallback<Array\<[AbilityInfo](js-apis-bundle-AbilityInfo.md)>> | Yes  | Callback used to return the ability information.               |

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
| bundleName | string | Yes   | Bundle name of an application.|

**Return value**
| Type            | Description                                    |
| -------------- | -------------------------------------- |
| Promise\<[Want](js-apis-application-Want.md)> | Promise used to return the **Want** object.|

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
| bundleName | string               | Yes   | Bundle name of an application.                  |
| callback   | AsyncCallback\<[Want](js-apis-application-Want.md)> | Yes   | Callback used to return the **Want** object.|

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

Obtains the [pixel map](js-apis-image.md) of the icon corresponding to a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

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
| Promise\<image.PixelMap> | Promise used to return the [pixel map](js-apis-image.md).|

**Example**

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

Obtains the [pixel map](js-apis-image.md) of the icon corresponding to a given bundle name and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                      | Mandatory  | Description                                      |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | Yes   | Bundle name based on which the pixel map is to obtain.                         |
| abilityName | string                                   | Yes   | Ability name based on which the pixel map is to obtain.                        |
| callback   | AsyncCallback\<image.PixelMap> | Yes  | Callback used to return the [pixel map](js-apis-image.md).|

**Example**

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

Obtains the [pixel map](js-apis-image.md) of the icon corresponding to a given bundle name, module name, and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                      | Mandatory  | Description                                      |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | Yes   | Bundle name based on which the pixel map is to obtain.                         |
| moduleName  | string                                   | Yes   | Module name based on which the pixel map is to obtain.                         |
| abilityName | string                                   | Yes   | Ability name based on which the pixel map is to obtain.                        |

**Return value**
| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise\<image.PixelMap> | Promise used to return the [pixel map](js-apis-image.md).|

**Example**

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

Obtains the [pixel map](js-apis-image.md) of the icon corresponding to a given bundle name, module name, and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name         | Type                                      | Mandatory  | Description                                      |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| bundleName  | string                                   | Yes   | Bundle name based on which the pixel map is to obtain.                         |
| moduleName  | string                                   | Yes   | Module name based on which the pixel map is to obtain.                         |
| abilityName | string                                   | Yes   | Ability name based on which the pixel map is to obtain.                        |
| callback   | AsyncCallback\<image.PixelMap> | Yes  | Callback used to return the [pixel map](js-apis-image.md).|

**Example**

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

Obtains the Extension ability information based on a given want. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type    | Mandatory  | Description                                      |
| -------------- | ------ | ---- | ---------------------------------------- |
| want           | [Want](js-apis-application-Want.md)   | Yes   | Want that contains the bundle name.                       |
| extensionType  | number | Yes   | Type of the Extension ability information to obtain. The default value is **0**. For details on the available enumerated values, see [ExtensionAbilityType](#extensionabilitytype9).|
| extensionFlags | number | Yes   | Extension ability information to be returned. The default value is **0**. For details on the available enumerated values, see [ExtensionFlags](#extensionflag9).|
| userId         | number | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.             |

**Return value**

| Type                                   | Description                            |
| ------------------------------------- | ------------------------------ |
| Promise<Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)>> | Promise used to return the Extension ability information.|

**Example**

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

Obtains the Extension ability information of the specified user based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name          | Type                                                        | Mandatory| Description                                                        |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want           | [Want](js-apis-application-Want.md)                                                        | Yes  | Want that contains the bundle name.                      |
| extensionType  | number                                                       | Yes  | Type of the Extension ability information to obtain. The default value is **0**. For details on the available enumerated values, see [ExtensionAbilityType](#extensionabilitytype9).|
| extensionFlags | number                                                       | Yes  | Extension ability information to be returned. The default value is **0**. For details on the available enumerated values, see [ExtensionFlags](#extensionflag9).|
| userId         | number                                                       | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.         |
| callback       | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)>> | Yes  | Callback used to return the Extension ability information.      |

**Example**

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

Obtains the Extension ability information based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type                                      | Mandatory  | Description                                      |
| -------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| want           | [Want](js-apis-application-Want.md)                                     | Yes   | Want that contains the bundle name.                     |
| extensionType  | number                                   | Yes   | Type of the Extension ability information to obtain. The default value is **0**. For details on the available enumerated values, see [ExtensionAbilityType](#extensionabilitytype9).|
| extensionFlags | number                                   | Yes   | Extension ability information to be returned. The default value is **0**. For details on the available enumerated values, see [ExtensionFlags](#extensionflag9).|
| callback       | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundle-ExtensionAbilityInfo.md)>> | Yes   | Callback used to return the Extension ability information.     |

**Example**

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

## bundle.getProfileByAbility<sup>9+</sup>

getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;

Obtains the JSON string array of the current application's configuration file in the [metadata](js-apis-bundle-Metadata.md) based on a given module name, ability name, and metadata name. This API uses an asynchronous callback to return the result. This API cannot be used to obtain the JSON string array of another application.

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| moduleName     | string                               | Yes   | Module to which the configuration file to be obtained belongs.             |
| abilityName    | string                               | Yes   | Ability to which the configuration file to be obtained belongs.            |
| metadataName   | string                               | Yes   | Metadata to which the configuration file to be obtained belongs.           |
| callback       | AsyncCallback\<Array\<string>>        | Yes   | Callback used to return the JSON string array of the configuration file.  |

**Example**

```js
let moduleName = 'entry';
let abilityName = 'MainAbility';
let metadataName = 'ohos.ability.shortcuts';
const caller = function callback(err, data) {
    console.error('Operation errcode is: ' + err);
    console.error('Operation result is: ' + data);
}
bundle.getProfileByAbility(moduleName, abilityName, metadataName, caller)
```

## bundle.getProfileByAbility<sup>9+</sup>

getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise\<Array\<string>>;

Obtains the JSON string array of the current application's configuration file in the [metadata](js-apis-bundle-Metadata.md) based on a given module name, ability name, and metadata name. This API uses a promise to return the result. This API cannot be used to obtain the JSON string array of another application.

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| moduleName     | string                               | Yes   | Module to which the configuration file to be obtained belongs.             |
| abilityName    | string                               | Yes   | Ability to which the configuration file to be obtained belongs.            |
| metadataName   | string                               | No   | Metadata to which the configuration file to be obtained belongs.           |

**Return value**

| Type                                   | Description                            |
| ------------------------------------- | ------------------------------ |
| Promise\<Array\<string>> | Promise used to return the JSON string array of the configuration file.|

**Example**

```js
let moduleName = 'entry';
let abilityName = 'MainAbility';
let metadataName = 'ohos.ability.shortcuts';

bundle.getProfileByAbility(moduleName, abilityName, metadataName).then(data=>{
    console.error('Operation result is: ' + data);
}).catch(err=>{
    console.error('Operation errcode is: ' + err);
})
```

## bundle.getProfileByExtensionAbility<sup>9+</sup>

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback\<Array\<string>>): void;

Obtains the JSON string array of the current application's configuration file in the [metadata](js-apis-bundle-Metadata.md) based on a given module name, Extension ability name, and metadata name. This API uses an asynchronous callback to return the result. This API cannot be used to obtain the JSON string array of another application.

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| moduleName     | string                               | Yes   | Module to which the configuration file to be obtained belongs.             |
| extensionAbilityName    | string                               | Yes   | Extension ability to which the configuration file to be obtained belongs.            |
| metadataName   | string                               | Yes   | Metadata to which the configuration file to be obtained belongs.           |
| callback       | AsyncCallback\<Array\<string>>        | Yes   | Callback used to return the JSON string array of the configuration file.  |

**Example**

```js
let moduleName = 'entry';
let extensionAbilityName = 'Form';
let metadataName = 'ohos.extension.form';
const caller = function callback(err, data) {
    console.error('Operation errcode is: ' + err);
    console.error('Operation result is: ' + data);
}
bundle.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName, caller)
```

## bundle.getProfileByExtensionAbility<sup>9+</sup>

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise\<Array\<string>>;

Obtains the JSON string array of the current application's configuration file in the [metadata](js-apis-bundle-Metadata.md) based on a given module name, Extension ability name, and metadata name. This API uses a promise to return the result. This API cannot be used to obtain the JSON string array of another application.

**System capability**: SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| moduleName     | string                               | Yes   | Module to which the configuration file to be obtained belongs.             |
| extensionAbilityName    | string                               | Yes   | Extension ability to which the configuration file to be obtained belongs.            |
| metadataName   | string                               | No   | Metadata to which the configuration file to be obtained belongs.           |

**Return value**

| Type                                   | Description                            |
| ------------------------------------- | ------------------------------ |
| Promise\<Array\<string>> | Promise used to return the JSON string array of the configuration file.|

**Example**

```js
let moduleName = 'entry';
let extensionAbilityName = 'Form';
let metadataName = 'ohos.extension.form';

bundle.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName).then(data=>{
    console.error('Operation result is: ' + data);
}).catch(err=>{
    console.error('Operation errcode is: ' + err);
})
```

## bundle.setDisposedStatus<sup>9+</sup>

setDisposedStatus(bundleName: string, status: number, callback: AsyncCallback\<void>): void;

Sets the disposal status for an application based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| bundleName     | string                               | Yes   | Bundle name of an application.             |
| status    | number                               | Yes   | Disposal status to set. This parameter is reserved for the application market. The default value is **0**, indicating that no disposal is performed.            |
| callback       | AsyncCallback\<void>        | Yes   | Callback that returns no value.  |

**Example**

```js
let bundleName = 'com.ohos.camera';
let status = 1;
const caller = function callback(err, data) {
    console.error('Operation err is: ' + err);
    console.error('Operation result is: ' + data);
}
bundle.setDisposedStatus(bundleName, status, caller)
```

## bundle.setDisposedStatus<sup>9+</sup>

setDisposedStatus(bundleName: string, status: number): Promise\<void>;

Sets the disposal status for an application based on a given bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| bundleName     | string                               | Yes   | Bundle name of an application.             |
| status    | number                               | Yes   | Disposal status to set. This parameter is reserved for the application market. The default value is **0**, indicating that no disposal is performed.            |

**Return value**

| Type                                   | Description                            |
| ------------------------------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
let bundleName = 'com.ohos.camera';
let status = 1;

bundle.setDisposedStatus(bundleName, status).then(data=>{
    console.error('Operation result is: ' + data);
}).catch(err=>{
    console.error('Operation err is: ' + err);
})
```

## bundle.getDisposedStatus<sup>9+</sup>

getDisposedStatus(bundleName: string, callback: AsyncCallback\<number>): void;

Obtains the disposal status of an application based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| bundleName     | string                               | Yes   | Bundle name of an application.             |
| callback       | AsyncCallback\<number>        | Yes   | Callback used to return the disposal status.  |

**Example**

```js
let bundleName = 'com.ohos.camera';
const caller = function callback(err, data) {
    console.error('Operation err is: ' + err);
    console.error('Operation result is: ' + data);
}
bundle.getDisposedStatus(bundleName, caller)
```

## bundle.getDisposedStatus<sup>9+</sup>

getDisposedStatus(bundleName: string): Promise\<number>;

Obtains the disposal status of an application based on a given bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_DISPOSED_APP_STATUS

**System capability**: SystemCapability.BundleManager.BundleFramework

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name            | Type                               | Mandatory  | Description                                      |
| ---------------- | ---------------------------------- | ---- | ---------------------------------------- |
| bundleName     | string                               | Yes   | Bundle name of an application.             |

**Return value**

| Type                                   | Description                            |
| ------------------------------------- | ------------------------------ |
| Promise\<number> | Promise used to return the disposal status.|

**Example**

```js
let bundleName = 'com.ohos.camera';

bundle.getDisposedStatus(bundleName).then(data=>{
    console.error('Operation result is: ' + data);
}).catch(err=>{
    console.error('Operation err is: ' + err);
})
```

## InstallErrorCode

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                                      | Default Value | Description                       |
| ---------------------------------------- | ---- | ------------------------- |
| SUCCESS                                  | 0    | Installation succeeded.                     |
| STATUS_INSTALL_FAILURE                   | 1    | Installation failed. (The application to be installed is not found.)           |
| STATUS_INSTALL_FAILURE_ABORTED           | 2    | Installation aborted.                     |
| STATUS_INSTALL_FAILURE_INVALID           | 3    | Invalid installation parameter.                   |
| STATUS_INSTALL_FAILURE_CONFLICT          | 4    | Installation conflict. (The basic information of the application to update is inconsistent with that of the existing application.) |
| STATUS_INSTALL_FAILURE_STORAGE           | 5    | Failed to store the bundle information.                  |
| STATUS_INSTALL_FAILURE_INCOMPATIBLE      | 6    | Installation incompatibility. (A downgrade occurs or the signature information is incorrect.) |
| STATUS_UNINSTALL_FAILURE                 | 7    | Uninstallation failed. (The application to be uninstalled is not found.)          |
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
| GET_ABILITY_INFO_SYSTEMAPP_ONLY<sup>8+</sup> | 0x00000080 | Obtains the ability information of system applications.|
| GET_ABILITY_INFO_WITH_DISABLE<sup>8+</sup> | 0x00000100 | Obtains information about disabled abilities.  |
| GET_APPLICATION_INFO_WITH_DISABLE<sup>8+</sup> | 0x00000200 | Obtains information about disabled applications.       |
| GET_APPLICATION_INFO_WITH_CERTIFICATE_FINGERPRINT <sup>9+</sup> | 0x00000400 | Obtains the signing certificate fingerprint of the application.       |
| GET_ALL_APPLICATION_INFO                 | 0xFFFF0000 | Obtains all application information.          |
| GET_BUNDLE_WITH_HASH_VALUE<sup>9+</sup> | 0x00000030 | Obtains information about the bundle that contains a hash value.      |

## BundleOptions

Describes the bundle options.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name    | Type    | Readable  | Writable  | Description                          |
| ------ | ------ | ---- | ---- | ---------------------------- |
| userId | number | Yes   | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

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
| UNSPECIFIED   | None   | Unspecified display orientation.    |
| LANDSCAPE     | None   | Landscape orientation.     |
| PORTRAIT      | None   | Portrait orientation.     |
| FOLLOW_RECENT | None   | Orientation same as that of the nearest ability in the stack.|
| LANDSCAPE_INVERTED<sup>9+</sup> |None   | Reverse landscape orientation.    |
| PORTRAIT_INVERTED<sup>9+</sup> |None   | Reverse portrait orientation.    |
| AUTO_ROTATION<sup>9+</sup> |None   | Orientation determined by the sensor.    |
| AUTO_ROTATION_LANDSCAPE<sup>9+</sup> |None   | Orientation determined by the sensor in the horizontal direction, including landscape and reverse landscape.    |
| AUTO_ROTATION_PORTRAIT<sup>9+</sup> |None   | Orientation determined by the sensor in the vertical direction, including portrait and reverse portrait.    |
| AUTO_ROTATION_RESTRICTED<sup>9+</sup> |None   | Orientation determined by the sensor when the sensor switch is enabled.    |
| AUTO_ROTATION_LANDSCAPE_RESTRICTED<sup>9+</sup> |None   | Orientation determined by the sensor in the horizontal direction, including landscape and reverse landscape, when the sensor switch is enabled.    |
| AUTO_ROTATION_PORTRAIT_RESTRICTED<sup>9+</sup> |None   | Orientation determined by the sensor in the vertical direction, including portrait and reverse portrait, when the sensor switch is enabled.    |
| LOCKED<sup>9+</sup> |None   | Auto rotate disabled.    |
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
| FORM<sup>9+</sup>              | 0    | Form (widget) included.  |
| WORK_SCHEDULER<sup>9+</sup>    | 1    | Work scheduler included.|
| INPUT_METHOD<sup>9+</sup>      | 2    | Input method included. |
| SERVICE<sup>9+</sup>           | 3    | Service included.  |
| ACCESSIBILITY<sup>9+</sup>     | 4    | Accessibility included. |
| DATA_SHARE<sup>9+</sup>        | 5    | Data sharing included.|
| FILE_SHARE<sup>9+</sup>        | 6    | File sharing included.|
| STATIC_SUBSCRIBER<sup>9+</sup> | 7    | Subscribers included. |
| WALLPAPER<sup>9+</sup>         | 8    | Wallpaper included.  |
| BACKUP<sup>9+</sup> | 9    | Data backup and restore included.|
| WINDOW<sup>9+</sup> | 10 | Window type extension information included.|
| ENTERPRISE_ADMIN<sup>9+</sup>  | 11   | Enterprise administrators included.  |
| THUMBNAIL<sup>9+</sup> | 13 | Thumbnails included.|
| PREVIEW<sup>9+</sup> | 14 | Preview included.|
| UNSPECIFIED<sup>9+</sup>       | 255   | Unspecified type.    |

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

Enumerates permission grant states.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                | Type  | Description  |
| ------------------ | ---- | ---- |
| PERMISSION_DENIED  | -1   | Permission denied.|
| PERMISSION_GRANTED | 0    | Permission granted.  |

## SupportWindowMode

Enumerates window modes.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                | Type  | Description  |
| ------------------ | ---- | ---- |
| FULL_SCREEN<sup>9+</sup> | 0   | Full screen.|
| SPLIT<sup>9+</sup> | 1    | Split-screen.  |
| FLOATING<sup>9+</sup> | 2    | Floating.  |

## UpgradeFlag

Enumerates the upgrade flags, which are for internal use only.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                         | Value  | Description            |
| ----------------------------- | ---- | ---------------- |
| NOT_UPGRADE<sup>9+</sup>      | 0    | No module needs an upgrade.    |
| SINGLE_UPGRADE<sup>9+</sup>   | 1    | A single module needs an upgrade.|
| RELATION_UPGRADE<sup>9+</sup> | 2    | The module that has a relationship with the current one needs an upgrade.|
