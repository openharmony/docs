# DateTimeRule

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

```c
typedef struct DateTimeRule {...} DateTimeRule
```

## 概述

时间日期规则。

**起始版本：** 22

**相关模块：** [i18n](capi-i18n.md)

**所在头文件：** [timezone.h](capi-timezone-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t month | 月份。月份从0开始计数，0表示一月。 |
| int32_t dayOfMonth | 当月的第几天。 |
| int32_t dayOfWeek | 当周的第几天。 |
| int32_t weekInMonth | 当月的第几周。 |
| int32_t millisInDay | 从当天凌晨0点开始到当前时间的毫秒值。 |
| [DateRuleType](capi-timezone-h.md#dateruletype) dateRuleType | 日期规则类型。 |
| [TimeRuleType](capi-timezone-h.md#timeruletype) timeRuleType | 时间规则类型。 |


