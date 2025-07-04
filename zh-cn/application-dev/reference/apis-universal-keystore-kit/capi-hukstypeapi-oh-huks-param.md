# OH_Huks_Param

## 概述

定义参数集中的参数结构体类型。

**起始版本：** 9

**相关模块：** [HuksTypeApi](capi-hukstypeapi.md)

**所在头文件：** [native_huks_type.h](capi-native-huks-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t tag | 标签值。 |
| union {<br>  bool boolParam <br>  int32_t int32Param <br> uint32_t uint32Param <br>    uint64_t uint64Param <br>    [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) blob <br> } | boolParam：bool型参数。<br>int32Param：int32_t型参数。<br>uint32Param：uint32_t型参数。<br>uint64Param：uint64_t型参数。<br>blob：OH_Huks_Blob型参数。  |

