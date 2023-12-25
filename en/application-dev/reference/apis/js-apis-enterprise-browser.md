# @ohos.enterprise.browser (Browser Management)

The **browser** module provides browser management, including setting, deleting, and obtaining browser policies.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import browser from '@ohos.enterprise.browser';
```

## browser.setPolicies

setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback&lt;void&gt;): void

Sets policies for a given browser through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |
| policies    | string              | Yes   | Policies to set. If this parameter is set to an empty string, the policies of the specified browser will be deleted. |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appId: string = 'com.example.myapplication';
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}';
browser.setPolicies(wantTemp, appId, policies, (err) => {
  if (err) {
    console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting browser policies');
});
```

## browser.setPolicies

setPolicies(admin: Want, appId: string, policies: string): Promise&lt;void&gt;

Sets policies for a given browser through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |
| policies    | string                | Yes   | Policies to set. If this parameter is set to an empty string, the policies of the specified browser will be deleted.  |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object is thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appId: string = 'com.example.myapplication';
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}';
browser.setPolicies(wantTemp, appId, policies).then(() => {
  console.info('Succeeded in setting browser policies');
}).catch((err: BusinessError) => {
  console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
});
```

## browser.getPolicies

getPolicies(admin: Want, appId: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the policies of a given browser through the specified device administrator application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |
| callback | AsyncCallback&lt;string&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appId: string = 'com.example.myapplication';
browser.getPolicies(wantTemp, appId, (err, result) => {
  if (err) {
    console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting  browser policies, result : ${JSON.stringify(result)}`);
});
```

## browser.getPolicies

getPolicies(admin: Want, appId: string): Promise&lt;string&gt;

Obtains the policies of a given browser through the specified device administrator application. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| appId    | string              | Yes   | Application ID, which is used to specify the browser.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the browser policies obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appId: string = 'com.example.myapplication';
browser.getPolicies(wantTemp, appId).then((result) => {
  console.info(`Succeeded in getting browser policies, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
});
```
