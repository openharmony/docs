# TimeZoneRules

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

```c
typedef struct TimeZoneRules {...} TimeZoneRules
```

## 概述

完整的时区规则，包括起始时区规则、起始时间戳数组定义的时区规则和每年生效的时区规则，能够全面描述时区的历史和未来规则。

**起始版本：** 22

**相关模块：** [i18n](capi-i18n.md)

**所在头文件：** [timezone.h](capi-timezone-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [InitialTimeZoneRule](capi-i18n-initialtimezonerule.md) initial | 起始时区规则。 |
| [TimeArrayTimeZoneRule*](capi-i18n-timearraytimezonerule.md) timeArrayRules | 起始时间戳数组定义的时区规则数组。 |
| [AnnualTimeZoneRule*](capi-i18n-annualtimezonerule.md) annualRules | 每年生效的时区规则数组。 |
| size_t numTimeArrayRules | 起始时间戳数组定义的时区规则数组的大小。 |
| size_t numAnnualRules | 每年生效的时区规则数组的大小。 |


