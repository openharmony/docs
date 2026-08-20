# @ohos.nearlink.advertising (NearLink Advertising Capability)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=1f7ebf6194dca265f1a8eeefc330905f60a6cb97 translatedAt=2026-08-17T08:48:24.949Z pushedAt=2026-08-18T11:10:11.754Z -->

This module provides Nearlink advertising functions, including starting and stopping advertising as well as subscribing to the advertising status.

**Since**: 26.0.0

## Modules to Import

```typescript
import { advertising } from '@kit.ConnectivityKit';
```

## AdvertisingParams

Enumerates the advertising parameters.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| advertisingSettings | [AdvertisingSettings](#advertisingsettings) | No | No | Advertising settings. |
| advertisingData | [AdvertisingData](#advertisingdata) | No | No | Advertising data packet. |

## AdvertisingSettings

Represents the advertising settings.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| interval | number | No | Yes | Advertising interval, in slots. The value ranges from 160 to 16777215, and the default value is **5000**. One slot equals to 0.125 ms. For example, 5000 slots equal to 625 ms. |
| power | [TxPowerMode](#txpowermode) | No | Yes | Advertising transmission power. If this parameter is not specified, the default value **ADV_TX_POWER_LOW** is used. |
| isConnectable | boolean | No | Yes | Whether advertising is connectable. **true**: Advertising is connectable. **false**: Advertising is not connectable. The default value is **true**. |

## AdvertisingData

Represents an advertising data packet.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuids | string[] | No | Yes | Service UUIDs. A UUID must contain 36 characters, including 32 hexadecimal digits and four hyphens (-). By default, this field is not used if not set. |
| manufacturerData | [ManufacturerData](#manufacturerdata)[] | No | Yes | Manufacturer data. By default, this field is not carried if it is not set. |
| serviceData | [ServiceData](#servicedata)[] | No | Yes | Service data. By default, this field is not carried if it is not set. |
| includeDeviceName | boolean | No | Yes | Whether the advertising data contains the local device name. **true**: **yes**. false: no. The default value is **false**. |

## ManufacturerData

Represents the manufacturer data.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| manufacturerId | number | No | No | Manufacturer ID. The value range is [1, 65535]. |
| manufacturerData | ArrayBuffer | No | No | Manufacturer data. |

## ServiceData

Represents the service data.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | No | No | Service UUID. A UUID must contain 36 characters, including 32 hexadecimal digits and four hyphens (-). |
| serviceData | ArrayBuffer | No | No | Service data. |

## AdvertisingStateChangeInfo

Represents the advertising state change information.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| advertisingId | number | No | No | Advertising ID. The value range is [0, 255]. |
| state | [AdvertisingState](#advertisingstate) | No | No | Advertising state. |

## TxPowerMode

Enumerates the advertising transmission power modes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| ADV_TX_POWER_LOW | 1 | Low power consumption mode. |
| ADV_TX_POWER_MEDIUM | 2 | Medium power consumption mode. |
| ADV_TX_POWER_HIGH | 3 | High power consumption mode. |

## AdvertisingState

Enumerates the advertising states.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| STARTED | 1 | Advertising started. |
| STOPPED | 2 | Advertising stopped. |

## advertising.startAdvertising

startAdvertising(advertisingParams: AdvertisingParams): Promise&lt;number&gt;

Starts NearLink advertising. This API uses a promise to return the result. This API is applicable to scenarios where the local device capabilities or data needs to be advertised, such as device discovery and device information advertising. You can use [advertising.onAdvertisingStateChange](#advertisingonadvertisingstatechange) to monitor the advertising status.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| advertisingParams | [AdvertisingParams](#advertisingparams) | Yes | Advertising parameters. |

**Return value** 

| Type | Description |
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the advertising ID. The advertising ID is a unique ID randomly allocated. The value range is [0, 255]. Similar to [advertising.stopAdvertising](#advertisingstopadvertising) and [AdvertisingStateChangeInfo](#advertisingstatechangeinfo).advertisingId, this ID can be used to distinguish the current advertising instance. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100040 | Integer out of range. |
| 36100043 | Invalid UUID. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
console.info('manufactureValueBuffer = ' + JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = ' + JSON.stringify(serviceValueBuffer));
let setting: advertising.AdvertisingSettings = {
  interval:5000,
  power:advertising.TxPowerMode.ADV_TX_POWER_LOW
};
let manufactureDataUnit: advertising.ManufacturerData = {
  manufacturerId:4567,
  manufacturerData:manufactureValueBuffer.buffer
};
let serviceDataUnit: advertising.ServiceData = {
  serviceUuid:'FFFFFFFF-1234-5678-ABCD-000000001234',
  serviceData:serviceValueBuffer.buffer
};
let advData: advertising.AdvertisingData = {
  serviceUuids:['FFFFFFFF-1234-5678-ABCD-000000001234'],
  manufacturerData:[manufactureDataUnit],
  serviceData:[serviceDataUnit]
};
let advertisingParams: advertising.AdvertisingParams = {
  advertisingSettings: setting,
  advertisingData: advData
};
let advId = -1;
try {
  advertising.startAdvertising(advertisingParams).then((advertisingId:number) => {
    advId = advertisingId;
    console.info('advertising id:' + JSON.stringify(advId));
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## advertising.stopAdvertising

stopAdvertising(advertisingId: number): Promise&lt;void&gt;

Stops NearLink advertising. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| advertisingId | number | Yes | Advertising ID, which is obtained when advertising is started. The value range is [0, 255]. |

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
| 36100040 | Invalid advertising ID. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let advId: number = 1; // advId is obtained when advertising is started. For details, please refer to return values of the startAdvertising API.
  advertising.stopAdvertising(advId).then(() => {
    console.info('stop advertising success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## advertising.onAdvertisingStateChange

onAdvertisingStateChange(callback: Callback&lt;AdvertisingStateChangeInfo&gt;): void

Subscribes to the NearLink advertising state change event. This API uses an asynchronous callback to return the result. When [advertising.startAdvertising](#advertisingstartadvertising) is called to start advertising or [advertising.stopAdvertising](#advertisingstopadvertising) is called to stop advertising, the callback is triggered to return the corresponding advertising ID and advertising status. This API must be used in pairs with [advertising.offAdvertisingStateChange](#advertisingoffadvertisingstatechange).

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo)&gt; | Yes | Callback used to return the advertising state change information. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**Example** 

```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let onReceiveEvent:(data: advertising.AdvertisingStateChangeInfo) => void =
  (data: advertising.AdvertisingStateChangeInfo) => {
  console.info('advertisingId:' + data.advertisingId);
  console.info('advertisingState:' + data.state);
};
try {
  advertising.onAdvertisingStateChange(onReceiveEvent);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## advertising.offAdvertisingStateChange

offAdvertisingStateChange(callback?: Callback&lt;AdvertisingStateChangeInfo&gt;): void

Unsubscribes from the NearLink advertising state change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[AdvertisingStateChangeInfo](#advertisingstatechangeinfo)&gt; | No | Callback used to return the advertising state change information.<br>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the event are unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |

**Example** 

```typescript
import { advertising } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  advertising.offAdvertisingStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```