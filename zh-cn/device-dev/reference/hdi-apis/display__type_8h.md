# display_type.h


## **概述**

显示类型定义，定义显示驱动接口所使用的数据类型。

**Since:**

1.0

**Version:**

2.0

**相关模块:**

[Display](_display.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [DisplayInfo](_display_info.md) | 定义显示信息结构体。 | 
| [LayerInfo](_layer_info.md) | 定义图层信息结构体。 | 
| [LayerAlpha](_layer_alpha.md) | 定义图层Alpha信息的结构体。 | 
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


### 宏定义

  | 名称 | 描述 | 
| -------- | -------- |
| [PROPERTY_NAME_LEN](_display.md#property_name_len)&nbsp;&nbsp;50 | 属性名字长度。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [DispErrCode](_display.md#disperrcode){&nbsp;DISPLAY_SUCCESS&nbsp;=&nbsp;0,&nbsp;DISPLAY_FAILURE&nbsp;=&nbsp;-1,&nbsp;DISPLAY_FD_ERR&nbsp;=&nbsp;-2,&nbsp;DISPLAY_PARAM_ERR&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;DISPLAY_NULL_PTR&nbsp;=&nbsp;-4,&nbsp;DISPLAY_NOT_SUPPORT&nbsp;=&nbsp;-5,&nbsp;DISPLAY_NOMEM&nbsp;=&nbsp;-6,&nbsp;DISPLAY_SYS_BUSY&nbsp;=&nbsp;-7,&nbsp;&nbsp;&nbsp;DISPLAY_NOT_PERM&nbsp;=&nbsp;-8&nbsp;} | 返回值类型定义。 | 
| [LayerType](_display.md#layertype){&nbsp;LAYER_TYPE_GRAPHIC,&nbsp;LAYER_TYPE_OVERLAY,&nbsp;LAYER_TYPE_SDIEBAND,&nbsp;LAYER_TYPE_CURSOR,&nbsp;&nbsp;&nbsp;LAYER_TYPE_BUTT&nbsp;} | 图层类型定义。 | 
| {&nbsp;HBM_USE_CPU_READ&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;0),&nbsp;HBM_USE_CPU_WRITE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;1),&nbsp;HBM_USE_MEM_MMZ&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;2),&nbsp;HBM_USE_MEM_DMA&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;3),&nbsp;&nbsp;&nbsp;HBM_USE_MEM_SHARE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;4),&nbsp;HBM_USE_MEM_MMZ_CACHE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;5),&nbsp;HBM_USE_MEM_FB&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;6),&nbsp;HBM_USE_ASSIGN_SIZE&nbsp;=&nbsp;(1&nbsp;&lt;&lt;&nbsp;7)&nbsp;} | 定义缓冲区使用。 | 
| [PixelFormat](_display.md#pixelformat){&nbsp;PIXEL_FMT_CLUT8&nbsp;=&nbsp;0,&nbsp;PIXEL_FMT_CLUT1,&nbsp;PIXEL_FMT_CLUT4,&nbsp;PIXEL_FMT_RGB_565,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_5658,&nbsp;PIXEL_FMT_RGBX_4444,&nbsp;PIXEL_FMT_RGBA_4444,&nbsp;PIXEL_FMT_RGB_444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBX_5551,&nbsp;PIXEL_FMT_RGBA_5551,&nbsp;PIXEL_FMT_RGB_555,&nbsp;PIXEL_FMT_RGBX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_8888,&nbsp;PIXEL_FMT_RGB_888,&nbsp;PIXEL_FMT_BGR_565,&nbsp;PIXEL_FMT_BGRX_4444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_4444,&nbsp;PIXEL_FMT_BGRX_5551,&nbsp;PIXEL_FMT_BGRA_5551,&nbsp;PIXEL_FMT_BGRX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_8888,&nbsp;PIXEL_FMT_YUV_422_I,&nbsp;PIXEL_FMT_YCBCR_422_SP,&nbsp;PIXEL_FMT_YCRCB_422_SP,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_SP,&nbsp;PIXEL_FMT_YCRCB_420_SP,&nbsp;PIXEL_FMT_YCBCR_422_P,&nbsp;PIXEL_FMT_YCRCB_422_P,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_P,&nbsp;PIXEL_FMT_YCRCB_420_P,&nbsp;PIXEL_FMT_YUYV_422_PKG,&nbsp;PIXEL_FMT_UYVY_422_PKG,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YVYU_422_PKG,&nbsp;PIXEL_FMT_VYUY_422_PKG,&nbsp;PIXEL_FMT_VENDER_MASK&nbsp;=&nbsp;0X7FFF0000,&nbsp;PIXEL_FMT_BUTT&nbsp;=&nbsp;0X7FFFFFFF&nbsp;} | 像素格式类型定义。 | 
| [TransformType](_display.md#transformtype){&nbsp;ROTATE_NONE&nbsp;=&nbsp;0,&nbsp;ROTATE_90,&nbsp;ROTATE_180,&nbsp;ROTATE_270,&nbsp;&nbsp;&nbsp;ROTATE_BUTT&nbsp;} | 图层变换类型定义。 | 
| [BlendType](_display.md#blendtype){&nbsp;BLEND_NONE&nbsp;=&nbsp;0,&nbsp;BLEND_CLEAR,&nbsp;BLEND_SRC,&nbsp;BLEND_SRCOVER,&nbsp;&nbsp;&nbsp;BLEND_DSTOVER,&nbsp;BLEND_SRCIN,&nbsp;BLEND_DSTIN,&nbsp;BLEND_SRCOUT,&nbsp;&nbsp;&nbsp;BLEND_DSTOUT,&nbsp;BLEND_SRCATOP,&nbsp;BLEND_DSTATOP,&nbsp;BLEND_ADD,&nbsp;&nbsp;&nbsp;BLEND_XOR,&nbsp;BLEND_DST,&nbsp;BLEND_AKS,&nbsp;BLEND_AKD,&nbsp;&nbsp;&nbsp;BLEND_BUTT&nbsp;} | 支持的图像混合类型。 | 
| [RopType](_display.md#roptype){&nbsp;ROP_BLACK&nbsp;=&nbsp;0,&nbsp;ROP_NOTMERGEPEN,&nbsp;ROP_MASKNOTPEN,&nbsp;ROP_NOTCOPYPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPENNOT,&nbsp;ROP_NOT,&nbsp;ROP_XORPEN,&nbsp;ROP_NOTMASKPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPEN,&nbsp;ROP_NOTXORPEN,&nbsp;ROP_NOP,&nbsp;ROP_MERGENOTPEN,&nbsp;&nbsp;&nbsp;ROP_COPYPE,&nbsp;ROP_MERGEPENNOT,&nbsp;ROP_MERGEPEN,&nbsp;ROP_WHITE,&nbsp;&nbsp;&nbsp;ROP_BUTT&nbsp;} | 硬件加速支持的ROP操作类型。 | 
| [ColorKey](_display.md#colorkey)&nbsp;{&nbsp;CKEY_NONE&nbsp;=&nbsp;0,&nbsp;CKEY_SRC,&nbsp;CKEY_DST,&nbsp;CKEY_BUTT&nbsp;} | Color&nbsp;key操作类型定义，即硬件加速支持的Color&nbsp;key操作类型。 | 
| [MirrorType](_display.md#mirrortype){&nbsp;MIRROR_NONE&nbsp;=&nbsp;0,&nbsp;MIRROR_LR,&nbsp;MIRROR_TB,&nbsp;MIRROR_BUTT&nbsp;} | 硬件加速支持的镜像操作类型定义。 | 
| [Connection](_display.md#connection){&nbsp;CON_INVALID&nbsp;=&nbsp;0,&nbsp;CONNECTED,&nbsp;DISCONNECTED&nbsp;} | 热插拔连接类型定义。 | 
| [InterfaceType](_display.md#interfacetype){&nbsp;DISP_INTF_HDMI&nbsp;=&nbsp;0,&nbsp;DISP_INTF_LCD,&nbsp;DISP_INTF_BT1120,&nbsp;DISP_INTF_BT656,&nbsp;&nbsp;&nbsp;DISP_INTF_YPBPR,&nbsp;DISP_INTF_RGB,&nbsp;DISP_INTF_CVBS,&nbsp;DISP_INTF_SVIDEO,&nbsp;&nbsp;&nbsp;DISP_INTF_VGA,&nbsp;DISP_INTF_MIPI,&nbsp;DISP_INTF_PANEL,&nbsp;DISP_INTF_BUTT&nbsp;} | 枚举接口类型。 | 
| [DispPowerStatus](_display.md#disppowerstatus){&nbsp;POWER_STATUS_ON,&nbsp;POWER_STATUS_STANDBY,&nbsp;POWER_STATUS_SUSPEND,&nbsp;POWER_STATUS_OFF,&nbsp;&nbsp;&nbsp;POWER_STATUS_BUTT&nbsp;} | 枚举显示状态。 | 
| [CompositionType](_display.md#compositiontype){&nbsp;COMPOSITION_CLIENT,&nbsp;COMPOSITION_DEVICE,&nbsp;COMPOSITION_CURSOR,&nbsp;COMPOSITION_VIDEO,&nbsp;&nbsp;&nbsp;COMPOSITION_DEVICE_CLEAR,&nbsp;COMPOSITION_CLIENT_CLEAR,&nbsp;COMPOSITION_TUNNEL,&nbsp;COMPOSITION_BUTT&nbsp;} | 枚举特殊层的组合类型。 | 
| [ColorGamut](_display.md#colorgamut){&nbsp;COLOR_GAMUT_INVALID&nbsp;=&nbsp;-1,&nbsp;COLOR_GAMUT_NATIVE&nbsp;=&nbsp;0,&nbsp;COLOR_GAMUT_SATNDARD_BT601&nbsp;=&nbsp;1,&nbsp;COLOR_GAMUT_STANDARD_BT709&nbsp;=&nbsp;2,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_DCI_P3&nbsp;=&nbsp;3,&nbsp;COLOR_GAMUT_SRGB&nbsp;=&nbsp;4,&nbsp;COLOR_GAMUT_ADOBE_RGB&nbsp;=&nbsp;5,&nbsp;COLOR_GAMUT_DISPLAY_P3&nbsp;=&nbsp;6,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_BT2020&nbsp;=&nbsp;7,&nbsp;COLOR_GAMUT_BT2100_PQ&nbsp;=&nbsp;8,&nbsp;COLOR_GAMUT_BT2100_HLG&nbsp;=&nbsp;9,&nbsp;COLOR_GAMUT_DISPLAY_BT2020&nbsp;=&nbsp;10&nbsp;} | 色域类型枚举值。 | 
| [GamutMap](_display.md#gamutmap){&nbsp;GAMUT_MAP_CONSTANT&nbsp;=&nbsp;0,&nbsp;GAMUT_MAP_EXPANSION&nbsp;=&nbsp;1,&nbsp;GAMUT_MAP_HDR_CONSTANT&nbsp;=&nbsp;2,&nbsp;GAMUT_MAP_HDR_EXPANSION&nbsp;=&nbsp;3&nbsp;} | 枚举色域的映射类型。 | 
| [ColorDataSpace](_display.md#colordataspace){&nbsp;&nbsp;COLOR_DATA_SPACE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;GAMUT_BT601&nbsp;=&nbsp;0x00000001,&nbsp;GAMUT_BT709&nbsp;=&nbsp;0x00000002,&nbsp;GAMUT_DCI_P3&nbsp;=&nbsp;0x00000003,&nbsp;&nbsp;&nbsp;GAMUT_SRGB&nbsp;=&nbsp;0x00000004,&nbsp;GAMUT_ADOBE_RGB&nbsp;=&nbsp;0x00000005,&nbsp;GAMUT_DISPLAY_P3&nbsp;=&nbsp;0x00000006,&nbsp;GAMUT_BT2020&nbsp;=&nbsp;0x00000007,&nbsp;&nbsp;&nbsp;GAMUT_BT2100_PQ&nbsp;=&nbsp;0x00000008,&nbsp;GAMUT_BT2100_HLG&nbsp;=&nbsp;0x00000009,&nbsp;GAMUT_DISPLAY_BT2020&nbsp;=&nbsp;0x0000000a,&nbsp;TRANSFORM_FUNC_UNSPECIFIED&nbsp;=&nbsp;0x00000100,&nbsp;&nbsp;&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;=&nbsp;0x00000200,&nbsp;TRANSFORM_FUNC_SRGB&nbsp;=&nbsp;0x00000300,&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;=&nbsp;0x00000400,&nbsp;TRANSFORM_FUNC_GM2_2&nbsp;=&nbsp;0x00000500,&nbsp;&nbsp;&nbsp;TRANSFORM_FUNC_GM2_6&nbsp;=&nbsp;0x00000600,&nbsp;TRANSFORM_FUNC_GM2_8&nbsp;=&nbsp;0x00000700,&nbsp;TRANSFORM_FUNC_ST2084&nbsp;=&nbsp;0x00000800,&nbsp;TRANSFORM_FUNC_HLG&nbsp;=&nbsp;0x00000900,&nbsp;&nbsp;&nbsp;PRECISION_UNSPECIFIED&nbsp;=&nbsp;0x00010000,&nbsp;PRECISION_FULL&nbsp;=&nbsp;0x00020000,&nbsp;PRESION_LIMITED&nbsp;=&nbsp;0x00030000,&nbsp;PRESION_EXTENDED&nbsp;=&nbsp;0x00040000,&nbsp;&nbsp;&nbsp;BT601_SMPTE170M_FULL&nbsp;=&nbsp;GAMUT_BT601&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT601_SMPTE170M_LIMITED&nbsp;=&nbsp;GAMUT_BT601&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRESION_LIMITED,&nbsp;BT709_LINEAR_FULL&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT709_LINEAR_EXTENDED&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRESION_EXTENDED,&nbsp;&nbsp;&nbsp;BT709_SRGB_FULL&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT709_SRGB_EXTENDED&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRESION_EXTENDED,&nbsp;BT709_SMPTE170M_LIMITED&nbsp;=&nbsp;GAMUT_BT709&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRESION_LIMITED,&nbsp;DCI_P3_LINEAR_FULL&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;DCI_P3_GAMMA26_FULL&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_GM2_6&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;DISPLAY_P3_LINEAR_FULL&nbsp;=&nbsp;GAMUT_DISPLAY_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;DCI_P3_SRGB_FULL&nbsp;=&nbsp;GAMUT_DCI_P3&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;ADOBE_RGB_GAMMA22_FULL&nbsp;=&nbsp;GAMUT_ADOBE_RGB&nbsp;\|&nbsp;TRANSFORM_FUNC_GM2_2&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;BT2020_LINEAR_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_LINEAR&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_SRGB_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_SRGB&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_SMPTE170M_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_SMPTE_170M&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_ST2084_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_ST2084&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;&nbsp;&nbsp;BT2020_HLG_FULL&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_HLG&nbsp;\|&nbsp;PRECISION_FULL,&nbsp;BT2020_ST2084_LIMITED&nbsp;=&nbsp;GAMUT_BT2020&nbsp;\|&nbsp;TRANSFORM_FUNC_ST2084&nbsp;\|&nbsp;PRESION_LIMITED&nbsp;} | 枚举颜色空间的类型。 | 
| [HDRFormat](_display.md#hdrformat){&nbsp;NOT_SUPPORT_HDR&nbsp;=&nbsp;0,&nbsp;DOLBY_VISION&nbsp;=&nbsp;1,&nbsp;HDR10&nbsp;=&nbsp;2,&nbsp;HLG&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;HDR10_PLUS&nbsp;=&nbsp;4,&nbsp;HDR_VIVID&nbsp;=&nbsp;5&nbsp;} | 枚举HDR格式。 | 
| [HDRMetadataKey](_display.md#hdrmetadatakey){&nbsp;&nbsp;MATAKEY_RED_PRIMARY_X&nbsp;=&nbsp;0,&nbsp;MATAKEY_RED_PRIMARY_Y&nbsp;=&nbsp;1,&nbsp;MATAKEY_GREEN_PRIMARY_X&nbsp;=&nbsp;2,&nbsp;MATAKEY_GREEN_PRIMARY_Y&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;MATAKEY_BLUE_PRIMARY_X&nbsp;=&nbsp;4,&nbsp;MATAKEY_BLUE_PRIMARY_Y&nbsp;=&nbsp;5,&nbsp;MATAKEY_WHITE_PRIMARY_X&nbsp;=&nbsp;6,&nbsp;MATAKEY_WHITE_PRIMARY_Y&nbsp;=&nbsp;7,&nbsp;&nbsp;&nbsp;MATAKEY_MAX_LUMINANCE&nbsp;=&nbsp;8,&nbsp;MATAKEY_MIN_LUMINANCE&nbsp;=&nbsp;9,&nbsp;MATAKEY_MAX_CONTENT_LIGHT_LEVEL&nbsp;=&nbsp;10,&nbsp;MATAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL&nbsp;=&nbsp;11,&nbsp;&nbsp;&nbsp;MATAKEY_HDR10_PLUS&nbsp;=&nbsp;12,&nbsp;MATAKEY_HDR_VIVID&nbsp;=&nbsp;13&nbsp;} | 枚举HDR元数据关键字。 | 
| [PresentTimestampType](_display.md#presenttimestamptype){&nbsp;HARDWARE_DISPLAY_PTS_UNSUPPORTED&nbsp;=&nbsp;0,&nbsp;HARDWARE_DISPLAY_PTS_DELAY&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;0,&nbsp;HARDWARE_DISPLAY_PTS_TIMESTAMP&nbsp;=&nbsp;1&nbsp;&lt;&lt;&nbsp;1&nbsp;} | 上屏时间戳类型枚举值。 | 
