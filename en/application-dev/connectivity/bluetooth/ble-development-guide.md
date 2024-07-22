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
| disableAdvertising()                | Disables BLE advertising temporarily.                                                               |
| enableAdvertising()                | Enables BLE advertising temporarily.                                                               |
| stopAdvertising()                  | Stops BLE advertising.                                                               |
| on(type: 'advertisingStateChange') | Subscribes to BLE advertising state changes.                                                               |
| off(type: 'advertisingStateChange')| Unsubscribes from BLE advertising state changes.                                                           |
| on(type: 'BLEDeviceFind')          | Subscribes to the BLE device discovery event.                                                       |
| off(type: 'BLEDeviceFind')         | Unsubscribes from the BLE device discovery event.                                                    |

## How to Develop

### Starting and Stopping BLE Advertising
1. Import the **ble** module.
2. Enable Bluetooth on the device.
3. Check that the SystemCapability.Communication.Bluetooth.Core capability is available.
4. Start BLE advertising. The peer device scans the advertisement.
5. Stop BLE advertising.
Example:

    ```ts
    import { ble } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    const TAG: string = 'BleAdvertisingManager';

    export class BleAdvertisingManager {
      private advHandle: number = 0xFF; // default invalid value

      // 1. Subscribe to BLE advertising state changes.
      public onAdvertisingStateChange() {
        try {
          ble.on('advertisingStateChange', (data: ble.AdvertisingStateChangeInfo) => {
            console.info(TAG, 'bluetooth advertising state = ' + JSON.stringify(data));
            AppStorage.setOrCreate('advertiserState', data.state);
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 2. Start BLE advertising the first time.
      public async startAdvertising() {
        // 2.1 Set BLE advertising parameters.
        let setting: ble.AdvertiseSetting = {
          interval: 160,
          txPower: 0,
          connectable: true
        };
        // 2.2 Construct the data to be advertised.
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
          includeDeviceName: false // Whether the device name is carried. This parameter is optional. Note that the length of an advertising packet including the device name cannot exceed 31 bytes.
        };
        let advResponse: ble.AdvertiseData = {
          serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb"],
          manufactureData: [manufactureDataUnit],
          serviceData: [serviceDataUnit]
        };
        // 2.3 Construct AdvertisingParams for starting the BLE advertising.
        let advertisingParams: ble.AdvertisingParams = {
          advertisingSettings: setting,
          advertisingData: advData,
          advertisingResponse: advResponse,
          duration: 0 // This parameter is optional. If the value is greater than 0, the advertising stops temporarily after a period of time. You can restart it as required.
        }

        // 2.4 Start BLE advertising the first time. The ID of the BLE advertising is returned.
        try {
          this.onAdvertisingStateChange();
          this.advHandle = await ble.startAdvertising(advertisingParams);
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 4. Disable the BLE advertising temporarily. The advertising resources still exist.
      public async disableAdvertising() {
        // 4.1 Construct parameters for temporarily disabling the BLE advertising.
        let advertisingDisableParams: ble.AdvertisingDisableParams = {
          advertisingId: this.advHandle // Use the ID of the first BLE advertising.
        }
        // 4.2 Disable the BLE advertising temporarily.
        try {
          await ble.disableAdvertising(advertisingDisableParams);
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 5. Enable the BLE advertising again.
      public async enableAdvertising(enableDuration: number) {
        // 5.1 Construct the parameters for temporarily enabling the advertising.
        let advertisingEnableParams: ble.AdvertisingEnableParams = {
          advertisingId: this.advHandle // Use the ID of the first BLE advertising.
          duration: enableDuration
        }
        // 5.2 Enable BLE advertising again.
        try {
          await ble.enableAdvertising(advertisingEnableParams);
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 6. Stop BLE advertising and release related resources.
      public async stopAdvertising() {
        try {
          await ble.stopAdvertising(this.advHandle);
          ble.off('advertisingStateChange', (data: ble.AdvertisingStateChangeInfo) => {
            console.info(TAG, 'bluetooth advertising state = ' + JSON.stringify(data));
          });
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }

    let bleAdvertisingManager = new BleAdvertisingManager();
    export default bleAdvertisingManager as BleAdvertisingManager;
    ```

For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).

### Starting and Stop BLE Scanning
1. Import the **ble** module.
2. Enable Bluetooth on the device.
3. Check that the SystemCapability.Communication.Bluetooth.Core capability is available.
4. Start BLE advertising on the peer device.
5. Start BLE scanning on the local device.
6. Stop BLE scanning.
Example:

    ```ts
    import { ble } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    const TAG: string = 'BleScanManager';

    export class BleScanManager {
      // 1. Subscribe to the scanning result.
      public onScanResult() {
        ble.on('BLEDeviceFind', (data: Array<ble.ScanResult>) => {
          if (data.length > 0) {
            console.info(TAG, 'BLE scan result = ' + data[0].deviceId);
          }
        });
      }

      // 2. Start scanning.
      public startScan() {
        // 2.1 Construct a scan filter that matches the expected advertising packet content.
        let manufactureId = 4567;
        let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
        let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
        let scanFilter: ble.ScanFilter = {// Define the filter based on site requirements.
          manufactureId: manufactureId,
          manufactureData: manufactureData.buffer,
          manufactureDataMask: manufactureDataMask.buffer
        };

        // 2.2 Construct scanning parameters.
        let scanOptions: ble.ScanOptions = {
          interval: 0,
          dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
          matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
        }
        try {
          this.onScanResult(); // Subscribe to the scanning result.
          ble.startBLEScan([scanFilter], scanOptions);
          console.info(TAG, 'startBleScan success');
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }

      // 3. Stop scanning.
      public stopScan() {
        try {
          ble.off('BLEDeviceFind', (data: Array<ble.ScanResult>) => { // Unsubscribe from the scanning result.
            console.info(TAG, 'off success');
          });
          ble.stopBLEScan();
          console.info(TAG, 'stopBleScan success');
        } catch (err) {
          console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
        }
      }
    }

    let bleScanManager = new BleScanManager();
    export default bleScanManager as BleScanManager;
    ```

For details about the error codes, see [Bluetooth Error Codes](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md).