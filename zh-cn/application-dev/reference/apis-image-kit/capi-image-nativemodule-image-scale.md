# Image_Scale

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct Image_Scale {...} Image_Scale
```

## 概述

图像缩放倍数。

**起始版本：** 22

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [image_common.h](capi-image-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| float x | 宽度的缩放倍数。<br>取值不能为0，建议取正数，否则会产生翻转效果。 |
| float y | 高度的缩放倍数。<br>取值不能为0，建议取正数，否则会产生翻转效果。 |


