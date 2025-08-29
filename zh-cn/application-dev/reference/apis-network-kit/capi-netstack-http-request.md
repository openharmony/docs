# Http_Request
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## 概述

HTTP请求结构体。

**起始版本：** 20

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_http_type.h](capi-net-http-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t requestId | HTTP请求的Id。 |
| char *url | HTTP请求的URL。 |
| [Http_RequestOptions](capi-netstack-http-requestoptions.md) *options | HTTP请求配置，指向Http_RequestOptions的指针，参考[Http_RequestOptions](capi-netstack-http-requestoptions.md)。 |


