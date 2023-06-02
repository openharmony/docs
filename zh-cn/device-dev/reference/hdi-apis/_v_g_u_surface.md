# VGUSurface


## 概述

2D硬件加速绘制目标表面。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [buffer](_display.md#buffer-23) | [VGUBuffer](_v_g_u_buffer.md)&nbsp;\*<br/>位图缓存 | 
| [clipRect](_display.md#cliprect) | [VGURect](_v_g_u_rect.md)&nbsp;\*<br/>矩形剪切域，如果为空，整个表面直接渲染。 | 
| [clipPath](_display.md#clippath) | [VGUPath](_v_g_u_path.md)&nbsp;\*<br/>路径剪切域，如果为空，整个表面直接渲染。 | 
| [clipType](_display.md#cliptype) | [VGUClipType](_display.md#vgucliptype)<br/>表面剪切类型 | 
| [mask](_display.md#mask) | [VGUMaskLayer](_v_g_u_mask_layer.md)&nbsp;\*<br/>蒙版图层，可以为空 | 
| [blend](_display.md#blend) | [VGUBlendType](_display.md#blendtype)<br/>混合叠加模式 | 
| [filter](_display.md#filter) | [VGUFilter](_display.md#vgufilter)<br/>图像滤波类型 | 
