# @ohos.enterprise.bluetoothManager (Bluetooth Management)

The **bluetoothManager** module provides Bluetooth management capabilities, including setting and obtaining Bluetooth information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { bluetoothManager } from '@kit.MDMKit';
```

## bluetoothManager.getBluetoothInfo

getBluetoothInfo(admin: Want): BluetoothInfo

Obtains device Bluetooth information through the specified device administrator application. This API returns the result synchronously. If the operation is successful, the Bluetooth information obtained is returned. If the operation fails, an exception will be thrown.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| [BluetoothInfo](#bluetoothinfo) | Bluetooth information, including the Bluetooth name, state, and profile connection state.|

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
import { bluetoothManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: bluetoothManager.BluetoothInfo = bluetoothManager.getBluetoothInfo(wantTemp);
    console.info(`Succeeded in getting bluetooth info: ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get bluetooth info. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addAllowedBluetoothDevices

addAllowedBluetoothDevices(admin: Want, deviceIds: Array\<string>): void

Adds allowed Bluetooth devices through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                               |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                     |
| deviceIds | Array\<string>                                          | Yes  | MAC addresses of the Bluetooth devices to add. This array can hold a maximum of 1000 MAC addresses.|

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
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
    bluetoothManager.addAllowedBluetoothDevices(wantTemp,deviceIds);
    console.info(`Succeeded in adding allowed bluetooth devices.`);
} catch(err) {
    console.error(`Failed to add allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeAllowedBluetoothDevices

removeAllowedBluetoothDevices(admin: Want, deviceIds: Array\<string>): void

Removes allowed Bluetooth devices through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                   |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.         |
| deviceIds | Array\<string>                                          | Yes  | MAC addresses of the Bluetooth devices to remove.|

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
import { bluetoothManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
    bluetoothManager.removeAllowedBluetoothDevices(wantTemp,deviceIds);
    console.info(`Succeeded in removing allowed bluetooth devices.`);
} catch(err) {
    console.error(`Failed to remove allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getAllowedBluetoothDevices

getAllowedBluetoothDevices(admin: Want): Array\<string>;

Obtains allowed Bluetooth devices through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Array\<string> | MAC addresses of allowed Bluetooth devices obtained.|

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
import { bluetoothManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
    let result: Array<string> = bluetoothManager.getAllowedBluetoothDevices(wantTemp);
    console.info(`Succeeded in getting allowed bluetooth devices. Result: ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## BluetoothInfo

Represents the device Bluetooth information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

| Name           | Type                                                        | Mandatory| Description                    |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------ |
| name            | string                                                       | Yes  | Bluetooth name of the device.    |
| state           | [access.BluetoothState](../apis-connectivity-kit/js-apis-bluetooth-access.md#bluetoothstate) | Yes  | Bluetooth state of the device.    |
| connectionState | [constant.ProfileConnectionState](../apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate) | Yes  | Bluetooth profile connection state of the device.|
