# TimeZoneRules

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=635c96c73146bacf985d294d6e608687bbdae586 translatedAt=2026-07-30T09:53:23.504Z pushedAt=2026-07-31T01:23:03.402Z -->

```c
typedef struct TimeZoneRules {...} TimeZoneRules
```

## Overview

A complete time zone rule includes the start time zone rule, time zone rule defined by the start timestamp array, and time zone rule that takes effect every year. It can comprehensively describe both the historical and future rules of a time zone.

**Since**: 22

**Related module**: [i18n](capi-i18n.md)

**Header file**: [timezone.h](capi-timezone-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [InitialTimeZoneRule](capi-i18n-initialtimezonerule.md) initial | Start time zone rule.|
| [TimeArrayTimeZoneRule*](capi-i18n-timearraytimezonerule.md) timeArrayRules | Time zone rule array defined by the start timestamp array.|
| [AnnualTimeZoneRule*](capi-i18n-annualtimezonerule.md) annualRules | Time zone rule array that takes effect annually.|
| size_t numTimeArrayRules | Size of the time zone rule array defined by the start timestamp array.|
| size_t numAnnualRules | Size of the time zone rule array that takes effect annually.|