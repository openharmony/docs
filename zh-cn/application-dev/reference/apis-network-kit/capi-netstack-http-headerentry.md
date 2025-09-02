# Http_HeaderEntry
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## 概述

请求或者响应的标头的所有键值对。

**起始版本：** 20

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_http_type.h](capi-net-http-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char *key | 请求或者响应的标头中的键。 |
| [Http_HeaderValue](capi-netstack-http-headervalue.md) *value | 请求或者响应的标头中的键对应的值，参考[Http_HeaderValue](capi-netstack-http-headervalue.md)。 |
| struct [Http_HeaderEntry](capi-netstack-http-headerentry.md) *next | 链式存储。指向下一个Http_HeaderEntry，参考[Http_HeaderEntry](capi-netstack-http-headerentry.md)。 |


