# @ohos.enterprise.browser (Browser Management) (System API)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **browser** module provides browser management, including setting, canceling, and obtaining browser policies.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module are available only to the [MDM application](../../mdm/mdm-kit-term.md#mdm-application-device-administrator-application), and can be called only after the device administrator application is activated via [enableAdmin](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2).
> 
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.browser](js-apis-enterprise-browser.md).

## Modules to Import

```ts
import { browser } from '@kit.MDMKit';
```

## browser.setPolicies<sup>(deprecated)</sup>

setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback&lt;void&gt;): void

Sets the browsing policy for a specified browser. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [setPolicySync](./js-apis-enterprise-browser.md#browsersetpolicysync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.           |
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |
| policies    | string              | Yes   | Policies to set. If this parameter is set to an empty string, the policies of the specified browser are canceled.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace the value of appId with the specified application ID of the browser.
let appId: string = 'com.example.******_******/******5t5CoBM=';
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}';
browser.setPolicies(wantTemp, appId, policies, (err) => {
  if (err) {
    console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting browser policies.');
});
```

## browser.setPolicies<sup>(deprecated)</sup>

setPolicies(admin: Want, appId: string, policies: string): Promise&lt;void&gt;

Sets the browsing policy for a specified browser. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [setPolicySync](./js-apis-enterprise-browser.md#browsersetpolicysync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.           |
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |
| policies    | string                | Yes   | Policies to set. If this parameter is set to an empty string, the policies of the specified browser are canceled.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object is thrown when the browser policy fails to be set. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace the value of appId with the specified application ID of the browser.
let appId: string = 'com.example.******_******/******5t5CoBM=';
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}';
browser.setPolicies(wantTemp, appId, policies).then(() => {
  console.info('Succeeded in setting browser policies.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
});
```

## browser.getPolicies<sup>(deprecated)</sup>

getPolicies(admin: Want, appId: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the policy of the specified browser. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getPoliciesSync](./js-apis-enterprise-browser.md#browsergetpoliciessync)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.           |
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |
| callback | AsyncCallback&lt;string&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace the value of appId with the specified application ID of the browser.
let appId: string = 'com.example.******_******/******5t5CoBM=';
browser.getPolicies(wantTemp, appId, (err, result) => {
  if (err) {
    console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting  browser policies, result : ${JSON.stringify(result)}`);
});
```

## browser.getPolicies<sup>(deprecated)</sup>

getPolicies(admin: Want, appId: string): Promise&lt;string&gt;

Obtains the policy of the specified browser. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getPoliciesSync](./js-apis-enterprise-browser.md#browsergetpoliciessync)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the browser policies obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { browser } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace the value of appId with the specified application ID of the browser.
let appId: string = 'com.example.******_******/******5t5CoBM=';
browser.getPolicies(wantTemp, appId).then((result) => {
  console.info(`Succeeded in getting browser policies, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
});
```
