# @ohos.bundle.bundleResourceManager (bundleResourceManager) (System API)

The **bundleResourceManager** module provides APIs for obtaining resource information, including [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md) and [LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> Since API version 12, this module supports query of icons and names of disabled applications and applications installed by all users.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
```

## Required Permissions

| Permission                                      | APL    | Description           |
| ------------------------------------------ | ------------ | ------------------|
| ohos.permission.GET_BUNDLE_RESOURCES| system_basic | Allows an application to obtain resource information of another application.|
| ohos.permission.GET_INSTALLED_BUNDLE_LIST | system_basic | Allows an application to read the list of installed applications.|

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

## Enums

### ResourceFlag

Enumerates the resource information flags, which indicate the type of resource information to obtain.

**System API**: This is a system API.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Resource

| Name                                     | Value        | Description                                                        |
| ----------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_RESOURCE_INFO_ALL                   | 0x00000001 | Both the application icon and label are obtained.|
| GET_RESOURCE_INFO_WITH_LABEL          | 0x00000002 | Only the application label is obtained.|
| GET_RESOURCE_INFO_WITH_ICON           | 0x00000004 | Only the application icon is obtained.|
| GET_RESOURCE_INFO_WITH_SORTED_BY_LABEL| 0x00000008 | The obtained information is sorted by label. It must be used together with **GET_RESOURCE_INFO_ALL** or **GET_RESOURCE_INFO_WITH_LABEL**.|
| GET_RESOURCE_INFO_WITH_DRAWABLE_DESCRIPTOR<sup>12+</sup>| 0x00000010 | The [drawableDescriptor](../apis-arkui/js-apis-arkui-drawableDescriptor-sys.md) object of the application icon is obtained.|


## APIs

### bundleResourceManager.getBundleResourceInfo

getBundleResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)

Obtains the resource information of an application based on the given bundle name and resource flags. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| resourceFlags | [number](#resourceflag) | No  | Type of the resource information to obtain.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md) | Resource information of the application obtained.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |


**Example**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getLauncherAbilityResourceInfo

getLauncherAbilityResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>

Obtains the bundle information of the entry ability of an application based on the given bundle name and resource flags. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| resourceFlags | [number](#resourceflag) | No  | Type of the resource information to obtain. The default value is **[ResourceFlag](#resourceflag).GET_RESOURCE_INFO_ALL**.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)> | Resource information of the entry ability obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |


**Example**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    let resourceInfo = bundleResourceManager.getLauncherAbilityResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getLauncherAbilityResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo[0].label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllBundleResourceInfo

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>>): void

Obtains the bundle resource information of all applications based on the given resource flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST and ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | Yes  | Type of the resource information to obtain.|
| callback | AsyncCallback\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the resource information of the application obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllBundleResourceInfo(bundleFlags, (err, data) => {
        if (err) {
            hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo failed. err: %{public}s', err.message);
            return;
        }
        hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllBundleResourceInfo

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag)): Promise<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>>;

Obtains the bundle resource information of all applications based on the given resource flags. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST and ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | Yes  | Type of the resource information to obtain.|

**Return value**

| Type                                                        | Description                            |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)>> | Promise used to return the resource information of the application obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllBundleResourceInfo(bundleFlags).then(data=> {
        hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    }).catch((err: BusinessError) => {
        hilog.info(0x0000, 'testTag', 'getAllBundleResourceInfo failed. err: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllLauncherAbilityResourceInfo

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>>): void

Obtains the resource information of the entry abilities of the current application based on the given resource flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST and ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | Yes  | Type of the resource information to obtain.|
| callback | AsyncCallback\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the resource information of the entry abilities obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllLauncherAbilityResourceInfo(bundleFlags, (err, data) => {
        if (err) {
            hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed. err: %{public}s', err.message);
            return;
        }
        hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getAllLauncherAbilityResourceInfo

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag)) : Promise<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>>

Obtains the resource information of the entry abilities of the current application based on the given resource flags. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST and ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | Yes  | Type of the resource information to obtain.|

**Return value**

| Type                                                        | Description                            |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>> | Promise used to return the resource information of the entry abilities obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**
```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
try {
    bundleResourceManager.getAllLauncherAbilityResourceInfo(bundleFlags).then(data=> {
        hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo successfully. Data length: %{public}s', JSON.stringify(data.length));
    }).catch((err: BusinessError) => {
        hilog.info(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed. err: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllLauncherAbilityResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getBundleResourceInfo<sup>12+</sup>

getBundleResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag), appIndex?: number): [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md)

Obtains the resource information of an application based on the given bundle name, resource flags, and app index. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| resourceFlags | [number](#resourceflag) | No  | Type of the resource information to obtain.|
| appIndex | number | No  | Index of the application clone. The default value is **0**.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo-sys.md) | Resource information of the application obtained.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex not in valid range or not found. |


**Example**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
let appIndex = 1;
try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags, appIndex);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed: %{public}s', message);
}
```

### bundleResourceManager.getLauncherAbilityResourceInfo<sup>12+</sup>

getLauncherAbilityResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag), appIndex?: number): Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)>

Obtains the launcher ability resource information of an application based on the given bundle name, resource flags, and app index. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| resourceFlags | [number](#resourceflag) | No  | Type of the resource information to obtain. The default value is **[ResourceFlag](#resourceflag).GET_RESOURCE_INFO_ALL**.|
| appIndex | number | No  | Index of the application clone. The default value is **0**.|

**Return value**

| Type                                                       | Description                                 |
| ----------------------------------------------------------- | ------------------------------------- |
| Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo-sys.md)> | Resource information of the entry ability obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex not in valid range or not found. |

**Example**

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.example.myapplication";
let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
let appIndex = 1;
try {
    let resourceInfo = bundleResourceManager.getLauncherAbilityResourceInfo(bundleName, bundleFlags, appIndex);
    hilog.info(0x0000, 'testTag', 'getLauncherAbilityResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo[0].label));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLauncherAbilityResourceInfo failed: %{public}s', message);
}
```
