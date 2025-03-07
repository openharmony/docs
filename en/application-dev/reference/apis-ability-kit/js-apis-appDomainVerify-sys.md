# @ohos.bundle.appDomainVerify (Application Domain Name Verification) (System API)

The appDomainVerify module provides APIs to query the mappings between applications and domain names for the purposes of application domain name verification.

> **NOTE**
>
> The initial APIs of this module are supported since API version 13. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { appDomainVerify } from '@kit.AbilityKit';
```

## Required Permissions

| Permission                                   | APL   | Description            |
| --------------------------------------- | ----------- | ---------------- |
| ohos.permission.GET_APP_DOMAIN_BUNDLE_INFO | system_basic | Allows an application to access the mappings between applications and domain names.|

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

## appDomainVerify.queryAssociatedDomains

queryAssociatedDomains(bundleName: string): string[]

Queries the list of domain names associated with an application based on its bundle name.

**Required permissions**: ohos.permission.GET_APP_DOMAIN_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.AppDomainVerify

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| bundleName  | string | Yes   | Bundle name of the application.      |

**Returns**

| Type                       | Description                |
| ------------------------- | ------------------ |
| string[] | List of domain names associated with the bundle name. If no domain name is associated, an empty array is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Domain Name Verification Error Codes](errorcode-appDomainVerify.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error.|
| 29900001 | System internal error. |

**Example**

```ts
import { appDomainVerify } from '@kit.AbilityKit';

// Obtain the list of domain names associated with the bundle name "com.example.app1".
let bundleName = "com.example.app1";
let domains = appDomainVerify.queryAssociatedDomains(bundleName);
domains.forEach(domain => {
  console.log(`app:${bundleName} associate with domain:${domain}`);
});
```

## appDomainVerify.queryAssociatedBundleNames

queryAssociatedBundleNames(domain: string): string[]

Obtains the list of bundle names associated with a domain name.

**Required permissions**: ohos.permission.GET_APP_DOMAIN_BUNDLE_INFO

**System capability**: SystemCapability.BundleManager.AppDomainVerify

**System API**: This is a system API.

**Parameters**

| Name        | Type    | Mandatory  | Description                                     |
| ----------- | ------ | ---- | --------------------------------------- |
| domain  | string | Yes   | Domain name.      |

**Returns**

| Type                       | Description                |
| ------------------------- | ------------------ |
| string[] | List of bundle names associated with the domain name. If no application is associated, an empty array is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Application Domain Name Verification Error Codes](errorcode-appDomainVerify.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error.|
| 29900001 | System internal error. |

**Example**

```ts
import { appDomainVerify } from '@kit.AbilityKit';

// Obtain the list of bundle names associated with the domain name "example.com".
let domain = "example.com";
let bundleNames = appDomainVerify.queryAssociatedBundleNames(domain);
bundleNames.forEach(bundleName => {
  console.log(`domain:${domain} associate with app:${bundleName}`);
});
```
