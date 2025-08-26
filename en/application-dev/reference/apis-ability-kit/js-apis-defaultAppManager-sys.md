# @ohos.bundle.defaultAppManager (Default Application Management) (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides APIs to query whether the current application is the default application of a specific type.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.bundle.defaultAppManager](js-apis-defaultAppManager.md).

## Modules to Import

```ts
import { defaultAppManager } from '@kit.AbilityKit';
```

## defaultAppManager.getDefaultApplication

getDefaultApplication(type: string, userId?: number): Promise\<BundleInfo>

Obtains the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| userId  | number | No   | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.                        |

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Promise used to return the default application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found.       |
| 17700023 | The specified default app does not exist. |
| 17700025 | The specified type is invalid.            |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

defaultAppManager.getDefaultApplication(defaultAppManager.ApplicationType.BROWSER)
  .then((data) => {
    console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  });

defaultAppManager.getDefaultApplication("image/png")
  .then((data) => {
    console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  });

defaultAppManager.getDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI)
  .then((data) => {
    console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  });
```

## defaultAppManager.getDefaultApplication

getDefaultApplication(type: string, userId: number, callback: AsyncCallback\<BundleInfo>) : void

Obtains the default application of a user based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| userId  | number | Yes   | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                          |
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found.       |
| 17700023 | The specified default app does not exist. |
| 17700025 | The specified type is invalid.            |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

let userId = 100;
defaultAppManager.getDefaultApplication(defaultAppManager.ApplicationType.BROWSER, userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});

defaultAppManager.getDefaultApplication("image/png", userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});

defaultAppManager.getDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});
```

## defaultAppManager.getDefaultApplication

getDefaultApplication(type: string, callback: AsyncCallback\<BundleInfo>) : void

Obtains the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| callback    | AsyncCallback\<[BundleInfo](js-apis-bundle-BundleInfo.md)> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700023 | The specified default app does not exist. |
| 17700025 | The specified type is invalid.            |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

defaultAppManager.getDefaultApplication(defaultAppManager.ApplicationType.BROWSER, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});

defaultAppManager.getDefaultApplication("image/png", (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});

defaultAppManager.getDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful. bundleInfo:' + JSON.stringify(data));
});
```

## defaultAppManager.getDefaultApplicationSync<sup>10+</sup>

getDefaultApplicationSync(type: string, userId?: number): BundleInfo

Obtains the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API returns the result synchronously.

**Required permissions**: ohos.permission.GET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                                   |
| -------| ------ | ---- | --------------------------------------- |
| type   | string | Yes  | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).|
| userId | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.         |

**Return value**

| Type                                      | Description                |
| ------------------------------------------ | -------------------- |
| [BundleInfo](js-apis-bundle-BundleInfo.md) | Bundle information of the default application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found.       |
| 17700023 | The specified default app does not exist. |
| 17700025 | The specified type is invalid.            |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

try {
  let data = defaultAppManager.getDefaultApplicationSync(defaultAppManager.ApplicationType.BROWSER)
  console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};

try {
  let data = defaultAppManager.getDefaultApplicationSync("image/png")
  console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};

try {
  let data = defaultAppManager.getDefaultApplicationSync(uniformTypeDescriptor.UniformDataType.AVI)
  console.info('Operation successful. bundleInfo: ' + JSON.stringify(data));
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};
```

## defaultAppManager.setDefaultApplication

setDefaultApplication(type: string, elementName: ElementName, userId?: number): Promise\<void>

Sets the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| elementName  | [ElementName](js-apis-bundle-ElementName.md) | Yes   | Information about the element to be set as the default application.                          |
| userId  | number | No   | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.                           |

**Return value**

| Type          | Description                              |
| -------------- | ---------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found.            |
| 17700025 | The specified type is invalid.                 |
| 17700028 | The specified ability does not match the type. |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

defaultAppManager.setDefaultApplication(defaultAppManager.ApplicationType.BROWSER, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}).then((data) => {
  console.info('Operation successful.');
}).catch((error: BusinessError) => {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
});

let userId = 100;
defaultAppManager.setDefaultApplication(defaultAppManager.ApplicationType.BROWSER, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId).then((data) => {
  console.info('Operation successful.');
}).catch((error: BusinessError) => {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
});

defaultAppManager.setDefaultApplication("image/png", {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId).then((data) => {
  console.info('Operation successful.');
}).catch((error: BusinessError) => {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
});

defaultAppManager.setDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId).then((data) => {
  console.info('Operation successful.');
}).catch((error: BusinessError) => {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
});
```

## defaultAppManager.setDefaultApplication

setDefaultApplication(type: string, elementName: ElementName, userId: number, callback: AsyncCallback\<void>) : void

Sets the default application for a user based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| elementName  | [ElementName](js-apis-bundle-ElementName.md) | Yes   | Information about the element to be set as the default application.                          |
| userId  | number | Yes   | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                          |
| callback    | AsyncCallback\<void> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found.            |
| 17700025 | The specified type is invalid.                 |
| 17700028 | The specified ability does not match the type. |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

let userId = 100;
defaultAppManager.setDefaultApplication(defaultAppManager.ApplicationType.BROWSER, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.setDefaultApplication("image/png", {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.setDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});
```

## defaultAppManager.setDefaultApplication

setDefaultApplication(type: string, elementName: ElementName, callback: AsyncCallback\<void>) : void

Sets the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| elementName  | [ElementName](js-apis-bundle-ElementName.md) | Yes   | Information about the element to be set as the default application.                          |
| callback    | AsyncCallback\<void> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700025 | The specified type is invalid.                 |
| 17700028 | The specified ability does not match the type. |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

defaultAppManager.setDefaultApplication(defaultAppManager.ApplicationType.BROWSER, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.setDefaultApplication("image/png", {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.setDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});
```

## defaultAppManager.setDefaultApplicationSync<sup>10+</sup>

setDefaultApplicationSync(type: string, elementName: ElementName, userId?: number): void

Sets the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API returns the result synchronously.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name     | Type  | Mandatory| Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type        | string | Yes  | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).|
| elementName | [ElementName](js-apis-bundle-ElementName.md) | Yes| Information about the element to be set as the default application.                          |
| userId      | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found.            |
| 17700025 | The specified type is invalid.                 |
| 17700028 | The specified ability does not match the type. |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

try {
  defaultAppManager.setDefaultApplicationSync(defaultAppManager.ApplicationType.BROWSER, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
});
  console.info('Operation successful.');
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};

let userId = 100;
try {
  defaultAppManager.setDefaultApplicationSync(defaultAppManager.ApplicationType.BROWSER, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId);
  console.info('Operation successful.');
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};

try {
  defaultAppManager.setDefaultApplicationSync("image/png", {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId);
  console.info('Operation successful.');
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};

try {
  defaultAppManager.setDefaultApplicationSync(uniformTypeDescriptor.UniformDataType.AVI, {
  bundleName: "com.example.myapplication",
  moduleName: "module01",
  abilityName: "EntryAbility"
}, userId);
  console.info('Operation successful.');
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};
```

## defaultAppManager.resetDefaultApplication

resetDefaultApplication(type: string, userId?: number): Promise\<void>

Resets the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| userId  | number | No   | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.                           |

**Return value**

| Type          | Description                              |
| -------------- | ---------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found. |
| 17700025 | The specified type is invalid.      |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

let userId = 100;
defaultAppManager.resetDefaultApplication(defaultAppManager.ApplicationType.BROWSER, userId)
  .then((data) => {
    console.info('Operation successful.');
  })
  .catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  });

defaultAppManager.resetDefaultApplication("image/png", userId)
  .then((data) => {
    console.info('Operation successful.');
  })
  .catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  });

defaultAppManager.resetDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, userId)
  .then((data) => {
    console.info('Operation successful.');
  })
  .catch((error: BusinessError) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
  });
```

## defaultAppManager.resetDefaultApplication

resetDefaultApplication(type: string, userId: number, callback: AsyncCallback\<void>) : void

Resets the default application for a user based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| userId  | number | Yes   | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).                         |
| callback    | AsyncCallback\<void> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found. |
| 17700025 | The specified type is invalid.      |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

let userId = 100;
defaultAppManager.resetDefaultApplication(defaultAppManager.ApplicationType.BROWSER, userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.resetDefaultApplication("image/png", userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.resetDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, userId, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});
```

## defaultAppManager.resetDefaultApplication

resetDefaultApplication(type: string, callback: AsyncCallback\<void>) : void

Resets the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| type  | string | Yes   | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).      |
| callback    | AsyncCallback\<void> | Yes   | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700025 | The specified type is invalid.      |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

defaultAppManager.resetDefaultApplication(defaultAppManager.ApplicationType.BROWSER, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.resetDefaultApplication("image/png", (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});

defaultAppManager.resetDefaultApplication(uniformTypeDescriptor.UniformDataType.AVI, (err: BusinessError, data) => {
  if (err) {
    console.error('Operation failed. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Operation successful.');
});
```

## defaultAppManager.resetDefaultApplicationSync<sup>10+</sup>

resetDefaultApplicationSync(type: string, userId?: number): void

Resets the default application based on a system-defined application type, a file type that complies with the media type format (either specified by **type** or **subtype**), or a [uniform data type](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md). This API returns the result synchronously.

**Required permissions**: ohos.permission.SET_DEFAULT_APPLICATION

**System capability**: SystemCapability.BundleManager.BundleFramework.DefaultApp

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                                   |
| ------ | ------ | ---- | --------------------------------------- |
| type   | string | Yes  | Type of the target application. It must be set to a value defined by [ApplicationType](js-apis-defaultAppManager.md#applicationtype), a file type that complies with the media type format, or a value defined by [UniformDataType](../apis-arkdata/js-apis-data-uniformTypeDescriptor.md).|
| userId | number | No  | User ID, which can be obtained by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9). The default value is the user ID of the caller.                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700004 | The specified user ID is not found. |
| 17700025 | The specified type is invalid.      |

**Example**

```ts
import { defaultAppManager } from '@kit.AbilityKit';
import { uniformTypeDescriptor } from '@kit.ArkData';

let userId = 100;
try {
  defaultAppManager.resetDefaultApplicationSync(defaultAppManager.ApplicationType.BROWSER, userId);
  console.info('Operation successful.');
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};

try {
  defaultAppManager.resetDefaultApplicationSync("image/png", userId);
  console.info('Operation successful.');
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};

try {
  defaultAppManager.resetDefaultApplicationSync(uniformTypeDescriptor.UniformDataType.AVI, userId);
  console.info('Operation successful.');
} catch(error) {
  console.error('Operation failed. Cause: ' + JSON.stringify(error));
};
```
