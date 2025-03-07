# @ohos.bundle.overlay (overlay)

The overlay module provides APIs for installing a [module with the overlay feature](#module-with-the-overlay-feature), querying the [module information](js-apis-bundleManager-overlayModuleInfo.md), and disabling and enabling the module.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

``` ts
import { overlay } from '@kit.AbilityKit';
```

## overlay.setOverlayEnabled

setOverlayEnabled(moduleName:string, isEnabled: boolean): Promise\<void>

Enables or disables a module with the overlay feature in the current application. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName  | string | Yes   | Name of the module with the overlay feature.              |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. The value **true** means to enable the module, and **false** means to disable the module.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified module name is not found. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let moduleName = "feature";
let isEnabled = false;

try {
  overlay.setOverlayEnabled(moduleName, isEnabled)
    .then(() => {
      console.info('setOverlayEnabled success');
    }).catch((err: BusinessError) => {
      console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
    });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.info('setOverlayEnabled failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.setOverlayEnabled

setOverlayEnabled(moduleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables a module with the overlay feature in the current application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName  | string | Yes   | Name of the module with the overlay feature.              |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. The value **true** means to enable the module, and **false** means to disable the module.|
| callback    | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified module name is not found. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let moduleName = "feature";
let isEnabled = false;

try {
  overlay.setOverlayEnabled(moduleName, isEnabled, (err, data) => {
    if (err) {
      console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
      return;
    }
    console.info('setOverlayEnabled success');
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.info('setOverlayEnabled failed due to err code: ' + code + ' ' + 'message:' + message);
}
```

## overlay.getOverlayModuleInfo

getOverlayModuleInfo(moduleName: string): Promise\<OverlayModuleInfo>

Obtains the information about a module with the overlay feature in the current application. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | ------------------------------------------ |
| moduleName | string | Yes   | Name of the module with the overlay feature.    |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)> | Promise used to return the result, which is an [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let moduleName = "feature";

(async () => {
  try {
    let overlayModuleInfo = await overlay.getOverlayModuleInfo(moduleName);
    console.log('overlayModuleInfo is ' + JSON.stringify(overlayModuleInfo));
  } catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getOverlayModuleInfo failed due to err code : ' + code + ' ' + 'message :' + message);
  }
})();
```

## overlay.getOverlayModuleInfo

getOverlayModuleInfo(moduleName: string, callback: AsyncCallback\<OverlayModuleInfo>): void

Obtains the information about a module with the overlay feature in the current application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName | string | Yes   | Name of the module with the overlay feature.    |
| callback    | AsyncCallback\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)> | Yes   | Callback used to return the result, which is an [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) object. If the operation is successful, **err** is **null**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let moduleName = "feature";

try {
  overlay.getOverlayModuleInfo(moduleName, (err, data) => {
    if (err) {
      console.log('getOverlayModuleInfo failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
      return;
    }
    console.log('overlayModuleInfo is ' + JSON.stringify(data));
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.log('getOverlayModuleInfo failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## overlay.getTargetOverlayModuleInfos

getTargetOverlayModuleInfos(targetModuleName: string): Promise\<Array\<OverlayModuleInfo>>

Obtains the information about modules with the overlay feature in the current application based on the target module name. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetModuleName | string | Yes   | Name of the target module specified by modules with the overlay feature.    |

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Promise used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let targetModuleName = "feature";

(async () => {
  try {
    let overlayModuleInfos = await overlay.getTargetOverlayModuleInfos(targetModuleName);
    console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
  } catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);
  }
})();
```

## overlay.getTargetOverlayModuleInfos

getTargetOverlayModuleInfos(targetModuleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void

Obtains the information about modules with the overlay feature in the current application based on the target module name. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetModuleName | string | Yes   | Name of the target module specified by modules with the overlay feature.    |
| callback    | AsyncCallback\<Array\<[OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md)>> | Yes   | Callback used to return the result, which is an array of [OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md) objects. If the operation is successful, **err** is **null**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700002 | The specified module name is not found.  |
| 17700034 | The specified module is an overlay module. |

**Example**

```ts
import { overlay } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let targetModuleName = "feature";

try {
  overlay.getTargetOverlayModuleInfos(targetModuleName, (err, data) => {
    if (err) {
      console.log('getTargetOverlayModuleInfos failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
      return;
    }
    console.log('overlayModuleInfo is ' + JSON.stringify(data));
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.log('getTargetOverlayModuleInfos failed due to err code : ' + code + ' ' + 'message :' + message);
}
```

## OverlayModuleInfo

type OverlayModuleInfo = _OverlayModuleInfo.OverlayModuleInfo

Defines the information about a module with the overlay feature.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_OverlayModuleInfo.OverlayModuleInfo](js-apis-bundleManager-overlayModuleInfo.md#overlaymoduleinfo-1) |Information about a module with the overlay feature.|

## Module with the Overlay Feature

**Concept**
A module with the overlay feature generally provides additional resource files for modules without the overlay feature on the device, so that the target modules can use these resource files at runtime to display different colors, labels, themes, and the like. The overlay feature applies only to the stage model.

**How do I identify a module with the overlay feature?**
If the **module.json5** file of a module contains the **targetModuleName** and **targetPriority fields** during project creation on DevEco Studio, the module is identified as a module with the overlay feature in the installation phase.
