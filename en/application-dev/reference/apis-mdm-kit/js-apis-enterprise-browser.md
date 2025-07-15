# @ohos.enterprise.browser (Browser Management)

The **browser** module provides browser management, including setting, canceling, and obtaining browser policies.

Browser policies are a collection of rules and settings that govern how a browser behaves, ensuring security, compliance, performance optimization, and a consistent user experience.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { browser } from '@kit.MDMKit';
```

## browser.setPolicySync

setPolicySync(admin: Want, appId: string, policyName: string, policyValue: string): void

Sets the sub-policy for a specified browser.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                                   | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
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

// Replace the value of appId with the specified application ID of the browser.
let appId: string = 'com.example.******_******/******5t5CoBM=';
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

Obtains the policy set for a specified browser.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description                    |
| ------ | ------------------------------------------------------- | ---- | ------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.          |
| appId  | string                                                  | Yes  | Application ID, which is used to specify the browser.|

**Return value**

| Type  | Description        |
| ------ | ------------ |
| string | Browser policy obtained.|

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

// Replace the value of appId with the specified application ID of the browser.
let appId: string = 'com.example.******_******/******5t5CoBM=';

try {
  let result: string = browser.getPoliciesSync(wantTemp, appId);
  console.info(`Succeeded in getting browser policies, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.setManagedBrowserPolicy<sup>15+</sup>

setManagedBrowserPolicy(admin: Want, bundleName: string, policyName: string, policyValue: string): void

Sets the browser policy. After the setting is successful, the system common event [BROWSER_POLICY_CHANGED_EVENT](../apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_managed_browser_policy_changed) is released.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BROWSER_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                                   | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| bundleName  | string                                                  | Yes  | Application bundle name, which is used to specify the browser.                                    |
| policyName  | string                                                  | Yes  | Browser policy name.|
| policyValue | string                                                  | Yes  | Browser policy value. If the value is an empty string, the policy corresponding to the policy name is removed.|

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
let bundleName: string = 'com.example.testbrowser';
let policyName: string = 'InsecurePrivateNetworkRequestsAllowed';
let policyValue: string = '{"level":"mandatory","scope":"machine","source":"platform","value":true}';

try {
  browser.setManagedBrowserPolicy(wantTemp, bundleName, policyName, policyValue);
  console.info('Succeeded in setting managed browser policy.');
} catch (err) {
  console.error(`Failed to set managed browser policy. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getManagedBrowserPolicy<sup>15+</sup>

getManagedBrowserPolicy(admin: Want, bundleName: string): ArrayBuffer

Obtains the policy of a specified browser.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name     | Type                                                   | Mandatory| Description                    |
| ----------- | ------------------------------------------------------- | ---- | ------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.          |
| bundleName  | string                                                  | Yes  | Application bundle name, which is used to specify the browser.|

**Return value**

| Type       | Description        |
| ----------- | ------------ |
| ArrayBuffer | Browser policy obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { util } from '@kit.ArkTS';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleName: string = 'com.example.testbrowser';

try {
  let buffer: ArrayBuffer = browser.getManagedBrowserPolicy(wantTemp, bundleName);
  let intBuffer: Uint8Array = new Uint8Array(buffer);
  let decoder: util.TextDecoder = util.TextDecoder.create('utf-8');
  let stringData: string = decoder.decodeToString(intBuffer);
  console.info(`Succeeded in getting managed browser policy, result : ${stringData}`);
} catch(err) {
  console.error(`Failed to get managed browser policy. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getSelfManagedBrowserPolicyVersion<sup>15+</sup>

getSelfManagedBrowserPolicyVersion(): string

Obtains the policy version of a specified browser.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Return value**

| Type   | Description        |
| ------ | ------------ |
| string | Browser policy version.|

**Example**

```ts

try {
  let version: string = browser.getSelfManagedBrowserPolicyVersion();
  console.info(`Succeeded in getting self managed browser policy version, result : ${version}`);
} catch(err) {
  console.error(`Failed to get self managed browser policy version. Code is ${err.code}, message is ${err.message}`);
}
```

## browser.getSelfManagedBrowserPolicy<sup>15+</sup>

getSelfManagedBrowserPolicy(): ArrayBuffer

Obtains the policy of a specified browser.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Return value**

| Type       | Description        |
| ----------- | ------------ |
| ArrayBuffer | Browser policy obtained.|

**Example**

```ts
import { util } from '@kit.ArkTS';

try {
  let buffer: ArrayBuffer = browser.getSelfManagedBrowserPolicy();
  let intBuffer: Uint8Array = new Uint8Array(buffer);
  let decoder: util.TextDecoder = util.TextDecoder.create('utf-8');
  let stringData: string = decoder.decodeToString(intBuffer);
  console.info(`Succeeded in getting self managed browser policy, result : ${stringData}`);
} catch(err) {
  console.error(`Failed to get self managed browser policy. Code is ${err.code}, message is ${err.message}`);
}
```
