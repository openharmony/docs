# @ohos.FusionConnectivity.partnerAgent (Device Status Notification Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=14ca614ebb030bf413b2d8393352ad7521a1d1b9 translatedAt=2026-08-19T10:03:38.946Z pushedAt=2026-08-20T02:19:58.754Z -->

This module uses Bluetooth communication technology to provide device discovery and device offline notification features for applications. The module can:

- Dynamically listen to and discovers Bluetooth devices pre-registered by the applications.

- Leverage the process startup mechanism to automatically start the [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) process of the applications when the target devices appear.

- Use the process destruction mechanism to automatically destroy the [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) process of the applications when all the devices go offline.

- Notify the applications of registered devices through the [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) API.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 23. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { partnerAgent } from '@kit.ConnectivityKit';
```

## partnerAgent.isPartnerAgentSupported

isPartnerAgentSupported(): boolean

Checks whether the local device supports the peripheral interconnection feature. If the return value of this API is **false**, other APIs in this document cannot be used.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| boolean | Whether the peripheral interconnection feature is supported. **true** if the peripheral interconnection feature is supported; **false** otherwise.|

**Example**

```js
import { partnerAgent } from '@kit.ConnectivityKit';
let isSupport = partnerAgent.isPartnerAgentSupported();
console.info(`This device support partner agent: ${isSupport}`);
```

## partnerAgent.bindDevice

bindDevice(deviceAddress: PartnerDeviceAddress, deviceCapability: DeviceCapability, businessCapability: BusinessCapability, partnerAgentExtensionAbilityName: string): Promise&lt;void&gt;

Registers a device. This API uses a promise to return the result.

- You are advised to use [isPartnerAgentSupported](#partneragentispartneragentsupported) to check whether the peripheral interconnection feature is supported on the device. The converged short-range peripheral interconnection module can be used only when the feature is supported.

- You can use [isDeviceBound](#partneragentisdevicebound) to check whether the device has been registered. If the device has been registered, you do not need to call **partnerAgent.bindDevice** again.

- [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) must be implemented for the application first.

- After the application registers the device, if the peripheral interconnection subsystem detects the device, the [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) process of the application will be activated. The application can perform service operations in the new process. Each time when the registered device is discovered or disconnected, the process will be activated and keeps running for 3 minutes (the time is updated with new notifications).

- Before the application registers the device, you need to call [connection.pairDevice](js-apis-bluetooth-connection.md#connectionpairdevice) to pair the device with Bluetooth. If the device has been registered and is unpaired with Bluetooth by the user, the device discovery and offline notification features will be automatically disabled, but the registration information will be retained for 30 days. If the device is paired with Bluetooth again within the 30 days, the peripheral interconnection subsystem can restore the device discovery and offline notification features. Otherwise, the registration information will be cleared.

- You can call [getBoundDevices](#partneragentgetbounddevices) to obtain all registered devices.

- Before using **partnerAgent.bindDevice**, you are advised to inform the user to obtain the authorization for the application to register the device.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**    | **Type**                                    | **Mandatory**  | **Description**                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceAddress | [PartnerDeviceAddress](#partnerdeviceaddress) | Yes | Address information of the device registered by the application.<br>The application must be configured with the **bluetoothAddress** option of the **PartnerDeviceAddress** type. |
| deviceCapability | [DeviceCapability](#devicecapability) | Yes | Capabilities supported by the registered device.<br> - If the **supportBR** option is set, the peripheral interconnection subsystem listens to the [ACL](../../connectivity/bluetooth/terminology.md#acl) connection status of the device. Once the ACL connection is established, the device is considered to be discovered successfully.<br> - If the **supportBleAdvertiser** option is set, the system starts [BLE](../../connectivity/bluetooth/terminology.md#ble) scanning of the device. Once the device is found, the device is considered to be discovered successfully.<br> Note:<br> To reduce the system power consumption, if the BLE finds the device but the application does not establish a Bluetooth connection with the device within 3 minutes, the peripheral interconnection subsystem automatically stops the **PartnerAgentExtensionAbility** process of the application. |
| businessCapability | [BusinessCapability](#businesscapability) | Yes | Service features of the device registered by the application, including media and call control. |
| partnerAgentExtensionAbilityName | string | Yes| The value of this parameter must be the same as the value of **name** in [extensionAbilities](../../quick-start/module-configuration-file.md#extensionabilities) in the application module-level configuration file [module.json5](../../quick-start/module-configuration-file.md).|

**Return value**

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|34900003 | The device is not paired.                         |
|34900004 | The device has already been bound to the PartnerAgentExtensionAbility.                        |
|34900005 | Bluetooth disabled. |
|34900099 | Internal error. |

**Example**

```js
import { partnerAgent, common } from '@kit.ConnectivityKit';
try {
  let btAddr: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
  };
  let deviceAddress: partnerAgent.PartnerDeviceAddress = {
    "bluetoothAddress": btAddr,
  };
  let capability: partnerAgent.DeviceCapability = {
    "supportBR": true,
    "supportBleAdvertiser": true,
  };
  let businessCap: partnerAgent.BusinessCapability = {
    "supportMediaControl": true,
    "supportTelephonyControl": true,
  };
  partnerAgent.bindDevice(deviceAddress, capability, businessCap, "testAbilityName")
    .then(() => {
      console.info(`bind device success: ${btAddr.address}`);
    })
    .catch((err: BusinessError) => {
      console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    });
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## partnerAgent.unbindDevice

unbindDevice(deviceAddress: PartnerDeviceAddress): Promise&lt;void&gt;

Unregisters a device. This API uses a promise to return the result.

- After this API is called to unregister a device, the [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) process of the application no longer receives the discovery and offline notifications of the device.

- The device to be unregistered must have been registered by calling the [bindDevice](#partneragentbinddevice) API. You are advised to use this API in pairs with the **bindDevice** API.

- You are advised to use [isDeviceBound](#partneragentisdevicebound) to check whether the device has been registered. If the device has been registered, you can call **partnerAgent.unbindDevice**.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**    | **Type**                                    | **Mandatory**  | **Description**                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceAddress | [PartnerDeviceAddress](#partnerdeviceaddress) | Mandatory | Address information of the device registered by the application.<br>The application must be configured with the **bluetoothAddress** option of the **PartnerDeviceAddress** type. |

**Return value**

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|34900001 | The device is not bound.                         |
|34900099 | Internal error. |

**Example**

```js
import { partnerAgent, common } from '@kit.ConnectivityKit';
try {
  let btAddr: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
  };
  let deviceAddress: partnerAgent.PartnerDeviceAddress = {
    "bluetoothAddress": btAddr,
  };
  partnerAgent.unbindDevice(deviceAddress)
    .then(() => {
      console.info(`unbind device success: ${btAddr.address}`);
    })
    .catch((err: BusinessError) => {
      console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    });
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## partnerAgent.isDeviceBound

isDeviceBound(deviceAddress: PartnerDeviceAddress): boolean

Checks whether the device has been registered by the application.

- You can call [bindDevice](#partneragentbinddevice) to register a device.

- You can call [unbindDevice](#partneragentunbinddevice) to unregister a device.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**    | **Type**                                    | **Mandatory**  | **Description**                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceAddress | [PartnerDeviceAddress](#partnerdeviceaddress) | Yes | Address information of the device registered by the application.<br>The application must be configured with the **bluetoothAddress** option of the **PartnerDeviceAddress** type. |

**Return value**

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| boolean | Whether the device has been registered by the application. **true** if the device has been registered; **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|34900099 | Internal error. |

**Example**

```js
import { partnerAgent, common } from '@kit.ConnectivityKit';
try {
  let btAddr: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
  };
  let deviceAddress: partnerAgent.PartnerDeviceAddress = {
    "bluetoothAddress": btAddr,
  };
  let isBound = partnerAgent.isDeviceBound(deviceAddress);
  console.info(`device is bound: ${isBound}`);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## partnerAgent.getBoundDevices

getBoundDevices(): PartnerDeviceAddress[]

Obtains all the devices registered by the application.

- You can call [bindDevice](#partneragentbinddevice) to register a device.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| [PartnerDeviceAddress](#partnerdeviceaddress)[] | All the devices registered by the application. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|34900099 | Internal error. |

**Example**

```js
import { partnerAgent, common } from '@kit.ConnectivityKit';
try {
  let devices = partnerAgent.getBoundDevices();
  console.info(`bound devices: ${devices}`);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## partnerAgent.isDeviceControlEnabled

isDeviceControlEnabled(deviceAddress: PartnerDeviceAddress): boolean

Checks whether the interconnection feature of the device is enabled.

- After the device is registered by calling the [bindDevice](#partneragentbinddevice) API, the interconnection feature of the device is enabled by default, and the enabling status of the feature can be displayed on the device details page in the system settings on the application.

- If the feature is disabled, you can enable it by toggling on the corresponding switch on the device details page in the system settings on the application.

- If the switch of this feature is not displayed on the device details page in the system settings on the application, call the [bindDevice](#partneragentbinddevice) API to register the device. Then, the switch will be displayed.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**    | **Type**                                    | **Mandatory**  | **Description**                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| deviceAddress | [PartnerDeviceAddress](#partnerdeviceaddress) | Mandatory | Address information of the device registered by the application.<br>The application must be configured with the **bluetoothAddress** option of the **PartnerDeviceAddress** type. |

**Return value**

| **Type**                 | **Description**                 |
| ------------------- | ------------------- |
| boolean | Whether the interconnection feature of the device is enabled. **true**: enabled; **false**: disabled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Error Codes of the Converged Short-Range Service Subsystem](../apis-connectivity-kit/errorcode-fusionConnectivity.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|34900099 | Internal error. |

**Example**

```js
import { partnerAgent, common } from '@kit.ConnectivityKit';
try {
  let btAddr: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
  };
  let deviceAddress: partnerAgent.PartnerDeviceAddress = {
    "bluetoothAddress": btAddr,
  };
  let isEnabled = partnerAgent.isDeviceControlEnabled(deviceAddress);
  console.info(`device control is enabled: ${isEnabled}`);
} catch (err) {
  console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## DeviceCapability

Describes the capabilities supported for discovering the device.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**                | **Type**  | **Read-Only**| **Optional**  | **Description**                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| supportBR            | boolean | No | Yes    | Whether the device can be discovered by the [ACL](../../connectivity/bluetooth/terminology.md#acl) connection. If the ACL connection is established, the device is considered to be discovered successfully. After a device is discovered, the [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) process is started and the [onDeviceDiscovered](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md#ondevicediscovered) method in the process is called. **true** if connection-based discovery is supported; **false** otherwise. The default value is **false**. |
| supportBleAdvertiser | boolean | No | Yes    | Whether the device can be discovered by the [BLE](../../connectivity/bluetooth/terminology.md#ble) scanning. If the device is found, the device is considered to be discovered successfully. After a device is discovered, the **PartnerAgentExtensionAbility** process is started and the **onDeviceDiscovered** method in the process is called. **true** if BLE scanning-based discovery is supported; **false** otherwise. The default value is **false**.<br> Note:<br>  If the **supportBleAdvertiser** option in [devicecapability](#devicecapability) is selected and the device is scanned but no ACL connection is established within 3 minutes, [onDestroyWithReason](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md#ondestroywithreason) will be called to destroy the started **PartnerAgentExtensionAbility** process. |

## BusinessCapability

Describes the service features supported by the device.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**                | **Type**  | **Read-Only**| **Optional**  | **Description**                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| supportMediaControl | boolean | No| Yes| Whether the device supports media control, such as controlling media playback, volume adjustment, and previous/next track. **true** if supported, **false** otherwise. The default value is **false**.|
| supportTelephonyControl | boolean | No | Yes | Whether the device supports call control, such as answering and ending a call. **true** if supported, and **false** otherwise. The default value is **false**. <br> Note: <br> If both **supportMediaControl** and **supportTelephonyControl** are set to false, the [PartnerAgentExtensionAbility](js-apis-fusionConnectivity-partnerAgentExtensionAbility.md) process is not started during device discovery. |

## PartnerDeviceAddress

Describes the device address information.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**                | **Type**  | **Read-Only**| **Optional**  | **Description**                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| bluetoothAddress     | [common.BluetoothAddress](js-apis-bluetooth-common.md#bluetoothaddress) | No| Yes   | Bluetooth address of the device.|

## PartnerAgentExtensionAbilityDestroyReason

Enumerates the reasons why **PartnerAgentExtensionAbility** is destroyed.

**System capability**: SystemCapability.Communication.FusionConnectivity.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**     | **Value**   | **Description**                          |
| --------  | ---- | ------------------------------ |
| UNKNOWN_REASON   | 0    | Unknown reason caused by the system. You are advised to retry the operation. |
| USER_CLOSED_ABILITY   | 1    | The user has disabled the interconnection feature of the device in the system settings on the application. It is recommended that the feature be enabled. |
| DEVICE_UNPAIRED  | 2    | The user has canceled the Bluetooth pairing relationship of the device. It is recommended that the Bluetooth pairing be performed again. |
| DEVICE_LOST | 3 | The device has been disconnected or not found. The possible causes are that the distance is too long, the device is powered off, or the device battery is used up. You are advised to check the device status. |
| BLUETOOTH_DISABLED    | 4    | Bluetooth is disabled. It is recommended that Bluetooth be enabled. |