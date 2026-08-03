# TimeZoneRuleQuery

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=635c96c73146bacf985d294d6e608687bbdae586 translatedAt=2026-07-30T09:53:30.528Z pushedAt=2026-07-31T01:23:08.630Z -->

```c
typedef struct TimeZoneRuleQuery {...} TimeZoneRuleQuery
```

## Overview

Used to input the query information and receive the query result.

**Since**: 22

**Related module**: [i18n](capi-i18n.md)

**Header file**: [timezone.h](capi-timezone-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| double base | Reference time for the query, in milliseconds. The value is Unix timestamp. |
| int32_t prevRawOffset | Previous raw offset of the time zone, in milliseconds. |
| int32_t prevDSTSavings | Previous daylight saving time offset, in milliseconds. |
| bool inclusive | Whether the query result contains the base time. The value **true** indicates that the query result contains the base time. The value **false** indicates the opposite.|
| double result | Query result, in milliseconds. The value is Unix timestamp. |