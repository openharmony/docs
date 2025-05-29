# @ohos.enterprise.restrictions (Restrictions)

This **restrictions** module provides APIs for disallowing general features of devices. You can globally disable or enable the features such as Bluetooth, HDC, USB, and Wi-Fi.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

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
| feature  | string                                                  | Yes  | Feature to set.<br>- **bluetooth**: Bluetooth capability of the device.<br>- **modifyDateTime**: capability of modifying the system time. Currently, this feature is available only for 2-in-1 devices.<br>- **printer**: printing capability. Currently, this feature is available only for 2-in-1 devices.<br>- **hdc**: OpenHarmony Device Connector (hdc).<br>- **microphone**: microphone capability of the device.<br>- **fingerprint**: fingerprint authentication capability of the device. If the fingerprint authentication capability has been disabled for a user using [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount14), a policy conflict will be reported when this API is invoked to enable the fingerprint authentication capability.<br>- **usb**: USB capability of the device. The external USB device cannot be used after this capability is disabled. That is, when the current device is in host mode, other external devices cannot be connected.<br>  If you use this API to disable the USB capability of a device in the following scenarios, a policy conflict will be reported:<br>  1. Available USB devices are added using the [addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices) API.<br>  2. The access policy of the USB storage device is set to read-only or disabled through the [setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy) API.<br>  3. A forbidden USB device type is added using the [addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14) API.<br>- **wifi**: Wi-Fi capability of the device.<br>- **tethering**<sup>14+</sup>: network sharing capability. Currently, this feature is available only for 2-in-1 devices.<br>- **inactiveUserFreeze**<sup>14+</sup>: capability of freezing inactive users. Currently, this feature is available only for 2-in-1 devices. When the system switches to the enterprise space user, the personal space users are inactive users.<br>- **camera**<sup>14+</sup>: camera capability of the device.<br>- mtpClient<sup>18+</sup>: MTP client capability. Currently, this feature is available only for 2-in-1 devices. The Media Transfer Protocol (MTP) allows users to access media files linearly on mobile devices.<br>- mtpServer<sup>18+</sup>: MTP server capability. Currently, this feature is available only for mobile phones, tablets, and 2-in-1 devices.<!--RP1--><!--RP1End--> <br> Note: Since API version 15, an application must request the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and call [adminManager.startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) to set the features including **bluetooth**, **hdc**, **microphone**, **usb**, **wifi**, **tethering**, and **camera**.|
| disallow | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                       |

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
  restrictions.setDisallowedPolicy(wantTemp, 'printer', true);
  console.info('Succeeded in setting printer disabled');
} catch (err) {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicy

getDisallowedPolicy(admin: Want, feature: string): boolean

Obtains a disabled feature.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS<sup>15+</sup>

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| feature | string                                                  | Yes  | Feature to set.<br>- **bluetooth**: Bluetooth capability of the device.<br>- **modifyDateTime**: capability of modifying the system time. Currently, this feature is available only for 2-in-1 devices.<br>- **printer**: printing capability. Currently, this feature is available only for 2-in-1 devices.<br>- **hdc**: OpenHarmony Device Connector (hdc).<br>- **microphone**: microphone capability of the device.<br>- **fingerprint**: fingerprint authentication capability of the device.<br>- **usb**: USB capability of the device. External USB devices cannot be used after this capability is disabled. That is, when the current device is in host mode, other external devices cannot be connected.<br>- **wifi**: Wi-Fi capability of the device.<br>- **tethering**<sup>14+</sup>: network sharing capability. Currently, this feature is available only for 2-in-1 devices.<br>- **inactiveUserFreeze**<sup>14+</sup>: capability of freezing inactive users. Currently, this feature is available only for 2-in-1 devices. When the system switches to the enterprise space user, the personal space users are inactive users.<br>- **camera**<sup>14+</sup>: camera capability of the device.<br>- mtpClient<sup>18+</sup>: MTP client capability. Currently, this feature is available only for 2-in-1 devices. The Media Transfer Protocol (MTP) allows users to access media files linearly on mobile devices.<br>- mtpServer<sup>18+</sup>: MTP server capability. Currently, this feature is available only for mobile phones, tablets, and 2-in-1 devices.<!--RP2--><!--RP2End--> <br> Note: Since API version 15, an application must request the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and call [adminManager.startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) to set the features including **bluetooth**, **hdc**, **microphone**, **usb**, **wifi**, **tethering**, and **camera**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the feature is disallowed; returns **false** otherwise.|

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

Enables or disables a feature of a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **fingerprint**: device fingerprint authentication capability. Currently, this feature is available only for 2-in-1 devices. The rules for using this parameter are as follows:<br>1. The device fingerprint authentication capability is disabled through the [setDisallowedPolicy](#restrictionssetdisallowedpolicy) API. If this parameter is transferred through this API, a policy conflict is reported.<br>2. After this API is used to disable or enable the device fingerprint authentication capability of a specified user, if the [setDisallowedPolicy](#restrictionssetdisallowedpolicy) API is used to disable the device fingerprint authentication capability, the latter will overwrite the former. All users can use the device fingerprint authentication capability enabled by the [setDisallowedPolicy](#restrictionssetdisallowedpolicy) API.|
| disallow | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                       |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call the [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) API to obtain the user ID.|

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

Obtains the status of a feature of a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature | string                                                  | Yes  | Feature to set.<br>- **fingerprint**: device fingerprint authentication capability. Currently, this feature is available only for 2-in-1 devices. When this parameter is used, the following rules apply: After [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount14) is used to disable or enable the device fingerprint authentication capability of a specified user, if the [setDisallowedPolicy](#restrictionssetdisallowedpolicy) API is used to disable the device fingerprint authentication capability, the latter will overwrite the former. And the calling result is **false**.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) to obtain the user ID.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | If **true** is returned, the feature is disabled. If **false** is returned, the feature is not disabled.|

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

Add a list of applications that are not allowed to use a feature for a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| list | Array\<string>                                                 | Yes  | List of content such as the bundle names.                     |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call the [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) API to obtain the user ID.|

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

Removes a list of applications that are not allowed to use a feature for a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| list | Array\<string>                                                 | Yes  | List of content such as the bundle names.                      |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>You can call the [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) API to obtain the user ID.|

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
