# @ohos.enterprise.systemManager (System Management)

The **systemManager** module provides system management capabilities.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { systemManager } from '@kit.MDMKit';
```

## systemManager.setNTPServer

setNTPServer(admin: Want, server: string): void

Sets the NTP server.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| server | string | Yes| NTP server addresses separated by a comma (,). For example, **ntpserver1.com,ntpserver2.com**. The value can contain a maximum of 96 bytes (including the end character).|

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
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

Obtains the NTP server information.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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

Sets the update policy. In intranet updates, call [systemManager.notifyUpdatePackages](#systemmanagernotifyupdatepackages) to notify the system of the update packages and then call this API to set the upgrade policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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
  "installStartTime": 1716281049, // Timestamp
  "installEndTime": 1716343200, // Timestamp
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
  "delayUpdateTime": 5, // Time for which the update is delayed, in hours.
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

Queries the update policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description              |
| ------ | ------------------------------------------------------- | ---- | ------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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

Notifies the system of the update packages. In intranet updates, call this API to notify the system of the update packages, and then call [systemManager.setOtaUpdatePolicy](#systemmanagersetotaupdatepolicy) to set the update policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| packageInfo  | [UpdatePackageInfo](#updatepackageinfo) | Yes  | Information about the system update packages.|

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
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let notify: systemManager.NotifyDescription = {
  "installTips": "installTips",
  "installTipsDetail": "installTips detail"
}
let description: systemManager.PackageDescription = {
  "notify": notify,
}
let updatePackages: Array<systemManager.Package> = [{
  "type": systemManager.PackageType.FIRMWARE,
  "path": "path",
  "fd": 60,
}]
let updatePackageInfo: systemManager.UpdatePackageInfo = {
  "version" : "1.0",
  "packages" : updatePackages,
  "description" : description,
};
systemManager.notifyUpdatePackages(wantTemp, updatePackageInfo).then(() => {
  console.info('Succeeded in notifying update packages.');
}).catch ((error: BusinessError) => {
  console.error(`Failed to notify update packages. Code is ${error.code},message is ${error.message}`);
});
```

## systemManager.getUpdateResult

getUpdateResult(admin: Want, version: string): Promise&lt;UpdateResult&gt;

Obtains the system update result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
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
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
systemManager.getUpdateResult(wantTemp, "1.0").then((result:systemManager.UpdateResult) => {
    console.info(`Succeeded in getting update result: ${JSON.stringify(result)}`);
  }).catch((error: BusinessError) => {
    console.error(`Get update result failed. Code is ${error.code},message is ${error.message}`);
  });
```
## systemManager.getUpdateAuthData<sup>19+</sup>

getUpdateAuthData(admin: Want): Promise&lt;string&gt;

Obtains the authentication data for system update verification. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

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
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
systemManager.getUpdateAuthData(wantTemp).then((result: string) => {
    console.info(`Succeeded in getting update auth data: ${JSON.stringify(result)}`);
  }).catch((error: BusinessError) => {
    console.error(`Get update auth data failed. Code is ${error.code},message is ${error.message}`);
  });
```
## SystemUpdateInfo

Represents information about the system version to update.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Type    | Read-Only | Optional| Description           |
| ----------------- | ------ | --- | --- |------------- |
| versionName       | string | No  | No|System version to update.  |
| firstReceivedTime | number | No  | No|Time when the system update package is received for the first time.|
| packageType       | string | No  | No|Type of the system update package to update. |

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
| disableSystemOtaUpdate<sup>20+</sup> | boolean   | No  | Yes| Whether to disable public network upgrade. <br>The value **true** means to disable public network upgrade; the value **false** (default) means the opposite. If public network upgrade is disabled, you can perform intranet upgrade.|

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
