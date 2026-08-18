# 401 Invalid Parameter Reported When an Optional Property Is Explicitly Set to undefined

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=ccbefe4808f1011a73b89a48a05ac99319b6faeb translatedAt=2026-08-18T11:00:40.356Z pushedAt=2026-08-18T11:19:15.722Z -->

## Symptom

During BLE Bluetooth app development, when you call an API that carries optional parameters and explicitly set an optional property to undefined, for example, [startScan](../../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#startscan15) (by writing manufactureId: undefined in the object literal), the API throws error code 401 (Invalid parameter), indicating an invalid parameter.

## Possible Causes

The underlying implementation of APIs such as `bleScanner.startScan` is written in C/C++. When you call these APIs on the app side, the parameters are passed through NAPI to the system layer for parsing:

- **Existence of object keys**: In memory, {} (without the property) and { manufactureId: undefined } (with the property explicitly set to undefined) are different. The former does not contain the key, while the latter contains the key with a value of undefined.

- **Strict type validation at the underlying layer**: When the underlying C++ receives the configuration object:

    - If the `manufactureId` key exists, the security mechanism strictly validates its value. The system expects to parse a valid numeric value (Number type), but actually receives `undefined`, causing a type mismatch. NAPI parsing fails and throws 401: Invalid parameter at the entry point.

    - If the `manufactureId` key does not exist, it is skipped directly and the system default logic (that is, no restriction on `manufactureId`) is applied.

## Solution

To avoid the strict type validation issue during cross-language calls, for optional parameters, follow the principle of adding properties only when needed (do not write a key when there is no valid value).

- When constructing a parameter object, do not explicitly assign `undefined` to optional properties.

- Write a property into the object literal or dynamically attach it to the object only when it has a valid value.

- This rule applies to all scenarios where the underlying C/C++ APIs are called through NAPI, including but not limited to BLE scan filter construction and event subscription/unsubscription.

## Sample Code

The following example uses the `bleScanner.startScan` API:

```ts
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { ble } from '@kit.ConnectivityKit';

let manufactureId: number | undefined = undefined; // Simulate a value that may be empty in actual services.
let manufactureData: Uint8Array = new Uint8Array([1, 2, 3, 4]);
let manufactureDataMask: Uint8Array = new Uint8Array([0xFF, 0xFF, 0xFF, 0xFF]);

// Write undefined directly into the object literal (which returns error code 401).
// let scanFilter: ble.ScanFilter = {
//     manufactureId: undefined,
//     manufactureData: manufactureData.buffer,
//     manufactureDataMask: manufactureDataMask.buffer
// };

// Recommended: initialize only the properties that definitely have values.
let scanFilter: ble.ScanFilter = {
    manufactureData: manufactureData.buffer,
    manufactureDataMask: manufactureDataMask.buffer
};

// Dynamically determine and mount the value to the object only when it is valid.
if (manufactureId !== undefined) {
    scanFilter.manufactureId = manufactureId;
}

let bleScanner: ble.BleScanner = ble.createBleScanner();

function onReceiveEvent(scanReport: ble.ScanReport) {
    console.info('BLE scan device find result = ' + JSON.stringify(scanReport));
}

let scanOptions: ble.ScanOptions = {
    interval: 500,
    dutyMode: ble.ScanDuty.SCAN_MODE_LOW_POWER,
    matchMode: ble.MatchMode.MATCH_MODE_AGGRESSIVE,
    reportMode: ble.ScanReportMode.FENCE_SENSITIVITY_LOW
};

try {
    bleScanner.on("BLEDeviceFind", onReceiveEvent);
    bleScanner.startScan([scanFilter], scanOptions);
    console.info('startScan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```