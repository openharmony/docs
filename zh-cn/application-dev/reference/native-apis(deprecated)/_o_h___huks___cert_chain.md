# OH_Huks_CertChain


## 概述

定义证书链的结构体类型。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_Huks_Blob](_o_h___huks___blob.md) \* [certs](#certs) | 指向证书数据的指针。  | 
| uint32_t [certsCount](#certscount) | 证书本数。  | 


## 结构体成员变量说明


### certs

```
struct OH_Huks_Blob* OH_Huks_CertChain::certs
```
**描述**
指向证书数据的指针。


### certsCount

```
uint32_t OH_Huks_CertChain::certsCount
```
**描述**
证书本数。
