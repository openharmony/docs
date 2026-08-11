# Asset_Attr

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @HarMonkey-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

```c
typedef struct {...} Asset_Attr
```

## 概述

关键资产属性，属性由标签和值组成，以键值对的形式存在。

**起始版本：** 11

**相关模块：** [AssetType](capi-assettype.md)

**所在头文件：** [asset_type.h](capi-asset-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t tag | 关键资产属性的标签。 |
| [Asset_Value](capi-assettype-asset-value.md) value | 关键资产属性的值（内容）。 |


