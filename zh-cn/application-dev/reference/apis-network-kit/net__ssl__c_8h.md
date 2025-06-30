# net_ssl_c.h


## 概述

为SSL/TLS证书链校验模块定义C接口。

**库：** libnet_ssl.so

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**相关模块：**[Netstack](netstack.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NetStack_CertVerification](netstack.md#oh_netstack_certverification) (const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*cert, const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*caCert) | 证书链校验接口。 |
| [OH_NetStack_GetPinSetForHostName](netstack.md#oh_netstack_getpinsetforhostname)(const char \*hostname, [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) \*pin) | 获取证书锁定信息。 |
| [OH_NetStack_GetCertificatesForHostName](netstack.md#oh_netstack_getcertificatesforhostname)(const char \*hostname, [NetStack_Certificates](_net_stack___certificates.md) \*certs) | 获取证书信息。 |
| [OH_Netstack_DestroyCertificatesContent](netstack.md#oh_netstack_destroycertificatescontent)([NetStack_Certificates](_net_stack___certificates.md) \*certs) | 释放证书内容。 |
| [OH_Netstack_IsCleartextPermitted](netstack.md#oh_netstack_iscleartextpermitted)(bool \*isCleartextPermitted) | 整体明文HTTP是否允许。 |
| [OH_Netstack_IsCleartextPermittedByHostName](netstack.md#oh_netstack_iscleartextpermittedbyhostname)(const char \*hostname, bool \*isCleartextPermitted) | 按域名明文HTTP是否允许。 |
