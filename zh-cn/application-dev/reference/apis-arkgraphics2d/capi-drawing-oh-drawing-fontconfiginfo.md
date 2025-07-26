# OH_Drawing_FontConfigInfo

## 概述

系统字体配置信息结构体。

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

**所在头文件：** [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## 汇总

### 成员变量

| 名称                                           | 描述                   |
| ---------------------------------------------- | ---------------------- |
| size_t fontDirSize                             | 系统字体文件路径数量。 |
| size_t fontGenericInfoSize                     | 通用字体集列表数量。   |
| size_t fallbackGroupSize                       | 备用字体集列表数量。   |
| char** fontDirSet                              | 系统字体文件路径列表。 |
| [OH_Drawing_FontGenericInfo](capi-drawing-oh-drawing-fontgenericinfo.md)* fontGenericInfoSet | 通用字体集列表。       |
| [OH_Drawing_FontFallbackGroup](capi-drawing-oh-drawing-fontfallbackgroup.md)* fallbackGroupSet | 备用字体集列表。       |

