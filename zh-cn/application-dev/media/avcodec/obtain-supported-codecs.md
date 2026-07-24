# 获取支持的编解码能力

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yang-xiaoyu5-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

因来源、编解码协议及设备能力的不同，导致不同设备上可用的编解码器及其能力存在差异。

为确保编解码行为符合预期，请通过音视频编解码能力接口查询系统支持的编解码器及其能力，选择符合开发需求的编解码器，并正确配置参数。

## 通用开发指导

1. 在CMake脚本中链接动态库。

   ``` cmake
   target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
   target_link_libraries(sample PUBLIC libnative_media_core.so)
   target_link_libraries(sample PUBLIC libnative_media_venc.so)
   target_link_libraries(sample PUBLIC libnative_media_vdec.so)
   target_link_libraries(sample PUBLIC libnative_media_acodec.so)
   ```
   > **说明：**
   >
   > 上述'sample'字样仅为示例，此处由开发者根据实际工程目录自定义。

2. 添加头文件。

   ```c++
   #include <algorithm>
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_audiocodec.h>
   #include <multimedia/player_framework/native_avcodec_videoencoder.h>
   #include <multimedia/player_framework/native_avcodec_videodecoder.h>
   ```

3. 获得音视频编解码能力实例。

   可通过以下方式获取音视频编解码能力实例。获取成功后，可继续执行后续操作。实例无显式释放接口，使用完毕后系统会自动释放资源并回收。

   方式一：通过[OH_AVCodec_GetCapability](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcodec_getcapability)获取系统推荐的音视频编解码器能力实例。
   
   ```c++
   // 获取系统推荐的音频AAC解码器能力实例。
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, false);
   ```

   方式二：通过[OH_AVCodec_GetCapabilityByCategory](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcodec_getcapabilitybycategory)获取指定软硬件的编解码能力实例。

   ```c++
   // 获取指定硬件的视频AVC编码器能力实例。
   OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true, HARDWARE);
   ```

   方式三：从API version 24开始，开发者可调用[OH_AVCodec_GetCapabilityList](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcodec_getcapabilitylist)接口，获取指定编解码器类型（如视频解码器）的全量能力实例列表。

   ```c++
   // 获取系统中所有视频解码器的能力实例列表。
   uint32_t count = 0;
   OH_AVCapability **capabilityList = OH_AVCodec_GetCapabilityList(OH_AVCODEC_TYPE_VIDEO_DECODER, &count);
   ```

4. 按需调用相应的查询接口。详细的API说明请参考[native_avcapability.h](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md)。

## 场景化开发

基于开发过程中可能遇到的具体场景，此处将举例说明能力查询接口的使用方法。

### 创建指定名称的编解码器

如果系统存在多个相同MIME类型的编解码器，使用`OH_XXX_CreateByMime`系列接口创建系统推荐的编解码器。如需创建其他编解码器，先获取名称，再通过`OH_XXX_CreateByName`系列接口创建指定名称的编解码器。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_GetName     | 获取对应的编解码器名称。 |

当H.264软件解码器和H.264硬件解码器同时存在时，创建H.264软件解码器的示例代码如下。

```c++
// 1. 获取H.264软件解码器能力实例。
OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
if (capability != nullptr) {
   // 2. 获取H.264软件解码器名称。
   const char *codecName = OH_AVCapability_GetName(capability);
   // 3. 创建H.264软件解码器实例。
   OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(codecName);
}
```

### 针对软硬件类别差异化配置编解码器参数

以下是软件编解码器和硬件编解码器的定义。

* **软件编解码器：** 指在CPU上工作的编解码器，具有迭代灵活、兼容性好和扩展能力强等特点。

* **硬件编解码器：** 指在专有硬件上工作的编解码器，具有低功耗、高性能和减少CPU负载等特点。

在硬件编解码器充足且满足能力要求时，优先使用硬件编解码器；否则使用软件编解码器。开发者可根据编解码器类别配置不同的编解码参数。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_IsHardware  | 确认能力实例对应的编解码器是否为硬件编解码器。 |

视频编码的软硬件类别差异化配置帧率示例如下。

```c++
// 1. 确认推荐的H.264编码器的软硬件类别。
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
bool isHardware = OH_AVCapability_IsHardware(capability);
// 2. 基于软硬件类别差异化配置。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // 异常处理。
}
double frameRate = isHardware ? 60.0 : 30.0;
if (!OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, frameRate)) {
   // 异常处理。
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);
```

### 创建多路编解码器

部分业务场景涉及创建多路编解码器，基于系统内存、处理器和带宽等资源的限制，某一编解码器的实例数是有限的，不能无限制创建。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_GetMaxSupportedInstances  | 获取能力实例对应编解码器的最大实例数。实际创建数还受系统内存、处理器和带宽等资源的约束。 |

优先创建硬件解码器实例，资源不足时创建软件解码器实例。示例如下。

```c++
constexpr int32_t NEEDED_VDEC_NUM = 8;
// 1. 创建硬件解码器实例。
OH_AVCapability *capHW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, HARDWARE);
if (capHW == nullptr) {
   // 异常处理。
}
int32_t vDecNumHW = std::min(OH_AVCapability_GetMaxSupportedInstances(capHW), NEEDED_VDEC_NUM);
int32_t createdVDecNum = 0;
for (int i = 0; i < vDecNumHW; i++) {
   OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capHW));
   if (videoDec != nullptr) {
      // 维护在videoDecVector中。
      createdVDecNum++;
   }
}
if (createdVDecNum < NEEDED_VDEC_NUM) {
   // 2. 不够时，创建软件解码器实例。
   OH_AVCapability *capSW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
   if (capSW == nullptr) {
      // 异常处理。
   }
   int32_t vDecNumSW = std::min(OH_AVCapability_GetMaxSupportedInstances(capSW), NEEDED_VDEC_NUM - createdVDecNum);
   for (int i = 0; i < vDecNumSW; i++) {
      OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capSW));
      if (videoDec != nullptr) {
         // 维护在videoDecVector中。
         createdVDecNum++;
      }
   }
}
```

### 控制编码质量

提供以下码控模式供开发者选择：恒定码率（CBR）、动态码率（VBR）、恒定质量（CQ）、质量稳定（SQR）和高质量恒定码率（CBRHQ）。
- CBR、VBR和CBRHQ码控模式下，编码质量取决于码率参数。CBRHQ码控模式从API版本26.0.0开始使用，仅支持H.265（HEVC）编码。如果配置了CBRHQ但是平台不支持，会自动使用CBR码控模式替代。
- CQ码控模式下，编码质量取决于质量参数。
- SQR码控模式下，编码质量由质量稳定码率因子和最大码率决定，且仅支持H.265（HEVC）编码。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_IsEncoderBitrateModeSupported  | 确认当前编码器是否支持给定的码控模式。 |
| OH_AVCapability_GetEncoderBitrateRange     | 获取当前编码器支持的码率范围，适用于CBR、VBR、SQR和CBRHQ码控模式。 |
| OH_AVCapability_GetEncoderQualityRange  | 获取当前编码器支持的质量范围，适用于CQ码控模式。  |

CBR和VBR码控模式示例如下。

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CBR;
int32_t bitrate = 3000000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认待配置码控模式是否支持。
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理。
}
// 2. 获取码率范围，判断待配置码率参数是否在范围内。
OH_AVRange bitrateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理。
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal) {
   // 3.（可选）调整待配置码率参数。
}
// 4. 配置编码参数。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // 异常处理。
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) ||
   !OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate))) {
   // 异常处理。
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);
```

CQ码控模式示例如下。

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CQ;
int32_t quality = 0;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认待配置码控模式是否支持。
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理。
}
// 2. 获取质量范围，判断待配置质量参数是否在范围内。
OH_AVRange qualityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
if (ret != AV_ERR_OK || qualityRange.maxVal < 0) {
   // 异常处理。
}
if (quality > qualityRange.maxVal || quality < qualityRange.minVal) {
   // 3.（可选）调整待配置质量参数。
}
// 4. 配置编码参数。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // 异常处理。
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_QUALITY, quality)) {
   // 异常处理。
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);
```

SQR码控模式示例如下。

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_SQR;
int32_t sqrFactor = 30; // 质量稳定码率因子。
int32_t maxBitrate = 20000000; // 最大码率。
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认待配置码控模式是否支持。
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理。
}
// 2. 获取码率范围，判断待配置最大码率参数是否在范围内。
OH_AVRange bitrateRange = {-1, -1};
// 最大码率参数的取值范围同码率参数，故复用OH_AVCapability_GetEncoderBitrateRange获取取值范围。
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理。
}

// 质量稳定码率因子取值范围为[0, 51]（同编码量化参数QP）。
if (sqrFactor > 51 || sqrFactor < 0) {
   // 3.（可选）调整待配置质量稳定码率因子参数。
}

if (maxBitrate > bitrateRange.maxVal || maxBitrate < bitrateRange.minVal) {
   // 4.（可选）调整待配置最大码率参数。
}

// 5. 配置编码参数。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_HEVC);
if (videoEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, 1920, 1080);
if (format == nullptr) {
   // 异常处理。
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_SQR_FACTOR, sqrFactor) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_MAX_BITRATE, maxBitrate)) {
   // 异常处理。
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);

// 6. 启动编码器，开始编码。
ret = OH_VideoEncoder_Prepare(videoEnc);
if (ret != AV_ERR_OK) {
   // 异常处理。
}
ret = OH_VideoEncoder_Start(videoEnc);
if (ret != AV_ERR_OK) {
   // 异常处理。
}

// 7.（可选）OH_VideoEncoder_SetParameter()在运行过程中动态配置质量稳定码率因子参数和最大码率参数。
OH_AVFormat *dynamicFormat = OH_AVFormat_Create();
// SQR码控支持动态配置最大码率参数和质量稳定码率因子参数。
sqrFactor = 25; // 更新质量稳定码率因子。
maxBitrate = 10000000; // 更新最大码率参数。
OH_AVFormat_SetLongValue(dynamicFormat, OH_MD_KEY_MAX_BITRATE, maxBitrate);
OH_AVFormat_SetIntValue(dynamicFormat, OH_MD_KEY_SQR_FACTOR, sqrFactor);
ret = OH_VideoEncoder_SetParameter(videoEnc, dynamicFormat);
if (ret != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(dynamicFormat);
```
CBRHQ码控模式示例如下：
```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CBR_HIGH_QUALITY;
int32_t bitrate = 3000000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认待配置码控模式是否支持。
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理。
}
// 2. 获取码率范围，判断待配置最大码率参数是否在范围内。
OH_AVRange bitrateRange = {-1, -1};
// 最大码率参数的取值范围同码率参数，故复用OH_AVCapability_GetEncoderBitrateRange获取取值范围。
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理。
}

if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal) {
   // 3.（可选）调整待配置最大码率参数。
}

// 4. 配置编码参数。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_HEVC);
if (videoEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, 1920, 1080);
if (format == nullptr) {
   // 异常处理。
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) ||
   !OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate))) {
   // 异常处理。
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);
```


### 查询编码器支持复杂度范围

复杂度等级决定了编码器使用的工具数量，但并非所有编码器都支持这一功能。若变量complexityRange返回值为{0, 0}，则表示当前编码器不支持复杂度等级配置。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetEncoderComplexityRange | 获取当前编码器支持的复杂度等级范围。 | 

```c++
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 确认支持的编码复杂度范围。
OH_AVRange complexityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
```

### 设置正确的音频编解码参数

在音频编解码场景中，需要设置采样率和通道数。对于音频编码，还需要设置码率。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetAudioSupportedSampleRateRanges     | 获取当前音频编解码器支持的采样率范围。 |
| OH_AVCapability_GetAudioChannelCountRange  | 获取当前音频编解码器支持的通道数范围。 |
| OH_AVCapability_GetEncoderBitrateRange     | 获取当前编码器支持的码率范围。 |

音频编解码参数查询示例如下。

```c++
int32_t sampleRate = 44100;
int32_t channelCount = 2;
int32_t bitrate = 261000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认待配置采样率是否支持。
OH_AVRange *sampleRateRanges = nullptr;
uint32_t rangesNum = 0;
int32_t ret = OH_AVCapability_GetAudioSupportedSampleRateRanges(capability, &sampleRateRanges, &rangesNum);
if (ret != AV_ERR_OK || sampleRateRanges == nullptr || rangesNum == 0) {
   // 异常处理。
}
bool isMatched = false;
for (uint32_t i = 0; i < rangesNum; i++) {
   if (sampleRate >= sampleRateRanges[i].minVal && sampleRate <= sampleRateRanges[i].maxVal) {
      isMatched = true;
      break;
   }
}
if (!isMatched) {
   // 2.（可选）调整待配置采样率。
}
// 3. 获取通道数范围，判断待配置通道数参数是否在范围内。
OH_AVRange channelRange = {-1, -1};
ret = OH_AVCapability_GetAudioChannelCountRange(capability, &channelRange);
if (ret != AV_ERR_OK || channelRange.maxVal <= 0) {
   // 异常处理。
}
if (channelCount > channelRange.maxVal || channelCount < channelRange.minVal ) {
   // 4.（可选）调整待配置通道数。
}
// 5. 获取码率范围，判断待配置码率参数是否在范围内。
OH_AVRange bitrateRange = {-1, -1};
ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理。
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal ) {
   // 6.（可选）调整待配置码率值。
}
// 7. 配置编码参数。
OH_AVCodec *audioEnc = OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (audioEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_Create();
if (format == nullptr) {
   // 异常处理。
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, sampleRate) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, channelCount) ||
   !OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate))) {
   // 异常处理。
}
if (OH_AudioCodec_Configure(audioEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);
```

### 查询编解码档次和级别支持情况

编解码标准包含多种编码工具，适用于不同的编码场景。对于特定应用场景，编解码标准按档次确定所需编码工具的开启与关闭情况（例如，H.264有基本档次、高档次和主档次）。详情参见 [OH_AVCProfile](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_avcprofile)。

级别划分了编解码器所需的处理能力和存储空间。H.264有1到6.2的20个级别，参考[OH_AVCLevel](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_avclevel)。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetSupportedProfiles                    | 获取当前编解码器支持的档次。 |
| OH_AVCapability_GetSupportedLevelsForProfile            | 获取当前编解码器在给定档次的情况下支持的级别信息。 |
| OH_AVCapability_AreProfileAndLevelSupported             | 确认当前编解码器是否支持特定的档次和级别组合。 |

确认待配置的档次是否支持，并查询该档次下支持的级别，示例如下。

```c++
OH_AVCProfile profile = AVC_PROFILE_MAIN;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认待配置档次是否支持。
const int32_t *profiles = nullptr;
uint32_t profileNum = 0;
int32_t ret = OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
if (ret != AV_ERR_OK || profiles == nullptr || profileNum == 0) {
   // 异常处理。
}
bool isMatched = false;
for (int i = 0; i < profileNum; i++) {
   if (profiles[i] == profile) {
      isMatched = true;
      break;
   }
}
// 2. 查询待配置档次能支持的级别范围。
const int32_t *levels = nullptr;
uint32_t levelNum = 0;
ret = OH_AVCapability_GetSupportedLevelsForProfile(capability, profile, &levels, &levelNum);
if (ret != AV_ERR_OK || levels == nullptr || levelNum == 0) {
   // 异常处理。
}
OH_AVCLevel maxLevel = static_cast<OH_AVCLevel>(levels[0]);
for (int32_t i = 1; i < levelNum; i++) {
   OH_AVCLevel tmp = static_cast<OH_AVCLevel>(levels[i]);
   if (tmp > maxLevel) {
      maxLevel = tmp;
   }
}
// 3.（可选）基于支持的最大级别做业务逻辑区分。
if (maxLevel >= AVC_LEVEL_51) {
   // level5.1以上，宽、高可配置3840x2160。
} else if (maxLevel >= AVC_LEVEL_4) {
   // level4.0以上，宽、高可配1920x1080。
} else if (maxLevel >= AVC_LEVEL_31) {
   // level3.1以上，宽、高可配1280x720。
} else {
   // 报错，不做编码。
}
// 4. 配置档次参数。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // 异常处理。
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, profile)) {
   // 异常处理。
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);
```

已知需要的编码档次和级别组合，直接查询支持情况示例如下。

```c++
// 1. 获取H.264编码器能力实例。
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 2. 查询编码档次和级别是否支持。
bool isSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_MAIN, AVC_LEVEL_51);
```

### 设置正确的视频宽高

视频编解码器对宽度和高度有对齐约束。例如，主流编解码器默认编解码像素格式为YUV420系列，UV分量在宽度和高度两个方向都会下采样为原始尺寸的一半，因此视频编解码的宽度和高度至少要按2对齐。其他因素也可能导致更严格的对齐约束。

视频编解码的宽高不仅会受帧级编解码能力限制，同时也会受协议级别对帧级能力的限制。以H.264为例，AVC_LEVEL_51限定最大每帧宏块数目为36864个。

根据视频高度计算最大视频宽度的公式如下。

![](figures/formula-maxmbsperframe.png)

*MaxMBsPerFrameLevelLimits*表示协议限定的编解码器最大每帧宏块数，*MaxMBsPerFrameSubmit*表示编解码器上报的最大每帧宏块数，实际生效的每帧最大宏块数（*MaxMBsPerFrame*）取这两者的最小值。在此基础上，结合给定的视频高度（*height*）以及单个宏块的宽和高（*MBWidth*和*MBHeight*，通常为16），即可推算得出该高度下所支持的最大视频宽度（*maxWidth*）。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoWidthAlignment     | 获取当前视频编解码器的宽对齐。 |
| OH_AVCapability_GetVideoHeightAlignment    | 获取当前视频编解码器的高对齐。 |
| OH_AVCapability_GetVideoWidthRange             | 获取当前视频编解码器支持的宽的范围。 |
| OH_AVCapability_GetVideoHeightRange            | 获取当前视频编解码器支持的高的范围。 |
| OH_AVCapability_GetVideoWidthRangeForHeight    | 获取当前视频编解码器在给定高情况下的宽的范围。 |
| OH_AVCapability_GetVideoHeightRangeForWidth    | 获取当前视频编解码器在给定宽情况下的高的范围。 |
| OH_AVCapability_IsVideoSizeSupported           | 校验当前视频编解码器是否支持给定的宽高组合。 |

校验视频高度和宽度是否支持，示例如下。

```c++
int32_t width = 1920;
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认视频宽高是否支持。
bool isSupported = OH_AVCapability_IsVideoSizeSupported(capability, width, height);
if (!isSupported) {
   // 2. (可选) 按已知视频高或已知视频宽查询详细限制，并调整。
}
```

如果视频高度和视频宽度校验不支持或配置失败，可尝试以下方法确定正确的视频宽高范围。

已知视频宽度，可以按照以下示例找到正确的尺寸配置。

```c++
int32_t width = 1920;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认视频宽符合宽对齐要求。
int32_t widthAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoWidthAlignment(capability, &widthAlignment);
if (ret != AV_ERR_OK || widthAlignment <= 0) {
   // 异常处理。
} else if (width % widthAlignment != 0) {
   // 2. (可选) 对齐视频宽。
   width = (width + widthAlignment - 1) / widthAlignment * widthAlignment;
}
// 3. 确认视频宽处在可支持宽范围内。
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRange(capability, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // 异常处理。
} else if (width < widthRange.minVal || width > widthRange.maxVal) {
   // 4. (可选) 调整视频宽。
   width = std::min(std::max(width, widthRange.minVal), widthRange.maxVal);
}
// 5. 基于视频宽，获取可选视频高的范围。
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRangeForWidth(capability, width, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // 异常处理。
}
// 6. 从可选高度范围中挑选合适的高度配置。
```

已知视频高度，可以按照以下示例找到正确的尺寸配置。

```c++
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认视频高符合高对齐要求。
int32_t heightAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoHeightAlignment(capability, &heightAlignment);
if (ret != AV_ERR_OK || heightAlignment <= 0) {
   // 异常处理。
} else if (height % heightAlignment != 0) {
   // 2. (可选) 对齐视频高。
   height = (height + heightAlignment - 1) / heightAlignment * heightAlignment;
}
// 3. 确认视频高处在可支持高范围内。
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRange(capability, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // 异常处理。
} else if (height < heightRange.minVal || height > heightRange.maxVal) {
   // 4. (可选) 调整视频高。
   height = std::min(std::max(height, heightRange.minVal), heightRange.maxVal);
}
// 5. 基于视频高，获取可选视频宽的范围。
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRangeForHeight(capability, height, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // 异常处理。
}
// 6. 从可选宽度范围中挑选合适的宽度配置。
```

### 设置正确的视频帧率

视频编解码的帧率受编解码器的每秒编解码能力和协议级别的每秒处理能力限制。例如，H.264的AVC_LEVEL_51限定最大每秒宏块数目为983040个。

根据视频的宽度和高度，计算最大帧率的公式如下。

![](figures/formula-maxmbspersecond.png)

*MaxMBsPerSecondLevelLimits*表示协议限定的编解码器最大每秒宏块数，*MaxMBsPerSecondSubmit*表示编解码器上报的最大每秒宏块数，实际能力取这两者的最小值。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoFrameRateRange             | 获取当前视频编解码器支持的帧率的范围。 |
| OH_AVCapability_GetVideoFrameRateRangeForSize      | 获取当前视频编解码器在给定图像尺寸情况下的帧率的范围。 |
| OH_AVCapability_AreVideoSizeAndFrameRateSupported  | 校验视频编解码器是否支持视频大小和帧率的特定组合。 |

有帧率目标需求时，校验帧率是否在可选范围内。示例如下。

```c++
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 获取支持的帧率范围。
OH_AVRange frameRateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
   // 异常处理。
}
// 2. 判断是否在可选帧率范围内。
bool isSupported = frameRate >= frameRateRange.minVal && frameRate <= frameRateRange.maxVal;
```

根据待配置的尺寸选择合适的帧率配置，示例代码如下。

```c++
constexpr int32_t width = 1920;
constexpr int32_t height = 1080;
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 确认待配置尺寸是否能达到理想帧率。
bool isSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, width, height, frameRate);
if (!isSupported) {
   // 2. 基于待配置视频尺寸，查询支持的帧率范围，并基于查询到的帧率调整待配置帧率。
   OH_AVRange frameRateRange = {-1, -1};
   int32_t ret = OH_AVCapability_GetVideoFrameRateRangeForSize(capability, width, height, &frameRateRange);
   if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
      // 异常处理。
   }
   frameRate = std::min(std::max(frameRate, frameRateRange.minVal), frameRateRange.maxVal);
}

// 3. 配置尺寸和帧率参数。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // 异常处理。
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, width, height);
if (format == nullptr) {
   // 异常处理。
}
if (!OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, static_cast<double>(frameRate))) {
   // 异常处理。
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
OH_AVFormat_Destroy(format);
```

### 设置正确的视频像素格式信息

视频像素格式指示的编码输入图像或解码输出图像的像素排布方式，参考[OH_AVPixelFormat](../../reference/apis-avcodec-kit/capi-native-avformat-h.md#oh_avpixelformat)。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoSupportedPixelFormats             | 获取当前视频编解码器支持的像素格式。 |
| OH_AVCapability_GetVideoSupportedNativeBufferFormats      | 获取视频编解码器支持的OH_NativeBuffer格式。 |

```c++
constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 获取当前视频编解码器支持的像素格式。
const int32_t *pixFormats = nullptr;
uint32_t pixFormatNum = 0;
int32_t ret = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
// 获取当前视频编解码器支持的OH_NativeBuffer格式，使用方式同OH_AVCapability_GetVideoSupportedPixelFormats接口。
// const OH_NativeBuffer_Format *nativeBufferFormats = nullptr;
// int32_t ret = OH_AVCapability_GetVideoSupportedNativeBufferFormats(capability, &nativeBufferFormats, &pixFormatNum);
if (ret != AV_ERR_OK || pixFormats == nullptr || pixFormatNum == 0) {
   // 异常处理。
}
// 2. 校验是否支持对应像素格式。
bool isMatched = false;
for (int i = 0; i < pixFormatNum; i++) {
   if (pixFormats[i] == DEFAULT_PIXELFORMAT) {
      isMatched = true;
      break;
   }
}
if (!isMatched) {
   // 3. 替换其他像素格式输入或选择其他编解码器。
}
```

### 查询编解码特性支持情况并获取特性属性信息

编解码特性是指在特定编解码场景中使用的可选特性，例如视频编码场景的时域可分级编码、 低时延编解码等。具体请参考[OH_AVCapabilityFeature](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcapabilityfeature)。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_IsFeatureSupported              | 确认当前编解码器是否支持给定的特性。 |
| OH_AVCapability_GetFeatureProperties            | 获取当前编解码器支持的指定特性的属性。|

查询H.264编码器是否支持长期参考帧特性，示例如下。

```c++
constexpr int32_t NEEDED_LTR_NUM = 2;
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理。
}
// 1. 查询是否支持长期参考帧特性。
bool isSupported = OH_AVCapability_IsFeatureSupported(capability,VIDEO_ENCODER_LONG_TERM_REFERENCE);
if (isSupported) {
   // 2. 查询支持的长期参考帧个数。
   OH_AVFormat *properties = OH_AVCapability_GetFeatureProperties(capability, VIDEO_ENCODER_LONG_TERM_REFERENCE);
   if (properties == nullptr) {
      // 异常处理。
   }
   int32_t maxLTRCount = -1;
   bool ret = OH_AVFormat_GetIntValue(properties, OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT, &maxLTRCount);
   if (ret && maxLTRCount >= NEEDED_LTR_NUM) {
      if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT, NEEDED_LTR_NUM)) {
         // 异常处理。
      }
   }
}
// 3. 编码器创建和配置。
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理。
}
```

### 筛选特定MIME类型的安全解码器（DRM播放场景）

从API version 24开始，在处理受数字版权管理保护的DRM媒体资源时，可以使用支持安全链路的"安全解码器"。

开发者可以通过获取解码器列表，并结合MIME类型通过接口OH_AVCapability_IsSecure查询解码器类型，精准筛选出符合要求的安全解码器。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCodec_GetCapabilityList              | 获取指定类型（如视频解码器）的所有编解码能力实例列表。 |
| OH_AVCapability_GetMimeType               | 获取该能力实例对应的MIME类型字符串。 |
| OH_AVCapability_CheckMimeType             | 校验该能力实例的MIME类型是否与目标类型一致。 |
| OH_AVCapability_IsSecure                  | 检查该能力实例是否描述了一个支持处理DRM资源的安全解码器。 |

开发者可通过以下代码实现H.264安全解码器的查询与初始化：

```c++
// 1. 定义期望的MIME类型。
const char *targetMime = OH_AVCODEC_MIMETYPE_VIDEO_AVC;
uint32_t count = 0;

// 2. 获取所有视频解码器的能力列表。
OH_AVCapability **capabilityList = OH_AVCodec_GetCapabilityList(OH_AVCODEC_TYPE_VIDEO_DECODER, &count);

if (capabilityList != nullptr && count > 0) {
    for (uint32_t i = 0; i < count; i++) {
        OH_AVCapability *cap = capabilityList[i];
        
        // 3. 检查是否为目标的MIME类型，且必须是安全解码器。
        if (OH_AVCapability_CheckMimeType(cap, targetMime) && OH_AVCapability_IsSecure(cap)) {
            // 4. 找到符合条件的解码器，获取其名称用于创建实例。
            const char *codecName = OH_AVCapability_GetName(cap);
            OH_AVCodec *secureVideoDec = OH_VideoDecoder_CreateByName(codecName);
            
            if (secureVideoDec != nullptr) {
                // 5. 成功创建安全解码器，跳出循环执行后续业务。
                break;
            }
        }
    }
}
```