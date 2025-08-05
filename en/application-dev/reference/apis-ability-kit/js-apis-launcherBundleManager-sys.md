# @ohos.bundle.launcherBundleManager (launcherBundleManager) (System API)

The module providers APIs for the Home Screen application to obtain the [launcher ability information](js-apis-bundleManager-launcherAbilityInfo.md) and [shortcut information](js-apis-bundleManager-shortcutInfo-sys.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
```


## launcherBundleManager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number, callback: AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\>) : void

Obtains the [launcher ability information](js-apis-bundleManager-launcherAbilityInfo.md) based on the given bundle name and user ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).|
| callback | AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\> | Yes| Callback used to return the LauncherAbilityInfo object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.      |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getLauncherAbilityInfo('com.example.demo', 100,
        (errData: BusinessError, data: launcherBundleManager.LauncherAbilityInfo[]) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.info('data is ' + JSON.stringify(data));
        }
    })
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getLauncherAbilityInfo<sup>9+</sup>

getLauncherAbilityInfo(bundleName: string, userId: number) : Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\>

Obtains the [launcher ability information](js-apis-bundleManager-launcherAbilityInfo.md) based on the given bundle name and user ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).|

**Return value**

| Type                         | Description                                              |
| ----------------------------- | -------------------------------------------------- |
| Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\> | Promise used to return the LauncherAbilityInfo object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.       |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getLauncherAbilityInfo("com.example.demo", 100)
        .then((data: launcherBundleManager.LauncherAbilityInfo[]) => {
        console.info('data is ' + JSON.stringify(data));
    }).catch ((errData: BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    })
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number, callback: AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\>) : void

Obtains the [launcher ability information](js-apis-bundleManager-launcherAbilityInfo.md) of all applications based on the given user ID. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | -------------- |
| userId | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).|
| callback | AsyncCallback\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\> | Yes| Callback used to return the array of LauncherAbilityInfo objects obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700004 | The specified user ID is not found.      |

Example

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100,
        (errData: BusinessError, data: launcherBundleManager.LauncherAbilityInfo[]) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.info('data is ' + JSON.stringify(data));
        }
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```
## launcherBundleManager.getAllLauncherAbilityInfo<sup>9+</sup>

getAllLauncherAbilityInfo(userId: number) : Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\>

Obtains the [launcher ability information](js-apis-bundleManager-launcherAbilityInfo.md) of all applications based on the given user ID. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | -------------- |
| userId | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).|

**Return value**

| Type                         | Description                                                  |
| ----------------------------- | ------------------------------------------------------ |
| Promise\<Array\<[LauncherAbilityInfo](js-apis-bundleManager-launcherAbilityInfo.md)\>\> | Promise used to return the array of LauncherAbilityInfo objects obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700004 | The specified user ID is not found.      |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getAllLauncherAbilityInfo(100)
        .then((data: launcherBundleManager.LauncherAbilityInfo[]) => {
        console.info('data is ' + JSON.stringify(data));
    }).catch ((errData: BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName :string, callback: AsyncCallback\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\>) : void

Obtains the [shortcut information](js-apis-bundleManager-shortcutInfo-sys.md) of the current user based on the given bundle name of a main application. To obtain shortcut information about an application clone, use [getShortcutInfoByAppIndex](#launcherbundlemanagergetshortcutinfobyappindex20).

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name.|
| callback | AsyncCallback\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\> | Yes| Callback used to return the [ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md) object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo",
        (errData: BusinessError, data: launcherBundleManager.ShortcutInfo[]) => {
        if (errData !== null) {
            console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
        } else {
            console.info('data is ' + JSON.stringify(data));
        }
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfo<sup>9+</sup>

getShortcutInfo(bundleName : string) : Promise\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\>

Obtains the [shortcut information](js-apis-bundleManager-shortcutInfo-sys.md) of the current user based on the given bundle name of a main application. To obtain shortcut information about an application clone, use [getShortcutInfoByAppIndex](#launcherbundlemanagergetshortcutinfobyappindex20).

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type                  | Description                                           |
| ---------------------- | ----------------------------------------------- |
| Promise\<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>\> | Promise used to return the [ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md) object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    launcherBundleManager.getShortcutInfo("com.example.demo")
        .then((data: launcherBundleManager.ShortcutInfo[]) => {
        console.info('data is ' + JSON.stringify(data));
    }).catch ((errData: BusinessError) => {
        console.error(`errData is errCode:${errData.code}  message:${errData.message}`);
    });
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfoSync<sup>10+</sup>

getShortcutInfoSync(bundleName : string) : Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>

Obtains the [shortcut information](js-apis-bundleManager-shortcutInfo-sys.md) of the current user based on the given bundle name of a main application. To obtain shortcut information about an application clone, use [getShortcutInfoByAppIndex](#launcherbundlemanagergetshortcutinfobyappindex20).

*Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name.|

**Return value**

| Type                  | Description                                           |
| ---------------------- | ----------------------------------------------- |
| Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\> | Array of the [ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md) objects obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    let data = launcherBundleManager.getShortcutInfoSync("com.example.demo");
    console.info('data is ' + JSON.stringify(data));
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.getShortcutInfoSync<sup>13+</sup>

getShortcutInfoSync(bundleName: string, userId: number) : Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\>

Obtains the [shortcut information](js-apis-bundleManager-shortcutInfo-sys.md) of the specified user based on the given bundle name of a main application. To obtain shortcut information about an application clone, use [getShortcutInfoByAppIndex](#launcherbundlemanagergetshortcutinfobyappindex20).

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| bundleName | string | Yes  | Bundle name.|
| userId     | number | Yes  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). |

**Return value**

| Type                  | Description                                           |
| ---------------------- | ----------------------------------------------- |
| Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md)\> | Array of the [ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md) objects obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.     |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    let data = launcherBundleManager.getShortcutInfoSync("com.example.demo", 100);
    console.info('data is ' + JSON.stringify(data));
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## launcherBundleManager.startShortcut<sup>12+</sup>

startShortcut(shortcutInfo: ShortcutInfo, options?: StartOptions): Promise\<void\>;

Starts an ability based on the specified [shortcut information](js-apis-bundleManager-shortcutInfo-sys.md).

**Required permissions**: ohos.permission.START_SHORTCUT

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name       | Type  | Mandatory| Description        |
| ------------ | ------ | ---- | -------------- |
| shortcutInfo | [ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md) | Yes  | Shortcut information of the application.|
| options      | [StartOptions](js-apis-app-ability-startOptions-sys.md)   | No  | Startup parameters, which are used to specify the window mode and device ID for switching the mission to the foreground.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not support. |
| 17700065 | The ability specified by want in the ShortcutInfo struct cannot be started.  |

**Example**

```ts
import launcherBundleManager from '@ohos.bundle.launcherBundleManager';
import { BusinessError } from '@ohos.base';

try {
    let data : Array<launcherBundleManager.ShortcutInfo> = launcherBundleManager.getShortcutInfoSync("com.example.demo");
    console.info('data is ' + JSON.stringify(data));
    if (data) {
        try {
            launcherBundleManager.startShortcut(data[0])
                .then(() => {
                console.info('startShortcut success');
            }).catch ((err: BusinessError) => {
                console.error(`errData is errCode:${err.code}  message:${err.message}`);
            });
        } catch (error) {
            let code = (error as BusinessError).code;
            let message = (error as BusinessError).message;
            console.error(`error is errCode:${code}  message:${message}`);
        }
    }
} catch (errData) {
    let code = (errData as BusinessError).code;
    let message = (errData as BusinessError).message;
    console.error(`errData is errCode:${code}  message:${message}`);
}
```

## ShortcutInfo

type ShortcutInfo = _ShortcutInfo

Defines the shortcut information defined in the [module.json5](../../quick-start/module-configuration-file.md#shortcuts) file of the application.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Type                                      | Description     |
| ------------------------------------------------------------ | -------------- |
| [_ShortcutInfo](js-apis-bundleManager-shortcutInfo-sys.md#shortcutinfo) | Shortcut information defined in the **module.json5** file. |

## ShortcutWant

type ShortcutWant = _ShortcutWant

Defines a collection of target [Wants](../../quick-start/module-configuration-file.md#wants) information defined within a shortcut.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Type                                      | Description     |
| ------------------------------------------------------------ | -------------- |
| [_ShortcutWant](js-apis-bundleManager-shortcutInfo-sys.md#shortcutwant) | Target [wants](../../quick-start/module-configuration-file.md#wants) defined in the shortcut configuration. |

## ParameterItem<sup>12+</sup>

type ParameterItem = _ParameterItem

Defines the custom data in the shortcut configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

| Type                                      | Description     |
| ------------------------------------------------------------ | -------------- |
| [_ParameterItem](js-apis-bundleManager-shortcutInfo-sys.md#parameteritem12) | Custom data in the shortcut configuration. |
