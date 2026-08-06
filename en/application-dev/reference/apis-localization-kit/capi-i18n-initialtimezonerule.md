# InitialTimeZoneRule

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=635c96c73146bacf985d294d6e608687bbdae586 translatedAt=2026-07-30T09:53:32.065Z pushedAt=2026-07-31T01:23:14.634Z -->

```c
typedef struct InitialTimeZoneRule {...} InitialTimeZoneRule
```

## Overview

Start time zone rule.

**Since**: 22

**Related module**: [i18n](capi-i18n.md)

**Header file**: [timezone.h](capi-timezone-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t rawOffset | Raw offset of the time zone, in milliseconds. |
| int32_t dstSavings | Daylight saving time offset, in milliseconds. |