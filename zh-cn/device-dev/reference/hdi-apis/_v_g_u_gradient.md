# VGUGradient


## 概述

渐变对象。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [matrix](_display.md#matrix-22) | [VGUMatrix3](_v_g_u_matrix3.md)&nbsp;\*<br/>针对渐变对象的变换矩阵 | 
| [colorStops](_display.md#colorstops) | [VGUColorStop](_v_g_u_color_stop.md)&nbsp;\*<br/>渐变停止颜色数组指针 | 
| [stopCount](_display.md#stopcount) | uint16_t<br/>渐变停止颜色个数 | 
| [linear](_display.md#linear) | [VGULinear](_v_g_u_linear.md)<br/>线性渐变对象 | 
| [radial](_display.md#radial) | [VGURadial](_v_g_u_radial.md)<br/>辐射渐变对象 | 
| [conic](_display.md#conic) | [VGUConic](_v_g_u_conic.md)<br/>圆锥渐变对象 | 
| [type](_display.md#type-67) | [VGUGradientType](_display.md#vgugradienttype)<br/>渐变类型 | 
| [spread](_display.md#spread) | [VGUFillSpread](_display.md#vgufillspread)<br/>渐变延伸模式 | 
| [opacity](_display.md#opacity-23) | uint8_t<br/>透明度，范围0~255 | 
