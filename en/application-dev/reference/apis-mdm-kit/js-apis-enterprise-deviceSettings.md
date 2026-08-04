# @ohos.enterprise.deviceSettings (Device Settings Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides enterprise device settings capabilities, including setting and obtaining the device screen-off time, system time, power policy, Eye Comfort mode, default input method, wallpaper, and hidden setting items.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { deviceSettings } from '@kit.MDMKit';
```

## deviceSettings.setValue

setValue(admin: Want, item: string, value: string): void

Sets the device policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

<!--Table: 10%; 10%; 10%; 70%-->
| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| item   | string                                                  | Yes  | Type of the policy to set.<br>- **screenOff**: device screen-off policy. For PCs/2-in-1 devices, the device power policy can be set for both battery and power modes.<br>- **dateTime**: system time settings.<br>- **powerPolicy**: device power policy. This capability is supported only on PCs/2-in-1 devices. After the policy is set, the **Settings** > **Power & battery** screen is not refreshed. The settings do not take effect on phones or tablets.<br>For PCs/2-in-1 devices, the device power policy can be set only for battery supply. When the sleep delay policy upon device screen-off due to timeout is set, the sleep action takes effect after the sleep time shown in the **Settings** > **Power & battery** screen, followed by an additional **delayTime**.<br>- **eyeComfort**: eye comfort mode. This parameter is supported since API version 23. This mode can only be enabled all day or disabled.<br>- **defaultInputMethod**: default input method. This parameter is supported since API version 23.|
| value  | string                                                  | Yes  | Policy type value.<br>If **item** is **screenOff**, **value** is the screen-off time, in ms. It is recommended that **value** be consistent with the options in the drop-down list box on the settings page. Passing **-1** to set the screen to never turn off is supported only on PCs/2‑in‑1 devices. This value does not take effect on other device types.<br>If **item** is **dateTime**, **value** is the system time to set, in ms.<br>If **item** is **powerPolicy**, **value** is a JSON string in {"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}} format.<br>**powerScene** indicates the power policy scenario. The following values are supported:<br>- **0**: screen-off due to timeout.<br>**powerPolicyAction** indicates the sleep action policy scenario. The following values are supported:<br>- **0**: No action is performed.<br>- **1**: enter sleep mode automatically.<br>- **2**: forcibly enter sleep mode.<br>- **3**: enter sleep mode. This policy does not take effect currently.<br>- **4**: power off.<br>**delayTime** indicates the delay time (unit: ms). The value cannot be **30000**. Other values are allowed.<br>If **item** is **eyeComfort**, **value** is a string indicating the status of the eye comfort mode.<br>- **on**: The eye comfort mode is enabled all day.<br>- **off**: The eye comfort mode is disabled.<br>If **item** is **defaultInputMethod**, **value** is a string indicating the name of the input method application bundle.<br>- You can use [getCurrentInputMethod](../apis-ime-kit/js-apis-inputmethod.md#inputmethodgetcurrentinputmethod9) to obtain the current input method application bundle name.|

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
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace with actual values.
  deviceSettings.setValue(wantTemp, 'screenOff', '3000');
  console.info(`Succeeded in setting screen off time.`);
} catch (err) {
  console.error(`Failed to set screen off time. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getValue

getValue(admin: Want, item: string): string

Obtains a device setting policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| item   | string                                                  | Yes  | Type of the policy to set.<br>- **screenOff**: device screen-off policy. For PCs/2-in-1 devices, the screen-off policy for battery supply can be queried.<br>- **powerPolicy**: device power policy, which takes effect only for PCs/2-in-1 devices. Only the power policy for battery supply can be queried.<br>- **eyeComfort**: eye comfort mode. This parameter is supported since API version 23.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Policy type value.<br>If **item** is **screenOff**, the device screen-off time (in ms) is returned. For PCs/2-in-1 devices, the device screen-off time (in ms) in battery mode is returned.<br>If **item** is **powerPolicy**, the power policy is returned. For PCs/2-in-1 devices, the power policy in battery mode is returned. The power policy a JSON string in {"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}} format. **powerScene** indicates the power policy scenario, **delayTime** indicates the delay time (in milliseconds), and **powerPolicyAction** indicates the sleep policy.<br>The value of **powerScene** can be:<br>- **0**: timeout.<br>The value of **powerPolicyAction** can be:<br>- **0**: No action is performed.<br>- **1**: enter sleep mode automatically.<br>- **2**: forcibly enter sleep mode.<br>- **3**: enter sleep mode. This policy does not take effect currently.<br>- **4**: power off.<br>If **item** is **eyeComfort**, **value** is a string indicating the status of the eye comfort mode.<br>- **on**: The eye comfort mode is enabled all day.<br>- **off**: The eye comfort mode is disabled.<br>- **unknown**: other modes.|

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
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let result: string = deviceSettings.getValue(wantTemp, 'screenOff');
  console.info(`Succeeded in getting screen off time, result : ${result}`);
} catch (err) {
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.setHomeWallpaper<sup>20+</sup>

setHomeWallpaper(admin: Want, fd: number): Promise&lt;void&gt;

Sets the home screen wallpaper. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_WALLPAPER

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| fd     | number                                                  | Yes  | File descriptor of the image to be set as the home screen wallpaper. The file descriptor of an image in the application's sandbox directory can be obtained via the file.fs.[openSync](../apis-core-file-kit/js-apis-file-fs.md#fileioopensync) API. The size of the wallpaper image must not exceed 100 MB.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object is thrown when the home screen wallpaper fails to be set.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

<!--code_no_check-->
```ts
import { deviceSettings } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs }  from '@kit.CoreFileKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// Replace parameters with actual values.
let filename: string = "homewallpaper.jpg";
let filePath: string = context.filesDir + '/' + filename;
let fd: number = fs.openSync(filePath, fs.OpenMode.READ_WRITE).fd;
deviceSettings.setHomeWallpaper(wantTemp, fd).then(() => {
  console.info('Succeeded in setting home wallpaper');
}).catch((err: BusinessError) => {
  console.error(`Failed to set home wallpaper. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  fs.closeSync(fd);
});
```
## deviceSettings.setUnlockWallpaper<sup>20+</sup>

setUnlockWallpaper(admin: Want, fd: number): Promise&lt;void&gt;

Sets the lock screen wallpaper. This API uses a promise to return the result. Enterprise device administrator applications can use this API to uniformly set the lock screen wallpaper for enterprise devices, for purposes such as corporate branding or security control.

**Required permissions**: ohos.permission.ENTERPRISE_SET_WALLPAPER

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| fd     | number                                                  | Yes  | File descriptor of the image to be set as the lock screen wallpaper. The file descriptor of an image in the application's sandbox directory can be obtained via the file.fs.[openSync](../apis-core-file-kit/js-apis-file-fs.md#fileioopensync) API. The size of the wallpaper image must not exceed 100 MB.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object is thrown when the lock screen wallpaper fails to be set.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

<!--code_no_check-->
```ts
import { deviceSettings } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs }  from '@kit.CoreFileKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
// Replace parameters with actual values.
let filename: string = "lockwallpaper.jpg";
let filePath: string = context.filesDir + '/' + filename;
let fd: number = fs.openSync(filePath, fs.OpenMode.READ_WRITE).fd;
deviceSettings.setUnlockWallpaper(wantTemp, fd).then(() => {
  console.info('Succeeded in setting lock wallpaper');
}).catch((err: BusinessError) => {
  console.error(`Failed to set lock wallpaper. Code: ${err.code}, message: ${err.message}`);
}).finally(() => {
  fs.closeSync(fd);
});
```

## deviceSettings.setValueForAccount<sup>24+</sup>

setValueForAccount(admin: Want, item: SettingsItem, accountId: number, value: string): void

Sets the device policy for a specified user. This API allows you to set a specific parameter for a given user, such as setting the device name for user 100.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| item   | [SettingsItem](#settingsitem24)                                                  | Yes  | Type of the policy to set.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).                      |
| value  | string                                                  | Yes  | Policy type value.<br>When **item** is set to [SettingsItem.DEVICE_NAME](#settingsitem24), **value** indicates the device name, which is a character string. The string length ranges from 1 to 100. Only the device name of the current user can be set. If the device name of another user is set, error code 9200012 is returned.<br>When **item** is set to [SettingsItem.FLOATING_NAVIGATION](#settingsitem24), this API can be called properly on phones and tablets but returns error code 801 on other devices. Only the three-button navigation of the current user can be set. Setting other users' three-button navigation does not take effect. The **value** parameter indicates the three-button navigation switch state.<br>- **'0'**: Three-button navigation is enabled. (If the Kiosk mode has been entered via [enterKioskMode](../apis-ability-kit/js-apis-app-ability-kioskManager.md#kioskmanagerenterkioskmode), the display of three-button navigation requires that the bottom gesture is enabled. Specifically, three-button navigation is displayed only when both the three-button navigation switch and the bottom gesture switch are enabled. The bottom gesture can be enabled or disabled using the [applicationManager.setKioskFeatures](./js-apis-enterprise-applicationManager.md#applicationmanagersetkioskfeatures20) API.)<br>- **'1'**: Three-button navigation is disabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace with actual values.
  let accountId = 100;
  let deviceName: string = "deviceName"
  deviceSettings.setValueForAccount(wantTemp, deviceSettings.SettingsItem.DEVICE_NAME, accountId, deviceName);
  console.info('Succeeded in setting device name.');
} catch (err) {
  console.error(`Failed to set device name. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getValueForAccount<sup>24+</sup>

getValueForAccount(admin: Want, item: SettingsItem, accountId: number): string

Obtains the device policy of a specified user. This API allows you to obtain a specific parameter of a given user, such as obtaining the device name of user 100.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| item   | [SettingsItem](#settingsitem24)                         | Yes  | Type of the policy to set. The following policy types are supported: **DEVICE_NAME** (device name) and **FLOATING_NAVIGATION** (three-button navigation).|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1). |

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Policy type value.<br>When **item** is set to [SettingsItem.DEVICE_NAME](#settingsitem24), this API returns the device name of the current user. If the device name of another user is queried, error code 9200012 is returned.<br>When **item** is set to [SettingsItem.FLOATING_NAVIGATION](#settingsitem24), this API returns the three-key navigation switch state for the specified user.<br>When **item** is set to [SettingsItem.FLOATING_NAVIGATION](#settingsitem24), this API can be called properly on phones and tablets but returns error code 801 on other devices.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace with actual values.
  let accountId = 100;
  let result: string = deviceSettings.getValueForAccount(wantTemp, deviceSettings.SettingsItem.DEVICE_NAME, accountId);
  console.info(`Succeeded in getting device name, result : ${result}`);
} catch (err) {
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.addHiddenSettingsMenu<sup>24+</sup>

addHiddenSettingsMenu(admin: Want, menusToHidden: Array\<SettingsMenu>): void

Adds a setting item to the hidden setting item list of the current user. Then the setting item is hidden in the current user's settings menu and cannot be found in settings search. Even if the setting item is located through some means, it cannot be opened when tapped. The settings take effect immediately after the API is called. The Settings application does not need to be restarted.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| menusToHidden | Array\<[SettingsMenu](#settingsmenu24)>          | Yes  | Hidden setting item list.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 9200016  | Service timeout. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let menusToHidden: Array<deviceSettings.SettingsMenu> = [
  // Replace or add items as needed.
  deviceSettings.SettingsMenu.ACCOUNT_ID,
  deviceSettings.SettingsMenu.WIFI,
]

try {
  deviceSettings.addHiddenSettingsMenu(wantTemp, menusToHidden);
  console.info('Succeeded in adding hidden settings menu.');
} catch (err) {
  console.error(`Failed to add hidden settings menu. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.removeHiddenSettingsMenu<sup>24+</sup>

removeHiddenSettingsMenu(admin: Want, menusToHidden: Array\<SettingsMenu>): void

Removes a setting item from the hidden setting item list of the current user. Setting items in the hidden setting item list are hidden in the current user's settings menu and cannot be found in settings search. Even if a setting item is located through some means, it cannot be opened when tapped. If the remaining hidden setting item list is empty after the removal, all setting items are displayed. The settings take effect immediately after the API is called. The Settings application does not need to be restarted.

Since API version 26.0.0, if you call [setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount) to disable [SUPER_HUB](./js-apis-enterprise-restrictions.md#featureforaccount) and then call this API to remove SuperHub from the hidden setting item list, a policy conflict occurs and error code 9200010 is reported.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| menusToHidden | Array\<[SettingsMenu](#settingsmenu24)>          | Yes  | Hidden setting item list.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. <br>Applicable version: 26.0.0+|
| 9200012  | Parameter verification failed.  |
| 9200016  | Service timeout. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let menusToHidden: Array<deviceSettings.SettingsMenu> = [
  // Replace or add items as needed.
  deviceSettings.SettingsMenu.ACCOUNT_ID,
  deviceSettings.SettingsMenu.WIFI,
]

try {
  deviceSettings.removeHiddenSettingsMenu(wantTemp, menusToHidden);
  console.info('Succeeded in removing hidden settings menu.');
} catch (err) {
  console.error(`Failed to remove hidden settings menu. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.getHiddenSettingsMenu<sup>24+</sup>

getHiddenSettingsMenu(admin: Want): Array\<SettingsMenu>

Obtains the hidden setting item list of the current user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array\<[SettingsMenu](#settingsmenu24)> | Hidden setting item list.|

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
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  const rawList: Array<number> = deviceSettings.getHiddenSettingsMenu(wantTemp) as Array<number>;
  for (const item of rawList) {
    const menu: deviceSettings.SettingsMenu = item as deviceSettings.SettingsMenu;
    console.info(`Valid SettingsMenu item: ${item} -> ${menu}`);
  }
  console.info('Succeeded in getting hidden settings menu.');
} catch (err) {
  console.error(`Failed to get hidden settings menu. Code: ${err.code}, message: ${err.message}`);
}
```

## deviceSettings.setSwitchStatus

setSwitchStatus(admin: Want, key: SwitchKey, status: SwitchStatus): void

Sets the state of a switch. This API can enable or disable NearLink, Bluetooth, Wi-Fi, and NFC. After the setting is applied, users can manually enable or disable them. Bluetooth and NFC can be forced on. Once set, they cannot be manually turned on or off by the user. If a switch has been disabled through the [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) API, error code 203 will be reported when you attempt to set the state of the switch through this API. In this case, you need to use the [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) API to enable the switch. When multiple MDM applications are present on the device, there are no conflicts among the switch states set by different MDM applications. The policy set last takes effect. The three states, on (user can manually enable/disable), off (user can manually enable/disable), and forced on (user cannot manually disable), can be switched arbitrarily, and no conflict occurs.

**Since**: 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name  | Type                                          | Mandatory  | Description                                 |
| ------- | ---------------------------------------------- | ---- |------------------------------------------------------------|
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.  |
| key     | [SwitchKey](#switchkey)                        | Yes     | Switch name. An application that has obtained the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and has been activated as the built-in device administrator application via [startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) can use this API to set the following switches: NearLink, Bluetooth, and Wi-Fi. Attempting to set the NFC switch will result in error code 9200002.|
| status  | [SwitchStatus](#switchstatus)                  | Yes     | Switch state. An application that has obtained the ohos.permission.PERSONAL_MANAGE_RESTRICTIONS permission and has been activated as the built-in device administrator application via [startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) can use this API to set the following states: ON and OFF. Attempting to set the FORCE_ON state will result in error code 9200002.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.  |
| 9201042  | Failed to toggle the switch state.  |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { deviceSettings } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace with actual values.
  let key: deviceSettings.SwitchKey = deviceSettings.SwitchKey.BLUETOOTH;
  let status: deviceSettings.SwitchStatus  = deviceSettings.SwitchStatus.ON;
  deviceSettings.setSwitchStatus(wantTemp, key, status);
  console.info(`Succeeded in setting switch status.`);
} catch (err) {
  console.error(`Failed to set switch status. Code: ${err.code}, message: ${err.message}`);
}
```

## SettingsItem<sup>24+</sup>

Policy type.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


| Name| Value  | Description          |
| ---- | ---- | -------------- |
| DEVICE_NAME   | 0    | Device name.|
| FLOATING_NAVIGATION<sup>24+</sup>   | 1   | Three-key navigation.|

## SettingsMenu<sup>24+</sup>

Describes the setting item list.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name  | Value| Description        |
| ------ | ------ | ----------- |
| ACCOUNT_ID                  | 0      | Account.|
| WIFI                        | 1      | Wi-Fi.|
| WIFI_PROXY_SETTINGS         | 2      | WLAN proxy.|
| WIFI_IP_SETTINGS            | 3      | WLAN IP.|
| BLUETOOTH                   | 4      | Bluetooth/NearLink & Bluetooth.|
| NETWORK                     | 5      | Network.|
| MOBILE_NETWORK              | 6      | Mobile network.|
| SUPER_DEVICE                | 7      | More connectivity options - Super Device.|
| MORE_CONNECTIVITY_OPTIONS   | 8      | More connectivity options.|
| HOME_SCREEN_STYLE           | 9      | Home screen & style.|
| DISPLAY_BRIGHTNESS          | 10     | Display & brightness.|
| SOUND_VIBRATION             | 11     | Sounds & vibration.|
| NOTIFICATIONS               | 12     | Notifications & status bar.|
| BIOMETRICS_PASSWORD         | 13     | Biometrics & screen lock.|
| APPS_AND_SERVICES           | 14     | Apps & services.|
| BATTERY                     | 15     | Battery.|
| STORAGE                     | 16     | Storage.|
| PRIVACY_AND_SECURITY        | 17     | Privacy & security.|
| DIGITAL_BALANCE             | 18     | Digital Balance.|
| SMART_ASSISTANT             | 19     | Smart assistant.|
| ACCESSIBILITY               | 20     | Accessibility.|
| SYSTEM                      | 21     | System.|
| ABOUT_DEVICE                | 22     | About.|
| SYSTEM_NAVIGATION           | 23     | System - system navigation.|
| LANGUAGE_REGION             | 24     | System - Language & region.|
| INPUT_METHODS               | 25     | System - Input method.|
| DATE_TIME                   | 26     | System - Date & time.|
| DATA_CLONE                  | 27     | System - Data Clone.|
| BACKUP_SETTINGS             | 28     | System - Backup & Restore.|
| RESET                       | 29     | System - Reset.|
| SUPERHUB                    | 30     | System - SuperHub.|
| USER_EXPERIENCE             | 31     | System - User Experience Improvement Program.|
| SCREEN_CAST                 | 32     | More connectivity options - ScreenCast.|
| PRINTERS_SCANNERS           | 33     | Printers & scanners.|
| MOBILE_DATA                 | 34     | Mobile network - Mobile data.|
| PERSONAL_HOTSPOT            | 35     | Mobile network - Personal hotspot.|
| SIM_MANAGEMENT              | 36     | Mobile network - SIM management.|
| AIRPLANE_MODE               | 37     | Mobile network - Airplane mode.|
| MANAGE_DATA_USAGE           | 38     | Mobile network - Management data usage.|
| VPN_SETTINGS                | 39     | Mobile network - VPN.|
| TEXT_DISPLAY_SIZE           | 40     | Display & brightness - Text & display size.|
| APP_DUPLICATOR              | 41     | System - App duplicator.|
| SEARCH                      | 42     | Search.|

## SwitchKey

Enumerates switch names.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name      | Value  | Description      | Required Permission|
| ---------- | --- | -----------|----------|
| NEARLINK  | 0    | NearLink.| ohos.permission.ENTERPRISE_MANAGE_SETTINGS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
| BLUETOOTH | 1    | Bluetooth.| ohos.permission.ENTERPRISE_MANAGE_SETTINGS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
| WIFI      | 2    | Wi-Fi.| ohos.permission.ENTERPRISE_MANAGE_SETTINGS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
| NFC       | 3    | NFC. | ohos.permission.ENTERPRISE_MANAGE_SETTINGS |

## SwitchStatus

Enumerates switch states.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name| Value  | Description     | Required Permission|
| ----| ---- | ----------|----------|
| ON  | 0    | On.| ohos.permission.ENTERPRISE_MANAGE_SETTINGS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
| OFF | 1    | Off.| ohos.permission.ENTERPRISE_MANAGE_SETTINGS or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS|
| FORCE_ON  | 2    | Forced-on.| ohos.permission.ENTERPRISE_MANAGE_SETTINGS |
