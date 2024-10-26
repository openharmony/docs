# AVCapability


## 概述

AVCapability模块提供用于编解码能力查询的函数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avcapability.h](native__avcapability_8h.md) | 声明用于编解码能力查询到的Native API。| 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AVRange](_o_h___a_v_range.md) | 范围包含最小值和最大值。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_BitrateMode](#oh_bitratemode-1) [OH_BitrateMode](#oh_bitratemode) | 编码器的比特率模式。  | 
| typedef struct [OH_AVRange](_o_h___a_v_range.md) [OH_AVRange](#oh_avrange) | 范围包含最小值和最大值。  | 
| typedef enum [OH_AVCodecCategory](#oh_avcodeccategory-1) [OH_AVCodecCategory](#oh_avcodeccategory) | 编解码器类别。  | 
| typedef enum [OH_AVCapabilityFeature](#oh_avcapabilityfeature-1) [OH_AVCapabilityFeature](#oh_avcapabilityfeature) | 可以在特定编解码器场景中使用的可选特性。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_BitrateMode](#oh_bitratemode-1) { <br/>BITRATE_MODE_CBR = 0, <br/>BITRATE_MODE_VBR = 1, <br/>BITRATE_MODE_CQ = 2 } | 编码器的比特率模式。  | 
| [OH_AVCodecCategory](#oh_avcodeccategory-1) { HARDWARE = 0, SOFTWARE } | 编解码器类别。  | 
| [OH_AVCapabilityFeature](#oh_avcapabilityfeature-1) {<br/> VIDEO_ENCODER_TEMPORAL_SCALABILITY = 0, <br/>VIDEO_ENCODER_LONG_TERM_REFERENCE = 1, <br/>VIDEO_LOW_LATENCY = 2 <br/>} | 可以在特定编解码器场景中使用的可选特性。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OH_AVCapability \*[OH_AVCodec_GetCapability](#oh_avcodec_getcapability) (const char \*mime, bool isEncoder) | 获取系统推荐的编解码器能力。  | 
| OH_AVCapability \*[OH_AVCodec_GetCapabilityByCategory](#oh_avcodec_getcapabilitybycategory) (const char \*mime, bool isEncoder, [OH_AVCodecCategory](#oh_avcodeccategory) category) | 获取指定类别中的编解码器能力。 | 
| bool [OH_AVCapability_IsHardware](#oh_avcapability_ishardware) (OH_AVCapability \*capability) | 检查能力实例是否描述了硬件编解码器。  | 
| const char \* [OH_AVCapability_GetName](#oh_avcapability_getname) (OH_AVCapability \*capability) | 获取编解码器名称。  | 
| int32_t [OH_AVCapability_GetMaxSupportedInstances](#oh_avcapability_getmaxsupportedinstances) (OH_AVCapability \*capability) | 获取编解码器支持的最大实例数。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderBitrateRange](#oh_avcapability_getencoderbitraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*bitrateRange) | 获取编码器支持的比特率范围。  | 
| bool [OH_AVCapability_IsEncoderBitrateModeSupported](#oh_avcapability_isencoderbitratemodesupported) (OH_AVCapability \*capability, [OH_BitrateMode](#oh_bitratemode) bitrateMode) | 检查编码器是否支持特定的比特率模式。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderQualityRange](#oh_avcapability_getencoderqualityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*qualityRange) | 获取编码器支持的质量范围。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetEncoderComplexityRange](#oh_avcapability_getencodercomplexityrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*complexityRange) | 获取编码器支持的编码器复杂性范围。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetAudioSupportedSampleRates](#oh_avcapability_getaudiosupportedsamplerates) (OH_AVCapability \*capability, const int32_t \*\*sampleRates, uint32_t \*sampleRateNum) | 获取音频编解码器支持的采样率。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetAudioChannelCountRange](#oh_avcapability_getaudiochannelcountrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*channelCountRange) | 获取音频编解码器支持的音频通道计数范围。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthAlignment](#oh_avcapability_getvideowidthalignment) (OH_AVCapability \*capability, int32_t \*widthAlignment) | 获取视频编解码器支持的视频宽度对齐。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoHeightAlignment](#oh_avcapability_getvideoheightalignment) (OH_AVCapability \*capability, int32_t \*heightAlignment) | 获取视频编解码器支持的视频高度对齐。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthRangeForHeight](#oh_avcapability_getvideowidthrangeforheight) (OH_AVCapability \*capability, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | 获取指定高度情况下视频编解码器支持的视频宽度范围。  | 
| OH_AVErrCode [OH_AVCapability_GetVideoHeightRangeForWidth](#oh_avcapability_getvideoheightrangeforwidth) (OH_AVCapability \*capability, int32_t width, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | 获取指定宽度情况下视频编解码器支持的视频高度范围。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*widthRange) | 获取视频编解码器支持的视频宽度范围。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*heightRange) | 获取视频编解码器支持的视频高度范围。  | 
| bool [OH_AVCapability_IsVideoSizeSupported](#oh_avcapability_isvideosizesupported) (OH_AVCapability \*capability, int32_t width, int32_t height) | 检查视频编解码器是否支持特定的视频大小。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoFrameRateRange](#oh_avcapability_getvideoframeraterange) (OH_AVCapability \*capability, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | 获取视频编解码器支持的视频帧率范围。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoFrameRateRangeForSize](#oh_avcapability_getvideoframeraterangeforsize) (OH_AVCapability \*capability, int32_t width, int32_t height, [OH_AVRange](_o_h___a_v_range.md) \*frameRateRange) | 获取指定视频大小的视频编解码器支持的视频帧率范围。  | 
| bool [OH_AVCapability_AreVideoSizeAndFrameRateSupported](#oh_avcapability_arevideosizeandframeratesupported) (OH_AVCapability \*capability, int32_t width, int32_t height, int32_t frameRate) | 检查视频编解码器是否支持视频大小和帧率的特定组合。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetVideoSupportedPixelFormats](#oh_avcapability_getvideosupportedpixelformats) (OH_AVCapability \*capability, const int32_t \*\*pixelFormats, uint32_t \*pixelFormatNum) | 获取视频编解码器支持的视频像素格式。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles) (OH_AVCapability \*capability, const int32_t \*\*profiles, uint32_t \*profileNum) | 获取编解码器支持的档次。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVCapability_GetSupportedLevelsForProfile](#oh_avcapability_getsupportedlevelsforprofile) (OH_AVCapability \*capability, int32_t profile, const int32_t \*\*levels, uint32_t \*levelNum) | 获取特定档次支持的编解码器级别。  | 
| bool [OH_AVCapability_AreProfileAndLevelSupported](#oh_avcapability_areprofileandlevelsupported) (OH_AVCapability \*capability, int32_t profile, int32_t level) | 检查编解码器是否支持档次和级别的特定组合。  | 
| bool [OH_AVCapability_IsFeatureSupported](#oh_avcapability_isfeaturesupported) (OH_AVCapability \*capability, [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature) | 检查编解码器是否支持指定特性。  | 
| OH_AVFormat \* [OH_AVCapability_GetFeatureProperties](#oh_avcapability_getfeatureproperties) (OH_AVCapability \*capability, [OH_AVCapabilityFeature](#oh_avcapabilityfeature) feature) | 获取指定特性的属性。 需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要调用者手动释放。  | 


## 类型定义说明


### OH_AVCapabilityFeature

```
typedef enum OH_AVCapabilityFeature OH_AVCapabilityFeature
```
**描述**
可以在特定编解码器场景中使用的可选特性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12


### OH_AVCodecCategory

```
typedef enum OH_AVCodecCategory OH_AVCodecCategory
```
**描述**
编解码器类别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_AVRange

```
typedef struct OH_AVRange OH_AVRange
```
**描述**
范围包含最小值和最大值。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


### OH_BitrateMode

```
typedef enum OH_BitrateMode OH_BitrateMode
```
**描述**
编码器的比特率模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10


## 枚举类型说明


### OH_AVCapabilityFeature

```
enum OH_AVCapabilityFeature
```
**描述**
可以在特定编解码器场景中使用的可选特性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| VIDEO_ENCODER_TEMPORAL_SCALABILITY  | 编解码器支持时域可分层特性，只用于视频编码场景。   | 
| VIDEO_ENCODER_LONG_TERM_REFERENCE  | 编解码器支持长期参考帧特性，只用于视频编码场景。   | 
| VIDEO_LOW_LATENCY  | 编解码器支持低时延特性，用于视频编码和视频解码场景。   | 


### OH_AVCodecCategory

```
enum OH_AVCodecCategory
```
**描述**
编解码器类别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| HARDWARE  | 硬件编解码。   | 
| SOFTWARE  | 软件编解码。   | 


### OH_BitrateMode

```
enum OH_BitrateMode
```
**描述**
编码器的比特率模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| BITRATE_MODE_CBR  | 恒定比特率模式。   | 
| BITRATE_MODE_VBR  | 可变比特率模式，码率仅作参考。   | 
| BITRATE_MODE_CQ  | 恒定质量模式。   | 


## 函数说明


### OH_AVCapability_AreProfileAndLevelSupported()

```
bool OH_AVCapability_AreProfileAndLevelSupported (OH_AVCapability *capability, int32_t profile, int32_t level)
```
**描述**
检查编解码器是否支持档次和级别的特定组合。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 
| profile | 编解码器档次。  | 
| level | 编解码器级别。  | 

**返回：**

如果支持档次和级别的组合，则返回true。 如果不支持，则为false。


### OH_AVCapability_AreVideoSizeAndFrameRateSupported()

```
bool OH_AVCapability_AreVideoSizeAndFrameRateSupported (OH_AVCapability *capability, int32_t width, int32_t height, int32_t frameRate)
```
**描述**
检查视频编解码器是否支持视频大小和帧率的特定组合。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| width | 视频水平像素数。  | 
| height | 视频垂直像素数。  | 
| frameRate | 每秒帧数。  | 

**返回：**

如果支持视频大小和帧率的组合，则返回true。 如果不支持，则为false。


### OH_AVCapability_GetAudioChannelCountRange()

```
OH_AVErrCode OH_AVCapability_GetAudioChannelCountRange (OH_AVCapability *capability, OH_AVRange *channelCountRange)
```
**描述**
获取音频编解码器支持的音频通道计数范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 音频编解码能力指针。不能填入视频编解码器能力指针。  | 
| channelCountRange | 输出参数。音频通道计数范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向音频通道计数范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetAudioSupportedSampleRates()

```
OH_AVErrCode OH_AVCapability_GetAudioSupportedSampleRates (OH_AVCapability *capability, const int32_t **sampleRates, uint32_t *sampleRateNum)
```
**描述**
获取音频编解码器支持的采样率。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 音频编解码能力指针。不能填入视频编解码器能力指针。  | 
| sampleRates | 输出参数。指向采样率数组的指针。  | 
| sampleRateNum | 输出参数。采样率数组的元素数目。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向采样率数组的指针为空指针，或者指向采样率数组的元素数目的指针为空指针，返回AV_ERR_INVALID_VAL。 当遇到未知错误，返回AV_ERR_UNKNOWN。 当内部使用内存分配失败，返回AV_ERR_NO_MEMORY。


### OH_AVCapability_GetEncoderBitrateRange()

```
OH_AVErrCode OH_AVCapability_GetEncoderBitrateRange (OH_AVCapability *capability, OH_AVRange *bitrateRange)
```
**描述**
获取编码器支持的比特率范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。  | 
| bitrateRange | 输出参数。编码器码率范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向编码器码率范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetEncoderComplexityRange()

```
OH_AVErrCode OH_AVCapability_GetEncoderComplexityRange (OH_AVCapability *capability, OH_AVRange *complexityRange)
```
**描述**
获取编码器支持的编码器复杂性范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。  | 
| complexityRange | 输出参数。编码器复杂度范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向编码器复杂度范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetEncoderQualityRange()

```
OH_AVErrCode OH_AVCapability_GetEncoderQualityRange (OH_AVCapability *capability, OH_AVRange *qualityRange)
```
**描述**
获取编码器支持的质量范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。  | 
| qualityRange | 输出参数。编码器质量范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向编码器质量范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetFeatureProperties()

```
OH_AVFormat* OH_AVCapability_GetFeatureProperties (OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```
**描述**
获取指定特性的属性。 需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要调用者手动释放。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 
| feature | 编解码特性，请参阅[OH_AVCapabilityFeature](#oh_avcapabilityfeature)。  | 

**返回：**

返回指向OH_AVFormat实例的指针。


### OH_AVCapability_GetMaxSupportedInstances()

```
int32_t OH_AVCapability_GetMaxSupportedInstances (OH_AVCapability *capability)
```
**描述**
获取编解码器支持的最大实例数。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 

**返回：**

返回支持的最大编解码器实例数。


### OH_AVCapability_GetName()

```
const char* OH_AVCapability_GetName (OH_AVCapability *capability)
```
**描述**
获取编解码器名称。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 

**返回：**

返回编解码器名称字符串。


### OH_AVCapability_GetSupportedLevelsForProfile()

```
OH_AVErrCode OH_AVCapability_GetSupportedLevelsForProfile (OH_AVCapability *capability, int32_t profile, const int32_t **levels, uint32_t *levelNum)
```
**描述**
获取特定档次支持的编解码器级别。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 
| profile | 编解码器档次。  | 
| levels | 输出参数。指向级别数组的指针。  | 
| levelNum | 输出参数。级别数组的元素数目。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者档次不在通过[OH_AVCapability_GetSupportedProfiles](#oh_avcapability_getsupportedprofiles)获取支持的档次数组中， 或者指向级别数组的指针为空指针，或者指向级别数组的元素数目的指针为空指针，返回AV_ERR_INVALID_VAL。 当遇到未知错误，返回AV_ERR_UNKNOWN。 当内部使用内存分配失败，返回AV_ERR_NO_MEMORY。


### OH_AVCapability_GetSupportedProfiles()

```
OH_AVErrCode OH_AVCapability_GetSupportedProfiles (OH_AVCapability *capability, const int32_t **profiles, uint32_t *profileNum)
```
**描述**
获取编解码器支持的档次。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 
| profiles | 输出参数。指向档次数组的指针。  | 
| profileNum | 输出参数。档次数组的元素数目。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向档次数组的指针为空指针，或者指向档次数组的元素数目的指针为空指针，返回AV_ERR_INVALID_VAL。 当遇到未知错误，返回AV_ERR_UNKNOWN。 当内部使用内存分配失败，返回AV_ERR_NO_MEMORY。


### OH_AVCapability_GetVideoFrameRateRange()

```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRange (OH_AVCapability *capability, OH_AVRange *frameRateRange)
```
**描述**
获取视频编解码器支持的视频帧率范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| frameRateRange | 输出参数。视频帧率范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向视频帧率范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetVideoFrameRateRangeForSize()

```
OH_AVErrCode OH_AVCapability_GetVideoFrameRateRangeForSize (OH_AVCapability *capability, int32_t width, int32_t height, OH_AVRange *frameRateRange)
```
**描述**
获取指定视频大小的视频编解码器支持的视频帧率范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| width | 视频水平像素数。  | 
| height | 视频垂直像素数。  | 
| frameRateRange | 输出参数。视频帧率范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者宽度和高度组合不支持，或者指向帧率范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetVideoHeightAlignment()

```
OH_AVErrCode OH_AVCapability_GetVideoHeightAlignment (OH_AVCapability *capability, int32_t *heightAlignment)
```
**描述**
获取视频编解码器支持的视频高度对齐。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| heightAlignment | 输出参数。视频高度对齐。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向视频高度对齐的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetVideoHeightRange()

```
OH_AVErrCode OH_AVCapability_GetVideoHeightRange (OH_AVCapability *capability, OH_AVRange *heightRange)
```
**描述**
获取视频编解码器支持的视频高度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| heightRange | 输出参数。视频高度范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向视频高度范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetVideoHeightRangeForWidth()

```
OH_AVErrCode OH_AVCapability_GetVideoHeightRangeForWidth (OH_AVCapability *capability, int32_t width, OH_AVRange *heightRange)
```
**描述**
获取指定宽度情况下视频编解码器支持的视频高度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| width | 视频水平像素数。  | 
| heightRange | 输出参数。视频高度范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者宽度不在通过[OH_AVCapability_GetVideoWidthRange](#oh_avcapability_getvideowidthrange)获取支持的宽度范围中， 或者指向高度范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetVideoSupportedPixelFormats()

```
OH_AVErrCode OH_AVCapability_GetVideoSupportedPixelFormats (OH_AVCapability *capability, const int32_t **pixelFormats, uint32_t *pixelFormatNum)
```
**描述**
获取视频编解码器支持的视频像素格式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| pixelFormats | 输出参数。指向视频像素格式数组的指针。  | 
| pixelFormatNum | 输出参数。像素格式数组的元素数目。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向视频像素格式数组的指针为空指针，或者指向像素格式数组的元素数目的指针为空指针，返回AV_ERR_INVALID_VAL。 当遇到未知错误，返回AV_ERR_UNKNOWN。 当内部使用内存分配失败，返回AV_ERR_NO_MEMORY。


### OH_AVCapability_GetVideoWidthAlignment()

```
OH_AVErrCode OH_AVCapability_GetVideoWidthAlignment (OH_AVCapability *capability, int32_t *widthAlignment)
```
**描述**
获取视频编解码器支持的视频宽度对齐。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| widthAlignment | 输出参数。视频宽度对齐。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向视频宽度对齐的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetVideoWidthRange()

```
OH_AVErrCode OH_AVCapability_GetVideoWidthRange (OH_AVCapability *capability, OH_AVRange *widthRange)
```
**描述**
获取视频编解码器支持的视频宽度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| widthRange | 输出参数。视频宽度范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者指向视频宽度范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_GetVideoWidthRangeForHeight()

```
OH_AVErrCode OH_AVCapability_GetVideoWidthRangeForHeight (OH_AVCapability *capability, int32_t height, OH_AVRange *widthRange)
```
**描述**
获取指定高度情况下视频编解码器支持的视频宽度范围。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| height | 视频垂直像素数。  | 
| widthRange | 输出参数。视频宽度范围。  | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当能力实例无效，或者高度不在通过[OH_AVCapability_GetVideoHeightRange](#oh_avcapability_getvideoheightrange)获取支持的高度范围中， 或者指向宽度范围的指针为空指针，返回AV_ERR_INVALID_VAL。


### OH_AVCapability_IsEncoderBitrateModeSupported()

```
bool OH_AVCapability_IsEncoderBitrateModeSupported (OH_AVCapability *capability, OH_BitrateMode bitrateMode)
```
**描述**
检查编码器是否支持特定的比特率模式。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编码器能力指针。不能填入解码器能力指针。  | 
| bitrateMode | 比特率模式。  | 

**返回：**

如果支持该比特率模式，则返回true；如果不支持该比特率模式，则返回false。


### OH_AVCapability_IsFeatureSupported()

```
bool OH_AVCapability_IsFeatureSupported (OH_AVCapability *capability, OH_AVCapabilityFeature feature)
```
**描述**
检查编解码器是否支持指定特性。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 
| feature | 编解码特性，请参阅[OH_AVCapabilityFeature](#oh_avcapabilityfeature)。  | 

**返回：**

如果支持该特性，则返回true。如果不支持，则为false。


### OH_AVCapability_IsHardware()

```
bool OH_AVCapability_IsHardware (OH_AVCapability *capability)
```
**描述**
检查能力实例是否描述了硬件编解码器。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 编解码能力指针。  | 

**返回：**

如果能力实例描述的是硬件编解码器，则返回true， 如果功能实例描述的是软件编解码器，则为false。


### OH_AVCapability_IsVideoSizeSupported()

```
bool OH_AVCapability_IsVideoSizeSupported (OH_AVCapability *capability, int32_t width, int32_t height)
```
**描述**
检查视频编解码器是否支持特定的视频大小。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capability | 视频编解码能力指针。不能填入音频编解码器能力指针。  | 
| width | 视频水平像素数。  | 
| height | 视频垂直像素数。  | 

**返回：**

如果支持该视频大小，则返回true，如果不支持该视频大小，则返回false。


### OH_AVCodec_GetCapability()

```
OH_AVCapability* OH_AVCodec_GetCapability (const char *mime, bool isEncoder)
```
**描述**
获取系统推荐的编解码器能力。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mime | MIME类型描述字符串，请参阅**AVCODEC_MIME_TYPE**。  | 
| isEncoder | 编码器为true，解码器为false。  | 

**返回：**

如果现有编解码器匹配，则返回能力实例， 如果指定的MIME类型与任何现有编解码器不匹配，则返回NULL。


### OH_AVCodec_GetCapabilityByCategory()

```
OH_AVCapability* OH_AVCodec_GetCapabilityByCategory (const char *mime, bool isEncoder, OH_AVCodecCategory category)
```
**描述**
获取指定类别中的编解码器能力。 通过指定类别， 匹配的编解码器仅限于硬件编解码器或软件编解码器。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mime | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量)。  | 
| isEncoder | 编码器为true，解码器为false。  | 
| category | 编解码器类别。  | 

**返回：**

如果现有编解码器匹配，则返回能力实例， 如果指定的MIME类型与任何现有编解码器不匹配，则返回NULL。
