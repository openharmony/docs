# Display


## **汇总**


## **概述**

显示模块驱动接口定义。

提供给图形系统使用的驱动接口，包括图层管理、设备控制、图形硬件加速、显示内存管理和回调接口等。

**Since**:

1.0

**Version**:。

2.0


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [display_device.h](display__device_8h.md) | 显示设备控制接口声明。 | 
| [display_gfx.h](display__gfx_8h.md) | 显示硬件加速驱动接口声明。 | 
| [display_gralloc.h](display__gralloc_8h.md) | 显示内存驱动接口声明。 | 
| [display_layer.h](display__layer_8h.md) | 显示图层驱动接口声明。 | 
| [display_type.h](display__type_8h.md) | 显示类型定义，定义显示驱动接口所使用的数据类型。 | 
| [display_vgu.h](display__vgu_8h.md) | 该文件定义2D矢量硬件加速模块相关驱动函数。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [DeviceFuncs](_device_funcs.md) | 显示设备控制接口结构体，定义显示设备控制接口函数指针。 | 
| [GfxFuncs](_gfx_funcs.md) | 显示硬件加速驱动接口结构体，定义硬件加速驱动接口函数指针。 | 
| [GrallocFuncs](_gralloc_funcs.md) | 显示内存驱动接口结构体，定义显示内存驱动接口函数指针。 | 
| [LayerFuncs](_layer_funcs.md) | 显示图层驱动接口结构体，定义显示图层驱动接口函数指针。 | 
| [DisplayInfo](_display_info.md) | 定义显示信息结构体 | 
| [LayerInfo](_layer_info.md) | 定义图层信息结构体 | 
| [LayerAlpha](_layer_alpha.md) | 定义图层Alpha信息的结构体 | 
| [BufferData](_buffer_data.md) | 定义一层的缓冲区数据，包括虚拟和物理内存地址。 | 
| [LayerBuffer](_layer_buffer.md) | 图层Buffer，用于存放图层数据。 | 
| [IRect](_i_rect.md) | 定义矩形信息。 | 
| [ISurface](_i_surface.md) | 用于存放窗口相关信息的结构体定义，提供给硬件加速使用，例如图像合成，位图搬移等操作。 | 
| [ILine](_i_line.md) | 线条描述结构体定义，用于硬件加速绘制直线。 | 
| [ICircle](_i_circle.md) | 圆形描述结构体定义，用于硬件加速绘制圆形。 | 
| [Rectangle](_rectangle.md) | 矩形描述结构体定义，用于硬件加速绘制矩形。 | 
| [GfxOpt](_gfx_opt.md) | 图像硬件加速相关的操作选项结构体定义，用于图像硬件加速时的操作选项。 | 
| [PropertyObject](_property_object.md) | 定义包含名称、属性ID和值的属性对象。 | 
| [DisplayCapability](_display_capability.md) | 定义输出性能。 | 
| [DisplayModeInfo](_display_mode_info.md) | 定义输出模式信息。 | 
| [AllocInfo](_alloc_info.md) | 定义关于要分配的内存的信息。 | 
| [HDRCapability](_h_d_r_capability.md) | HDR属性结构体定义。 | 
| [HDRMetaData](_h_d_r_meta_data.md) | HDR元数据结构体定义。 | 
| [VerifyAllocInfo](_verify_alloc_info.md) | 用于验证内存分配信息的结构体定义。 | 
| [PresentTimestamp](_present_timestamp.md) | 上屏时间戳结构体定义。 | 
| [ExtDataHandle](_ext_data_handle.md) | 扩展数据句柄结构体定义。 | 
| [YUVDescInfo](_yun_desc_info_.md) | YUV描述信息结构体定义。 | 
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
| [PROPERTY_NAME_LEN](#property_name_len)&nbsp;&nbsp;&nbsp;50 | 属性名字长度。 | 
| [HDI_VGU_SCALAR_IS_FLOAT](#hdi_vgu_scalar_is_float)&nbsp;&nbsp;&nbsp;1 | VGU标量是否为浮点型 | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| ([HotPlugCallback](#hotplugcallback))&nbsp;(uint32_t&nbsp;devId,&nbsp;bool&nbsp;connected,&nbsp;void&nbsp;\*data) | 热插拔事件回调&nbsp;。 | 
| ([VBlankCallback](#vblankcallback))&nbsp;(unsigned&nbsp;int&nbsp;sequence,&nbsp;uint64_t&nbsp;ns,&nbsp;void&nbsp;\*data) | VBlank&nbsp;事件回调。 | 
| ([RefreshCallback](#refreshcallback))&nbsp;(uint32_t&nbsp;devId,&nbsp;void&nbsp;\*data) | 刷新请求回调&nbsp;。 | 
| [VGUScalar](#vguscalar) | VGU标量。 | 
| [VGUPixelFormat](#vgupixelformat) | 像素格式。 | 
| [VGUBlendType](#vgublendtype) | 混合操作类型。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [DispErrCode](#disperrcode){&nbsp;DISPLAY_SUCCESS&nbsp;=&nbsp;0,&nbsp;DISPLAY_FAILURE&nbsp;=&nbsp;-1,&nbsp;DISPLAY_FD_ERR&nbsp;=&nbsp;-2,&nbsp;DISPLAY_PARAM_ERR&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;DISPLAY_NULL_PTR&nbsp;=&nbsp;-4,&nbsp;DISPLAY_NOT_SUPPORT&nbsp;=&nbsp;-5,&nbsp;DISPLAY_NOMEM&nbsp;=&nbsp;-6,&nbsp;DISPLAY_SYS_BUSY&nbsp;=&nbsp;-7,&nbsp;&nbsp;&nbsp;DISPLAY_NOT_PERM&nbsp;=&nbsp;-8&nbsp;} | 返回值类型定义。 | 
| [LayerType](#layertype){&nbsp;LAYER_TYPE_GRAPHIC,&nbsp;LAYER_TYPE_OVERLAY,&nbsp;LAYER_TYPE_SDIEBAND,&nbsp;LAYER_TYPE_CURSOR,&nbsp;&nbsp;&nbsp;LAYER_TYPE_BUTT&nbsp;} | 图层类型定义。 | 
| {&nbsp;HBM_USE_CPU_READ&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0),&nbsp;HBM_USE_CPU_WRITE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1),&nbsp;HBM_USE_MEM_MMZ&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2),&nbsp;HBM_USE_MEM_DMA&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3),&nbsp;&nbsp;&nbsp;HBM_USE_MEM_SHARE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;4),&nbsp;HBM_USE_MEM_MMZ_CACHE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;5),&nbsp;HBM_USE_MEM_FB&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;6),&nbsp;HBM_USE_ASSIGN_SIZE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;7)&nbsp;} | 定义缓冲区使用。 | 
| [PixelFormat](#pixelformat){&nbsp;PIXEL_FMT_CLUT8&nbsp;=&nbsp;0,&nbsp;PIXEL_FMT_CLUT1,&nbsp;PIXEL_FMT_CLUT4,&nbsp;PIXEL_FMT_RGB_565,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_5658,&nbsp;PIXEL_FMT_RGBX_4444,&nbsp;PIXEL_FMT_RGBA_4444,&nbsp;PIXEL_FMT_RGB_444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBX_5551,&nbsp;PIXEL_FMT_RGBA_5551,&nbsp;PIXEL_FMT_RGB_555,&nbsp;PIXEL_FMT_RGBX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_8888,&nbsp;PIXEL_FMT_RGB_888,&nbsp;PIXEL_FMT_BGR_565,&nbsp;PIXEL_FMT_BGRX_4444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_4444,&nbsp;PIXEL_FMT_BGRX_5551,&nbsp;PIXEL_FMT_BGRA_5551,&nbsp;PIXEL_FMT_BGRX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_8888,&nbsp;PIXEL_FMT_YUV_422_I,&nbsp;PIXEL_FMT_YCBCR_422_SP,&nbsp;PIXEL_FMT_YCRCB_422_SP,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_SP,&nbsp;PIXEL_FMT_YCRCB_420_SP,&nbsp;PIXEL_FMT_YCBCR_422_P,&nbsp;PIXEL_FMT_YCRCB_422_P,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_P,&nbsp;PIXEL_FMT_YCRCB_420_P,&nbsp;PIXEL_FMT_YUYV_422_PKG,&nbsp;PIXEL_FMT_UYVY_422_PKG,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YVYU_422_PKG,&nbsp;PIXEL_FMT_VYUY_422_PKG,&nbsp;PIXEL_FMT_VENDER_MASK&nbsp;=&nbsp;0X7FFF0000,&nbsp;PIXEL_FMT_BUTT&nbsp;=&nbsp;0X7FFFFFFF&nbsp;} | 像素格式类型定义。 | 
| [TransformType](#transformtype){&nbsp;ROTATE_NONE&nbsp;=&nbsp;0,&nbsp;ROTATE_90,&nbsp;ROTATE_180,&nbsp;ROTATE_270,&nbsp;&nbsp;&nbsp;ROTATE_BUTT&nbsp;} | 图层变换类型定义。 | 
| [BlendType](#blendtype){&nbsp;BLEND_NONE&nbsp;=&nbsp;0,&nbsp;BLEND_CLEAR,&nbsp;BLEND_SRC,&nbsp;BLEND_SRCOVER,&nbsp;&nbsp;&nbsp;BLEND_DSTOVER,&nbsp;BLEND_SRCIN,&nbsp;BLEND_DSTIN,&nbsp;BLEND_SRCOUT,&nbsp;&nbsp;&nbsp;BLEND_DSTOUT,&nbsp;BLEND_SRCATOP,&nbsp;BLEND_DSTATOP,&nbsp;BLEND_ADD,&nbsp;&nbsp;&nbsp;BLEND_XOR,&nbsp;BLEND_DST,&nbsp;BLEND_AKS,&nbsp;BLEND_AKD,&nbsp;&nbsp;&nbsp;BLEND_BUTT&nbsp;} | 支持的图像混合类型。 | 
| [RopType](#roptype){&nbsp;ROP_BLACK&nbsp;=&nbsp;0,&nbsp;ROP_NOTMERGEPEN,&nbsp;ROP_MASKNOTPEN,&nbsp;ROP_NOTCOPYPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPENNOT,&nbsp;ROP_NOT,&nbsp;ROP_XORPEN,&nbsp;ROP_NOTMASKPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPEN,&nbsp;ROP_NOTXORPEN,&nbsp;ROP_NOP,&nbsp;ROP_MERGENOTPEN,&nbsp;&nbsp;&nbsp;ROP_COPYPE,&nbsp;ROP_MERGEPENNOT,&nbsp;ROP_MERGEPEN,&nbsp;ROP_WHITE,&nbsp;&nbsp;&nbsp;ROP_BUTT&nbsp;} | 硬件加速支持的ROP操作类型。 | 
| [ColorKey](#colorkey)&nbsp;{&nbsp;CKEY_NONE&nbsp;=&nbsp;0,&nbsp;CKEY_SRC,&nbsp;CKEY_DST,&nbsp;CKEY_BUTT&nbsp;} | Color&nbsp;key操作类型定义，即硬件加速支持的Color&nbsp;key操作类型。 | 
| [MirrorType](#mirrortype){&nbsp;MIRROR_NONE&nbsp;=&nbsp;0,&nbsp;MIRROR_LR,&nbsp;MIRROR_TB,&nbsp;MIRROR_BUTT&nbsp;} | 硬件加速支持的镜像操作类型定义。 | 
| [Connection](#connection){&nbsp;CON_INVALID&nbsp;=&nbsp;0,&nbsp;CONNECTED,&nbsp;DISCONNECTED&nbsp;} | 热插拔连接类型定义。 | 
| [InterfaceType](#interfacetype){&nbsp;DISP_INTF_HDMI&nbsp;=&nbsp;0,&nbsp;DISP_INTF_LCD,&nbsp;DISP_INTF_BT1120,&nbsp;DISP_INTF_BT656,&nbsp;&nbsp;&nbsp;DISP_INTF_YPBPR,&nbsp;DISP_INTF_RGB,&nbsp;DISP_INTF_CVBS,&nbsp;DISP_INTF_SVIDEO,&nbsp;&nbsp;&nbsp;DISP_INTF_VGA,&nbsp;DISP_INTF_MIPI,&nbsp;DISP_INTF_PANEL,&nbsp;DISP_INTF_BUTT&nbsp;} | 枚举接口类型。 | 
| [DispPowerStatus](#disppowerstatus){&nbsp;POWER_STATUS_ON,&nbsp;POWER_STATUS_STANDBY,&nbsp;POWER_STATUS_SUSPEND,&nbsp;POWER_STATUS_OFF,&nbsp;&nbsp;&nbsp;POWER_STATUS_BUTT&nbsp;} | 枚举显示状态。 | 
| [CompositionType](#compositiontype){&nbsp;COMPOSITION_CLIENT,&nbsp;COMPOSITION_DEVICE,&nbsp;COMPOSITION_CURSOR,&nbsp;COMPOSITION_VIDEO,&nbsp;&nbsp;&nbsp;COMPOSITION_DEVICE_CLEAR,&nbsp;COMPOSITION_CLIENT_CLEAR,&nbsp;COMPOSITION_TUNNEL,&nbsp;COMPOSITION_BUTT&nbsp;} | 枚举特殊层的组合类型。 | 
| [ColorGamut](#colorgamut){&nbsp;COLOR_GAMUT_INVALID&nbsp;=&nbsp;-1,&nbsp;COLOR_GAMUT_NATIVE&nbsp;=&nbsp;0,&nbsp;COLOR_GAMUT_SATNDARD_BT601&nbsp;=&nbsp;1,&nbsp;COLOR_GAMUT_STANDARD_BT709&nbsp;=&nbsp;2,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_DCI_P3&nbsp;=&nbsp;3,&nbsp;COLOR_GAMUT_SRGB&nbsp;=&nbsp;4,&nbsp;COLOR_GAMUT_ADOBE_RGB&nbsp;=&nbsp;5,&nbsp;COLOR_GAMUT_DISPLAY_P3&nbsp;=&nbsp;6,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_BT2020&nbsp;=&nbsp;7,&nbsp;COLOR_GAMUT_BT2100_PQ&nbsp;=&nbsp;8,&nbsp;COLOR_GAMUT_BT2100_HLG&nbsp;=&nbsp;9,&nbsp;COLOR_GAMUT_DISPLAY_BT2020&nbsp;=&nbsp;10&nbsp;} | 色域类型枚举值。 | 
| [GamutMap](#gamutmap){&nbsp;GAMUT_MAP_CONSTANT&nbsp;=&nbsp;0,&nbsp;GAMUT_MAP_EXPANSION&nbsp;=&nbsp;1,&nbsp;GAMUT_MAP_HDR_CONSTANT&nbsp;=&nbsp;2,&nbsp;GAMUT_MAP_HDR_EXPANSION&nbsp;=&nbsp;3&nbsp;} | 枚举色域的映射类型。 | 
| [ColorDataSpace](#colordataspace){&nbsp;&nbsp;COLOR_DATA_SPACE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;GAMUT_BT601&nbsp;=&nbsp;0x00000001,&nbsp;GAMUT_BT709&nbsp;=&nbsp;0x00000002,&nbsp;GAMUT_DCI_P3&nbsp;=&nbsp;0x00000003,&nbsp;&nbsp;&nbsp;GAMUT_SRGB&nbsp;=&nbsp;0x00000004,&nbsp;GAMUT_ADOBE_RGB&nbsp;=&nbsp;0x00000005,&nbsp;GAMUT_DISPLAY_P3&nbsp;=&nbsp;0x00000006,&nbsp;GAMUT_BT2020&nbsp;=&nbsp;0x00000007,&nbsp;&nbsp;&nbsp;GAMUT_BT2100_PQ&nbsp;=&nbsp;0x00000008,&nbsp;GAMUT_BT2100_HLG&nbsp;=&nbsp;0x00000009,&nbsp;GAMUT_DISPLAY_BT2020&nbsp;=&nbsp;0x0000000a,&nbsp;TRANSFORM_FUNC_UNSPECIFIED&nbsp;=&nbsp;0x00000100,&nbsp;&nbsp;&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;=&nbsp;0x00000200,&nbsp;TRANSFORM_FUNC_SRGB&nbsp;=&nbsp;0x00000300,&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;=&nbsp;0x00000400,&nbsp;TRANSFORM_FUNC_GM2_2&nbsp;=&nbsp;0x00000500,&nbsp;&nbsp;&nbsp;TRANSFORM_FUNC_GM2_6&nbsp;=&nbsp;0x00000600,&nbsp;TRANSFORM_FUNC_GM2_8&nbsp;=&nbsp;0x00000700,&nbsp;TRANSFORM_FUNC_ST2084&nbsp;=&nbsp;0x00000800,&nbsp;TRANSFORM_FUNC_HLG&nbsp;=&nbsp;0x00000900,&nbsp;&nbsp;&nbsp;PRECISION_UNSPECIFIED&nbsp;=&nbsp;0x00010000,&nbsp;PRECISION_FULL&nbsp;=&nbsp;0x00020000,&nbsp;PRESION_LIMITED&nbsp;=&nbsp;0x00030000,&nbsp;PRESION_EXTENDED&nbsp;=&nbsp;0x00040000,&nbsp;&nbsp;&nbsp;BT601_SMPTE170M_FULL&nbsp;=&nbsp;GAMUT_BT601&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT601_SMPTE170M_LIMITED&nbsp;=&nbsp;GAMUT_BT601&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRESION_LIMITED,&nbsp;BT709_LINEAR_FULL&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT709_LINEAR_EXTENDED&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRESION_EXTENDED,&nbsp;&nbsp;&nbsp;BT709_SRGB_FULL&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT709_SRGB_EXTENDED&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRESION_EXTENDED,&nbsp;BT709_SMPTE170M_LIMITED&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRESION_LIMITED,&nbsp;DCI_P3_LINEAR_FULL&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;DCI_P3_GAMMA26_FULL&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_GM2_6&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;DISPLAY_P3_LINEAR_FULL&nbsp;=&nbsp;GAMUT_DISPLAY_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;DCI_P3_SRGB_FULL&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;ADOBE_RGB_GAMMA22_FULL&nbsp;=&nbsp;GAMUT_ADOBE_RGB&nbsp;\|&nbsp;TRANSFORM_FUNC_GM2_2&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;BT2020_LINEAR_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_SRGB_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_SMPTE170M_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_ST2084_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_ST2084&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;BT2020_HLG_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_HLG&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_ST2084_LIMITED&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_ST2084&nbsp;\|&nbsp;PRESION_LIMITED&nbsp;} | 枚举颜色空间的类型。 | 
| [HDRFormat](#hdrformat){&nbsp;NOT_SUPPORT_HDR&nbsp;=&nbsp;0,&nbsp;DOLBY_VISION&nbsp;=&nbsp;1,&nbsp;HDR10&nbsp;=&nbsp;2,&nbsp;HLG&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;HDR10_PLUS&nbsp;=&nbsp;4,&nbsp;HDR_VIVID&nbsp;=&nbsp;5&nbsp;} | 枚举HDR格式。 | 
| [HDRMetadataKey](#hdrmetadatakey){&nbsp;&nbsp;MATAKEY_RED_PRIMARY_X&nbsp;=&nbsp;0,&nbsp;MATAKEY_RED_PRIMARY_Y&nbsp;=&nbsp;1,&nbsp;MATAKEY_GREEN_PRIMARY_X&nbsp;=&nbsp;2,&nbsp;MATAKEY_GREEN_PRIMARY_Y&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;MATAKEY_BLUE_PRIMARY_X&nbsp;=&nbsp;4,&nbsp;MATAKEY_BLUE_PRIMARY_Y&nbsp;=&nbsp;5,&nbsp;MATAKEY_WHITE_PRIMARY_X&nbsp;=&nbsp;6,&nbsp;MATAKEY_WHITE_PRIMARY_Y&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;MATAKEY_MAX_LUMINANCE&nbsp;=&nbsp;8,&nbsp;MATAKEY_MIN_LUMINANCE&nbsp;=&nbsp;9,&nbsp;MATAKEY_MAX_CONTENT_LIGHT_LEVEL&nbsp;=&nbsp;10,&nbsp;MATAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;MATAKEY_HDR10_PLUS&nbsp;=&nbsp;12,&nbsp;MATAKEY_HDR_VIVID&nbsp;=&nbsp;13&nbsp;} | 枚举HDR元数据关键字。 | 
| [PresentTimestampType](#presenttimestamptype){&nbsp;HARDWARE_DISPLAY_PTS_UNSUPPORTED&nbsp;=&nbsp;0,&nbsp;HARDWARE_DISPLAY_PTS_DELAY&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0,&nbsp;HARDWARE_DISPLAY_PTS_TIMESTAMP&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1&nbsp;} | 上屏时间戳类型枚举值。 | 
| [VGUPathDataType](#vgupathdatatype){&nbsp;VGU_DATA_TYPE_S16&nbsp;=&nbsp;0,&nbsp;VGU_DATA_TYPE_S32,&nbsp;VGU_DATA_TYPE_F32&nbsp;} | 路径坐标数据类型。 | 
| [VGUCapability](#vgucapability){&nbsp;VGU_CAP_BLIT&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0),&nbsp;VGU_CAP_BLIT_NUM&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1),&nbsp;VGU_CAP_PATH&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2),&nbsp;VGU_CAP_FILTER_BLUR&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3)&nbsp;} | 硬件加速能力。 | 
| [VGUResult](#vguresult){&nbsp;&nbsp;&nbsp;VGU_SUCCESS&nbsp;=&nbsp;0,&nbsp;VGU_NO_SUPPORT&nbsp;=&nbsp;-1,&nbsp;VGU_OPERATION_FAILED&nbsp;=&nbsp;-2,&nbsp;VGU_OUT_OF_MEMORY&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;VGU_TIMEOUT&nbsp;=&nbsp;-4,&nbsp;VGU_INVALID_PARAMETER&nbsp;=&nbsp;-5,&nbsp;VGU_BUSY&nbsp;=&nbsp;-6,&nbsp;VGU_NO_CONTEXT&nbsp;=&nbsp;-7&nbsp;} | 错误码定义。 | 
| [VGULineCap](#vgulinecap){&nbsp;VGU_LINECAP_BUTT&nbsp;=&nbsp;0,&nbsp;VGU_LINECAP_ROUND,&nbsp;VGU_LINECAP_SQUARE&nbsp;} | 线帽。 | 
| [VGUJointType](#vgujointtype){&nbsp;VGU_LINE_JOIN_MITER&nbsp;=&nbsp;0,&nbsp;VGU_LINE_JOIN_ROUND,&nbsp;VGU_LINE_JOIN_BEVEL,&nbsp;VGU_LINE_JOIN_BUTT&nbsp;} | 联接类型。 | 
| [VGUFilter](#vgufilter){&nbsp;VGU_FILTER_BILINEAR&nbsp;=&nbsp;0,&nbsp;VGU_FILTER_NEAREST,&nbsp;VGU_FILTER_LINEAR,&nbsp;VGU_FILTER_BUTT&nbsp;} | 图像滤波类型。 | 
| [VGUFillRule](#vgufillrule){&nbsp;VGU_RULE_WINDING&nbsp;=&nbsp;0,&nbsp;VGU_RULE_EVEN_ODD,&nbsp;VGU_RULE_BUTT&nbsp;} | 填充规则定义。 | 
| [VGUFillSpread](#vgufillspread){&nbsp;VGU_SPREAD_PAD&nbsp;=&nbsp;0,&nbsp;VGU_SPREAD_REFLECT,&nbsp;VGU_SPREAD_REPEAT,&nbsp;VGU_SPREAD_BUTT&nbsp;} | 渐变填充区域外的延展类型。 | 
| [VGUWrapType](#vguwraptype){&nbsp;VGU_WRAP_REFLECT&nbsp;=&nbsp;0,&nbsp;VGU_WRAP_REPEAT,&nbsp;VGU_WRAP_BUTT&nbsp;} | 图像模式填充延展类型。 | 
| [VGUPathCmd](#vgupathcmd){&nbsp;&nbsp;&nbsp;VGU_PATH_CMD_CLOSE&nbsp;=&nbsp;0,&nbsp;VGU_PATH_CMD_MOVE,&nbsp;VGU_PATH_CMD_LINE,&nbsp;VGU_PATH_CMD_HLINE,&nbsp;&nbsp;&nbsp;VGU_PATH_CMD_VLINE,&nbsp;VGU_PATH_CMD_QUAD,&nbsp;VGU_PATH_CMD_CUBIC,&nbsp;VGU_PATH_CMD_SQUAD,&nbsp;&nbsp;&nbsp;VGU_PATH_CMD_SCUBIC,&nbsp;VGU_PATH_CMD_BUTT&nbsp;} | 路径绘制指令类型。 | 
| [VGUTransformType](#vgutransformtype){&nbsp;VGU_TRANSFORM_TRANSLATE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0),&nbsp;VGU_TRANSFORM_SCALE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1),&nbsp;VGU_TRANSFORM_ROTATE_90&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2),&nbsp;VGU_TRANSFORM_ROTATE_180&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3),&nbsp;&nbsp;&nbsp;VGU_TRANSFORM_ROTATE_270&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;4),&nbsp;VGU_TRANSFORM_OTHER&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;16)&nbsp;} | 变换类型。 | 
| [VGUClipType](#vgucliptype){&nbsp;VGU_CLIP_RECT&nbsp;=&nbsp;0,&nbsp;VGU_CLIP_PATH,&nbsp;VGU_CLIP_BUTT&nbsp;} | 绘制表面剪切类型。 | 
| [VGUGradientType](#vgugradienttype){&nbsp;VGU_GRADIENT_LINEAR&nbsp;=&nbsp;0,&nbsp;VGU_GRADIENT_RADIAL,&nbsp;VGU_GRADIENT_CONIC,&nbsp;VGU_GRADIENT_BUTT&nbsp;} | 渐变类型。 | 
| [VGUPaintType](#vgupainttype){&nbsp;VGU_PAINT_SOLID&nbsp;=&nbsp;0,&nbsp;VGU_PAINT_GRADIENT,&nbsp;VGU_PAINT_PATTERN,&nbsp;VGU_PAINT_BUTT&nbsp;} | 渲染对象。 | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [DeviceInitialize](#deviceinitialize)(DeviceFuncs&nbsp;\*\*funcs) | 实现显示设备控制接口的初始化，申请操作显示设备控制接口的资源，并获取对应的操作接口。 | 
| [DeviceUninitialize](#deviceuninitialize)(DeviceFuncs&nbsp;\*funcs) | 取消显示设备控制接口的初始化，释放控制接口使用到的资源。 | 
| [GfxInitialize](#gfxinitialize)(GfxFuncs&nbsp;\*\*funcs) | 获取硬件加速相关的操作接口指针。 | 
| [GfxUninitialize](#gfxuninitialize)(GfxFuncs&nbsp;\*funcs) | 释放硬件加速相关的操作接口指针。 | 
| [GrallocInitialize](#grallocinitialize)(GrallocFuncs&nbsp;\*\*funcs) | 初始化内存模块，并获取内存提供的操作接口。 | 
| [GrallocUninitialize](#grallocuninitialize)(GrallocFuncs&nbsp;\*funcs) | 取消初始化内存模块，并释放内存操作接口指针。 | 
| [LayerInitialize](#layerinitialize)(LayerFuncs&nbsp;\*\*funcs) | 实现图层初始化功能，申请图层使用的资源，并获取图层提供的操作接口。 | 
| [LayerUninitialize](#layeruninitialize)(LayerFuncs&nbsp;\*funcs) | 取消图层初始化功能，释放图层使用到的资源，并释放图层操作接口指针。 | 
| [VGUPathInit](#vgupathinit)(VGUPath&nbsp;\*path,&nbsp;VGUPathDataType&nbsp;type,&nbsp;const&nbsp;uint8_t&nbsp;\*segments,&nbsp;int&nbsp;numSegments,&nbsp;const&nbsp;uint8_t&nbsp;\*data,&nbsp;bool&nbsp;enAlias,&nbsp;VGURect&nbsp;boundBox) | 初始化路径对象。 | 
| [VGUPathAppend](#vgupathappend)(VGUPath&nbsp;\*path,&nbsp;const&nbsp;VGUPath&nbsp;\*subpath) | 添加子路径到当前路径中。 | 
| [VGUPathClear](#vgupathclear)(VGUPath&nbsp;\*path) | 清除路径对象内存。 | 
| [VGUMatrixIdentity](#vgumatrixidentity)(VGUMatrix3&nbsp;\*matrix) | 初始化矩阵对象为单位矩阵。 | 
| [VGUMatrixScale](#vgumatrixscale)(VGUMatrix3&nbsp;\*matrix,&nbsp;float&nbsp;xScale,&nbsp;float&nbsp;yScale) | 矩阵变换缩放。 | 
| [VGUMatrixRotate](#vgumatrixrotate)(VGUMatrix3&nbsp;\*matrix,&nbsp;float&nbsp;degree) | 矩阵变换旋转。 | 
| [VGUMatrixTranslate](#vgumatrixtranslate)(VGUMatrix3&nbsp;\*matrix,&nbsp;float&nbsp;x,&nbsp;float&nbsp;y) | 矩阵变换平移。 | 
| [VGUGradientColorStop](#vgugradientcolorstop)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUColorStop&nbsp;\*colorStop,&nbsp;uint32_t&nbsp;count) | 对渐变添加ColorStop。 | 
| [VGUGradientClearStop](#vgugradientclearstop)(VGUGradient&nbsp;\*gradient) | 清除ColorStop。 | 
| [VGUGradientMatrix](#vgugradientmatrix)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUMatrix3&nbsp;\*matrix) | 设置渐变对象的变换矩阵。 | 
| [VGUGradientLinear](#vgugradientlinear)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUPoint&nbsp;\*p1,&nbsp;const&nbsp;VGUPoint&nbsp;\*p2) | 创建线性渐变对象。 | 
| [VGUGradientRadial](#vgugradientradial)(VGUGradient&nbsp;\*gradient,&nbsp;const&nbsp;VGUPoint&nbsp;\*p1,&nbsp;VGUScalar&nbsp;r1,&nbsp;const&nbsp;VGUPoint&nbsp;\*p2,&nbsp;VGUScalar&nbsp;r2) | 创建辐射渐变对象 | 
| [VGUGradientConic](#vgugradientconic)(VGUGradient&nbsp;\*gradient,&nbsp;VGUScalar&nbsp;cx,&nbsp;VGUScalar&nbsp;cy) | 创建圆锥渐变对象。 | 
| [VGUInitialize](#vguinitialize)(VGUFuncs&nbsp;\*\*funcs) | 获取硬件加速相关的操作接口指针。 | 
| [VGUUninitialize](#vguuninitialize)(VGUFuncs&nbsp;\*funcs) | 去初始化硬件加速模块，同时释放硬件加速模块操作函数指针。 | 


### 变量

  | 名称 | 描述 | 
| -------- | -------- |
| ([DeviceFuncs::RegHotPlugCallback](#reghotplugcallback)&nbsp;)(HotPlugCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册热插拔事件回调。 | 
| ([DeviceFuncs::RegDisplayVBlankCallback](#regdisplayvblankcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;VBlankCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 注册VBlank事件回调。 | 
| ([DeviceFuncs::RegDisplayRefreshCallback](#regdisplayrefreshcallback)&nbsp;)(uint32_t&nbsp;devId,&nbsp;RefreshCallback&nbsp;callback,&nbsp;void&nbsp;\*data) | 刷新请求回调。 | 
| ([DeviceFuncs::GetDisplayCapability](#getdisplaycapability)&nbsp;)(uint32_t&nbsp;devId,&nbsp;DisplayCapability&nbsp;\*info) | 获取显示设备能力集。 | 
| ([DeviceFuncs::GetDisplaySupportedModes](#getdisplaysupportedmodes)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;DisplayModeInfo&nbsp;\*modes) | 获取显示设备支持的显示模式信息。 | 
| ([DeviceFuncs::GetDisplayMode](#getdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*modeId) | 获取显示设备当前的显示模式。 | 
| ([DeviceFuncs::SetDisplayMode](#setdisplaymode)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;modeId) | 设置显示设备的显示模式。 | 
| ([DeviceFuncs::GetDisplayPowerStatus](#getdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;DispPowerStatus&nbsp;\*status) | 获取显示设备当前的电源状态。 | 
| ([DeviceFuncs::SetDisplayPowerStatus](#setdisplaypowerstatus)&nbsp;)(uint32_t&nbsp;devId,&nbsp;DispPowerStatus&nbsp;status) | 设置显示设备当前的电源状态。 | 
| ([DeviceFuncs::GetDisplayBacklight](#getdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*level) | 获取显示设备当前的背光值。 | 
| ([DeviceFuncs::SetDisplayBacklight](#setdisplaybacklight)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;level) | 设置显示设备当前的背光值。 | 
| ([DeviceFuncs::GetDisplayProperty](#getdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;\*value) | 获取显示设备属性值。 | 
| ([DeviceFuncs::SetDisplayProperty](#setdisplayproperty)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;id,&nbsp;uint64_t&nbsp;value) | 设置显示设备属性值。 | 
| ([DeviceFuncs::PrepareDisplayLayers](#preparedisplaylayers)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;\*needFlushFb) | 显示设备合成前准备。 | 
| ([DeviceFuncs::GetDisplayCompChange](#getdisplaycompchange)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*Layers,&nbsp;int32_t&nbsp;\*type) | 获取显示设备合成类型有变化的layer。 | 
| ([DeviceFuncs::SetDisplayClientCrop](#setdisplayclientcrop)&nbsp;)(uint32_t&nbsp;devId,&nbsp;IRect&nbsp;\*rect) | 设置显示设备的裁剪区域。 | 
| ([DeviceFuncs::SetDisplayClientDestRect](#setdisplayclientdestrect)&nbsp;)(uint32_t&nbsp;devId,&nbsp;IRect&nbsp;\*rect) | 设置显示设备的显示区域。 | 
| ([DeviceFuncs::SetDisplayClientBuffer](#setdisplayclientbuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置显示设备的显示缓存。 | 
| ([DeviceFuncs::SetDisplayClientDamage](#setdisplayclientdamage)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;num,&nbsp;IRect&nbsp;\*rect) | 设置显示设备的显示脏区。 | 
| ([DeviceFuncs::SetDisplayVsyncEnabled](#setdisplayvsyncenabled)&nbsp;)(uint32_t&nbsp;devId,&nbsp;bool&nbsp;enabled) | 使能垂直同步信号。 | 
| ([DeviceFuncs::GetDisplayReleaseFence](#getdisplayreleasefence)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;uint32_t&nbsp;\*layers,&nbsp;int32_t&nbsp;\*fences) | 获取显示图层fence。 | 
| ([DeviceFuncs::GetDisplaySupportedColorGamuts](#getdisplaysupportedcolorgamuts)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;ColorGamut&nbsp;\*gamuts) | 获取显示设备支持的色域信息。 | 
| ([DeviceFuncs::GetDisplayColorGamut](#getdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;ColorGamut&nbsp;\*gamut) | 获取显示设备当前的色域模式。 | 
| ([DeviceFuncs::SetDisplayColorGamut](#setdisplaycolorgamut)&nbsp;)(uint32_t&nbsp;devId,&nbsp;ColorGamut&nbsp;gamut) | 设置显示设备当前的色域模式。 | 
| ([DeviceFuncs::GetDisplayGamutMap](#getdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;GamutMap&nbsp;\*gamutMap) | 获取显示设备当前的色域映射模式。 | 
| ([DeviceFuncs::SetDisplayGamutMap](#setdisplaygamutmap)&nbsp;)(uint32_t&nbsp;devId,&nbsp;GamutMap&nbsp;gamutMap) | 设置显示设备当前的色域映射模式。 | 
| ([DeviceFuncs::SetDisplayColorTransform](#setdisplaycolortransform)&nbsp;)(uint32_t&nbsp;devId,&nbsp;const&nbsp;float&nbsp;\*matrix) | 设置显示设备当前的4x4的颜色转换矩阵。 | 
| ([DeviceFuncs::GetHDRCapabilityInfos](#gethdrcapabilityinfos)&nbsp;)(uint32_t&nbsp;devId,&nbsp;HDRCapability&nbsp;\*info) | 获取显示设备支持的HDR属性信息。 | 
| ([DeviceFuncs::GetSupportedMetadataKey](#getsupportedmetadatakey)&nbsp;)(uint32_t&nbsp;devId,&nbsp;uint32_t&nbsp;\*num,&nbsp;DisplayInfo::widthHDRMetadataKey&nbsp;\*keys) | 获取显示设备支持的&nbsp;HDRMetadataKey。 | 
| ([DeviceFuncs::Commit](#commit)&nbsp;)(uint32_t&nbsp;devId,&nbsp;int32_t&nbsp;\*fence) | 提交合成送显请求。 | 
| ([DeviceFuncs::InvokeDisplayCmd](#invokedisplaycmd)&nbsp;)(uint32_t&nbsp;devId,...) | 调用显示设备命令。 | 
| ([DeviceFuncs::CreateVirtualDisplay](#createvirtualdisplay)&nbsp;)(uint32_t&nbsp;width,&nbsp;uint32_t&nbsp;height,&nbsp;int32_t&nbsp;\*format,&nbsp;uint32_t&nbsp;\*devId) | 创建虚拟显示设备。 | 
| ([DeviceFuncs::DestroyVirtualDisplay](#destroyvirtualdisplay)&nbsp;)(uint32_t&nbsp;devId) | 销毁虚拟显示设备。 | 
| ([DeviceFuncs::SetVirtualDisplayBuffer](#setvirtualdisplaybuffer)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;fence) | 设置虚拟屏的输出缓存。 | 
| ([DeviceFuncs::GetWriteBackFrame](#getwritebackframe)&nbsp;)(uint32_t&nbsp;devId,&nbsp;BufferHandle&nbsp;\*buffer,&nbsp;int32_t&nbsp;\*fence) | 获取显示设备的回写帧。 | 
| [DisplayInfo::width](#width-19) | 显示屏宽度 | 
| [DisplayInfo::height](#height-18) | 显示屏高度 | 
| [DisplayInfo::rotAngle](#rotangle) | 显示屏旋转角度 | 
| [LayerInfo::width](#width-29) | 图层宽度 | 
| [LayerInfo::height](#height-28) | 图层高度 | 
| [LayerInfo::type](#type-17) | 图层类型，包括图形层、视频层和媒体播放模式。 | 
| [LayerInfo::bpp](#bpp) | 每像素所占bit数 | 
| [LayerInfo::pixFormat](#pixformat-12) | 图层像素格式 | 
| [LayerAlpha::enGlobalAlpha](#englobalalpha-12) | 全局Alpha使能标志 | 
| [LayerAlpha::enPixelAlpha](#enpixelalpha-12) | 像素Alpha使能标志 | 
| [LayerAlpha::alpha0](#alpha0-12) | Alpha0值，取值范围：[0,&nbsp;255] | 
| [LayerAlpha::alpha1](#alpha1-12) | Alpha1值，取值范围：[0,&nbsp;255] | 
| [LayerAlpha::gAlpha](#galpha) | 全局alpha值，取值范围：[0,&nbsp;255] | 
| [BufferData::phyAddr](#phyaddr-13) | 物理内存地址 | 
| [BufferData::virAddr](#viraddr-12) | 虚拟内存地址 | 
| [LayerBuffer::fenceId](#fenceid) | buffer&nbsp;的fence号 | 
| [LayerBuffer::width](#width-39) | buffer宽度 | 
| [LayerBuffer::height](#height-38) | buffer高度 | 
| [LayerBuffer::pitch](#pitch) | 一行数据所占字节数 | 
| [LayerBuffer::pixFormat](#pixformat-22) | buffer像素格式 | 
| [LayerBuffer::data](#data-12) | 图层buffer数据 | 
| [LayerBuffer::hdl](#hdl) | 图层buffer句柄 | 
| [IRect::x](#x-14) | 矩形框起始x坐标 | 
| [IRect::y](#y-14) | 矩形框起始y坐标 | 
| [IRect::w](#w-12) | 矩形框宽度 | 
| [IRect::h](#h-12) | 矩形框高度 | 
| [ISurface::phyAddr](#phyaddr-23) | 图像首地址 | 
| [ISurface::height](#height-48) | 图像高度 | 
| [ISurface::width](#width-49) | 图像宽度 | 
| [ISurface::stride](#stride-12) | 图像跨度 | 
| [ISurface::enColorFmt](#encolorfmt) | 图像格式 | 
| [ISurface::bYCbCrClut](#bycbcrclut) | CLUT表是否位于YCbCr&nbsp;空间 | 
| [ISurface::bAlphaMax255](#balphamax255) | 图像Alpha最大值为255还是128 | 
| [ISurface::bAlphaExt1555](#balphaext1555) | 是否使能1555的Alpha扩展 | 
| [ISurface::alpha0](#alpha0-22) | Alpha0值，取值范围：[0,255] | 
| [ISurface::alpha1](#alpha1-22) | Alpha1值，取值范围：[0,255] | 
| [ISurface::cbcrPhyAddr](#clutphyaddr) | CbCr分量地址 | 
| [ISurface::cbcrStride](#cbcrstride) | CbCr分量跨度 | 
| [ISurface::clutPhyAddr](#clutphyaddr) | CLUT表首地址，用作颜色扩展或颜色校正。 | 
| [ILine::x0](#x0-12) | 线条起点的x坐标 | 
| [ILine::y0](#y0-12) | 线条起点的y坐标 | 
| [ILine::x1](#x1-13) | 线条终点的x坐标 | 
| [ILine::y1](#y1-13) | 线条终点的y坐标 | 
| [ILine::color](#color-15) | 线条颜色 | 
| [ICircle::x](#x-24) | 圆心x坐标 | 
| [ICircle::y](#y-24) | 圆心y坐标r | 
| [ICircle::r](#r) | 圆的半径 | 
| [ICircle::color](#color-25) | 圆的颜色 | 
| [Rectangle::rect](#rect-13) | 矩形区域 | 
| [Rectangle::color](#color-35) | 矩形颜色 | 
| [GfxOpt::enGlobalAlpha](#englobalalpha-22) | 全局Alpha使能位 | 
| [GfxOpt::globalAlpha](#globalalpha) | 全局Alpha的值 | 
| [GfxOpt::enPixelAlpha](#enpixelalpha-22) | 像素Alpha使能位 | 
| [GfxOpt::blendType](#blendtype) | 混合方式 | 
| [GfxOpt::colorKeyFrom](#colorkeyfrom) | 色键模式 | 
| [GfxOpt::enableRop](#enablerop) | Rop功能使能位 | 
| [GfxOpt::colorRopType](#colorroptype) | 颜色的Rop类型 | 
| [GfxOpt::alphaRopType](#alpharoptype) | Alpha的Rop类型 | 
| [GfxOpt::enableScale](#enablescale) | 缩放功能使能位 | 
| [GfxOpt::rotateType](#rotatetype) | 旋转类型 | 
| [GfxOpt::mirrorType](#mirrortype) | 镜像类型 | 
| [PropertyObject::name](#name-12) | 属性名称 | 
| [PropertyObject::propId](#propid) | 属性ID | 
| [PropertyObject::value](#value-12) | 属性值 | 
| [DisplayCapability::name](#name-22) | 显示设备名称 | 
| [DisplayCapability::type](#type-27) | 显示屏接口类型 | 
| [DisplayCapability::phyWidth](#phywidth) | 物理宽度 | 
| [DisplayCapability::phyHeight](#phyheight) | 物理高度 | 
| [DisplayCapability::supportLayers](#supportlayers) | 支持的图层数 | 
| [DisplayCapability::virtualDispCount](#virtualdispcount) | 支持的虚拟屏数 | 
| [DisplayCapability::supportWriteBack](#supportwriteback) | 是否支持回写 | 
| [DisplayCapability::propertyCount](#propertycount) | 属性数组大小 | 
| [DisplayCapability::props](#props) | 属性数组 | 
| [DisplayModeInfo::width](#width-59) | 像素宽度 | 
| [DisplayModeInfo::height](#height-58) | 像素高度 | 
| [DisplayModeInfo::freshRate](#freshrate) | 刷新速率 | 
| [DisplayModeInfo::id](#id) | 模式ID | 
| [AllocInfo::width](#width-69) | 申请内存宽度 | 
| [AllocInfo::height](#height-68) | 申请内存高度 | 
| [AllocInfo::usage](#usage-12) | 申请内存的使用场景 | 
| [AllocInfo::format](#format-12) | 申请内存格式 | 
| [AllocInfo::expectedSize](#expectedsize) | 申请内存大小 | 
| [HDRCapability::formatCount](#formatcount) | 支持的HDR格式的数量 | 
| [HDRCapability::formats](#formats) | 支持的HDR格式的数组首地址 | 
| [HDRCapability::maxLum](#maxlum) | 最大的光亮度luminance值 | 
| [HDRCapability::maxAverageLum](#maxaveragelum) | 最大的平均光亮度luminance值 | 
| [HDRCapability::minLum](#minlum) | 最小的光亮度luminance值 | 
| [HDRMetaData::key](#key) | HDR元数据关键字 | 
| [HDRMetaData::value](#value-22) | 关键字对应的值 | 
| [VerifyAllocInfo::width](#width-79) | 分配内存的宽度 | 
| [VerifyAllocInfo::height](#height-78) | 分配内存的高度 | 
| [VerifyAllocInfo::usage](#usage-22) | 内存的用处 | 
| [VerifyAllocInfo::format](#format-22) | 分配内存的像素格式 | 
| [PresentTimestamp::type](#type-37) | 上屏时间戳类型 | 
| [PresentTimestamp::time](#time) | 类型对应的值 | 
| [ExtDataHandle::fd](#fd) | 句柄&nbsp;fd，-1代表不支持 | 
| [ExtDataHandle::reserveInts](#reserveints) | reserve数组的个数 | 
| [ExtDataHandle::reserve](#reserve)&nbsp;[0] | reserve数组 | 
| [YUVDescInfo::baseAddr](#baseaddr) | 内存的初始地址 | 
| [YUVDescInfo::yOffset](#yoffset) | Y的偏移量 | 
| [YUVDescInfo::uOffset](#uoffset) | U的偏移量 | 
| [YUVDescInfo::vOffset](#voffset) | V的偏移量 | 
| [YUVDescInfo::yStride](#ystride) | Y的stride信息 | 
| [YUVDescInfo::uvStride](#uvstride) | UV的stride信息 | 
| [YUVDescInfo::uvStep](#uvstep) | UV的step信息 | 
| [VGUPoint::x](#x-34) | 点水平坐标 | 
| [VGUPoint::y](#y-34) | 点垂直坐标 | 
| [VGURect::x](#x-44) | 矩形水平起始坐标 | 
| [VGURect::y](#y-44) | 矩形垂直起始坐标 | 
| [VGURect::w](#w-22) | 矩形宽度 | 
| [VGURect::h](#h-22) | 矩形高度 | 
| [VGUPath::segment](#segment) | 存放路径命令数据 | 
| [VGUPath::numSegments](#numsegments) | 路径命令总数 | 
| [VGUPath::data](#data-22) | 存放路径命令对应坐标数据 | 
| [VGUPath::type](#type-47) | 路径数据存储类型 | 
| [VGUPath::enAlias](#enalias) | 抗锯齿开关 | 
| [VGUPath::boundBox](#boundbox) | 路径最大边界 | 
| [VGUMatrix3::m](#m)&nbsp;[3][3] | 3x3变换矩阵 | 
| [VGUMatrix3::type](#type-57) | 矩阵变换类型，简单变换为缩放，平移，90度倍数旋转。 | 
| [VGUBuffer::pixelFormat](#pixelformat) | 像素格式 | 
| [VGUBuffer::width](#width-89) | 位图宽度 | 
| [VGUBuffer::height](#height-88) | 位图高度 | 
| [VGUBuffer::stride](#stride-22) | 位图stride | 
| [VGUBuffer::virAddr](#viraddr-22) | 位图缓存的虚拟地址 | 
| [VGUBuffer::phyAddr](#phyaddr-33) | 位图缓存的物理地址 | 
| [VGUMaskLayer::buffer](#buffer-13) | 蒙版缓存 | 
| [VGUMaskLayer::rect](#rect-23) | 蒙版矩形 | 
| [VGUSurface::buffer](#buffer-23) | 位图缓存 | 
| [VGUSurface::clipRect](#cliprect) | 矩形剪切域，如果为空，整个表面直接渲染。 | 
| [VGUSurface::clipPath](#clippath) | 路径剪切域，如果为空，整个表面直接渲染。 | 
| [VGUSurface::clipType](#cliptype) | 表面剪切类型 | 
| [VGUSurface::mask](#mask) | 蒙版图层,&nbsp;可以为空。 | 
| [VGUSurface::blend](#blend) | 混合叠加模式 | 
| [VGUSurface::filter](#filter) | 图像滤波类型 | 
| [VGUColorStop::stop](#stop) | 颜色偏移位置,&nbsp;值范围是&nbsp;0.0&nbsp;~&nbsp;1.0。 | 
| [VGUColorStop::color](#color-45) | 偏移位置对应颜色 | 
| [VGULinear::x1](#x1-23) | 线性渐变起点水平坐标 | 
| [VGULinear::y1](#y1-23) | 线性渐变起点垂直坐标 | 
| [VGULinear::x2](#x2) | 线性渐变终点水平坐标 | 
| [VGULinear::y2](#y2) | 线性渐变起点垂直坐标 | 
| [VGURadial::x0](#x0-22) | 内圈圆心水平坐标 | 
| [VGURadial::y0](#y0-22) | 内圈圆心垂直坐标 | 
| [VGURadial::r0](#r0) | 内圈圆半径 | 
| [VGURadial::x1](#x1-33) | 外圈圆心水平坐标 | 
| [VGURadial::y1](#y1-33) | 外圈圆心垂直坐标 | 
| [VGURadial::r1](#r1) | 外圈圆半径 | 
| [VGUConic::cx](#cx) | 圆弧中心x坐标 | 
| [VGUConic::cy](#cy) | 圆弧中心y坐标 | 
| [VGUImage::buffer](#buffer-33) | 图像存储缓存 | 
| [VGUImage::matrix](#matrix-12) | 图像矩阵变换，该参数为空，则内部使用单位变换矩阵。 | 
| [VGUImage::rect](#rect-33) | 图像截取矩形，该参数为空，则截取整个图像。 | 
| [VGUImage::opacity](#opacity-13) | 透明度，范围0~255。 | 
| [VGUPattern::image](#image) | 图像对象 | 
| [VGUPattern::wrapx](#wrapx) | 图像水平方向平铺类型 | 
| [VGUPattern::wrapy](#wrapy) | 图像垂直方向平铺类型 | 
| [VGUGradient::matrix](#matrix-22) | 针对渐变对象的变换矩阵 | 
| [VGUGradient::colorStops](#colorstops) | 渐变停止颜色数组指针 | 
| [VGUGradient::stopCount](#stopcount) | 渐变停止颜色个数 | 
| [VGUGradient::linear](#linear) | 线性渐变对象 | 
| [VGUGradient::radial](#radial) | 辐射渐变对象 | 
| [VGUGradient::conic](#conic) | 圆锥渐变对象 | 
| [VGUGradient::type](#type-67) | 渐变类型 | 
| [VGUGradient::spread](#spread) | 渐变延伸模式 | 
| [VGUGradient::opacity](#opacity-23) | 透明度，范围0~255。 | 
| [VGUSolid::color](#color-55) | 颜色值 | 
| [VGUSolid::opacity](#opacity-33) | 透明度.&nbsp;值范围&nbsp;0&nbsp;~&nbsp;255。 | 
| [VGUPaintStyle::gradient](#gradient) | 渐变对象 | 
| [VGUPaintStyle::pattern](#pattern) | 图片模式对象 | 
| [VGUPaintStyle::solid](#solid) | 颜色对象 | 
| [VGUPaintStyle::type](#type-77) | 渲染类型 | 
| [VGUFillAttr::rule](#rule) | 填充规格 | 
| [VGUStrokeAttr::cap](#cap) | 线帽类型 | 
| [VGUStrokeAttr::join](#join) | 联结类型 | 
| [VGUStrokeAttr::miterLimit](#miterlimit) | 最大斜切长度 | 
| [VGUStrokeAttr::width](#width-99) | 线宽 | 
| ([VGUFuncs::InitVgu](#initvgu)&nbsp;)(void) | 初始化硬件加速。 | 
| ([VGUFuncs::DeinitVgu](#deinitvgu)&nbsp;)(void) | 去初始化硬件加速。 | 
| ([VGUFuncs::QueryCapability](#querycapability))(uint32_t&nbsp;cap) | 查询硬件能力集。 | 
| ([VGUFuncs::RenderFill](#renderfill))(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUPath&nbsp;\*path,&nbsp;const&nbsp;VGUMatrix3&nbsp;\*matrix,&nbsp;const&nbsp;VGUFillAttr&nbsp;\*attr,&nbsp;const&nbsp;VGUPaintStyle&nbsp;\*style) | 使用指定的渲染对象来填充路径。 | 
| ([VGUFuncs::RenderStroke](#renderstroke)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUPath&nbsp;\*path,&nbsp;const&nbsp;VGUMatrix3&nbsp;\*matrix,&nbsp;const&nbsp;VGUStrokeAttr&nbsp;\*attr,&nbsp;const&nbsp;VGUPaintStyle&nbsp;\*style) | 使用指定的渲染对象来描边路径。 | 
| ([VGUFuncs::RenderBlur](#renderblur)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;uint16_t&nbsp;blur) | 对目标表面进行模糊处理。 | 
| ([VGUFuncs::RenderBlit](#renderblit)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUImage&nbsp;\*src,&nbsp;uint32_t&nbsp;color) | 对图像进行搬移操作。 | 
| ([VGUFuncs::RenderBlitN](#renderblitn)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGUImage&nbsp;\*src,&nbsp;uint16_t&nbsp;count,&nbsp;uint32_t&nbsp;color) | 对多个源图像进行叠加操作。 | 
| ([VGUFuncs::RenderClearRect](#renderclearrect)&nbsp;)(VGUSurface&nbsp;\*target,&nbsp;const&nbsp;VGURect&nbsp;\*rect,&nbsp;uint32_t&nbsp;color,&nbsp;uint8_t&nbsp;opacity) | 对指定矩形进行颜色清除操作。 | 
| ([VGUFuncs::RenderCancel](#rendercancel)&nbsp;)() | 取消硬件加速渲染。 | 
| ([VGUFuncs::RenderSync](#rendersync)&nbsp;)(int32_t&nbsp;timeOut) | 同步硬件加速模块绘制或搬移操作。 | 


## **宏定义说明**


### PROPERTY_NAME_LEN


```
#define PROPERTY_NAME_LEN   50
```

**描述：**

属性名称长度

### HDI_VGU_SCALAR_IS_FLOAT 


```
#define HDI_VGU_SCALAR_IS_FLOAT   1
```

**描述：**

VGU标量是否为浮点型


## **类型定义说明**


### VGUPixelFormat


```
typedef PixelFormat VGUPixelFormat; 
```

**描述：**

像素格式


### VGUBlendType


```
typedef BlendType VGUBlendType; 
```

**描述：**

混合操作类型

### VGUScalar


```
#ifdef HDI_VGU_SCALAR_IS_FLOAT
typedef float VGUScalar;
#else
typedef int32_t VGUScalar;
#endif
```

**描述：**

VGU标量


### HotPlugCallback


```
typedef void(* HotPlugCallback) (uint32_t devId, bool connected, void *data)
```

**描述：**

热插拔事件回调。

当有热插拔事件发生时，会回调该接口，需要通过[RegHotPlugCallback](#reghotplugcallback)注册该回调接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID，此ID由HDI实现层生成，并通过当前回调接口传递给图形服务使用，用以标记当前连接的显示设备。 | 
| connected | 输入参数，指明设备的连接状态，true代表连接，false代表断开。 | 
| data | 输出参数，图形服务携带的私有数据，该参数携带的是[RegHotPlugCallback](#reghotplugcallback)接口注册时传递的私有数据地址。 | 


### RefreshCallback


```
typedef void(* RefreshCallback) (uint32_t devId, void *data)
```

**描述：**

刷新请求回调。

当接口实现层需要图形服务刷新数据帧时会回调该接口，需要通过[RegDisplayRefreshCallback](#regdisplayrefreshcallback)注册该回调接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，显示设备ID。 | 
| data | 输出参数，图形服务携带的私有数据，该参数携带的是[RegDisplayRefreshCallback](#regdisplayrefreshcallback)接口注册时传递的地址。 | 


### VBlankCallback


```
typedef void(* VBlankCallback) (unsigned int sequence, uint64_t ns, void *data)
```

**描述：**

VBlank 事件回调。

垂直同步事件回调接口，需要通过[RegDisplayVBlankCallback](#regdisplayvblankcallback)注册该回调接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| sequence | 输入参数，指明VBlank序列，是一个累加值。 | 
| ns | 输入参数，该次VBlank事件的时间戳，以纳秒为单位。 | 
| data | 输出参数，图形服务携带的私有数据，该参数携带的是[RegDisplayVBlankCallback](#regdisplayvblankcallback)接口注册时传递的地址。 | 


## **枚举类型说明**


### anonymous enum


```
anonymous enum
```

**描述：**

定义缓冲区使用。

  | 枚举值 | 描述 | 
| -------- | -------- |
| HBM_USE_CPU_READ | CPU&nbsp;读缓冲 | 
| HBM_USE_CPU_WRITE | CPU&nbsp;写内存 | 
| HBM_USE_MEM_MMZ | MMZ | 
| HBM_USE_MEM_DMA | DMA缓冲区 | 
| HBM_USE_MEM_SHARE | 共享内存缓冲区 | 
| HBM_USE_MEM_MMZ_CACHE | MMZ缓存 | 
| HBM_USE_MEM_FB | 帧缓存 | 
| HBM_USE_ASSIGN_SIZE | 内存分配 | 


### BlendType


```
enum BlendType
```

**描述：**

支持的图像混合类型。

系统在硬件加速期间基于指定的混合类型合成图像。

  | 枚举值 | 描述 | 
| -------- | -------- |
| BLEND_NONE | No&nbsp;混合操作 | 
| BLEND_CLEAR | CLEAR&nbsp;混合操作 | 
| BLEND_SRC | SRC&nbsp;混合操作 | 
| BLEND_SRCOVER | SRC_OVER&nbsp;混合操作 | 
| BLEND_DSTOVER | DST_OVER&nbsp;混合操作 | 
| BLEND_SRCIN | SRC_IN&nbsp;混合操作 | 
| BLEND_DSTIN | DST_IN&nbsp;混合操作 | 
| BLEND_SRCOUT | SRC_OUT&nbsp;混合操作 | 
| BLEND_DSTOUT | DST_OUT&nbsp;混合操作 | 
| BLEND_SRCATOP | SRC_ATOP&nbsp;混合操作 | 
| BLEND_DSTATOP | DST_ATOP&nbsp;混合操作 | 
| BLEND_ADD | ADD&nbsp;混合操作 | 
| BLEND_XOR | XOR&nbsp;混合操作 | 
| BLEND_DST | DST&nbsp;混合操作 | 
| BLEND_AKS | AKS&nbsp;混合操作 | 
| BLEND_AKD | AKD&nbsp;混合操作 | 
| BLEND_BUTT | 空操作 | 


### ColorDataSpace


```
enum ColorDataSpace
```

**描述：**

枚举颜色空间的类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_DATA_SPACE_UNKNOWN | 未知的 | 
| GAMUT_BT601 | BT601色域 | 
| GAMUT_BT709 | BT709色域 | 
| GAMUT_DCI_P3 | DCI_P3色域 | 
| GAMUT_SRGB | SRGB色域 | 
| GAMUT_ADOBE_RGB | ADOBE_RGB色域 | 
| GAMUT_DISPLAY_P3 | DISPLAY_P3色域 | 
| GAMUT_BT2020 | BT2020色域 | 
| GAMUT_BT2100_PQ | BT2100_PQ色域 | 
| GAMUT_BT2100_HLG | BT2100_HLG色域 | 
| GAMUT_DISPLAY_BT2020 | DISPLAY_BT2020色域 | 
| TRANSFORM_FUNC_UNSPECIFIED | UNSPECIFIED转换函数 | 
| TRANSFORM_FUNC_LINEAR | LINEAR转换函数 | 
| TRANSFORM_FUNC_SRGB | SRGB转换函数 | 
| TRANSFORM_FUNC_SMPTE_170M | SMPTE_170M转换函数 | 
| TRANSFORM_FUNC_GM2_2 | GM2_2转换函数 | 
| TRANSFORM_FUNC_GM2_6 | GM2_6转换函数 | 
| TRANSFORM_FUNC_GM2_8 | GM2_8转换函数 | 
| TRANSFORM_FUNC_ST2084 | ST2084转换函数 | 
| TRANSFORM_FUNC_HLG | HLG转换函数 | 
| PRECISION_UNSPECIFIED | UNSPECIFIED精度 | 
| PRECISION_FULL | FULL精度 | 
| PRESION_LIMITED | LIMITED精度 | 
| PRESION_EXTENDED | EXTENDED精度 | 
| BT601_SMPTE170M_FULL | BT601色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT601_SMPTE170M_LIMITED | BT601色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;LIMITED精度 | 
| BT709_LINEAR_FULL | BT709色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT709_LINEAR_EXTENDED | BT709色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;EXTENDED精度 | 
| BT709_SRGB_FULL | BT709色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT709_SRGB_EXTENDED | BT709色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;EXTENDED精度 | 
| BT709_SMPTE170M_LIMITED | BT709色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;LIMITED精度 | 
| DCI_P3_LINEAR_FULL | DCI_P3色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| DCI_P3_GAMMA26_FULL | DCI_P3色域&nbsp;\|&nbsp;GM2_6转换函数&nbsp;\|&nbsp;FULL精度 | 
| DISPLAY_P3_LINEAR_FULL | DISPLAY_P3色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| DCI_P3_SRGB_FULL | DCI_P3色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;FULL精度 | 
| ADOBE_RGB_GAMMA22_FULL | ADOBE_RGB色域&nbsp;\|&nbsp;GM2_2转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_LINEAR_FULL | BT2020色域&nbsp;\|&nbsp;LINEAR转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_SRGB_FULL | BT2020色域&nbsp;\|&nbsp;SRGB转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_SMPTE170M_FULL | BT2020色域&nbsp;\|&nbsp;SMPTE_170M转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_ST2084_FULL | BT2020色域&nbsp;\|&nbsp;ST2084转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_HLG_FULL | BT2020色域&nbsp;\|&nbsp;HLG转换函数&nbsp;\|&nbsp;FULL精度 | 
| BT2020_ST2084_LIMITED | BT2020色域&nbsp;\|&nbsp;ST2084转换函数&nbsp;\|&nbsp;LIMITED精度 | 


### ColorGamut


```
enum ColorGamut
```

**描述：**

色域类型枚举值

  | 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_GAMUT_INVALID | 无效值 | 
| COLOR_GAMUT_NATIVE | 默认值 | 
| COLOR_GAMUT_STANDARD_BT601 | Standard&nbsp;BT601类型 | 
| COLOR_GAMUT_STANDARD_BT709 | Standard&nbsp;BT709类型 | 
| COLOR_GAMUT_DCI_P3 | DCI&nbsp;P3类型 | 
| COLOR_GAMUT_SRGB | SRGB类型 | 
| COLOR_GAMUT_ADOBE_RGB | Adobe&nbsp;RGB类型 | 
| COLOR_GAMUT_DISPLAY_P3 | display&nbsp;P3类型 | 
| COLOR_GAMUT_BT2020 | BT2020类型 | 
| COLOR_GAMUT_BT2100_PQ | BT2100&nbsp;PQ类型 | 
| COLOR_GAMUT_BT2100_HLG | BT2100&nbsp;HLG类型 | 
| COLOR_GAMUT_DISPLAY_BT2020 | Display&nbsp;BT2020类型 | 


### ColorKey


```
enum ColorKey
```

**描述：**

Color key操作类型定义，即硬件加速支持的Color key操作类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| CKEY_NONE | 不使用colorkey | 
| CKEY_SRC | 使用源colorkey | 
| CKEY_DST | 使用目标colorkey | 
| CKEY_BUTT | 空操作 | 


### CompositionType


```
enum CompositionType
```

**描述：**

枚举特殊层的组合类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| COMPOSITION_CLIENT | Client&nbsp;合成类型，使用CPU或者GPU合成 | 
| COMPOSITION_DEVICE | Device&nbsp;合成类型，使用Device合成 | 
| COMPOSITION_CURSOR | Cursor合成类型，用于光标合成 | 
| COMPOSITION_VIDEO | Video合成类型，用于视频层合成 | 
| COMPOSITION_DEVICE_CLEAR | Device&nbsp;clear&nbsp;合成类型，device会清除目标区域 | 
| COMPOSITION_CLIENT_CLEAR | Client&nbsp;clear&nbsp;合成类型，service会清除目标区域 | 
| COMPOSITION_TUNNEL | Tunnel&nbsp;合成类型，用于tunnel | 
| COMPOSITION_BUTT | 合成类型，一个不可用类型，用于默认初始化 | 


### Connection


```
enum Connection
```

**描述：**

热插拔连接类型定义

  | 枚举值 | 描述 | 
| -------- | -------- |
| CON_INVALID | 无效类型 | 
| CONNECTED | 已连接 | 
| DISCONNECTED | 断开连接 | 


### DispErrCode


```
enum DispErrCode
```

**描述：**

返回值类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_SUCCESS | 成功 | 
| DISPLAY_FAILURE | 失败 | 
| DISPLAY_FD_ERR | fd错误 | 
| DISPLAY_PARAM_ERR | 参数错误 | 
| DISPLAY_NULL_PTR | 空指针 | 
| DISPLAY_NOT_SUPPORT | 不支持的特性 | 
| DISPLAY_NOMEM | 内存不足 | 
| DISPLAY_SYS_BUSY | 系统繁忙 | 
| DISPLAY_NOT_PERM | 操作不允许 | 


### DispPowerStatus


```
enum DispPowerStatus
```

**描述：**

枚举显示状态

  | 枚举值 | 描述 | 
| -------- | -------- |
| POWER_STATUS_ON | 上电模式 | 
| POWER_STATUS_STANDBY | 待机模式 | 
| POWER_STATUS_SUSPEND | 休眠模式 | 
| POWER_STATUS_OFF | 下电模式 | 
| POWER_STATUS_BUTT | 默认模式 | 


### GamutMap


```
enum GamutMap
```

**描述：**

枚举色域的映射类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| GAMUT_MAP_CONSTANT | 不变 | 
| GAMUT_MAP_EXPANSION | 映射增强 | 
| GAMUT_MAP_HDR_CONSTANT | 不变，用于HDR | 
| GAMUT_MAP_HDR_EXPANSION | 映射增强，用于HDR | 


### HDRFormat


```
enum HDRFormat
```

**描述：**

枚举HDR格式

  | 枚举值 | 描述 | 
| -------- | -------- |
| NOT_SUPPORT_HDR | 不支持HDR | 
| DOLBY_VISION | Dolby&nbsp;Vision格式 | 
| HDR10 | HDR10格式 | 
| HLG | HLG格式 | 
| HDR10_PLUS | HDR10&nbsp;Plus格式 | 
| HDR_VIVID | Vivid格式 | 


### HDRMetadataKey


```
enum HDRMetadataKey
```

**描述：**

枚举HDR元数据关键字

  | 枚举值 | 描述 | 
| -------- | -------- |
| MATAKEY_RED_PRIMARY_X | 红基色X坐标 | 
| MATAKEY_RED_PRIMARY_Y | 红基色Y坐标 | 
| MATAKEY_GREEN_PRIMARY_X | 绿基色X坐标 | 
| MATAKEY_GREEN_PRIMARY_Y | 绿基色Y坐标 | 
| MATAKEY_BLUE_PRIMARY_X | 蓝基色X坐标 | 
| MATAKEY_BLUE_PRIMARY_Y | 蓝基色Y坐标 | 
| MATAKEY_WHITE_PRIMARY_X | 白点X坐标 | 
| MATAKEY_WHITE_PRIMARY_Y | 白点Y坐标 | 
| MATAKEY_MAX_LUMINANCE | 最大的光亮度 | 
| MATAKEY_MIN_LUMINANCE | 最小的光亮度 | 
| MATAKEY_MAX_CONTENT_LIGHT_LEVEL | 最大的内容亮度水平 | 
| MATAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL | 最大的帧平均亮度水平 | 
| MATAKEY_HDR10_PLUS | HDR10&nbsp;Plus | 
| MATAKEY_HDR_VIVID | Vivid | 


### InterfaceType


```
enum InterfaceType
```

**描述：**

枚举接口类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| DISP_INTF_HDMI | HDMI&nbsp;接口 | 
| DISP_INTF_LCD | LCD&nbsp;接口 | 
| DISP_INTF_BT1120 | BT1120&nbsp;接口 | 
| DISP_INTF_BT656 | BT656&nbsp;接口 | 
| DISP_INTF_YPBPR | YPBPR&nbsp;接口 | 
| DISP_INTF_RGB | RGB&nbsp;接口 | 
| DISP_INTF_CVBS | CVBS&nbsp;接口 | 
| DISP_INTF_SVIDEO | SVIDEO&nbsp;接口 | 
| DISP_INTF_VGA | VGA&nbsp;接口 | 
| DISP_INTF_MIPI | MIPI&nbsp;接口 | 
| DISP_INTF_PANEL | PANEL&nbsp;接口 | 
| DISP_INTF_BUTT | BUTT&nbsp;接口，一个不可用类型，用于默认初始化。 | 


### LayerType


```
enum LayerType
```

**描述：**

图层类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| LAYER_TYPE_GRAPHIC | 图形层 | 
| LAYER_TYPE_OVERLAY | 视频层 | 
| LAYER_TYPE_SIDEBAND | 媒体播放 | 
| LAYER_TYPE_CURSOR | 光标层 | 
| LAYER_TYPE_BUTT | 空图层 | 


### MirrorType


```
enum MirrorType
```

**描述：**

硬件加速支持的镜像操作类型定义

  | 枚举值 | 描述 | 
| -------- | -------- |
| MIRROR_NONE | 不使用镜像 | 
| MIRROR_LR | 左右镜像 | 
| MIRROR_TB | 上下镜像 | 
| MIRROR_BUTT | 空操作 | 


### PixelFormat


```
enum PixelFormat
```

**描述：**

像素格式类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PIXEL_FMT_CLUT8 | CLUT8&nbsp;格式 | 
| PIXEL_FMT_CLUT1 | CLUT1&nbsp;格式 | 
| PIXEL_FMT_CLUT4 | CLUT4&nbsp;格式 | 
| PIXEL_FMT_RGB_565 | RGB565&nbsp;格式 | 
| PIXEL_FMT_RGBA_5658 | RGBA5658&nbsp;格式 | 
| PIXEL_FMT_RGBX_4444 | RGBX4444&nbsp;格式 | 
| PIXEL_FMT_RGBA_4444 | RGBA4444&nbsp;格式 | 
| PIXEL_FMT_RGB_444 | RGB444&nbsp;格式 | 
| PIXEL_FMT_RGBX_5551 | RGBX5551&nbsp;格式 | 
| PIXEL_FMT_RGBA_5551 | RGBA5551&nbsp;格式 | 
| PIXEL_FMT_RGB_555 | RGB555&nbsp;格式 | 
| PIXEL_FMT_RGBX_8888 | RGBX8888&nbsp;格式 | 
| PIXEL_FMT_RGBA_8888 | RGBA8888&nbsp;格式 | 
| PIXEL_FMT_RGB_888 | RGB888&nbsp;格式 | 
| PIXEL_FMT_BGR_565 | BGR565&nbsp;格式 | 
| PIXEL_FMT_BGRX_4444 | BGRX4444&nbsp;格式 | 
| PIXEL_FMT_BGRA_4444 | BGRA4444&nbsp;格式 | 
| PIXEL_FMT_BGRX_5551 | BGRX5551&nbsp;格式 | 
| PIXEL_FMT_BGRA_5551 | BGRA5551&nbsp;格式 | 
| PIXEL_FMT_BGRX_8888 | BGRX8888&nbsp;格式 | 
| PIXEL_FMT_BGRA_8888 | BGRA8888&nbsp;格式 | 
| PIXEL_FMT_YUV_422_I | YUV422&nbsp;交错格式 | 
| PIXEL_FMT_YCBCR_422_SP | YCBCR422&nbsp;半平面格式 | 
| PIXEL_FMT_YCRCB_422_SP | YCRCB422&nbsp;半平面格式 | 
| PIXEL_FMT_YCBCR_420_SP | YCBCR420&nbsp;半平面格式 | 
| PIXEL_FMT_YCRCB_420_SP | YCRCB420&nbsp;半平面格式 | 
| PIXEL_FMT_YCBCR_422_P | YCBCR422&nbsp;平面格式 | 
| PIXEL_FMT_YCRCB_422_P | YCRCB422&nbsp;平面格式 | 
| PIXEL_FMT_YCBCR_420_P | YCBCR420&nbsp;平面格式 | 
| PIXEL_FMT_YCRCB_420_P | YCRCB420&nbsp;平面格式 | 
| PIXEL_FMT_YUYV_422_PKG | YUYV422&nbsp;打包格式 | 
| PIXEL_FMT_UYVY_422_PKG | UYVY422&nbsp;打包格式t | 
| PIXEL_FMT_YVYU_422_PKG | YVYU422&nbsp;打包格式 | 
| PIXEL_FMT_VYUY_422_PKG | VYUY422&nbsp;打包格式 | 
| PIXEL_FMT_VENDER_MASK | vendor&nbsp;mask&nbsp;格式 | 
| PIXEL_FMT_BUTT | Invalid&nbsp;像素格式 | 


### PresentTimestampType


```
enum PresentTimestampType
```

**描述：**

上屏时间戳类型枚举值

  | 枚举值 | 描述 | 
| -------- | -------- |
| HARDWARE_DISPLAY_PTS_UNSUPPORTED | 不支持 | 
| HARDWARE_DISPLAY_PTS_DELAY | Delay&nbsp;时延类型 | 
| HARDWARE_DISPLAY_PTS_TIMESTAMP | 时间戳类型 | 


### RopType


```
enum RopType
```

**描述：**

硬件加速支持的ROP操作类型。

硬件加速支持的ROP操作类型，在将前景位图的RGB颜色分量和Alpha分量值与背景位图的RGB颜色分量值和Alpha分量值进行按位的布尔运算（包括按位与，按位或等），将结果输出。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ROP_BLACK | 黑色 | 
| ROP_NOTMERGEPEN | ~(S2+S1) | 
| ROP_MASKNOTPEN | ~S2&amp;S1 | 
| ROP_NOTCOPYPEN | ~S2 | 
| ROP_MASKPENNOT | S2&amp;~S1 | 
| ROP_NOT | ~S1 | 
| ROP_XORPEN | S2^S1 | 
| ROP_NOTMASKPEN | ~(S2&amp;S1) | 
| ROP_MASKPEN | S2&amp;S1 | 
| ROP_NOTXORPEN | ~(S2^S1) | 
| ROP_NOP | S1 | 
| ROP_MERGENOTPEN | ~S2+S1 | 
| ROP_COPYPE | S2 | 
| ROP_MERGEPENNOT | S2+~S1 | 
| ROP_MERGEPEN | S2+S1 | 
| ROP_WHITE | 白色 | 
| ROP_BUTT | 无效值 | 


### TransformType


```
enum TransformType
```

**描述：**

图层变换类型定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ROTATE_NONE | 不旋转 | 
| ROTATE_90 | 旋转90度 | 
| ROTATE_180 | 旋转180度 | 
| ROTATE_270 | 旋转270度 | 
| ROTATE_BUTT | 无效操作 | 


### VGUCapability


```
enum VGUCapability
```

**描述：**

硬件加速能力。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_CAP_BLIT | 支持Blit能力 | 
| VGU_CAP_BLIT_NUM | 搬移支持图片叠加最大数目 | 
| VGU_CAP_PATH | 支持路径的fill和stroke能力 | 
| VGU_CAP_FILTER_BLUR | 支持模糊能力 | 


### VGUClipType


```
enum VGUClipType
```

**描述：**

绘制表面剪切类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_CLIP_RECT | 矩形剪切(默认) | 
| VGU_CLIP_PATH | 路径剪切 | 
| VGU_CLIP_BUTT | 无效定义 | 


### VGUFillRule


```
enum VGUFillRule
```

**描述：**

填充规则定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_RULE_WINDING | 非0填充(默认) | 
| VGU_RULE_EVEN_ODD | 奇偶填充 | 
| VGU_RULE_BUTT | 无效定义 | 


### VGUFillSpread


```
enum VGUFillSpread
```

**描述：**

渐变填充区域外的延展类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_SPREAD_PAD | Pad类型(默认) | 
| VGU_SPREAD_REFLECT | Reflect类型 | 
| VGU_SPREAD_REPEAT | Repeat类型 | 
| VGU_SPREAD_BUTT | 无效定义 | 


### VGUFilter


```
enum VGUFilter
```

**描述：**

图像滤波类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_FILTER_BILINEAR | 双线性插值(默认) | 
| VGU_FILTER_NEAREST | 无插值 | 
| VGU_FILTER_LINEAR | 线性插值 | 
| VGU_FILTER_BUTT | 无效定义 | 


### VGUGradientType


```
enum VGUGradientType
```

**描述：**

渐变类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_GRADIENT_LINEAR | 线性渐变 | 
| VGU_GRADIENT_RADIAL | 辐射渐变 | 
| VGU_GRADIENT_CONIC | 圆锥渐变 | 
| VGU_GRADIENT_BUTT | 无效定义 | 


### VGUJointType


```
enum VGUJointType
```

**描述：**

联接类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_LINE_JOIN_MITER | 尖角(默认) | 
| VGU_LINE_JOIN_ROUND | 圆角 | 
| VGU_LINE_JOIN_BEVEL | 斜角 | 
| VGU_LINE_JOIN_BUTT | 无效定义 | 


### VGULineCap


```
enum VGULineCap
```

**描述：**

线帽。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_LINECAP_BUTT | 线条末端为平直线帽(默认) | 
| VGU_LINECAP_ROUND | 线条末端为圆形线帽 | 
| VGU_LINECAP_SQUARE | 线条末端为正方向形线帽 | 


### VGUPaintType


```
enum VGUPaintType
```

**描述：**

渲染对象

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_PAINT_SOLID | 填充颜色 | 
| VGU_PAINT_GRADIENT | 渲染渐变对象 | 
| VGU_PAINT_PATTERN | 渲染图片模式 | 
| VGU_PAINT_BUTT | 无效操作 | 


### VGUPathCmd


```
enum VGUPathCmd
```

**描述：**

路径绘制指令类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_PATH_CMD_CLOSE | 线段关闭，坐标数据：none | 
| VGU_PATH_CMD_MOVE | 移动到指定位置，坐标数据：x0,&nbsp;y0 | 
| VGU_PATH_CMD_LINE | 线条，坐标数据：x0,&nbsp;y0 | 
| VGU_PATH_CMD_HLINE | 水平线，坐标数据：x0 | 
| VGU_PATH_CMD_VLINE | 垂直线，坐标数据：y0 | 
| VGU_PATH_CMD_QUAD | 二次贝塞尔曲线，坐标数据：x0,&nbsp;y0,&nbsp;x1,&nbsp;y1 | 
| VGU_PATH_CMD_CUBIC | 三次贝塞尔曲线，坐标数据：x0,&nbsp;y0,&nbsp;x1,&nbsp;y1,&nbsp;x2,&nbsp;y2 | 
| VGU_PATH_CMD_SQUAD | 平滑二次贝塞尔曲线，坐标数据：x1,&nbsp;y1 | 
| VGU_PATH_CMD_SCUBIC | 平滑三次贝塞尔曲线，坐标数据：x1,&nbsp;y1,&nbsp;x2,&nbsp;y2 | 
| VGU_PATH_CMD_BUTT | 无效定义 | 


### VGUPathDataType


```
enum VGUPathDataType
```

**描述：**

路径坐标数据类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_DATA_TYPE_S16 | 整型(2&nbsp;bytes) | 
| VGU_DATA_TYPE_S32 | 整型(4&nbsp;bytes) | 
| VGU_DATA_TYPE_F32 | 浮点(4&nbsp;bytes) | 


### VGUResult


```
enum VGUResult
```

**描述：**

错误码定义。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_SUCCESS | 成功 | 
| VGU_NO_SUPPORT | 不支持 | 
| VGU_OPERATION_FAILED | 操作失败 | 
| VGU_OUT_OF_MEMORY | 内存溢出 | 
| VGU_TIMEOUT | 超时 | 
| VGU_INVALID_PARAMETER | 无效参数， | 
| VGU_BUSY | 设备忙 | 
| VGU_NO_CONTEXT | 无上下文 | 


### VGUTransformType


```
enum VGUTransformType
```

**描述：**

变换类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_TRANSFORM_TRANSLATE | 平移变换 | 
| VGU_TRANSFORM_SCALE | 缩放变换 | 
| VGU_TRANSFORM_ROTATE_90 | 旋转90度 | 
| VGU_TRANSFORM_ROTATE_180 | 旋转180度 | 
| VGU_TRANSFORM_ROTATE_270 | 旋转270度 | 
| VGU_TRANSFORM_OTHER | 其他变换 | 


### VGUWrapType


```
enum VGUWrapType
```

**描述：**

图像模式填充延展类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VGU_WRAP_REFLECT | 反射类型 | 
| VGU_WRAP_REPEAT | 重复类型 | 
| VGU_WRAP_BUTT | 无效定义 | 


## **函数说明**


### DeviceInitialize()


```
int32_t DeviceInitialize (DeviceFuncs ** funcs)
```

**描述：**

实现显示设备控制接口的初始化，申请操作显示设备控制接口的资源，并获取对应的操作接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，显示设备控制接口指针，初始化时分配内存，调用者不需要分配内存，调用者获取该指针用于操作显示设备。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### DeviceUninitialize()


```
int32_t DeviceUninitialize (DeviceFuncs * funcs)
```

**描述：**

取消显示设备控制接口的初始化，释放控制接口使用到的资源。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，显示设备控制接口指针，用于释放初始化函数中分配的操作指针内存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GfxInitialize()


```
int32_t GfxInitialize (GfxFuncs ** funcs)
```

**描述：**

获取硬件加速相关的操作接口指针。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，硬件加速模块操作接口指针，调用者不需要分配内存，调用者获取该指针操作硬件加速。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GfxUninitialize()


```
int32_t GfxUninitialize (GfxFuncs * funcs)
```

**描述：**

释放硬件加速相关的操作接口指针。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，硬件加速操作接口指针。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GrallocInitialize()


```
int32_t GrallocInitialize (GrallocFuncs ** funcs)
```

**描述：**

初始化内存模块，并获取内存提供的操作接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，内存模块操作接口指针，初始化内存模块时分配内存，调用者不需要分配内存，调用者获取该指针操作内存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GrallocUninitialize()


```
int32_t GrallocUninitialize (GrallocFuncs * funcs)
```

**描述：**

取消初始化内存模块，并释放内存操作接口指针。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，内存操作接口指针，用于释放内存初始化函数中分配的操作指针内存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### LayerInitialize()


```
int32_t LayerInitialize (LayerFuncs ** funcs)
```

**描述：**

实现图层初始化功能，申请图层使用的资源，并获取图层提供的操作接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，图层操作接口指针，初始化图层时分配内存，调用者不需要分配内存，调用者获取该指针操作图层。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**参见:**

[LayerUninitialize](#layeruninitialize)


### LayerUninitialize()


```
int32_t LayerUninitialize (LayerFuncs * funcs)
```

**描述：**

取消图层初始化功能，释放图层使用到的资源，并释放图层操作接口指针。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，图层操作接口指针，用于释放图层初始化函数中分配的操作指针内存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。

**参见:**

[LayerInitialize](#layerinitialize)


### VGUGradientClearStop()


```
VGUResult VGUGradientClearStop (VGUGradient * gradient)
```

**描述：**

清除ColorStop。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gradient | 输入参数，渐变对象。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUGradientColorStop()


```
VGUResult VGUGradientColorStop (VGUGradient * gradient, const VGUColorStop * colorStop, uint32_t count )
```

**描述：**

对渐变添加ColorStop。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gradient | 输入参数，渐变对象。 | 
| colorStop | 输入参数，ColorStop数组指针。 | 
| count | 输入参数，colorStops总数。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUGradientConic()


```
VGUResult VGUGradientConic (VGUGradient * gradient, VGUScalar cx, VGUScalar cy )
```

**描述：**

创建圆锥渐变对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gradient | 输入参数，渐变对象。 | 
| cx | 输入参数，渐变中心水平坐标。 | 
| cy | 输入参数，渐变中心垂直坐标。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUGradientLinear()


```
VGUResult VGUGradientLinear (VGUGradient * gradient, const VGUPoint * p1, const VGUPoint * p2 )
```

**描述：**

创建线性渐变对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gradient | 输入参数，渐变对象。 | 
| p1 | 输入参数，起点坐标。 | 
| p2 | 输入参数，终点坐标。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUGradientMatrix()


```
VGUResult VGUGradientMatrix (VGUGradient * gradient, const VGUMatrix3 * matrix )
```

**描述：**

设置渐变对象的变换矩阵。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gradient | 输入参数，渐变对象。 | 
| matrix | 输入参数，渐变对象变换矩阵。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUGradientRadial()


```
VGUResult VGUGradientRadial (VGUGradient * gradient, const VGUPoint * p1, VGUScalar r1, const VGUPoint * p2, VGUScalar r2 )
```

**描述：**

创建辐射渐变对象

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| gradient | 输入参数，渐变对象。 | 
| p1 | 输入参数，内圆圆心坐标。 | 
| r1 | 输入参数，内圆半径。 | 
| p2 | 输入参数，外圆圆心坐标。 | 
| r2 | 输入参数，外圆半径。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUInitialize()


```
VGUResult VGUInitialize (VGUFuncs ** funcs)
```

**描述：**

获取硬件加速相关的操作接口指针。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，硬件加速模块操作接口指针，调用者不需要分配内存，调用者获取该指针操作硬件加速。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUMatrixIdentity()


```
VGUResult VGUMatrixIdentity (VGUMatrix3 * matrix)
```

**描述：**

初始化矩阵对象为单位矩阵。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| matrix | 输入参数，变换矩阵对象。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUMatrixRotate()


```
VGUResult VGUMatrixRotate (VGUMatrix3 * matrix, float degree )
```

**描述：**

矩阵变换旋转。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| matrix | 输入参数，变换矩阵对象。 | 
| degree | 输入参数，旋转度数。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUMatrixScale()


```
VGUResult VGUMatrixScale (VGUMatrix3 * matrix, float xScale, float yScale )
```

**描述：**

矩阵变换缩放。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| matrix | 输入参数，变换矩阵对象。 | 
| xScale | 输入参数，水平方向缩放倍数。 | 
| yScale | 输入参数，垂直方向缩放倍数。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUMatrixTranslate()


```
VGUResult VGUMatrixTranslate (VGUMatrix3 * matrix, float x, float y )
```

**描述：**

矩阵变换平移。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| matrix | 输入参数，变换矩阵对象。 | 
| x | 输入参数，水平方向位置。 | 
| y | 输入参数，垂直方向位置。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUPathAppend()


```
VGUResult VGUPathAppend (VGUPath * path, const VGUPath * subpath )
```

**描述：**

添加子路径到当前路径中。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| path | 输入参数，路径对象。 | 
| subpath | 输入参数，存放子路径对象。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUPathClear()


```
VGUResult VGUPathClear (VGUPath * path)
```

**描述：**

清除路径对象内存。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| path | 输入参数，路径对象。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUPathInit()


```
VGUResult VGUPathInit (VGUPath * path, VGUPathDataType type, const uint8_t * segments, int numSegments, const uint8_t * data, bool enAlias, VGURect boundBox )
```

**描述：**

初始化路径对象。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| path | 输入参数，路径对象。 | 
| type | 输入参数，存储路径的数据类型。 | 
| segments | 输入参数，路径的命令缓存。 | 
| numSegments | 输入参数，路径命令总数。 | 
| data | 输入参数，路径命令对应的坐标缓存。 | 
| enAlias | 输入参数，使能抗锯齿。 | 
| boundBox | 输入参数，路径的边界范围。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### VGUUninitialize()


```
VGUResult VGUUninitialize (VGUFuncs * funcs)
```

**描述：**

去初始化硬件加速模块，同时释放硬件加速模块操作函数指针。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| funcs | 输出参数，硬件加速操作接口指针。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


## **变量说明**


### alpha0 [1/2]


```
uint8_t LayerAlpha::alpha0
```

**描述：**

alpha0值，取值范围：[0, 255]


### alpha0 [2/2]


```
uint8_t ISurface::alpha0
```

**描述：**

Alpha0值，取值范围：[0,255]


### alpha1 [1/2]


```
uint8_t LayerAlpha::alpha1
```

**描述：**

alpha1值，取值范围：[0, 255]


### alpha1 [2/2]


```
uint8_t ISurface::alpha1
```

**描述：**

Alpha1值，取值范围：[0,255]


### alphaRopType


```
RopType GfxOpt::alphaRopType
```

**描述：**

Alpha的Rop类型


### bAlphaExt1555


```
bool ISurface::bAlphaExt1555
```

**描述：**

是否使能1555的Alpha扩展


### bAlphaMax255


```
bool ISurface::bAlphaMax255
```

**描述：**

图像alpha最大值为255还是128


### baseAddr


```
void* YUVDescInfo::baseAddr
```

**描述：**

内存的初始地址


### blend


```
VGUBlendType VGUSurface::blend
```

**描述：**

混合叠加模式


### blendType


```
BlendType GfxOpt::blendType
```

**描述：**

混合方式


### boundBox


```
VGURect VGUPath::boundBox
```

**描述：**

路径最大边界


### bpp


```
int32_t LayerInfo::bpp
```

**描述：**

每像素所占bit数


### buffer [1/3]


```
VGUBuffer* VGUMaskLayer::buffer
```

**描述：**

蒙版缓存


### buffer [2/3]


```
VGUBuffer* VGUSurface::buffer
```

**描述：**

位图缓存

VGUSurface::clipRect


### buffer [3/3]


```
VGUBuffer* VGUImage::buffer
```

**描述：**

图像存储缓存


### bYCbCrClut


```
bool ISurface::bYCbCrClut
```

**描述：**

CLUT表是否位于 YCbCr 空间


### cap


```
VGULineCap VGUStrokeAttr::cap
```

**描述：**

线帽类型


### cbcrPhyAddr


```
uint64_t ISurface::cbcrPhyAddr
```

**描述：**

CbCr分量地址


### cbcrStride


```
int32_t ISurface::cbcrStride
```

**描述：**

CbCr分量跨度


### clipPath


```
VGUPath* VGUSurface::clipPath
```

**描述：**

路径剪切域，如果为空，整个表面直接渲染


### clipRect


```
VGURect* VGUSurface::clipRect
```

**描述：**

矩形剪切域，如果为空，整个表面直接渲染


### clipType


```
VGUClipType VGUSurface::clipType
```

**描述：**

表面剪切类型


### clutPhyAddr


```
uint64_t ISurface::clutPhyAddr
```

**描述：**

Clut表首地址，用作颜色扩展或颜色校正


### color [1/5]


```
uint32_t ILine::color
```

**描述：**

线条颜色


### color [2/5]


```
uint32_t ICircle::color
```

**描述：**

圆的颜色


### color [3/5]


```
uint32_t Rectangle::color
```

**描述：**

矩形颜色


### color [4/5]


```
uint32_t VGUColorStop::color
```

**描述：**

偏移位置对应颜色


### color [5/5]


```
uint32_t VGUSolid::color
```

**描述：**

颜色值


### colorKeyFrom


```
ColorKey GfxOpt::colorKeyFrom
```

**描述：**

色键模式


### colorRopType


```
RopType GfxOpt::colorRopType
```

**描述：**

颜色的Rop类型


### colorStops


```
VGUColorStop* VGUGradient::colorStops
```

**描述：**

渐变停止颜色数组指针


### Commit


```
int32_t(* DeviceFuncs::Commit) (uint32_t devId, int32_t *fence)
```

**描述：**

提交合成送显请求。

图形服务通过该接口向接口实现层提交合成送显请求，如果有硬件合成层，接口实现层需要在这时进行合成，并且把最终合成的数据送到硬件进行显示。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| fences | 输出参数，fence首地址，指向fence数组的首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### conic


```
VGUConic VGUGradient::conic
```

**描述：**

圆锥渐变对象


### CreateVirtualDisplay


```
int32_t(* DeviceFuncs::CreateVirtualDisplay) (uint32_t width, uint32_t height, int32_t *format, uint32_t *devId)
```

**描述：**

创建虚拟显示设备。

该接口用于创建一个虚拟显示设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| width | 输入参数，指定显示设备的像素宽度。 | 
| height | 输入参数，指定显示设备的像素高度。 | 
| format | 输出参数，指定显示设备的像素格式。&nbsp;详情参考[PixelFormat](#pixelformat)，接口实现层可以根据硬件需求，修改format并返回给图形服务。 | 
| devId | 输出参数，用于接口层返回创建的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### cx


```
VGUScalar VGUConic::cx
```

**描述：**

圆弧中心x坐标


### cy


```
VGUScalar VGUConic::cy
```

**描述：**

圆弧中心y坐标


### data [1/2]


```
BufferData LayerBuffer::data
```

**描述：**

图层buffer数据


### data [2/2]


```
uint8_t* VGUPath::data
```

**描述：**

存放路径命令对应坐标数据


### DeinitVgu


```
VGUResult(* VGUFuncs::DeinitVgu) (void)
```

**描述：**

去初始化硬件加速。

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。

**参见:**

[InitVgu](#initvgu)


### DestroyVirtualDisplay


```
int32_t(* DeviceFuncs::DestroyVirtualDisplay) (uint32_t devId)
```

**描述：**

销毁虚拟显示设备。

该接口用于销毁指定的虚拟显示设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### enableRop


```
bool GfxOpt::enableRop
```

**描述：**

Rop功能使能位


### enableScale


```
bool GfxOpt::enableScale
```

**描述：**

缩放功能使能位


### enAlias


```
bool VGUPath::enAlias
```

**描述：**

抗锯齿开关


### enColorFmt


```
PixelFormat ISurface::enColorFmt
```

**描述：**

图像格式


### enGlobalAlpha [1/2]


```
bool LayerAlpha::enGlobalAlpha
```

**描述：**

全局alpha使能标志


### enGlobalAlpha [2/2]


```
bool GfxOpt::enGlobalAlpha
```

**描述：**

全局alpha使能位


### enPixelAlpha [1/2]


```
bool LayerAlpha::enPixelAlpha
```

**描述：**

像素alpha使能标志


### enPixelAlpha [2/2]


```
bool GfxOpt::enPixelAlpha
```

**描述：**

像素alpha使能位


### expectedSize


```
uint32_t AllocInfo::expectedSize
```

**描述：**

申请内存大小


### fd


```
int32_t ExtDataHandle::fd
```

**描述：**

句柄 fd, -1代表不支持


### fenceId


```
int32_t LayerBuffer::fenceId
```

**描述：**

buffer 的fence号r


### filter


```
VGUFilter VGUSurface::filter
```

**描述：**

图像滤波类型


### format [1/2]


```
PixelFormat AllocInfo::format
```

**描述：**

申请内存格式


### format [2/2]


```
PixelFormat VerifyAllocInfo::format
```

**描述：**

分配内存的像素格式


### formatCount


```
uint32_t HDRCapability::formatCount
```

**描述：**

支持的HDR格式的数量


### formats


```
HDRFormat* HDRCapability::formats
```

**描述：**

支持的HDR格式的数组首地址


### freshRate


```
uint32_t DisplayModeInfo::freshRate
```

**描述：**

刷新速率


### gAlpha


```
uint8_t LayerAlpha::gAlpha
```

**描述：**

全局alpha值，取值范围：[0, 255]


### GetDisplayBacklight


```
int32_t(* DeviceFuncs::GetDisplayBacklight) (uint32_t devId, uint32_t *level)
```

**描述：**

获取显示设备当前的背光值。

图形服务可以通过该接口获取设置显示设备的背光值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| level | 输出参数，保存对应设备的背光值，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayCapability


```
int32_t(* DeviceFuncs::GetDisplayCapability) (uint32_t devId, DisplayCapability *info)
```

**描述：**

获取显示设备能力集。

图形服务可以通过该接口获取显示设备具备哪些显示能力。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| info | 输出参数，设备支持的能力级信息，详情参考[DisplayCapability](_display_capability.md)。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayColorGamut


```
int32_t(* DeviceFuncs::GetDisplayColorGamut) (uint32_t devId, ColorGamut *gamut)
```

**描述：**

获取显示设备当前的色域模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamut | 输出参数，保存对应设备的色域模式，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayCompChange


```
int32_t(* DeviceFuncs::GetDisplayCompChange) (uint32_t devId, uint32_t *num, uint32_t *Layers, int32_t *type)
```

**描述：**

获取显示设备合成类型有变化的layer。

在合成准备阶段，显示设备会根据设备的合成能力修改图层的合成类型，该接口会返回哪些图层合成类型发生了变化。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，表示合成类型发生了变化的图层数量。 | 
| Layers | 输出参数，指向图层数组首地址。 | 
| type | 输出参数，指向合成类型数组首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayGamutMap


```
int32_t(* DeviceFuncs::GetDisplayGamutMap) (uint32_t devId, GamutMap *gamutMap)
```

**描述：**

获取显示设备当前的色域映射模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamutMap | 输出参数，保存对应设备的色域映射模式，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayMode


```
int32_t(* DeviceFuncs::GetDisplayMode) (uint32_t devId, uint32_t *modeId)
```

**描述：**

获取显示设备当前的显示模式。

图形服务可以通过该接口获取显示设备当前的显示模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| modeId | 输出参数，存放当前设备的显示模式ID，&nbsp;由接口实现层进行数据的写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayPowerStatus


```
int32_t(* DeviceFuncs::GetDisplayPowerStatus) (uint32_t devId, DispPowerStatus *status)
```

**描述：**

获取显示设备当前的电源状态。

图形服务可以通过该接口获设置显示设备的电源状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| status | 输出参数，保存对应设备的电源状态，由接口实现层进行状态的写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayProperty


```
int32_t(* DeviceFuncs::GetDisplayProperty) (uint32_t devId, uint32_t id, uint64_t *value)
```

**描述：**

获取显示设备属性值。

图形服务可以通过该接口获取显示设备具体的属性值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| id | 输入参数，由接口GetDisplayCapability返回属性ID。 | 
| level | 输出参数，属性ID对应的属性值，由接口实现层写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplayReleaseFence


```
int32_t(* DeviceFuncs::GetDisplayReleaseFence) (uint32_t devId, uint32_t *num, uint32_t *layers, int32_t *fences)
```

**描述：**

获取显示图层fence。

图形服务在调用接口Commit后，需要通过该接口获取图层的fence信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，图层个数。 | 
| layers | 输出参数，图层首地址，指向图层数组的首地址。 | 
| fences | 输出参数，fence首地址，指向fence数组的首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplaySupportedColorGamuts


```
int32_t(* DeviceFuncs::GetDisplaySupportedColorGamuts) (uint32_t devId, uint32_t *num, ColorGamut *gamuts)
```

**描述：**

获取显示设备支持的色域信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，设备支持的色域数组个数。 | 
| gamuts | 输出参数，色域首地址，指向色域数组首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetDisplaySupportedModes


```
int32_t(* DeviceFuncs::GetDisplaySupportedModes) (uint32_t devId, uint32_t *num, DisplayModeInfo *modes)
```

**描述：**

获取显示设备支持的显示模式信息。

图形服务可以通过该接口获取到显示设备支持哪些显示模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，设备支持的模式数量。 | 
| modes | 输出参数，设备支持的所有模式信息，包括所有能支持的分辨率和刷新率，每一个模式实现层都有一个Id与之对应，在获取当前模式&nbsp;和设置当前模式时都会使用到，详情参考&nbsp;[DisplayModeInfo](_display_mode_info.md)。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetHDRCapabilityInfos


```
int32_t(* DeviceFuncs::GetHDRCapabilityInfos) (uint32_t devId, HDRCapability *info)
```

**描述：**

获取显示设备支持的HDR属性信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| info | 输出参数，保存对应设备的HDR属性信息，由接口实现层进行写入。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetSupportedMetadataKey


```
int32_t(* DeviceFuncs::GetSupportedMetadataKey) (uint32_t devId, uint32_t *num, HDRMetadataKey *keys)
```

**描述：**

获取显示设备支持的 HDRMetadataKey。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输出参数，设备支持的HDRMetadataKey数组个数。 | 
| keys | 输出参数，HDRMetadataKey首地址,&nbsp;指向HDRMetadataKey数组首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### GetWriteBackFrame


```
int32_t(* DeviceFuncs::GetWriteBackFrame) (uint32_t devId, BufferHandle *buffer, int32_t *fence)
```

**描述：**

获取显示设备的回写帧。

该接口用来获取devId指定的回写点数据，接口实现层将显示设备回写点的数据写入到设置的缓存中。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| buffer | 输出参数，回写点数据缓存。 | 
| fence | 输出参数，同步栅栏，图形服务在调用该接口时，需要将Buffer的release&nbsp;fence&nbsp;传入，标记该缓存是否可以被写入，接口实现层在接口返回前需要将buffer的acquirce&nbsp;fence&nbsp;写入回传给图形服务，用来标记回写数据是否已经写入缓存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### globalAlpha


```
uint32_t GfxOpt::globalAlpha
```

**描述：**

全局alpha的值


### gradient


```
VGUGradient* VGUPaintStyle::gradient
```

**描述：**

渐变对象


### h [1/2]


```
int32_t IRect::h
```

**描述：**

矩形框高度


### h [2/2]


```
VGUScalar VGURect::h
```

**描述：**

矩形高度


### hdl


```
BufferHandle* LayerBuffer::hdl
```

**描述：**

图层buffer句柄


### height [1/8]


```
uint32_t DisplayInfo::height
```

**描述：**

显示屏高度


### height [2/8]


```
int32_t LayerInfo::height
```

**描述：**

图层高度


### height [3/8]


```
int32_t LayerBuffer::height
```

**描述：**

buffer高度


### height [4/8]


```
int32_t ISurface::height
```

**描述：**

图像高度


### height [5/8]


```
int32_t DisplayModeInfo::height
```

**描述：**

像素高度


### height [6/8]


```
uint32_t AllocInfo::height
```

**描述：**

申请内存高度


### height [7/8]


```
uint32_t VerifyAllocInfo::height
```

**描述：**

分配内存的高度


### height [8/8]


```
uint32_t VGUBuffer::height
```

**描述：**

位图高度


### id


```
int32_t DisplayModeInfo::id
```

**描述：**

模式ID


### image


```
VGUImage* VGUPattern::image
```

**描述：**

图像对象


### InitVgu


```
VGUResult(* VGUFuncs::InitVgu) (void)
```

**描述：**

初始化硬件加速。

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。

**参见:**

[DeinitVgu](#deinitvgu)


### InvokeDisplayCmd


```
int32_t(* DeviceFuncs::InvokeDisplayCmd) (uint32_t devId,...)
```

**描述：**

调用显示设备命令。

该接口用于图形服务和接口实现层之间的接口扩展，如果由临时接口新增可以通过该接口进行扩展，不用增加新的接口定义。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### join


```
VGUJointType VGUStrokeAttr::join
```

**描述：**

联结类型


### key


```
HDRMetadataKey HDRMetaData::key
```

**描述：**

HDR元数据关键字


### linear


```
VGULinear VGUGradient::linear
```

**描述：**

线性渐变对象


### m


```
float VGUMatrix3::m[3][3]
```

**描述：**

3x3变换矩阵


### mask


```
VGUMaskLayer* VGUSurface::mask
```

**描述：**

蒙版图层，可以为空


### matrix [1/2]


```
VGUMatrix3* VGUImage::matrix
```

**描述：**

图像矩阵变换，该参数为空，则内部使用单位变换矩阵


### matrix [2/2]


```
VGUMatrix3* VGUGradient::matrix
```

**描述：**

针对渐变对象的变换矩阵


### maxAverageLum


```
float HDRCapability::maxAverageLum
```

**描述：**

最大的平均光亮度luminance值


### maxLum


```
float HDRCapability::maxLum
```

**描述：**

最大的光亮度luminance值


### minLum


```
float HDRCapability::minLum
```

**描述：**

最小的光亮度luminance值


### mirrorType


```
MirrorType GfxOpt::mirrorType
```

**描述：**

镜像类型


### miterLimit


```
float VGUStrokeAttr::miterLimit
```

**描述：**

最大斜切长度


### name [1/2]


```
char PropertyObject::name[PROPERTY_NAME_LEN]
```

**描述：**

属性名称


### name [2/2]


```
char DisplayCapability::name[PROPERTY_NAME_LEN]
```

**描述：**

显示设备名称


### numSegments


```
int32_t VGUPath::numSegments
```

**描述：**

路径命令总数


### opacity [1/3]


```
uint8_t VGUImage::opacity
```

**描述：**

透明度，范围0~255


### opacity [2/3]


```
uint8_t VGUGradient::opacity
```

**描述：**

透明度，范围0~255


### opacity [3/3]


```
uint8_t VGUSolid::opacity
```

**描述：**

透明度，取值范围 0 ~ 255。


### pattern


```
VGUPattern* VGUPaintStyle::pattern
```

**描述：**

图片模式对象


### phyAddr [1/3]


```
uint64_t BufferData::phyAddr
```

**描述：**

物理内存地址


### phyAddr [2/3]


```
uint64_t ISurface::phyAddr
```

**描述：**

图像首地址


### phyAddr [3/3]


```
uint64_t VGUBuffer::phyAddr
```

**描述：**

位图缓存的物理地址


### phyHeight


```
uint32_t DisplayCapability::phyHeight
```

**描述：**

物理高度


### phyWidth


```
uint32_t DisplayCapability::phyWidth
```

**描述：**

物理宽度


### pitch


```
int32_t LayerBuffer::pitch
```

**描述：**

一行数据所占字节数


### pixelFormat


```
VGUPixelFormat VGUBuffer::pixelFormat
```

**描述：**

像素格式


### pixFormat [1/2]


```
PixelFormat LayerInfo::pixFormat
```

**描述：**

图层像素格式


### pixFormat [2/2]


```
PixelFormat LayerBuffer::pixFormat
```

**描述：**

buffer像素格式r


### PrepareDisplayLayers


```
int32_t(* DeviceFuncs::PrepareDisplayLayers) (uint32_t devId, bool *needFlushFb)
```

**描述：**

显示设备合成前准备。

图形服务在合成前需要通过该接口通知显示设备进行合成前的准备工作。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| needFlushFb | 输出参数，接口实现层通过该参数指示图形服务在commit前是否需要通过[SetDisplayClientBuffer](#setdisplayclientbuffer)重新设置显示帧存。&nbsp;true表示需要设置显示帧存，false表示不需要。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### propertyCount


```
uint32_t DisplayCapability::propertyCount
```

**描述：**

属性数组大小


### propId


```
uint32_t PropertyObject::propId
```

**描述：**

属性ID


### props


```
PropertyObject* DisplayCapability::props
```

**描述：**

属性数组


### QueryCapability


```
int32_t(* VGUFuncs::QueryCapability) (uint32_t cap)
```

**描述：**

查询硬件能力集。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| cap | 输入参数，待查询能力。该参数类型定义参考&nbsp;[VGUCapability](#vgucapability)。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### r


```
int32_t ICircle::r
```

**描述：**

圆的半径


### r0


```
VGUScalar VGURadial::r0
```

**描述：**

内圈圆半径


### r1


```
VGUScalar VGURadial::r1
```

**描述：**

外圈圆半径


### radial


```
VGURadial VGUGradient::radial
```

**描述：**

辐射渐变对象


### rect [1/3]


```
IRect Rectangle::rect
```

**描述：**

矩形区域


### rect [2/3]


```
VGURect* VGUMaskLayer::rect
```

**描述：**

蒙版矩形


### rect [3/3]


```
VGURect* VGUImage::rect
```

**描述：**

图像截取矩形，该参数为空，则截取整个图像


### RegDisplayRefreshCallback


```
int32_t(* DeviceFuncs::RegDisplayRefreshCallback) (uint32_t devId, RefreshCallback callback, void *data)
```

**描述：**

刷新请求回调。

注册刷新请求事件回调，当实现层有刷新需求时，实现层通过回调注册的接口通知图形服务。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| callback | 输入参数，刷新请求事件回调实例，当有接口实现层有刷新请求时，需要通过该实例通知图形服务。 | 
| data | 输出参数，图形服务携带的私有数据，在事件回调接口中需要返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### RegDisplayVBlankCallback


```
int32_t(* DeviceFuncs::RegDisplayVBlankCallback) (uint32_t devId, VBlankCallback callback, void *data)
```

**描述：**

注册VBlank事件回调。

注册VBlank事件回调，当有VBlank事件发生时接口实现层需要回调注册的接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| callback | 输入参数，VBlank事件回调实例，当有VBlank事件发生时并且DisplayVsync处于Enable状态，接口实现层需要通过该实例通知图形服务。 | 
| data | 输出参数，图形服务携带的私有数据，在事件回调接口中需要返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### RegHotPlugCallback


```
int32_t(* DeviceFuncs::RegHotPlugCallback) (HotPlugCallback callback, void *data)
```

**描述：**

注册热插拔事件回调。

注册热插拔事件回调，当有热插拔事件发生时接口实现层需要回调注册的接口。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callback | 输入参数，热插拔事件回调实例，当有热插拔事件发生时，接口实现层需要通过该实例通知图形服务。 | 
| data | 输出参数，图形服务携带的私有数据，在事件回调接口中需要返回给图形服务。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### RenderBlit


```
VGUResult(* VGUFuncs::RenderBlit) (VGUSurface *target, const VGUImage *src, uint32_t color)
```

**描述：**

对图像进行搬移操作。

搬移过程中同时进行颜色空间转换，矩阵变换操作。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| target | 输入参数，渲染目标表面。 | 
| src | 输入参数，待叠加源图像。 | 
| color | 输入参数，参与混合的颜色值。如果颜色值为0，则不参与混合操作。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### RenderBlitN


```
VGUResult(* VGUFuncs::RenderBlitN) (VGUSurface *target, const VGUImage *src, uint16_t count, uint32_t color)
```

**描述：**

对多个源图像进行叠加操作。

搬移过程中同时进行颜色空间转换，矩阵变换操作。该接口支持多个源图形同时叠加到目标表面， 对于硬件支持源图像数目可以通过[QueryCapability](#querycapability)接口查询**。**

**参数**：


  | 名称 | 描述 | 
| -------- | -------- |
| target | 输入参数，渲染目标表面。 | 
| src | 输入参数，待叠加源图像数组。 | 
| count | 输入参数，待叠加源图像个数。 | 
| color | 输入参数，参与混合的颜色值。如果颜色值为0，则不参与混合操作。 | 


**返回**：


VGU_SUCCESS 表示执行成功。


其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### RenderBlur


```
VGUResult(* VGUFuncs::RenderBlur) (VGUSurface *target, uint16_t blur)
```

**描述：**

对目标表面进行模糊处理。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| target | 输入参数，渲染目标表面。 | 
| blur | 输入参数，模糊半径。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### RenderCancel


```
VGUResult(* VGUFuncs::RenderCancel) ()
```

**描述：**

取消硬件加速渲染。

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### RenderClearRect


```
VGUResult(* VGUFuncs::RenderClearRect) (VGUSurface *target, const VGURect *rect, uint32_t color, uint8_t opacity)
```

**描述：**

对指定矩形进行颜色清除操作。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| target | 输入参数，渲染目标表面。 | 
| rect | 输入参数，待填充矩形大小，如果该参数为空，则整个表面清除。 | 
| color | 输入参数，填充颜色。 | 
| opacity | 输入参数，填充透明度。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### RenderFill


```
VGUResult(* VGUFuncs::RenderFill) (VGUSurface *target, const VGUPath *path, const VGUMatrix3 *matrix, const VGUFillAttr *attr, const VGUPaintStyle *style)
```

**描述：**

使用指定的渲染对象来填充路径。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| target | 输入参数，渲染目标表面。 | 
| path | 输入参数，路径对象。 | 
| matrix | 输入参数，变换矩阵对象。&nbsp;如果该参数为空，默认为单位矩阵。 | 
| attr | 输入参数，填充属性。 | 
| style | 输入参数，绘制对象。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### RenderStroke


```
VGUResult(* VGUFuncs::RenderStroke) (VGUSurface *target, const VGUPath *path, const VGUMatrix3 *matrix, const VGUStrokeAttr *attr, const VGUPaintStyle *style)
```

**描述：**

使用指定的渲染对象来描边路径。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| target | 输入参数，渲染目标表面。 | 
| path | 输入参数，路径对象。 | 
| matrix | 输入参数，变换矩阵对象。&nbsp;如果该参数为空，默认为单位矩阵。 | 
| attr | 输入参数，描边属性。 | 
| style | 输入参数，绘制对象。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### RenderSync


```
VGUResult(* VGUFuncs::RenderSync) (int32_t timeOut)
```

**描述：**

同步硬件加速模块绘制或搬移操作。

该函数将阻塞等待硬件绘制完成后继续运行。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| timeOut | 输入参数，该参数表示硬件加速同步等待超时时间。&nbsp;值为**0**表示没有等待时间。 | 

**返回:**

VGU_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[VGUResult](#vguresult)。


### reserve


```
int32_t ExtDataHandle::reserve[0]
```

**描述：**

reserve数组


### reserveInts


```
uint32_t ExtDataHandle::reserveInts
```

**描述：**

reserve数组的个数


### rotAngle


```
int32_t DisplayInfo::rotAngle
```

**描述：**

显示屏旋转角度


### rotateType


```
TransformType GfxOpt::rotateType
```

**描述：**

旋转类型


### rule


```
VGUFillRule VGUFillAttr::rule
```

**描述：**

填充规格


### segment


```
uint8_t* VGUPath::segment
```

**描述：**

存放路径命令数据


### SetDisplayBacklight


```
int32_t(* DeviceFuncs::SetDisplayBacklight) (uint32_t devId, uint32_t level)
```

**描述：**

设置显示设备当前的背光值。

图形服务可以通过该接口获设置显示设备的背光值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| level | 输入参数，表示需要设置的背光值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientBuffer


```
int32_t(* DeviceFuncs::SetDisplayClientBuffer) (uint32_t devId, const BufferHandle *buffer, int32_t fence)
```

**描述：**

设置显示设备的显示缓存。

图形服务可以通过该接口将显示缓存设置给显示设备，显示设备硬件合成结果将会存放在该显示缓存中。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| buffer | 输入参数，显示缓存。 | 
| fence | 输入参数，同步栅栏，标识显示缓存是否可以访问，有图形服务创建和释放，接口实现层需要等待同步栅栏发送信号后才能使用显示缓存。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientCrop


```
int32_t(* DeviceFuncs::SetDisplayClientCrop) (uint32_t devId, IRect *rect)
```

**描述：**

设置显示设备的裁剪区域。

图形服务可以通过该接口设置显示设备的ClientBuffer的裁剪区域，裁剪区域不能超过ClientBuffer的大小。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| rect | 输入参数，ClientBuffer的裁剪区域。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientDamage


```
int32_t(* DeviceFuncs::SetDisplayClientDamage) (uint32_t devId, uint32_t num, IRect *rect)
```

**描述：**

设置显示设备的显示脏区。

图形服务可以通过该接口设置显示设备脏区，接口实现层可以根据该区域进行区域刷新，脏区是由多个矩形区域组合起来的。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| num | 输入参数，矩形个数。 | 
| rect | 输入参数，区域矩形指针，指向矩形数组的首地址。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayClientDestRect


```
int32_t(* DeviceFuncs::SetDisplayClientDestRect) (uint32_t devId, IRect *rect)
```

**描述：**

设置显示设备的显示区域。

图形服务可以通过该接口设置显示设备的显示区域。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| rect | 输入参数，显示区域。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayColorGamut


```
int32_t(* DeviceFuncs::SetDisplayColorGamut) (uint32_t devId, ColorGamut gamut)
```

**描述：**

设置显示设备当前的色域模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamut | 输入参数，表示需要设置的色域模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayColorTransform


```
int32_t(* DeviceFuncs::SetDisplayColorTransform) (uint32_t devId, const float *matrix)
```

**描述：**

设置显示设备当前的4x4的颜色转换矩阵。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| matrix | 输入参数，表示需要设置的颜色转换模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayGamutMap


```
int32_t(* DeviceFuncs::SetDisplayGamutMap) (uint32_t devId, GamutMap gamutMap)
```

**描述：**

设置显示设备当前的色域映射模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| gamutMap | 输入参数，表示需要设置的色域映射模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayMode


```
int32_t(* DeviceFuncs::SetDisplayMode) (uint32_t devId, uint32_t modeId)
```

**描述：**

设置显示设备的显示模式。

图形服务可以通过该接口获设置显示设备的显示模式。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| modeId | 输入参数，指明需要设置的模式ID，接口实现层将设备切换到该参数对应的显示模式。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayPowerStatus


```
int32_t(* DeviceFuncs::SetDisplayPowerStatus) (uint32_t devId, DispPowerStatus status)
```

**描述：**

设置显示设备当前的电源状态。

图形服务可以通过该接口获设置显示设备的电源状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| status | 输入参数，表示需要设置的电源状态。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayProperty


```
int32_t(* DeviceFuncs::SetDisplayProperty) (uint32_t devId, uint32_t id, uint64_t value)
```

**描述：**

设置显示设备属性值。

图形服务可以通过该接口设置显示设备具体的属性值。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| id | 输入参数，由接口GetDisplayCapability返回属性ID。 | 
| value | 输入参数，需要设置的属性值。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetDisplayVsyncEnabled


```
int32_t(* DeviceFuncs::SetDisplayVsyncEnabled) (uint32_t devId, bool enabled)
```

**描述：**

使能垂直同步信号。

图形服务可以通过该接口使能或取消垂直同步信号，当有垂直同步信号产生时，接口实现层需要回调图形服务通过RegDisplayVBlankCallback注册的 VBlankCallback 回调。 图形服务在需要刷新显示时需要使能垂直同步信号，在收到VBlankCallback事件回调时再进行合成送显，不需要刷新显示时需要取消垂直同步信号。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| enabled | 输入参数，使能状态，true表示能，false表示不能。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### SetVirtualDisplayBuffer


```
int32_t(* DeviceFuncs::SetVirtualDisplayBuffer) (uint32_t devId, BufferHandle *buffer, int32_t fence)
```

**描述：**

设置虚拟屏的输出缓存。

该接口用于设置虚拟屏输出缓存，接口实现层需要将虚拟屏的输出放入到该缓存中，接口实现层需要等待同步栅栏发送信号后才能使用缓存。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devId | 输入参数，指示需要操作的设备ID。 | 
| buffer | 输出参数，输出缓存。 | 
| fence | 输出参数，同步栅栏。 | 

**返回:**

DISPLAY_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](#disperrcode)。


### solid


```
VGUSolid* VGUPaintStyle::solid
```

**描述：**

颜色对象


### spread


```
VGUFillSpread VGUGradient::spread
```

**描述：**

渐变延伸模式


### stop


```
float VGUColorStop::stop
```

**描述：**

颜色偏移位置，取值范围是 0.0 ~ 1.0。


### stopCount


```
uint16_t VGUGradient::stopCount
```

**描述：**

渐变停止颜色个数


### stride [1/2]


```
int32_t ISurface::stride
```

**描述：**

图像跨度


### stride [2/2]


```
uint32_t VGUBuffer::stride
```

**描述：**

位图stride


### supportLayers


```
uint32_t DisplayCapability::supportLayers
```

**描述：**

支持的图层数


### supportWriteBack


```
bool DisplayCapability::supportWriteBack
```

**描述：**

是否支持回写


### time


```
int64_t PresentTimestamp::time
```

**描述：**

类型对应的值


### type [1/7]


```
LayerType LayerInfo::type
```

**描述：**

图层类型，包括图形层、视频层和媒体播放模式


### type [2/7]


```
InterfaceType DisplayCapability::type
```

**描述：**

显示屏接口类型


### type [3/7]


```
PresentTimestampType PresentTimestamp::type
```

**描述：**

上屏时间戳类型


### type [4/7]


```
VGUPathDataType VGUPath::type
```

**描述：**

路径数据存储类型


### type [5/7]


```
uint32_t VGUMatrix3::type
```

**描述：**

矩阵变换类型，简单变换为缩放，平移，90度倍数旋转


### type [6/7]


```
VGUGradientType VGUGradient::type
```

**描述：**

渐变类型


### type [7/7]


```
VGUPaintType VGUPaintStyle::type
```

**描述：**

渲染类型


### uOffset


```
size_t YUVDescInfo::uOffset
```

**描述：**

U的偏移量


### usage [1/2]


```
uint64_t AllocInfo::usage
```

**描述：**

申请内存的使用场景


### usage [2/2]


```
uint64_t VerifyAllocInfo::usage
```

**描述：**

内存的用处


### uvStep


```
size_t YUVDescInfo::uvStep
```

**描述：**

UV的step信息


### uvStride


```
size_t __attribute__::uvStride
```

**描述：**

UV的stride信息


### value [1/2]


```
uint64_t PropertyObject::value
```

**描述：**

属性值


### value [2/2]


```
float HDRMetaData::value
```

**描述：**

关键字对应的值


### virAddr [1/2]


```
void* BufferData::virAddr
```

**描述：**

虚拟内存地址


### virAddr [2/2]


```
void* VGUBuffer::virAddr
```

**描述：**

位图缓存的虚拟地址


### virtualDispCount


```
uint32_t DisplayCapability::virtualDispCount
```

**描述：**

支持的虚拟屏数


### vOffset


```
size_t YUVDescInfo::vOffset
```

**描述：**

V的偏移量


### w [1/2]


```
int32_t IRect::w
```

**描述：**

矩形框宽度


### w [2/2]


```
VGUScalar VGURect::w
```

**描述：**

矩形宽度


### width [1/9]


```
uint32_t DisplayInfo::width
```

**描述：**

显示屏宽度


### width [2/9]


```
int32_t LayerInfo::width
```

**描述：**

图层宽度


### width [3/9]


```
int32_t LayerBuffer::width
```

**描述：**

buffer宽度


### width [4/9]


```
int32_t ISurface::width
```

**描述：**

图像宽度


### width [5/9]


```
int32_t DisplayModeInfo::width
```

**描述：**

像素宽度


### width [6/9]


```
uint32_t AllocInfo::width
```

**描述：**

申请内存宽度


### width [7/9]


```
uint32_t VerifyAllocInfo::width
```

**描述：**

分配内存的宽度


### width [8/9]


```
uint32_t VGUBuffer::width
```

**描述：**

位图宽度


### width [9/9]


```
float VGUStrokeAttr::width
```

**描述：**

线宽


### wrapx


```
VGUWrapType VGUPattern::wrapx
```

**描述：**

图像水平方向平铺类型


### wrapy


```
VGUWrapType VGUPattern::wrapy
```

**描述：**

图像垂直方向平铺类型


### x [1/4]


```
int32_t IRect::x
```

**描述：**

矩形框起始x坐标


### x [2/4]


```
int32_t ICircle::x
```

**描述：**

圆心x坐标


### x [3/4]


```
VGUScalar VGUPoint::x
```

**描述：**

点水平坐标


### x [4/4]


```
VGUScalar VGURect::x
```

**描述：**

矩形水平起始坐标


### x0 [1/2]


```
int32_t ILine::x0
```

**描述：**

线条起点的x坐标


### x0 [2/2]


```
VGUScalar VGURadial::x0
```

**描述：**

内圈圆心水平坐标


### x1 [1/3]


```
int32_t ILine::x1
```

**描述：**

线条终点的x坐标


### x1 [2/3]


```
VGUScalar VGULinear::x1
```

**描述：**

线性渐变起点水平坐标


### x1 [3/3]


```
VGUScalar VGURadial::x1
```

**描述：**

外圈圆心水平坐标


### x2


```
VGUScalar VGULinear::x2
```

**描述：**

线性渐变终点水平坐标


### y [1/4]


```
int32_t IRect::y
```

**描述：**

矩形框起始y坐标


### y [2/4]


```
int32_t ICircle::y
```

**描述：**

圆心y坐标r


### y [3/4]


```
VGUScalar VGUPoint::y
```

**描述：**

点垂直坐标


### y [4/4]


```
VGUScalar VGURect::y
```

**描述：**

矩形垂直起始坐标


### y0 [1/2]


```
int32_t ILine::y0
```

**描述：**

线条起点的y坐标


### y0 [2/2]


```
VGUScalar VGURadial::y0
```

**描述：**

内圈圆心垂直坐标


### y1 [1/3]


```
int32_t ILine::y1
```

**描述：**

线条终点的y坐标


### y1 [2/3]


```
VGUScalar VGULinear::y1
```

**描述：**

线性渐变起点垂直坐标


### y1 [3/3]


```
VGUScalar VGURadial::y1
```

**描述：**

外圈圆心垂直坐标


### y2


```
VGUScalar VGULinear::y2
```

**描述：**

线性渐变终点垂直坐标


### yOffset


```
size_t YUVDescInfo::yOffset
```

**描述：**

Y的偏移量


### yStride


```
size_t YUVDescInfo::yStride
```

**描述：**

Y的stride信息
