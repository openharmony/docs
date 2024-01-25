# @ohos.enterprise.locationManager (Location Service Management)

The **locationManager** module provides location service management capabilities for devices, including setting and obtaining the location service policy.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import locationManager from '@ohos.enterprise.locationManager';
```

## locationManager.setLocationPolicy

setLocationPolicy(admin: Want, policy: LocationPolicy): void

Sets the location service policy. This API returns the result synchronously. If the operation fails, an exception will be thrown.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_LOCATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| policy | [LocationPolicy](js-apis-enterprise-locationManager.md) | Yes   | Location service policy to set. The value can be any of the following:<br>- **0**: default policy.<br>- **1**: The location service is disabled.<br>- **2**: The location service is forcibly enabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import locationManager from '@ohos.enterprise.locationManager';

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

Obtains the location service policy. This API returns the result synchronously. If the operation is successful, the location service policy is returned. If the operation fails, an exception will be thrown.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_LOCATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |

**Return value**

| Type            | Description                                                  |
| ---------------- | ------------------------------------------------------ |
| LocationPolicy | Location service policy obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import locationManager from '@ohos.enterprise.locationManager';
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

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

| Name                       | Value | Description   |
| ----------------------------| ----| ------------------------------- |
| DEFAULT_LOCATION_SERVICE    | 0   | Default policy.|
| DISALLOW_LOCATION_SERVICE | 1   | The location service is disabled.|
| FORCE_OPEN_LOCATION_SERVICE | 2   | The location service is forcibly enabled.|
