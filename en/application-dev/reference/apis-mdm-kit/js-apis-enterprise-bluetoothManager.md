# @ohos.enterprise.bluetoothManager (Bluetooth Management)

The **bluetoothManager** module provides Bluetooth management capabilities, including setting and obtaining Bluetooth information.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>
> - The global restriction policies are provided by **restrictions**. To disable Bluetooth globally, see [@ohos.enterprise.restrictions](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { bluetoothManager } from '@kit.MDMKit';
```

## bluetoothManager.getBluetoothInfo

getBluetoothInfo(admin: Want): BluetoothInfo

Obtains device Bluetooth information.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

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

Adds allowed Bluetooth devices. The current device can only connect to the allowed Bluetooth devices.

A policy conflict is reported when this API is called in the following scenarios:

1. Bluetooth has been disabled by calling [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy). You can resolve the conflict by enabling the Bluetooth through [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy).
2. Disallowed Bluetooth devices have been added by calling [addDisallowedBluetoothDevices](#bluetoothmanageradddisallowedbluetoothdevices20). You can resolve the conflict by removing disallowed Bluetooth devices through [removeDisallowedBluetoothDevices](#bluetoothmanagerremovedisallowedbluetoothdevices20).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                               |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                     |
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

Removes allowed Bluetooth devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                   |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.         |
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

getAllowedBluetoothDevices(admin: Want): Array\<string>

Obtains allowed Bluetooth devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

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

## bluetoothManager.addDisallowedBluetoothDevices<sup>20+</sup>

addDisallowedBluetoothDevices(admin: Want, deviceIds: Array&lt;string&gt;): void

Adds disallowed Bluetooth devices. The current device cannot connect to the disallowed Bluetooth devices.

A policy conflict is reported when this API is called in the following scenarios:

1. Bluetooth has been disabled by calling [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy). You can resolve the conflict by enabling the Bluetooth through [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy).
2. Allowed Bluetooth devices have been added by calling [addAllowedBluetoothDevices](#bluetoothmanageraddallowedbluetoothdevices). You can resolve the conflict by removing allowed Bluetooth devices through [removeAllowedBluetoothDevices](#bluetoothmanagerremoveallowedbluetoothdevices).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                               |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                     |
| deviceIds | Array&lt;string&gt;                                          | Yes  | MAC addresses of the Bluetooth devices to add. <br>The maximum number of disallowed Bluetooth devices is 1,000. If there are already 300 MAC addresses of the devices, only 700 more can be added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// Replace it as required.
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
    bluetoothManager.addDisallowedBluetoothDevices(wantTemp,deviceIds);
    console.info(`Succeeded in adding allowed bluetooth devices.`);
} catch(err) {
    console.error(`Failed to add allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeDisallowedBluetoothDevices<sup>20+</sup>

removeDisallowedBluetoothDevices(admin: Want, deviceIds: Array&lt;string&gt;): void

Removes disallowed Bluetooth devices. If some disallowed Bluetooth devices are removed, the current device cannot connect to the remaining disallowed Bluetooth devices. If all disallowed Bluetooth devices are removed, the current device can connect to any Bluetooth device.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                                   | Mandatory| Description                   |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.         |
| deviceIds | Array&lt;string&gt;                                          | Yes  | MAC addresses of the Bluetooth devices to remove.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// Replace it as required.
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
    bluetoothManager.removeDisallowedBluetoothDevices(wantTemp,deviceIds);
    console.info(`Succeeded in removing allowed bluetooth devices.`);
} catch(err) {
    console.error(`Failed to remove allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getDisallowedBluetoothDevices<sup>20+</sup>

getDisallowedBluetoothDevices(admin: Want): Array&lt;string&gt;

Obtains disallowed Bluetooth devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Array&lt;string&gt; | MAC addresses of disallowed Bluetooth devices obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
    let result: Array<string> = bluetoothManager.getDisallowedBluetoothDevices(wantTemp);
    console.info(`Succeeded in getting allowed bluetooth devices. Result: ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## BluetoothInfo

Represents the device Bluetooth information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

| Name           | Type                                                        | Read-Only| Optional| Description                    |
| --------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------ |
| name            | string                                                       | No  | No| Bluetooth name of the device.    |
| state           | [access.BluetoothState](../apis-connectivity-kit/js-apis-bluetooth-access.md#bluetoothstate) | No  | No| Bluetooth state of the device.    |
| connectionState | [constant.ProfileConnectionState](../apis-connectivity-kit/js-apis-bluetooth-constant.md#profileconnectionstate) | No  | No| Bluetooth profile connection state of the device.|

## bluetoothManager.turnOnBluetooth<sup>20+</sup>

turnOnBluetooth(admin: Want): void

Enables Bluetooth.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
    bluetoothManager.turnOnBluetooth(wantTemp);
    console.info(`Succeeded in turning on bluetooth.`);
} catch(err) {
    console.error(`Failed to turn on bluetooth. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.turnOffBluetooth<sup>20+</sup>

turnOffBluetooth(admin: Want): void

Disables Bluetooth.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 203      | This function is prohibited by enterprise management policies. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
    bluetoothManager.turnOffBluetooth(wantTemp);
    console.info(`Succeeded in turning off bluetooth.`);
} catch(err) {
    console.error(`Failed to turn off bluetooth. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addDisallowedBluetoothProtocols<sup>20+</sup>

addDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array&lt;Protocol&gt;): void

Adds disallowed Bluetooth protocols. Specified users cannot use the disallowed Bluetooth protocols to send files to other devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| accountId | number | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| protocols  | Array&lt;[Protocol](#protocol20)&gt; | Yes  | Bluetooth protocol array, which has a maximum length of 10,000.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// Replace it as required.
let accountId: number = 100;
let protocols: Array<bluetoothManager.Protocol> = [bluetoothManager.Protocol.GATT, bluetoothManager.Protocol.SPP];
try{
    bluetoothManager.addDisallowedBluetoothProtocols(wantTemp, accountId, protocols);
    console.info('Succeeded in adding disallowed bluetooth protocols policy.');
} catch (err) {
    console.error(`Failed to add disallowed bluetooth protocols. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeDisallowedBluetoothProtocols<sup>20+</sup>

removeDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array&lt;Protocol&gt;): void

Removes disallowed Bluetooth protocols. After removing some protocols, the user is still restricted by the remaining disallowed protocols; after removing all protocols, the user can use any protocol; removing non-existent protocols results in a successful API call but no actual change.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| accountId | number | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| protocols  | Array&lt;[Protocol](#protocol20)&gt; | Yes  | Bluetooth protocol array.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// Replace it as required.
let accountId: number = 100;
let protocols: Array<bluetoothManager.Protocol> = [bluetoothManager.Protocol.GATT, bluetoothManager.Protocol.SPP];
try{
    bluetoothManager.removeDisallowedBluetoothProtocols(wantTemp, accountId, protocols);
    console.info('Succeeded in removing disallowed bluetooth protocols policy.');
} catch (err) {
    console.error(`Failed to remove disallowed bluetooth protocols. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getDisallowedBluetoothProtocols<sup>20+</sup>

getDisallowedBluetoothProtocols(admin: Want, accountId: number): Array&lt;Protocol&gt;

Obtains the disallowed Bluetooth protocols of a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| accountId | number | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Array&lt;[Protocol](#protocol20)&gt; | Array of disallowed Bluetooth protocols.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
// Replace it as required.
let accountId: number = 100;
try{
    let result: Array<bluetoothManager.Protocol> = bluetoothManager.getDisallowedBluetoothProtocols(wantTemp, accountId);
    console.info(`Succeeded in getting disallowed bluetooth protocols. Result: ${JSON.stringify(result)}`);
} catch (err) {
    console.error(`Failed to get disallowed bluetooth protocols. Code: ${err.code}, message: ${err.message}`);
}
```

## Protocol<sup>20+</sup>

Represents the Bluetooth protocol type.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| GATT | 0 | [Generic Attribute Profile (GATT)](../../connectivity/terminology.md#gatt)|
| SPP | 1 | [Serial Port Profile (SPP)](../../connectivity/terminology.md#spp)|
<!--no_check-->