# @ohos.bundle.distributedBundle

The **distributedBundle** module provides APIs for managing distributed bundles.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```
import distributedBundle from '@ohos.bundle.distributedBundle';
```

## System Capability

SystemCapability.BundleManager.DistributedBundleFramework

## Required Permissions

| Permission                                      | Permission Level    | Description              |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | Permission to query information about all bundles.|

For details, see [Permission Levels](../../security/accesstoken-overview.md#permission-levels).

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback\<RemoteAbilityInfo>): void;

Obtains information about the remote ability that matches the given element name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| elementName | [ElementName](js-apis-bundleManager-elementName.md)          | Yes  | Target element name.                                           |
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **RemoteAbilityInfo** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID|    Error Message                  |
|----------|--------------------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'MainAbility'
        }, (err, data) => {
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

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName): Promise\<RemoteAbilityInfo>;

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
| Promise\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)> | Promise used to return the **RemoteAbilityInfo** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'MainAbility'
        }).then(data => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch(err => {
            console.error('Operation failed:' + JSON.stringify(err));
        });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void;

Obtains information about remote abilities that match the given element names. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)>   | Yes  | **ElementName** array, whose maximum length is 10.                            |
| callback     | AsyncCallback\<Array\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of **RemoteAbilityInfo** objects obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application1',
                abilityName: 'MainAbility1'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'MainAbility'
            }
        ], (err, data) => {
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

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>): Promise\<Array\<RemoteAbilityInfo>>;

Obtains information about remote abilities that match the given element names and locales. This API uses a promise to return the result.

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
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)>> | Promise used to return the array of **RemoteAbilityInfo** objects obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application',
                abilityName: 'MainAbility'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'MainAbility'
            }
        ]).then(data => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch(err => {
            console.error('Operation failed:' + JSON.stringify(err));
        });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, locale: string, callback: AsyncCallback\<RemoteAbilityInfo>): void;

Obtains information about the remote ability that matches the given element name and locale. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                              |
| ----------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md)                 | Yes  | Target element name.                           |
| locale  | string |Yes| Target locale.|
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the **RemoteAbilityInfo** object obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'MainAbility'
        }, 'zh-Hans-CN', (err, data) => {
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

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementName: ElementName, locale: string): Promise\<RemoteAbilityInfo>;

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
| Promise\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)> | Promise used to return the **RemoteAbilityInfo** object obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        {
            deviceId: '1',
            bundleName: 'com.example.application',
            abilityName: 'MainAbility'
        }, 'zh-Hans-CN').then(data => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch(err => {
            console.error('Operation failed:' + JSON.stringify(err));
        });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string, callback: AsyncCallback\<Array\<RemoteAbilityInfo>>): void;

Obtains information about remote abilities that match the given element names and locales. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                              |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementNames | Array<[ElementName](js-apis-bundleManager-elementName.md)>          | Yes  | **ElementName** array, whose maximum length is 10.                  |
| locale  | string |Yes| Target locale.|
| callback     | AsyncCallback\<Array\<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the array of **RemoteAbilityInfo** objects obtained. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID       |    Error Message                  |
|---------------|-------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application1',
                abilityName: 'MainAbility1'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'MainAbility'
            }
        ], 'zh-Hans-CN', (err, data) => {
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

## distributedBundle.getRemoteAbilityInfo

getRemoteAbilityInfo(elementNames: Array\<ElementName>, locale: string): Promise\<Array\<RemoteAbilityInfo>>;

Obtains information about remote abilities that match the given element names and locales. This API uses a promise to return the result.

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
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo.md)>> | Promise used to return the array of **RemoteAbilityInfo** objects obtained.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

| ID|    Error Message                  |
|----------|-------------------------|
| 17700001 | The specified bundle name is not found. |
| 17700003 | The specified ability name is not found. |
| 17700007 | The specified device ID is not found. |
| 17700027 | The distributed service is not running. |

**Example**

```ts
try {
    distributedBundle.getRemoteAbilityInfo(
        [
            {
                deviceId: '1',
                bundleName: 'com.example.application',
                abilityName: 'MainAbility'
            },
            {
                deviceId: '1',
                bundleName: 'com.example.application2',
                abilityName: 'MainAbility'
            }
        ], 'zh-Hans-CN').then(data => {
            console.info('Operation succeed:' + JSON.stringify(data));
        }).catch(err => {
            console.error('Operation failed:' + JSON.stringify(err));
        });
} catch (err) {
    console.error('Operation failed:' + JSON.stringify(err));
}
```
