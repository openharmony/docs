# OH_Drawing_FontGenericInfo
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk;@gmiao522;@Lem0nC-->
<!--SE: @liumingxiang-->
<!--TSE: @yhl0101-->
## 概述

系统所支持的通用字体集信息结构体。

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

**所在头文件：** [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## 汇总

### 成员变量

| 名称                                     | 描述                 |
| ---------------------------------------- | -------------------- |
| char* familyName                         | 字体家族名。         |
| size_t aliasInfoSize                     | 别名字体列表的数量。 |
| size_t adjustInfoSize                    | 字重映射列表的数量。 |
| [OH_Drawing_FontAliasInfo](capi-drawing-oh-drawing-fontaliasinfo.md)* aliasInfoSet   | 别名字体列表。       |
| [OH_Drawing_FontAdjustInfo](capi-drawing-oh-drawing-fontadjustinfo.md)* adjustInfoSet | 字重映射列表。       |

