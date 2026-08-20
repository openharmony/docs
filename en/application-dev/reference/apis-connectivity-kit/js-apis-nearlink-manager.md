# @ohos.nearlink.manager (Basic NearLink Management Capability)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=aa9545020692baaf11004432a3eb3c2a031071bf translatedAt=2026-08-17T08:49:12.741Z pushedAt=2026-08-18T12:03:24.668Z -->

This module provides basic NearLink management capabilities, including checking whether NearLink is supported, obtaining local device information, managing the NearLink status, and subscribing to status change events.

**Since**: 26.0.0

## Modules to Import

```typescript
import { manager } from '@kit.ConnectivityKit';
```

## manager.getState

getState(): NearlinkState

Queries the NearLink status.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| [NearlinkState](#nearlinkstate) | NearLink status. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let state: manager.NearlinkState = manager.getState();
  console.info('state:' + JSON.stringify(state));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.isNearLinkSupported

isNearLinkSupported(): boolean

Checks whether the current device supports NearLink.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| boolean | Whether the current device supports NearLink. The value **true** indicates that the device supports NearLink, and **false** indicates the opposite. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isSupported: boolean = manager.isNearLinkSupported();
  if (isSupported) {
    console.info('NearLink is supported on this device.');
  } else {
    console.info('NearLink is not supported on this device.');
  }
} catch (err) {
  console.error('Error occurred: ' + (err as BusinessError).code + ', ' + (err as BusinessError).message);
}
```

## manager.getLocalName

getLocalName(): string

Queries the NearLink name on the local device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| string | NearLink name on the local device. The value contains a maximum of 30 characters. |

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
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let name: string = manager.getLocalName();
  console.info('name:' + JSON.stringify(name));
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.getPairedDevices

getPairedDevices(): string[]

Obtains the devices paired with the current device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.ACCESS_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value** 

| Type | Description |
| -------- | -------- |
| string[] | List of paired device addresses. |

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
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let pairedDevices: string[] = manager.getPairedDevices();
  if (pairedDevices.length > 0) {
        console.info('getPairedDevices return: ' + JSON.stringify(pairedDevices));
    } else {
        console.info('No Paired Devices found.');
    }
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.onStateChange

onStateChange(callback: Callback&lt;NearlinkState&gt;): void

Subscribes to the NearLink status change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[NearlinkState](#nearlinkstate)&gt; | Yes | Callback used to return the NearLink status. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let callback: Callback<manager.NearlinkState> = (data: manager.NearlinkState) => {
  if (data === manager.NearlinkState.STATE_TURNING_ON) {
    console.info('nearlink STATE_TURNING_ON');
  } else if (data === manager.NearlinkState.STATE_ON) {
    console.info('nearlink STATE_ON');
  } else if (data === manager.NearlinkState.STATE_TURNING_OFF) {
    console.info('nearlink STATE_TURNING_OFF');
  } else if (data === manager.NearlinkState.STATE_OFF) {
    console.info('nearlink STATE_OFF');
  }
};
try {
  manager.onStateChange(callback);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.offStateChange

offStateChange(callback?: Callback&lt;NearlinkState&gt;): void

Unsubscribes from the NearLink status change event. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters** 

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;[NearlinkState](#nearlinkstate)&gt; | No | Callback used to return the NearLink status.<br>If this parameter is specified, the current callback is unregistered. If this parameter is not specified, all callbacks corresponding to the event are unregistered. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example** 

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  manager.offStateChange();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## NearlinkState

Enumerated the NearLink statuses.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| STATE_TURNING_ON | 0 | NearLink is being turned on. |
| STATE_ON | 1 | NearLink is turned on. |
| STATE_TURNING_OFF | 2 | NearLink is being turned off. |
| STATE_OFF | 3 | NearLink is turned off. |