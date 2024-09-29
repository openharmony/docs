# Obtaining Supported Codecs

The codecs and their capabilities that you can use for your application on a device vary according to the codec source, codec protocol, and codec capabilities deployed on that device.

To ensure that the encoding and decoding behavior meets your expectations, first query the audio and video codecs supported by the system and their capability parameters through a series of APIs. Then find the codecs that are suitable for the development scenario, and correctly configure the codec parameters.

## General Development
1. Link the dynamic link library in the CMake script.

   ``` cmake
   target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
   target_link_libraries(sample PUBLIC libnative_media_core.so)
   target_link_libraries(sample PUBLIC libnative_media_venc.so)
   target_link_libraries(sample PUBLIC libnative_media_vdec.so)
   ```
   > **NOTE**
   >
   > The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.
   >

2. Add the header files.

   ```c++
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_base.h>
   #include <multimedia/player_framework/native_avformat.h>
   #include <multimedia/player_framework/native_avcodec_videoencoder.h>
   #include <multimedia/player_framework/native_avcodec_videodecoder.h>
   ```

3. Obtain the audio/video codec capability instance.

   You can use either of the following methods to obtain the instance:
   
   Method 1: Call **OH_AVCodec_GetCapability** to obtain the codec capability instance recommended by the system. The recommendation policy is the same as that of the **OH_XXX_CreateByMime** series APIs.
   ```c++
   // Obtain the AAC decoder capability instance recommended by the system.
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, false);
   ```
   
   Method 2: Call **OH_AVCodec_GetCapabilityByCategory** to obtain the codec capability instance of the specified software or hardware.
   ```c++
   // Obtain the AVC encoder capability instance of the specified hardware.
   OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true, HARDWARE);
   ```
    The system automatically recycles the instance when it is no longer needed.

4. Call the query APIs as required. For details, see the [API Reference](../../reference/apis-avcodec-kit/_a_v_capability.md).

## Scenario-specific Development
This section describes how to use the capability query APIs in specific scenarios.

### Creating a Codec with the Specified Name

If multiple encoders or decoders with the same MIME type exist, using the **OH_XXX_CreateByMime** series APIs creates only codecs recommended by the system. To create a non-recommended codec, you must first obtain the codec name and then call **OH_XXX_CreateByName** series APIs to create a codec with the given name.

| API    | Description                        |
| -------- | -------------------------------- |
| OH_AVCapability_GetName     | Obtains the name of a codec corresponding to a capability instance.|

The code snippet below creates an H.264 software decoder when there are an H.264 software decoder and H.264 hardware decoder:
```c++
// 1. Obtain an H.264 software decoder capability instance.
OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
if (capability != nullptr) {
   // 2. Obtain the name of the H.264 software decoder.
   const char *codecName = OH_AVCapability_GetName(capability);
   // 3. Create an H.264 software decoder instance.
   OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(codecName);
}
```

### Setting Codec Parameters by Software or Hardware

A software codec and hardware codec are defined as follows:

* A software codec performs encoding and decoding on the CPU. Its capabilities can be flexibly iterated. It provides better compatibility and better protocol and specification extension capabilities over a hardware codec.

* A hardware codec performs encoding and decoding on dedicated hardware. It has been hardened on the hardware platform and its capabilities are iterated with the hardware platform. Compared with a software codec, a hardware codec has better power consumption, time consumption, and throughput performance, as well as lower CPU load.

A hardware codec is preferred as long as it meets your project requirements. You can configure codec parameters based on the software or hardware type.

| API    | Description                        |
| -------- | -------------------------------- |
| OH_AVCapability_IsHardware  | Checks whether a codec capability instance describes a hardware codec.|

The code snippet below shows the differentiated frame rate configuration for software and hardware video encoders.

```c++
// 1. Check whether the recommended H.264 encoder is a hardware codec.
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
bool isHardward = OH_AVCapability_IsHardware(capability);
// 2. Carry out differentiated configuration based on the software or hardware type.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
double frameRate = isHardward ? 60.0 : 30.0;
if (!OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, frameRate)) {
   // Exception handling.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Exception handling.
}
OH_AVFormat_Destroy(format);
```

### Creating a Multi-Channel Codec

Multiple codecs are required in certain scenarios. However, the number of codec instances that can be created is limited due to the restrictions of system resources.

| API    | Description                        |
| -------- | -------------------------------- |
| OH_AVCapability_GetMaxSupportedInstances  | Obtains the maximum number of codec instances that can be concurrently run corresponding to a capability instance. The actual number of codec instances that can be created is restricted by other system resources.|

Create hardware decoder instances first. If the hardware decoder instances cannot fully meet the project requirements, create software decoder instances. The following is an example:

```c++
constexpr int32_t NEEDED_VDEC_NUM = 8;
// 1. Create hardware decoder instances.
OH_AVCapability *capHW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, HARDWARE);
int32_t vDecNumHW = min(OH_AVCapability_GetMaxSupportedInstances(capHW), NEEDED_VDEC_NUM);
int32_t createdVDecNum = 0;
for (int i = 0; i < vDecNumHW; i++) {
   OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capHW));
   if (videoDec != nullptr) {
      // Maintained in videoDecVector.
      createdVDecNum++;
   }
}
if (createdVDecNum < NEEDED_VDEC_NUM) {
   // 2. If the hardware decoder instances cannot fully meet the project requirements, create software decoder instances.
   OH_AVCapability *capSW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, SOFTWARE);
   int32_t vDecNumSW = min(OH_AVCapability_GetMaxSupportedInstances(capSW), NEEDED_VDEC_NUM - createdVDecNum);
   for (int i = 0; i < vDecNumSW; i++) {
      OH_AVCodec *videoDec = OH_VideoDecoder_CreateByName(OH_AVCapability_GetName(capSW));
      if (videoDec != nullptr) {
         // Maintained in videoDecVector.
         createdVDecNum++;
      }
   }
}
```

### Controlling the Encoding Quality

Three bit rate modes are available: Constant Bit Rate (CBR), Dynamic Bit Rate (VBR), and Constant Quality (CQ). For CBR and VBR, the encoding quality is determined by the bit rate parameters. For CQ, the encoding quality is determined by the quality parameters.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_IsEncoderBitrateModeSupported  | Checks whether a codec supports the specified bit rate mode.|
| OH_AVCapability_GetEncoderBitrateRange     | Obtains the bit rate range supported by a codec. This API can be used in CBR or VBR mode.|
| OH_AVCapability_GetEncoderQualityRange  | Obtains the quality range supported by a codec. This API can be used in CQ mode. |

The code snippet below shows the configuration in CBR or VBR mode.

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CBR;
int32_t bitrate = 3000000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Exception handling.
}
// 1. Check whether a bit rate mode is supported.
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // Exception handling.
}
// 2. Obtain the bit rate range and check whether the bit rate to be configured is within the range.
OH_AVRange bitrateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // Exception handling.
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal) {
   // 3. (Optional) Adjust the bit rate parameters to be configured.
}
// 4. Set the encoding parameters.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) &&
   OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate)) == false) {
   // Exception handling.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Exception handling.
}
OH_AVFormat_Destroy(format);
```

The code snippet below shows the configuration in CQ mode.

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CQ;
int32_t quality = 0;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Exception handling.
}
// 1. Check whether a bit rate mode is supported.
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // Exception handling.
}
// 2. Obtain the quality range and determine whether the quality parameters to be configured are within the range.
OH_AVRange qualityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
if (ret != AV_ERR_OK || qualityRange.maxVal < 0) {
   // Exception handling.
}
if (quality > qualityRange.maxVal || quality < qualityRange.minVal) {
   // 3. (Optional) Adjust the quality parameters to be configured.
}
// 5. Set the encoding parameters.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) &&
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_QUALITY, quality) == false) {
   // Exception handling.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Exception handling.
}
OH_AVFormat_Destroy(format);
```

### Checking the Complexity Range Supported

The complexity range determines the number of tools used by the codec. It is supported only by some codecs.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetEncoderComplexityRange | Obtains the complexity range supported by a codec.| 

```c++
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // Exception handling.
}
// Check the supported encoding complexity range.
OH_AVRange complexityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
```

### Setting the Correct Audio Codec Parameters

In audio encoding or decoding scenarios, you need to query and set parameters such as the sampling rate, number of channels, and bit rate (required only for audio encoding).

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetAudioSupportedSampleRates     | Obtains the sample rates supported by an audio codec.|
| OH_AVCapability_GetAudioChannelCountRange  | Obtains the count range of channels supported by an audio codec.|
| OH_AVCapability_GetEncoderBitrateRange     | Obtains the bit rate range supported by an encoder.|

The code snippet below shows how to correctly set the encoding parameters in the audio encoding scenario.

```c++
int32_t sampleRate = 44100;
int32_t channelCount = 2;
int32_t bitrate = 261000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // Exception handling.
}
// 1. Check whether the sample rate to be configured is supported.
const int32_t *sampleRates = nullptr;
uint32_t sampleRateNum = -1;
int32_t ret = OH_AVCapability_GetAudioSupportedSampleRates(capability, &sampleRates, &sampleRateNum);
if (ret != AV_ERR_OK || sampleRates == nullptr || sampleRateNum <= 0) {
   // Exception handling.
}
bool isMatched = false;
for (int i = 0; i < sampleRateNum; i++) {
   if (sampleRates[i] == sampleRate) {
      isMatched = true;
   }
}
if (!isMatched) {
   // 2. (Optional) Adjust the sample rate to be configured.
}
// 3. Obtain the count range of channels and check whether the number of channels to be configured is within the range.
OH_AVRange channelRange = {-1, -1};
ret = OH_AVCapability_GetAudioChannelCountRange(capability, &channelRange);
if (ret != AV_ERR_OK || channelRange.maxVal <= 0) {
   // Exception handling.
}
if (channelCount > channelRange.maxVal || channelCount < channelRange.minVal ) {
   //4. (Optional) Adjust the number of channels to be configured.
}
// 5. Obtain the bit rate range and check whether the bit rate to be configured is within the range.
OH_AVRange bitrateRange = {-1, -1};
ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // Exception handling.
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal ) {
   //7. (Optional) Adjust the bit rate to be configured.
}
// 8. Set the encoding parameters.
OH_AVCodec *audioEnc = OH_AudioEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC);
OH_AVFormat *format = OH_AVFormat_Create();
if (OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, sampleRate) &&
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, channelCount) &&
   OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate)) == false) {
   // Exception handling.
}
if (OH_AudioEncoder_Configure(audioEnc, format) != AV_ERR_OK) {
   // Exception handling.
}
OH_AVFormat_Destroy(format);
```

### Checking the Codec Profile and Level Supported

The codec standard provides lots of encoding tools to deal with various encoding scenarios. However, not all tools are required in a specific scenario. Therefore, the standard uses the codec profile to specify the enabled status of these encoding tools. For example, for H.264, there are baseline, main, and high profiles. For details, see **OH_AVCProfile**.

A codec level is a division of the processing capability and storage space required by a codec. For example, for H.264, there are 20 levels ranging from 1 to 6.2. For details, see **OH_AVCLevel**.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetSupportedProfiles                    | Obtains the profiles supported by a codec.|
| OH_AVCapability_GetSupportedLevelsForProfile            | Obtains the codec levels supported by a profile.|
| OH_AVCapability_AreProfileAndLevelSupported             | Checks whether a codec supports the combination of a profile and level.|

The code snippet below checks whether a profile is supported and obtains the supported levels.

```c++
OH_AVCProfile profile = AVC_PROFILE_MAIN;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Exception handling.
}
// 1. Check whether the profile to be configured is supported.
const int32_t *profiles = nullptr;
uint32_t profileNum = -1;
int32_t ret = OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
if (ret != AV_ERR_OK || profiles == nullptr || profileNum <= 0) {
   // Exception handling.
}
bool isMatched = false;
for (int i = 0; i < profileNum; i++) {
   if (profiles[i] == profile) {
      isMatched = true;
   }
}
// 2. Obtain the codec levels supported by the profile.
const int32_t *levels = nullptr;
uint32_t levelNum = -1;
ret = OH_AVCapability_GetSupportedLevelsForProfile(capability, profile, &levels, &levelNum);
if (ret != AV_ERR_OK || levels == nullptr || levelNum <= 0) {
   // Exception handling.
}
OH_AVCLevel maxLevel = static_cast<OH_AVCLevel>(levels[levelNum -1]);
// 3. (Optional) Use different service logic based on the maximum level supported.
switch (maxLevel) {
   case AVC_LEVEL_31:
      // ...
      break;
   case AVC_LEVEL_51:
      // ...
      break;
   default:
      // ...
}
// 4. Set the profile parameters.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, profile)) {
   // Exception handling.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Exception handling.
}
OH_AVFormat_Destroy(format);
```

If you already know the required profile and level combination, use the code snippet below to check whether the combination is supported.

```c++
// 1. Obtain an H.264 encoder capability instance.
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Exception handling.
}
// 2. Check whether the combination of the profile and level is supported.
bool isSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_MAIN, AVC_LEVEL_51);
```

### Setting the Correct Video Width and Height

The video codec has restrictions on width and height alignment. For example, for YUV420 series, the default codec pixel format of popular codecs, downsampling is performed on the UV component. In this case, the width and height of the video codec must be 2-pixel aligned at least. There are other factors that may lead to stricter alignment restrictions.

The width and height of a video codec are restricted by the frame-level encoding and decoding capability of the codec and the frame-level capability defined in the protocol. For example, for H.264, AVC_LEVEL_51 limits the maximum number of macroblocks per frame to 36864.

The formula for calculating the maximum frame rate based on the image width and height is as follows, where **$MaxMBsPerFrameLevelLimits$** indicates the maximum number of macroblocks per frame defined in the protocol that can be supported by the codec, and **$MaxMBsPerFrameSubmit$** indicates the maximum number of macroblocks per frame reported by the codec. In practice, the intersection of the two values is used.

$$
MaxMBsPerFrame = \min(MaxMBsPerFrameLevelLimits, MaxMBsPerFrameSubmit) \\
MBWidth = MBHeight = 16 \\
maxWidth = \lfloor MaxMBsPerFrame \div \lceil \frac{height}{MBHeight} \rceil \rfloor \times MBWidth
$$

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoWidthAlignment     | Obtains the video width alignment supported by a video codec.|
| OH_AVCapability_GetVideoHeightAlignment    | Obtains the video height alignment supported by a video codec.|
| OH_AVCapability_GetVideoWidthRange             | Obtains the video width range supported by a video codec.|
| OH_AVCapability_GetVideoHeightRange            | Obtains the video height range supported by a video codec.|
| OH_AVCapability_GetVideoWidthRangeForHeight    | Obtains the video width range of a video codec based on a given height.|
| OH_AVCapability_GetVideoHeightRangeForWidth    | Obtains the video height range of a video codec based on a given width.|
| OH_AVCapability_IsVideoSizeSupported           | Checks whether a video codec supports the combination of a given width and height.|

If you already know the video height and width, use the code snippet below to check whether they are supported.

```c++
int32_t width = 1920;
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. Check whether the video width and height are supported.
bool isSupported = OH_AVCapability_IsVideoSizeSupported(capability, width, height);
if (!isSupported) {
   // 2. (Optional) Query detailed restrictions based on the video height and width and adjust the video height and width to use.
}
```

If the video height or width is not supported or the configuration fails, use the following methods to find the supported video width and height range.

Find the supported size configuration when the video width is known. The following is an example:

```c++
int32_t width = 1920;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. Check whether the video width meets the width alignment requirements.
int32_t widthAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoWidthAlignment(capability, &widthAlignment);
if (ret != AV_ERR_OK || widthAlignment <= 0) {
   // Exception handling.
} else if (width % widthAlignment != 0) {
   // 2. (Optional) Align the video width.
   width = (width + widthAlignment - 1) / widthAlignment * widthAlignment;
}
// 3. Check whether the video width is within the supported range.
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRange(capability, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // Exception handling.
} else if (width < widthRange.minVal || width > widthRange.maxVal) {
   // 4. (Optional) Adjust the video width.
   width = min(max(width, widthRange.minVal), widthRange.maxVal);
}
// 5. Obtain the range of available video heights based on the video width.
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRangeForWidth(capability, width, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // Exception handling.
}
// 6. Select a proper video height from the range.
```

Find the supported size configuration when the video height is known. The following is an example:

```c++
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. Check whether the video height meets the high alignment requirements.
int32_t heightAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoHeightAlignment(capability, &heightAlignment);
if (ret != AV_ERR_OK || heightAlignment <= 0) {
   // Exception handling.
} else if (height % heightAlignment != 0) {
   // 2. (Optional) Align the video height.
   height = (height + heightAlignment - 1) / heightAlignment * heightAlignment;
}
// 3. Check whether the video height is within the supported range.
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRange(capability, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // Exception handling.
} else if (height < heightRange.minVal || height > heightRange.maxVal) {
   // 4. (Optional) Adjust the video height.
   height = min(max(height, heightRange.minVal), heightRange.maxVal);
}
// 5. Obtain the range of available video widths based on the video height.
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRangeForHeight(capability, height, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // Exception handling.
}
// 6. Select a proper video width from the range.
```

### Setting the Correct Video Frame Rate

The frame rate of a video codec is restricted by the second-level encoding and decoding capability of the codec and the second-level capability defined in the protocol. For example, for H.264, AVC_LEVEL_51 limits the maximum number of macroblocks per second to 983040.

The formula for calculating the maximum frame rate based on the image width and height is as follows, where **$MaxMBsPerSecondLevelLimits$** indicates the maximum number of macroblocks per second defined in the protocol that can be supported by the codec, and **$MaxMBsPerSecondSubmit$** indicates the maximum number of macroblocks per second reported by the codec. In practice, the intersection of the two values is used.

$$
MaxMBsPerSecond = \min(MaxMBsPerSecondLevelLimits, MaxMBsPerSecondSubmit) \\
MBWidth = MBHeight = 16 \\
maxFrameRate = MaxMBsPerSecond \div (\lceil{\frac{width}{MBWidth}} \rceil \times \lceil \frac{height}{MBHeight} \rceil)
$$

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoFrameRateRange             | Obtains the video frame rate range supported by a video codec.|
| OH_AVCapability_GetVideoFrameRateRangeForSize      | Obtains the video frame rate range of a video codec based on a given video size.|
| OH_AVCapability_AreVideoSizeAndFrameRateSupported  | Checks whether a video codec supports the combination of a video size and frame rate.|

If a specific frame rate is required, you can use the code snippet below to check whether the frame rate is supported.

```c++
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. Obtain the supported frame rate range.
OH_AVRange frameRateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
   // Exception handling.
}
// 2. Check whether the frame rate is within the range.
bool isSupported = frameRate >= frameRateRange.minVal && frameRate <= frameRateRange.maxVal;
```

The code snippet below shows how to find a proper frame rate configuration based on a given video size.

```c++
constexpr int32_t width = 1920;
constexpr int32_t height = 1080;
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
// 1. Check whether the video size to be configured can reach the ideal frame rate.
bool isSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, width, height, frameRate);
if (!isSupported) {
   // 2. Query the supported frame rate range based on the video size, and adjust the frame rate to be configured based on the query result.
   OH_AVRange frameRateRange = {-1, -1};
   int32_t ret = OH_AVCapability_GetVideoFrameRateRangeForSize(capability, width, height, &frameRateRange);
   if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
      // Exception handling.
   }
   frameRate = min(max(frameRate, frameRateRange.minVal), frameRateRange.maxVal);
}

// 3. Set the video size and frame rate.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, width, height);
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_FRAME_RATE, frameRate)) {
   // Exception handling.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Exception handling.
}
OH_AVFormat_Destroy(format);
```

### Setting the Correct Video Pixel Format

The video pixel format determines the pixel arrangement mode of an input image for encoding or an output image of decoding. For details, see **OH_AVPixelFormat**.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoSupportedPixelFormats             | Obtains the video pixel formats supported by a video codec.|

```c++
constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Exception handling.
}
// 1. Obtain the video pixel formats supported by the video codec.
const int32_t *pixFormats = nullptr;
uint32_t pixFormatNum = -1;
int32_t ret = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
if (ret != AV_ERR_OK || pixFormats == nullptr || pixFormatNum <= 0) {
   // Exception handling.
}
// 2. Check whether the pixel format to be configured is supported.
bool isMatched = false;
for (int i = 0; i < pixFormatNum; i++) {
   if (pixFormats[i] == DEFAULT_PIXELFORMAT) {
      isMatched = true;
   }
}
if (!isMatched) {
   // 3. Replace an unsupported pixel format or select another codec.
}
```

### Checking Whether a Codec Feature Is Supported and Obtaining Its Properties

A codec feature refers to an optional feature used only in specific encoding and decoding scenarios. For details, see **OH_AVCapabilityFeature**.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_IsFeatureSupported              | Check whether a codec supports a given feature.|
| OH_AVCapability_GetFeatureProperties            | Obtains the properties of a feature. Only some features have property information.|

The code snippet below is an example of querying whether the H.264 encoder supports the long-term reference frame feature:

```c++
constexpr int32_t NEEDED_LTR_NUM = 2;
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Exception handling.
}
// 1. Check whether the long-term reference frame feature is supported.
bool isSupported = OH_AVCapability_IsFeatureSupported(capability,VIDEO_ENCODER_LONG_TERM_REFERENCE);
if (isSupported) {
   // 2. Obtain the number of supported long-term reference frames.
   OH_AVFormat *properties = OH_AVCapability_GetFeatureProperties(capability, VIDEO_ENCODER_LONG_TERM_REFERENCE);
   int32_t maxLTRCount = -1;
   int32_t ret = OH_AVFormat_GetIntValue(properties, OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT, &maxLTRCount);
   if (ret == AV_ERR_OK && maxLTRCount >= NEEDED_MIN_LTR_NUM) {
      if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT, NEEDED_LTR_NUM)) {
         // Exception handling.
      }
   }
}
// 3. Create and configure an encoder.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Exception handling.
}
```
