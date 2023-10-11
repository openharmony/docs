# AVCapability


## 概述

AVCapability模块提供用于编解码能力查询的函数。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avcapability.h](native__avcapability_8h.md) | 声明用于编解码能力查询到的Native API。<br>**引用文件**：<multimedia/player_framework/native_avcapability.h> <br>**库**：libnative_media_codecbase.so| 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVRange](_o_h___a_v_range.md) | 范围包含最小值和最大值。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_BitrateMode](#oh_bitratemode) | 编码器的比特率模式。 | 
| [OH_AVRange](#oh_avrange) | 范围包含最小值和最大值。 | 
| [OH_AVCodecCategory](#oh_avcodeccategory) | 编解码器类别。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_BitrateMode](#oh_bitratemode) { **BITRATE_MODE_CBR** = 0, **BITRATE_MODE_VBR** = 1, **BITRATE_MODE_CQ** = 2 } | 编码器的比特率模式。 | 
| [OH_AVCodecCategory](#oh_avcodeccategory) { **HARDWARE** = 0, **SOFTWARE** } | 编解码器类别。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVCodec_GetCapability](#oh_avcodec_getcapability) (const char \*mime, bool isEncoder) | 获取系统推荐的编解码器能力。 | 
| \*[OH_AVCodec_GetCapabilityByCategory](#oh_avcodec_getcapabilitybycategory) (const char \*mime, bool isEncoder, [OH_AVCodecCategory](#oh_avcodeccategory) category) | 获取指定类别中的编解码器能力。通过指定类别， 匹配的编解码器仅限于硬件编解码器或软件编解码器。 | 
| [OH_AVCapability_IsHardware](#oh_avcapability_ishardware) (OH_AVCapability \*capability) | 检查能力实例是否描述了硬件编解码器。 | 
| \*[OH_AVCapability_GetName](#oh_avcapability_getname) (OH_AVCapability \*capability) | 获取编解码器名称。 | 
| [OH_AVCapability_GetMaxSupportedInstances](#oh_avcapability_getmaxsupportedinstances) (OH_AVCapability \*capability) | 获取编解码器支持的最大实例数。 | 
| [OH_AVCapability_GetEncoderBitrateRange](#oh_avcapability_getencoderbitraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*bitrateRange) | 获取编码器支持的比特率范围。 | 
| [OH_AVCapability_IsEncoderBitrateModeSupported](#oh_avcapability_isencoderbitratemodesupported) (OH_AVCapability \*capability, [OH_BitrateMode](#oh_bitratemode) bitrateMode) | 检查编码器是否支持特定的比特率模式。 | 
| [OH_AVCapability_GetEncoderQualityRange](#oh_avcapability_getencoderqualityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*qualityRange) | 获取编码器支持的质量范围。 | 
| [OH_AVCapability_GetEncoderComplexityRange](#oh_avcapability_getencodercomplexityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*complexityRange) | 获取编码器支持的编码器复杂性范围。 | 
| [OH_AVCapability_GetAudioSupportedSampleRates](#oh_avcapability_getaudiosupportedsamplerates) (OH_AVCapability \*capability, const int32_t \*\*sampleRates, uint32_t \*sampleRateNum) | 获取音频编解码器支持的采样速率。 | 
| [OH_AVCapability_GetAudioChannelCountRange](#oh_avcapability_getaudiochannelcountrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*channelCountRange) | 获取音频编解码器支持的音频通道计数范围。 | 
| [OH_AVCapability_GetVideoWidthAlignment](#oh_avcapability_getvideowidthalignment) (OH_AVCapability \*capability, int32_t \*widthAlignment) | 获取视频编解码器支持的视频宽度对齐。 | 
| [OH_AVCapability_GetVideoHeightAlignment](#oh_avcapability_getvideoheightalignment) (OH_AVCapability \*capability, int32_t \*heightAlignment) | 获取视频编解码器支持的视频高度对齐。 | 
| [OH_AVCapability_GetVideoWidthRangeForHeight](#oh_avcapability_getvideowidthrangeforheight) (OH_AVCapability \*capability, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | 获取指定高度情况下视频编解码器支持的视频宽度范围。 | 
| [OH_AVCapability_GetVideoHeightRangeForWidth](#oh_avcapability_getvideoheightrangeforwidth) (OH_AVCapability \*capability, int32_t width, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | 获取指定宽度情况下视频编解码器支持的视频高度范围。 | 
| [OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | 获取视频编解码器支持的视频宽度范围。 | 
| [OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | 获取视频编解码器支持的视频高度范围。 | 
| [OH_AVCapability_IsVideoSizeSupported](#oh_avcapability_isvideosizesupported) (OH_AVCapability \*capability, int32_t width, int32_t height) | 检查视频编解码器是否支持特定的视频大小。 | 
| [OH_AVCapability_GetVideoFrameRateRange](#oh_avcapability_getvideoframeraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | 获取视频编解码器支持的视频帧率范围。 | 
| [OH_AVCapability_GetVideoFrameRateRangeForSize](#oh_avcapability_getvideoframeraterangeforsize) (OH_AVCapability \*capability, int32_t width, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | 获取指定视频大小的视频编解码器支持的视频帧率范围。 | 
| [OH_AVCapability_AreVideoSizeAndFrameRateSupported](#oh_avcapability_arevideosizeandframeratesupported) (OH_AVCapability \*capability, int32_t width, int32_t height, int32_t frameRate) | 检查视频编解码器是否支持视频大小和帧率的特定组合。 | 
| [OH_AVCapability_GetVideoSupportedPixelFormats](#oh_avcapability_getvideosupportedpixelformats) (OH_AVCapability \*capability, const int32_t \*\*pixelFormats, uint32_t \*pixelFormatNum) | 获取视频编解码器支持的视频像素格式。 | 
| [OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles) (OH_AVCapability \*capability, const int32_t \*\*profiles, uint32_t \*profileNum) | 获取编解码器支持的配置文件。 | 
| [OH_AVCapability_GetSupportedLevelsForProfile](#oh_avcapability_getsupportedlevelsforprofile) (OH_AVCapability \*capability, int32_t profile, const int32_t \*\*levels, uint32_t \*levelNum) | 获取特定配置文件支持的编解码器级别。 | 
| [OH_AVCapability_AreProfileAndLevelSupported](#oh_avcapability_areprofileandlevelsupported) (OH_AVCapability \*capability, int32_t profile, int32_t level) | 检查编解码器是否支持配置文件和级别的特定组合。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| **OH_AVRange::minVal** | 范围下限 | 
| **OH_AVRange::maxVal** | 范围上限 | 


## 类型定义说明


### OH_AVCodecCategory

  
```
typedef enum OH_AVCodecCategory OH_AVCodecCategory
```

**描述：**

编解码器类别。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10


### OH_AVRange

  
```
typedef struct OH_AVRange OH_AVRange
```

**描述：**

范围包含最小值和最大值。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10


### OH_BitrateMode

  
```
typedef enum OH_BitrateMode OH_BitrateMode
```

**描述：**

编码器的比特率模式。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10


## 枚举类型说明


### OH_AVCodecCategory

  
```
enum OH_AVCodecCategory
```

**描述：**

编解码器类别。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| HARDWARE | 硬件编解码。 | 
| SOFTWARE | 软件编解码。 | 


### OH_BitrateMode

  
```
enum OH_BitrateMode
```

**描述：**

编码器的比特率模式。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

10

| 枚举值 | 描述 |
| -------- | -------- |
| BITRATE_MODE_CBR | 恒定比特率模式。 | 
| BITRATE_MODE_VBR | 可变比特率模式。 | 
| BITRATE_MODE_CQ | 恒定质量模式。 | 


## 函数说明


### OH_AVCapability_AreProfileAndLevelSupported()

  
```
bool OH_AVCapability_AreProfileAndLevelSupported (OH_AVCapability *capability, int32_t profile, int32_t level)
```

**描述：**

检查编解码器是否支持配置文件和级别的特定组合。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针 | 
| profile | 编解码器配置文件 | 
| level | 编解码器级别 | 

**返回：**

如果支持配置文件和级别的组合，则返回true。 如果不支持，则为false。

**起始版本：**

10


### OH_AVCapability_AreVideoSizeAndFrameRateSupported()

  
```
bool OH_AVCapability_AreVideoSizeAndFrameRateSupported (OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)
```

**描述：**

检查视频编解码器是否支持视频大小和帧率的特定组合。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| width | 视频水平像素数。 | 
| height | 视频垂直像素数。 | 
| frameRate | 每秒帧数。 | 

**返回：**

如果支持视频大小和帧率的组合，则返回true。 如果不支持，则为false。

**起始版本：**

10


### OH_AVCapability_GetAudioChannelCountRange()

  
```
OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange (OH_AVCapability *capability, OH_AVRange *channelCountRange)
```

**描述：**

获取音频编解码器支持的音频通道计数范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 音频编解码能力指针。不能填入视频编解码器能力指针。 | 
| channelCountRange | 输出参数。音频通道计数范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetAudioSupportedSampleRates()

  
```
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates (OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)
```

**描述：**

获取音频编解码器支持的采样速率。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 音频编解码能力指针。不能填入视频编解码器能力指针。 | 
| sampleRates | 输出参数。指向采样速率数组的指针。 | 
| sampleRateNum | 输出参数。采样率数组的元素数目。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetEncoderBitrateRange()

  
```
OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange (OH_AVCapability *capability, OH_AVRange *bitrateRange)
```

**描述：**

获取编码器支持的比特率范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。 | 
| bitrateRange | 输出参数。编码器码率范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetEncoderComplexityRange()

  
```
OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange (OH_AVCapability *capability, OH_AVRange *complexityRange)
```

**描述：**

获取编码器支持的编码器复杂性范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。 | 
| complexityRange | 输出参数。编码器复杂度范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetEncoderQualityRange()

  
```
OH_AVErrCode OH_AVCapability_GetEncoderQualityRange (OH_AVCapability *capability, OH_AVRange *qualityRange)
```

**描述：**

获取编码器支持的质量范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。 | 
| qualityRange | 输出参数。编码器质量范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetMaxSupportedInstances()

  
```
int32_t OH_AVCapability_GetMaxSupportedInstances (OH_AVCapability *capability)
```

**描述：**

获取编解码器支持的最大实例数。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。 | 

**返回：**

返回支持的最大编解码器实例数。

**起始版本：**

10


### OH_AVCapability_GetName()

  
```
const char* OH_AVCapability_GetName (OH_AVCapability *capability)
```

**描述：**

获取编解码器名称。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。 | 

**返回：**

返回编解码器名称字符串。

**起始版本：**

10


### OH_AVCapability_GetSupportedLevelsForProfile()

  
```
OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile (OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)
```

**描述：**

获取特定配置文件支持的编解码器级别。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。 | 
| profile | 编解码器配置文件。 | 
| levels | 输出参数。指向级别数组的指针。 | 
| levelNum | 输出参数。级别数组的元素数目。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetSupportedProfiles()

  
```
OH_AVErrCode OH_AVCapability_GetSupportedProfiles (OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)
```

**描述：**

获取编解码器支持的配置文件。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。 | 
| profiles | 输出参数。指向配置文件数组的指针。 | 
| profileNum | 输出参数。配置文件数组的元素数目。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoFrameRateRange()

  
```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange (OH_AVCapability *capability, OH_AVRange *frameRateRange)
```

**描述：**

获取视频编解码器支持的视频帧率范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| frameRateRange | 输出参数。视频帧率范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoFrameRateRangeForSize()

  
```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize (OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)
```

**描述：**

获取指定视频大小的视频编解码器支持的视频帧率范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| width | 视频水平像素数。 | 
| height | 视频垂直像素数。 | 
| frameRateRange | 输出参数。视频帧率范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoHeightAlignment()

  
```
OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment (OH_AVCapability *capability, int32_t *heightAlignment)
```

**描述：**

获取视频编解码器支持的视频高度对齐。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| heightAlignment | 输出参数。视频高度对齐。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoHeightRange()

  
```
OH_AVErrCode OH_AVCapability_GetVideoHeightRange (OH_AVCapability *capability, OH_AVRange *heightRange)
```

**描述：**

获取视频编解码器支持的视频高度范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| heightRange | 输出参数。视频高度范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoHeightRangeForWidth()

  
```
OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth (OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)
```

**描述：**

获取指定宽度情况下视频编解码器支持的视频高度范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| width | 视频水平像素数。 | 
| heightRange | 输出参数。视频高度范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoSupportedPixelFormats()

  
```
OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats (OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)
```

**描述：**

获取视频编解码器支持的视频像素格式。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| pixelFormats | 输出参数。指向视频像素格式数组的指针。 | 
| pixelFormatNum | 输出参数。像素格式数组的元素数目。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoWidthAlignment()

  
```
OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment (OH_AVCapability *capability, int32_t *widthAlignment)
```

**描述：**

获取视频编解码器支持的视频宽度对齐。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| widthAlignment | 输出参数。视频宽度对齐 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoWidthRange()

  
```
OH_AVErrCode OH_AVCapability_GetVideoWidthRange (OH_AVCapability *capability, OH_AVRange *widthRange)
```

**描述：**

获取视频编解码器支持的视频宽度范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| widthRange | 输出参数。视频宽度范围 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_GetVideoWidthRangeForHeight()

  
```
OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight (OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)
```

**描述：**

获取指定高度情况下视频编解码器支持的视频宽度范围。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| height | 视频垂直像素数。 | 
| widthRange | 输出参数。视频宽度范围。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_AVCapability_IsEncoderBitrateModeSupported()

  
```
bool OH_AVCapability_IsEncoderBitrateModeSupported (OH_AVCapability *capability, OH_BitrateMode bitrateMode)
```

**描述：**

检查编码器是否支持特定的比特率模式。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。 | 
| bitrateMode | 比特率模式。 | 

**返回：**

如果支持该比特率模式，则返回true；如果不支持该比特率模式，则返回false。

**起始版本：**

10


### OH_AVCapability_IsHardware()

  
```
bool OH_AVCapability_IsHardware (OH_AVCapability *capability)
```

**描述：**

检查能力实例是否描述了硬件编解码器。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。 | 

**返回：**

如果能力实例描述的是硬件编解码器，则返回true， 如果功能实例描述的是软件编解码器，则为false。

**起始版本：**

10


### OH_AVCapability_IsVideoSizeSupported()

  
```
bool OH_AVCapability_IsVideoSizeSupported (OH_AVCapability *capability, int32_t width, int32_t height)
```

**描述：**

检查视频编解码器是否支持特定的视频大小。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。 | 
| width | 视频水平像素数。 | 
| height | 视频垂直像素数。 | 

**返回：**

如果支持该视频大小，则返回true，如果不支持该视频大小，则返回false。

**起始版本：**

10


### OH_AVCodec_GetCapability()

  
```
OH_AVCapability* OH_AVCodec_GetCapability (const char *mime, bool isEncoder)
```

**描述：**

获取系统推荐的编解码器能力。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mime | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量)。 | 
| isEncoder | 编码器为true，解码器为false。 | 

**返回：**

如果现有编解码器匹配，则返回能力实例， 如果指定的MIME类型与任何现有编解码器不匹配，则返回NULL。

**起始版本：**

10


### OH_AVCodec_GetCapabilityByCategory()

  
```
OH_AVCapability* OH_AVCodec_GetCapabilityByCategory (const char *mime, bool isEncoder, OH_AVCodecCategory category)
```

**描述：**

获取指定类别中的编解码器能力。

通过指定类别， 匹配的编解码器仅限于硬件编解码器或软件编解码器。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mime | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量)。 | 
| isEncoder | 编码器为true，解码器为false。 | 
| category | 编解码器类别。 | 

**返回：**

如果现有编解码器匹配，则返回能力实例， 如果指定的MIME类型与任何现有编解码器不匹配，则返回NULL。

**起始版本：**

10
