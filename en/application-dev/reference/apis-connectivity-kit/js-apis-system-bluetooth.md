# @system.bluetooth (Bluetooth)


> **NOTE**
>
> - The APIs provided by this module are no longer maintained since API version 7. You are advised to use profile APIs of [@ohos.bluetooth.ble](js-apis-bluetooth-ble.md).
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import bluetooth from '@system.bluetooth';
```

## bluetooth.startBLEScan(OBJECT)

Scans for Bluetooth Low Energy (BLE) devices nearby. This operation consumes system resources. Call [bluetooth.stopBLEScan](#bluetoothstopblescanobject) to stop the scan after a BLE device is detected and connected.

**System capability**: SystemCapability.Communication.Bluetooth.Lite

**Parameters**
**Table 1** StartBLEScanOptions

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| interval | number | No| Interval for reporting device information, in milliseconds. The default value is **0**, which means to report the detected device immediately and report other information at the given interval.|
| success | Function | No| Called when the operation is successful.|
| fail | Function | No| Called when the operation fails.|
| complete | Function | No| Called when the execution is complete.|

**Example**

  ```
  bluetooth.startBLEScan({
    interval:0,
    success() {
      console.log('call bluetooth.startBLEScan success.');
    },
    fail(code, data) {
      console.log('call bluetooth.startBLEScan failed, code:' + code + ', data:' + data);
    },
    complete() {
      console.log('call bluetooth.startBLEScan complete.');
    }
  });
  ```


## bluetooth.stopBLEScan(OBJECT)

Stops scanning for BLE devices nearby. This API is used with [bluetooth.startBLEScan(OBJECT)](#bluetoothstartblescanobject) in pairs.

**System capability**: SystemCapability.Communication.Bluetooth.Lite

**Parameters**
**Table 2** StopBLEScanOptions

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | No| Called when the operation is successful.|
| fail | Function | No| Called when the operation fails.|
| complete | Function | No| Called when the execution is complete.|

**Example**

  ```
  bluetooth.stopBLEScan({
    success() {
      console.log('call bluetooth.stopBLEScan success.');
    },
    fail(data, code) {
      console.log('call bluethooth.stopBLEScan fail, code:' + code + ', data:' + data);
    },
    complete() {
      console.log('call bluethooth.stopBLEScan complete.');
    }
  });
  ```


## bluetooth.subscribeBLEFound(OBJECT)

Subscribes to the newly detected BLE device. If this API is called multiple times, the last call takes effect.

**System capability**: SystemCapability.Communication.Bluetooth.Lite

**Parameters**
**Table 3** SubscribeBLEFoundOptions

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| success | Function | Yes| Called to report the newly detected device.|
| fail | Function | No| Called when the operation fails.|

**Table 4** Return value in success

| Name| Type| Description|
| -------- | -------- | -------- |
| devices | Array&lt;BluetoothDevice&gt; | List of the newly detected BLE devices.|

**Table 5** BluethoothDevice

| Name| Type| Description|
| -------- | -------- | -------- |
| addrType | string | Device address type, which can be:<br>-&nbsp;**public**: a public address<br>-&nbsp;**random**: a random address|
| addr | string | MAC address of the device.|
| rssi | number | Received signal strength indicator (RSSl) of the device.|
| txpower | string | **txpower** field in the Bluetooth advertising data.|
| data | hex&nbsp;string | Bluetooth advertising data (including advertising data and scan response data), in a hexadecimal string.|

**Example**

  ```
  bluetooth.subscribeBLEFound({
    success(data) {
      console.log('call bluetooth.subscribeBLEFound success, data: ${data}.');
    },
    fail(data, code) {
      console.log('call bluetooth.startBLEScan failed, code:' + code + ', data:' + data);
    }
  });
  ```


## bluetooth.unsubscribeBLEFound()

Unsubscribes from the newly detected devices.

**System capability**: SystemCapability.Communication.Bluetooth.Lite

**Example**

  ```
  bluetooth.unsubscribeBLEFound();
  ```


## Common Error Codes

| Error Code| Description|
| -------- | -------- |
| 1100 | The Bluetooth adapter is not initialized.|
| 1101 | The Bluetooth adapter is unavailable.|
| 1102 | The specified device is not found.|
| 1103 | Connection failed.|
| 1104 | The specified service is not found.|
| 1105 | The specified characteristic value is not found.|
| 1106 | The Bluetooth device is disconnected.|
| 1107 | The characteristic value does not support this operation.|
| 1108 | Other exceptions reported by the system.|
| 1109 | The system version does not support BLE.|
