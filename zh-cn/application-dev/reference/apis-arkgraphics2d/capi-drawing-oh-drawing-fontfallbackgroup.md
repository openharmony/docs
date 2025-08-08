# OH_Drawing_FontFallbackGroup
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk;@gmiao522;@Lem0nC-->
<!--SE: @liumingxiang-->
<!--TSE: @yhl0101-->
## 概述

备用字体集信息结构体。

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

**所在头文件：** [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## 汇总

### 成员变量

| 名称                                         | 描述                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| char* groupName                              | 备用字体集所对应的字体集名称，如果值为空，表示可以使用备用字体集列表集所有的字体。 |
| size_t fallbackInfoSize                      | 备用字体集数量。                                             |
| [OH_Drawing_FontFallbackInfo](capi-drawing-oh-drawing-fontfallbackinfo.md)* fallbackInfoSet | 备用字体字体集列表。                                         |

