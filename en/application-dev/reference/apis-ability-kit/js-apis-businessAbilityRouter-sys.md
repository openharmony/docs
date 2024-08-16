# @ohos.app.businessAbilityRouter (Business Ability Router) (System API)

The **businessAbilityRouter** module provides APIs for you to query the business ability information of applications installed on the device. It provides a unified template for you to register standard services by type. Based on the information, a system application or third-party application can obtain services that meet certain criteria and select a proper service. The module also provides unified rules to manage redirection between applications and services. It prevents arbitrary switching between the foreground and background and avoids the distribution of third-party applications by means of redirection.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>The APIs provided by this module are system APIs.

## Modules to Import

``` ts
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';
```

## Required Permissions

| Permission                                      | APL    | Description                |
| ------------------------------------------ | ------------ | -------------------- |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | Permission to query information about all bundles. |

For details about the APL, see [Basic Concepts in the Permission Mechanism](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

## BusinessType

Enumerates the types of business abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name       | Value  | Description                                |
| ----------- | ---- | ------------------------------------ |
| SHARE       | 0    | Business ability of the share type. |
| UNSPECIFIED | 255  | Business ability of an unspecified type.  |

## BusinessAbilityFilter

Describes the criteria for filtering business abilities.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name        | Type        | Read-only | Mandatory | Description                                  |
| ------------ | ------------ | ---- | ---- | -------------------------------------- |
| businessType | [BusinessType](#businesstype) | No  | Yes  | Type of the business ability.          |
| mimeType     | string       | No  | No  | MIME type supported by the business ability. |
| uri          | string       | No  | No  | URI supported by the business ability.       |

## businessAbilityRouter.queryBusinessAbilityInfo

queryBusinessAbilityInfo(filter: BusinessAbilityFilter, callback: AsyncCallback\<Array\<BusinessAbilityInfo\>\>): void;

Obtains the business ability information based on the specified filter criteria. This API uses an asynchronous callback to return the result. If the operation is successful, the business ability information is returned; otherwise, an error object is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name      | Type    | Mandatory  | Description                                   |
| ----------- | ------ | ---- | --------------------------------------- |
| filter | [BusinessAbilityFilter](#businessabilityfilter) | Yes   | Object used to filter the business abilities. |
| callback | AsyncCallback\<Array\<[BusinessAbilityInfo](js-apis-bundleManager-businessAbilityInfo-sys.md#businessabilityinfo)\>\> | Yes | Callback used to return the result. If the operation is successful, the business ability information that meets the filter criteria is returned; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**Example**

```ts
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';
import { BusinessError } from '@ohos.base';

let filter: businessAbilityRouter.BusinessAbilityFilter = {businessType: businessAbilityRouter.BusinessType.SHARE};

try {
    businessAbilityRouter.queryBusinessAbilityInfo(filter, (error, data) => {
        if (error) {
            console.error('queryBusinessAbilityInfo failed ' + error.message);
            return;
        }
        console.info('queryBusinessAbilityInfo success');
    });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('queryBusinessAbilityInfo failed ' + message);
}
```

## businessAbilityRouter.queryBusinessAbilityInfo

queryBusinessAbilityInfo(filter: BusinessAbilityFilter): Promise\<Array\<BusinessAbilityInfo\>\>;

Obtains the business ability information based on the specified filter criteria. This API uses a promise to return the result. If the operation is successful, the business ability information is returned; otherwise, an error object is returned.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name      | Type                             | Mandatory  | Description                                   |
| ----------- | ------------------------------- | ---- | --------------------------------------- |
| filter | [BusinessAbilityFilter](#businessabilityfilter) | Yes   | Object used to filter the business abilities. |

**Return value**

| Type                                                        | Description                                       |
| ------------------------------------------------------------ | ------------------------------------------- |
| Promise\<Array\<[BusinessAbilityInfo](js-apis-bundleManager-businessAbilityInfo-sys.md#businessabilityinfo)\>\> | Promise used to return the business ability information that meets the filter criteria. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**Example**

```ts
import businessAbilityRouter from '@ohos.app.businessAbilityRouter';
import { BusinessError } from '@ohos.base';

let filter: businessAbilityRouter.BusinessAbilityFilter = {businessType: businessAbilityRouter.BusinessType.SHARE};

try {
    businessAbilityRouter.queryBusinessAbilityInfo(filter)
        .then(() => {
            console.info('queryBusinessAbilityInfo success');
        }).catch((error: BusinessError) => {
            console.error('queryBusinessAbilityInfo failed ' + error.message);
        });
} catch (error) {
    let message = (error as BusinessError).message;
    console.error('queryBusinessAbilityInfo failed ' + message);
}
```
