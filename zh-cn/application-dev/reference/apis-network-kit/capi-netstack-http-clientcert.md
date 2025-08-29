# Http_ClientCert
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## 概述

发送到服务端的客户端证书配置，服务端将通过客户端证书校验客户端身份。

**起始版本：** 20

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_http_type.h](capi-net-http-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char *certPath | 证书路径。 |
| [Http_CertType](capi-net-http-type-h.md#http_certtype) type | 证书类型，默认是PEM，参考[Http_CertType](capi-net-http-type-h.md#http_certtype)。 |
| char *keyPath | 证书密钥的路径。 |
| char *keyPassword | 证书密钥的密码。 |


