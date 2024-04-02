# BLE Development

## Introduction
Bluetooth advertising and scanning help discover Bluetooth-enabled devices and implement BLE communication. This topic walks you through on how to start and stop Bluetooth advertising and scanning.

## When to Use
You can use the APIs provided by the **ble** module to:

- Start and stop BLE advertising.
- Start and stop BLE scanning.

## Available APIs

For details about the APIs and sample code, see [@ohos.bluetooth.ble](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md).

The following table describes the related APIs.

| API                            | Description                                                                      |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| startBLEScan()                     | Starts BLE scanning.                                                              |
| stopBLEScan()                      | Stops BLE scanning.                                                               |
| startAdvertising()                 | Starts BLE advertising.                                                               |
| stopAdvertising()                  | Stops BLE advertising.                                                               |
| on(type: 'advertisingStateChange') | Subscribes to BLE advertising status.                                                               |
| off(type: 'advertisingStateChange')| Unsubscribes from BLE advertising status.                                                           |
| on(type: 'BLEDeviceFind')          | Subscribes to BLE device discovery events.                                                       |
| off(type: 'BLEDeviceFind')         | Unsubscribes from the BLE device discovery events.                                                    |

## How to Develop

### Starting and Stopping BLE Advertising
1. Import the **ble** module.
2. Enable Bluetooth on the device.
3. Check that the SystemCapability.Communication.Bluetooth.Core capability is available.
4. Start BLE advertising. The peer device scans the advertisement.
5. Stop BLE advertising.

Example:

```ts
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';

// Start BLE advertising.
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;
let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 5;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
let setting: ble.AdvertiseSetting = {
  interval: 150,
  txPower: 0,
  connectable: true
};
let manufactureDataUnit: ble.ManufactureData = {
  manufactureId: 4567,
  manufactureValue: manufactureValueBuffer.buffer
};
let serviceDataUnit: ble.ServiceData = {
  serviceUuid: "00001888-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let advData: ble.AdvertiseData = {
  serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb"],
  manufactureData: [manufactureDataUnit],
  serviceData: [serviceDataUnit],
  includeDeviceName: false // Indicates whether the device name is carried. This parameter is optional. Note that the length of a broadcast packet including the device name cannot exceed 31 bytes.
};
let advResponse: ble.AdvertiseData = {
  serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb"],
  manufactureData: [manufactureDataUnit],
  serviceData: [serviceDataUnit]
};

ble.startAdvertising(setting, advData, advResponse);
console.info('startAdvertising success');

// Stop BLE advertising.
ble.stopAdvertising();
console.info('stopAdvertising success');
```

For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).

**Verification**

1. Execute the code for starting BLE advertising. 

   "startAdvertising success" is logged. 
2. Start scanning on another device that has the nrfConnect software installed.
   If the device obtains the following information, the BLE advertising is started:
   Manufacturer data: 0x01020304, Service Data: 0x05060708
3. Stop BLE advertising.
   The peer device will not receive that advertisement.
### Starting and Stop BLE Scanning
1. Import the **ble** module.
2. Enable Bluetooth on the device.
3. Check that the SystemCapability.Communication.Bluetooth.Core capability is available.
4. Start BLE advertising on the peer device.
5. Start BLE scanning on the local device.
6. Stop BLE scanning.

Example:

```ts
import ble from '@ohos.bluetooth.ble';
import { BusinessError } from '@ohos.base';

// Start BLE scanning.
let scanFilter: ble.ScanFilter = {
  name: 'Jackistang'
};
let scanOptions: ble.ScanOptions = {
  interval: 500,
  dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
  matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
}
ble.startBLEScan([scanFilter], scanOptions);
console.info('startBleScan success')

// Return the scanning result.
ble.on('BLEDeviceFind', (data) => {
  if (data.length > 0) {
    console.info('BLE scan result = ' + data[0].deviceName);
  }
});

// Stop BLE scanning.
ble.stopBLEScan();
console.info('stopBleScan success');
```

For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).

**Verification**

1. Install the nrfConnect software on device B, configure BLE advertising, change the device name to **Jackistang**, and start BLE advertising. 
2. Start scanning on device A. 
   If "BLE scan result = = Jackistang" is logged every 0.5 seconds on device A, the scanning is started. 
3. Stop scanning on device A.
   Device A will not receive "BLE scan result = = Jackistang".