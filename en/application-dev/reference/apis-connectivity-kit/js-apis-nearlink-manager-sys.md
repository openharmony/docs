# @ohos.nearlink.manager (Basic NearLink Management Capability) (System API)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=aa9545020692baaf11004432a3eb3c2a031071bf translatedAt=2026-08-17T08:49:08.929Z pushedAt=2026-08-18T12:03:22.652Z -->

This module provides basic NearLink management capabilities, including enabling or disabling NearLink, obtaining the MAC address of the local device, and setting the connection mode.

**Since**: 26.0.0

> **NOTE**
>
> The APIs provided by this module are system APIs.

## Modules to Import

```typescript
import { manager } from '@kit.ConnectivityKit';
```

## manager.enable

enable(): void

Enables NearLink.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 203 | EDM denied. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  manager.enable();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.disable

disable(): void

Disables NearLink.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  manager.disable();
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.getLocalAddress

getLocalAddress(): string

Queries the MAC address of the local device.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.GET_NEARLINK_LOCAL_MAC

**System capability:** SystemCapability.Communication.NearLink.Base

**Return value**

| Type | Description |
| -------- | -------- |
| string | Local MAC address, for example, **'11:22:33:AA:BB:FF'**. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let addr: string = manager.getLocalAddress();
  console.info('getLocalAddress addr:' + addr);
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## manager.factoryReset

factoryReset(): Promise&lt;void&gt;

Restores a device to its factory settings. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions:** ohos.permission.MANAGE_NEARLINK

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
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  manager.factoryReset().then(() => {
    console.info('factoryReset success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ConnectionMode

Enumerates the connection modes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| SLE_MODE_UNCONNECTABLE | 0 | The device cannot be connected. |
| SLE_MODE_CONNECTABLE | 1 | The device can be connected. |

## manager.setConnectionMode

setConnectionMode(mode: ConnectionMode, duration: number): Promise&lt;void&gt;

Sets the connection mode. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**Required permissions:** ohos.permission.ACCESS_NEARLINK and ohos.permission.MANAGE_NEARLINK

**System capability:** SystemCapability.Communication.NearLink.Base

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| mode | [ConnectionMode](#connectionmode) | Yes | Connection mode to be set. |
| duration | number | Yes | Duration of the mode to set, in seconds. The value must be an integer greater than or equal to 0. The value **0** indicates no time limit. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [General Error Codes](../errorcode-universal.md) and [NearLink Error Codes](errorcode-nearlink-service.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications are not allowed to use system APIs. |
| 801 | Capability not supported because the chip does not support it. |
| 36100003 | NearLink disabled. |
| 36100040 | Integer out of range. |
| 36100099 | Operation failed. |

**Example**

```typescript
import { manager } from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

try {
  let mode: manager.ConnectionMode = manager.ConnectionMode.SLE_MODE_CONNECTABLE;
  let duration: number = 100;
  manager.setConnectionMode(mode, duration).then(() => {
    console.info('setConnectionMode success');
  }).catch((err: BusinessError) => {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
  });
} catch (err) {
  console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```