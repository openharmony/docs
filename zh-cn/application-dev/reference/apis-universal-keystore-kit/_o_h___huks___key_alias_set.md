# OH_Huks_KeyAliasSet


## 概述

定义密钥别名集的结构体类型。

**起始版本：** 12

**相关模块：**[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [aliasesCnt](#aliasescnt) | 密钥别名集个数。  | 
| struct [OH_Huks_Blob](_o_h___huks___blob.md) \* [aliases](#aliases) | 指向密钥别名集数据的指针。  | 


## 结构体成员变量说明


### aliases

```
struct OH_Huks_Blob* OH_Huks_KeyAliasSet::aliases
```
**描述**
指向密钥别名集数据的指针。


### aliasesCnt

```
uint32_t OH_Huks_KeyAliasSet::aliasesCnt
```
**描述**
密钥别名集个数。
