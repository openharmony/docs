# GfxFuncs


## **概述**

显示硬件加速驱动接口结构体，定义硬件加速驱动接口函数指针。

**相关模块:**

[Display](_display.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([InitGfx](#initgfx))(void) | 初始化硬件加速。 | 
| ([DeinitGfx](#deinitgfx))(void) | 去初始化硬件加速。 | 
| ([FillRect](#fillrect))(ISurface&nbsp;\*surface,&nbsp;IRect&nbsp;\*rect,&nbsp;uint32_t&nbsp;color,&nbsp;GfxOpt&nbsp;\*opt) | 填充矩形，用一种颜色填充画布上指定矩形区域的矩形框。 | 
| ([DrawRectangle](#drawrectangle))(ISurface&nbsp;\*surface,&nbsp;Rectangle&nbsp;\*rect,&nbsp;uint32_t&nbsp;color,&nbsp;GfxOpt&nbsp;\*opt) | 绘制矩形框，用一种颜色在画布上绘制指定区域的矩形框。 | 
| ([DrawLine](#drawline))(ISurface&nbsp;\*surface,&nbsp;ILine&nbsp;\*line,&nbsp;GfxOpt&nbsp;\*opt) | 绘制直线，使用一种颜色在画布上绘制一条直线。 | 
| ([DrawCircle](#drawcircle))(ISurface&nbsp;\*surface,&nbsp;ICircle&nbsp;\*circle,&nbsp;GfxOpt&nbsp;\*opt) | 绘制圆形，使用一种颜色在画布上绘制指定圆心和半径的圆。 | 
| ([Blit](#blit))(ISurface&nbsp;\*srcSurface,&nbsp;IRect&nbsp;\*srcRect,&nbsp;ISurface&nbsp;\*dstSurface,&nbsp;IRect&nbsp;\*dstRect,&nbsp;GfxOpt&nbsp;\*opt) | 位图搬移 | 
| ([Sync](#sync))(int32_t&nbsp;timeOut) | 硬件加速同步。 | 


## **类成员变量说明**


### Blit

  
```
int32_t(* GfxFuncs::Blit) (ISurface *srcSurface, IRect *srcRect, ISurface *dstSurface, IRect *dstRect, GfxOpt *opt)
```

**描述：**

位图搬移。

在位图搬移过程中，可以实现色彩空间转换、缩放、旋转等功能。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| srcSurface | 输入参数，源位图信息。 | 
| srcRect | 输入参数，源位图搬移区域。 | 
| dstSurface | 输出参数，目标位图信息。 | 
| dstRect | 输出参数，目标位图区域。 | 
| opt | 输入参数，硬件加速选项。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### DeinitGfx

  
```
int32_t(* GfxFuncs::DeinitGfx) (void)
```

**描述：**

去初始化硬件加速。

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[InitGfx](#initgfx)


### DrawCircle

  
```
int32_t(* GfxFuncs::DrawCircle) (ISurface *surface, ICircle *circle, GfxOpt *opt)
```

**描述：**

绘制圆形，使用一种颜色在画布上绘制指定圆心和半径的圆。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| surface | 输入参数，画布。 | 
| circle | 输入参数，圆形结构。 | 
| opt | 输入参数，硬件加速选项。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### DrawLine

  
```
int32_t(* GfxFuncs::DrawLine) (ISurface *surface, ILine *line, GfxOpt *opt)
```

**描述：**

绘制直线，使用一种颜色在画布上绘制一条直线。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| surface | 输入参数，画布。 | 
| line | 输入参数，直线结构。 | 
| opt | 输入参数，硬件加速选项。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### DrawRectangle

  
```
int32_t(* GfxFuncs::DrawRectangle) (ISurface *surface, Rectangle *rect, uint32_t color, GfxOpt *opt)
```

**描述：**

绘制矩形框，用一种颜色在画布上绘制指定区域的矩形框。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| surface | 输入参数，画布。 | 
| rect | 输入参数，矩形框结构。 | 
| color | 输入参数，绘制的颜色。 | 
| opt | 输入参数，硬件加速选项。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### FillRect

  
```
int32_t(* GfxFuncs::FillRect) (ISurface *surface, IRect *rect, uint32_t color, GfxOpt *opt)
```

**描述：**

填充矩形，用一种颜色填充画布上指定矩形区域的矩形框。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| surface | 输入参数，画布。 | 
| rect | 输入参数，填充的矩形区域。 | 
| color | 输入参数，填充的颜色。 | 
| opt | 输入参数，硬件加速选项。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。


### InitGfx

  
```
int32_t(* GfxFuncs::InitGfx) (void)
```

**描述：**

初始化硬件加速。

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。

**参见:**

[DeinitGfx](#deinitgfx)


### Sync

  
```
int32_t(* GfxFuncs::Sync) (int32_t timeOut)
```

**描述：**

硬件加速同步。

在使用硬件加速模块进行图像绘制、图像叠加、图像搬移时，通过调用该接口进行硬件同步，该接口会等待硬件加速完成。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| timeOut | 输入参数，硬件加速同步超时设置，设置为0表示无超时，等待直到硬件加速完成。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#disperrcode)。
