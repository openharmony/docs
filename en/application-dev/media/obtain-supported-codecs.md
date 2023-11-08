# Obtaining Supported Codecs

Different devices support different codecs. Before invoking or configuring a codec, you need to query the codec specifications supported.

You can call the native APIs provided by the **AVCapability** module to check whether related capabilities are supported.

## How to Develop

Read [AVCapability](../reference/native-apis/_a_v_capability.md) for the API reference.

1. Obtain a codec capability instance.

    ```c
    // Obtain a codec capability instance based on the MIME type and encoder flag.
    OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false);

    // Obtain a codec capability instance based on the MIME type, encoder flag, and software/hardware type.
    OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
    ```

2. Query the specifications provided by the codec capability instance.
    ```c
    // Check whether the codec capability instance describes a hardware codec.
    bool isHardware = OH_AVCapability_IsHardware(capability);

    // Obtain the codec name of the codec capability instance.
    const char *codecName = OH_AVCapability_GetName(capability);

    // Obtain the maximum number of instances supported by the codec capability instance.
    int32_t maxSupportedInstances = OH_AVCapability_GetMaxSupportedInstances(capability);

    // Obtain the bit rate range supported by the encoder.
    OH_AVRange bitrateRange;
    int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Check whether the codec capability instance supports a specific bit rate mode.
    bool isEncoderBitrateModeSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, BITRATE_MODE_CBR);

    // Obtain the quality range supported by the encoder.
    OH_AVRange qualityRange;
    int32_t ret = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the complexity range supported by the encoder.
    OH_AVRange complexityRange;
    int32_t ret = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the supported audio sampling rates.
    const int32_t *sampleRates;
    uint32_t sampleRateNum = 0;
    int32_t ret = OH_AVCapability_GetAudioSupportedSampleRates(capability, &sampleRates, &sampleRateNum);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the number of audio channels supported.
    OH_AVRange channelCountRange;
    int32_t ret = OH_AVCapability_GetAudioChannelCountRange(capability, &channelCountRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the width alignment value supported.
    int32_t widthAlignment;
    int32_t ret = OH_AVCapability_GetVideoWidthAlignment(capability, &widthAlignment);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the height alignment value supported.
    int32_t heightAlignment;
    int32_t ret = OH_AVCapability_GetVideoHeightAlignment(capability, &heightAlignment);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the width range when the height is 1080.
    OH_AVRange widthRange;
    int32_t ret = OH_AVCapability_GetVideoWidthRangeForHeight(capability, 1080, &widthRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the height range when the width is 1920.
    OH_AVRange heightRange;
    int32_t ret = OH_AVCapability_GetVideoHeightRangeForWidth(capability, 1920, &heightRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the width range supported.
    OH_AVRange widthRange;
    int32_t ret = OH_AVCapability_GetVideoWidthRange(capability, &widthRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the height range supported.
    OH_AVRange heightRange;
    int32_t ret = OH_AVCapability_GetVideoWidthRange(capability, &heightRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Check whether the codec capability instance supports the 1080p resolution.
    bool isVideoSizeSupported = OH_AVCapability_IsVideoSizeSupported(capability, 1920, 1080);

    // Obtain the video frame rate range supported.
    OH_AVRange frameRateRange;
    int32_t ret = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the video frame rate range when the resolution is 1920 x 1080.
    OH_AVRange frameRateRange;
    int32_t ret =  OH_AVCapability_GetVideoFrameRateRangeForSize(capability, 1920, 1080, &frameRateRange);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Check whether the codec capability instance supports the scenario where the resolution is 1080p and the frame rate is 30 fps.
    bool areVideoSizeAndFrameRateSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, 1920, 1080, 30);

    // Obtain the supported color formats and the number of supported color formats.
    const int32_t *pixFormats;
    uint32_t pixFormatNum = 0;
    int32_t ret = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the profiles supported.
    const int32_t *profiles;
    uint32_t profileNum = 0;
    int32_t ret =  OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
    if (ret != AV_ERR_OK) {
        // Exception processing.
    }

    // Obtain the level range of a specific profile.
    const int32_t *levels;
    uint32_t levelNum = 0;
    int32_t ret = OH_AVCapability_GetSupportedLevelsForProfile(capability, 0, &levels, &levelNum);

    // Check whether the codec capability instance supports the combination of a profile and level.
    bool areProfileAndLevelSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_BASELINE, 1);
    ```
