# @ohos.nearlink.constant (NearLink Common Constants) (System API)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=02fce05de566ce8f56f53550eea84cf8ca0dfad8 translatedAt=2026-08-17T08:47:43.806Z pushedAt=2026-08-17T11:58:14.278Z -->

This module provides definitions of common constants for NearLink communication, including the device pairing status, device connection status, and device type.

**Since**: 26.0.0

> **NOTE**
>
> The APIs provided by this module are system APIs.

## Modules to Import

```typescript
import { nearlinkConstant } from '@kit.ConnectivityKit';
```

## ConnectionInterval

Enumerates the connection intervals. A smaller interval indicates a lower latency, higher throughput, but higher power consumption. A larger interval indicates lower power consumption but higher latency. The high-speed mode is suitable for scenarios that require high throughput and low latency, while the low-speed mode is suitable for scenarios that are sensitive to power consumption.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API:** This is a system API.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| HIGH_SPEED_INTERVAL_4_5 | 0 | Connection interval of 4.5 ms. |
| HIGH_SPEED_INTERVAL_4_875 | 1 | Connection interval of 4.875 ms. |
| MID_SPEED_INTERVAL_11_25 | 2 | Connection interval of 11.25 ms. |
| MID_SPEED_INTERVAL_15 | 3 | Connection interval of 15 ms. |
| MID_SPEED_INTERVAL_50 | 4 | Connection interval of 50 ms. |
| LOW_SPEED_INTERVAL_100 | 5 | Connection interval of 100 ms. |
| LOW_SPEED_INTERVAL_150 | 6 | Connection interval of 150 ms. |
| LOW_SPEED_INTERVAL_200 | 7 | Connection interval of 200 ms. |
| LOW_SPEED_INTERVAL_300 | 8 | Connection interval of 300 ms. |
| LOW_SPEED_INTERVAL_500 | 9 | Connection interval of 500 ms. |