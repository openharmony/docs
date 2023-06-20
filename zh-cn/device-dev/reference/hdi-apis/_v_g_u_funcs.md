# VGUFuncs


## 概述

定义2D硬件加速驱动函数。

**相关模块:**

[Display](_display.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| (\*&nbsp;[InitVgu](_display.md#initvgu)&nbsp;)(void) | [VGUResult](_display.md#vguresult)<br/>初始化硬件加速。 | 
| (\*&nbsp;[DeinitVgu](_display.md#deinitvgu)&nbsp;)(void) | [VGUResult](_display.md#vguresult)<br/>去初始化硬件加速。 | 
| (\*&nbsp;[QueryCapability](_display.md#querycapability)&nbsp;)(uint32_t&nbsp;cap) | int32_t<br/>查询硬件能力集。 | 
| (\*&nbsp;[RenderFill](_display.md#renderfill)&nbsp;)([VGUSurface](_v_g_u_surface.md)&nbsp;\*target,&nbsp;const&nbsp;[VGUPath](_v_g_u_path.md)&nbsp;\*path,&nbsp;const&nbsp;[VGUMatrix3](_v_g_u_matrix3.md)&nbsp;\*matrix,&nbsp;const&nbsp;[VGUFillAttr](_v_g_u_fill_attr.md)&nbsp;\*attr,&nbsp;const&nbsp;[VGUPaintStyle](_v_g_u_paint_style.md)&nbsp;\*style) | [VGUResult](_display.md#vguresult)<br/>使用指定的渲染对象来填充路径。 | 
| (\*&nbsp;[RenderStroke](_display.md#renderstroke)&nbsp;)([VGUSurface](_v_g_u_surface.md)&nbsp;\*target,&nbsp;const&nbsp;[VGUPath](_v_g_u_path.md)&nbsp;\*path,&nbsp;const&nbsp;[VGUMatrix3](_v_g_u_matrix3.md)&nbsp;\*matrix,&nbsp;const&nbsp;[VGUStrokeAttr](_v_g_u_stroke_attr.md)&nbsp;\*attr,&nbsp;const&nbsp;[VGUPaintStyle](_v_g_u_paint_style.md)&nbsp;\*style) | [VGUResult](_display.md#vguresult)<br/>使用指定的渲染对象来描边路径。 | 
| (\*&nbsp;[RenderBlur](_display.md#renderblur)&nbsp;)([VGUSurface](_v_g_u_surface.md)&nbsp;\*target,&nbsp;uint16_t&nbsp;blur) | [VGUResult](_display.md#vguresult)<br/>对目标表面进行模糊处理。 | 
| (\*&nbsp;[RenderBlit](_display.md#renderblit)&nbsp;)([VGUSurface](_v_g_u_surface.md)&nbsp;\*target,&nbsp;const&nbsp;[VGUImage](_v_g_u_image.md)&nbsp;\*src,&nbsp;uint32_t&nbsp;color) | [VGUResult](_display.md#vguresult)<br/>对图像进行搬移操作。 | 
| (\*&nbsp;[RenderBlitN](_display.md#renderblitn)&nbsp;)([VGUSurface](_v_g_u_surface.md)&nbsp;\*target,&nbsp;const&nbsp;[VGUImage](_v_g_u_image.md)&nbsp;\*src,&nbsp;uint16_t&nbsp;count,&nbsp;uint32_t&nbsp;color) | [VGUResult](_display.md#vguresult)<br/>对多个源图像进行叠加操作。 | 
| (\*&nbsp;[RenderClearRect](_display.md#renderclearrect)&nbsp;)([VGUSurface](_v_g_u_surface.md)&nbsp;\*target,&nbsp;const&nbsp;[VGURect](_v_g_u_rect.md)&nbsp;\*rect,&nbsp;uint32_t&nbsp;color,&nbsp;uint8_t&nbsp;opacity) | [VGUResult](_display.md#vguresult)<br/>对指定矩形进行颜色清除操作。 | 
| (\*&nbsp;[RenderCancel](_display.md#rendercancel)&nbsp;)() | [VGUResult](_display.md#vguresult)<br/>取消硬件加速渲染。 | 
| (\*&nbsp;[RenderSync](_display.md#rendersync)&nbsp;)(int32_t&nbsp;timeOut) | [VGUResult](_display.md#vguresult)<br/>同步硬件加速模块绘制或搬移操作。 | 
