# Asset_Value

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @HarMonkey-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

```c
typedef union {...} Asset_Value
```

## 概述

关键资产属性的值（内容）。

**起始版本：** 11

**相关模块：** [AssetType](capi-assettype.md)

**所在头文件：** [asset_type.h](capi-asset-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| bool boolean | 该字段用于传入bool类型的属性值。 |
| uint32_t u32 | 该字段用于传入uint32类型的属性值。 |
| [Asset_Blob](capi-assettype-asset-blob.md) blob | 该字段用于传入bytes类型的属性值。 |


