# Http_HeaderValue
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## 概述

请求或者响应的标头映射的值类型。

**起始版本：** 20

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_http_type.h](capi-net-http-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char *value | 标头键值对的值。 |
| struct [Http_HeaderValue](capi-netstack-http-headervalue.md) *next | 链式存储。指向下一个Http_HeaderValue，参考[Http_HeaderValue](capi-netstack-http-headervalue.md)。 |


