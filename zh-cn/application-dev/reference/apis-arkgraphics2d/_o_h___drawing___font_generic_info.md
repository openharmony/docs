# OH_Drawing_FontGenericInfo


## 概述

系统所支持的通用字体集信息结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [familyName](#familyname) | 字体家族名。  | 
| size_t [aliasInfoSize](#aliasinfosize) | 别名字体列表的数量。  | 
| size_t [adjustInfoSize](#adjustinfosize) | 字重映射列表的数量。  | 
| [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md) \* [aliasInfoSet](#aliasinfoset) | 别名字体列表。  | 
| [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md) \* [adjustInfoSet](#adjustinfoset) | 字重映射列表。  | 


## 结构体成员变量说明


### adjustInfoSet

```
OH_Drawing_FontAdjustInfo* OH_Drawing_FontGenericInfo::adjustInfoSet
```
**描述**

字重映射列表。


### adjustInfoSize

```
size_t OH_Drawing_FontGenericInfo::adjustInfoSize
```
**描述**

字重映射列表的数量。


### aliasInfoSet

```
OH_Drawing_FontAliasInfo* OH_Drawing_FontGenericInfo::aliasInfoSet
```
**描述**

别名字体列表。


### aliasInfoSize

```
size_t OH_Drawing_FontGenericInfo::aliasInfoSize
```
**描述**

别名字体列表的数量。


### familyName

```
char* OH_Drawing_FontGenericInfo::familyName
```
**描述**

字体家族名。
