# @ohos.bundle (Bundle) (System API)

The **bundle** module provides APIs for obtaining information about an application, including [bundle information](js-apis-bundle-BundleInfo.md), [application information](js-apis-bundle-ApplicationInfo.md), and [ability information](js-apis-bundle-AbilityInfo.md). It also provides APIs to obtain and set the application disabling state.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are deprecated since API version 9. You are advised to use [@ohos.bundle.bundleManager](js-apis-bundleManager-sys.md) instead.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.bundle](js-apis-Bundle.md).

## Modules to Import

```ts
import bundle from '@ohos.bundle';
```

## Required Permissions

| Permission                                        | APL        | Description           |
|--------------------------------------------|--------------|---------------|
| ohos.permission.CHANGE_ABILITY_ENABLED_STATE | system_basic | Permission to enable or disable an application or ability. |
| ohos.permission.GET_BUNDLE_INFO | normal | Permission to query information about a specified bundle. |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | Permission to query information about all bundles.    |
| ohos.permission.INSTALL_BUNDLE             | system_core  | Permission to install or uninstall bundles.     |
| ohos.permission.REMOVE_CACHE_FILES | system_basic | Permission to clear cache files of a bundle. |

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

## bundle.getBundleInstaller<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [installer.getBundleInstaller](js-apis-installer-sys.md#bundleinstallergetbundleinstaller) instead.

getBundleInstaller(): Promise&lt;BundleInstaller&gt;

Obtains the installation package. This API uses a promise to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Return value**

| Type                                                        | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| Promise<[BundleInstaller](js-apis-bundle-BundleInstaller-sys.md)> | Promise used to return the installation package. |

**Example**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

bundle.getBundleInstaller().then((data) => {
  console.info('getBundleInstaller successfully.');
}).catch((error: BusinessError) => {
  console.error('getBundleInstaller failed.');
});
```

## bundle.getBundleInstaller<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [installer.getBundleInstaller](js-apis-installer-sys.md#bundleinstallergetbundleinstaller) instead.

getBundleInstaller(callback: AsyncCallback&lt;BundleInstaller&gt;): void

Obtains the installation package. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory | Description            |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| callback | AsyncCallback<[BundleInstaller](js-apis-bundle-BundleInstaller-sys.md)> | Yes  | Callback used to return the installation package. |

**Example**

```ts
import bundle from '@ohos.bundle';

bundle.getBundleInstaller((err, data) => {
  if (err.code == 0) {
    console.error('getBundleInstaller failed.');
  } else {
    console.info('getBundleInstaller successfully');
  }
});
```
## bundle.cleanBundleCacheFiles<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.cleanBundleCacheFiles](js-apis-bundleManager-sys.md#bundlemanagercleanbundlecachefiles) instead.

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Clears the cache data of an application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.REMOVE_CACHE_FILES

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name     | Type               | Mandatory | Description                                 |
| ---------- | ------------------- | ---- | ------------------------------------- |
| bundleName | string              | Yes  | Bundle name. |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.         |

**Example**

```ts
import bundle from '@ohos.bundle';

let bundleName: string = "com.example.myapplication";

bundle.cleanBundleCacheFiles(bundleName, err => {
  if (err) {
    console.error('cleanBundleCacheFiles failed.');
  } else {
    console.info('cleanBundleCacheFiles successfully.');
  }
});
```

## bundle.cleanBundleCacheFiles<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.cleanBundleCacheFiles](js-apis-bundleManager-sys.md#bundlemanagercleanbundlecachefiles) instead.

cleanBundleCacheFiles(bundleName: string): Promise&lt;void&gt;

Clears the cache data of an application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.REMOVE_CACHE_FILES

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name    | Type  | Mandatory | Description                                 |
| ---------- | ------ | ---- | ------------------------------------- |
| bundleName | string | Yes  | Bundle name. |

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleName: string = "com.example.myapplication";

bundle.cleanBundleCacheFiles(bundleName).then(() => {
  console.info('cleanBundleCacheFiles successfully.');
}).catch((error: BusinessError) => {
  console.error('cleanBundleCacheFiles failed.');
});
```

## bundle.setApplicationEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setApplicationEnabled](js-apis-bundleManager-sys.md#bundlemanagersetapplicationenabled) instead.

setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable an application. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name     | Type               | Mandatory | Description                            |
| ---------- | ------------------- | ---- |--------------------------------|
| bundleName | string              | Yes  | Bundle name.         |
| isEnable   | boolean             | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite. |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result.                         |

**Example**

```ts
import bundle from '@ohos.bundle';

let bundleName: string = "com.example.myapplication";

bundle.setApplicationEnabled(bundleName, false, err => {
  if (err) {
    console.error('setApplicationEnabled failed.');
  } else {
    console.info('setApplicationEnabled successfully.');
  }
});
```

## bundle.setApplicationEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setApplicationEnabled](js-apis-bundleManager-sys.md#bundlemanagersetapplicationenabled) instead.

setApplicationEnabled(bundleName: string, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable an application. This API uses a promise to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name    | Type   | Mandatory | Description                                           |
| ---------- | ------- | ---- | ----------------------------------------------- |
| bundleName | string  | Yes  | Bundle name.           |
| isEnable   | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite. |

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleName: string = "com.example.myapplication";

bundle.setApplicationEnabled(bundleName, false).then(() => {
  console.info('setApplicationEnabled successfully.');
}).catch((error: BusinessError) => {
  console.error('setApplicationEnabled failed.');
});
```

## bundle.setAbilityEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setAbilityEnabled](js-apis-bundleManager-sys.md#bundlemanagersetabilityenabled) instead.

setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable an ability. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name  | Type                                        | Mandatory | Description                                           |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.                                  |
| isEnable | boolean                                      | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite. |
| callback | AsyncCallback\<void>                         | Yes  | Callback used to return the result.                   |

## bundle.setAbilityEnabled<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.setAbilityEnabled](js-apis-bundleManager-sys.md#bundlemanagersetabilityenabled) instead.

setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable an ability. This API uses a promise to return the result.

**Required permissions**

ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name  | Type                                        | Mandatory | Description                                           |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------- |
| info     | [AbilityInfo](js-apis-bundle-AbilityInfo.md) | Yes  | Ability information.                                  |
| isEnable | boolean                                      | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means the opposite. |

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let bundleName: string = "com.example.myapplication";
let abilityName: string = "EntryAbility";

bundle.getAbilityInfo(bundleName, abilityName).then((abilityInfo) => {
  console.info('getAbilityInfo successfully. Data: ' + JSON.stringify(abilityInfo));

  bundle.setAbilityEnabled(abilityInfo, false).then(data => {
    console.info('setAbilityEnabled successfully.');
  }).catch((error: BusinessError) => {
    console.error('setAbilityEnabled failed:' + JSON.stringify(error));
  })
}).catch((error: BusinessError) => {
  console.error('getAbilityInfo failed. Cause: ' + JSON.stringify(error));
});
```
## bundle.getPermissionDef<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef) instead.

getPermissionDef(permissionName: string, callback: AsyncCallback&lt;PermissionDef&gt;): void

Obtains the permission details by permission name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name        | Type                                                        | Mandatory | Description                                            |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| permissionName | string                                                       | Yes  | Name of the permission.                                |
| callback       | AsyncCallback<[PermissionDef](js-apis-bundle-PermissionDef-sys.md)> | Yes  | Callback used to return the permission details. |

**Example**

```ts
import bundle from '@ohos.bundle';

let permission: string = "ohos.permission.GET_BUNDLE_INFO";
bundle.getPermissionDef(permission, (err, data) => {
  if (err) {
    console.error('getPermissionDef failed:' + err.message);
  } else {
    console.info('getPermissionDef successfully:' + JSON.stringify(data));
  }
});
```

## bundle.getPermissionDef<sup>8+</sup> <sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager.getPermissionDef](js-apis-bundleManager-sys.md#bundlemanagergetpermissiondef) instead.

getPermissionDef(permissionName: string): Promise&lt;PermissionDef&gt;

Obtains the permission details by permission name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.BundleFramework

**System API**

This is a system API.

**Parameters**

| Name        | Type  | Mandatory | Description            |
| -------------- | ------ | ---- | ---------------- |
| permissionName | string | Yes  | Name of the permission. |

**Return value**

| Type                                                  | Description                                                  |
| ------------------------------------------------------ | ------------------------------------------------------ |
| Promise<[PermissionDef](js-apis-bundle-PermissionDef-sys.md)> | Promise used to return the permission details. |

**Example**

```ts
import bundle from '@ohos.bundle';
import { BusinessError } from '@ohos.base';

let permissionName: string = "ohos.permission.GET_BUNDLE_INFO";
bundle.getPermissionDef(permissionName).then((data) => {
  console.info('getPermissionDef successfully. Data: ' + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error('getPermissionDef failed. Cause: ' + error.message);
});
```
