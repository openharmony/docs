# HdfHuks


## 概述

提供通用密钥库服务（OpenHarmony Universal KeyStore，简称HUKS）核心逻辑的标准驱动API接口。

HUKS驱动API定义了HUKS核心组件（HUKS Core）的标准接口，向HUKS Service提供了统一的驱动接口， 这些接口涵盖了密钥全生命周期管理，包括密钥生成、密钥导入导出、密钥操作、密钥访问控制、密钥证明等功能。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IHuks.idl](_i_huks_8idl.md) | 定义了HUKS的驱动接口，用于进行密钥管理。 | 
| [IHuksTypes.idl](_i_huks_types_8idl.md) | 定义了HUKS的驱动接口的结构体。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IHuks](interface_i_huks.md) | 定义了HUKS的驱动接口，用于进行密钥管理。 | 
| struct&nbsp;&nbsp;[HuksBlob](_huks_blob.md) | HUKS的二进制数据结构体，用于封装密钥材料和密钥属性等参数。 | 
| struct&nbsp;&nbsp;[HuksParamSet](_huks_param_set.md) | 定义了HUKS的密钥参数集数据结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HuksChipsetPlatformDecryptScene](#hukschipsetplatformdecryptscene) { HUKS_CHIPSET_PLATFORM_DECRYPT_SCENCE_TA_TO_TA = 1 } | 芯片平台密钥解密场景枚举。 | 


## 枚举类型说明


### HuksChipsetPlatformDecryptScene

```
enum HuksChipsetPlatformDecryptScene
```

**描述**


芯片平台密钥解密场景枚举。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| HUKS_CHIPSET_PLATFORM_DECRYPT_SCENCE_TA_TO_TA | 针对TEE（Trusted Execution Environment）环境中的应用（Trusted Application)开放的平台密钥解密场景。 | 
