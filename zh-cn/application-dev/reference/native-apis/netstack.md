# Netstack


## 概述

为网络协议栈模块提供c接口。

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [net_ssl_c.h](net__ssl__c_8h.md) | 为SSL/TLS证书链校验模块定义C接口。 | 
| [net_ssl_c_type.h](net__ssl__c__type_8h.md) | 定义SSL/TLS证书链校验模块的C接口需要的数据结构。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [NetStack_CertBlob](_net_stack___cert_blob.md) | 证书数据结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NetStack_CertType](#netstack_certtype) { NetStack_CERT_TYPE_PEM = 0, NetStack_CERT_TYPE_DER = 1, NetStack_CERT_TYPE_INVALID } | 证书类型枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NetStack_VerifyCertification](#oh_netstack_verifycertification) (const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*cert, const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*caCert) | 对外暴露的证书链校验接口。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [NetStack_CertBlob::type](#type) | 证书类型 | 
| [NetStack_CertBlob::size](#size) | 证书内容长度 | 
| [NetStack_CertBlob::data](#data) | uint8_t \*<br/>证书内容 | 


## 枚举类型说明


### NetStack_CertType

```
enum NetStack_CertType
```

**描述**

证书类型枚举

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| NetStack_CERT_TYPE_PEM | PEM证书类型。 | 
| NetStack_CERT_TYPE_DER | DER证书类型。 | 
| NetStack_CERT_TYPE_INVALID | 错误证书类型。 | 


## 函数说明


### OH_NetStack_VerifyCertification()

```
uint32_t OH_NetStack_VerifyCertification (const struct NetStack_CertBlob * cert, const struct NetStack_CertBlob * caCert )
```

**描述**

对外暴露的证书链校验接口

**系统能力：** SystemCapability.Communication.Netstack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cert | 用户传入的待校验证书。 | 
| caCert | 用户指定的证书，若为空则以系统预置证书进行校验。 | 

**返回：**

0 - 成功

2305001 - 未指定的错误.

2305002 - 无法获取颁发者证书.

2305003 - 无法获取证书吊销列表（CRL）.

2305004 - 无法解密证书签名.

2305005 - 无法解密CRL签名.

2305006 - 无法解码颁发者公钥.

2305007 - 证书签名失败.

2305008 - CRL签名失败.

2305009 - 证书尚未生效.

2305010 - 证书已过期.

2305011 - CRL尚未有效.

2305012 - CRL已过期.

2305023 - 证书已被吊销.

2305024 - 证书颁发机构（CA）无效.

2305027 - 证书不受信任.


## 变量说明


### data

```
uint8_t* NetStack_CertBlob::data
```

**描述**

证书内容。


### size

```
uint32_t NetStack_CertBlob::size
```

**描述**

证书内容长度。


### type

```
enum NetStack_CertType NetStack_CertBlob::type
```

**描述**

证书类型。
