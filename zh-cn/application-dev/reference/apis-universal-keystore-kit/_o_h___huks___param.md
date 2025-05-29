# OH_Huks_Param


## 概述

定义参数集中的参数结构体类型。

**起始版本：** 9

**相关模块：**[HuksTypeApi](_huks_type_api.md)

**所在头文件：**[native_huks_type.h](native__huks__type_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [tag](#tag) | 标签值  | 
| union { <br>bool   [boolParam](#boolparam); <br>int32_t   [int32Param](#int32param); <br>uint32_t   [uint32Param](#uint32param); <br>uint64_t   [uint64Param](#uint64param); <br>struct [OH_Huks_Blob](_o_h___huks___blob.md) [blob](#blob);} | boolParam：bool型参数。 <br>int32Param：int32_t型参数。 <br>uint32Param：uint32_t型参数。<br>uint64Param：uint64_t型参数。<br>blob：OH_Huks_Blob型参数。| 


## 结构体成员变量说明


### blob

```
struct OH_Huks_Blob OH_Huks_Param::blob
```
**描述**
OH_Huks_Blob型参数。


### boolParam

```
bool OH_Huks_Param::boolParam
```
**描述**
bool型参数。


### int32Param

```
int32_t OH_Huks_Param::int32Param
```
**描述**
int32_t型参数。


### tag

```
uint32_t OH_Huks_Param::tag
```
**描述**
标签值。


### uint32Param

```
uint32_t OH_Huks_Param::uint32Param
```
**描述**
uint32_t型参数。


### uint64Param

```
uint64_t OH_Huks_Param::uint64Param
```
**描述**
uint64_t型参数。
