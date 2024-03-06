# OH_Huks_ParamSet


## 概述

定义参数集的结构体类型。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [paramSetSize](#paramsetsize) | 参数集的内存大小。  | 
| uint32_t [paramsCnt](#paramscnt) | 参数的个数。  | 
| struct [OH_Huks_Param](_o_h___huks___param.md) [params](#params) [] | 参数数组。  | 


## 结构体成员变量说明


### params[]

```
struct OH_Huks_Param OH_Huks_ParamSet::params[]
```
**描述**
参数数组。


### paramsCnt

```
uint32_t OH_Huks_ParamSet::paramsCnt
```
**描述**
参数的个数。


### paramSetSize

```
uint32_t OH_Huks_ParamSet::paramSetSize
```
**描述**
参数集的内存大小。
