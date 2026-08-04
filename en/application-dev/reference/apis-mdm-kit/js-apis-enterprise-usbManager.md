# @ohos.enterprise.usbManager (USB Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **usbManager** module provides APIs for USB management.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>
> The global restriction policy is provided by **restrictions**. To disable USB globally, see [@ohos.enterprise.restrictions (restriction policy)](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { usbManager } from '@kit.MDMKit';
```

## usbManager.addAllowedUsbDevices

addAllowedUsbDevices(admin: Want, usbDeviceIds: Array\<UsbDeviceId>): void

Adds allowed USB devices.

**Use cases:**
- Restrict access to only specific USB devices in enterprise security management scenarios.
- Enable device administrators to precisely control which USB devices can be recognized and used.
- Work with the [removeAllowedUsbDevices](#usbmanagerremoveallowedusbdevices) API to implement dynamic management of USB devices.

A policy conflict is reported when this API is called in the following scenarios:

1. The USB capability or the USB-to-serial capability of the device has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. The USB storage device access policy has been disabled using the [setUsbStorageDeviceAccessPolicy](#usbmanagersetusbstoragedeviceaccesspolicy) API.
3. Disallowed USB device types have been added using the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) API.
4. Disallowed USB device types have been added via [addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices).

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | Yes  | USB device IDs, which can be obtained through [getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices). The maximum number of USB devices is 1,000. If there are already 300 USB device IDs, only 700 more can be added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200007 | The system ability works abnormally. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
    vendorId: 1,
    productId: 1
  }];
  usbManager.addAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in adding allowed USB devices.`);
} catch (err) {
  console.error(`Failed to add allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeAllowedUsbDevices

removeAllowedUsbDevices(admin: Want, usbDeviceIds: Array\<UsbDeviceId>): void

Removes allowed USB devices.

**Use cases:**
- Revoke access permissions for certain USB devices in enterprise security management scenarios.
- Enable device administrators to dynamically adjust the list of allowed USB devices.
- Remove USB devices from the trustlist when they are no longer needed or pose a security risk.

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | Yes  | USB device IDs, which can be obtained through [getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices).|

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
    vendorId: 1,
    productId: 1
  }];
  usbManager.removeAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in removing allowed USB devices.`);
} catch (err) {
  console.error(`Failed to remove allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getAllowedUsbDevices

getAllowedUsbDevices(admin: Want | null): Array\<UsbDeviceId>

Obtains allowed USB devices.

**Use cases:**
- Retrieve the existing policy for evaluation before making any modifications.
- Display the current USB storage device access control status on the management page.

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| Array<[UsbDeviceId](#usbdeviceid)> | Array of device IDs in the USB device trustlist.|

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<usbManager.UsbDeviceId> = usbManager.getAllowedUsbDevices(wantTemp);
  console.info(`Succeeded in getting allowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.setUsbStorageDeviceAccessPolicy

setUsbStorageDeviceAccessPolicy(admin: Want, usbPolicy: UsbPolicy): void

Sets the USB storage device (baseClass = 0x08) access policy.

> **NOTE**
> Before calling the API, read and write operations on the USB storage device should be suspended to ensure operational stability and data integrity. Otherwise, unexpected exceptions may occur.

A policy conflict occurs when you set the USB storage device access policy to read, write, or read-only in the following scenarios:

1. The USB capability of the device has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. The USB storage device has been disallowed to use through [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14).
3. The USB storage write capability has been disabled for specific users via [setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated).

A policy conflict is reported if the USB storage device access policy is disabled by calling this API in the following scenarios:

1. The USB capability of the device has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. The available USB devices have been added through [addAllowedUsbDevices](#usbmanageraddallowedusbdevices).
3. The USB storage write capability has been disabled for specific users via [setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated).

You can disable a USB storage device by calling this API or [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14). The latter is recommended.

**Required permissions**:

- Before API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_USB
- Since API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_USB or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS (The application is activated as a built-in device administrator application via the [adminManager.startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) API.)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first). The strict priority is as follows: disabled > read-only > read and write.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                  |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| usbPolicy | [UsbPolicy](#usbpolicy)                                 | Yes  | Access policy of the USB storage device.                 |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200007 | The system ability works abnormally. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.DISABLED;
  usbManager.setUsbStorageDeviceAccessPolicy(wantTemp, policy);
  console.info(`Succeeded in setting USB storage device access policy.`);
} catch (err) {
  console.error(`Failed to set USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getUsbStorageDeviceAccessPolicy

getUsbStorageDeviceAccessPolicy(admin: Want | null): UsbPolicy

Obtains the USB storage device (baseClass = 0x08) access policy.

**Required permissions**:

- Before API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_USB
- Since API version 26.0.0: ohos.permission.ENTERPRISE_MANAGE_USB or ohos.permission.PERSONAL_MANAGE_RESTRICTIONS (The application is activated as a built-in device administrator application via the [adminManager.startAdminProvision](./js-apis-enterprise-adminManager.md#adminmanagerstartadminprovision15) API.)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                   | Description                 |
| ----------------------- | --------------------- |
| [UsbPolicy](#usbpolicy) | Access policy of the USB storage device. The value **READ_WRITE** indicates that the USB storage device can be read and written. The value **READ_ONLY** indicates that the USB storage device can only be read. The value **DISABLED** indicates that access to the USB storage device cannot be accessed.|

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: usbManager.UsbPolicy = usbManager.getUsbStorageDeviceAccessPolicy(wantTemp);
  console.info(`Succeeded in getting USB storage device access policy. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.addDisallowedUsbDevices<sup>14+</sup>

addDisallowedUsbDevices(admin: Want, usbDevices: Array\<UsbDeviceType>): void

Adds disallowed USB device types.

**Use cases:**
- Disable specific types of USB devices in enterprise security management scenarios.
- Prevent data leaks by disabling USB storage device types.
- Enable device administrators to prohibit the use of certain USB device types based on security policies.
- Work with the [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to implement dynamic management of USB device types.

> **NOTE**
>
> The [addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices) API is recommended.

A policy conflict is reported when this API is called in the following scenarios:

1. The USB capability of the device has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
2. The available USB devices have been added through [addAllowedUsbDevices](#usbmanageraddallowedusbdevices).
3. The USB storage write capability has been disabled for specific users via [setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated).
4. Disallowed USB device types have been added via [addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices).

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | Yes  | Array of the USB devices to be added, which can be obtained through [getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices). The maximum number of USB devices is 200. If there are already 100 USB device IDs, only 100 more can be added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDevices: Array<usbManager.UsbDeviceType> = [{
    baseClass: 8,
    subClass: 0,
    protocol: 0,
    descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.addDisallowedUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in adding disallowed USB devices.`);
} catch (err) {
  console.error(`Failed to add disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeDisallowedUsbDevices<sup>14+</sup>

removeDisallowedUsbDevices(admin: Want, usbDevices: Array\<UsbDeviceType>): void

Removes the disallowed USB device types.

**Use cases:**
- Lifts the restriction on certain USB device types in enterprise security management scenarios.
- Enable device administrators to dynamically adjust the list of disallowed USB device types.
- Remove USB device types from the blocklist when they no longer pose a security risk.

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | Yes  | Array of the USB devices to be removed, which can be obtained through [getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices).|

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDevices: Array<usbManager.UsbDeviceType> = [{
    baseClass: 8,
    subClass: 0,
    protocol: 0,
    descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.removeDisallowedUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in removing disallowed USB devices.`);
} catch (err) {
  console.error(`Failed to remove disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getDisallowedUsbDevices<sup>14+</sup>

getDisallowedUsbDevices(admin: Want | null): Array\<UsbDeviceType>

Obtains the disallowed USB device types.

**Use cases:**
- Retrieve the current list of disallowed USB device types for review by the device administrator.
- Obtain the existing blocklist for comparison before making any modifications.
- Display the current USB device type restriction policy configuration on the management page.

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                                    | Description                   |
| ---------------------------------------- | ----------------------- |
| Array<[UsbDeviceType](#usbdevicetype14)> | Disallowed USB device types obtained.|

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<usbManager.UsbDeviceType> = usbManager.getDisallowedUsbDevices(wantTemp);
  console.info(`Succeeded in getting disallowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.addDisallowedPermissiveUsbDevices

addDisallowedPermissiveUsbDevices(admin: Want, usbDevices: Array\<PermissiveUsbDeviceType>): void

Adds disallowed USB device types. Unlike the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) API, this API does not require matching based on the [defined-class-codes](https://www.usb.org/defined-class-codes) standard. This API takes effect immediately on connected USB devices without requiring re-plugging. For example, if a USB wired headset is in normal use and this API is called to disable it, the headset will become unavailable immediately.

A policy conflict is reported when this API is called in the following scenarios:

1. Disallowed USB device types have been added using the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) API.
2. The USB capability of the device has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated).
3. The available USB devices have been added through [addAllowedUsbDevices](#usbmanageraddallowedusbdevices).
4. The USB storage write capability has been disabled for specific users via [setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated).

**Since:** 26.0.0

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name    | Type                                                    | Mandatory| Description|
| ---------- | ------------------------------------------------------- | ---- | ---- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| usbDevices | Array\<[PermissiveUsbDeviceType](#permissiveusbdevicetype)> | Yes  | Array of USB device types to be added. Partial field matching is supported. The array can have a maximum of 1000 elements. If there are already 500 USB device IDs in the array, only 500 more can be added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Disable USB storage devices (use the actual USB device type parameter).
  let usbDevices1: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 8
  }];
  usbManager.addDisallowedPermissiveUsbDevices(wantTemp, usbDevices1);

  // Disable USB wired headsets (use the actual USB device type parameter).
  let usbDevices2: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 0,
    subClass: 0,
    protocol: 0,
    descriptor: usbManager.Descriptor.DEVICE
  }];
  usbManager.addDisallowedPermissiveUsbDevices(wantTemp, usbDevices2);

  // Disable USB wired keyboard input (use the actual USB device type parameter).
  let usbDevices3: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 3,
    subClass: 1,
    protocol: 1,
    descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.addDisallowedPermissiveUsbDevices(wantTemp, usbDevices3);
  console.info(`Succeeded in adding disallowed permissive USB devices.`);
} catch (err) {
  console.error(`Failed to add disallowed permissive USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeDisallowedPermissiveUsbDevices

removeDisallowedPermissiveUsbDevices(admin: Want, usbDevices: Array\<PermissiveUsbDeviceType>): void

Removes the USB device types that have been disallowed via [addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices). The removed USB device types can be used normally.

**Since:** 26.0.0

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name    | Type                                                      | Mandatory| Description|
| ---------- | --------------------------------------------------------- | ---- | ----- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md)   | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| usbDevices | Array\<[PermissiveUsbDeviceType](#permissiveusbdevicetype)> | Yes  | Array of USB device types to be removed.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let usbDevices: Array<usbManager.PermissiveUsbDeviceType> = [{
    baseClass: 8
  }];
  usbManager.removeDisallowedPermissiveUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in removing disallowed permissive USB devices.`);
} catch (err) {
  console.error(`Failed to remove disallowed permissive USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getDisallowedPermissiveUsbDevices

getDisallowedPermissiveUsbDevices(admin: Want | null): Array\<PermissiveUsbDeviceType>

Obtains the USB device types that have been disallowed via [addDisallowedPermissiveUsbDevices](#usbmanageradddisallowedpermissiveusbdevices).

**Since:** 26.0.0

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description|
| ------ | ------------------------------------------------------- | ---- | ----- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application. If the value is null, the disallowed USB device types on the current device are to be obtained.|

**Return value**

| Type                                                    | Description                        |
| -------------------------------------------------------- | ---------------------------- |
| Array\<[PermissiveUsbDeviceType](#permissiveusbdevicetype)> | Array of disallowed USB device types.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<usbManager.PermissiveUsbDeviceType> = usbManager.getDisallowedPermissiveUsbDevices(wantTemp);
  console.info(`Succeeded in getting disallowed permissive USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed permissive USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## UsbDeviceId

Represents the USB device identity information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name     | Type  | Read-Only| Optional| Description    |
| --------- | ------ | ---- | ---- | -------- |
| vendorId  | number | No  | No| Vendor ID.|
| productId | number | No  | No| Product ID.|

## UsbDeviceType<sup>14+</sup>

Represents the USB device type information.

You can obtain the list of USB devices connected to the host device through the [getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices) API, and then find the type of the current device in the returned list.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name      | Type                       | Read-Only| Optional| Description                                                        |
| ---------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| baseClass  | number                      | No  | No| Type code.<br>First, determine the type of descriptor to pass in based on this value. If the descriptor is **DEVICE**, this field takes the value of the **USBDevice.clazz** field; if the descriptor is **INTERFACE**, this field takes the value of the **USBDevice.configs.interfaces.clazz** field.<br>If the field value is 255 (indicating the device's type code is a vendor-defined code), calling the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) or [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to enable or disable the device will not take effect. If the field value is not defined in [defined-class-codes](https://www.usb.org/defined-class-codes), calling the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) or [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to enable or disable the device will also not take effect.|
| subClass   | number                      | No  | No| Subtype code.<br>First, determine the type of descriptor to pass in based on the value of baseClass. If the descriptor is **DEVICE**, this field takes the value of the **USBDevice.subClass** field; if the descriptor is **INTERFACE**, this field takes the value of the **USBDevice.configs.interfaces.subClass** field.<br>If the field value is 255 (indicating that the subtype code of the device is a vendor-defined code), calling the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) or [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to enable or disable the device will not take effect. If the field value is not defined in [defined-class-codes](https://www.usb.org/defined-class-codes), calling the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) or [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to enable or disable the device will also not take effect.|
| protocol   | number                      | No  | No| Protocol code.<br>First, determine the type of descriptor to pass in based on the value of baseClass. If the descriptor is **DEVICE**, this field takes the value of the **USBDevice.protocol** field; if the descriptor is **INTERFACE**, this field takes the value of the **USBDevice.configs.interfaces.protocol** field.<br>If the field value is 255 (indicating the device's protocol code is a vendor-defined code), calling the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) or [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to enable or disable the device will not take effect. If the field value is not defined in [defined-class-codes](https://www.usb.org/defined-class-codes), calling the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) or [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to enable or disable the device will also not take effect.|
| descriptor | [Descriptor](#descriptor14) | No  | No| USB descriptor.<br>If the value of **USBDevice.clazz** is **0**, you need to find the value of **USBDevice.configs.interfaces.clazz** in the Base Class column in [defined-class-codes](https://www.usb.org/defined-class-codes). The Descriptor Usage column in the row where the search result is located indicates the descriptor type to be transferred. If the value of Descriptor Usage is **Both**, both types can be transferred. If device-level disabling is required, transfer **DEVICE**. If interface-level disabling is required, transfer **INTERFACE**.<br>If the value of **USBDevice.clazz** is **255** (indicating the device's type code is a vendor-defined code), calling the [addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14) or [removeDisallowedUsbDevices](#usbmanagerremovedisallowedusbdevices14) API to enable or disable the device will not take effect. If the value of **USBDevice.clazz** is another value, search for the value in the Base Class column of [defined-class-codes](https://www.usb.org/defined-class-codes). The Descriptor Usage column in the row where the search result is located indicates the descriptor type to be transferred. If the value of Descriptor Usage is **Both**, both types can be transferred. If device-level disabling is required, transfer **DEVICE**. If interface-level disabling is required, transfer **INTERFACE**.|

## UsbPolicy

Enumerates the USB storage device access policies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| READ_WRITE | 0    | Read and write.|
| READ_ONLY  | 1    | Read only.    |
| DISABLED   | 2    | Disabled.    |

## Descriptor<sup>14+</sup>

Enumerates USB descriptors.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name     | Value  | Description        |
| --------- | ---- | ------------ |
| INTERFACE | 0    | Interface descriptor.|
| DEVICE    | 1    | Device descriptor.|

## PermissiveUsbDeviceType

USB device type information. Partial field matching is supported.

- Compared with [UsbDeviceType](#usbdevicetype14), the **subClass**, **protocol**, and **descriptor** parameters in this API are optional, allowing for more flexible USB device disabling policies.

- Only the matching based on the **baseClass** parameter is supported.

- Multiple parameters can be configured. All parameters must be satisfied simultaneously for a match.

- You can obtain the list of USB devices connected to the host device through the [getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices) API, and then find the type of the current device in the returned list.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name      | Type                       | Read-Only| Optional| Description                                                        |
| ---------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| baseClass  | number                      | No  | No  | Type code. The value range is [0, 255].<br>If **descriptor** is **DEVICE**, this parameter takes the value of the **USBDevice.clazz** parameter; if **descriptor** is **INTERFACE**, this parameter takes the value of the **USBDevice.configs.interfaces.clazz** parameter.|
| subClass   | number                      | No  | Yes  | Subtype code. The value range is [0, 255].<br>If **descriptor** is **DEVICE**, this parameter takes the value of the **USBDevice.subClass** parameter; if **descriptor** is **INTERFACE**, this parameter takes the value of the **USBDevice.configs.interfaces.subClass** parameter.|
| protocol   | number                      | No  | Yes  | Protocol code. The value range is [0, 255].<br>If **descriptor** is **DEVICE**, this parameter takes the value of the **USBDevice.protocol** parameter; if **descriptor** is **INTERFACE**, this parameter takes the value of the **USBDevice.configs.interfaces.protocol** parameter.|
| descriptor | [Descriptor](#descriptor14) | No  | Yes  | USB descriptor.<br>If **USBDevice.clazz** is **0**, locate the value of **USBDevice.configs.interfaces.clazz** in the **Base Class** column of the [defined-class-codes](https://www.usb.org/defined-class-codes) table. The **Descriptor Usage** column of the corresponding row indicates the descriptor type to be passed. (If **Descriptor Usage** is **Both**, either type can be passed. You can pass **DEVICE** for device-level disabling, or **INTERFACE** for interface-level disabling.) If **USBDevice.clazz** is other than **0**, locate that value in the **Base Class** column of the [defined-class-codes](https://www.usb.org/defined-class-codes) table. The **Descriptor Usage** column of the corresponding row indicates the descriptor type to be passed. (If **Descriptor Usage** is **Both**, either type can be passed. Pass **DEVICE** for device-level disabling, or **INTERFACE** for interface-level disabling.)|
