# JSVM_PropertyDescriptor
<!--Kit: Common Basic Capability-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 概述

属性描述符。

**起始版本：** 11

**相关模块：** [JSVM](capi-jsvm.md)

**所在头文件：** [jsvm_types.h](capi-jsvm-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const char* utf8name | 描述属性键值的可选字符串，UTF8编码。必须为属性提供utf8name或name之一。 |
| JSVM_Value name | 可选的JSVM_Value，指向用作属性键的JavaScript字符串或符号。必须为属性提供utf8name或name之一。 |
| JSVM_Callback method | 设置此项使属性描述符对象的value属性成为method表示的JavaScript函数。 |
| JSVM_Callback getter | 执行对属性的获取访问时调用的函数。 |
| JSVM_Callback setter | 执行属性的设置访问时调用的函数。 |
| JSVM_Value value | 如果属性是数据属性，则通过属性的get访问检索到的值。 |
| JSVM_PropertyAttributes attributes | 与特定属性关联的属性。 |


