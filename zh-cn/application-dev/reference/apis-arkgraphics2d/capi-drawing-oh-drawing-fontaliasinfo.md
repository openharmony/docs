# OH_Drawing_FontAliasInfo
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk;@gmiao522;@Lem0nC-->
<!--SE: @liumingxiang-->
<!--TSE: @yhl0101-->
## 概述

别名字体信息结构体。

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

**所在头文件：** [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char* familyName | 字体家族名。 |
| int weight | 字体字重值，当字重值大于0时，表示此字体集只包含所指定weight的字体，当字重值等于0时，表示此字体集包含所有字体。 |


