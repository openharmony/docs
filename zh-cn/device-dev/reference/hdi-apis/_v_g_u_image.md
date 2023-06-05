# VGUImage


## 概述

图像对象。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [buffer](_display.md#buffer-33) | [VGUBuffer](_v_g_u_buffer.md)&nbsp;\*<br/>图像存储缓存 | 
| [matrix](_display.md#matrix-12) | [VGUMatrix3](_v_g_u_matrix3.md)&nbsp;\*<br/>图像矩阵变换，该参数为空，则内部使用单位变换矩阵 | 
| [rect](_display.md#rect-33) | [VGURect](_v_g_u_rect.md)&nbsp;\*<br/>图像截取矩形，该参数为空，则截取整个图像 | 
| [opacity](_display.md#opacity-13) | uint8_t<br/>透明度，范围0~255 | 
