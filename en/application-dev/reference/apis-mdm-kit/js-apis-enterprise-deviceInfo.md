# @ohos.enterprise.deviceInfo (Device Information Management)

The deviceInfo module provides APIs for enterprise device information management, including the API for obtaining device serial numbers.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { deviceInfo } from '@kit.MDMKit';
```

## deviceInfo.getDeviceInfo

getDeviceInfo(admin: Want, label: string): string

Obtains device information.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| label  | string                                                  | Yes  | Device information to obtain.<br>- **deviceName**: device name.<br>- **deviceSerial**: device serial number.<br>- **simInfo**: SIM card information.<!--RP1--><!--RP1End-->|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Device information obtained.<br>If **label** is **simInfo**, the return value is the SIM card information in a JSON string. For example, [{"slotId": 0, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": ""}, {"slotId": 1, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": ""}]. <br>**slotId:0** indicates slot 1, and **slotId:1** indicates slot 2.|

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
  let result: string = deviceInfo.getDeviceInfo(wantTemp, 'deviceName');
  console.info(`Succeeded in getting device name, result : ${result}`);
} catch (err) {
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
}
```
