# @ohos.distributedBundle (Distributed Bundle Management) (System API)

The distributedBundle module manages distributed bundles.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are deprecated since API version 9. You are advised to use [@ohos.bundle.distributedBundleManager](js-apis-distributedBundleManager-sys.md) instead.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```
import distributedBundle from '@ohos.distributedBundle';
```

## System Capability

SystemCapability.BundleManager.DistributedBundleFramework

## Required Permissions

| Permission                                      | APL    | Description              |
| ------------------------------------------ | ------------ | ------------------ |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | Permission to query information about all applications.|

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

## distributedBundle.getRemoteAbilityInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md) instead.

getRemoteAbilityInfo(elementName: ElementName, callback: AsyncCallback&lt;RemoteAbilityInfo&gt;): void

Obtains the information about the remote ability that matches the given element name. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.DistributedBundleFramework

**System API**

This is a system API.

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                              |
| ----------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementName | [ElementName](js-apis-bundle-ElementName.md)                 | Yes  | **ElementName**.                           |
| callback    | AsyncCallback<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)> | Yes  | Callback used to return the remote ability information.|



## distributedBundle.getRemoteAbilityInfo<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md) instead.

getRemoteAbilityInfo(elementName: ElementName): Promise&lt;RemoteAbilityInfo&gt;

Obtains the information about the remote ability that matches the given element name. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.DistributedBundleFramework

**System API**

This is a system API.

**Parameters**

| Name     | Type                                        | Mandatory| Description                   |
| ----------- | -------------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundle-ElementName.md) | Yes  | **ElementName**.|

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)> | Promise used to return the remote ability information.|

## distributedBundle.getRemoteAbilityInfos<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md) instead.

getRemoteAbilityInfos(elementNames: Array&lt;ElementName&gt;, callback: AsyncCallback&lt;Array&lt;RemoteAbilityInfo&gt;&gt;): void

Obtains the information about remote abilities that match the given element names. This API uses an asynchronous callback to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.DistributedBundleFramework

**System API**

This is a system API.

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                              |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| elementNames | Array<[ElementName](js-apis-bundle-ElementName.md)>          | Yes  | **ElementName** array, whose maximum length is 10.                  |
| callback     | AsyncCallback< Array<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)>> | Yes  | Callback used to return an array of the remote ability information.|



## distributedBundle.getRemoteAbilityInfos<sup>deprecated<sup>

> This API is deprecated since API version 9. You are advised to use [getRemoteAbilityInfo(@ohos.bundle.distributedBundleManager)](js-apis-distributedBundleManager-sys.md) instead.

getRemoteAbilityInfos(elementNames: Array&lt;ElementName&gt;): Promise&lt;Array&lt;RemoteAbilityInfo&gt;&gt;

Obtains the information about remote abilities that match the given element names. This API uses a promise to return the result.

**Required permissions**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**

SystemCapability.BundleManager.DistributedBundleFramework

**System API**

This is a system API.

**Parameters**

| Name     | Type                                               | Mandatory| Description                 |
| ------------ | --------------------------------------------------- | ---- | ----------------------- |
| elementNames | Array<[ElementName](js-apis-bundle-ElementName.md)> | Yes  | **ElementName** array, whose maximum length is 10.|

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array<[RemoteAbilityInfo](js-apis-bundle-remoteAbilityInfo-sys.md)>> | Promise used to return an array of the remote ability information.|
