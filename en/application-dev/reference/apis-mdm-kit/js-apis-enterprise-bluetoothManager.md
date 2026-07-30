# @ohos.enterprise.bluetoothManager (Bluetooth Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides device Bluetooth management capabilities, including setting Bluetooth switch states, querying Bluetooth information, and managing the Bluetooth device trustlist, Bluetooth device blocklist, and Bluetooth protocol blocklist. Through this module, enterprises can centrally manage Bluetooth functions on devices, enabling fine-grained control over Bluetooth device connections and enhancing enterprise information security. This is suitable for scenarios where enterprises need to regulate Bluetooth usage on employee devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).
>
> The global restriction policies are provided by **restrictions**. To disable Bluetooth globally, see [@ohos.enterprise.restrictions](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { bluetoothManager } from '@kit.MDMKit';
```

## bluetoothManager.getBluetoothInfo

getBluetoothInfo(admin: Want): BluetoothInfo

Obtains device Bluetooth information.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Obtain Bluetooth information.
  let result: bluetoothManager.BluetoothInfo = bluetoothManager.getBluetoothInfo(wantTemp);
  console.info(`Succeeded in getting bluetooth info: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get bluetooth info. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addAllowedBluetoothDevices

addAllowedBluetoothDevices(admin: Want, deviceIds: Array\<string>): void

Adds Bluetooth devices to the trustlist. After adding devices to this list, the current device will only be allowed to connect to Bluetooth devices in the list. Since API version 22, the MAC addresses in the array must comply with the Bluetooth MAC address specifications (for example, 00:1A:2B:3C:4D:5E). Invalid MAC addresses will be removed and only valid MAC addresses will be added.

A policy conflict is reported when this API is called in the following scenarios:

1. Bluetooth has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated). In this case, you can call [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) enable Bluetooth to solve the conflict.
2. Disallowed Bluetooth devices have been added by calling [addDisallowedBluetoothDevices](#bluetoothmanageradddisallowedbluetoothdevices20). You can resolve the conflict by removing disallowed Bluetooth devices through [removeDisallowedBluetoothDevices](#bluetoothmanagerremovedisallowedbluetoothdevices20).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                               |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                     |
| deviceIds | Array\<string>                                          | Yes  | MAC addresses of the Bluetooth devices to add. The maximum number of allowed Bluetooth devices is 1,000. If there are already 300 MAC addresses of the devices, only 700 more can be added.|

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Define the array of Bluetooth device MAC addresses. (Replace it as required.)
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // Add Bluetooth devices to the trustlist.
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

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                   |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.         |
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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Define the array of Bluetooth device MAC addresses. (Replace it as required.)
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // Removes Bluetooth devices from the trustlist.
  bluetoothManager.removeAllowedBluetoothDevices(wantTemp,deviceIds);
  console.info(`Succeeded in removing allowed bluetooth devices.`);
} catch(err) {
  console.error(`Failed to remove allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getAllowedBluetoothDevices

getAllowedBluetoothDevices(admin: Want | null): Array\<string>

Obtains allowed Bluetooth devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Obtain the Bluetooth device trustlist.
  let result: Array<string> = bluetoothManager.getAllowedBluetoothDevices(wantTemp);
  console.info(`Succeeded in getting allowed bluetooth devices. Result: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addDisallowedBluetoothDevices<sup>20+</sup>

addDisallowedBluetoothDevices(admin: Want, deviceIds: Array&lt;string&gt;): void

Adds Bluetooth devices to the blocklist. The current device cannot connect to the disallowed Bluetooth devices. Since API version 22, the MAC addresses in the array must comply with the Bluetooth MAC address specifications (for example, 00:1A:2B:3C:4D:5E). Invalid MAC addresses will be removed and only valid MAC addresses will be added.

A policy conflict is reported when this API is called in the following scenarios:

1. Bluetooth has been disabled via [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated). In this case, you can call [setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated) enable Bluetooth to solve the conflict.
2. Allowed Bluetooth devices have been added by calling [addAllowedBluetoothDevices](#bluetoothmanageraddallowedbluetoothdevices). You can resolve the conflict by removing allowed Bluetooth devices through [removeAllowedBluetoothDevices](#bluetoothmanagerremoveallowedbluetoothdevices).

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                               |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                     |
| deviceIds | Array&lt;string&gt;                                          | Yes  | MAC addresses of the Bluetooth devices to add. The maximum number of disallowed Bluetooth devices is 1,000. If there are already 300 MAC addresses of the devices, only 700 more can be added.|

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Define the array of Bluetooth device MAC addresses. (Replace it as required.)
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // Add Bluetooth devices to the blocklist.
  bluetoothManager.addDisallowedBluetoothDevices(wantTemp,deviceIds);
  console.info(`Succeeded in adding disallowed bluetooth devices.`);
} catch(err) {
  console.error(`Failed to add disallowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeDisallowedBluetoothDevices<sup>20+</sup>

removeDisallowedBluetoothDevices(admin: Want, deviceIds: Array&lt;string&gt;): void

Removes disallowed Bluetooth devices. If some Bluetooth devices are removed from the disallowed list, the current device cannot connect to the remaining ones; if all Bluetooth devices are removed, the current device can connect to any Bluetooth device.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                   |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.         |
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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Define the array of Bluetooth device MAC addresses. (Replace it as required.)
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
  // Remove Bluetooth devices from the blocklist.
  bluetoothManager.removeDisallowedBluetoothDevices(wantTemp,deviceIds);
  console.info(`Succeeded in removing disallowed bluetooth devices.`);
} catch(err) {
  console.error(`Failed to remove disallowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getDisallowedBluetoothDevices<sup>20+</sup>

getDisallowedBluetoothDevices(admin: Want | null): Array&lt;string&gt;

Obtains disallowed Bluetooth devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

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
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Obtain Bluetooth device blocklist.
  let result: Array<string> = bluetoothManager.getDisallowedBluetoothDevices(wantTemp);
  console.info(`Succeeded in getting disallowed bluetooth devices. Result: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get disallowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.turnOnBluetooth<sup>20+</sup>

turnOnBluetooth(admin: Want): void

Enables Bluetooth. After Bluetooth is enabled, the user can manually disable it.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

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

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Enable Bluetooth.
  bluetoothManager.turnOnBluetooth(wantTemp);
  console.info(`Succeeded in turning on bluetooth.`);
} catch(err) {
  console.error(`Failed to turn on bluetooth. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.turnOffBluetooth<sup>20+</sup>

turnOffBluetooth(admin: Want): void

Disables Bluetooth. After Bluetooth is disabled, the user can manually enable it.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

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

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  // Disable Bluetooth.
  bluetoothManager.turnOffBluetooth(wantTemp);
  console.info('Succeeded in turning off bluetooth.');
} catch(err) {
  console.error(`Failed to turn off bluetooth. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addDisallowedBluetoothProtocols<sup>20+</sup>

addDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array&lt;Protocol&gt;): void

Adds disallowed Bluetooth protocols. Specified users cannot use the disallowed Bluetooth protocols to send files to other devices. This API is used to disable the GATT or SPP protocol, which does not take effect for system services and system applications. When the SPP protocol is passed, both the receiving and sending functions are disabled.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
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

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Define the user ID. (Replace it as required.)
let accountId: number = 100;
// Define the array of Bluetooth protocols. (Replace it as required.)
let protocols: Array<bluetoothManager.Protocol> = [bluetoothManager.Protocol.GATT, bluetoothManager.Protocol.SPP];
try {
  // Add Bluetooth protocols to the blocklist.
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

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
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

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Define the user ID. (Replace it as required.)
let accountId: number = 100;
// Define the array of Bluetooth protocols. (Replace it as required.)
let protocols: Array<bluetoothManager.Protocol> = [bluetoothManager.Protocol.GATT, bluetoothManager.Protocol.SPP];
try {
  // Remove Bluetooth protocols from the blocklist.
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

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
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

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Define the user ID. (Replace it as required.)
let accountId: number = 100;
try {
  // Obtains the Bluetooth protocol blocklist of a specified user.
  let result: Array<bluetoothManager.Protocol> = bluetoothManager.getDisallowedBluetoothProtocols(wantTemp, accountId);
  console.info(`Succeeded in getting disallowed bluetooth protocols. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed bluetooth protocols. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.addDisallowedBluetoothProtocols

addDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array\<Protocol\>, policy: TransferPolicy): void

Adds disallowed Bluetooth protocols. After the setting, specified users cannot use the disallowed Bluetooth protocols based on the specified transfer policy.

> **NOTE**
> 
> 1. This API is used to disable the GATT or SPP protocol, which does not take effect for system services and system applications.
> 2. When the SPP protocol is passed, the value of the **policy** parameter can only be **TransferPolicy.RECEIVE_SEND**. Otherwise, error code 9200012 will be returned.
> 3. This API and [addDisallowedBluetoothProtocols<sup>20+</sup>](#bluetoothmanageradddisallowedbluetoothprotocols20) are overloaded APIs. This API adds the **policy** parameter to specify the transfer policy, enabling more fine-grained control over Bluetooth protocol disabling behavior (for example, blocking only sending, only receiving, or both sending and receiving). If both APIs are used to configure disabling policies, the policies will be combined and take effect.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| protocols | Array&lt;[Protocol](#protocol20)&gt; | Yes| Array of Bluetooth protocols to be added to the blocklist.|
| policy | [TransferPolicy](#transferpolicy) | Yes| Transfer policy, which specifies the mode for disabling Bluetooth protocols. The options are **SEND_ONLY** (sending disabled), **RECEIVE_ONLY** (receiving disabled), and **RECEIVE_SEND** (sending and receiving disabled).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Define the user ID.
let accountId: number = 100;
// Define the Bluetooth protocol array.
let protocols: Array<bluetoothManager.Protocol> = [
  bluetoothManager.Protocol.GATT,
  bluetoothManager.Protocol.SPP,
  bluetoothManager.Protocol.OPP
];

try {
  // Add Bluetooth protocols to the blocklist and specify the transfer policy as disabling sending and receiving.
  bluetoothManager.addDisallowedBluetoothProtocols(wantTemp, accountId, protocols, bluetoothManager.TransferPolicy.RECEIVE_SEND);
  console.info('Succeeded in adding disallowed bluetooth protocols.');
} catch (err) {
  console.error(`Failed to add disallowed bluetooth protocols. Code is ${err.code}, message is ${err.message}`);
}
```

## bluetoothManager.removeDisallowedBluetoothProtocols

removeDisallowedBluetoothProtocols(admin: Want, accountId: number, protocols: Array\<Protocol\>, policy: TransferPolicy): void

Removes Bluetooth protocols from the blocklist. After the setting, specified users are no longer restricted by the transfer policy and can properly use these Bluetooth protocols.

> **NOTE**
> 
> 1. When the SPP protocol is passed, the value of the **policy** parameter can only be **TransferPolicy.RECEIVE_SEND**. Otherwise, error code 9200012 will be returned.
> 2. This API and [removeDisallowedBluetoothProtocols<sup>20+</sup>](#bluetoothmanagerremovedisallowedbluetoothprotocols20) are overloaded APIs. This API adds the **policy** parameter to remove the disallowing configuration based on the transfer policy. If the same protocol has been blocked under different policies via the two APIs, calling this API removes only the blocking configuration for the corresponding policy, while blocking configurations of other policies remain effective.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| protocols    | Array&lt;[Protocol](#protocol20)&gt;                                     | Yes  | Array of Bluetooth protocols to be removed from the blocklist.|
| policy | [TransferPolicy](#transferpolicy) | Yes| Transfer policy.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Define the user ID.
let accountId: number = 100;
// Define the Bluetooth protocol array.
let protocols: Array<bluetoothManager.Protocol> = [
  bluetoothManager.Protocol.GATT,
  bluetoothManager.Protocol.SPP,
  bluetoothManager.Protocol.OPP
];

try {
  // Remove Bluetooth protocols from the blocklist and specify the transfer policy as disabling sending and receiving.
  bluetoothManager.removeDisallowedBluetoothProtocols(wantTemp, accountId, protocols, bluetoothManager.TransferPolicy.RECEIVE_SEND);
  console.info('Succeeded in removing disallowed bluetooth protocols.');
} catch (err) {
  console.error(`Failed to remove disallowed bluetooth protocols. Code is ${err.code}, message is ${err.message}`);
}
```

## bluetoothManager.getDisallowedBluetoothProtocols

getDisallowedBluetoothProtocols(admin: Want | null, accountId: number, policy: TransferPolicy): Array\<Protocol\>

Obtains the list of disallowed Bluetooth protocols for a specified user under a specified transfer policy.

> **NOTE**
>
> 1. This API and [getDisallowedBluetoothProtocols<sup>20+</sup>](#bluetoothmanagergetdisallowedbluetoothprotocols20) are overloaded APIs. This API adds the **policy** parameter to query the disallowing configuration based on the transfer policy.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| policy | [TransferPolicy](#transferpolicy) | Yes| Transfer policy.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;[Protocol](#protocol20)&gt; | Array of disallowed Bluetooth protocols.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bluetoothManager } from '@kit.MDMKit';

// Create an EnterpriseAdminExtensionAbility component.
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Define the user ID.
let accountId: number = 100;

try {
  // Obtain the list of disallowed Bluetooth protocols for a specified user under a specified transfer policy.
  let result: Array<bluetoothManager.Protocol> = bluetoothManager.getDisallowedBluetoothProtocols(wantTemp, accountId, bluetoothManager.TransferPolicy.RECEIVE_SEND);
  console.info(`Succeeded in getting disallowed bluetooth protocols, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed bluetooth protocols. Code is ${err.code}, message is ${err.message}`);
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

## Protocol<sup>20+</sup>

Represents the Bluetooth protocol type.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| GATT | 0 | [Generic Attribute Profile (GATT)](../../connectivity/terminology.md#gatt)|
| SPP | 1 | [Serial Port Profile (SPP)](../../connectivity/terminology.md#spp)|
| OPP | 2 | [Object Push Profile (OPP)](../../connectivity/terminology.md#opp)|

## TransferPolicy

Transfer policy.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name                       | Value | Description   |
| ----------------------------| ----| ------------------------------- |
| SEND_ONLY   | 0   | Disable sending.|
| RECEIVE_ONLY        | 1   | Disable receiving.|
| RECEIVE_SEND    | 2   | Disable sending and receiving.|
