# OH_Huks_KeyInfo


## 概述

定义密钥信息的结构体类型。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_Huks_Blob](_o_h___huks___blob.md) [alias](#alias) | 密钥的别名。  | 
| struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \* [paramSet](#paramset) | 指向密钥参数集的指针。  | 


## 结构体成员变量说明


### alias

```
struct OH_Huks_Blob OH_Huks_KeyInfo::alias
```
**描述**
密钥的别名。


### paramSet

```
struct OH_Huks_ParamSet* OH_Huks_KeyInfo::paramSet
```
**描述**
指向密钥参数集的指针。
