# @ohos.enterprise.restrictions (Restrictions)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This **restrictions** module provides APIs for disallowing general features of devices. You can globally disable and re-enable features such as Bluetooth, HDC, USB, Wi-Fi, cellular data, camera, and microphone.

**Use cases**
- In enterprise device management scenarios, administrators need to restrict functions on employee devices to prevent data leaks or unauthorized use.
- In Bring Your Own Device (BYOD) scenarios, the enterprise space needs to restrict device functions to comply with enterprise security policies.
- In device security control scenarios, specific functions need to be disabled to protect sensitive enterprise information.

**Problems that can be solved**
- Prevent employees from transferring sensitive enterprise data via Bluetooth, USB, or other means.
- Restrict device debugging capabilities (HDC) to enhance device security.
- Control network access (Wi-Fi, cellular data, and so on) to comply with enterprise network policies.
- Manage device multimedia capabilities (camera, microphone, and so on) to protect privacy and enterprise confidentiality

**Benefits**
- Enhance enterprise device security and reduces the risk of data leaks.
- Meet compliance requirements and align with security audit standards.
- Enable fine-grained device function control, balancing security and user experience.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { restrictions } from '@kit.MDMKit';
```

## restrictions.setDisallowedPolicy<sup>(deprecated)</sup>

setDisallowedPolicy(admin: Want, feature: string, disallow: boolean): void

Disallows a feature.

> **NOTE**
> 
> This API applies a device-level restriction policy that affects all users of the device. To set a restriction policy for a specific user, use the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated) API.

**Since:** 12

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.setDisallowedPolicy](#restrictionssetdisallowedpolicy24)

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS, ohos.permission.PERSONAL_MANAGE_RESTRICTIONS<sup>15+</sup>, or ohos.permission.ENTERPRISE_MANAGE_NETWORK (The required permissions vary depending on the feature to be set. For details, see Table 1.)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| feature  | string                                                  | Yes  | For features that can be set, see Table 1.<br> **Note:** Since API version 15, applications granted with the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and activated as the [BDA](../../mdm/mdm-kit-term.md#byod-device-admin-bdabyod) via [startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) can use this API to set the following features: bluetooth, hdc, microphone, usb, wifi, tethering, and camera<!--RP3--><!--RP3End-->. Since API version 26.0.0, this API can also be used to set the mtpServer feature.|
| disallow | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                       |

**Table 1 Supported features**
|Feature|Description|Required Permission|
|--------------|---------------------|--------------|
|bluetooth|Device Bluetooth capability. If a Bluetooth device blocklist or trustlist is configured via [addDisallowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanageradddisallowedbluetoothdevices20) or [addAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanageraddallowedbluetoothdevices), disabling Bluetooth via this API takes priority. The blocklist or trustlist will only take effect after Bluetooth is re-enabled.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|modifyDateTime|Device capability to modify system time.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|printer|Device printing capability, which is supported only on PCs/2-in-1 devices for API versions earlier than 23, and on PCs/2-in-1 devices, smartphones, and tablets for API version 23 and later versions. When this API has disabled the device printing capability, enabling printing for a specific user via the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated) API will not take effect. The printing capability remains disabled for that user.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|hdc|Capability for other devices to connect to and debug this device via HDC. Disabling this capability prevents external devices from connecting or debugging via HDC.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|microphone|Device microphone capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|fingerprint|Device fingerprint authentication capability. Calling this API will trigger a policy conflict if fingerprint authentication has already been disabled for a user via [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated).|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|usb|Device USB capability. Disabling this capability prohibits the use of external USB devices (the device cannot act as a USB host to connect external devices).<br>A policy conflict occurs in the following scenarios:<br>1. A list of allowed USB devices has been configured via the [addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices) API.<br>2. USB storage device access policy has been set to read-only or disabled via the [setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy) API.<br>3. Specific USB device types have been blocked via the [addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14) API.<br>4. USB storage write has been disabled for specific users via the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated) API.<br>5. The USB-to-serial port has been disabled via the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API (with the **feature** parameter set to **usbSerial**).|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|wifi|Device Wi-Fi capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|tethering<sup>14+</sup>|Network tethering capability (the ability to share the device's internet connection with other devices, that is, hotspot sharing).|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|inactiveUserFreeze<sup>14+</sup>|Capability of freezing inactive users. When this capability is disabled, non-**UIAbility** processes will generally not be frozen, and background tasks requested by **UIAbility** (such as transient tasks, continuous tasks, deferred tasks, or energy efficiency resources) will also not be frozen. Currently, this capability is supported only on PCs/2-in-1 devices. When the system switches to the enterprise space user, the personal space users are inactive users.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|camera<sup>14+</sup>|Device camera capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|mtpClient<sup>18+</sup>|Media Transfer Protocol (MTP) client capability (including read and write capabilities), currently supported only on PC/2-in-1 devices. MTP allows users to linearly access media files on mobile devices. A policy conflict occurs if this API is used to disable MTP client capability after MTP client write access has been disabled for specific users via [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated).|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|mtpServer<sup>18+</sup>|MTP server capability, currently supported only on phone and tablets.|Before API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS; Since API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|sambaClient<sup>20+</sup>|Samba client capability, currently supported only on PC/2-in-1 devices. <br>Samba is a free software that implements the SMB protocol on Linux and UNIX systems, consisting of both server and client programs. Server Message Block (SMB) is a communication protocol for sharing files and printers over the local area network (LAN). It provides resource-sharing services, such as files and printers, among different computers within the LAN. As a client/server protocol, SMB allows clients to access shared resources hosted on servers.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|sambaServer<sup>20+</sup>|Samba server capability, currently supported only on PC/2-in-1 devices.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|backupAndRestore<sup>20+</sup>|Backup and restore capability. If this feature is disabled, the **Settings** > **System** > **Backup & Restore** and **Settings** > **Cloud** options will be dimmed. Currently, this feature is supported only on phones and tablets. To completely disable the backup and restore capability, you are advised to call [applicationManager.addDisallowedRunningBundlesSync](./js-apis-enterprise-applicationManager.md#applicationmanageradddisallowedrunningbundlessync) to disable applications with this feature, such as Backup & Restore, HiSuite, and Cloud.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|maintenanceMode<sup>20+</sup>|Device maintenance mode capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|mms<sup>20+</sup>|Multimedia Messaging Service (MMS) capability to receive and send multimedia messages. Currently, this feature is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|sms<sup>20+</sup>|Short Messaging Service (SMS) capability to receive and send SMS messages. Currently, this feature is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|mobileData<sup>20+</sup>|Cellular data capability, which is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_NETWORK|
|airplaneMode<sup>20+</sup>|Airplane mode capability, which is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_NETWORK|
|vpn<sup>20+</sup>|Virtual Private Network (VPN) capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|notification<sup>20+</sup>|Device notification capability. After this capability is disabled, notifications sent by system applications and third-party applications will not be displayed. However, notification capabilities for system services are not affected. If this API is used to disable the device-level notification capability after an allowed notification bundle has already been set via [addAllowedNotificationBundles](./js-apis-enterprise-applicationManager.md#applicationmanageraddallowednotificationbundles), error code 9200010 will be thrown.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|nfc<sup>20+</sup>|Near Field Communication (NFC) capability, which is supported only on phones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|privateSpace<sup>20+</sup>|Privacy space creation capability, which is supported only on smartphones and tablets. This setting does not affect existing private spaces.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|telephoneCall<sup>20+</sup>|Call capability. Disabling this feature blocks incoming or outgoing calls. Currently, this feature is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|appClone<sup>21+</sup>|[Application clone capability](../../quick-start/app-clone.md). When this feature is disabled, new application clones cannot be created. This feature is invalid for the application clone that has been created.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|externalStorageCard<sup>21+</sup> |External storage capability. Disabling this feature prohibits the use of external storage and unmounts currently connected external storage. If files are in use during unmounting, unmounting may fail with error code 9200013.<br>After external storage is disabled and then enabled again, you need to manually reconnect the external storage.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|randomMac<sup>21+</sup>|Random MAC address capability for Wi-Fi connections. When this feature is disabled, only the device's physical MAC address can be used for Wi-Fi connections.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|unmuteDevice<sup>22+</sup>|Device audio playback capability. When this feature is disabled, media playback will be muted, while [cellular calls](../../media/audio/audio-call-overview.md) remain unaffected.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|hdcRemote<sup>22+</sup>|Capability of the device to debug other devices through HDC. Currently, this feature can be set only for PCs/2-in-1 devices. Disabling this capability prevents debugging smartphones, tablets, PCs, smart watches, and other devices via HDC.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|virtualService<sup>23+</sup>|Device virtualization service capability, which refers to the system capability of running other operating system platforms (such as Linux and Windows) through virtualization technology by leveraging the redundancy of the device's hardware resources. If this capability is disabled, it is advised to uninstall all applications related to the virtualization service and prohibit their reinstallation.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|usbSerial<sup>24+</sup>|Device USB-to-serial port capability. After the capability is disabled, external USB-to-serial port devices will be unavailable. A policy conflict occurs in the following scenarios:<br>1. A list of allowed USB devices has been configured via the [addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices) API.<br>2. The USB device has been disabled via [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) (with the **feature** parameter set to **usb**).|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
<!--RP1--><!--RP1End-->

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200013  | The enterprise management policy has been successfully set, but the function has not taken effect in real time. <br>Applicable versions: 21+|
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  restrictions.setDisallowedPolicy(wantTemp, 'printer', true);
  console.info('Succeeded in setting printer disabled');
} catch (err) {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicy<sup>(deprecated)</sup>

getDisallowedPolicy(admin: Want \| null, feature: string): boolean

Queries whether a feature is disabled.

**Since:** 12

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.getDisallowedPolicy](#restrictionsgetdisallowedpolicy24)

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS, ohos.permission.PERSONAL_MANAGE_RESTRICTIONS<sup>15+</sup>, or ohos.permission.ENTERPRISE_MANAGE_NETWORK (The required permissions vary depending on the feature to be queried. For details, see Table 2.)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| feature | string                                                  | Yes  | For features that can be queried, see Table 2.<br> **Note:** Since API version 15, applications granted with the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and activated as the [BDA](../../mdm/mdm-kit-term.md#byod-device-admin-bdabyod) via [startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) can use this API to obtain the status of the following features: bluetooth, hdc, microphone, usb, wifi, tethering, and camera<!--RP4--><!--RP4End-->. Since API version 26.0.0, this API can also be used to obtain the status of the mtpServer feature.|

**Table 2** Features that can be queried
|Feature|Description|Required Permission|
|--------------|---------------------|--------------|
|bluetooth|Device Bluetooth capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|modifyDateTime|Device capability to modify system time.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|printer|Device printing capability, which is supported only on PCs/2-in-1 devices for API versions earlier than 23, and on PCs/2-in-1 devices, smartphones, and tablets for API version 23 and later versions.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|hdc|Capability for other devices to connect to and debug this device via HDC.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|microphone|Device microphone capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|fingerprint|Device fingerprint authentication capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|usb|Device USB capability. Disabling this capability prohibits the use of external USB devices (the device cannot act as a USB host to connect external devices).|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|wifi|Device Wi-Fi capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|tethering<sup>14+</sup>|Network tethering capability (the ability to share the device's internet connection with other devices, that is, hotspot sharing).|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|inactiveUserFreeze<sup>14+</sup>|Capability of freezing inactive users. When this capability is disabled, non-**UIAbility** processes will generally not be frozen, and background tasks requested by **UIAbility** (such as transient tasks, continuous tasks, deferred tasks, or energy efficiency resources) will also not be frozen. Currently, this capability is supported only on PCs/2-in-1 devices. When the system switches to the enterprise space user, the personal space users are inactive users.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|camera<sup>14+</sup>|Device camera capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|mtpClient<sup>18+</sup>|Media Transfer Protocol (MTP) client capability (including read and write capabilities), currently supported only on PC/2-in-1 devices. MTP allows users to linearly access media files on mobile devices.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|mtpServer<sup>18+</sup>|MTP server capability, currently supported only on phone and tablets.|Before API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS; Since API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
|sambaClient<sup>20+</sup>|Samba client capability, currently supported only on PC/2-in-1 devices. <br>Samba is a free software that implements the SMB protocol on Linux and UNIX systems, consisting of both server and client programs. Server Message Block (SMB) is a communication protocol for sharing files and printers over the local area network (LAN). It provides resource-sharing services, such as files and printers, among different computers within the LAN. As a client/server protocol, SMB allows clients to access shared resources hosted on servers.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|sambaServer<sup>20+</sup>|Samba server capability, currently supported only on PC/2-in-1 devices.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|backupAndRestore<sup>20+</sup>|Backup and restore capability. If this feature is disabled, the **Settings** > **System** > **Backup & Restore** and **Settings** > **Cloud** options will be dimmed. Currently, this feature is supported only on phones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|maintenanceMode<sup>20+</sup>|Device maintenance mode capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|mms<sup>20+</sup>|Multimedia Messaging Service (MMS) capability to receive and send multimedia messages. Currently, this feature is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|sms<sup>20+</sup>|Short Messaging Service (SMS) capability to receive and send SMS messages. Currently, this feature is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|mobileData<sup>20+</sup>|Cellular data capability, which is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_NETWORK|
|airplaneMode<sup>20+</sup>|Airplane mode capability, which is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_NETWORK|
|vpn<sup>20+</sup>|Virtual Private Network (VPN) capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|notification<sup>20+</sup>|Device notification capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|nfc<sup>20+</sup>|Near Field Communication (NFC) capability, which is supported only on phones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|privateSpace<sup>20+</sup>|Privacy space creation capability, which is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|telephoneCall<sup>20+</sup>|Call capability. Disabling this feature blocks incoming or outgoing calls. Currently, this feature is supported only on smartphones and tablets.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|appClone<sup>21+</sup>|[Application clone capability](../../quick-start/app-clone.md). When this feature is disabled, new application clones cannot be created.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|externalStorageCard<sup>21+</sup> |External storage capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|randomMac<sup>21+</sup>|Random MAC address capability for Wi-Fi connections.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|unmuteDevice<sup>22+</sup>|Device audio playback capability. When this feature is disabled, media playback will be muted, while [cellular calls](../../media/audio/audio-call-overview.md) remain unaffected.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|hdcRemote<sup>22+</sup>|Capability of the device to debug other devices through HDC. Currently, this feature can be set only for PCs/2-in-1 devices.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|virtualService<sup>23+</sup>|Device virtualization service capability.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
|usbSerial<sup>24+</sup>|Device USB-to-serial port capability. After the capability is disabled, external USB-to-serial port devices will be unavailable.|ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS|
<!--RP2--><!--RP2End-->

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

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let result: boolean = restrictions.getDisallowedPolicy(wantTemp, 'printer');
  console.info(`Succeeded in querying whether the printing function is disabled. Disabled status: ${result}`);
} catch (err) {
  console.error(`Failed to get printer disabled status. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setDisallowedPolicyForAccount<sup>(deprecated)</sup>

setDisallowedPolicyForAccount(admin: Want, feature: string, disallow: boolean, accountId: number): void

Disallows a feature for a specified user.

**Since:** 14

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount)

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

<!--Table: 10%; 10%; 10%; 70%-->
| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **fingerprint**: device fingerprint authentication capability. Currently, this feature is supported only on PCs/2-in-1 devices. The rules for using this parameter are as follows:<br>1. If the device fingerprint authentication capability has been disabled through the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API, calling this API with this parameter passed will throw a policy conflict.<br>2. After the device fingerprint authentication capability is enabled or disabled via this API for a specified user, any subsequent action via the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API will override the previous setting. If [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) enables the capability, all users gain access to the device fingerprint authentication.<br>- **print**<sup>20+</sup>: device printing capability, which is supported only on PCs/2-in-1 devices for API versions earlier than 23, and on PCs/2-in-1 devices, smartphones, and tablets for API version 23 and later versions. If the device printing capability is disabled via this API, it remains disabled for specific users even if the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API is used to enable it for those users.<br>- **mtpClient**<sup>20+</sup>: Media Transfer Protocol (MTP) client capability (write only). Currently, this feature is supported only on PCs/2-in-1 devices. MTP allows users to linearly access media files on mobile devices. A policy conflict error will occur if this API is used to disable the MTP client capability after MTP client write has been disabled for specific users via the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API.<br>- **usbStorageDeviceWrite**<sup>20+</sup>: USB storage device write capability. Currently, this feature is supported only on enterprise PCs/2-in-1 devices.<!--RP5--><!--RP5End--><br>  If the USB storage device write permission of a user is disabled via this API in any of the following situations, a policy conflict will be reported:<br>  1. The device USB capability has been disabled via the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API.<br>  2. USB storage device access policy has been set to read-only or disabled via the [setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy) API.<br>  3. Storage USB devices have been disabled via the [addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14) API.<br>- **diskRecoveryKey**<sup>20+</sup>: recovery [key export](../../security/UniversalKeystoreKit/huks-export-key-arkts.md) capability. Currently, this feature is supported only on PCs/2-in-1 devices.<br>- **sudo**<sup>20+</sup>: superuser do (execution with superuser privileges). Currently, this feature is supported only on PCs/2-in-1 devices. If this feature is disabled, neither enterprise spaces nor personal spaces can perform operations with superuser privileges.<br>- **distributedTransmissionOutgoing**<sup>20+</sup>: distributed one-way data transmission between devices (only data transmission to other devices is supported). A policy conflict occurs if this API is used to disable distributed one-way data transmission between devices after the distributed service has already been disabled via the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount) API.<br>- **openFileBoost**<sup>23+</sup>: <!--RP6-->file opening acceleration capability<!--RP6End-->, which provides the file opening acceleration status awareness capability for apps. By integrating the corresponding APIs, apps can detect the acceleration status of files, and further implement features such as displaying unique UI identifiers for accelerated files, thereby optimizing user experience of file opening. Currently, this feature is supported only on PCs/2-in-1 devices.|
| disallow | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                       |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  restrictions.setDisallowedPolicyForAccount(wantTemp, 'fingerprint', true, 100);
  console.info('Succeeded in setting fingerprint disabled');
} catch (err) {
  console.error(`Failed to set fingerprint disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicyForAccount<sup>(deprecated)</sup>

getDisallowedPolicyForAccount(admin: Want | null, feature: string, accountId: number): boolean

Obtains the status of a feature for a specified user.

**Since:** 14

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.getDisallowedPolicyForAccount](#restrictionsgetdisallowedpolicyforaccount)

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

<!--Table: 10%; 20%; 10%; 60%-->
| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| feature | string                                                  | Yes  | Feature to set.<br>- **fingerprint**: device fingerprint authentication capability. Currently, this feature is supported only on PCs/2-in-1 devices. Note that when [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated) is used to disable or enable the device fingerprint authentication capability for a specified user, any subsequent action via the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API will override the previous setting. The value **false** will be returned.<br>- **mtpClient**<sup>20+</sup>: Media Transfer Protocol (MTP) client capability (write only). Currently, this feature is supported only on PCs/2-in-1 devices. MTP allows users to linearly access media files on mobile devices.<br>- **usbStorageDeviceWrite**<sup>20+</sup>: USB storage device write capability. Currently, this feature is supported only on enterprise PCs/2-in-1 devices.<br>- **diskRecoveryKey**<sup>20+</sup>: recovery [key export](../../security/UniversalKeystoreKit/huks-export-key-arkts.md) capability. Currently, this feature is supported only on PCs/2-in-1 devices.<br>- **sudo**<sup>20+</sup>: superuser do (execution with superuser privileges). Currently, this feature is supported only on PCs/2-in-1 devices. If this feature is disabled, neither enterprise spaces nor personal spaces can perform operations with superuser privileges.<br>- **distributedTransmissionOutgoing**<sup>20+</sup>: one-way data transmission between devices (only data transmission to other devices is supported).<br>- **print**<sup>20+</sup>: device printing capability, which is supported only on PCs/2-in-1 devices for API versions earlier than 23, and on PCs/2-in-1 devices, smartphones, and tablets for API version 23 and later versions. If printing is disabled via the [setDisallowedPolicy](#restrictionssetdisallowedpolicydeprecated) API, it remains disabled even if the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated) API is used to enable it for specific users.<br>- **openFileBoost**<sup>23+</sup>: <!--RP6-->file opening acceleration capability<!--RP6End-->, which provides the file opening acceleration status awareness capability for apps. By integrating the corresponding APIs, apps can detect the acceleration status of files, and further implement features such as displaying unique UI identifiers for accelerated files, thereby optimizing user experience of file opening. Currently, this feature is supported only on PCs/2-in-1 devices.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** means the feature is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
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

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| list | Array\<string>                                                 | Yes  | App bundle name list.                     |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

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
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let valueList:Array<string> = ["com.xx.aa.", "com.xx.bb"];
try {
  // Replace parameters with actual values.
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

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| feature  | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| list | Array\<string>                                                 | Yes  | List of content such as the bundle names.                      |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

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
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let valueList:Array<string> = ["com.xx.aa.", "com.xx.bb"];
try {
  // Replace parameters with actual values.
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

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| feature | string                                                  | Yes  | Feature to set.<br>- **snapshotSkip**: screen snapshot capability.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

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
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let result: Array<string> = restrictions.getDisallowedListForAccount(wantTemp, 'snapshotSkip', 100);
  console.info('Succeeded in querying disallowed list for account');
} catch (err) {
  console.error(`Failed to query disallowed list for account. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setUserRestriction<sup>(deprecated)</sup>

setUserRestriction(admin: Want, settingsItem: string, restricted: boolean): void

Sets restrictions on user behaviors.

**Since:** 20

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.setUserRestriction](#restrictionssetuserrestriction)

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

<!--Table: 10%; 10%; 10%; 70%-->
| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| settingsItem  | string                                                  | Yes  | Behavior name. Only the following values are supported. If other values are passed, an error will be reported.<br>- **setApn**: APN configuration, currently supported only on smartphones and tablets.<br>- **powerLongPress**: capability to open the power menu by long-pressing the power button. Currently, only smartphones and tablets are supported.<br>- **setEthernetIp**: Ethernet IP address configuration, currently supported only on PCs/2-in-1 devices.<br>- **setDeviceName**: device name configuration, currently supported only on PCs/2-in-1 devices, smartphones, and tablets. When it is disabled, the device name cannot be modified in the following settings: **About**, **Bluetooth**, and **More connectivity options** > **NearLink** on PCs/2-in-1 devices, and **About**, **Bluetooth**, and **Personal hotspot** on smartphones and tablets.<br>- **setBiometricsAndScreenLock**: screen lock password configuration, currently supported only on PCs/2-in-1 devices, smartphones, and tablets.|
| restricted | boolean                                                 | Yes  | Whether to disable the action. The value **true** means to disable the action, and **false** means the opposite.                      |

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
import { restrictions } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  restrictions.setUserRestriction(wantTemp, 'setApn', true);
  console.info('Succeeded in restricting from setting apn');
} catch (err) {
  console.error(`Failed to restrict from setting apn. Code is ${err.code}, message is ${err.message}`);
}
```
## restrictions.getUserRestricted<sup>(deprecated)</sup>

getUserRestricted(admin: Want, settingsItem: string): boolean

Obtains the disabled status of a setting item.

**Since:** 20

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.getUserRestricted](#restrictionsgetuserrestricted)

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

<!--Table: 10%; 10%; 10%; 70%-->
| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| settingsItem | string                                             | Yes  | Setting item.<br>- **setEthernetIp**: Ethernet IP address configuration, currently supported only on PCs/2-in-1 devices.<br>- **setDeviceName**: device name configuration, currently supported only on PCs/2-in-1 devices, smartphones, and tablets. When it is disabled, the device name cannot be modified in the following settings: **About**, **Bluetooth**, and **More connectivity options** > **NearLink** on PCs/2-in-1 devices, and **About**, **Bluetooth**, and **Personal hotspot** on smartphones and tablets.<br>- **setBiometricsAndScreenLock**: screen lock password configuration, currently supported only on PCs/2-in-1 devices, smartphones, and tablets.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Disabled status of the specified setting item. The value **true** means the item is disabled; the value **false** means the opposite.|

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
import { restrictions } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace input parameters with actual values.
  let result: boolean = restrictions.getUserRestricted(wantTemp, 'setEthernetIp');
  console.info('Succeeded in getting user restricted');
} catch (err) {
  console.error(`Failed to get user restricted. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setUserRestrictionForAccount<sup>(deprecated)</sup>

setUserRestrictionForAccount(admin: Want, settingsItem: string, accountId: number, restricted: boolean): void

Sets restrictions on specified user behaviors.

**Since:** 23

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.setUserRestrictionForAccount](#restrictionssetuserrestrictionforaccount)

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| settingsItem  | string                                                  | Yes  | User behavior.<br>- **modifyWallpaper**: Modify the wallpaper, including the lock screen wallpaper and home screen wallpaper.<!--RP7--><!--RP7End-->|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).                      |
| restricted | boolean                                                 | Yes  | Whether to disable the action. The value **true** means to disable the action, and **false** means the opposite.                      |

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
import { restrictions } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let userId = 100;
let settingsItem: string = "modifyWallpaper";
try {
  restrictions.setUserRestrictionForAccount(wantTemp, settingsItem, userId, true);
  console.info('Succeeded in restricting from setting modifyWallpaper');
} catch (err) {
  console.error(`Failed to restrict from setting modifyWallpaper. Code is ${err.code}, message is ${err.message}`);
}
```
## restrictions.getUserRestrictedForAccount<sup>(deprecated)</sup>

getUserRestrictedForAccount(admin: Want | null, settingsItem: string, accountId: number): boolean

Obtains the disabled status of a setting item for a specified user.

**Since:** 23

**Deprecated since:** 26.0.0

**Substitutes:** [restrictions.getUserRestrictedForAccount](#restrictionsgetuserrestrictedforaccount)

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| settingsItem | string                                             | Yes  | Setting item.<br>- **modifyWallpaper**: Modify the wallpaper, including the lock screen wallpaper and home screen wallpaper.<!--RP7--><!--RP7End-->|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).                      |


**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Disabled status of the specified setting item. The value **true** means the item is disabled; the value **false** means the opposite.|

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
import { restrictions } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace with actual values.
let userId = 100;
let settingsItem: string = "modifyWallpaper";
try {
  let result: boolean = restrictions.getUserRestrictedForAccount(wantTemp, settingsItem, userId);
  console.info(`Succeeded in getting user restricted: ${result}`);
} catch (err) {
  console.error(`Failed to get user restricted. Code is ${err.code}, message is ${err.message}`);
}
```
## restrictions.setDisallowedPolicy<sup>24+</sup>

setDisallowedPolicy(admin: Want, feature: FeatureForDevice, disallow: boolean): void

Enables or disables a specified device feature. Once disabled, the feature cannot be used.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| feature  | [FeatureForDevice](#featurefordevice24)                                                  | Yes  | Device feature to be enabled or disabled.<br> **Note:** An application granted with the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and activated as the [BDA](../../mdm/mdm-kit-term.md#byod-device-admin-bdabyod) via [startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) can use this API to set the [FeatureForDevice.WIFI_P2P](#featurefordevice24) feature.|
| disallow | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                       |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9200013  | The enterprise management policy has been successfully set, but the function has not taken effect in real time. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  restrictions.setDisallowedPolicy(wantTemp, restrictions.FeatureForDevice.WIFI_P2P, true);
  console.info('Succeeded in setting Wi-Fi P2P disabled');
} catch (err) {
  console.error(`Failed to set Wi-Fi P2P disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicy<sup>24+</sup>

getDisallowedPolicy(admin: Want \| null, feature: FeatureForDevice): boolean

Queries whether a specified device feature is disabled.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| feature | [FeatureForDevice](#featurefordevice24)                                                  | Yes  | Device feature to be queried.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** indicates the device feature is disabled, and the value **false** indicates the opposite.|

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
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: boolean = restrictions.getDisallowedPolicy(wantTemp, restrictions.FeatureForDevice.WIFI_P2P);
  console.info(`Succeeded in querying whether Wi-Fi P2P is disabled. Disabled status: ${result}`);
} catch (err) {
  console.error(`Failed to get Wi-Fi P2P disabled status. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setDisallowedPolicyForAccount

setDisallowedPolicyForAccount(admin: Want, feature: FeatureForAccount, disallow: boolean, accountId: number): void

Disallows a feature for a specified user.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| feature   | [FeatureForAccount](#featureforaccount)                 | Yes  | User feature to be disabled or enabled.<br>If SuperHub has been added to the user's list of non-disableable applications through the [addUserNonStopApps](./js-apis-enterprise-applicationManager.md#applicationmanageraddusernonstopapps22) API, setting this parameter to **SUPER_HUB** will cause a policy conflict and error code 9200010 will be reported. In this case, call the [removeUserNonStopApps](./js-apis-enterprise-applicationManager.md#applicationmanagerremoveusernonstopapps22) API to remove SuperHub from the user's list of non-disableable applications to resolve the conflict.<br>When **feature** is **DISTRIBUTED_TRANSMISSION**, if the capability of distributed one-way data transmission between devices has been disabled via the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated) API, calling this API to disable the distributed management service will result in a policy conflict and error code 9200010 will be reported. You can call the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccountdeprecated) API to enable distributed one-way data transmission between devices to resolve the conflict.|
| disallow  | boolean                                                 | Yes  | Whether to disallow the feature. The value **true** means to disallow the feature; the value **false** means the opposite.                               |
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).<br>When **feature** is set to **SUPER_HUB**, this parameter can only be set to the ID of the current user. Otherwise, error code 9200012 will be reported.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  restrictions.setDisallowedPolicyForAccount(wantTemp, restrictions.FeatureForAccount.SUPER_HUB, true, 100);
  console.info('Succeeded in setting super hub disabled');
} catch (err) {
  console.error(`Failed to set super hub disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicyForAccount

getDisallowedPolicyForAccount(admin: Want | null, feature: FeatureForAccount, accountId: number): boolean

Obtains the status of a feature for a specified user.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| feature   | [FeatureForAccount](#featureforaccount)                      | Yes  | User feature to be queried.|
| accountId | number                                                       | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | The value **true** means the feature is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let result: boolean = restrictions.getDisallowedPolicyForAccount(wantTemp, restrictions.FeatureForAccount.SUPER_HUB, 100);
  console.info(`Succeeded in querying whether the super hub is disabled: ${result}`);
} catch (err) {
  console.error(`Failed to get whether super hub is disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setUserRestriction

setUserRestriction(admin: Want, settingsItem: SettingsForDevice, restricted: boolean): void

Restricts users from modifying specified device setting items.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                                   | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| settingsItem | [SettingsForDevice](#settingsfordevice)              | Yes  | Device setting items to be restricted from modification.                                |
| restricted  | boolean                                                 | Yes  | The value **true** means to disable the action, and **false** means the opposite.                             |

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
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  restrictions.setUserRestriction(wantTemp, restrictions.SettingsForDevice.SET_APN, true);
  console.info('Succeeded in restricting from setting apn');
} catch (err) {
  console.error(`Failed to restrict from setting apn. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getUserRestricted

getUserRestricted(admin: Want, settingsItem: SettingsForDevice): boolean

Obtains the disabled status of the specified device setting item.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                                   | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| settingsItem | [SettingsForDevice](#settingsfordevice)              | Yes  | Device setting item to be queried.                                    |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Disabled status of the specified device setting item. The value **true** means the item is disabled; the value **false** means the opposite.|

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
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: boolean = restrictions.getUserRestricted(wantTemp, restrictions.SettingsForDevice.SET_APN);
  console.info(`Succeeded in getting user restricted: ${result}`);
} catch (err) {
  console.error(`Failed to get user restricted. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setUserRestrictionForAccount

setUserRestrictionForAccount(admin: Want, settingsItem: SettingsForAccount, accountId: number, restricted: boolean): void

Restricts a specified user from modifying specified setting items.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                                   | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| settingsItem | [SettingsForAccount](#settingsforaccount)            | Yes  | User setting items to be restricted from modification.                                |
| accountId   | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|
| restricted  | boolean                                                 | Yes  | The value **true** means to disable the action, and **false** means the opposite.                             |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  restrictions.setUserRestrictionForAccount(wantTemp, restrictions.SettingsForAccount.MODIFY_WALLPAPER, 100, true);
  console.info('Succeeded in restricting from setting modifyWallpaper');
} catch (err) {
  console.error(`Failed to restrict from setting modifyWallpaper. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getUserRestrictedForAccount

getUserRestrictedForAccount(admin: Want | null, settingsItem: SettingsForAccount, accountId: number): boolean

Obtains the disabled status of a setting item for a specified user.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_SET_USER_RESTRICTION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| settingsItem | [SettingsForAccount](#settingsforaccount)                 | Yes  | User setting item to be queried.                                    |
| accountId   | number                                                       | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Disabled status of the specified user setting item. The value **true** means the item is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let result: boolean = restrictions.getUserRestrictedForAccount(wantTemp, restrictions.SettingsForAccount.MODIFY_WALLPAPER, 100);
  console.info(`Succeeded in getting user restricted: ${result}`);
} catch (err) {
  console.error(`Failed to get user restricted. Code is ${err.code}, message is ${err.message}`);
}
```

## FeatureForDevice<sup>24+</sup>

Enumerates device features.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name                       | Value | Description   |
| ----------------------------| ----| ------------------------------- |
| WIFI_P2P   | 0   | Wi-Fi P2P (peer-to-peer connection), which allows devices to directly connect to each other without an access point. Once this feature is disallowed, devices cannot be connected through Wi-Fi P2P, affecting application functions that require direct Wi-Fi connections, such as file transfer, online gaming, and screen sharing.|
| LOCAL_INPUT   | 2   | After local input (including the keyboard, mouse, touchpad, and touchscreen) is disabled, operations cannot be performed through local input. You can restart the device to cancel the disabling. If local input is disabled when the screen is off, the screen cannot be woken up. If the screen automatically turns off after this feature is disabled, the screen also cannot be woken up.<br>**Since**: 26.0.0|
| TRAFFIC_REDIRECTION   | 5   | Policy for controlling network traffic redirection. After this capability is disabled, TCP traffic cannot be redirected to other ports. You can cancel the disabling to restore the feature. Currently, this capability is supported only on PCs/2-in-1 devices.<br>**Since**: 26.0.0|
| CORE_DUMP   | 6   | Create a file dump. After this capability is disabled, file dumps cannot be created through the task manager. Currently, this capability is supported only on PCs/2-in-1 devices.<br>**Since**: 26.0.0|
| RS232   | 7   | RS-232 serial port control policy. If this capability is disabled, data cannot be transmitted via the RS-232 serial port. Currently, this capability is supported only on PCs/2-in-1 devices. (some devices do not support the RS-232 serial port).<br>**Since**: 26.0.0|
| DISK_ERASURE   | 8   | Disk erasure capability. Once disabled, the "Disk Erasure" entry will be grayed out. Currently, this capability is supported only on PCs/2-in-1 devices.<br>**Since**: 26.0.0|
| BLUETOOTH   | 9   | Device Bluetooth capability. If a Bluetooth device blocklist or trustlist is configured via [addDisallowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanageradddisallowedbluetoothdevices20) or [addAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanageraddallowedbluetoothdevices), disabling Bluetooth via this API takes priority. The blocklist or trustlist will only take effect after Bluetooth is re-enabled.<br>**Since**: 26.0.0|
| MODIFY_DATE_TIME   | 10   | Device capability to modify system time.<br>**Since**: 26.0.0|
| PRINTER   | 11   | Device printing capability. When the device printing capability has been disabled, enabling printing for a specific user via the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount) API will not take effect. The printing capability remains disabled for that user.<br>**Since**: 26.0.0|
| HDC   | 12   | Capability for other devices to connect to and debug this device via HDC. Disabling this capability prevents external devices from connecting or debugging via HDC.<br>**Since**: 26.0.0|
| MICROPHONE   | 13   | Device microphone capability.<br>**Since**: 26.0.0|
| FINGERPRINT   | 14   | Device fingerprint authentication capability. Enable device fingerprint authentication will trigger a policy conflict if fingerprint authentication has already been disabled for a user via [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount).<br>**Since**: 26.0.0|
| USB   | 15   | Device USB capability. Disabling this capability prohibits the use of external USB devices (the device cannot act as a USB host to connect external devices).<br>If the device USB capability is disabled in any of the following scenarios, a policy conflict will be reported:<br>1. A list of allowed USB devices has been configured via the [addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices) API.<br>2. USB storage device access policy has been set to read-only or disabled via the [setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy) API.<br>3. Specific USB device types have been blocked via the [addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14) API.<br>4. USB storage write has been disabled for specific users via the [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount) API.<br>5. USB-to-serial conversion ([USB_SERIAL](#featurefordevice24)) is disabled.<br>**Since**: 26.0.0|
| WIFI   | 16   | Device Wi-Fi capability.<br>**Since**: 26.0.0|
| TETHERING   | 17   | Network tethering capability (the ability to share the device's internet connection with other devices, that is, hotspot sharing).<br>**Since**: 26.0.0|
| INACTIVE_USER_FREEZE   | 18   | Capability of freezing inactive users. When this capability is disabled, non-**UIAbility** processes will generally not be frozen, and background tasks requested by **UIAbility** (such as transient tasks, continuous tasks, deferred tasks, or energy efficiency resources) will also not be frozen. Currently, this capability is supported only on PCs/2-in-1 devices. When the system switches to the enterprise space user, the personal space users are inactive users.<br>**Since**: 26.0.0|
| CAMERA   | 19   | Device camera capability.<br>**Since**: 26.0.0|
| MTP_CLIENT   | 20   | Media Transfer Protocol (MTP) client capability (including read and write capabilities), currently supported only on PC/2-in-1 devices. MTP allows users to linearly access media files on mobile devices. A policy conflict occurs when you disable the MTP client capability after MTP client write has been disabled for specific users via [setDisallowedPolicyForAccount](#restrictionssetdisallowedpolicyforaccount).<br>**Since**: 26.0.0|
| MTP_SERVER   | 21   | MTP server capability, currently supported only on phone and tablets.<br>**Since**: 26.0.0|
| SAMBA_CLIENT   | 22   | Samba client capability, currently supported only on PC/2-in-1 devices. <br>Samba is a free software that implements the SMB protocol on Linux and UNIX systems, consisting of both server and client programs. Server Message Block (SMB) is a communication protocol for sharing files and printers over the local area network (LAN). It provides resource-sharing services, such as files and printers, among different computers within the LAN. As a client/server protocol, SMB allows clients to access shared resources hosted on servers.<br>**Since**: 26.0.0|
| SAMBA_SERVER   | 23   | Samba server capability, currently supported only on PC/2-in-1 devices.<br>**Since**: 26.0.0|
| BACKUP_AND_RESTORE   | 24   | Backup and restore capability. If this feature is disabled, the **Settings** > **System** > **Backup & Restore** and **Settings** > **Cloud** options will be dimmed. Currently, this feature is supported only on phones and tablets. To completely disable the backup and restore capability, you are advised to call [applicationManager.addDisallowedRunningBundlesSync](./js-apis-enterprise-applicationManager.md#applicationmanageradddisallowedrunningbundlessync) to disable applications with this feature, such as Backup & Restore, HiSuite, and Cloud.<br>**Since**: 26.0.0|
| MAINTENANCE_MODE   | 25   | Device maintenance mode capability.<br>**Since**: 26.0.0|
| MMS   | 26   | Multimedia Messaging Service (MMS) capability to receive and send multimedia messages. Currently, this feature is supported only on smartphones and tablets.<br>**Since**: 26.0.0|
| SMS   | 27   | Short Messaging Service (SMS) capability to receive and send SMS messages. Currently, this feature is supported only on smartphones and tablets.<br>**Since**: 26.0.0|
| MOBILE_DATA   | 28   | Cellular data capability, which is supported only on smartphones and tablets.<br>**Since**: 26.0.0|
| AIRPLANE_MODE   | 29   | Airplane mode capability, which is supported only on smartphones and tablets.<br>**Since**: 26.0.0|
| VPN   | 30   | Virtual Private Network (VPN) capability.<br>**Since**: 26.0.0|
| NOTIFICATION   | 31   | Device notification capability. After this capability is disabled, notifications sent by system applications and third-party applications will not be displayed. However, notification capabilities for system services are not affected. If you disable the device-level notification capability after an allowed notification bundle has already been set via [addAllowedNotificationBundles](./js-apis-enterprise-applicationManager.md#applicationmanageraddallowednotificationbundles), error code 9200010 will be reported.<br>**Since**: 26.0.0|
| NFC   | 32   | Near Field Communication (NFC) capability, which is supported only on phones and tablets.<br>**Since**: 26.0.0|
| PRIVATE_SPACE   | 33   | Privacy space creation capability, which is supported only on smartphones and tablets. This setting does not affect existing private spaces.<br>**Since**: 26.0.0|
| TELEPHONE_CALL   | 34   | Call capability. Disabling this feature blocks incoming or outgoing calls. Currently, this feature is supported only on smartphones and tablets.<br>**Since**: 26.0.0|
| APP_CLONE   | 35   | [Application clone capability](../../quick-start/app-clone.md). When this feature is disabled, new application clones cannot be created. This feature is invalid for the application clone that has been created.<br>**Since**: 26.0.0|
| EXTERNAL_STORAGE_CARD   | 36   | External storage capability. Disabling this feature prohibits the use of external storage and unmounts currently connected external storage. If files are in use during unmounting, unmounting may fail with error code 9200013.<br>After external storage is disabled and then enabled again, you need to manually reconnect the external storage.<br>**Since**: 26.0.0|
| RANDOM_MAC   | 37   | Random MAC address capability for Wi-Fi connections. When this feature is disabled, only the device's physical MAC address can be used for Wi-Fi connections.<br>**Since**: 26.0.0|
| UNMUTE_DEVICE   | 38   | Device audio playback capability. When this feature is disabled, media playback will be muted, while [cellular calls](../../media/audio/audio-call-overview.md) remain unaffected.<br>**Since**: 26.0.0|
| HDC_REMOTE   | 39   | Capability of the device to debug other devices through HDC. Currently, this feature can be set only for PCs/2-in-1 devices. Disabling this capability prevents debugging smartphones, tablets, PCs, smart watches, and other devices via HDC.<br>**Since**: 26.0.0|
| VIRTUAL_SERVICE   | 40   | Device virtualization service capability, which refers to the system capability of running other operating system platforms (such as Linux and Windows) through virtualization technology by leveraging the redundancy of the device's hardware resources. If this capability is disabled, it is advised to uninstall all applications related to the virtualization service and prohibit their reinstallation.<br>**Since**: 26.0.0|
| USB_SERIAL   | 41   | Device USB-to-serial port capability. After the capability is disabled, external USB-to-serial port devices will be unavailable. Disabling the USB-to-Serial capability in any of the following scenario will trigger a policy conflict:<br>1. A list of allowed USB devices has been configured via the [addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices) API.<br>2. The device ([USB](#featurefordevice24)) capability has been disabled.<br>**Since**: 26.0.0|
| SCREEN_SHOT   | 42   | Screenshot capability. After this capability is disabled, screenshots cannot be taken.<br>**Since**: 26.0.0|
| SCREEN_RECORD   | 43   | Screen recording capability. After this capability is disabled, screen recording cannot be performed.<br>**Since**: 26.0.0|
| DISK_RECOVERY_KEY   | 44   | [Key export](../../security/UniversalKeystoreKit/huks-export-key-arkts.md) recovery capability. Currently, it is supported only on PCs/2-in-1 devices.<br>**Since**: 26.0.0|
| NEAR_LINK   | 45   | NearLink capability.<br>**Since**: 26.0.0|
| DEVELOPER_MODE   | 46   | Developer mode. Disabling this feature takes effect after the device is restarted.<br>**Since**: 26.0.0|
| RESET_FACTORY   | 47   | Factory reset capability.<br>**Since**: 26.0.0|
| REMOTE_DESK   | 48   | Remote desktop capability.<br>**Since**: 26.0.0|
| REMOTE_DIAGNOSIS   | 49   | Remote diagnosis capability.<br>**Since**: 26.0.0|
| OTA_UPDATE   | 50   | Public network system upgrade capability.<br>**Since**: 26.0.0|

## FeatureForAccount

Enumerates the features that can be disabled or enabled for a specified user.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name     | Value  | Description    |
| --------- | ---- | -------- |
| MULTI_WINDOW | 0    | System multi-window. Currently, this feature is available only on phones and tablets. Once disabled, the system multi-window feature (split-screen, one-click split-screen, Multi-Window, and floating window) cannot be used. If the feature is currently active, the current usage remains unaffected. However, it cannot be used once closed.|
| DISTRIBUTED_TRANSMISSION | 1    | [Distributed management service](../../distributedservice/distributedservice-kit-intro.md#working-principles). Once disabled, functions such as discovery, authentication, query, and listening in the distributed device management service cannot be used.|
| SUPER_HUB | 2    | SuperHub. Currently, this feature is available only on phones and tablets. Once disabled, the SuperHub feature cannot be used. If SuperHub is currently active, the current usage remains unaffected. However, it cannot be used once closed.|
| FINGERPRINT | 3    | Device fingerprint authentication capability. Currently, this feature is supported only on PCs/2-in-1 devices. The rules for using this capability are as follows:<br>1. After the device fingerprint authentication capability ([FeatureForDevice.FINGERPRINT](#featurefordevice24)) is disabled, disabling this capability for a specific user will result in a policy conflict.<br>2. After the device fingerprint authentication capability is disabled or enabled for a specific user, disabling this capability ([FeatureForDevice.FINGERPRINT](#featurefordevice24)) globally will override the user-specific policy. Subsequently, re-enabling this capability ([FeatureForDevice.FINGERPRINT](#featurefordevice24)) globally will allow all users to use device fingerprint authentication.|
| PRINT | 4    | Device printing capability. If the device printing capability is disabled for a specific user, it remains disabled for that user even if the device printing capability ([FeatureForDevice.PRINTER](#featurefordevice24)) capability is enabled globally.|
| MTP_CLIENT | 5    | MTP client capability (including read and write capabilities). Currently, it is supported only on PC/2-in-1 devices. MTP allows users to linearly access media files on mobile devices. After the device MTP client capability ([FeatureForDevice.MTP_CLIENT](#featurefordevice24)) is disabled, disabling the MTP client write capability for a specific user will result in a policy conflict.|
| USB_STORAGE_DEVICE_WRITE | 6    | USB storage device write capability. Currently, it is supported only on enterprise PCs/2-in-1 devices.<!--RP5--><!--RP5End--><br>Disabling the USB storage device write capability for a specific user in any of the following scenarios will result in a policy conflict:<br>1. The device USB capability ([FeatureForDevice.USB](#featurefordevice24)) has been disabled.<br>2. USB storage device access policy has been set to read-only or disabled via the [setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy) API.<br>3. Storage USB devices have been disabled via the [addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14) API.|
| DISK_RECOVERY_KEY | 7    | [Key export](../../security/UniversalKeystoreKit/huks-export-key-arkts.md) recovery capability. Currently, it is supported only on PCs/2-in-1 devices.|
| SUDO | 8    | superuser do (execution with superuser privileges). Currently, it is supported only on PCs/2-in-1 devices. If this feature is disabled, neither enterprise spaces nor personal spaces can perform operations with superuser privileges.|
| DISTRIBUTED_TRANSMISSION_OUTGOING | 9    | Distributed one-way data transmission between devices (only data transmission to other devices is supported). Disabling distributed one-way data transmission capability between devices after the distributed management service ([DISTRIBUTED_TRANSMISSION](#featureforaccount)) has been disabled will result in a policy conflict.|
| OPEN_FILE_BOOST | 10    | <!--RP6-->File open acceleration capability<!--RP6End-->, providing applications with the ability to sense the file open acceleration status. By integrating the corresponding APIs, apps can detect the acceleration status of files, and further implement features such as displaying unique UI identifiers for accelerated files, thereby optimizing user experience of file opening. Currently, this feature is supported only on PCs/2-in-1 devices.|

## SettingsForDevice

Enumerates device setting items.

**Since**: 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name| Value| Description|
|------|-----|------|
| SET_APN | 0 | APN configuration, currently supported only on phones and tablets.|
| POWER_LONG_PRESS | 1 | Opens the power menu by long-pressing the power button. Currently, this item is supported only on phones and tablets.|
| SET_ETHERNET_IP | 2 | Changes the Ethernet IP address. Currently, this item is supported only on PCs/2-in-1 devices.|
| SET_DEVICE_NAME | 3 | Changes the device name configuration. Currently, this item is supported only on PCs/2-in-1 devices, phones, and tablets. When it is disabled, the device name cannot be modified in the following settings: **About**, **Bluetooth**, and **More connectivity options** > **NearLink** on PCs/2-in-1 devices, and **About**, **Bluetooth**, and **Personal hotspot** on smartphones and tablets.|
| SET_BIOMETRICS_AND_SCREEN_LOCK | 4 | Changes the screen lock password. Currently, this item is supported only on PCs/2-in-1 devices, phones, and tablets.|

## SettingsForAccount

Enumerates user setting items.

**Since**: 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name| Value| Description|
|------|-----|------|
| MODIFY_WALLPAPER | 0 | Modifies the wallpaper, including both the lock screen wallpaper and the home screen wallpaper.|
<!--no_check-->