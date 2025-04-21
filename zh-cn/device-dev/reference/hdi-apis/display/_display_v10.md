# Display (V1_0)

## 概述

显示模块驱动接口定义。

提供给上层图形服务使用的驱动接口，包括图层管理、设备控制、显示内存管理等相关接口。

**起始版本：** 3.2

## 汇总

### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [DisplayBufferType.idl](_display_buffer_type_8idl_v10.md) | 显示内存类型定义，定义显示内存操作相关接口所使用的数据类型。 | 
| [IAllocator.idl](_i_allocator_8idl_v10.md) | 显示内存分配接口声明。 | 
| [IMapper.idl](_i_mapper_8idl_v10.md) | 显示内存映射接口声明。 | 
| [DisplayComposerType.idl](_display_composer_type_8idl_v10.md) | 显示合成类型定义，定义显示图层合成操作相关接口所使用的数据类型。 | 
| [IDisplayComposer.idl](_i_display_composer_8idl_v10.md) | 显示合成接口声明。 | 
| [IHotPlugCallback.idl](_i_hot_plug_callback_8idl_v10.md) | 热插拔事件回调接口声明。 | 
| [IRefreshCallback.idl](_i_refresh_callback_8idl_v10.md) | 显示刷新事件回调接口声明。 | 
| [IVBlankCallback.idl](_i_v_blank_callback_8idl_v10.md) | 帧同步事件回调接口声明。 | 

### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[AllocInfo](_alloc_info_v10.md) | 定义待分配内存的信息。 | 
| struct&nbsp;&nbsp;[VerifyAllocInfo](_verify_alloc_info_v10.md) | 用于验证内存分配信息的结构体定义。 | 
| interface&nbsp;&nbsp;[IAllocator](interface_i_allocator_v10.md) | 定义显示内存分配接口。 | 
| interface&nbsp;&nbsp;[IMapper](interface_i_mapper_v10.md) | 定义释放显示内存接口。 | 
| struct&nbsp;&nbsp;[PropertyObject](_property_object_v10.md) | 定义包含名称、属性ID和值的属性对象。 | 
| struct&nbsp;&nbsp;[DisplayCapability](_display_capability_v10.md) | 定义输出性能。 | 
| struct&nbsp;&nbsp;[DisplayModeInfo](_display_mode_info_v10.md) | 定义输出模式信息。 | 
| struct&nbsp;&nbsp;[LayerInfo](_layer_info_v10.md) | Defines 定义图层信息结构体。 | 
| struct&nbsp;&nbsp;[LayerAlpha](_layer_alpha_v10.md) | 定义图层Alpha信息的结构体。 | 
| struct&nbsp;&nbsp;[IRect](_i_rect_v10.md) | 定义矩形框信息。 | 
| struct&nbsp;&nbsp;[ISurface](_i_surface_v10.md) | 用于存放窗口相关信息的结构体定义，提供给硬件加速使用，例如图像合成，位图搬移等操作。 | 
| struct&nbsp;&nbsp;[ILine](_i_line_v10.md) | 线条描述结构体定义，用于硬件加速绘制直线。 | 
| struct&nbsp;&nbsp;[ICircle](_i_circle_v10.md) | 圆形描述结构体定义，用于硬件加速绘制圆形。 | 
| struct&nbsp;&nbsp;[Rectangle](_rectangle_v10.md) | 矩形描述结构体定义，用于硬件加速绘制矩形。 | 
| struct&nbsp;&nbsp;[GfxOpt](_gfx_opt_v10.md) | 图像硬件加速相关的操作选项结构体定义，用于图像硬件加速时的操作选项。 | 
| struct&nbsp;&nbsp;[HDRCapability](_h_d_r_capability_v10.md) | HDR属性结构体定义。 | 
| struct&nbsp;&nbsp;[HDRMetaData](_h_d_r_meta_data_v10.md) | HDR元数据结构体定义。 | 
| struct&nbsp;&nbsp;[PresentTimestamp](_present_timestamp_v10.md) | 上屏时间戳结构体定义。 | 
| struct&nbsp;&nbsp;[ExtDataHandle](_ext_data_handle_v10.md) | 扩展数据句柄结构体定义。 | 
| struct&nbsp;&nbsp;[YUVDescInfo](_y_u_v_desc_info_v10.md) | YUV描述信息结构体定义。 | 
| struct&nbsp;&nbsp;[HdifdInfo](_hdifd_info_v10.md) | 定义 hdi fd 信息结构体。 | 
| struct&nbsp;&nbsp;[LayerColor](_layer_color_v10.md) | 定义图层颜色设置的结构结构体。 | 
| interface&nbsp;&nbsp;[IDisplayComposer](interface_i_display_composer_v10.md) | 显示合成接口声明。 | 
| interface&nbsp;&nbsp;[IHotPlugCallback](interface_i_hot_plug_callback_v10.md) | 定义热插拔事件回调接口。 | 
| interface&nbsp;&nbsp;[IRefreshCallback](interface_i_refresh_callback_v10.md) | 定义显示刷新事件回调接口。 | 
| interface&nbsp;&nbsp;[IVBlankCallback](interface_i_v_blank_callback_v10.md) | 定义帧同步事件回调接口。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DispCmd](#dispcmd) {<br/>REQUEST_CMD_PREPARE_DISPLAY_LAYERS = 64 , REQUEST_CMD_SET_DISPLAY_CLIENT_BUFFER = 65 , REQUEST_CMD_SET_DISPLAY_CLIENT_DAMAGE = 66 , REQUEST_CMD_COMMIT = 67 ,<br/>REQUEST_CMD_SET_LAYER_ALPHA = 68 , REQUEST_CMD_SET_LAYER_REGION = 69 , REQUEST_CMD_SET_LAYER_CROP = 70 , REQUEST_CMD_SET_LAYER_ZORDER = 71 ,<br/>REQUEST_CMD_SET_LAYER_PREMULTI = 72 , REQUEST_CMD_SET_LAYER_TRANSFORM_MODE = 73 , REQUEST_CMD_SET_LAYER_DIRTY_REGION = 74 , REQUEST_CMD_SET_LAYER_VISIBLE_REGION = 75 ,<br/>REQUEST_CMD_SET_LAYER_BUFFER = 76 , REQUEST_CMD_SET_LAYER_COMPOSITION_TYPE = 77 , REQUEST_CMD_SET_LAYER_BLEND_TYPE = 78 , REQUEST_CMD_SET_LAYER_VISIBLE = 79 ,<br/>REQUEST_CMD_SET_LAYER_MASK_INFO = 80 , REQUEST_CMD_SET_LAYER_COLOR = 81 , REQUEST_CMD_BUTT , REPLY_CMD_SET_ERROR = 512 ,<br/>REPLY_CMD_PREPARE_DISPLAY_LAYERS = 513 , REPLY_CMD_COMMIT = 514 , REPLY_CMD_BUTT , CONTROL_CMD_REQUEST_BEGIN = 1024 ,<br/>CONTROL_CMD_REPLY_BEGIN = 1025 , CONTROL_CMD_REQUEST_END = 1026 , CONTROL_CMD_REPLY_END = 1027 , CONTROL_CMD_BUTT<br/>} | 枚举Display命令。 | 
| [DispErrCode](#disperrcode) {<br/>DISPLAY_SUCCESS = 0 , DISPLAY_FAILURE = -1 , DISPLAY_FD_ERR = -2 , DISPLAY_PARAM_ERR = -3 ,<br/>DISPLAY_NULL_PTR = -4 , DISPLAY_NOT_SUPPORT = -5 , DISPLAY_NOMEM = -6 , DISPLAY_SYS_BUSY = -7 , DISPLAY_NOT_PERM = -8<br/>} | 返回值类型定义。 | 
| [PixelFormat](#pixelformat) {<br/>PIXEL_FMT_CLUT8 = 0, PIXEL_FMT_CLUT1, PIXEL_FMT_CLUT4, PIXEL_FMT_RGB_565,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_5658, PIXEL_FMT_RGBX_4444, PIXEL_FMT_RGBA_4444, PIXEL_FMT_RGB_444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBX_5551, PIXEL_FMT_RGBA_5551, PIXEL_FMT_RGB_555, PIXEL_FMT_RGBX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_RGBA_8888, PIXEL_FMT_RGB_888, PIXEL_FMT_BGR_565, PIXEL_FMT_BGRX_4444,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_4444, PIXEL_FMT_BGRX_5551, PIXEL_FMT_BGRA_5551, PIXEL_FMT_BGRX_8888,&nbsp;&nbsp;&nbsp;PIXEL_FMT_BGRA_8888, PIXEL_FMT_YUV_422_I, PIXEL_FMT_YCBCR_422_SP, PIXEL_FMT_YCRCB_422_SP,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_SP, PIXEL_FMT_YCRCB_420_SP, PIXEL_FMT_YCBCR_422_P, PIXEL_FMT_YCRCB_422_P,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YCBCR_420_P, PIXEL_FMT_YCRCB_420_P, PIXEL_FMT_YUYV_422_PKG, PIXEL_FMT_UYVY_422_PKG,&nbsp;&nbsp;&nbsp;PIXEL_FMT_YVYU_422_PKG, PIXEL_FMT_VYUY_422_PKG, PIXEL_FMT_VENDER_MASK = 0X7FFF0000, PIXEL_FMT_BUTT = 0X7FFFFFFF<br/>} | 像素格式类型定义。 | 
| [BufferUsage](#bufferusage) : unsigned long {<br/>HBM_USE_CPU_READ = (1ULL &lt;&lt; 0) , HBM_USE_CPU_WRITE = (1ULL &lt;&lt; 1) , HBM_USE_MEM_MMZ = (1ULL &lt;&lt; 2) , HBM_USE_MEM_DMA = (1ULL &lt;&lt; 3) ,<br/>HBM_USE_MEM_SHARE = (1ULL &lt;&lt; 4) , HBM_USE_MEM_MMZ_CACHE = (1ULL &lt;&lt; 5) , HBM_USE_MEM_FB = (1ULL &lt;&lt; 6) , HBM_USE_ASSIGN_SIZE = (1ULL &lt;&lt; 7) ,<br/>HBM_USE_HW_RENDER = (1ULL &lt;&lt; 8) , HBM_USE_HW_TEXTURE = (1ULL &lt;&lt; 9) , HBM_USE_HW_COMPOSER = (1ULL &lt;&lt; 10) , HBM_USE_PROTECTED = (1ULL &lt;&lt; 11) ,<br/>HBM_USE_CAMERA_READ = (1ULL &lt;&lt; 12) , HBM_USE_CAMERA_WRITE = (1ULL &lt;&lt; 13) , HBM_USE_VIDEO_ENCODER = (1ULL &lt;&lt; 14) , HBM_USE_VIDEO_DECODER = (1ULL &lt;&lt; 15) ,<br/>HBM_USE_CPU_READ_OFTEN = (1ULL &lt;&lt; 16) , HBM_USE_VENDOR_PRI0 = (1ULL &lt;&lt; 44) , HBM_USE_VENDOR_PRI1 = (1ULL &lt;&lt; 45) , HBM_USE_VENDOR_PRI2 = (1ULL &lt;&lt; 46) ,<br/>HBM_USE_VENDOR_PRI3 = (1ULL &lt;&lt; 47) , HBM_USE_VENDOR_PRI4 = (1ULL &lt;&lt; 48) , HBM_USE_VENDOR_PRI5 = (1ULL &lt;&lt; 49) , HBM_USE_VENDOR_PRI6 = (1ULL &lt;&lt; 50) ,<br/>HBM_USE_VENDOR_PRI7 = (1ULL &lt;&lt; 51) , HBM_USE_VENDOR_PRI8 = (1ULL &lt;&lt; 52) , HBM_USE_VENDOR_PRI9 = (1ULL &lt;&lt; 53) , HBM_USE_VENDOR_PRI10 = (1ULL &lt;&lt; 54) ,<br/>HBM_USE_VENDOR_PRI11 = (1ULL &lt;&lt; 55) , HBM_USE_VENDOR_PRI12 = (1ULL &lt;&lt; 56) , HBM_USE_VENDOR_PRI13 = (1ULL &lt;&lt; 57) , HBM_USE_VENDOR_PRI14 = (1ULL &lt;&lt; 58) ,<br/>HBM_USE_VENDOR_PRI15 = (1ULL &lt;&lt; 59) , HBM_USE_VENDOR_PRI16 = (1ULL &lt;&lt; 60) , HBM_USE_VENDOR_PRI17 = (1ULL &lt;&lt; 61) , HBM_USE_VENDOR_PRI18 = (1ULL &lt;&lt; 62) ,<br/>HBM_USE_VENDOR_PRI19 = (1ULL &lt;&lt; 63)<br/>} | 定义缓冲区使用情况。 | 
| [TransformType](#transformtype) {<br/>ROTATE_NONE = 0, ROTATE_90, ROTATE_180, ROTATE_270 ,<br/>MIRROR_H , MIRROR_V , MIRROR_H_ROTATE_90 , MIRROR_V_ROTATE_90 ,<br/>ROTATE_BUTT<br/>} | 枚举图像的转换类型。 | 
| [DispPowerStatus](#disppowerstatus) {<br/>POWER_STATUS_ON = 0 , POWER_STATUS_STANDBY = 1 , POWER_STATUS_SUSPEND = 2 , POWER_STATUS_OFF = 3 ,<br/>POWER_STATUS_BUTT<br/>} | 枚举显示状态。 | 
| [CompositionType](#compositiontype) {<br/>COMPOSITION_CLIENT, COMPOSITION_DEVICE, COMPOSITION_CURSOR, COMPOSITION_VIDEO,&nbsp;&nbsp;&nbsp;COMPOSITION_DEVICE_CLEAR, COMPOSITION_CLIENT_CLEAR, COMPOSITION_TUNNEL, COMPOSITION_BUTT<br/>} | 枚举特殊层的组合类型。 | 
| [LayerType](#layertype) {<br/>LAYER_TYPE_GRAPHIC, LAYER_TYPE_OVERLAY, LAYER_TYPE_SDIEBAND, LAYER_TYPE_CURSOR, LAYER_TYPE_BUTT<br/>} | 图层类型定义。 | 
| [BlendType](#blendtype) {<br/>BLEND_NONE = 0, BLEND_CLEAR, BLEND_SRC, BLEND_SRCOVER,&nbsp;&nbsp;&nbsp;BLEND_DSTOVER, BLEND_SRCIN, BLEND_DSTIN, BLEND_SRCOUT,&nbsp;&nbsp;&nbsp;BLEND_DSTOUT, BLEND_SRCATOP, BLEND_DSTATOP, BLEND_ADD,&nbsp;&nbsp;&nbsp;BLEND_XOR, BLEND_DST, BLEND_AKS, BLEND_AKD,&nbsp;&nbsp;&nbsp;BLEND_BUTT<br/>} | 支持的图像混合类型。 | 
| [RopType](#roptype) {<br/>ROP_BLACK = 0, ROP_NOTMERGEPEN, ROP_MASKNOTPEN, ROP_NOTCOPYPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPENNOT, ROP_NOT, ROP_XORPEN, ROP_NOTMASKPEN,&nbsp;&nbsp;&nbsp;ROP_MASKPEN, ROP_NOTXORPEN, ROP_NOP, ROP_MERGENOTPEN,&nbsp;&nbsp;&nbsp;ROP_COPYPE, ROP_MERGEPENNOT, ROP_MERGEPEN, ROP_WHITE,&nbsp;&nbsp;&nbsp;ROP_BUTT<br/>} | 硬件加速支持的ROP操作类型。 | 
| [ColorKey](#colorkey) { CKEY_NONE = 0 , CKEY_SRC , CKEY_DST , CKEY_BUTT } | Colorkey操作类型定义，即硬件加速支持的Colorkey操作类型。 | 
| [MirrorType](#mirrortype) { MIRROR_NONE = 0 , MIRROR_LR , MIRROR_TB , MIRROR_BUTT } | 硬件加速支持的镜像操作类型定义。 | 
| [Connection](#connection) { CON_INVALID = 0 , CONNECTED , DISCONNECTED } | 热插拔连接类型定义。 | 
| [InterfaceType](#interfacetype) {<br/>DISP_INTF_HDMI = 0, DISP_INTF_LCD, DISP_INTF_BT1120, DISP_INTF_BT656,&nbsp;&nbsp;&nbsp;DISP_INTF_YPBPR, DISP_INTF_RGB, DISP_INTF_CVBS, DISP_INTF_SVIDEO,&nbsp;&nbsp;&nbsp;DISP_INTF_VGA, DISP_INTF_MIPI, DISP_INTF_PANEL, DISP_INTF_BUTT<br/>} | 显示接口类型。 | 
| [ColorGamut](#colorgamut) {<br/>COLOR_GAMUT_INVALID = -1, COLOR_GAMUT_NATIVE = 0, COLOR_GAMUT_SATNDARD_BT601 = 1, COLOR_GAMUT_STANDARD_BT709 = 2,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_DCI_P3 = 3, COLOR_GAMUT_SRGB = 4, COLOR_GAMUT_ADOBE_RGB = 5, COLOR_GAMUT_DISPLAY_P3 = 6,&nbsp;&nbsp;&nbsp;COLOR_GAMUT_BT2020 = 7, COLOR_GAMUT_BT2100_PQ = 8, COLOR_GAMUT_BT2100_HLG = 9, COLOR_GAMUT_DISPLAY_BT2020 = 10<br/>} | 色域类型枚举值。 | 
| [GamutMap](#gamutmap) { GAMUT_MAP_CONSTANT = 0, GAMUT_MAP_EXPANSION = 1, GAMUT_MAP_HDR_CONSTANT = 2, GAMUT_MAP_HDR_EXPANSION = 3 } | 枚举色域的映射类型。 | 
| [ColorDataSpace](#colordataspace) {<br/>COLOR_DATA_SPACE_UNKNOWN = 0, GAMUT_BT601 = 0x00000001, GAMUT_BT709 = 0x00000002, GAMUT_DCI_P3 = 0x00000003,&nbsp;&nbsp;&nbsp;GAMUT_SRGB = 0x00000004, GAMUT_ADOBE_RGB = 0x00000005, GAMUT_DISPLAY_P3 = 0x00000006, GAMUT_BT2020 = 0x00000007,&nbsp;&nbsp;&nbsp;GAMUT_BT2100_PQ = 0x00000008, GAMUT_BT2100_HLG = 0x00000009, GAMUT_DISPLAY_BT2020 = 0x0000000a, TRANSFORM_FUNC_UNSPECIFIED = 0x00000100,&nbsp;&nbsp;&nbsp;TRANSFORM_FUNC_LINEAR = 0x00000200, TRANSFORM_FUNC_SRGB = 0x00000300, TRANSFORM_FUNC_SMPTE_170M = 0x00000400, TRANSFORM_FUNC_GM2_2 = 0x00000500,&nbsp;&nbsp;TRANSFORM_FUNC_GM2_6 = 0x00000600, TRANSFORM_FUNC_GM2_8 = 0x00000700, TRANSFORM_FUNC_ST2084 = 0x00000800, TRANSFORM_FUNC_HLG = 0x00000900, PRECISION_UNSPECIFIED = 0x00010000, PRECISION_FULL = 0x00020000, PRESION_LIMITED = 0x00030000, PRESION_EXTENDED = 0x00040000,&nbsp;&nbsp;BT601_SMPTE170M_FULL = 1 \| 1024 \| 131072 , BT601_SMPTE170M_LIMITED = 1 \| 1024 \| 196608 , BT709_LINEAR_FULL&nbsp;&nbsp;= 2 \| 512 \| 131072 , BT709_LINEAR_EXTENDED = 2 \| 512 \| 262144 , BT709_SRGB_FULL&nbsp;&nbsp;= 2 \| 768 \| 131072 , BT709_SRGB_EXTENDED&nbsp;&nbsp;= 2 \| 768 \| 262144 , BT709_SMPTE170M_LIMITED = 2 \| 1024 \| 196608 , DCI_P3_LINEAR_FULL&nbsp;&nbsp;= 3 \| 512 \| 131072 , DCI_P3_GAMMA26_FULL = 3 \| 1536 \| 131072 , DISPLAY_P3_LINEAR_FULL = 6 \| 512 \| 131072 , DCI_P3_SRGB_FULL = 3 \| 768 \| 131072 , ADOBE_RGB_GAMMA22_FULL = 5 \| 1280 \| 131072 , BT2020_LINEAR_FULL = 7 \| 512 \| 131072 , BT2020_SRGB_FULL = 7 \| 768 \| 131072 , BT2020_SMPTE170M_FULL = 7 \| 1024 \| 131072 , BT2020_ST2084_FULL = 7 \| 2048 \| 131072 , BT2020_HLG_FULL = 7 \| 2304 \| 131072 , BT2020_ST2084_LIMITED = 7 \| 2048 \| 196608<br/>} | 枚举颜色空间的类型。 | 
| [HDRFormat](#hdrformat) {<br/>NOT_SUPPORT_HDR = 0, DOLBY_VISION = 1, HDR10 = 2, HLG = 3,&nbsp;&nbsp;&nbsp;HDR10_PLUS = 4, HDR_VIVID = 5<br/>} | 枚举HDR格式。 | 
| [HDRMetadataKey](#hdrmetadatakey) {<br/>MATAKEY_RED_PRIMARY_X = 0, MATAKEY_RED_PRIMARY_Y = 1, MATAKEY_GREEN_PRIMARY_X = 2, MATAKEY_GREEN_PRIMARY_Y = 3,&nbsp;&nbsp;&nbsp;MATAKEY_BLUE_PRIMARY_X = 4, MATAKEY_BLUE_PRIMARY_Y = 5, MATAKEY_WHITE_PRIMARY_X = 6, MATAKEY_WHITE_PRIMARY_Y = 7,&nbsp;&nbsp;&nbsp;MATAKEY_MAX_LUMINANCE = 8, MATAKEY_MIN_LUMINANCE = 9, MATAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, MATAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,&nbsp;&nbsp;&nbsp;MATAKEY_HDR10_PLUS = 12, MATAKEY_HDR_VIVID = 13<br/>} | 枚举HDR元数据关键字。 | 
| [PresentTimestampType](#presenttimestamptype) { HARDWARE_DISPLAY_PTS_UNSUPPORTED = 0, HARDWARE_DISPLAY_PTS_DELAY = 1 &lt;&lt; 0, HARDWARE_DISPLAY_PTS_TIMESTAMP = 1 &lt;&lt; 1 } | 上屏时间戳类型枚举值。 | 
| [MaskInfo](#maskinfo) { LAYER_NORAML = 0 , LAYER_HBM_SYNC = 1 } | 图层蒙版枚举值。 | 

## 枚举类型说明

### BlendType

```
enum BlendType
```

**描述**

支持的图像混合类型。

系统在硬件加速期间基于指定的混合类型合成图像。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| BLEND_NONE | No 混合操作。 | 
| BLEND_CLEAR | CLEAR 混合操作。 | 
| BLEND_SRC | SRC 混合操作。 | 
| BLEND_SRCOVER | SRC_OVER 混合操作。 | 
| BLEND_DSTOVER | DST_OVER 混合操作。 | 
| BLEND_SRCIN | SRC_IN 混合操作。 | 
| BLEND_DSTIN | DST_IN 混合操作。 | 
| BLEND_SRCOUT | SRC_OUT 混合操作。 | 
| BLEND_DSTOUT | DST_OUT 混合操作。 | 
| BLEND_SRCATOP | SRC_ATOP 混合操作。 | 
| BLEND_DSTATOP | DST_ATOP 混合操作。 | 
| BLEND_ADD | ADD 混合操作。 | 
| BLEND_XOR | XOR 混合操作。 | 
| BLEND_DST | DST 混合操作。 | 
| BLEND_AKS | AKS 混合操作。 | 
| BLEND_AKD | AKD 混合操作。 | 
| BLEND_BUTT | 空操作。 | 

### BufferUsage

```
enum BufferUsage : unsigned long
```

**描述**

定义缓冲区使用情况。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HBM_USE_CPU_READ | CPU 读取内存。 | 
| HBM_USE_CPU_WRITE | CPU 写入内存。 | 
| HBM_USE_MEM_MMZ | 媒体内存区 (MMZ)。 | 
| HBM_USE_MEM_DMA | 直接内存访问 （DMA） 内存区。 | 
| HBM_USE_MEM_SHARE | 共享内存内存区。 | 
| HBM_USE_MEM_MMZ_CACHE | 存在缓存的 MMZ。 | 
| HBM_USE_MEM_FB | 帧内存。 | 
| HBM_USE_ASSIGN_SIZE | 分配内存。 | 
| HBM_USE_HW_RENDER | 写入GPU内存情况。 | 
| HBM_USE_HW_TEXTURE | 读取GPU内存情况。 | 
| HBM_USE_HW_COMPOSER | 硬件编写情况。 | 
| HBM_USE_PROTECTED | 安全缓冲区情况，例如 DRM 。| 
| HBM_USE_CAMERA_READ | 读取相机情况。 | 
| HBM_USE_CAMERA_WRITE | 写入相机情况。 | 
| HBM_USE_VIDEO_ENCODER | 编码情况。 | 
| HBM_USE_VIDEO_DECODER | 解码情况。 | 
| HBM_USE_CPU_READ_OFTEN | HBM 经常使用 CPU 读取情况。 | 
| HBM_USE_VENDOR_PRI0 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI1 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI2 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI3 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI4 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI5 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI6 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI7 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI8 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI9 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI10 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI11 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI12 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI13 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI14 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI15 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI16 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI17 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI18 | 为供应商提供。 | 
| HBM_USE_VENDOR_PRI19 | 为供应商提供。 | 

### ColorDataSpace

```
enum ColorDataSpace
```

**描述**

枚举颜色空间的类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_DATA_SPACE_UNKNOWN | 未知的。 | 
| GAMUT_BT601 | BT601色域。 | 
| GAMUT_BT709 | BT709色域。 | 
| GAMUT_DCI_P3 | DCI_P3色域。 | 
| GAMUT_SRGB | SRGB色域。 | 
| GAMUT_ADOBE_RGB | ADOBE_RGB色域。 | 
| GAMUT_DISPLAY_P3 | DISPLAY_P3色域。 | 
| GAMUT_BT2020 | BT2020色域。 | 
| GAMUT_BT2100_PQ | BT2100_PQ色域。 | 
| GAMUT_BT2100_HLG | BT2100_HLG色域。 | 
| GAMUT_DISPLAY_BT2020 | DISPLAY_BT2020色域。 | 
| TRANSFORM_FUNC_UNSPECIFIED | UNSPECIFIED转换函数。 | 
| TRANSFORM_FUNC_LINEAR | LINEAR转换函数。 | 
| TRANSFORM_FUNC_SRGB | SRGB转换函数。 | 
| TRANSFORM_FUNC_SMPTE_170M | SMPTE_170M转换函数。 | 
| TRANSFORM_FUNC_GM2_2 | GM2_2转换函数。 | 
| TRANSFORM_FUNC_GM2_6 | GM2_6转换函数。 | 
| TRANSFORM_FUNC_GM2_8 | GM2_8转换函数。 | 
| TRANSFORM_FUNC_ST2084 | ST2084转换函数。 | 
| TRANSFORM_FUNC_HLG | HLG转换函数。 | 
| PRECISION_UNSPECIFIED | UNSPECIFIED精度。 | 
| PRECISION_FULL | FULL精度。 | 
| PRESION_LIMITED | LIMITED精度。 | 
| PRESION_EXTENDED | EXTENDED精度。 | 
| BT601_SMPTE170M_FULL | BT601色域 \| SMPTE_170M转换函数 \| FULL精度。 | 
| BT601_SMPTE170M_LIMITED | BT601色域 \| SMPTE_170M转换函数 \| LIMITED精度。| 
| BT709_LINEAR_FULL | BT709色域 \| LINEAR转换函数 \| FULL精度。 | 
| BT709_LINEAR_EXTENDED | BT709色域 \| LINEAR转换函数 \| EXTENDED精度。 | 
| BT709_SRGB_FULL | BT709色域 \| SRGB转换函数 \| FULL精度。 | 
| BT709_SRGB_EXTENDED | BT709色域 \| SRGB转换函数 \| EXTENDED精度。 | 
| BT709_SMPTE170M_LIMITED | BT709色域 \| SMPTE_170M转换函数 \| LIMITED精度。 | 
| DCI_P3_LINEAR_FULL | DCI_P3色域 \| LINEAR转换函数 \| FULL精度。 | 
| DCI_P3_GAMMA26_FULL | DCI_P3色域 \| GM2_6转换函数 \| FULL精度。 | 
| DISPLAY_P3_LINEAR_FULL | DISPLAY_P3色域 \| LINEAR转换函数 \| FULL精度。 | 
| DCI_P3_SRGB_FULL | DCI_P3色域 \| SRGB转换函数 \| FULL精度。 | 
| ADOBE_RGB_GAMMA22_FULL | ADOBE_RGB色域 \| GM2_2转换函数 \| FULL精度。 | 
| BT2020_LINEAR_FULL | BT2020色域 \| LINEAR转换函数 \| FULL精度。 | 
| BT2020_SRGB_FULL | BT2020色域 \| SRGB转换函数 \| FULL精度。 | 
| BT2020_SMPTE170M_FULL | BT2020色域 \| SMPTE_170M转换函数 \| FULL精度。 | 
| BT2020_ST2084_FULL | BT2020色域 \| ST2084转换函数 \| FULL精度。 | 
| BT2020_HLG_FULL | BT2020色域 \| HLG转换函数 \| FULL精度。 | 
| BT2020_ST2084_LIMITED | BT2020色域 \| ST2084转换函数 \| LIMITED精度。 | 

### ColorGamut

```
enum ColorGamut
```

**描述**

色域类型枚举值。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_GAMUT_INVALID | 无效值。 | 
| COLOR_GAMUT_NATIVE | 默认值。 | 
| COLOR_GAMUT_STANDARD_BT601| Standard BT601类型。 | 
| COLOR_GAMUT_STANDARD_BT709 | Standard BT709类型。 | 
| COLOR_GAMUT_DCI_P3 | DCI P3类型。 | 
| COLOR_GAMUT_SRGB | SRGB类型。 | 
| COLOR_GAMUT_ADOBE_RGB | Adobe RGB类型。 | 
| COLOR_GAMUT_DISPLAY_P3 | display P3类型。 | 
| COLOR_GAMUT_BT2020 | BT2020类型。 | 
| COLOR_GAMUT_BT2100_PQ | BT2100 PQ类型。 | 
| COLOR_GAMUT_BT2100_HLG | BT2100 HLG类型。 | 
| COLOR_GAMUT_DISPLAY_BT2020 | Display BT2020类型。 | 

### ColorKey

```
enum ColorKey
```

**描述**

Colorkey操作类型定义，即硬件加速支持的Colorkey操作类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| CKEY_NONE | 不使用Colorkey。 | 
| CKEY_SRC | 使用源Colorkey。 | 
| CKEY_DST | 使用目标Colorkey。 | 
| CKEY_BUTT | 空操作。 | 

### CompositionType

```
enum CompositionType
```

**描述**

枚举特殊层的组合类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| COMPOSITION_CLIENT | Client 合成类型，使用CPU或者GPU合成。 | 
| COMPOSITION_DEVICE | Device 合成类型，使用Device合成。 | 
| COMPOSITION_CURSOR | Cursor合成类型，用于光标合成。 | 
| COMPOSITION_VIDEO | Video合成类型，用于视频层合成。 | 
| COMPOSITION_DEVICE_CLEAR | Device清除合成类型，用于清楚Device。 | 
| COMPOSITION_CLIENT_CLEAR | Client清除合成类型，用于清除Client。 | 
| COMPOSITION_TUNNEL | Tunnel合成类型，用于tunnel合成。 | 
| COMPOSITION_BUTT | 合成类型，一个不可用类型，用于默认初始化。 | 

### Connection

```
enum Connection
```

**描述**

热插拔连接类型定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| CON_INVALID | 无效类型。 | 
| CONNECTED | 已连接。 | 
| DISCONNECTED | 断开连接。 | 

### DispCmd

```
enum DispCmd
```

**描述**

枚举Display命令。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| REQUEST_CMD_PREPARE_DISPLAY_LAYERS | 请求 CMD 准备显示图层。 | 
| REQUEST_CMD_SET_DISPLAY_CLIENT_BUFFER | 请求 CMD 设置显示客户端缓冲区。 | 
| REQUEST_CMD_SET_DISPLAY_CLIENT_DAMAGE | 请求 CMD 设置显示客户端损坏。 | 
| REQUEST_CMD_COMMIT | 请求 CMD 提交。 | 
| REQUEST_CMD_SET_LAYER_ALPHA | 请求 CMD 设置图层 ALPHA。| 
| REQUEST_CMD_SET_LAYER_REGION | 请求 CMD 设置图层区域。 | 
| REQUEST_CMD_SET_LAYER_CROP | 请求 CMD 设置图层裁剪。 | 
| REQUEST_CMD_SET_LAYER_ZORDER | 请求 CMD 设置图层ZORDER。 | 
| REQUEST_CMD_SET_LAYER_PREMULTI | 请求 CMD 设置图层PREMULTI。 | 
| REQUEST_CMD_SET_LAYER_TRANSFORM_MODE | 请求 CMD 设置图层变换模式。 | 
| REQUEST_CMD_SET_LAYER_DIRTY_REGION | 请求 CMD 设置图层脏区。 | 
| REQUEST_CMD_SET_LAYER_VISIBLE_REGION | 请求 CMD 设置图层可见区域。 | 
| REQUEST_CMD_SET_LAYER_BUFFER | 请求 CMD 设置图层缓冲区。 | 
| REQUEST_CMD_SET_LAYER_COMPOSITION_TYPE | 请求 CMD 设置图层成分类型。 | 
| REQUEST_CMD_SET_LAYER_BLEND_TYPE | 请求 CMD 设置图层混合类型。 | 
| REQUEST_CMD_SET_LAYER_VISIBLE | 请求 CMD 设置图层可见。 | 
| REQUEST_CMD_SET_LAYER_MASK_INFO | 请求 CMD 设置图层掩码信息。 | 
| REQUEST_CMD_SET_LAYER_COLOR | 请求 CMD 设置图层颜色。 | 
| REQUEST_CMD_BUTT | 请求 CMD 对接。 | 
| REPLY_CMD_SET_ERROR | 回复 CMD 设置错误。 | 
| REPLY_CMD_PREPARE_DISPLAY_LAYERS | 回复 CMD 准备显示图层。 | 
| REPLY_CMD_COMMIT | 回复 CMD 提交。 | 
| REPLY_CMD_BUTT | 回复 CMD 对接。 | 
| CONTROL_CMD_REQUEST_BEGIN | 控制 CMD 请求开始。 | 
| CONTROL_CMD_REPLY_BEGIN | 控制 CMD 回复开始。 | 
| CONTROL_CMD_REQUEST_END | 控制 CMD 请求结束。 | 
| CONTROL_CMD_REPLY_END | 控制 CMD 回复结束。 | 
| CONTROL_CMD_BUTT | 控制 CMD 对接。 | 

### DispErrCode

```
enum DispErrCode
```

**描述**

返回值类型定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_SUCCESS | 成功。 | 
| DISPLAY_FAILURE | 失败。 | 
| DISPLAY_FD_ERR | Fd错误。 | 
| DISPLAY_PARAM_ERR | 参数错误。 | 
| DISPLAY_NULL_PTR | 空指针。 | 
| DISPLAY_NOT_SUPPORT | 不支持的特性。 | 
| DISPLAY_NOMEM | 内存不足。 | 
| DISPLAY_SYS_BUSY | 系统繁忙。 | 
| DISPLAY_NOT_PERM | 操作不允许。 | 

### DispPowerStatus

```
enum DispPowerStatus
```

**描述**

枚举显示状态。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| POWER_STATUS_ON | 上电模式。 | 
| POWER_STATUS_STANDBY | 待机模式。 | 
| POWER_STATUS_SUSPEND | 休眠模式。 | 
| POWER_STATUS_OFF | 下电模式。 | 
| POWER_STATUS_BUTT | 默认模式。 | 

### GamutMap

```
enum GamutMap
```

**描述**

枚举色域的映射类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| GAMUT_MAP_CONSTANT | 不变。 | 
| GAMUT_MAP_EXPANSION | 映射增强。 | 
| GAMUT_MAP_HDR_CONSTANT | 不变，用于HDR。 | 
| GAMUT_MAP_HDR_EXPANSION | 映射增强，用于HDR。 | 

### HDRFormat

```
enum HDRFormat
```

**描述**

枚举HDR格式。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| NOT_SUPPORT_HDR | 不支持HDR。 | 
| DOLBY_VISION | Dolby Vision格式。 | 
| HDR10 | HDR10格式。 | 
| HLG | HLG格式。 | 
| HDR10_PLUS | HDR10 Plus格式。 | 
| HDR_VIVID | Vivid格式。 | 

### HDRMetadataKey

```
enum HDRMetadataKey
```

**描述**

枚举HDR元数据关键字。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| MATAKEY_RED_PRIMARY_X | 红基色X坐标。 | 
| MATAKEY_RED_PRIMARY_Y | 红基色Y坐标。 | 
| MATAKEY_GREEN_PRIMARY_X | 绿基色X坐标。 | 
| MATAKEY_GREEN_PRIMARY_Y | 绿基色Y坐标。 | 
| MATAKEY_BLUE_PRIMARY_X | 蓝基色X坐标。 | 
| MATAKEY_BLUE_PRIMARY_Y | 蓝基色Y坐标。 | 
| MATAKEY_WHITE_PRIMARY_X | 白点X坐标。 | 
| MATAKEY_WHITE_PRIMARY_Y | 白点Y坐标。 | 
| MATAKEY_MAX_LUMINANCE | 最大的光亮度。| 
| MATAKEY_MIN_LUMINANCE | 最小的光亮度。 | 
| MATAKEY_MAX_CONTENT_LIGHT_LEVEL | 最大的内容亮度水平。 | 
| MATAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL | 最大的帧平均亮度水平。 | 
| MATAKEY_HDR10_PLUS | HDR10 Plus。 | 
| MATAKEY_HDR_VIVID | Vivid。 | 

### InterfaceType

```
enum InterfaceType
```

**描述**

显示接口类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| DISP_INTF_HDMI | HDMI 接口。 | 
| DISP_INTF_LCD | LCD 接口。 | 
| DISP_INTF_BT1120 | BT1120 接口。 | 
| DISP_INTF_BT656 | BT656 接口。 | 
| DISP_INTF_YPBPR | YPBPR 接口。 | 
| DISP_INTF_RGB | RGB 接口。 | 
| DISP_INTF_CVBS | CVBS 接口。 | 
| DISP_INTF_SVIDEO | SVIDEO 接口。 | 
| DISP_INTF_VGA | VGA 接口。 | 
| DISP_INTF_MIPI | MIPI 接口。 | 
| DISP_INTF_PANEL | PANEL 接口。 | 
| DISP_INTF_BUTT | BUTT 接口， 一个不可用类型， 用于默认初始化。 | 

### LayerType

```
enum LayerType
```

**描述**

图层类型定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| LAYER_TYPE_GRAPHIC | 图形层。 | 
| LAYER_TYPE_OVERLAY | 视频层。 | 
| LAYER_TYPE_SDIEBAND | 媒体播放。 | 
| LAYER_TYPE_CURSOR | 光标层。 | 
| LAYER_TYPE_BUTT | 空图层。 | 

### MaskInfo

```
enum MaskInfo
```

**描述**

图层蒙版枚举值。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| LAYER_NORAML | 没有指纹蒙版 | 
| LAYER_HBM_SYNC | 有指纹蒙版 | 


### MirrorType

```
enum MirrorType
```

**描述**

硬件加速支持的镜像操作类型定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| MIRROR_NONE | 不使用镜像。 | 
| MIRROR_LR | 左右镜像。 | 
| MIRROR_TB | 上下镜像。 | 
| MIRROR_BUTT | 空操作。 | 

### PixelFormat

```
enum PixelFormat
```

**描述**

像素格式类型定义。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| PIXEL_FMT_CLUT8 | CLUT8 格式。 | 
| PIXEL_FMT_CLUT1 | CLUT1 格式。 | 
| PIXEL_FMT_CLUT4 | CLUT4 格式。 | 
| PIXEL_FMT_RGB_565 | RGB565 格式。 | 
| PIXEL_FMT_RGBA_5658 | RGBA5658 格式。 | 
| PIXEL_FMT_RGBX_4444 | RGBX4444 格式。 | 
| PIXEL_FMT_RGBA_4444 | RGBA4444 格式。 | 
| PIXEL_FMT_RGB_444 | RGB444 格式。 | 
| PIXEL_FMT_RGBX_5551 | RGBX5551 格式。 | 
| PIXEL_FMT_RGBA_5551 | RGBA5551 格式。 | 
| PIXEL_FMT_RGB_555 | RGB555 格式。 | 
| PIXEL_FMT_RGBX_8888 | RGBX8888 格式。 | 
| PIXEL_FMT_RGBA_8888 | RGBA8888 格式。 | 
| PIXEL_FMT_RGB_888 | RGB888 格式。 | 
| PIXEL_FMT_BGR_565 | BGR565 格式。 | 
| PIXEL_FMT_BGRX_4444 | BGRX4444 格式。 | 
| PIXEL_FMT_BGRA_4444 | BGRA4444 格式。 | 
| PIXEL_FMT_BGRX_5551 | BGRX5551 格式。 | 
| PIXEL_FMT_BGRA_5551 | BGRA5551 格式。 | 
| PIXEL_FMT_BGRX_8888 | BGRX8888 格式。| 
| PIXEL_FMT_BGRA_8888 | BGRA8888 格式。 | 
| PIXEL_FMT_YUV_422_I | YUV422 交错格式。 | 
| PIXEL_FMT_YCBCR_422_SP | YCBCR422 半平面格式。 | 
| PIXEL_FMT_YCRCB_422_SP | YCRCB422 半平面格式。 | 
| PIXEL_FMT_YCBCR_420_SP | YCBCR420 半平面格式。 | 
| PIXEL_FMT_YCRCB_420_SP | YCRCB420 半平面格式。 | 
| PIXEL_FMT_YCBCR_422_P | YCBCR422 平面格式。 | 
| PIXEL_FMT_YCRCB_422_P | YCRCB422 平面格式。 | 
| PIXEL_FMT_YCBCR_420_P | YCBCR420 平面格式。 | 
| PIXEL_FMT_YCRCB_420_P | YCRCB420 平面格式。 | 
| PIXEL_FMT_YUYV_422_PKG | YUYV422 平面格式。 | 
| PIXEL_FMT_UYVY_422_PKG | UYVY422 平面格式。 | 
| PIXEL_FMT_YVYU_422_PKG | YVYU422 平面格式。 | 
| PIXEL_FMT_VYUY_422_PKG | VYUY422 平面格式。 | 
| PIXEL_FMT_RGBA_1010102 | RGBA_1010102 供应商格式。 | 
| PIXEL_FMT_VENDER_MASK | 供应商掩码 格式。 | 
| PIXEL_FMT_BUTT | Invalid 像素格式。 | 

### PresentTimestampType

```
enum PresentTimestampType
```

**描述**

上屏时间戳类型枚举值。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HARDWARE_DISPLAY_PTS_UNSUPPORTED | 不支持。 | 
| HARDWARE_DISPLAY_PTS_DELAY | 时延类型。 | 
| HARDWARE_DISPLAY_PTS_TIMESTAMP | 时间戳类型。 | 

### RopType

```
enum RopType
```

**描述**
 
硬件加速支持的ROP操作类型，在将前景位图的RGB颜色分量和Alpha分量值与背景位图的RGB颜色 分量值和Alpha分量值进行按位的布尔运算（包括按位与，按位或等），将结果输出。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ROP_BLACK | 黑色。 | 
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
| ROP_WHITE | 白色。 | 
| ROP_BUTT | 无效值。 | 

### TransformType

```
enum TransformType
```

**描述**

枚举图像的转换类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| ROTATE_NONE | 不旋转。 | 
| ROTATE_90 | 旋转90度。 | 
| ROTATE_180 | 旋转180度。 | 
| ROTATE_270 | 旋转270度。 | 
| MIRROR_H | 水平方向镜像转换。 | 
| MIRROR_V | 垂直方向镜像转换。 | 
| MIRROR_H_ROTATE_90 | 水平方向镜像转换， 旋转90度。 | 
| MIRROR_V_ROTATE_90 | 垂直方向镜像转换， 旋转90度。 | 
| ROTATE_BUTT | 无效操作。 | 
