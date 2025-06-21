# Bluetooth Subsystem Changelog

## cl.bluetooth.1 Change in Bluetooth BLE API Error Codes


**Access Level**

Public API

**Reason for the Change**

The error codes of BLE APIs do not provide sufficient information for developers to fix issues.

**Change Impact**

This change requires application adaptation.

Before change: If the BLE advertising, BLE scanning, GATT client, or GATT server API fails, only error code 2900099 is returned.

After change: If the BLE advertising, BLE scanning, GATT client, or GATT server API fails, an error code with detailed information is returned.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 6.0.0.32

**Key API/Component Changes**

| Module                               | Namespace               | Class| API                                                  |Change Description   |
| ------------------------------------ | ------------------- | -- | ------------------------------------------------------------ | -------------- |
| @ohos.bluetooth.ble.d.ts       | ble             |  | function startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | Added error code 2900010 Advertising resources exhausted.<br>Added error code 2902054 Maximum packet data length exceeded.|
| @ohos.bluetooth.ble.d.ts       | ble        |  | function startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback&lt;number&gt;): void; | Added error code 2900010 Broadcast resources exhausted.<br>Added error code 2902054 Maximum packet data length exceeded. |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function startAdvertising(advertisingParams: AdvertisingParams): Promise&lt;number&gt;; | Added error code 2900010 Broadcast resources exhausted.<br>Added error code 2902054 Maximum packet data length exceeded. |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback&lt;void&gt;): void; | Added error code 2902055 Invalid advertising ID. |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise&lt;void&gt;; | Added error code 2902055 Invalid advertising ID. |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback&lt;void&gt;): void; | Added error code 2902055 Invalid advertising ID. |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise&lt;void&gt;; | Added error code 2902055 Invalid advertising ID. |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function stopAdvertising(advertisingId: number, callback: AsyncCallback&lt;void&gt;): void; | Added error code 2902055 Invalid advertising ID. |
| @ohos.bluetooth.ble.d.ts       | ble        |  | function stopAdvertising(advertisingId: number): Promise&lt;void&gt;; | Added error code 2902055 Invalid advertising ID. |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901000 Read failure, read operation prohibited by the peer.<br>Added error code 2901003 Read failure, no connection with the peer.<br>Added error code 2901004 Read failure, link congestion.<br>Added error code 2901005 Read failure, link not encrypted.<br>Added error code 2901006 Read failure, link not authenticated.<br>Added error code 2901007 Read failure, link not authorized. |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901000 Read failure, read operation prohibited by the peer.<br>Added error code 2901003 Read failure, no connection with the peer.<br>Added error code 2901004 Read failure, link congestion.<br>Added error code 2901005 Read failure, link not encrypted.<br>Added error code 2901006 Read failure, link not authenticated.<br>Added error code 2901007 Read failure, link not authorized. |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901000 Read failure, read operation prohibited by the peer.<br>Added error code 2901003 Read failure, no connection with the peer.<br>Added error code 2901004 Read failure, link congestion.<br>Added error code 2901005 Read failure, link not encrypted.<br>Added error code 2901006 Read failure, link not authenticated.<br>Added error code 2901007 Read failure, link not authorized. |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901000 Read failure, read operation prohibited by the peer.<br>Added error code 2901003 Read failure, no connection with the peer.<br>Added error code 2901004 Read failure, link congestion.<br>Added error code 2901005 Read failure, link not encrypted.<br>Added error code 2901006 Read failure, link not authenticated.<br>Added error code 2901007 Read failure, link not authorized. |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType, callback: AsyncCallback&lt;void> ): void; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901001 Write failure, write operation prohibited by the peer.<br>Added error code 2901003 Write failure, no connection with the peer.<br>Added error code 2901004 Write failure, link congestion.<br>Added error code 2901005 Write failure, link not encrypted.<br>Added error code 2901006 Write failure, link not authenticated.<br>Added error code 2901007 Write failure, link not authorized.  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType): Promise&lt;void&gt;; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901001 Write failure, write operation prohibited by the peer.<br>Added error code 2901003 Write failure, no connection with the peer.<br>Added error code 2901004 Write failure, link congestion.<br>Added error code 2901005 Write failure, link not encrypted.<br>Added error code 2901006 Write failure, link not authenticated.<br>Added error code 2901007 Write failure, link not authorized.  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;void&gt;): void; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901001 Write failure, write operation prohibited by the peer.<br>Added error code 2901003 Write failure, no connection with the peer.<br>Added error code 2901004 Write failure, link congestion.<br>Added error code 2901005 Write failure, link not encrypted.<br>Added error code 2901006 Write failure, link not authenticated.<br>Added error code 2901007 Write failure, link not authorized.  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | writeDescriptorValue(descriptor: BLEDescriptor): Promise&lt;void&gt;; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901001 Write failure, write operation prohibited by the peer.<br>Added error code 2901003 Write failure, no connection with the peer.<br>Added error code 2901004 Write failure, link congestion.<br>Added error code 2901005 Write failure, link not encrypted.<br>Added error code 2901006 Write failure, link not authenticated.<br>Added error code 2901007 Write failure, link not authorized.  |
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | getRssiValue(callback: AsyncCallback&lt;number&gt;): void; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901003 No connection with the peer.|
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | getRssiValue(): Promise&lt;number&gt;; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901003 No connection with the peer.|
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901003 No connection with the peer.|
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901003 No connection with the peer.|
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeIndication( characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901003 No connection with the peer.|
| @ohos.bluetooth.ble.d.ts       | ble        | GattClientDevice  | setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;; | Added error code 2900011 Busy operation, previous operation not yet completed.<br>Added error code 2901003 No connection with the peer.|

**Adaptation Guide**

An application can print the error code of an API call to help locate faults.

For example, if the BLE advertising fails because the advertising packet data exceeds the maximum length, try the following:

```ts
let advSettings: ble.AdvertiseSetting = {
  "interval": 160,
  "connectable": true,
};
// 1. Construct advertising packet data whose length exceeds the maximum value.
let serviceUuidsArray: Array<string> = new Array();
serviceUuidsArray.push("00001111-1111-1000-8000-00805f9b34fb");
serviceUuidsArray.push("00001111-2222-1000-8000-00805f9b34fb");
serviceUuidsArray.push("00001111-3333-1000-8000-00805f9b34fb");
let advData: ble.AdvertiseData = {
  "serviceUuids": serviceUuidsArray,
  "manufactureData": new Array(),
  "serviceData": new Array(),
  "includeDeviceName": true,
};

try {
  ble.startAdvertising(advSettings, advData);
} catch (err) {
  // 2. According to the log, error code 2902054 is reported during API call, indicating that the advertising packet data length exceeds the maximum value.
  console.error("errCode: " + err.code + ", errMessage: " + err.message);
}
// 3. Determine whether the advertising packet construction mode is appropriate based on the following considerations:
// - Whether the local Bluetooth device name is needed.
// - Whether to construct certain advertising packets as advResponse.
```
