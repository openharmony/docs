# @ohos.enterprise.telephonyManager (Telephony Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **telephonyManager** module provides the telephony management capability.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>
> The global restriction policy is provided by **restrictions**. To disable telephony globally, see [@ohos.enterprise.restrictions (Restrictions)](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { telephonyManager } from '@kit.MDMKit';
```

## telephonyManager.setSimDisabled

setSimDisabled(admin: Want, slotId: number): void

Disables the SIM card in the specified slot. After being disabled, the SIM card in the specified slot cannot be used for making or receiving calls, sending or receiving SMSs, or accessing the internet. For example, an enterprise device administrator can disable the SIM card when an employee leaves the company or a device is lost, preventing unauthorized use. This is applicable in scenarios where enterprises need to restrict employee devices' communication capabilities, such as preventing SIM card misuse after employee departure or device loss, thereby ensuring enterprise communication security and cost control.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| slotId | number                     | Yes  | Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the ID of the slot to be disabled.
  let slotId: number = 0;
  // Disable the SIM card in the specified slot.
  telephonyManager.setSimDisabled(wantTemp, slotId);
  console.info(`Succeeded in setting slotId: ${slotId} disabled.`);
} catch (err) {
  console.error(`Failed to set slotId disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.setSimEnabled

setSimEnabled(admin: Want, slotId: number): void

Enables the SIM card in a specified slot. After it has been disabled with **setSimDisabled**, the card must be turned back on manually in **Settings** > **Mobile network** > **SIM management**, as this **setSimEnabled** API cannot re-enable it directly.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| slotId | number                     | Yes  |Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the ID of the slot to be enabled.
  let slotId: number = 0;
  // Enable the SIM card in the specified slot.
  telephonyManager.setSimEnabled(wantTemp, slotId);
  console.info(`Succeeded in setting slotId: ${slotId} enabled.`);
} catch (err) {
  console.error(`Failed to set slotId enabled. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.isSimDisabled

isSimDisabled(admin: Want, slotId: number): boolean

Checks whether the SIM card in a specified slot is disabled. This API is applicable in scenarios where enterprise administrators need to check whether the SIM card disablement policy has taken effect. It helps administrators confirm the policy enforcement status and ensure that call control policies are correctly implemented.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| slotId | number                     | Yes  |Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2. |

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| boolean | A Boolean value indicating the SIM card status in the specified slot. The value **true** means the SIM card in the specified slot is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the ID of the slot to be queried.
  let slotId: number = 0;
  // Check whether the SIM card in the specified slot is disabled.
  let result: boolean = telephonyManager.isSimDisabled(wantTemp, slotId);
  console.info(`Succeeded in querying slotId: ${slotId} is disabled or not, result: ${result}`);
} catch (err) {
  console.error(`Failed to query sim is disabled or not. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.addOutgoingCallPolicyNumbers

addOutgoingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

Adds the trustlist or blocklist for outgoing calls. If no list is set, all numbers can make outgoing calls. Once a list is added, only numbers on the list are allowed (or blocked) from making outgoing calls. For example, an enterprise can restrict employees to calling only customer service hotlines, or prohibit them from calling specific numbers.

A policy conflict is reported when this API is called in the following scenarios:

1. The device's call capability has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated), using this API to add an outgoing call trustlist or blocklist will return error code 203. To resolve the conflict, enable the call capability via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. If an outgoing call blocklist has been set via this API, using this API again to add an outgoing call trustlist will return error code 9200010. To resolve the conflict, remove the previously set blocklist via the [removeOutgoingCallPolicyNumbers](#telephonymanagerremoveoutgoingcallpolicynumbers) API.
3. If an outgoing call trustlist has been set via this API, using this API again to add an outgoing call blocklist will return error code 9200010. To resolve the conflict, remove the previously set trustlist via the [removeOutgoingCallPolicyNumbers](#telephonymanagerremoveoutgoingcallpolicynumbers) API.


**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                  |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | Yes  | Policy for trustlist or blocklist. **BLOCK_LIST** indicates a blocklist, and **TRUST_LIST** indicates a trustlist.  |
| numbers | Array\<string>    | Yes  | List of phone numbers. Currently, only full number matching is supported. The total length of the array must not exceed 1,000. For example, if there are already 100 numbers in the current trustlist array, this API supports adding up to 900 more numbers. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the policy type to blocklist.
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // Set the call numbers to be added to the blocklist.
  let numbers: Array<string> = [
    // Replace the value as required.
    "13112345678"
  ];
  // Add the outgoing call blocklist.
  telephonyManager.addOutgoingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in adding outgoing call policy.');
} catch (err) {
  console.error(`Failed to add outgoing call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.removeOutgoingCallPolicyNumbers

removeOutgoingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

Removes the trustlist or blocklist for outgoing calls. If the list is not set, the removal fails. For example, an enterprise can use this API when removing call restrictions and restoring normal call permissions for employees.

A policy conflict is reported when this API is called in the following scenario:

If the device's call capability has been disabled via the [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) API, using this API to remove an outgoing call trustlist or blocklist will return error code 203. To resolve the conflict, enable the call capability via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).


**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | Yes  | Policy for trustlist or blocklist. **BLOCK_LIST** indicates a blocklist, and **TRUST_LIST** indicates a trustlist.  |
| numbers | Array\<string>    | Yes  | List of call numbers to remove. The total length of the array must not exceed 1,000. |


**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the policy type to blocklist.
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // Set the call numbers to be removed from the blocklist.
  let numbers: Array<string> = [
    // Replace the value as required.
    "13112345678"
  ];
  // Remove specified numbers from the outgoing call blocklist.
  telephonyManager.removeOutgoingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in removing outgoing call policy.');
} catch (err) {
  console.error(`Failed to remove outgoing call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.getOutgoingCallPolicyNumbers

getOutgoingCallPolicyNumbers(admin: Want | null, policy: adminManager.Policy): Array\<string>

Obtains the trustlist or blocklist for outgoing calls.


**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | Yes  | Policy for trustlist or blocklist. **BLOCK_LIST** indicates a blocklist, and **TRUST_LIST** indicates a trustlist. |


**Return value**

| Type                                    | Description                   |
| ---------------------------------------- | ----------------------- |
| Array\<string> | An array of numbers in the outgoing call blocklist or trustlist.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the policy type to blocklist.
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // Obtain the outgoing call blocklist.
  let numbers: Array<string> = telephonyManager.getOutgoingCallPolicyNumbers(wantTemp, policy);
  console.info(`Succeeded in getting outgoing call policy. result: ${JSON.stringify(numbers)}`);
} catch (err) {
  console.error(`Failed to get outgoing call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.addIncomingCallPolicyNumbers

addIncomingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

Adds the trustlist or blocklist for incoming calls. If no list is set, all numbers can make incoming calls. Once a list is added, only numbers on the list are allowed (or blocked) from making incoming calls. For example, an enterprise can restrict employees to answering only calls from customers, or prohibit them from answering harassment calls.

A policy conflict is reported when this API is called in the following scenarios:

1. The device's call capability has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated), using this API to add an incoming call trustlist or blocklist will return error code 203. To resolve the conflict, enable the call capability via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. If an incoming call blocklist has been set via this API, using this API again to add an incoming call trustlist will return error code 9200010. To resolve the conflict, remove the previously set blocklist via the [removeIncomingCallPolicyNumbers](#telephonymanagerremoveincomingcallpolicynumbers) API.
3. If an incoming call trustlist has been set via this API, using this API again to add an incoming call blocklist will return error code 9200010. To resolve the conflict, remove the previously set trustlist via the [removeIncomingCallPolicyNumbers](#telephonymanagerremoveincomingcallpolicynumbers) API.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                  |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | Yes  | Policy for trustlist or blocklist. **BLOCK_LIST** indicates a blocklist, and **TRUST_LIST** indicates a trustlist.  |
| numbers | Array\<string>    | Yes  | List of phone numbers. Currently, only full number matching is supported. The total length of the array must not exceed 1,000. For example, if there are already 100 numbers in the current trustlist array, this API supports adding up to 900 more numbers. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the policy type to blocklist.
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // Set the call numbers to be added to the blocklist.
  let numbers: Array<string> = [
    // Replace the value as required.
    "13112345678"
  ];
  // Add the incoming call blocklist.
  telephonyManager.addIncomingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in adding incoming call policy.');
} catch (err) {
  console.error(`Failed to add incoming call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.removeIncomingCallPolicyNumbers

removeIncomingCallPolicyNumbers(admin: Want, policy: adminManager.Policy, numbers: Array\<string>): void

Removes the trustlist or blocklist for incoming calls. If the list is not set, the removal fails. For example, an enterprise can use this API when lifting incoming call restrictions and restoring employees' normal answering permissions.

A policy conflict is reported when this API is called in the following scenario:

1. If the device's call capability has been disabled via the [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) API, using this API to remove an incoming call trustlist or blocklist will return error code 203. To resolve the conflict, enable the call capability via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).


**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | Yes  | Policy for trustlist or blocklist. **BLOCK_LIST** indicates a blocklist, and **TRUST_LIST** indicates a trustlist.  |
| numbers | Array\<string>    | Yes  | List of call numbers to remove. The total length of the array must not exceed 1,000.  |


**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the policy type to blocklist.
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // Set the call numbers to be removed from the blocklist.
  let numbers: Array<string> = [
    // Replace the value as required.
    "13112345678"
  ];
  // Remove specified numbers from the incoming call blocklist.
  telephonyManager.removeIncomingCallPolicyNumbers(wantTemp, policy, numbers);
  console.info('Succeeded in removing incoming call policy.');
} catch (err) {
  console.error(`Failed to remove incoming call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.getIncomingCallPolicyNumbers

getIncomingCallPolicyNumbers(admin: Want | null, policy: adminManager.Policy): Array\<string>

Obtains the trustlist or blocklist for incoming calls.


**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|
| policy | [adminManager.Policy](js-apis-enterprise-adminManager.md#policy20)    | Yes  | Policy for trustlist or blocklist. **BLOCK_LIST** indicates a blocklist, and **TRUST_LIST** indicates a trustlist.  |


**Return value**

| Type                                    | Description                   |
| ---------------------------------------- | ----------------------- |
| Array\<string> | An array of numbers in the incoming call blocklist or trustlist.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Set the policy type to blocklist.
  let policy: adminManager.Policy = adminManager.Policy.BLOCK_LIST;
  // Obtain the incoming call blocklist.
  let numbers: Array<string> = telephonyManager.getIncomingCallPolicyNumbers(wantTemp, policy);
  console.info(`Succeeded in getting incoming call policy. result: ${JSON.stringify(numbers)}`);
} catch (err) {
  console.error(`Failed to get incoming call policy. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.hangupCalling<sup>23+</sup>

hangupCalling(admin: Want): void

Ends the current call. Only carrier calls are supported, excluding MeeTime calls. For example, an enterprise device administrator can forcibly hang up a non-compliant call that an employee is currently on in enterprise security management scenarios.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Hang up the current call.
  telephonyManager.hangupCalling(wantTemp);
} catch (err) {
  console.error(`Failed to hang up calling. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.activeSim

activeSim(admin: Want, slotId: number): void

Activates the SIM card in the specified slot. In scenarios where a SIM card is inserted but not yet activated, this API can be used to activate the SIM card without requiring manual user action. After the SIM card is activated, it can be used for communication. To successfully call this API, the SIM card must be inserted and airplane mode must be turned off.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| slotId | number                     | Yes  | Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201017  | SIM card activation or deactivation failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Set the ID of the slot to be activated.
let slotId: number = 0;
try {
  // Activate the SIM card in the specified slot.
  telephonyManager.activeSim(wantTemp, slotId);
  console.info(`success to active SIM`);
} catch (err) {
  console.error(`Failed to active SIM. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.deactiveSim

deactiveSim(admin: Want, slotId: number): void

Deactivates the SIM card in the specified slot. After deactivation, the SIM card in that slot cannot be used for making or receiving calls, sending or receiving SMSs, or accessing the internet. For example, an enterprise can temporarily deactivate a SIM card during employee leave or device maintenance. To successfully call this API, the SIM card must be inserted and airplane mode must be turned off.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| slotId | number                     | Yes  | Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201017  | SIM card activation or deactivation failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Set the ID of the slot to be deactivated.
let slotId: number = 0;
try {
  // Deactivate the SIM card in the specified slot.
  telephonyManager.deactiveSim(wantTemp, slotId);
  console.info(`success to deactive SIM`);
} catch (err) {
  console.error(`Failed to deactive SIM. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.setDefaultData

setDefaultData(admin: Want, slotId: number): void

Sets the SIM card in the specified slot as the default data SIM card. The device will use the data connection from the SIM card in that slot for internet access. For example, in dual-SIM device management scenarios, an enterprise can specify a default data SIM card for employee devices to centrally manage data usage. To successfully call this API, the SIM card must be inserted and airplane mode must be turned off.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| slotId | number                     | Yes  | Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201020  | Failed to set the default data SIM card. The airplane mode is enabled or no SIM card is inserted. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Set the slot ID of the SIM card to be used as the default data SIM card.
let slotId: number = 0;
try {
  // Sets the specified slot as the default data SIM.
  telephonyManager.setDefaultData(wantTemp, slotId);
  console.info(`success to set default data SIM ID`);
} catch (err) {
  console.error(`Failed to set default data. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.getDefaultData

getDefaultData(admin: Want): number

Obtains the slot ID of the SIM card currently used as the default data SIM card on the device. For example, an enterprise device administrator can query the current default data SIM during device management for data usage control or data card configuration switching. If no SIM card is inserted or the device is in airplane mode, the API returns the slot ID of the last used data SIM card. If the device has never had a default data SIM set, the API returns **0**, indicating slot 1.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| number | Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace the values as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Obtain the slot ID of the SIM card currently used as the default data SIM card.
  let slotId: number = telephonyManager.getDefaultData(wantTemp);
  console.info(`success to get default data SIM ID, current is ${slotId}`);
} catch (err) {
  console.error(`Failed to get default data. Code: ${err.code}, message: ${err.message}`);
}
```
