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

Sets the USB access policy through the specified device administrator application. This API uses an asynchronous callback to return the result.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| usbPolicy  | [UsbPolicy](#usbpolicy) | Yes| USB access policy. This API supports **READ_WRITE** and **READ_ONLY** only.|
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

Sets the USB access policy through the specified device administrator application. This API uses a promise to return the result.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| usbPolicy  | [UsbPolicy](#usbpolicy) | Yes| USB access policy. This API supports **READ_WRITE** and **READ_ONLY** only.|

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

Enumerates the USB access policies.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name| Value| Description|
| -------- | -------- | -------- |
| READ_WRITE | 0 | Read and write.|
| READ_ONLY | 1 | Read only.|
| DISABLED<sup>11+</sup> | 2 | Disabled.|

## UsbDeviceId<sup>11+</sup>

Represents the USB device identity information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name     | Type  | Mandatory| Description    |
| --------- | ------ | ---- | -------- |
| vendorId  | number | Yes  | Vendor ID.|
| productId | number | Yes  | Product ID.|

## usbManager.disableUsb<sup>11+</sup>

disableUsb(admin: Want, disable: boolean): void

Enables or disables USB through the specified device administrator application.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name | Type                               | Mandatory| Description                                            |
| ------- | ----------------------------------- | ---- | ------------------------------------------------ |
| admin   | [Want](js-apis-app-ability-want.md) | Yes  | Device administrator application.                                  |
| disable | boolean                             | Yes  | Whether to disable USB. The value **true** means to disable USB; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
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

isUsbDevicesDisallowed(admin: Want): boolean

Checks whether USB is disabled through the specified device administrator application.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](js-apis-app-ability-want.md) | Yes  | Device administrator application.|

**Return value**

| Type   | Description                                                  |
| ------- | ------------------------------------------------------ |
| boolean | Returns **true** if USB is disabled; returns **false** otherwise. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
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

## usbManager.addAllowedUsbDevices<sup>11+</sup>

addAllowedUsbDevices(admin: Want, usbDeviceIds: Array<usbManager.UsbDeviceId>): void

Adds allowed USB devices through the specified device administrator application.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name      | Type                                           | Mandatory| Description                                       |
| ------------ | ----------------------------------------------- | ---- | ------------------------------------------- |
| admin        | [Want](js-apis-app-ability-want.md)             | Yes  | Device administrator application.                             |
| usbDeviceIds | Array<[usbManager.UsbDeviceId](#usbdeviceid11)> | Yes  | IDs of the allowed USB devices to add. This array can hold a maximum of 1000 device IDs.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
      vendorId: 1,
      productId: 1
  }];
  usbManager.addAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in adding allowed USB devices`);
} catch (err) {
  console.error(`Failed to adding allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeAllowedUsbDevices<sup>11+</sup>

removeAllowedUsbDevices(admin: Want, usbDeviceIds: Array<usbManager.UsbDeviceId>): void

Removes allowed USB devices through the specified device administrator application.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name      | Type                                           | Mandatory| Description           |
| ------------ | ----------------------------------------------- | ---- | --------------- |
| admin        | [Want](js-apis-app-ability-want.md)             | Yes  | Device administrator application. |
| usbDeviceIds | Array<[usbManager.UsbDeviceId](#usbdeviceid11)> | Yes  | IDs of the allowed USB devices to remove.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
      vendorId: 1,
      productId: 1
  }];
  usbManager.removeAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in removing allowed USB devices`);
} catch (err) {
  console.error(`Failed to removing allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getAllowedUsbDevices<sup>11+</sup>

getAllowedUsbDevices(admin: Want): Array<usbManager.UsbDeviceId>

Obtains allowed USB devices through the specified device administrator application.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](js-apis-app-ability-want.md) | Yes  | Device administrator application.|

**Return value**

| Type                                           | Description                     |
| ----------------------------------------------- | ------------------------- |
| Array<[usbManager.UsbDeviceId](#usbdeviceid11)> | Allowed USB devices obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let result: Array<usbManager.UsbDeviceId> = usbManager.getAllowedUsbDevices(wantTemp);
  console.info(`Succeeded in removing allowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to removing allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.setUsbStorageDeviceAccessPolicy<sup>11+</sup>

setUsbStorageDeviceAccessPolicy(admin: Want, usbPolicy: UsbPolicy): void

Sets the USB storage device access policy through the specified device administrator application.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name   | Type                               | Mandatory| Description                 |
| --------- | ----------------------------------- | ---- | --------------------- |
| admin     | [Want](js-apis-app-ability-want.md) | Yes  | Device administrator application.       |
| usbPolicy | [UsbPolicy](#usbpolicy)             | Yes  | USB storage device access policy.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.DISABLED;
  usbManager.setUsbStorageDeviceAccessPolicy(wantTemp, policy);
  console.info(`Succeeded in setting USB storage device access policy`);
} catch (err) {
  console.error(`Failed to setting USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getUsbStorageDeviceAccessPolicy<sup>11+</sup>

getUsbStorageDeviceAccessPolicy(admin: Want): Array<usbManager.UsbDeviceId>

Obtains the USB storage device access policy through the specified device administrator application.

Required permissions: ohos.permission.ENTERPRISE_MANAGE_USB

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](js-apis-app-ability-want.md) | Yes  | Device administrator application.|

**Return value**

| Type                   | Description                 |
| ----------------------- | --------------------- |
| [UsbPolicy](#usbpolicy) | USB storage device access policy.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let result: usbManager.UsbPolicy = usbManager.getUsbStorageDeviceAccessPolicy(wantTemp);
  console.info(`Succeeded in getting USB storage device access policy. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed togetting USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```
