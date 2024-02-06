# native_avcapability.h


## 概述

声明用于编解码能力查询到的Native API。

**起始版本：**

10

**相关模块：**

[AVCapability](_a_v_capability.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRange](_o_h___a_v_range.md) | 范围包含最小值和最大值。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_BitrateMode](_a_v_capability.md#oh_bitratemode) | 编码器的比特率模式。 | 
| [OH_AVRange](_a_v_capability.md#oh_avrange) | 范围包含最小值和最大值。 | 
| [OH_AVCodecCategory](_a_v_capability.md#oh_avcodeccategory) | 编解码器类别。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_BitrateMode](_a_v_capability.md#oh_bitratemode) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**BITRATE_MODE_CBR** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**BITRATE_MODE_VBR** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**BITRATE_MODE_CQ** = 2<br/>} | 编码器的比特率模式。 | 
| [OH_AVCodecCategory](_a_v_capability.md#oh_avcodeccategory) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**HARDWARE** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**SOFTWARE**<br/>} | 编解码器类别。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVCodec_GetCapability](_a_v_capability.md#oh_avcodec_getcapability) (const char \*mime, bool isEncoder) | 获取系统推荐的编解码器能力。 | 
| \*[OH_AVCodec_GetCapabilityByCategory](_a_v_capability.md#oh_avcodec_getcapabilitybycategory) (const char \*mime, bool isEncoder, [OH_AVCodecCategory](_a_v_capability.md#oh_avcodeccategory) category) | 获取指定类别中的编解码器能力。通过指定类别， 匹配的编解码器仅限于硬件编解码器或软件编解码器。 | 
| [OH_AVCapability_IsHardware](_a_v_capability.md#oh_avcapability_ishardware) (OH_AVCapability \*capability) | 检查能力实例是否描述了硬件编解码器。 | 
| \*[OH_AVCapability_GetName](_a_v_capability.md#oh_avcapability_getname) (OH_AVCapability \*capability) | 获取编解码器名称。 | 
| [OH_AVCapability_GetMaxSupportedInstances](_a_v_capability.md#oh_avcapability_getmaxsupportedinstances) (OH_AVCapability \*capability) | 获取编解码器支持的最大实例数。 | 
| [OH_AVCapability_GetEncoderBitrateRange](_a_v_capability.md#oh_avcapability_getencoderbitraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*bitrateRange) | 获取编码器支持的比特率范围。 | 
| [OH_AVCapability_IsEncoderBitrateModeSupported](_a_v_capability.md#oh_avcapability_isencoderbitratemodesupported) (OH_AVCapability \*capability, [OH_BitrateMode](_a_v_capability.md#oh_bitratemode) bitrateMode) | 检查编码器是否支持特定的比特率模式。 | 
| [OH_AVCapability_GetEncoderQualityRange](_a_v_capability.md#oh_avcapability_getencoderqualityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*qualityRange) | 获取编码器支持的质量范围。 | 
| [OH_AVCapability_GetEncoderComplexityRange](_a_v_capability.md#oh_avcapability_getencodercomplexityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*complexityRange) | 获取编码器支持的编码器复杂性范围。 | 
| [OH_AVCapability_GetAudioSupportedSampleRates](_a_v_capability.md#oh_avcapability_getaudiosupportedsamplerates) (OH_AVCapability \*capability, const int32_t \*\*sampleRates, uint32_t \*sampleRateNum) | 获取音频编解码器支持的采样速率。 | 
| [OH_AVCapability_GetAudioChannelCountRange](_a_v_capability.md#oh_avcapability_getaudiochannelcountrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*channelCountRange) | 获取音频编解码器支持的音频通道计数范围。 | 
| [OH_AVCapability_GetVideoWidthAlignment](_a_v_capability.md#oh_avcapability_getvideowidthalignment) (OH_AVCapability \*capability, int32_t \*widthAlignment) | 获取视频编解码器支持的视频宽度对齐。 | 
| [OH_AVCapability_GetVideoHeightAlignment](_a_v_capability.md#oh_avcapability_getvideoheightalignment) (OH_AVCapability \*capability, int32_t \*heightAlignment) | 获取视频编解码器支持的视频高度对齐。 | 
| [OH_AVCapability_GetVideoWidthRangeForHeight](_a_v_capability.md#oh_avcapability_getvideowidthrangeforheight) (OH_AVCapability \*capability, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | 获取指定高度情况下视频编解码器支持的视频宽度范围。 | 
| [OH_AVCapability_GetVideoHeightRangeForWidth](_a_v_capability.md#oh_avcapability_getvideoheightrangeforwidth) (OH_AVCapability \*capability, int32_t width, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | 获取指定宽度情况下视频编解码器支持的视频高度范围。 | 
| [OH_AVCapability_GetVideoWidthRange](_a_v_capability.md#oh_avcapability_getvideowidthrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | 获取视频编解码器支持的视频宽度范围。 | 
| [OH_AVCapability_GetVideoHeightRange](_a_v_capability.md#oh_avcapability_getvideoheightrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | 获取视频编解码器支持的视频高度范围。 | 
| [OH_AVCapability_IsVideoSizeSupported](_a_v_capability.md#oh_avcapability_isvideosizesupported) (OH_AVCapability \*capability, int32_t width, int32_t height) | 检查视频编解码器是否支持特定的视频大小。 | 
| [OH_AVCapability_GetVideoFrameRateRange](_a_v_capability.md#oh_avcapability_getvideoframeraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | 获取视频编解码器支持的视频帧率范围。 | 
| [OH_AVCapability_GetVideoFrameRateRangeForSize](_a_v_capability.md#oh_avcapability_getvideoframeraterangeforsize) (OH_AVCapability \*capability, int32_t width, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | 获取指定视频大小的视频编解码器支持的视频帧率范围。 | 
| [OH_AVCapability_AreVideoSizeAndFrameRateSupported](_a_v_capability.md#oh_avcapability_arevideosizeandframeratesupported) (OH_AVCapability \*capability, int32_t width, int32_t height, int32_t frameRate) | 检查视频编解码器是否支持视频大小和帧率的特定组合。 | 
| [OH_AVCapability_GetVideoSupportedPixelFormats](_a_v_capability.md#oh_avcapability_getvideosupportedpixelformats) (OH_AVCapability \*capability, const int32_t \*\*pixelFormats, uint32_t \*pixelFormatNum) | 获取视频编解码器支持的视频像素格式。 | 
| [OH_AVCapability_GetSupportedProfiles](_a_v_capability.md#oh_avcapability_getsupportedprofiles) (OH_AVCapability \*capability, const int32_t \*\*profiles, uint32_t \*profileNum) | 获取编解码器支持的配置文件。 | 
| [OH_AVCapability_GetSupportedLevelsForProfile](_a_v_capability.md#oh_avcapability_getsupportedlevelsforprofile) (OH_AVCapability \*capability, int32_t profile, const int32_t \*\*levels, uint32_t \*levelNum) | 获取特定配置文件支持的编解码器级别。 | 
| [OH_AVCapability_AreProfileAndLevelSupported](_a_v_capability.md#oh_avcapability_areprofileandlevelsupported) (OH_AVCapability \*capability, int32_t profile, int32_t level) | 检查编解码器是否支持配置文件和级别的特定组合。 | 
