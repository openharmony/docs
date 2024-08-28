# net_ssl_c_type.h


## 概述

定义SSL/TLS证书链校验模块的C接口需要的数据结构。

**库：** libnet_ssl.so

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**相关模块：**[Netstack](netstack.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [NetStack_CertBlob](_net_stack___cert_blob.md) | 证书数据结构体。 |
| [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) | 证书锁定信息数据结构体。 |
| [NetStack_Certificates](_net_stack___certificates.md) | 证书信息数据结构体。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [NetStack_CertType](netstack.md#netstack_certtype) { <br>[NetStack_CERT_TYPE_PEM](netstack.md) = 0, <br>[NetStack_CERT_TYPE_DER](netstack.md) = 1,<br> [NetStack_CERT_TYPE_INVALID](netstack.md) <br>} | 证书类型枚举。 |
| [NetStack_CertificatePinningKind](netstack.md#NetStack_CertificatePinningKind) {<br />[PUBLIC_KEY](netstack.md),<br />} | 证书锁定类型 |
| [NetStack_HashAlgorithm](netstack.md#NetStack_HashAlgorithm) {<br />[SHA_256](netstack.md),<br />} | 哈希算法类型 |
