# OH_Huks_PubKeyInfo

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## 概述

定义公钥信息的结构体类型。

**起始版本：** 9

**相关模块：** [HuksTypeApi](capi-hukstypeapi.md)

**所在头文件：** [native_huks_type.h](capi-native-huks-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| enum [OH_Huks_KeyAlg](capi-native-huks-type-h.md#oh_huks_keyalg) keyAlg | 公钥的算法类型。 |
| uint32_t keySize | 公钥的长度。 |
| uint32_t nOrXSize | n或X值的长度。 |
| uint32_t eOrYSize | e或Y值的长度。 |
| uint32_t placeHolder | 占位符大小。 |


