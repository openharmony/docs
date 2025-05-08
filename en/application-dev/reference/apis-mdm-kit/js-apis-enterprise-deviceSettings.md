# @ohos.enterprise.deviceSettings (Device Settings)

The **deviceSettings** module provides APIs for setting enterprise devices, including obtaining the screen-off time of a device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { deviceSettings } from '@kit.MDMKit';
```

## deviceSettings.setValue

setValue(admin: Want, item: string, value: string): void

Sets a device setting policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| item   | string                                                  | Yes  | Type of the policy to set.<br>- **screenOff**: screen-off policy. For 2-in-1 devices, only the screen-off policy in battery mode can be set.<br>- **dateTime**: system time settings.<br>- powerPolicy: device power policy. For 2in1 devices, only the power policy in battery mode can be set.|
| value  | string                                                  | Yes  | Policy to set.<br>If **item** is **screenOff**, **value** is the screen-off time, in ms.<br>If **item** is **dateTime**, **value** is the system time to set, in ms.<br>If **item** is **powerPolicy**, **value** is a JSON string in {"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}} format. **powerScene** specifies the power policy scenario; **delayTime** specifies the delay time in ms (it cannot be set to 30000 ms); **powerPolicyAction** specifies the sleep policy.<br>The value of **powerScene** can be:<br>- **0**: timeout.<br>The value of **powerPolicyAction** can be:<br>- **0**: No action is performed.<br>- **1**: enter sleep mode automatically.<br>- **2**: forcibly enter sleep mode.<br>- **3**: enter sleep mode (not supported by the power subsystem currently).<br>- **4**: power off.|

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

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| item   | string                                                  | Yes  | Type of the policy to set.<br>- **screenOff**: screen-off policy of a device. For a 2-in-1 device, only the screen-off policy in battery mode can be obtained.<br>- **dateTime**: system time settings.<br>- **powerPolicy**: device power policy. For 2-in-1 devices, only the power policy in battery mode can be obtained.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Policy obtained.<br>If **item** is **screenOff**, the device screen-off time (in ms) is returned. For a 2-in-1 device, the device screen-off time (in ms) in battery mode is returned.<br>If **item** is **dateTime**, the system time (in ms) is returned.<br>If **item** is **powerPolicy**, the power policy is returned. For a 2-in-1 device, the power policy in battery mode is returned. The power policy a JSON string in {"powerScene":xx,"powerPolicy":{"powerPolicyAction":xx,"delayTime":xx}} format. **powerScene** indicates the power policy scenario, **delayTime** indicates the delay time (in ms), and **powerPolicyAction** indicates the sleep policy.<br>The value of **powerScene** can be:<br>- **0**: timeout.<br>The value of **powerPolicyAction** can be:<br>- **0**: No action is performed.<br>- **1**: enter sleep mode automatically.<br>- **2**: forcibly enter sleep mode.<br>- **3**: enter sleep mode (not supported by the power subsystem currently).<br>- **4**: power off.|

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
  let result: string = deviceSettings.getValue(wantTemp, 'screenOff');
  console.info(`Succeeded in getting screen off time, result : ${result}`);
} catch (err) {
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
}
```
