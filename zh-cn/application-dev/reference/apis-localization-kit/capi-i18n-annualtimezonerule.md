# AnnualTimeZoneRule

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

```c
typedef struct AnnualTimeZoneRule {...} AnnualTimeZoneRule
```

## 概述

每年生效的时区规则。

**起始版本：** 22

**相关模块：** [i18n](capi-i18n.md)

**所在头文件：** [timezone.h](capi-timezone-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* name | 时区规则的名称。 |
| int32_t startYear | 时区规则生效的起始年份。 |
| int32_t endYear | 时区规则生效的终止年份。 |
| int32_t rawOffset | 时区的原始偏移量，单位为毫秒（ms）。 |
| int32_t dstSavings | 夏令时的偏移量，单位为毫秒（ms）。 |
| [DateTimeRule](capi-i18n-datetimerule.md) dateTimeRule | 时间日期规则。 |


