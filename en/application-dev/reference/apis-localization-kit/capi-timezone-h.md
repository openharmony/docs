# timezone.h

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=635c96c73146bacf985d294d6e608687bbdae586 translatedAt=2026-07-30T09:54:00.520Z pushedAt=2026-07-31T01:22:45.881Z -->

## Overview

Provides the capability of obtaining time zone information.

**Header file**: <i18n/timezone.h>

**Library**: libohi18n.so

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Related module**: [i18n](capi-i18n.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DateTimeRule](capi-i18n-datetimerule.md) | DateTimeRule | Rule of time and date.|
| [InitialTimeZoneRule](capi-i18n-initialtimezonerule.md) | InitialTimeZoneRule | Start time zone rule.|
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md) | TimeArrayTimeZoneRule | Time zone rule defined by the start timestamp array.|
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md) | AnnualTimeZoneRule | Time zone rule that takes effect annually.|
| [TimeZoneRules](capi-i18n-timezonerules.md) | TimeZoneRules | Complete time zone rule.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md) | TimeZoneRuleQuery | Used to input the query information and receive the query result.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DateRuleType](#dateruletype) | DateRuleType | Enumerates the date rule types.|
| [TimeRuleType](#timeruletype) | TimeRuleType | Enumerates the time rule types.|

### Macros

| Name| Description|
| -- | -- |
| MAX_YEAR_IN_ANNUAL_TIMEZONE_RULE 0x7fffffff | Max year of the time zone rule that takes effect annually.<br>**Since**: 22|

### Functions

| Name| Description|
| -- | -- |
| [I18n_ErrorCode OH_i18n_GetTimeZoneRules(const char* timeZoneID, TimeZoneRules* rules)](#oh_i18n_gettimezonerules) | Obtains the complete time zone rule based on the time zone ID.|
| [I18n_ErrorCode OH_i18n_GetFirstStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfirststartfromtimearraytimezonerule) | Obtains the first effective time of the time zone rule based on TimeArrayTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetFirstStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfirststartfromannualtimezonerule) | Obtains the first effective time of the time zone rule based on AnnualTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetFinalStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfinalstartfromtimearraytimezonerule) | Obtains the last effective time of the time zone rule based on TimeArrayTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetFinalStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfinalstartfromannualtimezonerule) | Obtains the last effective time of the time zone rule based on TimeArrayTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetNextStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getnextstartfromtimearraytimezonerule) | Obtains the next effective time of the time zone rule after the base time based on TimeArrayTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetNextStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getnextstartfromannualtimezonerule) | Obtains the next effective time of the time zone rule after the base time based on AnnualTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetPrevStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getprevstartfromtimearraytimezonerule) | Obtains the last effective time of the time zone rule before the base time based on TimeArrayTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetPrevStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getprevstartfromannualtimezonerule) | Obtains the last effective time of the time zone rule before the base time based on AnnualTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetStartTimeAt(TimeArrayTimeZoneRule* rule, int32_t index, double* result)](#oh_i18n_getstarttimeat) | Obtains the start time of the time zone rule at the specified index based on TimeArrayTimeZoneRule.|
| [I18n_ErrorCode OH_i18n_GetStartInYear(AnnualTimeZoneRule* rule, int32_t year, TimeZoneRuleQuery* query)](#oh_i18n_getstartinyear) | Obtains the effective time of the time zone rule in a specified year based on AnnualTimeZoneRule.|

## Enum Description

### DateRuleType

```c
enum DateRuleType
```

**Description**

Enumerates the date rule types.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

| Value| Description|
| -- | -- |
| DOM = 0 | Day of the month. For example, October 16 in 2025 is the 16th day of October.|
| DOW = 1 | Week day of the month. For example, October 16 in 2025 is the third Thursday of October.|
| DOW_GEQ_DOM = 2 | First weekday after the specified day of the month. For example, October 16 in 2025 is the first Thursday after the 13th, 14th, or 15th day of October.|
| DOW_LEQ_DOM = 3 | Last weekday before the specified day of the month. For example, October 16 in 2025 is the last Thursday before the 20th day of October.|

### TimeRuleType

```c
enum TimeRuleType
```

**Description**

Enumerates the time rule types.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

| Value| Description|
| -- | -- |
| WALL_TIME = 0 | Local clock time (not subject to time zone offset).|
| STANDARD_TIME = 1 | Local standard time (not subject to DST offset).|
| UTC_TIME = 2 | World standard time (UTC time).|

## Function Description

### OH_i18n_GetTimeZoneRules()

```c
I18n_ErrorCode OH_i18n_GetTimeZoneRules(const char* timeZoneID, TimeZoneRules* rules)
```

**Description**

Obtains the complete time zone rule based on the time zone ID.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| const char* timeZoneID | Time zone ID, for example, **Asia/Shanghai**.|
| [TimeZoneRules](capi-i18n-timezonerules.md)* rules | Obtains the complete time zone rule [TimeZoneRules](capi-i18n-timezonerules.md) corresponding to the time zone ID.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetFirstStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFirstStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the first effective time of the time zone rule based on TimeArrayTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | Time zone rule [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md) defined by the start timestamp array.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetFirstStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFirstStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the first effective time of the time zone rule based on AnnualTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | Time zone rule [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md) that takes effect every year.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetFinalStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFinalStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the last effective time of the time zone rule based on TimeArrayTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | Time zone rule [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md) defined by the start timestamp array.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetFinalStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFinalStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the last effective time of the time zone rule based on TimeArrayTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | Time zone rule [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md) that takes effect every year.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetNextStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetNextStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the next effective time of the time zone rule after the base time based on TimeArrayTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | Time zone rule [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md) defined by the start timestamp array.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetNextStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetNextStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the next effective time of the time zone rule after the base time based on AnnualTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | Time zone rule [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md) that takes effect every year.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetPrevStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetPrevStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the last effective time of the time zone rule before the base time based on TimeArrayTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | Time zone rule [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md) defined by the start timestamp array.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetPrevStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetPrevStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**Description**

Obtains the last effective time of the time zone rule before the base time based on AnnualTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | Time zone rule [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md) that takes effect every year.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetStartTimeAt()

```c
I18n_ErrorCode OH_i18n_GetStartTimeAt(TimeArrayTimeZoneRule* rule, int32_t index, double* result)
```

**Description**

Obtains the start time of the time zone rule at the specified index based on TimeArrayTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | Time zone rule [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md) defined by the start timestamp array.|
| int32_t index | Index of the start time. Value range: [0, rule.numStartTimes - 1]. |
| double* result | Time when the rule takes effect, in milliseconds. The value is Unix timestamp. |

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|

### OH_i18n_GetStartInYear()

```c
I18n_ErrorCode OH_i18n_GetStartInYear(AnnualTimeZoneRule* rule, int32_t year, TimeZoneRuleQuery* query)
```

**Description**

Obtains the effective time of the time zone rule in a specified year based on AnnualTimeZoneRule.

**System capability**: SystemCapability.Global.I18n

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | Time zone rule [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md) that takes effect every year.|
| int32_t year | Year to be queried.|
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | Used to input the query information and receive the query result.|

**Returns**

| Type| Description|
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | **0**: Success.<br>         **8900001**: Invalid input parameters.<br>         **8900050**: Unexpected error, for example, memory error.|