# OH_Huks_KeyAliasSet

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## 概述

定义密钥别名集的结构体类型。

**起始版本：** 20

**相关模块：** [HuksTypeApi](capi-hukstypeapi.md)

**所在头文件：** [native_huks_type.h](capi-native-huks-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t aliasesCnt | 密钥别名集个数。 |
| struct [OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *aliases | 指向密钥别名集数据的指针。 |


