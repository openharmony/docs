# Bundle

The **Bundle** module provides APIs for querying the information about bundles, applications, abilities, Extension abilities, and application states.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
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

For details, see [Permission Levels](../../security/accesstoken-overview.md#permission-levels).

## bundle.getApplicationInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getApplicationInfo](js-apis-bundleManager.md#bundlemanagergetapplicationinfo) instead.

getApplicationInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<ApplicationInfo>

Obtains the application information based on a given bundle name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type  | Mandatory| Description                                                        |
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

## bundle.getApplicationInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getApplicationInfo](js-apis-bundleManager.md#bundlemanagergetapplicationinfo) instead.

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void

Obtains the application information of the specified user based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
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

## bundle.getApplicationInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getApplicationInfo](js-apis-bundleManager.md#bundlemanagergetapplicationinfo) instead.


getApplicationInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<ApplicationInfo>): void

Obtains the application information based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
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


## bundle.getAllBundleInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAllBundleInfo](js-apis-bundleManager.md#bundlemanagergetallbundleinfo) instead.

getAllBundleInfo(bundleFlag: BundleFlag, userId?: number): Promise<Array\<BundleInfo>>

Obtains the information of all available bundles of the specified user in the system. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name    | Type      | Mandatory| Description                                                        |
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

## bundle.getAllBundleInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAllBundleInfo](js-apis-bundleManager.md#bundlemanagergetallbundleinfo) instead.


getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains the information of all available bundles in the system. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
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

## bundle.getAllBundleInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAllBundleInfo](js-apis-bundleManager.md#bundlemanagergetallbundleinfo) instead.


getAllBundleInfo(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains the information of all available bundles of the specified user in the system. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
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

## bundle.getBundleInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo) instead.


getBundleInfo(bundleName: string, bundleFlags: number, options?: BundleOptions): Promise\<BundleInfo>

Obtains the bundle information based on a given bundle name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type           | Mandatory  | Description                                     |
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

## bundle.getBundleInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo) instead.

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on a given bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                      | Mandatory| Description                                                        |
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


## bundle.getBundleInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleInfo](js-apis-bundleManager.md#bundlemanagergetbundleinfo) instead.

getBundleInfo(bundleName: string, bundleFlags: number, options: BundleOptions, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on a given bundle name and bundle options. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                      | Mandatory| Description                                                        |
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



## bundle.getBundleInstaller<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [installer.getBundleInstaller](js-apis-installer.md#bundleinstallergetbundleinstaller) instead.

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

## bundle.getBundleInstaller<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [installer.getBundleInstaller](js-apis-installer.md#bundleinstallergetbundleinstaller) instead.

getBundleInstaller(callback: AsyncCallback&lt;BundleInstaller&gt;): void;

Obtains the installation package information. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                                                        | Mandatory| Description            |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| callback | AsyncCallback<[BundleInstaller](js-apis-bundle-BundleInstaller.md)> | Yes  | Callback used to return the installation package information.|

## bundle.cleanBundleCacheFiles<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.cleanBundleCacheFiles](js-apis-bundleManager.md#bundlemanagercleanbundlecachefiles) instead.

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

Clears the cache data of an application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.REMOVE_CACHE_FILES

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type               | Mandatory| Description                                 |
| ---------- | ------------------- | ---- | ------------------------------------- |
| bundleName | string              | Yes  | Bundle name of an application.|
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.         |

## bundle.cleanBundleCacheFiles<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.cleanBundleCacheFiles](js-apis-bundleManager.md#bundlemanagercleanbundlecachefiles) instead.

cleanBundleCacheFiles(bundleName: string): Promise&lt;void&gt;

Clears the cache data of an application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.REMOVE_CACHE_FILES

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type  | Mandatory| Description                                 |
| ---------- | ------ | ---- | ------------------------------------- |
| bundleName | string | Yes  | Bundle name of an application.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

## bundle.setApplicationEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setApplicationEnabled](js-apis-bundleManager.md#bundlemanagersetapplicationenabled) instead.

setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void;

Sets whether to enable an application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type               | Mandatory| Description                                           |
| ---------- | ------------------- | ---- | ----------------------------------------------- |
| bundleName | string              | Yes  | Bundle name of an application.                               |
| isEnable   | boolean             | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite.|
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.                   |

## bundle.setApplicationEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setApplicationEnabled](js-apis-bundleManager.md#bundlemanagersetapplicationenabled) instead.

setApplicationEnabled(bundleName: string, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable an application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type   | Mandatory| Description                                           |
| ---------- | ------- | ---- | ----------------------------------------------- |
| bundleName | string  | Yes  | Bundle name of an application.                               |
| isEnable   | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

## bundle.setAbilityEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setAbilityEnabled](js-apis-bundleManager.md#bundlemanagersetabilityenabled) instead.

setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void;

Sets whether to enable an ability. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                                        | Mandatory| Description                                           |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.                                  |
| isEnable | boolean                                      | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite.|
| callback | AsyncCallback\<void>                         | Yes  | Callback used to return the result.                   |

## bundle.setAbilityEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setAbilityEnabled](js-apis-bundleManager.md#bundlemanagersetabilityenabled) instead.

setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable an ability. This API uses a promise to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                                        | Mandatory| Description                                           |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.                                  |
| isEnable | boolean                                      | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

## bundle.getPermissionDef<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getPermissionDef](js-apis-bundleManager.md#bundlemanagergetpermissiondef) instead.

getPermissionDef(permissionName: string, callback: AsyncCallback&lt;PermissionDef&gt;): void;

Obtains the permission details by permission name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name        | Type                                                        | Mandatory| Description                                            |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| permissionName | string                                                       | Yes  | Name of the permission.                                |
| callback       | AsyncCallback<[PermissionDef](js-apis-bundle-PermissionDef)> | Yes  | Callback used to return the permission details.|

## bundle.getPermissionDef<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getPermissionDef](js-apis-bundleManager.md#bundlemanagergetpermissiondef) instead.

getPermissionDef(permissionName: string): Promise&lt;PermissionDef&gt;

Obtains the permission details by permission name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API and cannot be called by third-party applications.

**Parameters**

| Name        | Type  | Mandatory| Description            |
| -------------- | ------ | ---- | ---------------- |
| permissionName | string | Yes  | Name of the permission.|

**Return value**

| Type                                                  | Description                                                  |
| ------------------------------------------------------ | ------------------------------------------------------ |
| Promise<[PermissionDef](js-apis-bundle-PermissionDef)> | Promise used to return the permission details.|


## bundle.getAllApplicationInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAllApplicationInfo](js-apis-bundleManager.md#bundlemanagergetallapplicationinfo) instead.

getAllApplicationInfo(bundleFlags: number, userId?: number): Promise<Array\<ApplicationInfo>>

Obtains the information about all applications of the specified user. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| userId      | number | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |

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

## bundle.getAllApplicationInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAllApplicationInfo](js-apis-bundleManager.md#bundlemanagergetallapplicationinfo) instead.

getAllApplicationInfo(bundleFlags: number, userId: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

Obtains the information about all applications of the specified user. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleFlags | number                                                       | Yes  | Type of information that will be returned. The default value is **0**. For details on the available enumerated values, see the application information flags in [BundleFlag](#bundleflag).|
| userId      | number                                                       | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.       |
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


## bundle.getAllApplicationInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAllApplicationInfo](js-apis-bundleManager.md#bundlemanagergetallapplicationinfo) instead.

getAllApplicationInfo(bundleFlags: number, callback: AsyncCallback<Array\<ApplicationInfo>>) : void;

Obtains the information about all applications. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
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

## bundle.getBundleArchiveInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleArchiveInfo](js-apis-bundleManager.md#bundlemanagergetbundlearchiveinfo) instead.

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number) : Promise\<BundleInfo>

Obtains information about the bundles contained in a HAP file. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type    | Mandatory  | Description          |
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

## bundle.getBundleArchiveInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleArchiveInfo](js-apis-bundleManager.md#bundlemanagergetbundlearchiveinfo) instead.

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>) : void

Obtains information about the bundles contained in a HAP file. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type    | Mandatory  | Description          |
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


## bundle.getAbilityInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.queryAbilityInfo](js-apis-bundleManager.md#bundlemanagerqueryabilityinfo) instead.

getAbilityInfo(bundleName: string, abilityName: string): Promise\<AbilityInfo>

Obtains the ability information based on a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description              |
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

## bundle.getAbilityInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.queryAbilityInfo](js-apis-bundleManager.md#bundlemanagerqueryabilityinfo) instead.

getAbilityInfo(bundleName: string, abilityName: string, callback: AsyncCallback\<AbilityInfo>): void;

Obtains the ability information based on a given bundle name and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name       | Type    | Mandatory  | Description           |
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

## bundle.getAbilityLabel<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAbilityLabel](js-apis-bundleManager.md#bundlemanagergetabilitylabel) instead.

getAbilityLabel(bundleName: string, abilityName: string): Promise\<string>

Obtains the application name based on a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description              |
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

## bundle.getAbilityLabel<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAbilityLabel](js-apis-bundleManager.md#bundlemanagergetabilitylabel) instead.

getAbilityLabel(bundleName: string, abilityName: string, callback : AsyncCallback\<string>): void

Obtains the application name based on a given bundle name and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type                    | Mandatory  | Description              |
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

## bundle.isAbilityEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.isAbilityEnabled](js-apis-bundleManager.md#bundlemanagerisabilityenabled) instead.

isAbilityEnabled(info: AbilityInfo): Promise\<boolean>

Checks whether the ability that matches a given **AbilityInfo** object is enabled. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name| Type                                        | Mandatory| Description             |
| ------ | -------------------------------------------- | ---- | ----------------- |
| info   | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.|

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

## bundle.isAbilityEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.isAbilityEnabled](js-apis-bundleManager.md#bundlemanagerisabilityenabled) instead.

isAbilityEnabled(info : AbilityInfo, callback : AsyncCallback\<boolean>): void

Checks whether the ability that matches a given **AbilityInfo** object is enabled. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name  | Type                                        | Mandatory| Description                   |
| -------- | -------------------------------------------- | ---- | ----------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.      |
| callback | AsyncCallback\<boolean>                      | Yes  | Callback used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned.|

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

## bundle.isApplicationEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.isApplicationEnabled](js-apis-bundleManager.md#bundlemanagerisapplicationenabled) instead.

isApplicationEnabled(bundleName: string): Promise\<boolean>

Checks whether an application is enabled based on a given bundle name. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name    | Type  | Mandatory| Description                    |
| ---------- | ------ | ---- | ------------------------ |
| bundleName | string | Yes  | Bundle name of an application.|

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

## bundle.isApplicationEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.isApplicationEnabled](js-apis-bundleManager.md#bundlemanagerisapplicationenabled) instead.

isApplicationEnabled(bundleName: string, callback : AsyncCallback\<boolean>): void

Checks whether an application is enabled based on a given bundle name. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name    | Type                   | Mandatory| Description                    |
| ---------- | ----------------------- | ---- | ------------------------ |
| bundleName | string                  | Yes  | Bundle name of an application.|
| callback   | AsyncCallback\<boolean> | Yes  | Callback used to return whether the ability is enabled. If the ability is enabled, **true** will be returned; otherwise, **false** will be returned. |

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

## bundle.queryAbilityByWant<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.queryAbilityInfo](js-apis-bundleManager.md#bundlemanagerqueryabilityinfo) instead.

queryAbilityByWant(want: Want, bundleFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

Obtains the ability information based on a given want. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type    | Mandatory  | Description                                   |
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



## bundle.queryAbilityByWant<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.queryAbilityInfo](js-apis-bundleManager.md#bundlemanagerqueryabilityinfo) instead.

queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

Obtains the ability information of the specified user based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
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

## bundle.queryAbilityByWant<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.queryAbilityInfo](js-apis-bundleManager.md#bundlemanagerqueryabilityinfo) instead.

queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback<Array\<AbilityInfo>>): void;

Obtains the ability information based on a given want. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
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



## bundle.getLaunchWantForBundle<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getLaunchWantForBundle](js-apis-bundleManager.md#bundlemanagergetlaunchwantforbundle) instead.

getLaunchWantForBundle(bundleName: string): Promise\<Want>

Obtains the **Want** object that launches the specified application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name    | Type  | Mandatory| Description                    |
| ---------- | ------ | ---- | ------------------------ |
| bundleName | string | Yes  | Bundle name of an application.|

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

## bundle.getLaunchWantForBundle<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getLaunchWantForBundle](js-apis-bundleManager.md#bundlemanagergetlaunchwantforbundle) instead.

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void;

Obtains the **Want** object that launches the specified application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name    | Type                                               | Mandatory| Description                                                    |
| ---------- | --------------------------------------------------- | ---- | -------------------------------------------------------- |
| bundleName | string                                              | Yes  | Bundle name of an application.                                |
| callback   | AsyncCallback\<[Want](js-apis-application-Want.md)> | Yes  | Callback used to return the **Want** object.|

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


## bundle.getNameForUid<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleNameByUid](js-apis-bundleManager.md#bundlemanagergetbundlenamebyuid) instead.

getNameForUid(uid: number): Promise\<string>

Obtains the bundle name based on a UID. This API uses a promise to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name| Type  | Mandatory| Description         |
| ------ | ------ | ---- | ------------- |
| uid    | number | Yes  | UID based on which the bundle name is to obtain.|

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

## bundle.getNameForUid<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getBundleNameByUid](js-apis-bundleManager.md#bundlemanagergetbundlenamebyuid) instead.

getNameForUid(uid: number, callback: AsyncCallback\<string>) : void

Obtains the bundle name based on a UID. This API uses an asynchronous callback to return the result.

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name  | Type                  | Mandatory| Description                                           |
| -------- | ---------------------- | ---- | ----------------------------------------------- |
| uid      | number                 | Yes  | UID based on which the bundle name is to obtain.                                  |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the bundle name.|

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


## bundle.getAbilityIcon<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAbilityIcon](js-apis-bundleManager.md#bundlemanagergetabilityicon) instead.

getAbilityIcon(bundleName: string, abilityName: string): Promise\<image.PixelMap>;

Obtains the [pixel map](js-apis-image.md) of the icon corresponding to a given bundle name and ability name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name     | Type  | Mandatory| Description                 |
| ----------- | ------ | ---- | --------------------- |
| bundleName  | string | Yes  | Bundle name based on which the pixel map is to obtain. |
| abilityName | string | Yes  | Ability name based on which the pixel map is to obtain.|

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

## bundle.getAbilityIcon<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getAbilityIcon](js-apis-bundleManager.md#bundlemanagergetabilityicon) instead.

getAbilityIcon(bundleName: string, abilityName: string, callback: AsyncCallback\<image.PixelMap>): void;

Obtains the [pixel map](js-apis-image.md) of the icon corresponding to a given bundle name and ability name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**

SystemCapability.BundleManager.BundleFramework

**Parameters**

| Name        | Type                                      | Mandatory  | Description                                      |
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

## InstallErrorCode<sup>deprecated<sup>
> This API is deprecated since API version 9. You are not advised to use it anymore.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                                                | Value  | Description                                            |
| ---------------------------------------------------- | ---- | ------------------------------------------------ |
| SUCCESS                                              | 0    | Installation succeeded.                                        |
| STATUS_INSTALL_FAILURE                               | 1    | Installation failed. (The application to be installed is not found.)                    |
| STATUS_INSTALL_FAILURE_ABORTED                       | 2    | Installation aborted.                                        |
| STATUS_INSTALL_FAILURE_INVALID                       | 3    | Invalid installation parameter.                                    |
| STATUS_INSTALL_FAILURE_CONFLICT                      | 4    | Installation conflict. (The basic information of the application to update is inconsistent with that of the existing application.) |
| STATUS_INSTALL_FAILURE_STORAGE                       | 5    | Failed to store the bundle information.                                  |
| STATUS_INSTALL_FAILURE_INCOMPATIBLE                  | 6    | Installation incompatibility. (A downgrade occurs or the signature information is incorrect.)|
| STATUS_UNINSTALL_FAILURE                             | 7    | Uninstallation failed. (The application to be uninstalled is not found.)                   |
| STATUS_UNINSTALL_FAILURE_BLOCKED                     | 8    | Uninstallation aborted. (This error code is not in use.)                           |
| STATUS_UNINSTALL_FAILURE_ABORTED                     | 9    | Uninstallation aborted. (Invalid parameters.)                       |
| STATUS_UNINSTALL_FAILURE_CONFLICT                    | 10   | Uninstallation conflict. (Failed to uninstall a system application or end the application process.)|
| STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT              | 0x0B | Installation failed. (Download timed out.)                           |
| STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED               | 0x0C | Installation failed. (Download failed.)                           |
| STATUS_RECOVER_FAILURE_INVALID<sup>8+</sup>          | 0x0D | Failed to restore the pre-installed application.                                |
| STATUS_ABILITY_NOT_FOUND                             | 0x40 | Ability not found.                                   |
| STATUS_BMS_SERVICE_ERROR                             | 0x41 | BMS service error.                                     |
| STATUS_FAILED_NO_SPACE_LEFT<sup>8+</sup>             | 0x42 | Insufficient device space.                                    |
| STATUS_GRANT_REQUEST_PERMISSIONS_FAILED<sup>8+</sup> | 0x43 | Application authorization failed.                                    |
| STATUS_INSTALL_PERMISSION_DENIED<sup>8+</sup>        | 0x44 | No installation permission.                                    |
| STATUS_UNINSTALL_PERMISSION_DENIED<sup>8+</sup>      | 0x45 | No uninstallation permission.                                    |

## BundleFlag<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.BundleFlag](js-apis-bundleManager.md#bundleflag) instead.

Enumerates bundle flags.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name                                           | Value        | Description                           |
| ----------------------------------------------- | ---------- | ------------------------------- |
| GET_BUNDLE_DEFAULT                              | 0x00000000 | Obtains the default application information.             |
| GET_BUNDLE_WITH_ABILITIES                       | 0x00000001 | Obtains the bundle information with the ability information.    |
| GET_ABILITY_INFO_WITH_PERMISSION                | 0x00000002 | Obtains the ability information with the permission information.      |
| GET_ABILITY_INFO_WITH_APPLICATION               | 0x00000004 | Obtains the ability information with the application information.      |
| GET_APPLICATION_INFO_WITH_PERMISSION            | 0x00000008 | Obtains the application information with the permission information.         |
| GET_BUNDLE_WITH_REQUESTED_PERMISSION            | 0x00000010 | Obtains the bundle information with the information about the required permissions.       |
| GET_ABILITY_INFO_WITH_METADATA<sup>8+</sup>     | 0x00000020 | Obtains the ability metadata information.        |
| GET_APPLICATION_INFO_WITH_METADATA<sup>8+</sup> | 0x00000040 | Obtains the application metadata information.           |
| GET_ABILITY_INFO_SYSTEMAPP_ONLY<sup>8+</sup>    | 0x00000080 | Obtains the ability information of system applications.|
| GET_ABILITY_INFO_WITH_DISABLE<sup>8+</sup>      | 0x00000100 | Obtains information about disabled abilities.    |
| GET_APPLICATION_INFO_WITH_DISABLE<sup>8+</sup>  | 0x00000200 | Obtains information about disabled applications.       |
| GET_ALL_APPLICATION_INFO                        | 0xFFFF0000 | Obtains all application information.             |

## BundleOptions<sup>deprecated<sup>
> This API is deprecated since API version 9. You are not advised to use it anymore.

Describes the bundle options.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name  | Type  | Readable| Writable| Description                                                 |
| ------ | ------ | ---- | ---- | ----------------------------------------------------- |
| userId | number | Yes  | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

## AbilityType<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.AbilityType](js-apis-bundleManager.md#abilitytype) instead.

Enumerates ability types.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name| Value| Description                       |
| ------- | ---- | --------------------------- |
| UNKNOWN | None  | Unknown ability type.            |
| PAGE    | None  | FA developed using the Page template to provide the capability of interacting with users.       |
| SERVICE | None  | PA developed using the Service template to provide the capability of running tasks in the background.          |
| DATA    | None  | PA developed using the Data template to provide unified data access for external systems.|

## DisplayOrientation<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.DisplayOrientation](js-apis-bundleManager.md#displayorientation) instead.

Enumerates display orientations.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name         | Value  | Description                    |
| ------------- | ---- | ------------------------ |
| UNSPECIFIED   | None  | Unspecified display orientation.        |
| LANDSCAPE     | None  | Landscape orientation.          |
| PORTRAIT      | None  | Portrait orientation.          |
| FOLLOW_RECENT | None  | Orientation same as that of the nearest ability in the stack.|
## LaunchMode<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.LaunchType](js-apis-bundleManager.md#launchtype) instead.

Enumerates launch modes.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name     | Value  | Description               |
| --------- | ---- | ------------------- |
| SINGLETON | 0    | The ability has only one instance.|
| STANDARD  | 1    | The ability can have multiple instances.  |

## AbilitySubType<sup>deprecated<sup>
> This API is deprecated since API version 9. You are not advised to use it anymore.

Enumerates ability subtypes.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name       | Value  | Description                         |
| ----------- | ---- | ----------------------------- |
| UNSPECIFIED | 0    | Undefined ability subtype.          |
| CA          | 1    | Ability that has a UI.|

## ColorMode<sup>deprecated<sup>
> This API is deprecated since API version 9. You are not advised to use it anymore.

Enumerates color modes.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name      | Value  | Description    |
| ---------- | ---- | -------- |
| AUTO_MODE  | -1   | Automatic mode.|
| DARK_MODE  | 0    | Dark mode.|
| LIGHT_MODE | 1    | Light mode.|


## GrantStatus<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.PermissionGrantState](js-apis-bundleManager.md#permissiongrantstate) instead.

Enumerates permission grant states.

 **System capability**: SystemCapability.BundleManager.BundleFramework

| Name              | Value  | Description        |
| ------------------ | ---- | ------------ |
| PERMISSION_DENIED  | -1   | Permission denied.|
| PERMISSION_GRANTED | 0    | Permission granted.    |
