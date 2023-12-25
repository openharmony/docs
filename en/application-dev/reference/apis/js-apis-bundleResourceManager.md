# @ohos.bundle.bundleResourceManager (bundleResourceManager)

The **bundleResourceManager** module provides APIs for obtaining resource information, including [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md) and [LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
```

## Required Permissions

| Permission                                      | Permission Level    | Description           |
| ------------------------------------------ | ------------ | ------------------|
|ohos.permission.GET_BUNDLE_RESOURCES| system_basic | Allows an application to obtain resource information of another application.|
| ohos.permission.GET_INSTALLED_BUNDLE_LIST | system_basic | Allows an application to read the list of installed applications.|

For details, see [Permission Levels](../../security/accesstoken-overview.md#permission-levels).

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


## APIs

### bundleResourceManager.getBundleResourceInfo

getBundleResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)

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
| [BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md) | Resource information of the application obtained.|


**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
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

getLauncherAbilityResourceInfo(bundleName: string, resourceFlags?: [number](#resourceflag)): Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>

Obtains the bundle information of the entry ability of an application based on the given bundle name and resource flags. This API returns the result synchronously.

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
| Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)> | Resource information of the entry ability obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
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

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>>): void

Obtains resource information of all applications based on the given resource flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST and ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | Yes  | Type of the resource information to obtain.|
| callback | AsyncCallback\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the resource information of the application obtained. Otherwise, **err** is an error object.|

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

getAllBundleResourceInfo(resourceFlags: [number](#resourceflag)): Promise<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>>;

Obtains resource information of all applications based on the given resource flags. This API uses a promise to return the result.

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
| Promise\<Array<[BundleResourceInfo](js-apis-bundleManager-BundleResourceInfo.md)>> | Promise used to return the resource information of the application obtained.|

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

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag), callback: AsyncCallback<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>>): void

Obtains resource information of the entry abilities of all applications based on the given resource flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST and ohos.permission.GET_BUNDLE_RESOURCES

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name    | Type  | Mandatory| Description               |
| ----------- | ------ | ---- | --------------------- |
| resourceFlags | [number](#resourceflag) | Yes  | Type of the resource information to obtain.|
| callback | AsyncCallback\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the resource information of the entry abilities obtained. Otherwise, **err** is an error object.|


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

getAllLauncherAbilityResourceInfo(resourceFlags: [number](#resourceflag)) : Promise<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>>

Obtains resource information of the entry abilities of all applications based on the given resource flags. This API uses a promise to return the result.

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
| Promise\<Array<[LauncherAbilityResourceInfo](js-apis-bundleManager-LauncherAbilityResourceInfo.md)>> | Promise used to return the resource information of the entry abilities obtained.|

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
