# BLE Scanning and Advertising

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->

## Introduction
This guide describes how to implement Bluetooth Low Energy (BLE) scanning and advertising. It supports scenarios such as discovering nearby BLE devices and enabling other devices to detect the local device.

## How to Develop

### Applying for Required Permissions
Apply for the **ohos.permission.ACCESS_BLUETOOTH** permission. For details about how to configure and apply for permissions, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

### Importing Required Modules
Import the **ble** and **BusinessError** modules.
```ts
import { ble } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

### BLE Scanning Process

**1. Subscribing to Scan Result Reporting Events**<br>
- You are advised to use the scan mode supported since API version 15, which allows an application to initiate and manage multiple scans. For details about the reporting events supported by this mode, see [on('BLEDeviceFind')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#onbledevicefind15).
```ts
// Define the callback for scan result reporting events.
function onReceiveEvent(scanReport: ble.ScanReport) {
  console.info('BLE scan device find result: '+ JSON.stringify(scanReport));
}

// Create a BleScanner instance. The instance can manage the scanning processes created under it.
let bleScanner: ble.BleScanner = ble.createBleScanner();

try {
  // Subscribe to scan result reporting events.
  bleScanner.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- The scan mode supported by API version 14 or earlier allows applications to initiate a single scan at a time. For details about the reporting events supported by this mode, see [ble.on('BLEDeviceFind')](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#bleonbledevicefind).
```ts
// Define the callback for scan result reporting events.
function onReceiveEvent(data: Array<ble.ScanResult>) {
  console.info('BLE scan device find result: '+ JSON.stringify(data));
}

try {
  // Enable event listening.
  ble.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- For details about how to parse advertising packets, see [Sample Code](#sample-code).

**2. Initiating a Scan**<br>
By scanning BLE advertisements from other nearby devices via BLE, you can discover or find the target devices required by the application.

If the local device detects a connectable BLE advertisement, it can establish a connection and perform data transmission with that device via the Generic Attribute Profile (GATT). In this case, the local device is also referred to as the GATT client. For details about specific operations, see [GATT-based Connection and Data Transmission](gatt-development-guide.md).

- You are advised to use the scan mode supported since API version 15, which allows an application to initiate and manage multiple scans. You can create a [BleScanner](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blescanner15) instance using [createBleScanner](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blecreateblescanner15) and start a scan using [startScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#startscan15).
```ts
// Create a bleScanner instance.
let bleScanner: ble.BleScanner = ble.createBleScanner();

// Construct a ScanFilter instance for scanning BLE advertising packets. The target BLE advertising packets must meet the filter criteria.
let manufactureId = 4567;
let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
let scanFilter: ble.ScanFilter = {// Define the ScanFilter instance based on service requirements.
  manufactureId: manufactureId,
  manufactureData: manufactureData.buffer,
  manufactureDataMask: manufactureDataMask.buffer
};

// Construct a ScanOptions instance.
let scanOptions: ble.ScanOptions = {
  interval: 0,
  dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
  matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
}

try {
  // Initiate a scan.
  bleScanner.startScan([scanFilter], scanOptions);
  console.info('startBleScan success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- The scan mode supported by API version 14 or earlier allows applications to initiate a single scan at a time. If you want to initiate another scan, you must stop the previous scan first. For details, see [ble.startBLEScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartblescan).
```ts
// Construct a ScanFilter instance for scanning BLE advertising packets. The target BLE advertising packets must meet the filter criteria.
let manufactureId = 4567;
let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
let scanFilter: ble.ScanFilter = {// Define the ScanFilter instance based on service requirements.
  manufactureId: manufactureId,
  manufactureData: manufactureData.buffer,
  manufactureDataMask: manufactureDataMask.buffer
};

// Construct a ScanOptions instance.
let scanOptions: ble.ScanOptions = {
  interval: 0,
  dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
  matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
}
try {
  // Initiate a scan.
  ble.startBLEScan([scanFilter], scanOptions);
  console.info('startBleScan success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**3. Stopping the Scan**<br>
Scanning is a process that consumes a large amount of Bluetooth hardware resources and affects device power consumption. Stop the scan if it is no longer needed.

- Since API version 15, the scan mode allows an application to initiate and manage multiple scans. To stop the scan, use [stopScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#stopscan15).
```ts
// Define the callback for scan result reporting events.
function onReceiveEvent(scanReport: ble.ScanReport) {
  console.info('BLE scan device find result: '+ JSON.stringify(scanReport));
}

// Create a bleScanner instance.
let bleScanner: ble.BleScanner = ble.createBleScanner();

try {
  bleScanner.off('BLEDeviceFind', onReceiveEvent);
  // Stop the scan.
  bleScanner.stopScan();
  console.info('stopBleScan success');
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- In API version 14 or earlier, the scan mode allows an application to initiate a single scan at a time. To stop the scan, use [ble.stopBLEScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopblescan).
```ts
// Define the callback for scan result reporting events.
function onReceiveEvent(data: Array<ble.ScanResult>) {
  console.info('BLE scan device find result: '+ JSON.stringify(data));
}

try {
  // Disable event listening.
  ble.off('BLEDeviceFind', onReceiveEvent);
  // Stop the scan.
  ble.stopBLEScan();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### BLE Advertising Process
A local device becomes discoverable to other devices by sending BLE advertisements.

Specifically, if it sends a connectable BLE advertisement, it can establish a connection and transmit data with the scanning device via GATT. In this case, the local device is also referred to as the GATT client. For details about specific operations, see [GATT-based Connection and Data Transmission](gatt-development-guide.md).

You are advised to use the BLE advertising mode supported since API version 11.

**1. Subscribing to BLE Advertising Status Reporting Events**<br>
For the BLE advertising mode supported since API version 11, use the following code:
```ts
function onReceiveEvent(data: ble.AdvertisingStateChangeInfo) {
    console.info('bluetooth advertising state = ' + JSON.stringify(data));
}

try {
    ble.on('advertisingStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**2. Starting BLE Advertising**<br>
- You are advised to use the BLE advertising mode supported since API version 11. This mode supports starting or stopping advertising with a specified ID multiple times without releasing the relevant advertising resources, and setting the duration for continuous advertising.<br>
For details about related APIs, see [ble.startAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartadvertising11) and [ble.enableAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#bleenableadvertising11).<br>
If [ble.startAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartadvertising11) is called for the first time, related resources are allocated while advertising is started. Since API version 15, you can call this API multiple times to establish multiple advertising channels, each being identified by a unique ID.
```ts
// Set BLE advertising parameters.
let setting: ble.AdvertiseSetting = {
    interval: 160,
    txPower: 0,
    connectable: true // Send a connectable BLE advertisement.
};
// Construct advertising data.
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
let serviceDataUnit1: ble.ServiceData = {
  serviceUuid: "00001999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let serviceDataUnit2: ble.ServiceData = {
  serviceUuid: "19991999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let advData: ble.AdvertiseData = {
  serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb", "18881888-0000-1000-8000-00805f9b34fb"],
  manufactureData: [manufactureDataUnit],
  serviceData: [],
  includeDeviceName: false // Whether the device name is contained. This parameter is optional. Note that the BLE advertising will fail if the maximum length (31 bytes) is exceeded.
};
let advResponse: ble.AdvertiseData = {
  serviceUuids: [],
  manufactureData: [],
  serviceData: [serviceDataUnit1, serviceDataUnit2],
};
// Construct an AdvertisingParams instance for starting the BLE advertising.
let advertisingParams: ble.AdvertisingParams = {
  advertisingSettings: setting,
  advertisingData: advData, // The length of advertising packets cannot exceed 31 bytes.
  advertisingResponse: advResponse, // The length of advertising packets cannot exceed 31 bytes.
  duration: 0 // Advertising duration. This parameter is optional. If the value is greater than 0, advertising will stop after the specified duration elapses, but the allocated advertising resources will remain. You can start advertising again as needed.
}

let advHandle = 0xFF; // Define the BLE advertising ID.

// During initial advertising, the Bluetooth subsystem automatically allocates relevant resources, including the BLE advertising ID obtained by the application.
try {
  ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
    if (err) {
      return;
    } else {
      advHandle = outAdvHandle;
      console.info("advHandle: " + advHandle);
    }
  });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// Construct an advertisingEnableParams instance for enabling advertising.
let advertisingEnableParams: ble.AdvertisingEnableParams = {
  advertisingId: advHandle, // Use the BLE advertising ID obtained by the application during initial advertising.
  duration: 300
}
try {
  // Start advertising again.
  ble.enableAdvertising(advertisingEnableParams, (err) => {
    if (err) {
      return;
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

- The scan mode supported by API version 10 or earlier allows applications to initiate a single scan at a time. If you want to initiate another scan, you must stop the previous scan by using [ble.startAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestartadvertising).
```ts
// Set BLE advertising parameters.
let setting: ble.AdvertiseSetting = {
    interval: 160,
    txPower: 0,
    connectable: true
};
// Construct advertising data.
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
let serviceDataUnit1: ble.ServiceData = {
  serviceUuid: "00001999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let serviceDataUnit2: ble.ServiceData = {
  serviceUuid: "19991999-0000-1000-8000-00805f9b34fb",
  serviceValue: serviceValueBuffer.buffer
};
let advData: ble.AdvertiseData = {
  serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb", "18881888-0000-1000-8000-00805f9b34fb"],
  manufactureData: [manufactureDataUnit],
  serviceData: [],
  includeDeviceName: false // Whether the device name is carried. This parameter is optional. Note that the length of an advertising packet including the device name cannot exceed 31 bytes.
};
let advResponse: ble.AdvertiseData = {
  serviceUuids: [],
  manufactureData: [],
  serviceData: [serviceDataUnit1, serviceDataUnit2],
};
try {
  // Start advertising.
  ble.startAdvertising(setting, advData ,advResponse);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**3. Stopping Advertising**<br>
Advertising is a process that consumes a large amount of Bluetooth hardware resources and affects device power consumption. Stop the BLE advertising if it is no longer needed.

- For the BLE advertising mode supported since API version 11, use [ble.disableAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#bledisableadvertising11) or [ble.stopAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopadvertising11).<br>
After [ble.stopAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopadvertising11) is called, advertising is disabled and the BLE advertising ID allocated during initial advertising becomes invalid.
```ts
let advHandle = 1; // The value is the BLE advertising ID obtained during initial advertising. It is a pseudo code ID.

// Construct an advertisingDisableParams instance for disabling BLE advertising.
let advertisingDisableParams: ble.AdvertisingDisableParams = {
    advertisingId: advHandle // Use the BLE advertising ID obtained by the application during initial advertising.
}
try {
  // Disable the BLE advertising.
  ble.disableAdvertising(advertisingDisableParams, (err) => {
    if (err) {
      return;
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

try {
  // Stop the BLE advertising.
  ble.stopAdvertising(advHandle, (err) => {
    if (err) {
      return;
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```

- For the BLE advertising mode supported by API version 10 or earlier, use [ble.stopAdvertising](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#blestopadvertising).
```ts
try {
  // Stop the BLE advertising.
  ble.stopAdvertising();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## Sample Code

### BLE Scanning
```ts
import { ble } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

const TAG: string = 'BleAdvertisingManager';

// See Core Assigned Numbers in Bluetooth Core Specification.
const BLE_ADV_TYPE_FLAG = 0x01;
const BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_INCOMPLETE = 0x02;
const BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_COMPLETE = 0x03;
const BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_INCOMPLETE = 0x04;
const BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_COMPLETE = 0x05;
const BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_INCOMPLETE = 0x06;
const BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_COMPLETE = 0x07;
const BLE_ADV_TYPE_LOCAL_NAME_SHORT = 0x08;
const BLE_ADV_TYPE_LOCAL_NAME_COMPLETE = 0x09;
const BLE_ADV_TYPE_TX_POWER_LEVEL = 0x0A;
const BLE_ADV_TYPE_16_BIT_SERVICE_SOLICITATION_UUIDS = 0x14;
const BLE_ADV_TYPE_128_BIT_SERVICE_SOLICITATION_UUIDS = 0x15;
const BLE_ADV_TYPE_32_BIT_SERVICE_SOLICITATION_UUIDS = 0x1F;
const BLE_ADV_TYPE_16_BIT_SERVICE_DATA = 0x16;
const BLE_ADV_TYPE_32_BIT_SERVICE_DATA = 0x20;
const BLE_ADV_TYPE_128_BIT_SERVICE_DATA = 0x21;
const BLE_ADV_TYPE_MANUFACTURER_SPECIFIC_DATA = 0xFF;

const BLUETOOTH_UUID_16_BIT_LENGTH = 2;
const BLUETOOTH_UUID_32_BIT_LENGTH = 4;
const BLUETOOTH_UUID_128_BIT_LENGTH = 16;

const BLUETOOTH_MANUFACTURE_ID_LENGTH = 2;

export class BleScanManager {
  bleScanner: ble.BleScanner = ble.createBleScanner();

  // 1. Define the callback for scan result reporting events.
  onReceiveEvent = (scanReport: ble.ScanReport) => {
    console.info(TAG, 'BLE scan device find result: '+ JSON.stringify(scanReport));
    if (scanReport.scanResult.length > 0) {
      console.info(TAG, 'BLE scan result: ' + scanReport.scanResult[0].deviceId);
      this.parseScanResult(scanReport.scanResult[0].data);
    }
  };

  public parseScanResult(data: ArrayBuffer) {
    let advData = new Uint8Array(data);
    if (advData.byteLength == 0) {
      console.warn(TAG, 'adv data length is 0');
      return;
    }

    let advertiseFlags: number = -1;
    let txPowerLevel: number = -1;
    let localName: string = '';
    let serviceUuids: string[] = [];
    let serviceSolicitationUuids: string[] = [];
    let manufactureSpecificDatas: Record<number, Uint8Array> = {};
    let serviceDatas: Record<string, Uint8Array> = {};

    let curPos = 0;
    while (curPos < advData.byteLength) {
      let length = advData[curPos++]; // Obtain the length (length + data) of the current advertising type, where curPos points to the next position.
      if (length == 0) {
        break;
      }

      // Obtain the content length (data) of the current advertising type.
      let advDataLength = length - 1;

      // Obtain the current advertising type, where curPos points to the next position. Parse the actual content from this position. For details, see Part A of Core Specification Supplement.
      let advDataType = advData[curPos++];
      switch (advDataType) {
        case BLE_ADV_TYPE_FLAG:
          advertiseFlags = advData[curPos];
          break;
        case BLE_ADV_TYPE_LOCAL_NAME_SHORT:
        case BLE_ADV_TYPE_LOCAL_NAME_COMPLETE:
          localName = advData.slice(curPos, curPos + advDataLength).toString();
          break;
        case BLE_ADV_TYPE_TX_POWER_LEVEL:
          txPowerLevel = advData[curPos];
          break;
        case BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_INCOMPLETE:
        case BLE_ADV_TYPE_16_BIT_SERVICE_UUIDS_COMPLETE:
          this.parseServiceUuid(BLUETOOTH_UUID_16_BIT_LENGTH, curPos, advDataLength, advData, serviceUuids);
          break;
        case BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_INCOMPLETE:
        case BLE_ADV_TYPE_32_BIT_SERVICE_UUIDS_COMPLETE:
          this.parseServiceUuid(BLUETOOTH_UUID_32_BIT_LENGTH, curPos, advDataLength, advData, serviceUuids);
          break;
        case BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_INCOMPLETE:
        case BLE_ADV_TYPE_128_BIT_SERVICE_UUIDS_COMPLETE:
          this.parseServiceUuid(BLUETOOTH_UUID_128_BIT_LENGTH, curPos, advDataLength, advData, serviceUuids);
          break;
        case BLE_ADV_TYPE_16_BIT_SERVICE_SOLICITATION_UUIDS:
          this.parseServiceSolicitationUuid(BLUETOOTH_UUID_16_BIT_LENGTH, curPos, advDataLength,
            advData, serviceSolicitationUuids);
          break;
        case BLE_ADV_TYPE_32_BIT_SERVICE_SOLICITATION_UUIDS:
          this.parseServiceSolicitationUuid(BLUETOOTH_UUID_32_BIT_LENGTH, curPos, advDataLength,
            advData, serviceSolicitationUuids);
          break;
        case BLE_ADV_TYPE_128_BIT_SERVICE_SOLICITATION_UUIDS:
          this.parseServiceSolicitationUuid(BLUETOOTH_UUID_128_BIT_LENGTH, curPos, advDataLength,
            advData, serviceSolicitationUuids);
          break;
        case BLE_ADV_TYPE_16_BIT_SERVICE_DATA:
          this.parseServiceData(BLUETOOTH_UUID_16_BIT_LENGTH, curPos, advDataLength, advData, serviceDatas);
          break;
        case BLE_ADV_TYPE_32_BIT_SERVICE_DATA:
          this.parseServiceData(BLUETOOTH_UUID_32_BIT_LENGTH, curPos, advDataLength, advData, serviceDatas);
          break;
        case BLE_ADV_TYPE_128_BIT_SERVICE_DATA:
          this.parseServiceData(BLUETOOTH_UUID_128_BIT_LENGTH, curPos, advDataLength, advData, serviceDatas);
          break;
        case BLE_ADV_TYPE_MANUFACTURER_SPECIFIC_DATA:
          this.parseManufactureData(curPos, advDataLength, advData, manufactureSpecificDatas);
          break;
        default:
          break;
      }
      curPos += advDataLength; // curPos points to the next field type.
    }
    console.info(TAG, 'advertiseFlags: ' + advertiseFlags);
    console.info(TAG, 'txPowerLevel: ' + txPowerLevel);
    console.info(TAG, 'localName: ' + localName);
    console.info(TAG, 'serviceUuids: ' + JSON.stringify(serviceUuids));
    console.info(TAG, 'serviceSolicitationUuids: ' + JSON.stringify(serviceSolicitationUuids));
    console.info(TAG, 'manufactureSpecificDatas: ' + JSON.stringify(manufactureSpecificDatas));
    console.info(TAG, 'serviceDatas: ' + JSON.stringify(serviceDatas));
  }

  private parseServiceUuid(uuidLength: number, curPos: number, advDataLength: number,
    advData: Uint8Array, serviceUuids: string[]) {
    while (advDataLength > 0) {
      let tmpData: Uint8Array = advData.slice(curPos, curPos + uuidLength);
      serviceUuids.push(this.getUuidFromUint8Array(uuidLength, tmpData));
      advDataLength -= uuidLength;
      curPos += uuidLength;
    }
  }

  private parseServiceSolicitationUuid(uuidLength: number, curPos: number, advDataLength: number,
    advData: Uint8Array, serviceSolicitationUuids: string[]) {
    while (advDataLength > 0) {
      let tmpData: Uint8Array = advData.slice(curPos, curPos + uuidLength);
      serviceSolicitationUuids.push(this.getUuidFromUint8Array(uuidLength, tmpData));
      advDataLength -= uuidLength;
      curPos += uuidLength;
    }
  }

  private getUuidFromUint8Array(uuidLength: number, uuidData: Uint8Array): string {
    let uuid = "";
    let temp: string = "";
    for (let i = uuidLength - 1; i > -1; i--) {
      temp += uuidData[i].toString(16).padStart(2, "0");
    }
    switch (uuidLength) {
      case BLUETOOTH_UUID_16_BIT_LENGTH:
        uuid = `0000${temp}-0000-1000-8000-00805F9B34FB`;
        break;
      case BLUETOOTH_UUID_32_BIT_LENGTH:
        uuid = `${temp}-0000-1000-8000-00805F9B34FB`;
        break;
      case BLUETOOTH_UUID_128_BIT_LENGTH:
        uuid = `${temp.substring(0, 8)}-${temp.substring(8, 12)}-${temp.substring(12, 16)}-${temp.substring(16, 20)}-${temp.substring(20, 32)}`;
        break;
      default:
        break;
    }
    return uuid;
  }

  private parseServiceData(uuidLength: number, curPos: number, advDataLength: number,
    advData: Uint8Array, serviceDatas: Record<number, Uint8Array>) {
    let uuid: Uint8Array = advData.slice(curPos, curPos + uuidLength);
    let data: Uint8Array = advData.slice(curPos + uuidLength, curPos + advDataLength);
    serviceDatas[this.getUuidFromUint8Array(uuidLength, uuid)] = data;
  }

  private parseManufactureData(curPos: number, advDataLength: number,
    advData: Uint8Array, manufactureSpecificDatas: Record<number, Uint8Array>) {
    let manufactureId: number = (advData[curPos + 1] << 8) + advData[curPos];
    let data: Uint8Array = advData.slice(curPos + BLUETOOTH_MANUFACTURE_ID_LENGTH, curPos + advDataLength);
    manufactureSpecificDatas[manufactureId] = data;
  }

  // 2. Start a scan.
  public startScan() {
    // 2.1 Construct a ScanFilter instance for scanning BLE advertising packets. The target BLE advertising packets must meet the filter criteria.
    let manufactureId = 4567;
    let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
    let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);
    let scanFilter: ble.ScanFilter = {// Define the ScanFilter instance based on service requirements.
      manufactureId: manufactureId,
      manufactureData: manufactureData.buffer,
      manufactureDataMask: manufactureDataMask.buffer
    };

    // 2.2 Construct a ScanOptions instance.
    let scanOptions: ble.ScanOptions = {
      interval: 0,
      dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
      matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
    }
    try {
      // Subscribe to scan result reporting events.
      this.bleScanner.on('BLEDeviceFind', this.onReceiveEvent);
      // Initiate a scan.
      this.bleScanner.startScan([scanFilter], scanOptions);
      console.info('startBleScan success');
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 3. Stop the scan.
  public stopScan() {
    try {
      // Disable event listening.
      this.bleScanner.off('BLEDeviceFind', this.onReceiveEvent);
      // Stop the scan.
      this.bleScanner.stopScan();
      console.info('stopBleScan success');
    } catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }
}

let bleScanManager = new BleScanManager();
export default bleScanManager as BleScanManager;
```

### BLE Advertising
```ts
import { ble } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'BleAdvertisingManager';

export class BleAdvertisingManager {
  private advHandle: number = 0xFF; // Initial invalid value.

  // 1. Define the BLE advertising status reporting event.
  onReceiveEvent = (data: ble.AdvertisingStateChangeInfo) => {
    console.info(TAG, 'bluetooth advertising state = ' + JSON.stringify(data));
    AppStorage.setOrCreate('advertiserState', data.state);
  };

  // 2. Start BLE advertising for the first time.
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
    let serviceDataUnit1: ble.ServiceData = {
      serviceUuid: "00001999-0000-1000-8000-00805f9b34fb",
      serviceValue: serviceValueBuffer.buffer
    };
    let serviceDataUnit2: ble.ServiceData = {
      serviceUuid: "19991999-0000-1000-8000-00805f9b34fb",
      serviceValue: serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
      serviceUuids: ["00001888-0000-1000-8000-00805f9b34fb", "18881888-0000-1000-8000-00805f9b34fb"],
      manufactureData: [manufactureDataUnit],
      serviceData: [],
      includeDeviceName: false // Whether the device name is contained. This parameter is optional. Note that the BLE advertising will fail if the maximum length (31 bytes) is exceeded.
    };
    let advResponse: ble.AdvertiseData = {
      serviceUuids: [],
      manufactureData: [],
      serviceData: [serviceDataUnit1, serviceDataUnit2],
    };
    // 2.3 Construct AdvertisingParams for starting the BLE advertising.
    let advertisingParams: ble.AdvertisingParams = {
      advertisingSettings: setting,
      advertisingData: advData, // The length of advertising packets cannot exceed 31 bytes.
      advertisingResponse: advResponse, // The length of advertising packets cannot exceed 31 bytes.
      duration: 0 // Advertising duration. This parameter is optional. If the value is greater than 0, advertising will stop after the specified duration elapses, but the allocated advertising resources will remain. You can start advertising again as needed.
    }

    // 2.4 During initial advertising, the Bluetooth subsystem automatically allocates relevant resources, including the BLE advertising ID obtained by the application.
    try {
      ble.on('advertisingStateChange', this.onReceiveEvent);
      this.advHandle = await ble.startAdvertising(advertisingParams);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 3. Disable the BLE advertising with the specified ID, that is, the ID allocated during initial advertising. The allocated advertising resources will remain after the BLE advertising is disabled.
  public async disableAdvertising() {
    // 3.1 Construct an advertisingDisableParams instance for disabling BLE advertising.
    let advertisingDisableParams: ble.AdvertisingDisableParams = {
      advertisingId: this.advHandle // Use the ID of the first BLE advertising.
    }
    try {
      // 3.2 Disable the BLE advertising.
      await ble.disableAdvertising(advertisingDisableParams);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 4. Enable the BLE advertising with the specified ID, that is, the ID allocated during initial advertising
  public async enableAdvertising(enableDuration: number) {
    // 4.1 Construct an advertisingEnableParams instance for enabling BLE advertising.
    let advertisingEnableParams: ble.AdvertisingEnableParams = {
      advertisingId: this.advHandle // Use the ID of the first BLE advertising.
      duration: enableDuration
    }
    try {
      // 4.2 Enable BLE advertising again.
      await ble.enableAdvertising(advertisingEnableParams);
    } catch (err) {
      console.error(TAG, 'errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
  }

  // 5. Stop BLE advertising to release related resources.
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
