# @ohos.enterprise.deviceControl (Device Control Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides device control capabilities for enterprise device management scenarios. Administrators can remotely control devices through this module, including operations such as device restart, shutdown, screen lock, and factory reset, helping enterprises achieve unified device management and security control.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { deviceControl } from '@kit.MDMKit';
```

## deviceControl.operateDevice

operateDevice(admin: Want, operate: string, addition?: string): void

Allows administrators to perform operations such as factory reset, restart, shutdown, and screen lock on devices. For example, in enterprise device management scenarios, administrators can remotely control employee devices to perform factory reset, restart, shutdown, or screen lock operations.

**Required permissions**: ohos.permission.ENTERPRISE_OPERATE_DEVICE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

<!--Table: 10%; 10%; 10%; 70%-->
| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| operate  | string                                                  | Yes  | Operation to be performed, which can be any of the following: Only the following operations are supported:<br>- **resetFactory**: restore device factory settings. After this API is called, the device will be restored to factory settings immediately. Once the restoration is complete, all device data will be erased and cannot be restored. To protect against data loss caused by potential application attacks, enterprises should implement robust security measures for their applications. If factory reset has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated), enable it first.<br>- **reboot**: restart devices.<br>- **shutDown**: shut down devices.<br>- **lockScreen**: lock the device screen.<!--RP1--><!--RP1End-->|
| addition | string                                                  | No  | <!--RP2-->Additional parameter for the operation. This parameter is reserved and does not need to be passed.<!--RP2End-->       |

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
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace the parameters as required.
  deviceControl.operateDevice(wantTemp, 'resetFactory');
} catch (err) {
  console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);
}
```

## deviceControl.operateDevice

operateDevice(admin: Want, operation: Operation, addition?: string): void

Allows the administrator to operate devices, for example, erasing disks.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_OPERATE_DEVICE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

<!--Table: 10%; 10%; 10%; 70%-->
| Name   | Type                                                    | Mandatory| Description                                                        |
| --------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| operation | [Operation](#operation)                                  | Yes  | Operation to be performed, which can be any of the following:                                              |
| addition  | string                                                   | No  | Additional parameter for the operation. When the operation type is disk erasure, the additional parameter is the sandbox path of the image. If a message needs to be displayed to the user after the disk erasure is successfully completed, this parameter can be set to deliver the information. The image size must be less than 5 KB (a QR code image is recommended). The length limit is 1024 bytes.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010 | A conflict policy has been configured. |
| 9200012  | Parameter verification failed.|
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { deviceControl } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let filePath: string = '/test.png';

try {
  // Replace the parameters as required.
  deviceControl.operateDevice(wantTemp, deviceControl.Operation.DISK_ERASURE, filePath);
} catch (err) {
  console.error(`Failed to disk erase. Code is ${err.code}, message is ${err.message}`);
}
```

## Operation

Defines the device operation.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name         | Value  | Description                                                        |
| ------------- | ---- | ------------------------------------------------------------ |
| DISK_ERASURE  | 0    | Disk erasure. After this API is called, the device immediately performs a disk erasure operation. Once completed, all data on the device will be erased and cannot be recovered. To protect against data loss caused by potential application attacks, enterprises should implement robust security measures for their applications. It is support only on PCs/2-in-1 devices.|
