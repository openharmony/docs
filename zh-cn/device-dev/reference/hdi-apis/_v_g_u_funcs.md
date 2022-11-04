# VGUFuncs


## **概述**

定义2D硬件加速驱动函数。

**相关模块:**

[Display](_display.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([VGUFuncs::InitVgu](_display.md#initvgu)&nbsp;)(void) | 初始化硬件加速。 | 
| ([VGUFuncs::DeinitVgu](_display.md#deinitvgu)&nbsp;)(void) | 去初始化硬件加速。 | 
| ([VGUFuncs::QueryCapability](_display.md#querycapability))(uint32_t&nbsp;cap) | 查询硬件能力集。 | 
| ([VGUFuncs::RenderFill](_display.md#renderfill))(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUPath&nbsp;\*path,&nbsp;const&nbsp;VGUMatrix3&nbsp;\*matrix,&nbsp;const&nbsp;VGUFillAttr&nbsp;\*attr,&nbsp;const&nbsp;VGUPaintStyle&nbsp;\*style) | 使用指定的渲染对象来填充路径。 | 
| ([VGUFuncs::RenderStroke](_display.md#renderstroke)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUPath&nbsp;\*path,&nbsp;const&nbsp;VGUMatrix3&nbsp;\*matrix,&nbsp;const&nbsp;VGUStrokeAttr&nbsp;\*attr,&nbsp;const&nbsp;VGUPaintStyle&nbsp;\*style) | 使用指定的渲染对象来描边路径。 | 
| ([VGUFuncs::RenderBlur](_display.md#renderblur)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;uint16_t&nbsp;blur) | 对目标表面进行模糊处理。 | 
| ([VGUFuncs::RenderBlit](_display.md#renderblit)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUImage&nbsp;\*src,&nbsp;uint32_t&nbsp;color) | 对图像进行搬移操作。 | 
| ([VGUFuncs::RenderBlitN](_display.md#renderblitn)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUImage&nbsp;\*src,&nbsp;uint16_t&nbsp;count,&nbsp;uint32_t&nbsp;color) | 对多个源图像进行叠加操作。 | 
| ([VGUFuncs::RenderClearRect](_display.md#renderclearrect)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGURect&nbsp;\*rect,&nbsp;uint32_t&nbsp;color,&nbsp;uint8_t&nbsp;opacity) | 对指定矩形进行颜色清除操作。 | 
| ([VGUFuncs::RenderCancel](_display.md#rendercancel)&nbsp;)() | 取消硬件加速渲染。 | 
| ([VGUFuncs::RenderSync](_display.md#rendersync)&nbsp;)(int32_t&nbsp;timeOut) | 同步硬件加速模块绘制或搬移操作。 | 
