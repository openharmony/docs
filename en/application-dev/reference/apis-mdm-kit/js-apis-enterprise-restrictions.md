# @ohos.enterprise.restrictions (Restrictions)

This **restrictions** module provides APIs for disallowing general features of devices. You can globally disable or enable the features such as Bluetooth, HDC, USB, and Wi-Fi.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { restrictions } from '@kit.MDMKit';
```

## restrictions.setDisallowedPolicy

setDisallowedPolicy(admin: Want, feature: string, disallow: boolean): void

Disallows a feature.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS<sup>15+</sup>

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| feature  | string                                                  | Yes  | Feature to set.<br>- **bluetooth**: Bluetooth capability.<br>- **modifyDateTime**: capability of modifying the system time. Currently, this feature is available only for 2-in-1 devices.<br>- **printer**: printing capability. Currently, this feature is available only for 2-in-1 devices.<br>- **hdc**: OpenHarmony Device Connector (HDC).<br>- **microphone**: microphone capability.<br>- **fingerprint**: fingerprint authentication capability. If this capability has been disabled for a user using [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount14), a policy conflict will be reported when **setDisallowedPolicy** is invoked.<br>- **usb**: USB capability. After this capability is disabled, the external USB device cannot be used. This means that the current device in host mode cannot connect to other external devices.<br>A policy conflict will be reported if **setDisallowedPolicy** is called in the following three scenarios:<br>1. Available USB devices have been added via [addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices).<br>2. The access policy of the USB storage device has been set to read-only or disabled via [setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy).<br>3. Disallowed USB device types have been added via [addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14).<br>- **wifi**: Wi-Fi capability.<br>- **tethering**<sup>14+</sup>: network sharing capability. The device can share the network (hotspot) with other devices.<br>- **inactiveUserFreeze**<sup>14+</sup>: capability of freezing inactive users. Currently, this feature is available only for 2-in-1 devices. When the system switches to the enterprise space user, the personal space users are inactive users.<br>- **camera**<sup>14+</sup>: camera capability.<br>- **mtpClient**<sup>18+</sup>: MTP client capability. Currently, this feature is available only for 2-in-1 devices. The Media Transfer Protocol (MTP) allows users to access media files linearly on mobile devices.<br>- **mtpServer**<sup>18+</sup>: MTP server capability. Currently, this feature is available only for mobile phones, tablets, and 2-in-1 devices.<!--RP1--><!--RP1End--> <br> **NOTE**<br>Since API version 15, applications granted with the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and [activated as device administrator applications](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) can set the following features: **bluetooth**, **hdc**, **microphone**, **usb**, **wifi**, **tethering**, and **camera**<!--RP3--><!--RP3End-->.| disallow | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                       |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  restrictions.setDisallowedPolicy(wantTemp, 'printer', true);
  console.info('Succeeded in setting printer disabled');
} catch (err) {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicy

getDisallowedPolicy(admin: Want, feature: string): boolean

Obtains a disallowed feature.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS<sup>15+</sup>

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| feature | string                                                  | Yes  | Feature to set.<br>- **bluetooth**: Bluetooth capability.<br>- **modifyDateTime**: capability of modifying the system time. Currently, this feature is available only for 2-in-1 devices.<br>- **printer**: printing capability. Currently, this feature is available only for 2-in-1 devices.<br>- **hdc**: OpenHarmony Device Connector (HDC).<br>- **microphone**: microphone capability.<br>- **fingerprint**: fingerprint authentication capability.<br>- **usb**: USB capability. After this capability is disabled, the external USB device cannot be used. This means that the current device in host mode cannot connect to other external devices.<br>- **wifi**: Wi-Fi capability.<br>- **tethering**<sup>14+</sup>: network sharing capability. The device can share the network (hotspot) with other devices. Currently, this feature is available only for 2-in-1 devices.<br>- **inactiveUserFreeze**<sup>14+</sup>: capability of freezing inactive users. Currently, this feature is available only for 2-in-1 devices. When the system switches to the enterprise space user, the personal space users are inactive users.<br>- **camera**<sup>14+</sup>: camera capability.<br>- **mtpClient**<sup>18+</sup>: MTP client capability. Currently, this feature is available only for 2-in-1 devices. The Media Transfer Protocol (MTP) allows users to access media files linearly on mobile devices.<br>- **mtpServer**<sup>18+</sup>: MTP server capability. Currently, this feature is available only for mobile phones, tablets, and 2-in-1 devices.<!--RP2--><!--RP2End--> <br> **NOTE**<br>Since API version 15, applications granted with the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and [activated as device administrator applications](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) can obtain the following features: **bluetooth**, **hdc**, **microphone**, **usb**, **wifi**, **tethering**, and **camera**<!--RP4--><!--RP4End-->.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** means the feature is disallowed; the value **false** means the opposite.|

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

try {
  let result: boolean = restrictions.getDisallowedPolicy(wantTemp, 'printer');
  console.info(`Succeeded in querying is the printing function disabled : ${result}`);
} catch (err) {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setDisallowedPolicyForAccount<sup>14+</sup>

setDisallowedPolicyForAccount(admin: Want, feature: string, disallow: boolean, accountId: number): void

Disallows a feature for a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **fingerprint**: device fingerprint authentication capability. Currently, this feature is available only for 2-in-1 devices. The rules for using this parameter are as follows:<br>1. If this capability has been disabled through the [setDisallowedPolicy](#restrictionssetdisallowedpolicy) API, using **setDisallowedPolicyForAccount** will throw a policy conflict.<br>2. When **setDisallowedPolicyForAccount** is used to disable or enable the device fingerprint authentication capability for a specified user, any subsequent action via the [setDisallowedPolicy](#restrictionssetdisallowedpolicy) API will override the previous setting. If [setDisallowedPolicy](#restrictionssetdisallowedpolicy) enables the capability, all users gain access to the device fingerprint authentication.|
| disallow | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                       |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | the administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  restrictions.setDisallowedPolicyForAccount(wantTemp, 'fingerprint', true, 100);
  console.info('Succeeded in setting fingerprint disabled');
} catch (err) {
  console.error(`Failed to set fingerprint disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicyForAccount<sup>14+</sup>

getDisallowedPolicyForAccount(admin: Want, feature: string, accountId: number): boolean

Obtains the status of a feature for a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature | string                                                  | Yes  | Feature to set.<br>- **fingerprint**: device fingerprint authentication capability. Currently, this feature is available only for 2-in-1 devices. Note that when [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount14) is used to disable or enable the device fingerprint authentication capability for a specified user, any subsequent action via the [setDisallowedPolicy](#restrictionssetdisallowedpolicy) API will override the previous setting. The value **false** will be returned.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** means the feature is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | the administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: boolean = restrictions.getDisallowedPolicyForAccount(wantTemp, 'fingerprint', 100);
  console.info(`Succeeded in querying is the fingerprint function disabled : ${result}`);
} catch (err) {
  console.error(`Failed to set fingerprint disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.addDisallowedListForAccount<sup>14+</sup>

addDisallowedListForAccount(admin: Want, feature: string, list: Array\<string>, accountId: number): void

Adds a list of applications that are not allowed to use a feature for a specified user.  

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| list | Array\<string>                                                 | Yes  | List of content such as the bundle names.                     |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                   |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let valueList:Array<string> = ["com.xx.aa.", "com.xx.bb"];
try {
  restrictions.addDisallowedListForAccount(wantTemp, 'snapshotSkip', valueList, 100);
  console.info('Succeeded in adding disallowed snapshotSkip feature');
} catch (err) {
  console.error(`Failed to add disallowed snapshotSkip feature. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.removeDisallowedListForAccount<sup>14+</sup>

removeDisallowedListForAccount(admin: Want, feature: string, list: Array\<string>, accountId: number): void

Removes the list of applications that are not allowed to use a feature for a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| list | Array\<string>                                                 | Yes  | List of content such as the bundle names.                      |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                    |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let valueList:Array<string> = ["com.xx.aa.", "com.xx.bb"];
try {
  restrictions.removeDisallowedListForAccount(wantTemp, 'snapshotSkip', valueList, 100);
  console.info('Succeeded in removing disallowed snapshotSkip feature');
} catch (err) {
  console.error(`Failed to remove disallowed snapshotSkip feature. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedListForAccount<sup>14+</sup>

getDisallowedListForAccount(admin: Want, feature: string, accountId: number): Array\<string>

Obtains the list of applications that are not allowed to use a feature for a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| Array\<string> | List of applications that have been added by the user and for which a certain feature is disabled.|

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

try {
  let result: Array<string> = restrictions.getDisallowedListForAccount(wantTemp, 'snapshotSkip', 100);
  console.info('Succeeded in querying disallowed list for account');
} catch (err) {
  console.error(`Failed to query disallowed list for account. Code is ${err.code}, message is ${err.message}`);
}
```
