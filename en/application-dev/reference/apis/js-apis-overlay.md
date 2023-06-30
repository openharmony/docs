# @ohos.bundle.overlay (overlay)

The **overlay** module provides APIs for installing a [module with the overlay feature](#module-with-the-overlay-feature), querying the [module information](js-apis-bundleManager-overlayModuleInfo.md), and disabling and enabling the module.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

``` ts
import overlay from '@ohos.bundle.overlay'
```

## overlay.setOverlayEnabled

setOverlayEnabled(moduleName:string, isEnabled: boolean): Promise\<void>;

Enables or disables a module with the overlay feature in the current application. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName  | string | Yes   | HAP name of the module with the overlay feature.              |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. The value **true** means to enable the module, and **false** means to disable the module.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var moduleName = "feature";
var isEnabled = false;

try {
    overlay.setOverlayEnabled(moduleName, isEnabled)
        .then(() => {
            console.info('setOverlayEnabled success');
        }).catch((err) => {
            console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
        });
} catch (err) {
    console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
}
```

## overlay.setOverlayEnabled

setOverlayEnabled(moduleName:string, isEnabled: boolean, callback: AsyncCallback\<void>): void;

Enables or disables a module with the overlay feature in the current application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName  | string | Yes   | HAP name of the module with the overlay feature.              |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. The value **true** means to enable the module, and **false** means to disable the module.|
| callback    | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var moduleName = "feature";
var isEnabled = false;

try {
    overlay.setOverlayEnabled(moduleName, isEnabled, (err, data) => {
        if (err) {
            console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
            return;
        }
        console.info('setOverlayEnabled success');
    });
} catch (err) {
    console.info('setOverlayEnabled failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
}
```

## overlay.setOverlayEnabledByBundleName

setOverlayEnabledByBundleName(bundleName:string, moduleName:string, isEnabled: boolean): Promise\<void>;

Enables or disables a module with the overlay feature in another application. This API uses a promise to return the result. If the operation is successful, the processing result is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | Yes   | Bundle name of the application.                |
| moduleName  | string | Yes   | HAP name of the module with the overlay feature.   |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. The value **true** means to enable the module, and **false** means to disable the module.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var bundleName = "com.example.myapplication_xxxxx";
var moduleName = "feature";
var isEnabled = false;

try {
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled)
        .then((data) => {
            console.info('setOverlayEnabledByBundleName successfully');
        }).catch((err) => {
            console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
        });
} catch (err) {
    console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
}
```

## overlay.setOverlayEnabledByBundleName

setOverlayEnabledByBundleName(bundleName:string, moduleName:string, isEnabled: boolean, callback: AsyncCallback\<void>): void;

Enables or disables a module with the overlay feature in another application. This API uses an asynchronous callback to return the result. If the operation is successful, the processing result is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                 |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | Yes   | Bundle name of the application.                |
| moduleName  | string | Yes   | HAP name of the module with the overlay feature.   |
| isEnabled   | boolean  | Yes | Whether to enable the module with the overlay feature. The value **true** means to enable the module, and **false** means to disable the module.|
| callback    | AsyncCallback\<void> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined** and data is the processing result obtained; otherwise, **err** is an error object.                   |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var bundleName = "com.example.myapplication_xxxxx";
var moduleName = "feature";
var isEnabled = false;

try {
    overlay.setOverlayEnabledByBundleName(bundleName, moduleName, isEnabled, (err, data) => {
        if (err) {
            console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
            return;
        }
        console.info('setOverlayEnabledByBundleName successfully');
    });
} catch (err) {
    console.info('setOverlayEnabledByBundleName failed due to err code: ' + err.code + ' ' + 'message:' + err.message);
}
```

## overlay.getOverlayModuleInfo

getOverlayModuleInfo(moduleName: string): Promise\<OverlayModuleInfo>;

Obtains the information about a module with the overlay feature in the current application. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | ------------------------------------------ |
| moduleName | string | Yes   | HAP name of the module with the overlay feature.    |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<OverlayModuleInfo> | Promise used to return the result, which is an **OverlayModuleInfo** object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfo = await overlay.getOverlayModuleInfo(moduleName);
        console.log('overlayModuleInfo is ' + JSON.stringify(overlayModuleInfo));
    } catch(err) {
        console.log('getOverlayModuleInfo failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
    }
})();
```

## overlay.getOverlayModuleInfo

getOverlayModuleInfo(moduleName: string, callback: AsyncCallback\<OverlayModuleInfo>): void;

Obtains the information about a module with the overlay feature in the current application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| moduleName | string | Yes   | HAP name of the module with the overlay feature.    |
| callback    | AsyncCallback\<OverlayModuleInfo> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var moduleName = "feature";
try {
    overlay.getOverlayModuleInfo(moduleName, (err, data) => {
        if (err) {
            console.log('getOverlayModuleInfo failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    console.log('getOverlayModuleInfo failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
}
```

## overlay.getTargetOverlayModuleInfos

getTargetOverlayModuleInfos(targetModuleName: string): Promise\<Array\<OverlayModuleInfo>>;

Obtains the information about modules with the overlay feature in the current application based on the target module name. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetModuleName | string | Yes   | HAP name of the target module, which is **targetModuleName** specified by modules with the overlay feature.    |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<Array\<OverlayModuleInfo>> | Promise used to return the result, which is an array of **OverlayModuleInfo** objects.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |

**Example**

```ts
var targetModuleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getTargetOverlayModuleInfos(targetModuleName);
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        console.log('getTargetOverlayModuleInfos failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
    }
})();
```

## overlay.getTargetOverlayModuleInfos

getTargetOverlayModuleInfos(targetModuleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void;

Obtains the information about modules with the overlay feature in the current application based on the target module name. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetModuleName | string | Yes   | HAP name of the target module specified by modules with the overlay feature.    |
| callback    | AsyncCallback\<Array\<OverlayModuleInfo>> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700002 | The specified module name is not found.  |
| 17700034 | The specified module is an overlay module. |

**Example**

```ts
var targetModuleName = "feature";
try {
    overlay.getTargetOverlayModuleInfos(targetModuleName, (err, data) => {
        if (err) {
            console.log('getTargetOverlayModuleInfos failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    console.log('getTargetOverlayModuleInfos failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
}
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, moduleName?: string): Promise\<Array\<OverlayModuleInfo>>;

Obtains the information about a module with the overlay feature in another application. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | No   | HAP name of the module with the overlay feature. By default, no value is passed, and the API obtains the information of all modules with the overlay feature in that application.    |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<Array\<OverlayModuleInfo>> | Promise used to return the result, which is an array of **OverlayModuleInfo** objects.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var bundleName = "com.example.myapplication_xxxxx";
var moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName);
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        console.log('getTargetOverlayModuleInfos failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
    }
})();
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, moduleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void;

Obtains the information about a module with the overlay feature in another application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | Yes   | HAP name of the module with the overlay feature. If this parameter is not specified, the API obtains the information of all modules with the overlay feature in that application.    |
| callback    | AsyncCallback\<Array\<OverlayModuleInfo>> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |
| 17700033 | The specified module is not an overlay module. |

**Example**

```ts
var bundleName = "com.example.myapplication_xxxxx";
var moduleName = "feature";

try {
    overlay.getOverlayModuleInfoByBundleName(bundleName, moduleName, (err, data) => {
        if (err) {
            console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
}
```

## overlay.getOverlayModuleInfoByBundleName

getOverlayModuleInfoByBundleName(bundleName: string, callback: AsyncCallback\<Array\<OverlayModuleInfo>>): void;

Obtains the information about all modules with the overlay feature in another application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName | string | Yes   | Bundle name of the application.                   |
| callback    | AsyncCallback\<Array\<OverlayModuleInfo>> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700032 | The specified bundle does not contain any overlay module. |

**Example**

```ts
var bundleName = "com.example.myapplication_xxxxx";

try {
    overlay.getOverlayModuleInfoByBundleName(bundleName, (err, data) => {
        if (err) {
            console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    console.log('getOverlayModuleInfoByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
}
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, moduleName?: string): Promise\<Array\<OverlayModuleInfo>>;

Obtains the information about modules with the overlay feature in another application based on the target module name. This API uses a promise to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | No   | HAP name of the target module, which is **targetModuleName** specified by modules with the overlay feature. By default, no value is passed, and the API obtains the information associated with all modules in that application.    |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<Array\<OverlayModuleInfo>> | Promise used to return the result, which is an array of **OverlayModuleInfo** objects.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |
| 17700035 | The specified bundle is an overlay bundle. |

**Example**

```ts
var targetBundleName = "com.example.myapplication_xxxxx";
var moduleName = "feature";

(async() => {
    try {
        let overlayModuleInfos = await overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName);
        console.log('overlayModuleInfos are ' + JSON.stringify(overlayModuleInfos));
    } catch(err) {
        console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
    }
})();
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, moduleName: string, callback: AsyncCallback&lt;Array&lt;OverlayModuleInfo&gt;&gt;): void;

Obtains the information about modules with the overlay feature in another application based on the target module name. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | Yes   | Bundle name of the application.                   |
| moduleName | string | Yes   | HAP name of the target module, which is **targetModuleName** specified by modules with the overlay feature. If this parameter is not specified, the API obtains the information associated with all modules in that application.    |
| callback    | AsyncCallback\<Array\<OverlayModuleInfo>> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700002 | The specified module name is not found. |
| 17700034 | The specified module is an overlay module. |
| 17700035 | The specified bundle is an overlay bundle. |

**Example**

```ts
var targetBundleName = "com.example.myapplication_xxxxx";
var moduleName = "feature";

try {
    overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, moduleName, (err, data) => {
        if (err) {
            console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
}
```

## overlay.getTargetOverlayModuleInfosByBundleName

getTargetOverlayModuleInfosByBundleName(targetBundleName: string, callback: AsyncCallback&lt;Array&lt;OverlayModuleInfo&gt;&gt;): void;

Obtains the information about all modules with the overlay feature in another application. This API uses an asynchronous callback to return the result. If the operation is successful, **null** is returned; otherwise, an error message is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.BundleFramework.Overlay

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| targetBundleName | string | Yes   | Bundle name of the application.                   |
| callback    | AsyncCallback\<Array\<OverlayModuleInfo>> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.                  |

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID| Error Message                               |
| ------ | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700035 | The specified bundle is an overlay bundle. |

**Example**

```ts
var targetBundleName = "com.example.myapplication_xxxxx";

try {
    overlay.getTargetOverlayModuleInfosByBundleName(targetBundleName, (err, data) => {
        if (err) {
            console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
            return;
        }
        console.log('overlayModuleInfo is ' + JSON.stringify(data));
    });
} catch (err) {
    console.log('getTargetOverlayModuleInfosByBundleName failed due to err code : ' + err.code + ' ' + 'message :' + err.message);
}
```

## Module with the Overlay Feature

**Concept**
A module with the overlay feature generally provides additional resource files for modules without the overlay feature on the device, so that the target modules can use these resource files at runtime to display different colors, labels, themes, and the like. The overlay feature applies only to the stage model.

**How do I identify a module with the overlay feature?**
If the **module.json5** file of a module contains the **targetModuleName** and **targetPriority fields** during project creation on DevEco Studio, the module is identified as a module with the overlay feature in the installation phase.
