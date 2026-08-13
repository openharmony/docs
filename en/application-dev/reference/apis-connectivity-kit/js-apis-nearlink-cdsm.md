# @ohos.nearlink.cdsm (CDSM Capability)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8a03c39231c24a89e7d2329d21e5c175c46ce77e translatedAt=2026-08-12T11:27:54.714Z pushedAt=2026-08-13T10:31:51.409Z -->

This module provides the coordinated devices set management (CDSM) capability for NearLink, including querying and subscribing to the coordinated devices set information of NearLink.

**Since**: 26.0.0

## Modules to Import

```typescript
import { cdsm } from '@kit.ConnectivityKit';
```

## cdsm.createCdsmClient

createCdsmClient(address: string): CdsmClient

Creates a CDSM client instance.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| address | string | Yes | Address of a member device in the paired and connected coordinated devices set. The address format is **11:22:33:AA:BB:FF**. |

**Return value** 

| Type | Description |
| -------- | -------- |
| [CdsmClient](#cdsmclient) | CDSM client instance. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100041 | Invalid address. |
| 36100050 | Coordinated Devices Set Management not supported. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Address of a member device in the paired and connected coordinated devices set
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr);
  console.info('client: ' + JSON.stringify(client));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## CdsmClient

Obtains the coordinated devices set information of a remote device. Before using this method, you need to call cdsm.createCdsmClient to create a CdsmClient instance.

An app only needs to create one instance for a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

### getCdsmInfo

getCdsmInfo(): CdsmInfo

Queries information about the coordinated devices set of a remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [CdsmInfo](#cdsminfo) | Information about the coordinated devices set of a remote device. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let addr: string = '00:11:22:33:AA:FF'; // Address of a member device in the paired and connected coordinated devices set
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr); // An app only needs to create one instance for a remote device.
let cdsmInformation: cdsm.CdsmInfo = client.getCdsmInfo();
  console.info('cdsmInformation:' + JSON.stringify(cdsmInformation));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### onCdsmInfoChange

onCdsmInfoChange(callback: Callback&lt;CdsmInfo&gt;): void

Subscribes to the CDSM information change event. This API uses an asynchronous callback to return the result.

The app must have the **ohos.permission.ACCESS_NEARLINK** permission to receive this event.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[CdsmInfo](#cdsminfo)&gt; | Yes | Callback used to return the CDSM information. |

**Example** 

```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<cdsm.CdsmInfo> = (data: cdsm.CdsmInfo) => {
  console.info('CdsmInfo:' + JSON.stringify(data));
};

let addr: string = '00:11:22:33:AA:FF'; // Address of a member device in the paired and connected coordinated devices set
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr); // An app only needs to create one instance for a remote device.
  client.onCdsmInfoChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### offCdsmInfoChange

offCdsmInfoChange(callback?: Callback&lt;CdsmInfo&gt;): void

Unsubscribes from the CDSM information change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[CdsmInfo](#cdsminfo)&gt; | No | Callback used to return the CDSM information.<br/>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks used to listen for CDSM information change events are unregistered. |

**Example** 

```typescript
import { cdsm } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<cdsm.CdsmInfo> = (data: cdsm.CdsmInfo) => {
  console.info('CdsmInfo:' + JSON.stringify(data));
};

let addr: string = '00:11:22:33:AA:FF'; // Address of a member device in the paired and connected coordinated devices set
let client: cdsm.CdsmClient;
try {
  client = cdsm.createCdsmClient(addr); // An app only needs to create one instance for a remote device.
  client.onCdsmInfoChange(callback);
  client.offCdsmInfoChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## CdsmInfo

Represents the CDSM information.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| members | [CdsmMemberInfo](#cdsmmemberinfo)[] | No | No | Information about member devices in the coordinated devices set. |

## CdsmMemberInfo

Represents the information about member devices in the coordinated devices set.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| address | string | No | No | Member device address. |
| state | [CdsmConnectionState](#cdsmconnectionstate) | No | No | Member device connection state. |

## CdsmConnectionState

Enumerates the connection states between the coordinated devices set and the remote device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| DISCONNECTED | 0 | Disconnected. |
| CONNECTED | 1 | Connected. |