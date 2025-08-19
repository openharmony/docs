# @ohos.enterprise.telephonyManager (Telephony Management)

The **telephonyManager** module provides the telephony management capability.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>
> - The global restriction policy is provided by **restrictions**. To disable telephony globally, see [@ohos.enterprise.restrictions (Restrictions)](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { telephonyManager } from '@kit.MDMKit';
```

## telephonyManager.setSimDisabled
setSimDisabled(admin: Want, slotId: number): void

Disables the SIM card in a specified slot.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| slotId | number                     | Yes  | Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2.|

**Error codes**

For details, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                      |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
try {
  let slotId: number = 0;
  telephonyManager.setSimDisabled(wantTemp, slotId);
  console.info(`Succeeded in setting slotId: ${slotId} disabled.`);
} catch (err) {
  console.error(`Failed to set slotId disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.setSimEnabled

setSimEnabled(admin: Want, slotId: number): void

Enables the SIM card in a specified slot.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| slotId | number                     | Yes  |Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2. |

**Error codes**

For details, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
try {
  let slotId: number = 0;
  telephonyManager.setSimEnabled(wantTemp, slotId);
  console.info(`Succeeded in setting slotId: ${slotId} enabled.`);
} catch (err) {
  console.error(`Failed to set slotId enabled. Code: ${err.code}, message: ${err.message}`);
}
```

## telephonyManager.isSimDisabled

isSimDisabled(admin: Want, slotId: number): boolean

Checks whether the SIM card in a specified slot is disabled.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_TELEPHONY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| slotId | number                     | Yes  |Slot ID. Currently, only single-slot and dual-slot devices are supported. The value can be **0** or **1**, where **0** indicates slot 1 and **1** indicates slot 2. |

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| boolean | A Boolean value indicating the SIM card status in the specified slot. The value **true** means the SIM card in the specified slot is disabled; the value **false** means the opposite.|

**Error codes**

For details, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { telephonyManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
try {
  let slotId: number = 0;
  let result: boolean = telephonyManager.isSimDisabled(wantTemp, slotId);
  console.info(`Succeeded in querying slotId: ${slotId} is disabled or not, result: ${result}`);
} catch (err) {
  console.error(`Failed to query sim is disabled or not. Code: ${err.code}, message: ${err.message}`);
}
```
