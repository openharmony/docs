# OH_Drawing_FontAliasInfo


## 概述

别名字体信息结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [familyName](#familyname) | 字体家族名  | 
| int [weight](#weight) | 字体字重值，当字重值大于0时，表示此字体集只包含所指定weight的字体，当字重值等于0时，表示此字体集包含所有字体  | 


## 结构体成员变量说明


### familyName

```
char* OH_Drawing_FontAliasInfo::familyName
```
**描述**

字体家族名


### weight

```
int OH_Drawing_FontAliasInfo::weight
```
**描述**

字体字重值，当字重值大于0时，表示此字体集只包含所指定weight的字体，当字重值等于0时，表示此字体集包含所有字体
