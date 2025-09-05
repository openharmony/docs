# @ohos.bundle.distributedBundleManager (distributedBundleManager) (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides APIs for managing distributed bundles.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

``` ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
```

## System Capabilities

SystemCapability.BundleManager.DistributedBundleFramework

## Required Permissions

| Permission                                      | APL    | Description              |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | Permission to obtain basic information and other sensitive information about a bundle.|

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void

Obtains information about the remote ability that matches the given element name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| elementName | [ElementName](js-apis-bundleManager-elementName.md)          | Yes  | Target element name.                                           |
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the RemoteAbilityInfo object obtained. Otherwise, **err** is an error object and **data** is **undefined**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                  |
|----------|--------------------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }, (err: BusinessError, data: distributedBundle.RemoteAbilityInfo) => {
            if (err) {
                console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
            } else {
                console.info('Operation succeed:' + JSON.stringify(data));
            }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>

Obtains information about the remote ability that matches the given element name. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name      | Type                                        | Mandatory| Description                   |
| ----------- | -------------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes  | Target element name.|

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | Promise used to return the result. If the operation is successful, the RemoteAbilityInfo object is returned. Otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }).then((data: distributedBundle.RemoteAbilityInfo) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void

Obtains information about the remote abilities that match the given element names. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)>   | Yes  | **ElementName** array, whose maximum length is 10.                            |
| callback     | AsyncCallback\<Array\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of RemoteAbilityInfo objects obtained. Otherwise, **err** is an error object and **data** is **undefined**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application1',
                abilityName: 'EntryAbility1'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ], (err: BusinessError, data: distributedBundle.RemoteAbilityInfo[]) => {
          if (err) {
            console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
          } else {
            console.info('Operation succeed:' + JSON.stringify(data));
          }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>

Obtains information about the remote abilities that match the given element names. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name       | Type                                               | Mandatory| Description                   |
| ------------ | --------------------------------------------------- | ---- | ----------------------- |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)> | Yes  | **ElementName** array, whose maximum length is 10.|

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | Promise used to return the result. If the operation is successful, an array of RemoteAbilityInfo objects is returned. Otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application',
                abilityName: 'EntryAbility'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ]).then((data: distributedBundle.RemoteAbilityInfo[]) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, locale: string, callback: AsyncCallback\<RemoteAbilityInfo>): void

Obtains information about the remote ability that matches the given element name and locale. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                              |
| ----------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md)                 | Yes  | Target element name.                           |
| locale  | string |Yes| Target locale.|
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the RemoteAbilityInfo object obtained. Otherwise, **err** is an error object and **data** is **undefined**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }, 'zh-Hans-CN', (err: BusinessError, data: distributedBundle.RemoteAbilityInfo) => {
          if (err) {
            console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
          } else {
            console.info('Operation succeed:' + JSON.stringify(data));
          }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, locale: string): Promise\<RemoteAbilityInfo>

Obtains information about the remote ability that matches the given element name and locale. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name      | Type                                        | Mandatory| Description                   |
| ----------- | -------------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes  | Target element name.|
| locale  | string |Yes| Target locale.|

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)> | Promise used to return the result. If the operation is successful, the RemoteAbilityInfo object is returned. Otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'EntryAbility'
        }, 'zh-Hans-CN').then((data: distributedBundle.RemoteAbilityInfo) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void

Obtains information about the remote abilities that match the given element names and locale. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                              |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)>          | Yes  | **ElementName** array, whose maximum length is 10.                  |
| locale  | string |Yes| Target locale.|
| callback     | AsyncCallback\<Array\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | Yes  | [Callback](../apis-basic-services-kit/js-apis-base.md#asynccallback) used to return the result. If the operation is successful, **err** is **null** and **data** is the array of RemoteAbilityInfo objects obtained. Otherwise, **err** is an error object and **data** is **undefined**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID       |    Error Message                  |
|---------------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application1',
                abilityName: 'EntryAbility1'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ], 'zh-Hans-CN', (err: BusinessError, data: distributedBundle.RemoteAbilityInfo[]) => {
          if (err) {
           console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
          } else {
            console.info('Operation succeed:' + JSON.stringify(data));
          }
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string): Promise\<Array\<RemoteAbilityInfo>>

Obtains information about the remote abilities that match the given element names and locale. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name       | Type                                               | Mandatory| Description                   |
| ------------ | --------------------------------------------------- | ---- | ----------------------- |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)> | Yes  | **ElementName** array, whose maximum length is 10.|
| locale  | string |Yes| Target locale.|

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md)>> | Promise used to return the result. If the operation is successful, an array of RemoteAbilityInfo objects is returned. Otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 801 | Capability not supported. |
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
import distributedBundle from '@ohos.bundle.distributedBundleManager';
import { BusinessError } from '@ohos.base';

try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application',
                abilityName: 'EntryAbility'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'EntryAbility'
            }
        ], 'zh-Hans-CN').then((data: distributedBundle.RemoteAbilityInfo[]) => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
            console.error(`Operation failed: error code is ${err.code}  and error message is ${err.message}`);
        });
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error(`Operation failed: error code is ${code}  and error message is ${message}`);
}
```

## RemoteAbilityInfo

type RemoteAbilityInfo = _RemoteAbilityInfo

Defines the remote ability information.

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| [_RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md#remoteabilityinfo) |Remote ability information.|
