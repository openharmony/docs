# @ohos.bluetooth.ble (Bluetooth BLE Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

The **ble** module provides Bluetooth Low Energy (BLE) capabilities, including BLE scan, BLE advertising, and Generic Attribute Profile (GATT)-based connection and data transmission.

> **NOTE**
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - You can use [util.generateRandomUUID](../apis-arkts/js-apis-util.md#utilgeneraterandomuuid9) to generate a UUID wherever necessary.



## Modules to Import

```js
import { ble } from '@kit.ConnectivityKit';
```


## ProfileConnectionState<sup>10+</sup>

type ProfileConnectionState = constant.ProfileConnectionState

Defines the profile connection status of the Bluetooth device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                 | Description                 |
| ------------------- | ------------------- |
| [constant.ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | Profile connection status of the Bluetooth device.|


## ble.createGattServer

createGattServer(): GattServer

Creates a [GattServer](#gattserver) instance, which represents the server in a GATT connection.
- You can use this instance to operate the server, for example, call [addService](#addservice) to add a server and use [notifyCharacteristicChanged](#notifycharacteristicchanged) report characteristic changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [GattServer](#gattserver) | **GattServer** instance created.|

**Example**

```js
let gattServer: ble.GattServer = ble.createGattServer();
console.info('gatt success');
```


## ble.createGattClientDevice

createGattClientDevice(deviceId: string): GattClientDevice

Creates a [GattClientDevice] instance, which represents the client in a GATT connection.
- You can use this instance to operate the client, for example, call [connect](#connect) to initiate a connection to the peer device and call [getServices](#getservices) to obtain all service capabilities supported by the peer device.
- This API requires the device address of the server. You can obtain the device address of the server by calling [ble.startBLEScan](#blestartblescan) or [startScan](#startscan15) of [BleScanner](#blescanner15). Ensure that the BLE advertising of the server is enabled.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                  |
| -------- | ------ | ---- | ------------------------------------ |
| deviceId | string | Yes   | Address of the peer device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                                   | Description                                  |
| ------------------------------------- | ------------------------------------ |
| [GattClientDevice](#gattclientdevice) | **GattClientDevice** instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.getConnectedBLEDevices

getConnectedBLEDevices(): Array&lt;string&gt;

Obtains the BLE devices that have been connected to the local device via GATT.
- It is recommended that this API be used on the server. If this API is used on the client, the returned device address is empty.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;string&gt; | Addresses of BLE devices that have been connected to the local device via GATT.<br>For security purposes, the device addresses obtained are virtual MAC addresses.<br>- The virtual address remains unchanged after a device is paired successfully.<br>- If a device is unpaired or Bluetooth is disabled, the virtual address will change after the device is paired again.<br>- To persistently save the addresses, call [access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let result: Array<string> = ble.getConnectedBLEDevices();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.startBLEScan

startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void

Starts BLE scanning.
- You can obtain the scan result through the callback of [ble.on('BLEDeviceFind')](#bleonbledevicefind). Only BLE devices can be discovered. You can call [ble.stopBLEScan](#blestopblescan) to stop the BLE scan.
- This API supports only single-channel scans. That is, the application can call this API only once at a time. Before calling this API again, you need to call [ble.stopBLEScan](#blestopblescan) to stop the previous scan.
- To use multi-channel scans, call [BleScanner](#blescanner15).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | Yes   | Rules for filtering the scan result. Devices that meet the filtering rules will be retained.<br>If this parameter is set to **null**, all discoverable BLE devices nearby will be scanned. However, this method is not recommended as it may pick up unexpected devices and increase power consumption.|
| options | [ScanOptions](#scanoptions)            | No   | Scan options.                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<ble.ScanResult>) {
    console.info('BLE scan device find result = '+ JSON.stringify(data));
}
try {
    ble.on("BLEDeviceFind", onReceiveEvent);
    let scanFilter: ble.ScanFilter = {
            deviceId:"XX:XX:XX:XX:XX:XX",
            name:"test",
            serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"
        };
    let scanOptions: ble.ScanOptions = {
    interval: 500,
    dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
    matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE
    }
    ble.startBLEScan([scanFilter],scanOptions);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.stopBLEScan

stopBLEScan(): void

Stops BLE scanning.
- You can call [ble.startBLEScan](#blestartblescan) to stop the BLE scan.
- Call this API to stop the Bluetooth scan if device discovery is no longer needed.
- Scan results will not be reported after this API is called. You need to start a Bluetooth scan again for device discovery.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    ble.stopBLEScan();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.startAdvertising

startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void

Starts sending BLE advertising packets.
- Call [ble.stopAdvertising](#blestopadvertising) if the application no longer needs to send BLE advertising packets.
- This API works in synchronous mode. It cannot be used with [ble.stopAdvertising](#blestopadvertising11) of API version 11.


**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type                                   | Mandatory  | Description            |
| ----------- | ------------------------------------- | ---- | -------------- |
| setting     | [AdvertiseSetting](#advertisesetting) | Yes   | Settings related to BLE advertising.   |
| advData     | [AdvertiseData](#advertisedata)       | Yes   | BLE advertising data.  |
| advResponse | [AdvertiseData](#advertisedata)       | No   | BLE advertising response.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900010 | The number of advertising resources reaches the upper limit.       |
|2900099 | Operation failed.                        |
|2902054 | The length of the advertising data exceeds the upper limit.        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    ble.startAdvertising(setting, advData ,advResponse);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.stopAdvertising

stopAdvertising(): void

Stops sending BLE advertising packets.
- This API works for BLE advertising initiated by [ble.startAdvertising](#blestartadvertising).
- This API cannot be used with [ble.startAdvertising](#blestartadvertising11) of API version 11.
- Call this API if the application no longer needs to send BLE advertising packets.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    ble.stopAdvertising();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.startAdvertising<sup>11+</sup>

startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback&lt;number&gt;): void

Starts sending BLE advertising packets for the first time. This API uses an asynchronous callback to return the result.
- After this API is called, the Bluetooth subsystem allocates related resources and returns the advertising ID using an asynchronous callback.
- If the advertising duration is specified, advertising will stop after the duration elapses, but the allocated advertising resources will remain. You can call [ble.enableAdvertising](#bleenableadvertising11) to enable advertising again.
- Since API version 15, you can call this API multiple times to establish multiple advertising channels, each being identified by a unique ID.
- Call [ble.stopAdvertising](#blestopadvertising11) (supported since API version 11) if advertising is no longer needed. Do not use this API with [ble.stopAdvertising](#blestopadvertising) (supported since API version 10).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name              | Type                                   | Mandatory | Description                            |
| ------------------- | --------------------------------------- | ----- | ------------------------------- |
| advertisingParams   | [AdvertisingParams](#advertisingparams11) | Yes   | Parameters for starting BLE advertising.          |
| callback            | AsyncCallback&lt;number&gt;             | Yes   | Callback used to return the advertisement ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900010 | The number of advertising resources reaches the upper limit.       |
|2900099 | Operation failed.                        |
|2902054 | The length of the advertising data exceeds the upper limit.        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true,
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
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
```


## ble.startAdvertising<sup>11+</sup>

startAdvertising(advertisingParams: AdvertisingParams): Promise&lt;number&gt;

Starts sending BLE advertising packets for the first time. This API uses a promise to return the result.
- After this API is called, the Bluetooth subsystem allocates related resources and returns the advertising ID using a promise.
- If the advertising duration is specified, advertising will stop after the duration elapses, but the allocated advertising resources will remain. You can call [ble.enableAdvertising](#bleenableadvertising11) to enable advertising again.
- Since API version 15, you can call this API multiple times to establish multiple advertising channels, each being identified by a unique ID.
- Call [ble.stopAdvertising](#blestopadvertising11-1) (supported since API version 11) if advertising is no longer needed. Do not use this API with [ble.stopAdvertising](#blestopadvertising) (supported since API version 10).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name              | Type                                  | Mandatory | Description                   |
| ------------------- | -------------------------------------- | ----- | ----------------------- |
| advertisingParams   | [AdvertisingParams](#advertisingparams11) | Yes   | Parameters for starting BLE advertising. |

**Return value**

| Type                      | Description                           |
| -------------------------- | ------------------------------- |
| Promise&lt;number&gt;      | Promise used to return the BLE advertisement ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900010 | The number of advertising resources reaches the upper limit.       |
|2900099 | Operation failed.                        |
|2902054 | The length of the advertising data exceeds the upper limit.        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams)
        .then(outAdvHandle => {
            advHandle = outAdvHandle;
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.enableAdvertising<sup>11+</sup>

enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback&lt;void&gt;): void

Enables BLE advertising based on the specified **advertisingId**. This API uses an asynchronous callback to return the result.
- The advertising resource corresponding to **advertisingId** in [AdvertisingEnableParams](#advertisingenableparams11) has been allocated when [ble.startAdvertising](#blestartadvertising11) is called to start BLE for the first time.
- If the advertising duration is specified in [ble.startAdvertising](#blestartadvertising11), advertising will stop after the duration elapses. You can call this API to enable advertising again.
- If advertising is disabled by calling [ble.disableAdvertising](#bledisableadvertising11), you can call this API to enable advertising again.
- You can obtain the operation result through the callback of [ble.on('advertisingStateChange')](#bleonadvertisingstatechange11).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                   | Type                                                | Mandatory | Description                            |
| ------------------------- | --------------------------------------------------- | ----- | ------------------------------- |
| advertisingEnableParams   | [AdvertisingEnableParams](#advertisingenableparams11) | Yes   | Parameters for temporarily enabling BLE advertising.       |
| callback                  | AsyncCallback&lt;void&gt;                           | Yes   | Callback used to return the result.                       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                     |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 300
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingEnableParams: ble.AdvertisingEnableParams = {
        advertisingId: advHandle,
        duration: 0
    }

    // after 3s, advertising disabled, then enable the advertising
    ble.enableAdvertising(advertisingEnableParams, (err) => {
        if (err) {
            return;
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.enableAdvertising<sup>11+</sup>

enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise&lt;void&gt;

Enables BLE advertising based on the specified **advertisingId**. This API uses a promise to return the result.
- The advertising resource corresponding to **advertisingId** in [AdvertisingEnableParams](#advertisingenableparams11) has been allocated when [ble.startAdvertising](#blestartadvertising11) is called to start BLE for the first time.
- If the advertising duration is specified in [ble.startAdvertising](#blestartadvertising11), advertising will stop after the duration elapses. You can call this API to enable advertising again.
- If advertising is disabled by calling [ble.disableAdvertising](#bledisableadvertising11), you can call this API to enable advertising again.
- You can obtain the operation result through the callback of [ble.on('advertisingStateChange')](#bleonadvertisingstatechange11).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                   | Type                                                | Mandatory | Description                            |
| ------------------------- | --------------------------------------------------- | ----- | ------------------------------- |
| advertisingEnableParams   | [AdvertisingEnableParams](#advertisingenableparams11) | Yes   | Parameters for temporarily enabling BLE advertising.       |

**Return value**

| Type                      | Description         |
| -------------------------- | ------------ |
| Promise&lt;void&gt;      | Promise used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                   |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 300
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingEnableParams: ble.AdvertisingEnableParams = {
        advertisingId: advHandle,
        duration: 0
    }

    // after 3s, advertising disabled, then enable the advertising
    ble.enableAdvertising(advertisingEnableParams)
        .then(() => {
            console.info("enable success");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.disableAdvertising<sup>11+</sup>

disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback&lt;void&gt;): void

Disables BLE advertising based on the specified **advertisingId**. This API uses an asynchronous callback to return the result.
- After this API is called, advertising will stop, but the allocated advertising resources will remain. You can call [ble.enableAdvertising](#bleenableadvertising11) to enable advertising again.
- The advertising resource corresponding to **advertisingId** in [AdvertisingDisableParams](#advertisingdisableparams11) has been allocated when [ble.startAdvertising](#blestartadvertising11) is called to start BLE for the first time.
- You can obtain the operation result through the callback of [ble.on('advertisingStateChange')](#bleonadvertisingstatechange11).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                   | Type                                                  | Mandatory | Description                            |
| ------------------------- | ----------------------------------------------------- | ----- | ------------------------------- |
| advertisingDisableParams  | [AdvertisingDisableParams](#advertisingdisableparams11) | Yes   | Parameters for temporarily disabling BLE advertising.       |
| callback                  | AsyncCallback&lt;void&gt;                             | Yes   | Callback used to return the result.                       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                     |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingDisableParams: ble.AdvertisingDisableParams = {
        advertisingId: advHandle
    }
    ble.disableAdvertising(advertisingDisableParams, (err) => {
        if (err) {
            return;
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.disableAdvertising<sup>11+</sup>

disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise&lt;void&gt;

Disables BLE advertising based on the specified **advertisingId**. This API uses a promise to return the result.
- After this API is called, advertising will stop, but the allocated advertising resources will remain. You can call [ble.enableAdvertising](#bleenableadvertising11) to enable advertising again.
- The advertising resource corresponding to **advertisingId** in [AdvertisingDisableParams](#advertisingdisableparams11) has been allocated when [ble.startAdvertising](#blestartadvertising11) is called to start BLE for the first time.
- You can obtain the operation result through the callback of [ble.on('advertisingStateChange')](#bleonadvertisingstatechange11).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                   | Type                                                  | Mandatory | Description                            |
| ------------------------- | ----------------------------------------------------- | ----- | ------------------------------- |
| advertisingDisableParams  | [AdvertisingDisableParams](#advertisingdisableparams11) | Yes   | Parameters for temporarily disabling BLE advertising.       |

**Return value**

| Type                      | Description         |
| -------------------------- | ------------ |
| Promise&lt;void&gt;        | Promise used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| ------- | -------------------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                  |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    let advertisingDisableParams: ble.AdvertisingDisableParams = {
        advertisingId: advHandle
    }
    ble.disableAdvertising(advertisingDisableParams)
        .then(() => {
            console.info("enable success");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ble.stopAdvertising<sup>11+</sup>

stopAdvertising(advertisingId: number, callback: AsyncCallback&lt;void&gt;): void

Stops sending BLE advertising packets. This API uses an asynchronous callback to return the result.
- If this API is used with [ble.startAdvertising](#blestartadvertising11) (supported since API version 11), the requested advertising resources will be released.
- The **advertisingId** allocated when [ble.startAdvertising](#blestartadvertising11) is called to start advertising for the first time will also become invalid.
- This API cannot be used with [ble.startAdvertising](#blestartadvertising) (supported since API version 10).
- You can obtain the operation result through the callback of [ble.on('advertisingStateChange')](#bleonadvertisingstatechange11).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                   | Type                         | Mandatory | Description                        |
| ------------------------- | ---------------------------- | ----- | --------------------------- |
| advertisingId             | number                       | Yes   | ID of the advertisement to stop.       |
| callback                  | AsyncCallback&lt;void&gt;    | Yes   | Callback used to return the result.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                  |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    ble.stopAdvertising(advHandle, (err) => {
        if (err) {
            return;
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.stopAdvertising<sup>11+</sup>

stopAdvertising(advertisingId: number): Promise&lt;void&gt;

Stops sending BLE advertising packets. This API uses a promise to return the result.
- If this API is used with [ble.startAdvertising](#blestartadvertising11) (supported since API version 11), the requested advertising resources will be released.
- The **advertisingId** allocated when [ble.startAdvertising](#blestartadvertising11) is called to start advertising for the first time will also become invalid.
- This API cannot be used with [ble.startAdvertising](#blestartadvertising) (supported since API version 10).
- You can obtain the operation result through the callback of [ble.on('advertisingStateChange')](#bleonadvertisingstatechange11).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                   | Type                         | Mandatory | Description                        |
| ------------------------- | ---------------------------- | ----- | --------------------------- |
| advertisingId             | number                       | Yes   | ID of the advertisement to stop.       |

**Return value**

| Type                      | Description         |
| -------------------------- | ------------ |
| Promise&lt;void&gt;        | Promise used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                 |
|801     | Capability not supported.                |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |
|2902055 | Invalid advertising id.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
try {
    let setting: ble.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true
    };
    let manufactureDataUnit: ble.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: ble.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advResponse: ble.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit]
    };
    let advertisingParams: ble.AdvertisingParams = {
        advertisingSettings: setting,
        advertisingData: advData,
        advertisingResponse: advResponse,
        duration: 0
    }
    let advHandle = 0xFF;
    ble.startAdvertising(advertisingParams, (err, outAdvHandle) => {
        if (err) {
            return;
        } else {
            advHandle = outAdvHandle;
            console.info("advHandle: " + advHandle);
        }
    });

    ble.stopAdvertising(advHandle)
        .then(() => {
            console.info("enable success");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.on('advertisingStateChange')<sup>11+</sup>

on(type: 'advertisingStateChange', callback: Callback&lt;AdvertisingStateChangeInfo&gt;): void

Subscribes to BLE advertising status. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                                                   | Mandatory  | Description                                                     |
| -------- | ------------------------------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                                                    | Yes   | Event type. The value **advertisingStateChange** indicates an advertising state change event.<br>This event is triggered if the advertising state changes when [ble.startAdvertising](#blestartadvertising11), [ble.stopAdvertising](#blestopadvertising11), [ble.enableAdvertising](#bleenableadvertising11) or [ble.disableAdvertising](#bledisableadvertising11) is called.    |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo11)&gt; | Yes   | Callback used to return the advertising state change event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: ble.AdvertisingStateChangeInfo) {
    console.info('bluetooth advertising state = ' + JSON.stringify(data));
}
try {
    ble.on('advertisingStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.off('advertisingStateChange')<sup>11+</sup>

off(type: 'advertisingStateChange', callback?: Callback&lt;AdvertisingStateChangeInfo&gt;): void

Unsubscribes from BLE advertising status. No BLE advertising state change events will be received when BLE advertising is stopped or started.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                                                   | Mandatory  | Description                                                     |
| -------- | ------------------------------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                                                    | Yes   | Event type. The value **advertisingStateChange** indicates an advertising state change event.       |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo11)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [ble.on('advertisingStateChange')](#bleonadvertisingstatechange11). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|401     | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                       |
|801     | Capability not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: ble.AdvertisingStateChangeInfo) {
    console.info('bluetooth advertising state = ' + JSON.stringify(data));
}
try {
    ble.on('advertisingStateChange', onReceiveEvent);
    ble.off('advertisingStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.on('BLEDeviceFind')

on(type: 'BLEDeviceFind', callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Subscribes to BLE scan result reporting events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates a scan result reporting event.<br>This event is triggered if a BLE device is discovered when [ble.startBLEScan](#blestartblescan) is called.|
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | Yes   | Callback used to return the set of scan results.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<ble.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    ble.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## ble.off('BLEDeviceFind')

off(type: 'BLEDeviceFind', callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Unsubscribes from BLE scan result reporting events.
- After [ble.stopBLEScan](#blestopblescan) is called to stop the BLE scan, call this API to unsubscribe from scan result reporting events if device discovery is no longer needed.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates a scan result reporting event.       |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [ble.on('BLEDeviceFind')](#bleonbledevicefind). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).


| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: Array<ble.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    ble.on('BLEDeviceFind', onReceiveEvent);
    ble.off('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## GattServer

Represents a GATT server.
- You can use [ble.createGattServer](#blecreategattserver) to create a server instance.
- You can use this instance to operate the server, for example, call [addService](#addservice) to add a server and use [notifyCharacteristicChanged](#notifycharacteristicchanged) report characteristic changes.


### addService

addService(service: GattService): void

Adds a service to this GATT server. This operation registers the service with the Bluetooth subsystem to indicate the capabilities supported by the server.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                         | Mandatory  | Description                      |
| ------- | --------------------------- | ---- | ------------------------ |
| service | [GattService](#gattservice) | Yes   | Service data, which indicates the functions supported by the server.<br>For example, **00001800-0000-1000-8000-00805f9b34fb** indicates the general access service, and **00001801-0000-1000-8000-00805f9b34fb** indicates the general characteristic service.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// Create characteristics.
let characteristics: Array<ble.BLECharacteristic> = [];
let arrayBufferC = new ArrayBuffer(8);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
characteristics[0] = characteristic;

// Create a gattService instance.
let gattService: ble.GattService = {serviceUuid:'00001810-0000-1000-8000-00805F9B34FB', isPrimary: true, characteristics:characteristics, includeServices:[]};

try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.addService(gattService);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### removeService

removeService(serviceUuid: string): void

Deletes a service added to the server.
- The service has been added by calling [addService](#addservice).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type    | Mandatory  | Description                                      |
| ----------- | ------ | ---- | ---------------------------------------- |
| serviceUuid | string | Yes   | UUID of the service to be deleted, for example, 00001810-0000-1000-8000-00805F9B34FB.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let server: ble.GattServer = ble.createGattServer();
try {
    // Before removeService is called, the server and the client must be paired and connected.
    server.removeService('00001810-0000-1000-8000-00805F9B34FB');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### close

close(): void

Closes the server instance. The instance created by calling [ble.createGattServer](#blecreategattserver) is unavailable after being closed.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let server: ble.GattServer = ble.createGattServer();
try {
    server.close();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### notifyCharacteristicChanged

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic, callback: AsyncCallback&lt;void&gt;): void

Sends a characteristic change notification or indication from the server to the client. This API uses an asynchronous callback to return the result.

- You are advised to enable the notification or indication function for the Client Characteristic Configuration descriptor (UUID: 00002902-0000-1000-8000-00805f9b34fb) of the characteristic.
- According to the Bluetooth protocol, the data length of the Client Characteristic Configuration descriptor is 2 bytes. Bit 0 and bit 1 indicate whether notification and indication are enabled, respectively. For example, **bit 0 = 1** indicates that notification is enabled.
- This API is called when the properties of a GATT characteristic change.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                                     |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | Yes   | Client address, for example, XX:XX:XX:XX:XX:XX.|
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | Yes   | Characteristic object.                              |
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferC = new ArrayBuffer(8);
let notifyCharacter: ble.NotifyCharacteristic = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: arrayBufferC,
    confirm: true
};
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacter, (err: BusinessError) => {
        if (err) {
            console.error('notifyCharacteristicChanged callback failed');
        } else {
            console.info('notifyCharacteristicChanged callback successful');
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### notifyCharacteristicChanged

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): Promise&lt;void&gt;

Sends a characteristic change event from the server to the client. This API uses a promise to return the result.

- You are advised to enable notification or indication for the Client Characteristic Configuration descriptor of the characteristic.
- According to the Bluetooth protocol, the data length of the Client Characteristic Configuration descriptor is 2 bytes. Bit 0 and bit 1 indicate whether notification and indication are enabled, respectively. For example, **bit 0 = 1** indicates that notification is enabled.
- This API is called when the properties of a GATT characteristic change.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                                     |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | Yes   | Client address, for example, XX:XX:XX:XX:XX:XX.|
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | Yes   | Characteristic object.                              |

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferC = new ArrayBuffer(8);
let notifyCharacter: ble.NotifyCharacteristic = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: arrayBufferC,
    confirm: true
};
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacter).then(() => {
        console.info('notifyCharacteristicChanged promise successful');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### sendResponse

sendResponse(serverResponse: ServerResponse): void

Sends a response to a client request. This helps to prevent a connection from being disconnected due to a timeout.

A client request is received through the following APIs:

- [on('characteristicRead')](#oncharacteristicread)
- [on('characteristicWrite')](#oncharacteristicwrite) (Whether a response is needed is determined based on **needRsp** in [CharacteristicWriteRequest](#characteristicwriterequest)).
- [on('descriptorRead')](#ondescriptorread)
- [on('descriptorWrite')](#ondescriptorwrite) (Whether a response is needed is determined by **needRsp** in [DescriptorWriteRequest](#descriptorwriterequest)).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                               | Mandatory  | Description             |
| -------------- | --------------------------------- | ---- | --------------- |
| serverResponse | [ServerResponse](#serverresponse) | Yes   | Response returned by the GATT server.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
/* send response */
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1;
let serverResponse: ble.ServerResponse = {
    deviceId: 'XX:XX:XX:XX:XX:XX',
    transId: 0,
    status: 0,
    offset: 0,
    value: arrayBufferCCC
};
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.sendResponse(serverResponse);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### on('characteristicRead')

on(type: 'characteristicRead', callback: Callback&lt;CharacteristicReadRequest&gt;): void

Subscribes to characteristic read request events of the client. After receiving the event, the server needs to call [sendResponse](#sendresponse) to send a response to the client. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicRead** indicates a characteristic read request event.<br>This event is triggered when the server receives a characteristic read request from the client.|
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequest)&gt; | Yes   | Callback used to return the read request event.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1;
let gattServer: ble.GattServer = ble.createGattServer();
function ReadCharacteristicReq(characteristicReadRequest: ble.CharacteristicReadRequest) {
    let deviceId: string = characteristicReadRequest.deviceId;
    let transId: number = characteristicReadRequest.transId;
    let offset: number = characteristicReadRequest.offset;
    let characteristicUuid: string = characteristicReadRequest.characteristicUuid;

    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('characteristicRead', ReadCharacteristicReq);
```


### off('characteristicRead')

off(type: 'characteristicRead', callback?: Callback&lt;CharacteristicReadRequest&gt;): void

Unsubscribes from characteristic read request events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicRead** indicates a characteristic read request event.   |
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequest)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('characteristicRead')](#oncharacteristicread). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('characteristicRead');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('characteristicWrite')

on(type: 'characteristicWrite', callback: Callback&lt;CharacteristicWriteRequest&gt;): void

Subscribes to characteristic write request events of the client. After receiving such an event, the server determines whether to call [sendResponse](#sendresponse) to send a response to the client based on the **needRsp** in [CharacteristicWriteRequest](#characteristicwriterequest).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicWrite** indicates a characteristic write request event.<br>This event is triggered when the server receives a characteristic write request from the client.|
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequest)&gt; | Yes   | Callback used to return the write request event.            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
let gattServer: ble.GattServer = ble.createGattServer();
function WriteCharacteristicReq(characteristicWriteRequest: ble.CharacteristicWriteRequest) {
    let deviceId: string = characteristicWriteRequest.deviceId;
    let transId: number = characteristicWriteRequest.transId;
    let offset: number = characteristicWriteRequest.offset;
    let isPrepared: boolean = characteristicWriteRequest.isPrepared;
    let needRsp: boolean = characteristicWriteRequest.needRsp;
    let value: Uint8Array =  new Uint8Array(characteristicWriteRequest.value);
    let characteristicUuid: string = characteristicWriteRequest.characteristicUuid;

    cccValue[0] = value[0];
    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('characteristicWrite', WriteCharacteristicReq);
```


### off('characteristicWrite')

off(type: 'characteristicWrite', callback?: Callback&lt;CharacteristicWriteRequest&gt;): void

Unsubscribes from characteristic write request events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicWrite** indicates a characteristic write request event.  |
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequest)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('characteristicWrite')](#oncharacteristicwrite). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('characteristicWrite');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('descriptorRead')

on(type: 'descriptorRead', callback: Callback&lt;DescriptorReadRequest&gt;): void

Subscribes to descriptor read request events of the client. After receiving the event, the server needs to call [sendResponse](#sendresponse) to send a response to the client.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                               |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorRead** indicates a descriptor read request event.<br>This event is triggered when the server receives a descriptor read request from the client.|
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequest)&gt; | Yes   | Callback used to return the read request event.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
descValue[0] = 1;
let gattServer: ble.GattServer = ble.createGattServer();
function ReadDescriptorReq(descriptorReadRequest: ble.DescriptorReadRequest) {
    let deviceId: string = descriptorReadRequest.deviceId;
    let transId: number = descriptorReadRequest.transId;
    let offset: number = descriptorReadRequest.offset;
    let descriptorUuid: string = descriptorReadRequest.descriptorUuid;

    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('descriptorRead', ReadDescriptorReq);
```


### off('descriptorRead')

off(type: 'descriptorRead', callback?: Callback&lt;DescriptorReadRequest&gt;): void

Unsubscribes from descriptor read request events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorRead** indicates a descriptor read request event.       |
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequest)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('descriptorRead')](#ondescriptorread). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('descriptorRead');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('descriptorWrite')

on(type: 'descriptorWrite', callback: Callback&lt;DescriptorWriteRequest&gt;): void

Subscribes to descriptor write request events of the client. After receiving such an event, the server determines whether to call [sendResponse](#sendresponse) to send a response to the client based on the **needRsp** in [DescriptorWriteRequest](#descriptorwriterequest).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorWrite** indicates a descriptor write request event.<br>This event is triggered when the server receives a descriptor write request from the client.|
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequest)&gt; | Yes   | Callback used to return the write request event.        |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
let gattServer: ble.GattServer = ble.createGattServer();
function WriteDescriptorReq(descriptorWriteRequest: ble.DescriptorWriteRequest) {
    let deviceId: string = descriptorWriteRequest.deviceId;
    let transId: number = descriptorWriteRequest.transId;
    let offset: number = descriptorWriteRequest.offset;
    let isPrepared: boolean = descriptorWriteRequest.isPrepared;
    let needRsp: boolean = descriptorWriteRequest.needRsp;
    let value: Uint8Array = new Uint8Array(descriptorWriteRequest.value);
    let descriptorUuid: string = descriptorWriteRequest.descriptorUuid;

    descValue[0] = value[0];
    let serverResponse: ble.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}
gattServer.on('descriptorWrite', WriteDescriptorReq);
```


### off('descriptorWrite')

off(type: 'descriptorWrite', callback?: Callback&lt;DescriptorWriteRequest&gt;): void

Unsubscribes from descriptor write request events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorWrite** indicates a descriptor write request event.      |
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequest)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('descriptorWrite')](#ondescriptorwrite). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
let gattServer: ble.GattServer = ble.createGattServer();
gattServer.off('descriptorWrite');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('connectionStateChange')

on(type: 'connectionStateChange', callback: Callback&lt;BLEConnectionChangeState&gt;): void

Subscribes to GATT connection state change events on the server. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates a connection state change event.<br>This event is triggered when the GATT connection state changes.<br>For example, the connection status may change when a connection request or disconnection request is received.|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | Yes   | Callback used to return the GATT connection state change event.                         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let Connected = (bleConnectionChangeState: ble.BLEConnectionChangeState) => {
    let deviceId: string = bleConnectionChangeState.deviceId;
    let status: constant.ProfileConnectionState = bleConnectionChangeState.state;
}
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.on('connectionStateChange', Connected);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('connectionStateChange')

off(type: 'connectionStateChange', callback?: Callback&lt;BLEConnectionChangeState&gt;): void

Unsubscribes from GATT connection state change events on the server.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates a connection state change event.|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('connectionStateChange')](#onconnectionstatechange). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('connectionStateChange');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('BLEMtuChange')

on(type: 'BLEMtuChange', callback: Callback&lt;number&gt;): void

Subscribes to MTU change events on the server. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEMtuChange** indicates an MTU change event.<br>This event is triggered when the client initiates an MTU negotiation request.|
| callback | Callback&lt;number&gt; | Yes   | Callback used to return the negotiated MTU, in bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.on('BLEMtuChange', (mtu: number) => {
    console.info('BLEMtuChange, mtu: ' + mtu);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLEMtuChange')

off(type: 'BLEMtuChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from MTU change events on the server.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEMtuChange** indicates an MTU change event.|
| callback | Callback&lt;number&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('BLEMtuChange')](#onblemtuchange). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattServer: ble.GattServer = ble.createGattServer();
    gattServer.off('BLEMtuChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## GattClientDevice

Represents a GATT client class. It provides APIs for connecting to and transmitting data with the server.

- Before using the APIs of this class, you need to call [createGattClientDevice](#blecreategattclientdevice) to construct a GATT client instance.
- You can create multiple instances of this class to manage multiple GATT connections.

### connect

connect(): void

Initiates a GATT connection to the server.

- The address of the peer device has been specified by the **deviceId** in [createGattClientDevice](#blecreategattclientdevice).
- The client can use [on('BLEConnectionStateChange')](#onbleconnectionstatechange) to subscribe to connection state change events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect

disconnect(): void

Disconnects the GATT connection from the server.

- The client can use [on('BLEConnectionStateChange')](#onbleconnectionstatechange) to subscribe to connection state change events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.disconnect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### close

close(): void

Closes a client instance. The instance created by calling [GattClientDevice](#gattclientdevice) is unavailable after being closed.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.close();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getDeviceName

getDeviceName(callback: AsyncCallback&lt;string&gt;): void

Obtains the device name of the server. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**, and **data** is the device name of the server.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let gattClient: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        gattClient.getDeviceName((err: BusinessError, data: string)=> {
            console.info('device name err ' + JSON.stringify(err));
            console.info('device name' + JSON.stringify(data));
        })
    }
}
// callback
try {
    gattClient.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getDeviceName

getDeviceName(): Promise&lt;string&gt;

Obtains the name of the peer BLE device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description                                |
| --------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the device name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let gattClient: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
gattClient.on('BLEConnectionStateChange', ConnectStateChanged);
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        gattClient.getDeviceName().then((data: string) => {
            console.info('device name' + JSON.stringify(data));
        })
    }
}
// promise
try {
    gattClient.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getServices

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

Obtains the list of services supported by the server. This API uses an asynchronous callback to return the result.

Before invoking characteristic or descriptor read and write APIs, call this API to obtain the services supported by the server and ensure that the services include the characteristics or descriptors to be operated. The related APIs include:

- [readCharacteristicValue](#readcharacteristicvalue)
- [readDescriptorValue](#readdescriptorvalue)
- [writeCharacteristicValue](#writecharacteristicvalue)
- [writeDescriptorValue](#writedescriptorvalue)
- [setCharacteristicChangeNotification](#setcharacteristicchangenotification)
- [setCharacteristicChangeIndication](#setcharacteristicchangeindication)

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**, and **data** is the list of services supported by the server.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.            |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Callback mode.
let getServices = (code: BusinessError, gattServices: Array<ble.GattService>) => {
    if (code && code.code != 0) {
        console.info('bluetooth code is ' + code.code);
        return;
    }
    let services: Array<ble.GattService> = gattServices;
    console.info('bluetooth services size is ', services.length);
    for (let i = 0; i < services.length; i++) {
        console.info('bluetooth serviceUuid is ' + services[i].serviceUuid);
    }
}
let device: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        device.getServices(getServices);
    }
}

try {
    device.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getServices

getServices(): Promise&lt;Array&lt;GattService&gt;&gt;

Obtains all services of the peer BLE device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                                      | Description                         |
| ---------------------------------------- | --------------------------- |
| Promise&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Promise used to return the list of services supported by the server.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { ble, constant } from '@kit.ConnectivityKit';
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Promise mode.
let device: ble.GattClientDevice = ble.createGattClientDevice("11:22:33:44:55:66");
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
    if (connectState == constant.ProfileConnectionState.STATE_CONNECTED) {
        device.getServices().then((result: Array<ble.GattService>) => {
            console.info('getServices successfully:' + JSON.stringify(result));
        });
    }
}
try {
    device.connect();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readCharacteristicValue

readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void

Reads the value of the specified characteristic. This API uses an asynchronous callback to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included. Otherwise, the read operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                      | Mandatory  | Description                     |
| -------------- | ---------------------------------------- | ---- | ----------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic)  | Yes   | Characteristic to read.               |
| callback       | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**, and **data** is the characteristic object containing the read data. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function readCcc(code: BusinessError, BLECharacteristic: ble.BLECharacteristic) {
  if (code.code != 0) {
      return;
  }
  console.info('bluetooth characteristic uuid: ' + BLECharacteristic.characteristicUuid);
  let value = new Uint8Array(BLECharacteristic.characteristicValue);
  console.info('bluetooth characteristic value: ' + value[0]);
}

let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readCharacteristicValue(characteristic, readCcc);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readCharacteristicValue

readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;

Reads the value of the specified characteristic. This API uses a promise to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included. Otherwise, the read operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description      |
| -------------- | --------------------------------------- | ---- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic to read.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLECharacteristic](#blecharacteristic)&gt; | Promise used to return the characteristic object containing the read data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readCharacteristicValue(characteristic);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readDescriptorValue

readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void

Reads data from the specified descriptor. This API uses an asynchronous callback to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified descriptor is included. Otherwise, the read operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description                     |
| ---------- | ---------------------------------------- | ---- | ----------------------- |
| descriptor | [BLEDescriptor](#bledescriptor)          | Yes   | Descriptor to read.               |
| callback   | AsyncCallback&lt;[BLEDescriptor](#bledescriptor)&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**, and **data** is the descriptor object containing the read data. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function readDesc(code: BusinessError, BLEDescriptor: ble.BLEDescriptor) {
    if (code.code != 0) {
        return;
    }
    console.info('bluetooth descriptor uuid: ' + BLEDescriptor.descriptorUuid);
    let value = new Uint8Array(BLEDescriptor.descriptorValue);
    console.info('bluetooth descriptor value: ' + value[0]);
}

let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readDescriptorValue(descriptor, readDesc);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readDescriptorValue

readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;

Reads data from the specified descriptor. This API uses a promise to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified descriptor is included. Otherwise, the read operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description      |
| ---------- | ------------------------------- | ---- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes   | Descriptor to read.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLEDescriptor](#bledescriptor)&gt; | Promise used to return the descriptor object containing the read data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901000 | Read forbidden.                         |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readDescriptorValue(descriptor);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeCharacteristicValue

writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType, callback: AsyncCallback&lt;void&gt;): void

Writes a value to the specified characteristic. This API uses an asynchronous callback to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included. Otherwise, the write operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                 |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic to write.|
| writeType | [GattWriteType](#gattwritetype) | Yes   | Write mode.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the write operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC, descriptors:descriptors};
function writeCharacteristicValueCallBack(code: BusinessError) {
    if (code != null) {
        return;
    }
    console.info('bluetooth writeCharacteristicValue success');
}
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE, writeCharacteristicValueCallBack);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeCharacteristicValue

writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType): Promise&lt;void&gt;

Writes a value to the specified characteristic. This API uses a promise to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included. Otherwise, the write operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                 |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic to write.|
| writeType | [GattWriteType](#gattwritetype) | Yes   | Write mode.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor>  = [];
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC, descriptors:descriptors};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeCharacteristicValue(characteristic, ble.GattWriteType.WRITE);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeDescriptorValue

writeDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;void&gt;): void

Writes data to the specified descriptor. This API uses an asynchronous callback to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified descriptor is included. Otherwise, the write operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description                |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes   | Descriptor to write.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the write operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeDescriptorValue(descriptor, (err: BusinessError) => {
        if (err) {
            console.error('writeDescriptorValue callback failed');
        } else {
            console.info('writeDescriptorValue callback successful');
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeDescriptorValue

writeDescriptorValue(descriptor: BLEDescriptor): Promise&lt;void&gt;

Writes data to the specified descriptor. This API uses a promise to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified descriptor is included. Otherwise, the write operation will fail.<br>
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description                |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes   | Descriptor to write.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901001 | Write forbidden.                        |
|2901003 | The connection is not established.                |
|2901004 | The connection is congested.                |
|2901005 | The connection is not encrypted.                |
|2901006 | The connection is not authenticated.                |
|2901007 | The connection is not authorized.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(2);
let descV = new Uint8Array(bufferDesc);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeDescriptorValue(descriptor).then(() => {
        console.info('writeDescriptorValue promise success');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getRssiValue

getRssiValue(callback: AsyncCallback&lt;number&gt;): void

Obtains the RSSI of a GATT connection. This API uses an asynchronous callback to return the result.<br>
- You can call this API only after the GATT profile is connected by calling [connect](#connect).
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**, and **data** is the obtained RSSI (unit: dBm). Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.         |
|801 | Capability not supported.          |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// callback
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.connect();
    let rssi = gattClient.getRssiValue((err: BusinessError, data: number)=> {
        console.info('rssi err ' + JSON.stringify(err));
        console.info('rssi value' + JSON.stringify(data));
    })
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getRssiValue

getRssiValue(): Promise&lt;number&gt;

Obtains the RSSI of a GATT connection. This API uses a promise to return the result.<br>
- You can call this API only after the GATT profile is connected by calling [connect](#connect).
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description                               |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. used to return the signal strength, in dBm.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.               |
|801 | Capability not supported.          |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.getRssiValue().then((data: number) => {
        console.info('rssi' + JSON.stringify(data));
    })
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### setBLEMtuSize

setBLEMtuSize(mtu: number): void

Negotiates the MTU between the client and server.<br>
- You can call this API only after the GATT profile is connected by calling [connect](#connect).<br>
- You can call [on('BLEMtuChange')](#onblemtuchange-1) to subscribe to the MTU negotiation result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| mtu  | number | Yes   | MTU to negotiate. The value range is [23, 517], in bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.setBLEMtuSize(128);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### setCharacteristicChangeNotification

setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the client to receive characteristic change notifications from the server. This API uses an asynchronous callback to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included.<br>
- The server can send change notifications only if the specified characteristic contains the UUID (00002902-0000-1000-8000-00805f9b34fb) of the Client Characteristic Configuration descriptor.<br>
- If **enable** is set to **true**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to enable the change notification function.<br>
- If **enable** is set to **false**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to disable the change notification function.<br>
- You can call [on('BLECharacteristicChange')](#onblecharacteristicchange) to subscribe to characteristic change notifications of the server.<br>
- The client does not need to send a response when receiving a characteristic change notification from the server.
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic of the server.                     |
| enable         | boolean                                 | Yes   | Whether to enable characteristic change notification.<br>The value **true** means to enable the application, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.setCharacteristicChangeNotification(characteristic, false, (err: BusinessError) => {
        if (err) {
            console.error('notifyCharacteristicChanged callback failed');
        } else {
            console.info('notifyCharacteristicChanged callback successful');
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


### setCharacteristicChangeNotification

setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;

Sets whether to enable the client to receive characteristic change notifications from the server. This API uses a promise to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included.<br>
- The server can send change notifications only if the specified characteristic contains the UUID (00002902-0000-1000-8000-00805f9b34fb) of the Client Characteristic Configuration descriptor.<br>
- If **enable** is set to **true**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to enable the change notification function.<br>
- If **enable** is set to **false**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to disable the change notification function.<br>
- You can call [on('BLECharacteristicChange')](#onblecharacteristicchange) to subscribe to characteristic change notifications of the server.<br>
- The client does not need to send a response when receiving a characteristic change notification from the server.
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic of the server.                     |
| enable         | boolean                                 | Yes   | Whether to enable characteristic change notification.<br>**true** to enable, **false** otherwise.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
  let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
  device.setCharacteristicChangeNotification(characteristic, false);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


### setCharacteristicChangeIndication

setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the client to receive characteristic change indications from the server. This API uses an asynchronous callback to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included.<br>
- The server can send change indications only if the specified characteristic contains the UUID (00002902-0000-1000-8000-00805f9b34fb) of the Client Characteristic Configuration descriptor.<br>
- If **enable** is set to **true**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to enable the change indication function.<br>
- If **enable** is set to **false**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to disable the change indication function.<br>
- You can call [on('BLECharacteristicChange')](#onblecharacteristicchange) to subscribe to characteristic change indications of the server.<br>
- When receiving a characteristic change indication from the server, the client does not need to send a response as this will be done by the Bluetooth service.
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic of the server.                     |
| enable         | boolean                                 | Yes   | Whether to enable characteristic change indication.<br>The value **true** means to enable the application, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
  let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
  device.setCharacteristicChangeIndication(characteristic, false, (err: BusinessError) => {
    if (err) {
      console.error('notifyCharacteristicChanged callback failed');
    } else {
      console.info('notifyCharacteristicChanged callback successful');
    }
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


### setCharacteristicChangeIndication

setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;

Sets whether to enable the client to receive characteristic change indications from the server. This API uses an asynchronous callback to return the result.<br>
- You need to call [getServices](#getservices) to obtain all services supported by the server, and ensure that the UUID of the specified characteristic is included.<br>
- The server can send change indications only if the specified characteristic contains the UUID (00002902-0000-1000-8000-00805f9b34fb) of the Client Characteristic Configuration descriptor.<br>
- If **enable** is set to **true**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to enable the change indication function.<br>
- If **enable** is set to **false**, the system Bluetooth service automatically writes the Client Characteristic Configuration descriptor to the server to disable the change indication function.<br>
- You can call [on('BLECharacteristicChange')](#onblecharacteristicchange) to subscribe to characteristic change indications of the server.<br>
- When receiving a characteristic change indication from the server, the client does not need to send a response as this will be done by the Bluetooth service.
- You can call the following APIs only after receiving an asynchronous callback: [readCharacteristicValue](#readcharacteristicvalue), [readDescriptorValue](#readdescriptorvalue), [writeCharacteristicValue](#writecharacteristicvalue), [writeDescriptorValue](#writedescriptorvalue), [getRssiValue](#getrssivalue), [setCharacteristicChangeNotification](#setcharacteristicchangenotification), and [setCharacteristicChangeIndication](#setcharacteristicchangeindication).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic of the server.                     |
| enable         | boolean                                 | Yes   | Whether to enable characteristic change indication.<br>**true** to enable, **false** otherwise.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900011 | The operation is busy. The last operation is not complete.             |
|2900099 | Operation failed.                        |
|2901003 | The connection is not established.                |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(2);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 0; // Use the Client Characteristic Configuration descriptor as an example. When bit 0 and bit 1 are both set to 0, the notification and indication functions are disabled.
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: ble.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
try {
  let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
  device.setCharacteristicChangeIndication(characteristic, false);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

```


### on('BLECharacteristicChange')

on(type: 'BLECharacteristicChange', callback: Callback&lt;BLECharacteristic&gt;): void

Subscribes to the characteristic change events of the server. This API uses an asynchronous callback to return the result.<br>
-  You can receive characteristic change notifications or indications only after calling [setCharacteristicChangeNotification](#setcharacteristicchangenotification) or [setCharacteristicChangeIndication](#setcharacteristicchangeindication) to enable the notification or indication function.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLECharacteristicChange** indicates a characteristic change event.<br>This event is triggered when the client receives a characteristic change notification or indication from the server.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Callback used to return the updated characteristic.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function CharacteristicChange(characteristicChangeReq: ble.BLECharacteristic) {
    let serviceUuid: string = characteristicChangeReq.serviceUuid;
    let characteristicUuid: string = characteristicChangeReq.characteristicUuid;
    let value: Uint8Array = new Uint8Array(characteristicChangeReq.characteristicValue);
}
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.on('BLECharacteristicChange', CharacteristicChange);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLECharacteristicChange')

off(type: 'BLECharacteristicChange', callback?: Callback&lt;BLECharacteristic&gt;): void

Unsubscribes from the characteristic change events of the server.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLECharacteristicChange** indicates a characteristic change event.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('BLECharacteristicChange')](#onblecharacteristicchange). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLECharacteristicChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### on('BLEConnectionStateChange')

on(type: 'BLEConnectionStateChange', callback: Callback&lt;BLEConnectionChangeState&gt;): void

Subscribes to connection state change events of GATT profile on the client. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEConnectionStateChange** indicates a connection state change event.<br>This event is triggered when the GATT connection state changes.<br>For example, the connection status may change when the client calls [connect](#connect) or [disconnect](#disconnect).|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | Yes   | Callback used to return the GATT connection state change event.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function ConnectStateChanged(state: ble.BLEConnectionChangeState) {
    console.info('bluetooth connect state changed');
    let connectState: ble.ProfileConnectionState = state.state;
}
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.on('BLEConnectionStateChange', ConnectStateChanged);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLEConnectionStateChange')

off(type: 'BLEConnectionStateChange', callback?: Callback&lt;BLEConnectionChangeState&gt;): void

Unsubscribes from connection state change events of GATT profile on the client.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEConnectionStateChange** indicates a connection state change event.|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('BLEConnectionStateChange')](#onbleconnectionstatechange). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLEConnectionStateChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### on('BLEMtuChange')

on(type: 'BLEMtuChange', callback: Callback&lt;number&gt;): void

Subscribes to MTU change events on the client. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEMtuChange** indicates an MTU change event.<br>This event is triggered when the client initiates MTU negotiation by calling [setBLEMtuSize](#setblemtusize).|
| callback | Callback&lt;number&gt; | Yes   | Callback used to return the negotiated MTU, in bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    gattClient.on('BLEMtuChange', (mtu: number) => {
      console.info('BLEMtuChange, mtu: ' + mtu);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('BLEMtuChange')

off(type: 'BLEMtuChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from MTU change events on the client.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEMtuChange** indicates an MTU change event.|
| callback | Callback&lt;number&gt; | No   | Callback to unregister. If this parameter is specified, it must be the same as the callback in [on('BLEMtuChange')](#onblemtuchange-1). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLEMtuChange');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ble.createBleScanner<sup>15+</sup>

createBleScanner(): BleScanner

Creates a [BleScanner](#blescanner15) instance, which can be used to initiate or stop the BLE scan.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type| Description|
| ------------ | ------------- |
| [BleScanner](#blescanner15) | **BleScanner** instance.|

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
let bleScanner: ble.BleScanner = ble.createBleScanner();
console.info('create bleScanner success');
```

## BleScanner<sup>15+</sup>

Represents the BLE scanner class, which provides scan-related APIs.<br>
- Before using the APIs of this class, you need to call [createBleScanner](#blecreateblescanner15) to construct a BLE scanner instance.<br>
- You can create multiple instances of this class to manage multiple scan processes.

### startScan<sup>15+</sup>

startScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): Promise&lt;void&gt;

Starts BLE scanning. This API uses a promise to return the result.<br>
- This API can be used to scan only BLE devices.<br>
- You can obtain the scan result through the callback of [on('BLEDeviceFind')](#onbledevicefind15).<br>
- You can call [stopScan](#stopscan15) to stop the BLE scan.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | Yes   | Filter criteria for BLE advertising. Devices that meet the filter criteria will be reported.<br>If this parameter is set to **null**, all discoverable BLE devices nearby will be scanned. However, this method is not recommended as it may pick up unexpected devices and increase power consumption.|
| options | [ScanOptions](#scanoptions)            | No   | Defines the scan configuration parameters.                    |

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900009 | Fails to start scan as it is out of hardware resources.                 |
|2900099 | Operation failed.                        |
|2902050 | Failed to start scan as Ble scan is already started by the app.|

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
let bleScanner: ble.BleScanner = ble.createBleScanner();
function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('BLE scan device find result = '+ JSON.stringify(scanReport));
}
try {
    bleScanner.on("BLEDeviceFind", onReceiveEvent);
    let scanFilter: ble.ScanFilter = {
            deviceId:"XX:XX:XX:XX:XX:XX",
            name:"test",
            serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"
        };
    let scanOptions: ble.ScanOptions = {
        interval: 500,
        dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
        matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE,
        reportMode: ble.ScanReportMode.FENCE_SENSITIVITY_LOW
    }
    bleScanner.startScan([scanFilter],scanOptions);
    console.info('startScan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### stopScan<sup>15+</sup>

stopScan(): Promise&lt;void&gt;

Stops an ongoing BLE scan.<br>
- This API works for a scan initiated by calling [startScan](#startscan15).<br>
- Call this API to stop the Bluetooth scan if device discovery is no longer needed.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
let bleScanner: ble.BleScanner = ble.createBleScanner();
try {
    bleScanner.stopScan();
    console.info('stopScan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### on('BLEDeviceFind')<sup>15+</sup>

on(type: 'BLEDeviceFind', callback: Callback&lt;ScanReport&gt;): void

Subscribes to BLE scan result reporting events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates a scan result reporting event.<br>This event is triggered if a BLE device is discovered when [startScan](#startscan15) is called. |
| callback | Callback&lt;[ScanReport](#scanreport15)&gt; | Yes   | Callback used to return the set of scan results.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('bluetooth device find = '+ JSON.stringify(scanReport));
}
let bleScanner: ble.BleScanner = ble.createBleScanner();
try {
    bleScanner.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### off('BLEDeviceFind')<sup>15+</sup>

off(type: 'BLEDeviceFind', callback?: Callback&lt;ScanReport&gt;): void

Unsubscribes from BLE scan result reporting events.<br>
- After [stopScan](#stopscan15) is called to stop the BLE scan, call this API to unsubscribe from scan result reporting events if device discovery is no longer needed.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates a scan result reporting event.       |
| callback | Callback&lt;[ScanReport](#scanreport15)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [on('BLEDeviceFind')](#onbledevicefind15). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';
function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('bluetooth device find = '+ JSON.stringify(scanReport));
}
let bleScanner: ble.BleScanner = ble.createBleScanner();
try {
    bleScanner.on('BLEDeviceFind', onReceiveEvent);
    bleScanner.off('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## GattService

Defines the structure of GATT service, which can contain multiple [characteristics](#blecharacteristic) and other dependent services.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Read-Only| Optional  | Description                                      |
| --------------- | ---------------------------------------- |---- | ---- | ---------------------------------------- |
| serviceUuid     | string                                   | No| No   | UUID of the GATT service. for example, 00001888-0000-1000-8000-00805f9b34fb.|
| isPrimary       | boolean                                  | No| No   | Whether the service is a primary service. The value **true** indicates that the service is a primary service, and the value **false** indicates the opposite.               |
| characteristics | Array&lt;[BLECharacteristic](#blecharacteristic)&gt; | No| No   | Characteristics of the GATT service.                            |
| includeServices | Array&lt;[GattService](#gattservice)&gt; | No| Yes   | Services on which the service depends.                            |



## BLECharacteristic

Defines the structure of GATT characteristic, which is the core data unit of [GattService](#gattservice).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type                                    | Read-Only| Optional  | Description                                |
| ------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string                                   | No| No   | Service UUID of the characteristic. for example, 00001888-0000-1000-8000-00805f9b34fb.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| characteristicUuid  | string                  | No| No   | Characteristic UUID. for example, 00002a11-0000-1000-8000-00805f9b34fb.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| characteristicValue | ArrayBuffer                              | No| No   | Characteristic value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                     |
| descriptors         | Array&lt;[BLEDescriptor](#bledescriptor)&gt; | No| No   | Descriptors contained in the characteristic.<br>**Atomic service API**: This API can be used in atomic services since API version 12.               |
| properties  | [GattProperties](#gattproperties) | No| Yes    | Properties supported by the characteristic.<br>**Atomic service API**: This API can be used in atomic services since API version 12.    |
| characteristicValueHandle<sup>18+</sup> | number                           | No   | Yes   | Unique handle of the characteristic. It can be used to distinguish descriptors if the BLE device that serves as the server provides multiple descriptors with the same UUID.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                     |
| permissions<sup>20+</sup> | [GattPermissions](#gattpermissions20)   | No   | Yes   | Permissions required for characteristic read and write operations.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                 |


## BLEDescriptor

Defines the structure of GATT descriptor, which is the data unit of [BLECharacteristic](#blecharacteristic) and is used to describe the additional information and properties of the characteristic.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type       | Read-Only| Optional  | Description                                      |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid        | string      | No| No   | Service UUID of the characteristic. for example, 00001888-0000-1000-8000-00805f9b34fb.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| characteristicUuid | string      | No| No   | Characteristic UUID of the descriptor. for example, 00002a11-0000-1000-8000-00805f9b34fb.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| descriptorUuid     | string      | No| No   | Descriptor UUID. for example, 00002902-0000-1000-8000-00805f9b34fb.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| descriptorValue    | ArrayBuffer | No| No   | Descriptor value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                             |
| descriptorHandle<sup>18+</sup> | number        | No   | Yes   | Unique handle of the descriptor. It can be used to distinguish descriptors if the BLE device that serves as the server provides multiple descriptors with the same UUID.<br>**Atomic service API**: This API can be used in atomic services since API version 18.                     |
| permissions<sup>20+</sup> | [GattPermissions](#gattpermissions20)       | No   | Yes   | Permissions required for descriptor read and write operations.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                 |


## NotifyCharacteristic

Defines the structure of characteristic notification.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type       | Read-Only| Optional  | Description                                      |
| ------------------- | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string      | No| No   | Service UUID of the characteristic. for example, 00001888-0000-1000-8000-00805f9b34fb.|
| characteristicUuid  | string      | No| No   | Characteristic UUID. for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| characteristicValue | ArrayBuffer | No| No   | Characteristic value.                              |
| confirm             | boolean     | No| No   | Whether confirmation is required. The value **true** indicates that confirmation is required for an indication, and the value **false** indicates that confirmation is not required for a notification.|


## CharacteristicReadRequest

Defines the structure of characteristic read request sent from the client.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Read-Only| Optional  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | No| No   | Bluetooth device address of the client. for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | No| No   | Transaction identifier of the characteristic read request. It must be the same as the **transId** in the response returned by the server.      |
| offset             | number | No| No   | Read offset of the client. For example, **k** indicates that the read starts from the kth byte.<br>It must be the same as the **offset** in the response returned by the server.|
| characteristicUuid | string | No| No   | Characteristic UUID. for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string | No| No   | Service UUID of the characteristic. for example, 00001888-0000-1000-8000-00805f9b34fb.|


## CharacteristicWriteRequest

Defines the structure of characteristic write request sent from the client.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Read-Only| Optional  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | No| No   | Bluetooth device address of the client. for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | No| No   | Transaction identifier of the characteristic write request. It must be the same as the **transId** in the response returned by the server.      |
| offset             | number | No| No   | Write offset of the client. For example, **k** indicates that the write starts from the kth byte.<br>It must be the same as the **offset** in the response returned by the server.|
| isPrepared             | boolean | No| No   | Whether to respond immediately after receiving a write request from the client.<br>The value **true** means to respond at a later time, and the value **false** means to respond immediately.|
| needRsp             | boolean | No| No   | Whether to respond to the client.<br>The value **true** means to respond to the client, and the value **false** means to respond immediately.|
| value             | ArrayBuffer | No| No   | Characteristic value to write.|
| characteristicUuid | string | No| No   | Characteristic UUID. for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string | No| No   | Service UUID of the characteristic. for example, 00001888-0000-1000-8000-00805f9b34fb.|


## DescriptorReadRequest

Defines the structure of descriptor read request sent from the client.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Read-Only| Optional  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | No| No   | Bluetooth device address of the client. for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | No| No   | Transaction identifier of the characteristic read request. It must be the same as the **transId** in the response returned by the server.      |
| offset             | number | No| No   | Read offset of the client. For example, **k** indicates that the read starts from the kth byte.<br>It must be the same as the **offset** in the response returned by the server.|
| descriptorUuid     | string | No| No   | Descriptor UUID. for example, 00002902-0000-1000-8000-00805f9b34fb.|
| characteristicUuid | string | No| No   | Characteristic UUID of the descriptor. for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string | No| No   | Service UUID of the characteristic. for example, 00001888-0000-1000-8000-00805f9b34fb.|


## DescriptorWriteRequest

Defines the structure of descriptor write request sent from the client.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type       | Read-Only| Optional  | Description                                      |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| deviceId           | string      | No| No   | Bluetooth device address of the client. for example, XX:XX:XX:XX:XX:XX.|
| transId            | number      | No| No   | Transaction identifier of the characteristic write request. It must be the same as the **transId** in the response returned by the server.      |
| offset             | number      | No| No   | Write offset of the client. For example, **k** indicates that the write starts from the kth byte.<br>It must be the same as the **offset** in the response returned by the server.|
| isPrepared         | boolean     | No| No   | Whether to respond immediately after receiving a write request from the client.<br>The value **true** means to respond at a later time, and the value **false** means to respond immediately.                            |
| needRsp            | boolean     | No| No   | Whether to respond to the client.<br>The value **true** means to respond to the client, and the value **false** means to respond immediately.                      |
| value              | ArrayBuffer | No| No   | Descriptor value to write.                          |
| descriptorUuid     | string      | No| No   | Descriptor UUID. for example, 00002902-0000-1000-8000-00805f9b34fb.|
| characteristicUuid | string      | No| No   | Characteristic UUID of the descriptor. for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string      | No| No   | Service UUID of the characteristic. for example, 00001888-0000-1000-8000-00805f9b34fb.|


## ServerResponse

Defines the structure of server response to a read/write request from the client.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type       | Read-Only| Optional  | Description                                    |
| -------- | ----------- | ---- |  ---- | -------------------------------------- |
| deviceId | string      | No| No   | Bluetooth device address of the client. for example, XX:XX:XX:XX:XX:XX.      |
| transId  | number      | No| No   | Transaction identifier of the read/write request. It must be the same as the **transId** in the response returned by the server.       |
| status   | number      | No| No   | Response state. Set this parameter to **0**, which indicates a normal response.                  |
| offset   | number      | No| No   | Read/write offset. It must be the same as the **offset** in the read/write request sent from the client.|
| value    | ArrayBuffer | No| No   | Response data.                         |


## BLEConnectionChangeState

Defines the connection status of the GATT profile.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                                         | Read-Only| Optional| Description                                         |
| -------- | ------------------------------------------------- | ---- | ---- | --------------------------------------------- |
| deviceId | string                                            | No| No  | Peer Bluetooth device address. for example, XX:XX:XX:XX:XX:XX.|
| state    | [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | No| No  | Connection status of the GATT profile.                      |


## ScanResult

Defines the scan result to be reported upon scanning advertising packets that meet the filter criteria.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type       | Read-Only| Optional  | Description                                |
| -------- | ----------- | ---- | ---- | ---------------------------------- |
| deviceId | string      | No| No   | Bluetooth device address. for example, XX:XX:XX:XX:XX:XX.<br>For security purposes, the device addresses obtained are virtual MAC addresses.<br>- The virtual address remains unchanged after a device is paired successfully.<br>- If a device is unpaired or Bluetooth is disabled, the virtual address will change after the device is paired again.<br>- To persistently save the addresses, call [access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16).|
| rssi     | number      | No| No   | Signal strength, in dBm.                   |
| data     | ArrayBuffer | No| No   | Advertising data sent by the discovered device.                   |
| deviceName | string | No| No   | Device name.                   |
| connectable  | boolean | No| No   | Whether the discovered device is connectable. The value **true** indicates that the discovered device is connectable, and the value **false** indicates the opposite.                   |


## AdvertiseSetting

Defines the BLE advertising parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name         | Type   | Read-Only| Optional  | Description                                      |
| ----------- | ------- | ---- | ---- | ---------------------------------------- |
| interval    | number  | No| Yes   | Advertising interval.<br>The value range is [32, 16777215], in slots. One slot represents 0.625 ms. The default value is **1600**.<br>The maximum value is **16384** for traditional advertising.|
| txPower     | number  | No| Yes   | Transmit power. The value range is [–127, 1], in dBm. The default value is **–7**.<br>Considering performance and power consumption, the recommended parameter values are as follows: **1** for high level, **-7** for medium level, and **-15** for low level.  |
| connectable | boolean | No| Yes   | Whether the advertising is connectable. The value **true** indicates that the advertising is connectable, and the value false indicates the opposite. The default value is **true**.                  |


## AdvertiseData

Defines the BLE advertising packet data, which can also be used in the response to a scan request. Currently, only traditional advertising is supported. The maximum length of the packet data is 31 bytes. The advertising will fail if the maximum length is exceeded. When all parameters are included (especially the Bluetooth device name), ensure the length of advertising packet data does not exceed 31 bytes.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Read-Only| Optional  | Description                         |
| --------------- | ---------------------------------------- | ---- | ---- | --------------------------- |
| serviceUuids    | Array&lt;string&gt;                      | No| No   | Service UUID.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| manufactureData | Array&lt;[ManufactureData](#manufacturedata)&gt; | No| No   | Manufacturer data.<br>**Atomic service API**: This API can be used in atomic services since API version 12.          |
| serviceData     | Array&lt;[ServiceData](#servicedata)&gt; | No| No   | Service data.<br>**Atomic service API**: This API can be used in atomic services since API version 12.              |
| includeDeviceName | boolean     | No| Yes   | Whether to include the Bluetooth device name. The value **true** means to include the Bluetooth device name, and the value **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.       |
| includeTxPower<sup>18+</sup> | boolean     | No   | Yes   | Whether to include the transmit power.<br>The value **true** means to include the transmit power, and the value **false** means the opposite. The default value is **false**.<br>This parameter occupies three bytes.<br>**Atomic service API**: This API can be used in atomic services since API version 18.     |


## AdvertisingParams<sup>11+</sup>

Defines the parameters for initial BLE advertising.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                            | Read-Only| Optional | Description                     |
| ------------------- | ------------------------------- | ----- | ----- | ------------------------ |
| advertisingSettings<sup>11+</sup> | [AdvertiseSetting](#advertisesetting) | No| No   | Advertising settings.   |
| advertisingData<sup>11+</sup>    | [AdvertiseData](#advertisedata) | No| No   | Advertising data.     |
| advertisingResponse<sup>11+</sup> | [AdvertiseData](#advertisedata) | No| Yes   | Advertising response.|
| duration<sup>11+</sup>    | number   | No| Yes   | Advertising duration. The value range is [1,65535], in 10 ms.<br>If this parameter is not specified or set to **0**, advertising packets are sent continuously.   |

## AdvertisingEnableParams<sup>11+</sup>

Defines the parameters for enabling BLE advertising.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                  | Read-Only| Optional | Description                     |
| ------------------- | --------------------- | ----- | ----- | ------------------------ |
| advertisingId       | number                | No| No   | Advertising ID.    |
| duration            | number                | No| Yes   | Advertising duration. The value range is [1,65535], in 10 ms.<br>If this parameter is not specified or set to **0**, advertising packets are sent continuously.  |

## AdvertisingDisableParams<sup>11+</sup>

Defines the parameters for disabling BLE advertising.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                  | Read-Only| Optional | Description                     |
| ------------------- | --------------------- | ----- | ----- | ------------------------ |
| advertisingId       | number                | No| No   | Advertising ID.    |

## AdvertisingStateChangeInfo<sup>11+</sup>

Defines the BLE advertising status information.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                                    | Read-Only| Optional  | Description                     |
| ------------------- | --------------------------------------- | ----- | ----- | ------------------------ |
| advertisingId       | number                                  | No| No   |Advertising ID. It is assigned in initial advertising and is used to identify subsequent advertising operations.          |
| state               | [AdvertisingState](#advertisingstate11)   | No| No   | BLE advertising status.            |

## ManufactureData

Defines the manufacturer data in the BLE advertising packet data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name              | Type               | Read-Only| Optional  | Description                |
| ---------------- | ------------------- | ---- | ---- | ------------------ |
| manufactureId    | number  | No| No   | Manufacturer ID allocated by the Bluetooth Special Interest Group (SIG).|
| manufactureValue | ArrayBuffer         | No| No   | Manufacturer data.    |


## ServiceData

Represents the service data in the BLE advertising packet data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name          | Type       | Read-Only| Optional  | Description        |
| ------------ | ----------- | ---- | ---- | ---------- |
| serviceUuid  | string      | No | No   | Service UUID.|
| serviceValue | ArrayBuffer | No | No   | Service data.   |


## ScanFilter

Defines the scan filters for BLE advertising packet data. Only advertising packets that meet the filter criteria are reported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                    | Type   | Read-Only| Optional | Description                                                        |
| ------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| deviceId                                 | string      | No| Yes   | BLE device address. for example, XX:XX:XX:XX:XX:XX.          |
| name                                     | string      | No| Yes   | BLE device name.                                       |
| serviceUuid                              | string      | No| Yes   | Service UUID. for example, 00001888-0000-1000-8000-00805f9b34fb.|
| serviceUuidMask             | string      | No| Yes    | Service UUID mask. This parameter can be used with **serviceUuid** to filter specific service UUIDs. for example, FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF.|
| serviceSolicitationUuid     | string      | No| Yes    | Service solicitation UUID. for example, 00001888-0000-1000-8000-00805F9B34FB.|
| serviceSolicitationUuidMask | string      | No| Yes    | Service solicitation UUID mask. This parameter can be used with **serviceSolicitationUuid** to filter specific service solicitation UUIDs. for example, FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF.|
| serviceData                 | ArrayBuffer | No| Yes    | Service data. for example, [0x90,0x00,0xF1,0xF2].|
| serviceDataMask             | ArrayBuffer | No| Yes    | Service data mask. This parameter can be used with **serviceData** to filter specific service data. for example, [0xFF,0xFF,0xFF,0xFF].|
| manufactureId               | number      | No| Yes    | Manufacturer ID. for example, 0x0006.                |
| manufactureData             | ArrayBuffer | No| Yes    | Manufacturer data. This parameter can be used with **manufactureId** to filter specific manufacturers. for example, [0x1F,0x2F,0x3F].|
| manufactureDataMask         | ArrayBuffer | No| Yes    | Manufacturer data mask. This parameter can be used with **manufactureData** to filter specific manufacturer data. for example, [0xFF,0xFF,0xFF].|


## ScanOptions

Defines the scan options.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name       | Type                   | Read-Only| Optional  | Description                                    |
| --------- | ----------------------- | ---- | ---- | -------------------------------------- |
| interval  | number                  | No| Yes   | Delay for reporting the scan result, in ms. The default value is **0**. This parameter is used together with [ScanReportMode](#scanreportmode15).<br>- This parameter does not take effect in normal and geofence scan reporting modes. The advertising packets that meet the filtering criteria are reported immediately.<br>- This parameter takes effect in batch scan reporting mode. The advertising packets that meet the filtering criteria are stored in the cache queue and reported after the specified delay. If this parameter is not set or its value is in the range of [0, 5000), the Bluetooth subsystem sets the delay to **5000** by default. If the number of advertising packets that meet the filtering criteria exceeds the hardware's cache capability within the specified delay, the Bluetooth subsystem reports the scan result in advance.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                    |
| dutyMode  | [ScanDuty](#scanduty)   | No| Yes   | Scan mode. The default value is **SCAN_MODE_LOW_POWER**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.       |
| matchMode | [MatchMode](#matchmode) | No| Yes   | Hardware match mode. The default value is **MATCH_MODE_AGGRESSIVE**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| phyType<sup>12+</sup> | [PhyType](#phytype12) | No| Yes   | Physical channel type. The default value is **PHY_LE_1M**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| reportMode<sup>15+</sup> | [ScanReportMode](#scanreportmode15) | No| Yes   | Reporting mode. The default value is **NORMAL**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|


## GattProperties

Describes the properties supported by a GATT characteristic. The properties determine how the characteristic and its descriptors are used and accessed.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type | Read-Only| Optional  | Description         |
| -------- | ------ |---- |---- | ----------- |
| write    | boolean | No| Yes | Whether the write operation is supported.<br>The value **true** indicates that the write operation is supported and a response is required, and the value **false** indicates that the write operation is not supported. The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| writeNoResponse | boolean | No| Yes  | Whether the write operation is supported.<br>The value **true** indicates that the write operation is supported without requiring a response, and the value **false** indicates that the write operation is not supported. The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| read | boolean   | No|  Yes   | Whether the read operation is supported.<br>**true** if it has flash, **false** otherwise. The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| notify | boolean   | No| Yes   | Whether the notification operation is supported.<br>The value **true** indicates that the notification operation is supported and a response is required, and the value **false** indicates the notification operation is not supported. false<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| indicate | boolean   | No| Yes   | Whether the indication operation is supported.<br>The value **true** indicates that the indication operation is supported without requiring a response, and the value **false** indicates the indication operation is not supported. false<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| broadcast<sup>20+</sup> | boolean   | No| Yes   | Whether the characteristic can be sent by the server in advertising packets.<br>The value **true** indicates that the characteristic can be sent by the server as [ServiceData](#servicedata) in advertising packets, and the value **false** indicates the opposite. false<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| authenticatedSignedWrite<sup>20+</sup> | boolean   | No| Yes   | Whether the characteristic can be written with a signature.<br>The value **true** indicates that the characteristic can be written with a signature, and the value **false** indicates the opposite. Set this parameter to **true** if you want to replace the encryption process with signature verification. Ensure that **writeSigned** or **writeSignedMitm** in [GattPermissions](#gattpermissions20) is also set to **true**. Otherwise, this parameter does not take effect. false<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| extendedProperties<sup>20+</sup> | boolean   | No| Yes   | Whether the characteristic has extended attributes.<br>The value **true** indicates that the characteristic has extended attributes, and the value **false** indicates the opposite. false<br>**Atomic service API**: This API can be used in atomic services since API version 20.|


## GattPermissions<sup>20+</sup>

Defines the permissions required for GATT characteristic or descriptor read/write operations.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type | Read-Only| Optional  | Description         |
| -------- | ------ |---- |---- | ----------- |
| read | boolean   | No|  Yes   | Whether reading characteristics or descriptors is allowed.<br>**true** to enable, **false** otherwise. The default value is **true**.|
| readEncrypted | boolean   | No|  Yes   | Whether the characteristic or descriptor needs to be encrypted before being read.<br>The value **true** indicates that the characteristic or descriptor needs to be encrypted before being read, and the value **false** indicates the opposite. The default value is **false**.|
| readEncryptedMitm | boolean   | No|  Yes   | Whether the characteristic or descriptor to be read needs to be encrypted to prevent man-in-the-middle (MITM) attacks.<br>Enabling encryption helps to prevent data from being tampered with by a third party. The value **true** means to enable encryption, and the value **false** indicates the opposite. The default value is **false**.|
| write    | boolean | No| Yes | Whether writing characteristics or descriptors is allowed.<br>**true** to enable, **false** otherwise. The default value is **true**.|
| writeEncrypted    | boolean | No| Yes | Whether the characteristic or descriptor needs to be encrypted before being written.<br>The value **true** indicates that the characteristic or descriptor needs to be encrypted before being written, and the value **false** indicates the opposite. The default value is **false**.|
| writeEncryptedMitm    | boolean | No| Yes | Whether the characteristic or descriptor to be written needs to be encrypted to prevent MITM attacks.<br>The value **true** means to enable encryption, and the value **false** indicates the opposite. The default value is **false**.|
| writeSigned    | boolean | No| Yes | Whether the characteristic or descriptor needs to be signed before being written.<br>The value **true** means to enable encryption, and the value **false** indicates the opposite. The default value is **false**.|
| writeSignedMitm    | boolean | No| Yes | Whether the characteristic or descriptor to be written needs to be signed to prevent MITM attacks.<br>The value **true** means to enable encryption, and the value **false** indicates the opposite. The default value is **false**.|


## GattWriteType

Enumerates GATT characteristic write modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                  | Value   | Description             |
| ------------------------------------| ------ | --------------- |
| WRITE               | 1 | The peer Bluetooth device needs to send a confirmation after the write operation is complete.  |
| WRITE_NO_RESPONSE   | 2 | The peer Bluetooth device does ot need to send a confirmation after the write operation is complete. |


## ScanDuty

Enumerates scan modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description          |
| --------------------- | ---- | ------------ |
| SCAN_MODE_LOW_POWER   | 0    | Low-power mode, which features lower power consumption but lower performance.|
| SCAN_MODE_BALANCED    | 1    | Balanced mode, which features balanced performance and power consumption.     |
| SCAN_MODE_LOW_LATENCY | 2    | Low-latency mode, which features high performance but high power consumption.    |


## MatchMode

Enumerates the hardware match modes of BLE scan filters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description                                      |
| --------------------- | ---- | ---------------------------------------- |
| MATCH_MODE_AGGRESSIVE | 1    | Reports advertising packets only if their signal strength is relatively low or they are transmitted sparsely within a short period of time.|
| MATCH_MODE_STICKY     | 2    | Reports advertising packets only if their signal strength is high or they are transmitted intensively within a short period of time.      |

## AdvertisingState<sup>11+</sup>

Enumerates BLE advertising states.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| STARTED<sup>11+</sup>   | 1    | After [startAdvertising](#blestartadvertising11) is called, advertising is successfully started and related resources are allocated.      |
| ENABLED<sup>11+</sup>   | 2    | After [enableAdvertising](#bleenableadvertising11) is called, advertising is enabled successfully.      |
| DISABLED<sup>11+</sup>  | 3    | After [disableAdvertising](#bledisableadvertising11) is called, advertising is disabled successfully.      |
| STOPPED<sup>11+</sup>    | 4    | After [stopAdvertising](#blestopadvertising11) is called, advertising is disabled successfully and the resources allocated during initial advertising are released.      |

## PhyType<sup>12+</sup>

Enumerates the physical channels that are used to receive BLE advertising packets.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| PHY_LE_1M<sup>12+</sup>   | 1    | 1M PHY type.      |
| PHY_LE_ALL_SUPPORTED<sup>12+</sup>   | 255    | All supported PHY types.   |

## ScanReport<sup>15+</sup>

Defines the scan report.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Type                 |Read-Only  |Optional  | Description                                    |
| --------- | ----------------------- | ---- | ---- | ------------------------------ |
| reportType  | [ScanReportType](#scanreporttype15)        | No| No| Type of the scan report.   |
| scanResult  | Array&lt;[ScanResult](#scanresult)&gt;    | No| No| Scan result to be reported upon scanning advertising packets that meet the filter criteria.       |

## ScanReportType<sup>15+</sup>

Enumerates scan report types.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| ON_FOUND  | 1    | Triggers reporting when BLE advertising packets that meet the filter criteria are found. It applies to both the conventional and geofence reporting modes.<br> **Atomic service API**: This API can be used in atomic services since API version 15.     |
| ON_LOST | 2    | Triggers reporting when no BLE advertising packets that meet the filter criteria are found. It applies only to the geofence reporting mode.<br> **Atomic service API**: This API can be used in atomic services since API version 15.   |
| ON_BATCH<sup>19+</sup> | 3    | Triggers reporting when BLE advertising packets that meet the filter criteria are found. The reporting interval is the value of **interval** in [ScanOptions](#scanoptions).<br> **Atomic service API**: This API can be used in atomic services since API version 19.   |

## ScanReportMode<sup>15+</sup>

Enumerates scan result reporting modes.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| NORMAL  | 1    | Conventional reporting mode. The BLE advertising packets that meet the filter criteria are reported immediately after being scanned.<br>**Atomic service API**: This API can be used in atomic services since API version 15.      |
| BATCH<sup>19+</sup>  | 2    | Batch scan reporting mode.<br>- This mode reduces the frequency at which scan results are reported, enabling the system to remain in sleep mode for extended periods and thus reducing the overall power consumption of the device.<br>- In this mode, the BLE advertising packets that meet the filtering criteria are not reported immediately. Instead, they are reported after being cached for a period of time (specified by **interval** in [ScanOptions](#scanoptions)).<br>**Atomic service API**: This API can be used in atomic services since API version 19.      |
| FENCE_SENSITIVITY_LOW<sup>18+</sup>  | 10    | Low-sensitivity geofence reporting mode.<br>- In this mode, advertising packets are reported only when the device enters or leaves the geofence.<br>- This mode is applicable when the signal strength is relatively high and advertising packets are transmitted sparsely within a short period of time.<br>- When advertising packets are detected for the first time, the device enters the geofence and reporting is triggered once.<br>- If no advertising packets are detected within the specified period of time, the device leaves the geofence and reporting is triggered once.<br>**Atomic service API**: This API can be used in atomic services since API version 18.   |
| FENCE_SENSITIVITY_HIGH<sup>18+</sup>  | 11    | High-sensitivity geofence reporting mode.<br>- In this mode, advertising packets are reported only when the device enters or leaves the geofence.<br>- This mode is applicable when the signal strength is relatively low and advertising packets are transmitted sparsely within a short period of time.<br>- When advertising packets are detected for the first time, the device enters the geofence and reporting is triggered once.<br>- If no advertising packets are detected within the specified period of time, the device leaves the geofence and reporting is triggered once.<br>**Atomic service API**: This API can be used in atomic services since API version 18.   |
