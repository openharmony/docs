# Obtaining Supported Codecs

Different devices support different codecs. Before invoking or configuring a codec, you need to query the codec specifications supported.

You can call the native APIs provided by the **AVCapability** module to check whether related capabilities are supported.

## Linking the Dynamic Library in the CMake Script

``` cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
```

## How to Develop

Read [AVCapability](../../reference/apis-avcodec-kit/_a_v_capability.md) for the API reference.

1. Add the header files.

   ```c
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   ```

2. Obtain a codec capability instance.

   ```c
   // Obtain a codec capability instance based on the MIME type and encoder flag.
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);
   
   // Obtain a codec capability instance based on the MIME type, encoder flag, and software/hardware type.
   OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
   ```

3. Query parameters.

   ```c
    // Check whether the codec capability instance describes a hardware codec.
   bool isHardware = OH_AVCapability_IsHardware(capability);
   
   // Obtain the codec name of the codec capability instance.
   const char *codecName = OH_AVCapability_GetName(capability);
   
   // Obtain the maximum number of instances supported by the codec capability instance.
   int32_t maxSupportedInstances = OH_AVCapability_GetMaxSupportedInstances(capability);
   
   // Obtain the bit rate range supported by the encoder.
   OH_AVRange bitrateRange;
   int32_t bitrateRet = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
   
   
   // Check whether the codec capability instance supports a specific bit rate mode.
   bool isEncoderBitrateModeSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, BITRATE_MODE_CBR);
   
   // Obtain the quality range supported by the encoder.
   OH_AVRange qualityRange;
   int32_t qualityRet = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
   
   
   // Obtain the complexity range supported by the encoder.
   OH_AVRange complexityRange;
   int32_t complexityRet = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
   
   
   // Obtain the supported audio sampling rates.
   const int32_t *sampleRates;
   uint32_t sampleRateNum = 0;
   int32_t sampleRet = OH_AVCapability_GetAudioSupportedSampleRates(capability, &sampleRates, &sampleRateNum);
   
   
   // Obtain the number of audio channels supported.
   OH_AVRange channelCountRange;
   int32_t channelCountRet = OH_AVCapability_GetAudioChannelCountRange(capability, &channelCountRange);
   
   
   // Obtain the width alignment value supported.
   int32_t widthAlignment;
   int32_t widthRet = OH_AVCapability_GetVideoWidthAlignment(capability, &widthAlignment);
   
   
   // Obtain the height alignment value supported.
   int32_t heightAlignment;
   int32_t heightRet = OH_AVCapability_GetVideoHeightAlignment(capability, &heightAlignment);
   
   
   // Obtain the width range when the height is 1080.
   OH_AVRange widthRange;
   int32_t widthRangeRet = OH_AVCapability_GetVideoWidthRangeForHeight(capability, 1080, &widthRange);
   
   
   // Obtain the height range when the width is 1920.
   OH_AVRange heightRange;
   int32_t heightRangeRet = OH_AVCapability_GetVideoHeightRangeForWidth(capability, 1920, &heightRange);
   
   
   // Obtain the width range supported.
   OH_AVRange videoWidthRange;
   int32_t videoWidthRet = OH_AVCapability_GetVideoWidthRange(capability, &videoWidthRange);
   
   
   // Obtain the height range supported.
   OH_AVRange videoHeightRange;
   int32_t videoHeightRet = OH_AVCapability_GetVideoHeightRange(capability, &videoHeightRange);
   
   
   // Check whether the codec capability instance supports the 1080p resolution.
   bool isVideoSizeSupported = OH_AVCapability_IsVideoSizeSupported(capability, 1920, 1080);
   
   // Obtain the video frame rate range supported.
   OH_AVRange frameRateRange;
   int32_t videoFrameRet = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
   
   
   // Obtain the video frame rate range when the resolution is 1920 x 1080.
   OH_AVRange frameRateRangeForSize;
   int32_t ret = OH_AVCapability_GetVideoFrameRateRangeForSize(capability, 1920, 1080, &frameRateRangeForSize);
   
   
   // Check whether the codec capability instance supports the scenario where the resolution is 1080p and the frame rate is 30 fps.
   bool areVideoSizeAndFrameRateSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, 1920, 1080, 30);
   
   // Obtain the supported color formats and the number of supported color formats.
   const int32_t *pixFormats;
   uint32_t pixFormatNum = 0;
   int32_t pixFormatRet = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
   
   
   // Obtain the profiles supported.
   const int32_t *profiles;
   uint32_t profileNum = 0;
   int32_t profilesRet = OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
   
   
   // Obtain the level range of a specific profile.
   const int32_t *levels;
   uint32_t levelNum = 0;
   int32_t levelsRet = OH_AVCapability_GetSupportedLevelsForProfile(capability, 0, &levels, &levelNum);
   
   // Check whether the codec capability instance supports the combination of a profile and level.
   bool areProfileAndLevelSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_BASELINE, 1);
   ```
