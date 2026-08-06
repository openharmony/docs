# @ohos.enterprise.systemManager (System Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides system management capabilities, including NTP time server settings, OTA update policy management, system update management, key event handling policies, log collection, and device activation lock management. It is suitable for enterprise device management scenarios, helping enterprise administrators uniformly manage device system configurations, update policies, and security policies, thereby improving enterprise device management efficiency and security.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { systemManager } from '@kit.MDMKit';
```

## systemManager.setNTPServer

setNTPServer(admin: Want, server: string): void

Sets the Network Time Protocol (NTP) time server. After successful configuration, the system will use the specified NTP server for time synchronization to calibrate the system time. This API is suitable for scenarios where enterprise devices require unified time synchronization, ensuring that device time remains consistent with standard time and avoiding business issues caused by inaccurate time, such as inconsistent log timestamps and certificate validation failures.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| server | string | Yes| NTP server addresses separated by commas (,). For example, **ntpserver1.com,ntpserver2.com**. The value can contain a maximum of 96 bytes, including the null terminator (**\0**).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let server: string = "ntpserver.com";
try {
  systemManager.setNTPServer(wantTemp, server);
  console.info('Succeeded in setting NTPserver.');
} catch (err) {
  console.error(`Failed to set ntp server. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getNTPServer

getNTPServer(admin: Want): string

Obtains the NTP server information. This API is applicable to scenarios where you need to query the current NTP server address configured on the device, to verify whether the time synchronization configuration is correct, or to obtain the current configuration before making policy adjustments.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| string | NTP server information.|

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
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  systemManager.getNTPServer(wantTemp);
  console.info('Succeeded in getting NTP server.');
} catch (err) {
  console.error(`Failed to get ntp server. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.setOtaUpdatePolicy

setOtaUpdatePolicy(admin: Want, policy: OtaUpdatePolicy): void

Sets the update policy. After the setting is successful, the system performs OTA updates based on the specified policy type. Different policy types correspond to different update behaviors. In intranet updates, call [systemManager.notifyUpdatePackages](#systemmanagernotifyupdatepackages) to notify the system of the update packages and then call this API to set the upgrade policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy exclusivity](../../mdm/mdm-kit-multi-mdm.md#rule-2-policy-exclusivity).

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| policy | [OtaUpdatePolicy](#otaupdatepolicy) | Yes| OTA update policy to set.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Default update policy.
let otaUpdatePolicy1: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.DEFAULT,
  "version": "version_1.0.0.0",
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy1);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// Prohibit update.
let otaUpdatePolicy2: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.PROHIBIT,
  "version": "version_1.0.0.1",
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy2);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// Enforce update. 
let otaUpdatePolicy3: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.UPDATE_TO_SPECIFIC_VERSION,
  "version": "version_1.0.0.2",
  "latestUpdateTime": 1716343200, // Timestamp
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy3);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// Update at the specified time period.
let otaUpdatePolicy4: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.WINDOWS,
  "version": "version_1.0.0.3",
  "installStartTime": 1716281049, // Timestamp.
  "installEndTime": 1716343200, // Timestamp.
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy4);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// Delay the update.
let otaUpdatePolicy5: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.POSTPONE,
  "version": "version_1.0.0.4",
  "delayUpdateTime": 5, // Unit: hour
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy5);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// Disable public network upgrade.
let otaUpdatePolicy6: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.DEFAULT,
  "version": "version_1.0.0.5",
  "disableSystemOtaUpdate": true,
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy6);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getOtaUpdatePolicy

getOtaUpdatePolicy(admin: Want): OtaUpdatePolicy

Checks the update policy. This API is applicable to scenarios where you need to obtain the current OTA update policy configuration of the device, to verify whether the policy is correctly delivered, or to obtain the current policy configuration before making policy adjustments.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description              |
| ------ | ------------------------------------------------------- | ---- | ------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type  | Description                           |
| ------ | ------------------------------- |
| [OtaUpdatePolicy](#otaupdatepolicy) | **OtaUpdatePolicy** object containing the update policy obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let policy: systemManager.OtaUpdatePolicy= systemManager.getOtaUpdatePolicy(wantTemp);
  console.info(`Succeeded in getting update policy: ${JSON.stringify(policy)}`);
} catch (err) {
  console.error(`Failed to get update policy. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.notifyUpdatePackages

notifyUpdatePackages(admin: Want, packageInfo: UpdatePackageInfo): Promise&lt;void&gt;

Notifies the system of the update packages. In intranet updates, call this API to notify the system of the update packages, and then call [systemManager.setOtaUpdatePolicy](#systemmanagersetotaupdatepolicy) to set the update policy. This API uses a promise to return the result.
> **NOTE**
> 
> This API is time-consuming. Subsequent calls to other synchronous APIs in the application main thread must wait for the asynchronous return of this API.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| packageInfo  | [UpdatePackageInfo](#updatepackageinfo) | Yes  | Information about the system update packages.<br>**Note**: The input **UpdatePackageInfo.packages.path** must be a .zip package starting with update. If a file in other formats is input, error code 9201004 will be reported.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object will be thrown if the operation fails.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201004  | The update packages do not exist or analyzing failed. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let notify: systemManager.NotifyDescription = {
  // Replace with actual values.
  "installTips": "installTips",
  "installTipsDetail": "installTips detail"
};
let description: systemManager.PackageDescription = {
  // Replace with actual values.
  "notify": notify
};
let updatePackages: Array<systemManager.Package> = [];
// Replace the application sandbox path with the actual one.
let fileDir = "/xxxx/xxxx/";
let path1: string = "update_sd_base.zip";
let path2: string = "update_sd_cust_xxxxx_all_cn.zip";
let path3: string = "update_sd_preload_xxxxx_all_cn_R1.zip";
let fd1: number = fs.openSync(fileDir + path1, fs.OpenMode.READ_ONLY).fd;
let fd2: number = fs.openSync(fileDir + "xxxxx/" + path2, fs.OpenMode.READ_ONLY).fd;
let fd3: number = fs.openSync(fileDir + "xxxxx/" + path3, fs.OpenMode.READ_ONLY).fd;
let package1: systemManager.Package = {
  // Replace with actual values.
  "type": systemManager.PackageType.FIRMWARE,
  "path": path1,
  "fd": fd1
};
let package2: systemManager.Package = {
  // Replace with actual values.
  "type": systemManager.PackageType.FIRMWARE,
  "path": path2,
  "fd": fd2
};
let package3: systemManager.Package = {
  // Replace with actual values.
  "type": systemManager.PackageType.FIRMWARE,
  "path": path3,
  "fd": fd3
};
updatePackages.push(package1);
updatePackages.push(package2);
updatePackages.push(package3);
let updatePackageInfo: systemManager.UpdatePackageInfo = {
  // Replace with actual values.
  "version" : "1.0",
  "packages" : updatePackages,
  "description" : description
};
systemManager.notifyUpdatePackages(wantTemp, updatePackageInfo).then(() => {
  console.info('Succeeded in notifying update packages.');
}).catch ((error: BusinessError) => {
  console.error(`Failed to notify update packages. Code is ${error.code},message is ${error.message}`);
});
```

## systemManager.getUpdateResult

getUpdateResult(admin: Want, version: string): Promise&lt;UpdateResult&gt;

Obtains the system update result. This API uses a promise to return the result. This API is applicable to scenarios where you need to check whether a system update is successful. It helps enterprise administrators understand the device update status and handle update failures in a timely manner to ensure that the device system version meets enterprise requirements.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| version  | string | Yes  | Version of the update package.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;[UpdateResult](#updateresult)&gt; | Promise used to return the system update result.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
systemManager.getUpdateResult(wantTemp, "1.0").then((result:systemManager.UpdateResult) => {
  console.info(`Succeeded in getting update result: ${JSON.stringify(result)}`);
}).catch((error: BusinessError) => {
  console.error(`Get update result failed. Code is ${error.code},message is ${error.message}`);
});
```
## systemManager.getUpdateAuthData<sup>19+</sup>

getUpdateAuthData(admin: Want): Promise&lt;string&gt;

Obtains the authentication data for system update verification. This API uses a promise to return the result. This API is applicable to intranet update scenarios. Enterprise administrators can use the authentication data to verify the validity and integrity of the system update package, preventing malicious update packages and improving system security.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the authentication data.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
systemManager.getUpdateAuthData(wantTemp).then((result: string) => {
  console.info(`Succeeded in getting update auth data: ${JSON.stringify(result)}`);
}).catch((error: BusinessError) => {
  console.error(`Get update auth data failed. Code is ${error.code},message is ${error.message}`);
});
```

## systemManager.setOtaUpdateNonceEnable

setOtaUpdateNonceEnable(admin: Want, isEnable: boolean): void

Sets whether to enable nonce for OTA update (nonce is enabled by default). When nonce is enabled, the system verifies the validity of the nonce during the OTA update process to prevent replay attacks and enhance system security.
> **NOTE**
> 
> To ensure system security, it is not advised to disable nonce verification unless required by specific use cases such as intranet updates.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices but returns error code 801 on other devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| isEnable | boolean | Yes| The value **true** means to enable nonce for OTA update, and the value **false** means to disable nonce for OTA update.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200016  | Service timeout. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let isEnable: boolean = true;
try {
  systemManager.setOtaUpdateNonceEnable(wantTemp, isEnable);
  console.info('Succeeded in setting OTA update Nonce enable.');
} catch (err) {
  console.error(`Failed to set OTA update Nonce enable. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.isOtaUpdateNonceEnable

isOtaUpdateNonceEnable(admin: Want): boolean

Checks whether nonce is enabled for OTA update. This API is applicable to scenarios where you need to verify the OTA update security configuration on the device. It helps enterprise administrators confirm the status of the nonce verification feature to ensure system update security.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices but returns error code 801 on other devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| boolean | The value **true** means that the nonce for OTA update is enabled, and the value **false** means that the nonce for OTA update is disabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200016  | Service timeout. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: boolean = systemManager.isOtaUpdateNonceEnable(wantTemp);
  console.info(`Succeeded in querying OTA update Nonce enable: ${result}`);
} catch (err) {
  console.error(`Failed to query OTA update Nonce enable. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.addDisallowedNearLinkProtocols<sup>20+</sup>

addDisallowedNearLinkProtocols(admin: Want, protocols: Array&lt;NearLinkProtocol&gt;, accountId: number): void

Adds a list of NearLink protocols that are not allowed to be used for a specified user. NearLink Kit provides a low-power, high-speed short-range communication service that supports connection and data interaction between NearLink devices. <!--RP3--><!--RP3End-->This API does not take effect for system services and system applications such as the keyboard and stylus.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| protocols  | Array&lt;[NearLinkProtocol](#nearlinkprotocol20)&gt;               | Yes  | NearLink protocol list.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|


**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).


| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |


**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace with actual values.
let protocols: systemManager.NearLinkProtocol[] = [systemManager.NearLinkProtocol.SSAP,
  systemManager.NearLinkProtocol.DATA_TRANSFER];

// Replace with actual values.
let accountId: number = 100;

try {
  systemManager.addDisallowedNearLinkProtocols(wantTemp, protocols, accountId);
  console.info('Succeeded in adding the disabled Starlink protocol list for the specified user.');
} catch (err) {
  console.error(`Failed to add the disabled Starlink protocol list for the specified user. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.removeDisallowedNearLinkProtocols<sup>20+</sup>

removeDisallowedNearLinkProtocols(admin: Want, protocols: Array&lt;NearLinkProtocol&gt;, accountId: number): void

Removes the list of disallowed NearLink protocols for a specified user. After successful removal, the specified user can use the removed NearLink protocols for communication again, restoring the corresponding protocol connection capabilities. Use cases: In enterprise device management scenarios, administrators can use this API to remove previously set NearLink protocol disabling policies, allowing users to resume communication between devices via NearLink protocols. This is suitable for scenarios where there is a need to restore NearLink communication capabilities for specific users, helping enterprise administrators flexibly adjust NearLink protocol access permissions of user devices to meet communication requirements in different business scenarios.


**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| protocols  | Array&lt;[NearLinkProtocol](#nearlinkprotocol20)&gt;               | Yes  | NearLink protocol list.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. | 
| 9200012  | Parameter verification failed. |                
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace with actual values.
let protocols: systemManager.NearLinkProtocol[] = [systemManager.NearLinkProtocol.SSAP,
  systemManager.NearLinkProtocol.DATA_TRANSFER];

// Replace with actual values.
let accountId: number = 100;
try {
  systemManager.removeDisallowedNearLinkProtocols(wantTemp, protocols, accountId);
  console.info('Succeeded in removing the disabled Starlink protocol list for the specified user.');
} catch (err) {
  console.error(`Failed to remove the disabled Starlink protocol list for the specified user. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getDisallowedNearLinkProtocols<sup>20+</sup>

getDisallowedNearLinkProtocols(admin: Want, accountId: number): Array&lt;NearLinkProtocol&gt;

Obtains the list of disallowed NearLink protocols for a specified user. This API is applicable to scenarios where there is a need to query the current NearLink protocol access restrictions for a user, helping enterprise administrators verify whether the policy has been correctly applied or obtain the current configuration before making policy adjustments.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                  |
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| Array&lt;[NearLinkProtocol](#nearlinkprotocol20)&gt;          | List of disallowed NearLink protocols for a specified user.|

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
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace with actual values.
let accountId: number = 100;

try {
  let result: systemManager.NearLinkProtocol[] = systemManager.getDisallowedNearLinkProtocols(wantTemp, accountId);
  console.info(`Succeeded in querying the disabled Starlink protocol list for the specified user: ${result}`);
} catch (err) {
  console.error(`Failed to query the disabled Starlink protocol list for the specified user. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.setInstallLocalEnterpriseAppEnabled<sup>20+</sup>

setInstallLocalEnterpriseAppEnabled(admin: Want, isEnable: boolean): void

Sets whether local installation of enterprise applications is supported. When local installation is enabled, users can install enterprise applications (signing certificate distribution type: **enterprise_normal**) by double-tapping their installation packages on enterprise PCs/2-in-1 devices with the local installation capability.<!--RP8--><!--RP8End-->

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices but returns error code 801 on other devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first) If any MDM app supports local installation of enterprise apps, the comprehensive policy is to support local installation of enterprise apps.

**Parameters**

| Name  | Type                                 | Mandatory | Description|
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| isEnable | boolean | Yes| Whether local installation of enterprise applications is supported. The value **true** indicates that the local installation of enterprise applications is supported, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts

import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let isEnable: boolean = true;
try {
  systemManager.setInstallLocalEnterpriseAppEnabled(wantTemp, isEnable);
  console.info('Succeeded in setting InstallLocalEnterpriseAppEnabled.');
} catch (err) {
  console.error(`Failed to set installLocalEnterpriseAppEnabled. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getInstallLocalEnterpriseAppEnabled<sup>20+</sup>

getInstallLocalEnterpriseAppEnabled(admin: Want | null): boolean

Checks whether local installation of enterprise applications is supported. This API is applicable to scenarios where there is a need to verify whether the local installation of enterprise applications is enabled on the device, helping enterprise administrators confirm the policy configuration status to ensure that enterprise applications can be properly installed.<!--RP8--><!--RP8End-->

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices but returns error code 801 on other devices.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>Before API version 24, this API can be called to check whether local installation of enterprise applications is supported. If the device has multiple MDM applications, you can pass **admin** to query the corresponding policies. Since API version 24, **admin** can be set to **null**. In this case, the policies that actually take effect on the device are returned.|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| boolean | Whether local installation of enterprise applications is supported. The value **true** indicates that local installation is supported, and the value **false** indicates the opposite.|

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
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let isEnable: boolean = systemManager.getInstallLocalEnterpriseAppEnabled(wantTemp);
  console.info('Succeeded in getting installLocalEnterpriseAppEnabled.');
} catch (err) {
  console.error(`Failed to get installLocalEnterpriseAppEnabled. Code is ${err.code}, message is ${err.message}`);
}
```
  

## systemManager.setAutoUnlockAfterReboot<sup>20+</sup>

setAutoUnlockAfterReboot(admin: Want, isAllowed: boolean): void

Sets automatic unlocking upon device reboot. This setting takes effect only on devices without a screen lock password. This API is applicable to enterprise unattended devices or scenarios where services need to be quickly restored through a restart, avoiding device downtime caused by manual unlocking, thereby improving device operation and maintenance efficiency and service continuity.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first). If any MDM app sets automatic unlocking upon device restart, the comprehensive policy is automatic unlocking upon device restart.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| isAllowed | boolean | Yes| The value **true** indicates that the device is automatically unlocked after reboot, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let isAllowed: boolean = true;
try {
  systemManager.setAutoUnlockAfterReboot(wantTemp, isAllowed);
  console.info('Succeeded in setting setAutoUnlockAfterReboot.');
} catch (err) {
  console.error(`Failed to set auto unlock after reboot. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getAutoUnlockAfterReboot<sup>20+</sup>

getAutoUnlockAfterReboot(admin: Want | null): boolean

Checks whether the device is automatically unlocked upon reboot. This API is applicable to scenarios where there is a need to verify whether the device reboot unlock policy is correctly configured, helping enterprise administrators confirm the status of the automatic device unlock function.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| boolean | The value **true** indicates the device is automatically unlocked after reboot, and the value **false** indicates the opposite.|

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
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  systemManager.getAutoUnlockAfterReboot(wantTemp);
  console.info('Succeeded in getting auto unlock after reboot.');
} catch (err) {
  console.error(`Failed to get auto unlock after reboot. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.addKeyEventPolicies<sup>23+</sup>

addKeyEventPolicies(admin: Want, keyPolicies: Array&lt;KeyEventPolicy&gt;): void

Adds a key event handling policy. When the system triggers a key event, if the event matches the delivered key event policy, the MDM app will be notified via the [EnterpriseAdminExtensionAbility.onKeyEvent](js-apis-EnterpriseAdminExtensionAbility.md#onkeyevent23) callback, with the key event information of the matched policy carried in the callback.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| keyPolicies     | Array&lt;[KeyEventPolicy](#keyeventpolicy23)&gt; | Yes  | Key policy. Physical keys (power key, volume up, and volume down) and navigation keys (back, home, and recently opened) are supported. Physical keys can be combined into a combination key, but navigation keys cannot. For details about the combination key event response, see the key event callback [onKeyEvent](js-apis-EnterpriseAdminExtensionAbility.md#onkeyevent23).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let keypolicy: Array<systemManager.KeyEventPolicy> = [
  {
    "keyCode": systemManager.KeyCode.POWER,
    "keyPolicy": systemManager.KeyPolicy.CUSTOM
  },
  {
    "keyCode": systemManager.KeyCode.VOLUME_UP,
    "keyPolicy": systemManager.KeyPolicy.CUSTOM
  }
];

try {
  systemManager.addKeyEventPolicies(wantTemp, keypolicy);
  console.info('Succeeded in adding key event policies.');
} catch (err) {
  console.error(`Failed to add key event policies. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.removeKeyEventPolicies<sup>23+</sup>

removeKeyEventPolicies(admin: Want, keyCodes: Array&lt;KeyCode&gt;): void

Removes a key event handling policy. After the deletion is successful, the system restores the default handling behavior for the specified key event. This API is applicable to scenarios where there is a need to restore the default key behavior, helping enterprise administrators flexibly adjust device key response policies to meet the needs of different business scenarios.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| keyCodes    | Array&lt;[KeyCode](#keycode23)&gt; | Yes  | Key code. You can remove multiple key policies at a time. Removing an unsupported key will report error code 9200012.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let keyCodes: Array<systemManager.KeyCode> = [
  systemManager.KeyCode.POWER, systemManager.KeyCode.VOLUME_UP,
];

try {
  systemManager.removeKeyEventPolicies(wantTemp, keyCodes);
  console.info('Succeeded in removing key event policies.');
} catch (err) {
  console.error(`Failed to remove key event policies. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getKeyEventPolicies<sup>23+</sup>

getKeyEventPolicies(admin: Want | null): Array&lt;KeyEventPolicy&gt;

Obtains the key event handling policy. This API is applicable to scenarios where you need to query the current key event handling policy configuration. It helps enterprise administrators verify whether the policy has been correctly applied or obtain the current configuration before making policy adjustments.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| Array&lt;[KeyEventPolicy](#keyeventpolicy23)&gt; | List of currently configured key event policies.|

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
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let result: Array<systemManager.KeyEventPolicy> = [];
try {
  result = systemManager.getKeyEventPolicies(wantTemp);
  console.info('Succeeded in getting key event policies.');
} catch (err) {
  console.error(`Failed to get key event policies. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.startCollectLog<sup>23+</sup>

startCollectLog(admin: Want): Promise&lt;void&gt;

Starts to collect the fault logs of the [FaultType](../apis-performance-analysis-kit/js-apis-faultLogger.md#faulttype) type that have been generated and stored on the device's hard disk. The fault logs, application service logs, and system runtime logs that are not stored on the hard disk cannot be collected.

- After the API is called, the system starts a log collection task. The API returns a response immediately after the task is started. The task may fail due to system performance constraints.
- This API can be called by multiple MDM apps. Logs collected by different MDM apps under different users are saved separately and do not affect each other. Only one MDM app can start a log collection task at a time. If this API is called before the task is complete, the error code 9201009 is returned, and other MDM apps may call the API only after the task finishes.
- Upon task completion, the MDM app is notified via the [EnterpriseAdminExtensionAbility.onLogCollected](js-apis-EnterpriseAdminExtensionAbility.md#onlogcollected23) callback. The system mounts the collected log files to the MDM app sandbox path, enabling the MDM app to read the logs within the callback.
- If the log collection task takes more than 5 minutes, the [EnterpriseAdminExtensionAbility.onLogCollected](js-apis-EnterpriseAdminExtensionAbility.md#onlogcollected23) callback returns a task execution failure message.
- After the app obtains the logs, you are advised to call [systemManager.finishLogCollected](#systemmanagerfinishlogcollected23) to remove the collected logs.

**Required permissions**: ohos.permission.ENTERPRISE_READ_LOG

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: This API can be called by multiple MDM apps. Logs collected by different MDM apps under different users are stored separately and do not affect each other. Only one MDM app can start a log collection task at a time. If this API is called before the task is complete, the error code 9201009 is returned, and other MDM apps may call the API only after the task finishes.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. When a log collection task fails to be created, an error object is thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201009  | Collecting logs, please try again later. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

systemManager.startCollectLog(wantTemp).then(() => {
  console.info('Succeeded in starting collect log');
}).catch((err: BusinessError) => {
  console.error(`Failed to start collect log. Code: ${err.code}, message: ${err.message}`);
});
```

## systemManager.finishLogCollected<sup>23+</sup>

finishLogCollected(admin: Want): void

Deletes the device logs collected by the current MDM app under the current user.

> **NOTE**
> 
> After the app calls [startCollectLog](#systemmanagerstartcollectlog23) to initiate log collection and receives the [EnterpriseAdminExtensionAbility.onLogCollected](js-apis-EnterpriseAdminExtensionAbility.md#onlogcollected23) callback, you are advised to immediately copy or process the logs, and then call this API to delete the collected logs.
> 
> If this API is not called, device logs will occupy the system storage space, which does not affect the next call of [startCollectLog](#systemmanagerstartcollectlog23) to start a log collection task.

**Required permissions**: ohos.permission.ENTERPRISE_READ_LOG

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

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
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  systemManager.finishLogCollected(wantTemp);
  console.info('Succeeded in finishing log collected.');
} catch (err) {
  console.error(`Failed to finish log collected. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.setActivationLockDisabled<sup>24+</sup>

setActivationLockDisabled(admin: Want, isDisabled: boolean, credential?: string): Promise&lt;void&gt;

Enables or disables the device activation lock. After the device activation lock is disabled, the Find Device function will no longer be available. This function is only available on certain devices.<!--RP5--><!--RP5End-->

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| isDisabled | boolean | Yes| Whether to disable the activation lock. The value **true** indicates yes, and the value **false** indicates no.|
| credential | string | No| Credential for disabling the activation lock. To disable the activation lock, you must set this parameter to a valid credential<!--RP6--><!--RP6End-->. Leave this parameter empty when enabling the activation lock.|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object is thrown when the activation lock fails to be enabled or disabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9200016  | Service timeout. |
| 9201011  | The credential of the activation lock is invalid. |
| 9201012  | Failed to enable or disable the activation lock. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let credential: string = "XXX";
let isDisabled: boolean = true;
systemManager.setActivationLockDisabled(wantTemp, isDisabled, credential).then(() => {
  console.info('Succeeded in setting activation lock status.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set activation lock status. Code: ${err.code}, message: ${err.message}`);
});
```

## systemManager.isActivationLockDisabled<sup>24+</sup>

isActivationLockDisabled(admin: Want): Promise&lt;boolean&gt;

Checks whether the device activation lock is disabled. This API is applicable to scenarios where you need to verify the device activation lock status. It helps enterprise administrators confirm the device's security configuration, especially when understanding the activation lock state is necessary for device transfer or recycling.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise used to return whether the device activation lock is disabled. The value **true** indicates that the device activation lock is disabled and the Find Device function cannot be used. The value **false** indicates that the device activation lock is enabled and the Find Device function is available.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200016  | Service timeout. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { systemManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

systemManager.isActivationLockDisabled(wantTemp).then(result => {
  console.info(`Succeeded in getting activation lock status: ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set activation lock status. Code: ${err.code}, message: ${err.message}`);
});
```

## systemManager.setInstallLocalEnterpriseAppEnabledForAccount<sup>24+</sup>

setInstallLocalEnterpriseAppEnabledForAccount(admin: Want, isEnable: boolean, accountId: number): void

Sets whether local installation of enterprise applications is supported for a specified user. After the policy of supporting local enterprise application installation is delivered to a PC/2-in-1 enterprise device that has the local installation capability, the user can double-click an enterprise application installation package on the desktop or in the Files application to install it.<!--RP8--><!--RP8End-->

Only enterprise applications signed with the **enterprise_normal** or **enterprise_mdm** signature type are supported.

> **NOTE**
>
> A PC/2-in-1 enterprise device supports local installation of enterprise applications for the current user if any of the following conditions is met:
>
> 1. The offline installer has been enabled by calling [setInstallLocalEnterpriseAppEnabled](#systemmanagersetinstalllocalenterpriseappenabled20).
> 2. Local installation of enterprise applications is enabled for the current user by calling this API.
<!--RP7--><!--RP7End-->

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices but returns error code 801 on other devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first) If any MDM app supports local installation of enterprise apps, the comprehensive policy is to support local installation of enterprise apps.

**Parameters**

| Name  | Type                                 | Mandatory | Description|
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| isEnable | boolean | Yes| Whether local installation of enterprise applications is supported. The value **true** indicates that the local installation of enterprise applications is supported, and the value **false** indicates the opposite.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 9200012 | Parameter verification failed. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts

import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let isEnable: boolean = true;
let accountId: number = 100;
try {
  systemManager.setInstallLocalEnterpriseAppEnabledForAccount(wantTemp, isEnable, accountId);
  console.info('Succeeded in setting InstallLocalEnterpriseAppEnabledForAccount.');
} catch (err) {
  console.error(`Failed to set installLocalEnterpriseAppEnabledForAccount. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getInstallLocalEnterpriseAppEnabledForAccount<sup>24+</sup>

getInstallLocalEnterpriseAppEnabledForAccount(admin: Want | null, accountId: number): boolean

Checks whether local installation of enterprise applications is supported for a specified user. This API is applicable to scenarios where there is a need to verify whether local installation of enterprise applications is enabled for a specific user, helping enterprise administrators confirm the policy configuration status and ensure that users can normally install enterprise applications.<!--RP8--><!--RP8End-->

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices but returns error code 801 on other devices.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>If the device has multiple MDM applications, you can pass **admin** to query the corresponding policies. If **null** is passed, the policies that actually take effect on the device are returned.|
| accountId | number                                                 | Yes  | User ID, which must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

**Return value**

| Type  | Description                               |
| ------ | ----------------------------------- |
| boolean | Whether local installation of enterprise applications is supported. The value **true** indicates that local installation is supported, and the value **false** indicates the opposite. When **admin** is set to **null**, this API checks whether local installation of enterprise applications is supported.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012 | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let accountId: number = 100;
try {
  let isEnable: boolean = systemManager.getInstallLocalEnterpriseAppEnabledForAccount(wantTemp, accountId);
  console.info('Succeeded in getting installLocalEnterpriseAppEnabled.');
} catch (err) {
  console.error(`Failed to get installLocalEnterpriseAppEnabled. Code is ${err.code}, message is ${err.message}`);
}
```

## SystemUpdateInfo

Represents information about the system version to update.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | --- | --- |------------- |
| versionName       | string | No  | No|System version to update.  |
| firstReceivedTime | number | No  | No|Time when the system update package is received for the first time, in seconds.|
| packageType       | string | No  | No|Type of the system update package to update. The value can be **normal** or **patch**. |

## OtaUpdatePolicy

Represents an OTA update policy.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Type    | Read-Only| Optional| Description                           |
| ----------- | --------| ---- | -----| -------------------------- |
| policyType        | [PolicyType](#policytype)   | No  | No| Type of the update policy.|
| version | string   | No  | No|Version of the software to update.|
| latestUpdateTime        | number   | No  | Yes| Latest update time (timestamp).|
| delayUpdateTime | number   | No  | Yes| Period for which the update is postponed, in hours.|
| installStartTime        | number   | No  | Yes| Start time (timestamp) of the installation window.|
| installEndTime | number   | No  | Yes| End time (timestamp) of the installation window.|
| disableSystemOtaUpdate<sup>20+</sup> | boolean   | No  | Yes| Whether to disable public network upgrade. The value **true** indicates that public network upgrade is disabled, and the value **false** indicates the opposite. If this field is used as an input parameter of [systemManager.setOtaUpdatePolicy](#systemmanagersetotaupdatepolicy), the default value can be retained. The current configuration can be obtained via the [systemManager.getOtaUpdatePolicy](#systemmanagergetotaupdatepolicy) API. After public network upgrade is disabled, you can perform intranet upgrade.<!--RP4--><!--RP4End--> |

## PolicyType

Enumerates the update policy types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| DEFAULT | 0 | Default update policy, which periodically notifies the user of the update and starts the update after user confirmation.|
| PROHIBIT  | 1 | Prohibit updates.|
| UPDATE_TO_SPECIFIC_VERSION | 2 | Enforce updates. In this case, **latestUpdateTime** must be specified.|
| WINDOWS | 3 | Update at the specified time window. In this case, **installStartTime** and **installEndTime** must be specified.|
| POSTPONE | 4 | Postpone updates. After the time specified by **delayUpdateTime** is over, the default update policy is used.|

## UpdatePackageInfo

Represents information about the system update packages.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | --- | ---- |------------- |
| version       | string | No  | No| Version of the system update package.  |
| packages | Array&lt;[Package](#package)&gt; | No  | No| Details about the system update packages.|
| description       | [PackageDescription](#packagedescription) | No  | Yes| Description of the system update packages. |
| authInfo<sup>19+</sup> | string | No| Yes| Authentication information of the system update package.|

## Package

Represents the details about a system update package.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | --- | --- | ------------- |
| type       | [PackageType](#packagetype) | No  | No|  Type of the system update package.  |
| path | string | No  | No| Path of the system update package. If **fd** is specified, pass in the update package name here.|
| fd       | number | No  | Yes| File descriptor (FD) of the system update package. Currently, you cannot pass in **path** only. The **fd** parameter must also be passed in. |

## PackageDescription

Represents the description of a system update package.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | --- | --- | ------------- |
| notify       | [NotifyDescription](#notifydescription) | No  | Yes| Update notification defined by an enterprise.  |

## NotifyDescription

Represents the update notification defined by an enterprise.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type    | Read-Only |  Optional| Description           |
| ----------------- | ------ | --- | ---- | ------------- |
| installTips       | string | No  | Yes| Update tips provided by the enterprise.  |
| installTipsDetail       | string | No  | Yes| Details about the update tips customized by the enterprise.  |

## UpdateResult

Represents the update result information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type  | Read-Only | Optional  | Description           |
| ----------------- | ------ | ------ | ------ | ------------- |
| version       | string |  No| No|Current version of the system.  |
| status       | [UpdateStatus](#updatestatus) | No| No| System update status.  |
| errorInfo       | [ErrorInfo](#errorinfo) | No| No| Error information.  |

## ErrorInfo

Represents the update error information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | ------ | ------ | ------------- |
| code       | number | No| No| Error code.  |
| message       | string | No| No| Error message.  |

## PackageType

Enumerates the update package types.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| FIRMWARE | 1 | Firmware.|

## UpdateStatus

Enumerates the system update statuses.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name              | Value | Description   |
| -----------------  | ---- | ----- |
| NO_UPDATE_PACKAGE  | -4 | The system update package of the specified version does not exist.|
| UPDATE_WAITING     | -3 | The system update package is waiting to be installed.|
| UPDATING           | -2 | The system update is being performed.|
| UPDATE_FAILURE     | -1 | The update failed.|
| UPDATE_SUCCESS     | 0 | The update is successful.|

## NearLinkProtocol<sup>20+</sup>

Enumerates NearLink protocols.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name              | Value | Description   |
| -----------------  | ---- | ----- |
| SSAP   | 0 |  SparkLink Service Access Protocol (SSAP).<!--RP1--><!--RP1End--> |
| DATA_TRANSFER      | 1 | Data transfer protocol.<!--RP2--><!--RP2End--> |

## KeyEventPolicy<sup>23+</sup>

Enumerates key event handling policies. When a key event occurs, only the keys for which the key event handling policy has been delivered are intercepted. For key events where no handling policy has been delivered, the system executes its original response logic.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | ------ | ------ | ------------- |
| keyCode       | [KeyCode](#keycode23) | No| No| Key code.  |
| keyPolicy       | [KeyPolicy](#keypolicy23) | No| No| Key policy.  |

## KeyCode<sup>23+</sup>

Key code. The [addKeyEventPolicies](#systemmanageraddkeyeventpolicies23), [removeKeyEventPolicies](#systemmanagerremovekeyeventpolicies23), [getKeyEventPolicies](#systemmanagergetkeyeventpolicies23), and [onKeyEvent](js-apis-EnterpriseAdminExtensionAbility.md#onkeyevent23) APIs map key codes to the corresponding physical keys on the device.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name              | Value | Description   |
| -----------------  | ---- | ----- |
| POWER    | 0 |  Power key|
| VOLUME_UP       | 1 | Volume up|
| VOLUME_DOWN       | 2 | Volume down|
| BACK       | 3 | Navigation key - back|
| HOME       | 4 | Navigation key - home|
| RECENT       | 5 | Navigation key - recently opened|

## KeyPolicy<sup>23+</sup>

Enumerates key policies. This refers to the system behavior triggered after the key code delivered by the MDM app matches the system key event.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name              | Value | Description   |
| -----------------  | ---- | ----- |
| INTERCEPTION     | 0 |  Intercepts messages. After this parameter is set, only the current key event is intercepted. The system does not process the event, and the key callback API does not respond to the key event. For example, after the power key interception policy is delivered, pressing the power key does not respond, the device cannot be powered off or locked, and only the power key event in the power-on state is affected. When the device is powered off, the power key can be used to power on the device.|
| CUSTOM        | 1 | Intercepts and forwards messages. When this policy is configured, the system intercepts the current key event and does not process the event. In addition, the [EnterpriseAdminExtensionAbility.onKeyEvent](js-apis-EnterpriseAdminExtensionAbility.md#onkeyevent23) callback API is used to notify the MDM app of the key event, which does not block the processing of other events.|

## KeyEvent<sup>23+</sup>

Enumerates key events. When the [EnterpriseAdminExtensionAbility.onKeyEvent](js-apis-EnterpriseAdminExtensionAbility.md#onkeyevent23) key event callback is triggered, the current key event information is transferred.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | ------ | ------ | ------------- |
| keyCode       | [KeyCode](#keycode23) | No| No| Key code.  |
| keyAction       | [KeyAction](#keyaction23) | No| No| Key action.  |
| actionTime       | number | No| No| Time when the key action occurs. The value is a microsecond-level timestamp after the system is powered on. For long-press key events, this parameter remains unchanged in subsequent key events. Apps can use this timestamp to determine whether the event is a long-press event and execute the corresponding long-press event logic accordingly.  |
| keyItems       | Array&lt;[KeyItem](#keyitem23)&gt; | No| No| Information about other keys that are being pressed when the current key event occurs.  |

## KeyAction<sup>23+</sup>

Enumerates key actions.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name              | Value | Description   |
| -----------------  | ---- | ----- |
| UNKNOWN      | -1 |  Any key action other than press and release.|
| DOWN         | 0 | Key press.|
| UP          | 1 | Key release.|

## KeyItem<sup>23+</sup>

Enumerates other key information. This refers to the information of other keys that have been pressed when the current [KeyCode](#keycode23) event occurs.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | ------ | ------ | ------------- |
| keyCode       | [KeyCode](#keycode23) | No| No| Key code.  |
| pressed       | boolean  | No| No| Key action. It indicates whether the key is pressed: **true** for pressed; **false** for released. |
| downTime      | number | No| No| Time when the key action occurs. The value is a microsecond-level timestamp after the system is powered on. Navigation keys do not support combination expansion, so their occurrence time is displayed as 0.|
