# @ohos.bluetooth.ble (Bluetooth BLE Module)

The **ble** module provides APIs for operating and managing Bluetooth.

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

Creates a **GattServer** instance.

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

Creates a **GattClientDevice** instance.

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

Obtains the Bluetooth Low Energy (BLE) devices connected to this device.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;string&gt; | Addresses of the BLE devices connected to this device.<br>For security purposes, the device addresses obtained are random MAC addresses.<br>- The random MAC address remains unchanged after a device is paired successfully.<br>- The random address changes when the paired device is unpaired and scanned again or the Bluetooth service is turned off.|

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
> **NOTE**
> - This API can be used to scan only BLE devices.
> - This API supports only single-channel scanning. That is, the application can call this API only once at a time. Before calling this API again, you need to call [ble.stopBLEScan](#blestopscan) to stop previous scanning.
> - To use multi-channel scanning, call [BleScanner](#blescanner15).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | Yes   | Rules for filtering the scan result. Devices that meet the filtering rules will be retained. Set this parameter to **null** if you do not want to filter the scan result.|
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

Starts BLE advertising.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type                                   | Mandatory  | Description            |
| ----------- | ------------------------------------- | ---- | -------------- |
| setting     | [AdvertiseSetting](#advertisesetting) | Yes   | Settings related to BLE advertising.   |
| advData     | [AdvertiseData](#advertisedata)       | Yes   | Content of the BLE advertisement packet.     |
| advResponse | [AdvertiseData](#advertisedata)       | No   | Response to the BLE scan request.|

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

Stops BLE advertising.

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

Starts BLE advertising. This API uses an asynchronous callback to return the result. Since API version 15, you can call this API multiple times to establish multiple advertising channels, each being identified by a unique ID.

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
|2900099 | Operation failed.                        |

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

Starts BLE advertising. This API uses a promise to return the result. Since API version 15, you can call this API multiple times to establish multiple advertising channels, each being identified by a unique ID.

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
|2900099 | Operation failed.                        |

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

Temporarily enables BLE advertising. This API uses an asynchronous callback to return the result.

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

Temporarily enables BLE advertising. This API uses a promise to return the result.

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

Disables BLE advertising temporarily. This API uses an asynchronous callback to return the result.

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

Disables BLE advertising temporarily. This API uses a promise to return the result.

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

Stops BLE advertising. This API uses an asynchronous callback to return the result.

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

Stops BLE advertising. This API uses a promise to return the result.

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
| type     | string                                                                    | Yes   | Event type. The value is **advertisingStateChange**, which indicates the advertising status change.       |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo11)&gt; | Yes   | Callback used to return the advertising status. You need to implement this callback.|

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

Unsubscribes from BLE advertising status.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                                                   | Mandatory  | Description                                                     |
| -------- | ------------------------------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                                                    | Yes   | Event type. The value is **advertisingStateChange**, which indicates the advertising status change.       |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo11)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to BLE device discovery events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEDeviceFind**, which indicates an event of discovering a BLE device.  |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | Yes   | Callback used to return the discovered devices. You need to implement this callback.|

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

Unsubscribes from BLE device discovery events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEDeviceFind**, which indicates an event of discovering a BLE device.       |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Represents the **GattServer** class. Before using APIs in this class, you need to call **createGattServer()** to create a **GattServer** instance.


### addService

addService(service: GattService): void

Adds a service to this GATT server.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                         | Mandatory  | Description                      |
| ------- | --------------------------- | ---- | ------------------------ |
| service | [GattService](#gattservice) | Yes   | Service to add. Settings related to BLE advertising.|

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
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
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

Removes a service from this GATT server.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type    | Mandatory  | Description                                      |
| ----------- | ------ | ---- | ---------------------------------------- |
| serviceUuid | string | Yes   | Service UUID, for example, 00001810-0000-1000-8000-00805F9B34FB.|

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

Closes this GATT server to unregister it from the protocol stack. The closed [GattServer](#gattserver) instance will no longer be used.

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

Notifies a connected client device when a characteristic value changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                                     |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | Yes   | Address of the client device to notify, for example, XX:XX:XX:XX:XX:XX.|
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | Yes   | New characteristic value.                              |
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
            console.info('notifyCharacteristicChanged callback failed');
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

Notifies a connected client device when a characteristic value changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                                     |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | Yes   | Address of the client device to notify, for example, XX:XX:XX:XX:XX:XX.|
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | Yes   | New characteristic value.                              |

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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

Sends a response to a read or write request from the GATT client.

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
cccValue[0] = 1123;
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

Subscribes to characteristic read request events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **characteristicRead**, which indicates a characteristic read request event.|
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequest)&gt; | Yes   | Callback used to return a characteristic read request event from the GATT client.           |

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
cccValue[0] = 1123;
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
| type     | string                                   | Yes   | Event type. The value is **characteristicRead**, which indicates a characteristic read request event.   |
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequest)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to characteristic write request events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **characteristicWrite**, which indicates a characteristic write request event.|
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequest)&gt; | Yes   | Callback used to return a characteristic write request from the GATT client.            |

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
| type     | string                                   | Yes   | Event type. The value is **characteristicWrite**, which indicates a characteristic write request event.  |
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequest)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to descriptor read request events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                               |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **descriptorRead**, which indicates a descriptor read request event.|
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequest)&gt; | Yes   | Callback used to return a characteristic read request event from the GATT client.       |

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
descValue[0] = 1101;
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
| type     | string                                   | Yes   | Event type. The value is **descriptorRead**, which indicates a descriptor read request event.       |
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequest)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to descriptor write request events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **descriptorWrite**, which indicates a descriptor write request event.|
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequest)&gt; | Yes   | Callback used to return a characteristic write request from the GATT client.        |

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
| type     | string                                   | Yes   | Event type. The value is **descriptorWrite**, which indicates a descriptor write request event.      |
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequest)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to BLE connection state changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **connectionStateChange**, which indicates BLE connection state changes.|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | Yes   | Callback used to return the BLE connection state.                         |

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
import { constant } from '@kit.ConnectivityKit';
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

Unsubscribes from BLE connection state changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **connectionStateChange**, which indicates BLE connection state changes.|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to MTU status changes for the server. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEMtuChange**, which indicates the MTU status changes. If this parameter is not set correctly, the callback cannot be registered.|
| callback | Callback&lt;number&gt; | Yes   | Callback used to return the number of MTU bytes.|

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

Unsubscribes from MTU status changes for the server.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEMtuChange**, which indicates the MTU status changes. If this parameter is not set correctly, the callback cannot be registered.|
| callback | Callback&lt;number&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Represents the **GattClientDevice** class. Before using APIs in this class, you need to call **createGattClientDevice(deviceId: string)** to create a **GattClientDevice** instance.


### connect

connect(): void

Connects to the peer BLE device.

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

Disconnects from the peer BLE device.

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

Closes this GATT client to unregister it from the protocol stack. The closed [GattClientDevice](#gattclientdevice) instance will no longer be used.

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

Obtains the name of the peer BLE device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the peer BLE device name.|

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// callback
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.connect();
    gattClient.getDeviceName((err: BusinessError, data: string)=> {
        console.info('device name err ' + JSON.stringify(err));
        console.info('device name' + JSON.stringify(data));
    })
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
| Promise&lt;string&gt; | Promise used to return the peer BLE device name.|

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// promise
try {
    let gattClient: ble.GattClientDevice = ble.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.connect();
    gattClient.getDeviceName().then((data: string) => {
        console.info('device name' + JSON.stringify(data));
    })
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getServices

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

Obtains all services of the peer BLE device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Yes   | Callback used to return the services obtained.|

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

try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.connect();
    device.getServices(getServices);
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
| Promise&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Promise used to return the services obtained.|

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
// Promise mode.
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.connect();
    device.getServices().then((result: Array<ble.GattService>) => {
        console.info('getServices successfully:' + JSON.stringify(result));
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### readCharacteristicValue

readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void

Reads the characteristic value of the specific service of the peer BLE device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                      | Mandatory  | Description                     |
| -------------- | ---------------------------------------- | ---- | ----------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic)  | Yes   | Characteristic value to read.               |
| callback       | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Callback used to return the characteristic value read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901000 | Read forbidden.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function readCcc(code: BusinessError, BLECharacteristic: ble.BLECharacteristic) {
  if (code.code != 0) {
      return;
  }
  console.info('bluetooth characteristic uuid: ' + BLECharacteristic.characteristicUuid);
  let value = new Uint8Array(BLECharacteristic.characteristicValue);
  console.info('bluetooth characteristic value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
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

Reads the characteristic value of the specific service of the peer BLE device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description      |
| -------------- | --------------------------------------- | ---- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic value to read.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLECharacteristic](#blecharacteristic)&gt; | Promise used to return the characteristic value read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901000 | Read forbidden.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
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

Reads the descriptor contained in the specific characteristic of the peer BLE device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description                     |
| ---------- | ---------------------------------------- | ---- | ----------------------- |
| descriptor | [BLEDescriptor](#bledescriptor)          | Yes   | Descriptor to read.               |
| callback   | AsyncCallback&lt;[BLEDescriptor](#bledescriptor)&gt; | Yes   | Callback used to return the descriptor read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901000 | Read forbidden.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function readDesc(code: BusinessError, BLEDescriptor: ble.BLEDescriptor) {
    if (code.code != 0) {
        return;
    }
    console.info('bluetooth descriptor uuid: ' + BLEDescriptor.descriptorUuid);
    let value = new Uint8Array(BLEDescriptor.descriptorValue);
    console.info('bluetooth descriptor value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB',
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

Reads the descriptor contained in the specific characteristic of the peer BLE device. This API uses a promise to return the result.

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
| Promise&lt;[BLEDescriptor](#bledescriptor)&gt; | Promise used to return the descriptor read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.               |
|2901000 | Read forbidden.                |
|2900099 | Operation failed.              |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB',
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

Writes a characteristic value to the peer BLE device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                 |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Binary value and other parameters of the BLE device characteristic.|
| writeType | [GattWriteType](#gattwritetype) | Yes   | Write type of the Bluetooth device characteristic value.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the write operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901001 | Write forbidden.                        |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
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

Writes a characteristic value to the peer BLE device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                 |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Binary value and other parameters of the BLE device characteristic.|
| writeType | [GattWriteType](#gattwritetype) | Yes   | Write type of the Bluetooth device characteristic value.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise used to return the descriptor read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901001 | Write forbidden.                        |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let descriptors: Array<ble.BLEDescriptor>  = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: ble.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
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

Writes binary data to the specific descriptor of the peer BLE device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description                |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes   | Binary value and other parameters of the BLE device descriptor.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the write operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901001 | Write forbidden.                        |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 22;
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device: ble.GattClientDevice = ble.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeDescriptorValue(descriptor, (err: BusinessError) => {
        if (err) {
            console.info('notifyCharacteristicChanged callback failed');
        } else {
            console.info('notifyCharacteristicChanged callback successful');
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### writeDescriptorValue

writeDescriptorValue(descriptor: BLEDescriptor): Promise&lt;void&gt;

Writes binary data to the specific descriptor of the peer BLE device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description                |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes   | Binary value and other parameters of the BLE device descriptor.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise used to return the descriptor read.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901001 | Write forbidden.                        |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 22;
let descriptor: ble.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB',
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

Obtains the RSSI of the peer BLE device. It can be used only after a connection is set up by calling [connect](#connect). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the signal strength, in dBm.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.         |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

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

Obtains the RSSI of the peer BLE device. It can be used only after a connection is set up by calling [connect](#connect). This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description                               |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Callback used to return the signal strength, in dBm.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.               |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

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

Sets the maximum transmission unit (MTU) that can be transmitted between the GATT client and its peer BLE device. This API can be used only after a connection is set up by calling [connect](#connect).
> **NOTE**
> - This API subscribes to MTU status change events through [on ('BLEMtuChange')] (#onblemtuchange-1).

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| mtu  | number | Yes   | MTU to set, which ranges from 22 to 512 bytes.|

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

Sets a notification for the change of a characteristic. The GATT client that subscribes to the change will be notified when the characteristic changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | BLE characteristic to listen for.                     |
| enable         | boolean                                 | Yes   | Whether to notify the client of the characteristic change. The value **true** means to notify the client, and the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

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
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
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
            console.info('notifyCharacteristicChanged callback failed');
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

Sets a notification for the change of a characteristic. The GATT client that subscribes to the change will be notified when the characteristic changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | BLE characteristic to listen for.                     |
| enable         | boolean                                 | Yes   | Whether to notify the client of the characteristic change. The value **true** means to notify the client, and the value **false** means the opposite.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
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

Sets an indication for the change of a characteristic. The GATT client must acknowledge the indication received. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | BLE characteristic to listen for.                     |
| enable         | boolean                                 | Yes   | Whether to notify the client of the characteristic change. The value **true** means to notify the client, and the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

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
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
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
      console.info('notifyCharacteristicChanged callback failed');
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

Sets an indication for the change of a characteristic. The GATT client must acknowledge the indication received. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | BLE characteristic to listen for.                     |
| enable         | boolean                                 | Yes   | Whether to notify the client of the characteristic change. The value **true** means to notify the client, and the value **false** means the opposite.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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
// Create descriptors.
let descriptors: Array<ble.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
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

Subscribes to BLE characteristic changes. Before calling this API, use [setCharacteristicChangeNotification](#setcharacteristicchangenotification) or [setCharacteristicChangeIndication](#setcharacteristicchangeindication) to enable the client to receive notifications or indications from the server. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLECharacteristicChange**, which indicates characteristic value changes.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Callback used to return the characteristic value changes.                 |

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

Unsubscribes from BLE characteristic changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLECharacteristicChange**, which indicates characteristic value changes.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to BLE connection state changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEConnectionStateChange**, which indicates BLE connection state changes.|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | Yes   | Callback used to return the BLE connection state.                          |

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

Unsubscribes from BLE connection state changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEConnectionStateChange**, which indicates BLE connection state changes.|
| callback | Callback&lt;[BLEConnectionChangeState](#bleconnectionchangestate)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Subscribes to MTU status changes for the client. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEMtuChange**, which indicates the MTU status changes. If this parameter is not set correctly, the callback cannot be registered.|
| callback | Callback&lt;number&gt; | Yes   | Callback used to return the number of MTU bytes.|

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

Unsubscribes from MTU status changes for the client.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEMtuChange**, which indicates the MTU status changes. If this parameter is not set correctly, the callback cannot be registered.|
| callback | Callback&lt;number&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Represents the **BleScanner** class. Before using APIs in this class, you need to call **createBleScanner()** to create a **BleScanner** instance.

### startScan<sup>15+</sup>

startScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): Promise&lt;void&gt;

Initiates BLE scanning. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | Yes   | Rules for filtering the scan result. Devices that meet the filtering rules will be retained. Set this parameter to **null** if you do not want to filter the scan result.|
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
|2900009 | Fails to start scan as it is out of hardware.                 |
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

Stops BLE scanning.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

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
import { ble } from '@kit.ConnectivityKit';
let bleScanner: ble.BleScanner = ble.createBleScanner();
try {
    bleScanner.stopScan();
    console.info('startScan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### on('BLEDeviceFind')<sup>15+</sup>

on(type: 'BLEDeviceFind', callback: Callback&lt;ScanReport&gt;): void

Subscribes to BLE device discovery events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEDeviceFind**, which indicates an event of discovering a BLE device.  |
| callback | Callback&lt;[ScanReport](#scanreport15)&gt; | Yes   | Callback used to return the discovered devices. You need to implement this callback.|

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

Unsubscribes from BLE device discovery events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **BLEDeviceFind**, which indicates an event of discovering a BLE device.       |
| callback | Callback&lt;[ScanReport](#scanreport15)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for the specified **type**.|

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

Defines the GATT service API parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Readable  | Writable  | Description                                      |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid     | string                                   | Yes   | Yes   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|
| isPrimary       | boolean                                  | Yes   | Yes   | Whether the service is a primary service. The value **true** means a primary service.               |
| characteristics | Array&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Yes   | List of characteristics of the service.                            |
| includeServices | Array&lt;[GattService](#gattservice)&gt; | Yes   | Yes   | Services on which the service depends.                            |


## BLECharacteristic

Defines the characteristic API parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type                                    | Readable  | Writable  | Description                                |
| ------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string                                   | Yes   | Yes   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|
| characteristicUuid  | string                  | Yes   | Yes   | Characteristic UUID, for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| characteristicValue | ArrayBuffer                              | Yes   | Yes   | Binary value of the characteristic.                     |
| descriptors         | Array&lt;[BLEDescriptor](#bledescriptor)&gt; | Yes   | Yes   | List of descriptors of the characteristic.               |
| properties  | [GattProperties](#gattproperties) |   Yes  | Yes    | Properties of the characteristic.    |


## BLEDescriptor

Represents a BLE descriptor.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type       | Readable  | Writable  | Description                                      |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid        | string      | Yes   | Yes   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|
| characteristicUuid | string      | Yes   | Yes   | Characteristic UUID, for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| descriptorUuid     | string      | Yes   | Yes   | Descriptor UUID, for example, 00002902-0000-1000-8000-00805f9b34fb.|
| descriptorValue    | ArrayBuffer | Yes   | Yes   | Binary value of the descriptor.                             |


## NotifyCharacteristic

Defines the parameters in the notifications sent when the server characteristic value changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type       | Readable  | Writable  | Description                                      |
| ------------------- | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string      | Yes   | Yes   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|
| characteristicUuid  | string      | Yes   | Yes   | Characteristic UUID, for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| characteristicValue | ArrayBuffer | Yes   | Yes   | Binary value of the characteristic.                              |
| confirm             | boolean     | Yes   | Yes   | Whether the indication or notification needs to be acknowledged by the peer end. Set this parameter to **true** for an indication, which needs to be acknowledged by the peer end.<br>Set this parameter to **false** for a notification, which does not need to be acknowledged by the peer end.|


## CharacteristicReadRequest

Defines the parameters of the **CharacteristicReadReq** event received by the server.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the peer device that sends the request, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the read request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Position from which the characteristic value is read. For example, **k** means to read from the kth byte. The response returned by the server must use the same offset.|
| characteristicUuid | string | Yes   | No   | Characteristic UUID, for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string | Yes   | No   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|


## CharacteristicWriteRequest

Defines the parameters of the **CharacteristicWriteReq** event received by the server.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the peer device that sends the request, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the write request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Start position for writing the characteristic value. For example, **k** means to write from the kth byte. The response returned by the server must use the same offset.|
| isPrepared             | boolean | Yes   | No   | Whether the write request is executed immediately. The value **true** means to execute the write request immediately.|
| needRsp             | boolean | Yes   | No   | Whether to send a response to the GATT client. The value **true** means to send a response.|
| value             | ArrayBuffer | Yes   | No   | Binary value of the descriptor to write.|
| characteristicUuid | string | Yes   | No   | Characteristic UUID, for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string | Yes   | No   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|


## DescriptorReadRequest

Defines the parameters of the **DescriptorReadReq** event received by the server.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the peer device that sends the request, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the read request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Position from which the descriptor is read. For example, **k** means to read from the kth byte. The response returned by the server must use the same offset.|
| descriptorUuid     | string | Yes   | No   | Descriptor UUID, for example, 00002902-0000-1000-8000-00805f9b34fb.|
| characteristicUuid | string | Yes   | No   | Characteristic UUID, for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string | Yes   | No   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|


## DescriptorWriteRequest

Defines the parameters of the **DescriptorWriteReq** event received by the server.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type       | Readable  | Writable  | Description                                      |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| deviceId           | string      | Yes   | No   | Address of the peer device that sends the request, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number      | Yes   | No   | Transmission ID of the write request. The response returned by the server must use the same transmission ID.      |
| offset             | number      | Yes   | No   | Start position for writing the descriptor. For example, **k** means to write from the kth byte. The response returned by the server must use the same offset.|
| isPrepared             | boolean     | Yes   | No   | Whether the write request is executed immediately.                            |
| needRsp            | boolean     | Yes   | No   | Whether to send a response to the GATT client.                      |
| value              | ArrayBuffer | Yes   | No   | Binary value of the descriptor to write.                          |
| descriptorUuid     | string      | Yes   | No   | Descriptor UUID, for example, 00002902-0000-1000-8000-00805f9b34fb.|
| characteristicUuid | string      | Yes   | No   | Characteristic UUID, for example, 00002a11-0000-1000-8000-00805f9b34fb.|
| serviceUuid        | string      | Yes   | No   | Service UUID, for example, 00001888-0000-1000-8000-00805f9b34fb.|


## ServerResponse

Defines the parameters of the server's response to the GATT client's read/write request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type       | Readable  | Writable  | Description                                    |
| -------- | ----------- | ---- | ---- | -------------------------------------- |
| deviceId | string      | Yes   | No   | Address of the peer device, for example, XX:XX:XX:XX:XX:XX.      |
| transId  | number      | Yes   | No   | Transmission ID of the request. The value must be the same as the ID carried in the read/write request received.       |
| status   | number      | Yes   | No   | Response state. Set this parameter to **0**, which indicates a normal response.                  |
| offset   | number      | Yes   | No   | Start read/write position. The value must be the same as the offset carried in the read/write request.|
| value    | ArrayBuffer | Yes   | No   | Binary data in the response.                         |


## BLEConnectionChangeState

Represents the GATT profile connection state.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                                         | Readable| Writable| Description                                         |
| -------- | ------------------------------------------------- | ---- | ---- | --------------------------------------------- |
| deviceId | string                                            | Yes  | No  | Address of the peer device, for example, XX:XX:XX:XX:XX:XX.|
| state    | [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | Yes  | Yes  | BLE connection state.                      |


## ScanResult

Defines the scan result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type       | Readable  | Writable  | Description                                |
| -------- | ----------- | ---- | ---- | ---------------------------------- |
| deviceId | string      | Yes   | No   | Address of the device discovered, for example, XX:XX:XX:XX:XX:XX.<br>For security purposes, the device addresses obtained are random MAC addresses.<br>- The random MAC address remains unchanged after a device is paired successfully.<br>- The random address changes when the paired device is unpaired and scanned again or the Bluetooth service is turned off.|
| rssi     | number      | Yes   | No   | RSSI of the device.                   |
| data     | ArrayBuffer | Yes   | No   | Advertisement packets sent by the device.                   |
| deviceName | string | Yes   | No   | Name of the device detected.                   |
| connectable  | boolean | Yes   | No   | Whether the discovered device is connectable. The value **true** means the discovered device is connectable; the value **false** means the opposite.                   |


## AdvertiseSetting

Defines the BLE advertising parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name         | Type   | Readable  | Writable  | Description                                      |
| ----------- | ------- | ---- | ---- | ---------------------------------------- |
| interval    | number  | Yes   | Yes   | Advertising interval.<br>The minimum value is 32 slots, indicating 20 ms. The maximum value is 16777215 slots. The default value is 1600 slots, indicating 1s. (In traditional advertising mode, the maximum value is 16384 slots, indicating 10.24s.)|
| txPower     | number  | Yes   | Yes   | Transmit power, in dBm.<br>The minimum value is **-127**, and the maximum value is **1**. The default value is **-7**.<br>Recommended value: **1** for high transmit power, **-7** for medium transmit power, and **-15** for low transmit power.  |
| connectable | boolean | Yes   | Yes   | Whether the advertisement is connectable.<br>The value **true** (default value) indicates that the advertisement is connectable, and the value **false** indicates the opposite.                  |


## AdvertiseData

Represents the content of a BLE advertising packet, which is 31 bytes in size.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Readable  | Writable  | Description                         |
| --------------- | ---------------------------------------- | ---- | ---- | --------------------------- |
| serviceUuids    | Array&lt;string&gt;                      | Yes   | Yes   | List of service UUIDs to broadcast.|
| manufactureData | Array&lt;[ManufactureData](#manufacturedata)&gt; | Yes   | Yes   | List of manufacturers to broadcast.          |
| serviceData     | Array&lt;[ServiceData](#servicedata)&gt; | Yes   | Yes   | List of service data to broadcast.              |
| includeDeviceName | boolean     | Yes   | Yes   | Whether the device name is contained. This parameter is optional.<br>To carry the device name, set this parameter to **true**. Otherwise, set this parameter to **false** or leave it unspecified.<br>Note that the advertising packet containing the device name cannot exceed 31 bytes.       |

## AdvertisingParams<sup>11+</sup>

Defines the parameters for starting BLE advertising for the first time.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                            | Readable | Writable | Description                     |
| ------------------- | ------------------------------- | ----- | ----- | ------------------------ |
| advertisingSettings<sup>11+</sup> | [AdvertiseSetting](#advertisesetting) | Yes   | Yes   | Parameters related advertising settings.   |
| advertisingData<sup>11+</sup>    | [AdvertiseData](#advertisedata) | Yes   | Yes   | Content of the advertising packet.     |
| advertisingResponse<sup>11+</sup> | [AdvertiseData](#advertisedata) | Yes   | Yes   | Content of the response to the scan request.|
| duration<sup>11+</sup>    | number   | Yes   | Yes   | Duration for the advertising, in 10 ms.<br><br>The value ranges from 1 (10 ms) to 65535 (655350 ms).<br>If this parameter is not specified or set to **0**, advertising packets are sent continuously.   |

## AdvertisingEnableParams<sup>11+</sup>

Defines the parameters for temporarily enabling BLE advertising.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                  | Readable | Writable | Description                     |
| ------------------- | --------------------- | ----- | ----- | ------------------------ |
| advertisingId<sup>11+</sup>       | number                | Yes   | Yes   | ID of the advertisement.    |
| duration<sup>11+</sup>            | number                | Yes   | Yes   | Duration for the advertising, in 10 ms.<br><br>The value ranges from 1 (10 ms) to 65535 (655350 ms).<br>If this parameter is not specified or set to **0**, advertising packets are sent continuously.  |

## AdvertisingDisableParams<sup>11+</sup>

Defines the parameters for temporarily disabling BLE advertising.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                  | Readable | Writable | Description                     |
| ------------------- | --------------------- | ----- | ----- | ------------------------ |
| advertisingId<sup>11+</sup>       | number                | Yes   | Yes   | ID of the advertisement.    |

## AdvertisingStateChangeInfo<sup>11+</sup>

Represents the advertising status information.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Type                                    | Readable | Writable | Description                     |
| ------------------- | --------------------------------------- | ----- | ----- | ------------------------ |
| advertisingId<sup>11+</sup>       | number                                  | Yes   | Yes   | ID of the advertisement.          |
| state<sup>11+</sup>               | [AdvertisingState](#advertisingstate11)   | Yes   | Yes   | Advertising status.            |

## ManufactureData

Defines the content of a BLE advertisement packet.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name              | Type               | Readable  | Writable  | Description                |
| ---------------- | ------------------- | ---- | ---- | ------------------ |
| manufactureId    | number  | Yes   | Yes   | Manufacturer ID allocated by the Bluetooth SIG.|
| manufactureValue | ArrayBuffer         | Yes   | Yes   | Manufacturer data.    |


## ServiceData

Defines the service data contained in an advertisement packet.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name          | Type       | Readable  | Writable  | Description        |
| ------------ | ----------- | ---- | ---- | ---------- |
| serviceUuid  | string      | Yes   | Yes   | Service UUID.|
| serviceValue | ArrayBuffer | Yes   | Yes   | Service data.   |


## ScanFilter

Defines the scan filter parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                    | Type   | Mandatory | Description                                                        |
| ------------------------------------------ | -------- | ---- | ------------------------------------------------------------ |
| deviceId                                 | string      | No   | Address of the BLE device to filter, for example, XX:XX:XX:XX:XX:XX.          |
| name                                     | string      | No   | Name of the BLE device to filter.                                       |
| serviceUuid                              | string      | No   | Service UUID of the device to filter, for example, 00001888-0000-1000-8000-00805f9b34fb.|
| serviceUuidMask             | string      | No    | Service UUID mask of the device to filter, for example, FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF.|
| serviceSolicitationUuid     | string      | No    | Service solicitation UUID of the device to filter, for example, 00001888-0000-1000-8000-00805F9B34FB.|
| serviceSolicitationUuidMask | string      | No    | Service solicitation UUID mask of the device to filter, for example, FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF.|
| serviceData                 | ArrayBuffer | No    | Service data of the device to filter, for example, [0x90,0x00,0xF1,0xF2].|
| serviceDataMask             | ArrayBuffer | No    | Service data mask of the device to filter, for example, [0xFF,0xFF,0xFF,0xFF].|
| manufactureId               | number      | No    | Manufacturer ID of the device to filter, for example, 0x0006.                |
| manufactureData             | ArrayBuffer | No    | Manufacturer data of the device to filter, for example, [0x1F,0x2F,0x3F].|
| manufactureDataMask         | ArrayBuffer | No    | Manufacturer data mask of the device to filter, for example, [0xFF,0xFF,0xFF].|


## ScanOptions

Defines the scan configuration parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name       | Type                   | Readable  | Writable  | Description                                    |
| --------- | ----------------------- | ---- | ---- | -------------------------------------- |
| interval  | number                  | Yes   | Yes   | Delay in reporting the scan result. The default value is **0**.                   |
| dutyMode  | [ScanDuty](#scanduty)   | Yes   | Yes   | Scan duty. The default value is SCAN_MODE_LOW_POWER.       |
| matchMode | [MatchMode](#matchmode) | Yes   | Yes   | Hardware filtering match mode. The default value is **MATCH_MODE_AGGRESSIVE**.|
| phyType<sup>12+</sup> | [PhyType](#phytype12) | Yes   | Yes   | Physical layer (PHY) type used in scanning.|
| reportMode<sup>15+</sup> | [ScanReportMode](#scanreportmode15) | Yes   | Yes   | Scan result reporting mode.|


## GattProperties

Defines the properties of a GATT characteristic.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type | Mandatory  | Description         |
| -------- | ------ |---- | ----------- |
| write    | boolean | No | Whether the characteristic is writeable. The value **true** means to allow writes to the characteristic with an acknowledgment.|
| writeNoResponse | boolean | No   | Whether to allow the characteristic to be written without an acknowledgment. The value **true** means to allow writes to the characteristic without an acknowledgment.|
| read | boolean   |  No   | Whether the characteristic is readable. The value **true** means the characteristic is readable. |
| notify | boolean   | No   | Whether to notify the client when the characteristic value changes. The value **true** means to notify the client of the characteristic change.|
| indicate | boolean   | No   | Whether to indicate the client when the characteristic value changes. The value **true** means to indicate the client of the characteristic change. An acknowledgment from the client is also required.|


## GattWriteType

Enumerates the GATT write types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                  | Value   | Description             |
| ------------------------------------| ------ | --------------- |
| WRITE               | 1 | Write a characteristic value with a response from the peer device.  |
| WRITE_NO_RESPONSE   | 2 | Write characteristic value without a response from the peer device. |


## ScanDuty

Enumerates the scan duties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description          |
| --------------------- | ---- | ------------ |
| SCAN_MODE_LOW_POWER   | 0    | Low-power mode, which is the default value.|
| SCAN_MODE_BALANCED    | 1    | Balanced mode.     |
| SCAN_MODE_LOW_LATENCY | 2    | Low-latency mode.    |


## MatchMode

Enumerates the hardware match modes of BLE scan filters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description                                      |
| --------------------- | ---- | ---------------------------------------- |
| MATCH_MODE_AGGRESSIVE | 1    | Hardware reports the scan result with a lower threshold of signal strength and few number of matches in a duration. This is the default value.|
| MATCH_MODE_STICKY     | 2    | Hardware reports the scan result with a higher threshold of signal strength and sightings.      |

## AdvertisingState<sup>11+</sup>

Enumerates the advertising statuses.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| STARTED<sup>11+</sup>   | 1    | The BLE advertising is started for the first time.      |
| ENABLED<sup>11+</sup>   | 2    | The BLE advertising is enabled temporarily.      |
| DISABLED<sup>11+</sup>  | 3    | The BLE advertising is disabled temporarily.      |
| STOPPED<sup>11+</sup>    | 4    | The BLE advertising is stopped.      |

## PhyType<sup>12+</sup>

Enumerates the PHY types used in scanning.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| PHY_LE_1M<sup>12+</sup>   | 1    | 1 M PHY.      |
| PHY_LE_ALL_SUPPORTED<sup>12+</sup>   | 255    | PHY mode supported by the Bluetooth profile used in scanning.   |

## ScanReport<sup>15+</sup>

Enumerates the scan result reporting modes.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Type                 | Read-Only  | Optional  | Description                                    |
| --------- | ----------------------- | ---- | ---- | ------------------------------ |
| reportType  | [ScanReportType](#scanreporttype15)        | No| No| Type of the scan report.   |
| scanResult  | Array&lt;[ScanResult](#scanresult)&gt;    | No| No|Scan result.       |

## ScanReportType<sup>15+</sup>

Enumerates the types of scan reports.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| ON_FOUND  | 1    | Advertising packets found.      |
| ON_LOST | 2    | Advertising packets lost.   |

## ScanReportMode<sup>15+</sup>

Enumerates the scan result reporting modes.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name     | Value   | Description                          |
| --------  | ---- | ------------------------------ |
| NORMAL  | 1    | Normal mode.      |
| FENCE_SENSITIVITY_LOW<sup>18+</sup>  | 10    | Low-sensitivity geofence reporting mode. The scan result is reported only when the advertising packet is received for the first time or lost.   |
| FENCE_SENSITIVITY_HIGH<sup>18+</sup>  | 11    | High-sensitivity geofence reporting mode. The scan result is reported only when the advertising packet is received for the first time or lost.   |
