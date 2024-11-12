# 获取支持的编解码能力

因来源不同、编解码器协议不同以及设备在编解码能力部署上的不同，在不同设备上开发者可用的编解码器及其能力是有差异的。

为确保编解码行为符合预期，开发者应提前通过音视频编解码能力系列接口查询系统支持的音视频编解码器及其关联的能力参数，找到符合开发场景需求的编解码器，并正确配置编解码参数。

## 通用开发指导
1. 在CMake脚本中链接动态库。

   ``` cmake
   target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
   target_link_libraries(sample PUBLIC libnative_media_core.so)
   target_link_libraries(sample PUBLIC libnative_media_venc.so)
   target_link_libraries(sample PUBLIC libnative_media_vdec.so)
   ```
   > **说明：**
   >
   > 上述'sample'字样仅为示例，此处由开发者根据实际工程目录自定义。
   >

2. 添加头文件。

   ```c++
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avcodec_videoencoder.h>
   #include <multimedia/player_framework/native_avcodec_videodecoder.h>
   ```

3. 获得音视频编解码能力实例。

   支持两种获取音视频编解码能力实例的方式：
   
   方式一：通过`OH_AVCodec_GetCapability`获取框架推荐的音视频编解码器能力实例。与`OH_XXX_CreateByMime`系列接口框架推荐策略一致。
   ```c++
   // 获取系统推荐的音频AAC解码器能力实例
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, false);
   ```
   
   方式二：通过`OH_AVCodec_GetCapabilityByCategory`获取指定软件或硬件的编解码能力实例。
   ```c++
   // 获取指定硬件的视频AVC编码器能力实例
   OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true, HARDWARE);
   ```
   若获取能力实例成功，则可继续向下执行。开发者无需关注该实例的回收问题，框架会自行回收。

4. 按需调用相应查询接口，详细的API说明请参考[API文档](../../reference/apis-avcodec-kit/_a_v_capability.md)。

## 场景化开发指导
基于开发者可能遇到特定场景，举例说明能力查询接口使用方法。

### 创建指定名称的编解码器

如系统内存在相同MIME类型的多个编码器或多个解码器。使用`OH_XXX_CreateByMime`系列接口只能创建系统推荐的特定编解码器。若需创建其他编解码器，开发者可先获取编解码器名称，再通过`OH_XXX_CreateByName`系列接口创建指定名称的编解码器。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_GetName     | 获取能力实例对应编解码器的名称 |

H.264软件解码器和H.264硬件解码器共存时，创建H.264软件解码器示例：
```c++
// 1. 获取H.264软件解码器能力实例
OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
if (capability != nullptr) {
   // 2. 获取H.264软件解码器名称
   const char *codecName = OH_AVCapability_GetName(capability);
   // 3. 创建H.264软件解码器实例
   OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(codecName);
}
```

### 针对软硬件类别差异化配置编解码器参数

软件编解码器和硬件编解码器定义如下：

* **软件编解码器:** 指在CPU上进行编解码工作的编解码器，能力可灵活迭代，相比硬件编解码器具有更好的兼容性，更好的协议和规格扩展能力。

* **硬件编解码器:** 指在专有硬件上进行编解码工作的编解码器，其特点是已在硬件平台硬化，能力随硬件平台迭代。相比软件编解码器具有更好的功耗、耗时和吞吐表现，同时能降低CPU负载。

基于上述软件编解码器和硬件编解码器的特点，在硬件编解码器满足要求的时候，优先使用硬件编解码器，否则使用软件编解码器。开发者可基于软件还是硬件类别差异化配置编解码参数。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_IsHardware  | 确认能力实例对应的编解码器是否是硬件的 |

视频编码，软硬件差异化配置帧率示例：

```c++
// 1. 确认推荐的H.264编码器的软硬件类别
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
bool isHardward = OH_AVCapability_IsHardware(capability);
// 2. 基于软硬件类别差异化配置
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
double frameRate = isHardward ? 60.0 : 30.0;
if (!OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, frameRate)) {
   // 异常处理
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理
}
OH_AVFormat_Destroy(format);
```

### 创建多路编解码器

部分业务场景涉及创建多路编解码器，基于各类资源的限制，某一编解码器的实例数是有限的，不能无限制创建。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_GetMaxSupportedInstances  | 获取能力实例对应编解码器可同时运行的最大实例数，实际能成功创建的数目还受系统其他资源的约束 |

优先创建硬件解码器实例，不够时再创建软件解码器实例，示例如下：

```c++
constexpr int32_t NEEDED_VDEC_NUM = 8;
// 1. 创建硬件解码器实例
OH_AVCapability *capHW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, HARDWARE);
int32_t vDecNumHW = min(OH_AVCapability_GetMaxSupportedInstances(capHW), NEEDED_VDEC_NUM);
int32_t createdVDecNum = 0;
for (int i = 0; i < vDecNumHW; i++) {
   OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capHW));
   if (videoDec != nullptr) {
      // 维护在videoDecVector中
      createdVDecNum++;
   }
}
if (createdVDecNum < NEEDED_VDEC_NUM) {
   // 2. 不够时，创建软件解码器实例
   OH_AVCapability *capSW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
   int32_t vDecNumSW = min(OH_AVCapability_GetMaxSupportedInstances(capSW), NEEDED_VDEC_NUM - createdVDecNum);
   for (int i = 0; i < vDecNumSW; i++) {
      OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capSW));
      if (videoDec != nullptr) {
         // 维护在videoDecVector中
         createdVDecNum++;
      }
   }
}
```

### 控制编码质量

当前提供三种码控模式供开发者选用，分别是恒定码率（CBR）码控模式、动态码率（VBR）码控模式，以及恒定质量（CQ）码控模式。对于CBR和VBR码控模式，编码质量由码率参数决定。对于CQ码控模式，编码质量由质量参数决定。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_IsEncoderBitrateModeSupported  | 确认当前编解码器是否支持给定的码控模式 |
| OH_AVCapability_GetEncoderBitrateRange     | 获取当前编解码器支持的码率范围，在CBR和VBR码控模式下使用|
| OH_AVCapability_GetEncoderQualityRange  | 获取当前编解码器支持的质量范围，在CQ码控模式下使用  |

CBR和VBR码控模式示例如下：

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CBR;
int32_t bitrate = 3000000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 1. 确认待配置码控模式是否支持
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理
}
// 2. 获取码率范围，判断待配置码率参数是否在范围内
OH_AVRange bitrateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal) {
   // 3.（可选）调整待配置码率参数
}
// 4. 配置编码参数
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) &&
   OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate)) == false) {
   // 异常处理
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理
}
OH_AVFormat_Destroy(format);
```

CQ码控模式示例如下：

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CQ;
int32_t quality = 0;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 1. 确认待配置码控模式是否支持
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理
}
// 2. 获取质量范围，判断待配置质量参数是否在范围内
OH_AVRange qualityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
if (ret != AV_ERR_OK || qualityRange.maxVal < 0) {
   // 异常处理
}
if (quality > qualityRange.maxVal || quality < qualityRange.minVal) {
   // 3.（可选）调整待配置质量参数
}
// 5. 配置编码参数
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) &&
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_QUALITY, quality) == false) {
   // 异常处理
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理
}
OH_AVFormat_Destroy(format);
```

### 查询编解码器支持复杂度范围

复杂度等级决定了编解码器使用的工具的数目，仅部分编解码器支持。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetEncoderComplexityRange | 获取当前编解码器支持的复杂度范围 | 

```c++
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // 异常处理
}
// 确认支持的编码复杂度范围
OH_AVRange complexityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
```

### 设置正确的音频编解码参数

在音频编解码场景中，有采样率、通道数以及码率（仅音频编码）等参数需要查询后设置。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetAudioSupportedSampleRates     | 获取当前音频编解码器支持的采样率范围 |
| OH_AVCapability_GetAudioChannelCountRange  | 获取当前音频编解码器支持的通道数范围 |
| OH_AVCapability_GetEncoderBitrateRange     | 获取当前编码器支持的码率范围 |

音频编码场景，确认并设置正确的编码的参数，示例如下：

```c++
int32_t sampleRate = 44100;
int32_t channelCount = 2;
int32_t bitrate = 261000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // 异常处理
}
// 1. 确认待配置采样率是否支持
const int32_t *sampleRates = nullptr;
uint32_t sampleRateNum = -1;
int32_t ret = OH_AVCapability_GetAudioSupportedSampleRates(capability, &sampleRates, &sampleRateNum);
if (ret != AV_ERR_OK || sampleRates == nullptr || sampleRateNum <= 0) {
   // 异常处理
}
bool isMatched = false;
for (int i = 0; i < sampleRateNum; i++) {
   if (sampleRates[i] == sampleRate) {
      isMatched = true;
   }
}
if (!isMatched) {
   // 2.（可选）调整待配置采样率
}
// 3. 获取通道数范围，判断待配置通道数参数是否在范围内
OH_AVRange channelRange = {-1, -1};
ret = OH_AVCapability_GetAudioChannelCountRange(capability, &channelRange);
if (ret != AV_ERR_OK || channelRange.maxVal <= 0) {
   // 异常处理
}
if (channelCount > channelRange.maxVal || channelCount < channelRange.minVal ) {
   // 4.（可选）调整待配置通道数
}
// 5. 获取码率范围，判断待配置码率参数是否在范围内
OH_AVRange bitrateRange = {-1, -1};
ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal ) {
   // 7.（可选）调整待配置码率值
}
// 8. 配置编码参数
OH_AVCodec *audioEnc = OH_AudioEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC);
OH_AVFormat *format = OH_AVFormat_Create();
if (OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, sampleRate) &&
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, channelCount) &&
   OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate)) == false) {
   // 异常处理
}
if (OH_AudioEncoder_Configure(audioEnc, format) != AV_ERR_OK) {
   // 异常处理
}
OH_AVFormat_Destroy(format);
```

### 查询编解码档次和级别支持情况

编解码标准由很多编码工具构成，能应对多种编码场景。对于特定应用场景，并非需要所有的工具，编解码标准按档次确定多种编码工具的开启与关闭情况。以H.264为例，存在基本档次、主档次和高档次，参考[OH_AVCProfile](../../reference/apis-avcodec-kit/_codec_base.md#oh_avcprofile-1)。

级别是对编解码器所需的处理能力和储存空间的划分。以H.264为例，存在1到6.2的20个级别，参考[OH_AVCLevel](../../reference/apis-avcodec-kit/_codec_base.md#oh_avclevel-1)。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetSupportedProfiles                    | 获取当前编解码器支持的档次 |
| OH_AVCapability_GetSupportedLevelsForProfile            | 获取当前编解码器在给定档次的情况下支持的等级信息 |
| OH_AVCapability_AreProfileAndLevelSupported             | 确认当前编解码器是否支持特定的档次和等级组合 |

确认待配置档次是否支持，并查询能支持的级别，示例如下：

```c++
OH_AVCProfile profile = AVC_PROFILE_MAIN;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 1. 确认待配置档次是否支持
const int32_t *profiles = nullptr;
uint32_t profileNum = -1;
int32_t ret = OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
if (ret != AV_ERR_OK || profiles == nullptr || profileNum <= 0) {
   // 异常处理
}
bool isMatched = false;
for (int i = 0; i < profileNum; i++) {
   if (profiles[i] == profile) {
      isMatched = true;
   }
}
// 2. 查询待配置档次能支持的级别范围
const int32_t *levels = nullptr;
uint32_t levelNum = -1;
ret = OH_AVCapability_GetSupportedLevelsForProfile(capability, profile, &levels, &levelNum);
if (ret != AV_ERR_OK || levels == nullptr || levelNum <= 0) {
   // 异常处理
}
OH_AVCLevel maxLevel = static_cast<OH_AVCLevel>(levels[levelNum -1]);
// 3.（可选）基于支持的最大级别做业务逻辑区分
switch (maxLevel) {
   case AVC_LEVEL_31:
      // level 3.1-3.2，宽、高最大可配1280x720
      break;
   case AVC_LEVEL_51:
      // level 4.0-后续，宽、高最大可配1920x1080
      break;
   default:
      // 报错，不做编码
}
// 4. 配置档次参数
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, profile)) {
   // 异常处理
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理
}
OH_AVFormat_Destroy(format);
```

已知需要的编码档次和级别组合，直接查询支持情况示例如下：

```c++
// 1. 获取H.264编码器能力实例
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 2. 查询编码档次和级别是否支持
bool isSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_MAIN, AVC_LEVEL_51);
```

### 设置正确的视频宽高

视频编解码器对宽高存在对齐约束，如主流编解码器默认编解码像素格式为YUV420系列中的，会对UV分量下采样，在此情况下视频编解码的宽高至少要按2对齐。此外还有其他因素可能导致更加严格的对齐约束。

视频编解码的宽高不仅会受帧级编解码能力限制，同时也会受协议中级别对帧级能力的限制。以H.264为例，AVC_LEVEL_51限定最大每帧宏块数目为36864。

给定图像宽和高，求最大帧率的公式如下, 其中*MaxMBsPerFrameLevelLimits*是编解码器能支持的最大级别在协议中限定的最大每帧宏块数, *MaxMBsPerFrameSubmit*是编解码器上报能支持的最大每帧宏块数，实际能力取两者交集。

![](figures/formula-maxmbsperframe.png)

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoWidthAlignment     | 获取当前视频编解码器的宽对齐 |
| OH_AVCapability_GetVideoHeightAlignment    | 确认当前视频编解码器的高对齐 |
| OH_AVCapability_GetVideoWidthRange             | 获取当前视频编解码器支持的宽的范围 |
| OH_AVCapability_GetVideoHeightRange            | 获取当前视频编解码器支持的高的范围 |
| OH_AVCapability_GetVideoWidthRangeForHeight    | 获取当前视频编解码器在给定高情况下的宽的范围 |
| OH_AVCapability_GetVideoHeightRangeForWidth    | 获取当前视频编解码器在给定宽情况下的高的范围 |
| OH_AVCapability_IsVideoSizeSupported           | 确认当前视频编解码器是否支持给定的宽高组合 |

已知视频高和视频宽，校验是否支持，示例如下：

```c++
int32_t width = 1920;
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. 确认视频宽高是否支持
bool isSupported = OH_AVCapability_IsVideoSizeSupported(capability, width, height);
if (!isSupported) {
   // 2. (可选) 按已知视频高或已知视频宽查询详细限制，并调整
}
```

若遇到基于已知视频高和视频宽校验不支持或配置失败，可用下列示意的多种方式尝试找到正确的视频宽高范围。

已知视频宽，找到正确的尺寸配置，示例如下：

```c++
int32_t width = 1920;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. 确认视频宽符合宽对齐要求
int32_t widthAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoWidthAlignment(capability, &widthAlignment);
if (ret != AV_ERR_OK || widthAlignment <= 0) {
   // 异常处理
} else if (width % widthAlignment != 0) {
   // 2. (可选) 对齐视频宽
   width = (width + widthAlignment - 1) / widthAlignment * widthAlignment;
}
// 3. 确认视频宽处在可支持宽范围内
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRange(capability, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // 异常处理
} else if (width < widthRange.minVal || width > widthRange.maxVal) {
   // 4. (可选) 调整视频宽
   width = min(max(width, widthRange.minVal), widthRange.maxVal);
}
// 5. 基于视频宽，获取可选视频高的范围
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRangeForWidth(capability, width, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // 异常处理
}
// 6. 从可选高度范围中挑选合适的高度配置
```

已知视频高，找到正确的尺寸配置，示例如下：

```c++
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. 确认视频高符合高对齐要求
int32_t heightAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoHeightAlignment(capability, &heightAlignment);
if (ret != AV_ERR_OK || heightAlignment <= 0) {
   // 异常处理
} else if (height % heightAlignment != 0) {
   // 2. (可选) 对齐视频高
   height = (height + heightAlignment - 1) / heightAlignment * heightAlignment;
}
// 3. 确认视频高处在可支持高范围内
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRange(capability, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // 异常处理
} else if (height < heightRange.minVal || height > heightRange.maxVal) {
   // 4. (可选) 调整视频高
   height = min(max(height, heightRange.minVal), heightRange.maxVal);
}
// 5. 基于视频高，获取可选视频宽的范围
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRangeForHeight(capability, height, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // 异常处理
}
// 6. 从可选宽度范围中挑选合适的宽度配置
```

### 设置正确的视频帧率

视频编解码的帧率不仅会受编解码器秒级编解码能力限制，同时也会受协议中级别对秒级能力的限制。以H.264为例，AVC_LEVEL_51限定最大每秒宏块数目为983040。

给定图像宽和高，求最大帧率的公式如下, 其中*MaxMBsPerSecondLevelLimits*是编解码器能支持的最大级别在协议中限定的最大每秒宏块数, *MaxMBsPerSecondSubmit*是编解码器上报能支持的最大每秒宏块数，实际能力取两者交集。

![](figures/formula-maxmbspersecond.png)

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoFrameRateRange             | 获取当前视频编解码器支持的帧率的范围 |
| OH_AVCapability_GetVideoFrameRateRangeForSize      | 获取当前视频编解码器在给定图像尺寸情况下的帧率的范围 |
| OH_AVCapability_AreVideoSizeAndFrameRateSupported  | 检查视频编解码器是否支持视频大小和帧率的特定组合 |

有需求的帧率目标，确认帧率是否在可选范围内，示例如下：

```c++
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. 获取支持的帧率范围
OH_AVRange frameRateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
   // 异常处理
}
// 2. 判断是否在可选帧率范围内
bool isSupported = frameRate >= frameRateRange.minVal && frameRate <= frameRateRange.maxVal;
```

基于待配置的尺寸找到合适的帧率配置，示例代码如下：

```c++
constexpr int32_t width = 1920;
constexpr int32_t height = 1080;
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. 确认待配置尺寸是否能达到理想帧率
bool isSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, width, height, frameRate);
if (!isSupported) {
   // 2. 基于待配置视频尺寸，查询支持的帧率范围，并基于查询到的帧率调整待配置帧率
   OH_AVRange frameRateRange = {-1, -1};
   int32_t ret = OH_AVCapability_GetVideoFrameRateRangeForSize(capability, width, height, &frameRateRange);
   if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
      // 异常处理
   }
   frameRate = min(max(frameRate, frameRateRange.minVal), frameRateRange.maxVal);
}

// 3. 配置尺寸和帧率参数
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, width, height);
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_FRAME_RATE, frameRate)) {
   // 异常处理
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理
}
OH_AVFormat_Destroy(format);
```

### 设置正确的视频像素格式信息

视频像素格式指示的编码输入图像或解码输出图像的像素排布方式，参考[OH_AVPixelFormat](../../reference/apis-avcodec-kit/_core.md#oh_avpixelformat-1)。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoSupportedPixelFormats             | 获取当前视频编解码器支持的像素格式 |

```c++
constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 1. 获取当前视频编解码器支持的像素格式
const int32_t *pixFormats = nullptr;
uint32_t pixFormatNum = -1;
int32_t ret = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
if (ret != AV_ERR_OK || pixFormats == nullptr || pixFormatNum <= 0) {
   // 异常处理
}
// 2. 校验是否支持对应像素格式
bool isMatched = false;
for (int i = 0; i < pixFormatNum; i++) {
   if (pixFormats[i] == DEFAULT_PIXELFORMAT) {
      isMatched = true;
   }
}
if (!isMatched) {
   // 3. 替换其他像素格式输入或选择其他编解码器
}
```

### 查询编解码特性支持情况并获取特性属性信息

编解码特性是指仅在特定编解码场景中使用的可选特性，参考[OH_AVCapabilityFeature](../../reference/apis-avcodec-kit/_a_v_capability.md#oh_avcapabilityfeature-1)。
| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_IsFeatureSupported              | 确认当前编解码器是否支持给定的特性 |
| OH_AVCapability_GetFeatureProperties            | 获取当前编码器支持的指定特性的属性，仅部分特性存在属性信息 |

查询H.264编码器是否支持长期参考帧特性示例如下：

```c++
constexpr int32_t NEEDED_LTR_NUM = 2;
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 1. 查询是否支持长期参考帧特性
bool isSupported = OH_AVCapability_IsFeatureSupported(capability,VIDEO_ENCODER_LONG_TERM_REFERENCE);
if (isSupported) {
   // 2. 查询支持的长期参考帧个数
   OH_AVFormat *properties = OH_AVCapability_GetFeatureProperties(capability, VIDEO_ENCODER_LONG_TERM_REFERENCE);
   int32_t maxLTRCount = -1;
   bool ret = OH_AVFormat_GetIntValue(properties, OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT, &maxLTRCount);
   if (ret && maxLTRCount >= NEEDED_LTR_NUM) {
      if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT, NEEDED_LTR_NUM)) {
         // 异常处理
      }
   }
}
// 3. 编码器创建和配置
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // 异常处理
}
```