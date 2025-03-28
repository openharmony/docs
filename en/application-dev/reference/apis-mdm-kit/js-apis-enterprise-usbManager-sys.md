# @ohos.enterprise.usbManager (USB Management) (System API)

The **usbManager** module provides APIs for USB management.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is [enabled](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin).
> 
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.usbManager](js-apis-enterprise-usbManager.md).

## Modules to Import

```ts
import { usbManager } from '@kit.MDMKit';
```

## usbManager.setUsbPolicy

setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void

Sets the USB read/write policy. This API uses an asynchronous callback to return the result.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| usbPolicy  | [UsbPolicy](js-apis-enterprise-usbManager.md#usbpolicy) | Yes| USB access policy. This API supports **READ_WRITE** and **READ_ONLY** only.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.READ_WRITE

usbManager.setUsbPolicy(wantTemp, policy, (err) => {
  if (err) {
    console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting usb policy');
})
```

## usbManager.setUsbPolicy

setUsbPolicy(admin: Want, usbPolicy: UsbPolicy): Promise\<void>

Sets the USB read/write policy. This API uses a promise to return the result.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| usbPolicy  | [UsbPolicy](js-apis-enterprise-usbManager.md#usbpolicy) | Yes| USB access policy. This API supports **READ_WRITE** and **READ_ONLY** only.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. An error object is thrown when the USB policy fails to be set.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.READ_WRITE

usbManager.setUsbPolicy(wantTemp, policy).then(() => {
  console.info('Succeeded in setting usb policy');
}).catch((err: BusinessError) => {
  console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);
})
```

## usbManager.disableUsb<sup>11+</sup>

disableUsb(admin: Want, disable: boolean): void

Enables or disables USB.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name | Type                                                   | Mandatory| Description                                            |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.          |
| disable | boolean                                                 | Yes  | Whether to disable USB. The value **true** means to disable USB; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  usbManager.disableUsb(wantTemp, true);
  console.info(`Succeeded in disabling USB`);
} catch (err) {
  console.error(`Failed to disabling USB. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.isUsbDisabled<sup>11+</sup>

isUsbDisabled(admin: Want): boolean

Queries whether the USB is disabled.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type   | Description                                                  |
| ------- | ------------------------------------------------------ |
| boolean | Returns **true** if USB is disabled;<br>returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let isDisabled = usbManager.isUsbDisabled(wantTemp);
  console.info(`Succeeded in querying if USB is disabled: ${isDisabled}`);
} catch (err) {
  console.error(`Failed to query if USB is disabled. Code: ${err.code}, message: ${err.message}`);
}
```
