# NetStack_CertBlob

## 概述

证书数据结构体。

**起始版本：** 11

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_ssl_c_type.h](capi-net-ssl-c-type-h.md)

## 汇总

### 成员变量

| 名称                                                                        | 描述 |
|---------------------------------------------------------------------------| -- |
| enum [NetStack_CertType](capi-net-ssl-c-type-h.md#netstack_certtype) type | 证书类型。 |
| uint32_t size                                                             | 证书内容长度。 |
| uint8_t *data                                                             | 证书内容。 |
