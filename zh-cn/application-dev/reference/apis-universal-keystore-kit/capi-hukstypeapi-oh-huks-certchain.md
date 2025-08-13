# OH_Huks_CertChain

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--SE: @HighLowWorld-->
<!--TSE: @wxy1234564846-->

## 概述

定义证书链的结构体类型。

**起始版本：** 9

**相关模块：** [HuksTypeApi](capi-hukstypeapi.md)

**所在头文件：** [native_huks_type.h](capi-native-huks-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| struct [OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *certs | 指向证书数据的指针。 |
| uint32_t certsCount | 证书本数。 |


