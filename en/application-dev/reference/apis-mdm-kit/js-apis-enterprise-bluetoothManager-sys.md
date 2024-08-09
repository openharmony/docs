# @ohos.enterprise.bluetoothManager (Bluetooth Management) (System API)

The **bluetoothManager** module provides Bluetooth management capabilities, including setting and obtaining Bluetooth information.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is [enabled](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin).
> 
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.bluetoothManager](js-apis-enterprise-bluetoothManager.md).

## Modules to Import

```ts
import { bluetoothManager } from '@kit.MDMKit';
```

## bluetoothManager.isBluetoothDisabled

isBluetoothDisabled(admin: Want): boolean

Checks whether Bluetooth is disabled. This API returns the result synchronously.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| :-------------------- | ------------------------- |
| boolean | Returns **true** if Bluetooth is disabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let isDisabled: boolean = bluetoothManager.isBluetoothDisabled(wantTemp);
  console.info(`Succeeded in query the bluetooth is disabled or not, isDisabled : ${isDisabled}`);
} catch(err) {
  console.error(`Failed to query the bluetooth is disabled or not. Code: ${err.code}, message: ${err.message}`);
};
```

## bluetoothManager.setBluetoothDisabled

setBluetoothDisabled(admin: Want, disabled: boolean): void

Disables Bluetooth. This API returns the result synchronously.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name    | Type                               | Mandatory| Description                                     |
| ---------- | ----------------------------------- | ---- | ----------------------------------------- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                           |
| disabled   | boolean                             | Yes  | Whether to disable Bluetooth. The value **true** means to disable Bluetooth; **false** means the opposite.|

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
import { bluetoothManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  bluetoothManager.setBluetoothDisabled(wantTemp, true);
  console.info('Succeeded in set the bluetooth disabled.');
} catch(err) {
  console.error(`Failed to set the bluetooth disabled. Code: ${err.code}, message: ${err.message}`);
};
```
