# CodecExtTypes.idl


## 概述

Codec模块接口定义中使用的扩展数据类型。

模块包路径：ohos.hdi.codec.v2_0

引用：ohos.hdi.codec.v2_0.CodecTypes

**起始版本：** 4.1

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[SupportBufferType](_support_buffer_type_v20.md) | 查询vendor层支持buffer类型信息。 | 
| struct&nbsp;&nbsp;[UseBufferType](_use_buffer_type_v20.md) | 设置输入输出端口对应的buffer类型。 | 
| struct&nbsp;&nbsp;[GetBufferHandleUsageParams](_get_buffer_handle_usage_params_v20.md) | 查询vendor层BufferHandle的默认usage配置。 | 
| struct&nbsp;&nbsp;[CodecVideoPortFormatParam](_codec_video_port_format_param_v20.md) | 设置输入输出端口的编解码格式。 | 
| struct&nbsp;&nbsp;[ControlRateConstantQuality](_control_rate_constant_quality_v20.md) | 控制编码画面质量参数。 | 
| struct&nbsp;&nbsp;[WorkingFrequencyParam](_working_frequency_param_v20.md) | 查询/设置vendor层编解码器工作频率。 | 
| struct&nbsp;&nbsp;[ProcessNameParam](_process_name_param_v20.md) | 设置调用者进程名。 | 
| struct&nbsp;&nbsp;[CodecVideoParamHevc](_codec_video_param_hevc_v20.md) | 定义HEVC视频编码格式信息。 | 
| struct&nbsp;&nbsp;[ColorAspects](_color_aspects_v20.md) | 色彩空间相关枚举 | 
| struct&nbsp;&nbsp;[CodecVideoColorspace](_codec_video_colorspace_v20.md) | 定义色彩空间参数信息 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CodecVideoExType](_codec_v20.md#codecvideoextype) { CODEC_VIDEO_CodingVP9 = 10 , CODEC_VIDEO_CodingHEVC = 11 } | 视频编码格式枚举，对OMX原生枚举OMX_VIDEO_CODINGTYPE的补充。 | 
| [CodecHevcProfile](_codec_v20.md#codechevcprofile) {<br/>CODEC_HEVC_PROFILE_INVALID = 0x0 , CODEC_HEVC_PROFILE_MAIN = 0x1 , CODEC_HEVC_PROFILE_MAIN10 = 0x2 , CODEC_HEVC_PROFILE_MAIN_STILL = 0x3 , CODEC_HEVC_PROFILE_MAIN10_HDR10 = 0x1000 , CODEC_HEVC_PROFILE_MAIN10_HDR10_PLUS = 0x2000 , CODEC_HEVC_PROFILE_MAX = 0x7FFFFFFF<br/>} | HEVC的profile枚举。 | 
| [CodecHevcLevel](_codec_v20.md#codechevclevel) {<br/>CODEC_HEVC_LEVEL_INVALID = 0x0 , CODEC_HEVC_MAIN_TIER_LEVEL1 = 0x1 , CODEC_HEVC_HIGH_TIER_LEVEL1 = 0x2 , CODEC_HEVC_MAIN_TIER_LEVEL2 = 0x4 , CODEC_HEVC_HIGH_TIER_LEVEL2 = 0x8 , CODEC_HEVC_MAIN_TIER_LEVEL21 = 0x10 , CODEC_HEVC_HIGH_TIER_LEVEL21 = 0x20 , CODEC_HEVC_MAIN_TIER_LEVEL3 = 0x40 , CODEC_HEVC_HIGH_TIER_LEVEL3 = 0x80 , CODEC_HEVC_MAIN_TIER_LEVEL31 = 0x100 , CODEC_HEVC_HIGH_TIER_LEVEL31 = 0x200 , CODEC_HEVC_MAIN_TIER_LEVEL4 = 0x400 , CODEC_HEVC_HIGH_TIER_LEVEL4 = 0x800 , CODEC_HEVC_MAIN_TIER_LEVEL41 = 0x1000 , CODEC_HEVC_HIGH_TIER_LEVEL41 = 0x2000 , CODEC_HEVC_MAIN_TIER_LEVEL5 = 0x4000 , CODEC_HEVC_HIGH_TIER_LEVEL5 = 0x8000 , CODEC_HEVC_MAIN_TIER_LEVEL51 = 0x10000 , CODEC_HEVC_HIGH_TIER_LEVEL51 = 0x20000 , CODEC_HEVC_MAIN_TIER_LEVEL52 = 0x40000 , CODEC_HEVC_HIGH_TIER_LEVEL52 = 0x80000 , CODEC_HEVC_MAIN_TIER_LEVEL6 = 0x100000 , CODEC_HEVC_HIGH_TIER_LEVEL6 = 0x200000 , CODEC_HEVC_MAIN_TIER_LEVEL61 = 0x400000 , CODEC_HEVC_HIGH_TIER_LEVEL61 = 0x800000 , CODEC_HEVC_MAIN_TIER_LEVEL62 = 0x1000000 , CODEC_HEVC_HIGH_TIER_LEVEL62 = 0x2000000 , CODEC_HEVC_HIGH_TIER_MAX = 0x7FFFFFFF<br/>} | HEVC的level枚举。 | 
| [CodecBufferType](_codec_v20.md#codecbuffertype) {<br/>CODEC_BUFFER_TYPE_INVALID = 0 , CODEC_BUFFER_TYPE_VIRTUAL_ADDR = 0x1 , CODEC_BUFFER_TYPE_AVSHARE_MEM_FD = 0x2 , CODEC_BUFFER_TYPE_HANDLE = 0x4 , CODEC_BUFFER_TYPE_DYNAMIC_HANDLE = 0x8 , CODEC_BUFFER_TYPE_DMA_MEM_FD = 0x10<br/>} | 用于存储编解码视频帧的buffer类型。 | 
| [CodecIndexExType](_codec_v20.md#codecindexextype) {<br/>Codec_IndexExtBufferTypeStartUnused = 0x6F000000 + 0x00a00000 , Codec_IndexParamSupportBufferType , Codec_IndexParamUseBufferType , Codec_IndexParamGetBufferHandleUsage ,<br/>Codec_IndexCodecVideoPortFormat , Codec_IndexParamControlRateConstantQuality , Codec_IndexParamVideoHevc = 0x6F000000 + 0x00a00007 , Codec_IndexColorAspects ,<br/>Codec_IndexParamWorkingFrequency , Codec_IndexParamProcessName<br/>} | 编解码器参数索引，对OMX原生枚举OMX_INDEXTYPE的扩展。 | 
| [RangeType](_codec_v20.md#rangetype) { RANGE_UNSPECIFIED , RANGE_FULL , RANGE_LIMITED , RANGE_MAX = 0xff } | 视频像素值范围。 | 
| [Primaries](_codec_v20.md#primaries) {<br/>PRIMARIES_UNSPECIFIED , PRIMARIES_BT709 , PRIMARIES_BT470_6M , PRIMARIES_BT601_625 , PRIMARIES_BT601_525 , PRIMARIES_GENERICFILM , PRIMARIES_BT2020 , PRIMARIES_MAX = 0xff<br/>} | 设置视频色域。 | 
| [Transfer](_codec_v20.md#transfer) {<br/>TRANSFER_UNSPECIFIED , TRANSFER_LINEAR , TRANSFER_SRGB , TRANSFER_SMPTE170 , TRANSFER_GAMMA22 , TRANSFER_GAMMA28 , TRANSFER_PQ , TRANSFER_HLG , TRANSFER_SMPTE240 = 0x40 , TRANSFER_XVYCC , TRANSFER_BT1361 , TRANSFER_ST428 , TRANSFER_MAX = 0xff<br/>} | 设置视频传递函数。 | 
| [MatrixCoeffs](_codec_v20.md#matrixcoeffs) {<br/>MATRIX_UNSPECIFED , MATRIX_BT709 , MATRIX_FCC , MATRIX_BT601 ,<br/>MATRIX_SMPTE240 , MATRIX_BT2020 , MATRIX_BT2020CONSTANT , MATRIX_MAX = 0xff<br/>} | 设置视频矩阵系数。 | 
