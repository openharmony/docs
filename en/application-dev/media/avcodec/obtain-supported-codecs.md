# Obtaining Supported Codecs

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yang-xiaoyu5-->
<!--Designer: @dpy2650-->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

Due to differences in sources, codec protocols, and device capabilities, the available codecs and their capabilities vary across different devices.

To ensure that codec behavior meets expectations, use the audio and video codec capability interface to query the codecs supported by the system and their capabilities, select codecs that align with your development requirements, and configure parameters correctly.

## General Development
1. Link the dynamic libraries in the CMake script.

   ``` cmake
   target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
   target_link_libraries(sample PUBLIC libnative_media_core.so)
   target_link_libraries(sample PUBLIC libnative_media_venc.so)
   target_link_libraries(sample PUBLIC libnative_media_vdec.so)
   target_link_libraries(sample PUBLIC libnative_media_acodec.so)
   ```
   > **NOTE**
   >
   > The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.
   >

2. Add the header files.

   ```c++
   #include <algorithm>
   #include <multimedia/player_framework/native_avcapability.h>
   #include <multimedia/player_framework/native_avcodec_audiocodec.h>
   #include <multimedia/player_framework/native_avcodec_videoencoder.h>
   #include <multimedia/player_framework/native_avcodec_videodecoder.h>
   ```

3. Obtain an audio/video codec capability instance.

   You can use either of the following methods to obtain the instance:
   
   Method 1: Call **OH_AVCodec_GetCapability** to obtain the codec capability instance recommended by the system. The recommendation policy is the same as that of the **OH_XXX_CreateByMime** series APIs.
   ```c++
   // Obtain the AAC decoder capability instance recommended by the system.
   OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, false);
   ```
   
   Method 2: Call **OH_AVCodec_GetCapabilityByCategory** to obtain the codec capability instance for the specified software or hardware.
   ```c++
   // Obtain the AVC encoder capability instance for the specified hardware.
   OH_AVCapability *capability = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true, HARDWARE);
   ```
   After obtaining the codec capability instance, you can move on to the next steps. There is no need to manually release the instance. The system automatically reclaims the instance when it is no longer needed.
   
4. Call the query APIs as required. For details, see [AudioCodec](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md).

## Scenario-based Development
This section provides examples to illustrate the use of capability query interfaces in specific scenarios that may be encountered during development.

### Creating a Codec with the Specified Name

If there are multiple codecs of the same MIME type, use the **OH_XXX_CreateByMime** series APIs to create the system-recommended codec. To create other codecs, you must first obtain their name and then call **OH_XXX_CreateByName** series APIs to create the codec with the specified name.

| API    | Description                        |
| -------- | -------------------------------- |
| OH_AVCapability_GetName     | Obtains the name of a codec corresponding to a capability instance.|

The following is an example of creating an H.264 software decoder when both the H.264 software decoder and H.264 hardware decoder exist:

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

The definitions of software codecs and hardware codecs are as follows:

* **Software codec**: a codec that runs on the CPU, featuring flexible iteration, good compatibility, and strong expandability.

* **Hardware codec**: a codec that runs on dedicated hardware, featuring low-power consumption, high performance, and reduced CPU load.

When hardware codecs are sufficient and meet capability requirements, prioritize their use; otherwise, use software codecs. You can configure different codec parameters based on the codec category.

| API    | Description                        |
| -------- | -------------------------------- |
| OH_AVCapability_IsHardware  | Checks whether a codec capability instance describes a hardware codec.|

The following is an example of differentiated frame rate configuration for video encoding based on hardware/software categories.

```c++
// 1. Check whether the recommended H.264 encoder is a hardware codec.
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
bool isHardware = OH_AVCapability_IsHardware(capability);
// 2. Carry out differentiated configuration based on the software or hardware type.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // Handle exceptions.
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // Handle exceptions.
}
double frameRate = isHardware ? 60.0 : 30.0;
if (!OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, frameRate)) {
   // Handle exceptions.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(format);
```

### Creating a Multi-Channel Codec

Multiple codecs are required in certain scenarios. However, the number of codec instances that can be created is limited due to constraints on system resources such as memory, processor, and bandwidth.

| API    | Description                        |
| -------- | -------------------------------- |
| OH_AVCapability_GetMaxSupportedInstances  | Obtains the maximum number of codec instances corresponding to the capability instance. The actual number of codec instances created is also constrained by system resources like memory, processor, and bandwidth.|

Prioritize creating hardware decoder instances; if resources are insufficient, create software decoder instances. An example is as follows:

```c++
constexpr int32_t NEEDED_VDEC_NUM = 8;
// 1. Create hardware decoder instances.
OH_AVCapability *capHW = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_AVC, false, HARDWARE);
if (capHW == nullptr) {
   // Handle exceptions.
}
int32_t vDecNumHW = std::min(OH_AVCapability_GetMaxSupportedInstances(capHW), NEEDED_VDEC_NUM);
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
   if (capSW == nullptr) {
      // Handle exceptions.
   }
   int32_t vDecNumSW = std::min(OH_AVCapability_GetMaxSupportedInstances(capSW), NEEDED_VDEC_NUM - createdVDecNum);
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

 Four bit rate modes are available: Constant Bit Rate (CBR), Dynamic Bit Rate (VBR), Constant Quality (CQ), and Stable Quality (SQR).
- For CBR and VBR, the encoding quality is determined by the bit rate parameters.
- For CQ, the encoding quality is determined by the quality parameters.
- For SQR, the encoding quality is determined by the SQR factor and the maximum bit rate. Currently, only H.265 (HEVC) encoding is supported.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_IsEncoderBitrateModeSupported  | Checks whether an encoder supports the specified bit rate mode.|
| OH_AVCapability_GetEncoderBitrateRange     | Obtains the bit rate range supported by an encoder. It applies to CBR, VBR, and SQR modes.|
| OH_AVCapability_GetEncoderQualityRange  | Obtains the quality range supported by an encoder. It applies to CQ mode. |

The code snippet below shows the configuration in CBR or VBR mode.

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CBR;
int32_t bitrate = 3000000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether a bit rate mode is supported.
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // Handle exceptions.
}
// 2. Obtain the bit rate range and check whether the bit rate to be configured is within the range.
OH_AVRange bitrateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // Handle exceptions.
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal) {
   // 3. (Optional) Adjust the bit rate parameters to be configured.
}
// 4. Set the encoding parameters.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // Handle exceptions.
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // Handle exceptions.
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) ||
   !OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate))) {
   // Handle exceptions.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(format);
```

The code snippet below shows the configuration in CQ mode.

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_CQ;
int32_t quality = 0;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether a bit rate mode is supported.
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // Handle exceptions.
}
// 2. Obtain the quality range and determine whether the quality parameters to be configured are within the range.
OH_AVRange qualityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderQualityRange(capability, &qualityRange);
if (ret != AV_ERR_OK || qualityRange.maxVal < 0) {
   // Handle exceptions.
}
if (quality > qualityRange.maxVal || quality < qualityRange.minVal) {
   // 3. (Optional) Adjust the quality parameters to be configured.
}
// 5. Set the encoding parameters.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // Handle exceptions.
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // Handle exceptions.
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_QUALITY, quality)) {
   // Handle exceptions.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(format);
```

The code snippet below shows the configuration in SQR mode.

```c++
OH_BitrateMode bitrateMode = BITRATE_MODE_SQR;
int32_t sqrFactor = 30; // SQR factor.
int32_t maxBitrate = 20000000; // Maximum bit rate.
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether a bit rate mode is supported.
bool isSupported = OH_AVCapability_IsEncoderBitrateModeSupported(capability, bitrateMode);
if (!isSupported) {
   // Handle exceptions.
}
// 2. Obtain the bit rate range and check whether the maximum bit rate to be configured is within the range.
OH_AVRange bitrateRange = {-1, -1};
// The value range of the maximum bit rate is the same as that of the bit rate. Therefore, OH_AVCapability_GetEncoderBitrateRange is reused to obtain the value range.
int32_t ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // Handle exceptions.
}

// The value range of the SQR factor is [0, 51] (same as the QP).
if (sqrFactor > 51 || sqrFactor < 0) {
   // 3. (Optional) Adjust the SQR factor to be configured.
}

if (maxBitrate > bitrateRange.maxVal || maxBitrate < bitrateRange.minVal) {
   // 4. (Optional) Adjust the maximum bit rate parameters to be configured.
}

// 5. Set the encoding parameters.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_HEVC);
if (videoEnc == nullptr) {
   // Handle exceptions.
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, 1920, 1080);
if (format == nullptr) {
   // Handle exceptions.
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, bitrateMode) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_SQR_FACTOR, sqrFactor) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_MAX_BITRATE, maxBitrate)) {
   // Handle exceptions.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(format);

// 6. Start the encoder.
ret = OH_VideoEncoder_Prepare(videoEnc);
if (ret != AV_ERR_OK) {
   // Handle exceptions.
}
ret = OH_VideoEncoder_Start(videoEnc);
if (ret != AV_ERR_OK) {
   // Handle exceptions.
}

// 7. (Optional) Use OH_VideoEncoder_SetParameter() to dynamically configure the SQR factor and maximum bit rate during the running.
OH_AVFormat *dynamicFormat = OH_AVFormat_Create();
// SQR supports dynamic configuration of the maximum bit rate and SQR factor.
sqrFactor = 25; // Update the SQR factor.
maxBitrate = 10000000; // Update the maximum bit rate.
OH_AVFormat_SetLongValue(dynamicFormat, OH_MD_KEY_MAX_BITRATE, maxBitrate);
OH_AVFormat_SetIntValue(dynamicFormat, OH_MD_KEY_SQR_FACTOR, sqrFactor);
ret = OH_VideoEncoder_SetParameter(videoEnc, dynamicFormat);
if (ret != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(dynamicFormat);
```

### Checking the Complexity Range Supported

The complexity range determines the number of tools used by the encoder. However, not all encoders support this feature.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetEncoderComplexityRange | Obtains the complexity range supported by an encoder.| 

```c++
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// Check the supported encoding complexity range.
OH_AVRange complexityRange = {-1, -1};
int32_t ret = OH_AVCapability_GetEncoderComplexityRange(capability, &complexityRange);
```

### Setting Correct Audio Codec Parameters

In audio encoding and decoding scenarios, you need to set the sample rate and number of channels. For audio encoding, you also need to set the bit rate.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetAudioSupportedSampleRateRanges     | Obtains the sample rates supported by an audio codec.|
| OH_AVCapability_GetAudioChannelCountRange  | Obtains the count range of channels supported by an audio codec.|
| OH_AVCapability_GetEncoderBitrateRange     | Obtains the bit rate range supported by an encoder.|

The following is an example of querying audio codec parameters:

```c++
int32_t sampleRate = 44100;
int32_t channelCount = 2;
int32_t bitrate = 261000;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether the sample rate to be configured is supported.
OH_AVRange *sampleRateRanges = nullptr;
uint32_t rangesNum = 0;
int32_t ret = OH_AVCapability_GetAudioSupportedSampleRateRanges(capability, &sampleRateRanges, &rangesNum);
if (ret != AV_ERR_OK || sampleRateRanges == nullptr || rangesNum == 0) {
   // Handle exceptions.
}
bool isMatched = false;
for (uint32_t i = 0; i < rangesNum; i++) {
   if (sampleRate >= sampleRateRanges[i].minVal && sampleRate <= sampleRateRanges[i].maxVal) {
      isMatched = true;
      break;
   }
}
if (!isMatched) {
   // 2. (Optional) Adjust the sample rate to be configured.
}
// 3. Obtain the count range of channels and check whether the number of channels to be configured is within the range.
OH_AVRange channelRange = {-1, -1};
ret = OH_AVCapability_GetAudioChannelCountRange(capability, &channelRange);
if (ret != AV_ERR_OK || channelRange.maxVal <= 0) {
   // Handle exceptions.
}
if (channelCount > channelRange.maxVal || channelCount < channelRange.minVal ) {
   //4. (Optional) Adjust the number of channels to be configured.
}
// 5. Obtain the bit rate range and check whether the bit rate to be configured is within the range.
OH_AVRange bitrateRange = {-1, -1};
ret = OH_AVCapability_GetEncoderBitrateRange(capability, &bitrateRange);
if (ret != AV_ERR_OK || bitrateRange.maxVal <= 0) {
   // Handle exceptions.
}
if (bitrate > bitrateRange.maxVal || bitrate < bitrateRange.minVal ) {
   //7. (Optional) Adjust the bit rate to be configured.
}
// 8. Set the encoding parameters.
OH_AVCodec *audioEnc = OH_AudioCodec_CreateByMime(OH_AVCODEC_MIMETYPE_AUDIO_AAC, true);
if (audioEnc == nullptr) {
   // Handle exceptions.
}
OH_AVFormat *format = OH_AVFormat_Create();
if (format == nullptr) {
   // Handle exceptions.
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_SAMPLE_RATE, sampleRate) ||
   !OH_AVFormat_SetIntValue(format, OH_MD_KEY_AUD_CHANNEL_COUNT, channelCount) ||
   !OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, static_cast<int64_t>(bitrate))) {
   // Handle exceptions.
}
if (OH_AudioCodec_Configure(audioEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(format);
```

### Checking the Codec Profile and Level Supported

The codec standard contains multiple encoding tools, which are applicable to different encoding scenarios. Codec standards include multiple encoding tools, which are applicable to different encoding scenarios. For specific scenarios, the codec standard uses the codec profile to specify the enabled status of these encoding tools. For example, for H.264, there are baseline, main, and high profiles. For details, see [OH_AVCProfile](../../reference/apis-avcodec-kit/_codec_base.md#oh_avcprofile-1).

Codec levels define the processing capability and storage space required by the codec. For example, for H.264, there are 20 levels ranging from 1 to 6.2. For details, see [OH_AVCLevel](../../reference/apis-avcodec-kit/_codec_base.md#oh_avclevel-1).

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
   // Handle exceptions.
}
// 1. Check whether the profile to be configured is supported.
const int32_t *profiles = nullptr;
uint32_t profileNum = 0;
int32_t ret = OH_AVCapability_GetSupportedProfiles(capability, &profiles, &profileNum);
if (ret != AV_ERR_OK || profiles == nullptr || profileNum == 0) {
   // Handle exceptions.
}
bool isMatched = false;
for (int i = 0; i < profileNum; i++) {
   if (profiles[i] == profile) {
      isMatched = true;
      break;
   }
}
// 2. Obtain the codec levels supported by the profile.
const int32_t *levels = nullptr;
uint32_t levelNum = 0;
ret = OH_AVCapability_GetSupportedLevelsForProfile(capability, profile, &levels, &levelNum);
if (ret != AV_ERR_OK || levels == nullptr || levelNum == 0) {
   // Handle exceptions.
}
OH_AVCLevel maxLevel = static_cast<OH_AVCLevel>(levels[0]);
for (int32_t i = 1; i < levelNum; i++) {
   OH_AVCLevel tmp = static_cast<OH_AVCLevel>(levels[i]);
   if (tmp > maxLevel) {
      maxLevel = tmp;
   }
}
// 3. (Optional) Use different service logic based on the maximum level supported.
if (maxLevel >= AVC_LEVEL_51) {
   // For levels above 5.1, the width and height can be configured to 3840*2160.
} else if (maxLevel >= AVC_LEVEL_4) {
   // For levels above 4.0, the width and height can be configured to 1920*1080.
} else if (maxLevel >= AVC_LEVEL_31) {
   // For levels above 3.1, the width and height can be configured to 1280*720.
} else {
   // An error is reported and no encoding is performed.
}
// 4. Set the profile parameters.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // Handle exceptions.
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
if (format == nullptr) {
   // Handle exceptions.
}
if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, profile)) {
   // Handle exceptions.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(format);
```

If you already know the required profile and level combination, use the code snippet below to check whether the combination is supported.

```c++
// 1. Obtain an H.264 encoder capability instance.
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 2. Check whether the combination of the profile and level is supported.
bool isSupported = OH_AVCapability_AreProfileAndLevelSupported(capability, AVC_PROFILE_MAIN, AVC_LEVEL_51);
```

### Setting the Correct Video Width and Height

Video codecs have alignment constraints on width and height. For example, mainstream codecs use YUV420 series as the default codec pixel format, where UV components are downsampled to half the original size in both width and height directions. Therefore, the width and height of video codecs must be aligned to at least 2. Other factors may also lead to more strict alignment constraints.

The width and height of video codecs are not only limited by frame-level codec capabilities but also by protocol-level constraints on frame-level capabilities. Taking H.264 as an example, AVC_LEVEL_51 limits the maximum number of macroblocks per frame to 36864.

The formula for calculating the maximum video width based on the video height is as follows:

![](figures/formula-maxmbsperframe.png)

**MaxMBsPerFrameLevelLimits** refers to the maximum number of macroblocks per frame of the codec limited by the protocol, and **MaxMBsPerFrameSubmit** refers to the maximum number of macroblocks per frame reported by the codec. The actual capability is the minimum of the two.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoWidthAlignment     | Obtains the video width alignment supported by a video codec.|
| OH_AVCapability_GetVideoHeightAlignment    | Obtains the video height alignment supported by a video codec.|
| OH_AVCapability_GetVideoWidthRange             | Obtains the video width range supported by a video codec.|
| OH_AVCapability_GetVideoHeightRange            | Obtains the video height range supported by a video codec.|
| OH_AVCapability_GetVideoWidthRangeForHeight    | Obtains the video width range of a video codec based on a given height.|
| OH_AVCapability_GetVideoHeightRangeForWidth    | Obtains the video height range of a video codec based on a given width.|
| OH_AVCapability_IsVideoSizeSupported           | Checks whether a video codec supports the combination of a given width and height.|

The following example shows how to check whether the video height and width are supported:

```c++
int32_t width = 1920;
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether the video width and height are supported.
bool isSupported = OH_AVCapability_IsVideoSizeSupported(capability, width, height);
if (!isSupported) {
   // 2. (Optional) Query detailed restrictions based on the video height and width and adjust the video height and width to use.
}
```

If the verification of video height and width fails or the configuration fails, you can try the following methods to determine the correct video width and height range.

If the video width is known, you can find the correct size configuration as shown in the following example:

```c++
int32_t width = 1920;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether the video width meets the width alignment requirements.
int32_t widthAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoWidthAlignment(capability, &widthAlignment);
if (ret != AV_ERR_OK || widthAlignment <= 0) {
   // Handle exceptions.
} else if (width % widthAlignment != 0) {
   // 2. (Optional) Align the video width.
   width = (width + widthAlignment - 1) / widthAlignment * widthAlignment;
}
// 3. Check whether the video width is within the supported range.
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRange(capability, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // Handle exceptions.
} else if (width < widthRange.minVal || width > widthRange.maxVal) {
   // 4. (Optional) Adjust the video width.
   width = std::min(std::max(width, widthRange.minVal), widthRange.maxVal);
}
// 5. Obtain the range of available video heights based on the video width.
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRangeForWidth(capability, width, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // Handle exceptions.
}
// 6. Select a proper video height from the range.
```

If the video height is known, you can find the correct size configuration as shown in the following example:

```c++
int32_t height = 1080;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether the video height meets the high alignment requirements.
int32_t heightAlignment = 0;
int32_t ret = OH_AVCapability_GetVideoHeightAlignment(capability, &heightAlignment);
if (ret != AV_ERR_OK || heightAlignment <= 0) {
   // Handle exceptions.
} else if (height % heightAlignment != 0) {
   // 2. (Optional) Align the video height.
   height = (height + heightAlignment - 1) / heightAlignment * heightAlignment;
}
// 3. Check whether the video height is within the supported range.
OH_AVRange heightRange = {-1, -1};
ret = OH_AVCapability_GetVideoHeightRange(capability, &heightRange);
if (ret != AV_ERR_OK || heightRange.maxVal <= 0) {
   // Handle exceptions.
} else if (height < heightRange.minVal || height > heightRange.maxVal) {
   // 4. (Optional) Adjust the video height.
   height = std::min(std::max(height, heightRange.minVal), heightRange.maxVal);
}
// 5. Obtain the range of available video widths based on the video height.
OH_AVRange widthRange = {-1, -1};
ret = OH_AVCapability_GetVideoWidthRangeForHeight(capability, height, &widthRange);
if (ret != AV_ERR_OK || widthRange.maxVal <= 0) {
   // Handle exceptions.
}
// 6. Select a proper video width from the range.
```

### Setting the Correct Video Frame Rate

The frame rate of a video codec is limited by the codec's per-second codec capability and the protocol-level per-second processing capability. For example, AVC_LEVEL_51 of H.264 limits the maximum number of macroblocks per second to 983040.

The formula for calculating the maximum frame rate based on the video width and height is as follows:

![](figures/formula-maxmbspersecond.png)

**MaxMBsPerSecondLevelLimits** refers to the maximum number of macroblocks per second of the codec limited by the protocol, and **MaxMBsPerSecondSubmit** refers to the maximum number of macroblocks per second reported by the codec. The actual capability is the minimum of the two.

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoFrameRateRange             | Obtains the video frame rate range supported by a video codec.|
| OH_AVCapability_GetVideoFrameRateRangeForSize      | Obtains the video frame rate range of a video codec based on a given video size.|
| OH_AVCapability_AreVideoSizeAndFrameRateSupported  | Checks whether a video codec supports the combination of a video size and frame rate.|

When there is a requirement about the target frame rate, check whether the frame rate is within the optional range. An example is as follows:

```c++
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Obtain the supported frame rate range.
OH_AVRange frameRateRange = {-1, -1};
int32_t ret = OH_AVCapability_GetVideoFrameRateRange(capability, &frameRateRange);
if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
   // Handle exceptions.
}
// 2. Check whether the frame rate is within the range.
bool isSupported = frameRate >= frameRateRange.minVal && frameRate <= frameRateRange.maxVal;
```

The code snippet below shows how to select a proper frame rate configuration based on a given video size.

```c++
constexpr int32_t width = 1920;
constexpr int32_t height = 1080;
int32_t frameRate = 120;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether the video size to be configured can reach the ideal frame rate.
bool isSupported = OH_AVCapability_AreVideoSizeAndFrameRateSupported(capability, width, height, frameRate);
if (!isSupported) {
   // 2. Query the supported frame rate range based on the video size, and adjust the frame rate to be configured based on the query result.
   OH_AVRange frameRateRange = {-1, -1};
   int32_t ret = OH_AVCapability_GetVideoFrameRateRangeForSize(capability, width, height, &frameRateRange);
   if (ret != AV_ERR_OK || frameRateRange.maxVal <= 0) {
      // Handle exceptions.
   }
   frameRate = std::min(std::max(frameRate, frameRateRange.minVal), frameRateRange.maxVal);
}

// 3. Set the video size and frame rate.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (videoEnc == nullptr) {
   // Handle exceptions.
}
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, width, height);
if (format == nullptr) {
   // Handle exceptions.
}
if (!OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, static_cast<double>(frameRate))) {
   // Handle exceptions.
}
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
OH_AVFormat_Destroy(format);
```

### Setting the Correct Video Pixel Format

The video pixel format determines the pixel layout of an image that is encoded as input or decoded as output. For details, see [OH_AVPixelFormat](../../reference/apis-avcodec-kit/_core.md#oh_avpixelformat-1).

| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_GetVideoSupportedPixelFormats             | Obtains the video pixel formats supported by a video codec.|

```c++
constexpr OH_AVPixelFormat DEFAULT_PIXELFORMAT = AV_PIXEL_FORMAT_NV12;
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Obtain the video pixel formats supported by the video codec.
const int32_t *pixFormats = nullptr;
uint32_t pixFormatNum = 0;
int32_t ret = OH_AVCapability_GetVideoSupportedPixelFormats(capability, &pixFormats, &pixFormatNum);
if (ret != AV_ERR_OK || pixFormats == nullptr || pixFormatNum == 0) {
   // Handle exceptions.
}
// 2. Check whether the pixel format to be configured is supported.
bool isMatched = false;
for (int i = 0; i < pixFormatNum; i++) {
   if (pixFormats[i] == DEFAULT_PIXELFORMAT) {
      isMatched = true;
      break;
   }
}
if (!isMatched) {
   // 3. Replace an unsupported pixel format or select another codec.
}
```

### Checking Whether a Codec Feature Is Supported and Obtaining Its Properties

Codec features refer to optional features used in specific codec scenarios, such as temporal scalable encoding and low-latency codec in video encoding scenarios. For details, see [OH_AVCapabilityFeature](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcapabilityfeature-1).
| API    | Description                        |
| -------- | ---------------------------- |
| OH_AVCapability_IsFeatureSupported              | Checks whether a codec supports a given feature.|
| OH_AVCapability_GetFeatureProperties            | Obtains the properties of a specified feature supported by a codec.|

The code snippet below is an example of querying whether the H.264 encoder supports the long-term reference frame feature:

```c++
constexpr int32_t NEEDED_LTR_NUM = 2;
OH_AVFormat *format = OH_AVFormat_CreateVideoFormat(OH_AVCODEC_MIMETYPE_VIDEO_AVC, 1920, 1080);
OH_AVCapability *capability = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_AVC, true);
if (capability == nullptr) {
   // Handle exceptions.
}
// 1. Check whether the long-term reference frame feature is supported.
bool isSupported = OH_AVCapability_IsFeatureSupported(capability,VIDEO_ENCODER_LONG_TERM_REFERENCE);
if (isSupported) {
   // 2. Obtain the number of supported long-term reference frames.
   OH_AVFormat *properties = OH_AVCapability_GetFeatureProperties(capability, VIDEO_ENCODER_LONG_TERM_REFERENCE);
   if (properties == nullptr) {
      // Handle exceptions.
   }
   int32_t maxLTRCount = -1;
   bool ret = OH_AVFormat_GetIntValue(properties, OH_FEATURE_PROPERTY_KEY_VIDEO_ENCODER_MAX_LTR_FRAME_COUNT, &maxLTRCount);
   if (ret && maxLTRCount >= NEEDED_LTR_NUM) {
      if (!OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT, NEEDED_LTR_NUM)) {
         // Handle exceptions.
      }
   }
}
// 3. Create and configure an encoder.
OH_AVCodec *videoEnc = OH_VideoEncoder_CreateByMime(OH_AVCODEC_MIMETYPE_VIDEO_AVC);
if (OH_VideoEncoder_Configure(videoEnc, format) != AV_ERR_OK) {
   // Handle exceptions.
}
```

<!--no_check-->