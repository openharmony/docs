# AnnualTimeZoneRule

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=635c96c73146bacf985d294d6e608687bbdae586 translatedAt=2026-07-30T09:54:39.243Z pushedAt=2026-07-31T01:23:18.297Z -->

```c
typedef struct AnnualTimeZoneRule {...} AnnualTimeZoneRule
```

## Overview

Time zone rule that takes effect annually.

**Since**: 22

**Related module**: [i18n](capi-i18n.md)

**Header file**: [timezone.h](capi-timezone-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* name | Name of the time zone rule.|
| int32_t startYear | Start year when the time zone rule takes effect.|
| int32_t endYear | End year when the time zone rule takes effect.|
| int32_t rawOffset | Raw offset of the time zone, in milliseconds. |
| int32_t dstSavings | Daylight saving time offset, in milliseconds. |
| [DateTimeRule](capi-i18n-datetimerule.md) dateTimeRule | Rule of time and date.|