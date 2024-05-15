# 音视频编解码能力

因来源不同、编解码器协议不同以及设备在编解码能力部署上的不同，开发者可用的编解码器及其能力是变化的。

开发者为确保编解码行为符合预期，在使用AVCodec kit做音视频编解码前，应提前通过音视频编解码能力系列接口查询系统支持的音视频编解码器及其关联的能力参数，找到符合开发场景需求的编解码器，并正确配置编解码参数。


## 基础概念
### 音视频编解码器来源及其特点
目前系统支持的音视频编解码器主要有两种来源，一种是由AVCodec框架直接提供的软件编解码器，一种由设备厂商通过AVCodec框架间接提供的硬件编解码器。

软件编解码器和硬件编解码器定义如下：

* **软件编解码器:** 指在CPU上进行编解码工作的编解码器，能力可灵活迭代，相比硬件编解码器具有更好的兼容性，更好的协议和规格扩展能力。

* **硬件编解码器:** 指在专有硬件上进行编解码工作的编解码器，其特点是已在硬件平台硬化，能力随硬件平台迭代。相比软件编解码器具有更好的功耗、耗时和吞吐表现，同时能降低CPU负载。

基于上述软件编解码器和硬件编解码器的特点，在硬件编解码器满足要求的时候，优先使用硬件编解码器，否则使用软件编解码器。

### 视频编解码级别对尺寸和帧率的约束

以H.264为例，下表描述了H.264协议中不同等级的最大每秒宏块数目和最大每帧宏块数目限制。

| level | MBsPerSecond | MBsPerFrame |
| --  | -------- | ------ |
| 1   | 1485     | 99     |
| 1b  | 1485     | 99     |
| 1.1 | 3000     | 396    |
| 1.2 | 6000     | 396    |
| 1.3 | 11880    | 396    |
| 2   | 11880    | 396    |
| 2.1 | 19800    | 792    |
| 2.2 | 20250    | 1620   |
| 3   | 40500    | 1620   |
| 3.1 | 108000   | 3600   |
| 3.2 | 216000   | 5120   |
| 4   | 245760   | 8192   |
| 4.1 | 245760   | 8192   |
| 4.2 | 522240   | 8704   |
| 5   | 589824   | 22080  |
| 5.1 | 983040   | 36864  |
| 5.2 | 2073600  | 36864  |
| 6   | 4177920  | 139264 |
| 6.1 | 8355840  | 139264 |
| 6.2 | 16711680 | 139264 |

音视频编解码能力会基于编解码器上报支持的最大等级找到协议上限$MaxMBsPerFrameLevelLimits$和$maxMBsPerSecondLevelLimits$，并与直接上报的$MaxMBsPerFrameSubmit$和$MaxMBsPerSecondSubmit$取并交集。
$$
MaxMBsPerFrame = \min(MaxMBsPerFrameLevelLimits, MaxMBsPerFrameSubmit)\\
MaxMBsPerSecond = \min(MaxMBsPerSecondLevelLimits, MaxMBsPerSecondSubmit)
$$

给定图像高，求最大图像高的公式如下：
$$
maxWidth = \lfloor MaxMBsPerFrame \div \lceil \frac{height}{MBHeight} \rceil \rfloor \times MBWidth
$$

给定图像宽和高，求最大帧率的公式如下：
$$
maxFrameRate = MaxMBsPerSecond \div (\lceil{\frac{width}{MBWidth}} \rceil \times \lceil \frac{height}{MBHeight} \rceil)
$$

对于H.264来说，宏块宽高都是16:
$$
MBWidth = MBHeight = 16
$$


## 通用开发指导
1. 在CMake脚本中链接动态库。

   ``` cmake
   target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
   ```

2. 添加头文件。

   ```c++
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   ```

3. 获得音视频编解码能力句柄。

   支持两种获取音视频编解码能力句柄的方式：
   
   方式一：通过`OH_AVCodec_GetCapability`获取框架推荐的音视频编解码器能力句柄。与`OH_XXX_CreateByMime`系列接口框架推荐策略一致。
   ```c++
   // 获取系统推荐的音频AAC解码器能力句柄
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, false);
   ```
   
   方式二：通过`OH_AVCodec_GetCapabilityByCategory`获取指定软件或硬件的编解码能力句柄。
   ```c++
   // 获取指定硬件的视频AVC编码器能力句柄
   OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true, HARDWARE);
   ```
   若获取能力句柄成功，则可继续向下执行。开发者无需关注该句柄的回收问题，框架会自行回收。

4. 按需调用相应查询接口，详细的API说明请参考[API文档](../../reference/apis-avcodec-kit/_a_v_capability.md)。

## 场景化开发指导
基于开发者可能遇到特定场景，举例说明：

### 创建指定名称的编解码器

如系统内存在同MIME_TYPE且同编解码场景的多个编解码器，且使用`OH_XXX_CreateByMime`系列接口默认创建不到的其中某一编解码器。因编解码器名字具有唯一性，可用于区分上述多个编解码器。开发者可先获取编解码名字，再通过`OH_XXX_CreateByName`系列接口创建指定名字的编解码器。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_GetName     | 获取能力句柄对应编解码器的名称 |

H.264软件解码器和H.264硬件解码器共存时，创建H.264软件解码器示例：
```c++
// 1. 获取H.264软件解码器能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
if (capability != nullptr) {
   // 2. 获取H.264软件解码器名称
   const char *codecName = OH_AVCapability_GetName(capability);
   // 3. 创建H.264硬件解码器实例
   OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByName(codecName);
}
```

### 针对软硬件类别差异化配置编解码器

基于软件编解码器和硬件编解码器的差异，开发者可基于软件还是硬件类别调整编解码配置。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_IsHardware  | 确认能力句柄对应编解码器是否硬件的 |

视频编码，软硬件差异化配置帧率示例：
```c++
// 1. 创建H.264编码器实例
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
// 2. 获取H.264编码器能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// ... RegisterCallback
// 3. 软硬件类别差异化配置
OH_AVFormat *format = OH_AVFormat_Create();
// ...
if (OH_AVCapability_IsHardware(capability)) {
   OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 60.0);
} else {
   OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0);
}
(void)OH_VideoEncoder_Configure(videoEnc, format);
OH_AVFormat_Destroy(format);
```

### 创建多路编解码器

部分业务场景涉及创建多路编解码器，基于各类资源的限制，某一编解码器的实例数是有限的，不能无限制创建。

| 接口     | 功能描述                         |
| -------- | -------------------------------- |
| OH_AVCapability_GetMaxSupportedInstances  | 获取能力句柄对应编解码器可同时运行的最大实例数，实际能成功创建的数目还受系统其他资源的约束 |

优先创建硬件解码器实例不够时创建软件解码器实例示例：
```c++
constexpr int32_t NEEDED_VDEC_NUM = 24;
// 1. 创建硬件解码器实例
OH_AVCapability *capHW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, HARDWARE);
int32_t vDecNumHW = OH_AVCapability_GetMaxSupportedInstances(capHW);
vDecNumHW = min(vDecNumHW, NEEDED_VDEC_NUM);
int32_t createdVDecNum = 0;
for (int i = 0; i < vDecNumHW; i++) {
   OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capHW));
   if (videoDec != nullptr) {
      // 维护在videoDecVector中
      createdVDecNum++;
   }
}
if (createdVDecNum < NEEDED_VDEC_NUM) {
   // 2. 创建软件解码器实例
   OH_AVCapability *capSW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
   int32_t vDecNumSW = OH_AVCapability_GetMaxSupportedInstances(capSW);
   vDecNumSW = min(vDecNumSW, NEEDED_VDEC_NUM - createdVDecNum);
   for (int i = 0; i < vDecNumSW; i++) {
      OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capSW));
      if (videoDec != nullptr) {
         // 维护在videoDecVector中
         createdVDecNum++
      }
   }
}
```

### 控制编码质量参数

编码质量参数主要由码控模式参数，恒定质量码控模式下质量参数以及恒定码率与动态码率码控模式下的码率参数组成。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_IsEncoderBitrateModeSupported  | 确认当前编解码器是否支持给定的码控模式 |
| OH_AVCapability_GetEncoderBitrateRange     | 获取当前编解码器支持的码率范围，在CBR和VBR码控模式下使用|
| OH_AVCapability_GetEncoderQualityRange  | 获取当前编解码器支持的质量范围，在CQ码控模式下使用  |

CBR和VBR码控模式示例如下：

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CBR;
int32_t bitrate = 3000000
// int32_t quality = 0;
// 1. 获取H.264编码器能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}

// 2. 确认特定码控模式是否支持
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理
}
// 3. 码率是否支持
OH_AVRange bitrateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal) {
   // 4.（可选）调整码率值
}
// 5. 配置编码参数
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
(void)OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode);
(void)OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate));
(void)OH_VideoEncoder_Configure(videoEnc, format);
OH_AVFormat_Destroy(format);
```

CQ码控模式示例如下：

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CQ;
int32_t quality = 0;
// 1. 获取H.264编码器能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 2. 质量是否支持
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // 异常处理
}
// 3. 查询当前能力中，编码质量范围
OH_AVRange qualityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
if (ret != AV_ERR_OK || qualityRange.maxVal < 0) {
   // 异常处理
}
if (quality > qualityRange.maxVal || quality < qualityRange.minVal) {
   // 4.（可选）调整质量
}
// 5. 配置编码参数
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
(void)OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode);
(void)OH_AVFormat_SetIntValue(format, OH_MD_KEY_QUALITY, quality);
(void)OH_VideoEncoder_Configure(videoEnc, format);
OH_AVFormat_Destroy(format);
```

### 确定编解码器支持复杂度范围

复杂度等级决定了编解码器使用的工具的数目，仅部分编解码器支持。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetEncoderComplexityRange | 获取当前编解码器支持的复杂度范围 | 

```c++
// 1. 获取能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // 异常处理
}

// 2. 确认支持的编码复杂度范围
OH_AVRange complexityRange;
int32_t complexityRet = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
```

### 设置的正确的音频编解码参数

音频编解码场景主要有采样率和通道数两个关键参数需要查询，编码场景还多一个码率参数需要查询。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetAudioSupportedSampleRates     | 获取当前音频编解码器支持的采样率范围 |
| OH_AVCapability_GetAudioChannelCountRange  | 获取当前音频编解码器支持的通道数范围 |
| OH_AVCapability_GetEncoderBitrateRange     | 获取当前编解码器支持的码率范围 |

音频编码场景，确认并设置正确的编码的参数示例如下：

```c++
int32_t sampleRate = 44100;
int32_t channelCount = 2;
int32_t bitrate = 261000;
// 1. 获取aac音频编码能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // 异常处理
}
// 2. 确认采样率是否支持
const int32_t *sampleRates = nullptr;
uint32_t sampleRateNum = -1;
int32_t ret = OH_AVCapability_GetAudioSupportedSampleRates(capability, &sampleRates, &sampleRateNum);
if (ret != AV_ERR_OK || sampleRates == nullptr || sampleRateNum <= 0) {
   // 异常处理
}
bool isMatched = false;
for (int i = 0; i < sampleRateNum; i++) {
   // TODO: 离散是否支持
   if (sampleRates[i] == sampleRate) {
      isMatched = true;
   }
}
if (!isMatched) {
   // 3.（可选）调整采样率
}
// 4. 确认通道数是否支持
OH_AVRange channelRange = {-1，-1};
ret = OH_AVCapability_GetAudioChannelCountRange(capability, &channelRange);
if (ret != AV_ERR_OK || channelRange.maxVal <= 0) {
   // 异常处理
}
if (channelCount > channelRange.maxVal || channelCount < channelRange.minVal ) {
   // 5.（可选）调整通道值
}
// 6. 确认码率是否支持
OH_AVRange bitrateRange = {-1，-1};
ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // 异常处理
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal ) {
   // 7.（可选）调整码率值
}
// 8. 编码配置参数
OH_AVCodec *aEnc =  OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
OH_AVFormat *format = OH_AVFormat_Create();
OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, sampleRate);
OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, channelCount);
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate));
(void)OH_AudioCodec_Configure(aEnc, format);
OH_AVFormat_Destroy(format);
```

### 查询编解码档次和级别支持情况

编解码标准由很多编码工具构成，能应对多种编码场景。对于特定应用场景，并非需要所有的工具，编解码标准按档次确定多种编码工具的使能与关闭。以H.264为例，参考OH_AVCProfile。存在基本档次、主档次和高档次。

级别是对编解码器所需的处理能力和储存空间的划分。以H.264为例，参考OH_AVCLevel，存在1到6.2的20个级别。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetSupportedProfiles                    | 获取当前编解码器支持的档次 |
| OH_AVCapability_GetSupportedLevelsForProfile            | 获取当前编解码器在给定档次的情况下支持的等级信息 |
| OH_AVCapability_AreProfileAndLevelSupported             | 确认当前编解码器是否支持特定的档次和等级组合 |

未知档次和级别情况下，尝试获取可配置的的档次，以及能支持的级别，示例如下：

```c++
// 1. 获取H.264编码器能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 2. 查询支持的档次
const int32_t *profiles = nullptr;
uint32_t profileNum = -1;
int32_t ret = OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
if (ret != AV_ERR_OK || profiles == nullptr || profileNum <= 0) {
   // 异常处理
}
for (int i = 0; i < profileNum; i++) {
   // 3. 查询特定档次支持的级别
   int32_t profile = profiles[i]; // 对照枚举OH_AVCProfile
   const int32_t *levels = nullptr;
   uint32_t levelNum = -1;
   ret = OH_AVCapability_GetSupportedLevelsForProfile(capability, profile, &levels, &levelNum);
   if (ret != AV_ERR_OK || levels == nullptr || levelNum <= 0) {
      // 异常处理
   }
   for (int j = 0; j < levelNum; j++) {
      int32_t level = levels[j]; // 对照枚举OH_AVCLevel
   }
}
```

已知需要的编码档次和级别组合，直接查询支持情况示例如下：

```c++
// 1. 获取H.264编码器能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 2. 查询编码档次和级别是否支持
bool isSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_MAIN, AVC_LEVEL_51);
```

### 设置正确的视频宽高

视频编解码器对宽高存在对齐约束，如主流编解码器默认编解码像素格式为YUV420系列中的，会对UV分量下采样，在此情况下视频编解码的宽高至少要按2对齐。此外还有其他因素可能导致更加严格的对齐约束。

视频编解码的宽高不仅会受帧级编解码能力限制，同时也会受协议中级别对帧级能力定义限制。

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
OH_AVRange widthRange = {-1，-1};
ret = OH_AVCapability_GetVideoWidthRange(capability, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // 异常处理
} else if (width < widthRange.minVal || width > widthRange.maxVal) {
   // 4. (可选) 调整视频宽
   width = min(max(width, widthRange.minVal), widthRange.maxVal);
}
// 5. 基于视频宽，获取可选视频高的范围
OH_AVRange heightRange = {-1，-1};
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
OH_AVRange heightRange = {-1，-1};
ret = OH_AVCapability_GetVideoHeightRange(capability, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // 异常处理
} else if (height < heightRange.minVal || height > heightRange.maxVal) {
   // 4. (可选) 调整视频高
   height = min(max(height, heightRange.minVal), heightRange.maxVal);
}
// 5. 基于视频高，获取可选视频宽的范围
OH_AVRange widthRange = {-1，-1};
ret = OH_AVCapability_GetVideoWidthRangeForHeight(capability, height, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // 异常处理
}
// 6. 从可选宽度范围中挑选合适的宽度配置
```

### 设置正确的视频帧率

视频编解码的帧率不仅会受秒级编解码能力限制，同时也会受协议中级别对秒级能力定义限制。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoFrameRateRange             | 获取当前视频编解码器支持的帧率的范围 |
| OH_AVCapability_GetVideoFrameRateRangeForSize      | 获取当前视频编解码器在给定图像尺寸情况下的帧率的范围 |
| OH_AVCapability_AreVideoSizeAndFrameRateSupported  | 获取当前视频编解码器支持的高的范围 |

有需求的帧率目标，确认帧率是否在可选范围内，示例如下：

```c++
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. 获取支持的帧率范围
OH_AVRange frameRateRange = {-1，-1};
int32_t ret = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
   // 异常处理
}
// 2. 判断是否在可选帧率范围内
bool isSupported = frameRate >= frameRateRange.minVal && frameRate <= frameRateRange.maxVal;
```

确认明确的尺寸和帧率组合是否支持，示例代码如下：

```c++
bool isSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, 1920, 1080, 120);
if (!isSupported) {
   // 基于确定视频尺寸，查询支持的帧率范围，并调整
}
```

在确定的视频尺寸下，选择合适的帧率配置，示例如下：

```c++
int32_t width = 1920;
int32_t height = 1080;
// 1. 获取确定视频尺寸下可选的帧率范围
OH_AVRange frameRateRange = {-1，-1};
int32_t ret = OH_AVCapability_GetVideoFrameRateRangeForSize(capability, width, height, &frameRateRange);
if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
   // 异常处理
}
// 2. 从可选帧率范围中挑选合适的帧率配置
```

### 设置正确的视频像素格式信息

视频像素格式指示的编码输入图像或解码输出图像的像素排布方式，参考OH_AVPixelFormat
// TODO: 待确认，解码是否要配置，解码查询是否有用

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoSupportedPixelFormats             | 获取当前视频编解码器支持的像素格式 |

```c++
// 1. 获取H.264编码器能力句柄
constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 2. 获取当前视频编解码器支持的像素格式
const int32_t *pixFormats = nullptr;
uint32_t pixFormatNum = -1;
int32_t ret = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
if (ret != AV_ERR_OK || pixFormats == nullptr || pixFormatNum <= 0) {
   // 异常处理
}
// 3. 校验是否支持对应像素格式
bool isMatched = false;
for (int i = 0; i < pixFormatNum; i++) {
   if (pixFormats[i] == DEFAULT_PIXELFORMAT) {
      isMatched = true;
   }
}
if (!isMatched) {
   // 4. 替换其他像素格式输入或选择其他编解码器
}
```

### 查询编解码特性支持情况并获取特性属性信息

编解码特性是指仅在特定编解码场景中使用的可选特性，参考OH_AVCapabilityFeature。

| 接口     | 功能描述                         |
| -------- | ---------------------------- |
| OH_AVCapability_IsFeatureSupported              | 确认当前编解码器是否支持给定的特性 |
| OH_AVCapability_GetFeatureProperties            | 获取当前编码器支持的指定特性的属性，仅部分特性存在属性信息 |

查询H.264编码器是否支持长期参考帧特性示例如下：

```c++
constexpr int32_t NEEDED_LTR_NUM = 2;
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
// 1. 获取H.264编码器能力句柄
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // 异常处理
}
// 2. 查询是否支持长期参考帧特性
bool isSupported = OH_AVCapability_IsFeatureSupported(capability,VIDEO_ENCODER_LONG_TERM_REFERENCE);
if (isSupported) {
   // 3. (可选) 查询支持的长期参考帧个数
   OH_AVFormat *properties = OH_AVCapability_GetFeatureProperties(capability, VIDEO_ENCODER_LONG_TERM_REFERENCE);
   int32_t maxLTRCount = -1;
   int32_t ret = OH_AVFormat_GetIntValue(properties, OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT, &maxLTRCount);
   if (ret == AV_ERR_OK && maxLTRCount >= NEEDED_MIN_LTR_NUM) {
      (void)OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT, NEEDED_LTR_NUM);
   }
}
// 4. 编码器创建和配置
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_VideoEncoder_Configure(videoEnc, format);
```