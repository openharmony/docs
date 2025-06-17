# OH_Drawing_Image_Info

## 概述

定义图片信息结构体。

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

**所在头文件：** [drawing_types.h](capi-drawing-types-h.md)

## 汇总

### 成员变量

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| int32_t width                                                | 宽度，单位为像素。                                           |
| int32_t height                                               | 高度，单位为像素。                                           |
| [OH_Drawing_ColorFormat](capi-drawing-types-h.md#oh_drawing_colorformat) colorType | 颜色类型[OH_Drawing_ColorFormat](capi-drawing-types-h.md#oh_drawing_colorformat)。 |
| [OH_Drawing_AlphaFormat](capi-drawing-types-h.md#oh_drawing_alphaformat) alphaType | 透明度类型[OH_Drawing_AlphaFormat](capi-drawing-types-h.md#oh_drawing_alphaformat)。 |

