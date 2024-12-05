# 媒体子系统Changelog

## cl.multimedia.1 AVCodec Kit部分接口废弃

**访问级别**

公开接口

**废弃原因**

本次废弃接口为重复接口，或是当前未被使用的接口，为优化开发者体验，废弃此部分接口。

**废弃影响**

该变更为兼容性变更。

废弃接口保留5个API版本后删除。

**废弃发生版本**

从OpenHarmony SDK 5.1.0.43开始。

**变更的接口/组件**

| 接口名称              | 废弃说明     |
| ---------------------| ----------- |
| OH_ED_KEY_TIME_STAMP | 未使用 |
| OH_ED_KEY_EOS | 未使用 |
| OH_VideoEncodeBitrateMode | 重复接口 |
| CBR  | 重复接口 |
| VBR | 重复接口 |
| CQ | 重复接口 |
| HEVC_PROFILE_MAIN_10_HDR10 | 非标接口，未使用 |
| HEVC_PROFILE_MAIN_10_HDR10_PLUS | 非标接口，未使用 |
| OH_MD_KEY_SCALING_MODE | 重复接口 |
| OH_ScalingMode| 重复接口 |
| SCALING_MODE_SCALE_TO_WINDOW| 重复接口 |
| SCALING_MODE_SCALE_CROP| 重复接口 |
| OH_AVDemuxer_SetMediaKeySystemInfoCallback| 重复接口 |
| DRM_MediaKeySystemInfoCallback| 重复接口 |

**适配指导**

| 接口名称              | 替代接口     |
| ---------------------| ----------- |
| OH_ED_KEY_TIME_STAMP | / |
| OH_ED_KEY_EOS  | / |
| OH_VideoEncodeBitrateMode  | [OH_BitrateMode](../../../application-dev/reference/apis-avcodec-kit/_codec_base.md) |
| CBR | [BITRATE_MODE_CBR](../../../application-dev/reference/apis-avcodec-kit/_codec_base.md) |
| VBR | [BITRATE_MODE_VBR](../../../application-dev/reference/apis-avcodec-kit/_codec_base.md) |
| CQ  | [BITRATE_MODE_CQ](../../../application-dev/reference/apis-avcodec-kit/_codec_base.md) |
| HEVC_PROFILE_MAIN_10_HDR10 | / |
| HEVC_PROFILE_MAIN_10_HDR10_PLUS | / |
| OH_MD_KEY_SCALING_MODE | [OH_NativeWindow_NativeWindowSetScalingModeV2](../../../application-dev/reference/apis-arkgraphics2d/_native_window.md) |
| OH_ScalingMode | [OHScalingModeV2](../../../application-dev/reference/apis-arkgraphics2d/_native_window.md) | 
| SCALING_MODE_SCALE_TO_WINDOW | [OH_SCALING_MODE_SCALE_TO_WINDOW_V2](../../../application-dev/reference/apis-arkgraphics2d/_native_window.md) |
| SCALING_MODE_SCALE_CROP | [OH_SCALING_MODE_SCALE_CROP_V2](../../../application-dev/reference/apis-arkgraphics2d/_native_window.md) |
| OH_AVDemuxer_SetMediaKeySystemInfoCallback | [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](../../../application-dev/reference/apis-avcodec-kit/native__avdemuxer_8h.md) |
| DRM_MediaKeySystemInfoCallback | [Demuxer_MediaKeySystemInfoCallback](../../../application-dev/reference/apis-avcodec-kit/native__avdemuxer_8h.md) |

## c1.multimedia.2 AVCodec Kit OH_BitrateMode枚举位置变更

**访问级别**

公开接口

**变更原因**

编解码能力查询和视频编码都会用到该枚举。

**变更影响**

该变更为兼容性变更。

变更前：OH_BitrateMode枚举在native_avcapability.h中。  

变更后：OH_BitrateMode枚举在native_avcodec_base.h中。

**起始 API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.1.0.43版本开始。

**变更的接口/组件**

| 接口名称                   | 原所在头文件位置 | 变更后所在头文件位置 |
| ------------------------- | -------------- | ------------------ |
| OH_BitrateMode | native_avcapability.h | native_avcodec_base.h |
| BITRATE_MODE_CBR | native_avcapability.h | native_avcodec_base.h |
| BITRATE_MODE_VBR | native_avcapability.h | native_avcodec_base.h |
| BITRATE_MODE_CQ | native_avcapability.h | native_avcodec_base.h |

**适配指导**

开发者无需适配。

## c1.multimedia.3 AVCodec Kit音视频编解码OH_XXX_Flush、OH_XXX_Stop支持重复调用

**访问级别**

公开接口

**变更原因**

音视频编解码重复调用OH_XXX_Flush、OH_XXX_Stop接口，并不会使状态机发生变化，故支持重复调用以增强接口易用性。

**变更影响**

该变更为兼容性变更。

变更前：重复调用音视频编解码OH_XXX_Flush、OH_XXX_Stop接口，返回 AV_ERR_INVALID_STATE。 

变更后：重复调用音视频编解码OH_XXX_Flush、OH_XXX_Stop接口，返回 AV_ERR_OK。

**起始 API Level**

| 接口名称               | 起始 API Level |
| --------------------- | ----------- |
| OH_VideoDecoder_Stop  | API 9 |
| OH_VideoEncoder_Stop  | API 9 |
| OH_AudioDecoder_Stop  | API 9 |
| OH_AudioEncoder_Stop  | API 9 |
| OH_AudioCodec_Stop    | API 11 |
| OH_VideoDecoder_Flush | API 9 |
| OH_VideoEncoder_Flush | API 9 |
| OH_AudioDecoder_Flush | API 9 |
| OH_AudioEncoder_Flush | API 9 |
| OH_AudioCodec_Flush   | API 11 |

**变更发生版本**

从OpenHarmony SDK 5.1.0.43版本开始。

**变更的接口/组件**

| 接口名称               | 描述        |
| --------------------- | ----------- |
| OH_VideoDecoder_Stop  | 支持重复调用 |
| OH_VideoEncoder_Stop  | 支持重复调用 |
| OH_AudioDecoder_Stop  | 支持重复调用 |
| OH_AudioEncoder_Stop  | 支持重复调用 |
| OH_AudioCodec_Stop    | 支持重复调用 |
| OH_VideoDecoder_Flush | 支持重复调用 |
| OH_VideoEncoder_Flush | 支持重复调用 |
| OH_AudioDecoder_Flush | 支持重复调用 |
| OH_AudioEncoder_Flush | 支持重复调用 |
| OH_AudioCodec_Flush   | 支持重复调用 |

**适配指导**

开发者无需适配。
