# @ohos.enterprise.browser (Browser Management)

The **browser** module provides browser management, including setting, deleting, and obtaining browser policies.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { browser } from '@kit.MDMKit';
```

## browser.setPolicySync

setPolicySync(admin: Want, appId: string, policyName: string, policyValue: string): void

Sets a policy for a browser through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                                   | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| appId       | string                                                  | Yes  | Application ID, which is used to specify the browser.                                    |
| policyName  | string                                                  | Yes  | Name of the browser policy to set. If the value is an empty string, the browser policy corresponding to the application ID is set.|
| policyValue | string                                                  | Yes  | Browser policy to set. If the value is an empty string, the policy corresponding to the policy name is removed.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appId: string = 'com.example.myapplication';
let policyName: string = 'InsecurePrivateNetworkRequestsAllowed';
let policyValue: string = '{"level":"mandatory","scope":"machine","source":"platform","value":true}';

try {
  browser.setPolicySync(wantTemp, appId, policyName, policyValue);
  console.info('Succeeded in setting browser policies.');
} catch (err) {
  console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getPoliciesSync

getPoliciesSync(admin: Want, appId: string): string

Obtains the policies of a browser through the specified device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description                    |
| ------ | ------------------------------------------------------- | ---- | ------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.          |
| appId  | string                                                  | Yes  | Application ID, which is used to specify the browser.|

**Return value**

| Type  | Description        |
| ------ | ------------ |
| string | Browser policies obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appId: string = 'com.example.myapplication';

try {
  let result: string = browser.getPoliciesSync(wantTemp, appId);
  console.info(`Succeeded in getting browser policies, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
}
```
