# @ohos.bundle.freeInstall (freeInstall) (System API)

The module provides APIs for setting and obtaining installation-free information and APIs for obtaining BundlePackInfo and DispatchInfo.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import { freeInstall } from '@kit.AbilityKit';
```

## Required Permissions

| Permission                                      | APL    | Description              |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | Permission to query information about all applications.|
| ohos.permission.INSTALL_BUNDLE             | system_core  | Permission to install or uninstall other applications except enterprise applications, including enterprise InHouse, mobile device management (MDM), and Normal applications.  |

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).
## UpgradeFlag

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name            | Value  | Description            |
| ---------------- | ---- | ---------------- |
| NOT_UPGRADE      | 0    | No module needs an upgrade.    |
| SINGLE_UPGRADE   | 1    | A single module needs an upgrade.|
| RELATION_UPGRADE | 2    | The module that has a relationship with the current one needs an upgrade.|

## BundlePackFlag

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name              | Value        | Description                              |
| ------------------ | ---------- | ---------------------------------- |
| GET_PACK_INFO_ALL  | 0x00000000 | All information in the **pack.info** file.   |
| GET_PACKAGES       | 0x00000001 | Package information in the **pack.info** file.|
| GET_BUNDLE_SUMMARY | 0x00000002 | Bundle summary information in the **pack.info** file. |
| GET_MODULE_SUMMARY | 0x00000004 | Module summary information in the **pack.info** file. |

## setHapModuleUpgradeFlag

setHapModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag, callback: AsyncCallback\<void>):void

Sets an upgrade flag for a module. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INSTALL_BUNDLE

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Parameters**

| Name    | Type                       | Mandatory| Description                      |
| ----------- | --------------------------- | ---- | ---------------------------- |
| bundleName  | string                      | Yes  | Bundle name.    |
| moduleName  | string                      | Yes  | Module name.          |
| upgradeFlag | [UpgradeFlag](#upgradeflag) | Yes  | Upgrade flag, which is for internal use only.      |
| callback    | AsyncCallback\<void>        | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                           |
|----------|---------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let upgradeFlag = freeInstall.UpgradeFlag.SINGLE_UPGRADE;
try {
    freeInstall.setHapModuleUpgradeFlag(bundleName, moduleName, upgradeFlag, err => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed');
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## setHapModuleUpgradeFlag

setHapModuleUpgradeFlag(bundleName: string, moduleName: string, upgradeFlag: UpgradeFlag): Promise\<void>

Sets an upgrade flag for a module. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INSTALL_BUNDLE

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Parameters**

| Name     | Type                       | Mandatory| Description                  |
| ----------- | --------------------------- | ---- | ---------------------- |
| bundleName  | string                      | Yes  | Bundle name.|
| moduleName  | string                      | Yes  | Module name.    |
| upgradeFlag | [UpgradeFlag](#upgradeflag) | Yes  | Upgrade flag, which is for internal use only.|

**Return value**

| Type         | Description                                |
| ------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                           |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let upgradeFlag = freeInstall.UpgradeFlag.SINGLE_UPGRADE;
try {
    freeInstall.setHapModuleUpgradeFlag(bundleName, moduleName, upgradeFlag).then(() => {
        console.info('Operation succeed')
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## isHapModuleRemovable

isHapModuleRemovable(bundleName: string, moduleName: string, callback: AsyncCallback\<boolean>): void

Checks whether a module can be removed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Parameters**

| Name     | Type                  | Mandatory| Description                                         |
| ---------- | ---------------------- | ---- | --------------------------------------------- |
| bundleName | string                 | Yes  | Bundle name.                     |
| moduleName | string                 | Yes  | Module name.                           |
| callback   | AsyncCallback\<boolean> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the module can be removed, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                           |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
try {
    freeInstall.isHapModuleRemovable(bundleName, moduleName, (err, data) => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## isHapModuleRemovable

isHapModuleRemovable(bundleName: string, moduleName: string): Promise\<boolean>

Checks whether a module can be removed. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Parameters**

| Name    | Type  | Mandatory| Description              |
| ---------- | ------ | ---- | ------------------ |
| bundleName | string | Yes  | Bundle name.  |
| moduleName | string | Yes  | Module name.|

**Return value**

| Type            | Description                        |
| ---------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. If the module can be removed, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                           |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700002 | The specified module name is not found. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
try {
    freeInstall.isHapModuleRemovable(bundleName, moduleName).then(data => {
        console.info('Operation succeed:' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## getBundlePackInfo

getBundlePackInfo(bundleName: string, bundlePackFlag : BundlePackFlag, callback: AsyncCallback\<BundlePackInfo>): void

Obtains bundlePackInfo based on **bundleName** and **bundlePackFlag**. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Parameters**

| Name        | Type                                                        | Mandatory| Description                                                        |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| bundleName     | string                                                       | Yes  | Bundle name.                                            |
| bundlePackFlag | [BundlePackFlag](#bundlepackflag)                            | Yes  | Flag of the bundle package.                                    |
| callback       | AsyncCallback<[BundlePackInfo](js-apis-bundleManager-BundlePackInfo-sys.md)> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the BundlePackInfo object obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                           |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
let bundleName = 'com.example.myapplication';
let bundlePackFlag = freeInstall.BundlePackFlag.GET_PACK_INFO_ALL;
try {
    freeInstall.getBundlePackInfo(bundleName, bundlePackFlag, (err, data) => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```
## getBundlePackInfo

getBundlePackInfo(bundleName: string, bundlePackFlag : BundlePackFlag): Promise\<BundlePackInfo>

Obtains bundlePackInfo based on **bundleName** and **bundlePackFlag**. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Parameters**

| Name        | Type                             | Mandatory| Description                  |
| -------------- | --------------------------------- | ---- | ---------------------- |
| bundleName     | string                            | Yes  | Bundle name.|
| bundlePackFlag | [BundlePackFlag](#bundlepackflag) | Yes  | Flag of the bundle package.|

**Return value**

| Type                                                      | Description                               |
| ---------------------------------------------------------- | ----------------------------------- |
| Promise<[BundlePackInfo](js-apis-bundleManager-BundlePackInfo-sys.md)> | Promise used to return the BundlePackInfo object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                           |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
let bundleName = 'com.example.myapplication';
let bundlePackFlag = freeInstall.BundlePackFlag.GET_PACK_INFO_ALL;
try {
    freeInstall.getBundlePackInfo(bundleName, bundlePackFlag).then(data => {
        console.info('Operation succeed:' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## getDispatchInfo

getDispatchInfo(callback: AsyncCallback\<DispatchInfo>): void

Obtains the dispatch information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md)> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**, and **data** is the [DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md) object obtained. otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID|    Error Message                           |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 801 | Capability not supported. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
try {
    freeInstall.getDispatchInfo((err, data) => {
        if (err) {
            console.error('Operation failed:' + JSON.stringify(err));
        } else {
            console.info('Operation succeed:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## getDispatchInfo

getDispatchInfo(): Promise\<DispatchInfo>

Obtains the dispatch information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

**Return value**

| Type                                            | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| Promise<[DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md)> | Promise used to return the [DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md) object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID|    Error Message                           |
|----------|----------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 801 | Capability not supported. |

**Example**

```js
import { freeInstall } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
try {
    freeInstall.getDispatchInfo().then(data => {
        console.info('Operation succeed:' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error('Operation failed:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## DispatchInfo

type DispatchInfo = _DispatchInfo

Defines the installation-free structure and API version information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_DispatchInfo](js-apis-bundleManager-dispatchInfo-sys.md#dispatchinfo) |Installation-free structure and API version information.|

## BundlePackInfo

type BundlePackInfo = _PackInfo.BundlePackInfo

Defines the bundle information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.BundlePackInfo](js-apis-bundleManager-BundlePackInfo-sys.md#bundlepackinfo) |Bundle information.|

## PackageConfig

type PackageConfig = _PackInfo.PackageConfig

Defines the package configuration information in the **pack.info** file.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.PackageConfig](js-apis-bundleManager-BundlePackInfo-sys.md#packageconfig) |Package configuration information in the **pack.info** file.|

## PackageSummary

type PackageSummary = _PackInfo.PackageSummary

Defines the package summary information in the **pack.info** file.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.PackageSummary](js-apis-bundleManager-BundlePackInfo-sys.md#packagesummary) |Package summary information in the **pack.info** file.|

## BundleConfigInfo

type BundleConfigInfo = _PackInfo.BundleConfigInfo

Defines the bundle configuration information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.BundleConfigInfo](js-apis-bundleManager-BundlePackInfo-sys.md#bundleconfiginfo) |Bundle configuration information.|

## ExtensionAbility

type ExtensionAbility = _PackInfo.ExtensionAbility

Defines the ExtensionAbility configuration information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ExtensionAbility](js-apis-bundleManager-BundlePackInfo-sys.md#extensionability) |ExtensionAbility configuration information.|

## ModuleConfigInfo

type ModuleConfigInfo = _PackInfo.ModuleConfigInfo

Defines the module configuration information of the bundle.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ModuleConfigInfo](js-apis-bundleManager-BundlePackInfo-sys.md#moduleconfiginfo) |Module configuration information of the bundle.|

## ModuleDistroInfo

type ModuleDistroInfo = _PackInfo.ModuleDistroInfo

Defines the distribution information of the module.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ModuleDistroInfo](js-apis-bundleManager-BundlePackInfo-sys.md#moduledistroinfo) |Distribution information of the module.|

## ModuleAbilityInfo

type ModuleAbilityInfo = _PackInfo.ModuleAbilityInfo

Defines the ability information of the module.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ModuleAbilityInfo](js-apis-bundleManager-BundlePackInfo-sys.md#moduleabilityinfo) |Ability information of the module.|

## AbilityFormInfo

type AbilityFormInfo = _PackInfo.AbilityFormInfo

Defines the widget information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.AbilityFormInfo](js-apis-bundleManager-BundlePackInfo-sys.md#abilityforminfo) |Widget information.|

## Version

type Version = _PackInfo.Version

Defines the version in the **pack.info** file.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.Version](js-apis-bundleManager-BundlePackInfo-sys.md#version) |Version in the **pack.info** file.|

## ApiVersion

type ApiVersion = _PackInfo.ApiVersion

Defines the API version of the module.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_PackInfo.ApiVersion](js-apis-bundleManager-BundlePackInfo-sys.md#apiversion) |API version of the module.|
