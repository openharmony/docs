# Asset_ResultSet

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @HarMonkey-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

```c
typedef struct {...} Asset_ResultSet
```

## 概述

多条关键资产的查询结果。

**起始版本：** 11

**相关模块：** [AssetType](capi-assettype.md)

**所在头文件：** [asset_type.h](capi-asset-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t count | 关键资产的条数。 |
| [Asset_Result](capi-assettype-asset-result.md) *results | 指向关键资产数组的指针。 |


