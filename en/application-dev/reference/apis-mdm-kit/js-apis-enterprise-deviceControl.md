# @ohos.enterprise.deviceControl (Device Control)

The **deviceControl** module provides APIs for device control.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { deviceControl } from '@kit.MDMKit';
```

## deviceControl.operateDevice

operateDevice(admin: Want, operate: string, addition?: string): void

Allows the specified device administrator application to operate devices.

**Required permissions**: ohos.permission.ENTERPRISE_OPERATE_DEVICE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| operate  | string                                                  | Yes  | Operation to be performed, which can be any of the following:<br>- **resetFactory**: restore device factory settings.<br>- **reboot**: restart devices.<br>- **shutDown**: shut down devices.<br>- **lockScreen**: lock device screens.<!--RP1--><!--RP1End-->|
| addition | string                                                  | No  | <!--RP2-->Additional parameter for the operation. Currently, this parameter does not need to be passed in.<!--RP2End-->       |

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
import { deviceControl } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  deviceControl.operateDevice(wantTemp, 'resetFactory');
} catch (err) {
  console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);
}
```
