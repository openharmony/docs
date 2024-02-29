# @ohos.bluetooth (Bluetooth) (System API)

The **Bluetooth** module provides classic Bluetooth capabilities and Bluetooth Low Energy (BLE) scan and advertising.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are no longer maintained since API version 9. You are advised to use profile APIs of [@ohos.bluetooth.ble](js-apis-bluetooth-ble.md).
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.bluetooth (Bluetooth)](js-apis-bluetooth.md).

## Modules to Import

```js
import bluetooth from '@ohos.bluetooth';
```

## bluetooth.cancelPairedDevice<sup>8+</sup><sup>(deprecated)</sup><a name="cancelPairedDevice"></a>

cancelPairedDevice(deviceId: string): boolean

Cancels a paired remote device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [bluetoothManager.cancelPairedDevice](js-apis-bluetoothManager-sys.md#bluetoothmanagercancelpaireddevicedeprecated) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                   |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | Yes   | Address of the remote device to cancel, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let result : boolean = bluetooth.cancelPairedDevice("XX:XX:XX:XX:XX:XX");
```
