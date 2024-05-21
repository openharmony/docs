# @ohos.bundle.bundleManager (bundleManager) (System API)

The **bundleManager** module provides APIs for querying information about bundles, applications, abilities, ExtensionAbilities, and more.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.bundle.bundleManager](js-apis-bundleManager.md).

## Modules to Import

```ts
import bundleManager from '@ohos.bundle.bundleManager';
```

## Required Permissions

| Permission                                      | APL    | Description           |
| ------------------------------------------ | ------------ | ------------------|
| ohos.permission.GET_BUNDLE_INFO            | normal       | Permission to obtain basic information about a bundle.  |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED| system_basic | Permission to obtain basic information and other sensitive information about a bundle.|
| ohos.permission.REMOVE_CACHE_FILES         | system_basic | Permission to clear cache files of a bundle.      |
| ohos.permission.CHANGE_ABILITY_ENABLED_STATE| system_basic | Permission to enable or disable an application or ability. |
| ohos.permission.GET_INSTALLED_BUNDLE_LIST | system_basic | Permission to read installed application list.|

For details, see [Permission APL](../../security/AccessToken/app-permission-mgmt-overview.md#permission-apl).

## Enums

### ApplicationFlag

Enumerates the application flags, which indicate the type of application information to obtain.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name                                | Value        | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| GET_APPLICATION_INFO_DEFAULT         | 0x00000000 | Used to obtain the default application information. The obtained information does not contain the permission information or metadata.|
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000001 | Used to obtain the application information with permission information.                   |
| GET_APPLICATION_INFO_WITH_METADATA   | 0x00000002 | Used to obtain the application information with metadata.                     |
| GET_APPLICATION_INFO_WITH_DISABLE    | 0x00000004 | Used to obtain the application information of disabled bundles.                 |

### AbilityFlag

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
| GET_ABILITY_INFO_WITH_APP_LINKING  | 0x00000040 | Used to obtain the ability information filtered by domain name verification.                        |
| GET_ABILITY_INFO_WITH_SKILL<sup>12+</sup>   | 0x00000080 | Used to obtain the ability information with skills.                        |

### ExtensionAbilityFlag

Enumerates the ExtensionAbility flags, which indicate the type of ExtensionAbility information to obtain.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name                                       | Value        | Description                                                        |
| ------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_EXTENSION_ABILITY_INFO_DEFAULT          | 0x00000000 | Used to obtain the default ExtensionAbility information. The obtained information does not contain the permission, metadata, or disabled ability information.|
| GET_EXTENSION_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | Used to obtain the ExtensionAbility information with permission information.              |
| GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | Used to obtain the ExtensionAbility information with application information.        |
| GET_EXTENSION_ABILITY_INFO_WITH_METADATA    | 0x00000004 | Used to obtain the ExtensionAbility information with metadata.                |
| GET_EXTENSION_ABILITY_INFO_WITH_SKILL<sup>12+</sup>     | 0x00000010 | Used to obtain the ExtensionAbility information with skills.                |

### ProfileType<sup>11+</sup>

Enumerates the types of profiles (also called application files).

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name          | Value  | Description           |
| -------------- | ---- | --------------- |
| INTENT_PROFILE  | 1    | Profile of the InsightIntent framework.   |

### AppDistributionType<sup>12+</sup>

Enumerates the application distribution types.

 **System capability**: SystemCapability.BundleManager.BundleFramework.Core

 **System API**: This is a system API.

| Name             | Value  | Description           |
| ----------------- | ---- | --------------- |
| APP_GALLERY       | 1    | Application distributed by AppGallery.   |
| ENTERPRISE        | 2    | Enterprise application that can be installed on personal devices.   |
| ENTERPRISE_NORMAL | 3    | Common enterprise application that can be installed on enterprise devices only through an enterprise mobile device management (MDM) application. The applications of this type do not require device management privileges.   |
| ENTERPRISE_MDM    | 4    | Enterprise MDM application that can be installed only on enterprise devices. The applications of this type must have device management privileges, such as remote locking devices and installing common enterprise applications on devices.   |
| OS_INTEGRATION    | 5    | Preset system application.   |
| CROWDTESTING      | 6    | Crowdtesting application.   |
| NONE              | 7    | Other.          |

## APIs

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID. |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the ability information.
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on the given bundle name and bundle flags. This API uses an asynchronous callback to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the ExtensionAbility information.
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, userId?: number): Promise\<BundleInfo>

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API uses a promise to return the result.

No permission is required for obtaining the caller's own information.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | Yes  | Bundle name.|
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.      |
| userId      | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type                                                       | Description                       |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise used to return the bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found.     |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
// Obtain the bundle information with the application and signature information.
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getApplicationInfo

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
| userId     | number | Yes  | User ID. |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getApplicationInfo

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
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getApplicationInfo

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
| userId     | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                                                        | Description                            |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Promise used to return the application information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, userId: number, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains the information about all bundles based on the given bundle flags and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.                   |
| userId      | number | Yes  | User ID.                     |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | --------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains the information about all bundles based on the given bundle flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.  |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: number, userId?: number): Promise<Array\<BundleInfo>>

Obtains the information about all bundles based on the given bundle flags and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ----------- | ------ | ---- | -------------------------------------------------- |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.                  |
| userId      | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                     |

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Promise used to return the array of bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, userId: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

Obtains the information about all applications based on the given application flags and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| userId   | number | Yes  | User ID.        |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

Obtains the information about all applications based on the given application flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of application information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: number, userId?: number): Promise<Array\<ApplicationInfo>>

Obtains the information about all applications based on the given application flags and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_INSTALLED_BUNDLE_LIST

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- | ---------------------------------------------------------- |
| appFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.                      |
| userId   | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                       |

**Return value**

| Type                                                        | Description                                    |
| ------------------------------------------------------------ | ---------------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Promise used to return the array of application information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                        |
| -------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, userId: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

Obtains an array of ability information based on the given want, ability flags, and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.                      |
| userId       | number | Yes  | User ID.                              |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

Obtains an array of ability information based on the given want and ability flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | -------------------------------------------------------|
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.      |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ability information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

Obtains the ability information based on the given want, ability flags, and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.|
| userId       | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                      |

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise used to return the array of ability information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryAbilityInfoSync<sup>10+</sup>

queryAbilityInfoSync(want: Want, abilityFlags: number, userId?: number): Array\<AbilityInfo>

Obtains the ability information based on the given want, ability flags, and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | Yes  | Want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.|
| userId       | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                      |

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | An array of ability information.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryAbilityInfo<sup>12+</sup>

queryAbilityInfo(wants: Array\<Want>, abilityFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

Obtains the ability information based on the given want list, ability flags, and user ID.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                                                 |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Array\<Want>   | Yes  | List of want containing the bundle name to query.                |
| abilityFlags | [number](#abilityflag) | Yes  | Type of the ability information to obtain.|
| userId       | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                      |

**Return value**

| Type                                                        | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)> | An array of ability information.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

Obtains the ExtensionAbility information based on the given want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                                        | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | Yes  | Want containing the bundle name to query.                      |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager-sys.md#extensionabilitytype)                | Yes  | Type of the ExtensionAbility.                                |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | Yes  | Type of the ExtensionAbility information to obtain.   |
| userId                | number                                                       | Yes  | User ID.                                                |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ExtensionAbility information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, callback: AsyncCallback<Array\<ExtensionAbilityInfo>>): void

Obtains the ExtensionAbility information based on the given want, ExtensionAbility type, and ExtensionAbility flags. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                                        | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | Yes  | Want containing the bundle name to query.                      |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager-sys.md#extensionabilitytype)                | Yes  | Type of the ExtensionAbility.                                |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | Yes  | Type of the ExtensionAbility information to obtain.   |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of ExtensionAbility information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId?: number): Promise<Array\<ExtensionAbilityInfo>>

Obtains the ExtensionAbility information based on the given want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                         | Mandatory| Description                                                     |
| --------------------- | --------------------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                                          | Yes  | Want containing the bundle name to query.                   |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager-sys.md#extensionabilitytype) | Yes  | Type of the ExtensionAbility.                             |
| extensionAbilityFlags | [number](#extensionabilityflag)               | Yes  | Type of the ExtensionAbility information to obtain.|
| userId                | number                                        | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                                             |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Promise used to return the array of ExtensionAbility information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.queryExtensionAbilityInfoSync<sup>10+</sup>

queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: ExtensionAbilityType, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

Obtains the ExtensionAbility information based on the given want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                                         | Mandatory| Description                                                     |
| --------------------- | --------------------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                                          | Yes  | Want containing the bundle name to query.                   |
| extensionAbilityType  | [ExtensionAbilityType](js-apis-bundleManager-sys.md#extensionabilitytype) | Yes  | Type of the ExtensionAbility.                             |
| extensionAbilityFlags | [number](#extensionabilityflag)               | Yes  | Type of the ExtensionAbility information to obtain.|
| userId                | number                                        | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                                             |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | An array of ExtensionAbility information.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.getBundleNameByUid

getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void

Obtains the bundle name based on the given UID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                 | Yes  | UID of the application.                                           |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle name obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | --------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleNameByUid

getBundleNameByUid(uid: number): Promise\<string>

Obtains the bundle name based on the given UID. This API uses a promise to return the result.

**System API**: This is a system API.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleNameByUidSync<sup>10+</sup>

getBundleNameByUidSync(uid: number): string

Obtains the bundle name based on the given UID. This API returns the result synchronously.

**System API**: This is a system API.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message           |
| -------- | ---------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700021 | The uid is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let uid = 20010005;
try {
    let data = bundleManager.getBundleNameByUidSync(uid);
    hilog.info(0x0000, 'testTag', 'getBundleNameByUidSync successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleNameByUidSync failed. Cause: %{public}s', message);
}
```

### bundleManager.getBundleArchiveInfo

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
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Yes| Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the bundle information obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                 |
| -------- | --------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleArchiveInfo

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleArchiveInfoSync<sup>10+</sup>

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700022 | The hapFilePath is invalid. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void

Clears the cache files based on the given bundle name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.REMOVE_CACHE_FILES

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                  |
| callback   | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                        |
| 17700030 | The specified bundle does not support clearing of cache files. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string): Promise\<void>

Clears the cache files based on the given bundle name. This API uses a promise to return the result.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                  |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.                      |
| 17700030 | The specified bundle does not support clearing of cache files. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.               |
| isEnabled  | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means to disable the application.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean): Promise\<void>

Enables or disables an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.           |
| isEnabled  | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means to disable the application.|

**Return value**

| Type          | Description                                |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.setApplicationEnabledSync<sup>10+</sup>

setApplicationEnabledSync(bundleName: string, isEnabled: boolean): void

Enables or disables an application. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                 |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | Yes  | Bundle name.               |
| isEnabled  | boolean | Yes  | Whether to enable the application. The value **true** means to enable the application, and **false** means to disable the application.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabledSync(bundleName, false);
    hilog.info(0x0000, 'testTag', 'setApplicationEnabledSync successfully.');
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'setApplicationEnabledSync failed: %{public}s', message);
}
```

### bundleManager.setAbilityEnabled

setAbilityEnabled(info: AbilityInfo, isEnabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables an ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.             |
| isEnabled| boolean     | Yes  | Whether to enable the ability. The value **true** means to enable the ability, and **false** means to disable the ability. |
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ---------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.setAbilityEnabled

setAbilityEnabled(info: AbilityInfo, isEnabled: boolean): Promise\<void>

Enables or disables an ability. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.                  |
| isEnabled| boolean     | Yes  | Whether to enable the ability. The value **true** means to enable the ability, and **false** means to disable the ability. |

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.setAbilityEnabledSync<sup>10+</sup>

setAbilityEnabledSync(info: AbilityInfo, isEnabled: boolean): void

Enables or disables an ability. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name   | Type       | Mandatory| Description                                 |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.             |
| isEnabled| boolean     | Yes  | Whether to enable the ability. The value **true** means to enable the ability, and **false** means to disable the ability. |

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ---------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void

Checks whether an application is enabled. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name.|
| callback | AsyncCallback\<boolean> | Yes| Callback used to return the result. The value **true** means that the application is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.isApplicationEnabled

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
| Promise\<boolean> | Promise used to return the result. The value **true** means that the application is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.isApplicationEnabledSync<sup>10+</sup>

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
| boolean | Returns **true** if the application is enabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = 'com.example.myapplication';

try {
    let data = bundleManager.isApplicationEnabledSync(bundleName);
    hilog.info(0x0000, 'testTag', 'isApplicationEnabledSync successfully: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'isApplicationEnabledSync failed: %{public}s', message);
}
```

### bundleManager.isAbilityEnabled

isAbilityEnabled(info: AbilityInfo], callback: AsyncCallback\<boolean>): void

Checks whether an ability is enabled. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name| Type       | Mandatory| Description                       |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | Yes  | Information about the target ability.|
| callback | AsyncCallback\<boolean> | Yes| Callback used to return the result. The value **true** means that the ability is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.isAbilityEnabled

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
| Promise\<boolean> | Promise used to return the result. The value **true** means that the ability is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.isAbilityEnabledSync<sup>10+</sup>

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
| boolean | Returns **true** if the ability is enabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | --------------------------------------- |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId: number, callback: AsyncCallback\<Want>): void

Obtains the Want used to launch the bundle based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                                    |
| userId     | number               | Yes  | User ID.                                                  |
| callback   | AsyncCallback\<Want> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **Want** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void

Obtains the Want used to launch the bundle based on the given bundle name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                                        |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | Yes  | Bundle name.                                    |
| callback   | AsyncCallback\<Want> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **Want** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                            |
| -------- | --------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId?: number): Promise\<Want>

Obtains the Want used to launch the bundle based on the given bundle name and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<Want> | Promise used to return the **Want** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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


### bundleManager.getLaunchWantForBundleSync<sup>10+</sup>

getLaunchWantForBundleSync(bundleName: string, userId?: number): Want

Obtains the Want used to launch the bundle based on the given bundle name and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Want | **Want** object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
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

### bundleManager.getPermissionDef

getPermissionDef(permissionName: string, callback: AsyncCallback\<PermissionDef>): void

Obtains the **PermissionDef** struct based on the given permission name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name          | Type                                                        | Mandatory| Description                                                        |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| permissionName | string                                                       | Yes  | Name of the permission.                                              |
| callback       | AsyncCallback\<[PermissionDef](js-apis-bundleManager-permissionDef-sys.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **PermissionDef** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getPermissionDef

getPermissionDef(permissionName: string): Promise\<PermissionDef>

Obtains the **PermissionDef** struct based on the given permission name. This API uses a promise to return the result.

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
| Promise\<[PermissionDef](js-apis-bundleManager-permissionDef-sys.md)> | Promise used to return the **PermissionDef** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getPermissionDefSync<sup>10+</sup>

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
|[PermissionDef](js-apis-bundleManager-permissionDef-sys.md) | **PermissionDef** object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700006 | The specified permission is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let permissionName = "ohos.permission.GET_BUNDLE_INFO";
try {
    let PermissionDef = bundleManager.getPermissionDefSync(permissionName);
    hilog.info(0x0000, 'testTag', 'getPermissionDefSync successfully. Data: %{public}s', JSON.stringify(PermissionDef));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getPermissionDefSync failed. Cause: %{public}s', message);
}
```

### bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<string>): void

Obtains the ability label based on the given bundle name, module name, and ability name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Resource

**Parameters**

| Name     | Type                  | Mandatory| Description                                                        |
| ----------- | ---------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                 | Yes  | Bundle name.                                    |
| moduleName  | string                 | Yes  | Module name.                                    |
| abilityName | string                 | Yes  | Name of the UIAbility component.                                   |
| callback    | AsyncCallback\<string> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the label obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>

Obtains the ability label based on the given bundle name, module name, and ability name. This API uses a promise to return the result.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAbilityLabelSync<sup>10+</sup>

getAbilityLabelSync(bundleName: string, moduleName: string, abilityName: string): string

Obtains the ability label based on the given bundle name, module name, and ability name. This API returns the result synchronously.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number, userId: number) : ApplicationInfo

Obtains the application information based on the given bundle name, application flags, and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                      |
| ----------- | ------ | ---- | ----------------------------------------------------------|
| bundleName  | string | Yes  | Bundle name.                                 |
| applicationFlags | [number](#applicationflag) | Yes  | Type of the application information to obtain.      |
| userId      | number | Yes  | User ID.                                        |

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | Application information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number) : ApplicationInfo

Obtains the application information based on the given bundle name and application flags. This API returns the result synchronously.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleInfoSync

getBundleInfoSync(bundleName: string, bundleFlags: number, userId: number): BundleInfo

Obtains the bundle information based on the given bundle name, bundle flags, and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name      | Type  | Mandatory| Description                                                    |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | Yes  | Bundle name.                                |
| [bundleFlags](js-apis-bundleManager.md#bundleflag) | number | Yes  | Type of the bundle information to obtain.|
| userId      | number | Yes  | User ID.                                            |

**Return value**

| Type      | Description                |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | Bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getBundleInfoSync

getBundleInfoSync(bundleName: string, bundleFlags: number): BundleInfo

Obtains the bundle information based on the given bundle name and bundle flags. This API returns the result synchronously.

**System API**: This is a system API.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getSharedBundleInfo<sup>10+</sup>

getSharedBundleInfo(bundleName: string,  moduleName: string, callback: AsyncCallback\<Array\<SharedBundleInfo\>\>): void

Obtains the shared bundle information based on the given bundle name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string                                                       | Yes  | Bundle name.                                  |
| moduleName | string                                                       | Yes  | Module name.                                  |
| callback   | AsyncCallback\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the shared bundle information obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getSharedBundleInfo<sup>10+</sup>

getSharedBundleInfo(bundleName: string, moduleName: string): Promise\<Array\<SharedBundleInfo\>\>

Obtains the shared bundle information based on the given bundle name. This API uses a promise to return the result.

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified moduleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAllSharedBundleInfo<sup>10+</sup>

getAllSharedBundleInfo(callback: AsyncCallback\<Array\<SharedBundleInfo\>\>): void

Obtains the information about all shared bundles. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is an array of the shared bundle information obtained.|

**Error codes**

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

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

### bundleManager.getAllSharedBundleInfo<sup>10+</sup>

getAllSharedBundleInfo(): Promise\<Array\<SharedBundleInfo\>\>

Obtains the information about all shared bundles. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<Array\<[SharedBundleInfo](js-apis-bundleManager-sharedBundleInfo-sys.md)\>\> | Promise used to return an array of the shared bundle information obtained.|

**Error codes**

| ID| Error Message                            |
| -------- | ------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

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

### bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, callback: AsyncCallback\<AppProvisionInfo\>): void

Obtains the provision profile based on the given bundle name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes  | Bundle name.|
| callback | AsyncCallback\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the provision profile obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, userId: number, callback: AsyncCallback\<AppProvisionInfo\>): void

Obtains the provision profile based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes  | Bundle name.|
| userId | number | Yes| User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).|
| callback | AsyncCallback\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the provision profile obtained.|


**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAppProvisionInfo<sup>10+</sup>

getAppProvisionInfo(bundleName: string, userId?: number): Promise\<AppProvisionInfo\>

Obtains the provision profile based on the given bundle name and user ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type        | Mandatory| Description         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes| Bundle name.|
| userId | number | No| User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID on the current device.|


**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise\<[AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md)\> | Promise used to return the provision profile obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getAppProvisionInfoSync<sup>10+</sup>

getAppProvisionInfoSync(bundleName: string, userId?: number): AppProvisionInfo

Obtains the provision profile based on the given bundle name and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type        | Mandatory| Description         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes| Bundle name.|
| userId | number | No| User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID on the current device.|


**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| [AppProvisionInfo](js-apis-bundleManager-AppProvisionInfo-sys.md) | Provision profile.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
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

### bundleManager.getSpecifiedDistributionType<sup>10+</sup>
getSpecifiedDistributionType(bundleName: string): string

Obtains the distribution type of a bundle in synchronous mode. The return value is the **specifiedDistributionType** field value in [InstallParam](./js-apis-installer-sys.md#installparam) passed when **install** is called.

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
| string | Distribution type of the bundle.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |

**Example**
```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
let bundleName = "com.example.myapplication";

try {
    let type = bundleManager.getSpecifiedDistributionType(bundleName);
    console.info('getSpecifiedDistributionType successfully, type:' + type);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getSpecifiedDistributionType failed. Cause: ' + message);
}
```


### bundleManager.getAdditionalInfo<sup>10+</sup>

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
let bundleName = "com.example.myapplication";

try {
    let info = bundleManager.getAdditionalInfo(bundleName);
    console.info('getAdditionalInfo successfully, additionInfo:' + info);
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('getAdditionalInfo failed. Cause: ' + message);
}
```

### bundleManager.queryExtensionAbilityInfoSync<sup>11+</sup>

queryExtensionAbilityInfoSync(want: Want, extensionAbilityType: string, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

Obtains the ExtensionAbility information based on the given want, ExtensionAbility type, ExtensionAbility flags, and user ID. This API returns the result synchronously.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                           | Mandatory| Description                                                     |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| want                  | Want                            | Yes  | Want containing the bundle name to query.                   |
| extensionAbilityType  | string                          | Yes  | Type of the custom ExtensionAbility.                       |
| extensionAbilityFlags | [number](#extensionabilityflag) | Yes  | Information flags to be contained in the returned **ExtensionAbilityInfo** object.|
| userId                | number                          | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | An array of **ExtensionAbilityInfo** objects.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. At least one parameter(action, entity, uri or type) is required for implicit query. |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
// Call the API with the userId parameter specified.
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

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

### bundleManager.getJsonProfile<sup>11+</sup>

getJsonProfile(profileType: ProfileType, bundleName: string, moduleName?: string): string

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

**Return value**

| Type  | Description                     |
| ------ | ------------------------ |
| string | JSON string of the profile.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.       |
| 17700002 | The specified moduleName is not found.       |
| 17700024 | Failed to get the profile because the specified profile is not found in the HAP. |
| 17700026 | The specified bundle is disabled.            |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

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

### bundleManager.getRecoverableApplicationInfo<sup>11+</sup>

getRecoverableApplicationInfo(callback: AsyncCallback\<Array\<RecoverableApplicationInfo\>\>): void

Obtains information about all preinstalled applications that can be restored. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[RecoverableApplicationInfo](js-apis-bundleManager-recoverableApplicationInfo-sys.md)\>\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is an array of the recoverable application information obtained.|

**Error codes**

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

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

### bundleManager.getRecoverableApplicationInfo<sup>11+</sup>

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

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

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

### bundleManager.setAdditionalInfo<sup>11+</sup>

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                                   |
| -------- | ---------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter bundleName is empty. |
| 17700001 | The specified bundleName is not found.                     |
| 17700053 | Not app gallery call.                                      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

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

### bundleManager.getAllPreinstalledApplicationInfo<sup>12+</sup>

getAllPreinstalledApplicationInfo(): Promise\<Array\<PreinstalledApplicationInfo\>\>

Obtains information about all preinstalled applications. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[PreinstalledApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Promise used to return the array of preinstalled applications obtained.|

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import Base from '@ohos.base';

bundleManager.getAllPreinstalledApplicationInfo().then((data: Array<bundleManager.PreinstalledApplicationInfo>) => {
    console.info("GetAllPreinstalledApplicationInfo success, data is :" + JSON.stringify(data));

}).catch((err: Base.BusinessError) => {
    console.error("GetAllPreinstalledApplicationInfo success errCode is :" + JSON.stringify(err.code));
});
```

### bundleManager.queryExtensionAbilityInfoSync<sup>11+</sup>

queryExtensionAbilityInfoSync(extensionAbilityType: string, extensionAbilityFlags: number, userId?: number): Array\<ExtensionAbilityInfo>

Obtains the ExtensionAbility information based on the given ExtensionAbility type, ExtensionAbility flags, and user ID.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type                           | Mandatory| Description                                                     |
| --------------------- | ------------------------------- | ---- | --------------------------------------------------------- |
| extensionAbilityType  | string                          | Yes  | Type of the custom ExtensionAbility.                       |
| extensionAbilityFlags | [number](#extensionabilityflag) | Yes  | Information flags to be contained in the returned **ExtensionAbilityInfo** object.|
| userId                | number                          | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)> | An array of **ExtensionAbilityInfo** objects.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

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
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

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
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

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

### bundleManager.getAllBundleInfoByDeveloperId<sup>12+</sup>

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

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter developerId is empty. |
| 17700059 | The specified developerId is invalid.       |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

let developerId = "123456.789";

try {
    let data = bundleManager.getAllBundleInfoByDeveloperId(developerId);
    hilog.info(0x0000, 'testTag', 'getAllBundleInfoByDeveloperId successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getAllBundleInfoByDeveloperId failed: %{public}s', message);
}
```

### bundleManager.getDeveloperIds<sup>12+</sup>

getDeveloperIds(appDistributionType?: number): Array<String>

Obtains all the developer IDs of the current user based on the given application distribution type.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name               | Type     | Mandatory| Description                    |
| --------------------- | ---------| ---- | --------------------- |
| appDistributionType  | [number](#appdistributiontype12)   | No  | Application distribution type. If this parameter is not specified, a list of developer IDs of all applications is returned.      |

**Return value**

| Type                                                        | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| Array\<String>    | An array of strings.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

let appDistributionType = bundleManager.AppDistributionType.ENTERPRISE;

try {
    let data = bundleManager.getDeveloperIds(appDistributionType);
    hilog.info(0x0000, 'testTag', 'getDeveloperIds successfully. Data: %{public}s', JSON.stringify(data));
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getDeveloperIds failed: %{public}s', message);
}
```

### bundleManager.switchUninstallState<sup>12+</sup>

switchUninstallState(bundleName: string, state: boolean): void

Switches the uninstall state of an application. This API is independent from EDM application interception control.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CHANGE_BUNDLE_UNINSTALL_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName | string | Yes  | Bundle name of the application.|
| state | boolean | Yes  | Whether the application can be uninstalled. The value **true** means that the application can be uninstalled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found.  |
| 17700060 | The specified application can not be uninstalled.      |

**Example**

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
import { BusinessError } from '@ohos.base';

try {
    bundleManager.switchUninstallState('com.example.myapplication', false);
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'switchUninstallState failed: %{public}s', message);
}
```
