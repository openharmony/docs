# @ohos.enterprise.deviceInfo (Device Information Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides APIs for enterprise device information management, including obtaining device serial numbers, device names, and SIM card information. Enterprise administrators can use this module to query device details, enabling unified management and tracking of device assets.

**Use cases:**
- Device asset management and tracking
- Enterprise device compliance check
- Device information collection and statistics
- Fault diagnosis and device identification

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { deviceInfo } from '@kit.MDMKit';
```

## deviceInfo.getDeviceInfo

getDeviceInfo(admin: Want, label: string): string

Obtains device information.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Enterprise device management extension component, which is used to specify the target application that has the device management capability. The **Want** object must contain **abilityName** (extended ability name) and **bundleName** (application bundle name) parameters.                                              |
| label  | string                                                  | Yes  | Device information label that can be obtained.<br>- **deviceName**: device name.<br>- **deviceSerial**: device serial number.<br>- **simInfo**: SIM card information.<!--RP1--><!--RP1End-->|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| string | Device information obtained.<br>If **label** is **simInfo**, the return value is the SIM card information in a JSON string. For example, [{"slotId": 0, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": "", "NUMBER": ""}, {"slotId": 1, "MEID": "", "IMSI": "", "ICCID": "", "IMEI": "", "NUMBER": ""}], where **slotId:0** indicates card slot 1, and **slotId:1** indicates card slot 2. **NUMBER** indicates the phone number and is supported since API version 23. The value is in the E.164 international standard format (for example, +8612345678901) that contains the country code.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200007 | The system ability works abnormally. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace with actual values.
  let result: string = deviceInfo.getDeviceInfo(wantTemp, 'deviceName');
  console.info(`Succeeded in getting device name, result : ${result}`);
} catch (err) {
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
}
```
