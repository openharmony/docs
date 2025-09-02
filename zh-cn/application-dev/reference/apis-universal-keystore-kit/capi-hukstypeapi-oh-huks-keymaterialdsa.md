# OH_Huks_KeyMaterialDsa

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## 概述

定义Dsa密钥的结构体类型。

**起始版本：** 9

**相关模块：** [HuksTypeApi](capi-hukstypeapi.md)

**所在头文件：** [native_huks_type.h](capi-native-huks-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| enum [OH_Huks_KeyAlg](capi-native-huks-type-h.md#oh_huks_keyalg) keyAlg | 密钥的算法类型。 |
| uint32_t keySize | 密钥的长度。 |
| uint32_t xSize | x值的长度。 |
| uint32_t ySize | y值的长度。 |
| uint32_t pSize | p值的长度。 |
| uint32_t qSize | q值的长度。 |
| uint32_t gSize | g值的长度。 |


