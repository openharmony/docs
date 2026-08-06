# DateTimeRule

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=635c96c73146bacf985d294d6e608687bbdae586 translatedAt=2026-07-30T09:53:30.093Z pushedAt=2026-07-31T01:23:16.367Z -->

```c
typedef struct DateTimeRule {...} DateTimeRule
```

## Overview

Rule of time and date.

**Since**: 22

**Related module**: [i18n](capi-i18n.md)

**Header file**: [timezone.h](capi-timezone-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t month | Month. The month starts from **0**, indicating January. |
| int32_t dayOfMonth | Day of the month.|
| int32_t dayOfWeek | Day of the week.|
| int32_t weekInMonth | Week of the month.|
| int32_t millisInDay | Millisecond value from 00:00 on the current day to the current time.|
| [DateRuleType](capi-timezone-h.md#dateruletype) dateRuleType | Date rule type.|
| [TimeRuleType](capi-timezone-h.md#timeruletype) timeRuleType | Time rule type.|