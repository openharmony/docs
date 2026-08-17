# @ohos.nearlink.constant (NearLink Common Constants) (System API)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=777cd887ad4c87d5f44c1f9d04d5ef57d4f4c52f translatedAt=2026-08-12T11:27:44.149Z pushedAt=2026-08-14T11:26:14.031Z -->

This module provides definitions of common constants.

**Since**: 26.0.0

> **NOTE**
>
> The APIs provided by this module are system APIs.

## Modules to Import

```typescript
import { nearlinkConstant } from '@kit.ConnectivityKit';
```

## ConnectionInterval

Enumerates the connection intervals.

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