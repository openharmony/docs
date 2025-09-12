# @ohos.bundle.overlay (overlay) (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides APIs for installing a [module with the overlay feature](js-apis-overlay.md), querying the [module information](js-apis-bundleManager-overlayModuleInfo.md), and disabling and enabling the module.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.bundle.overlay](js-apis-overlay.md).

## Modules to Import

``` ts
import { overlay } from '@kit.AbilityKit';
```

## overlay.setOverlayEnabledByBundleName

setOverlayEnabledByBundleName(bundleName: string, moduleName: string, isEnabled: boolean): Promise\<void>

Enables or disables a module with the overlay feature in another application. This API uses a promise to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | Yes   | Bundle name of the application.                |
| moduleName  | string | Yes   | Name of the module with the overlay feature.   |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. **true** to enable, **false** otherwise.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";
let isEnabled = false;

try {
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled)
        .then((data) => {
            console.info('setOverlayEnabledByBundleName successfully');
        }).catch((err: BusinessError) => {
            console.error('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error('setOverlayEnabledByBundleName failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.setOverlayEnabledByBundleName

setOverlayEnabledByBundleName(bundleName: string, moduleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables a module with the overlay feature in another application. This API uses an asynchronous callback to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                 |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | Yes   | Bundle name of the application.                |
| moduleName  | string | Yes   | Name of the module with the overlay feature.   |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. **true** to enable, **false** otherwise.|
| callback    | AsyncCallback\<void> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";
let isEnabled = false;

try {
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled, (err, data) => {
        if (err) {
            console.error('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
            return;
        }
        console.info('setOverlayEnabledByBundleName successfully');
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error('setOverlayEnabledByBundleName failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, moduleName?: string): Promise\<Array\<OverlayModuleInfo>>

Obtains the information about a module with the overlay feature in another application. This API uses a promise to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | No   | Name of the module with the overlay feature. By default, no value is passed, and the API obtains the information of all modules with the overlay feature in that application.    |

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Promise used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName);
        console.info('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);
    }
})();
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, moduleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void

Obtains the information about a module with the overlay feature in another application. This API uses an asynchronous callback to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | Yes   | Name of the module with the overlay feature. If this parameter is not specified, the API obtains the information of all modules with the overlay feature in that application.    |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

try {
    overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName, (err, data) => {
        if (err) {
            console.error('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.info('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error('getOverlayModuleInfoByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void

Obtains the information about all modules with the overlay feature in another application. This API uses an asynchronous callback to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.                   |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName = "com.example.myapplication_xxxxx";

try {
    overlay.getOverlayModuleInfoByBundleName(bundleName, (err, data) => {
        if (err) {
            console.error('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.info('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error('getOverlayModuleInfoByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, moduleName?: string): Promise\<Array\<OverlayModuleInfo>>

Obtains the information about modules with the overlay feature in another application based on the target module name. This API uses a promise to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | No   | Name of the target module. By default, no value is passed, and the API obtains the information associated with all modules in that application.    |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Promise used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |
| 17700035 | The specified bundle is an overlay bundle. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let targetBundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName);
        console.info('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
    }
})();
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;OverlayModuleInfo&gt;&gt;): void

Obtains the information about modules with the overlay feature in another application based on the target module name. This API uses an asynchronous callback to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | Yes   | Name of the target module. If this parameter is not specified, the API obtains the information associated with all modules in that application.    |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |
| 17700035 | The specified bundle is an overlay bundle. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let targetBundleName = "com.example.myapplication_xxxxx";
let moduleName = "feature";

try {
    overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName, (err, data) => {
        if (err) {
            console.error('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.info('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, callback: AsyncCallback&lt;Array&lt;OverlayModuleInfo&gt;&gt;): void

Obtains the information about all modules with the overlay feature in another application. This API uses an asynchronous callback to return the result.

No permission is required when the specified application is the caller itself.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | Yes   | Bundle name of the application.                   |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundleName is not found. |
| 17700035 | The specified bundle is an overlay bundle. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let targetBundleName = "com.example.myapplication_xxxxx";

try {
    overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, (err, data) => {
        if (err) {
            console.error('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.info('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + code + ' ' + 'message :' + message);
}
```
