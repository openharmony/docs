# timezone.h

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

## 概述

提供获取时区信息的能力。

**引用文件：** <i18n/timezone.h>

**库：** libohi18n.so

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**相关模块：** [i18n](capi-i18n.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [DateTimeRule](capi-i18n-datetimerule.md) | DateTimeRule | 时间日期规则。 |
| [InitialTimeZoneRule](capi-i18n-initialtimezonerule.md) | InitialTimeZoneRule | 起始时区规则。 |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md) | TimeArrayTimeZoneRule | 起始时间戳数组定义的时区规则。 |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md) | AnnualTimeZoneRule | 每年生效的时区规则。 |
| [TimeZoneRules](capi-i18n-timezonerules.md) | TimeZoneRules | 完整的时区规则。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md) | TimeZoneRuleQuery | 用于传入查询的信息，并接收查询的结果。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [DateRuleType](#dateruletype) | DateRuleType | 日期规则类型的枚举。 |
| [TimeRuleType](#timeruletype) | TimeRuleType | 时间规则类型的枚举。 |

### 宏定义

| 名称 | 描述 |
| -- | -- |
| MAX_YEAR_IN_ANNUAL_TIMEZONE_RULE 0x7fffffff | 每年生效时区规则的年份最大值。<br>**起始版本：** 22 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [I18n_ErrorCode OH_i18n_GetTimeZoneRules(const char* timeZoneID, TimeZoneRules* rules)](#oh_i18n_gettimezonerules) | 通过时区ID，获取完整的时区规则。 |
| [I18n_ErrorCode OH_i18n_GetFirstStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfirststartfromtimearraytimezonerule) | 根据TimeArrayTimeZoneRule，获取时区规则的首次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetFirstStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfirststartfromannualtimezonerule) | 根据AnnualTimeZoneRule，获取时区规则的首次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetFinalStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfinalstartfromtimearraytimezonerule) | 根据TimeArrayTimeZoneRule，获取时区规则的最后一次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetFinalStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getfinalstartfromannualtimezonerule) | 根据AnnualTimeZoneRule，获取时区规则的最后一次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetNextStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getnextstartfromtimearraytimezonerule) | 根据TimeArrayTimeZoneRule，获取时区规则在基准时间之后的下一次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetNextStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getnextstartfromannualtimezonerule) | 根据AnnualTimeZoneRule，获取时区规则在基准时间之后的下一次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetPrevStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getprevstartfromtimearraytimezonerule) | 根据TimeArrayTimeZoneRule，获取时区规则在基准时间之前的上一次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetPrevStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)](#oh_i18n_getprevstartfromannualtimezonerule) | 根据AnnualTimeZoneRule，获取时区规则在基准时间之前的上一次生效时间。 |
| [I18n_ErrorCode OH_i18n_GetStartTimeAt(TimeArrayTimeZoneRule* rule, int32_t index, double* result)](#oh_i18n_getstarttimeat) | 根据TimeArrayTimeZoneRule，获取时区规则指定索引的起始时间。 |
| [I18n_ErrorCode OH_i18n_GetStartInYear(AnnualTimeZoneRule* rule, int32_t year, TimeZoneRuleQuery* query)](#oh_i18n_getstartinyear) | 根据AnnualTimeZoneRule，获取时区规则在指定年份的生效时间。 |

## 枚举类型说明

### DateRuleType

```c
enum DateRuleType
```

**描述**

日期规则类型的枚举。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| DOM = 0 | 当月的第几天，以2025年为例，十月十六日为：十月的第十六天。 |
| DOW = 1 | 当月的第几个星期几，以2025年为例，十月十六日为：十月的第三个星期四。 |
| DOW_GEQ_DOM = 2 | 当月第几天之后的第一个星期几，以2025年为例，十月十六日为：十月第十三天/十四天/十五天之后的第一个星期四。 |
| DOW_LEQ_DOM = 3 | 当月第几天之前的最后一个星期几，以2025年为例，十月十六日为：十月第二十天之前的最后一个星期四。 |

### TimeRuleType

```c
enum TimeRuleType
```

**描述**

时间规则类型的枚举。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| WALL_TIME = 0 | 本地时钟时间（不考虑时区偏移）。 |
| STANDARD_TIME = 1 | 本地标准时间（不考虑夏令时偏移）。 |
| UTC_TIME = 2 | 世界标准时间（UTC时间）。 |


## 函数说明

### OH_i18n_GetTimeZoneRules()

```c
I18n_ErrorCode OH_i18n_GetTimeZoneRules(const char* timeZoneID, TimeZoneRules* rules)
```

**描述**

通过时区ID，获取完整的时区规则。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* timeZoneID | 时区ID，例如“Asia/Shanghai”。 |
| [TimeZoneRules](capi-i18n-timezonerules.md)* rules | 与时区ID对应的完整时区规则[TimeZoneRules](capi-i18n-timezonerules.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetFirstStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFirstStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据TimeArrayTimeZoneRule，获取时区规则的首次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | 起始时间戳数组定义的时区规则[TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetFirstStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFirstStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据AnnualTimeZoneRule，获取时区规则的首次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | 每年生效的时区规则[AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetFinalStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFinalStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据TimeArrayTimeZoneRule，获取时区规则的最后一次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | 起始时间戳数组定义的时区规则[TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetFinalStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetFinalStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据AnnualTimeZoneRule，获取时区规则的最后一次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | 每年生效的时区规则[AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetNextStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetNextStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据TimeArrayTimeZoneRule，获取时区规则在基准时间之后的下一次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | 起始时间戳数组定义的时区规则[TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetNextStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetNextStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据AnnualTimeZoneRule，获取时区规则在基准时间之后的下一次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | 每年生效的时区规则[AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetPrevStartFromTimeArrayTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetPrevStartFromTimeArrayTimeZoneRule(TimeArrayTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据TimeArrayTimeZoneRule，获取时区规则在基准时间之前的上一次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | 起始时间戳数组定义的时区规则[TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetPrevStartFromAnnualTimeZoneRule()

```c
I18n_ErrorCode OH_i18n_GetPrevStartFromAnnualTimeZoneRule(AnnualTimeZoneRule* rule, TimeZoneRuleQuery* query)
```

**描述**

根据AnnualTimeZoneRule，获取时区规则在基准时间之前的上一次生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | 每年生效的时区规则[AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetStartTimeAt()

```c
I18n_ErrorCode OH_i18n_GetStartTimeAt(TimeArrayTimeZoneRule* rule, int32_t index, double* result)
```

**描述**

根据TimeArrayTimeZoneRule，获取时区规则指定索引的起始时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)* rule | 起始时间戳数组定义的时区规则[TimeArrayTimeZoneRule](capi-i18n-timearraytimezonerule.md)。 |
| int32_t index | 起始时间的索引。取值范围：[0, rule.numStartTimes - 1]。 |
| double* result | 规则生效的起始时间，单位为毫秒（ms），采用Unix时间戳格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |

### OH_i18n_GetStartInYear()

```c
I18n_ErrorCode OH_i18n_GetStartInYear(AnnualTimeZoneRule* rule, int32_t year, TimeZoneRuleQuery* query)
```

**描述**

根据AnnualTimeZoneRule，获取时区规则在指定年份的生效时间。

**系统能力：** SystemCapability.Global.I18n

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)* rule | 每年生效的时区规则[AnnualTimeZoneRule](capi-i18n-annualtimezonerule.md)。 |
| int32_t year | 查询的年份。 |
| [TimeZoneRuleQuery](capi-i18n-timezonerulequery.md)* query | 用于传入查询的信息，并接收查询的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [I18n_ErrorCode](capi-errorcode-h.md#i18n_errorcode) | 0 - 成功。<br>         8900001 - 传入参数无效。<br>         8900050 - 预期之外的错误，例如内存错误。 |


