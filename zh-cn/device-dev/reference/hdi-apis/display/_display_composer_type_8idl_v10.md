# DisplayComposerType.idl


## 概述

显示合成类型定义，定义显示图层合成操作相关接口所使用的数据类型。

模块包路径：ohos.hdi.display.composer.v1_0

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[PropertyObject](_property_object_v10.md) | 定义包含名称、属性ID和值的属性对象。 | 
| struct&nbsp;&nbsp;[DisplayCapability](_display_capability_v10.md) | 定义输出性能。 | 
| struct&nbsp;&nbsp;[DisplayModeInfo](_display_mode_info_v10.md) | 定义输出模式信息。 | 
| struct&nbsp;&nbsp;[LayerInfo](_layer_info_v10.md) | Defines 定义图层信息结构体。 | 
| struct&nbsp;&nbsp;[LayerAlpha](_layer_alpha_v10.md) | 定义图层Alpha信息的结构体。 | 
| struct&nbsp;&nbsp;[IRect](_i_rect_v10.md) | 定义矩形框信息。 | 
| struct&nbsp;&nbsp;[ISurface](_i_surface_v10.md) | 用于存放窗口相关信息的结构体定义，提供给硬件加速使用，例如图像合成，位图搬移等操作。 | 
| struct&nbsp;&nbsp;[ILine](_i_line_v10.md) | 线条描述结构体定义，用于硬件加速绘制直线。 | 
| struct&nbsp;&nbsp;[ICircle](_i_circle_v10.md) | 圆形描述结构体定义，用于硬件加速绘制圆形。 | 
| struct&nbsp;&nbsp;[Rectangle](_rectangle_v10.md) | 矩形描述结构体定义，用于硬件加速绘制矩形， | 
| struct&nbsp;&nbsp;[GfxOpt](_gfx_opt_v10.md) | 图像硬件加速相关的操作选项结构体定义，用于图像硬件加速时的操作选项。 | 
| struct&nbsp;&nbsp;[HDRCapability](_h_d_r_capability_v10.md) | HDR属性结构体定义。 | 
| struct&nbsp;&nbsp;[HDRMetaData](_h_d_r_meta_data_v10.md) | HDR元数据结构体定义。 | 
| struct&nbsp;&nbsp;[PresentTimestamp](_present_timestamp_v10.md) | 上屏时间戳结构体定义。 | 
| struct&nbsp;&nbsp;[ExtDataHandle](_ext_data_handle_v10.md) | 扩展数据句柄结构体定义。 | 
| struct&nbsp;&nbsp;[YUVDescInfo](_y_u_v_desc_info_v10.md) | YUV描述信息结构体定义。 | 
| struct&nbsp;&nbsp;[HdifdInfo](_hdifd_info_v10.md) | 定义 hdi fd 信息结构体。 | 
| struct&nbsp;&nbsp;[LayerColor](_layer_color_v10.md) | 定义图层颜色设置的结构结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DispCmd](_display_v10.md#dispcmd) {<br/>REQUEST_CMD_PREPARE_DISPLAY_LAYERS = 64 , REQUEST_CMD_SET_DISPLAY_CLIENT_BUFFER = 65 , REQUEST_CMD_SET_DISPLAY_CLIENT_DAMAGE = 66 , REQUEST_CMD_COMMIT = 67 ,<br/>REQUEST_CMD_SET_LAYER_ALPHA = 68 , REQUEST_CMD_SET_LAYER_REGION = 69 , REQUEST_CMD_SET_LAYER_CROP = 70 , REQUEST_CMD_SET_LAYER_ZORDER = 71 ,<br/>REQUEST_CMD_SET_LAYER_PREMULTI = 72 , REQUEST_CMD_SET_LAYER_TRANSFORM_MODE = 73 , REQUEST_CMD_SET_LAYER_DIRTY_REGION = 74 , REQUEST_CMD_SET_LAYER_VISIBLE_REGION = 75 ,<br/>REQUEST_CMD_SET_LAYER_BUFFER = 76 , REQUEST_CMD_SET_LAYER_COMPOSITION_TYPE = 77 , REQUEST_CMD_SET_LAYER_BLEND_TYPE = 78 , REQUEST_CMD_SET_LAYER_VISIBLE = 79 ,<br/>REQUEST_CMD_SET_LAYER_MASK_INFO = 80 , REQUEST_CMD_SET_LAYER_COLOR = 81 , REQUEST_CMD_BUTT , REPLY_CMD_SET_ERROR = 512 ,<br/>REPLY_CMD_PREPARE_DISPLAY_LAYERS = 513 , REPLY_CMD_COMMIT = 514 , REPLY_CMD_BUTT , CONTROL_CMD_REQUEST_BEGIN = 1024 ,<br/>CONTROL_CMD_REPLY_BEGIN = 1025 , CONTROL_CMD_REQUEST_END = 1026 , CONTROL_CMD_REPLY_END = 1027 , CONTROL_CMD_BUTT<br/>} | 枚举Display命令。 | 
| [DispErrCode](_display_v10.md#disperrcode) {<br/>DISPLAY_SUCCESS = 0 , DISPLAY_FAILURE = -1 , DISPLAY_FD_ERR = -2 , DISPLAY_PARAM_ERR = -3 ,<br/>DISPLAY_NULL_PTR = -4 , DISPLAY_NOT_SUPPORT = -5 , DISPLAY_NOMEM = -6 , DISPLAY_SYS_BUSY = -7 , DISPLAY_NOT_PERM = -8<br/>} | 返回值类型定义。 | 
| [PixelFormat](_display_v10.md#pixelformat) {<br/>PIXEL_FMT_CLUT8 = 0, PIXEL_FMT_CLUT1, PIXEL_FMT_CLUT4, PIXEL_FMT_RGB_565,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_5658, PIXEL_FMT_RGBX_4444, PIXEL_FMT_RGBA_4444, PIXEL_FMT_RGB_444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBX_5551, PIXEL_FMT_RGBA_5551, PIXEL_FMT_RGB_555, PIXEL_FMT_RGBX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_8888, PIXEL_FMT_RGB_888, PIXEL_FMT_BGR_565, PIXEL_FMT_BGRX_4444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_4444, PIXEL_FMT_BGRX_5551, PIXEL_FMT_BGRA_5551, PIXEL_FMT_BGRX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_8888, PIXEL_FMT_YUV_422_I, PIXEL_FMT_YCBCR_422_SP, PIXEL_FMT_YCRCB_422_SP,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_SP, PIXEL_FMT_YCRCB_420_SP, PIXEL_FMT_YCBCR_422_P, PIXEL_FMT_YCRCB_422_P,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_P, PIXEL_FMT_YCRCB_420_P, PIXEL_FMT_YUYV_422_PKG, PIXEL_FMT_UYVY_422_PKG,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YVYU_422_PKG, PIXEL_FMT_VYUY_422_PKG, PIXEL_FMT_VENDER_MASK = 0X7FFF0000, PIXEL_FMT_BUTT = 0X7FFFFFFF<br/>} | 像素格式类型定义。 | 
| [BufferUsage](_display_v10.md#bufferusage) : unsigned long {<br/>HBM_USE_CPU_READ = (1ULL &lt;&lt; 0) , HBM_USE_CPU_WRITE = (1ULL &lt;&lt; 1) , HBM_USE_MEM_MMZ = (1ULL &lt;&lt; 2) , HBM_USE_MEM_DMA = (1ULL &lt;&lt; 3) ,<br/>HBM_USE_MEM_SHARE = (1ULL &lt;&lt; 4) , HBM_USE_MEM_MMZ_CACHE = (1ULL &lt;&lt; 5) , HBM_USE_MEM_FB = (1ULL &lt;&lt; 6) , HBM_USE_ASSIGN_SIZE = (1ULL &lt;&lt; 7) ,<br/>HBM_USE_HW_RENDER = (1ULL &lt;&lt; 8) , HBM_USE_HW_TEXTURE = (1ULL &lt;&lt; 9) , HBM_USE_HW_COMPOSER = (1ULL &lt;&lt; 10) , HBM_USE_PROTECTED = (1ULL &lt;&lt; 11) ,<br/>HBM_USE_CAMERA_READ = (1ULL &lt;&lt; 12) , HBM_USE_CAMERA_WRITE = (1ULL &lt;&lt; 13) , HBM_USE_VIDEO_ENCODER = (1ULL &lt;&lt; 14) , HBM_USE_VIDEO_DECODER = (1ULL &lt;&lt; 15) ,<br/>HBM_USE_CPU_READ_OFTEN = (1ULL &lt;&lt; 16) , HBM_USE_VENDOR_PRI0 = (1ULL &lt;&lt; 44) , HBM_USE_VENDOR_PRI1 = (1ULL &lt;&lt; 45) , HBM_USE_VENDOR_PRI2 = (1ULL &lt;&lt; 46) ,<br/>HBM_USE_VENDOR_PRI3 = (1ULL &lt;&lt; 47) , HBM_USE_VENDOR_PRI4 = (1ULL &lt;&lt; 48) , HBM_USE_VENDOR_PRI5 = (1ULL &lt;&lt; 49) , HBM_USE_VENDOR_PRI6 = (1ULL &lt;&lt; 50) ,<br/>HBM_USE_VENDOR_PRI7 = (1ULL &lt;&lt; 51) , HBM_USE_VENDOR_PRI8 = (1ULL &lt;&lt; 52) , HBM_USE_VENDOR_PRI9 = (1ULL &lt;&lt; 53) , HBM_USE_VENDOR_PRI10 = (1ULL &lt;&lt; 54) ,<br/>HBM_USE_VENDOR_PRI11 = (1ULL &lt;&lt; 55) , HBM_USE_VENDOR_PRI12 = (1ULL &lt;&lt; 56) , HBM_USE_VENDOR_PRI13 = (1ULL &lt;&lt; 57) , HBM_USE_VENDOR_PRI14 = (1ULL &lt;&lt; 58) ,<br/>HBM_USE_VENDOR_PRI15 = (1ULL &lt;&lt; 59) , HBM_USE_VENDOR_PRI16 = (1ULL &lt;&lt; 60) , HBM_USE_VENDOR_PRI17 = (1ULL &lt;&lt; 61) , HBM_USE_VENDOR_PRI18 = (1ULL &lt;&lt; 62) ,<br/>HBM_USE_VENDOR_PRI19 = (1ULL &lt;&lt; 63)<br/>} | 定义缓冲区使用情况。 | 
| [TransformType](_display_v10.md#transformtype) {<br/>ROTATE_NONE = 0, ROTATE_90, ROTATE_180, ROTATE_270 ,<br/>MIRROR_H , MIRROR_V , MIRROR_H_ROTATE_90 , MIRROR_V_ROTATE_90 ,<br/>ROTATE_BUTT<br/>} | 枚举图像的转换类型。 | 
| [DispPowerStatus](_display_v10.md#disppowerstatus) {<br/>POWER_STATUS_ON = 0 , POWER_STATUS_STANDBY = 1 , POWER_STATUS_SUSPEND = 2 , POWER_STATUS_OFF = 3 ,<br/>POWER_STATUS_BUTT<br/>} | 枚举显示状态。 | 
| [CompositionType](_display_v10.md#compositiontype) {<br/>COMPOSITION_CLIENT, COMPOSITION_DEVICE, COMPOSITION_CURSOR, COMPOSITION_VIDEO,&nbsp;&nbsp;&nbsp;COMPOSITION_DEVICE_CLEAR, COMPOSITION_CLIENT_CLEAR, COMPOSITION_TUNNEL, COMPOSITION_BUTT<br/>} | 枚举特殊层的组合类型。 | 
| [LayerType](_display_v10.md#layertype) {<br/>LAYER_TYPE_GRAPHIC, LAYER_TYPE_OVERLAY, LAYER_TYPE_SDIEBAND, LAYER_TYPE_CURSOR, LAYER_TYPE_BUTT<br/>} | 图层类型定义。 | 
| [BlendType](_display_v10.md#blendtype) {<br/>BLEND_NONE = 0, BLEND_CLEAR, BLEND_SRC, BLEND_SRCOVER,&nbsp;&nbsp;&nbsp;BLEND_DSTOVER, BLEND_SRCIN, BLEND_DSTIN, BLEND_SRCOUT,&nbsp;&nbsp;&nbsp;BLEND_DSTOUT, BLEND_SRCATOP, BLEND_DSTATOP, BLEND_ADD,&nbsp;&nbsp;&nbsp;BLEND_XOR, BLEND_DST, BLEND_AKS, BLEND_AKD,&nbsp;&nbsp;&nbsp;BLEND_BUTT<br/>} | 支持的图像混合类型。 | 
| [RopType](_display_v10.md#roptype) {<br/>ROP_BLACK = 0, ROP_NOTMERGEPEN, ROP_MASKNOTPEN, ROP_NOTCOPYPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPENNOT, ROP_NOT, ROP_XORPEN, ROP_NOTMASKPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPEN, ROP_NOTXORPEN, ROP_NOP, ROP_MERGENOTPEN,&nbsp;&nbsp;&nbsp;ROP_COPYPE, ROP_MERGEPENNOT, ROP_MERGEPEN, ROP_WHITE,&nbsp;&nbsp;&nbsp;ROP_BUTT<br/>} | 硬件加速支持的ROP操作类型。 | 
| [ColorKey](_display_v10.md#colorkey) { CKEY_NONE = 0 , CKEY_SRC , CKEY_DST , CKEY_BUTT } | Colorkey操作类型定义，即硬件加速支持的Colorkey操作类型。 | 
| [MirrorType](_display_v10.md#mirrortype) { MIRROR_NONE = 0 , MIRROR_LR , MIRROR_TB , MIRROR_BUTT } | 硬件加速支持的镜像操作类型定义。 | 
| [Connection](_display_v10.md#connection) { CON_INVALID = 0 , CONNECTED , DISCONNECTED } | 热插拔连接类型定义。 | 
| [InterfaceType](_display_v10.md#interfacetype) {<br/>DISP_INTF_HDMI = 0, DISP_INTF_LCD, DISP_INTF_BT1120, DISP_INTF_BT656,&nbsp;&nbsp;&nbsp;DISP_INTF_YPBPR, DISP_INTF_RGB, DISP_INTF_CVBS, DISP_INTF_SVIDEO,&nbsp;&nbsp;&nbsp;DISP_INTF_VGA, DISP_INTF_MIPI, DISP_INTF_PANEL, DISP_INTF_BUTT<br/>} | 显示接口类型。 | 
| [ColorGamut](_display_v10.md#colorgamut) {<br/>COLOR_GAMUT_INVALID = -1, COLOR_GAMUT_NATIVE = 0, COLOR_GAMUT_SATNDARD_BT601 = 1, COLOR_GAMUT_STANDARD_BT709 = 2,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_DCI_P3 = 3, COLOR_GAMUT_SRGB = 4, COLOR_GAMUT_ADOBE_RGB = 5, COLOR_GAMUT_DISPLAY_P3 = 6,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_BT2020 = 7, COLOR_GAMUT_BT2100_PQ = 8, COLOR_GAMUT_BT2100_HLG = 9, COLOR_GAMUT_DISPLAY_BT2020 = 10<br/>} | 色域类型枚举值。 | 
| [GamutMap](_display_v10.md#gamutmap) { GAMUT_MAP_CONSTANT = 0, GAMUT_MAP_EXPANSION = 1, GAMUT_MAP_HDR_CONSTANT = 2, GAMUT_MAP_HDR_EXPANSION = 3 } | 枚举色域的映射类型。 | 
| [ColorDataSpace](_display_v10.md#colordataspace) {<br/>COLOR_DATA_SPACE_UNKNOWN = 0, GAMUT_BT601 = 0x00000001, GAMUT_BT709 = 0x00000002, GAMUT_DCI_P3 = 0x00000003,&nbsp;&nbsp;&nbsp;GAMUT_SRGB = 0x00000004, GAMUT_ADOBE_RGB = 0x00000005, GAMUT_DISPLAY_P3 = 0x00000006, GAMUT_BT2020 = 0x00000007,&nbsp;&nbsp;&nbsp;GAMUT_BT2100_PQ = 0x00000008, GAMUT_BT2100_HLG = 0x00000009, GAMUT_DISPLAY_BT2020 = 0x0000000a, TRANSFORM_FUNC_UNSPECIFIED = 0x00000100,&nbsp;&nbsp;&nbsp;TRANSFORM_FUNC_LINEAR = 0x00000200, TRANSFORM_FUNC_SRGB = 0x00000300, TRANSFORM_FUNC_SMPTE_170M = 0x00000400, TRANSFORM_FUNC_GM2_2 = 0x00000500,&nbsp;&nbsp;TRANSFORM_FUNC_GM2_6 = 0x00000600, TRANSFORM_FUNC_GM2_8 = 0x00000700, TRANSFORM_FUNC_ST2084 = 0x00000800, TRANSFORM_FUNC_HLG = 0x00000900, PRECISION_UNSPECIFIED = 0x00010000, PRECISION_FULL = 0x00020000, PRESION_LIMITED = 0x00030000, PRESION_EXTENDED = 0x00040000,&nbsp;&nbsp;BT601_SMPTE170M_FULL = 1 \| 1024 \| 131072 , BT601_SMPTE170M_LIMITED = 1 \| 1024 \| 196608 , BT709_LINEAR_FULL&nbsp;&nbsp;= 2 \| 512 \| 131072 , BT709_LINEAR_EXTENDED = 2 \| 512 \| 262144 , BT709_SRGB_FULL&nbsp;&nbsp;= 2 \| 768 \| 131072 , BT709_SRGB_EXTENDED&nbsp;&nbsp;= 2 \| 768 \| 262144 , BT709_SMPTE170M_LIMITED = 2 \| 1024 \| 196608 , DCI_P3_LINEAR_FULL&nbsp;&nbsp;= 3 \| 512 \| 131072 , DCI_P3_GAMMA26_FULL = 3 \| 1536 \| 131072 , DISPLAY_P3_LINEAR_FULL = 6 \| 512 \| 131072 , DCI_P3_SRGB_FULL = 3 \| 768 \| 131072 , ADOBE_RGB_GAMMA22_FULL = 5 \| 1280 \| 131072 , BT2020_LINEAR_FULL = 7 \| 512 \| 131072 , BT2020_SRGB_FULL = 7 \| 768 \| 131072 , BT2020_SMPTE170M_FULL = 7 \| 1024 \| 131072 , BT2020_ST2084_FULL = 7 \| 2048 \| 131072 , BT2020_HLG_FULL = 7 \| 2304 \| 131072 , BT2020_ST2084_LIMITED = 7 \| 2048 \| 196608<br/>} | 枚举颜色空间的类型。 | 
| [HDRFormat](_display_v10.md#hdrformat) {<br/>NOT_SUPPORT_HDR = 0, DOLBY_VISION = 1, HDR10 = 2, HLG = 3,&nbsp;&nbsp;&nbsp;HDR10_PLUS = 4, HDR_VIVID = 5<br/>} | 枚举HDR格式。 | 
| [HDRMetadataKey](_display_v10.md#hdrmetadatakey) {<br/>MATAKEY_RED_PRIMARY_X = 0, MATAKEY_RED_PRIMARY_Y = 1, MATAKEY_GREEN_PRIMARY_X = 2, MATAKEY_GREEN_PRIMARY_Y = 3,&nbsp;&nbsp;&nbsp;MATAKEY_BLUE_PRIMARY_X = 4, MATAKEY_BLUE_PRIMARY_Y = 5, MATAKEY_WHITE_PRIMARY_X = 6, MATAKEY_WHITE_PRIMARY_Y = 7,&nbsp;&nbsp;&nbsp;MATAKEY_MAX_LUMINANCE = 8, MATAKEY_MIN_LUMINANCE = 9, MATAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, MATAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,&nbsp;&nbsp;&nbsp;MATAKEY_HDR10_PLUS = 12, MATAKEY_HDR_VIVID = 13<br/>} | 枚举HDR元数据关键字。 | 
| [PresentTimestampType](_display_v10.md#presenttimestamptype) { HARDWARE_DISPLAY_PTS_UNSUPPORTED = 0, HARDWARE_DISPLAY_PTS_DELAY = 1 &lt;&lt; 0, HARDWARE_DISPLAY_PTS_TIMESTAMP = 1 &lt;&lt; 1 } | 上屏时间戳类型枚举值。 | 
| [MaskInfo](_display_v10.md#maskinfo) { LAYER_NORAML = 0 , LAYER_HBM_SYNC = 1 } | 图层蒙版枚举值。 | 
