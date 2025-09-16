# @ohos.bundle.bundleManager (bundleManager) (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides APIs for obtaining application information, including [BundleInfo](js-apis-bundleManager-bundleInfo.md), [ApplicationInfo](js-apis-bundleManager-ApplicationInfo-sys.md), [AbilityInfo](js-apis-bundleManager-abilityInfo.md), and [ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.bundle.bundleManager](js-apis-bundleManager.md).

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## BundleFlag

Enumerates the bundle flags, which indicate the type of bundle information to obtain. The table below describes only flags available in system APIs. For details about flags available in public APIs, see [BundleFlag](./js-apis-bundleManager.md#bundleflag).

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                                         | Value        | Description                                                        |
| --------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_ONLY_WITH_LAUNCHER_ABILITY<sup>12+</sup> | 0x00001000 | Used to obtain the bundle information of the application that has only a home screen icon. It is valid only in the [getAllBundleInfo](#bundlemanagergetallbundleinfo) API.<br>**System API**: This flag can be used only in system APIs.|
| GET_BUNDLE_INFO_OF_ANY_USER<sup>12+</sup>      | 0x00002000 | Used to obtain the bundle information of an application installed by any user. It must be used together with **GET_BUNDLE_INFO_WITH_APPLICATION**. It is valid only in the [getBundleInfo](#bundlemanagergetbundleinfo14) and [getAllBundleInfo](#bundlemanagergetallbundleinfo) APIs.<br>**System API**: This flag can be used only in system APIs.|
| GET_BUNDLE_INFO_EXCLUDE_CLONE<sup>12+</sup> | 0x00004000 | Used to obtain the bundle information of a main application (excluding its clones). It is valid only in the [getAllBundleInfo](#bundlemanagergetallbundleinfo) API.<br>**System API**: This flag can be used only in system APIs.|
| GET_BUNDLE_INFO_WITH_CLOUD_KIT<sup>20+</sup> | 0x00008000 | Used to obtain the bundle information of an application that has device-cloud file synchronization or device-cloud structured data synchronization enabled. It is valid only in the [getAllBundleInfo](#bundlemanagergetallbundleinfo) API.<br>**System API**: This flag can be used only in system APIs.|

## ApplicationFlag

Enumerates the application flags, which indicate the type of application information to obtain.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name                                | Value        | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| GET_APPLICATION_INFO_DEFAULT         | 0x00000000 | Used to obtain the default application information. The obtained information does not contain the permission information or metadata.|
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000001 | Used to obtain the application information with permission information.                   |
| GET_APPLICATION_INFO_WITH_METADATA   | 0x00000002 | Used to obtain the application information with metadata.                     |
| GET_APPLICATION_INFO_WITH_DISABLE    | 0x00000004 | Used to obtain the application information of disabled bundles.                 |

## AbilityFlag

Enumerates the ability flags, which indicate the type of ability information to obtain.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name                             | Value        | Description                                                        |
| --------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_ABILITY_INFO_DEFAULT          | 0x00000000 | Used to obtain the default ability information. The obtained information does not contain the permission, metadata, or disabled ability information.|
| GET_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | Used to obtain the ability information with permission information.                         |
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | Used to obtain the ability information with application information.                    |
| GET_ABILITY_INFO_WITH_METADATA    | 0x00000004 | Used to obtain the ability information with metadata.                           |
| GET_ABILITY_INFO_WITH_DISABLE     | 0x00000008 | Used to obtain the ability information of disabled abilities.                  |
| GET_ABILITY_INFO_ONLY_SYSTEM_APP  | 0x00000010 | Used to obtain the ability information of system applications.                        |
| GET_ABILITY_INFO_WITH_APP_LINKING<sup>12+</sup>  | 0x00000040 | Used to obtain the ability information filtered by domain name verification.                        |
| GET_ABILITY_INFO_WITH_SKILL<sup>12+</sup>   | 0x00000080 | Used to obtain the ability information with skills.                        |

## ExtensionAbilityFlag

Enumerates the ExtensionAbility flags, which indicate the type of ExtensionAbility information to obtain.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name                                       | Value        | Description                                                        |
| ------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_EXTENSION_ABILITY_INFO_DEFAULT          | 0x00000000 | Used to obtain the default ExtensionAbility information. The obtained information does not contain the permission, metadata, or disabled ExtensionAbility information.|
| GET_EXTENSION_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | Used to obtain the ExtensionAbility information with permission information.              |
| GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | Used to obtain the ExtensionAbility information with application information.        |
| GET_EXTENSION_ABILITY_INFO_WITH_METADATA    | 0x00000004 | Used to obtain the ExtensionAbility information with metadata.                |
| GET_EXTENSION_ABILITY_INFO_WITH_SKILL<sup>12+</sup>     | 0x00000010 | Used to obtain the ExtensionAbility information with skills.                |

## ProfileType<sup>11+</sup>

Enumerates the types of profiles (also called application files).

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name          | Value  | Description           |
| -------------- | ---- | --------------- |
| INTENT_PROFILE  | 1    | Profile of the InsightIntent framework.   |

## AppDistributionType<sup>12+</sup>

Enumerates the application [distribution types](../../security/app-provision-structure.md).

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name             | Value  | Description           |
| ----------------- | ---- | --------------- |
| APP_GALLERY       | 1    | Application installed from AppGallery.   |
| ENTERPRISE        | 2    | Enterprise application that can be installed on personal devices.   |
| ENTERPRISE_NORMAL | 3    | Common enterprise application that can be installed on enterprise devices only through an enterprise mobile device management (MDM) application.   |
| ENTERPRISE_MDM    | 4    | Enterprise MDM application that can be installed only on enterprise devices. To install a common enterprise application, you must have [administrator privileges](../apis-mdm-kit/js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin).   |
| OS_INTEGRATION    | 5    | Preinstalled system application.   |
| CROWDTESTING      | 6    | Application under crowdtesting, which is distributed by AppGallery to a limited number of users and come with a set expiration date. When the system detects that the validity period of the application expires, it prompts the user to update to the release version available on AppGallery.   |
| NONE              | 7    | Other.          |

## ApplicationInfoFlag<sup>12+</sup>
Enumerates the application information flag, which describes the status between an application and user.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name| Value| Description|
|----------------|---|---|
| FLAG_INSTALLED|  0x00000001 | The application is installed for the specified user.|
| FLAG_OTHER_INSTALLED<sup>15+</sup>|  0x00000010 | The application is installed for users other than the specified user.|
| FLAG_PREINSTALLED_APP<sup>15+</sup>|  0x00000020 | The application is a preinstalled application.|
| FLAG_PREINSTALLED_APP_UPDATE<sup>15+</sup>|  0x00000040 | The preinstalled application is updated.|

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the ability information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

```ts
// Obtain the bundle information with the metadata in the application information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle name and bundle flags. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the ExtensionAbility information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getBundleInfo<sup>14+</sup>

getBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<BundleInfo>

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.      |
| userId      | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the application and signature information.
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfo failed. Cause: %{public}s', message);
}

```

## bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void

Obtains the application information based on the given bundle name, application flags, and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|
| appFlags   | [number](#applicationflag) | Yes  | Type of the application information to obtain.   |
| userId     | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: number, callback: AsyncCallback\<ApplicationInfo>): void

Obtains the application information based on the given bundle name and application flags. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|
| appFlags   | [number](#applicationflag) | Yes  | Type of the application information to obtain.   |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: number, userId?: number): Promise\<ApplicationInfo>

Obtains the application information based on the given bundle name, application flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|
| appFlags   | [number](#applicationflag) | Yes  | Type of the application information to obtain.   |
| userId     | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                                                        | Description                            |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Promise used to return the application information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getApplicationInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, userId: number, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains all the bundle information in the system based on the given bundle flags and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.                   |
| userId      | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                     |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | --------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    bundleManager.getAllBundleInfo(bundleFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains all the bundle information in the system based on the given bundle flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.  |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, userId?: number): Promise<Array\<BundleInfo>>

Obtains all the bundle information in the system based on the given bundle flags and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.                  |
| userId      | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.                     |

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Promise used to return the array of bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, userId: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

Obtains all the application information in the system based on the given application flags and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| userId   | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).        |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getAllApplicationInfo(appFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

Obtains all the application information in the system based on the given application flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, userId?: number): Promise<Array\<ApplicationInfo>>

Obtains all the application information in the system based on the given application flags and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ---------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| userId   | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.                       |

**Return value**

| Type                                                        | Description                                    |
| ------------------------------------------------------------ | ---------------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Promise used to return the array of application information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllApplicationInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllApplicationInfo failed. Cause: %{public}s', message);
}

```

## bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, userId: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

Obtains the ability information based on the given Want, ability flags, and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.                      |
| userId       | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                              |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

Obtains the ability information based on the given Want and ability flags. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | -------------------------------------------------------|
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.      |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

Obtains the ability information based on the given Want, ability flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.|
| userId       | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.                      |

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise used to return the array of ability information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.queryAbilityInfoSync<sup>10+</sup>

queryAbilityInfoSync(want: Want, abilityFlags: number, userId?: number): Array\<AbilityInfo>

Obtains the ability information based on the given want, ability flags, and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.|
| userId       | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.                      |

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | An array of ability information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {

    let infos = bundleManager.queryAbilityInfoSync(want, abilityFlags, userId);
    hilog.info(0x0000, 'testTag', 'queryAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(infos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfoSync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let infos = bundleManager.queryAbilityInfoSync(want, abilityFlags);
    hilog.info(0x0000, 'testTag', 'queryAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(infos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.queryAbilityInfo<sup>12+</sup>

queryAbilityInfo(wants: Array\<Want>, abilityFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

Obtains the ability information based on the given Want list, ability flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Array\<Want>   | Yes  | List of want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.|
| userId       | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.                      |

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise used to return an array of [AbilityInfo](js-apis-bundleManager-abilityInfo.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication1",
    abilityName : "EntryAbility"
};
let want1: Want = {
    bundleName : "com.example.myapplication2",
    abilityName : "EntryAbility"
};
let wants: Array<Want> = [ want, want1 ];
 try {
        bundleManager.queryAbilityInfo(wants, abilityFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
      })
    } catch (err) {
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
    }
```

## bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

Obtains the ExtensionAbility information based on the given Want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                                        | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | Yes  | Want containing the bundle name to query.                      |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype)                | Yes  | Type of the ExtensionAbility.                                |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | Yes  | Type of the ExtensionAbility information to obtain.   |
| userId                | number                                                       | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                                                |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ExtensionAbility information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

Obtains the ExtensionAbility information based on the given Want, ExtensionAbility type, and ExtensionAbility flags. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                                        | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | Yes  | Want containing the bundle name to query.                      |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype)                | Yes  | Type of the ExtensionAbility.                                |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | Yes  | Type of the ExtensionAbility information to obtain.   |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ExtensionAbility information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId?: number): Promise<Array\<ExtensionAbilityInfo>>

Obtains the ExtensionAbility information based on the given Want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                         | Mandatory| Description                                                     |
| --------------------- | --------------------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                                          | Yes  | Want containing the bundle name to query.                   |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | Yes  | Type of the ExtensionAbility.                             |
| extensionAbilityFlags | [number](#extensionabilityflag)               | Yes  | Type of the ExtensionAbility information to obtain.|
| userId                | number                                        | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.                                             |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Promise used to return the array of ExtensionAbility information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';

let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', err.message);
    })
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfoSync<sup>10+</sup>

queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

Obtains the ExtensionAbility information based on the given Want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                         | Mandatory| Description                                                     |
| --------------------- | --------------------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                                          | Yes  | Want containing the bundle name to query.                   |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager.md#extensionabilitytype) | Yes  | Type of the ExtensionAbility.                             |
| extensionAbilityFlags | [number](#extensionabilityflag)               | Yes  | Type of the ExtensionAbility information to obtain.|
| userId                | number                                        | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.                                             |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | An array of ExtensionAbility information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';

let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let extenInfos = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags, userId);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(extenInfos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let extenInfos = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(extenInfos));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void

Obtains the bundle name based on the given UID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                 | Yes  | UID of the application.                                           |
| callback | AsyncCallback\<string> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle name obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed: %{public}s', message);
}
```

## bundleManager.getBundleNameByUid<sup>14+</sup>

getBundleNameByUid(uid: number): Promise\<string>

Obtains the bundle name based on the given UID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise\<string> | Promise used to return the bundle name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleNameByUid successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUid failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleNameByUidSync<sup>14+</sup>

getBundleNameByUidSync(uid: number): string

Obtains the bundle name based on the given UID. This API returns the result synchronously.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type  | Mandatory| Description               |
| ---- | ------ | ---- | ------------------ |
| uid  | number | Yes  | UID of the application.|

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| string | Bundle name obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;
try {
    let data = bundleManager.getBundleNameByUidSync(uid);
    hilog.info(0x0000, 'testTag', 'getBundleNameByUidSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUidSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given HAP file path and bundle flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ----------------------------------------------------------- |
| hapFilePath | string | Yes  | Path where the HAP file is stored. The path must be the relative path of the current bundle's data directory.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.      |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                 |
| -------- | --------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getBundleArchiveInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string,  bundleFlags: number): Promise\<BundleInfo>

Obtains the bundle information based on the given HAP file path and bundle flags. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | Yes  | Path where the HAP file is stored. The path must be the relative path of the current bundle's data directory.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.      |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags).then((data) => {
        hilog.info(0x0000, 'testTag', 'getBundleArchiveInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getBundleArchiveInfoSync<sup>10+</sup>

getBundleArchiveInfoSync(hapFilePath: string, bundleFlags: number): BundleInfo

Obtains the bundle information based on the given HAP file path and bundle flags. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | Yes  | Path where the HAP file is stored. The path must be the relative path of the current bundle's data directory.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.      |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    let data = bundleManager.getBundleArchiveInfoSync(hapFilePath, bundleFlags)
    hilog.info(0x0000, 'testTag', 'getBundleArchiveInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleArchiveInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllBundleCacheSize<sup>15+</sup>

getAllBundleCacheSize(): Promise\<number>

Obtains the global cache size. This API uses a promise to return the result.

It is not possible to obtain the cache of applications that are currently running or have been granted the "AllowAppDataNotCleared" privilege as specified in the [application configuration guide](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<number> | Promise used to return the size of the global cache, in bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllBundleCacheSize().then((data) => {
        hilog.info(0x0000, 'testTag','getAllBundleCacheSize successful. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllBundleCacheSize failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleCacheSize failed: %{public}s', message);
}
```

## bundleManager.cleanAllBundleCache<sup>15+</sup>

cleanAllBundleCache(): Promise\<void>

Clears the global cache. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REMOVE_CACHE_FILES

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.cleanAllBundleCache().then((data) => {
        hilog.info(0x0000, 'testTag','cleanAllBundleCache successful.');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'cleanAllBundleCache failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanAllBundleCache failed: %{public}s', message);
}
```

## bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void

Clears the bundle cache based on the given bundle name. This API uses an asynchronous callback to return the result.

No permission is required when the caller clears its own cache.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REMOVE_CACHE_FILES

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                  |
| callback   | AsyncCallback\<void> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                        |
| 17700030 | The specified bundle does not support clearing of cache files. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName, err => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);
}
```

## bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string): Promise\<void>

Clears the bundle cache based on the given bundle name. This API uses a promise to return the result.

No permission is required when the caller clears its own cache.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REMOVE_CACHE_FILES

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                      |
| ---------- | ------ | ---- | ------------------------------------------ |
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. If clearing the cache files fails, an error object is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                      |
| 17700030 | The specified bundle does not support clearing of cache files. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName).then(() => {
        hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);
}
```

## bundleManager.cleanBundleCacheFiles<sup>15+</sup>

cleanBundleCacheFiles(bundleName: string, appIndex: number): Promise\<void>

Clears the bundle cache based on the given bundle name and application index. This API uses a promise to return the result.

No permission is required when the caller clears its own cache.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REMOVE_CACHE_FILES

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                      |
| ---------- | ------ | ---- | ------------------------------------------ |
| bundleName | string | Yes  | Bundle name.|
| appIndex | number | Yes  | Index of the application clone.<br>The value **0** means to clear the cache of the main application. A value greater than 0 means to clear the cache data of the application clone.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. If clearing the cache files fails, an error object is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                      |
| 17700030 | The specified bundle does not support clearing of cache files. |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let appIndex = 1;

try {
    bundleManager.cleanBundleCacheFiles(bundleName, appIndex).then(() => {
        hilog.info(0x0000, 'testTag', 'cleanBundleCacheFiles successfully.');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'cleanBundleCacheFiles failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.               |
| isEnabled  | boolean | Yes  | Whether to enable the application. **true** to enable, **false** otherwise.|
| callback | AsyncCallback\<void> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false, err => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'setApplicationEnabled successfully.');
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean): Promise\<void>

Enables or disables an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.           |
| isEnabled  | boolean | Yes  | Whether to enable the application. **true** to enable, **false** otherwise.|

**Return value**

| Type          | Description                                |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false).then(() => {
        hilog.info(0x0000, "testTag", "setApplicationEnabled successfully.");
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabled<sup>12+</sup>

setApplicationEnabled(bundleName: string, appIndex: number, isEnabled: boolean): Promise\<void>

Enables or disables an application or an application clone. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.           |
| appIndex   | number  | Yes  | Index of the application clone.<br>The value **0** means to enable or disable the main application. A value greater than 0 means to enable or disable the application clone.             |
| isEnabled  | boolean | Yes  | Whether to enable the application or application clone. **true** to enable, **false** otherwise.|

**Return value**

| Type          | Description                                |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, 1, false).then(() => {
        hilog.info(0x0000, "testTag", "setApplicationEnabled successfully.");
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.setApplicationEnabledSync<sup>10+</sup>

setApplicationEnabledSync(bundleName: string, isEnabled: boolean): void

Enables or disables an application. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.               |
| isEnabled  | boolean | Yes  | Whether to enable the application. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabledSync(bundleName, false);
    hilog.info(0x0000, 'testTag', 'setApplicationEnabledSync successfully.');
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabledSync failed: %{public}s', message);
}
```

## bundleManager.setAbilityEnabled

setAbilityEnabled(info: AbilityInfo, isEnabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables an ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.             |
| isEnabled| boolean     | Yes  | Whether to enable the ability. **true** to enable, **false** otherwise.|
| callback | AsyncCallback\<void> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ---------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false, err => {
            if (err) {
                hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);
            } else {
                hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");
            }
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.setAbilityEnabled

setAbilityEnabled(info: AbilityInfo, isEnabled: boolean): Promise\<void>

Enables or disables an ability. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.                  |
| isEnabled| boolean     | Yes  | Whether to enable the ability. **true** to enable, **false** otherwise.|

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false).then(() => {
            hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.setAbilityEnabled<sup>12+</sup>

setAbilityEnabled(info: AbilityInfo, appIndex: number, isEnabled: boolean): Promise\<void>

Enables or disables an ability of an application or an application clone. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.                  |
| appIndex   | number    | Yes  | Index of the application clone.<br>The value **0** means to enable or disable the ability of the main application. A value greater than 0 means to enable or disable the ability of the application clone.           |
| isEnabled| boolean     | Yes  | Whether to enable the ability. **true** to enable, **false** otherwise.|

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, 1, false).then(() => {
            hilog.info(0x0000, "testTag", "setAbilityEnabled successfully.");
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'setAbilityEnabled failed: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.setAbilityEnabledSync<sup>10+</sup>

setAbilityEnabledSync(info: AbilityInfo, isEnabled: boolean): void

Enables or disables an ability. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.             |
| isEnabled| boolean     | Yes  | Whether to enable the ability. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ---------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        try {
            bundleManager.setAbilityEnabledSync(info, false);
            hilog.info(0x0000, "testTag", "setAbilityEnabledSync successfully.");
        } catch (err) {
            let message = (err as BusinessError).message;
            hilog.error(0x0000, 'testTag', 'setAbilityEnabledSync failed: %{public}s', message);
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void

Checks whether an application is enabled. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name.|
| callback | AsyncCallback\<boolean> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed: %{public}s', message);
}
```

## bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string): Promise\<boolean>

Checks whether an application is enabled. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name. |

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', message);
}
```

## bundleManager.isApplicationEnabled<sup>12+</sup>

isApplicationEnabled(bundleName: string, appIndex: number): Promise\<boolean>

Checks whether an application or an application clone is enabled. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name. |
| appIndex   | number  | Yes  | Index of the application clone.<br>The value **0** means to obtain the enabled status of the main application. A value greater than 0 means to obtain the enabled status of the application clone.           |

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName, 1).then((data) => {
        hilog.info(0x0000, 'testTag', 'isApplicationEnabled successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabled failed. Cause: %{public}s', message);
}
```

## bundleManager.isApplicationEnabledSync<sup>10+</sup>

isApplicationEnabledSync(bundleName: string): boolean

Checks whether an application is enabled. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Check result for whether the application is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    let data = bundleManager.isApplicationEnabledSync(bundleName);
    hilog.info(0x0000, 'testTag', 'isApplicationEnabledSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabledSync failed: %{public}s', message);
}
```

## bundleManager.isAbilityEnabled

isAbilityEnabled(info: AbilityInfo, callback: AsyncCallback\<boolean>): void

Checks whether an ability is enabled. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type       | Mandatory| Description                       |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.|
| callback | AsyncCallback\<boolean> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info, (err, data) => {
            if (err) {
                hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed: %{public}s', err.message);
            } else {
                hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully: %{public}s', JSON.stringify(data));
            }
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isAbilityEnabled

isAbilityEnabled(info: AbilityInfo): Promise\<boolean>

Checks whether an ability is enabled. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type       | Mandatory| Description                       |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info).then((data) => {
            hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully. Data: %{public}s', JSON.stringify(data));
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed. Cause: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isAbilityEnabled<sup>12+</sup>

isAbilityEnabled(info: AbilityInfo, appIndex: number): Promise\<boolean>

Checks whether an ability of an application or an application clone is enabled. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type       | Mandatory| Description                       |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.|
| appIndex   | number  | Yes  | Index of the application clone.<br>The value **0** means to obtain the enabled status of the ability of the main application. A value greater than 0 means to obtain the enabled status of the ability of the application clone.          |

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700061 | AppIndex is not in the valid range. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info, 1).then((data) => {
            hilog.info(0x0000, 'testTag', 'isAbilityEnabled successfully. Data: %{public}s', JSON.stringify(data));
        }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', 'isAbilityEnabled failed. Cause: %{public}s', err.message);
        });
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.isAbilityEnabledSync<sup>10+</sup>

isAbilityEnabledSync(info: AbilityInfo): boolean

Checks whether an ability is enabled. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type       | Mandatory| Description                       |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.|

**Return value**

| Type   | Description                                                                |
| ------- | ------------------------------------------------------------------- |
| boolean | Check result for whether the ability is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        hilog.info(0x0000, 'testTag', 'queryAbilityInfo successfully. Data: %{public}s', JSON.stringify(abilitiesInfo));
        let info = abilitiesInfo[0];

        try {
            let data = bundleManager.isAbilityEnabledSync(info);
            hilog.info(0x0000, 'testTag', 'isAbilityEnabledSync successfully: %{public}s', JSON.stringify(data));
        } catch (err) {
            let message = (err as BusinessError).message;
            hilog.error(0x0000, 'testTag', 'isAbilityEnabledSync failed: %{public}s', message);
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryAbilityInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId: number, callback: AsyncCallback\<Want>): void

Obtains the Want used to launch the bundle based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                                    |
| userId     | number               | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                                                  |
| callback   | AsyncCallback\<Want> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the Want. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', message);
}
```

## bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void

Obtains the Want used to launch the bundle based on the given bundle name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                                    |
| callback   | AsyncCallback\<Want> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the Want. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';

try {
    bundleManager.getLaunchWantForBundle(bundleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed: %{public}s', message);
}
```

## bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId?: number): Promise\<Want>

Obtains the Want used to launch the bundle based on the given bundle name and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<Want> | Promise used to return the Want object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getLaunchWantForBundle successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundle failed. Cause: %{public}s', message);
}
```


## bundleManager.getLaunchWantForBundleSync<sup>10+</sup>

getLaunchWantForBundleSync(bundleName: string, userId?: number): Want

Obtains the Want used to launch the bundle based on the given bundle name and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Want | Want object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Calling interface without permission 'ohos.permission.GET_BUNDLE_INFO_PRIVILEGED'. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName, userId);
    hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    let want: Want = bundleManager.getLaunchWantForBundleSync(bundleName);
    hilog.info(0x0000, 'testTag', 'getLaunchWantForBundleSync successfully. Data: %{public}s', JSON.stringify(want));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getLaunchWantForBundleSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getPermissionDef

getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void

Obtains the PermissionDef struct based on the given permission name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                        | Mandatory| Description                                                        |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| permissionName | string                                                       | Yes  | Name of the permission.                                              |
| callback       | AsyncCallback\<[PermissionDef](js-apis-bundleManager-permissionDef-sys.md)> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the PermissionDef object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let permission = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permission, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getPermissionDef failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getPermissionDef successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getPermissionDef failed: %{public}s', message);
}
```

## bundleManager.getPermissionDef

getPermissionDef(permissionName: string): Promise\<PermissionDef>

Obtains the PermissionDef struct based on the given permission name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type  | Mandatory| Description          |
| -------------- | ------ | ---- | -------------- |
| permissionName | string | Yes  | Name of the permission.|

**Return value**

| Type                                                        | Description                                      |
| ------------------------------------------------------------ | ------------------------------------------ |
| Promise\<[PermissionDef](js-apis-bundleManager-permissionDef-sys.md)> | Promise used to return the PermissionDef object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let permissionName = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permissionName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getPermissionDef successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getPermissionDef failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getPermissionDef failed. Cause: %{public}s', message);
}
```

## bundleManager.getPermissionDefSync<sup>10+</sup>

getPermissionDefSync(permissionName: string): PermissionDef;

Obtains the **PermissionDef** struct based on the given permission name. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type  | Mandatory| Description          |
| -------------- | ------ | ---- | -------------- |
| permissionName | string | Yes  | Name of the permission.|

**Return value**

| Type                                                        | Description                                      |
| ------------------------------------------------------------ | ------------------------------------------ |
|[PermissionDef](js-apis-bundleManager-permissionDef-sys.md) | PermissionDef object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let permissionName = "ohos.permission.GET_BUNDLE_INFO";
try {
    let PermissionDef = bundleManager.getPermissionDefSync(permissionName);
    hilog.info(0x0000, 'testTag', 'getPermissionDefSync successfully. Data: %{public}s', JSON.stringify(PermissionDef));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getPermissionDefSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<string>): void

Obtains the label based on the given bundle name, module name, and ability name. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type                  | Mandatory| Description                                                        |
| ----------- | ---------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                 | Yes  | Bundle name.                                    |
| moduleName  | string                 | Yes  | Module name.                                    |
| abilityName | string                 | Yes  | Name of the UIAbility component.                                   |
| callback    | AsyncCallback\<string> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the label. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAbilityLabel failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAbilityLabel successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAbilityLabel failed: %{public}s', message);
}
```

## bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>

Obtains the label based on the given bundle name, module name, and ability name. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type  | Mandatory| Description                     |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | Yes  | Bundle name. |
| moduleName  | string | Yes  | Module name. |
| abilityName | string | Yes  | Name of the UIAbility component.|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the label.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAbilityLabel successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAbilityLabel failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAbilityLabel failed. Cause: %{public}s', message);
}
```

## bundleManager.getAbilityLabelSync<sup>10+</sup>

getAbilityLabelSync(bundleName: string, moduleName: string, abilityName: string): string

Obtains the ability label based on the given bundle name, module name, and ability name. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type  | Mandatory| Description                     |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | Yes  | Bundle name. |
| moduleName  | string | Yes  | Module name. |
| abilityName | string | Yes  | Name of the UIAbility component.|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| string | Label of the ability.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'EntryAbility';

try {
    let abilityLabel = bundleManager.getAbilityLabelSync(bundleName, moduleName, abilityName);
    hilog.info(0x0000, 'testTag', 'getAbilityLabelSync successfully. Data: %{public}s', abilityLabel);
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAbilityLabelSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number, userId: number) : ApplicationInfo

Obtains the application information based on the given bundle name, application flags, and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                      |
| ----------- | ------ | ---- | ----------------------------------------------------------|
| bundleName  | string | Yes  | Bundle name.                                 |
| applicationFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.      |
| userId      | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                                        |

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Application information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags, userId);
    hilog.info(0x0000, 'testTag', 'getApplicationInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfoSync failed: %{public}s', message);
}
```

## bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number) : ApplicationInfo

Obtains the application information based on the given bundle name and application flags. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                      | Mandatory| Description                                                 |
| ---------------- | -------------------------- | ---- | ----------------------------------------------------- |
| bundleName       | string                     | Yes  | Bundle name.                           |
| applicationFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.|

**Return value**

| Type                                                       | Description                     |
| ----------------------------------------------------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Application information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags);
    hilog.info(0x0000, 'testTag', 'getApplicationInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number, userId: number): BundleInfo

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | Yes  | Bundle name.                                |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                                            |

**Return value**

| Type      | Description                |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getBundleInfoSync<sup>14+</sup>

getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo

Obtains the bundle information for the caller's user based on the given bundle name and bundle flags. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                                  |
| ----------- | --------------------- | ---- | ------------------------------------------------------ |
| bundleName  | string                | Yes  | Bundle name.                            |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type                                             | Description                |
| ------------------------------------------------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleInfoSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleInfoSync failed: %{public}s', message);
}
```

## bundleManager.getSharedBundleInfo<sup>10+</sup>

getSharedBundleInfo(bundleName: string,  moduleName: string, callback: AsyncCallback\<Array\<SharedBundleInfo\>\>): void

Obtains the shared bundle information based on the given bundle name. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string                                                       | Yes  | Bundle name.                                  |
| moduleName | string                                                       | Yes  | Module name.                                  |
| callback   | AsyncCallback\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the shared bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'library';

try {
    bundleManager.getSharedBundleInfo(bundleName, moduleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getSharedBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getSharedBundleInfo<sup>10+</sup>

getSharedBundleInfo(bundleName: string, moduleName: string): Promise\<Array\<SharedBundleInfo\>\>

Obtains the shared bundle information based on the given bundle name. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name.|
| moduleName | string | Yes  | Module name.|

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Promise used to return the shared bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'library';

try {
    bundleManager.getSharedBundleInfo(bundleName, moduleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getSharedBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getSharedBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllSharedBundleInfo<sup>10+</sup>

getAllSharedBundleInfo(callback: AsyncCallback\<Array\<SharedBundleInfo\>\>): void

Obtains all the shared bundle information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is all the shared bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllSharedBundleInfo((err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAllSharedBundleInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed: %{public}s', message);
}
```

## bundleManager.getAllSharedBundleInfo<sup>10+</sup>

getAllSharedBundleInfo(): Promise\<Array\<SharedBundleInfo\>\>

Obtains all the shared bundle information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Promise used to return an array of the shared bundle information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllSharedBundleInfo().then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllSharedBundleInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllSharedBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, callback: AsyncCallback\<AppProvisionInfo\>): void

Obtains the provision profile based on the given bundle name. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes  | Bundle name.|
| callback | AsyncCallback\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the provision profile.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.getAppProvisionInfo(bundleName, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, userId: number, callback: AsyncCallback\<AppProvisionInfo\>): void

Obtains the provision profile based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes  | Bundle name.|
| userId | number | Yes| User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).|
| callback | AsyncCallback\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the provision profile.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let userId = 100;

try {
    bundleManager.getAppProvisionInfo(bundleName, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, userId?: number): Promise\<AppProvisionInfo\>

Obtains the provision profile based on the given bundle name and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type        | Mandatory| Description         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes| Bundle name.|
| userId | number | No| User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.|


**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | Promise used to return the provision profile obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let userId = 100;

try {
    bundleManager.getAppProvisionInfo(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', message);
}

try {
    bundleManager.getAppProvisionInfo(bundleName, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAppProvisionInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppProvisionInfoSync<sup>10+</sup>

getAppProvisionInfoSync(bundleName: string, userId?: number): AppProvisionInfo

Obtains the provision profile based on the given bundle name and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type        | Mandatory| Description         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes| Bundle name.|
| userId | number | No| User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.|


**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| [AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md) | Provision profile.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = "com.ohos.myapplication";
let userId = 100;

try {
    let data = bundleManager.getAppProvisionInfoSync(bundleName);
    hilog.info(0x0000, 'testTag', 'getAppProvisionInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfoSync failed. Cause: %{public}s', message);
}

try {
    let data = bundleManager.getAppProvisionInfoSync(bundleName, userId);
    hilog.info(0x0000, 'testTag', 'getAppProvisionInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppProvisionInfoSync failed. Cause: %{public}s', message);
}
```

## bundleManager.getSpecifiedDistributionType<sup>10+</sup>
getSpecifiedDistributionType(bundleName: string): string

Obtains the [distribution type](../../security/app-provision-structure.md) of a bundle in synchronous mode. The return value is the **specifiedDistributionType** field value in [InstallParam](./js-apis-installer-sys.md#installparam) passed when **install** is called.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name        | Type                               | Mandatory| Description                        |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type         | Description                                  |
| ------------- | -------------------------------------- |
| string | [Distribution type](../../security/app-provision-structure.md) of the bundle.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**
```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication";

try {
    let type = bundleManager.getSpecifiedDistributionType(bundleName);
    console.info('getSpecifiedDistributionType successfully, type:' + type);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getSpecifiedDistributionType failed. Cause: ' + message);
}
```


## bundleManager.getAdditionalInfo<sup>10+</sup>

getAdditionalInfo(bundleName: string): string

Obtains additional information about a bundle in synchronous mode. The return value is the **additionalInfo** field value in [InstallParam](./js-apis-installer-sys.md#installparam) passed when **install** is called.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name        | Type                               | Mandatory| Description                        |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type         | Description                                  |
| ------------- | -------------------------------------- |
| string | Additional information about the bundle.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication";

try {
    let info = bundleManager.getAdditionalInfo(bundleName);
    console.info('getAdditionalInfo successfully, additionInfo:' + info);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getAdditionalInfo failed. Cause: ' + message);
}
```

## bundleManager.queryExtensionAbilityInfoSync<sup>11+</sup>

queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: string, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

Obtains the ExtensionAbility information based on the given Want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API returns the result synchronously.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                           | Mandatory| Description                                                     |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                            | Yes  | Want containing the bundle name to query.                   |
| extensionAbilityType  | string                          | Yes  | Type of the custom ExtensionAbility.                       |
| extensionAbilityFlags | [number](#extensionabilityflag) | Yes  | Information flags to be contained in the returned ExtensionAbilityInfo object.|
| userId                | number                          | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | An array of ExtensionAbility information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri, type or linkFeature) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
// Call the API with the userId parameter specified.
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags, userId)
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

```ts
// Call the API without passing in the userId parameter.
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want: Want = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility"
};

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(want, extensionAbilityType, extensionFlags);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

## bundleManager.getJsonProfile<sup>11+</sup>

getJsonProfile(profileType: ProfileType, bundleName: string, moduleName?: string, userId?: number): string

Obtains the JSON strings of the profile based on the given profile type, bundle name, and module name. This API returns the result synchronously.

No permission is required for obtaining the caller's own profile.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                           | Mandatory| Description                                                     |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| profileType           | [ProfileType](#profiletype11)     | Yes  | Type of the profile.                                  |
| bundleName            | string                          | Yes  | Bundle name of the application.                                 |
| moduleName            | string                          | No  | Module name of the application. If this parameter is not passed in, the entry module is used.           |
| userId<sup>12+</sup>  | number                          | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type  | Description                     |
| ------ | ------------------------ |
| string | JSON string of the profile.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.       |
| 17700002 | The specified moduleName is not found.       |
| 17700004 | The specified user ID is not found.      |
| 17700024 | Failed to get the profile because the specified profile is not found in the HAP. |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let profileType = bundleManager.ProfileType.INTENT_PROFILE;

try {
    let data = bundleManager.getJsonProfile(profileType, bundleName, moduleName)
    hilog.info(0x0000, 'testTag', 'getJsonProfile successfully. Data: %{public}s', data);
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getJsonProfile failed: %{public}s', message);
}
```

## bundleManager.getRecoverableApplicationInfo<sup>11+</sup>

getRecoverableApplicationInfo(callback: AsyncCallback\<Array\<RecoverableApplicationInfo\>\>): void

Obtains information about all preinstalled applications that can be restored. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[RecoverableApplicationInfo](js-apis-bundleManager-recoverableApplicationInfo-sys.md)\>\> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the information about all preinstalled applications.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getRecoverableApplicationInfo((err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getRecoverableApplicationInfo successfully: %{public}s', JSON.stringify(data));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.getRecoverableApplicationInfo<sup>11+</sup>

getRecoverableApplicationInfo(): Promise\<Array\<RecoverableApplicationInfo\>\>

Obtains information about all preinstalled applications that can be restored. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<Array\<[RecoverableApplicationInfo](js-apis-bundleManager-recoverableApplicationInfo-sys.md)\>\> | Promise used to return the information about all recoverable applications.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getRecoverableApplicationInfo().then((data) => {
        hilog.info(0x0000, 'testTag', 'getRecoverableApplicationInfo successfully: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getRecoverableApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.setAdditionalInfo<sup>11+</sup>

setAdditionalInfo(bundleName: string, additionalInfo: string): void

Sets additional information for an application. This API can be called only by AppGallery.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                            | Mandatory| Description                                              |
| --------------------- | ------------------------------- | ---- | -------------------------------------------------- |
| bundleName            | string                          | Yes  | Bundle name.                                   |
| additionalInfo        | string                          | Yes  | Additional information to set.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                   |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found.                     |
| 17700053 | The caller is not AppGallery.                                     |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName = "com.example.myapplication";
let additionalInfo = "xxxxxxxxx,formUpdateLevel:4";

try {
    bundleManager.setAdditionalInfo(bundleName, additionalInfo);
    hilog.info(0x0000, 'testTag', 'setAdditionalInfo successfully.');
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setAdditionalInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllPreinstalledApplicationInfo<sup>12+</sup>

getAllPreinstalledApplicationInfo(): Promise\<Array\<PreinstalledApplicationInfo\>\>

Obtains information about all preinstalled applications. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[PreinstalledApplicationInfo](js-apis-bundleManager-ApplicationInfo-sys.md)>> | Promise used to return the array of preinstalled applications obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                   |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    bundleManager.getAllPreinstalledApplicationInfo().then((data)=>{
        hilog.info(0x0000, 'testTag', 'getAllPreinstalledApplicationInfo success, Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllPreinstalledApplicationInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllPreinstalledApplicationInfo failed: %{public}s', message);
}
```

## bundleManager.queryExtensionAbilityInfoSync<sup>11+</sup>

queryExtensionAbilityInfoSync(extensionAbilityType: string, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

Obtains the ExtensionAbility information based on the given ExtensionAbility type, ExtensionAbility flags, and user ID.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                           | Mandatory| Description                                                     |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| extensionAbilityType  | string                          | Yes  | Type of the custom ExtensionAbility.                       |
| extensionAbilityFlags | [number](#extensionabilityflag) | Yes  | Information flags to be contained in the returned ExtensionAbilityInfo object.|
| userId                | number                          | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | An array of ExtensionAbility information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter extensionAbilityType is empty. |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |

**Example**

```ts
// Call the API with the userId parameter specified.
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(extensionAbilityType, extensionFlags, userId)
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

```ts
// Call the API without passing in the userId parameter.
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let extensionAbilityType = "form";
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;

try {
    let data = bundleManager.queryExtensionAbilityInfoSync(extensionAbilityType, extensionFlags);
    hilog.info(0x0000, 'testTag', 'queryExtensionAbilityInfoSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'queryExtensionAbilityInfoSync failed: %{public}s', message);
}
```

## bundleManager.getAllBundleInfoByDeveloperId<sup>12+</sup>

getAllBundleInfoByDeveloperId(developerId: string): Array\<BundleInfo>

Obtains the information about all bundles of the current user based on the given developer ID.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type     | Mandatory| Description                    |
| --------------------- | ---------| ---- | --------------------- |
| developerId           | string   | Yes  | Developer ID.      |

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>    | An array of bundle information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter developerId is empty. |
| 17700059 | The specified developerId is invalid.       |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let developerId = "123456.789";

try {
    let data = bundleManager.getAllBundleInfoByDeveloperId(developerId);
    hilog.info(0x0000, 'testTag', 'getAllBundleInfoByDeveloperId successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfoByDeveloperId failed: %{public}s', message);
}
```

## bundleManager.getDeveloperIds<sup>12+</sup>

getDeveloperIds(appDistributionType?: number): Array\<string>

Obtains all the developer IDs of the current user based on the given application [distribution type](#appdistributiontype12).

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type     | Mandatory| Description                    |
| --------------------- | ---------| ---- | --------------------- |
| [appDistributionType](#appdistributiontype12)  | number   | No  | Application distribution type. If this parameter is not specified, a list of developer IDs of all applications is returned.      |

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<string>    | An array of strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let appDistributionType = bundleManager.AppDistributionType.ENTERPRISE;

try {
    let data = bundleManager.getDeveloperIds(appDistributionType);
    hilog.info(0x0000, 'testTag', 'getDeveloperIds successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDeveloperIds failed: %{public}s', message);
}
```

## bundleManager.switchUninstallState<sup>12+</sup>

switchUninstallState(bundleName: string, state: boolean): void

Switches the uninstall state of an application. This API is independent of EDM application interception control.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_BUNDLE_UNINSTALL_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes  | Bundle name of the application.|
| state | boolean | Yes  | Whether the application can be uninstalled. T**true** if the application can be uninstalled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700060 | The specified application cannot be uninstalled.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    bundleManager.switchUninstallState('com.example.myapplication', false);
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'switchUninstallState failed: %{public}s', message);
}
```

## bundleManager.getAllPluginInfo<sup>19+</sup>

getAllPluginInfo(hostBundleName: string, userId?: number): Promise<Array\<PluginBundleInfo>>

Obtains all the plugin information in the system based on the given host bundle name and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| hostBundleName | string | Yes  | Bundle name of the target application.|
| userId         | number   | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Promise<Array\<[PluginBundleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md)>> | Promise used to return the array of plugin information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found.  |
| 17700004 | The specified user ID is not found.      |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hostBundleName = 'com.ohos.demo';
let userId = 100;

try {
    bundleManager.getAllPluginInfo(hostBundleName, userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllPluginInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', message);
}
```

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let hostBundleName = 'com.ohos.demo';

try {
    bundleManager.getAllPluginInfo(hostBundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllPluginInfo successfully. Data: %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllPluginInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getExtResource<sup>12+</sup>

getExtResource(bundleName: string): Promise\<Array\<string>>;

Obtains the module names corresponding to the extended resources based on the given bundle name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the extended resources are to be queried.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array\<string>> | Promise used to return the API call result and the module names corresponding to the extended resources.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700303 | Failed to obtain extended resources. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.getExtResource(bundleName).then((modules : Array<string>) => {
        for (let i = 0; i < modules.length; i++) {
            hilog.info(0x0000, 'testTag', 'getExtResource item: %s', modules[i]);
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getExtResource failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getExtResource failed. Cause: %{public}s', message);
}
```

## bundleManager.enableDynamicIcon<sup>12+</sup>

enableDynamicIcon(bundleName: string, moduleName: string): Promise\<void>;

Enables the dynamic icon based on the given bundle name and module name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DYNAMIC_ICON

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the dynamic icon is to be enabled.|
| moduleName  | string | Yes  | Module name based on which the dynamic icon is to be enabled.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |
| 17700304 | Failed to enable the dynamic icon. |
| 17700307 | Dynamic icons cannot take effect due to existing custom themes. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';
let moduleName : string = 'moduleTest';

try {
    bundleManager.enableDynamicIcon(bundleName, moduleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'enableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.enableDynamicIcon<sup>20+</sup>

enableDynamicIcon(bundleName: string, moduleName: string, option?: BundleOptions): Promise\<void>

Enables the dynamic icon based on the given bundle name, module name, and bundle options. This API uses a promise to return the result.

To enable the dynamic icon for the current user, you must request the ohos.permission.ACCESS_DYNAMIC_ICON permission.

To enable the dynamic icon for another user, you must request the ohos.permission.ACCESS_DYNAMIC_ICON and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS permissions.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DYNAMIC_ICON or (ohos.permission.ACCESS_DYNAMIC_ICON and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS)


**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the dynamic icon is to be enabled.|
| moduleName  | string | Yes  | Module name based on which the dynamic icon is to be enabled.|
| option  | [BundleOptions](js-apis-bundleManager-BundleInfo-sys.md#bundleoptions) | No  | User and application clone index based on which the dynamic icon is to be enabled. By default, the dynamic icon is enabled for all users and all application clones.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |
| 17700004 | The specified user ID is not found. |
| 17700061 | AppIndex not in valid range. |
| 17700304 | Failed to enable the dynamic icon. |
| 17700307 | Dynamic icons cannot take effect due to existing custom themes. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName: string = 'com.ohos.demo';
let moduleName: string = 'moduleTest';
let option: bundleManager.BundleOptions = {'userId':100, 'appIndex':0};

try {
    bundleManager.enableDynamicIcon(bundleName, moduleName, option).then(() => {
        hilog.info(0x0000, 'testTag', 'enableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'enableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.disableDynamicIcon<sup>12+</sup>

disableDynamicIcon(bundleName: string): Promise\<void>;

Disables the dynamic icon based on the given bundle name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DYNAMIC_ICON

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the dynamic icon is to be disabled.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700305 | Failed to disable the dynamic icon. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.disableDynamicIcon(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'disableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.disableDynamicIcon<sup>20+</sup>

disableDynamicIcon(bundleName: string, option?: BundleOptions): Promise\<void>

Disables the dynamic icon based on the given bundle name and bundle options. This API uses a promise to return the result.

To disable the dynamic icon for the current user, you must request the ohos.permission.ACCESS_DYNAMIC_ICON permission.

To disable the dynamic icon for another user, you must request the ohos.permission.ACCESS_DYNAMIC_ICON and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS permissions.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DYNAMIC_ICON or (ohos.permission.ACCESS_DYNAMIC_ICON and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS)


**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the dynamic icon is to be disabled.|
| option  | [BundleOptions](js-apis-bundleManager-BundleInfo-sys.md#bundleoptions) | No  | User and application clone index based on which the dynamic icon is to be disabled. By default, the dynamic icon is disabled for all users and all application clones.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |
| 17700061 | AppIndex not in valid range. |
| 17700305 | Failed to disable the dynamic icon. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName: string = 'com.ohos.demo';
let option: bundleManager.BundleOptions = {'userId':100, 'appIndex':0};

try {
    bundleManager.disableDynamicIcon(bundleName, option).then(() => {
        hilog.info(0x0000, 'testTag', 'disableDynamicIcon successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'disableDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.getDynamicIcon<sup>12+</sup>

getDynamicIcon(bundleName: string): Promise\<string>;

Obtains the module name corresponding to the dynamic icon based on the specified bundle name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name based on which the extended resources are to be queried.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<string> | Promise used to return the API call result and module name corresponding to the dynamic icon.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700306 | Failed to obtain the dynamic icon. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName : string = 'com.ohos.demo';

try {
    bundleManager.getDynamicIcon(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getDynamicIcon successfully %s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getDynamicIcon failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDynamicIcon failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppCloneIdentity<sup>14+</sup>

getAppCloneIdentity(uid: number): Promise\<AppCloneIdentity>;

Obtains the bundle name and application index of an application clone based on the given UID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------|
|    uid     | number |  Yes |     UID of the application.     |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<AppCloneIdentity> | Promise used to return \<AppCloneIdentity>.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let uid = 20010005;

try {
    bundleManager.getAppCloneIdentity(uid).then((res: bundleManager.AppCloneIdentity) => {
        hilog.info(0x0000, 'testTag', 'getAppCloneIdentity res = %{public}s', JSON.stringify(res));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppCloneIdentity failed. Cause: %{public}s', message);
}
```

## bundleManager.getAppCloneIdentityBySandboxDataDir<sup>20+</sup>

getAppCloneIdentityBySandboxDataDir(sandboxDataDir: string): AppCloneIdentity

Obtains the identity information of an application, including the bundle name and clone index, based on the given sandbox directory name.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------|
| sandboxDataDir | string |  Yes | Name of the [sandbox directory of the application](../../file-management/app-sandbox-directory.md).<br>**NOTE**<br>The validity of this parameter is not verified. If the input **sandboxDataDir** does not match the directory name format for application clones or atomic services, **sandboxDataDir** is returned as **AppCloneIdentity.bundleName**, and **AppCloneIdentity.appIndex** is **0**.<br> 1. Directory name format for application clones: `+clone-{appIndex}+{bundleName}`, where **appIndex** and **bundleName** are variables corresponding to the clone index and bundle name, respectively. Example: `+clone-1+com.example.myapplication`.<br> 2. Directory name format for atomic services: `+auid-{uid}+{bundleName}`, where **uid** and **bundleName** are variables corresponding to the UID and bundle name, respectively. Example: `+auid-20000000+com.example.myapplication`.  |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| [AppCloneIdentity](js-apis-bundleManager-bundleInfo.md#appcloneidentity14) | Bundle name and clone index of the application.|


**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Main application.
let dataDir = 'com.example.myapplication';
try {
    let res = bundleManager.getAppCloneIdentityBySandboxDataDir(dataDir);
    console.info('getAppCloneIdentityBySandboxDataDir successfully. res = ' + JSON.stringify(res));
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getAppCloneIdentityBySandboxDataDir failed. Cause = ' + message);
}

// Application clone.
let cloneDataDir = '+clone-1+com.example.myapplication';
try {
    let res = bundleManager.getAppCloneIdentityBySandboxDataDir(cloneDataDir);
    console.info('getAppCloneIdentityBySandboxDataDir successfully. res = ' + JSON.stringify(res));
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getAppCloneIdentityBySandboxDataDir failed. Cause = ' + message);
}

// Atomic service.
let atomicDataDir = '+auid-20000000+com.example.myapplication';
try {
    let res = bundleManager.getAppCloneIdentityBySandboxDataDir(atomicDataDir);
    console.info('getAppCloneIdentityBySandboxDataDir successfully. res = ' + JSON.stringify(res));
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getAppCloneIdentityBySandboxDataDir failed. Cause = ' + message);
}
```

## bundleManager.getSandboxDataDir<sup>20+</sup>

getSandboxDataDir(bundleName: string, appIndex: number): string

Obtains the sandbox directory of an application based on the given bundle name and clone index.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------|
| bundleName | string |  Yes |   Bundle name of the application. This API can be called only when the application or its clone is available for the current user. Otherwise, error code 17700001 is returned.  |
| appIndex | number |  Yes |   Index of the application. The value ranges from 0 to 5. The value **0** indicates the main application, and the values 1 to 5 indicate the indexes of application clones.  |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| string | Sandbox directory of the application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700061 | The appIndex is invalid. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';
let appIndex = 1;

try {
    let dataDir = bundleManager.getSandboxDataDir(bundleName, appIndex);
    console.info('getSandboxDataDir successfully. dataDir = ' + dataDir);
} catch (err) {
    let message = (err as BusinessError).message;
    console.error('getSandboxDataDir failed. Cause = ' + message);
}
```

## bundleManager.getAppCloneBundleInfo<sup>12+</sup>

getAppCloneBundleInfo(bundleName: string, appIndex: number, bundleFlags: number, userId?: number): Promise\<BundleInfo>;

Obtains the bundle information of an application or an application clone based on the given bundle name, app index, [bundleFlags](js-apis-bundleManager.md#bundleflag), and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------|
|    bundleName     | string |  Yes |       Bundle name.     |
|    appIndex     | number |  Yes |       Index of the application clone.<br>The value **0** means to obtain the bundle information of the main application. A value greater than 0 means to obtain the bundle information of the application clone.     |
|    [bundleFlags](js-apis-bundleManager.md#bundleflag)     | number |  Yes |       Type of the bundle information to obtain.   |
|    userId     | number |  No |       User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.     |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<BundleInfo> | Promise used to return the bundle information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is invalid. |
| 17700026 | The specified bundle is disabled. |
| 17700061 | The appIndex is invalid. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let appIndex = 1;
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getAppCloneBundleInfo(bundleName, appIndex, bundleFlags).then((res: bundleManager.BundleInfo) => {
        hilog.info(0x0000, 'testTag', 'getAppCloneBundleInfo res: BundleInfo = %{public}s', JSON.stringify(res));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAppCloneBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAppCloneBundleInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllAppCloneBundleInfo<sup>12+</sup>

getAllAppCloneBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<Array\<BundleInfo>>;

Obtains all the bundle information of applications and application clones based on the given bundle name, [bundleFlags](js-apis-bundleManager.md#bundleflag), and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ---------------------------|
|    bundleName     | string |  Yes |       Bundle name.     |
|    [bundleFlags](js-apis-bundleManager.md#bundleflag)     | number |  Yes |       Type of the bundle information to obtain.   |
|    userId     | number |  No |       User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller. The value must be greater than or equal to 0.     |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array\<BundleInfo>> | Promise used to return all the bundle information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is invalid. |
| 17700026 | The specified bundle and clone apps are all disabled. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getAllAppCloneBundleInfo(bundleName, bundleFlags).then((res: Array<bundleManager.BundleInfo>) => {
        let index = 0;
        for (let item of res) {
            hilog.info(0x0000, 'testTag', 'getAllAppCloneBundleInfo res: BundleInfo[%{public}d] = %{public}s', index++, JSON.stringify(item));
        }
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllAppCloneBundleInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllAppCloneBundleInfo failed. Cause: %{public}s', message);
}
```
## bundleManager.verifyAbc<sup>11+</sup>

verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean, callback: AsyncCallback\<void>): void

Verifies an .abc file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RUN_DYN_CODE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| abcPaths  | Array\<string> | Yes  | Path of the .abc file.|
| deleteOriginalFiles | boolean | Yes  | Whether to delete the .abc file. **true** to delete, **false** otherwise.|
| callback | AsyncCallback\<void> | Yes| [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700201 | Failed to verify the abc file. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let abcPaths: Array<string> = ['/data/storage/el2/base/a.abc'];

try {
  bundleManager.verifyAbc(abcPaths, true, (err, data) => {
    if (err) {
      hilog.error(0x0000, 'testTag', 'verifyAbc failed: %{public}s', err.message);
    } else {
      hilog.info(0x0000, 'testTag', 'verifyAbc successfully');
    }
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'verifyAbc failed: %{public}s', message);
}
```

## bundleManager.migrateData<sup>18+</sup>

migrateData(sourcePaths: Array&lt;string&gt;, destinationPath: string): Promise&lt;void&gt;

Migrates files from the source path to the destination path. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MIGRATE_DATA

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| sourcePaths | Array&lt;string&gt; | Yes| Array of source paths. The value can be a single file path such as **/example1/test.txt** or a directory path such as **/example2/test**.|
| destinationPath | string | Yes| Destination path. Only one directory path is supported, for example, **/example2/test**.|

**Return value**

| Type      | Description                |
| ---------- | -------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700080 | The source paths are invalid. |
| 17700081 | The destination path is invalid. |
| 17700082 | User authentication failed. |
| 17700083 | Waiting for user authentication timeout. |
| 17700084 | There are inaccessible path in the source paths. |
| 17700085 | The destination path cannot be accessed. |
| 17700086 | System error occurred during copy execution. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Change the values of source1, source2, and dest to the actual file or directory paths.
  let source1: string = "/data/app/el2/100/base/com.example.myapplication/";
  let source2: string = "/data/app/el2/101/base/com.example.myapplication/log.txt";
  let dest: string = "/data/local/tmp";
  let sourcePaths: Array<string> = [source1, source2];

  bundleManager.migrateData(sourcePaths, dest)
    .then(() => {
      console.info(`migrateData succeed`);
    })
    .catch((err: BusinessError) => {
      console.error(`migrateData err : `, JSON.stringify(err));
    })
} catch(err) {
  console.error(`migrateData call err : `, JSON.stringify(err));
}
```

## bundleManager.verifyAbc<sup>11+</sup>

verifyAbc(abcPaths: Array\<string>, deleteOriginalFiles: boolean): Promise\<void>

Verifies an .abc file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RUN_DYN_CODE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| abcPaths  | Array\<string> | Yes  | Path of the .abc file.|
| deleteOriginalFiles | boolean | Yes  | Whether to delete the .abc file. **true** to delete, **false** otherwise.      |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700201 | Failed to verify the abc file. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let abcPaths: Array<string> = ['/data/storage/el2/base/a.abc'];

try {
  bundleManager.verifyAbc(abcPaths, true).then((data) => {
    hilog.info(0x0000, 'testTag', 'verifyAbc successfully');
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'verifyAbc failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'verifyAbc failed. Cause: %{public}s', message);
}
```

## bundleManager.deleteAbc<sup>11+</sup>

deleteAbc(abcPath: string): Promise\<void>

Deletes an .abc file based on the specified file path. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RUN_DYN_CODE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| abcPath  | string | Yes  | Path of the .abc file.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700202 | Failed to delete the abc file. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let abcPath: string = '/data/storage/el2/base/a.abc';

try {
  bundleManager.deleteAbc(abcPath).then((data) => {
    hilog.info(0x0000, 'testTag', 'deleteAbc successfully');
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', 'deleteAbc failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  hilog.error(0x0000, 'testTag', 'deleteAbc failed. Cause: %{public}s', message);
}
```

## bundleManager.getDynamicIconInfo<sup>20+</sup>

getDynamicIconInfo(bundleName: string): Promise\<Array\<DynamicIconInfo>>

Obtains the dynamic icon information of all users and all application clones based on the given bundle name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name of the application for which the dynamic icon information is to be queried.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array<[DynamicIconInfo](js-apis-bundleManager-BundleInfo-sys.md#dynamiciconinfo)>> | Promise used to return the dynamic icon information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700001 | The specified bundleName is not found. |
| 17700306 | Failed to obtain the dynamic icon. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleName: string = 'com.ohos.demo';

try {
    bundleManager.getDynamicIconInfo(bundleName).then((data) => {
        hilog.info(0x0000, 'testTag', 'getDynamicIconInfo successfully %s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getDynamicIconInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDynamicIconInfo failed. Cause: %{public}s', message);
}
```

## bundleManager.getAllDynamicIconInfo<sup>20+</sup>

getAllDynamicIconInfo(userId?: number): Promise\<Array\<DynamicIconInfo>>

Obtains the dynamic icon information of all applications and all application clones of a specified user. This API uses a promise to return the result.

To obtain the dynamic icon information of all applications and all application clones of the current user, you must request the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED permission.

To obtain the dynamic icon information of all applications and all application clones of other users or all users, you must request the ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS permissions.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| userId  | number | No  | User ID. By default, the dynamic icon information of all applications and all application clones of all users is queried.|

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<Array\<[DynamicIconInfo](js-apis-bundleManager-BundleInfo-sys.md#dynamiciconinfo)>> | Promise used to return the dynamic icon information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 17700004 |  The specified user ID is not found. |
| 17700306  | Failed to obtain the dynamic icon. |

**Example**

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let userId: number = 100;

try {
    bundleManager.getAllDynamicIconInfo(userId).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllDynamicIconInfo successfully');
    }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllDynamicIconInfo failed. Cause: %{public}s', err.message);
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllDynamicIconInfo failed. Cause: %{public}s', message);
}
```

## PermissionDef

type PermissionDef = _PermissionDef

Defines the detailed information about the permissions defined in the [module.json5](../../quick-start/module-configuration-file.md) file.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PermissionDef](./js-apis-bundleManager-permissionDef-sys.md#permissiondef) |Permission details defined in the configuration file.|

## SharedBundleInfo<sup>10+</sup>

type SharedBundleInfo = _SharedBundleInfo

Defines the shared bundle information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md#sharedbundleinfo) |Shared bundle information.|

## AppProvisionInfo<sup>10+</sup>

type AppProvisionInfo = _AppProvisionInfo.AppProvisionInfo

Defines the information in the [HarmonyAppProvision configuration file](../../security/app-provision-structure.md).

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_AppProvisionInfo.AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md#appprovisioninfo) |Information in the [HarmonyAppProvision configuration file](../../security/app-provision-structure.md).|


## Validity<sup>10+</sup>

type Validity = _AppProvisionInfo.Validity

Defines the validity period in the configuration file.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_AppProvisionInfo.Validity](js-apis-bundleManager-AppProvisionInfo-sys.md#validity) |Validity period in the configuration file.|

## RecoverableApplicationInfo<sup>11+</sup>

type RecoverableApplicationInfo = _RecoverableApplicationInfo

Defines the information about a preinstalled application that can be restored after being uninstalled.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_RecoverableApplicationInfo](js-apis-bundleManager-recoverableApplicationInfo-sys.md#recoverableapplicationinfo) |Information about a preinstalled application that can be restored after being uninstalled.|

## PreinstalledApplicationInfo<sup>12+</sup>

type PreinstalledApplicationInfo = _PreinstalledApplicationInfo

Defines the preinstalled application information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PreinstalledApplicationInfo](js-apis-bundleManager-ApplicationInfo-sys.md#preinstalledapplicationinfo12) |Preinstalled application information.|

## PluginBundleInfo<sup>19+</sup>

type PluginBundleInfo = _PluginBundleInfo

Defines the plugin information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PluginBundleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md#pluginbundleinfo) |Plugin information.|

## PluginModuleInfo<sup>19+</sup>

type PluginModuleInfo = _PluginModuleInfo

Defines the module information of a plugin.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PluginModuleInfo](js-apis-bundleManager-pluginBundleInfo-sys.md#pluginmoduleinfo) |Module information of the plugin.|

## DynamicIconInfo<sup>20+</sup>

type DynamicIconInfo = _BundleInfo.DynamicIconInfo

Describes the information about the dynamic icon of an application.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.DynamicIconInfo](js-apis-bundleManager-BundleInfo-sys.md#dynamiciconinfo) |Information about the dynamic icon of an application.|

## BundleOptions<sup>20+</sup>

type BundleOptions = _BundleInfo.BundleOptions

Describes the bundle options used to set or query application information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_BundleInfo.BundleOptions](js-apis-bundleManager-BundleInfo-sys.md#bundleoptions) |Bundle options used to set or query application information.|
