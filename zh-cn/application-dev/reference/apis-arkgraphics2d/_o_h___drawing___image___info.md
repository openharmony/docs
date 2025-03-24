# OH_Drawing_Image_Info


## 概述

定义图片信息结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [width](#width) | 宽度，单位为像素。 | 
| int32_t [height](#height) | 高度，单位为像素。 | 
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) [colorType](#colortype) | 颜色类型[OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat)。 | 
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) [alphaType](#alphatype) | 透明度类型[OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat)。 | 


## 结构体成员变量说明


### alphaType

```
OH_Drawing_AlphaFormat OH_Drawing_Image_Info::alphaType
```

**描述**

透明度类型[OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat)。


### colorType

```
OH_Drawing_ColorFormat OH_Drawing_Image_Info::colorType
```

**描述**

颜色类型[OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat)。


### height

```
int32_t OH_Drawing_Image_Info::height
```

**描述**

高度，单位为像素。


### width

```
int32_t OH_Drawing_Image_Info::width
```

**描述**

宽度，单位为像素。
