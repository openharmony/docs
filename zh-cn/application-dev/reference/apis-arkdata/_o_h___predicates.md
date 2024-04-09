# OH_Predicates


## 概述

表示谓词。

**起始版本：** 10

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [id](_r_d_b.md#id-25) | OH_Predicates结构体的唯一标识符。 |
| [equalTo](_r_d_b.md#equalto) | 函数指针，配置谓词以匹配数据字段等于指定值的字段。 |
| [notEqualTo](_r_d_b.md#notequalto) | 函数指针，配置谓词以匹配数据字段不等于指定值的字段。 |
| [beginWrap](_r_d_b.md#beginwrap) | 函数指针，向谓词添加左括号。 |
| [endWrap](_r_d_b.md#endwrap) | 函数指针，向谓词添加右括号。 |
| [orOperate](_r_d_b.md#oroperate) | 函数指针，将或条件添加到谓词中。 |
| [andOperate](_r_d_b.md#andoperate) | 函数指针，向谓词添加和条件。 |
| [isNull](_r_d_b.md#isnull-22) | 函数指针，配置谓词以匹配值为null的字段。 |
| [isNotNull](_r_d_b.md#isnotnull) | 函数指针，配置谓词以匹配值不为null的指定字段。 |
| [like](_r_d_b.md#like) | 函数指针，配置谓词以匹配数据字段为field且值类似于指定字符串的字段。 |
| [between](_r_d_b.md#between) | 函数指针，将谓词配置为匹配数据字段为field且其值在给定范围内的指定字段。 |
| [notBetween](_r_d_b.md#notbetween) | 函数指针，将谓词配置为匹配数据字段为field且其值超出给定范围内的指定字段。 |
| [greaterThan](_r_d_b.md#greaterthan) | 函数指针，配置谓词以匹配数据字段为field且值大于指定值valueObject的字段。 |
| [lessThan](_r_d_b.md#lessthan) | 函数指针，配置谓词以匹配数据字段为field且值小于指定值valueObject的字段。 |
| [greaterThanOrEqualTo](_r_d_b.md#greaterthanorequalto) | 函数指针，配置谓词以匹配数据字段为field且值大于或等于指定值valueObject的字段。 |
| [lessThanOrEqualTo](_r_d_b.md#lessthanorequalto) | 函数指针，配置谓词以匹配数据字段为field且值小于或等于指定值valueObject的字段。 |
| [orderBy](_r_d_b.md#orderby) | 函数指针，配置谓词以匹配其值按升序或降序排序的列。 |
| [distinct](_r_d_b.md#distinct) | 函数指针，配置谓词以过滤重复记录并仅保留其中一个。 |
| [limit](_r_d_b.md#limit) | 函数指针，设置最大数据记录数的谓词。 |
| [offset](_r_d_b.md#offset) | 函数指针，配置谓词以指定返回结果的起始位置。 |
| [groupBy](_r_d_b.md#groupby) | 函数指针，配置R谓词按指定列分组查询结果。 |
| [in](_r_d_b.md#in) | 函数指针，配置谓词以匹配数据字段为field且值在给定范围内的指定字段。 |
| [notIn](_r_d_b.md#notin) | 函数指针，配置谓词以匹配数据字段为field且值超出给定范围内的指定字段。 |
| [clear](_r_d_b.md#clear-12) | 函数指针，清空谓词。 |
| [destroy](_r_d_b.md#destroy-24) | 销毁OH_Predicates对象，并回收该对象占用的内存。 |
