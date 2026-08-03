# @ohos.enterprise.locationManager (Location Service Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **locationManager** module provides location service management capabilities for devices, including setting and obtaining the location service policy.

**Use cases:**
This module is applicable to enterprise device management scenarios, where administrators can centrally manage location service policies for devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
> 

## Modules to Import

```ts
import { locationManager } from '@kit.MDMKit';
```

## locationManager.setLocationPolicy

setLocationPolicy(admin: Want, policy: LocationPolicy): void

Sets a location service policy. This API can be used in enterprise management and control scenarios. For example, you can disable the location service in confidential areas to protect information security, or forcibly enable the location service in logistics and distribution applications to track device locations.

> **NOTE**
>
> - Disabled: Set this option when privacy protection or power saving is required.
> - Forced on: Set this option in scenarios such as device security tracking and asset management.
> - Default: This option removes policy restrictions and allows the user to control the setting independently.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_LOCATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy exclusivity](../../mdm/mdm-kit-multi-mdm.md#rule-2-policy-exclusivity).

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.       |
| policy | [LocationPolicy](#locationpolicy) | Yes   | Location service policy to set. The value can be any of the following:<br>- **0**: The default policy is used.<br>- **1**: The location service is disabled.<br>- **2**: The location service is forcibly on.|

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
import { locationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  locationManager.setLocationPolicy(wantTemp, locationManager.LocationPolicy.DISALLOW_LOCATION_SERVICE);
  console.info(`Succeeded in setting location policy.`);
} catch(err) {
  console.error(`Failed to set location policy. Code: ${err.code}, message: ${err.message}`);
}
```
## locationManager.getLocationPolicy

getLocationPolicy(admin: Want | null): LocationPolicy

Queries the location service policy. This API can be used in enterprise device administrator applications to check the current location service policy state of the device, for policy compliance verification or state confirmation before policy adjustment. It is suitable for scenarios such as confirming the current policy configuration, reading the policy state when the device administrator application starts, and checking the policy when troubleshooting location service issues.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_LOCATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                             | Description                                                |
| --------------------------------- | ---------------------------------------------------- |
| [LocationPolicy](#locationpolicy) | Enumerated value of the location service policy. **0**: The default policy is used. **1**: The location service is disabled. **2**: The location service is forcibly on.|

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
import { locationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: locationManager.LocationPolicy = locationManager.getLocationPolicy(wantTemp);
  console.info(`Succeeded in getting location policy. policy: ${result}`);
} catch(err) {
  console.error(`Failed to get location policy. Code: ${err.code}, message: ${err.message}`);
}
```

## LocationPolicy

Enumerates the location service policies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Model restriction**: This API can be used only in the stage model.

| Name                       | Value | Description   |
| ----------------------------| ----| ------------------------------- |
| DEFAULT_LOCATION_SERVICE    | 0   | Default policy. The location service is not restricted and can be controlled by the user.|
| DISALLOW_LOCATION_SERVICE | 1   | The location service is disabled. This policy applies to scenarios where the location service needs to be disabled, such as confidential areas and conference rooms.|
| FORCE_OPEN_LOCATION_SERVICE | 2   | The location service is forcibly enabled. This policy applies to scenarios where the location service needs to be available, such as logistics tracking and field management.|
