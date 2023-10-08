# @ohos.enterprise.usbManager (USB Management)

The **usbManager** module provides APIs for USB management.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import usbManager from '@ohos.enterprise.usbManager';
```

## usbManager.setUsbPolicy

setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void

Sets the USB read/write policy through the specified device administrator application. This API uses an asynchronous callback to return the result.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| usbPolicy  | [UsbPolicy](#usbpolicy) | Yes| USB read/write policy to set.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Sets the USB read/write policy through the specified device administrator application. This API uses a promise to return the result.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| usbPolicy  | [UsbPolicy](#usbpolicy) | Yes| USB read/write policy to set.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. An error object will be thrown if the operation fails.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.READ_WRITE

usbManager.setUsbPolicy(wantTemp, policy).then(() => {
  console.info('Succeeded in setting usb policy');
}).catch((err: BusinessError) => {
  console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);
})
```

## UsbPolicy

Enumerates the USB read/write policies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| READ_WRITE | 0 | The USB is readable and writable.|
| READ_ONLY | 1 | The USB is read-only.|
