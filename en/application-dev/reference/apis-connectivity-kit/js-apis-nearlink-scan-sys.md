# @ohos.nearlink.scan (NearLink Scanning Capability) (System API)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @CCCZKing-->
<!--Designer: @lilong32; @CCCZKing-->
<!--Tester: @zhangjiaji111-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=af1955eee0928cd91182a5d17e143d0faec0b2d7 translatedAt=2026-08-12T11:29:31.102Z pushedAt=2026-08-14T11:42:02.109Z -->

This module provides the NearLink scanning capability.

**Since**: 26.0.0

> **NOTE**
>
> The APIs provided by this module are system APIs.

## Modules to Import

```typescript
import { scan } from '@kit.ConnectivityKit';
```

## ScanMode

Enumerates the scan modes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Communication.NearLink.Base

| Name | Value | Description |
| -------- | -------- | -------- |
| SCAN_MODE_LOW_LATENCY | 2 | High-power scan mode. The scan frequency is high, and the power consumption is high. |