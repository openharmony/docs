# display_vgu.h


## **概述**

定义2D矢量硬件加速模块相关驱动函数。

**Since:**

3.0

**相关模块:**

[Display](_display.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [VGUPoint](_v_g_u_point.md) | 坐标点对象。 | 
| [VGURect](_v_g_u_rect.md) | 矩形对象。 | 
| [VGUPath](_v_g_u_path.md) | 路径对象，存放路径命令和坐标数据。 | 
| [VGUMatrix3](_v_g_u_matrix3.md) | 变换矩阵。 | 
| [VGUBuffer](_v_g_u_buffer.md) | 硬件加速渲染位图缓存。 | 
| [VGUMaskLayer](_v_g_u_mask_layer.md) | 定义蒙版图层。 | 
| [VGUSurface](_v_g_u_surface.md) | 2D硬件加速绘制目标表面。 | 
| [VGUColorStop](_v_g_u_color_stop.md) | 渐变颜色分布位置。 | 
| [VGULinear](_v_g_u_linear.md) | 线性渐变。 | 
| [VGURadial](_v_g_u_radial.md) | 辐射渐变。 | 
| [VGUConic](_v_g_u_conic.md) | 圆锥渐变。 | 
| [VGUImage](_v_g_u_image.md) | 图像对象。 | 
| [VGUPattern](_v_g_u_pattern.md) | 图片模式对象。 | 
| [VGUGradient](_v_g_u_gradient.md) | 渐变对象。 | 
| [VGUSolid](_v_g_u_solid.md) | 颜色对象。 | 
| [VGUPaintStyle](_v_g_u_paint_style.md) | 填充或描边路径的渲染风格。 | 
| [VGUFillAttr](_v_g_u_fill_attr.md) | 填充路径的属性。 | 
| [VGUStrokeAttr](_v_g_u_stroke_attr.md) | 描边路径的属性。 | 
| [VGUFuncs](_v_g_u_funcs.md) | 定义2D硬件加速驱动函数。 | 


### 宏定义

  | 名称 | 描述 | 
| -------- | -------- |
| HDI_VGU_SCALAR_IS_FLOAT&nbsp;&nbsp;&nbsp;1 | VGU标量是否为浮点型 | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| [VGUScalar](_display.md#vguscalar) | VGU标量 | 
| [VGUPixelFormat](_display.md#vgupixelformat) | 像素格式。 | 
| [VGUBlendType](_display.md#vgublendtype) | 混合操作类型。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [VGUPathDataType](_display.md#vgupathdatatype){&nbsp;VGU_DATA_TYPE_S16&nbsp;=&nbsp;0,&nbsp;VGU_DATA_TYPE_S32,&nbsp;VGU_DATA_TYPE_F32&nbsp;} | 路径坐标数据类型。 | 
| [VGUCapability](_display.md#vgucapability){&nbsp;VGU_CAP_BLIT&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0),&nbsp;VGU_CAP_BLIT_NUM&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1),&nbsp;VGU_CAP_PATH&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2),&nbsp;VGU_CAP_FILTER_BLUR&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3)&nbsp;} | 硬件加速能力。 | 
| [VGUResult](_display.md#vguresult){&nbsp;&nbsp;&nbsp;VGU_SUCCESS&nbsp;=&nbsp;0,&nbsp;VGU_NO_SUPPORT&nbsp;=&nbsp;-1,&nbsp;VGU_OPERATION_FAILED&nbsp;=&nbsp;-2,&nbsp;VGU_OUT_OF_MEMORY&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;VGU_TIMEOUT&nbsp;=&nbsp;-4,&nbsp;VGU_INVALID_PARAMETER&nbsp;=&nbsp;-5,&nbsp;VGU_BUSY&nbsp;=&nbsp;-6,&nbsp;VGU_NO_CONTEXT&nbsp;=&nbsp;-7&nbsp;} | 错误码定义。 | 
| [VGULineCap](_display.md#vgulinecap){&nbsp;VGU_LINECAP_BUTT&nbsp;=&nbsp;0,&nbsp;VGU_LINECAP_ROUND,&nbsp;VGU_LINECAP_SQUARE&nbsp;} | 线帽。 | 
| [VGUJointType](_display.md#vgujointtype){&nbsp;VGU_LINE_JOIN_MITER&nbsp;=&nbsp;0,&nbsp;VGU_LINE_JOIN_ROUND,&nbsp;VGU_LINE_JOIN_BEVEL,&nbsp;VGU_LINE_JOIN_BUTT&nbsp;} | 联接类型。 | 
| [VGUFilter](_display.md#vgufilter){&nbsp;VGU_FILTER_BILINEAR&nbsp;=&nbsp;0,&nbsp;VGU_FILTER_NEAREST,&nbsp;VGU_FILTER_LINEAR,&nbsp;VGU_FILTER_BUTT&nbsp;} | 图像滤波类型。 | 
| [VGUFillRule](_display.md#vgufillrule){&nbsp;VGU_RULE_WINDING&nbsp;=&nbsp;0,&nbsp;VGU_RULE_EVEN_ODD,&nbsp;VGU_RULE_BUTT&nbsp;} | 填充规则定义。 | 
| [VGUFillSpread](_display.md#vgufillspread){&nbsp;VGU_SPREAD_PAD&nbsp;=&nbsp;0,&nbsp;VGU_SPREAD_REFLECT,&nbsp;VGU_SPREAD_REPEAT,&nbsp;VGU_SPREAD_BUTT&nbsp;} | 渐变填充区域外的延展类型。 | 
| [VGUWrapType](_display.md#vguwraptype){&nbsp;VGU_WRAP_REFLECT&nbsp;=&nbsp;0,&nbsp;VGU_WRAP_REPEAT,&nbsp;VGU_WRAP_BUTT&nbsp;} | 图像模式填充延展类型。 | 
| [VGUPathCmd](_display.md#vgupathcmd){&nbsp;&nbsp;&nbsp;VGU_PATH_CMD_CLOSE&nbsp;=&nbsp;0,&nbsp;VGU_PATH_CMD_MOVE,&nbsp;VGU_PATH_CMD_LINE,&nbsp;VGU_PATH_CMD_HLINE,&nbsp;&nbsp;&nbsp;VGU_PATH_CMD_VLINE,&nbsp;VGU_PATH_CMD_QUAD,&nbsp;VGU_PATH_CMD_CUBIC,&nbsp;VGU_PATH_CMD_SQUAD,&nbsp;&nbsp;&nbsp;VGU_PATH_CMD_SCUBIC,&nbsp;VGU_PATH_CMD_BUTT&nbsp;} | 路径绘制指令类型。 | 
| [VGUTransformType](_display.md#vgutransformtype){&nbsp;VGU_TRANSFORM_TRANSLATE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0),&nbsp;VGU_TRANSFORM_SCALE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1),&nbsp;VGU_TRANSFORM_ROTATE_90&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2),&nbsp;VGU_TRANSFORM_ROTATE_180&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3),&nbsp;&nbsp;&nbsp;VGU_TRANSFORM_ROTATE_270&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;4),&nbsp;VGU_TRANSFORM_OTHER&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;16)&nbsp;} | 变换类型。 | 
| [VGUClipType](_display.md#vgucliptype){&nbsp;VGU_CLIP_RECT&nbsp;=&nbsp;0,&nbsp;VGU_CLIP_PATH,&nbsp;VGU_CLIP_BUTT&nbsp;} | 绘制表面剪切类型。 | 
| [VGUGradientType](_display.md#vgugradienttype){&nbsp;VGU_GRADIENT_LINEAR&nbsp;=&nbsp;0,&nbsp;VGU_GRADIENT_RADIAL,&nbsp;VGU_GRADIENT_CONIC,&nbsp;VGU_GRADIENT_BUTT&nbsp;} | 渐变类型。 | 
| [VGUPaintType](_display.md#vgupainttype){&nbsp;VGU_PAINT_SOLID&nbsp;=&nbsp;0,&nbsp;VGU_PAINT_GRADIENT,&nbsp;VGU_PAINT_PATTERN,&nbsp;VGU_PAINT_BUTT&nbsp;} | 渲染对象。 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [VGUPathInit](_display.md#vgupathinit)(VGUPath&nbsp;\*path,&nbsp;VGUPathDataType&nbsp;type,&nbsp;const&nbsp;uint8_t&nbsp;\*segments,&nbsp;int&nbsp;numSegments,&nbsp;const&nbsp;uint8_t&nbsp;\*data,&nbsp;bool&nbsp;enAlias,&nbsp;VGURect&nbsp;boundBox) | 初始化路径对象。 | 
| [VGUPathAppend](_display.md#vgupathappend)(VGUPath&nbsp;\*path,&nbsp;const&nbsp;VGUPath&nbsp;\*subpath) | 添加子路径到当前路径中。 | 
| [VGUPathClear](_display.md#vgupathclear)(VGUPath&nbsp;\*path) | 清除路径对象内存。 | 
| [VGUMatrixIdentity](_display.md#vgumatrixidentity)(VGUMatrix3&nbsp;\*matrix) | 初始化矩阵对象为单位矩阵。 | 
| [VGUMatrixScale](_display.md#vgumatrixscale)(VGUMatrix3&nbsp;\*matrix,&nbsp;float&nbsp;xScale,&nbsp;float&nbsp;yScale) | 矩阵变换缩放。 | 
| [VGUMatrixRotate](_display.md#vgumatrixrotate)(VGUMatrix3&nbsp;\*matrix,&nbsp;float&nbsp;degree) | 矩阵变换旋转。 | 
| [VGUMatrixTranslate](_display.md#vgumatrixtranslate)(VGUMatrix3&nbsp;\*matrix,&nbsp;float&nbsp;x,&nbsp;float&nbsp;y) | 矩阵变换平移。 | 
| [VGUGradientColorStop](_display.md#vgugradientcolorstop)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUColorStop&nbsp;\*colorStop,&nbsp;uint32_t&nbsp;count) | 对渐变添加ColorStop。 | 
| [VGUGradientClearStop](_display.md#vgugradientclearstop)(VGUGradient&nbsp;\*gradient) | 清除ColorStop。 | 
| [VGUGradientMatrix](_display.md#vgugradientmatrix)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUMatrix3&nbsp;\*matrix) | 设置渐变对象的变换矩阵。 | 
| [VGUGradientLinear](_display.md#vgugradientlinear)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUPoint&nbsp;\*p1,&nbsp;const&nbsp;VGUPoint&nbsp;\*p2) | 创建线性渐变对象。 | 
| [VGUGradientRadial](_display.md#vgugradientradial)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUPoint&nbsp;\*p1,&nbsp;VGUScalar&nbsp;r1,&nbsp;const&nbsp;VGUPoint&nbsp;\*p2,&nbsp;VGUScalar&nbsp;r2) | 创建辐射渐变对象 | 
| [VGUGradientConic](_display.md#vgugradientconic)(VGUGradient&nbsp;\*gradient,&nbsp;VGUScalar&nbsp;cx,&nbsp;VGUScalar&nbsp;cy) | 创建圆锥渐变对象。 | 
| [VGUInitialize](_display.md#vguinitialize)(VGUFuncs&nbsp;\*\*funcs) | 获取硬件加速相关的操作接口指针。 | 
| [VGUUninitialize](_display.md#vguuninitialize)(VGUFuncs&nbsp;\*funcs) | 去初始化硬件加速模块，同时释放硬件加速模块操作函数指针。 | 
