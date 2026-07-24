# native_avcapability.h
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yang-xiaoyu5-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明用于编解码能力查询到的Native API。

**引用文件：** <multimedia/player_framework/native_avcapability.h>

**库：** libnative_media_codecbase.so

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**相关模块：** [AVCapability](capi-avcapability.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVRange](capi-avcapability-oh-avrange.md) | OH_AVRange | 范围包含最小值和最大值。 |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) | OH_AVCapability | 为OH_AVCapability接口定义native层对象。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVCodecCategory](#oh_avcodeccategory) | OH_AVCodecCategory | 编解码器类别。 |
| [OH_AVCodecType](#oh_avcodectype) | OH_AVCodecType | 编解码器类型。 |
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature) | OH_AVCapabilityFeature | 可以在特定编解码器场景中使用的可选特性。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVCapability *OH_AVCodec_GetCapability(const char *mime, bool isEncoder)](#oh_avcodec_getcapability) | 获取系统推荐的编解码器能力。 |
| [OH_AVCapability *OH_AVCodec_GetCapabilityByCategory(const char *mime, bool isEncoder, OH_AVCodecCategory category)](#oh_avcodec_getcapabilitybycategory) | 获取指定类别中的编解码器能力。通过指定类别，匹配的编解码器仅限于硬件编解码器或软件编解码器。 |
| [OH_AVCapability **OH_AVCodec_GetCapabilityList(OH_AVCodecType codecType, uint32_t *count)](#oh_avcodec_getcapabilitylist) | 获取指定编解码器类型的能力列表。此功能会根据提供的编解码器类型检索出系统支持的所有匹配的编解码器能力。 |
| [bool OH_AVCapability_IsHardware(OH_AVCapability *capability)](#oh_avcapability_ishardware) | 检查能力实例是否描述了硬件编解码器。 |
| [bool OH_AVCapability_IsSecure(OH_AVCapability *capability)](#oh_avcapability_issecure) | 检查能力实例是否描述了一个DRM解码器。 |
| [const char *OH_AVCapability_GetName(OH_AVCapability *capability)](#oh_avcapability_getname) | 获取对应的编解码器名称。 |
| [const char *OH_AVCapability_GetMimeType(OH_AVCapability *capability)](#oh_avcapability_getmimetype) | 获取编解码器的MIME类型。 |
| [bool OH_AVCapability_CheckMimeType(OH_AVCapability *capability, const char *mimeType)](#oh_avcapability_checkmimetype) | 检查编解码器的MIME类型是否与指定的MIME类型匹配。 |
| [int32_t OH_AVCapability_GetMaxSupportedInstances(OH_AVCapability *capability)](#oh_avcapability_getmaxsupportedinstances) | 获取编解码器支持的最大实例数。 |
| [OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange(OH_AVCapability *capability, OH_AVRange *bitrateRange)](#oh_avcapability_getencoderbitraterange) | 获取编码器支持的比特率范围。 |
| [bool OH_AVCapability_IsEncoderBitrateModeSupported(OH_AVCapability *capability, OH_BitrateMode bitrateMode)](#oh_avcapability_isencoderbitratemodesupported) | 检查编码器是否支持特定的比特率模式。 |
| [OH_AVErrCode OH_AVCapability_GetEncoderQualityRange(OH_AVCapability *capability, OH_AVRange *qualityRange)](#oh_avcapability_getencoderqualityrange) | 获取编码器支持的质量范围。 |
| [OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange(OH_AVCapability *capability, OH_AVRange *complexityRange)](#oh_avcapability_getencodercomplexityrange) | 获取编码器支持的编码器复杂性范围。 |
| [OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates(OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)](#oh_avcapability_getaudiosupportedsamplerates) | 获取音频编解码器支持的采样率。 |
| [OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRateRanges(OH_AVCapability *capability, OH_AVRange **sampleRateRanges, uint32_t *rangesNum)](#oh_avcapability_getaudiosupportedsamplerateranges) | 获取音频编解码器支持的采样率范围。 |
| [OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange(OH_AVCapability *capability, OH_AVRange *channelCountRange)](#oh_avcapability_getaudiochannelcountrange) | 获取音频编解码器支持的音频通道计数范围。 |
| [OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment(OH_AVCapability *capability, int32_t *widthAlignment)](#oh_avcapability_getvideowidthalignment) | 获取视频编解码器支持的视频宽度对齐。 |
| [OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment(OH_AVCapability *capability, int32_t *heightAlignment)](#oh_avcapability_getvideoheightalignment) | 获取视频编解码器支持的视频高度对齐。 |
| [OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight(OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)](#oh_avcapability_getvideowidthrangeforheight) | 获取指定高度情况下视频编解码器支持的视频宽度范围。 |
| [OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth(OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)](#oh_avcapability_getvideoheightrangeforwidth) | 获取指定宽度情况下视频编解码器支持的视频高度范围。 |
| [OH_AVErrCode OH_AVCapability_GetVideoWidthRange(OH_AVCapability *capability, OH_AVRange *widthRange)](#oh_avcapability_getvideowidthrange) | 获取视频编解码器支持的视频宽度范围。 |
| [OH_AVErrCode OH_AVCapability_GetVideoHeightRange(OH_AVCapability *capability, OH_AVRange *heightRange)](#oh_avcapability_getvideoheightrange) | 获取视频编解码器支持的视频高度范围。 |
| [bool OH_AVCapability_IsVideoSizeSupported(OH_AVCapability *capability, int32_t width, int32_t height)](#oh_avcapability_isvideosizesupported) | 检查视频编解码器是否支持特定的视频大小。 |
| [OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange(OH_AVCapability *capability, OH_AVRange *frameRateRange)](#oh_avcapability_getvideoframeraterange) | 获取视频编解码器支持的视频帧率范围。 |
| [OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize(OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)](#oh_avcapability_getvideoframeraterangeforsize) | 获取指定视频大小的视频编解码器支持的视频帧率范围。 |
| [bool OH_AVCapability_AreVideoSizeAndFrameRateSupported(OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)](#oh_avcapability_arevideosizeandframeratesupported) | 检查视频编解码器是否支持视频大小和帧率的特定组合。 |
| [OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats(OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)](#oh_avcapability_getvideosupportedpixelformats) | 获取视频编解码器支持的视频像素格式。 |
| [OH_AVErrCode OH_AVCapability_GetVideoSupportedNativeBufferFormats(OH_AVCapability *capability, const OH_NativeBuffer_Format **nativeBufferFormats, uint32_t *nativeBufferFormatNum)](#oh_avcapability_getvideosupportednativebufferformats) | 获取视频编解码器支持的OH_NativeBuffer格式。该函数提供了视频编解码器能够处理的OH_NativeBuffer格式信息，具体取值可见OH_NativeBuffer_Format。 |
| [OH_AVErrCode OH_AVCapability_GetSupportedProfiles(OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)](#oh_avcapability_getsupportedprofiles) | 获取编解码器支持的档次。 |
| [OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile(OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)](#oh_avcapability_getsupportedlevelsforprofile) | 获取特定档次支持的编解码器级别。 |
| [bool OH_AVCapability_AreProfileAndLevelSupported(OH_AVCapability *capability, int32_t profile, int32_t level)](#oh_avcapability_areprofileandlevelsupported) | 检查编解码器是否支持档次和级别的特定组合。 |
| [bool OH_AVCapability_IsFeatureSupported(OH_AVCapability *capability, OH_AVCapabilityFeature feature)](#oh_avcapability_isfeaturesupported) | 检查编解码器是否支持指定特性。 |
| [OH_AVFormat *OH_AVCapability_GetFeatureProperties(OH_AVCapability *capability, OH_AVCapabilityFeature feature)](#oh_avcapability_getfeatureproperties) | 获取指定特性的属性。需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要调用者手动释放。 |

## 枚举类型说明

### OH_AVCodecCategory

```c
enum OH_AVCodecCategory
```

**描述**

编解码器类别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| HARDWARE = 0 | 硬件编解码。 |
| SOFTWARE | 软件编解码。 |

### OH_AVCodecType

```c
enum OH_AVCodecType
```

**描述**

编解码器类型。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_AVCODEC_TYPE_VIDEO_ENCODER = 0 | 表示视频编码器。<br>**起始版本：** 24 |
| OH_AVCODEC_TYPE_VIDEO_DECODER = 1 | 表示视频解码器。<br>**起始版本：** 24 |
| OH_AVCODEC_TYPE_AUDIO_ENCODER = 2 | 表示音频编码器。<br>**起始版本：** 24 |
| OH_AVCODEC_TYPE_AUDIO_DECODER = 3 | 表示音频解码器。<br>**起始版本：** 24 |

### OH_AVCapabilityFeature

```c
enum OH_AVCapabilityFeature
```

**描述**

可以在特定编解码器场景中使用的可选特性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| VIDEO_ENCODER_TEMPORAL_SCALABILITY = 0 | 编解码器支持时域可分层特性，只用于视频编码场景。 |
| VIDEO_ENCODER_LONG_TERM_REFERENCE = 1 | 编解码器支持长期参考帧特性，只用于视频编码场景。 |
| VIDEO_LOW_LATENCY = 2 | 编解码器支持低时延特性，只用于视频解码场景。 |
| VIDEO_ENCODER_B_FRAME = 7 | 编解码器支持B帧特性，只用于视频编码场景。<br>**起始版本：** 20 |
| VIDEO_DECODER_OUTPUT_IN_DECODING_ORDER = 8 | 解码器支持按解码顺序输出帧特性，只用于视频解码场景。<br>**起始版本：** 26.0.0 |
| VIDEO_ENCODER_PREPROC_DOWNSAMPLING = 9 | 编码器支持视频编码前处理降采样特性，该能力仅适用于视频编码器。<br>仅当编码器通过[OH_VideoEncoder_CreatePrimaryWithPreproc](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createprimarywithpreproc)或[OH_VideoEncoder_CreateSecondaryFromPrimary](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createsecondaryfromprimary)接口创建时，方可启用该能力。<br>**起始版本：** 26.0.0 |
| VIDEO_ENCODER_PREPROC_CROP = 10 | 编码器支持视频编码前处理裁剪特性，该特性仅适用于视频编码器。<br>仅当编码器通过[OH_VideoEncoder_CreatePrimaryWithPreproc](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createprimarywithpreproc)或[OH_VideoEncoder_CreateSecondaryFromPrimary](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_createsecondaryfromprimary)接口创建时，方可启用该能力。<br>**起始版本：** 26.0.0 |


## 函数说明

### OH_AVCodec_GetCapability()

```c
OH_AVCapability *OH_AVCodec_GetCapability(const char *mime, bool isEncoder)
```

**描述**

获取系统推荐的编解码器能力。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *mime | MIME类型描述字符串，请参阅AVCODEC_MIME_TYPE类型[变量](capi-native-avcodec-base-h.md#变量)。 |
| bool isEncoder | 编码器为true，解码器为false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) * | 如果现有编解码器匹配，则返回能力实例，如果指定的MIME类型与任何现有编解码器不匹配，则返回NULL。 |

### OH_AVCodec_GetCapabilityByCategory()

```c
OH_AVCapability *OH_AVCodec_GetCapabilityByCategory(const char *mime, bool isEncoder, OH_AVCodecCategory category)
```

**描述**

获取指定类别中的编解码器能力。通过指定类别，匹配的编解码器仅限于硬件编解码器或软件编解码器。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *mime | MIME类型描述字符串，请参阅AVCODEC_MIME_TYPE类型[变量](capi-native-avcodec-base-h.md#变量)。 |
| bool isEncoder | 编码器为true，解码器为false。 |
| [OH_AVCodecCategory](#oh_avcodeccategory) category | 编解码器类别。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) * | 如果现有编解码器匹配，则返回能力实例，如果指定的MIME类型与任何现有编解码器不匹配，则返回NULL。 |

### OH_AVCodec_GetCapabilityList()

```c
OH_AVCapability **OH_AVCodec_GetCapabilityList(OH_AVCodecType codecType, uint32_t *count)
```

**描述**

获取指定编解码器类型的能力列表。此功能会根据提供的编解码器类型检索出系统支持的所有匹配的编解码器能力。

>**说明：** 
> 
>编解码器能力列表的内存由系统底层全局维护，调用者无需管理其生命周期，不得手动分配或释放此内存。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodecType](capi-native-avcapability-h.md#oh_avcodectype) codecType | 指定要查询的编解码器类型。 |
| uint32_t *count | 输出参数。指向一个uint32_t变量的指针，用于存储匹配到的编解码器能力数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVCapability **](capi-avcapability-oh-avcapability.md) | 如果找到匹配项，则返回指向OH_AVCapability实例数组的指针。<br>         如果未找到匹配的编解码器或发生错误，则返回NULL。 |

### OH_AVCapability_IsHardware()

```c
bool OH_AVCapability_IsHardware(OH_AVCapability *capability)
```

**描述**

检查能力实例是否描述了硬件编解码器。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果能力实例描述的是硬件编解码器，则返回true，如果功能实例描述的是软件编解码器，则为false。 |

### OH_AVCapability_IsSecure()

```c
bool OH_AVCapability_IsSecure(OH_AVCapability *capability)
```

**描述**

检查能力实例是否描述了一个DRM解码器。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果能力实例描述的是DRM解码器，则返回true。<br>         如果能力实例描述的是非DRM解码器，则为false。 |

### OH_AVCapability_GetName()

```c
const char *OH_AVCapability_GetName(OH_AVCapability *capability)
```

**描述**

获取对应的编解码器名称。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回编解码器名称字符串。 |

### OH_AVCapability_GetMimeType()

```c
const char *OH_AVCapability_GetMimeType(OH_AVCapability *capability)
```

**描述**

获取编解码器的MIME类型。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char * | 返回编解码器的MIME类型字符串。 |

### OH_AVCapability_CheckMimeType()

```c
bool OH_AVCapability_CheckMimeType(OH_AVCapability *capability, const char *mimeType)
```

**描述**

检查编解码器的MIME类型是否与指定的MIME类型匹配。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |
| const char *mimeType | 要检查的目标MIME类型字符串。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果MIME类型匹配则返回true，否则返回false。 |

### OH_AVCapability_GetMaxSupportedInstances()

```c
int32_t OH_AVCapability_GetMaxSupportedInstances(OH_AVCapability *capability)
```

**描述**

获取编解码器支持的最大实例数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回支持的最大编解码器实例数。 |

### OH_AVCapability_GetEncoderBitrateRange()

```c
OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange(OH_AVCapability *capability, OH_AVRange *bitrateRange)
```

**描述**

获取编码器支持的比特率范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编码器能力指针。如果给的是解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *bitrateRange | 输出参数。编码器码率范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向编码器码率范围的指针为空指针。 |

### OH_AVCapability_IsEncoderBitrateModeSupported()

```c
bool OH_AVCapability_IsEncoderBitrateModeSupported(OH_AVCapability *capability, OH_BitrateMode bitrateMode)
```

**描述**

检查编码器是否支持特定的比特率模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编码器能力指针。如果给的是解码器能力指针，会导致未定义行为。 |
| [OH_BitrateMode](capi-native-avcodec-base-h.md#oh_bitratemode) bitrateMode | 比特率模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持该比特率模式，则返回true；如果不支持该比特率模式，则返回false。 |

### OH_AVCapability_GetEncoderQualityRange()

```c
OH_AVErrCode OH_AVCapability_GetEncoderQualityRange(OH_AVCapability *capability, OH_AVRange *qualityRange)
```

**描述**

获取编码器支持的质量范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编码器能力指针。如果给的是解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *qualityRange | 输出参数。编码器质量范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向编码器质量范围的指针为空指针。 |

### OH_AVCapability_GetEncoderComplexityRange()

```c
OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange(OH_AVCapability *capability, OH_AVRange *complexityRange)
```

**描述**

获取编码器支持的编码器复杂性范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编码器能力指针。如果给的是解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *complexityRange | 输出参数。编码器复杂度范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向编码器复杂度范围的指针为空指针。 |

### OH_AVCapability_GetAudioSupportedSampleRates()

```c
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates(OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)
```

**描述**

获取音频编解码器支持的采样率。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 音频编解码能力指针。如果给的是视频编解码器能力指针，会导致未定义行为。 |
| const int32_t **sampleRates | 输出参数。指向采样率数组的指针。 |
| uint32_t *sampleRateNum | 输出参数。采样率数组的元素数目。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向采样率数组的指针为空指针，或者指向采样率数组的元素数目的指针为空指针。<br> AV_ERR_UNKNOWN：未知错误。<br> AV_ERR_NO_MEMORY：内部使用内存分配失败。 |

### OH_AVCapability_GetAudioSupportedSampleRateRanges()

```c
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRateRanges(OH_AVCapability *capability, OH_AVRange **sampleRateRanges, uint32_t *rangesNum)
```

**描述**

获取音频编解码器支持的采样率范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 音频编解码能力指针。如果给的是视频编解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) **sampleRateRanges | 输出参数。指向采样率范围数组的指针。 |
| uint32_t *rangesNum | 输出参数。采样率范围数组的元素数目。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向采样率范围数组的指针为空指针，或者指向采样率范围数组的元素数目的指针为空指针。<br> AV_ERR_UNKNOWN：未知错误。<br> AV_ERR_NO_MEMORY：内部使用内存分配失败。 |

### OH_AVCapability_GetAudioChannelCountRange()

```c
OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange(OH_AVCapability *capability, OH_AVRange *channelCountRange)
```

**描述**

获取音频编解码器支持的音频通道计数范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 音频编解码能力指针。如果给的是视频编解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *channelCountRange | 输出参数。音频通道计数范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向音频通道计数范围的指针为空指针。 |

### OH_AVCapability_GetVideoWidthAlignment()

```c
OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment(OH_AVCapability *capability, int32_t *widthAlignment)
```

**描述**

获取视频编解码器支持的视频宽度对齐。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| int32_t *widthAlignment | 输出参数。视频宽度对齐。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向视频宽度对齐的指针为空指针。 |

### OH_AVCapability_GetVideoHeightAlignment()

```c
OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment(OH_AVCapability *capability, int32_t *heightAlignment)
```

**描述**

获取视频编解码器支持的视频高度对齐。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| int32_t *heightAlignment | 输出参数。视频高度对齐。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向视频高度对齐的指针为空指针。 |

### OH_AVCapability_GetVideoWidthRangeForHeight()

```c
OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight(OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)
```

**描述**

获取指定高度情况下视频编解码器支持的视频宽度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| int32_t height | 视频垂直像素数。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *widthRange | 输出参数。视频宽度范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者高度不在通过[OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange)获取支持的高度范围中，或者指向宽度范围的指针为空指针。 |

### OH_AVCapability_GetVideoHeightRangeForWidth()

```c
OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth(OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)
```

**描述**

获取指定宽度情况下视频编解码器支持的视频高度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| int32_t width | 视频水平像素数。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *heightRange | 输出参数。视频高度范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者宽度不在通过[OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange)获取支持的宽度范围中，或者指向高度范围的指针为空指针。 |

### OH_AVCapability_GetVideoWidthRange()

```c
OH_AVErrCode OH_AVCapability_GetVideoWidthRange(OH_AVCapability *capability, OH_AVRange *widthRange)
```

**描述**

获取视频编解码器支持的视频宽度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *widthRange | 输出参数。视频宽度范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向视频宽度范围的指针为空指针。 |

### OH_AVCapability_GetVideoHeightRange()

```c
OH_AVErrCode OH_AVCapability_GetVideoHeightRange(OH_AVCapability *capability, OH_AVRange *heightRange)
```

**描述**

获取视频编解码器支持的视频高度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *heightRange | 输出参数。视频高度范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向视频高度范围的指针为空指针。 |

### OH_AVCapability_IsVideoSizeSupported()

```c
bool OH_AVCapability_IsVideoSizeSupported(OH_AVCapability *capability, int32_t width, int32_t height)
```

**描述**

检查视频编解码器是否支持特定的视频大小。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| int32_t width | 视频水平像素数。 |
| int32_t height | 视频垂直像素数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持该视频大小，则返回true，如果不支持该视频大小，则返回false。 |

### OH_AVCapability_GetVideoFrameRateRange()

```c
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange(OH_AVCapability *capability, OH_AVRange *frameRateRange)
```

**描述**

获取视频编解码器支持的视频帧率范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *frameRateRange | 输出参数。视频帧率范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向视频帧率范围的指针为空指针。 |

### OH_AVCapability_GetVideoFrameRateRangeForSize()

```c
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize(OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)
```

**描述**

获取指定视频大小的视频编解码器支持的视频帧率范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| int32_t width | 视频水平像素数。 |
| int32_t height | 视频垂直像素数。 |
| [OH_AVRange](capi-avcapability-oh-avrange.md) *frameRateRange | 输出参数。视频帧率范围。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者宽度和高度组合不支持，或者指向帧率范围的指针为空指针。 |

### OH_AVCapability_AreVideoSizeAndFrameRateSupported()

```c
bool OH_AVCapability_AreVideoSizeAndFrameRateSupported(OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)
```

**描述**

检查视频编解码器是否支持视频大小和帧率的特定组合。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| int32_t width | 视频水平像素数。 |
| int32_t height | 视频垂直像素数。 |
| int32_t frameRate | 每秒帧数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持视频大小和帧率的组合，则返回true。如果不支持，则为false。 |

### OH_AVCapability_GetVideoSupportedPixelFormats()

```c
OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats(OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)
```

**描述**

获取视频编解码器支持的视频像素格式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。如果给的是音频编解码器能力指针，会导致未定义行为。 |
| const int32_t **pixelFormats | 输出参数。指向视频像素格式数组的指针。参考[OH_AVPixelFormat](../../reference/apis-avcodec-kit/capi-native-avformat-h.md#oh_avpixelformat)。 |
| uint32_t *pixelFormatNum | 输出参数。像素格式数组的元素数目。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向视频像素格式数组的指针为空指针，或者指向像素格式数组的元素数目的指针为空指针。<br> AV_ERR_UNKNOWN：未知错误。<br> AV_ERR_NO_MEMORY：内部使用内存分配失败。 |

### OH_AVCapability_GetVideoSupportedNativeBufferFormats()

```c
OH_AVErrCode OH_AVCapability_GetVideoSupportedNativeBufferFormats(OH_AVCapability *capability, const OH_NativeBuffer_Format **nativeBufferFormats, uint32_t *nativeBufferFormatNum)
```

**描述**

获取视频编解码器支持的OH_NativeBuffer格式。该函数提供了视频编解码器能够处理的OH_NativeBuffer格式信息，具体取值可见OH_NativeBuffer_Format。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 视频编解码能力指针。 |
| const [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_format) **nativeBufferFormats | 输出参数。指向OH_NativeBuffer_Format数组的指针。 |
| uint32_t *nativeBufferFormatNum | 输出参数。OH_NativeBuffer_Format数组的元素数目。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：能力实例无效、能力实例是音频编解码器能力、指向NativeBuffer格式数组的指针为空指针、<br> 或指向NativeBuffer格式数组的元素数目的指针为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_NO_MEMORY：内部使用内存分配失败。 |

### OH_AVCapability_GetSupportedProfiles()

```c
OH_AVErrCode OH_AVCapability_GetSupportedProfiles(OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)
```

**描述**

获取编解码器支持的档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |
| const int32_t **profiles | 输出参数。指向档次数组的指针。例如，H.264档次参考[OH_AVCProfile](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_avcprofile)。 |
| uint32_t *profileNum | 输出参数。档次数组的元素数目。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者指向档次数组的指针为空指针，或者指向档次数组的元素数目的指针为空指针。<br> AV_ERR_UNKNOWN：未知错误。<br> AV_ERR_NO_MEMORY：内部使用内存分配失败。 |

### OH_AVCapability_GetSupportedLevelsForProfile()

```c
OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile(OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)
```

**描述**

获取特定档次支持的编解码器级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |
| int32_t profile | 编解码器档次。 |
| const int32_t **levels | 输出参数。指向级别数组的指针。例如，H.264级别参考[OH_AVCLevel](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_avclevel)。 |
| uint32_t *levelNum | 输出参数。级别数组的元素数目。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：能力实例无效，或者档次不在通过[OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles)获取支持的档次数组中，或者指向级别数组的指针为空指针，或者指向级别数组的元素数目的指针为空指针。<br> AV_ERR_UNKNOWN：未知错误。<br> AV_ERR_NO_MEMORY：内部使用内存分配失败。 |

### OH_AVCapability_AreProfileAndLevelSupported()

```c
bool OH_AVCapability_AreProfileAndLevelSupported(OH_AVCapability *capability, int32_t profile, int32_t level)
```

**描述**

检查编解码器是否支持档次和级别的特定组合。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |
| int32_t profile | 编解码器档次。 |
| int32_t level | 编解码器级别。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持档次和级别的组合，则返回true。如果不支持，则为false。 |

### OH_AVCapability_IsFeatureSupported()

```c
bool OH_AVCapability_IsFeatureSupported(OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```

**描述**

检查编解码器是否支持指定特性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature | 编解码特性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果支持该特性，则返回true。如果不支持，则为false。 |

### OH_AVCapability_GetFeatureProperties()

```c
OH_AVFormat *OH_AVCapability_GetFeatureProperties(OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```

**描述**

获取指定特性的属性。需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要调用者手动释放。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCapability](capi-avcapability-oh-avcapability.md) *capability | 编解码能力指针。 |
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature | 编解码特性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | 返回指向OH_AVFormat实例的指针。 |


