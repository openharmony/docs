# @ohos.nearlink.scan (NearLink Scanning Capability)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=aa9545020692baaf11004432a3eb3c2a031071bf translatedAt=2026-08-17T08:50:49.790Z pushedAt=2026-08-19T01:21:14.143Z -->

This module provides the NearLink scanning capability, including starting and stopping scanning and subscribing to scanning results.

**Since**: 26.0.0

## Modules to Import

```typescript
import { scan } from '@kit.ConnectivityKit';
```

## scan.startScan

startScan(filters: ScanFilters[] | null, options?: ScanOptions): Promise&lt;void&gt;

Starts NearLink scanning. This API uses a promise to return the result. You need to call [scan.onDeviceFound](#scanondevicefound) to subscribe to the scanning results. After this API initiates scanning, the scanned device information is reported through the [scan.onDeviceFound](#scanondevicefound) callback. After the scanning is complete, you can call [scan.stopScan](#scanstopscan) to stop scanning.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| filters | [ScanFilters](#scanfilters)[] \| null | Yes | Filter criteria for NearLink advertising. Devices that meet the filter criteria will be reported. If the filter is not enabled, **null** is passed.<br>If this parameter is set to **null**, all discoverable NearLink devices nearby will be scanned. However, this method is not recommended as it may pick up unexpected devices and increase power consumption. |
| options | [ScanOptions](#scanoptions) | No | Scan options. The low power consumption mode is used by default. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100040 | Integer out of range. |
| 36100041 | Invalid address. |
| 36100042 | Empty array. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Perform scanning without using a filter.
try {
  scan.startScan(null).then(() => {
    console.info('start scan without filter success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}

// Perform scanning using a filter.
let scanFilter: scan.ScanFilters = {
  address: '11:22:33:44:AA:FF',
  deviceName: 'device name'
};
try {
  scan.startScan([scanFilter]).then(() => {
    console.info('start scan with filter success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## scan.stopScan

stopScan(): Promise&lt;void&gt;

Stops NearLink scanning. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  scan.stopScan().then(() => {
    console.info('stop scan success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## scan.onDeviceFound

onDeviceFound(callback: Callback\<ScanResults[]\>): void

Subscribes to NearLink scanning results. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&zwnj;\<&zwnj;&zwnj;[ScanResults](#scanresults)&zwnj;[]&zwnj;\> | Yes | Callback used to return a **ScanResults** object. By default, a random address is returned for the scanning result. If the app has the system permission **ohos.permission.GET_NEARLINK_PEER_MAC**, the actual device address is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**Example** 

```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onReceiveEvent:(data: scan.ScanResults[]) => void = (data: scan.ScanResults[]) => {
  console.info('scan result addr:' + data[0].address + 'name:' + data[0].deviceName);
};
try {
  scan.onDeviceFound(onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## scan.offDeviceFound

offDeviceFound(callback?: Callback\<ScanResults[]\>): void

Unsubscribes from NearLink scanning results. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;&zwnj;[ScanResults](#scanresults)&zwnj;[]&gt; | No | Callback used to return a **ScanResults** object. If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the event are unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**Example** 

```typescript
import { scan } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  scan.offDeviceFound();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ScanResults

Represents the scanning results.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Address of the device discovered. The address format is **11:22:33:AA:BB:FF**. |
| rssi | number | No | No | RSSI of the device discovered. The value range is [–128, +127], in dBm. The value **127** is invalid. |
| data | ArrayBuffer | No | No | Advertising packet data. |
| deviceName | string | No | No | Name of the device discovered. The value contains 0 to 30 characters. |
| isConnectable | boolean | No | No | Whether the discovered device is connectable. The value **true** indicates that the discovered device is connectable, and the value **false** indicates the opposite. |
| deviceClass | [nearlinkConstant.DeviceClass](js-apis-nearlink-constant.md#deviceclass) | No | Yes | Type of the device discovered. This field is not returned if the device advertising information does not carry the device type. |

## ScanFilters

Defines the scan filters

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | Yes | Device address. By default, this field is not used if it is not set. The address format is **11:22:33:AA:BB:FF**. |
| deviceName | string | No | Yes | Device name. The value contains 0 to 30 characters. By default, this field is not used if it is not set. |
| manufacturerId | number | No | Yes | Manufacturer ID. The value range is [1, 65535]. By default, this field is not used if it is not set. |
| manufacturerData | ArrayBuffer | No | Yes | Manufacturer data. By default, this field is not used if it is not set. **manufacturerId** must be set along with the field. |
| manufacturerDataMask | ArrayBuffer | No | Yes | Manufacturer data mask. By default, this field is not used if it is not set. This field must be set along with **manufacturerData**, and the lengths of the two fields must be the same. A bitwise AND operation is performed on the mask and manufacturer data to accurately match the specified bits in the manufacturer data. |
| rssi | number | No | Yes | RSSI threshold, in dBm. The value range is [–128, 127]. Broadcast packets whose RSSI is greater than or equal to this threshold will be filtered out. You are advised to set the threshold within the range of [–90, 20]. By default, the signal strength is not filtered if this parameter is not set. |

## ScanOptions

Represents the scan options.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| scanMode | [ScanMode](#scanmode) | No | Yes | Scan mode. The default value is **'SCAN_MODE_LOW_POWER'**. |
| duration | number | No | Yes | Scan duration, in seconds. The value range is [10, 60]. Full-time scanning is used by default. |

## ScanMode

Enumerates the scan modes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| SCAN_MODE_LOW_POWER | 0 | Low-power scan mode. The scan frequency and power consumption are low. This is the default value. |
| SCAN_MODE_BALANCED | 1 | Balanced scan mode. The scan frequency and power consumption are medium. |