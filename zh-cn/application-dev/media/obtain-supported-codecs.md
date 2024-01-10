# 获取支持的编解码能力(C/C++)

不同设备支持的编解码能力存在差异，开发者在调用编解码或配置编解码器前，需要先查询当前系统支持的编解码器规格。

开发者可以调用本模块的Native API接口，查询相关能力的支持情况。

## 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
```

## 开发步骤

详细的API说明请参考[API文档](../reference/native-apis/_a_v_capability.md)。

1. 添加头文件。

   ```c
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   ```

2. 获得能力。

   ```c
   // 根据mime type、是否编码器获得能力
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);
   
   // 根据mime type、是否编码器以及软硬件类别获得能力
   OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
   ```

3. 查询参数。

   ```c
    // 查询当前能力是否支持硬件
   bool isHardware = OH_AVCapability_IsHardware(capability);
   
   // 查询当前能力codec名称
   const char *codecName = OH_AVCapability_GetName(capability);
   
   // 查询当前能力中，最大支持的实例数
   int32_t maxSupportedInstances = OH_AVCapability_GetMaxSupportedInstances(capability);
   
   // 查询当前能力中，编码支持的码率范围
   OH_AVRange bitrateRange;
   int32_t bitrateRet = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
   
   
   // 查询当前能力中，码控模式是否支持
   bool isEncoderBitrateModeSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, BITRATE_MODE_CBR);
   
   // 查询当前能力中，编码质量范围
   OH_AVRange qualityRange;
   int32_t qualityRet = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
   
   
   // 查询当前能力中，编码复杂度范围
   OH_AVRange complexityRange;
   int32_t complexityRet = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
   
   
   // 查询当前能力中，支持的音频采样率
   const int32_t *sampleRates;
   uint32_t sampleRateNum = 0;
   int32_t sampleRet = OH_AVCapability_GetAudioSupportedSampleRates(capability, &sampleRates, &sampleRateNum);
   
   
   // 查询当前能力中，支持的音频通道数范围
   OH_AVRange channelCountRange;
   int32_t channelCountRet = OH_AVCapability_GetAudioChannelCountRange(capability, &channelCountRange);
   
   
   // 查询当前能力中，宽的对齐值
   int32_t widthAlignment;
   int32_t widthRet = OH_AVCapability_GetVideoWidthAlignment(capability, &widthAlignment);
   
   
   // 查询当前能力中，高的对齐值
   int32_t heightAlignment;
   int32_t heightRet = OH_AVCapability_GetVideoHeightAlignment(capability, &heightAlignment);
   
   
   // 查询当前能力中，高为1080时，宽的范围
   OH_AVRange widthRange;
   int32_t widthRangeRet = OH_AVCapability_GetVideoWidthRangeForHeight(capability, 1080, &widthRange);
   
   
   // 查询当前能力中，宽为1920时，高的范围
   OH_AVRange heightRange;
   int32_t heightRangeRet = OH_AVCapability_GetVideoHeightRangeForWidth(capability, 1920, &heightRange);
   
   
   // 查询当前能力中，宽的范围
   OH_AVRange videoWidthRange;
   int32_t videoWidthRet = OH_AVCapability_GetVideoWidthRange(capability, &videoWidthRange);
   
   
   // 查询当前能力中，高的范围
   OH_AVRange videoHeightRange;
   int32_t videoHeightRet = OH_AVCapability_GetVideoHeightRange(capability, &videoHeightRange);
   
   
   // 校验当前能力是否支持分辨率1080p
   bool isVideoSizeSupported = OH_AVCapability_IsVideoSizeSupported(capability, 1920, 1080);
   
   // 查询当前能力中，视频帧率范围
   OH_AVRange frameRateRange;
   int32_t videoFrameRet = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
   
   
   // 查询当前能力中，分辨率为1920x1080时视频帧率范围
   OH_AVRange frameRateRangeForSize;
   int32_t ret = OH_AVCapability_GetVideoFrameRateRangeForSize(capability, 1920, 1080, &frameRateRangeForSize);
   
   
   // 校验当前能力是否支持分辨率1080p、帧率30的场景
   bool areVideoSizeAndFrameRateSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, 1920, 1080, 30);
   
   // 查询当前能力中，支持的颜色格式以及个数
   const int32_t *pixFormats;
   uint32_t pixFormatNum = 0;
   int32_t pixFormatRet = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
   
   
   // 查询当前能力中，支持的模板
   const int32_t *profiles;
   uint32_t profileNum = 0;
   int32_t profilesRet = OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
   
   
   // 查询当前能力中，特定模板情况下的等级范围
   const int32_t *levels;
   uint32_t levelNum = 0;
   int32_t levelsRet = OH_AVCapability_GetSupportedLevelsForProfile(capability, 0, &levels, &levelNum);
   
   // 检查编解码器是否支持配置文件和级别的特定组合
   bool areProfileAndLevelSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_BASELINE, 1);
   ```