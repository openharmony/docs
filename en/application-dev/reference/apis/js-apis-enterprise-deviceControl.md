# @ohos.enterprise.deviceControl (Device Control)

The **deviceControl** module provides APIs for device control.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import deviceControl from '@ohos.enterprise.deviceControl';
```

## deviceControl.resetFactory

resetFactory(admin: Want, callback: AsyncCallback\<void>): void

Restores device factory settings through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESET_DEVICE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import deviceControl from '@ohos.enterprise.deviceControl';
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

deviceControl.resetFactory(wantTemp, (err) => {
  if (err) {
    console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.log('Succeeded in resetting factory');
})
```

## deviceControl.resetFactory

resetFactory(admin: Want): Promise\<void>

Restores device factory settings through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESET_DEVICE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import deviceControl from '@ohos.enterprise.deviceControl';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

deviceControl.resetFactory(wantTemp).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);
})
```

## deviceControl.shutdown<sup>11+</sup>

shutdown(admin: Want): void

Shuts down the device through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_REBOOT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import deviceControl from '@ohos.enterprise.deviceControl';
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  deviceControl.shutdown(wantTemp);
} catch (err) {
  console.error(`Failed to shutdown device. Code is ${err.code}, message is ${err.message}`);
}
```

## deviceControl.reboot<sup>11+</sup>

reboot(admin: Want): void

Reboots the device through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_REBOOT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import deviceControl from '@ohos.enterprise.deviceControl';
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  deviceControl.reboot(wantTemp);
} catch (err) {
  console.error(`Failed to reboot device. Code is ${err.code}, message is ${err.message}`);
}
```

## deviceControl.lockScreen<sup>11+</sup>

lockScreen(admin: Want): void

Locks the device screen through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_LOCK_DEVICE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import deviceControl from '@ohos.enterprise.deviceControl';
import Want from '@ohos.app.ability.Want';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  deviceControl.lockScreen(wantTemp);
} catch (err) {
  console.error(`Failed to lock screen. Code is ${err.code}, message is ${err.message}`);
}
```
