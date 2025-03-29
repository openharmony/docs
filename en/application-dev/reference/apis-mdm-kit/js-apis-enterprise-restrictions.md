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
| feature  | string                                                  | Yes  | Feature to set.<br>- **bluetooth**: Bluetooth capability of the device.<br>- **modifyDateTime**: capability of modifying the system time. Currently, this feature is available only for 2-in-1 devices.<br>- **printer**: printing capability. Currently, this feature is available only for 2-in-1 devices.<br>- **hdc**: OpenHarmony Device Connector (hdc).<br>- **microphone**: microphone capability of the device.<br>- **fingerprint**: fingerprint authentication capability of the device.<br>- **usb**: USB capability of the device. The external USB device cannot be used after this capability is disabled. That is, when the current device is in host mode, other external devices cannot be connected.<br> If you use this API to disable the USB capability of a device in the following scenarios, a policy conflict will be reported:<br>  1. Available USB devices are added using the [addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices) API.<br>  2. The access policy of the USB storage device is set to read-only or disabled through the [setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy) API.<br>- **wifi**: Wi-Fi capability of the device.<!--RP1--><!--RP1End--> |
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
