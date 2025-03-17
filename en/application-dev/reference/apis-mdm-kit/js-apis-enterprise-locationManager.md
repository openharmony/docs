# @ohos.enterprise.locationManager (Location Service Management)

The **locationManager** module provides location service management capabilities for devices, including setting and obtaining the location service policy.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.
> 

## Modules to Import

```ts
import { locationManager } from '@kit.MDMKit';
```

## locationManager.setLocationPolicy

setLocationPolicy(admin: Want, policy: LocationPolicy): void

Sets the location service policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_LOCATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| policy | [LocationPolicy](#locationpolicy) | Yes   | Location service policy to set. The value can be any of the following:<br>- **0**: The default policy is used.<br>- **1**: The location service is disabled.<br>- **2**: The location service is forcibly enabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { locationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    locationManager.setLocationPolicy(wantTemp, locationManager.LocationPolicy.DISALLOW_LOCATION_SERVICE);
    console.info(`Succeeded in setting location patch tag.`);
} catch(err) {
    console.error(`Failed to get location patch tag. Code: ${err.code}, message: ${err.message}`);
}
```
## locationManager.getLocationPolicy

getLocationPolicy(admin: Want): LocationPolicy

Queries the location service policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_LOCATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility.       |

**Return value**

| Type                             | Description                                                |
| --------------------------------- | ---------------------------------------------------- |
| [LocationPolicy](#locationpolicy) | Enumerated value of the location service policy. **0**: The default policy is used. **1**: The location service is disabled. **2**: The location service is forcibly enabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { locationManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: locationManager.LocationPolicy = locationManager.getLocationPolicy(wantTemp);
    console.info(`Succeeded in getting location policy. policy: ${result}`);
} catch(err) {
    console.error(`Failed to get device encryption status. Code: ${err.code}, message: ${err.message}`);
}
```

## LocationPolicy

Enumerates the location service policies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Model restriction**: This API can be used only in the stage model.

| Name                       | Value | Description   |
| ----------------------------| ----| ------------------------------- |
| DEFAULT_LOCATION_SERVICE    | 0   | Default policy.|
| DISALLOW_LOCATION_SERVICE | 1   | The location service is disabled.|
| FORCE_OPEN_LOCATION_SERVICE | 2   | The location service is forcibly enabled.|
